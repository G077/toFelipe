static int ac;

typedef struct no
{
	char palara[23];
	int num;
	long long valor;
	struct no *dir;
	struct no *esq;
}no;

void inserir( no * raiz ,char pala[23],int num,long long va  ); // caça locais para serem alocados ;
void adicao( int d ,no * raiz ,char pala[23],int num,long long va );// funcao que realmente alocar folhas;
void adicaoiguais( int d ,no * raiz ,char pala[23],int num,long long va ); // alocar para faz o traramento de collisao para valores iguais
void inicial( no * raiz ,char pala[23],int num,long long va );// so pega os valroes das posiçoes 0 dos vetores para fazer a raiz 
void tri( char palara[23],char palara1[23]);// faz a copia da palavra do vetor para folha guardar
void btree(int argv[],char* argc[]);// funcao main para arvores

void inserir( no * raiz ,char pala[23],int num,long long va  ){

  if( va ==raiz->valor ){
    if( raiz->dir != NULL )
    adicao( 1,raiz,pala,num,va );// 1 representa a alocar A direita
    else if( raiz->esq != NULL )
    adicao( 0,raiz,pala,num,va );// 0 representa a alocar a esquerda
	else 
    adicaoiguais(0,raiz,pala,num,va ); // sem poder alocar o tramento de colisao vai para essa funcao para ser tratada.
  }
  else if( va > raiz->valor ){
	if( raiz->dir != NULL)
    inserir( raiz->dir,pala,num,va );
    else{
    adicao( 1,raiz,pala,num,va );
	}
  }
  else if( va < raiz->valor ){
    if( raiz->esq != NULL)
	inserir( raiz->esq,pala,num,va );
    else{
     adicao( 0,raiz,pala,num,va );		
	}
  }  
}

void adicaoiguais( int d ,no * raiz ,char pala[23],int num,long long va ){
no *aux=raiz;
while( aux->esq != NULL)
 aux=aux->esq;
 
aux->esq=( no * )malloc( sizeof(no));
aux=aux->esq;

aux->num=num;
aux->valor=va;
tri(aux->palara,pala);
aux->dir=NULL;
aux->esq=NULL;

}





void adicao( int d ,no * raiz ,char pala[23],int num,long long va ){
if( d == 1){
raiz->dir=( no * )malloc( sizeof(no));
raiz=raiz->dir;
}
else{
raiz->esq=( no * )malloc( sizeof(no));
raiz=raiz->esq;
}

raiz->num=num;
raiz->valor=va;
tri(raiz->palara,pala);
raiz->dir=NULL;
raiz->esq=NULL;

}

void inicial( no * raiz ,char pala[23],int num,long long va ){
raiz->num=num;
raiz->valor=va;
tri(raiz->palara,pala);
raiz->dir=NULL;
raiz->esq=NULL;

}
void tri( char palara[23],char palara1[23]){
int i;
for(i=0; palara1[i] != 0 ;i++)
palara[i]=palara1[i];
palara[i]=0;

}



void qual( no *raiz , long long x ,char pa[23] ){
  if( x == raiz->valor ){

   if( comp( raiz->palara ,pa ) == 0 ){// 0 iguais
   ac++;
   printf("A palavra '%s' possui no texto e repitiu %lld vezes e total foi = '%d' \n",raiz->palara,raiz->num,ac);
   }
   else{
   while( comp( raiz->palara ,pa ) == 1 & raiz->esq != NULL ){ // valor iguais  mas palavras defirente logo uma colisao ,para esse tramento ele corre toda para a esq e faz a compação de palavra a palavra ate char ou nao;
    ac++;
	raiz=raiz->esq;
   }
    if(raiz->esq != NULL ){
      printf("palavra nao encontrada\n");
      return;
    } 
    printf("A palavra '%s' possui no texto e repitiu %lld vezes e total foi = '%d' \n",raiz->palara,raiz->num,ac);
   }

   }
  else if( x < raiz->valor ){
   if( raiz->esq != NULL){
   ac++;
   qual( raiz->esq ,x ,pa);
   }
   else
   printf("valor nao encontrado\n");  
  }
  else if( x > raiz->valor ){
   if( raiz->dir != NULL){
   ac++;	   
   qual( raiz->dir ,x ,pa );
   }
   else
   printf("valor nao encontrado\n");  
  }
 
}


void btree(int argv[],char* argc[]){


no raiz; //NO RAIZ
arquivando( argv,argc );
float tempo;
time_t t_init,t_fim;

inicial( &raiz,test[0],contador[0],array[0] );// INICIA INICIALIZA O RAIZ QUE UMA ESTRUTURA PARA NÃO FICAR INDEFINIDO.

for(int i=1;i<1024 ;i++)
inserir( &raiz,test[i],contador[i],array[i] );// CRIA A ARVORE INSERINDO  PALAVRAS E NUMERO DOS INDENTIFICADORES E A REPETIÇAO DAS  PALVRAS   

char in[23];
printf("qual palavra ?\n");
scanf("%s",&in);

// NACO DE COD PARA PEGAR A PALAVRA'IN' E TRANSFORMA-LA EM VALOR NUMERICO PARA SER COMPARADA NA VALORES DAS FOLHAS DAS ARVORES.
//
long long acu=1;
long long macu;
for(int i=0;in[i]!=0;i++){
 acu= (acu * in[i]) -(i+1) ;
 
}
if(acu < 0 )
acu=acu*-1;

// FIM DO NACO
 t_init=time(NULL);

ac=0;
qual( &raiz,acu,in );// INCIO DA PESQUISA PESQUISA 

t_fim=time(NULL);
tempo =difftime( t_fim,t_init );

printf("tempo de  execuçao em segundos foi =>%.5f\n",tempo);
}
