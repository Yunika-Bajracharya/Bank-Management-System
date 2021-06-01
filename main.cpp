#include "bank.h"
#include <cstdlib>
#include <stdio.h>
#include <iostream>
using std::string;

void bank::menu() {
  int option;
  do{
  std::cout << "\n\n\t\t *********************************\n"
            << "\t\t 1. Create a New Account \n"
            << "\t\t 2. Deposit money \n"
            << "\t\t 3. Check your balance \n"
            << "\t\t 4. Withdraw amount \n"
            << "\t\t 5. View your Account Information \n"
            << "\t\t 6. Exit \n"
            << "\t\t *********************************\n"
            << "\t\t Option: ";
  std::cin >> option;
  system("cls");
  std::cout << std::endl;
  switch (option) {
  case 1:
    getInfo();
    break;
  case 2:
    deposit();
    break;
  case 3:
    balanceInfo();
    break;
  case 4:
    withdraw();
    break;
  case 5:
    info();
    break;
  }
} while (option != 6);
}

void bank::getInfo() {
  using std::cout;
  using std::cin;
  fflush(stdin);
  cout << "Enter Account Name: ";
  cin.getline(accountName,40);
  cout << std::endl;
  cout << "Choose your Account Type[CURRENT | SAVINGS | FIXED] : ";
  cin >> accountType;
  cout << std::endl;
  cout << "How much amount would you like to Deposit? ";
  cin >> balance;
  cout << std::endl;
}

void bank::deposit() {
  std::cout << "Enter the amount you want to deposit: ";
  std::cin >> depositAmount;

  balance += depositAmount;
  std::cout << "\nRs. " << depositAmount << " has been successfully deposited. \n";
}

void bank::balanceInfo() {
  std::cout<<"Your current balance is Rs. "<<balance<<std::endl;
}
void bank::withdraw() {
  std::cout << "Enter the amount you want to withdraw: ";
  std::cin >> withdrawAmount;

  if (withdrawAmount <= balance) {
    balance -= withdrawAmount;
    std::cout << "\nRs. " << withdrawAmount << " has been withdrawn from your account.";
    }
  else {
    std::cout << "Insufficient Balance \n";
  }
}

void bank::info() {
  std::cout << "Account Name: " << accountName << std::endl
            << "Account Type: " << accountType << std::endl
            << "Balance: " << balance << std::endl;
}

int main() {
    bank obj;
    obj.menu();
  return 0;
}
