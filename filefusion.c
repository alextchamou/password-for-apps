#include<stdio.h>
#include<stdlib.h>

int main()
{
    //files open
   system("touch file1.txt");
   system("touch file2.txt");
    FILE *f1=fopen("file1.txt","r");
    FILE *f2=fopen("file2.txt","r");

//open file of destination for the copy
// lorsque tu fais une ouverture en mode w ecriture si le fichier n exite pas il est cree
FILE *f3 = fopen("file3.txt","w");
char c;
if(f1 == NULL || f2 == NULL || f3 == NULL)
{
    puts("Impossible to open the files");
    exit(EXIT_FAILURE);
}

//copy of file f1 in to f3
while((c = fgetc(f1)) !=EOF)
fputc(c,f3);

//copy of file f2 in to f3
while((c = fgetc(f2)) != EOF)
fputc(c,f3);
printf("les deux fichiers sont bien fusionnes dans le file3.txt ");
fclose(f1);
fclose(f2);
fclose(f3);
return 0 ;
}