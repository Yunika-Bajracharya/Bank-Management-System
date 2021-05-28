#include "bank.h"
#include <iostream>
using namespace std;

void bank::menu() {
  int option;
  cout << "\n\t\t Choose an option from 1-6: \n\n";
  cout << "\t\t 1. Create a New Account \n";
  cout << "\t\t 2. Deposit money \n";
  cout << "\t\t 3. Check your balance \n";
  cout << "\t\t 4. Withdraw amount \n";
  cout << "\t\t 5. View your Account Information \n";
  cout << "\t\t 6. Exit \n";
  cin >> option;

  switch (option) {
  case 1:
    getInfo();
    break;
  case 2:
    deposit();
    break;
  case 3:
    info();
    break;
  case 4:
    withdraw();
    break;
  case 5:
    info();
    break;
  case 6:
    cout << "Thank you" << endl;
    exit(0);
    break;
  default:
    cout << "Thank you" << endl;
    break;
  }
}

void bank::getInfo() {
  cout << "Enter Name: " << endl;
  cin >> name;
  cout << "Enter Account Name: " << endl;
  cin >> accountName;
  cout << "Enter the Type of Account: " << endl;
  cin >> accountType;
  cout << "How much amount would you like to Deposit? " << endl;
  cin >> initialBalance;
  int go;
  cout << "Enter 0 to go to the Main Menu" << endl;
  cin >> go;
  if (go == 0) {
    menu();
  } else
    return;
}

void bank::deposit() {
  int value;
  cout << "Enter the ammout: ";
  cin >> value;

  initialBalance += value;
  cout << "added money";
  menu();
}

void bank::withdraw() {
  int value;
  cout << "Enter the ammout: ";
  cin >> value;

  if (value <= initialBalance) {
    initialBalance -= value;
  } else {
    cout << "Insufficient Balance" << endl;
  }
  menu();
}

void bank::info() {
  cout << "Name: " << name << endl
       << "Account Name :" << accountName << endl
       << "Accout Type: " << accountType << endl
       << "Balance: " << initialBalance << endl;

  menu();
}

int main() {
  bank obj;
  obj.menu();
  return 0;
}
