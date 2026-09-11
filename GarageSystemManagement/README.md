# C++ Parking Garage Management System

A console-based parking garage management system written in C++.

This project was built to practice C++ structs, pointers, references, dynamic memory allocation, operator overloading, time handling, and file I/O.

## Features

- Dynamically creates a parking garage based on user input
- Uses a dynamically allocated 2D array of parking spaces
- Searches for available parking spaces
- Prevents additional vehicles from entering when the garage is full
- Collects vehicle information:
  - License plate
  - Vehicle brand/make
  - Vehicle color
- Automatically records the vehicle's entry time
- Allows the customer to enter a parking duration
- Calculates the ticket expiration time
- Marks parking spaces as `EMPTY` or `OCCUPIED`
- Assigns a ticket number based on the parking location
- Generates a separate `.txt` ticket file for each parked vehicle


## Example

### Garage Setup

```text
How many parking rows: 2
How many parking slot availible in each row: 2

EMPTY EMPTY
EMPTY EMPTY
```

### Parking a Vehicle

```text
How many hours: 1
How many minutes: 10
Vechicle License Plate: 111
Vehicle Color: Black
Brand Name: Ford
```

After all four spaces in a 2x2 garage are occupied:

```text
Garage is full!

OCCUPIED OCCUPIED
OCCUPIED OCCUPIED
```

## Generated Parking Ticket

Each customer receives a separate text file containing their parking ticket.

Example:

```text
========================
      PARKING TICKET
========================
Ticket #: 0
License Plate: 111
Vehicle: Ford
Color: Black
Entry Time: 4:37 PM
Expiration Time: 5:47 PM
========================
```

Example ticket files:

```text
ticket0.txt
ticket1.txt
ticket10.txt
ticket11.txt
```



## Concepts Practiced

This project was created as part of my C++ learning and focuses on:

- Structs and nested structs
- Pointers
- References
- Pass-by-reference
- Dynamic memory allocation
- Dynamic 2D arrays
- Searching through a 2D structure
- Operator overloading
- System time using `<ctime>`
- Time calculations
- File output using `ofstream`
- Basic input handling
- Breaking a larger program into functions


Compile: 
```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -Werror parkingGarageManagementSystem.cpp -o m
```
Run:
```bash
./m
```


## Purpose

The goal of this project was not only to build a parking garage simulation, but also to combine several fundamental C++ concepts into one larger program.

It demonstrates how structs, pointers, references, dynamic memory, time handling, and file I/O can work together in a practical application.