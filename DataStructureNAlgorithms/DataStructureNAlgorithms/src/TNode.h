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
		int32_t DeleteNode(uint32_t index);
		bool isSorted();
		void ReverseLLEle();
		void ReverseLLNode();
		TNode<T>* getFirstNode() { return m_first; }
		void ReverseLLRec(TNode<T>*, TNode<T>* tail = NULL);
		void ConcatenateLL(TNode<T>* _second);
		TNode<T>* MergeLL(TNode<T>* _secondLL); //assuming sorted linked list
		bool isLooped();
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


	//===============================================================
	//!
	//! brief : Method to delete a node at an given index
	//!
	//! args : uint32_t index
	//!
	//! return : success status
	//!
	template <typename T>
	int32_t TLinkedList<T>::DeleteNode(uint32_t index) {

		TNode<T>* _ptr, * _qtr = 0;
		int32_t _status = -1;		//failure case is -1 else positive vale
		if (index < 0 || index > CountOfNodes()) //invalid index
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
	template<typename T>
	bool TLinkedList<T>::isSorted() {

		TNode<T>* _ptr = NULL;
		TNode<T>* _tail = NULL;
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
	template<typename T>
	void TLinkedList<T>::ReverseLLEle() {

		TNode<T>* _ptr = m_first;
		uint32_t _cnt = CountOfNodes();
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
	template<typename T>
	void TLinkedList<T>::ReverseLLNode() {

		TNode<T>* _nxptr, * _rptr, * _curptr;
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


	//===============================================================
	//!
	//! brief : Method to reverse the elements of a linked list by reversing the links via recursion
	//!
	//! args : first node, empty node pointer
	//!
	template<typename T>
	void TLinkedList<T>::ReverseLLRec(TNode<T>* _first, TNode<T>* _tail) {

		if (_first) {
			ReverseLLRec(_first->next, _first);
			_first->next = _tail;
		}
		else {
			m_first = _tail;
		}
	}


	//===============================================================
	//!
	//! brief : Method to concatenate two linked list keeping the first node address of second linked list 
	//!
	//! args : second LL
	//!
	template<typename T>
	void TLinkedList<T>::ConcatenateLL(TNode<T>* _second) {
		TNode<T>* _first = m_first;
		if (!_first) {
#ifdef ENABLE_LOG_PRINTS
			std::cout << "Empty Linked List" << std::endl;
#endif
			return;
		}
		while (_first->next) {
			_first = _first->next;
		}
		_first->next = _second;
	}

	//===============================================================
	//!
	//! brief : Method to merge two sorted linked list
	//!
	//! args : second linked list
	//!
	//! returns : first node of merged linked list
	template<typename T>
	TNode<T>* TLinkedList<T>::MergeLL(TNode<T>* _secondll) {

		TNode<T>* _firstll, * _mergell,* _mergefirstNode;
		_mergefirstNode = NULL;


		if ((!m_first) || (!_secondll)) {
#ifdef ENABLE_LOG_PRINTS
			std::cout << "Empty Linked List detected" << std::endl;
#endif
			return NULL;
		}

		_firstll = m_first;
		_mergell = NULL;

		if (_firstll->data <= _secondll->data) {
			_mergell = _firstll;
			_mergefirstNode = _mergell;
			_firstll = _firstll->next;
			_mergell->next = NULL;
		}
		else {
			_mergell = _secondll;
			_mergefirstNode = _mergell;
			_secondll = _secondll->next;
			_mergell->next = NULL;
		}

		while ((_firstll) && (_secondll)) {

			if (_firstll->data <= _secondll->data) {
				_mergell->next = _firstll;
				_mergell = _firstll;
				_firstll = _firstll->next;
				_mergell->next = NULL;
			}
			else {
				_mergell->next = _secondll;
				_mergell = _secondll;
				_secondll = _secondll->next;
				_mergell->next = NULL;
			}
		}

		if (_firstll) {
			_mergell->next = _firstll;
		}
		else {
			_mergell->next = _secondll;
		}

		return _mergefirstNode;
	}

	//===============================================================
	//!
	//! brief : Method to find if a linked list is looped
	//!
	//! args : --
	//!
	//! returns : status if looped or not
	template<typename T>
	bool TLinkedList<T>::isLooped() {

		TNode<T>* _first, * _second;
		if (!m_first) {
#ifdef ENABLE_LOG_PRINTS
			std::cout << "Empty Linked List" << std::endl;
#endif
			return false;
		}

		_first = _second = m_first;
		do {

			_first = _first->next;
			_second = _second->next;
			_first = _first ? _first->next : _first;

		} while (_first && _second && _first != _second);

		return (_first == _second);
	}

}// end of namespace tlinkedlist

//===============================================================
//
//===============================================================

//===============================================================
//					END OF FILE
//===============================================================