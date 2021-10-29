def get_build_order(node, graph, visited, stack):
    visited[node] = True

    if node in graph:
        for n in graph[node]:
            if not visited[n]:
                get_build_order(n, graph, visited, stack)
        stack.insert(0, node)


def check_cycle(node, graph, visited, parent):
    visited[node] = True

    if node in graph:
        for n in graph[node]:
            if not visited[n]:
                if check_cycle(n, graph, visited, node):
                    return True
            elif n != parent:
                return True
    return False


def driver():
    graph = {
        0: [1],
        1: [2, 3],
        2: [1, 3],
        3: [1],
        4: [5],
        5: [4]
    }

    stack = []
    visited = [False] * len(graph)
    for i in range(len(graph)):
        if not visited[i]:
            get_build_order(i, graph, visited, stack)
    print(stack)

    visited = [False] * len(graph)
    for i in range(len(graph)):
        if not visited[i]:
            if check_cycle(i, graph, visited, -1):
                return True
    return False


def main():
    if driver():
        print('Cycle exists')
    else:
        print('Cycle does not exist')


if __name__ == '__main__':
    main()
