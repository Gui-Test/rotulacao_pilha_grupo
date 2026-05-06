#include "arq.h"
//Para compilar: gcc main.c arq.h pilha.c matriz.c

int main(){
    int m = 0,n = 0;
    int rotulo = 0;
    info direcao[4]={{-1,0},{0,1},{1,0},{0,-1}}; //Norte, Leste, Sul, Oeste

    struct pilha *pilha;
    pilha = cria();

    int **mat = cria_matriz(&m,&n);

    printf("m: %d", m);
    printf("\nn: %d", n);

    printf("\n");

    insere_matriz(&mat,m,n);
    print_matriz(mat,m,n);

    int tam_objeto = 0;
    int maior = 0;
    int maior_rotulo = 0;

    for (int i=0;i < m;i++){
        for (int j=0;j < n;j++){
            if (mat[i][j] == 1){
                rotulo+=10;
                tam_objeto = marcador(i,j,rotulo,pilha,direcao,&mat,m,n);
                printf("\nObjeto %d: tamanho %d\n", rotulo, tam_objeto);
                if(tam_objeto > maior){
                    maior = tam_objeto;
                    maior_rotulo = rotulo;
                }
                reinicia(pilha);
            }
        }
    }

    print_matriz(mat,m,n);
    printf("MAIOR OBJETO: %d\n", maior_rotulo);

    limpa_matriz(&mat, m, n, rotulo);
    print_matriz(mat,m,n);

    destroi(pilha);

    for(int i = 0; i<m; i++)
        free(mat[i]); 
    free(mat);
   
}