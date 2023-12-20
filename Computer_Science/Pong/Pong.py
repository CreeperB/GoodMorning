import pygame
import random


def random_color():
    return [random.randint(50, 255), random.randint(50, 255), random.randint(50, 255)]


def reset_ball(side):
    global ball_x
    global ball_speed_x
    global ball_speed_y
    global score1
    global score2

    # change ball's y speed to random
    if ball_y >= 240:
        ball_speed_y = -random.uniform(3, 7)
    elif ball_y < 240:
        ball_speed_y = random.uniform(3, 7)

    # ball on the right side of the edge
    if side == "right":
        ball_speed_x = 4 + (score1 + score2) * 0.2
        score1 += 1
        ball_x = 80
    # ball on the left side of the edge
    elif side == "left":
        ball_speed_x = -4 - (score1 + score2) * 0.2
        score2 += 1
        ball_x = 560
    # end if any score equals 11
    if score1 == 11 or score2 == 11:
        return 1
    else:
        return 0


pygame.init()
screen = pygame.display.set_mode([640, 480])

# the ball's variables
ball_x = 50
ball_y = 50
ball_radius = 8
ball_color = [255, 0, 0]
ball_speed_x = 4
ball_speed_y = 5
ball_speed_boost = 1.1

# the paddle's variables
paddle1_x = 20
paddle1_y = 200
paddle2_x = 600
paddle2_y = 200
paddle_width = 8
paddle_height = 60
paddle_color_1 = [20, 180, 180]
paddle_color_2 = [20, 180, 180]
paddle_speed = 5

pygame.font.init()
myfont = pygame.font.SysFont("Arial", 15)
score1 = 0
score2 = 0

# allows milliseconds for holding the key
pygame.key.set_repeat(10, 10)

running = True
# game loop
while running:
    for event in pygame.event.get():
        # check if you've exited the game
        if event.type == pygame.QUIT:
            running = False

        # check if you pressed a key
        if event.type == pygame.KEYDOWN:
            # Press w key for paddle1 to go up
            if event.key == pygame.K_w:
                paddle1_y = paddle1_y - paddle_speed
                if paddle1_y < 0:
                    paddle1_y = 0
            # Press s key for paddle1 to go down
            if event.key == pygame.K_s:
                paddle1_y = paddle1_y + paddle_speed
                if paddle1_y > screen.get_height() - paddle_height:
                    paddle1_y = screen.get_height() - paddle_height
            # Press up key for paddle2 to go up
            if event.key == pygame.K_UP:
                paddle2_y = paddle2_y - paddle_speed
                if paddle2_y < 0:
                    paddle2_y = 0
            # Press down key for paddle2 to go down
            if event.key == pygame.K_DOWN:
                paddle2_y = paddle2_y + paddle_speed
                if paddle2_y > screen.get_height() - paddle_height:
                    paddle2_y = screen.get_height() - paddle_height

    # delay for 10 milliseconds
    pygame.time.delay(10)
    # make the screen completely black
    black = [0, 0, 0]
    screen.fill(black)

    # move the ball
    ball_x = ball_x + ball_speed_x
    ball_y = ball_y + ball_speed_y
    # check if the ball is off the bottom of the screen
    if ball_y > screen.get_height() - ball_radius:
        ball_speed_y = -ball_speed_y
    # check if the ball hit the top of the screen
    if ball_y < ball_radius:
        ball_speed_y = -ball_speed_y
    # check if the ball hit the right side of the screen
    if ball_x > screen.get_width() - ball_radius:
        if reset_ball("right"):
            running = False
    # check if the ball hit the left side of the screen
    if ball_x < ball_radius:
        if reset_ball("left"):
            running = False

    # create imaginary rectangles around ball and paddle
    # circles are measured from the center, so have to subtract 1 radius from the x and y
    ball_rect = pygame.Rect(ball_x - ball_radius, ball_y - ball_radius, ball_radius * 2, ball_radius * 2)
    paddle1_rect = pygame.Rect(paddle1_x, paddle1_y, paddle_width, paddle_height)
    paddle2_rect = pygame.Rect(paddle2_x, paddle2_y, paddle_width, paddle_height)
    if ball_rect.colliderect(paddle1_rect):
        if ball_x + ball_radius >= paddle1_x:
            ball_speed_x = -ball_speed_x * ball_speed_boost
        else:
            ball_speed_y = -ball_speed_y
        paddle_color_1 = random_color()
        ball_color = random_color()
    if ball_rect.colliderect(paddle2_rect):
        if ball_x - ball_radius <= paddle2_x:
            ball_speed_x = -ball_speed_x * ball_speed_boost
        else:
            ball_speed_y = -ball_speed_y
        paddle_color_2 = random_color()
        ball_color = random_color()

    # draw everything on the screen
    score1_label = myfont.render(str(score1), 1, pygame.color.THECOLORS['white'])
    screen.blit(score1_label, (5, 10))
    score2_label = myfont.render(str(score2), 1, pygame.color.THECOLORS['white'])
    screen.blit(score2_label, (620, 10))
    pygame.draw.circle(screen, ball_color, [int(ball_x), int(ball_y)], ball_radius, 0)
    pygame.draw.rect(screen, paddle_color_1, [paddle1_x, paddle1_y, paddle_width, paddle_height], 0)
    pygame.draw.rect(screen, paddle_color_2, [paddle2_x, paddle2_y, paddle_width, paddle_height], 0)
    # update the entire display
    pygame.display.update()

end = True
while end:
    for event in pygame.event.get():
        # check if you've exited the game
        if event.type == pygame.QUIT:
            end = False
    end_game_label = None
    myfont = pygame.font.SysFont("Arial", 20)
    if score1 == 11:
        end_game_label = myfont.render("Left side win!!", 1, pygame.color.THECOLORS['white'])

    if score2 == 11:
        end_game_label = myfont.render("Right side win!!", 1, pygame.color.THECOLORS['white'])

    screen.blit(end_game_label, (240, 240))
    pygame.display.update()