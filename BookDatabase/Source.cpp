#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

struct Book {
	string title;
	string author;
};

string lowerString(string input) {
	int length = input.length();
	char myArray[1024];

	strcpy_s(myArray, input.c_str());

	for (size_t i = 0; i < sizeof(myArray) / sizeof(myArray[0]); i++) {
		myArray[i] = tolower(myArray[i]);
	}
	string output(myArray);

	return output;
}

int main() {
	vector<Book> list;
	int choice;

	cout << "Book Managment Database\n"
		<< "------------------------\n";

	while (true) {
		cout << "\nWhat would you like to do?\n"
			<< "(Input corresponding number only)\n\n";
		cout << "1. Add a book\n"
			<< "2. List all books\n"
			<< "3. Edit a book's information\n"
			<< "4. Delete a book from the system\n"
			<< "5. Exit program\n\n";
		cout << "*NOTE: All book titles, authors are CASE SENSITIVE;\n\n";

		cin >> choice;
		cin.ignore();

		switch (choice) {
			case 1: {
				list.push_back(Book());
				cout << "\nWhat is the name of the book? ";
				getline(cin, list.back().title);
				cout << "\nWho is the author of the book? ";
				getline(cin, list.back().author);
				cout << "\n";
				system("pause");
				break;
			}
			case 2: {
				cout << "\n";
				for (size_t i = 0; i < list.size(); i++) {
					cout << "Title: " << list[i].title << ". Author: " << list[i].author << ".\n";
				}
				cout << "\n";
				system("pause");
				break;
			}
			case 3: {
				string bookTitle;
				string choice;
				cout << "What is the title of the book you would like to edit? ";
				getline(cin, bookTitle);
				bookTitle = lowerString(bookTitle);
				cout << "Would like to edit the title or the author of the book? (title/author) ";
				getline(cin, choice);
				choice = lowerString(choice);

				for (size_t i = 0; i < list.size(); i++) {
					string loweredTitle = lowerString(list[i].title);
					if (loweredTitle == bookTitle) {
						if (choice == "title") {
							cout << "\nThe current title of the book is " << list[i].title
								<< ". What would you like to change it to? ";
							getline(cin, list[i].title);
							cout << "\nThe new name of the book is " << list[i].title << "\n";
						}
						else if (choice == "author") {
							cout << "The current author of the book is " << list[i].author
								<< ". What would you like to change it to? ";
							getline(cin, list[i].author);
							cout << "\nThe new author of the book is " << list[i].author << "\n";
						}
					}
					break;
				}
				cout << "/n";
				system("pause");
				break;
			}
			case 4: {
				string bookToDelete;
				cout << "\nWhat is the title of the book you want to delete? ";
				getline(cin, bookToDelete);
				bookToDelete = lowerString(bookToDelete);

				for (size_t i = 0; i < list.size(); i++) {
					string loweredTitle = lowerString(list[i].title);
					if (loweredTitle == bookToDelete) {
						list.erase(list.begin() + i);
						break;
					}
				}
				cout << "\n";
				system("pause");
				break;
			}
			case 5: {
				char choice;
				cout << "Are you sure you want to exit? (Y / N) ";
				cin >> choice;
				cin.ignore();

				if (tolower(choice) == 'y') {
					cout << "Goodbye!\n\n";
					system("pause");
					exit(0);
				}
				break;
			}
			break;
		}
	}
}