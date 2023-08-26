#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<ctype.h>
void main()
{	clrscr();
	      char password[10],ch,opt2;
			int i;
	      do
		{       i=0;
			cout<<"\n\n \t\t\t\t enter password";
			while((ch=getch())!='\r')
			{
				cout<<'*';
				password[i]=ch;
				i++;
			}
			password[i]='\0';
			if(strcmp(password,"password")!=0)
				{cout<<"\n\t\t\t wrong password, do you want to try again? enter y for yes";
				 cin>>opt2;
				 if(tolower(opt2)=='y')
				 continue;
				 else exit(0);
				}
			else if(strcmp(password,"password")==0)
			break;
		}while(opt2=='y'||opt2=='Y');
 cout<<"enters into main menu";
 getch();
}