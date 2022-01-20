#include<iostream>
#include"try.cpp"


int main()
{
    AccountList al;
    al.addOneAccount();
    /*al.addMultipleAccounts();
    al.displayParticularMember();
    al.displayAll();
    al.checkBalance();
    al.withdrawRequest();
    al.checkBalance();*/
    cout<<"Deposit\n";
    al.DepositRequest();
    al.checkBalance();

    return 0;
}
