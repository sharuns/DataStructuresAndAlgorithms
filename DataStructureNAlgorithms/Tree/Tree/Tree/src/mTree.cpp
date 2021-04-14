#include<iostream>
#include<queue>
#include "btree.h"


mTree::mTree() {
	m_root.rchild = NULL;
	m_root.lchild = NULL;
}

void mTree::create() {

	std::queue<Node*> tQ;

	std::cout << "Enter root value" << std::endl;
	std::cin >> m_root.data;

	std::cin.ignore(1000, '\n');

	tQ.push(&m_root);

	while (!tQ.empty()) {
	
		Node *tmp = tQ.front(); //as pop does not return the content popped 
		tQ.pop();
		int tdata;


		std::cout << "Enter Value for left child of " << tmp->data << std::endl;
		std::cin >> tdata;

		std::cin.ignore(1000, '\n');

		if (tdata) {
			Node* temp = new Node;
			temp->data = tdata;
			temp->lchild = temp->rchild = 0;
			tmp->lchild = temp;
			tQ.push(temp);

		}
		tdata = 0;
		std::cout << "Enter Value for Right child of " << tmp->data << std::endl;
		std::cin >> tdata;

		std::cin.ignore(1000, '\n');

		if (tdata) {
			Node* temp = new Node;
			temp->data = tdata;
			temp->rchild = temp->rchild = 0;
			tmp->rchild = temp;
			tQ.push(temp);

		}

	
	}


}

void mTree::PreOrderTraverse(Node * node) {
	
	if (node) {
		std::cout << node->data << " ";
		PreOrderTraverse(node->lchild);
		PreOrderTraverse(node->rchild);
	}
}

void mTree::InOrderTraversal(Node* node) {
	if (node) {
		
		PreOrderTraverse(node->lchild);
		std::cout << node->data << " ";
		PreOrderTraverse(node->rchild);
	}

}