#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Player
{
	public:
	struct 
	{
		float money;
		float level;
		int id;
		int age;
		string name;

	} data;

	void PlayerData()
	{
		String PlayerName;
		String PlayerID;
		boolean PlayerIsRich;
		boolean PlayerIsPoor;
		float PlayerMoney;
		float PlayerIncome;

		if (PlayerIsRich == 100000)
		{
			cout << "Top 1 Percent Earner" << endl;
		}
		else
		{
			cout << " Player is Below 50 percent profit earner" << endl;
		}

		

	}

	


};

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


class Trade
{
	public:
	struct 
	{
		float currency;
		float price;
	} money;
		
	
};
		

int main()
{
	
	cout << ". View Players" << endl;
	cout << ". Login" << endl;
	cout << ". Sign in" << endl;
	cout << ". Trade" << endl;
	cout << ". Check Balance" << endl;
	cout << ". Buy" << endl;
	cout << ". Sell" << endl;
	cout << ". Exit" << endl;
	cout << " " << endl;
	char choice;

	cout << "Enter Choice: ";
	cin >> choice;

	Login log;
	SignIn sign;
	Trade trade;

	switch (choice)
	{
		case '1':
			log.Log();
		break;
		
		case '2':
			sign.Sign();
		break;

		case '3':
			trade.money


	}
		
}

	
