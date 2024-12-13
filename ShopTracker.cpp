// Name: Carlos Bracho
// Course: CS-210

#include "ShopTracker.h"


using namespace std;

// Constructor:
ShopTracker::ShopTracker() {}

// Methods:

// This method loads the item data from a file, updating the frequency map
void ShopTracker::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file!" << endl; // Displays an error if the file can't be opened for some reason
        return;
    }

    string word;
    while (file >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);  // Make everything lowercase
        items[word]++;  // Increment the frequency count of the item
    }

    file.close();
    saveToFile("frequency.dat");  // Save the data to a backup file
}

// This method saves the item names and frequencies to a backup file
void ShopTracker::saveToFile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error saving file!" << endl; // Displays an error if the file can't be opened for some reason
        return;
    }

    // Loop through the map and write each item and its frequency to the file
    for (const auto& pair : items) {
        file << pair.first << " " << pair.second << endl;  // Save each item and its frequency
    }

    file.close();
}

// This method returns the frequency of an item
int ShopTracker::getFrequency(const string& item) {
    string lowerItem = item;
    
    // Converting the input item to lowercase for input handling 
    transform(lowerItem.begin(), lowerItem.end(), lowerItem.begin(), ::tolower);
    return items[lowerItem];  // Return frequency of the item, default is 0 if not found
}


// This method displays all items and their frequencies on the screen
void ShopTracker::displayAllItems() {
    for (const auto& pair : items) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

// This method displays a histogram of item frequencies using asterisks
void ShopTracker::displayHistogram() {
    for (const auto& pair : items) {
        cout << pair.first << " ";

        // Print a number of asterisks equal to the item's frequency
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";  // Print asterisk for each item occurrence
        }
        cout << endl;
    }
}

// This method displays the main menu and handles user input for different choices
void ShopTracker::showMenu() {
    int choice;
    do {
        // Display menu
        cout << "\nMenu:" << endl;
        cout << "1. Search for an item frequency" << endl;
        cout << "2. Display all items and their frequencies" << endl;
        cout << "3. Display histogram of item frequencies" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";

        // Check if the input is a valid integer and within range (1-4)
        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input

            cout << "Invalid input! Please enter a valid option (1-4): ";
        }
                
        // Handle the user's menu choice
        switch (choice) {
            case 1: {
                // Ask the user to input the item they want to search for
                cout << "Enter the item you want to search for: ";
                string item;
                cin >> item;
                int frequency = getFrequency(item);
                cout << "\nThe item \"" << item << "\" appears " << frequency << " times." << endl;
                break;
            }
            case 2: {
                // Display all items and their frequencies
                cout << "\nAll items and their frequencies:" << endl;
                displayAllItems();
                break;
            }
            case 3: {
                // Display the histogram of item frequencies
                cout << "\nHistogram of item frequencies:" << endl;
                displayHistogram();
                break;
            }
            case 4: {
                // Exit the program
                cout << "\nExiting the program." << endl;
                break;
            }
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);
}

