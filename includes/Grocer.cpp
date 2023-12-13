#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
using namespace std;

#include "Grocer.h"

// methods

// creates a set that contains the names of the grocery items
// from the read file (does not contain duplicates)
void Grocer::createGroceryList() {
  string fileTxt;
  ifstream readFileTxt("CS210_Project_Three_Input_File.txt");   // read-file

  while (getline(readFileTxt, fileTxt)) {
    groceryList.insert(fileTxt);          // insert read-file contents to set
  }
  readFileTxt.close();
}

// Displays all of the menu options
void Grocer::showMenuOptions() {
  cout << "\n\nChoose from the following menu options: " << endl;
  cout << "\t1 - Find frequency of a specific item" << endl;
  cout << "\t2 - Display frequency of all items" << endl;
  cout << "\t3 - Display histogram of all items" << endl;
  cout << "\t4 - Quit program" << endl;
}

// Validates string input when searching for frequency
// of specific item
string Grocer::handleStrInputVal(string strInput) {
  string formattedStrInput = "";

  for (char charFromInput : strInput) {
    // capitalize first char
    if (charFromInput == strInput.at(0)) {
      charFromInput = toupper(strInput.at(0));
    } 
    // rest of the char should be lower-cased
    else {
      charFromInput = tolower(charFromInput);
    }
    formattedStrInput += charFromInput;
  }
  // return formatted string input 
  return formattedStrInput;
}

// Asks for the user's input and handles menu options
void Grocer::handleMenuOptions() {
  int menuOption = 0;
  string menuItemToSearch;

  // do-while loop will keep iterating until the user enters "4"
  do {
    // Ask for user input, and handle it according to the menu options
    showMenuOptions();
    cout << "Enter an menu option: ";
    cin >> menuOption;

    // Error handling for invalid input
    if (cin.fail()) {
      cout << "ERROR! Please try again with an input of 1-4." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
      handleMenuOptions();
    } 

    switch (menuOption) {
      case 1:
        cout << "Enter an item to search: ";
        cin >> menuItemToSearch;
        // formats string input to match the read-files format
        menuItemToSearch = handleStrInputVal(menuItemToSearch);

        // display message if item is not found
        if (freqOfGroceryItem(menuItemToSearch) == 0) {
          cout << menuItemToSearch << " is not found!" << endl;
        }
        // display frequency of inputted item
        else {
          cout << menuItemToSearch << " " << freqOfGroceryItem(menuItemToSearch) << endl;
        }
        break;
      case 2:
        cout << "Frequency of all items: " << endl;
        freqOfAllGroceryItems();
        break;
      case 3:
        cout << "Histogram of all items: " << endl;
        histogramOfAllGroceryItems();
        break;
      case 4:
        cout << "\nGoodbye! " << endl;
        exit(0);
        break;
      // handles error and displays message for invalid numerical values
      default:
        cout << "ERROR! Value outside of range: " << menuOption << endl;
        cout << "Please try again with an input of 1-4" << endl;
        break;
    }
  }
  while (menuOption != 4);
}

// Returns frequency of user inputted grocery item
int Grocer::freqOfGroceryItem(string groceryItem) {
  int numOfFreq = 0;

  string fileTxt;
  ifstream readFileTxt("CS210_Project_Three_Input_File.txt");   // read-file

  while (getline(readFileTxt, fileTxt)) {
    if (fileTxt == groceryItem) {
      numOfFreq++;
    }
  }
  readFileTxt.close();
  return numOfFreq;
}

// Creates "frequency.dat" file to save grocery-list frequency data
void Grocer::createBackup() {
  createGroceryList();                        // creates grocery-list set
  ofstream writeFileTxt("frequency.dat");

  // appends grocery item along with frequency to .dat file
  for (string groceryListItem : groceryList) {
    writeFileTxt << groceryListItem << " " << freqOfGroceryItem(groceryListItem) << endl;
  }
  writeFileTxt.close();                     // close write-file
} 

// prints the frequency of ALL grocery items
void Grocer::freqOfAllGroceryItems() {
  for (string groceryItem : groceryList) {
    cout << groceryItem << " " << freqOfGroceryItem(groceryItem) << endl;
  }
}

// prints the histogram of ALL grocery items
void Grocer::histogramOfAllGroceryItems() {
  for (string groceryItem : groceryList) {
    cout << groceryItem << " " << histogramProducer(freqOfGroceryItem(groceryItem)) << endl;
  }
}
// to help with main histogramOfAllGroceryItems method
string Grocer::histogramProducer(int freqOfItemCnt) {
  // prints the special character according to
  // frequency in grocery-list
  for (int i=0; i<freqOfItemCnt; i++) {
    cout << "*";
  }
  return "";
}