char table1[1434][23]; // (1024== VAGAS PRINCIPAIS) + (410 == VAGAS PARA COLISÕES)

//TABLE1 E VARIAVEL GLOBAL PARA NÃO USAR PONTERIO PARA TRATAR A TABELA

void stri( char a[23] ,long long x ); //COPIA A PALAVRA NA POSIÇAO
void add1( long long x,char y[23]  ); // QUE ALOCA A PALAVRA NA POSIÇAO
void pega1( long long acu , char in[23] ,int repetidas );
int iguaus1( long long acu ,char test[23] ); // SE AS STRINGS SAO IGUAIS
void hashF(int argv[],char* argc[]); // MAIN DA HASHF
int gauis1( long long acu ,char test1[23] ); // PEGA O VALOR  DA PALAVRA DE INPUT PARA A BUSCA, E GUARDA QUNATAS VEZES QUE ELA REPITIU COMPARANDO COM A VARIVEL GLOBAL 'TEST' NO ARQUIVO ARQUIVANDO.C COMPARANDO STRING A STRING PARA PEGAR A POSIÇÃO. 

void add1( long long x,char y[23]  ){

  int k=1;
  if( table1[x][0] == 0 ){
  stri( y,x );
  }
  else {
  while(k<410)
  {
  if( table1[1023+k][0] == 0 ){
     stri( y,1023+k );
     return;
    }
     k++;
  }

  }
}
void stri( char a[23] ,long long x ){
int i;
for (i = 0; a[i] != 0 ; i++)
table1[x][i]=a[i];
table1[x][i+1]=0;

}

int iguaus1( long long acu ,char test1[23] ){
  int i=0;
   do{
    if( table1[acu][i]==test1[i] ){
      if( table1[acu][i] == 0 )
       return 1;//iguaus1
     
       i++;
     }
    else{
      return 0;//diferente
    }
    
  }while(i);

}

int gauis1( long long acu ,char test1[23] ){
  int i=0;
   do{
    if( test[acu][i]==test1[i] ){
      if( test[acu][i] == 0 )
       return 1;//iguaus1
     
       i++;
     }
    else{
      return 0;//diferente
    }
    
  }while(i);

}

void pega1( long long acu , char in[23] ,int repetidas  ){
int cont=1;

 if(table1[acu] == 0 ){
    printf(" nao possur essa palavra ! \n");
    return;
}
else {
   if( iguaus1(acu ,in) ){
   
   printf("no texot possui a palavra '%s' no arquivo e total de interaçoes foi '%d' quantidade de palavras repetidas '%d'\n\n ",table1[acu],cont ,repetidas);

   }
  
   else{

   long long acu1=1024;
   for(int i = 1024 ;table1[i] != 0 ; i++)   
      {
     cont++; 
     if( iguaus1( acu1 ,in) ){
     printf("no texot possui a palavra '%s' no arquivo e total de interaçoes foi '%d' quantidade de palavras repetidas '%d'\n\n  ",table1[i],cont ,repetidas); 
      return;
      }
     acu1++;
     }
   }  

  }
}

void hashF(int argv[],char* argc[]){

arquivando( argv,argc );

float tempo;
time_t t_init,t_fim;

for(int i=0;i<1434;i++) // SETANDO 0 EM TODAS POSIÇOES PARA FAZER A COMPARAÇÃO PARA VER SE A POSIÇAO E VAZIA == 0  OU NAO != DE 0
table1[i][0]=0;

for(int i=0;i<1023;i++)
add1( array[i]%1024 , test[i] );

char in[23];
int sair;
long long acu;

acu=1;  
printf("digite a palavra\n");
scanf("%s",&in);
int a;
for(long long i=0;i<1024;i++){
if( gauis1(i , in) ){
 a=i;
}
}


for(int i=0;in[i]!=0;i++){
 acu= (acu * in[i]) -(i+1) ;
}
if(acu < 0 )
acu=acu*-1;

 t_init=time(NULL);

pega1( acu %1024 , in ,contador[a] );

t_fim=time(NULL);
tempo =difftime( t_fim,t_init );

printf("tempo de  execuçao em segundos foi =>%.5f\n",tempo);



}




