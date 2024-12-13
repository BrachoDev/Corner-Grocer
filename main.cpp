// Name: Carlos Bracho
// Course: CS-210

#include "ShopTracker.h"

using namespace std;

int main() {

    // Creating an instance of the ShopTracker class
    ShopTracker ShopTracker;

    // Loading the item data from the input file
    ShopTracker.loadFromFile("inventory.txt");

    // Display the menu for user interaction
    ShopTracker.showMenu(); 

    return 0;
}
