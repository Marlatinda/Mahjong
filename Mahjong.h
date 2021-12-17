#ifndef MAHJONG_MAHJONG_H
#define MAHJONG_MAHJONG_H

#include <iostream>

using namespace std;
//方向依次为：上下左右
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
typedef struct {
    int x;
    int y;
    int number;
} node;

class Mahjong {
public:
    Mahjong(int r, int c);

    //广度优先搜索
    int breathFirstSearch(int x1, int y1, int x2, int y2);

    void printArray();

    void printPath();

    void setPath(int x1, int y1, int x2, int y2);

private:
    int row;
    int column;
    int used[1024][1024]{};
    int data[1024][1024]{};
    int path[1024 * 1024][2]{};


};


#endif //MAHJONG_MAHJONG_H
