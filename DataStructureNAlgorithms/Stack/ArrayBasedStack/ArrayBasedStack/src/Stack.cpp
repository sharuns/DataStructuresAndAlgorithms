////////////////////////////////////////////////////////////////!
//!                                                             	
//! File : Stack.cpp
//!
//! Auther : Sharun Sashikumar
//!
//! Brief : Stack class implementation
//!
//! Date : Oct 2020
//!	
//!
////////////////////////////////////////////////////////////////!

//===============================================================

//===============================================================
//                        INCLUDES
//===============================================================
#include<iostream>
#include"Stack.h"

//===============================================================
//
//===============================================================

//===============================================================
//                        TYPEDEFs
//===============================================================

//===============================================================
//                          DATA
//===============================================================

//===============================================================
//
//===============================================================

//===============================================================
//!
//! brief : Constructor
//! 
//! args : 
//!
AStack::AStack() {

	std::cout << "Enter Stack size" << std::endl;
	std::cin >> m_stack._size;

	std::cin.ignore(1000, '\n');

	m_stack._ptr = new uint32_t[m_stack._size];
	m_stack._top = EMPTY_STACK;
}

//===============================================================
//!
//! brief : Destructor
//! 
//! args : 
//!
AStack::~AStack() {

	delete[] m_stack._ptr;
}

//===============================================================
//!
//! brief : Push
//! 
//! args : 
//!
void AStack::Push(int _data) {

	if (m_stack._top == m_stack._size - 1) {
		
#ifdef ENABLE_LOG_PRINT
		_Log("Stack Overflow");
#endif
		return;
	}
	else{
		m_stack._top++;
		m_stack._ptr[m_stack._top] = _data;
	}
}

//===============================================================
//!
//! brief : Pop
//! 
//! args : 
//!
uint32_t AStack::Pop() {

	if (m_stack._top == EMPTY_STACK) {

#ifdef ENABLE_LOG_PRINT
		_Log("Stack Empty");
#endif
		return 0;
	}
	else {
		int _temp = m_stack._ptr[m_stack._top];
		m_stack._ptr[m_stack._top] = NULL;
		m_stack._top--;
		return _temp;
	}
}

//===============================================================
//!
//! brief : Peek
//! 
//! args : 
//!
uint32_t AStack::Peek(uint32_t _pos) {
	
	if (_pos > m_stack._size) {
#ifdef ENABLE_LOG_PRINTS
		_Log("Invalid position");
#endif
	}
	else
	return (m_stack._ptr[m_stack._top - _pos + 1]);
}

//===============================================================
//!
//! brief : StackTop
//! 
//! args : 
//!
uint32_t AStack::StackTop() {

	if (m_stack._top == EMPTY_STACK) {

#ifdef ENABLE_LOG_PRINT
		_Log("Stack Empty");
#endif
		return 0;
	}
	else {
		return (m_stack._ptr[m_stack._top]);
	}

}

//===============================================================
//!
//! brief : isFull
//! 
//! args : 
//!
bool AStack::isFull() {

	return (m_stack._top == m_stack._size-1);
}

//===============================================================
//!
//! brief : isEmpty
//! 
//! args : 
//!
bool AStack::isEmpty() {
	return (m_stack._top == EMPTY_STACK);
}

//===============================================================
//
//===============================================================

//===============================================================
//                        END OF FILE
//===============================================================