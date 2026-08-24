#include <iostream>
#include <iomanip>
using namespace std;

struct Address{
  string city;
  string state;
  int zipCode;
};

struct Employee{
  string name;
  int id;
  double hourlyWage;
  double hoursWorked;
  double grossPay;
  Address address;
};

double calculateGrossPay(double hourlyWage, double hoursWorked);
void displayEmployee(Employee employee);
Employee findHighestPaid(Employee employees[], int size);
double calculateTotalPayroll(const Employee employees[], int size);
double calculateAveragePayroll(const Employee employees[], int size);
int countOvertimeEmployees(const Employee employees[], int size);
int findEmployeeById(const Employee employees[], int size, int targetId);
void giveRaise(Employee employees[], int size, int targetId, double percentage);
bool updateEmployeeAddress(Employee employees[], int size, int targetId, Address newAddress);


int main(){
  const int MAX_EMPLOYEES = 5;
  Employee employee[MAX_EMPLOYEES];
  int size;
  cout << "How many employee: ";
  cin >> size;
  while (!(size > 0  && size <= 5)){
    cout << "Max number of employee must be 5 or less than.\n please enter size again: ";
    cin >> size;
  }
  cout << endl;
  // Input Handling
  for(int i = 0; i < size; i++){
    cout << "Employee " << (i+1) << endl;
    cin.ignore();
    cout << "Name: ";
    getline(cin, employee[i].name);
    cout << "ID: "; 
    cin >> employee[i].id;
    cout << "Hourly wage: ";
    cin >> employee[i].hourlyWage;
    cout << "Hours worked: ";
    cin >> employee[i].hoursWorked;
    employee[i].grossPay = calculateGrossPay(employee[i].hourlyWage, employee[i].hoursWorked);
    cout << "Address" << endl;
    cin.ignore();
    cout << "City: ";
    getline(cin, employee[i].address.city);
    cout << "State: ";
    getline(cin, employee[i].address.state);
    cout << "Zip Code: ";
    cin >> employee[i].address.zipCode;
    cout << endl;
  }

  cout << endl;
  cout << "EMPLOYEE REPORT" << endl;
  for(int i = 0; i < size; i++){
    displayEmployee(employee[i]);
  }

    // Payroll Summary

  cout << fixed << setprecision(2);

  cout << "\nPAYROLL SUMMARY" << endl;
  cout << "================" << endl;

  cout << "Total payroll: $"
       << calculateTotalPayroll(employee, size) << endl;

  cout << "Average payroll: $"
       << calculateAveragePayroll(employee, size) << endl;

  cout << "Overtime employees: "
       << countOvertimeEmployees(employee, size) << endl;


  // Highest-Paid Employee

  Employee highestPaid = findHighestPaid(employee, size);

  cout << "\nHIGHEST-PAID EMPLOYEE" << endl;
  displayEmployee(highestPaid);


  // Search for Employee by ID

  int searchId;

  cout << "\nEnter employee ID to search: ";
  cin >> searchId;

  int searchIndex = findEmployeeById(employee, size, searchId);

  if (searchIndex >= 0) {
    cout << "\nEMPLOYEE FOUND" << endl;
    displayEmployee(employee[searchIndex]);
  } else {
    cout << "Employee not found." << endl;
  }


  // Give Raise

  int raiseId;
  double percentage;

  cout << "\nEnter employee ID to give a raise: ";
  cin >> raiseId;

  cout << "Enter raise percentage: ";
  cin >> percentage;

  int raiseIndex = findEmployeeById(employee, size, raiseId);

  giveRaise(employee, size, raiseId, percentage);

  if (raiseIndex >= 0 && percentage >= 0) {
    cout << "\nEMPLOYEE AFTER RAISE" << endl;
    displayEmployee(employee[raiseIndex]);
  }


  // Update Employee Address

  int addressId;
  Address newAddress;

  cout << "\nEnter employee ID to update address: ";
  cin >> addressId;

  cin.ignore();

  cout << "Enter new city: ";
  getline(cin, newAddress.city);

  cout << "Enter new state: ";
  getline(cin, newAddress.state);

  cout << "Enter new ZIP code: ";
  cin >> newAddress.zipCode;

  bool addressUpdated =
      updateEmployeeAddress(employee, size, addressId, newAddress);

  if (addressUpdated) {
    cout << "\nAddress updated successfully." << endl;

    int addressIndex =
        findEmployeeById(employee, size, addressId);

    displayEmployee(employee[addressIndex]);
  } else {
    cout << "Employee not found." << endl;
  }


  // Final Updated Employee Report

  cout << "\nFINAL UPDATED EMPLOYEE REPORT" << endl;
  cout << "=============================" << endl;

  for (int i = 0; i < size; i++) {
    displayEmployee(employee[i]);
  }


  // Updated Payroll Summary

  cout << "\nUPDATED PAYROLL SUMMARY" << endl;
  cout << "=======================" << endl;

  cout << "Total payroll: $"
       << calculateTotalPayroll(employee, size) << endl;

  cout << "Average payroll: $"
       << calculateAveragePayroll(employee, size) << endl;

  cout << "Overtime employees: "
       << countOvertimeEmployees(employee, size) << endl;

  Employee updatedHighestPaid =
      findHighestPaid(employee, size);

  cout << "\nHIGHEST-PAID EMPLOYEE AFTER UPDATES" << endl;
  displayEmployee(updatedHighestPaid);


  return 0;
}


double calculateGrossPay(double hourlyWage, double hoursWorked){
  if (hoursWorked <= 40){
    return hourlyWage * hoursWorked;
  } else {
    double regularPay = hourlyWage * 40;
    double overtimePay = ((hoursWorked - 40) * hourlyWage * 1.5);
    return regularPay + overtimePay;
  }
}

void displayEmployee(Employee employee){
  cout << fixed << setprecision(2);
  cout << "Employee Information" << endl;
  cout << "------------------------" << endl;
  cout << "Name: " << employee.name << endl;
  cout << "ID: " << employee.id << endl;
  cout << "Hourly wage: $" << employee.hourlyWage << endl;
  cout << "Hours worked: " << employee.hoursWorked << endl;
  cout << "Gross Pay: $" << employee.grossPay << endl;
  cout << "Address: " << employee.address.city << ", " << employee.address.state << ", " << employee.address.zipCode << endl;
}

Employee findHighestPaid(Employee employees[], int size){
  if (size >  0){
    double maxGrossPay = employees[0].grossPay;
    int index = 0;
    for(int i = 1; i < size; i++){
      if (maxGrossPay < employees[i].grossPay){
        index = i;
        maxGrossPay = employees[i].grossPay;
      }
    }
    return employees[index];
  } else {
    return Employee{};
  }
}

double calculateTotalPayroll(const Employee employees[], int size){
  double totalPayroll = 0;
  for(int i = 0; i < size; i++){
    totalPayroll += employees[i].grossPay;
  }
  return totalPayroll;
}


double calculateAveragePayroll(const Employee employees[], int size){
  return calculateTotalPayroll(employees, size) / (size  * 1.0);
}


int countOvertimeEmployees(const Employee employees[], int size){
  int count = 0;
  for(int i = 0; i < size; i++){
    if (employees[i].hoursWorked > 40){
      count++;
    }
  }
  return count;
}

int findEmployeeById(const Employee employees[], int size, int targetId){
  for(int i = 0; i < size; i++){
    if(employees[i].id == targetId){
      return i;
    }
  }
  return -1;
}

void giveRaise(Employee employees[], int size, int targetId, double percentage){
  if(percentage < 0){
     cout << "Raise percentage cannot be negative.\n";
    return;
  }
  int indexID = findEmployeeById(employees, size, targetId);
  if (indexID >= 0){
      double raiseAmount = employees[indexID].hourlyWage * (percentage / 100);
      employees[indexID].hourlyWage = employees[indexID].hourlyWage + raiseAmount;
      employees[indexID].grossPay = calculateGrossPay(employees[indexID].hourlyWage, employees[indexID].hoursWorked);
  } else {
    cout << "Employee not found." << endl;
  }
}

bool updateEmployeeAddress(Employee employees[], int size, int targetId, Address newAddress){
  int indexID = findEmployeeById(employees, size, targetId);
  if (indexID >= 0){
    employees[indexID].address = newAddress;
    return true;
  } else {
    return false;
  }
}