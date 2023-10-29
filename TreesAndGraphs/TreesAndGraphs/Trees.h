#pragma once
#include <vector>
#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

class TreeNode {
public:
	int data;
	vector<TreeNode*> children;
	TreeNode* parent;
	TreeNode(int val) : data(val), parent(nullptr) {}
	TreeNode() : data(0), parent(nullptr) {}
};


class Tree {
public:
	
	//constructor
	Tree() {
		root = createRandomNode(nullptr);
	}

	TreeNode* root;
	vector<TreeNode*> Node_List;
	

	//generate random node
	TreeNode* createRandomNode(TreeNode* inputparent) {
		TreeNode* NewNode = new TreeNode();
		NewNode->data = rand() % 100;
		NewNode->parent = inputparent;
		return NewNode;
	}

	//rescieve random node
	TreeNode* getRandomNode(TreeNode* root){
		if (root == nullptr) {
			return nullptr;
		}

		
		vector<TreeNode*> nodes;
		stack<TreeNode*> stack;
		stack.push(root);

		while (!stack.empty()) {
			TreeNode* node = stack.top();
			stack.pop();
			nodes.push_back(node);

			for (TreeNode* child : node->children) {
				stack.push(child);
			}
		}

		
		if (!nodes.empty()) {
			int randomIndex = rand() % nodes.size();
			return nodes[randomIndex];
		}

		return nullptr; 
	}

	//generating tree
	void generateRandomTree(TreeNode* root, int currentDepth, int maxDepth) {
		if (currentDepth >= maxDepth -1) {
			return;
		}

		int numChildren = rand() % 4;

		for (int i = 0; i < numChildren; i++) {
			TreeNode* child = createRandomNode(root);
			root->children.push_back(child);

			generateRandomTree(child, currentDepth + 1, maxDepth);
		}
	}

	//prints tree
	void printTree(TreeNode* node, int depth) {
		if (node == nullptr) {
			return;
		}

		cout << "Node data: " << node->data << " (Depth: " << depth << ")" << endl;

		for (TreeNode* child : node->children) {
			printTree(child, depth + 1);
		}
	}

	

	//create nodes manually
	//TreeNode* newTreeNode(int data, TreeNode* parent) {
	//		TreeNode* node = new TreeNode(data);
	//		//node->data = data;
	//		node->parent = parent;
	//		Node_List.push_back(node);
	//		if (parent != nullptr) {
	//			parent->children.push_back(node);
	//		}
	//		return node;
	//}

	//DFS preorder
	void preorderTraversal(TreeNode* node) {
		if (node == nullptr) {
			return;
		}

		stack<TreeNode*> Stack;
		vector<int> Preorder;
		Stack.push(node);

		while (!Stack.empty()) {
			TreeNode* temp = Stack.top();
			Stack.pop();
			Preorder.push_back(temp->data);

			for (int i = temp->children.size() - 1; i >= 0; i--) {
				Stack.push(temp->children[i]);
			}
		}

		for (auto i : Preorder) {
			cout << i << " ";
		}
		cout << endl;
	}

	//return root
	TreeNode* getRoot() {
		return root;
	}


	//view parent of node
	void parentOfNode(TreeNode* node) {
		if (node != nullptr) {
			if (node->parent != nullptr) {
				cout << node->parent->data;
			}
			else {
				cout << "This is the root node.";
			}
		}
		else {
			cout << "Node is null.";
		}
		cout << endl;
	}


	//see children of node
	vector<TreeNode*> childrenOfNode(TreeNode* node) {
		vector<TreeNode*> children;
		if (node != nullptr) {
			for (const auto& child : node->children) {
				children.push_back(child);
			}
		}
		return children;
	}
	
	//check size of tree
	int Size(TreeNode* node) {
		if (node == nullptr) {
			return 0;
		}

		int size = 1; 

		for (TreeNode* child : node->children) {
			size += Size(child);
		}

		return size;
	}

	//print size
	void printTreeSize(TreeNode* root) {
		int treeSize = Size(root);
		cout << "The size of the tree is: " << treeSize << endl;
	}


	//get depth of random node
	int getDepthOfNode(TreeNode* root, TreeNode* node) {
		if (root == nullptr || node == nullptr) {
			return -1; // Node not found or invalid input.
		}
		if (root == node) {
			return 0; // Node is the root node.
		}

		for (const auto& child : root->children) {
			int childDepth = getDepthOfNode(child, node);
			if (childDepth != -1) {
				return 1 + childDepth; // Add 1 for the current level.
			}
		}

		return -1; // Node not found in the subtree.
	}

	//print said node
	void printNodeDepth(TreeNode* node, int depth) {
		if (depth != -1) {
			cout << "Depth of the node is: " << depth << endl;
		}
		else {
			cout << "Node is not in the tree." << endl;
		}
	}

	//get height of tree
	int getHeight(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		int maxHeight = 0;
		for (TreeNode* child : root->children) {
			int childHeight = getHeight(child);
			maxHeight = std::max(maxHeight, childHeight);
		}

		return maxHeight + 1;
	}

	//delete node
	void deleteNode(TreeNode*& root, int key) {
		
		if (root == nullptr)
			return;

		if (root->data == key) {
			for (auto child : root->children) {
				deleteNode(child, key);
			}
			delete root;
			root = nullptr;
			return;
		}

		int num_children = root->children.size();
		for (int i = 0; i < num_children; i++) {
			TreeNode* child = root->children[i];

			if (child->data == key) {
				
				int num_grandchildren = child->children.size();
				if (num_grandchildren) {
					root->children[i] = child->children[num_grandchildren - 1];
					child->children.pop_back();
				}
				
				else {
					root->children.erase(root->children.begin() + i);
				}

				for (auto grandchild : child->children) {
					deleteNode(grandchild, key);
				}
				delete child;
			}
			
			else {
				deleteNode(child, key);
			}
		}
	}



	bool isEmpty() {
		return root == nullptr;
	}

	//print if empty or not
	void printisEmpty() {
		if (isEmpty()) {
			cout << "The tree is empty" << endl;
		}
		else {
			cout << "The tree is not empty" << endl;
		}
	}


	bool isRoot(TreeNode* node) {
		return node->parent == nullptr;
	}

	void printRootStatus(TreeNode* node) {
		if (isRoot(node)) {
			cout << "This node is the root of the tree" << endl;
		}
		else {
			cout << "This node is not the root of the tree" << endl;
		}
	}

	bool isLeaf(TreeNode* node) {
		return node->children.empty();
	}

	void printLeafStatus(TreeNode* node) {
		if (isLeaf(node)) {
			cout << "this node is a leaf" << endl;
		}
		else {
			cout << "This node is not a leaf" << endl;
		}
	}
	
};
