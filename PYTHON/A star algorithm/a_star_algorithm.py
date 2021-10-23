from typing import Tuple
from grid import grid


class Node:
    def __init__(self, state: Tuple, parent=None) -> None:
        self.state = state
        self.parent = parent

    def __str__(self) -> str:
        return str(self.state)


class a_star:

    def __init__(self, rows=10, cols=10, start=(0, 0), end=None, obstructions=None, obstruction_density=30, block_size=20) -> None:
        self.__rows = rows
        self.__cols = cols
        self.__start = start
        self.__end = end if end else (self.__rows, self.__cols)
        self.__grid = grid(rows=self.__rows, cols=self.__cols,
                           start=self.__start, end=self.__end, obstructions=obstructions, obstruction_density=obstruction_density, block_size=block_size)
        self.__obstructions = self.__grid.get_obstructions()

        print(len(self.__obstructions))
        self.__visited = {}
        self.__steps = {}

    def __h(self, x, y):
        return abs(pow(self.__end[0] - x, 2)) + abs(pow(self.__end[1] - y, 2))

    def __get_neightbours(self, curr_node: Node):

        x, y = curr_node.state
        neighbours = []

        if x > 0:
            if (x-1, y) not in self.__obstructions:
                if not self.__visited.get((x-1, y), False):
                    neighbours.append(Node((x-1, y), curr_node))

        if y > 0:
            if (x, y-1) not in self.__obstructions:
                if not self.__visited.get((x, y-1), False):
                    neighbours.append(Node((x, y-1), curr_node))

        if x < self.__rows - 1:
            if (x+1, y) not in self.__obstructions:
                if not self.__visited.get((x+1, y), False):
                    neighbours.append(Node((x+1, y), curr_node))

        if y < self.__cols - 1:
            if (x, y+1) not in self.__obstructions:
                if not self.__visited.get((x, y+1), False):
                    neighbours.append(Node((x, y+1), curr_node))

        return neighbours

    def display(self):
        self.__grid.draw_grid()

    def solve(self):

        end_node = self.__get_node()

        path = []

        if end_node:
            while end_node:
                path.append(end_node.state)
                end_node = end_node.parent

            path.reverse()

            self.__grid.set_final_path(path)

            return path

        return None

    def __get_node(self) -> Node:

        factor = {}
        steps = {}

        curr_node = Node(self.__start)

        x, y = curr_node.state

        cells = [curr_node]
        steps[curr_node.state] = 0
        factor[curr_node.state] = steps[curr_node.state] + \
            self.__h(x, y)

        while len(cells) > 0:

            x, y = curr_node.state

            self.__grid.visit(x, y)
            cells.remove(curr_node)
            self.__visited[curr_node.state] = True
            del factor[curr_node.state]

            if (x, y) == self.__end:
                return curr_node

            neighbours = self.__get_neightbours(curr_node=curr_node)
            next_step = None
            min_factor = pow(2, 31) - 1

            cells.extend(neighbours)
            for neighbour in cells:

                temp = factor.get(neighbour.state, None)
                temp_x, temp_y = neighbour.state

                if not steps.get(neighbour.state, None):
                    steps[neighbour.state] = steps[curr_node.state]+1

                self.__visited[neighbour.state] = True

                if not temp:
                    temp = steps[neighbour.state] + self.__h(temp_x, temp_y)
                    factor[neighbour.state] = temp

                if temp <= min_factor:
                    next_step = neighbour
                    min_factor = temp

            curr_node = next_step

        return None


def main():
    a = a_star(80, 80, (1, 79), (72, 8), block_size=10)
    path = a.solve()
    print('final path:', path)
    a.display()


if __name__ == "__main__":
    main()
