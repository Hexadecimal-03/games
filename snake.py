from random import randrange
from turtle import *

from freegames import square, vector

def start (speed):
    print ("Snake: 1")

    food = vector(0, 0)
    snake = [vector(10, 0)]
    aim = vector(0, -10)


    def change(x, y):
        """Change snake direction."""
        aim.x = x
        aim.y = y


    def inside(head):
        """Return True if head inside boundaries."""
        return -200 < head.x < 190 and -200 < head.y < 190


    def move():
        """Move snake forward one segment."""
        onkey(lambda: change(10, 0), 'd')
        if aim.x == -10:
            onkey(None, 'd')
            
        onkey(lambda: change(-10, 0), 'a')
        if aim.x == 10:
            onkey(None, 'a')

        onkey(lambda: change(0, 10), 'w')
        if aim.y == -10:
            onkey(None, 'w')
        
        onkey(lambda: change(0, -10), 's')
        if aim.y == 10:
            onkey(None, 's')
        
        head = snake[-1].copy()
        head.move(aim)

        if not inside (head):
            if head.x > 190:
                head.x = -200
            elif head.x < -200:
                head.x = 190
            elif head.y > 190:
                head.y = -200
            elif head.y < -200:
                head.y = 190
                

        if head in snake:
            square(head.x, head.y, 9, 'red')
            print ("Your final score is: ", len(snake))
            update()
            return

        snake.append(head)

        if head == food:
            print('Snake:', len(snake))
            food.x = randrange(-15, 15) * 10
            food.y = randrange(-15, 15) * 10
        else:
            snake.pop(0)

        clear()

        for body in snake:
            square(body.x, body.y, 9, 'black')

        square(food.x, food.y, 9, 'green')
        update()
        
        ontimer(move, speed)


    setup(420, 420, 370, 0)
    clear()
    hideturtle()
    tracer(False)
    move()
    onkey (None, '1')
    onkey (None, '2')
    onkey (None, '3')
    done()


def onscreen():
    Screen()
    clear()
    goto(0, 0)
    write("Press 1 for Easy Mode", align="center", font=("Courier", 10, "bold"))
    goto(0, -50)
    write("Press 2 for Moderate Mode", align="center", font=("Courier", 10, "bold"))
    goto(0, -100)
    write("Press 3 for Hard Mode", align="center", font=("Courier", 10, "bold"))
    
    goto(0,-250)
    write('Welcome to the game Kid', align="center", font=("Courier", 16, "bold"))

    

    
    
hideturtle()
tracer(False)
onscreen()
listen()
onkey (lambda: start(200), '1')
onkey (lambda: start(100), '2')
onkey (lambda: start(50), '3')


done()