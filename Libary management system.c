#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

void welcome();
void login();
void mainmenu();
void add_books();
void delete_books();
void edit_books();
void search_books();
void view_books();



int wrong=1, count;
int i=0, valid=0;
char choice=0 ;

char answer;
int target=0,found=0;

struct books
{
	int books_id;
    char b_name[20];
	char a_name[20];
	char s_name[20];
	char add[15];
	int days;
	int yr;

}m;
void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void gotoxy(short x, short y)
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void main() // declare main function
{
	welcome(); // call welcome screen
	login();// call login screen
}
// welcomr function
void welcome()
{

	gotoxy(25,6);
printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
gotoxy(25,7);
printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
gotoxy(25,8);
printf("        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
gotoxy(25,9);
printf("        =                 WELCOME                   =");
gotoxy(25,10);
printf("        =                   TO                      =");
gotoxy(25,11);
printf("        =                 LIBRARY                   =");
gotoxy(25,12);
printf("        =               MANAGEMENT                  =");
gotoxy(25,13);
printf("        =                 SYSTEM                    =");
gotoxy(25,14);
printf("        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
gotoxy(25,15);
printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
gotoxy(25,16);
printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
gotoxy(28,22);
printf(" Enter any key to continue.....");
getch();
}
// login function
void login()
{
	system("cls");
	int L=0;
	char a[30], b[30];
	system("cls");

  for(i=1;i<=95;i++)
   {

       printf("-");
    sleep(10);
   }
printf("\n");
char    ch[23]="\t\t\t\t\tLogin Screen";
	for(i=1;i<=22;i++)
   {

       printf("%c",ch[i]);
    sleep(10);
   }
   printf("\n");
	for(i=1;i<=95;i++)
   {

       printf("-");
    sleep(10);
   }
   printf("\n");
	do
	{
		printf("\n\t\t\t\tEnter Username and Password");

		printf("\n\t\t\t\tUsername:");
		scanf("%s" ,a);

		printf("\n\t\t\t\tPassword:");
		scanf("%s" ,b);
		if((strcmp(a,"tittanmoy")==0)&& (strcmp(b,"tanmoy125")==0))
		{
			printf("\n\t\t\t\tLogged Into System.");
			printf("\n\t\t\t\tPress any key to go next");
						for(i=1;i<=7;i++)
   {

       printf(".");
    sleep(10);
   }
    printf("\n");
			for(i=1;i<=95;i++)
   {

       printf("-");
    sleep(10);
   }
	 printf("\n");
	 		getch();
			mainmenu();
		}
		else
		{

			printf("\t\t\t\tLogin Failed Enter Again Username & Password Again\n\n");
			L++;
		}
	}
		while(L<=3);
	if(L>3){
		system("cls");
		gotoxy(40,15);
		printf("Sorry,Unknown User.");
		getch();
		system("cls");
	}

}
// mainmenu function
void mainmenu(void)
	{
		int choice;

		system("cls");
		for(i=1;i<=95;i++)
   {

       printf("-");
    sleep(10);
   }

		gotoxy(20,2);
		printf("MAIN MENU\n");
for(i=1;i<=95;i++)
   {

       printf("-");
    sleep(10);
   }
   printf("\n");
		gotoxy(20,5);
		printf("1. Add Books");
		gotoxy(20,7);
		printf("2. View Add  Books");
		gotoxy(20,9);
		printf("3. Search Books");
		gotoxy(20,11);
		printf("4. Edit Book's Record");
		gotoxy(20,13);
		printf("5. Take Book");
		gotoxy(20,15);
		printf("6. View Take Books ");
		gotoxy(20,17);
		printf("7. Delete Book");
		gotoxy(20,19);
		printf("8. Take Book Delete");
		gotoxy(20,21);
		printf("9. Add Library Book Collection");
		gotoxy(20,23);
		printf("10. View Library Book Collection");
		gotoxy(20,25);
		printf("11. Exit");
		gotoxy(20,27);
		printf("Please Enter a choice[1-11]:");
		scanf("%i",&choice);
		switch(choice)
			{
				case 1:
				add_books();
				break;
				case 2:
				view_books();
				break;
				case 3:
			    search_books();
				break;
				case 4:
				edit_books();
				break;
				case 5:
				take_books();
				break;
				case 6:
                    view_take_books();
                    break;
				case 7:
				delete_books();
				case 8:
				take_delete_books();
				break;
                case 9:
                Library_book_collection();
                break;
                case 10:
                laibtary_book_view();
                break;
				case 11:
				exit(0);
				break;

				default:
					printf("Wrong Entry!!");
					exit(0);


			}
}
//Library view book collection function
void laibtary_book_view()
{
	int i,e;
	FILE*sfile;
	system("cls");
	sfile=fopen("LibraryBookRecord.txt","r");
	printf("\n\t\t\t*********************************************************");
	printf("\n\t\t\t**************** VIEW LIBRARY BOOK RECORDS *****************");
	printf("\n\t\t\t*********************************************************");
	if(sfile==NULL)
	{
		printf("\n\n\t\t RECORD EMPTY");
		getch();
	}
	else
	{
		gotoxy(1,6);
		printf("Book Id NO.");
		gotoxy(13,6);
		printf("Book Name");
		gotoxy(30,6);
		printf("Publication");
		gotoxy(45,6);
		printf("Librarian Name");
		gotoxy(63,6);
		printf("Location");
		gotoxy(83,6);
		printf("Quantity of Book\n");
		for(i=0;i<99;i++)
		{
			printf("-");
		}
		e=8;
		while(fscanf(sfile,"%i %s %s %s %s %i\n\n",&m.books_id,m.b_name,m.a_name,m.s_name,m.add,&m.days)!=EOF)
		{
			gotoxy(1,e);
			printf("%i",m.books_id);
			gotoxy(13,e);
			printf("%s",m.b_name);
			gotoxy(30,e);
			printf("%s",m.a_name);
			gotoxy(45,e);
			printf("%s",m.s_name);
			gotoxy(63,e);
			printf("%s",m.add);
			gotoxy(83,e);
			printf("%i",m.days);
			e++;
		}
		printf("\n");
		for(i=0;i<99;i++)
		printf("-");
	}
	printf("\n\n\t Press any key for main menu........");
	fclose(sfile);
	getch();
	mainmenu();


}
//Library add book collection function
void Library_book_collection()
{
	/*int days;
	system("cls");
	FILE *sfile;
	sfile = fopen("LibraryBookRecord.txt","a");
	printf("\n\t\t****************************************************");
	printf("\n\t*********************ADD NEW BOOKS*********************");
	printf("\n\t\t******************************************************");
	printf("\n\n\t\t  ENTER YOUR DETAILS BELOW:");
	printf("\n\t\t------------------------------");
	printf("\n\t\tBook ID NO.\t\t:");
	fflush(stdin);
	scanf("%i",&m.books_id);
	do
	{
		printf("\n\t\tBook Name\t\t:");
		fflush(stdin);
		gets(m.b_name);
		m.b_name[0]=toupper(m.b_name[0]);
		for (i=0;i<strlen(m.b_name); ++i)
		{
			if(isalpha(m.b_name[i]))
			{
				valid = 1;
			}
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
	do
	{
		printf("\n\t\tPublication\t\t:");
		fflush(stdin);
		gets(m.a_name);
		m.a_name[0]=toupper(m.a_name[0]);
		for (i=0;i<strlen(m.a_name); ++i)
		{
			if(isalpha(m.a_name[i]))
				valid = 1;
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
	do
	{
		printf("\n\t\tStudent Name\t\t:");
		fflush(stdin);
		gets(m.s_name);
		m.s_name[0]=toupper(m.s_name[0]);
		for (i=0;i<strlen(m.s_name); ++i)
		{
			if(isalpha(m.s_name[i]))
				valid = 1;
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
		do
			{
				printf("\n\t\tStudent Address\t\t:");
				fflush(stdin);
				gets(m.add);
				m.add[0]=toupper(m.add[0]);
				for (i=0;i<strlen(m.add); ++i)
				{
					if(isalpha(m.add[i]))
					valid = 1;
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\nAddress contain invalid character. Please enter again.");
				}
			}while(!valid);
			printf("\n\t\tEnter Duration To Add Book");

			do
			{
				printf("\n\t\tMaximum [1-15] Days\t:");
				scanf("%i",&m.days);
				if(m.days<1 || m.days>15)
				{
					printf("\n\tYou Cannot take more than 15x Days.Re-Enter.");
				}
			} while(m.days<1 || m.days>15);

	fprintf(sfile,"%i %s %s %s %s %i\n\n",m.books_id, m.b_name, m.a_name, m.s_name,m.add,m.days);
	fclose(sfile);
	printf("\n\t SUCCESFULLY RECORDED.\n");
	getch();
	printf("\n\t\t Do you want to add another book?[Y/N]:");
	scanf("%s",&answer);
	while(toupper(answer)!='Y'&& toupper(answer)!='N')
	{
		printf("Invalid!\n\tDo you want to add book?[Y/N]:");
		scanf("%s",&answer);
	}
	if(toupper(answer)=='Y')
	{
		Library_book_collection();
	}
	else
	{
		printf("\n\t\tPress any key to go to mainmenu.....");
		mainmenu();
	}*/
	printf("\n\t\t*******************************   YOu Cannot *********************");
	printf("\n\t*********************           Access this Function *********************");
	printf("\n\t\t**************************** Only Admin Can Access **************************\n");


}

// add books function
void add_books()
{
	int days;
	system("cls");
	FILE *sfile;
	sfile = fopen("BookRecord.txt","a");
	printf("\n\t\t****************************************************");
	printf("\n\t*********************ADD NEW BOOKS*********************");
	printf("\n\t\t******************************************************");
	printf("\n\n\t\t  ENTER YOUR DETAILS BELOW:");
	printf("\n\t\t------------------------------");
	printf("\n\t\tBook ID NO.\t\t:");
	fflush(stdin);
	scanf("%i",&m.books_id);
	do
	{
		printf("\n\t\tBook Name\t\t:");
		fflush(stdin);
		gets(m.b_name);
		m.b_name[0]=toupper(m.b_name[0]);
		for (i=0;i<strlen(m.b_name); ++i)
		{
			if(isalpha(m.b_name[i]))
			{
				valid = 1;
			}
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
	do
	{
		printf("\n\t\tPublication\t\t:");
		fflush(stdin);
		gets(m.a_name);
		m.a_name[0]=toupper(m.a_name[0]);
		for (i=0;i<strlen(m.a_name); ++i)
		{
			if(isalpha(m.a_name[i]))
				valid = 1;
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
	do
	{
		printf("\n\t\tStudent Name\t\t:");
		fflush(stdin);
		gets(m.s_name);
		m.s_name[0]=toupper(m.s_name[0]);
		for (i=0;i<strlen(m.s_name); ++i)
		{
			if(isalpha(m.s_name[i]))
				valid = 1;
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
		do
			{
				printf("\n\t\tStudent Address\t\t:");
				fflush(stdin);
				gets(m.add);
				m.add[0]=toupper(m.add[0]);
				for (i=0;i<strlen(m.add); ++i)
				{
					if(isalpha(m.add[i]))
					valid = 1;
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\nAddress contain invalid character. Please enter again.");
				}
			}while(!valid);
			printf("\n\t\tEnter Duration To Add Book");

			do
			{
				printf("\n\t\tMaximum [1-15] Days\t:");
				scanf("%i",&m.days);
				if(m.days<1 || m.days>15)
				{
					printf("\n\tYou Cannot take more than 15x Days.Re-Enter.");
				}
			} while(m.days<1 || m.days>15);

	fprintf(sfile,"%i %s %s %s %s %i\n\n",m.books_id, m.b_name, m.a_name, m.s_name,m.add,m.days);
	fclose(sfile);
	printf("\n\t SUCCESFULLY RECORDED.\n");
	getch();
	printf("\n\t\t Do you want to add another book?[Y/N]:");
	scanf("%s",&answer);
	while(toupper(answer)!='Y'&& toupper(answer)!='N')
	{
		printf("Invalid!\n\tDo you want to add book?[Y/N]:");
		scanf("%s",&answer);
	}
	if(toupper(answer)=='Y')
	{
		add_books();
	}
	else
	{
		printf("\n\t\tPress any key to go to mainmenu.....");
		mainmenu();
	}

}
//Take books function
void take_books()
{
	int days;
	system("cls");
	FILE *sfile;
	sfile = fopen("TakeBookRecord.txt","a");
	printf("\n\t\t****************************************************");
	printf("\n\t*********************TAKE BOOKS*********************");
	printf("\n\t\t******************************************************");
	printf("\n\n\t\t  ENTER YOUR DETAILS BELOW:");
	printf("\n\t\t------------------------------");
	printf("\n\t\tBook ID NO.\t\t:");
	fflush(stdin);
	scanf("%i",&m.books_id);
	do
	{
		printf("\n\t\tBook Name\t\t:");
		fflush(stdin);
		gets(m.b_name);
		m.b_name[0]=toupper(m.b_name[0]);
		for (i=0;i<strlen(m.b_name); ++i)
		{
			if(isalpha(m.b_name[i]))
			{
				valid = 1;
			}
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
	do
	{
		printf("\n\t\tPublication\t\t:");
		fflush(stdin);
		gets(m.a_name);
		m.a_name[0]=toupper(m.a_name[0]);
		for (i=0;i<strlen(m.a_name); ++i)
		{
			if(isalpha(m.a_name[i]))
				valid = 1;
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
	do
	{
		printf("\n\t\tStudent Name\t\t:");
		fflush(stdin);
		gets(m.s_name);
		m.s_name[0]=toupper(m.s_name[0]);
		for (i=0;i<strlen(m.s_name); ++i)
		{
			if(isalpha(m.s_name[i]))
				valid = 1;
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
		do
			{
				printf("\n\t\tStudent Address\t\t:");
				fflush(stdin);
				gets(m.add);
				m.add[0]=toupper(m.add[0]);
				for (i=0;i<strlen(m.add); ++i)
				{
					if(isalpha(m.add[i]))
					valid = 1;
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\nAddress contain invalid character. Please enter again.");
				}
			}
			while(!valid);
			printf("\n\t\tEnter Duration To Take Book");

			do
			{
				printf("\n\t\tMaximum [1-15] Days\t:");
				scanf("%i",&m.days);
				if(m.days<1 || m.days>15)
				{
					printf("\n\tYou Cannot take more than 15x Days.Re-Enter.");
				}
			}while(m.days<1 || m.days>15);

	fprintf(sfile,"%i %s %s %s %s %i\n\n",m.books_id, m.b_name, m.a_name, m.s_name,m.add,m.days);
	fclose(sfile);
	printf("\n\t SUCCESFULLY RECORDED.\n");
	getch();
	printf("\n\t\t Do you want to take another book?[Y/N]:");
	scanf("%s",&answer);
	while(toupper(answer)!='Y'&& toupper(answer)!='N')
	{
		printf("Invalid!\n\tDo you want to take book?[Y/N]:");
		scanf("%s",&answer);
	}
	if(toupper(answer)=='Y')
	{
		take_books();
	}
	else
	{
		printf("\n\t\tPress any key to go to mainmenu.....");
		mainmenu();
	}

}
//View all take books function
void  view_take_books()
{
	int i,e;
	FILE*sfile;
	system("cls");
	sfile=fopen("TakeBookRecord.txt","r");
	printf("\n\t\t\t*********************************************************");
	printf("\n\t\t\t**************** VIEW ALL TAKE BOOK RECORDS *****************");
	printf("\n\t\t\t*********************************************************");
	if(sfile==NULL)
	{
		printf("\n\n\t\t RECORD EMPTY");
		getch();
	}
	else
	{
		gotoxy(1,6);
		printf("Book Id NO.");
		gotoxy(13,6);
		printf("Book Name");
		gotoxy(30,6);
		printf("Publication");
		gotoxy(45,6);
		printf("Students Name");
		gotoxy(63,6);
		printf("Students Address");
		gotoxy(83,6);
		printf("Due Days\n");
		for(i=0;i<95;i++)
		{
			printf("-");
		}
		e=8;
		while(fscanf(sfile,"%i %s %s %s %s %i\n\n",&m.books_id,m.b_name,m.a_name,m.s_name,m.add,&m.days)!=EOF)
		{
			gotoxy(1,e);
			printf("%i",m.books_id);
			gotoxy(13,e);
			printf("%s",m.b_name);
			gotoxy(30,e);
			printf("%s",m.a_name);
			gotoxy(45,e);
			printf("%s",m.s_name);
			gotoxy(63,e);
			printf("%s",m.add);
			gotoxy(83,e);
			printf("%i",m.days);
			e++;
		}
		printf("\n");
		for(i=0;i<95;i++)
		printf("-");
	}
	printf("\n\n\t Press any key for main menu........");
	fclose(sfile);
	getch();
	mainmenu();


}
//Delete Take books function
void take_delete_books()
{

	int target;
	system("cls");
	printf("\n\t\t*************************************************");
	printf("\n\t***************Take Books Delete Details****************");
	printf("\n\t\t*************************************************");
	FILE *sfile,*mfile;
	sfile=fopen("TakeBookRecord.txt","r");
	printf("\nEnter Book ID NO. for delete:");
	scanf("%i",&target);
	mfile=fopen("TempBook.txt","w+");
	if(sfile==NULL)
	{
		printf("\n\tNo Record in File!");
		printf("\n\t\t\tPress any key to Main Menu..");
		getch();
		mainmenu();
	}
	else
	{
		while(fscanf(sfile,"%i %s %s %s %s %i\n",&m.books_id,m.b_name,m.a_name,m.s_name,m.add,&m.days)!=EOF)
		{
			if(target!=m.books_id)
			{
				fprintf(mfile,"%i %s %s %s %s %i\n",m.books_id,m.b_name,m.a_name,m.s_name,m.add,m.days);
			}
			else
			{
				found=1;
			}
		}
		if(!found)
		{
			printf("\nRecord not found");
		}
		else
		{
			printf("\n\tRecord deleted successfully.....");
		}
		fclose(sfile);
		fclose(mfile);
		remove("TakeBookRecord.txt");
		rename("TempBook.txt","TakeBookRecord.txt");
	}
	getch();
	mainmenu();
}
// search books function
void search_books()
{
	int found=0;
	char id[40];
	FILE *sfile;
	system("cls");
	sfile=fopen("BookRecord.txt","rb");
	//sfile=fopen("TakeBookRecord.txt","rb");
	printf("\n\t\t******************************************************");
	printf("\n\t\t***************** SEARCH BOOKS LIST*******************");
	printf("\n\t\t******************************************************\n\n");

	printf("\nEnter Book Name to search:");
	fflush(stdin);
	scanf("%s",id);
	id[0]=toupper(id[0]);

	printf("                                                                                     \n");
	printf(" Book ID NO. Book Name    Publication    Student Name   Student Address   Due Days");

	printf("\n=====================================================================================\n");
	while(fscanf(sfile,"%i %s %s %s %s %i\n\n",&m.books_id, m.b_name, m.a_name, m.s_name, m.add, &m.days)!=EOF)
	{
		if(strcmp(id,m.b_name)==0)
		{
			found=1;
			gotoxy(1,10);
			printf("%i",m.books_id);
			gotoxy(12,10);
			printf("%s",m.b_name);
			gotoxy(24,10);
			printf(" %s",m.a_name);
			gotoxy(40,10);
			printf(" %s",m.s_name);
			gotoxy(56,10);
			printf("%s",m.add);
			gotoxy(74,10);
			printf("%i",m.days);
			break;
		}
	}
		if(!found) printf("\n\n\tNo Record");
		fclose(sfile);


		printf("\t\t\n\n\nPress any key to go to mainmenu.....");
		getch();
		mainmenu();

}


// view books function
void view_books()
{
	int i,e;
	FILE*sfile;
	system("cls");
	sfile=fopen("BookRecord.txt","r");
	printf("\n\t\t\t*********************************************************");
	printf("\n\t\t\t**************** VIEW ALL ADD BOOK RECORDS *****************");
	printf("\n\t\t\t*********************************************************");
	if(sfile==NULL)
	{
		printf("\n\n\t\t RECORD EMPTY");
		getch();
	}
	else
	{
		gotoxy(1,6);
		printf("Book Id NO.");
		gotoxy(13,6);
		printf("Book Name");
		gotoxy(30,6);
		printf("Publication");
		gotoxy(45,6);
		printf("Students Name");
		gotoxy(63,6);
		printf("Students Address");
		gotoxy(83,6);
		printf("Due Days\n");
		for(i=0;i<95;i++)
		{
			printf("-");
		}
		e=8;
		while(fscanf(sfile,"%i %s %s %s %s %i\n\n",&m.books_id,m.b_name,m.a_name,m.s_name,m.add,&m.days)!=EOF)
		{
			gotoxy(1,e);
			printf("%i",m.books_id);
			gotoxy(13,e);
			printf("%s",m.b_name);
			gotoxy(30,e);
			printf("%s",m.a_name);
			gotoxy(45,e);
			printf("%s",m.s_name);
			gotoxy(63,e);
			printf("%s",m.add);
			gotoxy(83,e);
			printf("%i",m.days);
			e++;
		}
		printf("\n");
		for(i=0;i<95;i++)
		printf("-");
	}
	printf("\n\n\t Press any key for main menu........");
	fclose(sfile);
	getch();
	mainmenu();


}
// delete function
void delete_books()
{

	int target;
	system("cls");
	printf("\n\t\t*************************************************");
	printf("\n\t***************Delete Books Details****************");
	printf("\n\t\t*************************************************");
	FILE *sfile,*mfile;
	sfile=fopen("BookRecord.txt","r");
	printf("\nEnter Book ID NO. for delete:");
	scanf("%i",&target);
	mfile=fopen("TempBook.txt","w+");
	if(sfile==NULL)
	{
		printf("\n\tNo Record in File!");
		printf("\n\t\t\tPress any key to Main Menu..");
		getch();
		mainmenu();
	}
	else
	{
		while(fscanf(sfile,"%i %s %s %s %s %i\n",&m.books_id,m.b_name,m.a_name,m.s_name,m.add,&m.days)!=EOF)
		{
			if(target!=m.books_id)
			{
				fprintf(mfile,"%i %s %s %s %s %i\n",m.books_id,m.b_name,m.a_name,m.s_name,m.add,m.days);
			}
			else
			{
				found=1;
			}
		}
		if(!found)
		{
			printf("\nRecord not found");
		}
		else
		{
			printf("\n\tRecord deleted successfully.....");
		}
		fclose(sfile);
		fclose(mfile);
		remove("BookRecord.txt");
		rename("TempBook.txt","BookRecord.txt");
	}
	getch();
	mainmenu();
}

// edit function
void edit_books()
{
	int i, found,target;
  char ch;
  int books_id;
  FILE *sfile, *modify;
  system("cls");
  printf("\n\t\t********************************************");
  printf("\n\t\t*******Edit Books Details*******************");
  printf("\n\t\t********************************************");

   sfile=fopen("BookRecord.txt","rb+");
   if(sfile==NULL)
   {

		printf("\n\t Can not open file!! ");
		getch();
		mainmenu();
   }
   gotoxy(15,6);
   printf("\tEnter Book ID NO. for edit:");
   scanf("%i",&target);
   gotoxy(15,8);
   modify=fopen("TempBook.txt","a+");
   if (modify==NULL)
   {
   	printf("\n File cannot be open...!");
   	getch();
   	printf("\n\nPress any key to go to main menu");
   	for(i=1;i<=11;i++)
   {

       printf(".");
    sleep(15);
   }
   	mainmenu();
   }
   else
   {
   	while(fscanf(sfile,"%i %s %s %s %s %i\n",&m.books_id,m.b_name,m.a_name,m.s_name,m.add,&m.days)!=EOF)
   	{
   		if(m.books_id==target)
   		{
   			found=1;
   			printf("\n\tBook ID NO.\t:%i\n\tBook Name\t:%s\n\tPublication\t:%s\n\tStudent Name\t:%s\n\tStudent Address\t:%s\n\tDue Days\t:%i\n",m.books_id,
			   															m.b_name,m.a_name,m.s_name,m.add,m.days);
			printf("\n\tEdit With New Records!");
   			do
   			{
   				printf("\n\t\tEnter New Book Name\t\t:");
				fflush(stdin);
				gets(m.b_name);
				m.b_name[0]=toupper(m.b_name[0]);
				for (i=0;i<strlen(m.b_name); ++i)
				{
					if(isalpha(m.b_name[i]))
					{
						valid = 1;
					}
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\nBook name contain invalid character. Please enter again.");
				}
			}while(!valid);
			do
			{
				printf("\n\t\tEnter New Publication\t\t:");
				fflush(stdin);
				gets(m.a_name);
				m.a_name[0]=toupper(m.a_name[0]);
				for (i=0;i<strlen(m.a_name); ++i)
				{
					if(isalpha(m.a_name[i]))
					valid = 1;
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\nWriter name contain invalid character. Please enter again.");
				}
			}while(!valid);
			do
			{
				printf("\n\t\tEnter New Student Name\t\t:");
				fflush(stdin);
				gets(m.s_name);
				m.s_name[0]=toupper(m.s_name[0]);
				for (i=0;i<strlen(m.s_name); ++i)
				{
					if(isalpha(m.s_name[i]))
					valid = 1;
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\nStudent name contain invalid character. Please enter again.");
				}
			}while(!valid);
			do
			{
				printf("\n\t\tEnter New Student Address\t:");
				fflush(stdin);
				gets(m.add);
				m.add[0]=toupper(m.add[0]);
				for (i=0;i<strlen(m.add); ++i)
				{
					if(isalpha(m.add[i]))
					valid = 1;
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\nAddress contain invalid character. Please enter again.");
				}
			}while(!valid);
			printf("\n\t\tEnter Duration To Take Book");

			do
			{
				printf("\n\t\tMaximum [1-15] Days\t\t:");
				scanf("%i",&m.days);
				if(m.days<1 || m.days>15)
				{
					printf("\n\tYou Cannot take more than 10 Days.Re-Enter.");
				}
			}while(m.days<1 || m.days>15);

			printf("\nPress 'U' to update and other key to cancel....!");
			ch=getche();
			if(ch=='u'|| ch=='U')
			{
				fprintf(modify,"%i %s %s %s %s %i",m.books_id,m.b_name,m.a_name,m.s_name,m.add,m.days);
				fflush(stdin);
				printf("\n\nBooks has been updated......");
			}
			else
			{
				fprintf(modify,"%i %s %s %s %s %i",m.books_id,m.b_name,m.a_name,m.s_name,m.add,m.days);
				fflush(stdin);
			}
	   }
	   if(!found)printf("\n\tNo record found!");
	   fclose(modify);
	   fclose(sfile);
	   remove("BookRecord.txt");
	   rename("TempBook.txt","BookRecord.txt");

     	printf("\n\t\tPress any key to go to mainmenu.....");
     	getch();
	    mainmenu();
   }
}
}
// end of program
