#include <iostream>
#include <cstring>
using namespace std;

void ftc(){
    double f;
    double c;
    int select;

    cout<<"Enter 1 For C to F"<<endl;
    cout<<"Enter 2 For F to C"<<endl;
    cout<<"Choice: ";
    cin>>select;

    switch(select){
        case 1:
            cout<<"Enter C: ";
            cin>>c;
            cout <<"F: "<< c*9.0/5.0 +32 <<endl;
            break;
        case 2:
            cout<<"Enter F: ";
            cin>>f;
            cout<<"C: "<< (f-32) * 5.0/9.00 <<endl;
            break;
        default:
            cout<<"The Selected option is not in the choices, Terminating..."<<endl;
    }
}

int main(){
    ftc();
}