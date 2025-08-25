//this is my first project ever created
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // and i was planning to do algorithms stuff that is why i added it but i got lazy

using namespace std;

class Student
{
  private:
    string name = "undefined";
    char gender = 'm';
    int ID = 0;
    int age = 0;
    int grade = 0;
  public:
    Student(string n,int id,int a,int g)
    {
      name = n;
      ID = id;
      age = a;
      grade = g;
    }
    int Id() const { return ID; }
    int Age() const { return age; }
    int Grade() const { return grade; }

    void display() const
    {
      cout << "name of Student : " << name << endl;
      cout << "age of Student : " << age << endl;
      cout << "ID : " << ID << endl;
      cout << "Grade : " << grade << endl;
    }

};

class StudentManager
{
  private:
    vector<Student> students;
  public:
    void addStudent(const Student& s)
    {
      students.push_back(s);
      cout << "student added succsesfully" << endl;
    }
    void viewAll()
    {
      
        for (const Student& s : students)
        {
          s.display();
        }
    }
    void search(int id) const
    {
      for(const Student& s : students)
      {
        if(s.Id() == id)
        {
          cout << "student found" << endl;
          s.display();
        }
      }
    }
    void removeStudent(int id)
    {
      for(auto it = students.begin(); it != students.end();++it)
      {
        if(it->Id() == id)
        {
            students.erase(it);
            cout << "student removed succesfully" << endl;
            return;
        }

      }
    }




};
int main()
{
  StudentManager manager;
  int choice;

  do
  {
    cout << "/welcome to student manager" << endl;
    cout << "options :" << endl;
    cout << "1:add student\n";
    cout << "2:view all students\n";
    cout << "3:Search for a student\n";
    cout << "4:Remove student\n";
    cout << "5:Exit\n";
    cin >> choice;
    cin.ignore();
    switch(choice)
    {
      case 1:
      {
        string name;
        int id,ae,rade;
        
        cout << "/enter student name : ";
        getline(cin, name);
        cout << "\n";
        cout << "/enter student id :";
        cin >> id;
        cout << "\n";
        cout << "/enter student age : ";
        cin >> ae;
        cout << "/enter students grade : ";
        cin >> rade;
        
        cin.ignore();
        Student s(name,id,ae,rade);
        manager.addStudent(s);
        break;
      }
      case 2:
      {
        manager.viewAll();
        break;
      }
      case 3:
      {  
        int searchId;
        cout << "student ID : ";
        cin >> searchId;
        cout << "\n";
        manager.search(searchId);
        break;
      }
       case 4:
      {  
        int removeId;
        cout << "student ID : ";
        cin >> removeId;
        manager.removeStudent(removeId);
        break;
      }
      case 5:
      {
        cout << "bye" << endl;
        break;
      }
      default:
      {
        cout << "invalid choice" << endl;
        break;
      }
    }
  }while (choice != 5);
  
  return 0;
}
