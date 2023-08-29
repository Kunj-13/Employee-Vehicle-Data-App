#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
// password for the admin is "admin"
// password for rest of the employees is "cmpsc121"

//string holds all of the information for each employee such as first, last name, vehicle info and email.
string fname, lname, email, ve_make, ve_model, ve_color, ve_plnum;
string phone;
// void add function allows adding employee data by asking series of question that user want to store
void add()
{
  fstream myfile;

  cout << "\n1. Enter first name : ";
  cin  >> fname;
  cout << "\n2. Enter last name : ";
  cin  >> lname;
  cout << "\n3. Enter phone number : ";
  cin  >> phone;
  cout << "\n4. Enter email : ";
  cin  >> email;
  cout << "\n5. Enter vehicle make : ";
  cin  >> ve_make;
  cout << "\n6. Enter vehicle model : ";
  cin  >> ve_model;
  cout << "\n7. Enter vehicle color : ";
  cin  >> ve_color;
  cout << "\n8. Enter vehicle plate number : ";
  cin  >> ve_plnum;

  myfile.open("database.txt", fstream::app);

  myfile << "\n" << " " << fname << " " << lname << " " << phone << " " << email << " " << ve_make << " " << ve_model << " " << ve_color << " " << ve_plnum;

  myfile.close();

}
// the void delete function allows only the admin to delete any employee information in the database
void del()
{
  char checkID[100];
  fstream myfile, myfile1;

  int found = 0;

  cout << "--------------------------------------------" << endl;
  cout << "\t\t\tDelete Employee data." << endl;
  cout << "--------------------------------------------" << endl;

  myfile.open("database.txt");

  if (!myfile)
  {
      cout << "\n\t\t\tNo Data found ....";
      myfile.close();
  }

  else
  {
    cout << "\nEnter employee email id to remove data: ";
    cin >> checkID;

    myfile1.open("database_duplicate.txt", fstream::app);
    myfile >> fname >> lname >> phone >> email >> ve_make >> ve_model >> ve_color >> ve_plnum;

    while (!myfile.eof())
        {
            if (checkID != email)
            {
                myfile1 << " " << fname << " " << lname << " " << phone << " " << email << " " << ve_make << " " << ve_model << " " << ve_color << " " << ve_plnum << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            myfile >> fname >> lname >> phone >> email >> ve_make >> ve_model >> ve_color >> ve_plnum;
        }

        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        myfile1.close();
        myfile.close();
        remove("database.txt");
        rename("database_duplicate.txt", "database.txt");
  }
}
// search function allows any user to find a specific employee information by searching the employee's email id
void search()
{
  fstream myfile;

  char checkID[100];

  cout << "--------------------------------------------" <<endl;
  cout << "\t\t\t Employee search data." <<endl;
  cout << "--------------------------------------------" <<endl;

  myfile.open("database.txt");

  cout << "Enter employee email id : ";
  cin  >> checkID;

  if (!myfile)
  {
      cout << "\n\t\t\tNo Data found ...." << endl;
      myfile.close();
  }

  else
  {
    myfile >> fname >> lname >> phone >> email >> ve_make >> ve_model >> ve_color >> ve_plnum;

    while (!myfile.eof())
        {
            if (checkID == email)
            {
              cout << "\n--------------------------------------------" << endl;
              cout << "Employee first name           : " << fname << endl;
              cout << "Employee last  name           : " << lname << endl;
              cout << "Employee phone number         : " << phone << endl;
              cout << "Employee email                : " << email << endl;
              cout << "Employee vehicle make         : " << ve_make << endl;
              cout << "Employee vehicle model        : " << ve_model << endl;
              cout << "Employee vehicle color        : " << ve_color << endl;
              cout << "Employee vehicle plate number : " << ve_plnum << endl;
              cout << "\n--------------------------------------------" << endl;

            }
            myfile >> fname >> lname >> phone >> email >> ve_make >> ve_model >> ve_color >> ve_plnum;  
        }
  }

  myfile.close();
}
// the update functions allows only the admin to modify any specific employee's information.
void update()
{
  char checkID[100];
  int found = 0;
  fstream myfile, myfile1;

  cout << "--------------------------------------------" <<endl;
  cout << "\t\t\t Employee update data." <<endl;
  cout << "--------------------------------------------" <<endl;

  myfile.open("database.txt");
  if (!myfile)
  {
    cout << "\n\t\t\tNo Data is Present..";
    myfile.close();
  }

  else
  {
    cout << "\nEnter employee email id : ";
    cin >> checkID;

    myfile1.open("database_duplicate.txt", fstream::app);
    myfile << fname << lname << phone << email << ve_make << ve_model << ve_color << ve_plnum;

    while (!myfile.eof())
        {

            if (checkID == email)
            {
                  int choice;

                  cout << "What do you want to modify ? " << endl; 
                  cout << "press 1. first name" << endl;
                  cout << "press 2. last  name" << endl;
                  cout << "press 3. phone" << endl;
                  cout << "press 4. email" << endl;
                  cout << "press 5. vehicle make" << endl;
                  cout << "press 6. vehicle model" << endl;
                  cout << "press 7. vehicle color" << endl;
                  cout << "press 8. vehicle plate number" << endl;
                  cout << "\n\n =========================================== " <<endl;

                  cout << "\nplease enter your response : ";
                  cin >> choice;

                  if (choice == 1)
                  {
                    cout << "\n1. Enter first name : ";
                    cin  >> fname;
                  }

                  else if (choice == 2)
                  {
                    cout << "\n2. Enter last name : ";
                    cin  >> lname;
                  }

                  else if (choice == 3)
                  {
                    cout << "\n3. Enter phone number : ";
                    cin  >> phone;
                  }

                  else if (choice == 4)
                  {
                    cout << "\n4. Enter email : ";
                    cin  >> email;
                  }

                  else if (choice == 5)
                  {
                    cout << "\n5. Enter vehicle make : ";
                    cin  >> ve_make;
                  }

                  else if (choice == 6)
                  {
                    cout << "\n6. Enter vehicle model : ";
                    cin  >> ve_model;
                  }

                  else if (choice == 7)
                  {
                    cout << "\n7. Enter vehicle color : ";
                    cin  >> ve_color;
                  }

                  else if (choice == 8)
                  {
                    cout << "\n8. Enter vehicle plate number : ";
                    cin  >> ve_plnum;
                  }






                  cout << "Successfully updated data ...." << endl;

                  myfile1 << " " << fname << " " << lname << " " << phone << " " << email << " " << ve_make << " " << ve_model << " " << ve_color << " " << ve_plnum << "\n";

                  found++;
            }

            else
            {
              myfile1 << " " << fname << " " << lname << " " << phone << " " << email << " " << ve_make << " " << ve_model << " " << ve_color << " " << ve_plnum << "\n";
            }

            myfile >> fname >> lname >> phone >> email >> ve_make >> ve_model >> ve_color >> ve_plnum;
        }
          if (found == 0)
          {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
          }

        myfile1.close();
        myfile.close();
        remove("database.txt");
        rename("database_duplicate.txt", "database.txt");
  }
}
//the view function allows any user to find information for all employees in the database.
void view()
{
  int total = 1;
  fstream myfile;

  cout << "--------------------------------------------" <<endl;
  cout << "\t\t\t Employee record." <<endl;
  cout << "--------------------------------------------" <<endl;

  myfile.open("database.txt");
  if (!myfile)
  {
    cout << "\n\t\t\tNo Data available... ";
    myfile.close();
  }

  else
  {
    myfile >> fname >> lname >> phone >> email >> ve_make >> ve_model >> ve_color >> ve_plnum;

    
    while (!myfile.eof())
        {
            cout << "\n\n";
            cout << total++ << ". "<< "FIRST NAME           : " << fname 
                              << "\n   LAST NAME            : " << lname 
                              << "\n   PHONE                : " << phone 
                              << "\n   email                : " << email 
                              << "\n   VEHICLE MAKE         : " << ve_make 
                              << "\n   VEHICLE MODEL        : " << ve_model 
                              << "\n   VEHICLE COLOR        : " << ve_color 
                              << "\n   VEHICLE PLATE NUMBER : " << ve_plnum << "\n\n================================================================";
            myfile >> fname >> lname >> phone >> email >> ve_make >> ve_model >> ve_color >> ve_plnum;
        }
  }

  myfile.close();
}

void exit()
{
  exit (0);
}

////////////////////////////////////////////
void admin()
{
  int choice;
  cout << "-----------------------------------" <<endl;
  cout << "Press 1. to add data"    << endl;
  cout << "Press 2. to update data" << endl;
  cout << "Press 3. to delete data" << endl;
  cout << "Press 4. to view data"   << endl;
  cout << "press 5. to search data" << endl;
  cout << "Press 6. to exit."       << endl;
  cout << "-----------------------------------" <<endl;
  cout << "\n";
  cout << "Please enter your choice : ";
  cin  >> choice;

  if (choice == 1)
  {
    add();
  }

  else if (choice == 2)
  {
    update();
  }

  else if (choice == 3)
  {
    del();
  }

  else if (choice == 4)
  {
    view();
  }

  else if (choice == 5)
  {
    search();
  }

  else if (choice == 6)
  {
    exit();
  }

  else
  {
    admin();
  }
}

void user()
{
  int choice;
  cout << "-----------------------------------" <<endl;
  cout << "Press 1. to add data"    << endl;
  cout << "Press 2. to view data"   << endl;
  cout << "Press 3. to search data" << endl;
  cout << "Press 4. to exit"        << endl;
  cout << "-----------------------------------" <<endl;

  cout << "\n";
  cout << "Please enter your choice : ";
  cin  >> choice;

  if (choice == 1)
  {
    add();
  }

  else if (choice == 2)
  {
    view();
  }

  else if (choice == 3)
  {
    search();
  }

  else if (choice == 4)
  {
    exit();
  }

  else
  {
    cout << "\n\n-----------------------------------------" << endl;
    cout << "You have enter wrong choice !! try again" << endl;
    user();

  }


}

int main() 
{

  cout << "-----------------------------------------" << endl;
  cout << "\t\t\t\t Employee Database" << endl;
  cout << "-----------------------------------------" << endl;

  // admin password = admin and username password = cmpsc121

  string password;

  cout << "\n\n\t Please enter password : ";
  cin  >> password;

  // if password for admin it will take to admin page else user

  if (password == "admin")
  {
    admin();
  }

  else if (password == "cmpsc121")
  {
    user();
  }

  else
  {
    cout << "----------------------------------------------------" << endl;
    cout << "\n\nSorry you are not authorized !!!" << endl;
    exit (0);
  }
//when the wrong password is entered, the program will display that they are not authorized.
  
}