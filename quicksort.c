
//
//VARIAVEL GLOBAL  'LONG LONG vetor' GUARDA OS VALORES NUMERICOS REFERENTE AS PALAVRAS E USA A VARIAVEL GLOBAL 'ARRAY' DO ARQUIVO ARQUIVANDO.C EM PARA FORMAR ELE.  
//
//VARIAVEL GLOBAL  'CHAR words' GUARDA AS PALAVRAS DA VARIAVEL GLOBAL 'TEST' DO ARQUIVO ARQUIVANDO.C EM FORMA ORDENADA
//


void quickSort(long long int arr[], int low, int high);
int partition (long long int arr[], int low, int high);
void cop(long long test[]);
void ordenar();
int comp1( long long test,long long test1[] );
void swap(long long * a, long long* b);
void Fisrtquicksort(int argv[], char *argc[]);
void repitidaorde();


long long vetor[1024];
     char words[1024][22];
int ordenacao[1024];

int comp1( long long test, long long test1[] ){
  int i=0;
   do{
    if(test != test1[i]){

       i++;
     }
    else{
      return i;//achando
    }
    
  }while(i<1024);
 return -1;
}

void swap(long long * a, long long* b) 
{ 
    long long t = *a; 
    *a = *b; 
    *b = t; 
} 
  
int partition (long long int arr[], int low, int high) 
{ 
    long long pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

void quickSort(long long int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  

void Fisrtquicksort(int argv[], char *argc[]) 
{ 
    arquivando( argv,argc );
    cop(vetor);
    int n = sizeof(vetor)/sizeof(vetor[0]); 
     quickSort(vetor, 0, n-1);   
     ordenar();
    repitidaorde();

} 


void ordenar(){

for(int i=0 ; i<1024;i++){
int aux=comp1( vetor[i] ,array);
if( aux == -1){
    printf("error:ordenar comp1 retonou -1");
  return;
}
strcpy(words[i],test[aux]);

}

}



void cop(long long test[]){
 for(int i=0 ; i<1024;i++)
 test[i]=array[i];
}


void repitidaorde(){
   
   for(int i=0;i<1024;i++){
   
     for(int j=0;j<1024;j++){
       if( array[j] ==vetor[i] ){
       ordenacao[i]=contador[j];
       }
     }
   
   }



}