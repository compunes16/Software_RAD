/********************************************************************
 *  @description: Tratamento de Erros - Algoritimos   				
 *  @author: Gustavo Serpeloni										
 * 	@Professor: Antonio Maria Tommaselli							
 *	@Date: 20/02/2018												
 *******************************************************************/
 
 #include "pfotoga.h"

// <1> Tratamento de erros - SIS.c

int bandaExistente(int elem,int* banda,int TAM){	

	int i,contem=0;	
	for (i=1; i <= TAM ; i++){
	    if(elem == banda[i]){
		 		contem = 1;
		 		break;
	    }
    }
	return contem;
}


int verBandaZeradas(int elem,int* banda,int TAM){
	int i,total = 0;
	
	for (i=1;i <= TAM;i++){
		if(elem == banda[i]){
			total++;
		}
	}
	
	printf("\n \n total : %i",total);
	if(total == TAM) return 1;
    else return 0;
}



