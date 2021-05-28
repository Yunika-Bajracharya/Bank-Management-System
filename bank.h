
class bank {
  char name[30];
  char accountName[20];
  char accountType[20];
  int initialBalance;

public:
  void menu();
  void getInfo(); // contains value of the above ones
  void deposit();
  void withdraw();
  void info(); // shows all the information of the account
};
