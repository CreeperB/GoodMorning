# wumpus world

class room:
    def __init__(self, y, x, breeze, stench, gold, pit, wumpus):
        self.y = y
        self.x = x
        self.breeze = breeze
        self.stench = stench
        self.gold = gold
        self.pit = pit
        self.wumpus = wumpus
rooms = [room(0,0,0,0,0,0,0)]
print(rooms)