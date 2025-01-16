#include <stdio.h>
#include <stdlib.h>

void libera(int dim, float **matriz) {
    for (int i = 0; i < dim; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void troca(int dim, float **matriz, int col, int linha1, int linha2) {
    for (int j = 0; j < col; j++) {
        int aux = matriz[linha1][j];
        matriz[linha1][j] = matriz[linha2][j];
        matriz[linha2][j] = aux;
    }
}

int main() {
    int dim;
    float **matriz;

    scanf("%d", &dim);
    int col = dim + 1; 
    matriz = malloc(dim * sizeof(int *));
    for (int i = 0; i < dim; i++) {
        matriz[i] = malloc(col * sizeof(int));
    }

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    int max = 0;
    // Pivoteamento Parcial e Eliminação de Gauss
    for (int j = 0; j < dim; j++) {
        int linha_pivo = j;
        for (int i = j + 1; i < dim; i++) {
            if (matriz[i][j] > max) {
                max = matriz[i][j];
                linha_pivo = i;
            }
        }

        // Troca a linha atual com a linha do pivô
        if (linha_pivo != j) {
            troca(dim, matriz, col, j, linha_pivo);
        }
    }

    // for(int i=0; i<dim; i++){
    //     for(int j=0; j< col; j++){
    //         printf("%.2f ", matriz[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int j=0; j<col; j++){
        for(int i= j+1; i<dim; i++){
            // printf("%d\n",matriz[i][j]);
            float m = (matriz[i][j])/(matriz[j][j]);
            for(int k =j; k<col; k++){
                float aux = matriz[j][k]* m;
                matriz[i][k] = matriz[i][k] - aux;
            }
        }
    }
    for(int i=0; i<dim; i++){
        for(int j=0; j< col; j++){
            printf("%.0f ", matriz[i][j]);
        }
        printf("\n");
    }

    libera(dim, matriz);
    return 0;
}