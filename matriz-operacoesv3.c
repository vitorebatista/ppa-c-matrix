#include "matrizv3.h"
#include "toolsv3.h"

/*
function msomar
Realiza a soma de duas matrizes.
As matrizes devem ter o mesmo número de linhas e colunas, sendo o
resultado uma nova matriz de mesmo tamanho.
@return res, ponteiro para a matriz resultante
@param mat_a, ponteiro para objeto do tipo mymatriz
@param mat_b, ponteiro para objeto do tipo mymatriz
@param tipo, inteiro que define a ordem de aninhamento dos loops:
             - 0 para ij
             - 1 para ji
*/
mymatriz *msomar (mymatriz *mat_a, mymatriz *mat_b, int tipo){
    mymatriz temp;
    mymatriz *result = malloc(sizeof(mymatriz));
    int i_max, j_max; //auxiliares para controle de aninhamento

    //verifica se foi alocado memória para a matriz
    if ( (mat_a == NULL) || (mat_b == NULL)) {
        printf ("** Erro: Memoria Insuficiente **\n");
        return NULL;
    }

    //valida se matrizes tem tamanhos compatíveis
    if (mat_a->col != mat_b->col || mat_a->lin != mat_b->lin ){
        printf ("** Erro: Matrizes devem ter mesma configuração para que se possa somar. **\n");
        return NULL;
    }

    //matriz resultado
	temp.matriz = NULL;
	temp.lin = mat_a->lin;
	temp.col = mat_a->col;

    //realiza a alocação de memória para matriz resultado
    if (malocar(&temp)) {
		printf ("ERROR: Out of memory\n");
	}else{
        mzerar(&temp);
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
            // printf("[i] %d ", i );
            // printf("[j] %d ", j );
            if (tipo == 0){ //tipo = 0: ordem de aninhamento ij
                // printf("[a] %d ", mat_a->matriz[i][j] );
                // printf("[b] %d ", mat_b->matriz[i][j]);
                temp.matriz[i][j] = mat_a->matriz[i][j] + mat_b->matriz[i][j];
                // printf("[r] %d\n", result.matriz[i][j]);
            }else{ //tipo = 1: ordem de aninhamento ji
                // printf("[a1] %d ", mat_a->matriz[i][j] );
                // printf("[b1] %d ", mat_b->matriz[i][j]);
                temp.matriz[j][i] = mat_a->matriz[j][i] + mat_b->matriz[j][i];
                // printf("[r1] %d\n", result.matriz[i][j]);
            }
            
        }
    }
    result->matriz = temp.matriz;
    result->lin = temp.lin;
    result->col = temp.col;
    return result;
}


/*
function mmultiplicar
Realiza a multiplicação de duas matrizes.
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
    mymatriz temp;
    mymatriz *result = malloc(sizeof(mymatriz));
    int i_max, j_max, k_max; //auxiliares para controle de aninhamento
    
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
	temp.matriz = NULL;
	temp.lin = mat_a->lin;
	temp.col = mat_b->col;
    
    //realiza a alocação de memória para matriz resultado
    if (malocar(&temp)) {
		printf ("ERROR: Out of memory\n");
	}else{
        mzerar(&temp);
    }
    printf("lin %d col %d\n", temp.lin, temp.col);
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
                temp.matriz[a][b] += mat_a->matriz[a][c] * mat_b->matriz[c][b];
                // printf("a[%d][%d] = %d\n", a, c, mat_a->matriz[a][c] );
                // printf("b[%d][%d] = %d\n", c, b, mat_b->matriz[c][b] );
                // printf("%d x %d = %d (%d)\n", mat_a->matriz[a][c], mat_b->matriz[c][b], mat_a->matriz[a][c] * mat_b->matriz[c][b], result.matriz[a][b]);
            }
        }
    }

    result->matriz = temp.matriz;
    result->lin = temp.lin;
    result->col = temp.col;
    return result;
}