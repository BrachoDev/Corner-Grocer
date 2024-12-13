#include "ItemTracker.h" // Including the header file ItemTracker.h

// Constructor:
ItemTracker::ItemTracker(string itemName, int itemFrequency) {

    ItemName = itemName;
    ItemFrequency = itemFrequency;

}    

// Setters:
void ItemTracker::setItemName(string itemName){
    ItemName = itemName;
}

void ItemTracker::setItemFrequency(int itemFrequency){
    ItemFrequency = itemFrequency;
}

// Getters:

string ItemTracker::getItemName() {
    return ItemName;
}

int ItemTracker::getItemFrequency() {
    return ItemFrequency;
}