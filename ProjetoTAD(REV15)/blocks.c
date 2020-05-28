#include "pfotoga.h"


DADOS* var;
char caminho[300],auxCaminho[300],nomeImagem[30], auxImage[30];



void blocks(FILA* F){

	var = F->inicio;
	int i;
	
/*	for(i=0; i < 15; i++) printf("\n Valor var[%i]: %lf",i,var->radpar[i]);*/
	printf("\n Focal: %lf",var->focal);
	printf("\n Valores do radpar : %.2lf %.2lf ",var->radpar[5],var->radpar[6]);
	
	
	FILE *bckInit,*bckGrid,*bckUori,*bckBrdf,*bckOrto,*bchOrto,*blockData;	
	bckInit  =  fopen("01_block-init.txt","w+");    
	bckGrid  =  fopen("02_block-grid.txt","w+");    
	bckUori  =  fopen("03_block-uori.txt","w+");    
	bckBrdf  =  fopen("04_block-brdf-rela.txt","w+");    
	bckOrto  =  fopen("04_block-orto.txt","w+");    
	bchOrto  =  fopen("04_batch-orto.txt","w+");    
	blockData  =  fopen("block-init_data.txt","r+");    
	
       
	fscanf(blockData,"%s\n%s",caminho,auxImage); // Retirando os dados referente aos caminhos repassados;
	printf("\nCaminho:%s \n nome: %s \n",caminho,auxImage);
	nImage(nomeImagem);
    
    
	//Cabeçalho 01_block-init.txt
	   fprintf(bckInit,"Bits_per_pixel: 16 \nN_Channels: 25 \nFocal: %lf \n",var->focal); // Alterar valor Focal : encontrado em sis-rik_v1;
	   fprintf(bckInit,"Pixel_sz:\t0.0000055 \nAbsCalFn: block\\abscal.txt \nBRDF_fn: block\\brdf.txt \n");
	   fprintf(bckInit,"SunZenAz: %.2lf %.2lf \nNbits: 32 \n",var->radpar[5],var->radpar[6]); // SuzenAz retirdo do radpar
	   	



	while (var->Mdados[0] == var->prox->Mdados[0]){
		incCaminho(auxCaminho,var);	      		
		fprintf(bckInit,"%s\t%0.f\t%s\t%s\t%s\t%s\t",var->PID,var->Mdados[0],auxCaminho,nomeImagem,"block\\extor-photoscan-dt.txt","block\\sis_rik_v1.txt");
	   	fprintf(bckInit,"%s\t%s\n","block\\radpar_init.txt","data\\K00000.dat");
	  	var = var->prox;
	}

	blockGrid(F,bckGrid);
	blockUori(F,bckUori);
	block_Brdf_Orto(F,bckBrdf);
	block_Brdf_Orto(F,bckOrto);
	batchOrto(F,bchOrto);
	

	fclose(bckInit);
	fclose(bckGrid);
	fclose(bckUori);
	fclose(bckBrdf);
	fclose(bckOrto);
	fclose(bchOrto);	 
	printf("\n Arquivos Gerados com Sucesso ! \n");
	
}// end 01_block_init


void incCaminho(char* auxCaminho,DADOS* var){
	strcpy(auxCaminho,caminho);
	strcat(auxCaminho,"\\");
	strcat(auxCaminho,var->PID);	
	strcat(auxCaminho,".dat");
}



void nImage(char* nomeImagem){
	strcpy(nomeImagem,"block\\");
	strcat(nomeImagem,auxImage);
	strcat(nomeImagem,".hdr");
}



void blockGrid(FILA* F,FILE *blockgrid){
	

	var = F->inicio;
	
	fprintf(blockgrid,"Bits_per_pixel: 16 \nN_Channels: 25 \nFocal: %lf \n",var->focal); // Alterar valor Focal : encontrado em sis-rik_v1;
	fprintf(blockgrid,"Pixel_sz:\t0.0000055 \nAbsCalFn: block\\abscal.txt \nBRDF_fn: block\\brdf.txt \n");
	fprintf(blockgrid,"SunZenAz: %.2lf %.2lf \nNbits: 32 \n",var->radpar[5],var->radpar[6]); // SuzenAz retirdo do radpar
	
	
	while (var->Mdados[0] == var->prox->Mdados[0]){
		incCaminho(auxCaminho,var);
		fprintf(blockgrid,"%s\t%0.f\t%s\t%s\t%s\t%s\t",var->PID,var->Mdados[0],auxCaminho,nomeImagem,"init\\ext_ori_initial.txt","block\\sis_rik_v1.txt");
	   	fprintf(blockgrid,"%s\t%s\n","init\\rad_par_initial.txt","data\\K00000.dat");
	  	var = var->prox;
	}



}// end Block-Grid




void blockUori(FILA*F, FILE *blockuori){

	var = F->inicio;
	
	
	fprintf(blockuori,"Bits_per_pixel: 16 \nN_Channels: 25 \nFocal: %lf \n",var->focal); // Alterar valor Focal : encontrado em sis-rik_v1;
	fprintf(blockuori,"Pixel_sz:\t0.0000055 \nAbsCalFn: block\\abscal.txt \nBRDF_fn: block\\brdf.txt \n");
	fprintf(blockuori,"SunZenAz: %.2lf %.2lf \nNbits: 32 \n",var->radpar[5],var->radpar[6]); 
	
	
	while (var->Mdados[0] == var->prox->Mdados[0]){
		incCaminho(auxCaminho,var);
		fprintf(blockuori,"%s\t%0.f\t%s\t%s\t%s\t%s\t",var->PID,var->Mdados[0],auxCaminho,nomeImagem,"init\\ext_ori_initial.txt","block\\sis_rik_v1.txt");
	   	fprintf(blockuori,"%s\t%s\n","init\\rad_par_initial.txt","data\\K00000.dat");
	  	var = var->prox;
	}

}// end Block-Grid


void block_Brdf_Orto(FILA* F,FILE *arquivo){
	

	var = F->inicio;
	
	fprintf(arquivo,"Bits_per_pixel: 16 \nN_Channels: 25 \nFocal: %lf \n",var->focal); // Alterar valor Focal : encontrado em sis-rik_v1;
	fprintf(arquivo,"Pixel_sz:\t0.0000055 \nAbsCalFn: block\\abscal.txt \nBRDF_fn: block\\brdf.txt \n");
	fprintf(arquivo,"SunZenAz: %.2lf %.2lf \nNbits: 32 \n",var->radpar[5],var->radpar[6]); // SuzenAz retirdo do radpar
	
	
	while (var->Mdados[0] == var->prox->Mdados[0]){
		incCaminho(auxCaminho,var);
		fprintf(arquivo,"%s\t%0.f\t%s\t%s\t%s\t%s\t",var->PID,var->Mdados[0],auxCaminho,nomeImagem,"uori\\extor-all.txt","block\\sis_rik_v1.txt");
	   	fprintf(arquivo,"%s\t%s\n","init\\rad_par_initial.txt","data\\K00000.dat");
	  	var = var->prox;
	}

}// end Block-Grid


void batchOrto(FILA *F,FILE *arquivo){
	
/*	 Arrumar nomeclatura dos dados referente ao caminho, comopor exemplo:
		1- Numero da banda;
		2- Valor da camera;
*/	
		
	var = F->inicio;
	fprintf(arquivo,"radiometric\n");
	fprintf(arquivo,"%s\t%0.f\t%s\t%s\t%s\t","04_block-orto.txt",var->Mdados[0],"match_param_orto1_bu.txt","mosaic-orto-Camera\\sta-ch_Banda-orto.txt","mosaic-orto-Camera\\log-ch_Banda-orto.txt");
	fprintf(arquivo,"%s\t%s\t%s\t","block\\DSM-10m.xyz","block\\DSM_50cm.asc","mosaic-orto-50cm\\rad_tie-block-ch5-orto.txt");
	fprintf(arquivo,"%s\t%s\t%s\t%s\t%s\t","mosaic-orto-50cm\\orto-block-ch5_50cm.raw","mosaic-orto-50cm\\pc-block-ch5-orto.txt");
	fprintf(arquivo,"%s\t%s\n","mosaic-orto-50cm\\sd-block-ch5-orto.raw","dummy.txt");
	
}//end batchOrto
