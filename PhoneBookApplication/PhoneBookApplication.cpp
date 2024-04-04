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
	myPhoneBook.addRecord("Ronaldo", "Cristiano", "122-333-4443");
	myPhoneBook.addRecord("Benzema", "Karim", "112-563-5443");
	myPhoneBook.addRecord("Messi", "Lionel", "421-563-4364");
	myPhoneBook.addRecord("Bellingham", "Jude", "144-255-6541");
	myPhoneBook.addRecord("Carvajal", "Daniel", "153-633-6783");
	myPhoneBook.addRecord("Mbappe", "Kylian", "757-439-2929");
	myPhoneBook.addRecord("Wayne", "Bruce", "131-141-4144");
	myPhoneBook.addRecord("kent", "Clark", "132-424-5555");

	std::cout << "Phone Records" << std::endl;
	myPhoneBook.displayRecords();
	
	myPhoneBook.sortRecordsByLastName();
	std::cout << "\n Phone Records after sorting by last name: " << std::endl;
	myPhoneBook.displayRecords();

	std::string searchLastName = "Adenekan";
	std::cout << "\nSearching for records with last name: " << searchLastName << std::endl;
	myPhoneBook.retrieveByLastName(searchLastName);

	std::string nameToDelete = "Messi";
	std::cout << "\nDeleting records with last name: " << nameToDelete << std::endl;
	myPhoneBook.deleteByLastName(nameToDelete);

	std::cout << "\nPhone records after deletion:" << std::endl;
	myPhoneBook.displayRecords();

	myPhoneBook.loadFromFile("C:\\Users\\domin\\OneDrive\\Desktop\\School\\Winter 2024\\DSA\\Source Codes\\PhoneBookApplication\\phonebook.txt");
	myPhoneBook.saveToFile("C:\\Users\\domin\\OneDrive\\Desktop\\School\\Winter 2024\\DSA\\Source Codes\\PhoneBookApplication\\phonebook.txt");

	std::cout << "\nContents of phone book after loading: " << std::endl;
	myPhoneBook.displayRecords();

	return 0;
}

