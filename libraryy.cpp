#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string book = "undefined";
    string author = "undefined";
    string genre = "undefined";
    int publishYear = 2000;
    int pages = 0;
    int ID = 0;
public:
    Book(string b, string a, string g, int y, int p, int id)
        : book(b), author(a), genre(g), publishYear(y), pages(p), ID(id) {}

    int getID() const {
        return ID;
    }

    void print() const {
        cout << "Book's name: " << book << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
        cout << "Year: " << publishYear << endl;
        cout << "Pages: " << pages << endl;
        cout << "ID: " << ID << endl;
    }
};

class Library {
private:
    vector<Book> data;
public:
    void addBook(const Book& s) {
        data.push_back(s);
        cout << "Book added successfully!" << endl;
    }

    void remove(int Id) {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->getID() == Id) {
                data.erase(it);
                cout << "Book removed successfully." << endl;
                return;
            }
        }
        cout << "Book with ID " << Id << " not found." << endl;
    }

    void search(int Id) const {
        for (const Book& s : data) {
            if (s.getID() == Id) {
                cout << "Book found successfully:" << endl;
                s.print();
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void viewAll() const {
        if (data.empty()) {
            cout << "Library is empty." << endl;
            return;
        }
        for (const Book& s : data) {
            s.print();
            cout << "-----------------------" << endl;
        }
    }
};

int main() {
    Library ob;
    int choice = 0;
    bool exit = true;

    do {
        cout << "/---- Welcome to the Library ----/" << endl;
        cout << "1: Add a book" << endl;
        cout << "2: Delete a book" << endl;
        cout << "3: View library" << endl;
        cout << "4: Search for a book" << endl;
        cout << "5: Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string name, author, genre;
                int year, pages, id;

                cout << "Book's name: ";
                getline(cin, name);
                cout << "Author's name: ";
                getline(cin, author);
                cout << "Genre: ";
                getline(cin, genre);
                cout << "Publish year: ";
                cin >> year;
                cout << "Pages: ";
                cin >> pages;
                cout << "ID: ";
                cin >> id;
                cin.ignore();

                Book newBook(name, author, genre, year, pages, id);
                ob.addBook(newBook);
                break;
            }
            case 2: {
                int id;
                cout << "Enter ID of book to delete: ";
                cin >> id;
                ob.remove(id);
                break;
            }
            case 3:
                ob.viewAll();
                break;
            case 4: {
                int id;
                cout << "Enter book ID to search: ";
                cin >> id;
                ob.search(id);
                break;
            }
            case 5:
                cout << "Goodbye!" << endl;
                exit = false;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (exit);

    return 0;
}

