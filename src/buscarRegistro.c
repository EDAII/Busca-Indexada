#include <stdio.h>
#include <string.h>
#include "../inc/buscarRegistro.h"

int buscarRegistro(char *nomeArquivo, int opcao, char *abreviaturaBusca){
	FILE *arqPrincipal, *arqIndex;
	char abreviaturaPrincipal[3], abreviaturaAux[3], nomePais[60];
	int contadorIndex = 0, contadorIndexAux = 0, tamanhoCluster, flag = 0, qtdRegistros;

//Abre os arquivos de registro
	arqPrincipal = fopen(nomeArquivo, "r");
	arqIndex = fopen("bin/kIndex.txt", "r");

	if (arqPrincipal == NULL || arqIndex == NULL){
		puts("\nErro na leitura do arquivo.");
		return -1;
  	}

//Realiza a leitura da primeira linha do arquivo de indice com dados referentes ao tamanho dos clusters e da quantidade de registros
	fscanf(arqIndex,"%d\n", &tamanhoCluster);
	while((fscanf(arqIndex,"%s\n", abreviaturaPrincipal))!=EOF){		//Enquanto nao for o final do arquivo faca	
		if(strcmp(abreviaturaPrincipal, abreviaturaBusca) == 0)	//Se a linha atual for igual a busca sair do loop
			break;
		

		if(contadorIndex > 0){		//Verifica se nao e a primeira linha do arquivo (Sem abreviatura para comparar)
			if((strcmp(abreviaturaPrincipal, abreviaturaBusca) > 0) && (strcmp(abreviaturaAux, abreviaturaBusca) < 0))	//compara a abreviatura de busca com a abreviatura anterior e a posterior
				break;
				
		}
		strcpy(abreviaturaAux, abreviaturaPrincipal);	// copia a abreviatura atual para a variavel auxiliar
		contadorIndex++;
	}

	if(contadorIndex > 0){		//Verifica se nao e a primeira linha do arquivo (Sem abreviatura para comparar)
		contadorIndex--;
	}
	
	fclose(arqIndex);	
	contadorIndex = tamanhoCluster * contadorIndex;	//calcula a posicao real do registro
	fscanf(arqPrincipal,"%d\n", &qtdRegistros);

	while((fscanf(arqPrincipal,"%s\t%s\n", abreviaturaPrincipal, nomePais))!=EOF){
		if(contadorIndexAux >= contadorIndex){
			if (strcmp(abreviaturaPrincipal, abreviaturaBusca) == 0){
				if(opcao == 1 || opcao == 2){
					return 0;
				}
				printf("%s\t%s", abreviaturaPrincipal, nomePais);	//exibe o cadastro desejado
				flag = 2;
				break;
			}
		}
		
		if(contadorIndexAux >= (contadorIndex + tamanhoCluster))
			break;
		contadorIndexAux++;
	}

//Tratamento do retorno caso o registro nao tenha sido encontrado	
	if (flag != 2){
		if(opcao == 2)
			return 1;		
		puts("\nRegistro nao encontrado.");
		if(opcao == 1)
			return -2;		
	}

	fclose(arqPrincipal);
	return 0;
}
