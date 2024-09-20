#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define SIZE 100

void menu();
void start();
void back();
void add();
void display();
void search();
void edit();
void erase();


struct Person
{
    char name[SIZE];
    char father_name[SIZE];
    char mother_name[SIZE];
    char address[SIZE];
    char gender[SIZE];
    long int mobile;
    char mail[SIZE];
    char nationality[SIZE];
} p;
FILE *fp, *ft;
int i, t;

int main()
{
    system("COLOR 8E");
    start();
    return 0;
}

void back()
{
    start();
}

void start()
{
    menu();
}


void menu()
{


    system("cls");
    system("COLOR 1E");
    printf("\t   ------------------------------------------\n>>>>>>>>>>>|  Welcome to Contact Management System  |<<<<<<<<<<<\n\t   ------------------------------------------");
    printf("\n\n\n\t\t\t  MAIN MENU\n\t\t______________________________\n\t\t||  (1) Add A New Contact   ||\n\t\t||  (2) List All Contacts   ||\n\t\t||  (3) Search For Contact  ||\n\t\t||  (4) Edit A Contact      ||\n\t\t||  (5) Delete A Contact    ||\n\t\t||  (0) Exit                ||\n\t\t------------------------------\n\t\t");

    int digit;
    printf("\n\t\tEnter Your Choice : ");
    scanf("%d", &digit);

    switch(digit)
    {
    case 0:
        printf("\n\t\tSuccessfully Exit.\n\t\tThank You.\n\n");
        exit(0);
    case 1:
        add();
        break;
    case 2:
        display();
        break;
    case 3:
        search();
        break;
    case 4:
        edit();
        break;
    case 5:
        erase();
        break;
    default:
        printf("\n\t\tInvalid Choice.\n\t\tPlease Try Again.\n");
        menu();
    }
}

void add()
{
    system("cls");
    fp = fopen("Project.txt", "ab+");
    for( ; ; )
    {
        fflush(stdin);
        printf("\nTo Get Main Menu Enter Blank Space or Only Enter Or a Or b Or c In The Name Input : \n");
        printf("Enter Full Name : ");
        scanf("%[^\n]", p.name);
        if(stricmp(p.name,"")==0 || stricmp(p.name," ")==0 || stricmp(p.name,"a")==0 || stricmp(p.name,"b")==0 || stricmp(p.name,"c")==0)
            break;
        fflush(stdin);
        printf("Enter Father's Name : ");
        scanf("%[^\n]", p.father_name);
        fflush(stdin);
        printf("Enter Mother's Name : ");
        scanf("%[^\n]", p.mother_name);
        fflush(stdin);
        printf("Enter Address : ");
        scanf("%[^\n]", p.address);
        fflush(stdin);
        printf("Enter Gender : ");
        scanf("%[^\n]", p.gender);
        fflush(stdin);
        printf("Enter Phone Number : ");
        scanf("%ld", &p.mobile);
        fflush(stdin);
        printf("Enter E-mail : ");
        scanf("%[^\n]", p.mail);
        fflush(stdin);
        printf("Enter Nationality : ");
        scanf("%[^\n]", p.nationality);
        fflush(stdin);
        fwrite(&p,sizeof(p),1,fp);
        printf("\n\t%s's Data Saved Successfully.\n\n", p.name);

    }
    fclose(fp);
    system("cls");
    menu();
}

void display()
{
    system("cls");
    int count;

    printf("\t\t   ----------------------\n\t>>>>>>>>>>>|  List Of Contacts  |<<<<<<<<<<<\n\t\t   ----------------------\n");

    for( ; ;)
    {
        fp=fopen("Project.txt","rb+");
        if(fp==NULL)
        {
            printf("\n\t\t    File Opening Error.\n\t\t\tTry Again.\n\t\t\tThank You.\n");
            printf("\n\t\tEnter Any Key : ");
            getch();
            system("cls");
            menu();
        }

        while(fread(&p,sizeof(p),1,fp)==1)
        {

            printf("\n\t\tName\t\t: %s\n\t\tFather's Name\t: %s\n\t\tMother's Name\t: %s\n\t\tAddress\t\t: %s\n\t\tGender\t\t: %s\n\t\tPhone Number\t: %ld\n\t\tEmail\t\t: %s\n\t\tNationality\t: %s\n",p.name,p.father_name,p.mother_name,p.address,p.gender,p.mobile,p.mail,p.nationality);
            count++;

        }
        if(count!=0)
        {
            printf("=========================================================== [%c]-(%d)\n\n",i-32,count);

        }
        fclose(fp);
        printf("\n\tEnter Any Key To Get Main Menu : ");
        getch();
        menu();
    }

}
void search()
{
    long int mobl;
    char email;
    int ch, found = 0;
    system("cls");

    do
    {
        system("cls");
        fp = fopen("Project.txt","rb+");
        if(fp==NULL)
        {
            printf("\n\t\t    File Opening Error.\n\t\t\tTry Again.\n\t\t\tThank You.\n");
            printf("\n\t\tEnter Any Key : ");
            getch();
            system("cls");
            menu();
        }
        system("cls");
        printf("\n\t  Search Phone Number : ");
        scanf("%ld", &mobl);

        while(fread(&p,sizeof(p),1,fp)==1)
        {
            if(p.mobile == mobl)
            {
                printf("\n\t  Detail Information About %s.\n", p.name);
                printf("\n\t\tName\t\t: %s\n\t\tFather's Name\t: %s\n\t\tMother's Name\t: %s\n\t\tAddress\t\t: %s\n\t\tGender\t\t: %s\n\t\tPhone Number\t: %ld\n\t\tEmail\t\t: %s\n\t\tNationality\t: %s\n",p.name,p.father_name,p.mother_name,p.address,p.gender,p.mobile,p.mail,p.nationality);
                found++;
                if(found % 8 == 0)
                {
                    printf("Enter any key To Get Main Menu : ");
                    getch();
                }
            }
        }
        if(found==0)
            printf("\n\t  ==>>> Not Found !");
        else
            printf("\n\t  ==>>> %d Match(s) Found !", found);
        fclose(fp);
        printf("\n\t  ==>>> Try Again ?\n\n\n\t\t(1) Yes (To Review/ Retry)\n\t\t(0) No (Main Menu)\n\t");
        printf("\n\t  ==>>> Enter Your Choice : ");
        scanf("%d",&ch);

    }
    while(ch==1);
    system("cls");
    menu();
}

void edit()
{
    system("cls");

    long int phone;
    printf("Enter Phone number of the person you want to update details : ");
    scanf("%ld",&phone);
    FILE *fp,*temp;
    fp = fopen("Project.txt","rb");
    temp = fopen("temp", "wb+");
    if(fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("\n\t\tEnter Any Key to continue : ");
        return;
    }
    else
    {
        int flag=0;
        struct Person per;

        while(fread(&per,sizeof(per),1,fp)==1)
        {
            if(per.mobile == phone)
            {
                printf("\n\t   %s's Data Found.\n\t\tNow Edit The Contact.\n\t\tThank You.\n", per.name);

                printf("\nTo Get Main Menu Enter Blank Space : \n");
                printf("\tEnter Full Name : ");
                scanf("%[^\n]", per.name);
                fflush(stdin);
                printf("\tEnter Father's Name : ");
                scanf("%[^\n]", per.father_name);
                fflush(stdin);
                printf("\tEnter Mother's Name : ");
                scanf("%[^\n]", per.mother_name);
                fflush(stdin);
                printf("\tEnter Address : ");
                scanf("%[^\n]", per.address);
                fflush(stdin);
                printf("\tEnter Gender : ");
                scanf("%[^\n]", per.gender);
                fflush(stdin);
                printf("\tEnter Phone Number : ");
                scanf("%ld", &per.mobile);
                fflush(stdin);
                printf("\tEnter E-mail : ");
                scanf("%[^\n]", per.mail);
                fflush(stdin);
                printf("\tEnter Nationality : ");
                scanf("%[^\n]", per.nationality);

                fwrite(&per,sizeof(per),1,temp);
                system("cls");
                printf("Data updated successfully\n");
                flag=1;

            }
            else fwrite(&per,sizeof(per),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("cls");
            printf("No record found for %d number\n",phone);
        }
        fclose(fp);
        fclose(temp);
        remove("Project.txt");
        rename("temp","Project.txt");
        fflush(stdin);
        printf("Press any key to continue....\n");
    }
}

void erase()
{
    system("cls");
    long int phone;
    printf("Enter Phone number of the person you want to remove: ");
    scanf("%ld",&phone);
    FILE *temp;
    fp  = fopen("Project.txt", "rb");
    temp = fopen("temp","wb+");
    if(fp==NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        struct Person per;
        int flag=0;

        while (fread(&per, sizeof(per), 1, fp) == 1)
        {
            if(per.mobile == phone)
            {
                system("cls");
                printf("Person removed successfully\n");
                flag = 1;
            }
            else fwrite(&per,sizeof(per),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("cls");
            printf("No record found for %d number\n",phone);
        }
        fclose(fp);
        fclose(temp);
        remove("Project.txt");
        rename("temp","Project.txt");
        fflush(stdin);
        printf("Press any key to continue....\n");
    }
}
