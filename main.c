 #include"header.h"
 
 void main(int argv[], char *argc[]){


//argc[1]); // tabelas 
//argc[2]); // texto

 char a[]={"pseq"}; 
 char b[]={"pbinaria"};
 char c[]={"arvore"};
 char d[]={"haberto"};
 char e[]={"hlista"};
 

      if( comp(a,argc[1]) == 0 ){
       
         pesqsequencia( argv, argc );
      }
      else if( comp(b,argc[1]) == 0 ){
       
         searchbinary( argv, argc );
      }
      else if( comp(c,argc[1]) == 0){
       
         btree( argv, argc );
      }
      else if( comp(d,argc[1]) == 0){
        hashF( argv, argc );

      }
      else if( comp(e,argc[1]) == 0){
       
         hashA( argv, argc ); 
      }
      else{
          printf("Dados digitados errados \n");
      }
 }