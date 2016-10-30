#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE* archivo = fopen("Vibrio_cholerae.txt","r");
  int * buffer = NULL;
  int i, c;
  c = fgetc(archivo);
  while(!feof(archivo))
    {
      buffer = (int*)realloc(NULL, sizeof(int));
        i = 0;
      while( c != '\n')
        {
	if(c == 'A'){
          buffer[i] = 0;
          i++;
        }
	if(c == 'C'){
          buffer[i] = 1;
          i++;
        }
	if(c == 'T'){
          buffer[i] = 2;
          i++;
        }
	if(c == 'G'){
          buffer[i] = 3;
          i++;
        }
          c = fgetc(archivo);
          buffer = (int*)realloc(buffer, (i+1)*sizeof(int));

}
      /*Agrego el \n al buffer*/
      buffer = (int*)realloc(buffer, (i+2)*sizeof(int));
      buffer[i] = c;
      buffer[i+1] = 0;
      /*Trabajar con el buffer*/
      printf("archivo leido, ultimo elemento: %d\n", buffer[i-1]);
      c = fgetc(archivo);
    }
  close(archivo);


 int numeros=i;
 int max0=0,max1=0,max2=0,max3=0;
 int letrasRepetidas[4]={0,0,0,0};
 for(i=0;i<numeros;i++)
 {
	if(buffer[i]==0)
 	{
 	letrasRepetidas[1]=0;
 	letrasRepetidas[2]=0;
 	letrasRepetidas[3]=0;
 	letrasRepetidas[0]++;
 	if(letrasRepetidas[0]>max0){ max0=letrasRepetidas[0]; }
 	}
 	if(buffer[i]==1)
       {
         letrasRepetidas[1]++;
         letrasRepetidas[2]=0;
         letrasRepetidas[3]=0;
         letrasRepetidas[0]=0;
         if(letrasRepetidas[1]>max1){ max1=letrasRepetidas[1]; }
         }
 	if(buffer[i]==2)
         {
         letrasRepetidas[1]=0;
         letrasRepetidas[2]++;
         letrasRepetidas[3]=0;
         letrasRepetidas[0]=0;
         if(letrasRepetidas[2]>max2){ max2=letrasRepetidas[2]; }
         }
 	if(buffer[i]==3)
         {
         letrasRepetidas[1]=0;
         letrasRepetidas[2]=0;
         letrasRepetidas[3]++;
         letrasRepetidas[0]=0;
         if(letrasRepetidas[3]>max3){ max3=letrasRepetidas[3]; }
         }
 
 }
 printf("el maximo de A es: %d\n",max0);
 printf("el maximo de C es: %d\n",max1);
 printf("el maximo de T es: %d\n",max2);
 printf("el maximo de G es: %d\n",max3);

}
