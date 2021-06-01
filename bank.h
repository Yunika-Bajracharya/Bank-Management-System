
class bank {
  char accountName[40];
  char accountType[30];
  double balance;
  double depositAmount;
  double withdrawAmount;

public:
  void menu();
  void getInfo(); // gets the information of the account
  void deposit();
  void balanceInfo();
  void withdraw();
  void info(); // shows all the information of the account
  void exit();
};
