// This is Student Management System Program in C++ using class with file handling
// Programmed by : SHAHID

#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>

using namespace std;
int choice;
class student
{
	int roll;
	char name[30];
	char branch[20];
	
	public:
		void getdata()
		{
			cout<<"Enter roll number : ";
			cin>>roll;
			cin.ignore();
			cout<<"Enter name of the student  : ";
			gets(name);
			cin.ignore();
			cout<<"Enter your branch : ";
			gets(branch);
			cin.ignore();
		}
		
		void display()
		{
			cout<<"\n\n";
			cout<<"Name    : "<<name<<endl;
			cout<<"Roll     : "<<roll<<endl;
			cout<<"Branch   : "<<branch<<endl<<endl;
			
		}
	
}s;

void addstudent()
{
	ofstream fout;
	fout.open("Studentrecord.dat",ios::binary|ios::app);
	s.getdata();
	fout.write((char*)&s,sizeof(s));
	
	fout.close();
	cout<<"\n\nStudent added successfully\n\n";
	
	getch();
	
}

void displaystudent()
{
	ifstream fin;
	fin.open("Studentrecord.dat",ios::binary);

	while(fin.read((char*)&s,sizeof(s)))
	{
		s.display();		
	}
	fin.close();
	getch();
	
}
	
	
int main()
{
	system("cls");
	while(true)
	{
	
		system("cls");
		cout<<"\n\n";
		cout<<"\t\t\t ---------------------------------------------\n";
		cout<<"\t\t\t|             STUDENT MANAGEMENT              |\n";
		cout<<"\t\t\t ---------------------------------------------\n\n";
		
		
		cout<<"\n";
		cout<<"\t\t\t\t1. Add student\n";
		cout<<"\t\t\t\t2. Display Student\n";
		cout<<"\t\t\t\t3. Exit\n\n";
		
		cout<<"\t\t\t\tChoice (1/2/3)\n\n";
		cout<<"Enter your choice : ";
		cin>>choice;
		system("cls");
		
		if(choice == 1)
		{
			addstudent();
		}
		
		else if(choice ==2 )
		{
		
			displaystudent();
		}
		else if(choice == 3)
			{
				
				
				cout<<"\n\nPress any key to exit";
				break;
				exit(0);
			}
		else
		{
			cout<<"\n\nInvalid option...... try again";
			getch();
		}
			
	}
	
	
	return 0;
	
}
