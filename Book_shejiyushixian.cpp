#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

class Book {
private:
    float price;
    string shelf_id;
    int id;
public:
    static int Num;
    Book();
    friend ostream& operator<<(ostream& os, const Book& book);
    friend istream& operator>>(istream& is, Book& book);
    friend bool comp(const Book& book1, const Book& book2);
};

int Book::Num = 0;

Book::Book() {
    price = 0;
    shelf_id = "";
    Num++;
    id = Num;
}

istream& operator>>(istream& is, Book& book) {
    getline(is, book.shelf_id);
    is >> book.price;
    is.ignore();
    return is;
}

ostream& operator<<(ostream& os, const Book& book) {
    os << "ID: " << book.id 
       << " Shelf_ID: " << left << setw(18) << book.shelf_id
       << "Price: " << book.price;
    return os;
}

bool comp(const Book& book1, const Book& book2) {
    if (book1.price != book2.price) {
        return book1.price > book2.price;
    } else {
        return book1.id < book2.id;
    }
}

int main() {
    int n;
    cin >> n;
    cin.get();
    
    Book *library = new Book[n];
    for (int i = 0; i < n; i++) {
        cin >> library[i];
    }
    
    sort(library, library + n, comp);
    
    for (int i = 0; i < n; i++) {
        cout << library[i] << endl;
    }
    
    delete[] library;
    return 0;
}
