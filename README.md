# C++ Struct and OOP Practice

This repository contains my C++ practice assignments focused on structures and foundational object-oriented programming concepts.

## Concepts Practiced

- Defining custom data types using `struct`
- Creating and initializing structure objects
- Accessing members with the dot operator
- Copying structure objects
- Nested structures
- Arrays of structures
- Passing structured data to functions
- Reading input with `cin` and `getline`
- Using `cin.ignore()` when switching between numeric and line input
- Organizing employee and address information
- Calculating employee payroll

## Employee Payroll Assignment

The employee payroll program:

1. Asks how many employees will be entered.
2. Collects each employee's:
   - Name
   - ID
   - Hourly wage
   - Hours worked
   - City
   - State
   - ZIP code
3. Stores the information using nested structures.
4. Calculates and displays payroll information.

## Example Structure Design

```cpp
struct Address {
    string city;
    string state;
    int zipCode;
};

struct Employee {
    string name;
    int id;
    double hourlyWage;
    double hoursWorked;
    Address address;
};


## Compile and Run

Compile a C++ file using:

g++ -std=c++17 filename.cpp -o program

Run the program:

./program

Replace filename.cpp with the name of the source file you want to compile.

## Operator overloading using with struct. 
C++ know how to print built-in types such as int, double, and string, but it does not automatocially know how an Employee should be display. 
struct Employee{
    ..
}
int main(){
    Employee e;
    cout << e << endl;
}
this can not be because we haven't teach the C++ how to print it. 
