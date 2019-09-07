#include "matrizv3.h"
#include "toolsv3.h"

/*
function msomar
Realiza operação para duas matrizes.
As matrizes envolvidas na adição devem ser da mesma ordem, quer dizer, devem ter o mesmo
número de linhas e colunas. A matriz resultante terá a mesma configuração.
@return res, ponteiro para a matriz resultante
@param mat_a, ponteiro para objeto do tipo mymatriz
@param mat_b, ponteiro para objeto do tipo mymatriz
@param tipo, inteiro que define a ordem de aninhamento dos loops:
             - 0 para ij
             - 1 para ji
*/
mymatriz *msomar (mymatriz *mat_a, mymatriz *mat_b, int tipo){
    mymatriz res;
    int i_max, j_max; //auxiliares para controle de aninhamento

    //verifica se foi alocado memória para a matriz
    if ( (mat_a == NULL) || (mat_b == NULL)) {
        printf ("** Erro: Memoria Insuficiente **\n");
        return NULL;
    }

    //valida se matrizes tem tamanhos compatíveis
    if (mat_a->col != mat_b->col || mat_a->lin != mat_b->lin ){
        printf ("** Erro: Matrizes devem ter mesma configuração para que se possa somar. **\n");
        return -1;
    }

    //matriz resultado
	res.matriz = NULL;
	res.lin = mat_a->lin;
	res.col = mat_a->col;

    //realiza a alocação de memória para matriz resultado
    if (malocar(&res)) {
		printf ("ERROR: Out of memory\n");
	}else{
        mzerar(&res);
    }

    //define aninhamento, conforme parametro tipo
    i_max = mat_a->lin;
    j_max = mat_a->col;
    if (tipo == 1){ //tipo = 1: ordem de aninhamento ji
        i_max = mat_a->col;
        j_max = mat_a->lin;
    }
    
    //realiza a soma dos elementos da matriz a e b
    for (int i = 0; i < i_max; i++){
        for (int j = 0; j < j_max; j++){

            
            if (tipo == 0){ //tipo = 0: ordem de aninhamento ij
                //printf("[a] %d ", mat_a->matriz[i][j] );
                //printf("[b] %d ", mat_b->matriz[i][j]);
                res.matriz[i][j] = mat_a->matriz[i][j] + mat_b->matriz[i][j];
                //printf("[r] %d\n", res.matriz[i][j]);

            }else{ //tipo = 1: ordem de aninhamento ji
                //printf("[a] %d ", mat_a->matriz[i][j] );
                //printf("[b] %d ", mat_b->matriz[i][j]);
                res.matriz[j][i] = mat_a->matriz[j][i] + mat_b->matriz[j][i];
                //printf("[r] %d\n", res.matriz[i][j]);

            }
            
        }
    }

    return &res.matriz;
}


/*
function mmultiplicar
Realiza operação para duas matrizes.
As matrizes envolvidas na multiplicação devem seguir a regra: número de colunas da primeira
matriz deve ser igual ao número de linhas da segunda matriz. A matriz resultante será configurada
tendo o número de linhas da primeira e o número de colunas da segunda. Ex: 3x4 * 4x3 = 3x3
@return res, ponteiro para a matriz resultante
@param mat_a, ponteiro para objeto do tipo mymatriz
@param mat_b, ponteiro para objeto do tipo mymatriz
@param tipo, inteiro que define a ordem de aninhamento dos loops:
             - 0 para ijk
             - 1 para ikj
             - 2 para kij
             - 3 para kji
             - 4 para jik
             - 5 para jki

*/
mymatriz *mmultiplicar (mymatriz *mat_a, mymatriz *mat_b, int tipo){    
    int i_max, j_max, k_max; //auxiliares para controle de aninhamento
    mymatriz res;

    //verifica se foi alocado memória para a matriz
    if ( (mat_a == NULL) || (mat_b == NULL)) {
        printf ("** Erro: Memoria Insuficiente **\n");
        return NULL;
    }

    //valida se matrizes tem tamanhos compatíveis
    if (mat_a->col != mat_b->lin ){
        printf ("** Erro: Matrizes devem ter mesma configuração para que se possa somar. **\n");
        return NULL;
    }

    //matriz resultado
	res->matriz = NULL;
	res->lin = mat_a->lin;
	res->col = mat_b->col;
    
    //realiza a alocação de memória para matriz resultado
    if (malocar(&res)) {
		printf ("ERROR: Out of memory\n");
	}else{
        mzerar(&res);
    }
    printf("lin %d col %d\n", res->lin, res->col);
    //inicializa variáveis de controle dos for`s
    i_max = mat_a->lin;
    j_max = mat_b->col;
    k_max = mat_a->col; //ou mat_b->lin

    //define aninhamento, conforme parametro tipo
    int maxA = 0;
    int maxB = 0;
    int maxC = 0;
    
    switch(tipo){
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

    for (int a = 0; a < maxA; a++){
        for (int b = 0; b < maxB; b++){
            for (int c = 0; c < maxC; c++){
                res->matriz[a][b] += mat_a->matriz[a][c] * mat_b->matriz[c][b];
                //printf("a[%d][%d] = %d\n", i, k, mat_a->matriz[i][k] );
                //printf("b[%d][%d] = %d\n", k, j, mat_b->matriz[k][j] );
                //printf("%d x %d = %d (%d)\n", mat_a->matriz[i][k], mat_b->matriz[k][j], mat_a->matriz[i][k] * mat_b->matriz[k][j], res.matriz[i][j]);
            }
        }
    }
    printf("lin %d col %d\n", res->lin, res->col);
    return &res;
}