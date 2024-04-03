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
};
#endif 
