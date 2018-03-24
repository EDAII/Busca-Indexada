#include <stdio.h>
#include <string.h>
#include "../inc/ordenarRegistro.h"

typedef struct Registro{
	char nomePais[60], abreviatura[3];
}Registro;

int ordenarRegistros(char *nomeArquivo){
	FILE *arqPrincipal;
	int qtdRegistros, i = 0, indexMin;
	
	arqPrincipal = fopen(nomeArquivo, "r");
	
	if (arqPrincipal == NULL){
		puts("\nErro na leitura do arquivo.");
		return -1;
  	}
	fscanf(arqPrincipal,"%d\n", &qtdRegistros);	//Leitura da primeira linha com quantidade de registros
	Registro vetorRegistros[qtdRegistros+1], vetorRegistrosAux[qtdRegistros+1];

	while((fscanf(arqPrincipal,"%s\t%s\n", vetorRegistros[i].abreviatura, vetorRegistros[i].nomePais))!=EOF)	//Carrega registros para memoria principal
		i++;

	fclose(arqPrincipal);

	for(i = 0; i < qtdRegistros; i++){	//Ordenacao dos registros com o metodo SelectionSort
		indexMin = i;
		for(int j = i + 1; j <= qtdRegistros; j++){			
			if(strcmp(vetorRegistros[indexMin].abreviatura, vetorRegistros[j].abreviatura) > 0)
				indexMin = j;
		}
		if(indexMin != i){
			strcpy(vetorRegistrosAux->abreviatura, vetorRegistros[indexMin].abreviatura);
			strcpy(vetorRegistrosAux->nomePais, vetorRegistros[indexMin].nomePais);

			strcpy(vetorRegistros[indexMin].abreviatura, vetorRegistros[i].abreviatura);
			strcpy(vetorRegistros[indexMin].nomePais, vetorRegistros[i].nomePais);

			strcpy(vetorRegistros[i].abreviatura, vetorRegistrosAux->abreviatura);
			strcpy(vetorRegistros[i].nomePais, vetorRegistrosAux->nomePais);
		}
	}

	arqPrincipal = fopen(nomeArquivo, "w");

	if (arqPrincipal == NULL){
		puts("\nErro na leitura do arquivo.");
		return -1;
  	}

	fprintf(arqPrincipal, "%d\n", qtdRegistros);

	for(i =0; i<qtdRegistros; i++)	//Escreve no arquivo os dados ordenados
		fprintf(arqPrincipal, "%s\t%s\n", vetorRegistros[i].abreviatura, vetorRegistros[i].nomePais);
	

	fclose(arqPrincipal);
	return 0;
}

