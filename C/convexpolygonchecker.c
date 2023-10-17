#include <stdio.h>

typedef struct Point {
    int x, y;
} Point;

int crossProduct(Point a, Point b, Point c) {
    int x1 = a.x - b.x;
    int y1 = a.y - b.y;
    int x2 = c.x - b.x;
    int y2 = c.y - b.y;
    return x1 * y2 - x2 * y1;
}

int isConvex(Point polygon[], int n) {
    if (n < 3) return 0;

    int initialSign = 0;
    for (int i = 0; i < n; i++) {
        int currentSign = crossProduct(polygon[i], polygon[(i + 1) % n], polygon[(i + 2) % n]);
        if (currentSign != 0) {
            if (initialSign == 0) {
                initialSign = currentSign;
            } else if (initialSign != currentSign) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Point polygon[n];

    printf("Enter the coordinates of the vertices:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &polygon[i].x, &polygon[i].y);
    }

    if (isConvex(polygon, n)) {
        printf("The polygon is convex.\n");
    } else {
        printf("The polygon is not convex.\n");
    }

    return 0;
}
