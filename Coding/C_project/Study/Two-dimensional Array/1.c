//
// Created by bokeboke on 2023/10/23.
//

#include <stdbool.h>

bool findNumberIn2DArry(int **matrix, int matrixsize, int *matrixColsize, int tager) {
    if(matrixsize == 0||matrixColsize == 0) return false;
    int x = *matrixColsize - 1, y = 0;
    while (x >= 0 && y < matrixsize) {
        if(matrix[y][x] < tager) x--;
        else if(matrix[y][x] > tager) y++;
        if(matrix[y][x] == tager) return 1;
    }
    return 0;
}//matrixsize 高度，matriixColsize 宽度

