// Name: Carlos Bracho
// Course: CS-210

#ifndef INVENTORY_APP_H
#define INVENTORY_APP_H

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>

class ShopTracker {
private:
    std::map<std::string, int> items;  // Map to store item names and their frequencies

public:
    ShopTracker(); // Constructor to initialize the ShopTracker object
    void loadFromFile(const std::string& filename);  // Loads item data from the input file and updates the map
    void saveToFile(const std::string& filename);   // Saves item frequencies to a backup file
    int getFrequency(const std::string& item);      // Returns the frequency of a specific item, after converting it to lowercase
    void displayAllItems();                        // Displays all items and their frequencies
    void displayHistogram();                       // Displays histogram of item frequencies
    void showMenu();                               // Display the menu and handles user input
};

#endif
