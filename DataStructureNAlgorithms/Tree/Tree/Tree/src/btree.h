#pragma once

typedef struct Node {

	Node * rchild;
	int data;
	Node* lchild;
};

class mTree {

public :

	Node m_root;

	mTree();
	void create();
	void PreOrderTraverse(Node * node);
	void InOrderTraversal(Node* node);

};
