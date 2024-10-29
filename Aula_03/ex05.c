#include <stdio.h>
int main (int argc, char **argv){
  int i,cont=0;
  char s[100];
  char ss[100];

  //ler string sem espaco
  scanf("%s",s);   

  //ler string com espaco
  scanf("%[^\n]",ss);  

  for (i = 0 ; s[i] != '\0' ; i++){
    if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
      cont++;
    }
  }

  printf("A string tem %d vogais\n",cont);

  int count = 0;  

  for (i = 0 ; ss[i] != '\0' ; i++){
    if(ss[i]=='a' || ss[i]=='e' || ss[i]=='i' || ss[i]=='o' || ss[i]=='u'){
      cont++;
    }
  }

  printf("A string tem %d vogais\n",cont);
  
  return 0;
}