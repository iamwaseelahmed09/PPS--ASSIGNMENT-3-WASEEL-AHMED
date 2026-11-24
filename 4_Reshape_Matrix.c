#include <stdlib.h>

int** matrixReshape(int** mat, int matSize,
                    int* matColSize, int r, int c,
                    int* returnSize,
                    int** returnColumnSizes) {
    int oldRows = matSize;
    int oldCols = matColSize[0];

    if (oldRows * oldCols != r * c) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }

    int** result = (int**)malloc(r * sizeof(int*));
    *returnColumnSizes = (int*)malloc(r * sizeof(int));

    for (int i = 0; i < r; i++) {
        result[i] = (int*)malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int index = i * c + j;
            result[i][j] = mat[index / oldCols][index % oldCols];
        }
    }

    *returnSize = r;
    return result;
}
