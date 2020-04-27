

static int repitou=0;
int funcao(int esq,int dir,int meio,long long a[10],long long escolha);
void searchbinary(int argv[], char *argc[]);

int funcao(int esq,int dir,int meio,long long a[10],long long escolha){
 
int b;
 if(esq <= dir){

meio =(dir+esq)/2;
 if(a[meio] == escolha)
 return meio;
 if( a[meio] > escolha )
 {
 repitou++;    
 b=funcao( esq , meio-1, meio , a , escolha ); 
 }
 
 else if( a[meio] < escolha )
  {
  repitou++;
  b=funcao( meio+1 , dir, meio , a, escolha );
  }
 
 }
 return b;
 
}





void searchbinary(int argv[], char *argc[]){
    float tempo;
    time_t t_init,t_fim;

    char aux[1][22];
    long long acu=1;
    Fisrtquicksort(argv,argc);

    printf("Digete a palavra \n ");
    scanf("%s",&aux[0]);
    aux[0][21]=0;
    for(int i=0;aux[0][i]!=0;i++){
    acu= (acu * aux[0][i]) -(i+1) ;
    }

    t_init=time(NULL);
   int posicao=funcao(0,1023,0,vetor,acu);// passando a 'VARIAVEL GLOBAL' ->VETOR  DECLARADA NO ARQUIVO QUICKSORT QUE E 'VARIAVEL GLOBAL ARRAY' DO ARQUIVO ARQUIVANDO.C ORDENADA.  
    t_fim=time(NULL);
    
  
    printf("A palavra '%s' possui no texto e repitiu %lld vezes e total foi = %d \n",words[posicao],ordenacao[posicao],repitou);
  
   printf("Search binary tempo de  execuçao em segundos foi =>%.5f\n",tempo);
}
