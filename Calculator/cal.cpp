#include <iostream>
using namespace std;

void MainCode(){
int num1;
int num2;
char oper;

    cout<<"Enter First Number: ";
    cin>>num1;

    cout<<"Enter Second Number: ";
    cin>>num2;

    cout<<"Enter a Operator: ";
    cin>>oper;

    switch (oper) {
    case '+':
        cout<<num1<<" + "<<num2<<" = "<<num1 + num2;
        break;

    case '-':
        cout<<num1<<" - "<<num2<<" = "<<num1 - num2;
        break;
    
    case '*':
        cout<<num1<<" * "<<num2<<" = "<<num1 * num2;
        break;
    
    case '/':
        cout<<num1<<" / "<<num2<<" / "<<num1 / num2;
        break;
    
    default:
    cout<<"The Operator is non-existent, pick another one!"<<endl;
    break;
    }

}

int main(){
    MainCode();

    return 0;
}
