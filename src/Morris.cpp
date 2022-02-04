#include<iostream>

class Node
{
public:
	int m_data;
	Node* left;
	Node* right;

	Node() : m_data(0), left(nullptr), right(nullptr) {}
	Node(int data) : m_data(data), left(nullptr), right(nullptr) {}
	Node(int data, Node* left, Node* right) : m_data(data), left(left), right(right) {}

};

void Morris(Node* root)
{
	if (root == nullptr)
		return;
	Node* cur = root;
	Node* mostright = nullptr;

	while (cur != nullptr)
	{
		mostright = cur->left;
		if (mostright != nullptr)//cur has left child
		{
			while (mostright->right != nullptr && !(mostright->right == cur))//mr right child not null and not point to cur, movie right
			{
				mostright = mostright->right;
			}
			if (mostright->right == nullptr)
			{
				mostright->right = cur;
				cur = cur->left;
				continue;//back to while !cur
			}
			else
			{
				mostright->right = nullptr;
			}
		}
		std::cout << cur->m_data << std::endl;
		cur = cur->right;		
	}
}

void printTree(Node* root)
{
	if (root != nullptr){
		std::cout << root->m_data << std::endl;
		if (root->left != nullptr) printTree(root->left);
		if (root->right != nullptr) printTree(root->right);
	}
	else return;
}

int Main()
{
	Node* h1 = new Node(5);
	h1->left = new Node(4);
	h1->right = new Node(6);
	h1->left->left = new Node(7);
	h1->left->right = new Node(8);
	Morris(h1);
	//printTree(h1);
	system("pause");
	return 0;
}

