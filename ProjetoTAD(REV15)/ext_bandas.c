/********************************************************************
 *  @description: Algoritimos que gravam os valores referente ao tipo de camera utilizada suas 
 			bandas e local mapeado; 		    				
 *  @author: Gustavo Serpeloni										
 *  @Professor: Imai							
 *  @Date: 26/05/2020												
 *******************************************************************/

#include "pfotoga.h"
#define MAX 50000


void ext_bandas(char* dados){
	setlocale(LC_NUMERIC, "pt_BR");
	FILE *arq;
	arq = fopen("banda-dt-2016.txt", "r");
	char leitura[300];
	char str1[5], str2[10];
	int i = 0, cont = 0, total=0;
	float dts[30];
	//double dt;
	
	//Iniciando dts: 
	for(i=0; i < 30; i ++) dts[i] = 0;
	
	printf("\n --------  Bandas ARQ. Externo -------- \n\n");
		if(arq == NULL) {
			printf("Caminho ou Arquivo nao encontrado ! \n\n");
			ext_bandas(dados);
			fclose(arq);
			system("pause");
		}else {
	
				while ( fgets(leitura,MAX,arq) != NULL) {
				    strcpy(dados,leitura);
				 	cont ++;
				}
				total = cont -1;
				printf("1. Qtd - Dados coletados: %i", total);
			
			//Movendo o curso para a segunda linha: 
				rewind(arq);
				fseek(arq,7*sizeof(char),SEEK_CUR);
				printf("\n\n ----- Imprimindo dados gravados do arquivo ------ \n");
			
			//Gravando Numero da Banda e Valor referente a banda especifica:
			 //2 - Gravar os dados nas estruturas dts[??];
				cont = 0;	 
				while( fscanf(arq,"%s	%s", str1, str2) != EOF ) {
				//	printf("%s  %s",str1, str2);
					
					//Necessario trocar dados de "." por "," no windows
					dts[cont] = atof(str2);
				//	printf("\t - dts: %.3lf\n",dts[cont]);
					cont++;
				}
				
			//3- Imprimindo valores referente ao vetor de Dts: 
				printf("\n\n ------- Imprimindo valores no vetor de DTS ------- \n");
				
				for(i=0; i < total; i++){
					BAND[10].dt[i] = dts[i];
					printf("%.3lf\n", BAND[10].dt[i]);
				}			
    } //end else


}// end function ext_bandas




