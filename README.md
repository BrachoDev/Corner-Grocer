# Corner Grocer Item-Tracking Program

## Overview

This project is a simple item-tracking program for my class CS-210. The program analyzes text records of items purchased throughout the day and gives the user multiple functionalities.

## Functional Requirements

The program includes the following menu options:

1. **Search for Item Frequency**: Prompt the user to input an item and return the frequency of that item.
2. **Display All Items and Frequencies**: Print a list of all items and their purchase frequencies.
3. **Display Histogram of Item Frequencies**: Print a histogram representing the frequency of each item using asterisks.
4. **Exit**: Exit the program.

## Data File

The program reads from an input file `inventory.txt` and creates a backup file `frequency.dat` to store the frequency of each item.

## Implementation

The program is implemented in C++ and includes a class `ShopTracker` with the following methods:

- `loadFromFile(const std::string& filename)`: Loads item data from the input file.
- `saveToFile(const std::string& filename)`: Saves item frequencies to a backup file.
- `getFrequency(const std::string& item)`: Returns the frequency of a specific item.
- `displayAllItems()`: Displays all items and their frequencies.
- `displayHistogram()`: Displays a histogram of item frequencies.
- `showMenu()`: Displays the menu and handles user input.

## Example Output

```
Menu:
1. Search for an item frequency
2. Display all items and their frequencies
3. Display histogram of item frequencies
4. Exit
Enter your choice: 2

All items and their frequencies:
spinach: 4
radishes: 3
broccoli: 5
...

Menu:
1. Search for an item frequency
2. Display all items and their frequencies
3. Display histogram of item frequencies
4. Exit
Enter your choice: 3

Histogram of item frequencies:
spinach ****
radishes ***
broccoli *****
...
```

## Conclusion

This project demonstrates the ability to write professional, well-documented, and readable code in C++. It also showcases the use of classes and maps to develop a secure and efficient item-tracking program for the Corner Grocer.
