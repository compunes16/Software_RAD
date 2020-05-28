/********************************************************************
 *  @description: Algoritimos que gravam os valores referente ao tipo de camera utilizada suas 
 			bandas e local mapeado; 		    				
 *  @author: Gustavo Serpeloni										
 *  @Professor: Imai							
 *  @Date: 26/05/2020												
 *******************************************************************/

#include "pfotoga.h"
#define MAX 50000

void ext_bandas(){

	FILE *arq;
	arq = fopen("banda-dt-2016.txt", "r");
	char leitura[70], dados[70];;
	
	
	
	printf("\n -- Bandas Externas ::");
	system("pause");
	if(arq == NULL) {
		printf("Caminho ou Arquivo nao encontrado ! \n\n");
		ext_bandas();
		fclose(arq);
		system("pause");
	}else {
	
		while ( fgets(leitura,MAX,arq) != NULL) {
		 	strcpy(dados,leitura);
		 	printf("%s",leitura);
		}
		fclose(arq);

    }


}// end function ext_bandas




