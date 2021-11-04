// Basic Student Management Record in c++ without using file handling

#include<iostream>
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<conio.h>


using namespace std;
class students
{
	public:
	    int roll;
	    char name[100];
	    char account[100];
	    char gender[10];
	    char clas[20];
	    char sec;
    
    

        // Getting the data
        void getdata()
        {
            system("cls");
            cout<<"\n\n";
            cout<<"\t\t\t\t\t -------------------------------------------------------\n";
            cout<<"\t\t\t\t\t|              ADD STUDENT DETAILS                      |\n";
            cout<<"\t\t\t\t\t -------------------------------------------------------\n\n";
            cout<<"\t\t\tEnter the roll number of the student : ";
            cin>>roll;
            cin.ignore();
            cout<<"\t\t\tEnter Section : ";
            cin>>sec;
            cin.ignore();
            cout<<"\t\t\tEnter the name of the student : ";
            gets(name);
            cout<<"\t\t\tEnter the class : ";
            gets(clas);
            cout<<"\t\t\tEnter the gender : ";
            gets(gender);
            cout<<"\t\t\tEnter the email account : ";
            gets(account);
            cin.ignore();
        }
        
        // Display the information
        void putdata()
        {
            cout<<endl;
            cout<<"\n";
            cout<<"\t\t\t\tName          : "<<name<<endl;
            cout<<"\t\t\t\tRoll number   : "<<roll<<endl;
            cout<<"\t\t\t\tClass         : "<<clas<<endl;
            cout<<"\t\t\t\tSection       : "<<sec<<endl;
            cout<<"\t\t\t\tGender        : "<<gender<<endl;
            cout<<"\t\t\t\tEmail Account : "<<account<<endl<<endl;
        }

        // Modify the student data
        void modify(char updatedname[],char updatedclass[], char updatedsection, char updatedemail[])
        {
            
            strcpy (name , updatedname);
            strcpy (clas , updatedclass);
            strcpy (account , updatedemail);
            sec = updatedsection;
            
            
            
        }

        

        int return_roll()
        {
            return roll;
        }
};

int main()
{
    system("cls");
    students student[100];
    int i=0;
    while(true)
    {
    system("cls");
    cout<<"\t\t\t\t ----------------------------------------------------\n";
    cout<<"\t\t\t\t|               STUDENT MANAGEMENT SYSTEM            |\n";
    cout<<"\t\t\t\t ----------------------------------------------------\n\n";

    cout<<"\t\t\t1. Add Student account \n";
    cout<<"\t\t\t2. Display all student information\n";
    cout<<"\t\t\t3. Search student by roll number \n";
    cout<<"\t\t\t4. Modify student information \n";
    cout<<"\t\t\t5. Delete Student record\n";
    cout<<"\t\t\t6. Exit\n\n";
    cout<<"\t\t\t\t(option  1/2/3/4/5/6 )\n\n";

    int choice;
    char ch;
    cout<<"\t\tEnter your choice : ";
    cin>>choice;
    system("cls");

        // Adding the student 
        if(choice ==1)
        {
		
            do
            {
                student[i].getdata();
                i++;
                cout<<"\n\n\n\t\tStudent added successfully!...\n";
                getch();
                system("cls");
                cout<<"\n\n\t\tWanna Add another student ? (y/n) : ";
                cin>>ch;
            }while(ch == 'y' || ch == 'Y');
            
	    }
	    
	    
        // Displaying data of the all students
        else if(choice == 2)
        {
	
            cout<<"\n\n";
            cout<<"\t\t\t --------------------------------------------------\n";
            cout<<"\t\t\t|             ALL STUDENT INFORMATION              |\n";
            cout<<"\t\t\t --------------------------------------------------\n\n";
            for(int k=0;k<i;k++)
                student[k].putdata();
            getch();
           
		}
        //Searching of student by roll number
        else if(choice == 3)
        {
		
            int flag;
			flag = 0;
            int raw_roll;
            cout<<"\n\t\t\t\t ------------------- SEARCHING STUDENT -----------------\n\n";
            cout<<"\t\t\tEnter the roll number of the student to search : ";
            cin>>raw_roll;
            for(int l=0; l<=i; l++)
            {
                if(raw_roll == student[l].return_roll())
                {
                    system("cls");
                    cout<<"\t\t\t------------------ STUDENT DETAILS -----------------\n";
                    student[l].putdata();
                    flag++;
                    getch();
                    break;
                }
            }
            if(flag == 0)
                cout<<"\n\nStudent not found! \n\n";
            
            getch();
		}
        // Updating the information
        else if(choice == 4)
        {
		
            int found = 0;
            int raw2;
            char newsec;
            char newname[100],newe[100],newcl[10];
            
            cout<<"\n\n\t\t\t\t  ----------------- SEARCHING THE STUDENT ---------------\n\n";
            cout<<"\t\t\tEnter the Roll number of student to update the information : ";
            cin>>raw2;
            for(int j = 0;j<i;j++)
            {
                if(raw2 == student[j].return_roll())
                {
                    system("cls");
                    found++;
                    cout<<"\n\n";
                    cout<<"\t\t\t ---------------------------------------------------------------\n";
                    cout<<"\t\t\t|             MODIFY STUDENT ROLL NO. "<<raw2<<" DETAILS         |\n";
                    cout<<"\t\t\t ---------------------------------------------------------------\n\n";
                    cout<<"\t\t\t\tDetail of the student\n\n";
                    student[j].putdata();
                    cout<<endl<<endl;
                    cout<<"\t\t\t\tEnter the new section : ";
                    cin>>newsec;
                    cin.ignore();
                    cout<<"\t\t\t\tEnter new name of the student : ";
                    cin>>newname;
                    cin.ignore();
                    cout<<"\t\t\t\tEnter the new class : ";
                    gets(newcl);
                    cin.ignore();
                    cout<<"\t\t\t\tEnter new email account : ";
                    gets(newe);
                    cin.ignore();
                    
                    student[j].modify(newname,newcl,newsec,newe);
                    cout<<"\n\n";
                    cout<<"Updated sucessfully!\n\n";
                    getch();
                    break;
                    
                }
            }
            if(found == 0)
                cout<<"\n\n\t\t\tStudent not found!!! \n";

            
        getch(); 
        }
		
		else if(choice == 5)
		{
			int r,f=0;
			cout<<"Enter the student roll number to find and delete the record : ";
			cin>>r;
			
			for(int j=0;j<i;j++)
			{
				if(student[j].return_roll() == r)
				{
					system("cls");
					int pos;
					cout<<"\n\n";
					cout<<"\t\t\t\t ------------------------------------------\n";
					cout<<"\t\t\t\t|           DELETE STUDENT RECORD          |\n";
					cout<<"\t\t\t\t ------------------------------------------\n\n";
					student[j].putdata();
					cout<<"\n\n";
					cout<<"\t\t\tThis student's record is going to be removed\n\n";
					cout<<"\n\n\t\t\t\tPress any key to continue...\n\n";
					getch();
					pos = j;
					f++;
					for(int l = pos; l<i;l++)
					{
						student[l].roll = student[l+1].roll;
						student[l].sec = student[l+1].sec;
						strcpy(student[l].name,student[l+1].name);
						strcpy(student[l].account,student[l+1].account);
						strcpy(student[l].clas,student[l+1].clas);
					
						
					}
					i = i-1;
					cout<<"\n\n\t\t\tStudent record deleted successfully...";
					getch();
					break;
				}
			}
			if(f == 0)
			{
				cout<<"\n\n\t\t\tSorry Student is not found!\n\n";
				break;
			}
		}
        else if(choice == 6)
        {
	
            cout<<"Press any key to exit....\n";
            getch();
            break;
            exit(0);
    	}

//        else
//        {
//		
//            cout<<"\n\n\t\t\tInvalid input!\n";
//            getch();
//        }

    }
    
    getch();

    return 0;
}
