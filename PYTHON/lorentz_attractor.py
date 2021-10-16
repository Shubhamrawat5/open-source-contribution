import pygame
import random 

'''
Python code to create lorentz attractor in pygame
'''


pygame.init()

screen = pygame.display.set_mode((400, 300))

pygame.display.set_caption("Lorentz attractor")

x, y, z = 1, 0, 0
hu = 0
a, b, c = 10, 28, 8 / 3

running = True
while running:

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    dt = 0.01
    dx = (a * (y - x)) * dt
    dy = (x * (b - z) - y) * dt
    dz = (x * y - c * z) * dt

    x += dx
    y += dy
    z += dz

    cx = random.randint(0, 255)
    cy = random.randint(0, 255)
    cz = random.randint(0, 255)

    pygame.draw.rect(screen, (cx, cy, cz), (x+200, y+150, 1, 1))
    pygame.transform.scale(screen,(400, 600))
    # print(x+400, y+300, z)

    pygame.display.update()
    