#include<iostream>
#include<string>
#include<vector>
#include<algorithm>//sort头文件 
using namespace std;


class Book {
	private:
		int id;
		string isbn;
		string name;
		string author;
		string publisher;
		string publishTime;
		double price;
		int pageNum;
		string intro;
		int borrowCount;
	public:
		Book(int id,string isbn,string name,string author,string publisher,string publishTime,double price,int pageNum,string intro):
			id(id),isbn(isbn),name(name),author(author),publisher(publisher),publishTime(publishTime),price(price),pageNum(pageNum),intro(intro),
			borrowCount(0) {}

		int getId()const {
			return id;
		}
		string getIsbn()const {
			return isbn;
		}
		string getName()const {
			return name;
		}
		string getAuthor()const {
			return author;
		}
		string getPublisher()const {
			return publisher;
		}
		string getPublisherTime()const {
			return publishTime;
		}
		double getPrice()const {
			return price;
		}
		int getPageNum()const {
			return pageNum;
		}
		string getIntro()const {
			return intro;
		}
		int getBorrowCount()const {
			return borrowCount;
		}
		void incBorrowCount() {
			borrowCount++;
		}
};
class User {
	protected://
		string account;
		string password;
		string role;

	public:
		User(string account,string password,string role):account(account),password(password),role(role) {}

		string getAccount()const {
			return account;
		}
		string getPassword()const {
			return password;
		}
		string getRole()const {
			return role;
		}
		void changePassword(string newPwd) {
			password=newPwd;
		}
};
class Admin:public User {
	public:
		Admin(string account,string password):
			User(account,password,"管理员") {}
		void addBook(vector<Book>&books,const Book&book) {
			books.push_back(book);//vector的pushback方法
		}
		void deleteBook(vector<Book>&books,int id) {
			for(auto it=books.begin(); it!=books.end(); ++it) { //兄弟们,这里不懂了
				if(it->getId()==id) {
					books.erase(it);
					break;
				}
			}
		}
};
class Reader:public User {
	private:
		vector<int>borrowedBookIds;
	public:
		Reader(string account,string password):
			User(account,password,"读者") {}
		void borrowBook(int bookId) {
			borrowedBookIds.push_back(bookId);   //unknown
		}
		void returnBook(int bookId) {
			for(auto it=borrowedBookIds.begin(); it!=borrowedBookIds.end(); ++it) {
				if(*it==bookId) {
					borrowedBookIds.erase(it);
					break;
				}
				else
				{
					++it;
				}
			}
		}
		void showBorrowedRecords() const 
		{
				cout<<"借阅记录:";
				for(int id:borrowedBookIds)
				{cout<<id<<" ";}
				cout<<endl;
			}
		};
        vector<Book> searchByName(const vector<Book>&books,const string & name)
		{
			vector<Book>res;
			for(const auto&b:books)
			{
				if(b.getName()==name)
				res.push_back(b);
			}
			sort(res.begin(),res.end(),[](const Book&a,const Book&b)
			{return a.getName()<b.getName();}
			);//sort函数
			return res;
		};
		vector<Book> searchByAuthor(const vector<Book>&books,const string&author)
		{
			vector<Book>res;
			for(const auto& b:books)
			{
				if(b.getAuthor()==author)
				{
					res.push_back(b);
				}
			}
			 sort(res.begin(),res.end(),[](const Book&a,const Book&b)
			{return a.getName()<b.getName();}
			);//sort函数
			return res; 
		};
	vector<Book>
	topBorrowed(const vector<Book>& books)
	{
        vector<Book> temp=books;
		sort(temp.begin(),temp.end(),[](const Book& a,const Book&b)
		{return a.getBorrowCount()>b.getBorrowCount();}
		);
		
		if(temp.size()>10)
		temp.resize(10);
		return temp;
	}
	//不会写 (添加图书) 
//	void initBooks(vector<Book>& books)
//	{
//		books.push_back(Book(1,"9787115512345","C++ Primer","Stanley B.Lippman","人民邮电出版社","2021-05-01",129.0,980,"C++经典教程"));
//	}
//		
int main() {
//	vector<Book> books;
//	vector<User> users;

	return 0;
}
