


void pesqsequencia(int argv[], char *argc[]);

void pesqsequencia(int argv[], char *argc[]){

arquivando(argv,argc);
int i;

float tempo;
time_t t_init,t_fim;
 
char in[23];
long long acu;

acu=1;  
printf("digite a palavra\n");
scanf("%s",&in);
for(int i=0;in[i]!=0;i++){
 acu= (acu * in[i]) -(i+1) ;
}
if(acu < 0 )
acu=acu*-1;


t_init=time(NULL);
for(i=0;i<1024 ;i++){
  if( acu == array[i] ){
  printf("A palavra '%s' possui no texto e repitiu %d vezes e total foi = %d \n",test[i],contador[i], i+1 );
  break;
  }

}
t_fim=time(NULL);
tempo =difftime( t_fim,t_init );


printf("tempo de  execuçao em segundos foi =>%.5f\n",tempo);

}

