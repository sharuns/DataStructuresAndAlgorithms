////////////////////////////////////////////////////////////////!
//!
//! File : Node.h
//!
//! Auther : Sharun Sashikumar
//!
//! Brief : Basic Linked List class
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


namespace linkedlist {

//===============================================================
//!
//! brief : Node struct
//! 
	struct Node {
	public:
		int data;
		Node* next;

	}; 

//===============================================================
//!
//! brief : Linked List class
//! 
	class LinkedList {

	protected:

		void AddData(Node*);

	public:

		LinkedList() : m_first(0) {}
		LinkedList(int A[], int size);
		~LinkedList();

		void CreateLinkedListAddEnd();
		void CreateLinkedListAddFront();
		void CreateLinkedSortedList();
		void Display();
		void DisplayRec(); 
		uint32_t CountNodes();
		uint32_t SumofNodes();
		uint32_t MaximumElement(); //assuming we are storing only positive numbers
		Node* SearchElement(uint32_t ele);
		Node* SearchElementMtH(uint32_t ele);
		//TODO:
		//void Insert(int index, int element);
		//int Delete(int index);
		//int LengthLL();

	private:
		Node* m_first;

	};//end of Likned List class 

} //end of namespace
//===============================================================
//
//===============================================================

//===============================================================
//					END OF FILE
//===============================================================