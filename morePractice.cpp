#include <iostream>
using namespace std;
#include <string>

struct Address{
  string city;
  string state;
  int zipCode;
};

struct Employee {
  string name;
  int id;
  Address address;
};

int main(){
  Employee employee1;

  employee1.name = "Arslan";
  employee1.id = 101;
  employee1.address.city = "Brooklyn";
  employee1.address.state = "New York";
  employee1.address.zipCode = 11210;

  Employee e
  {
      .name = "Arslan",
      .id = 101,
      .address = {
          .city = "Brooklyn",
          .state = "New York",
          .zipCode = 11210
      }
  };

  // Initialization: values provided during creation
  Employee employee1 = {"Arslan", 101, {"Brooklyn", "New York", 11210}};
  cout << employee1.name << endl;
  cout << employee1.address.city << endl;

  return 0;
}
