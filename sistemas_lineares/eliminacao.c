
#include <stdio.h>
#include <stdlib.h>

void libera(int dim, int **matriz){
    for (int i=0; i < dim; i++)
        free (matriz[i]);
    free (matriz); 

}

int main(){

    int dim;
    int **matriz;

    scanf("%d", &dim);
    int col = dim+1;
    matriz = malloc (dim * sizeof (int*)) ;

    for (int i=0; i < dim; i++)
        matriz[i] = malloc (col * sizeof (int)) ;

    for (int i=0; i < dim; i++)
        for (int j=0; j < col; j++)
            scanf("%d", &matriz[i][j]);       

    for(int j=0; j<col; j++){
        for(int i= j+1; i<dim; i++){
            // printf("%d\n",matriz[i][j]);
            int m = (matriz[i][j])/(matriz[j][j]);
            for(int k =j; k<col; k++){
                int aux = matriz[j][k]* m;
                matriz[i][k] = matriz[i][k] - aux;
            }
        }
    }
    for(int i=0; i<dim; i++){
        for(int j=0; j< col; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    libera(dim, matriz);

    return 0;
}