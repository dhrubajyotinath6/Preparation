#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void charcount(char *st, int freq[]){

   int i, counter;
   char ttmp;

   for(i = 0; i < 26; i++)
   {
     freq[i] = 0;
   }

   for (counter = 0; st[counter] != '\0'; counter++)
   {
       
       if(isalpha(st[counter]))
       {

         ttmp = tolower(st[counter]);
         freq[ttmp - 'a']++;
       }


   }
  // for (i = 0; i <26; i++)
  // {
  //  printf("\n %c \t %d", 'a' + i, freq[i]);
  // }
}

int main(){

 char inpstr[30]="apple";
 int i, hfreq[26];
 //printf("Enter the string please:");
 //gets(inpstr);
 charcount(inpstr, hfreq);
 for (i = 0; i <26; i++)
 {

 printf("\n %c \t %d", 'a' + i, hfreq[i]);

 }
 return 0;
}
