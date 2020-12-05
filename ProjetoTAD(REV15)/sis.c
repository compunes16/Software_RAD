/********************************************************************
 *  @description: Algoritimo para gerar o arquivo : SIS_RIK_V1
 *  @author: Gustavo Serpeloni
 *  @Professor: Antonio Maria Tommaselli
 *  @tool: CAMERA RIKOLA
 *  @Date: 20/02/2018
 *******************************************************************/

#include "pfotoga.h"
#include <math.h>


/***************************************    Funções : Filas Dinamicas    ********************************************/

SISRIK* iniFIla(void) {

	SISRIK* inifila = (SISRIK*) malloc (sizeof(SISRIK));
	inifila->inicio = NULL;
	inifila->Fim = NULL;
	inifila->qntdelem = 0;

	return inifila;
}



void insereElem(SISRIK* SK,int qntdBanda) {

	int i,j;

	if(SK == NULL) {
		printf("\n <!!> Primeiro inicie a Fila - VAZIA !");
		exit(0);
	}
	if(SK->qntdelem >= 0) {
		for(i=1; i <= qntdBanda ; i++) {
			NO* novoNO = (NO*) malloc (sizeof(NO));
			strcpy(novoNO->idr,"K000000");
			novoNO->dados[0] = SK->qntdelem+1;
			novoNO->adicionado = 0;
			novoNO->dados[1] = 1;
			novoNO->dados[2] = SK->xdir;
			novoNO->dados[3] = 0.0000055;
			novoNO->dados[4] = 648;
			novoNO->dados[5] = 1017;
			for(j=0; j < 6 ; j++) novoNO->dados[10+j] = 0;
			novoNO->ant = NULL;
			novoNO->prox = NULL;

			if(SK->inicio == NULL) {
				SK->inicio = novoNO;
				SK->Fim = novoNO;
			}
			if (SK->inicio != NULL) {
				SK->Fim->prox = novoNO;
				novoNO->ant = SK->Fim;
				SK->Fim = novoNO;
			}
			SK->qntdelem++;

		}//end	FOR

	}//end else_if

}//end insereElem


NO* insereDadosPOI(double *POI,NO* no,FILA* F) { // Insere  os valores : f,dppx ,dppy,k1
	no->dados[6] = (POI[0]/div);
	no->dados[7] = (POI[1]/div);
	no->dados[8] = (POI[2]/div);
	no->dados[9] = (POI[3]*-(pow(10.0,6)));
	F->inicio->focal = no->dados[6];
}


void valorXDIR(SISRIK *SK) {
	printf("\n <1.1> Valor setado para Xdir: %i \n",SK->xdir);
	system("pause");
}



/***************************************    ALGORITIMO : CONFIG. ARQUIVO SISTEMA RIKOLA   ********************************************/

// Obs: Tratamento de erro de inserção para que nao   o sistema
void sisRikBandas(SISRIK *SK,FILA* F) {

	int banda[24],TAM;
	char mac[50],sensor[10],valor[6];
	int i,elem = 1,cont = 0;
	char caminho;
	FILE* rikolaData;
	rikolaData = fopen("config/rikola_data.txt","r");

	printf("\n ---------------------------------------------------------------------------------------- \n");
	printf("\n \t \t *** CONFIGURAÇÃO DAS BANDAS *** \n");
	fscanf(rikolaData,"%i",&TAM);
	fscanf(rikolaData,"%i",&SK->xdir);
	printf("\n <1> Tamanho de Bandas utilizadas: %i\n",TAM);
	printf(" <2> Valor para Xdir : %i\n",SK->xdir);
	system("pause");


	insereElem(SK,TAM);
	for (i = 1; i <= TAM ; i++) banda[i] = 0;


	//do{
	elem = 1;
	printf("\n ---------------------------------------------------------------------------------------- ");
	printf("\n \n <!!> Arquivo somente será configurado após todas as bandas estarem setadas !!");
	printf("\n <2> Insira o valor entre [1..%i] para selecionar as bandas do Arquivo \n",TAM); // TAM - escolhido pelo usuario
	//printf("\n <3> Caso queira parar digite [0] \n");



	//--------------- Sensor 1 -------------

	printf("\n <**> SENSOR 1 \n");
	while(fscanf(rikolaData,"%s",sensor) != EOF) {
		if(strcmp("Sensor1",sensor) == 0) {
			break;
		}
	}

	while( (fscanf(rikolaData,"%s",valor) != EOF) && ( strcmp("Sensor2",valor)!=0 )) {
		elem = atoi(valor);
		banda[elem] = elem;
		printf(" Banda: %i \t",banda[elem]);

	}

	printf("\n\n <3>Retirando dados Sensor 1 [...] \n \n ");
	arqPOI(SK,banda,"config/s1.txt",F);


	//--------------- Sensor 2 -------------

	printf("\n <**> SENSOR 2 \n");
	rewind(rikolaData);
	while(fscanf(rikolaData,"%s",sensor) != EOF) {
		if(strcmp("Sensor2",sensor) == 0) {
			break;
		}
	}

	while( (fscanf(rikolaData,"%s",valor) != EOF)) {
		if(strcmp("#Disposicao:",valor) == 0) break;
		elem = atoi(valor);
		banda[elem] = elem;
		printf(" Banda: %i \t",banda[elem]);
	}

	printf("\n <4>Retirando dados Sensor 2 [...]");
	arqPOI(SK,banda,"config/s2.txt",F);



	printf("\n ----------------------------------------------------------------------------------------");
	printf("\n <!> Alocado uma quantidade de [%i] elementos !\n ",cont);
	printf("\n\n \t \t *** Impressao - Bandas Alocadas *** \n \n");
	exibirBandasSisk(banda,TAM);

	fclose(rikolaData);
}//end Function





/***************************************    Funções : Impressâo dos Dados    ********************************************/

void exibirBandasSisk(int *banda,int TAM) {

	int i,cont=0;

	for (i=1; i <= TAM ; i++) {

		if (cont >= 3) {
			printf("\n");
			cont = 0;
		}
		printf(" BD[%i] = %i \t",i,banda[i]);
		cont++;
	}
}



void exibirSISR(SISRIK* SK) {

	int i;
	NO* aux;
	aux = SK->inicio;
	printf("\n *** IMPRESSÃO DA FILA ALOCADA *** \n");

	while ( aux != NULL) {
		printf("%s",aux->idr);
		for(i=0; i < 16; i++) printf("\n DADOS[%i]: %.7lf",i,aux->dados[i]);
		aux = aux->prox;
		printf("\n");
	}

}//end exibir







/***************************************    Funções referente aos Arquivos    ********************************************/

void arqPOI(SISRIK *SK,int *banda,char *sensor,FILA* F) { // Leitura do arquivo para retirar  :: C , XP ,YP E K1


	char leitura[50],l8[d];
	int i,cont = 0;
	double l1,l2,l3,l4,l5,l6,l7,POI[3];


	FILE* arq1;

	do {
		arq1 = fopen (sensor,"r");
		if( arq1 == NULL) printf("\n <!!> Arquivo não encontrado ! \n");

	} while(arq1 == NULL);




	while ( fscanf (arq1,"%s",leitura) != EOF ) {	 	// procura a linha que será iniciado a leitura
		if( strstr(leitura,"Variable") != NULL) {
			break;
		}
	}//end While

	fseek(arq1,+69,SEEK_CUR); // seta o cursor na linha abaixo do cabeçalho: Variable , Value ...


	//Leitura detalhada dos dados ::

	while ( fscanf (arq1,"%s %lf %lf %lf %lf %lf %s \n",leitura,&l1,&l2,&l3,&l4,&l5,l8) != EOF ) {
		//printf("\n %s %lf %lf %lf %lf %lf %s \n",leitura,l1,l2,l3,l4,l5,l8);
		POI[cont] = l1;
		if (cont >= 4) break;
		cont++;
	}//end While



	printf("\n\n<> Valores retirados do Arquivo POI");
	for(i=0; i < 4 ; i++) {
		printf("\n POI[%i] = %lf",i,POI[i]);
	}
	printf("\n \n");

	// Busca - banda alocada e insere os valores retirados do POI

	NO* aux,*aux2;
	aux = SK->inicio;
	while ( aux != NULL ) {
		for (i=1; i < 26 ; i++) {
			if(banda[i] == aux->dados[0] && aux->adicionado == 0) {
				aux2 = aux;
				insereDadosPOI(POI,aux2,F);
				aux->adicionado = 1;
			}
		}
		aux = aux->prox;
	}

	fclose (arq1);
}//end arqPOI




void gerarArquivoRik(SISRIK *SK) {

	FILE* saida;
	saida = fopen("outup/sis_rik_v1.txt","w+");

	NO* aux;
	aux = SK->inicio;

	fprintf(saida,"%s","id byte_o xdir pix nrow ncol f dppx dppy k1 k2 k3 t1 t2 s a\n"); // Cabeçalho
	while (aux != NULL) {

		fprintf(saida,"%s\t%.0lf\t%.0lf\t%.0lf\t%.7lf\t","K0000",aux->dados[0],aux->dados[1],aux->dados[2],aux->dados[3]);
		fprintf(saida,"%.0lf\t%.0lf\t%.7lf\t%.7lf\t",aux->dados[4],aux->dados[5],aux->dados[6],aux->dados[7]);
		fprintf(saida,"%.7lf\t%.2lf\t%.0lf\t%.0lf\t",aux->dados[8],aux->dados[9],aux->dados[10],aux->dados[11]);
		fprintf(saida,"%.0lf\t%.0lf\t%.0lf\t%.0lf\n",aux->dados[12],aux->dados[13],aux->dados[14],aux->dados[15]);

		aux = aux->prox;
	}

	fclose(saida);
}//end
