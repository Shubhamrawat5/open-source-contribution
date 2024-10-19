def print_rangolli(n):
    rows = []
    for i in range(n):
        row_ = "-".join(string.ascii_lowercase[i: n])
        rows.append(row_[:: -1] + row_[1:])
    width = len(rows[0])

    # For top rows
    for i in reversed(range(n)):
        print(rows[i].center(width, "-"))

    # For bottom rows
    for i in range(1, n):
        print(rows[i].center(width, "-"))


if __name__ == "__main__":
    n = int(input())
    print_rangolli(n)
