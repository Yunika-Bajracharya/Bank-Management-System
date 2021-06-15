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
              << "\t\t 6. Update your Account Information \n"
              << "\t\t 7. Remove your Account \n"
              << "\t\t 8. Exit \n"
              << "\t\t *********************************\n"
              << "\t\t Option: ";
    std::cin >> option;
    system(CLEAR);
    switch (option) {
    case 1:
      setInfo();
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
      showInfo();
      break;
    case 6:
      updateInfo();
      break;
/*     case 7:
      removeAccount();
      break; */
    }
  } while (option != 8);
}

void Bank::setInfo() {
  using std::cin;
  using std::cout;

  char accountName[40];
  char address[40];
  int phoneNumber;
  int accountType;
  long balance;

  fflush(stdin);
  cout << "Enter Account Name: ";
  // cin.getline(accountName, 40);
  cin >> accountName;
  cout << std::endl;
  cout << "Enter your Address: ";
  cin >> address;
  cout << std::endl;
  cout << "Enter your contact number: ";
  cin >> phoneNumber;
  cout << std::endl;
  cout << "Choose your Account Type[CURRENT | SAVINGS | FIXED] : ";
  cin >> accountType;
  cout << std::endl;
  cout << "How much amount would you like to Deposit? ";
  cin >> balance;
  cout << std::endl;

  char *ID = generateID();

  User user(accountName, ID, accountType, balance);
  cout << "New user created, ID: " << ID << std::endl;
  users.push_back(user);

  delete ID;
}

void Bank::deposit() {
  int index = getAccoutIndex();
  if (index == -1) {
    return;
  }
  User user = users.at(index);

  long depositAmount;
  std::cout << "Enter the amount you want to deposit: ";
  std::cin >> depositAmount;

  int depositStatus = user.deposit(depositAmount);
  if (depositStatus) {
    std::cout << "\nRs." << depositAmount << "has been successfully deposited."
              << std::endl;

    users.erase(users.begin() + index);
    users.push_back(user);
  } else {
    std::cout << "\n Something Went wrong" << std::endl;
  }
}

void Bank::balanceInfo() {
  std::cout << "Your current balance is Rs. " << users.at(0).getBalance()
            << std::endl;
}

void Bank::withdraw() {
  int index = getAccoutIndex();
  if (index == -1) {
    return;
  }
  User user = users.at(index);

  long withdrawAmount;
  std::cout << "Enter the amount you want to withdraw: ";
  std::cin >> withdrawAmount;

  int withdrawStatus = user.withdraw(withdrawAmount);
  if (withdrawStatus) {
    std::cout << "\nRs. " << withdrawAmount
              << " has been withdrawn from your account.";
    users.erase(users.begin() + index);
    users.push_back(user);
  } else {
    std::cout << "Insufficient Balance \n";
  }
}

void Bank::showInfo() {
  int index = getAccoutIndex();
  if (index == -1) {
    return;
  }
  User user = users.at(index);
  std::cout << "Account Name: " << user.getName() << std::endl
            << "Accout ID:" << user.getID() << std::endl
            << "Account Type: " << user.getAccoutType() << std::endl
            << "Balance: " << user.getBalance() << std::endl;
}

void Bank::updateInfo() {
  using std::cin;
  using std::cout;

  char accountName[40];
  char address[40];
  int phoneNumber;
  int accountType;
  long balance;

  int index = getAccoutIndex();
  if (index == -1) {
    return;
  }
  User user = users.at(index);

  cout << "\nPrevious Data" << std::endl
            << "Account Name: " << user.getName() << std::endl
            << "Accout ID:" << user.getID() << std::endl
            << "Account Type: " << user.getAccoutType() << std::endl
            << "Balance: " << user.getBalance() << std::endl
            << "\nEnter new data: "<< std::endl;
  cout << "\nEnter Account Name: ";
  cin >> accountName;
  cout << std::endl;
  cout << "Enter your Address: ";
  cin >> address;
  cout << std::endl;
  cout << "Enter your contact number: ";
  cin >> phoneNumber;
  cout << std::endl;
  cout << "Choose your Account Type[CURRENT | SAVINGS | FIXED] : ";
  cin >> accountType;
  cout << std::endl;

  char *ID = generateID();

  cout << "Your new account ID is: " << ID << std::endl;
  users.push_back(user);

  delete ID;
}

int Bank::getAccoutIndex() {
  char ID[ID_LENGTH];
  std::cout << "Enter the account ID: ";
  std::cin >> ID;
  for (int i = 0; i < users.size(); i++) {
    if (strcmp(ID, users.at(i).getID()) == 0) {
      std::cout << "User Found" << std::endl;
      return i;
    }
  }
  std::cout << "Invalid ID" << std::endl;
  return -1;
}

char *Bank::generateID() {
  std::srand(time(NULL));
  char *ID = new char[ID_LENGTH];

  for (int i = 0; i < ID_LENGTH; i++) {
    ID[i] = static_cast<char>((rand() % 10) + ASCII_NUM_PUSH);
  }

  ID[ID_LENGTH + 1] = '\0';

  // TODO
  // Make each ID unique

  return ID;
}
