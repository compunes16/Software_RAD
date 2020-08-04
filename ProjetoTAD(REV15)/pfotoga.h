/********************************************************************
 *  @description: Cabeçalho arquivos Projetos-Arquivos Fotogametria *
 *  @author: Gustavo Serpeloni						  *
 *  @Professor: Antonio Maria Tommaselli					  *
 *  @Date: 20/02/2018							        *
 *******************************************************************/


//BIBLIOTECAS INCLUIDAS NO PROGRAMA

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <locale.h>
#include <ctype.h>
#include "tratamentoDeErros.h"
#include "sis.h"
#include "blocks.h"
#define MAX 50000
#define d 80 		// tamanho das strings
#define div 1000.0 	// divisor para o calculo do tempo. float




// ************************************   STRUCTS ***********************************


// -------------- <1>  Estrutura de Dados POH.texfile - Fila Dinamica -------------- 

typedef struct dados{
	int qntphotos;
	double focal;
	char PID[30];
	double Mdados[8]; //Dados arquivo POE e taskfile
	double V[8]; // Velocidades para CubeStartTime
	double radpar[7]; // valores radpar
	struct dados *prox;
	struct dados *ant;
}DADOS;


typedef struct fila{
	DADOS* inicio;
	DADOS* final;
	int qntbanda;
	int nelem;
}FILA;



// --------------  <2> Estrutura - Camera Rikola  --------------

typedef struct no{
	double dados[15];
	int adicionado;
	char idr[30];
	struct no *prox;
	struct no *ant;
}NO; 


typedef struct sisrik{
	int qntdelem;
	int xdir; // valor xDir
	NO* inicio;
	NO* Fim;	
}SISRIK;




// -------------- <3> Estruturas globais : BANDAS  --------------

struct band{
	float dt[25];
}BAND[10]; // Bandas alocadas na memoria do software

struct band_ext{
	float dt[60];
}BAND_EXT; //Definindo banda com entrada Externa




/* **********************************************************************************  
   ***********************************  FUNÇÕES ************************************* 
   **********************************************************************************/

// -------------- <1> Funções Implementadas -------------- 

void Menu(FILA* F,SISRIK* SK);
void NuvemdePontos();
void selectMenu();
void selectBandas(int tipo);
void ModificaCaminho(char* saida);
float buscaBanda(int banda,int tipodt);
void bandaGravacao();
void ext_bandas();
void camEntrada(char* caminho);
void ajuda();
void retornaMenu();



// -------------- <2> Funções : Campos e Banda -------------- 

void CF2014C05ms(char* dados);
void CF2014C10ms(char* dados);
void CF2015C05ms(char* dados);
void CF2015C10ms(char* dados);
void CF2015C15ms(char* dados);
void CC2015C10ms(char* dados);
void CL2017C05ms(char* dados);
void CL2017C10ms(char* dados);
void CL2017C15ms(char* dados);
void CCM05ms(char* dados);
void ext_bandas(char* dados);

void exibirArquivo();


// -------------- <3>  Funções POE : TESKFILE(Alocação Dinamica) -------------- 

void leituraPOE(FILA* F);
void IDPROCESS(char* ID,char* band);
void calculoTempo(FILA* F);
void extorFiles(FILA* F);


// -------------- <4> Funcoes : Filas Dinamicas -------------- 

FILA* iniFila();
void insereFila(FILA* F,char* ID,char* band,double x,double y,double z,double omega,double fi,double kappa);
void exibirFila(FILA* F);
void buscaNos(FILA* F);
void removeElemFila(FILA* F, DADOS *remover);


// -------------- <5> Funcoes : CubeStartTime -------------- 

void cubeStartTime(FILA* F,FILE* CST,DADOS* var1,DADOS* var2,int cont);


// -------------- <6> Funções : RadPar  --------------

void insereRadPar(FILA *F,FILE *RDP);



//---------------  <7> Funções : Arquivo SIS_RIK --------------
SISRIK* iniFIla(void);
void exibirSISR(SISRIK* SK);
void insereElem(SISRIK* SK,int qntdBanda);
void valorXDIR(SISRIK *SK);
void sisRikBandas(SISRIK *SK,FILA* F);
void exibirBandasSisk(int *banda,int TAM);
void arqPOI(SISRIK *SK,int *banda,char* sensor,FILA* F);
NO* insereDadosPOI(double *POI,NO* no,FILA* F);
void gerarArquivoRik(SISRIK *SK);


// -------------- <8> Block Init --------------
void blocks(FILA* F);
void blockUori(FILA* F,FILE *blockuori);
void blockGrid(FILA* F,FILE *blockgrid);
void block_Brdf_Orto(FILA* F,FILE *arquivo);
void batchOrto(FILA *F,FILE *arquivo);
void incCaminho(char* auxCaminho,DADOS* var);
void nImage(char* auxImagem);
