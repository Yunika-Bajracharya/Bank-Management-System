#pragma once
#include "Bank.h"
#define CURRENT 1
#define SAVINGS 2
#define FIXED 3

class User {
public:
  User(const char *name, const char *id, int type, long initialBalance);
  ~User();
  // Get functions, returns user's informations
  const char *getName();
  const char *getID();
  int getAccoutType();
  long getBalance();

  // Set functions, sets user's informations
  void setName(const char *);
  void setID(const char *);
  void setAccountType(int);
  int deposit(long);
  int withdraw(long);

private:
  const char *name, *id;
  int type;
  long balance;
};
