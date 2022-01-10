#include<stdio.h>
#include<stdlib.h>
typedef struct student student ;//allias a la structure student 
struct student{
    char ID[15];
    char name[20];
    char vorname[20];
    char add[20];//adresse 
    int Class;
    long unsigned int telefonnummer;
};
student stu;
void get_password(char* pass)
{
    char temp_passP[25];
    int i=0 ;
    while(1)
    {
        temp_passP[i]=getc();
        if(temp_passP[i]==13){break;}
        else if(temp_passP[i]==8)
        {
            if(i!=0)
        {
             printf("\b \b");
             i--;
        }
        else{printf("\a");}
        }
        else
        {
            printf("*");
            *(pass+i)=temp_passP[i];
            i++;
        }
        *(pass+i)='\0';
    }
}
void use_passs_field()
{
    int use;
    char pass[10];
     printf("\n The Database is password protected.\n");
     printf("\nEnter valid username and password\n");
     printf("USERNAME:- \n");
     printf("PASSWORD:- \n");
     scanf("%d",&use);
    get_password(pass);
     }
     void add_student(){
         //find a way to clean the window
         printf("Add Record");
         FILE *fp;
         fp=fopen("record.txt","ab+");
         if(fp==NULL)
         {
             printf("\nEroor in Opening file\n Make sure your file is not write protected");
         }
         else{
             fflush(stdin);
             printf("\nID: ");fgets(stu.ID,sizeof(stu.ID),stdin);
             printf("\nAdress: ");fgets(stu.add,sizeof(stu.name),stdin);
             printf("\nParent's name: ");fgets(stu.vorname,sizeof(stu.vorname),stdin);
             printf("\nClass : ");scanf("%d",&stu.class);
             printf("\nPhone Number: ");scanf("%ld",&stu.telefonnummer);
             fwrite(&stu,sizeof(stu),1,fp);
             printf("\nThe record is sucessfully added");
         }
         fclose(fp);//fermeture du fichier fp
         return ;
         }
         void_search_student(){
             // I have to clean the screen at this place
Printf("\nsearch Record");
char s_id[15];
int isFound=0;
printf("\nEnter the ID to search: ");fflush(stdin);
fgets(s_id,sizeof(s_id),stdin);
File *fp;
fp=fopen("record.txt","rb");
while(fread(&stu,sizeof(stu),1,fp)==1)
{
    if(strcmp(s_id,stu.ID)== 0)
    {isFound = 1 ;}
    break ;
}
if(isFound == 1)
{
    printf("\nThe record is Found ");
    printf("ID: %s",stu.ID);
    printf("\nName: %s",stu.name);
    printf("\nAdress: %s",stu.add);
    printf("\nParent's Name: %s",stu.vorname);
    printf("\nClass: %d",stu.Class);
    printf("Phone No: %ld",stu.telefonnummer);
}
else{printf("\nSorry, No record found in the database");}
fclose(fp);
         }
         return;
     }
void mod_student()
{
    //clean the windows at this place 
    printf("MOdify Record");
    char s_id[15];
    int isFound = 0;
    printf("Enter ID to Modify: ");fflush(stdin);
    fgets(s_id,sizeof(s_id),stdin);
    File *fp;
    fp=fopen("record.txt","rb+");
    while(fread(&stu,sizeof(stu),1,fp)==1)
    {
        if(strcmp(s_id,stu.ID)==0)
        {
            printf("\nID: ");fgets(stu.ID,sizeof(stu.ID),stdin);
             printf("\nAdress: ");fgets(stu.add,sizeof(stu.name),stdin);
             printf("\nParent's name: ");fgets(stu.vorname,sizeof(stu.vorname),stdin);
             printf("\nClass : ");scanf("%d",&stu.Class);
             printf("\nPhone Number: ");scanf("%ld",&stu.telefonnummer);
             fseek(fp,-sizeof(stu),SEEK_CUR);
             fwrite(&stu,sizeof(stu)),1,fp);
             isFound = 1 ;
             break ;
        }
    }
    if(!isFound){printf("\nNo Record Found");}
    fclose(fp);
    return ;
}
void delete_student()
{
    //clean windows at this position 
printf("Delete Record");
char s_id[15];
int isFound = 0 ;
printf("\nEnter ID to Modify: ");fflush(stdin);
fgets(s_id,sizeof(s_id),stdin);
File *fp, *temp;
fp = fopen("record.txt","rb");
temp = fopen("temp.txt","wb");
while(fread(&stu,sizeof(stu),1,fp)== 1)
{
    if(strcmp(s_id,stu.ID)== 0)
    {
        fwrite(&stu,sizeof(stu),1,temp);
    }
}
fclose(fp);
fclose(temp);
remove("record.txt");
rename("temp.txt","record.txt");
printf("\nThe record is successfully deleted");
return ;
}

void main_window()
{
    int choice ;
    int x = 2 ;
    while(1)
    {
        printf("\n1.Add student");
         printf("\n2. Search Student");
         printf("\n3. Modify Student Record");
         printf("\n4. Delete Student Record");
         printf("\n5. Change password");
         printf("\n6. Exit");
         printf("Enter your choice");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:
             add_student();
             break ;
             case 2:
             search_student();
             break ;
             case 3:
             mod_student();
             break ;
             case 4: 
             delete_student();
             break ;
             case 5: // i have to work again on password changed
             break ;
             case 6:
             exit(0);
             break;
             default:
             break ;
         }
    }
}
int main()
{
    printf("\nwelcome at the Technical uni of Kaiserslautern");
    main_window();
    return 0;
}