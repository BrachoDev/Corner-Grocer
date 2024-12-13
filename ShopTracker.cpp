#include "ShopTracker.h"


using namespace std;

ShopTracker::ShopTracker() {}

void ShopTracker::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file!" << endl;
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

void ShopTracker::saveToFile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error saving file!" << endl;
        return;
    }

    for (const auto& pair : items) {
        file << pair.first << " " << pair.second << endl;  // Save each item and its frequency
    }

    file.close();
}

int ShopTracker::getFrequency(const string& item) {
    string lowerItem = item;
    transform(lowerItem.begin(), lowerItem.end(), lowerItem.begin(), ::tolower);  // Lowercase input
    return items[lowerItem];  // Return frequency of the item, default is 0 if not found
}

void ShopTracker::displayAllItems() {
    for (const auto& pair : items) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

void ShopTracker::displayHistogram() {
    for (const auto& pair : items) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";  // Print asterisk for each item occurrence
        }
        cout << endl;
    }
}

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
                

        switch (choice) {
            case 1: {
                cout << "Enter the item you want to search for: ";
                string item;
                cin >> item;
                int frequency = getFrequency(item);
                cout << "The item \"" << item << "\" appears " << frequency << " times." << endl;
                break;
            }
            case 2: {
                cout << "All items and their frequencies:" << endl;
                displayAllItems();
                break;
            }
            case 3: {
                cout << "Histogram of item frequencies:" << endl;
                displayHistogram();
                break;
            }
            case 4: {
                cout << "Exiting the program." << endl;
                break;
            }
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);
}

