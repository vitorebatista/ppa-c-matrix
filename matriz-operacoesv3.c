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
mymatriz *mmultiplicar (mymatriz *mat_a, mymatriz *mat_b, int tipo){
    mymatriz *res = malloc(sizeof(mymatriz));
    int i_max, j_max, k_max; //auxiliares para controle de aninhamento

    //verifica se foi alocado memória para a matriz
    if ( (mat_a == NULL) || (mat_b == NULL)) {
        printf ("** Erro: Memoria Insuficiente **\n");
        return NULL;
    }

    //valida se matrizes tem tamanhos compatíveis
    if (mat_a->col != mat_b->lin ){
        printf ("** Erro: Matrizes devem ter mesma configuração para que se possa multiplicar. **\n");
        return NULL;
    }

    //matriz resultado
	res->matriz = NULL;
	res->lin = mat_a->lin;
	res->col = mat_b->col;

    //realiza a alocação de memória para matriz resultado
    if (malocar(res)) {
		printf ("ERROR: Out of memory\n");
	        exit(1);
	}else{
        mzerar(res);
    }

    //inicializa variáveis de controle dos for`s
    i_max = mat_a->lin;
    j_max = mat_b->col;
    k_max = mat_a->col; //ou mat_b->lin

    //define aninhamento, conforme parametro tipo
    switch(tipo){
        case 0: //ijk
            for (int i = 0; i < i_max; i++){
                for (int j = 0; j < j_max; j++){
                    for (int k = 0; k < k_max; k++){
                        res->matriz[i][j] += mat_a->matriz[i][k] * mat_b->matriz[k][j];
                        //printf("a[%d][%d] = %d\n", i, k, mat_a->matriz[i][k] );
                        //printf("b[%d][%d] = %d\n", k, j, mat_b->matriz[k][j] );
                        //printf("%d x %d = %d (%d)\n", mat_a->matriz[i][k], mat_b->matriz[k][j], mat_a->matriz[i][k] * mat_b->matriz[k][j], res.matriz[i][j]);
                    }
                }
            }
            break;

        case 1: //ikj
            for (int i = 0; i < i_max; i++){
                for (int k = 0; k < k_max; k++){
                    for (int j = 0; j < j_max; j++){
                        res->matriz[i][j] += mat_a->matriz[i][k] * mat_b->matriz[k][j];
                    }
                }
            }
            break;

        case 2: //kij
            for (int k = 0; k < k_max; k++){
                for (int i = 0; i < i_max; i++){
                    for (int j = 0; j < j_max; j++){
                        res->matriz[i][j] += mat_a->matriz[i][k] * mat_b->matriz[k][j];
                    }
                }
            }
            break;

        case 3: //kji
            for (int k = 0; k < k_max; k++){
                for (int i = 0; i < i_max; i++){        
                    for (int j = 0; j < j_max; j++){
                        res->matriz[i][j] += mat_a->matriz[i][k] * mat_b->matriz[k][j];
                    }
                }
            }
            break;

        case 4: //jik
            for (int j = 0; j < j_max; j++){
                for (int i = 0; i < i_max; i++){
                    for (int k = 0; k < k_max; k++){            
                        res->matriz[i][j] += mat_a->matriz[i][k] * mat_b->matriz[k][j];
                    }
                }
            }
            break;

        default: //jki
            for (int j = 0; j < j_max; j++){
                for (int k = 0; k < k_max; k++){
                    for (int i = 0; i < i_max; i++){
                        res->matriz[i][j] += mat_a->matriz[i][k] * mat_b->matriz[k][j];
                    }
                }
            }
            break;
            
    }

    return res;
}
int multiplicar_submatriz(matriz_bloco_t *mat_suba, matriz_bloco_t *mat_subb, matriz_bloco_t *mat_subc)
{

    //verifica se foi alocado memória para as matrizes
    if ( (mat_suba == NULL) || (mat_subb == NULL) || (mat_subc == NULL)) {
        printf ("** Erro: Memoria Insuficiente **\n");
        return (-1);
    }

    for (int i = mat_suba->bloco->lin_inicio; i < mat_suba->bloco->lin_fim; i++)
    {
        for (int j = mat_subb->bloco->col_inicio; j < mat_subb->bloco->col_fim; j++)
        {
            for (int k = mat_suba->bloco->col_inicio; k < mat_suba->bloco->col_fim; k++)
            {
                mat_subc->matriz->matriz[i][j] += mat_suba->matriz->matriz[i][k] * mat_subb->matriz->matriz[k][j];
            }
        }
    }

    return 0;
}

matriz_bloco_t **particionar_matriz(int **matriz, int mat_lin, int mat_col, int orientacao, int divisor)
{
    matriz_bloco_t **matriz_bloco = NULL;
    matriz_bloco = (matriz_bloco_t **)calloc(divisor, sizeof(matriz_bloco_t *));

    //verifica se foi alocado memória para a matriz
    if ( (matriz == NULL) || (matriz_bloco == NULL)) {
        printf ("** Erro: Memoria Insuficiente **\n");
        return NULL;
    }

    //verificar se divisor tem valor válido
    if (orientacao == 0 && (divisor > mat_lin)){
        printf ("** Erro: Divisor (%d) maior que o número de linhas (%d) **\n", divisor, mat_lin);
        return NULL;
    }else{
        if (orientacao == 1 && (divisor > mat_col)){
            printf("** Erro: Divisor (%d) maior que o número de colunas (%d) **\n", divisor, mat_col);
            return NULL;
        }
    }

    //aloca memória para cada subdivisao da matriz original
    for (int i = 0; i < divisor; i++)
    {
        matriz_bloco[i] = (matriz_bloco_t *)malloc(sizeof(matriz_bloco_t));
        matriz_bloco[i]->bloco = (bloco_t *)malloc(sizeof(bloco_t));
    }

    //aloca espaço para matriz (mymatriz)
    mymatriz *new_matriz = (mymatriz *)malloc(sizeof(mymatriz));
    new_matriz->matriz = matriz;
    new_matriz->lin = mat_lin;
    new_matriz->col = mat_col;

    if (orientacao == 0)
    {
        int lin_div = mat_lin / divisor; //tamanho do bloco (linhas)

        for (int i = 0; i < divisor; i++)
        {
            matriz_bloco[i]->matriz = new_matriz;
            matriz_bloco[i]->bloco->lin_inicio = (lin_div * i); 
            matriz_bloco[i]->bloco->lin_fim = (i + 1) * lin_div;
            matriz_bloco[i]->bloco->col_inicio = 0;
            matriz_bloco[i]->bloco->col_fim = mat_col;
        }
        //ajusta último bloco para abranger as linhas restantes
        matriz_bloco[divisor - 1]->bloco->lin_fim = mat_lin;
    }
    else
    {
        int lin_div = mat_col / divisor; //tamanho do bloco (colunas)
        for (int i = 0; i < divisor; i++)
        {
            matriz_bloco[i]->matriz = new_matriz;
            matriz_bloco[i]->bloco->lin_inicio = 0;
            matriz_bloco[i]->bloco->lin_fim = mat_lin;
            matriz_bloco[i]->bloco->col_inicio = i * lin_div;
            matriz_bloco[i]->bloco->col_fim = (i + 1) * lin_div;
        }

        //ajusta último bloco para abranger as colunas restantes
        matriz_bloco[divisor - 1]->bloco->col_fim = mat_col;
    }
    return matriz_bloco;
}

matriz_bloco_t **csubmatrizv2(int mat_lin, int mat_col, int divisor)
{
    matriz_bloco_t **matriz_bloco = NULL;
    matriz_bloco = (matriz_bloco_t **)calloc(divisor, sizeof(matriz_bloco_t *));

    if (!matriz_bloco)
    {
        printf("ERROR: Out of memory\n");
        exit (1);
    }

    for (int i = 0; i < divisor; i++)
    {
        matriz_bloco[i] = (matriz_bloco_t *)malloc(sizeof(matriz_bloco_t));
        matriz_bloco[i]->bloco = (bloco_t *)malloc(sizeof(bloco_t));
        matriz_bloco[i]->matriz = (mymatriz *) malloc(sizeof(mymatriz));
        matriz_bloco[i]->matriz->lin = mat_lin;
        matriz_bloco[i]->matriz->col = mat_col;
        malocar(matriz_bloco[i]->matriz);
        mzerar(matriz_bloco[i]->matriz);
    }

    for (int i = 0; i < divisor; i++)
    {
        matriz_bloco[i]->bloco->lin_inicio = 0;
        matriz_bloco[i]->bloco->lin_fim = mat_lin;
        matriz_bloco[i]->bloco->col_inicio = 0;
        matriz_bloco[i]->bloco->col_fim = mat_col;
    }
    return matriz_bloco;
}
