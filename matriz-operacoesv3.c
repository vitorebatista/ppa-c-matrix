#include "toolsv3.h"
#include "matrizv3.h"

/*
Realiza a soma de duas matrizes.
As matrizes devem ter o mesmo número de linhas e colunas, sendo o
resultado uma nova matriz de mesmo tamanho.
@return res, ponteiro para a matriz resultante
@param mat_a, ponteiro da struct mymatriz
@param mat_b, ponteiro da struct mymatriz
@param tipo, ordem para executar a somatória:
        - 0 para ij
        - 1 para ji
*/
mymatriz *msomar(mymatriz *mat_a, mymatriz *mat_b, int tipo)
{
    mymatriz *result = malloc(sizeof(mymatriz));
    int i_max, j_max;

    if (mat_a->matriz == NULL)
    {
        printf("\nERRO: Matriz A não alocada \n\n");
        exit(1);
    }

    if (mat_b->matriz == NULL)
    {
        printf("\nERRO: Matriz B não alocada \n\n");
        exit(1);
    }

    if ((mat_a->lin != mat_b->lin) || (mat_a->col != mat_b->col))
    {
        printf("\nERRO: As matrizes não são do mesmo tamanho\n");
        exit(1);
    }

    result->matriz = NULL;
    result->col = mat_a->col;
    result->lin = mat_a->lin;

    if (malocar(result))
    {
        printf("\nERROR: Erro ao inicializar matriz\n");
        exit(1);
    }
    else
    {
        mzerar(result);
    }

    //define aninhamento, conforme parametro tipo
    i_max = mat_a->lin;
    j_max = mat_a->col;
    if (tipo == 1)
    { //tipo = 1: ordem de aninhamento ji
        i_max = mat_a->col;
        j_max = mat_a->lin;
    }

    //realiza a soma dos elementos da matriz a e b
    for (int i = 0; i < i_max; i++)
    {
        for (int j = 0; j < j_max; j++)
        {
            if (tipo == 0)
            { //tipo = 0: ordem de aninhamento ij
                result->matriz[i][j] = mat_a->matriz[i][j] + mat_b->matriz[i][j];
            }
            else
            { //tipo = 1: ordem de aninhamento ji
                result->matriz[j][i] = mat_a->matriz[j][i] + mat_b->matriz[j][i];
            }
        }
    }
    // result->matriz = temp.matriz;
    // result->lin = temp.lin;
    // result->col = temp.col;
    return result;
}

/*
Realiza a multiplicação de duas matrizes.
As matrizes envolvidas na multiplicação devem seguir a regra: número de colunas da primeira
matriz deve ser igual ao número de linhas da segunda matriz. A matriz resultante será configurada
tendo o número de linhas da primeira e o número de colunas da segunda. Ex: 3x4 * 4x3 = 3x3
@return res, ponteiro para a matriz resultante
@param mat_a, ponteiro para objeto do tipo mymatriz
@param mat_b, ponteiro para objeto do tipo mymatriz
@param tipo, ordem para executar a multiplicação:
             - 0 para ijk
             - 1 para ikj
             - 2 para kij
             - 3 para kji
             - 4 para jik
             - 5 para jki

*/
mymatriz *mmultiplicar(mymatriz *mat_a, mymatriz *mat_b, int tipo)
{
    mymatriz *result = malloc(sizeof(mymatriz));
    int i_max, j_max, k_max; //auxiliares para controle de aninhamento

    if (mat_a->matriz == NULL)
    {
        printf("\nERRO: Matriz A não alocada \n\n");
        exit(1);
    }

    if (mat_b->matriz == NULL)
    {
        printf("\nERRO: Matriz B não alocada \n\n");
        exit(1);
    }

    if ((mat_a->lin != mat_b->lin) || (mat_a->col != mat_b->col))
    {
        printf("\nERRO: As matrizes não são do mesmo tamanho\n");
        exit(1);
    }

    //matriz resultado
    result->matriz = NULL;
    result->lin = mat_a->lin;
    result->col = mat_b->col;

    //realiza a alocação de memória para matriz resultado
    if (malocar(result))
    {
        printf("\nERROR: Erro ao inicializar matriz\n");
        exit(1);
    }
    else
    {
        mzerar(result);
    }

    i_max = mat_a->lin;
    j_max = mat_b->col;
    k_max = mat_a->col;

    int maxA = 0;
    int maxB = 0;
    int maxC = 0;

    switch (tipo)
    {
    case 0: //ijk
        maxA = i_max;
        maxB = j_max;
        maxC = k_max;
        break;

    case 1: //ikj
        maxA = i_max;
        maxB = k_max;
        maxC = j_max;
        break;

    case 2: //kij
        maxA = k_max;
        maxB = i_max;
        maxC = j_max;
        break;

    case 3: //kji
        maxA = k_max;
        maxB = j_max;
        maxC = i_max;
        break;

    case 4: //jik
        maxA = j_max;
        maxB = i_max;
        maxC = k_max;
        break;

    default: //jki
        maxA = j_max;
        maxB = k_max;
        maxC = i_max;
        break;
    }

    for (int a = 0; a < maxA; a++)
    {
        for (int b = 0; b < maxB; b++)
        {
            for (int c = 0; c < maxC; c++)
            {
                result->matriz[a][b] += mat_a->matriz[a][c] * mat_b->matriz[c][b];
            }
        }
    }

    return result;
}