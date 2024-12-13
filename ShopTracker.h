#ifndef SHOP_TRACKER_H
#define SHOP_TRACKER_H

#include <iostream>
#include<map>
using namespace std;

class ShopTracker {

private:
    // Map to store item names and their frequencies 
    map<string, int> items;

public:
    // Constructor:
    ShopTracker();

    // Methods:
    
    void loadFromFile(string filename); // Loads the data from the inventory.txt file
    int getFrequency(string item); //This returns the frequency of an specific item
    void showMenu(); // Displays a menu to the user




};























#endif