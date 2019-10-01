#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "matrizv3.h"

mymatriz *msomar (mymatriz *mat_a, mymatriz *mat_b, int tipo);
mymatriz *mmultiplicar (mymatriz *mat_a, mymatriz *mat_b, int tipo);

int multiplicar_submatriz (matriz_bloco_t *mat_suba, matriz_bloco_t *mat_subb, matriz_bloco_t *mat_subc);
matriz_bloco_t **csubmatrizv2(int mat_lin, int mat_col, int divisor);
matriz_bloco_t **particionar_matriz(int **matriz, int mat_lin, int mat_col, int orientacao, int divisor);
