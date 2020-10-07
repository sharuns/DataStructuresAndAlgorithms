////////////////////////////////////////////////////////////////!
//!
//! File : Node.h
//!
//! Auther : Sharun Sashikumar
//!
//! Brief : Basic Linked List class driver
//!
//! Date : Sep 2020
//!	
//!
////////////////////////////////////////////////////////////////!

//===============================================================

// Use a define to compile a version of ndoe class 

#define _USE_TEMPLATE_CLASS
//#define _USE_NODE_CLASS

//===============================================================

//===============================================================
//						INCLUDES
//===============================================================

#include<iostream>
#include"Node.h"
#include"TNode.h"


#ifdef _USE_TEMPLATE_CLASS
using namespace tlinkedlist;
#endif
#ifdef _USE_NODE_CLASS
using namespace linkedlist;
#endif

//===============================================================
//
//===============================================================

//===============================================================
//						TYPEDEFS
//===============================================================

//===============================================================
//						  DATA
//===============================================================

//===============================================================
//
//===============================================================

//===============================================================
//!
//! 
//! main driver
//!
//!
int main() {
	
#ifdef _USE_TEMPLATE_CLASS
	
	//****************************** TLinkedList class driver
	TLinkedList<uint32_t> tobj;
	tobj.ReverseLLEle();
	tobj.CreateTLinkedListAddEnd();
	tobj.Display();
	std::cout << std::endl;

	if (tobj.SearchElement(23))
		std::cout << "Found" << std::endl;
	else
		std::cout << "Not Found" << std::endl;

	//tobj.DeleteNode(2);
	//tobj.Display();

	if (tobj.isSorted())
		std::cout << "Linked list sorted " << std::endl;
	else std::cout << "Linked list not sorted " << std::endl;

	tobj.ReverseLLNode();

	tobj.Display();

#endif 
#ifdef _USE_NODE_CLASS

	//===============================================================
	LinkedList obj;	
	obj.Display();					  //Empty Linked list
	obj.CreateLinkedListAddEnd();
	obj.Display();
	std::cout << std::endl;
	
	if (obj.SearchElementMtH(23))
		std::cout << "Found" << std::endl;
	else
		std::cout << "Not Found" << std::endl;

	obj.DisplayRec();
	std::cout << std::endl;
	std::cout << "Sum of Node : " << obj.SumofNodes() << std::endl;

	//obj.DeleteNode(1);
	//obj.Display();

	if(obj.isSorted())
	std::cout << "Linked list sorted " << std::endl;
	else std::cout << "Linked list not sorted " << std::endl;


	obj.ReverseLLNode();
	obj.Display();
	
#endif

	std::cout << std::endl 
	<< "Press Enter to exit" <<  std::endl;
	std::cin.get();

}
//===============================================================
//
//===============================================================

//===============================================================
//					END OF FILE
//===============================================================
