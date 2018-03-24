#include <stdio.h>
#include <string.h>
#include "../inc/gerarIndex.h"

int gerarArquivoIndex(char *nomeArquivo){
	printf ("%s", nomeArquivo);
	FILE *arqPrincipal;
	char abreviatura[3], nomePais[60];
	int tamanhoCluster, contadorIndex = 0, qtdRegistros;
	
	puts("\nDigite o tamanho do cluster a alocar: ");
	scanf("%d", &tamanhoCluster);
	arqPrincipal = fopen(nomeArquivo, "r");

	FILE *arqIndex;
	arqIndex = fopen("bin/kIndex.txt", "w");
	
	if (arqPrincipal == NULL){
		printf("\nErro na leitura do arquivo de listas.");
		return -1;
  	}
	if (arqIndex == NULL){
		printf("\nErro na criacao do arquivo de indices.");
		return -1;
  	}
	fprintf(arqIndex, "%d\n", tamanhoCluster);
	fscanf(arqPrincipal,"%d\n", &qtdRegistros);
	while((fscanf(arqPrincipal,"%s\t%s\n", abreviatura, nomePais))!=EOF){
		if(contadorIndex == 0 || contadorIndex == tamanhoCluster){
			fprintf(arqIndex, "%s\n", abreviatura);
			contadorIndex = 0;
		}
		contadorIndex++;
	}

	fclose(arqIndex);
	fclose(arqPrincipal);
	return 0;
}
