// %d = Heltal
// %f = Decimaltal
// %c = Tecken
// %s = Strängar
// scanf kan inte läsa "white spaces", istället kan vi använda fgets om det är mellanslag i strängen vi vill läsa in.
// fgets = file get string
// '\0' är en null terminator

#include <stdio.h> // Standardbibliotek så att vi kan använda scanf och printf
#include <ctype.h> // För att kunna jobba med tecken (toupper, tolower)

/*
#define betyder att varje gång ELEVER, PROV, NAMN dyker upp i programmet så ersätts det med 5 för ELEVER, 11 för NAMN och 13 för PROV
*/
#define ELEVER 5 
#define PROV 13 
#define NAMN 11 
int main () {

char namn[ELEVER][NAMN]; 
int prov[ELEVER][PROV];
double medel[ELEVER];

int hogst = 0;
double total = 0; 
for (int i = 0; i < ELEVER; i++) 
{ 
    int summa = 0;
    scanf("%10s", namn[i]); // Läser in elevernas namn, "%10s" betyder att vi vill läsa in en sträng som innehåller 10 tecken.
    
    for (int j = 0; j < PROV; j++) // Loopar igenom proven och läser in poäng
{ 
    scanf("%d" , &prov[i][j]);
    summa += prov [i][j]; // Lägger ihop provpoäng
}
medel[i] = (double)summa / PROV; // Räknar ut medelpoäng
total += medel[i]; // total = total + medel
namn [i][0] = toupper(namn[i][0]); // Gör första bokstaven stor
for(int k = 1; namn[i][k] != '\0'; k++) // != (inte lika med)
{
     namn[i][k] = tolower(namn[i][k]); // Gör alla bokstäver små efter den första bokstaven i namnet
} 
 
}

for(int i = 1; i < ELEVER; i++) // Jämför alla elevers medelpoäng för att hitta den med högst
/*Börjar räkna från 1 för att hogst = 0 är vår startpunkt
och vi behöver inte jämföra elev 0 med elev 0*/
{
    if (medel[i] > medel[hogst]) // Om nuvarande elev har högre medel än den som just nu har högst så blir hogst = i
    {
        hogst = i;
    }
}
printf("%s\n", namn[hogst]); // Skriver ut elev med högst medel

double snitt = total / ELEVER; // Klassens medelvärde 
for (int i = 0; i < ELEVER; i++) 
{
    /*Loopar igenom elevernas medelvärde
    och skriver ut namnet på elever som har lägre medelvärde än klassens snitt*/
   if (medel[i] < snitt)
   {
    printf("%s\n", namn[i]);
   }
}
return 0; 
}