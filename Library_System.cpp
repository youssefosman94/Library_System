#include <iostream>
#include <cstdio>
#include <vector>

/* Library System */

void Menu(void);


class Book
{
private:
    std::string title;
    std::string author;
    int year;

public:
    Book(std::string title, std::string author, int year)
    {
        this->title = title;
        this->author = author;
        this->year = year;
    }
    std::string get_title(void) { return title; }
    std::string get_author(void) { return author; }
    int get_year(void) { return year; }
    void DisplayInfo(void)
    {

        std::cout << "Title: " << title << ", Author: " << author << ", Year: " << year << "\n";
    }
};
class LibraryCatalog
{
private:
    std::vector<Book> books;

public:
    void AddBook(std::string t, std::string a, int y)
    {
        Book temp(t, a, y);
        books.push_back(temp);
    }
    void SearchByAuthor(std::string a)
    {
        bool flag = false;
        for (auto var : books)
        {
            if (var.get_author() == a)
            {
                flag = true;
                var.DisplayInfo();
                break;
            }
        }
        if (!flag)
        {
            std::cout << "this Book not Found\n";
        }
    }
    void DisplayCatalog(void)
    {
        for (auto var : books)
        {
            var.DisplayInfo();
            std::cout << "------------------------------------\n";
        }
    }
};
int main()
{
    int choise;
    LibraryCatalog catalog;
    std::string title, author;
    int year;
    while (true)
    {
        Menu();
        std::cin >> choise;
        switch (choise)
        {
        case 1:
            std::cout << "Enter the Title of the book: ";
            std::cin.ignore();
            getline(std::cin, title);
            std::cout << "enter the author of the book: ";
            getline(std::cin, author);
            std::cout << "enter the year of the book: ";
            std::cin >> year;
            catalog.AddBook(title, author, year);
            break;

        case 2:
            std::cout << "enter the author of the book: ";
            std::cin.ignore();
            getline(std::cin, author);
            catalog.SearchByAuthor(author);
            break;

        case 3:
            catalog.DisplayCatalog();
            break;

        case 4:
            exit(0);

        default:
            std::cout << "please enter coorect choise....!\n";
        }
    }
}
void Menu(void)
{
    std::cout << "Menu:\n"
              << "1. Add a book\n"
              << "2. Search by Author\n"
              << "3. Display catalog\n"
              << "4. Exit\n";
    std::cout << "Enter Your Choise: ";
}
