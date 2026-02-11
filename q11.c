*returnSize = *matrixColSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*matrixColSize));
    int** result = (int**)malloc(sizeof(int*) * (*matrixColSize));
    for (int i = 0; i < *matrixColSize; i++) {
        (*returnColumnSizes)[i] = matrixSize;
        result[i] = (int*)malloc(sizeof(int) * matrixSize);
        for (int j = 0; j < matrixSize; j++) {
            result[i][j] = matrix[j][i];
        }
    }
    return result;
