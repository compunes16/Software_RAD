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
	char leitura[70], dados[70];
	int band;
	double dt[6];
	//double dt;
	
	
	
	printf("\n -- Bandas Externas ::");
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
	
	
		rewind(arq);
		fseek(arq,7*sizeof(char),SEEK_CUR);
		printf("\n\n2- Imprimindo dados gravados do arquivo !\n");
	
		//Gravando Numero da Banda e Valor referente a banda especifica:
		 //2 - Gravar os dados nas estruturas 
		while( fscanf(arq,"%i	%s", &band, dt) != EOF ) {
			printf("%i   %s \t",band, dt);
		}
		

	
		
    }


}// end function ext_bandas




