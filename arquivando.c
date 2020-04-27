#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
//VARIAVEL GLOBAL  LONG LONG array - ELA GUARDA OS VALORES NUMERICA REFERIDOS AS PALAVRA PARA SEREM USADO EM OUTRAS FUNÇÕES PARA PRECISAR RETORNA VETORES.
//
//VARIAVEL GLOBAL CHAR test - JA ESSA USA UMA MATRIZ PARA GURADAR AS PALAVRAS VALIDAS.
//
//VARIAVEL GLOBAL int contador - ESSAS GUARDA AS QUNATIDADES  DE PALAVRA REPETIDAS .
//
//
// ELAS SE INTERLIGAM PELA POSIÇÃO . 
// EXP:
// POSIÇÃO 0  TEM A PALAVRA ,QUANTA VEZES REPETIOU, E VALORES NUMERICO NELA.
//

void arquivando(int argv[],char* argc[]);
int comp( char *test, char *test1 );


char test[1024][23];
int  contador[1024];
long long array[1024];


void arquivando(int argv[],char* argc[]){
  

 
FILE * arquivo=fopen(argc[2],"r+");

char linha[20480];// 20.480  == 1024 * 22(uma palavra de 22 letras) == pior caso


fread(linha,20480,1,arquivo);


//###############################################
//#  NACO DE COD PARA FILTRAR AS PLAVARAS,ELE FAZ:#
//#  PEGA AS LETRAS MAIÚSCULAS E MINUSCULAS E FAZ #
//#  A COMPARAÇÃO DE PALAVRAS REPITIDAS.          #
//###############################################

int i,j=0,cont=0,wi;

for( i=0;i<1024;i++)
contador[i]=1;  

for( i=0;cont<1024;i++){

   if( linha[i] >64 & linha[i] < 123 & ( linha[i] < 91 | linha[i] > 96 ) ){ // com o char menor que 64 ja ecluxir a maiorias dos lixos,logo ja exclui espaço em branco e quebra de linha ja separando palavras. 
    j=i;
    wi=0;
    
    while( wi < 21 & linha[j] >64 & linha[j] < 123 & ( linha[j] < 91 | linha[j] > 96 ) ){ // range 64 == a  a 123 == Z  .. de 91 a 96 sao decartados
      
      test[cont][wi]= linha[j];
      j++;
      wi++;
    } 
    test[cont][wi]=0;
    i=j;
    

     
     //###############################################
     //#  NACO DE COD PARA FAZER AS LETRAS MAISCÚLAS   #
     //#  FICAREM MINUSCULAS                           #
     //###############################################
     
     for(int n=0;test[cont][n]!=0;n++){
     if( test[cont][n] > 64 & test[cont][n] < 91 ){// 65 A 90 RANGE DAS LETRAS MAISCÚLAS
     char aux =test[cont][n] + 32; // 32 posiçoes sao entre  elas
     test[cont][n]=aux;  //32 letras da maiscúla ate minusculas .
      }
     }
    





    int k=0,l=0,primeiro;
    while( k < cont){
        
        if( comp( test[cont], test[k] )){
          k++;
         }
        else{
          l++; 
          if(l==1){
           primeiro=k;
           k++;
           contador[primeiro] = contador[primeiro] +1;  
           }
          else{
           contador[primeiro] = contador[primeiro] +1;
           k++;
           }
         }
       }
 
    if(l==0)
     cont++;


      
    }
   

    
   else{
        while(  linha[j]<64  | linha[j] > 123 | ( linha[j]== 91  | linha[j]== 92 | linha[j]==93  | linha[j]== 94 | linha[j]== 95 | linha[j]== 96 ) ){ // do range 91 a 96 e o intervalo entre letras maiscúlas e minusculas
           j++;
        }
       i=j-1;
      }

}




//###############################################
//#  funcao para mudar palavras para valores in- #
//#  interos                                     #
//###############################################
for( j=0;j<1024;j++){

long long acu=1;
long long macu;
for(int i=0;test[j][i]!=0;i++){
 acu= (acu * test[j][i]) -(i+1) ;
 
}
if(acu < 0 )// Para ficar negativa na hora do quicksort
acu=acu*-1;

array[j]=acu; // variavel global que guarda os valores

}






}


int comp( char *test, char *test1 ){ // funcao em alternativa ao strcomp
  int i=0;
   do{
    if(test[i]==test1[i]){
      if(test[i]== 0)
       return 0;//iguais
     
       i++;
     }
    else{
      return 1;//diferente
    }
    
  }while(i);

}
