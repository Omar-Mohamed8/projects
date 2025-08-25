#include <iostream>
#include <vector>
#include <string>

using namespace std;
string name1 = "undefined";
string name2 = "undefined";
int won = 0;
class User
{
	private:
		string user1 = "player 1";
		string user2 = "player 2";
	public:
		User(string n1,string n2)
		{
			user1 = n1;
			user2 = n2;
		}
		string getUsr()
		{
			return user1;
		}
		string getUsrt()
		{
			return user2;
		}
};
void setUser()
{
	cout << "player 1 : " << endl;
	getline(cin, name1)
	cout << "player 2 : " << endl;
	getline(cin, name2)
}
void print(vector<vector<User>>& tic)
{
		for(auto& i : tic)
		{
			for(auto& j : i)
			{
				cout << j << " ";
			}
			cout << endl;
		}

		cout << endl;

}
void check(vector<vector<User>>& tic)
{
	const int h = 3;
	char one = 'x';
	char two = 'o';
	for(int i =0,i > 3,i++)
	{
		if(tic[i][0] = one && tic[i][1] = one && tic[i][2] = one)
		{
			won = 1;
		}
		else if(tic[0][i] = one && tic[1][i] = one && tic[0][i] = one)
		{
			won = 1;
		}
		else if(tic[0][0] = one && tic[1][1] = one && tic[2][2] = one)
		{
			won = 1;
		}
		else if(tic[0][2] = one && tic[1][1] = one && tic[2][0] = one)
		{
			won = 1;
		}

		else if(tic[i][0] = two && tic[i][1] = two && tic[i][2] = two)
		{
			won = 2;
		}
		else if(tic[0][i] = two && tic[1][i] = two && tic[0][i] = two)
		{
			won = 2;
		}
		else if(tic[0][0] = two && tic[1][1] = two && tic[2][2] = two)
		{
			won = 2;
		}
		else if(tic[0][2] = two && tic[1][1] = two && tic[2][0] = two)
		{
			won = 2;
		}
		else
		{
			won = 0;
		}
	}
}
int main()
{
	setUser();
	User ob1(name1,name2);
	vector<vector<User>>tic;
	tic.push_back({0,0,0});
	tic.push_back({0,0,0});
        tic.push_back({0,0,0});

	do
	{	
		int row = 0;
		int column = 0;
		char choice = 'y';
		
		print(tic);

		cout << "player " << user1 << "turn,X" << endl;
		cout << "choose a row:";
		cin >> row;
		if(row > 3 || row = 0)
		{
			cout << "wrong position" << endl;
			return;
		}
		cout << "choose a coulmn:";
		cin >> coulmn;
		if(column > 3 || column = 0)
		{
			cout << "wrong position" << endl;
			return;
		}
		if(tic[row][column] == 'o' || tic[row][column] == 'x')
		{
			cout << "taken position" << endl;
			return;
		}
		tic[row][column] = 'x';

		cin.ignore();

		print(tic);

		cout << "player " << user2 << "turn,0" << endl;
		cout << "choose a row:";
		cin >> row;
		if(row > 3 || row = 0)
		{
			cout << "wrong position" << endl;
			return;
		}
		cout << "choose a coulmn:";
		cin >> coulmn;
		if(column > 3 || column = 0)
		{
			cout << "wrong position" << endl;
			return;
		}
                if(tic[row][column] == 'o' || tic[row][column] == 'x')
		{
			cout << "taken position" << endl;
			return;
		}
		tic[row][column] = 'o';
		cin.ignore();
		
		check(tic);
		if(win = 1)
		{
			cout << user1 << "won" << endl;
			cout << "wanna play again?/y : yes,n : no ";
			cin >> choice;
			if (choice == 'y')
			{
				tic.push_back({0,0,0});
				tic.push_back({0,0,0});
        	       		tic.push_back({0,0,0});
			}

		}
		else if(win = 2)
		{
			cout << user2 << "won" << endl;
			cout << "wanna play again?/y : yes,n : no ";
			cin >> choice;
			if (choice == 'y')
			{
		        	tic.push_back({0,0,0});
		        	tic.push_back({0,0,0});
               	        	tic.push_back({0,0,0});
			}	

		}



	} while(won != 0 && choice = n);

	return 0;
}
