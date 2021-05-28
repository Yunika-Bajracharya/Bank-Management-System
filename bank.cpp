#include <iostream>
using namespace std;

class bank
{
    char name[30];
    char accountName[20];
    char accountType[20];
    int initialBalance;
    int depositAmount;
    int withdrawlAmount;
public:
    void menu();
    void getInfo(); // contains value of the above ones
    void deposit();
    void withdraw();
    void info(); // shows all the information of the account
};

void bank::menu() {
    int option;
    cout<<"\n\t\t Choose an option from 1-6: \n\n";
    cout<<"\t\t 1. Create a New Account \n";
    cout<<"\t\t 2. Deposit money \n";
    cout<<"\t\t 3. Check your balance \n";
    cout<<"\t\t 4. Withdraw amount \n";
    cout<<"\t\t 5. View your Account Information \n";
    cout<<"\t\t 6. Exit \n";
    cin>>option;
}

void bank::getInfo() {
    cout<<"Enter Name: "<<endl;
    cin>>name;
    cout<<"Enter Account Name: "<<endl;
    cin>>accountName;
    cout<<"Enter the Type of Account: "<<endl;
    cin>>accountType;
    cout<<"How much amount would you like to Deposit? "<<endl;
    cin>>initialBalance;
    int go;
    cout<<"Enter 0 to go to the Main Menu"<<endl;
    cin>>go;
    if (go == 0) {
        menu();
    }
    else
        return;
}

int main () {
    bank obj;
    obj.menu();
    obj.getInfo();
    return 0;
}
