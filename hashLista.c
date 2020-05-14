static int po;
typedef struct es{
 int repidas;
 char palavra[23];
 struct es * prox;
}es;

es table[1024]; // STRUCT QUE IMITA A  LISTA DE VETOR DAS HASH ABERTA

void add( long long x,char y[23],int cont ); // ADD NA ESTRUTURA E LISTA TAMBEM
void pega( long long acu , char in[23] ); //PESQUISA PELA PALAVRA
int iguais( char testdes[23] ,char test[23] ); // COMPARA AS STRINGS
void hashA(int argv[],char* argc[]);// MAIN DO HASH

void add( long long x,char y[23] ,int cont ){
  es * aux= &table[x];

  int i;
  while (1){

  if( aux->prox== NULL){
  aux->prox=(es*)malloc(sizeof(es));  
  aux=aux->prox;
  for (i = 0; (y[i] != 0 & i<22); i++)
  aux->palavra[i]=y[i];
  aux->palavra[i+1]=0;
  aux->repidas=cont;
  aux->prox=NULL;
  return; 
   }
  else{
   aux=aux->prox; // AVANÇA ATE ACHAR O NULL
   }  

  
  }
}

void hashA(int argv[],char* argc[]){

arquivando( argv,argc );
float tempo;
time_t t_init,t_fim;


for(int i=0;i<1024;i++){//INICIALIZA 
table[i].repidas=0;
table[i].prox=NULL;
}


for(int i=0;i<1024;i++){
add( array[i]%1024 , test[i] , contador[i]);
}



char in[23];
int sair;
long long acu;


acu=1;  
printf("digite a palavra\n");
scanf("%s",&in);
for(int i=0;in[i]!=0;i++){
 acu= (acu * in[i]) -(i+1) ;
}
if(acu < 0 )
acu=acu*-1;

clock_t t;

t=clock();
po=0;
pega( acu %1024 , in );

t= clock() -t;


printf("tempo de  execuçao de hashAberta  foi =>%lld\n",t);

}



void pega( long long acu , char in[23]  ){
int i=1;  
es *p=&table[acu];
po++;
if( p->prox == NULL ){
printf("nao possui essa palavra no texto \n");
return;
}
p=p->prox;

while(1){// WHILE PARA ACHAR A PALAVRA E COMPARAR A STRING UMA POR UMA
if(  iguais( p->palavra ,in ) ){
printf("A palavra %s possui no texto e repitiu %d vezes totais de interaçoes '%d' \n ",p->palavra,p->repidas,po);
return;
}
else{
   if( p->prox == NULL ){
   printf("nao possui essa palavra no texto \n"); 
   return;
   }
   else{
   po++;
   p=p->prox;
  }
 
 }
}

}

int iguais( char testdes[23] ,char test[23] ){
  int i=0;
  
   do{
    if( testdes[i] == test[i] ){
      if( testdes[i] == 0 )
       return 1;//iguais
     
       i++;
     }
    else{
      return 0;//diferente
    }
    
  }while(i);

}
