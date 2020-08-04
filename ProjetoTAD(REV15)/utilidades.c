/********************************************************************
 *  @description: Utilidades- Algoritimos   				
 *  @author: Gustavo Serpeloni										
 * 	@Professor: Antonio Maria Tommaselli							
 *	@Date: 20/02/2018												
 *******************************************************************/

#include "pfotoga.h"


// <1> MENU E SELEÇÂO

void Menu(FILA* F,SISRIK* SK) {
	
	int x = 1;
/*	char  x;
	printf("\t\t \t **********************************\n");
	printf("\t\t \t ********       MENU       ********\n");
	printf("\t\t \t **********************************");
	printf ("\n\n <1> - NUVEM DE PONTOS (ENUMERAÇÃO E ADC.ZEROS) \n ");
	printf ("\n <2> - LOCAL DA MISSÃO - BANDAS DT  \n ");
	printf ("\n <3> - EXTOR FILE - POE & TASKFILE \n ");
	printf ("\n <4> - RIKOLA FILE - SIS_RIK_V1 \n ");
	printf ("\n <5> -  Blocks FILE  \n ");
	printf("\n <6> - Ajuda \n");
	printf ("\n <0> - SAIR \n ");
	
	do {
		fflush(stdin);
		printf("\n Insira uma opcao: ");
		x = getchar();
		if(x =='0') exit(0);
	} while (x < '1' || x > '5');

	fflush(stdin);*/	
	
//x = 5;	


 while ( x < 6 ){	
	system("cls");	
	
	
    switch (x) {
		case 1 :
			printf("\n \t \t -------------------------------------------");
			printf("\n \t \t -----    NUVEM DE PONTOS - (DSM_Xm)  ------");
			printf("\n \t \t -------------------------------------------\n \n");
			NuvemdePontos();
			printf("\n\n");
			system("pause");
			break;
			
		case 2 :	
			printf("\n \t \t --------------------------------------------------");		
			printf("\n \t \t -------    LOCAL DA MISSÃO - BANDAS DT     -------");	
			printf("\n \t \t --------------------------------------------------\n\n");		
			selectMenu();
			printf("\n\n");
			system("pause");
			break;
			
		case 3 :
			printf("\n \t \t -------------------------------------------");
			printf("\n \t \t --------    Extor-Photoscan-DT     --------");
			printf("\n \t \t -------------------------------------------\n \n");				
			F = iniFila();
			leituraPOE(F);
			printf("\n\n");
			system("pause");
			break;	
				
		case 4 :
			printf("\n \t \t -------------------------------------------");
			printf("\n \t \t --------  ARQUIVO - DADOS RIKOLA  ---------");
			printf("\n \t \t -------------------------------------------\n \n");				
			SK = iniFIla();
			sisRikBandas(SK,F);
			gerarArquivoRik(SK);
			printf("\n Arquivo Gerado com Sucesso ! \n \n");
			system("pause");
			break;	
			
			
		case 5 :
			printf("\n \t \t -------------------------------------------");
			printf("\n \t \t --------  ARQUIVO - Block  ---------");
			printf("\n \t \t -------------------------------------------\n \n");
			blocks(F);
			printf("\n\n");
			break;
			
				
		case 6 :
			ajuda();
			break;
			
	}
	x++;
  }// end  while
	
}//end Menu




void selectMenu() {
	
	int tipo;
	printf("\n ----------------");
	printf("\n --- FLORESTA ---");
	printf("\n ----------------");
	printf ("\n <1> config_floresta_2014_camera_05ms");
	printf ("\n <2> config_floresta_2014_camera_10ms");
	printf ("\n <3> config_floresta_2015_camera_05ms");
	printf ("\n <4> config_floresta_2015_camera_10ms");
	printf ("\n <5> config_floresta_2015_camera_15ms \n ");
	
	printf("\n ---------------");
	printf("\n ---  CANA  ---");
	printf("\n ---------------");
	printf ("\n <6> config_cana_2015_camera_10ms\n");
	
	printf("\n ---------------");
	printf("\n --- LARANJA ---");
	printf("\n ---------------");
	printf("\n <7> config_laranja_2017_camera_05ms");
	printf("\n <8> config_laranja_2017_camera_10ms");
	printf("\n <9> config_laranja_2017_camera_15ms");
	printf("\n <10> config_citrus_murta_05ms\n");
	
	printf("\n -----------------------");
	printf("\n --- Arquivo Externo ---");
	printf("\n -----------------------");
	printf("\n <11> Abrir");
	
	printf("\n\n <0> Retornar ao Menu Principal");
	

	
	do {
		fflush(stdin);
		printf("\n \n Insira a Opção Desejada : ");
		scanf("%i",&tipo);
	} while(tipo < 0 || tipo > 11);

	system("cls");
	switch (tipo) {
		case 1:
			printf("\t *** Config_Floresta_2014_Camera_05ms ***");
			selectBandas(tipo);
			break;

		case 2:
			printf("\t *** Config_Floresta_2014_Camera_10ms ***");
			selectBandas(tipo);
			break;

		case 3:
			printf("\t *** Config_Floresta_2015_Camera_05ms ***");
			selectBandas(tipo);
			break;

		case 4:
			printf("\t *** Config_Floresta_2015_Camera_10ms ***");
			selectBandas(tipo);
			break;

		case 5:
			printf("\t *** Config_Floresta_2015_Camera_15ms ***");
			selectBandas(tipo);
			break;

		case 6:
			printf("\t *** Config_Cana_2015_Camera_10ms ***");
			selectBandas(tipo);
			break;

		case 7:
			printf("\t *** Config_Laranja_2017_Camera_05ms ***");
			selectBandas(tipo);
			break;

		case 8:
			printf("\t *** Config_Laranja_2017_Camera_10ms ***");
			selectBandas(tipo);
			break;

		case 9:
			printf("\t *** Config_Laranja_2017_Camera_15ms ***");
			selectBandas(tipo);
			break;
			
		case 10:
		    printf("\t *** Config_Citrus_Murta_05ms ***");
		    selectBandas(tipo);
			break;	
			
		case 11:
		    printf("\t *** Arquivo Externo::  ***");
		    selectBandas(tipo);
			break;	
			
		case 0:
			retornaMenu();
			break;
			
	}//end switch case

}//end Selecao de Arquivos




void retornaMenu(){
	FILA* F;
	SISRIK* SK;
	system("cls");
	Menu(F,SK);
}




// <2> AJUDA

void ajuda(){
	
	printf("\t \t  ***** AJUDA -  FUNCIONALIDADES PROGRAMA ***** \n \n ");
	printf("<1> Para Nuvem de Pontos utilizar Arquivo [ DSM_5M ] \n");
	printf("  (1.1)Nuvem de Pontos cria um arquivo ordenado e insere 0's ao final dos dados; \n \n ");
	
	printf("\n<2> Selecione o arquivo correto das bandas referente ao local da missão realizada; \n");
	printf("  (2.1)Sera gerado um arquvio referente ao tipo selecionado para uso interno do programa \n \n");
	
	printf("\n<3> Para gerar o arquivo Extor_File adicione corretamente os arquivos pedidos : \n");
	printf("  (3.1) Selecione o local da Missão[item2], para que seja usado posteriormente; \n");
	printf("  (3.2) Insira o arquivo [ POE ] para retirar os dados necessarios; \n");
	printf("  (3.3) Insira o arquivo [ TASKFILE ], para o calculo do tempo;\n");
	printf("  (3.4) Após inseri-los : são retirado os dados e gerado outros dois arquivos sendo :");
	printf("\n    -> extor-photoscan-dt.txt | cube-start-time.txt \n\n ");
	
	printf("\n<4> Gerar o arquivo [ DADOS DA CAMERA RIKOLA ]\n");
	printf("  (4.1) Inicialmente é pedido o valor xdir [0..3] \n");
	printf("  (4.2) Selecionar quais bandas que receberam os valores  \n");
	printf("  (4.3) O algoritimo somente termina quando todas as bandas forem inseridas\n");
	printf("  (4.4) Necessário selecionar para um conjunto de bandas o arquivo que será usado com base\n");
	printf("  (4.5) Após tudo setado o arquivo será gerado.\n");
	

}//end ajuda


