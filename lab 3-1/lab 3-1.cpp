#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct Book
{
    string title = "";
    string author = "";
    double price = 0.0;
    int releaseDate = 0;
};

void display_menu()
{
    cout << "MENU" << endl
        << "a - Add a new book to the library" << endl
        << "i - Information about a specific book" << endl
        << "d - Display all authors stored" << endl
        << "x - Exit" << endl;

}

int main()
{
    cout << "Library Manager" << endl << endl;

    display_menu();

    vector<Book> book_list;

    char choice;

    do
    {
        Book book;

        cout << "\nEnter a command: ";
        cin >> choice;

        string temp;
        bool found = false;

        switch (choice)
        {
            case 'A':
            case 'a':
                cout << "Enter a title for the new book: ";

                cin.ignore();
                getline(cin, book.title);

                cout << "Enter author for the new book: ";
                getline(cin, book.author);

                cout << "Enter price of the book: ";
                cin >> book.price;

                cout << "Enter year of release: ";
                cin >> book.releaseDate;

                book_list.push_back(book);

                cout << "New book has been added successfully to the library..." << endl;
                break;

            case 'D':
            case 'd':
                cout << left << setw(4) << "AUTHORS" << endl;
                cout << "--------------------" << endl;

                for (int i = 0; i < book_list.size(); i++)
                {
                    cout << setw(4) << book_list[i].author << endl;
                }
                break;

            case 'I':
            case 'i':

                cout << "Enter author of the book you would like to know more about: ";

                cin.ignore();
                getline(cin, temp);

                cout << "INFO" << endl;
             
                for (int i = 0; i < book_list.size(); i++)
                {
                    if (temp == book_list[i].author)
                    {
                        
                            cout << "------------" << endl
                            << book_list[i].title << endl
                            << book_list[i].author << endl
                            << book_list[i].price << endl
                            << book_list[i].releaseDate << endl;

                        found = true;
                    }
                }

                if (found == false)
                {
                    cout << "No book was found under that author name!" << endl << endl;
                }
                break;

            case 'X':
            case 'x':
                cout << "Bye!" << endl;
                break;    
        }


    } while (tolower(choice) != 'x');
}

