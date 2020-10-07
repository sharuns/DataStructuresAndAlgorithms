////////////////////////////////////////////////////////////////!
//!
//! File : Node.cpp
//!
//! Auther : Sharun Sashikumar
//!
//! Brief : Basic Linked List class implementation
//!
//! Date : Sep 2020
//!	
//!
////////////////////////////////////////////////////////////////!

//===============================================================
#pragma once
//===============================================================
//						INCLUDES
//===============================================================

#include<iostream>
#include "Node.h" //include Node.h before including logger.h

#ifdef ENABLE_LOG_PRINTS
#include "Logger.h"
#endif

//===============================================================
//
//===============================================================

//===============================================================
//						TYPEDEFs
//===============================================================

//===============================================================
//						  DATA
//===============================================================

//===============================================================
//
//===============================================================
 
using namespace linkedlist;

//===============================================================
//!
//! brief : Linked List parameterized constructor
//! 
//! args : array and number of elements
//!
LinkedList::LinkedList(int A[], int ele) {
	Node* last, * t;
	int i = 0;

	m_first = new Node;
	m_first->data = A[0];
	m_first->next = 0;
	last = m_first;

	for (int i = 1; i < ele; i++) {
		t = new Node;
		t->data = A[i];
		t->next = 0;
		last->next = t;
		last = t;
	}

}

//===============================================================
//!
//! brief : Linked List destructor
//! 
LinkedList :: ~LinkedList() {
	Node* p = m_first;
	while (m_first) {
		m_first = m_first->next;
		delete p;
		p = m_first;
	}
}

//===============================================================
//!
//! brief : Method to add values to a new node 
//! 
//! args : Node struct pointer
//!
void LinkedList::AddData(Node* ptr) {
	std::cout << "Enter value to be fed : ";
	std::cin >> ptr->data;
	std::cin.ignore(1000, '\n');
}

//===============================================================
//!
//! brief : Method to create LL with elements added at the end always  
//! 
//! args : --
//!
void LinkedList::CreateLinkedListAddEnd()
{
	char _addnode = 'y';
	Node* ptr = NULL;
	ptr = m_first;
	while ((_addnode == 'y')|| (_addnode == 'Y')) {

		Node* temp = new Node();
		temp->data = 0;
		temp->next = 0;

		AddData(temp);

		if (!ptr) {
			//if the LL is empty
			m_first = temp;
			ptr = m_first;
		}
		else {
			while (ptr->next) {
				ptr = ptr->next;
			}//We have reached the last node
			//Add the new node here
			ptr->next = temp;
		}

		std::cout << "Do you want to another element ? (y:Yes n:No)" << std::endl;
		std::cin >> _addnode;
		std::cin.ignore(1000, '\n');
	}
}

//===============================================================
//!
//! brief : Method to create a sorted Linked list
//! 
//! args : --
//!
void LinkedList::CreateLinkedSortedList() {
	
	char _addNode = 'y';
	Node* ptr = NULL;

	while ((_addNode == 'y') || (_addNode == 'Y')) {

		Node* temp = new Node();
		temp->data = 0;
		temp->next = 0;

		AddData(temp);

		ptr = m_first;

		//Add the incoming node according to data in a sorted manner		
		if ((!m_first)||(temp->data < m_first->data)) { //if first node or value smaller than the first node
			temp->next = m_first;
			m_first = temp;
			ptr = m_first;
		}
		else {
			while ((ptr->next)) {		//go through the entire linked list
				if (temp->data < ptr->next->data) { //inserting node in-between
					temp->next = ptr->next;
					ptr->next = temp;
					break;
				}
				else {
					ptr = ptr->next;
				}
				
			}
			if (!(ptr->next)) 
			{
				ptr->next = temp; //Last element condition
			}
		}

		std::cout << "Do you want to another element ? y:Yes n:No" << std::endl;
		std::cin >> _addNode;
		std::cin.ignore(1000, '\n');

	}

}

//===============================================================
//!
//! brief : Method to create a linked list with elements added in the front
//! 
//! args : --
//!
void LinkedList::CreateLinkedListAddFront() {

	char  _addNode = 'y';

	while ((_addNode == 'y') || (_addNode == 'Y')) {

		Node* temp = new Node();
		temp->data = 0;
		temp->next = 0;

		AddData(temp);
		//Adds the incoming node at the beganing itself		
		temp->next = m_first;
		m_first = temp;

		std::cout << "Do you want to another element ? y:Yes n:No" << std::endl;
		std::cin >> _addNode;
		std::cin.ignore(1000, '\n');

	}


}

//===============================================================
//!
//! brief : Method to Display the contents of the Linkedlist
//! 
//! args : --
//!
void LinkedList::Display()
{
	if (m_first == NULL) {
		#ifdef ENABLE_LOG_PRINTS
		_Log("Empty Linked List");
		#endif	
		return;
	}
	Node* ptr = m_first;
	while (ptr) {
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
}//end of Display

//===============================================================
//!
//! brief : Recursive display method for displaying elements of the linked list
//! 
//! args : --
//!
void LinkedList::DisplayRec() {

	static Node* ptr = m_first;
	if(ptr){ //terminating condition for the recursive loop
		std::cout << ptr->data << " ";
		ptr = ptr->next;
		DisplayRec();
	}
}

//===============================================================
//!
//! brief : Method to return the number of nodes present in the linked list
//!
//! args : --
//!
uint32_t LinkedList::CountNodes() {

	Node* _ptr = m_first;
	if (!_ptr){
	#ifdef ENABLE_LOG_PRINTS
		_Log("Empty Linked List");
	#endif
		return 0; //safeguard for empty linked list
	}
	uint32_t _count = 0;
	while (_ptr) {
		++_count;
		_ptr = _ptr->next;
	}
	return _count;
}

//===============================================================
//!
//! brief : Method to return the sum of nodes present in the linked list
//!
//! args : --
//!
uint32_t LinkedList::SumofNodes() {

	Node* _ptr = m_first;
	if (!_ptr) {
		#ifdef ENABLE_LOG_PRINTS
		std::cout << "Empty Linked List" << std::endl;
		#endif	
		return 0; //safeguard for empty linked list
	}
	uint32_t _sum = 0;
	while (_ptr) {
		_sum = _sum + _ptr->data;
		_ptr = _ptr->next;
	}
	return _sum;
}

//===============================================================
//!
//! brief : Method to find the maximum element in the linked list assuming that we store only positive integers
//!
//! args : --
//!
uint32_t LinkedList::MaximumElement() {

	Node* _ptr = m_first;
	if (!_ptr) {
		#ifdef ENABLE_LOG_PRINTS
			std::cout << "Empty Linked List" << std::endl;
		#endif	
		return 0; //safeguard for empty linked list
	}
	uint32_t _max = 0;
	while (_ptr) {
		if ((_ptr->data) > _max) {
			_max = _ptr->data;
			_ptr = _ptr->next;
		}
	}

	return _max;
}

//===============================================================
//!
//! brief : Method to search the passed element in the linked list
//! 
//! args : --
//!
Node* LinkedList::SearchElement(uint32_t _ele) {

	Node* _ptr = m_first;
	if (!_ptr) {
#ifdef ENABLE_LOG_PRINTS
		std::cout << "Empty Linked List" << std::endl;
#endif	
		return 0; //safeguard for empty linked list
	}
	
	while (_ptr) {
		if ((_ptr->data) == _ele) {
			return _ptr;
		}
			_ptr = _ptr->next;
	}

	return NULL;
} 

//===============================================================
//!
//! brief : Method to linear search a LL with Move to head for faster search, next time the same element is searched
//! 
//! args : --
//!
Node* LinkedList::SearchElementMtH(uint32_t _ele) {

	Node* _ptr = m_first;
	Node* _tail = _ptr;
	if (!_ptr) {
#ifdef ENABLE_LOG_PRINTS
		std::cout << "Empty Linked List" << std::endl;
#endif	
		return 0; //safeguard for empty linked list
	}

	while (_ptr) {
		if ((_ptr->data) == _ele) {
			_tail->next = _ptr->next;
			_ptr->next = m_first;
			m_first = _ptr;
			return _ptr;
		}
		_tail = _ptr;
		_ptr = _ptr->next;
	}

	return NULL;

}


//===============================================================
//!
//! brief : Method to delete a node at an given index
//!
//! args : uint32_t index
//!
//! return : success status
//!
int32_t LinkedList::DeleteNode(uint32_t index) {

	Node* _ptr, * _qtr = 0;
	int32_t _status = -1;		//failure case is -1 else positive vale
	if (index < 0 || index > CountNodes()) //invalid index
		return 0;

	//assuming index starts from 1
	if (index == 1) {
		_ptr = m_first;
		m_first = m_first->next;
		_status = _ptr->data;
		delete _ptr;
	}
	else {
		_ptr = m_first;

		for (int i = 0; i < index - 1; i++)
		{
			_qtr = _ptr;
			_ptr = _ptr->next;
		}
		_qtr->next = _ptr->next;
		_status = _ptr->data;
		delete _ptr;
	}
	return _status;
}

//===============================================================
//!
//! brief : Method to detect if the linked list is sorted
//!
//! args : --
//!
//! return : success status
//!
bool LinkedList::isSorted() {

	Node* _ptr = NULL;
	Node* _tail = NULL;
	if (m_first) {
		_tail = m_first;
		if (m_first->next)
			_ptr = m_first->next;
	}

	while (_ptr) {

		if (_ptr->data < _tail->data) {
			return false;
		}
		_tail = _ptr;
		_ptr = _ptr->next;
	}
	return true;
}

//===============================================================
//!
//! brief : Method to reverse the elements of a linked list using aux array
//!
//! args : --
//!
void LinkedList::ReverseLLEle() {

	Node* _ptr = m_first;
	uint32_t _cnt = CountNodes();
	if (_cnt) {
		uint32_t* _aux = new uint32_t[_cnt];

		for (uint32_t _nd = 0; _nd < _cnt; _nd++) {
			_aux[_nd] = _ptr->data;
			_ptr = _ptr->next;
		}

		_ptr = m_first;

		for (int32_t _id = _cnt; _id > 0; _id--) {
			_ptr->data = _aux[_id - 1];
			_ptr = _ptr->next;
		}

	}

}

//===============================================================
//!
//! brief : Method to reverse the elements of a linked list by reversing the links
//!
//! args : --
//!
void LinkedList::ReverseLLNode() {

	Node* _nxptr, *_rptr, *_curptr;
	_rptr = _curptr = _nxptr = NULL;
	
	//using sliding pointers

	if (m_first) {
		_nxptr = m_first;
		while (_nxptr) {
		
			_rptr = _curptr;
			_curptr = _nxptr;
			_nxptr = _nxptr->next;
			_curptr->next = _rptr;
		}
	}
	else {
#ifdef ENABLE_LOG_PRINTS
		std::cout << "Empty Linked List" << std::endl;
#endif	
		return; 
	}

	m_first = _curptr;

}

#if 0
void LinkedList::Insert(int index, int element) {

	Node* temp, * p = first;

	if (index < 0 || index > LengthLL())
		return;

	temp = new Node;
	temp->data = element;
	temp->next = 0;

	if (index == 0)
	{
		temp->next = first;
		first = temp;
	}
	else {
		for (int i = 0; i < index - 1; i++)
			p = p->next;

		temp->next = p->next;
		p->next = temp;
	}
}
#endif  

//===============================================================
//
//===============================================================

//===============================================================
//					END OF FILE
//===============================================================