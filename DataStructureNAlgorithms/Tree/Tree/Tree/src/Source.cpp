#include<iostream>
#include "btree.h"

int main() {

	std::cout << "Hi" << std::endl;
	mTree test;
	test.create();
	std::cout << &(test.m_root) << std::endl;
	test.InOrderTraversal(&(test.m_root));

}