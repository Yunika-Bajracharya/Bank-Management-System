#include "User.h"

const char *User::getName() { return name; }
const char *User::getID() { return id; }
int User::getAccoutType() { return type; }
long User::getBalance() { return balance; }

void User::setName(const char *name) { strcpy(this->name, name); }
void User::setID(const char *id) { strcpy(this->id, id); }
void User::setAccountType(int type) { this->type = type; }
int User::deposit(long amount) {
  this->balance += amount;
  return 1;
}
int User::withdraw(long amount) {
  if (amount > this->balance) {
    return 0;
  } else {
    this->balance -= amount;
    return 1;
  }
}

User::User(const char *name, const char *id, int type, long initialBalance) {
  this->balance = 0;

  this->setName(name);
  this->setID(id);
  this->setAccountType(type);
  this->deposit(initialBalance);
}

User::~User() {}
