#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintMatrix(float** ar, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.1f  ", ar[i][j]);
        }
        printf("\n");
    }
    return;
}

void PrintInverse(float** ar, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = n; j < m; j++) {
            printf("%.1f  ", ar[i][j]);
        }
        printf("\n");
    }
    return;
}

void InverseOfMatrix(float** matrix, int order)
{
    float temp;
    printf("=== Matriz ===\n");
    PrintMatrix(matrix, order, order);
 
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < 2 * order; j++) {
            if (j == (i + order))
                matrix[i][j] = 1;
        }
    }
 
    for (int i = order - 1; i > 0; i--) {
        if (matrix[i - 1][0] < matrix[i][0]) {
            float* temp = matrix[i];
            matrix[i] = matrix[i - 1];
            matrix[i - 1] = temp;
        }
    }
 
    printf("\n=== Matriz aumentada ===\n");
    PrintMatrix(matrix, order, order * 2);
 
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            if (j != i) {
                temp = matrix[j][i] / matrix[i][i];
                for (int k = 0; k < 2 * order; k++) {
                    matrix[j][k] -= matrix[i][k] * temp;
                }
            }
        }
    }
 
    for (int i = 0; i < order; i++) {
        temp = matrix[i][i];
        for (int j = 0; j < 2 * order; j++) {
            matrix[i][j] = matrix[i][j] / temp;
        }
    }
 
    printf("\n=== Matriz Inversa ===\n");
    PrintInverse(matrix, order, 2 * order);
 
    return;
}

int main()
{
    float tempo;
    time_t t_ini, t_fim;
    
    t_ini = time(NULL);
    int order;
    printf("Entre com a ordem da matriz");
    scanf("%d", &order);

    float** matrix = (float**)malloc(order * sizeof(float*));
    for (int i = 0; i < order; i++) {
        matrix[i] = (float*)malloc(order * sizeof(float));
    }

      printf("Entre com os elementos da matriz:\n");
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            printf("Digite o valor do termo A (%i | %i): ", i+1, j+1);
            scanf("%f", &matrix[i][j]);
        }
    }

    InverseOfMatrix(matrix, order);

    for (int i = 0; i < order; i++) {
        free(matrix[i]);
    }
    free(matrix);
     t_fim = time(NULL);
    tempo =  difftime(t_fim, t_ini);
    printf("Tempo: %.1fs\n",tempo);

    return 0;
}