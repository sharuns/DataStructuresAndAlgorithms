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
#ifdef _USE_TEMPLATE_CLASS
template< class T>
#endif
void DisplayLinkedList(
#ifdef _USE_TEMPLATE_CLASS
	TNode<T>*
	#endif
#ifdef _USE_NODE_CLASS
	Node*
#endif
	_ptr) 
{

	if (_ptr == NULL) {
#ifdef ENABLE_LOG_PRINTS
		_Log("Empty Linked List");
#endif
		return;
	}

	while (_ptr) {
		std::cout << _ptr->data << " ";
		_ptr = _ptr->next;
	}
	std::cout << std::endl;
}
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
	TNode<uint32_t>* ret = NULL;
	tobj.ReverseLLEle();
	tobj.CreateTLinkedListAddEnd();
	tobj.Display();
	std::cout << std::endl;

	/*if (tobj.SearchElement(23))
		std::cout << "Found" << std::endl;
	else
		std::cout << "Not Found" << std::endl;
		*/

	//tobj.DeleteNode(2);
	//tobj.Display();

	if (tobj.isSorted())
		std::cout << "Linked list sorted " << std::endl;
	else std::cout << "Linked list not sorted " << std::endl;

	//tobj.ReverseLLNode();
	//tobj.ReverseLLRec(tobj.getFirstNode());

	TLinkedList<uint32_t> t2obj;
	t2obj.CreateTLinkedListAddEnd();

	if (t2obj.isSorted()) {
		std::cout << "Linked list sorted " << std::endl;
		t2obj.Display();
		ret = tobj.MergeLL(t2obj.getFirstNode());
	}
	else std::cout << "Linked list not sorted " << std::endl;

	//tobj.ConcatenateLL(t2obj.getFirstNode());
	DisplayLinkedList(ret);

#endif 
#ifdef _USE_NODE_CLASS

	//===============================================================
	LinkedList obj;
	Node* ret;
	obj.Display();					  //Empty Linked list
	obj.CreateLinkedSortedList();
	obj.Display();
	std::cout << std::endl;
	
	/*if (obj.SearchElementMtH(23))
		std::cout << "Found" << std::endl;
	else
		std::cout << "Not Found" << std::endl;
		*/
	//obj.DisplayRec();
	//std::cout << std::endl;
	//std::cout << "Sum of Node : " << obj.SumofNodes() << std::endl;

	//obj.DeleteNode(1);
	//obj.Display();

	if(obj.isSorted())
	std::cout << "Linked list sorted " << std::endl;
	else std::cout << "Linked list not sorted " << std::endl;


	//obj.ReverseLLNode();
	//obj.ReverseLLRec(obj.getFirstNode());
	LinkedList obj2;
	obj2.CreateLinkedSortedList();
	//obj2.ConcatenateLL(obj.getFirstNode());
	ret = obj.MergeLL(obj2.getFirstNode());
	DisplayLinkedList(ret);
	
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
