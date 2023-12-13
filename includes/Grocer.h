#ifndef GROCER_H
#define GROCER_H

#include <iostream>
#include <iomanip>
#include <set>
using namespace std;

class Grocer {
  private:
    // set to hold content of read-file
    set<string> groceryList;      

  public:
    // empty constructor
    Grocer(){};       

    // methods
    void createGroceryList();
    void showMenuOptions();
    string handleStrInputVal(string strInput);
    void handleMenuOptions();
    int freqOfGroceryItem(string groceryItem);
    void createBackup();
    void freqOfAllGroceryItems();
    void histogramOfAllGroceryItems();
    string histogramProducer(int freqOfItemCnt);
};

#endif