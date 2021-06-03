#include "Bank.h"

Bank *bank = nullptr;
int main() {

  bank = new Bank();

  bank->menu();
}
