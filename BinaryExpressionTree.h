

#pragma once
#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

using namespace std;

//Node in the binary tree
struct TreeNode
{
	string data; //Contains postfix expression
	TreeNode* leftNode; //Left child node
	TreeNode* rightNode; //Right child node

	//Constructor
	TreeNode(string data)
		: data(data), leftNode(nullptr), rightNode(nullptr) {}
};

class BinaryExpressionTree
{
private:
	string postfix; //Stores postfix expression
	TreeNode* root; //Root node of binary tree
public:

	//Returns a binary tree representing the provided postfix expression
	void buildFromPostfix(string expr)
	{
		postfix = expr; //Stores provided postfix expression
		stack<TreeNode*> st; //Stack of pointers to tree nodes
		string token; //Represents operator or operand in postfix
		istringstream ss(expr); //Tokenizes postfix

		//While the expression is tokenizable
		while (ss >> token)
		{
			//If the token is an integer
			if (isdigit(token[0]))
			{
				TreeNode* newNode = new TreeNode(token); //Create a new TreeNode holding the integer
				st.push(newNode); //Push the new node onto the stack
			}
			//If the token is an operator
			else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
			{
				TreeNode* newNode = new TreeNode(token); //Create a new TreeNode holding the operator

				//If the stack is not empty and there are 2 operands to perform an operation
				if (st.size() >= 2)
				{
					//Top node of the stack becomes right child node of new node
					TreeNode* right = st.top(); 
					st.pop();
					newNode->rightNode = right;

					//Top node of the stack becomes left child node of new node
					TreeNode* left = st.top();
					st.pop();
					newNode->leftNode = left;

					//New node with child nodes is pushed to the stack
					st.push(newNode); 
				}
				else
					throw runtime_error("Not enough operands!"); //Stack is empty or missing operands
			}
			else
				throw runtime_error("Invalid token found in expression!"); //Occurs when invalid token is found in postfix.
		}
		//If the stack is not empty after adding all new nodes
		if (!st.empty())
		{
			//Node on top of stack containing all other nodes becomes root node of binary tree
			root = st.top();
			st.pop();

			//If the stack is not empty after tree is created
			if (!st.empty())
			{
				root = nullptr; //Resets root to nullptr
				throw runtime_error("Too many operands in expression! Resetting root to null.");
			}
		}
	}

	//Evaluates the postfix expression through the tree 
	float evaluateTree(TreeNode* rootNode)
	{
		if (rootNode->leftNode == nullptr && rootNode->rightNode == nullptr) //If the root node is a leaf node with no left or right nodes
			return stod(rootNode->data); //Convert the integer string and return
		else
		{
			//Recursively call the function passing the left and right nodes
			float leftOperand = evaluateTree(rootNode->leftNode);
			float rightOperand = evaluateTree(rootNode->rightNode);

			//Performs operation on the two operands from the leaf nodes depending on operator
			if (rootNode->data == "+")
				return leftOperand + rightOperand;
			else if (rootNode->data == "-")
				return leftOperand - rightOperand;
			else if (rootNode->data == "*")
				return leftOperand * rightOperand;
			else if (rootNode->data == "/")
			{
				if (rightOperand == 0)
					throw runtime_error("Cannot divide by 0."); //Prints error statement when attempting division by 0
				return leftOperand / rightOperand;
			}
		}
	}

	//Uses inorder traversal to rebuild infix expression (Left -> Root -> Right)
	string infixTraversal(TreeNode* rootNode) 
	{
		string infix; //Holds final infix expression

		if (rootNode->leftNode == nullptr && rootNode->rightNode == nullptr) //If the root node is a leaf node with no left or right nodes
			return rootNode->data; //Return the data of the current node
		else
		{
			if ((rootNode->data == "+" || rootNode->data == "-")) //Adds parentheses to maintain rules of order of operations
			{
				infix += "(";
				infix += infixTraversal(rootNode->leftNode) + " "; //Visits left node first
				infix += rootNode->data + " "; //Visits root
				infix += infixTraversal(rootNode->rightNode); //Visits right node last
				infix += ")";
			}
			else
			{
				infix += infixTraversal(rootNode->leftNode) + " "; //Visits left node first
				infix += rootNode->data + " "; //Visits root
				infix += infixTraversal(rootNode->rightNode); //Visits right node last
			}
		}
		return infix;
	}

	//Uses postorder traversal to rebuild postfix expression (Left -> Right -> Root)
	string postfixTraversal(TreeNode* root) 
	{
		string postfix; //Holds final postfix expression

		if (root->leftNode == nullptr && root->rightNode == nullptr) //If the root node is a leaf node with no left or right nodes
			return root->data; //Return the data of the current node
		else
		{
			postfix += postfixTraversal(root->leftNode) + " "; //Visits left node first
			postfix += postfixTraversal(root->rightNode) + " "; //Visits right node 
			postfix += root->data; //Visits root last
		}
		return postfix;
	}

	//Checks if the tree is empty, returns true if empty
	bool isEmpty()
	{
		if (root == nullptr)
			return true;
		return false;
	}

	//Used to delete all nodes of the tree
	void clearTree(TreeNode* rootNode)
	{
		if (!rootNode)
			return;
		clearTree(rootNode->leftNode);
		clearTree(rootNode->rightNode);
		delete rootNode;
	}

	//Returns root of binary tree, prints error if tree is empty
	TreeNode* getRoot()
	{
		if (root == nullptr)
			throw runtime_error("Tree is empty!");
		return root;
	}

	//Returns the current postfix expression
	string getPostfix()
	{
		return postfix;
	}

	//Constructor
	BinaryExpressionTree(TreeNode* root = nullptr)
		: root(root) {}

	//Destructor, calls clearTree function to delete all nodes
	~BinaryExpressionTree()
	{
		clearTree(root);
	}
};