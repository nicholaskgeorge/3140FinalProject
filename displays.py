import pygame

pygame.init()
white = (255, 255, 255)
X = 995
Y = 680
display_surface = pygame.display.set_mode((X, Y ))
pygame.display.set_caption('GAME TIME')

randomnum=0 #to be received via serial stuff

if randomnum==0:
    image = pygame.image.load('right.jpeg').convert()

else:
    image = pygame.image.load('left.jpeg').convert()

while True :
    display_surface.fill(white)
    display_surface.blit(image, (0, 0))
    for event in pygame.event.get() :
        if event.type == pygame.QUIT :
            pygame.quit()
            quit()
        pygame.display.update()
