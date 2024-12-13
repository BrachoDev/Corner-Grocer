#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <iostream>
using namespace std;

class ItemTracker {

private:
    string ItemName;
    int ItemFrequency;

public:

    // Constructor:
    ItemTracker(string itemName, int itemFrequency);

    // Getters:
    string getItemName();
    int getItemFrequency();

    // Setters:
    void setItemName(string itemName);
    void setItemFrequency(int itemFrequency);

};

























#endif