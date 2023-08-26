#include<iostream.h> //for cin and cout operations
#include<process.h>  //for exit function
#include<conio.h>    //for clrscr and getch functions
#include<fstream.h>  //for handling functions related to files (input,output,open,close)
#include<ctype.h>    //to allow usage of tolower
#include<dos.h>      //for delay function
#include<stdio.h>    //for gets,remove and rename function
#include<string.h>   //for stcpy and fstrcmpi funtions related to strings
char input;
class rental         //class rental definition starts
{	char name[20];
	int duration;
	long int price;
	int book2;

 public:void new_details() // Function to Add new details/rentals
	{
	cout<<"\n\n\n  Enter your name: ";
	gets(name);
	cout<<"\n  The type of boats available are ";
	      cout<<"\n  1. Long Cruise Boat";
	      cout<<"\n  2. Speedboat";
	      cout<<"\n  3. Fishing Boat";
	      cout<<"\n\n  Enter the boat you want to rent: ";
	      cin>>book2;
	      if(book2>3 || book2<1)
	      {
	      cout<<"\n\n\t\t Wrong input of boat choice";
	      }
	      else
	      {
		cout<<"\n Enter the number of days of rent: ";
		cin>>duration;
		if(book2==1)
		{
			price=10000+100*duration;
			cout<<"\n The price of the rent is: "<<price;
		}
		else if(book2==2)
		{
			price=5000+60*duration;
			cout<<"\n The price of the rent is: "<<price;
		}
		else if(book2==3)
		{
		price=1000+50*duration;
		cout<<"\n The price of the rent is: "<<price;
		}
		cout<<"\n\n\t\t Your details have been uploaded to our servers";
	      }
	}

	void show_details(int r)
	{ char boattype[30];
	  gotoxy(1,r);
	  cout<<name;

       {       if(book2==1)
	  strcpy(boattype,"Long cruise boat");

	  else if(book2==2)
	  strcpy(boattype,"Speed boat");

	  else if(book2==3)
	  strcpy(boattype,"Fishing boat");
       }
	  gotoxy(18,r);

	  cout<<boattype;
	  gotoxy(47,r);
	  cout<<duration;
	  gotoxy(65,r);
	  cout<<price;
	}
       void show_details1() // function to show details
	{ cout<<"\n\t\t\t\t  RENTAL VIEW ";
	  cout<<"\n\n Your name is: "<<name;
	  cout<<"\n\n Your boat of choice is: ";
	  if(book2==1)
	  cout<<"Long Cruise boat";
	  else if(book2==2)
	  cout<<"Speedboat";
	  else
	  cout<<"Fishing boat";
	  cout<<"\n\n Your journey duration is: "<<duration;
	  cout<<"\n\n Your rental price is: "<<price;
	}

	char* getname()
	{return name;}

	int getdur()
	{return duration;}
}b1;

fstream file,fs;
void new_details()
{            file.open("rental.dat",ios::out|ios::app);
	     b1.new_details();
	     file.write((char*)&b1, sizeof(rental));
	     file.close();
}

int search_details(char n[20])
{
	char found;
	file.open("rental.dat", ios::in);
	file.seekg(0,ios::beg);
	while(file.read((char*)&b1,sizeof(rental)))
	{
		if(strcmpi(b1.getname(),n)==0)
		{
			clrscr();
			b1.show_details1();
			found='y';
			break;
			return 1;
		}
	}
	file.close();
	if(found!='y')
	cout<<"\n No records were found.";
	return 0;
	getch();
}

void modify_details()
{            char nam[20];
	     char found='n';
	     clrscr();
	     cout<<"\n Enter the name to be searched: ";
	     gets(nam);
	     file.open("rental.dat",ios::in|ios::out);
	     while(file.read((char*)&b1,sizeof(rental)) )
	     {
		if(strcmpi(b1.getname(),nam)==0)
		{
		b1.show_details1();
		cout<<"\n Please enter your new rental details.";
		b1.new_details();
		int pos=-1*sizeof(rental);
		file.seekp(pos,ios::cur);
		file.write((char*)&b1,sizeof(rental));
		cout<<"\n Rental details have been successfully updated.";
		found='y';
		}
	     }
	     file.close();
	     if(found=='n')
		cout<<"\n Details were not found.";

}

 void display_details()   //Function to show all rentals in a list format
 {
	clrscr();
	cout<<"\n \t\t\t     LIST OF RENTALS \t\t\t\t";
	file.open("rental.dat",ios::in|ios::out);
	int r=7;
		gotoxy(1,4);
		cout<<"Name";
		gotoxy(20,4);
		cout<<"Boat type";
		gotoxy(46,4);
		cout<<"Days";
		gotoxy(64,4);
		cout<<"Price";
	while(file.read((char*)&b1,sizeof(rental)))
	{
		b1.show_details(r);
		r++;
	}

	file.close();
 }

void delete_details()   //Function to delete a rental by name
{
	clrscr();
	cout<<"\n\t\t\t\t     DELETION ";
	char n[20];
	cout<<"\n\n\n Please enter your name: ";
	gets(n);
	file.open("rental.dat",ios::in|ios::out);
	fs.open("temp.dat",ios::out);
	file.seekg(0,ios::beg);
	while(file.read((char*)&b1,sizeof(b1)))
	{
		if(strcmpi(b1.getname(),n)!=0)
		{	fs.write((char*)&b1,sizeof(b1));
		}
	}
	file.close();
	fs.close();
	remove("rental.dat");
	rename("temp.dat","rental.dat");
	cout<<"\n Details have been successfully deleted.";
}

void main()
{
do {
clrscr();
char book,n1[20],opt;
int choice;
long int price;
cout<<"\n\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ";
cout<<"\n\t    (|-|)(-|-)(|-|) WELCOME TO BOAT RENTAL (|-|)(-|-)(|-|)  \t ";
cout<<"\n\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

cout<<"\n\n\n ------------------------------------------------------------------------------- ";
cout<<"\n   Press:- \n\t\t";
cout<<"\n \t\t 1. To enter new details.";
cout<<"\n \t\t 2. To modify an old rental." ;
cout<<"\n \t\t 3. To display your rentals based on name.";
cout<<"\n \t\t 4. To display all the rentals in the list.";
cout<<"\n \t\t 5. To delete any rental. ";
cout<<"\n \t\t 6. Exit";
cout<<"\n ------------------------------------------------------------------------------- ";
cout<<"\n\n Your choice is: ";
cin>>choice;
	switch(choice)
	{case 1:clrscr();
		cout<<"\t\t\t    ENTER NEW DETAILS";
		new_details();
		break;
	 case 2:clrscr();
		cout<<"\t\t\t    MODIFICATION OF DETAILS";
		modify_details();
		break;
	 case 3:clrscr();
		cout<<"\t\t\t    SEARCHING FOR SPECIFIC DETAILS";
		cout<<"\n\n\n Enter the name to be searched: ";
		cin>>n1;
		search_details(n1);
		break;
	 case 4:{
		clrscr();
		cout<<"\t\t\t VIEWING ALL RECORDS(ADMIN RESTRICTED)";
		char password[10],ch,opt2;
		int i;
		  do
		     {
		       i=0;
		       cout<<"\n\n\n\tENTER ADMIN PASSWORD(LOWERCASE ONLY) \t: ";
		       while((ch=getch())!='\r')
			  {
				cout<<'*';
				password[i]=ch;
				i++;
			  }
		       password[i]='\0';
		       if(strcmp(password,"admin123")!=0)
			{
			  cout<<"\n\n\n\t\t WRONG PASSWORD";
			  cout<<"\n\n\t\t\t Do you want to try again? (Y/N): ";
			  cin>>opt2;
			  if(tolower(opt2)=='y')
			  continue;
			  else
			  exit(0);
			}
			  else if(strcmp(password,"admin123")==0)
			  break;
		     }
			  while(opt2=='y'||opt2=='Y');
			  cout<<"\n\n\n\n\t\t\t\tLoading.";
			  delay(400);
			  cout<<".";
			  delay(400);
			  cout<<".";
		     getch();
		}

	 {
		clrscr();
		display_details();
		break;
	 }
	 case 5:clrscr();
		cout<<"\n\n\t\t\t\t    DELETION";
		cout<<"\n\n\n\n Confirm Deletion. Press Y to continue with deletion: ";
		cin>>opt;
		if(tolower(opt)=='y')
		{delete_details();
		break;}
		else break;
	 case 6: break;
	 default:clrscr();
		 cout<<"\n\n Wrong input number";
	}
	if(choice==6)
	{
		delay(400);
		cout<<"\n\n\n\t\t\t\tEXITING";
		delay(400);
		cout<<".";
		delay(350);
		cout<<".";
		delay(300);
		cout<<".";
		delay(300);
		exit(0);
	}
	else
	cout<<"\n\n If you wish to continue with the program input 'Y' :";
	cin>>input;
	if(input=='y'||input=='Y')
	continue;
	else
	delay(400);
	cout<<"\n\n\n\t\t\t\tEXITING";
	delay(400);
	cout<<".";
	delay(350);
	cout<<".";
	delay(300);
	cout<<".";
	delay(300);
	exit(0);
}while(tolower(input)=='y');

	 getch();
}
