import pygame

pygame.init()

width = 400
height = 400

screen = pygame.display.set_mode((width, height))


class sprite:
    class obstacle:
        def __init__(self, width, height):
            self.width = width
            self.height = height
            self.obstacleColor = (0, 0, 0)
            
        
        def draw_temp_obstacle(self, surface):
            pygame.draw.rect(surface, self.obstacleColor)
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    

pygame.quit()