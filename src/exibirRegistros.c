#include <stdio.h>
#include <string.h>
#include "../inc/exibirRegistros.h"

int exibirRegistros(char *nomeArquivo){
	FILE *arqPrincipal;
	char abreviatura[3], nomePais[60];
	int qtdRegistros;

	arqPrincipal = fopen(nomeArquivo, "r");
	
	if (arqPrincipal == NULL){
		puts("\nErro na leitura do arquivo.");
		return -1;
  	}
	fscanf(arqPrincipal,"%d\n", &qtdRegistros);
	while((fscanf(arqPrincipal,"%s\t%s\n", abreviatura, nomePais))!=EOF)
		printf("%s\t%s\n", abreviatura, nomePais);
	
	fclose(arqPrincipal);
	return 0;
}
