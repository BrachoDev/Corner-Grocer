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
    ShopTracker();
    void loadFromFile(const std::string& filename);  // Loads item data from the input file
    void saveToFile(const std::string& filename);   // Saves item frequencies to a backup file
    int getFrequency(const std::string& item);      // Returns frequency of a specific item
    void displayAllItems();                        // Displays all items with their frequencies
    void displayHistogram();                       // Displays histogram of item frequencies
    void showMenu();                               // Display the menu
};

#endif
