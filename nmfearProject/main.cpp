#include<iostream>
using namespace std;
int main()
{
	struct
	{
		string fname;
		string lname;
		string job;
		string desc;
	} catdata;
	
	struct
	{
		int studId;
		float percent;
		float val;
	} numdata;
	
	struct
	{
		char choice;
		string pass;
		string user;
		string logpass;
		string loguser;
	} login;
	
	cout << "1. Login" << endl;
	cout << "2. Sign in" << endl;
	cout << "3. Trade" << endl;
	cout << "4. Buy" << endl;
	cout << "5. Sell" << endl;
	cout << "6. Exit" << endl;
	
	class login 
	{
		public:
			cout << "Enter a Username: ";
			cin >> login.user;
			
			cout << "Enter a Password: ";
			cin >> login.pass;
				
	};
	
	class SignIn
	{
		public:
			cout << "Enter a desired Username: ";
			cin >> login.loguser;
			
			cout << "Enter a desired Password: ";
			cin >> login.logpass;
			
	}
	
	class trade
	{
		public:
			cout << ""
	}
	
	
	
	
	
	
	
	/*switch(choice)
	{
		case 1:
			
	}*/
	
	
}
