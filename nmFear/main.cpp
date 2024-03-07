#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


class Login 
{
	public:	
	struct
	{
		char choice;
		string pass;
		string user;
	} login;
	
	void Log()
	{
		cout << "Enter a Username: ";
		cin >> login.user;
			
		cout << "Enter a Password: ";
		cin >> login.pass;
	}
	
};

class SignIn
{
	public:
	struct
	{
		string signpass;
		string signuser;
	} sign;
	
	void Sign()
	{
		cout << "Enter a desired Username: ";
		cin >> sign.signuser;
			
		cout << "Enter a desired Password: ";
		cin >> sign.signpass;
	}
					
};
		
int main()
{
	
	cout << "1. Login" << endl;
	cout << "2. Sign in" << endl;
	cout << "3. Trade" << endl;
	cout << "4. Buy" << endl;
	cout << "5. Sell" << endl;
	cout << "6. Exit" << endl;
	cout << " " << endl;
	char choice;

	cout << "Enter Choice: ";
	cin >> choice;

	Login log;
	SignIn sign;

	switch (choice)
	{
		case '1':
			log.Log();
		break;
		
		case '2':
			sign.Sign();
		break;
	}
		
}

	
