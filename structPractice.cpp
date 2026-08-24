#include <iostream>
using namespace std;

// A student is a type of data that contain name, age, and GPA.
struct Student {
  string name;
  int age;
  double gpa;
};

struct Employee{
  string name;
  int id;
  double hourlyWage;
  double hourWorked;
};

int main(){
  // create one student object. 
  Student s1{"Alex", 20, 3.7};
  Student s2{"Sarah", 21, 3.9};
  Student s3{"John", 19, 3.4};

  s1.gpa = 4.0;
  // s1.name = "Alex";
  // s1.age = 20;
  // s1.gpa = 3.7;
  // Struct objects can be copied.
// Student s2 = s1; creates a new Student object and copies
// the values of s1's members into s2.
// s1 and s2 are separate objects, so changing a member of
// s2 does not change the corresponding member of s1.
// Student s2 = s1;

  cout << s1.name << " " << s1.age << " " << s1.gpa << endl;

  Employee e;
  e.name = "Umar";
  e.id = 123;
  e.hourlyWage = 15;
  e.hourWorked = 30;

  cout << "Name: " << e.name << '\n'
        << "ID: " << e.id << '\n'
        << "Hourly Wage: " << e.hourlyWage << '\n'
        << "Worked Hours: " << e.hourWorked << endl;


  return 0;
}