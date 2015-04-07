#include<stdio.h>
int main(void)
{
 char a[200];
 char ch;
 int i,x,y;
 int j;

printf("Enter a sentence:how are you");
 for(i=0;i<200;i++)
 {
  scanf("%c",&a[i]);
  if(a[i]=='\n')
  {
   x=i;
   break;
  }
 }
 //´¢´æ×Ö·û´®
 ch=a[x-1];
 printf("%c\n",ch);
 //´¢´æÖÕÖ¹·û
 for(i=0;a[i]!=' ';i++)
  ;
 j=i;
 printf("%d\n",j);
 //¼ÆËãµÚÒ»¶Î×Ö·û³¤¶È
 /*while(1)
 {
  if(x==j)
   goto L;
  for(i=x;a[i]!=' ';i--)
   ;
  y=i;
  for(i=y;i<x;i++)
   printf("%c",a[i]);
  x=y;
 }*/
L: for(i=0;i<j;i++)
  printf("%c",a[i]);
 //Êä³öµÚÒ»¶Î×Ö·û´®
 printf("%c\n",ch);
//Êä³öÖÕÖ¹·û
 return 0;
}
