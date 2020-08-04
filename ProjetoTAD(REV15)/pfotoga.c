/*
  @description: Algoritimos para gerar os seguintes Arquivos;
   <1> DSM_5mz		 	<2> Extor_POE_FILE
   <3> Cube_Start_Time		<4> Radpar_init
*/

#include "pfotoga.h"



// ************************************  Algoritimo para Gerar os Arquivos  *********************************** 

// <1> FUNÇÃO NUVEM DE PONTOS - DSM_5m

void NuvemdePontos() {

	FILE *arq,*arq2;
	int cont=1;
	char leitura[70],caminho[300],saida[300];
	char dados[70];
	
	printf("\n<1> Arquivos DSM_Xm \n");
	arq = fopen("Dsm_Xm.xyz","r");


	if(arq == NULL) {
		printf("Caminho ou Arquivo nao encontrado ! \n\n");
		NuvemdePontos();
		system("pause");
	}else {
		strcpy(saida,"DSM_Xm.xyz"); 
		ModificaCaminho(saida); //modificação  do caminho .xyz
		printf("\n Saida: %s",saida);
		arq2 = fopen(saida,"w+"); 
		
		while ( fgets(leitura,MAX,arq) != NULL) {
			strcpy(dados,leitura);
			dados[strlen(dados)-2] = '\t';
			dados [strlen(dados)-1] = '0';
			fprintf(arq2,"%d\t%s\n",cont,dados);
			cont++;
		}
		fclose(arq);
		fclose(arq2);

		printf("\n\n<1> Quantidade de Dados Verificados : %i",cont);
		printf("\n<2> Nuvem de Pontos Organizada com Sucesso !\n");
	}//end else


}// end NuvemdePontos




// # SELEÇÃO DE DADOS DAS CAMERA POR MISSÃO

void selectBandas(int tipo){
	
	FILE *arq1,*arq2;
	char bandadt[300];
	
	switch(tipo){
		case  1 : CF2014C05ms(bandadt); break;
		case  2 : CF2014C10ms(bandadt); break;
		case  3 : CF2015C05ms(bandadt); break;
		case  4 : CF2015C10ms(bandadt); break;
		case  5 : CF2015C15ms(bandadt); break;
		case  6 : CC2015C10ms(bandadt); break;
		case  7 : CL2017C05ms(bandadt); break;
		case  8 : CL2017C10ms(bandadt); break;
		case  9 : CL2017C15ms(bandadt); break;
		case  10: CCM05ms(bandadt); break;
		case  11: ext_bandas(bandadt); break;		
	}
	
		arq1 = fopen("dt-file.txt","w+");
		arq2 = fopen("tipo.txt","w+");
		
		fprintf(arq2,"%i",tipo);
		fputs(bandadt,arq1);
		fclose(arq1);
		fclose(arq2);
		printf("\n\n <1> Arquivo Gerado Com Sucesso !\n");
 	
}//end Funcao_Leitura




/*   Arquivos POE-TEXTFILE - Inicio do programaa para leitura e gravaçao e dados   */ 

void leituraPOE(FILA* F){	

	DADOS* D;
	FILE *POE;
	int cont=1,ant=0;
	char ID[17],band[2],caminho[300];
	float tempo;
    double x,y,z,omega,fi,kappa; 
	double r11,r12,r13,r21,r22,r23,r31,r32,r33;   
	   
	   
	printf("\n<!> VERIFICANDO - ARQUIVO (POE.txt) \n");
	POE = fopen("POE.txt","rt"); 

	
	if(POE == NULL) { // Caso o arquivo esteja vazio
		printf(" <obs> Caminho ou Arquivo nao encontrado ! \n\n");
		leituraPOE(F);
	}
    else{
    	
		while ( fscanf(POE,"%s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",ID,&x,&y,&z,&omega,&fi,&kappa,&r11,&r12,&r13,&r21,&r22,&r23,&r31,&r32,&r33) != EOF ){
			   IDPROCESS(ID,band);			   	  		
			  if( (strstr(ID,"K0"))!= NULL ) {			  	
			   insereFila(F,ID,band,x,y,z,omega,fi,kappa); // FILA DINAMICA - LEITURA E INSERÇÃO
				if (ant != atoi(band)){ // quantidade de bandas
					ant = atoi(band);
					F->qntbanda++;
				}					 
				cont++; //total de elementos	
			  }  	
		 }//end while
		
		//printf("\n \n Imprimindo Filaaaaa \n \n ::");
		//exibirFila(F);
		printf("\n <1> Qntd. de dados obtidos POE :: %i",cont);
		printf("\n <2> Qntd. de de bandas  :: %i",F->qntbanda);
		printf("\n");
	    buscaNos(F);
		calculoTempo(F);			
		fclose(POE);
		extorFiles(F);
		printf("\n <1> Arquivo Cube Start Time   - Gerado com Sucesso !! \n \n");		
		printf("\n <2> Arquivo RadParInit        - Gerado com Sucesso !! \n \n");		
		printf("\n <3> Arquivo Extor-hotoscan-dt - Gerado com Sucesso !! \n \n");		
    }
}//end MAIN



void calculoTempo(FILA* F){	
	
	DADOS* aux; aux = F->inicio;
		
	float banda = aux->Mdados[0],tempo,valorbanda;
	int cont=1,tipodt;	
	char l1[d],l2[d],l3[d],l4[d],l5[d],l6[d],l7[d],l8[d],l9[d],l10[d],l11[d],l12[d],l13[d],l14[d],l15[d],l16[d],l17[d];
	char PID2[15]=" ",PID3[15]=" ",caminho[300];

		
// Modificação da String do PHOTOID para realizar a Procura	

	strncpy(PID2,aux->PID,6); 
	printf("\n <3> PHOTOID INICIAL :: %s",F->inicio->PID);
	printf("\n <4> PHOTOID FINAL :: %s \n",F->final->PID);
	
	
printf("\n ---------------------------------------------------------------------------------------- \n");

//ABRINDO -- ARQUIVO
	FILE *arq2,*campo;
	printf("\n<!> VERIFICANDO - ARQUIVO ( TASKFILE.txt )  \n");
	//camEntrada(caminho);
    arq2 = fopen("TASKFILE.TXT","r");	    
	campo = fopen("tipo.txt","r");
	
	
	
// Numero do Local selecionado - Banda Selecionada no item 2:	
	while( fscanf(campo,"%i",&tipodt) != EOF ) { 
		tipodt = tipodt; 
	}

// Procura o primeiro PHOTOID encontrado:
	while ( fscanf(arq2," %s ",&l17) != EOF ){		
		if(strncmp(l17,PID2,6) == 0){
			printf("\n <1> Inicio da Leitura :: %s  \n <2> Fim da Leitura ::  %.6s ",PID2,F->final->PID);
			break;
		}
	}	
	
	fseek(arq2,-12,SEEK_CUR); 


// Procura os dados e o tempo para o calculo;
					
	while (fscanf(arq2,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s ",&l1,&l2,&l3,&l4,&l5,&l6,&l7,&l8,&l9,&l10,&l11,&l12,l13,&l14,&l15,&l16) != EOF && aux != NULL ){		
		   if(banda != aux->Mdados[0]){
				strncpy(PID3,aux->PID,6); 
				rewind(arq2);
					
				  while ( fscanf(arq2," %s ",&l17) != EOF ){	
						if(strncmp(PID3,l17,6) == 0) break;
				  }
				  
				banda = aux->Mdados[0];
				fseek(arq2,-12,SEEK_CUR);
		 			  			   	  
			}
			else if (strncmp(aux->PID,l1,6) == 0){		//Substituir valor do tempo refente -- aqui . 
					tempo = atoi(l6);		
					aux->V[0] = (tempo/div) ; //coloca no vetor o tempo sem a dividir por 1000.0
					valorbanda = buscaBanda(banda,tipodt); // verifica o valor correto da banda com ref. no dt;
					//if(cont < 200) printf("\n-Tempo: %lf \t Valor Banda: %lf \t banda: %d ",aux->V[0],valorbanda,tipodt);
					aux->Mdados[1] = ( aux->V[0] + valorbanda);		
					aux = aux->prox;
					cont++;
			}	
	}

	fclose(arq2);
	fclose(campo);
	
}// end Funcao Calcula Tempo





void extorFiles(FILA* F){ // Função :: + Extor-POE + CubeStartTime + Radpar_init
	
    DADOS *aux,*ant,*prox,*rem;
    int removidos=0,cont=0;
    double banda1;
    aux= F->inicio;
    FILE *saida,*CST,*RDP;	
    
    saida = fopen("extor-photoscan-dt.txt","w+"); // extor file POE
    CST =   fopen("cube-start-time.txt","w+"); // cube start time
    RDP =   fopen("radpar-init.txt","w+"); // radpar init
    
    
    fprintf(saida,"id\tband\ttime\tstatus\tX0\tY0\tZ0\tomega\tphi\tkappa\n");	 //Cabeçalho - Extor_POE_FILE
    fprintf(CST,"ima_id\tcube_start\tvX0\tvY0\tvZ0\tvo\tvp\tvk\n");	 //Cabeçalho - Cube Start Time
 
	FILE* arqRemov;
	arqRemov= fopen("Imagens_removidas.txt","wt+");
	
        printf("\n <3> PhotosId's Removidos :: \n");
		while( aux!= NULL ){	  
             if(aux->qntphotos < F->qntbanda){
             	fprintf(arqRemov,"%s",aux->PID);
                  removeElemFila(F,aux);
			    removidos++; 	
		      }	
		  	  aux = aux->prox;	  
        }
	    printf("\n \n <!!> Quantidade - Removidos : %i \n",removidos);
	    fprintf(arqRemov,"Quantidade de imagens removidas : %i",removidos);
   		aux = F->inicio; // resetando o ponteiro para o inicio da fila 
        banda1 = aux->Mdados[0];
  printf("\n ---------------------------------------------------------------------------------------- \n");
   
   while (aux!= NULL){  
        if(aux->qntphotos == F->qntbanda){				
                ant = aux ;
				prox = aux->prox;
             if( banda1 == aux->Mdados[0] && banda1 == prox->Mdados[0]){
                 cubeStartTime(F,CST,prox,ant,cont); // realiza o arquivo CubeStart Time
                 cont++;
            } 								
			    fprintf(saida,"%s\t%.0f\t %.6f\tadjusted\t%.9lf\t%.9lf\t%.9lf\t%.9lf\t%.9lf\t%.9lf\n",aux->PID,aux->Mdados[0],aux->Mdados[1],aux->Mdados[2],aux->Mdados[3],aux->Mdados[4],aux->Mdados[5],aux->Mdados[6],aux->Mdados[7]);	
		  }
		   
	   aux = aux->prox;
     }	

  insereRadPar(F,RDP);	 
  fclose(saida);
  fclose(CST);
  fclose(RDP);
  fclose(arqRemov);
  
}// end extorFiles




	
	
// <3> FUNÇÃO cubeStarTime	
	
void cubeStartTime(FILA* F,FILE *CST,DADOS* var1,DADOS* var2,int cont){
	// Chamada pela função extorFile
	int i;
	double x,x0;
	double t = var1->V[0],t0 = var2->V[0];
	
	
	for(i=1;i < 7;i++){
	   x = var1->Mdados[i+1];
	   x0 = var2->Mdados[i+1];	   
       var1->V[i] = ( x - x0 ) / ( t - t0 );
	}
	
	
	// Tratamento de Erros
    if(cont == 0 ){		   
       fprintf(CST,"%s\t %.4lf",var2->PID,var2->V[0]);
       for(i=0;i < 6;i++) fprintf(CST," \t %.9lf",var1->V[i+1]);		
	} 	
	if (cont >= 0){
      fprintf(CST,"\n%s\t %.4lf",var1->PID,var1->V[0]);
      for(i=0;i < 6;i++) fprintf(CST," \t %.9lf",var1->V[i+1]);	 		
    }  


}//end Cube-Start-Time	




// <4> FUNÇÃO RADPAR

void insereRadPar(FILA *F,FILE *RDP){
	
	DADOS *aux;
	int i;
	double banda1;
	double ra,rb,se,saz;
	aux = F->inicio;
	banda1 = aux->Mdados[0];
	FILE *dataRadpar;
	dataRadpar = fopen("radpar_data.txt","rt");
	
printf("\n ---------------------------------------------------------------------------------------- \n");	
	printf("<!!> Gerando Arquivo RadPar.txt : \n");	
	fscanf(dataRadpar,"%lf\n%lf\n%lf\n%lf\n",&ra,&rb,&se,&saz);
	//printf("\nRA: %.2lf \nRB: %.2lf\nSE: %.2lf \nSAZ: %.2lf",ra,rb,se,saz);
	fflush(stdin);
	
fprintf(RDP,"ima_id\tband\trel_a\trel_b\tsd_rela\tsd_relb\tsd_dn\tsunzen\tsunaz\nrad 1 0"); //Cabeçalho - RadPar	
	
  while (aux != NULL){
	 //if(banda1 != aux->Mdados[0]) break;	
			aux->radpar[0] = ra;
			aux->radpar[1] = rb;
			aux->radpar[2] = 0.05;	
			aux->radpar[3] = 0.0;
			aux->radpar[4] = 0.2;
			aux->radpar[5] = se;
			aux->radpar[6] = saz;
			fprintf(RDP,"\n%s\t%.0f",aux->PID,aux->Mdados[0]);
			for(i=0;i < 7;i++) fprintf(RDP,"\t%.2lf",aux->radpar[i]);						
		aux = aux->prox;	
	}
	

	fclose(dataRadpar);
}//end RadPar-Init




// ************************************   Funções  Complementares  *********************************** 
	
// Busca o valor dt e retorna o valor da banda banda especificada;		
float buscaBanda(int banda,int tipodt){ 		
	banda = (int) banda;
	return BAND[tipodt-1].dt[banda-1];
	
	//Adicionar verificacao caso o tipo da banda seja externa: 
	//return BAND_EXT.dt[banda-1];
	
	
	
}	



void IDPROCESS(char* ID,char* band){ //processo para retirar o valor da banda e nome do arquivo POE

	char novo[10];
	int i,j,cont=0;
	
	for(i=0;i < strlen(ID);i++){
		    if(ID[i] == 'b' || ID[i] == 'B'){
             band[0] = ID[i+1];
    	       if (ID[i+2] != '_') {
				 band[1] = ID[i+2]; 
				 band[2] = '\0';
			   }
		       else{
		       	 band[1] = '\0';
			   }	
			}
			if(ID[i] == '_'){
			 for (j=i+1;j<strlen(ID);j++){
				 if(ID[j] == '.'){
					novo[cont] ='\0';
					break;	
			     }
				  novo[cont] = ID[j];	
				  cont++;				
				}
			}
	}
	//printf("\n ID: %s \t NovoId: %s",ID,novo);
	strcpy(ID,novo);	
	
}//end funcao



