
/****************************************************************************  
 *																			
 *  @name::    PROJETO DE PESQUISA  - AUTOMAÇÃO DO PROCESSO DE FOTOGAMETRIA 
 *  @author::  GUSTAVO  VINICIUS C. SERPELONI								
 *  @project:: ANTONIO M.G. TOMMASELLI										
 *  @date :	   02/03//17 12:24 												
 *  @version:: 10															
 *																			
 ************************************************************************** */


#include "pfotoga.h"
#include "sis.h"


int main () {
    setlocale(LC_ALL, "Portuguese"); 
    
	char x,continua;	
	FILA   *F;
	DADOS  *D;
	SISRIK *SK;
	bandaGravacao();
		
	fflush(stdin); 
	Menu(F,SK); //Inicio do programa principal
	//ext_bandas(); // Testando as bandas de entrada externas





/*	-- Utilizando Menu de intercao com o usuario : 
	do {
		system("cls");
		fflush(stdin); 
		Menu(F,SK);
	    
		printf("\n Deseja Continuar S/N : ");
		continua = getche();
		 if (continua == 'N' || continua == 'n') exit(0);
	} while(continua =='S' || continua == 's');	
*/


	
	printf("\n \n");
	system("pause");
	return 0;
	
	
}//end Main

