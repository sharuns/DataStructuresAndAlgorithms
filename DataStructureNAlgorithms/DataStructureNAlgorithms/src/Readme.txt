
	Templated version of the TNode class and linked list class
//================== LOGS AND KNOWN BUGS =================================
/*
	= Current version works only with data types where the '=' operator is valid by default
	= Current version of template class works only with primitive data types
	= DisplayRec() method in Node.h class works only once because of the static ptr
	= Node class assumes that we are stroing only positive integers
	= Include Node.h before including logger.h in Node.cpp else produces build errors
*/