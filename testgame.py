# import pygame module in this program
import pygame
import random
import serial
import time

pygame.init()
# define the RGB value
# for white colour
white = (255, 255, 255)
# assigning values to X and Y variable
X = 1500
Y = 1000
# create the display surface object
# of specific dimension..e(X, Y).
display_surface = pygame.display.set_mode((X, Y ))
# set the pygame window name
pygame.display.set_caption('GAME TIME')
image = pygame.image.load('cher.jpeg').convert()
# create a surface object, image is drawn on it.
#C:\Users\julietdenapoli\Desktop\
# infinite loop
#pick random number 0-3 (0 straight, 1 right, 2 left, 3 jump)
initial = 0
ser = serial.Serial('COM12', 57600)

while(1):
    time.sleep(1)
    data = ser.readline()
    if initial == 0:
        if(data == "ready"):
            inital=1
            ser.write("setgo")
    else:
        pickImage = random.randint(0,1)
        ser.write(pickImage)
        if pickImage == 1:
            image = pygame.image.load('cher.jpeg').convert()
        else:
            image = pygame.image.load('cher.jpeg').convert()

    display_surface.fill(white)
    display_surface.blit(image, (0, 0))
    # iterate over the list of Event objects
    # that was returned by pygame.event.get() method.
    for event in pygame.event.get() :
        # if event object type is QUIT
        # then quitting the pygame
        # and program both.
        if event.type == pygame.QUIT :
            # deactivates the pygame library
            pygame.quit()
            # quit the program.
            quit()
        # Draws the surface object to the screen.
        pygame.display.update()
