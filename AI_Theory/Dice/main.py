import mss.tools
import pygame
from PIL import Image
from ultralytics import YOLO

def capture():
	with mss.mss() as sct:
		top = 580
		left = 722
		monitor = {"top": top, "left": left, "width": 1440 - left, "height": 900 - top}

		sct_img = sct.grab(monitor)

		mss.tools.to_png(sct_img.rgb, sct_img.size, output="fg.png")
    
	bg = Image.new("RGBA", (8000, 8000), (255,255,255))
	fg = Image.open("fg.png").convert("RGBA")
	fg = fg.transpose(Image.ROTATE_270)
	fg.save("fg.png", format="png")
	fg = Image.open("fg.png").convert("RGBA")
	fx, fy = fg.size
 
	x, y = 300, 300
	
	bg.paste(fg, (x, y, x + fx, y + fy), fg)
	bg.save("output.png", format="png")


	model = YOLO("best/weights/best.pt")
	results = model.predict("output.png")
	result = results[0]
 
	dices = []

	for box in result.boxes:
		class_id = result.names[box.cls[0].item()]
		cords = box.xyxy[0].tolist()
		cords = [round(x) for x in cords]
		conf = round(box.conf[0].item(), 2)
		print("Object type:", class_id)
		dices.append(int(class_id))
		print("Coordinates:", cords)
		print("Probability:", conf)
		print("---")
  
	dices = sorted(dices)
	print(dices)
	return dices

pygame.init()
width, height = 360, 900
screen = pygame.display.set_mode((width, height))

objects = []
names = ['1 for each', '2 for each', '3 for each', '4 for each', '5 for each', '6 for each', 'Choice', '4 of a kind', 'Full house', 'Small straight', 'Large straight', 'Yacht']

class Button:
    def __init__(self, x, y, width, height, text):
        self.rect = pygame.Rect(x, y, width, height)
        self.text = text
        self.clicked = False
        objects.append(self)
        

    def draw(self, screen):
        pygame.draw.rect(screen, (255, 255, 255), self.rect)
        font = pygame.font.Font(None, 30)
        text = font.render(self.text, True, (0, 0, 0))
        text_rect = text.get_rect(center=self.rect.center)
        screen.blit(text, text_rect)

    def update(self):
        if self.clicked:
            dices = []
            if self.text == '1 for each' or self.text == '2 for each' or self.text == '3 for each' or self.text == '4 for each' or self.text == '5 for each' or self.text == '6 for each' or self.text == 'Choice' or self.text == '4 of a kind' or self.text == 'Full house' or self.text == 'Small straight' or self.text == 'Large straight' or self.text == 'Yacht':
                dices = capture()
            score = 0
            if self.text == '1 for each':
                for dice in dices:
                    if dice == 1:
                        score += 1
            elif self.text == '2 for each':
                for dice in dices:
                    if dice == 2:
                        score += 2
            elif self.text == '3 for each':
                for dice in dices:
                    if dice == 3:
                        score += 3
            elif self.text == '4 for each':
                for dice in dices:
                    if dice == 4:
                        score += 4    
            elif self.text == '5 for each':
                for dice in dices:
                    if dice == 5:
                        score += 5
            elif self.text == '6 for each':
                for dice in dices:
                    if dice == 6:
                        score += 6
            elif self.text == 'Choice':
                for dice in dices:
                    score += dice    
            elif self.text == '4 of a kind':
                for dice in dices:
                    if dices.count(dice) >= 4:
                        score += dice
            elif self.text == 'Full house':
                for dice1 in dices:
                    if dices.count(dice1) == 3:
                        for dice2 in dices:
                            if dice2 != dice1 and dices.count(dice2) == 2:
                                for dice in dices:
                                    score += dice
            elif self.text == 'Small straight':
                if 1 in dices and 2 in dices and 3 in dices and 4 in dices:
                    score += 15
                elif 2 in dices and 3 in dices and 4 in dices and 5 in dices:
                    score += 15
                elif 3 in dices and 4 in dices and 5 in dices and 6 in dices:
                    score += 15
            elif self.text == 'Large straight':
                if 1 in dices and 2 in dices and 3 in dices and 4 in dices and 5 in dices:
                    score += 30
                elif 2 in dices and 3 in dices and 4 in dices and 5 in dices and 6 in dices:
                    score += 30
            elif self.text == 'Yacht':
                for dice in dices:
                    if dices.count(dice) == 5:
                        score += 50
            self.text = str(score)

    def handle_event(self, event):
        if event.type == pygame.MOUSEBUTTONDOWN:
            if self.rect.collidepoint(event.pos):
                self.clicked = True
        elif event.type == pygame.MOUSEBUTTONUP:
            self.clicked = False

def myFunction():
	print('Button clicked!')
 

for i in range(12):
	button = Button(30, 60*i, 300, 50, names[i])

print(objects)

font = pygame.font.Font(None, 36)

label_color = (255, 255, 255)

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        for obj in objects:
            obj.handle_event(event)

    screen.fill((0, 0, 0))
    
    label_text = "Total: " + str(sum([int(obj.text) for obj in objects if obj.text.isdigit()]))
    label = font.render(label_text, True, label_color)
        
    for obj in objects:
        obj.update()
        obj.draw(screen)
        
    screen.blit(label, (30, 720))
    
    pygame.display.flip()

pygame.quit()