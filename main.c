#include <stdio.h>
#include <ctype.h>

#define ELEVER 5 
#define PROV 13 

int main () {
char namn
int poäng
double medel 
double total

for (int i = 0; i < ELEVER; i++) 
{
scanf("%10s", namn [i]);
 int sum = 0;

for (int j = 0; j < PROV; j++) 
{ scanf("%d" , &poäng[i][j]);
sum += poäng [i][j];
}
medel[i] = (double)sum / PROV;
total += medel[i];

namn [i][0] = toupper(namn[i][0]);
for(int k = 1; namn[i][k] != '\0'; k++)
{ 





  

