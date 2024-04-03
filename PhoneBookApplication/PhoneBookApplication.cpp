// 
#include <iostream>
#include "PhoneRecord.h"

int main()
{
	PhoneBook myPhoneBook;
	myPhoneBook.addRecord("Asahan", "Gurk", "999-555-2031");
	myPhoneBook.addRecord("Adenekan", "Alfred", "999-555-1234");
	myPhoneBook.addRecord("Singh", "Kamaldeep", "213-555-1333");
	myPhoneBook.addRecord("Brown", "Charlie", "131-333-3131");

	std::cout << "Phone Records" << std::endl;
	myPhoneBook.displayRecords();
	
	myPhoneBook.sortRecordsByLastName();
	std::cout << "\n Phone Records after sorting by last name: " << std::endl;
	myPhoneBook.displayRecords();

	return 0;
}

