#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
  
// Function to randomly generates password
// of length N
void randomPasswordGeneration(int N,char *str)
{
    // Initialize counter
    int i = 0;
  
    int randomizer = 0;
  
    // Seed the random-number generator
    // with current time so that the
    // numbers will be different every time
    srand((unsigned int)(time(NULL)));
  
    // Array of numbers
    char numbers[] = "0123456789";
  
    // Array of small alphabets
    char letter[] = "abcdefghijklmnoqprstuvwyzx";
  
    // Array of capital alphabets
    char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
  
    // Array of all the special symbols
    char symbols[] = "!@#$^&*?";
  
    // Stores the random password
    char password[N];
    //store the random password for a file 
    char mdp[N];
  
    // To select the randomizer
    // inside the loop
    randomizer = rand() % 4;
  
    // Iterate over the range [0, N]
    for (i = 0; i < N; i++) {
  
        if (randomizer == 1) {
            password[i] = numbers[rand() % 10];
            randomizer = rand() % 4;
            mdp[i]=password[i];
            //printf("%c", password[i]);
        }
        else if (randomizer == 2) {
            password[i] = symbols[rand() % 8];
            randomizer = rand() % 4;
             mdp[i]=password[i];
           // printf("%c", password[i]);
        }
        else if (randomizer == 3) {
            password[i] = LETTER[rand() % 26];
            randomizer = rand() % 4;
            mdp[i]=password[i];
           // printf("%c", password[i]);
        }
        else {
            password[i] = letter[rand() % 26];
            randomizer = rand() % 4;
            mdp[i]=password[i];
            //printf("%c", password[i]);
        }
    }
    strcpy(str,mdp);
}
  
// Driver Code
int main()
{
    // Length of the password to
    // be generated
    int N = 10;
    char ID[25];
    char pwd[25];
    int i= 0;
    char c ;
    FILE *fp ;
    system("touch password.txt");
     fp=fopen("password.txt","r+");
    if(fp!=NULL)
    {
    printf("Entrez l adresse du site web dont vous voulez sauvegardez le MDP:\n");
   fflush(stdin);
    fgets(ID,sizeof(ID),stdin);
    fputs(ID,fp);
    randomPasswordGeneration(N,pwd);
    fprintf(fp,"\nID : %s ",pwd);
   /* for(i=0;ID[i]!='\0';i++)
    {
        c=ID[i];
    fputc(c,fp);
    }*/
    }
    else 
    printf("Impossible d ouvrir le fichier ");
    fclose(fp);
    // Function Call

  
    return 0;
}