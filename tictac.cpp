//used some chatgpt to be real...it is obvious from the comments and other but you know
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string name1 = "undefined";
string name2 = "undefined";
int won = 0;

class User {
private:
    string user1 = "player 1";
    string user2 = "player 2";
public:
    User(string n1, string n2) {
        user1 = n1;
        user2 = n2;
    }
    string getUsr() {
        return user1;
    }
    string getUsrt() {
        return user2;
    }
};

void setUser() {
    cout << "Player 1: ";
    getline(cin, name1);
    cout << "Player 2: ";
    getline(cin, name2);
}

void print(vector<vector<char>>& tic) {
    cout << "\nCurrent Board:\n";
    for (auto& row : tic) {
        for (char cell : row) {
            cout << (cell == ' ' ? '-' : cell) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void check(vector<vector<char>>& tic) {
    char one = 'x';
    char two = 'o';

    for (int i = 0; i < 3; i++) {
        // rows
        if (tic[i][0] == one && tic[i][1] == one && tic[i][2] == one) {
            won = 1;
            return;
        }
        if (tic[i][0] == two && tic[i][1] == two && tic[i][2] == two) {
            won = 2;
            return;
        }

        // columns
        if (tic[0][i] == one && tic[1][i] == one && tic[2][i] == one) {
            won = 1;
            return;
        }
        if (tic[0][i] == two && tic[1][i] == two && tic[2][i] == two) {
            won = 2;
            return;
        }
    }

    // diagonals
    if (tic[0][0] == one && tic[1][1] == one && tic[2][2] == one) {
        won = 1;
        return;
    }
    if (tic[0][0] == two && tic[1][1] == two && tic[2][2] == two) {
        won = 2;
        return;
    }
    if (tic[0][2] == one && tic[1][1] == one && tic[2][0] == one) {
        won = 1;
        return;
    }
    if (tic[0][2] == two && tic[1][1] == two && tic[2][0] == two) {
        won = 2;
        return;
    }
}

bool isFull(vector<vector<char>>& tic) {
    for (auto& row : tic) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

int main() {
    setUser();
    User ob1(name1, name2);
    char choice = 'y';

    do {
        vector<vector<char>> tic(3, vector<char>(3, ' ')); // reset board
        won = 0;

        while (won == 0 && !isFull(tic)) {
            print(tic);

            // --- Player 1 turn ---
            int row, column;
            cout << "Player " << ob1.getUsr() << "'s turn (X)\n";
            cout << "Choose a row (0-2): ";
            cin >> row;
            cout << "Choose a column (0-2): ";
            cin >> column;

            if (row < 0 || row > 2 || column < 0 || column > 2) {
                cout << "Invalid position!\n";
                continue;
            }
            if (tic[row][column] != ' ') {
                cout << "Position already taken!\n";
                continue;
            }
            tic[row][column] = 'x';
            check(tic);
            if (won != 0 || isFull(tic)) break;

            print(tic);

            // --- Player 2 turn ---
            cout << "Player " << ob1.getUsrt() << "'s turn (O)\n";
            cout << "Choose a row (0-2): ";
            cin >> row;
            cout << "Choose a column (0-2): ";
            cin >> column;

            if (row < 0 || row > 2 || column < 0 || column > 2) {
                cout << "Invalid position!\n";
                continue;
            }
            if (tic[row][column] != ' ') {
                cout << "Position already taken!\n";
                continue;
            }
            tic[row][column] = 'o';
            check(tic);
        }

        print(tic);

        if (won == 1) {
            cout << ob1.getUsr() << " wins!\n";
        } else if (won == 2) {
            cout << ob1.getUsrt() << " wins!\n";
        } else {
            cout << "It's a draw!\n";
        }

        cout << "Wanna play again? (y = yes, n = no): ";
        cin >> choice;
        cin.ignore(); // clear newline from input buffer

    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}

