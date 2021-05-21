# import pygame module in this program
import pygame
import random
import serial

#set up GAME
pygame.init()
white = (255, 255, 255)
X = 1500
Y = 1000
display_surface = pygame.display.set_mode((X, Y ))
pygame.display.set_caption('GAME TIME')


#WHEN C CALLS PYTHON
initial = 0
ser = serial.Serial('/dev/tty.usbmodemSDA5336CE061', 57600)

while(1):
    data = ser.readline()
    if initial==0:
        if(data=="ready"):
            initial=1
            ser.write("setgo")
    else:
        pickImage=random.randint(0, 1)
        ser.write(pickImage)

        if pickImage==1: #right turn
            image = pygame.image.load('right.jpeg').convert()
        else: #left
            image = pygame.image.load('left.jpeg').convert()

    display_surface.fill(white)
    display_surface.blit(image, (0, 0))
    for event in pygame.event.get() :
        if event.type == pygame.QUIT :
            pygame.quit()
            quit()
    pygame.display.update()

#
# # activate the pygame library .
# # initiate pygame and give permission
# # to use pygame's functionality.
# pygame.init()
#
# # define the RGB value
# # for white colour
# white = (255, 255, 255)
#
# # assigning values to X and Y variable
# X = 1500
# Y = 1000
#
# # create the display surface object
# # of specific dimension..e(X, Y).
# display_surface = pygame.display.set_mode((X, Y ))
#
# # set the pygame window name
# pygame.display.set_caption('GAME TIME')
#
# # create a surface object, image is drawn on it.
# image = pygame.image.load('cher.jpeg').convert()
# #C:\Users\julietdenapoli\Desktop\
# # infinite loop
# while True :
#
#     # completely fill the surface object
#     # with white colour
#     display_surface.fill(white)
#
#     # copying the image surface object
#     # to the display surface object at
#     # (0, 0) coordinate.
#     display_surface.blit(image, (0, 0))
#
#     # iterate over the list of Event objects
#     # that was returned by pygame.event.get() method.
#     for event in pygame.event.get() :
#
#         # if event object type is QUIT
#         # then quitting the pygame
#         # and program both.
#         if event.type == pygame.QUIT :
#
#             # deactivates the pygame library
#             pygame.quit()
#
#             # quit the program.
#             quit()
#
#         # Draws the surface object to the screen.
#         pygame.display.update()
