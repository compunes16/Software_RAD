/********************************************************************
 *  @description: Algoritimos que gravam os valores referente ao tipo de camera utilizada suas 
 			bandas e local mapeado; 		    				
 *  @author: Gustavo Serpeloni										
 *  @Professor: Antonio Maria Tommaselli							
 *  @Date: 20/02/2018												
 *******************************************************************/

#include "pfotoga.h"



// ************************************  FUNÇÕES -  DADOS DO TIPO DE CAMERAS*********************************** 


void CF2014C05ms(char* dados){  
  strcpy(dados,"band\tdt\n1\t0\n2\t0.023\n3\t0.046\n4\t0.069\n5\t0.092\n6\t0.115\n7\t0.138\n8\t0.161\n9\t0.184\n10\t0.207\n11\t0.413\n12\t0.436\n13\t0.459\n14\t0.482\n15\t0.505\n16\t0.528\n17\t0.551\n18\t0.574\n19\t0.597\n20\t0.62\n21\t0.643\n22\t0.666\n23\t0.689\n24\t0.712\n25\t0.735\n");		
  printf("\n%s",dados);
  
}// end Floresta_2014_05ms

void CF2014C10ms(char* dados){

	strcpy(dados,"band\tdt\n1\t0\n2\t0.028\n3\t0.056\n4\t0.084\n5\t0.112\n6\t0.14\n7\t0.168\n8\t0.196\n9\t0.224\n10\t0.252\n11\t0.463\n12\t0.491\n13\t0.519\n14\t0.547\n15\t0.575\n16\t0.603\n17\t0.631\n18\t0.659\n19\t0.687\n20\t0.715\n21\t0.743\n22\t0.771\n23\t0.799\n24\t0.827\n25\t0.855\n");
	printf("\n%s",dados);
		
}// end Floresta_2014_10ms

void CF2015C05ms(char* dados){
	
	strcpy(dados,"\nband\tdt\n1\t0\n2\t0.056\n3\t0.079\n4\t0.102\n5\t0.125\n6\t0.148\n7\t0.171\n8\t0.194\n9\t0.217\n10\t0.24\n11\t0.446\n12\t0.469\n13\t0.492\n14\t0.515\n15\t0.538\n16\t0.561\n17\t0.584\n18\t0.607\n19\t0.63\n20\t0.653\n21\t0.676\n22\t0.699\n23\t0.722\n24\t0.745\n25\t0.779\n");
	printf("\n%s",dados);	
	
}// end Floresta_2015_05ms

void CF2015C10ms(char* dados){	
	strcpy(dados,"\nband\tdt\n1\t0\n2\t0.061\n3\t0.089\n4\t0.117\n5\t0.145\n6\t0.173\n7\t0.201\n8\t0.229\n9\t0.257\n10\t0.285\n11\t0.496\n12\t0.524\n13\t0.552\n14\t0.58\n15\t0.608\n16\t0.636\n17\t0.664\n18\t0.692\n19\t0.72\n20\t0.748\n21\t0.776\n22\t0.804\n23\t0.832\n24\t0.86\n25\t0.899\n");
	printf("\n%s",dados);
		
}// end Floresta_2015_10ms

void CF2015C15ms(char* dados){
	strcpy(dados,"\nband\tdt\n1\t0\n2\t0.066\n3\t0.099\n4\t0.132\n5\t0.165z\n6\t0.198\n7\t0.231\n8\t0.264\n9\t0.297\n10\t0.33\n11\t0.546\n12\t0.579\n13\t0.612\n14\t0.645\n15\t0.678\n16\t0.711\n17\t0.744\n18\t0.777\n19\t0.81\n20\t0.843\n21\t0.876\n22\t0.909\n23\t0.942\n24\t0.975\n25\t1.019\n");
	printf("\n%s",dados);	
	
}// end Floresta_2015_15ms

void CC2015C10ms(char* dados){	
	strcpy(dados,"\nband\tdt\n1\t0\n2\t0.035\n3\t0.063\n4\t0.091\n5\t0.119\n6\t0.147\n7\t0.175\n8\t0.203\n9\t0.231\n10\t0.259\n11\t0.47\n12\t0.498\n13\t0.526\n14\t0.554\n15\t0.582\n16\t0.61\n17\t0.638\n18\t0.666\n19\t0.694\n20\t0.722\n21\t0.75\n22\t0.778\n23\t0.806\n24\t0.834\n25\t0.862\n");
	printf("\n%s",dados);	
	
}// end CANA_2015_10ms

void CL2017C05ms(char* dados){
	strcpy(dados,"\nband\tdt\n1\t0\n2\t0.023\n3\t0.046\n4\t0.069\n5\t0.092\n6\t0.115\n7\t0.138\n8\t0.161\n9\t0.184\n10\t0.207\n11\t0.413\n12\t0.436\n13\t0.459\n14\t0.482\n15\t0.505\n16\t0.528\n17\t0.551\n18\t0.574\n19\t0.597\n20\t0.62\n21\t0.643\n22\t0.666\n23\t0.689\n24\t0.712\n25\t0.742\n");
	printf("\n%s",dados);	
	
}// end LARANJA_2017_05ms

void CL2017C10ms(char* dados){
	strcpy(dados,"\nband\tdt\n1\t0\n2\t0.028\n3\t0.056\n4\t0.084\n5\t0.112\n6\t0.14\n7\t0.168\n8\t0.196\n9\t0.224\n10\t0.252\n11\t0.28\n12\t0.308\n13\t0.336\n14\t0.364\n15\t0.392\n16\t0.42\n17\t0.448\n18\t0.476\n19\t0.504\n20\t0.532\n21\t0.56\n22\t0.588\n23\t0.616\n24\t0.644\n25\t0.672\n");
	printf("\n%s",dados);	
	
}// end LARANJA_2017_10ms

void CL2017C15ms(char* dados){	
	strcpy(dados,"\nband\tdt\n1\t0\n2\t0.033\n3\t0.066\n4\t0.099\n5\t0.132\n6\t0.165\n7\t0.198\n8\t0.231\n9\t0.264\n10\t0.297\n11\t0.33\n12\t0.363\n13\t0.396\n14\t0.429\n15\t0.462\n16\t0.495\n17\t0.528\n18\t0.561\n19\t0.594\n20\t0.627\n21\t0.66\n22\t0.693\n23\t0.726\n24\t0.759\n25\t0.792\n");
    printf("\n%s",dados);
    		
}// end LARANJA_2017_15ms


void CCM05ms(char* dados){	
	strcpy(dados,"band\tdt\n1\t0\n2\t0.056\n3\t0.079\n4\t0.102\n5\t0.125\n6\t0.148\n7\t0.171\n8\t0.194\n9\t0.217\n10\t0.240\n11\t0.446\n12\t0.469\n13\t0.492\n14\t0.515\n15\t0.538\n16\t0.561\n17\t0.584\n18\t0.607\n19\t0.630\n20\t0.653\n21\t0.676\n22\t0.699\n23\t0.722\n24\t0.745\n25\t0.774\n");
	printf("\n%s",dados);
}//end Citrus Murtras 05ms



// ************************************  Grava os valores de cada banda em uma estrutura  *********************************** 


void bandaGravacao(){ 
	
// Floresta-2014-05ms
BAND[0].dt[0] = 0;	  BAND[0].dt[1] = 0.023;	BAND[0].dt[2] = 0.046;      BAND[0].dt[3] = 0.069;  	    BAND[0].dt[4] = 0.092;	
BAND[0].dt[5] = 0.115;	  BAND[0].dt[6] = 0.138;	BAND[0].dt[7] = 0.161;      BAND[0].dt[8] = 0.184;  	    BAND[0].dt[9] = 0.207;	
BAND[0].dt[10] = 0.413;	  BAND[0].dt[11] = 0.436;	BAND[0].dt[12] = 0.459;	    BAND[0].dt[13] = 0.482;	    BAND[0].dt[14] = 0.505;	
BAND[0].dt[15] = 0.528;	  BAND[0].dt[16] = 0.551;	BAND[0].dt[17] = 0.574;	    BAND[0].dt[18] = 0.597;	    BAND[0].dt[19] = 0.62;	
BAND[0].dt[20] = 0.643;	  BAND[0].dt[21] = 0.666;	BAND[0].dt[22] = 0.689;	    BAND[0].dt[23] = 0.712;	    BAND[0].dt[24] = 0.735;

// Floresta-2014-10ms
BAND[1].dt[0] = 0;	 BAND[1].dt[1] = 0.028;	    BAND[1].dt[2] = 0.056;   	BAND[1].dt[3] = 0.084; 	   BAND[1].dt[4] = 0.112;
BAND[1].dt[5] = 0.14;	 BAND[1].dt[6] = 0.168;	    BAND[1].dt[7] = 0.196;   	BAND[1].dt[8] = 0.224;	   BAND[1].dt[9] = 0.252;
BAND[1].dt[10] = 0.463;	 BAND[1].dt[11] = 0.491;	BAND[1].dt[12] = 0.519;	    BAND[1].dt[13] = 0.547;	   BAND[1].dt[14] = 0.575;	   
BAND[1].dt[15] = 0.603;  BAND[1].dt[16] = 0.631;	BAND[1].dt[17] = 0.659;	    BAND[1].dt[18] = 0.687;	   BAND[1].dt[19] = 0.715;	
BAND[1].dt[20] = 0.743;	 BAND[1].dt[21] = 0.771;	BAND[1].dt[22] = 0.799;	    BAND[1].dt[23] = 0.827;	   BAND[1].dt[24] = 0.855;	


// Floresta-2015-05ms
BAND[2].dt[0] = 0;	  BAND[2].dt[1] = 0.056;	BAND[2].dt[2] = 0.079;	  BAND[2].dt[3] = 0.102;	BAND[2].dt[4] = 0.125;	
BAND[2].dt[5] = 0.148;    BAND[2].dt[6] = 0.171;	BAND[2].dt[7] = 0.194;	  BAND[2].dt[8] = 0.217;	BAND[2].dt[9] = 0.24;	
BAND[2].dt[10] = 0.446;	  BAND[2].dt[11] = 0.469;	BAND[2].dt[12] = 0.492;	  BAND[2].dt[13] = 0.515;	BAND[2].dt[14] = 0.538;	
BAND[2].dt[15] = 0.561;	  BAND[2].dt[16] = 0.584;	BAND[2].dt[17] = 0.607;	  BAND[2].dt[18] = 0.63;	BAND[2].dt[19] = 0.653;	
BAND[2].dt[20] = 0.676;	  BAND[2].dt[21] = 0.699;	BAND[2].dt[22] = 0.722;	  BAND[2].dt[23] = 0.745;	BAND[2].dt[24] = 0.779;	
	
	
//Floresta-2015-10ms

BAND[3].dt[0] = 0;	BAND[3].dt[1] = 0.061;	BAND[3].dt[2] = 0.089;	BAND[3].dt[3] = 0.117;	BAND[3].dt[4] = 0.145;	
BAND[3].dt[5] = 0.173;	BAND[3].dt[6] = 0.201;	BAND[3].dt[7] = 0.229;	BAND[3].dt[8] = 0.257;	BAND[3].dt[9] = 0.285;	
BAND[3].dt[10] = 0.496;	BAND[3].dt[11] = 0.524;	BAND[3].dt[12] = 0.552;	BAND[3].dt[13] = 0.58;	BAND[3].dt[14] = 0.608;	
BAND[3].dt[15] = 0.636;	BAND[3].dt[16] = 0.664;	BAND[3].dt[17] = 0.692;	BAND[3].dt[18] = 0.72;	BAND[3].dt[19] = 0.748;	
BAND[3].dt[20] = 0.776;	BAND[3].dt[21] = 0.804;	BAND[3].dt[22] = 0.832;	BAND[3].dt[23] = 0.86;	BAND[3].dt[24] = 0.899;		
	
	
//Floresta-2015-15ms
BAND[4].dt[0] = 0;	BAND[4].dt[1] = 0.066;	BAND[4].dt[2] = 0.099;	BAND[4].dt[3] = 0.132;	BAND[4].dt[4] = 0.165;	
BAND[4].dt[5] = 0.198;	BAND[4].dt[6] = 0.231;	BAND[4].dt[7] = 0.264;	BAND[4].dt[8] = 0.297;	BAND[4].dt[9] = 0.33;	
BAND[4].dt[10] = 0.546;	BAND[4].dt[11] = 0.579;	BAND[4].dt[12] = 0.612;	BAND[4].dt[13] = 0.645;	BAND[4].dt[14] = 0.678;	
BAND[4].dt[15] = 0.711;	BAND[4].dt[16] = 0.744;	BAND[4].dt[17] = 0.777;	BAND[4].dt[18] = 0.81;	BAND[4].dt[19] = 0.843;	
BAND[4].dt[20] = 0.876;	BAND[4].dt[21] = 0.909;	BAND[4].dt[22] = 0.942;	BAND[4].dt[23] = 0.975;	BAND[4].dt[24] = 1.019;	
	
	
//Cana-2015-05ms	
BAND[5].dt[0] = 0; 		BAND[5].dt[1] = 0.035;		BAND[5].dt[2] = 0.063;		BAND[5].dt[3] = 0.091;		BAND[5].dt[4] = 0.119;	
BAND[5].dt[5] = 0.147;		BAND[5].dt[6] = 0.175;		BAND[5].dt[7] = 0.203;		BAND[5].dt[8] = 0.231;		BAND[5].dt[9] = 0.259;	
BAND[5].dt[10] = 0.47;		BAND[5].dt[11] = 0.498;		BAND[5].dt[12] = 0.526;		BAND[5].dt[13] = 0.554;		BAND[5].dt[14] = 0.582;	
BAND[5].dt[15] = 0.61;		BAND[5].dt[16] = 0.638;		BAND[5].dt[17] = 0.666;		BAND[5].dt[18] = 0.694;		BAND[5].dt[19] = 0.722;	
BAND[5].dt[20] = 0.75;		BAND[5].dt[21] = 0.778;		BAND[5].dt[22] = 0.806;		BAND[5].dt[23] = 0.834;		BAND[5].dt[24] = 0.862;	

//Laranja-2017-05ms - Atualizada Erika (20.03.19)
BAND[6].dt[0] = 0;		BAND[6].dt[1] = 0.023;		BAND[6].dt[2] = 0.046;	BAND[6].dt[3] = 0.069;	BAND[6].dt[4] = 0.092;	
BAND[6].dt[5] = 0.115;		BAND[6].dt[6] = 0.138;		BAND[6].dt[7] = 0.161;	BAND[6].dt[8] = 0.184;	BAND[6].dt[9] = 0.207;	
BAND[6].dt[10] = 0.413;		BAND[6].dt[11] = 0.436;		BAND[6].dt[12] = 0.459;	BAND[6].dt[13] = 0.482;	BAND[6].dt[14] = 0.505;	
BAND[6].dt[15] = 0.528;		BAND[6].dt[16] = 0.551;		BAND[6].dt[17] = 0.574;	BAND[6].dt[18] = 0.597;	BAND[6].dt[19] = 0.62;	
BAND[6].dt[20] = 0.643;		BAND[6].dt[21] = 0.666;		BAND[6].dt[22] = 0.689;	BAND[6].dt[23] = 0.712;	BAND[6].dt[24] = 0.742;	


//Laranja-2017-10ms
BAND[7].dt[0] = 0;	BAND[7].dt[1] = 0.028;		BAND[7].dt[2] = 0.056;	BAND[7].dt[3] = 0.084;	BAND[7].dt[4] = 0.112;	
BAND[7].dt[5] = 0.14;	BAND[7].dt[6] = 0.168;		BAND[7].dt[7] = 0.196;	BAND[7].dt[8] = 0.224;	BAND[7].dt[9] = 0.252;	
BAND[7].dt[10] = 0.28;	BAND[7].dt[11] = 0.308;		BAND[7].dt[12] = 0.336;	BAND[7].dt[13] = 0.364;	BAND[7].dt[14] = 0.392;	
BAND[7].dt[15] = 0.42;	BAND[7].dt[16] = 0.448;		BAND[7].dt[17] = 0.476;	BAND[7].dt[18] = 0.504;	BAND[7].dt[19] = 0.532;	
BAND[7].dt[20] = 0.56;	BAND[7].dt[21] = 0.588;		BAND[7].dt[22] = 0.616;	BAND[7].dt[23] = 0.644;	BAND[7].dt[24] = 0.672;	


//Laranja-2017-15ms
BAND[8].dt[0] = 0;	BAND[8].dt[1] = 0.033;		BAND[8].dt[2] = 0.066;	BAND[8].dt[3] = 0.099;	BAND[8].dt[4] = 0.132;	
BAND[8].dt[5] = 0.165;	BAND[8].dt[6] = 0.198;		BAND[8].dt[7] = 0.231;	BAND[8].dt[8] = 0.264;	BAND[8].dt[9] = 0.297;	
BAND[8].dt[10] = 0.33;	BAND[8].dt[11] = 0.363;		BAND[8].dt[12] = 0.396;	BAND[8].dt[13] = 0.429;	BAND[8].dt[14] = 0.462;	
BAND[8].dt[15] = 0.495;	BAND[8].dt[16] = 0.528;		BAND[8].dt[17] = 0.561;	BAND[8].dt[18] = 0.594;	BAND[8].dt[19] = 0.627;	
BAND[8].dt[20] = 0.66;	BAND[8].dt[21] = 0.693;		BAND[8].dt[22] = 0.726;	BAND[8].dt[23] = 0.759;	BAND[8].dt[24] = 0.792;		
	
	
//Citrus-murta-05ms - modificar  
BAND[9].dt[0] = 0;	BAND[9].dt[1] = 0.056;		    BAND[9].dt[2] = 0.079;	BAND[9].dt[3] = 0.102;	BAND[9].dt[4] = 0.125;	
BAND[9].dt[5] = 0.148;	BAND[9].dt[6] = 0.171;		BAND[9].dt[7] = 0.194;	BAND[9].dt[8] = 0.217;	BAND[9].dt[9] = 0.240;	
BAND[9].dt[10] = 0.446;	BAND[9].dt[11] = 0.469;		BAND[9].dt[12] = 0.492;	BAND[9].dt[13] = 0.515;	BAND[9].dt[14] = 0.538;	
BAND[9].dt[15] = 0.561;	BAND[9].dt[16] = 0.584;		BAND[9].dt[17] = 0.607;	BAND[9].dt[18] = 0.630;	BAND[9].dt[19] = 0.653;	
BAND[9].dt[20] = 0.676;	BAND[9].dt[21] = 0.699;		BAND[9].dt[22] = 0.722;	BAND[9].dt[23] = 0.745;	BAND[9].dt[24] = 0.774;				
	
}


