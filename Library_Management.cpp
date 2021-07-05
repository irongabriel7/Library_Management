#include<iostream>
#include<string.h>
#include<unistd.h>
#include<stdio.h>


#define ADMINUSER "admin"
#define ADMINPASSWORD "admin123"

const int nbooks=2; //Maximum Book Limit
const int nstudents=2; //Maximum Student Limit

using namespace std;
/*
   LIBRARY MANAGEMENT
    ------------
   |  STUDENTS  |     
    ------------
        |
       \_/
    ------------
   |   BOOKS    |     
    ------------
        |
       \_/
    ------------
   |   ADMIN    |     
    ------------
   
*/

//class student
class student
{
	int studentid[nstudents];
	string sname[nstudents];
	string sclass[nstudents];
		
  public:
  
       student()
	{
	  for(int i=0;i<nstudents;i++)
             {
                studentid[i]=0;
                sname[i]="";
                sclass[i]="";
            }
	}
	void create_student()
	{
	 bool flags2=false;
	 system("clear");
	 for(int i=0;i<nstudents;i++)
	 {
	   if(studentid[i]==0)
	   {
             cout<<"\n NEW STUDENT ENTRY...\n";
             cout<<"\n Enter The Student ID : ";
             cin>>studentid[i];
             cin.ignore();
             cout<<"\n Enter The Name of The Student: ";
             getline(cin,sname[i]);
             cout<<"\n Enter The Student Class: ";
             getline(cin,sclass[i]);
             cout<<"\n\n\n Student Created..\n";
             sleep(1);
             flags2=true;
             break;
             }
           }
           if(flags2!=true)
           {
             cout<<"\n Maxmimum Student Limit Has Reached !!!!\n";
             sleep(1);
           }
        }
        
        void show_student()
        {
         system("clear");
         cout<<"\n\n\t-------------- STUDENTS LIST --------------";
         for(int i=0;i<nstudents;i++)
         {
          if(studentid[i]!=0)
          {
           cout<<"\n\n Student ID : "<<studentid[i];
           cout<<"\n Student Name : "<<sname[i];
           cout<<"\n Student Class : "<<sclass[i]<<"\n";
          }
        }
        cout<<"\nPress Enter to continue....\n";
        cin.ignore();
        cin.get();
        }
        
        void del_student()
        {
          char choices2='n';
          int deslid;
          bool flags1=false;
          system("clear");
          cout<<"\n\t------------------------------------------------";
          cout<<"\n Enter The Student ID to Delete: ";
          cin>>deslid;
          for(int i=0;i<nstudents;i++)
          {
            if(studentid[i]==deslid)
            {
              flags1=true;
              cout<<"\n ID Found :\t"<<studentid[i];
              cout<<"\n Are You Sure you want to Delete!!!.....";
              cout<<"\n Press 'y' or 'n'\n";
              cin>>choices2;
            }
            
            if(choices2=='y')
            {
              studentid[i]=0;
              sname[i]="";
              sclass[i]="";
              break;
            }
            
          }
          
          if(flags1==false)
          {
            cout<<"\n STUDENT Not Found!!!";
            cout<<"\n May be Entered ID is wrong\n";
            sleep(1);
          }
                                                
        }
        
        int check_student(int ck)
        {
          for(int j=0;j<nstudents;j++)
             {
              if(studentid[j]!=0)
              {
               if(studentid[j]==ck)
               {
                cout<<"\n\n Student ID : "<<studentid[j];
                cout<<"\n Student Name : "<<sname[j];
                cout<<"\n Student Class : "<<sclass[j]<<"\n";                
                return 1;
               }
             }
            }
            
            cout<<"\n Student Not Found\n";
            sleep(1.2);
            return 0;
            
	 }
        
        
        void modify_student()
        {
          char choices2='n';
          int cslid;
          bool flags1=false;
          system("clear");
          cout<<"\n\t------------------------------------------------";
          cout<<"\n Enter The Student ID to Modify: ";
          cin>>cslid;
          for(int i=0;i<nstudents;i++)
          {
            if(studentid[i] == cslid)
            {
              flags1=true;
              cout<<"\n ID Found :\t"<<studentid[i];
              cout<<"\n Are You Sure you want to Modify!!!.....";
              cout<<"\n Press 'y' or 'n'\n";
              cin>>choices2;
            }
            
            if(choices2=='y')
            {
              system("clear");
              cout<<"\n\n Enter New Student ID: ";
              cin>>studentid[i];
              cin.ignore();
              cout<<"\nEnter New Student Name: ";
              getline(cin,sname[i]);
              cout<<"\nEnter New Student Class: ";
              getline(cin,sclass[i]);
              break;
            }
            
          }
          
          if(flags1==false)
          {
            cout<<"\n STUDENT Not Found!!!";
            cout<<"\n May be Entered ID is wrong\n";
            sleep(1);
          }
                                                
        }
        
        
 };
//class Book
class book :public student
{
	int bid[nbooks];
	int issuebid[nbooks];
	int issuesid[nbooks];
	int nofissues;
	string bname[nbooks];
	string bcat[nbooks];
	
  public:
       book()
	{
	  nofissues=0;
	  for(int i=0;i<nbooks;i++)
	  {
	    bid[i]=0;
	    issuebid[i]=0;
	    issuesid[i]=0;
	    bname[i]="";
	    bcat[i]="";
	  }
	 }
	void create_book()
	{
	 bool flag2=false;
	 system("clear");
	 for(int i=0;i<nbooks;i++)
	 {
	   if(bid[i]==0)
	   {
             cout<<"\n NEW BOOK ENTRY...\n";
             cout<<"\n Enter The book ID : ";
             cin>>bid[i];
             cin.ignore();
             cout<<"Enter The Name of The Book: ";
             getline(cin,bname[i]);
             cout<<"Enter The Book Category: ";
             getline(cin,bcat[i],'\n');
             cout<<"\n\n\n Book Created..\n";
             flag2=true;
             break;
             }
           }
           if(flag2!=true)
           {
             cout<<"\n Maxmimum Books Limit Has Reached !!!!";
             cout<<"\n Delete Some Books\n";
             sleep(1);
           }
        }
        
        void show_book()
        {
         system("clear");
         cout<<"\n\n\t-------------- Books Available --------------";
         for(int i=0;i<nbooks;i++)
         {
          if(bid[i]!=0)
          {
           cout<<"\n\n Book ID : "<<bid[i];
           cout<<"\n Book Name : "<<bname[i];
           cout<<"\n Book Category : "<<bcat[i]<<"\n";
          }
        }
        cout<<"\nPress Enter to Continue...\n";
        cin.ignore();
        cin.get();
        }
        
                              
        void del_book()
        {
          char choice2='n';
          int delid;
          bool flag1=false;
          system("clear");
          cout<<"\n\t------------------------------------------------";
          cout<<"\n Enter The Book ID to Delete: \n";
          cin>>delid;
          for(int i=0;i<nbooks;i++)
          {
            if(bid[i]== delid)
            {
              flag1=true;
              cout<<"\n ID Found :\t"<<bid[i];
              cout<<"\n Are You Sure you want to Delete!!!.....";
              cout<<"\n Press 'y' or 'n'\n";
              cin>>choice2;
            }
            
            if(choice2=='y')
            {
              bid[i]=0;
              bname[i]="";
              bcat[i]="";
              break;
            }
            
          }
          
          if(flag1==false)
          {
            cout<<"\n BOOK Not Found!!!";
            cout<<"\n May be Entered ID is wrong\n";
            sleep(1);
          }
             
        }
        
        void book_issue()
	{
	 int bk,sk,flagf=0,flagi=0,check;
	 system("clear");
	 cout<<"\n\n\t-------------- Book Issue --------------";
	 for(int i=0;i<nbooks;i++)
	 {
	   if(issuebid[i]==0)
	   { 
	     flagi=1;           
             cout<<"\n\n Enter The Book ID To Issue : ";
             cin>>issuebid[i];
             for(int j=0;j<nbooks;j++)
             {
              if(bid[j]!=0)
              {
               if(bid[j]==issuebid[i])
               {
                flagf=1;
                cout<<"\n\n Book ID : "<<bid[j];
                cout<<"\n Book Name : "<<bname[j];
                cout<<"\n Book Category : "<<bcat[j]<<"\n";                
                break;
               }
               
             }
            }
            if(flagf==0)
            {
              issuebid[i]=0;
              cout<<"\nBook Not Found\n";
              sleep(1);
              break;
            }
            cout<<"\n Enter The Student ID To Issue : ";
            cin>>issuesid[i];
            check=check_student(issuesid[i]);
            if(check==1)
            {
             nofissues++;
             cout<<"\n Book Issued\n";
             sleep(1.5);
             break;              
            }
            else
            {
             issuebid[i]=0;
             issuesid[i]=0; 
             break;
            }                    
          }
         }
         
         if(flagi==0)
         {
          cout<<"\n Maximum Issue Limit Reached\n";
          sleep(1);
         }
                               
        }
        
        void book_deposit()
	{
	 int dpt, dst, flar=0,flaq=0;
	 system("clear");
	 cout<<"\n\n\t-------------- Book Deposit --------------";
         cout<<"\n\n Enter The Book ID To Deposit : ";
         cin>>dpt;
         cout<<"\n\n Enter The Student ID To Deposit : ";
         cin>>dst;
	 for(int i=0;i<nbooks;i++)
	 {
	  if(issuebid[i]!=0)
	  {
	   if(issuebid[i]==dpt)
	   {
	     dpt=i;
	     flar=1;	     
	     break;                 
            }
           }
          }
           
         for(int u=0;u<nbooks;u++)
	  {
	    if(issuesid[u]!=0)
	     { 
	       if(issuesid[u]==dst)
	       {
	         dst=u;
	         flaq=1;
	         break;
	       }
	      }
	    
	   } 
	   if(flar == 1 && flaq == 1)
	   {
	     cout<<"\n Book and Student Found!!!";
	     nofissues--;
             cout<<"\n\n Book Deposited\n";
             issuebid[dpt]=0;
             issuesid[dst]=0;            
             sleep(1);
             sleep(0.5);
           }
          else
           {
            cout<<"\n Not Found!!!\n";
            sleep(1);           
           }            
         }
      
         
        void issued_books()
        {
         system("clear");
         cout<<"\n\n\t-------------- Issued List --------------";
         cout<<"\n\n Number of Issues: "<<nofissues;
         for(int i=0;i<nbooks;i++)
         {
           if(issuebid[i]!=0)
           {
             cout<<"\n\n Book ID: "<<issuebid[i];
             cout<<"\t\t Student ID: "<<issuesid[i];
           }
         }
         cout<<"\nPress Enter to Continue...\n";
         cin.ignore();
         cin.get();
        }
};
  


class admin :public book
{
	char adminUser[10];
	char adminPassword[10];
	
  public:
	void adminlogin()
        {
         char adchoice;
         system("clear");
         cout<<"\n\n\t-------------- Admin Login --------------";
         cout<<"\n\n\tEnter username: ";
         cin>>adminUser;
         cout<<"\n\n\tEnter password: ";
         cin>>adminPassword;
         if((strcmp(adminUser, ADMINUSER) == 0) && (strcmp(adminPassword, ADMINPASSWORD) == 0))
         {
           cout<<"\n\n\tSuccessfully logged in\n";
           sleep(1);
          do{
              system("clear");
              cout<<"\n\n\t-------------- Admin Menu --------------";
              cout<<"\n\n\t 1 - Add Books";
              cout<<"\n\n\t 2 - Show Books";
              cout<<"\n\n\t 3 - Delete Books";
              cout<<"\n\n\t 4 - Add Students";
              cout<<"\n\n\t 5 - Show Students";
              cout<<"\n\n\t 6 - Modify Students";
              cout<<"\n\n\t 7 - Delete Student";
              cout<<"\n\n\t 8 - Exit Admin Menu";
              cout<<"\n\n\t Enter Your Choice [1-8]:";
              cin>>adchoice;
              switch(adchoice)
              {
               case '1':create_book();
                        break;
               case '2':show_book();
                        break;
               case '3':del_book();
                        break;
               case '4':create_student();
                        break;
               case '5':show_student();
                        break;
               case '6':modify_student();
                        break;
               case '7':del_student();
                        break;
               default: adchoice=0;
               }
          }while(adchoice!=0);
          }
         else
         {
            cout<<"\n\n\tWrong Credentials\n";
            sleep(1);
         }
                     
         
                    
        }
};

int main()
{
    char choice;
    admin obj1;
    do
    {
        system("clear");
        cout<<"\n\n\t-------------- MAIN MENU --------------";
        cout<<"\n\n\t 1 - SHOW BOOKS";
        cout<<"\n\n\t 2 - BOOK ISSUE";
        cout<<"\n\n\t 3 - BOOK DEPOSIT";
        cout<<"\n\n\t 4 - ISSUED LIST";
        cout<<"\n\n\t 5 - ADMIN MENU";
        cout<<"\n\n\t 6 - SHOW STUDENTS";
        cout<<"\n\n\t 7 - EXIT";
        cout<<"\n\n\tPlease Select Your Option (1-7) ";
        cin>>choice;
        switch(choice)
        {
        case '1':obj1.show_book();
                 break; 
        case '2':obj1.book_issue();
                 break;     
        case '3':obj1.book_deposit();
                 break;
        case '4':obj1.issued_books();
                 break;
        case '5':obj1.adminlogin();
                 break;
        case '6':obj1.show_student();
                 break;
        case '7':exit(0);
        default :cout<<"\a";
        }
     }while(choice!='7'); 
     
     return 0;
 }
 
