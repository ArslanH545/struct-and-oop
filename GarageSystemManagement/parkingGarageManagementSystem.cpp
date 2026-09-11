#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

struct Time{
    int hour = 0;
    int minute = 0;
};

struct Vehicle{
    string licensePlate = "";
    string make = "";
    string color = "";
};

struct ParkingTicket{
    int ticketName = -1;
    Vehicle vehicle;
    Time entryTime;
    Time exitTime;
};

struct ParkingSpace{
    bool occupied = false;
    ParkingTicket ticket;
};

struct Duration{
    int hour = 0;
    int minute = 0;
};

struct Position {
    int row = -1;
    int col = -1;
};



void displayMenu();
ostream &operator<<(ostream &os, const Time &time);
ostream &operator<<(ostream &os, const Vehicle &vehicle);
ostream &operator<<(ostream &os, const ParkingTicket &ticket);
ostream &operator<<(ostream &os, const ParkingSpace &space);
void designGarage(ParkingSpace **&space, int &rows, int &cols);
void displayGarage(ParkingSpace **space, int row, int cols);
void deleteGarage(ParkingSpace **&space, int rows);
Time getCurrentTime();
bool checkEmptySpace(ParkingSpace **& space, int &rows, int &cols);
Position findEmptySpace(ParkingSpace **& space, int &rows, int &cols);
void vehicleInfoAndDuration(ParkingSpace &parkingSpace, Duration &duration, int &row, int &col);
void printTicketToFile(const ParkingTicket& ticket);



int main(){
    // Design the Garage
    ParkingSpace **space;
    int rows, cols;
    designGarage(space, rows, cols);

    cout << endl;
    
    // display Garage
    displayGarage(space, rows, cols);

    cout << endl;

    Duration duration;
    
    while (true){
    // Check whether the garage has the empty space or not. 
        if (checkEmptySpace(space, rows, cols)){
            Position pos = findEmptySpace(space, rows, cols);
            // Asking the duration;
            vehicleInfoAndDuration(space[pos.row][pos.col], duration, pos.row, pos.col);
            printTicketToFile(space[pos.row][pos.col].ticket);
        } else {
            cout << "Garage is full!" << endl;
            break;
        }
        cout << endl;
    }
    //  Seeing how many being filled.
    displayGarage(space, rows, cols);
    // Delete memeory from heap.
    deleteGarage(space, rows);
    return 0;
}

void displayMenu(){
    cout << "1. Park a vehicle" << endl;
    cout << "2. Remove a vehicle" << endl;
    cout << "3. Find a vehicle" << endl;
    cout << "4. Display all parked vehicles" << endl;
    cout << "5. Display garage summary" << endl;
    cout << "Exit" << endl;
}

ostream &operator<<(ostream &os, const Time &time)
{
    int displayHour;
    if (time.hour == 0)
    {
        displayHour = 12;
    }
    else if (time.hour > 12)
    {
        displayHour = time.hour - 12;
    }
    else
    {
        displayHour = time.hour;
    }
    os << displayHour << ":";
    if (time.minute < 10)
    {
        os << "0";
    }
    os << time.minute;
    if (time.hour < 12)
    {
        os << " AM";
    }
    else
    {
        os << " PM";
    }

    return os;
}

ostream &operator<<(ostream &os, const Vehicle &vehicle){
    os << vehicle.licensePlate << " " << vehicle.make << " " << vehicle.color << endl;
    return os;
}

ostream &operator<<(ostream &os, const ParkingTicket &ticket){
    os << ticket.ticketName << "\n"
       << ticket.vehicle
       << ticket.entryTime
       << ticket.exitTime;
    return os;
}

ostream &operator<<(ostream &os, const ParkingSpace &space){
    if (!space.occupied)
    {
        os << "EMPTY";
    }
    else
    {
        os << "OCCUPIED";
    }
    return os;
}

void designGarage(ParkingSpace **&space, int &rows, int &cols){
    cout << "How many parking rows: ";
    cin >> rows;
    cout << "How many parking slot availible in each row: ";
    cin >> cols;
    space = new ParkingSpace *[rows];
    for (int i = 0; i < rows; i++)
    {
        space[i] = new ParkingSpace[cols];
    }
}

void displayGarage(ParkingSpace **space, int row, int cols){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < cols; j++){
            if (j < cols - 1)
            {
                cout << *(*(space + i) + j) << " ";
            }
            else
            {
                cout << *(*(space + i) + j);
            }
        }
        cout << endl;
    }
}

void deleteGarage(ParkingSpace **&space, int rows){
    for (int i = 0; i < rows; i++)
    {
        delete[] space[i];
    }
    delete[] space;
    space = nullptr;
}

// This method is written by chatgpt because I haven't learn the library and read documentation. 
Time getCurrentTime(){
    time_t now = time(nullptr);
    tm *localTime = localtime(&now);
    Time currentTime;
    currentTime.hour = localTime->tm_hour;
    currentTime.minute = localTime->tm_min;
    return currentTime;
}


bool checkEmptySpace(ParkingSpace **& space, int &rows, int &cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j< cols; j++){
            if (!space[i][j].occupied){
                return true;
            }
        }
    }
    return false;
}

Position findEmptySpace(ParkingSpace **& space, int &rows, int &cols){
    Position pos;
     for (int i = 0; i < rows; i++){
        for (int j = 0; j< cols; j++){
            if (!space[i][j].occupied){
               return pos = {i, j};
            }
        }
    }
    return pos;
}

void vehicleInfoAndDuration(ParkingSpace &parkingSpace, Duration &duration, int &row, int &col){
    cout << "How many hours: ";
    cin >> duration.hour;
    cout << "How many minutes: ";
    cin >> duration.minute;

    parkingSpace.occupied = true;
    parkingSpace.ticket.ticketName = row * 10 + col;
    parkingSpace.ticket.entryTime = getCurrentTime();
    parkingSpace.ticket.exitTime = {parkingSpace.ticket.entryTime.hour + duration.hour, parkingSpace.ticket.entryTime.minute + duration.minute};
    cout << "Vechicle License Plate: ";
    cin >> parkingSpace.ticket.vehicle.licensePlate;
    cout << "Vehicle Color: ";
    cin >> parkingSpace.ticket.vehicle.color;
    cout << "Brand Name: ";
    cin >> parkingSpace.ticket.vehicle.make;
}

void printTicketToFile(const ParkingTicket& ticket) {
    string outputFileName = "ticket" + to_string(ticket.ticketName) + ".txt";
    ofstream outputFile(outputFileName);

    outputFile << "========================" << endl;
    outputFile << "      PARKING TICKET" << endl;
    outputFile << "========================" << endl;

    outputFile << "Ticket #: " << ticket.ticketName << endl;

    outputFile << "License Plate: "
               << ticket.vehicle.licensePlate << endl;

    outputFile << "Vehicle: "
               << ticket.vehicle.make << endl;

    outputFile << "Color: "
               << ticket.vehicle.color << endl;

    outputFile << "Entry Time: "
               << ticket.entryTime << endl;

    outputFile << "Expiration Time: "
               << ticket.exitTime << endl;

    outputFile << "========================" << endl;

    outputFile.close();
}