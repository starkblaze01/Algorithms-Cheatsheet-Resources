from pynput.keyboard import Key, Controller
import time

keyboard = Controller()


time.sleep(4)


def right():
    sum= 0
    while True:
        sum = sum+1
        keyboard.press(Key.right)
        if sum ==8:
            break

def left():
    sum= 0
    while True:
        sum = sum+1
        keyboard.press(Key.left)
        if sum ==3:
            break
        
        
def up():
    sum= 0
    while True:
        sum = sum+1
        keyboard.press(Key.up)
        if sum ==8:
            break

def down():
    sum= 0
    while True:
        sum = sum+1
        keyboard.press(Key.down)
        if sum ==3:
            break




