// WEEK 1
/*
#include <stdio.h>   // LAB 1 POPULATION
#include <stdlib.h>

int main()  
{
    int s, f, i = 0;
    
    do
    {
    printf("\nEnter the starting year: ");
    scanf("%d", &s);
    }
    while(s < 9);
    
    do
    {
    printf("\nEnter the final year: ");
    scanf("%d", &f);
    }
    while(f < s);

    do
    {
    s = s + s/3 - s/4;  
    i++;
    }
    while (s != f);

    printf("\nNo of years: %d", i);
    

    return 0;
}
*/
/*
#include <stdio.h>   
#include <stdlib.h>            // PROBLEM SET1

int main()
{   
    int n;
    
    do
    {
    printf("\nEnter the number: ");
    scanf("%d", &n);
    }
    while(n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < i+1 ; j++)
      {
          printf("#");
      }
      printf("\n");
    }
    return 0;
}*/
/*
#include <stdio.h>   
#include <stdlib.h>            // PROBLEM SET1

int main()
{   
    int n;
    
    do
    {
    printf("\nEnter the number: ");
    scanf("%d", &n);
    }
    while(n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n ; j++)
      {
          if(j < n-i-1)
          {
            printf(" ");
          }
          else
          {
            printf("#");
          }
      }
      printf("\n");
    }
    return 0;
}
*/
/*
#include <stdio.h>   
#include <stdlib.h>            // PROBLEM SET1

int main()
{   
    int n;
    
    do
    {
    printf("\nEnter the number: ");
    scanf("%d", &n);
    }
    while(n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < 2*n; j++)
      {
          if(j < n-i-1 || j > n+i)                    // || j > n+i
          {
            printf(" ");
          }
          else if(j == n-1)
          {
            printf("#  ");
          }        
          else
          {
            printf("#");
          }
      }
      printf("\n");
    }
    return 0;
}
*/
/*
#include <stdio.h>   
#include <stdlib.h> 
int main()
{  
  float n;
  int counter = 1;
  do
  { 
    scanf("%f", &n);
  }
  while(n < 0);

  n = n*100;
                         // how to round digits in c
  while (n > 25)
  {
    n = n-25;
    counter++;
  }
 
  while (n > 10)
  {
    n = n-10;
    counter++;
  }
  
  while (n > 5)
  {
    n = n-5;
    counter++;
  }
 
  while (n > 1)
  {
    n = n-1;
    counter++;
  }

  printf("%d",counter);
  return 0;
}
*/
#include <stdio.h>   
#include <stdlib.h>
int main()
{ 
  unsigned long long int x, y;
  scanf("%llf",&x);
  y=x;

  for(int i = 0; i < 16; i+=2)
  {
     
  }
  return 0;
}








