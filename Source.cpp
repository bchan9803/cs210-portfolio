// Bryan Chan
// Prof. Bill Chan (CS 210)
// 10 December 2023
// Project Three
// The purpose of this project is to create a "grocery-tracking program" that can read from a .txt file, analyze the data, and display the frequencies of the item's apperance based on the user's selection.


#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
using namespace std;

#include "includes/Grocer.h"
#include "includes/Grocer.cpp"

int main() {
  Grocer test1;  

  test1.createBackup();       // creates back-up file
  test1.handleMenuOptions();  // display menu

  return 0; 
}