#include "Book.h"
#include <iostream>

Book::Book(int ID, std::string authorName, std::string book)
{
	bookID = ID;
	author = authorName;
	bookName = book;
}

/* default constructor that calls the parameterized constructor */
Book::Book()
{
	bookID = 0;
	author = "";
	bookName = "";
}
/*This function will add newBook to bookList if it is not already in bookList.*/
void addBook(std::vector<Book> &bookList, Book &newBook)
{
	bool isPresent = false;
	
	for(int index = 0; index < bookList.size(); index++)
	{
		if(bookList[index].bookID == newBook.bookID)
		{
			isPresent = true;
			break;
		}
	}
	
	if(!isPresent)
	{
		bookList.push_back(newBook);
	}
}
/*This function copies all the books stored in bookList to a dynamic array
 *  managed by the backupList pointer and returns the size of this dynamic 
 * array*/
int backupBookList( std::vector<Book> &bookList, Book* &backupList)
{
	int vectorSize = bookList.size();
	
	backupList = new Book[vectorSize];
	
	for(int index = 0; index < bookList.size(); index++)
	{
		backupList[index] = bookList[index];
	}
	
	return vectorSize;
}
/*This function returns the space occupied by the pointee of backupList.*/
void destructBackupList(Book* &backupList)
{
       
	std::cout<<"\nFreeing memory..."<<std::endl;
	delete[] backupList;
	std::cout<<"Memory Freed."<< std::endl;
}