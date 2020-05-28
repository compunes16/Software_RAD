/********************************************************************
 *  @description: Algoritimos para tratamento de ARQUIVOS  				
 *  @author: Gustavo Serpeloni										
 *  @Professor: Antonio Maria Tommaselli							
 *  @Date: 08/08/2018												
 *******************************************************************/
 
 #include "pfotoga.h"
 
 
void exibirArquivo(){
	
	FILE* arq;
	char leitura[1000];
	char caminho[300];
	camEntrada(caminho);
	
	arq = fopen(caminho,"rt");
	
	while ( fgets(leitura,MAX,arq) != NULL){
		printf("\n %s",leitura);
		
	}
	
	fclose(arq);
}				



void ModificaCaminho(char *saida){ // DSM_5m extensão do arquivo nova;
	int i;
	for(i=0; i < strlen(saida); i++) {
		if(saida[i] == '.') { 
			saida[i] = '\0';
		}
	}
	strcat(saida,"W.xyz"); // adc. NEW no final do arquivo DSM_5m;
}//end funcaos



void camEntrada(char* caminho){	// função para pegar o caminho dos arquivos
    fflush(stdin);
	printf("<.> Insira o caminho de entrada do arquivo com seu nome e extensao :\n");
	gets(caminho); // pega o caminho em formato de string;
}		
