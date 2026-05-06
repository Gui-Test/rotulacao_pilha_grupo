#include "arq.h"

int ** cria_matriz(int *m, int *n){
    FILE *f = fopen("entrada_1.txt", "r");
    if(!f){
        printf("Arquivo não encontrado.\n");
        return NULL;
    }
    int **mat;
    //conta o número de linhas
    *m = conta_linha(f);                        
    fclose(f);
    //conta o número de colunas
    f = fopen("entrada_1.txt", "r");
    char buffer[256] = " ";
    fgets(buffer, sizeof(buffer), f);
    *n = strlen(buffer)-1;                      
    fclose(f);
    
    //Malloc na matriz
    mat = malloc(sizeof(int*) * (*m));
    for(int i=0;i < *m;i++){
        mat[i] = malloc(sizeof(int) * (*n));
    }

    
    return mat;
}

int conta_linha(FILE *f){
    int nlinha = 0;
    char ch = ' ';
    while(!feof(f)){
        ch = fgetc(f);
        if(ch == '\n'){
            nlinha++;
        }
    }
    return nlinha+1;
}

void insere_matriz(int*** mat, int m, int n){
    FILE *f = fopen("entrada_1.txt", "r");
    if(!f){
        printf("Arquivo não encontrado.\n");
        return;
    }
    char ch = ' ';
    int num = 0;
    for(int i=0;i < m;i++){
        for(int j=0;j < n;j++){
            ch = fgetc(f);
            if(ch == '\n'){
              ch = fgetc(f);
            }
            num = ch - '0';
            (*mat)[i][j] = num;
        }
        
    }
    fclose(f);
}

void print_matriz(int **mat, int m, int n){
    printf("\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int marcador(int i,int j,int rot, struct pilha *pil, info dir[4], int*** mat, int m, int n){
    int tam = 0;
    info novo;
    novo.lin = i;
    novo.col = j;
    (*mat)[i][j] = rot;
    empilha(&novo, pil);
    
    tam++;

    while(novo.lin >= 0){
        novo = mover(mat, dir, &novo);
        if(novo.lin >= 0){
            (*mat)[novo.lin][novo.col] = rot; 
            empilha(&novo, pil);
            tam++;
        }
    }

    while(vazia(pil) != 1){
        desempilha(&novo, pil);
        while(novo.lin >= 0){
            novo = mover(mat, dir, &novo);
            if(novo.lin >= 0){
                (*mat)[novo.lin][novo.col] = rot; 
                empilha(&novo, pil);
                tam++;
            }
        }
    }

    return tam;
}

//ideia: ver se tem algum 1 em volta e copia os dados de onde esse 1 está, se não retorna null.
info mover(int ***mat, info dir[4], info *novo){
    int l = novo->lin;
    int c = novo->col;
    info aux;
    aux.lin = l;
    aux.col = c;
    if((*mat)[l+dir[0].lin][c+dir[0].col] == 1){
        aux.lin += dir[0].lin;
        aux.col += dir[0].col;
        return aux;
    }
    if((*mat)[l+dir[1].lin][c+dir[1].col] == 1){
        aux.lin += dir[1].lin;
        aux.col += dir[1].col;
        return aux;
    }
    if((*mat)[l+dir[2].lin][c+dir[3].col] == 1){
        aux.lin += dir[2].lin;
        aux.col += dir[2].col;
        return aux;
    }
    if((*mat)[l+dir[3].lin][c+dir[3].col] == 1){
        aux.lin += dir[3].lin;
        aux.col += dir[3].col;
        return aux;
    }
        aux.lin = -1;
        aux.col = -1;
    return aux;
}


    

    
