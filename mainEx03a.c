#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "toolsv3.h"
#include "matrizv3.h"
#include "matriz-operacoesv3.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int main(int argc, char *argv[]) {

	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	// DECLARAÇÃO de VARIÁVEIS
	mymatriz mat_a, mat_b;
	mymatriz **mmultbloco, **mmult;
	char filename[100];
	FILE *fmat;
	int nr_line;
	int *vet_line = NULL;
	int N, M, La, Lb;
	double start_time, end_time;

        matriz_bloco_t *Vsubmat_a = NULL;
        matriz_bloco_t *Vsubmat_b = NULL;
        int nro_submatrizes=2;

	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	if (argc != 3){
		printf ("ERRO: Numero de parametros %s <matriz_a> <matriz_b>\n", argv[0]);
		exit (1);
	}

	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	//                Leitura da Matriz A (arquivo)
	fmat = fopen(argv[1],"r");
	if (fmat == NULL) {
		printf("Error: Na abertura dos arquivos.");
		exit(1);
	}
	extrai_parametros_matriz(fmat, &N, &La, &vet_line, &nr_line);
	//return 1;
	mat_a.matriz = NULL;
	mat_a.lin = N;
	mat_a.col = La;
	if (malocar(&mat_a)) {
		printf ("ERROR: Out of memory\n");
	}
	filein_matriz (mat_a.matriz, N, La, fmat, vet_line, nr_line);
	free (vet_line);
	fclose(fmat);
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	//               Leitura da Matriz B (arquivo)
	fmat = fopen(argv[2],"r");
	if (fmat == NULL) {
		printf("Error: Na abertura dos arquivos.");
		exit(1);
	}
	extrai_parametros_matriz(fmat, &Lb, &M, &vet_line, &nr_line);
	mat_b.matriz = NULL;
	mat_b.lin = Lb;
	mat_b.col = M;
	if (malocar(&mat_b)) {
		printf ("ERROR: Out of memory\n");
	}
	filein_matriz (mat_b.matriz, Lb, M, fmat, vet_line, nr_line);
	free (vet_line);
	fclose(fmat);
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	printf("\n%%%%%%%%%%%%%%%%\n");
	
	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	//               Operações de Multiplicação
	mmult = (mymatriz **) malloc (sizeof(mymatriz *));
	printf("\n ##### multiplicar_t1 de Matrizes #####\n");
	start_time = wtime();
	mmult[0] = mmultiplicar(&mat_a, &mat_b, 1);
	end_time = wtime();
	mimprimir(mmult[0]);
	printf("\tRuntime: %f\n", end_time - start_time);
	sprintf(filename, "mult_t1.result");
	fmat = fopen(filename,"w");
	fileout_matriz(mmult[0], fmat);
	fclose(fmat);
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	//               Operações de Multiplicação (em bloco)
	mmultbloco = (mymatriz **) malloc (sizeof(mymatriz *));
	printf("\n ##### multiplicar_t1 de Matrizes #####\n");
	start_time = wtime();

	Vsubmat_a = particionar_matriz (mat_a.matriz, N, La, 1, 2);
	Vsubmat_b = particionar_matriz (mat_b.matriz, Lb, M, 0, 2);
	Vsubmat_c = csubmatrizv2 (N, M, nro_submatrizes);

	mmsubmatriz (Vsubmat_a[0], Vsubmat_b[0], Vsubmat_c[0]);
	mmsubmatriz (Vsubmat_a[1], Vsubmat_b[1], Vsubmat_c[1]);
	mmultibloco[0] = msomar(Vsubmat_c[0]->matriz,Vsubmat_c[1]->matriz, 1);
	
	end_time = wtime();
	mimprimir(mmultbloco[0]);
	printf("\tRuntime: %f\n", end_time - start_time);
	sprintf(filename, "mult_t1.result");
	fmat = fopen(filename,"w");
	fileout_matriz(mmultbloco[0], fmat);
	fclose(fmat);
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	//              Comparação dos resultados
	printf("\n ##### Comparação dos resultados da Multiplicação de matrizes #####\n");
	printf("[mult_t0 vs multbloco_t0]\t");
	mcomparar (mat_mult[0],mmultbloco[0]);
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	//                   Liberação de memória
	mliberar(mmult[0]);
	free (mmult[0]);
	mliberar(mmultbloco[0]);
	free (mmultbloco[0]);

	mliberar(&mat_a);
	mliberar(&mat_b);
	free(mmult);
	free(mmultbloco);
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	return 0;
}
