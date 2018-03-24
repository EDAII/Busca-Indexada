#include <stdio.h>
#include <string.h>
#include "../inc/apagarRegistro.h"
#include "../inc/buscarRegistro.h"

int apagarRegistro(char *nomeArquivo){

	char abreviaturaBusca[3];
	puts("Digite a abreviatura do pais a ser apagado: ");
	scanf("%s", abreviaturaBusca);

	if (buscarRegistro(nomeArquivo, 1, abreviaturaBusca) != 0){
		puts("Registro nao existe.");
		return 0;
	}
	else {
		FILE *arqPrincipal, *arqTemp;
		char abreviatura[3], nomePais[60];
		int qtdRegistros;
	
		arqPrincipal = fopen(nomeArquivo, "r");
		arqTemp = fopen("bin/ListaPaisesTemp.txt", "w");
	
		if (arqPrincipal == NULL || arqTemp == NULL){
			puts("\nErro na leitura do arquivo.");
			return -1;
  		}
		fscanf(arqPrincipal,"%d\n", &qtdRegistros);
		while((fscanf(arqPrincipal,"%s\t%s\n", abreviatura, nomePais))!=EOF){
			if(strcmp(abreviatura, abreviaturaBusca) != 0){			
				fprintf(arqTemp, "%s\t%s\n", abreviatura, nomePais);
			}
		}
		
		fclose(arqPrincipal);
		fclose(arqTemp);

		arqPrincipal = fopen(nomeArquivo, "w");
		arqTemp = fopen("bin/ListaPaisesTemp.txt", "r");
	
		if (arqPrincipal == NULL || arqTemp == NULL){
			puts("\nErro na leitura do arquivo.");
			return -1;
  		}
		fprintf(arqPrincipal,"%d\n", --qtdRegistros);
		while((fscanf(arqTemp,"%s\t%s\n", abreviatura, nomePais))!=EOF)
			fprintf(arqPrincipal, "%s\t%s\n", abreviatura, nomePais);
		
		fclose(arqPrincipal);
		fclose(arqTemp);
	}	
	remove("bin/ListaPaisesTemp.txt");
	return 0;
}
