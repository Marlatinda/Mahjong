#include "Mahjong.h"

Mahjong::Mahjong(int r, int c) {
    row = r;
    column = c;
    data[0][0] = 1;
    data[4][5] = 1;
    data[0][8] = 4;
    data[2][0] = 4;
    data[3][0] = 2;
    data[3][8] = 1;
}

void Mahjong::printArray() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

void Mahjong::printPath() {
    int i = 0;
    while (path[i + 1][0] != 9999) {
        printf("(%d,%d)->", path[i][0], path[i][1]);
        i++;
    }
    printf("(%d,%d)", path[i][0], path[i][1]);
}

void Mahjong::setPath(int x1, int y1, int x2, int y2) {
    int i = 0;
    if (x1 != x2) {
        int min = x1 < x2 ? x1 : x2;
        int max = x1 > x2 ? x1 : x2;
        i = min;
        while (i <= max) {
            path[i - min][0] = i;
            path[i - min][1] = y1;
            i++;
        }
    } else if (y1 != y2) {
        int min = y1 < y2 ? y1 : y2;
        int max = y1 > y2 ? y1 : y2;
        i = min;
        while (i <= max) {
            path[i - min][0] = x1;
            path[i - min][1] = i;
            i++;
        }
    }
    path[i][0] = 9999;
}

int Mahjong::breathFirstSearch(int x1, int y1, int x2, int y2) {
    //不同的两个方块有相同的非零数值才能消除
    if ((data[x1][y1] != data[x2][y2] || !data[x1][y1] || !data[x2][y2]) || (x1 == x2 && y1 == y2)) {
        return 0;
    }
    node temp = {x1, y1, 0};
    node queue[row * column];
    int front = 0;
    int rear = 0;
    int x;
    int y;
    int num;
    queue[rear++] = temp;
    while (front < rear) {
        x = queue[front].x;
        y = queue[front].y;
        num = queue[front++].number;//直线的数量
        for (auto &d: dir) {
            //当前读取的坐标
            int xIndex = x + d[0];
            int yIndex = y + d[1];
            //cout << "(" << xIndex << "," << yIndex << ")->";
            //用三根以内的直线连在一起才能消除
            while (!data[xIndex][yIndex] && num < 3 && xIndex >= 0 && xIndex < row && yIndex >= 0 && yIndex < column &&
                   !used[xIndex][yIndex]) {
                used[xIndex][yIndex] = 1;
                temp = {xIndex, yIndex, num + 1};
                //cout << "(" << xIndex << "," << yIndex << ")->";
                queue[rear++] = temp;
                xIndex += d[0];
                yIndex += d[1];
            }
            if (xIndex == x2 && yIndex == y2 && num < 3) {
                return 1;
            }
        }
    }
    return 0;
}
