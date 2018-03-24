#include <stdio.h>
#include <string.h>
#include "../inc/main.h"
#include "../inc/apagarRegistro.h"
#include "../inc/buscarRegistro.h"
#include "../inc/exibirRegistros.h"
#include "../inc/gerarIndex.h"
#include "../inc/ordenarRegistro.h"
#include "../inc/inserirRegistro.h"

typedef struct Registro{
	char abreviatura[3], nomePais[60];
}Registro;

//------------------>  FUNCAO PRINCIPAL
int main(){

	int opcao, status;
	char nomeArquivo[] = "bin/ListaPaises.txt", abreviaturaBusca[3];
	
	while(1){
		puts("\nEscolha uma opcao:\n[1] - ORDENAR lista de registros;\n[2] - GERAR novo arquivo index;\n[3] - BUSCAR registro;\n[4] - EXIBIR todos os registros;\n[5] - APAGAR registro;\n[6] - INSERIR registro;\n[0] - SAIR;");
		scanf("%d", &opcao);
		
		switch(opcao){
		case 1:
			status = ordenarRegistros(nomeArquivo);
			if (status == 0)
				puts("\nArquivo ordenado com sucesso!!!");
			else
				puts("\nErro ao ordenado arquivo.");
			break;

		case 2:
			status = gerarArquivoIndex(nomeArquivo);
			if (status == 0)
				puts("\nArquivo gerado com sucesso!!!");
			else
				puts("\nErro ao gerar arquivo.");
			break;
		
		case 3:
			puts("\nDigite a abreviatura de busca: ");
			scanf("%s", abreviaturaBusca);
			buscarRegistro(nomeArquivo, 0, abreviaturaBusca);
			break;

		case 4:
			status = exibirRegistros(nomeArquivo);
			if (status != 0)
				puts("\nErro ao exibir registros!!!");
			break;

		case 5:
			status = apagarRegistro(nomeArquivo);
			if (status == 0)
				puts("\nRegistro apagado com sucesso!!!");
			else
				puts("\nErro ao apagar arquivo.");
			break;

		case 6:
			status = inserirRegistro(nomeArquivo);
			if (status == 0)
				puts("\nRegistro inserido com sucesso!!!");
			else
				puts("\nErro ao inserido arquivo.");
			break;

		case 0:
			return 0;

		default:
			puts("\nOPCAO INVALIDA...\n\nEscolha novamente!");
			break;
		}

	}
	return 0;
}
