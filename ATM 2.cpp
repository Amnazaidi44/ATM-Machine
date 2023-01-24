#include<iostream>
#include<fstream>
using namespace std;
class ATM_MACHINE{
    private:
        int withdraw;
        int deposit;
        int balance;

        public:
            ofstream write;
            ifstream read;
            
            ATM_MACHINE(){
                balance = 0;
            }
            void showChoice(){
                cout<<"1 => Check Balance"<<endl;
                   cout<<"2 => Deposit Money"<<endl;
                    cout<<"3 => Withdraw Money"<<endl;
                    cout<<"4 => Show Transaction History"<<endl;
            }
            void checkBalance(){
                cout<<"Your Balance is : "<<balance<<"Rs"<<endl;
            }

            void DepositCash(){
                write.open("hi.txt",ios::app);
                cout<<"Enter Amount to Deposit : ";
                cin>>deposit;
                while(deposit<0){
                    cout<<"Plese Enter Correct Value : ";
                    cin>>deposit;
                }
                balance+=deposit;
                cout<<deposit<<"Rs Deposited to Your Account"<<endl;
                if(deposit!=0){
                    write<<"You Deposited   : "<<deposit<<"Rs"<<endl;
                }
                write.close();
            }

            void withdrawCash(){
                write.open("hi.txt",ios::app);
                cout<<"Enter Amount to Withdraw : ";
                cin>>withdraw;
                balance-=withdraw;
                cout<<withdraw<<"Rs Withdrawn from your Account"<<endl;
                if(withdraw!=0){
                    write<<"You Withdrawn   : "<<withdraw<<"Rs"<<endl;
                }
                write.close();
            }

            void showHistory(){
                string str;
                read.open("hi.txt");
                getline(read,str);
                bool empty = str.empty() != 0;
                if(empty){
                    cout<<"File is Empty!"<<endl;
                }
                else{
                	write.open("hi.txt",ios::app);
                    cout<<"\nTransaction History"<<endl;
                    while(read.eof()==0){
                    getline(read,str);
                    cout<<str<<endl;
                }
                }
                read.close();
            }
};

int main(){
    double cardno=12345678910;
    int pincode;
    int choice;
    char ans;
    ATM_MACHINE account;
    cout<<"Enter card no";
    cin>>cardno;
    if(cardno==cardno)
{
cout<<"Enter pin code";
cin>>pincode;
if(pincode==1234)
{
cout<<"Password is correct";
do{
    account.showChoice();
    cout<<"Enter Your Choice => ";
    cin>>choice;

    switch(choice){
        case 1:
        account.checkBalance();
        break;

        case 2:
        account.DepositCash();
        break;

        case 3:
        account.withdrawCash();
        break;

        case 4:
        account.showHistory();
        break;

        default:
        cout<<"Invalid Choice!"<<endl;
    }

    cout<<"Do You Want to Run Program Again (Y/N) : ";
    cin>>ans;
    if(ans=='N' || ans == 'n'){
        cout<<"Thanks for Using My ATM MACHINE"<<endl;
    }
}while(ans=='Y' || ans=='y');
}
else
{
	cout<<"pin code is incorrect";
}
}
else
{
cout<<"Incorrect";
}
}
