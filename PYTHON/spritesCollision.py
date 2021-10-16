import pygame
import sys

#define Sprite Class
class Sprite(pygame.sprite.Sprite):

    def __init__(self,pos) :
        pygame.sprite.Sprite.__init__(self) #initialises sprite class
        self.image = pygame.Surface([20,20])
        self.image.fill((255,0,255))
        self.rect = self.image.get_rect()
        self.rect.center = pos
    
#main function
def main() :
    pygame.init()
    clock = pygame.time.Clock()

    fps = 50
    bg = [0,0,0]
    size = [500,500]
    screen = pygame.display.set_mode(size)

    player = Sprite([40,50])
    player.move = [pygame.K_LEFT,pygame.K_RIGHT,pygame.K_UP,pygame.K_DOWN]
    player.vx = 5
    player.vy = 5

    wall = Sprite([100,60])

    wall_group = pygame.sprite.Group()
    wall_group.add(wall)
    
    player_group = pygame.sprite.Group()
    player_group.add(player)
    
    while True :
        for event in pygame.event.get() :
            if event.type == pygame.QUIT :
                return False

        keys = pygame.key.get_pressed()

        for i in range(2): #it's either left or right direction in which our sprite is moving along
            if keys[player.move[i]]:
                player.rect.x += player.vx * [-1,1][i]

        for i in range(2):
            if keys[player.move[2:4][i]]:
                player.rect.y += player.vy * [-1,1][i]
        
        screen.fill(bg)

        hit = pygame.sprite.spritecollide(player,wall_group,True)

        if hit :
            player.image.fill((255,255,255))

        player_group.draw(screen)
        wall_group.draw(screen)
        pygame.display.update()
        clock.tick(fps)
            
    pygame.quit()
    sys.exit

    
if __name__ == '__main__' :
    main()
