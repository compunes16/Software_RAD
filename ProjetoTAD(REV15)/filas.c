#include "pfotoga.h"

/********************************************************************
 *  @description: Algoritimos Filas 				
 *  @author: Gustavo Serpeloni										
 *  @Professor: Antonio Maria Tommaselli							
 *  @Date: 08/08/2018												
 *******************************************************************/


FILA* iniFila(){	
	FILA *fi = (FILA*) malloc(sizeof(FILA));
		fi->inicio = NULL;
		fi->final = NULL;
		fi->nelem =1;
		return fi;
}



void insereFila(FILA* F,char* ID,char* band,double x,double y,double z,double omega,double fi,double kappa){
		
	if(F == NULL){
	   printf("\n FILA VAZIA - Nao é possivel inserir dados - Primeiro Inicie a FILA");
	}
	else{	
	   DADOS* novoD = (DADOS*) malloc(sizeof(DADOS)); 
	   strcpy(novoD->PID,ID);
	   strcat(novoD->PID,"DC");  //nome da imagem com final sem DC
	   novoD->Mdados[0] = atoi(band);
	   novoD->Mdados[2] = x;
	   novoD->Mdados[3] = y;
	   novoD->Mdados[4] = z;
	   novoD->Mdados[5] = omega;
	   novoD->Mdados[6] = fi;
	   novoD->Mdados[7] = kappa;   			
	   novoD->prox = NULL;	
	   novoD->ant = NULL;
				    
		if(F->inicio == NULL){
			F->inicio = novoD;
			F->final = novoD;
		}
		 else{
		    F->final->prox = novoD;
		    novoD->ant = F->final;
			F->final = novoD;	
		 }
	      F->nelem ++;
    }
    
    
}//end InsereFila




void removeElemFila(FILA* F,DADOS *rem){
	
    DADOS *no;
    no = rem;
    printf(" [%s] ",rem->PID);	
    
	if(F->nelem > 1){
        if(no == F->inicio){
  		      if(no == F->inicio){	
                    rem = no->prox;
                    free(no);
                    F->inicio = rem;
		       }	  	
		  }else if(no == F->final){
		  	  rem = no->ant;
		  	  free(no);
		  	  F->final = rem ; 
		  	  		  	
		  }
		   else{	
	           no->ant->prox = no->prox;		   	  
		   	   no->prox->ant = no->ant;
		   	   rem = no->prox;	
			   free(no);   	
		  }
	}

	 F->nelem --;
}



void exibirFila(FILA* F){
	int i;
	DADOS* aux; aux = F->inicio;	
		
	printf("\n \n *** Exibir DADOS ");	
	
	while (aux != NULL){		
		printf("\n \n PHOTO ID: %s && PROX ID : %s",aux->PID,aux->prox->PID);
	
		for(i=0; i < 8  ; i++){
		   if( i != 1 ) printf("\n MDADOS[%i]: %.16f",i,aux->Mdados[i]);
		}
		aux = aux->prox;
	} 

	printf("\n\n\n NO INICIAL :%s",F->inicio->PID);
	printf("\n NO FINAL :%s",F->final->PID);
	printf("\n\n Quantidade de Elem: %i \n ",F->nelem);
}
			



void buscaNos(FILA* F){
	
	DADOS *aux,*aux2; aux = F->inicio;
	int cont=1;
	double banda1 = aux->Mdados[0];
	
	while(aux != NULL){		
		aux->qntphotos = 1;			
		//Marca as photos com a quantidade correta		
		  for (aux2 = aux->prox ; aux2 != NULL ; aux2 = aux2->prox ){
				if ( strncmp(aux2->PID,aux->PID,6) == 0 ) {	
					aux->qntphotos ++;
					cont++;
				} 	
			}
			
		//Repassa pelas fotos e insere a quantidade correta em que aparecem ;	
		   for (aux2 = aux->prox ; aux2 != NULL ; aux2 = aux2->prox ){
				if ( (aux->qntphotos == F->qntbanda) && (strncmp(aux2->PID,aux->PID,6) == 0) ) {	
						aux2->qntphotos = aux->qntphotos; 
				}
		 }			
		aux=aux->prox; 	
		if (banda1 != aux->Mdados[0]) break;
  }
}// end busca;	







