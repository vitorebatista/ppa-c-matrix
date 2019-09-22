#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SOME_HEADER_FILE_H
#define SOME_HEADER_FILE_H
typedef struct {
    int lin_inicio;
    int lin_fim;
    int col_inicio;
    int col_fim;
} bloco_t;

typedef struct {
    int **matriz;
    int lin;
    int col;
} mymatriz;

typedef struct {
    mymatriz *matriz; //Corrigido, estava int **matriz;
    bloco_t *bloco;
    int mat_col;
    int mat_lin;
    int divisor;
} matriz_bloco_t;
#endif

// gerência de matrizes
int malocar (mymatriz *matriz);
int mgerar(mymatriz *matriz, int valor);
int mimprimir (mymatriz *matriz);
int mzerar (mymatriz *matriz);
int mliberar (mymatriz *matriz);
int mcomparar (mymatriz *mat_a, mymatriz *mat_b);

// submatriz
//int gerar_submatriz (int **mat_origem, matriz_bloco_t *submatriz, bloco_t *bloco);
//int imprimir_submatriz (matriz_bloco_t *submatriz);
//matriz_bloco_t **particionar_matriz (int **matriz, int mat_lin, int mat_col, int orientacao, int divisor);
//matriz_bloco_t **liberar_submatriz (matriz_bloco_t **submatriz);
//int imprimir_bloco (matriz_bloco_t *submatriz);
//matriz_bloco_t **constroi_submatriz (int **matriz, int mat_lin, int mat_col, int divisor);
//matriz_bloco_t **csubmatrizv2 (int mat_lin, int mat_col, int divisor);

