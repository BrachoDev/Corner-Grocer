#include "ShopTracker.h"

using namespace std;

int main() {
    ShopTracker ShopTracker;
    ShopTracker.loadFromFile("inventory.txt");  // Load items from the input file

    // Call the menu directly from the InventoryApp class
    ShopTracker.showMenu(); 

    return 0;
}
