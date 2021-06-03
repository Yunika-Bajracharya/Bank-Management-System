#include "Bank.h"

using std::string;

void Bank::menu() {
  int option;
  do {
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

void Bank::getInfo() {
  using std::cin;
  using std::cout;
  fflush(stdin);
  cout << "Enter Account Name: ";
  cin.getline(accountName, 40);
  cout << std::endl;
  cout << "Choose your Account Type[CURRENT | SAVINGS | FIXED] : ";
  cin >> accountType;
  cout << std::endl;
  cout << "How much amount would you like to Deposit? ";
  cin >> balance;
  cout << std::endl;
}

void Bank::deposit() {
  std::cout << "Enter the amount you want to deposit: ";
  std::cin >> depositAmount;

  balance += depositAmount;
  std::cout << "\nRs. " << depositAmount
            << " has been successfully deposited. \n";
}

void Bank::balanceInfo() {
  std::cout << "Your current balance is Rs. " << balance << std::endl;
}
void Bank::withdraw() {
  std::cout << "Enter the amount you want to withdraw: ";
  std::cin >> withdrawAmount;

  if (withdrawAmount <= balance) {
    balance -= withdrawAmount;
    std::cout << "\nRs. " << withdrawAmount
              << " has been withdrawn from your account.";
  } else {
    std::cout << "Insufficient Balance \n";
  }
}

void Bank::info() {
  std::cout << "Account Name: " << accountName << std::endl
            << "Account Type: " << accountType << std::endl
            << "Balance: " << balance << std::endl;
}

