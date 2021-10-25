from typing import List, Optional
import pygame
import sys
import random


class grid:

    __BLACK = (0, 0, 0)
    __GREY = (200, 200, 200)
    __WHITE = (255, 255, 255)
    __GREEN = (0, 200, 0)
    __RED = (200, 0, 0)
    __BLUE = (0, 0, 200)
    __YELLOW = (200, 200, 0)

    def __init__(self, rows=20, cols=20, start=(0, 0), end=None, obstructions=None, obstruction_density=30, block_size=20) -> None:
        self.__rows = rows
        self.__cols = cols
        self.__block_size = block_size
        self.__visisted = []
        self.__final_path = []
        self.__start = start
        self.__end = end if end else (self.__rows - 1, self.__cols - 1)
        self.__obstructions_num = round(
            self.__rows * self.__cols * (70 if obstruction_density > 70 else obstruction_density) * 0.01)
        self.__obstructions = None
        self.__obstructions = obstructions if obstructions else self.get_obstructions()
        pygame.init()
        self.__SCREEN = pygame.display.set_mode(
            (self.__rows * self.__block_size, self.__cols * self.__block_size))

    def get_obstructions(self) -> List:

        if self.__obstructions:
            return self.__obstructions

        obs = []
        for _ in range(self.__obstructions_num):

            while True:
                x = round(random.random() * self.__rows)
                y = round(random.random() * self.__cols)

                if (x, y) not in obs and ((not (x, y) == self.__start) or (not (x, y) == self.__end)):
                    obs.append((x, y))
                    break

        return obs

    def visit(self, x, y):
        if not (x, y) == self.__start and not (x, y) == self.__end:
            self.__visisted.append((x, y))

    def set_final_path(self, path: Optional[List]):
        self.__final_path = path if path else []

    def draw_grid(self) -> None:
        self.__SCREEN.fill(grid.__BLACK)

        self.__draw_grid_boxes()
        self.__draw_obstructions()
        self.__draw_start_and_end()
        self.__draw_visited()
        self.__draw_final_path()
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
            pygame.display.update()

    def __draw_grid_boxes(self) -> None:
        for x in range(self.__rows):
            for y in range(self.__cols):
                rect = pygame.Rect(
                    x * self.__block_size, y * self.__block_size, self.__block_size, self.__block_size)
                pygame.draw.rect(self.__SCREEN, grid.__WHITE, rect, 1)

    def __draw_obstructions(self) -> None:
        for x, y in self.__obstructions:
            rect = pygame.Rect(
                x * self.__block_size, y * self.__block_size, self.__block_size, self.__block_size)
            self.__SCREEN.fill(self.__GREY, rect=rect)

    def __draw_start_and_end(self) -> None:

        start_x, start_y = self.__start
        start_rect = pygame.Rect(
            start_x * self.__block_size, start_y * self.__block_size, self.__block_size, self.__block_size)
        self.__SCREEN.fill(self.__BLUE, rect=start_rect)

        end_x, end_y = self.__end
        end_rect = pygame.Rect(
            end_x * self.__block_size, end_y * self.__block_size, self.__block_size, self.__block_size)
        self.__SCREEN.fill(self.__YELLOW, rect=end_rect)

    def __draw_visited(self) -> None:

        for x, y in self.__visisted:
            rect = pygame.Rect((x + 0.025) * self.__block_size, (y + 0.025) *
                               self.__block_size, self.__block_size * 0.95, self.__block_size * 0.95)
            self.__SCREEN.fill(self.__RED, rect=rect)

    def __draw_final_path(self) -> None:

        for x, y in self.__final_path[1:-1]:
            rect = pygame.Rect(
                (x+0.025) * self.__block_size, (y+0.025) * self.__block_size, self.__block_size * 0.95, self.__block_size * 0.95)
            self.__SCREEN.fill(self.__GREEN, rect=rect)


if __name__ == "__main__":
    g = grid()
    g.draw_grid()
