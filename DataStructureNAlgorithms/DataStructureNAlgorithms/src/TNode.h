////////////////////////////////////////////////////////////////!
//!
//! File : TNode.h
//!
//! Auther : Sharun Sashikumar
//!
//! Brief : Basic template Linked List class
//!
//! Date : Sep 2020
//!	
//!
////////////////////////////////////////////////////////////////!

//===============================================================

#pragma once
#define ENABLE_LOG_PRINTS

//===============================================================
//						INCLUDES
//===============================================================

#include<iostream>
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

namespace tlinkedlist {


	//===============================================================
	//!
	//! brief : template TNode struct
	//!
	template <class T>
	class TNode {
	public:
		T data;
		TNode* next;
	};  

	//===============================================================
	//!
	//! brief : template Linked List class
	//! 
	template<class T>
	class TLinkedList { //Works with primitive types only

		TNode<T>* m_first;

	protected:

		void AddData(TNode<T>*); //called from within the class APIs

	public:

		TLinkedList() : m_first(0) {}
		TLinkedList(T A[], int size);


		//create a linekd list by adding elements one by one maually.
		void CreateTLinkedListAddEnd();
		void CreateTLinkedListAddFront();
		//void CreateLinkedSortedList();  //For this version to work we must have a comparison handler for all types
		void Display();
		uint32_t CountOfNodes();
		TNode<T>* SearchElement(T ele);
		TNode<T>* SearchElementMtH(T ele);
		//uint32_t MaximumElement(); // for this method need to device a comparison strategy
		//void Insert(int index, int element);
		//int Delete(int index);
		//int LengthLL();

	};//TLikned List class 


	//===============================================================
	//!
	//! brief : Linked List parameterized constructor
	//! 
	//! args : array and number of elements
	//!
	template <class T>
	TLinkedList<T>::TLinkedList(T A[], int ele) {
		TNode* last, * t;
		int i = 0;

		m_first = new TNode;
		m_first->data = A[0];
		m_first->next = 0;
		last = m_first;

		for (int i = 1; i < ele; i++) {
			t = new TNode;
			t->data = A[i];
			t->next = 0;
			last->next = t;
			last = t;
		}

	}

	//===============================================================
	//!
	//! brief : Method to add values to a new node 
	//! 
	//! args : Node struct pointer
	//!
	template<class T>
	void TLinkedList<T>::AddData(TNode<T>* ptr) {

		std::cout << "Enter the data to be entered" << std::endl;
		std::cin >> 
		ptr->data;
		std::cin.ignore(1000, '\n');

	}

	//===============================================================
	//!
	//! brief : Templated Method to create LL with elements added at the end always
	//! 
	//! args : --
	//!
	template <class T>
	void TLinkedList<T>::CreateTLinkedListAddEnd()
	{
		char  _addNode = 'y';
		TNode<T>* _ptr = NULL;
		_ptr = m_first;
		while ((_addNode == 'y') ||( _addNode == 'Y')) {

			TNode<T>* _temp = new TNode<T>();
			_temp->data = 0;
			_temp->next = 0;

			AddData(_temp);

			if (!_ptr) {
				//if the LL is empty
				m_first = _temp;
				_ptr = m_first;
			}
			else {
				while (_ptr->next) {
					_ptr = _ptr->next;
				}//We have reached the last TNode
				//Add the new TNode here
				_ptr->next = _temp;
			}

			std::cout << "Do you want to another element ? (y:Yes n:No)" << std::endl;
			std::cin >> _addNode;
			std::cin.ignore(1000, '\n');

		}
	}

	//===============================================================
	//!
	//! brief : Templeted version for the createLinkedListFront method
	//! 
	//! args : --
	//!
	template<class T>
	void TLinkedList<T>::CreateTLinkedListAddFront() {

		bool _addNode = 'y';

		while ((_addNode == 'y') || (_addNode == 'Y')) {

			TNode<T>* _temp = new TNode<T>();
			_temp->data = 0;
			_temp->next = 0;

			AddData(_temp);
			//Adds the incoming node at the beganing itself		
			_temp->next = m_first;
			m_first = _temp;

			std::cout << "Do you want to another element ? y:Yes n:No";
			std::cin >> _addNode;
			std::cin.ignore(1000, '\n');

		}
	}// end of createLinkedListFront

	//===============================================================
	//!
	//! brief : Templated Display method to display the content
	//! 
	//! args : --
	//!
	template< class T>
	void TLinkedList<T>::Display() {

		if (m_first == NULL) {
			#ifdef ENABLE_LOG_PRINTS
			_Log("Empty Linked List");
			#endif
			return;
		}
		TNode<T>* _ptr = m_first;
		while (_ptr) {
			std::cout << _ptr->data << " ";
			_ptr = _ptr->next;
		}
		std::cout << std::endl;

	}

	//===============================================================
	//!
	//! brief : Template method to return the number of node in the linked list
	//! 
	//! args : --
	//!
	template<class T>
	uint32_t TLinkedList<T>::CountOfNodes() {

		TNode<T>* _ptr = m_first;
		if (!_ptr) {
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
	//! brief : Method to search the passed element in the linked list
	//! 
	//! args : --
	//!
	template<class T>
	TNode<T>* TLinkedList<T>::SearchElement(T _ele) {

			TNode<T>* _ptr = m_first;
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
	template<class T>
	TNode<T>* TLinkedList<T>::SearchElementMtH(T _ele) {

		TNode<T>* _ptr = m_first;
		TNode<T>* _tail = _ptr;
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

}// end of namespace tlinkedlist

//===============================================================
//
//===============================================================

//===============================================================
//					END OF FILE
//===============================================================