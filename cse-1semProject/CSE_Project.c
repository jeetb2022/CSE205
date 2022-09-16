
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
COORD coord={0,0};
struct book
{
	char code[20];
	char name[20];
	char date[20];
	int cost;
}b;
int seat = 60 ;
void gotoxy();
int searchusername();
void checkpassword();
void login();
void insert_details();//for inserting movie details
void editmovieinfo();
void viewAll(); // for view all data 
void find(); // for finding data
void book_ticket(); //for booking tickets
void old_record(); //for view old recorrds of users,booked tickets
int  collection=0;
void gotoxy(int x,int y)
{
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void main()
{

	//login();
	// editmovieinfo();
    	char username[9],password[10];
		// system("cls");
		gotoxy(30,10);
printf("Enter your username: ");
scanf("%s",username);
int l =searchusername(username);
gotoxy(30,12);
printf("Enter your password: ");
for (int i=0;i<10;i++){
    password[i]=getch();
    if (password[i]==13){
        password[i]='\0';
        break;
    }
    else {
        printf("*");
    }
}
checkpassword(l,password);

	
	 int ch;
 	do{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\n");	
	system("cls");
		gotoxy(30,10);
	printf("\t Moive Ticket booking ");
	printf("\n");
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	
	printf("\nEnter >1< To Insert Movie");
   	printf("\nEnter >2< To View All Movie");
	printf("\nEnter >3< To Find Movie ");
	printf("\nEnter >4< To Book Tickets");
	printf("\nEnter >5< To View All Transactions");
   	printf("\nEnter >0< To Exit ");

   	printf("\nEnter your Choice ::");
   	scanf("%d",&ch); 
	//    system("cls");	

   	switch (ch)
   	{
    		case 1 :
    		insert_details();
   		break;
		case 2:
    		viewAll();
   		break;
    		
		case 3:
    		find();
   		break;

		case 4:
		book_ticket();
		break;
		
		case 5:
		old_record();
		break;

    		case 0:
    		exit(0);
    		break;

    		default:
    		printf("Wrong choice !");
    		break;
   	}
 }while(ch!=0);
 
}
void login(){
FILE *f,*fp1;
f= fopen("login.txt","a");
fp1= fopen("password.txt","a");
char newusername[9],newpassword[10];
scanf("%s",newusername);
scanf("%s",newpassword);
// scanf("%s",newpassword);



fputs(" ",f);
fputs(" ",fp1);

for (int i=0;i<9;i++){
fputc(newusername[i],f);
}
for (int i=0;i<10;i++){
fputc(newpassword[i],fp1);
}


fclose(f);
fclose(fp1);
}
void editmovieinfo(){
	FILE *fp;
	fopen("data.txt","a+");
			printf("\nEnter the movie in which you want to make changes: ");
			char moviecode[20];
			scanf("%s",moviecode);
			rewind(fp);
			while (fread(&b,sizeof(b),1,fp)==1){
				
				if(strcmpi(b.code,moviecode)==1){
					printf(" hi");
					printf("\nEnter new name,date and time and ticketprice: ");
					scanf("%s %s %s %d",b.name,b.code,b.date,&b.cost);
					fseek(fp,-sizeof(b),SEEK_CUR);
					fwrite(&b,sizeof(b),1,fp);
					break;
				}
			}
}

int searchusername (char a[]){
    FILE *f;
if (f==NULL){
    printf("error");
}
char FileInfo[100];
int LengthOfFile=0;
int numberofstrings=0;
f= fopen("login.txt","r");
char file =' ';
  for (int i=0;file!=EOF;i++){
    char file =fgetc(f);
    FileInfo[i]=file;
    LengthOfFile++;
}
for (int i=0;i<100;i++){

    if (FileInfo[i] ==' '){
        
        numberofstrings++;
    }
}
 
char *username =strtok(FileInfo," ");
for (int j=1;j<=numberofstrings;j++){
    
    if (strcmp(a,username) == 0){

        return j;
        break;
    }
    username=strtok(NULL," ");
}
}
void checkpassword(int n,char b[]){
FILE *f,*fp1;

if (fp1==NULL){
    printf("error");
}
char FileInfo[100];
int LengthOfFile=0;
f= fopen("login.txt","r");
fp1= fopen("password.txt","r");
char file =' ';
for (int i=0;file!=EOF;i++){
    char file =fgetc(fp1);
    FileInfo[i]=file;
    LengthOfFile++;
}
 
 char *password =strtok(FileInfo," ");
 for (int i=0;i<n-1;i++){
     password=strtok(NULL," ");
     
 }
 
 if (strcmp(b,password)==0){
    
 }
 else {
     printf("your password is incorrect!");
	  printf("please enter again");
     
     main();
     
     
 }


}
void insert_details()
{
	
	FILE *fp;
	struct book b;
	printf("Enter movie code :- ");	
	scanf("%s",b.code);
	printf("Enter  name :- ");	
	scanf("%s",b.name);
	printf("Enter Release Date:- ");	
	scanf("%s",b.date);
	printf("Enetr Ticket Price:- ");	
	scanf("%d",&b.cost);
	
	fp=fopen("data.txt","a");

	if(fp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(fp,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
		printf("Recorded Successfully");
	}
		printf("\n");
	fclose(fp);
	// system("cls");
}
void find() //find details
{
	struct book b;
	FILE *fp;
	
	char ch[20];
	printf("Enter movie code :");
	scanf("%s",ch);

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,ch) == 0)
			{	
				//printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tmovie name ::%s",b.name);
				printf("\n\t\tmovie date ::%s",b.date);
				printf("\n\t\tprice of ticket ::%d",b.cost);
				
			}
		}
		
	}

	fclose(fp);
	// system("cls");
}
void viewAll()
{
	
	char ch;
	FILE *fp;

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	
	fclose(fp);
getch();
}
//for ticket booking 
void book_ticket()
{
 struct book b;
	FILE *fp;
    FILE *fp2;
	FILE *ufp;

	int total_seat,mobile,total_amount;
	char name[20];
     char a[20];
int l1, e;
	
	char ch; //used in display all movies
	char movie_code[20]; //for searching

	// disply all moives by default for movie code
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		// system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fp);
	
	//display ends
	printf("\n For Book ticket Choice Movie(Enter Movie Code First Latter Of Movie)\n");
	printf("\n Enter movie code :");
	scanf("%s",movie_code);
	//system("clear");
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
   
	else
	{	
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmpi(b.code,movie_code) == 0)
			{	
				
				//printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tMovie name ::%s",b.name);
				printf("\n\t\tdate name ::%s",b.date);
				printf("\n\t\tPrice of ticket::%d",b.cost);
				
				e=b.cost;
				l1=strlen(b.name);
                
				for (int i=0;i<20;i++){
					if (i<l1){
						a[i]=b.name[i];
					}
					else{
						a[i]='\0';
					}
				}
			}
		}
		
	}
	printf("\n* Fill Deatails  *");
	printf("\n your name :");
	scanf("%s",name);
	printf("\n mobile number :");
	scanf("%d",&mobile);
	printf("\n Total number of tickets :");
	scanf("%d",&total_seat);
	fp2=fopen("collection.txt","w");
	char total_collection[5];
	total_amount = e * total_seat;
	collection =collection +total_amount;
    itoa(collection,total_collection,10);
    fprintf(fp2,"%s",total_collection);
    fclose(fp2);
	printf("\n ENJOY MOVIE \n");
	printf("\n\t\tname : %s",name);
	printf("\n\t\tmobile Number : %d",mobile);
	printf("\n\t\tmovie name : %s",a);
	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tcost per ticket : %d",e);
	printf("\n\t\tTotal Amount : %d",total_amount);
	
	
	ufp=fopen("oldTransection.txt","a");
	if(ufp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(ufp,"%s %s %d %d %d %d \n",name,a,total_seat,e,total_amount,mobile);
		printf("\n Record insert Sucessfull to the old record file");
	}
		printf("\n");
	fclose(ufp);
	fclose(fp);
getch();
}
//for view all user transections
void old_record()
{
	char ch;
	FILE *fp;

	//system("clear");
	
	fp = fopen("oldTransection.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		// system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fp);

getch();
}


