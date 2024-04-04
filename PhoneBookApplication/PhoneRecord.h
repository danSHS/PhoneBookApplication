#pragma once
#ifndef PHONERECORD_H
#define PHONERECORD_H
#define PHONEBOOK_H

#include <string>
#include <iostream>

class Phonerecord {

public:
	std::string lastName;
	std::string firstName;
	std::string phoneNumber;
	Phonerecord* prev;
	Phonerecord* next;

	Phonerecord(std::string ln, std::string fn, std::string pn)
		: lastName(ln), firstName(fn), phoneNumber(pn), prev(nullptr), next(nullptr) {}

};

class PhoneBook {
private:
	Phonerecord* head;
	Phonerecord* tail;

	Phonerecord* getMiddle(Phonerecord* start) {
		if (!start) return start;
		Phonerecord* slow = start;
		Phonerecord* fast = start->next;
		while (fast && fast->next) 
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	Phonerecord* merge(Phonerecord* first, Phonerecord* second) {
		if (!first) return second;
		if (!second) return first;

		Phonerecord duummy("", "", "");
		Phonerecord* tail = &duummy;
		duummy.next = first;

		while (first != nullptr && second != nullptr) {
			if (first->lastName.compare(second->lastName) < 0) {
				tail->next = first;
				first->prev = tail;
				first = first->next;
			}
			else {
				tail->next = second;
				second->prev = tail;
				second = second->next;
			}
			tail = tail->next;
		}

		
		if (first == nullptr) {
			tail->next = second;
			if (second) second->prev = tail;
		}
		else {
			tail->next = first;
			if (first) first->prev = tail;
		}

		
		Phonerecord* head = duummy.next;
		if (head) head->prev = nullptr; 
		return head;
	}

	Phonerecord* mergeSort(Phonerecord* head) {
		if (!head || !head->next) return head;

		Phonerecord* middle = getMiddle(head);
		Phonerecord* nextOfMiddle = middle->next;

		middle->next = nullptr;

		Phonerecord* left = mergeSort(head);
		Phonerecord* right = mergeSort(nextOfMiddle);

		return merge(left, right);
	}

public:
	PhoneBook() : head(nullptr), tail(nullptr) {}

	~PhoneBook() {
		Phonerecord* current = head;
		while (current != nullptr) {
			Phonerecord* next = current->next;
			delete current;
			current = next;
		}
	}

	void addRecord(std::string lastname, std::string firstname, std::string phoneNumber) {
		Phonerecord* newRecord = new Phonerecord(lastname, firstname, phoneNumber);
		if (head == nullptr) {
			head = newRecord;
			tail = newRecord;
		}
		else
		{
			tail->next = newRecord;
			newRecord->prev = tail;
			tail = newRecord;
		}
	}

	void displayRecords() const {
		Phonerecord* current = head;
		while (current != nullptr) {
			std::cout << "Name: " << current->lastName << "," << current->firstName << " Phone Number: " << current->phoneNumber << std::endl;
			current = current->next;
		}
	}

	void sortRecordsByLastName() {
		if (!head || !head->next) return;

		head = mergeSort(head);

		Phonerecord* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		tail = temp;

		Phonerecord* current = head;
		Phonerecord* previous = nullptr;
		while (current != nullptr) {
			current->prev = previous;
			previous = current;
			previous = current;
			current = current->next;
		}
	}
	void retrieveByLastName(const std::string& specificLastName) const {
	Phonerecord* current = head;
	bool found = false;

	while (current != nullptr) {
		if (current->lastName == specificLastName) {
			std::cout << "Name: " << current->lastName << ", " << current->firstName << " - Phone Number: " << current->phoneNumber << std::endl;
			found = true;
		}
		current = current->next;
	}
	if (!found) {
		std::cout << "No records found for last name: " << specificLastName << std::endl;
	}
}
	void deleteByLastName(const std::string& specificLastName) {
		Phonerecord* current = head;
		bool found = false;

		while (current != nullptr) {
			if (current->lastName == specificLastName) {
				found = true;

				if (current->prev) {
					current->prev->next = current->next;
				}
				else {
					head = current->next;
				}

				if (current->next) {
					current->next->prev = current->prev;
				}
				else {
					tail = current->prev;
				}

				Phonerecord* temp = current->next;
				delete current;
				current = temp;
			}
			else {
				current = current->next;
			}
		}

		if (!found) {
			std::cout << "No records found for last name: " << specificLastName << std::endl;
		}
	}

	void loadFromFile(const std::string& filename) {
		std::ifstream file(filename);
		std::string line;
		while (std::getline(file, line)) {
			std::stringstream linestream(line);
			std::string lastName, firstName, phoneNumber;

			std::getline(linestream, lastName, ',');
			std::getline(linestream, firstName, ',');
			std::getline(linestream, phoneNumber);

			if (!lastName.empty() && !firstName.empty() && !phoneNumber.empty()) {
				addRecord(lastName, firstName, phoneNumber);
			}
		}
		file.close();
	}
	void saveToFile(const std::string& filename) const {
		std::ofstream file(filename);
		Phonerecord* current = head;
		while (current != nullptr) {
			file << current->lastName << "," << current->firstName << "," << current->phoneNumber << std::endl;
			current = current->next;
		}
		file.close();
	}
};
#endif 
