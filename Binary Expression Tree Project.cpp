// Binary Expression Tree Project.cpp : The purpose of this project is to create a binary 
// expression tree out of a provided postfix expression. All leaf nodes are expected to 
// represent the operands of the expression, while all non-leaf nodes will contain all operators.
// The two child nodes of a parent node will have an operation performed on them--this operation
// will depend on which operator is stored in the parent node. The program will be able to 
// traverse the tree to evaluate the expression and also rebuild the expression in both infix and
// postfix form. 

#include <iostream>
#include "BinaryExpressionTree.h"

int main()
{
    //Test tree 1
    BinaryExpressionTree tree;
    tree.buildFromPostfix("5 3 +");
    cout << "Postfix: " << tree.getPostfix() << endl;
    cout << "Result: " << tree.evaluateTree(tree.getRoot()) << endl;
    cout << "Rebuilt Infix: " << tree.infixTraversal(tree.getRoot()) << endl;
    cout << "Rebuilt Postfix: " << tree.postfixTraversal(tree.getRoot()) << endl;
    cout << endl;

    //Test tree 2
    BinaryExpressionTree tree2;
    tree2.buildFromPostfix("8 2 - 3 +");
    cout << "Postfix: " << tree2.getPostfix() << endl;
    cout << "Result: " << tree2.evaluateTree(tree2.getRoot()) << endl;
    cout << "Rebuilt Infix: " << tree2.infixTraversal(tree2.getRoot()) << endl;
    cout << "Rebuilt Postfix: " << tree2.postfixTraversal(tree2.getRoot()) << endl;
    cout << endl;

    //Test tree 3
    BinaryExpressionTree tree3;
    tree3.buildFromPostfix("5 3 8 * +");
    cout << "Postfix: " << tree3.getPostfix() << endl;
    cout << "Result: " << tree3.evaluateTree(tree3.getRoot()) << endl;
    cout << "Rebuilt Infix: " << tree3.infixTraversal(tree3.getRoot()) << endl;
    cout << "Rebuilt Postfix: " << tree3.postfixTraversal(tree3.getRoot()) << endl;
    cout << endl;

    //Test tree 4
    BinaryExpressionTree tree4;
    tree4.buildFromPostfix("6 2 / 3 +");
    cout << "Postfix: " << tree4.getPostfix() << endl;
    cout << "Result: " << tree4.evaluateTree(tree4.getRoot()) << endl;
    cout << "Rebuilt Infix: " << tree4.infixTraversal(tree4.getRoot()) << endl;
    cout << "Rebuilt Postfix: " << tree4.postfixTraversal(tree4.getRoot()) << endl;
    cout << endl;

    //Test tree 5
    BinaryExpressionTree tree5;
    tree5.buildFromPostfix("5 8 + 3 -");
    cout << "Postfix: " << tree5.getPostfix() << endl;
    cout << "Result: " << tree5.evaluateTree(tree5.getRoot()) << endl;
    cout << "Rebuilt Infix: " << tree5.infixTraversal(tree5.getRoot()) << endl;
    cout << "Rebuilt Postfix: " << tree5.postfixTraversal(tree5.getRoot()) << endl;
    cout << endl;

    //Test tree 6
    BinaryExpressionTree tree6;
    tree6.buildFromPostfix("5 3 + 8 *");
    cout << "Postfix: " << tree6.getPostfix() << endl;
    cout << "Result: " << tree6.evaluateTree(tree6.getRoot()) << endl;
    cout << "Rebuilt Infix: " << tree6.infixTraversal(tree6.getRoot()) << endl;
    cout << "Rebuilt Postfix: " << tree6.postfixTraversal(tree6.getRoot()) << endl;
    cout << endl;

    //Test tree 7
    BinaryExpressionTree tree7;
    tree7.buildFromPostfix("8 2 3 * + 6 -");
    cout << "Postfix: " << tree7.getPostfix() << endl;
    cout << "Result: " << tree7.evaluateTree(tree7.getRoot()) << endl;
    cout << "Rebuilt Infix: " << tree7.infixTraversal(tree7.getRoot()) << endl;
    cout << "Rebuilt Postfix: " << tree7.postfixTraversal(tree7.getRoot()) << endl;
    cout << endl;

    //Test tree 8
    BinaryExpressionTree tree8;
    tree8.buildFromPostfix("5 3 8 * + 2 /");
    cout << "Postfix: " << tree8.getPostfix() << endl;
    cout << "Result: " << tree8.evaluateTree(tree8.getRoot()) << endl;
    cout << "Rebuilt Infix: " << tree8.infixTraversal(tree8.getRoot()) << endl;
    cout << "Rebuilt Postfix: " << tree8.postfixTraversal(tree8.getRoot()) << endl;
    cout << endl;

    //Test tree 9
    BinaryExpressionTree tree9;
    tree9.buildFromPostfix("8 2 + 3 6 * -");
    cout << "Postfix: " << tree9.getPostfix() << endl;
    cout << "Result: " << tree9.evaluateTree(tree9.getRoot()) << endl;
    cout << "Rebuilt Infix: " << tree9.infixTraversal(tree9.getRoot()) << endl;
    cout << "Rebuilt Postfix: " << tree9.postfixTraversal(tree9.getRoot()) << endl;
    cout << endl;

    //Test tree 10
    BinaryExpressionTree tree10;
    tree10.buildFromPostfix("5 3 + 8 2 / -");
    cout << "Postfix: " << tree10.getPostfix() << endl;
    cout << "Result: " << tree10.evaluateTree(tree10.getRoot()) << endl;
    cout << "Rebuilt Infix: " << tree10.infixTraversal(tree10.getRoot()) << endl;
    cout << "Rebuilt Postfix: " << tree10.postfixTraversal(tree10.getRoot()) << endl;
    cout << endl;

    //Catching an error using an empty binary tree
    try {
        BinaryExpressionTree emptyTree;
        cout << emptyTree.getRoot() << endl;
    }
    catch (runtime_error& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    cout << endl;

    //Catching an error using a tree with an empty stack or not full enough stack
    try {
        BinaryExpressionTree errorTree;
        errorTree.buildFromPostfix("2 2 + -");
    }
    catch (runtime_error& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    cout << endl;

    //Catching an error with an invalid character in expression
    try {
        BinaryExpressionTree errorTree;
        errorTree.buildFromPostfix("3 4 @ 7 +");
    }
    catch (runtime_error& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    cout << endl;

    //Catching an error with an extra integer in expression, resets root of tree to nullptr
    try {
        BinaryExpressionTree errorTree;
        errorTree.buildFromPostfix("5 3 + 8 2 / - 4");
    }
    catch (runtime_error& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    cout << endl;

    //Catching an error with division by 0
    try {
        BinaryExpressionTree errorTree;
        errorTree.buildFromPostfix("5 0 /");
        cout << errorTree.evaluateTree(errorTree.getRoot()) << endl;
    }
    catch (runtime_error& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    cout << endl;

    return 0;
}