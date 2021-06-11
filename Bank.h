#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>

#include "User.h"
#ifdef WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

class Bank {
  char accountName[40];
  char accountType[30];
  double balance;
  double depositAmount;
  double withdrawAmount;
  std::vector<User> users;

public:
  void menu();
  void getInfo(); // gets the information of the account
  void deposit();
  void balanceInfo();
  void withdraw();
  void info(); // shows all the information of the account
  void exit();
};
