#pragma once

#include <cstdlib>
#include <iostream>
#include <random>
#include <time.h>
#include <vector>

#include "User.h"
#ifdef WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define ASCII_NUM_PUSH 48

class Bank {
  std::vector<User> users;

public:
  void menu();
  void setInfo(); // set the information of the account
  void deposit();
  void balanceInfo();
  void withdraw();
  void showInfo(); // shows all the information of the account
  void updateInfo();
  // void removeAccount();
  void exit();

  int getAccoutIndex();

  static char *generateID();
};
