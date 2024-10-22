import tkinter
import random
from tkinter import Label, messagebox

# Constants
GRID_SIZE = 4
TILE_VALUES = [2, 4]
bg_grid_color = {
    2: "light blue", 4: "light green", 8: "yellow",
    16: "orange", 32: "red", 64: "magenta",
    128: "blue", 256: "green", 512: "#00FFFF",
    1024: "#856ff8", 2048: "pink"
}
number_colour = {
    2: "red", 4: "blue", 8: "#856ff8", 16: "black",
    32: "yellow", 64: "green", 128: "light green",
    256: "light blue", 512: "red", 1024: "#00FFFF",
    2048: "magenta"
}


class Game(tkinter.Frame):
    def __init__(self):
        super().__init__()
        self.grid()
        self.master.title('2048')

        self.mainGrid = tkinter.Frame(self, bg="grey", bd=3, width=400, height=400)
        self.mainGrid.grid(pady=(100, 0))
        self.make_grid()
        self.begin_game()

        # Bind key events
        self.master.bind("<Left>", self.left)
        self.master.bind("<Right>", self.right)
        self.master.bind("<Up>", self.up)
        self.master.bind("<Down>", self.down)

        self.mainloop()

    def make_grid(self):
        self.cells = []
        for i in range(GRID_SIZE):
            row = []
            for j in range(GRID_SIZE):
                cell_frame = tkinter.Frame(self.mainGrid, bg="azure4", width=100, height=100)
                cell_frame.grid(row=i, column=j, padx=5, pady=5)
                cell_number = tkinter.Label(self.mainGrid, bg="azure4")
                cell_number.grid(row=i, column=j)
                row.append({"frame": cell_frame, "value": cell_number})
            self.cells.append(row)

        # Displaying the score
        score_frame = tkinter.Frame(self)
        score_frame.place(relx=0.5, y=45, anchor="center")
        tkinter.Label(score_frame, text="Score").grid(row=0)
        self.score_label = tkinter.Label(score_frame, text="0")
        self.score_label.grid(row=1)

    def begin_game(self):
        self.matrix = [[0] * GRID_SIZE for _ in range(GRID_SIZE)]
        self.score = 0
        self.add_new_tile()
        self.add_new_tile()
        self.updation()

    def add_new_tile(self):
        empty_positions = [(i, j) for i in range(GRID_SIZE) for j in range(GRID_SIZE) if self.matrix[i][j] == 0]
        if empty_positions:
            row, column = random.choice(empty_positions)
            self.matrix[row][column] = random.choice(TILE_VALUES)
            self.update_cell(row, column)

    def update_cell(self, row, column):
        value = self.matrix[row][column]
        if value:
            self.cells[row][column]["frame"].configure(bg=bg_grid_color[value])
            self.cells[row][column]["value"].configure(bg=bg_grid_color[value], fg=number_colour[value], text=str(value))
        else:
            self.cells[row][column]["frame"].configure(bg="azure4")
            self.cells[row][column]["value"].configure(bg="azure4", text=" ")

    def stack_and_combine(self):
        for i in range(GRID_SIZE):
            # Stack tiles
            new_row = [value for value in self.matrix[i] if value != 0]
            new_row += [0] * (GRID_SIZE - len(new_row))

            # Combine tiles
            for j in range(GRID_SIZE - 1):
                if new_row[j] != 0 and new_row[j] == new_row[j + 1]:
                    new_row[j] *= 2
                    new_row[j + 1] = 0
                    self.score += new_row[j]

            # Stack again after combining
            new_row = [value for value in new_row if value != 0] + [0] * (GRID_SIZE - len(new_row))
            self.matrix[i] = new_row

    def move_left(self):
        self.stack_and_combine()
        self.add_new_tile()
        self.updation()
        self.check_end()

    def move_right(self):
        self.matrix = [row[::-1] for row in self.matrix]
        self.stack_and_combine()
        self.matrix = [row[::-1] for row in self.matrix]
        self.add_new_tile()
        self.updation()
        self.check_end()

    def move_up(self):
        self.transpose()
        self.stack_and_combine()
        self.transpose()
        self.add_new_tile()
        self.updation()
        self.check_end()

    def move_down(self):
        self.transpose()
        self.reverse()
        self.stack_and_combine()
        self.reverse()
        self.transpose()
        self.add_new_tile()
        self.updation()
        self.check_end()

    def transpose(self):
        self.matrix = [list(row) for row in zip(*self.matrix)]

    def reverse(self):
        self.matrix = [row[::-1] for row in self.matrix]

    def check_end(self):
        if any(2048 in row for row in self.matrix):
            messagebox.showinfo("YOU WIN", f"Your score is {self.score}")
        elif not any(0 in row for row in self.matrix) and not self.hori_possible() and not self.verti_possible():
            messagebox.showinfo("YOU LOSE", f"Your final score is {self.score}")

    def hori_possible(self):
        return any(self.matrix[i][j] == self.matrix[i][j + 1] for i in range(GRID_SIZE) for j in range(GRID_SIZE - 1))

    def verti_possible(self):
        return any(self.matrix[i][j] == self.matrix[i + 1][j] for i in range(GRID_SIZE - 1) for j in range(GRID_SIZE))

    def updation(self):
        for i in range(GRID_SIZE):
            for j in range(GRID_SIZE):
                self.update_cell(i, j)
        self.score_label.configure(text=self.score)

    # Event handling
    def left(self, event):
        self.move_left()

    def right(self, event):
        self.move_right()

    def up(self, event):
        self.move_up()

    def down(self, event):
        self.move_down()


Game()
