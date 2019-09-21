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
    //printf("\nENTROU NO mmultiplicar \n\n");
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

int multiplicar_submatriz (matriz_bloco_t *mat_suba, matriz_bloco_t *mat_subb, matriz_bloco_t *mat_subc)
{
    printf("Entrou multiplicar_submatriz");
    // Percorre Linha de A
    for (int linA = 0; linA < mat_suba[0].mat_lin; linA++)
        // Percorre Coluna de B
        for (int colB = 0; colB < mat_subb[0].mat_col; colB++)
        {
            mat_subc[0].matriz[linA][colB] = 0; // Zera posição em C
            // Percorre Coluna A = Linha B
            for (int linC = 0; linC < mat_suba[0].mat_lin; linC++)
                mat_subc[0].matriz[linA][colB] += mat_suba[0].matriz[linA][linC] * mat_subb[0].matriz[linC][colB];
        }
    return 0;
}


// int gerar_submatriz(int **mat_origem, matriz_bloco_t *submatriz, bloco_t *bloco)
// {

// 	int posCol = 0;
// 	int posLin = 0;

// 	for (int lin = bloco->lin_inicio; lin < bloco->lin_fim; lin++)
// 	{
// 		for (int col = bloco->col_inicio; col < bloco->col_fim; col++)
// 		{
// 			submatriz[0].matriz[posLin][posCol] = mat_origem[lin][col];
// 			posCol += 1;
// 		}
// 		posLin += 1;
// 		posCol = 0;
// 	}
// 	return 0;
// }

matriz_bloco_t **particionar_matriz(int **matriz, int mat_lin, int mat_col, int orientacao, int divisor)
{
	matriz_bloco_t **sub_matriz = malloc(divisor * sizeof(matriz_bloco_t *));

	int tam_limite = orientacao == 1 ? mat_col : mat_lin;
	int tam_carga = 1;
	int resto = 0;
	int use_resto = 0;
	int resto_final = 0;

	// Define uma Distribuição de Carga Simples
	// Enquanto o tamanho de cada carga multiplicado pela
	// quantidade de processamentos for menor que o limite
	// alimenta a carga
	while ((tam_carga * divisor) <= tam_limite)
	{
		tam_carga += 1;
	}

	// Retorna ao estado anterior a superação do limite
	tam_carga -= 1;

	// Verifica se há "resto" de alocação
	if (tam_carga * divisor < tam_limite)
	{
		resto = tam_limite - (tam_carga * divisor);
	}

	// Se carga estiver zerada, há mais processamentos que limites
	if (tam_carga == 0)
	{
		printf("Há mais processamentos do que submatrizes, favor rever quantidade de processos.\n");
		exit(1);
	}
	else
	{
		for (int pos_submatriz = 0; pos_submatriz < divisor; pos_submatriz++)
		{

			// Distribui o resto de carga
			if (resto != 0)
			{
				use_resto = 1;
				resto -= 1;
			}
			else
			{
				use_resto = 0;
			}

			bloco_t *blocoX = malloc(sizeof(bloco_t));
			if(blocoX == NULL){
				printf ("ERROR: Out of memory\n");
				exit(0);
			}
			// Gera o Bloco para busca da SubMatriz
			blocoX->col_inicio = 0;
			blocoX->col_fim = mat_col;
			blocoX->lin_inicio = 0;
			blocoX->lin_fim = mat_lin;
			if (orientacao == 1)
			{
				blocoX->col_inicio = resto_final;
				blocoX->col_fim = resto_final + tam_carga + use_resto;
			}
			else
			{
				blocoX->lin_inicio = resto_final;
				blocoX->lin_fim = resto_final + tam_carga + use_resto;
			}
			resto_final += tam_carga + use_resto;
			//int **matrizX;
			mymatriz matrizX;
			matrizX.matriz = NULL;
			matrizX.lin = orientacao == 1 ? mat_lin : tam_carga + use_resto;
			matrizX.col = orientacao == 1 ? tam_carga + use_resto : mat_col;
			
			if (malocar(&matrizX))
			{
				printf ("ERROR: Out of memory\n");
				exit(0);
			}
			mzerar(&matrizX);
			
			// Gera o Bloco correto
			blocoX->col_inicio = 0;
			blocoX->col_fim = mat_col;
			blocoX->lin_inicio = 0;
			blocoX->lin_fim = mat_lin;
			if (orientacao == 1)
			{
				blocoX->col_fim = tam_carga + use_resto;
			}
			else
			{
				blocoX->lin_fim = tam_carga + use_resto;
			}
			
			sub_matriz[pos_submatriz] = (matriz_bloco_t *)malloc(sizeof(matriz_bloco_t));
			sub_matriz[pos_submatriz]->bloco = blocoX;
			sub_matriz[pos_submatriz]->matriz = matrizX.matriz;
			printf ("GEROU mymatriz matrizX\n");
			mliberar(&matrizX);
		}
	}

	return sub_matriz;
}

matriz_bloco_t **csubmatrizv2(int mat_lin, int mat_col, int divisor)
{
	matriz_bloco_t **sub_matriz = malloc(divisor * sizeof(matriz_bloco_t *));

	for (int pos_submatriz = 0; pos_submatriz < divisor; pos_submatriz++)
	{
		bloco_t *blocoX = malloc(sizeof(bloco_t));
		if (blocoX == NULL)
		{
			printf ("ERROR: Out of memory\n");
			exit(0);
		}
		blocoX->col_inicio = 0;
		blocoX->col_fim = mat_col;
		blocoX->lin_inicio = 0;
		blocoX->lin_fim = mat_lin;

		mymatriz matrizX;
		matrizX.matriz = NULL;
		matrizX.lin = mat_lin;
		matrizX.col = mat_col;
		if (malocar(&matrizX))
		{
			printf ("ERROR: Out of memory\n");
			exit(0);
		}
		mzerar(&matrizX);

		sub_matriz[pos_submatriz] = (matriz_bloco_t *)malloc(sizeof(matriz_bloco_t));
		sub_matriz[pos_submatriz]->bloco = blocoX;
		sub_matriz[pos_submatriz]->matriz = matrizX.matriz;
		mliberar(&matrizX);
	}

	return sub_matriz;
}