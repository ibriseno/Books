#include "Book.h"
#include <iostream>
#include <string>
#include <vector>    /*-----Defines the vector container class-----*/

using namespace std;

int main()
{
	vector<Book> bookList;
        /*------------(bookID, Author, Book)------------*/
        /*Any book with different ID but with same author or book name is possible.*/
        /*Two books with the same ID are not possible in the same bookList*/
	Book myBook(111, "Dr. Seuss", "The Cat in the Hat");
	Book myBook2(112, "Dr. Seuss", "Harry Potter And The Chamber Of Secrets");
	Book myBook3(113, "JK Rowling", "Harry Potter And The Prisoner Of Azkaban");
	Book myBook4(111, "JK Rowling", "Harry Potter And The Goblet Of Fire");
     
	
	/*Calling addBook to check for any repeated unique ID's*/
	
	addBook(bookList, myBook);
	addBook(bookList, myBook2);
	addBook(bookList, myBook3);
	addBook(bookList, myBook4);
	
	cout<<"Books: "<<bookList.size()<<endl;
	
	for(int index=0 ; index< bookList.size(); index++)
	{
		cout<<"\nBook ID: "<<bookList[index].bookID;
		cout<<"\nAuthor: "<<bookList[index].author;
		cout<<"\nBook Name: "<<bookList[index].bookName;
		cout<<"\n";
	}
	
	Book* backupList;
	
	int backupSize = backupBookList(bookList, backupList);
	
	cout<<"\n\nBackup Size: "<<backupSize<<endl;
	
	for(int index=0 ; index< backupSize; index++)
	{
		cout<<"\nBook ID: "<<bookList[index].bookID;
		cout<<"\nAuthor: "<<bookList[index].author;
		cout<<"\nBook Name: "<<bookList[index].bookName;
		cout<<"\n";
	}
	
	destructBackupList(backupList);
	
	return 0;
}