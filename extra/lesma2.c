#include <stdio.h>
int level(int a){
int l=0;
if(a<10){
l=1;
}
else if(a>=10 && a<20){
l=2;
}
else{
l=3;
}
return l;
}
int main(){
int n=0;
int j=0;
int a=0;
int m=0;
scanf("%d",&n);
for(int i=1;i<=n;i++){
scanf("%d", &j);
if(a<j){
a=j;
}
}
m=level(a);
printf("%d",m);
}