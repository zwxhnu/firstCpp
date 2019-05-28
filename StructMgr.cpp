//
// Created by Apple on 2019-04-28.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;


typedef struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;

    friend ostream &operator<<(ostream &output, Books &book) {
        output << "title: " << book.title << "\t author: " << book.author << "\t subject: " << book.subject << endl;
        return output;
    }
} Books;

void printBook(Books book);

void print2Book(Books *book);

int main() {
    /**
     * The difference between class and struct
     * 1. the default member access in a class is private, whereas in a struct it is public.
     * 2. inheriting from class defaults to private, while inheriting from struct defaults to public.
     * 3. A class can define a template, but a struct cannot.
     */
    Books book1;
    Books book2;

    strcpy(book1.title, "C++");
    strcpy(book1.author, "Runoob");
    strcpy(book1.subject, "program language");
    book1.book_id = 12345;

    strcpy(book2.title, "Java");
    strcpy(book2.author, "Runoob");
    strcpy(book2.subject, "program language");
    book2.book_id = 12346;

    printBook(book1);
    printBook(book2);

    print2Book(&book1);
    print2Book(&book2);
    cout << book1 << endl;
    return 0;
}

void printBook(Books book) {
    cout << "title of book: " << book.title << endl;
    cout << "author of book: " << book.author << endl;
    cout << "subject of book: " << book.subject << endl;
}

void print2Book(Books *book) {
    cout << "title of book: " << book->title << endl;
    cout << "author of book: " << book->author << endl;
    cout << "subject of book: " << book->subject << endl;
}
