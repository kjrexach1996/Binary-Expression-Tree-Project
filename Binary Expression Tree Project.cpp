// Binary Expression Tree Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryExpressionTree.h"

int main()
{
    //Test tree 1
    BinaryExpressionTree tree;
    tree.buildFromPostfix("2 2 +");
    cout << "Postfix: " << tree.getPostfix() << endl;
    cout << "Result: " << tree.evaluateTree(tree.getRoot()) << endl;
    cout << "Rebuilt Infix: " << tree.infixTraversal(tree.getRoot()) << endl;
    cout << "Rebuilt Postfix: " << tree.postfixTraversal(tree.getRoot()) << endl;
    cout << endl;

    //Test tree 2
    BinaryExpressionTree newTree;
    newTree.buildFromPostfix("8 2 - 3 +");
    cout << "Postfix: " << newTree.getPostfix() << endl;
    cout << "Result: " << newTree.evaluateTree(newTree.getRoot()) << endl;
    cout << "Rebuilt Infix: " << newTree.infixTraversal(newTree.getRoot()) << endl;
    cout << "Rebuilt Postfix: " << newTree.postfixTraversal(newTree.getRoot()) << endl;
    cout << endl;

    //Catching an error with an empty stack
    try {
        BinaryExpressionTree anotherTree;
        anotherTree.buildFromPostfix("2 2 + -");
    }
    catch (runtime_error& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    cout << endl;

    //Test tree 3
    BinaryExpressionTree againTree;
    againTree.buildFromPostfix("10 20 30 40 - * + 50 /");
    cout << "Postfix: " << againTree.getPostfix() << endl;
    cout << "Result: " << againTree.evaluateTree(againTree.getRoot()) << endl;
    cout << "Rebuilt Infix: " << againTree.infixTraversal(againTree.getRoot()) << endl;
    cout << "Rebuilt Postfix: " << againTree.postfixTraversal(againTree.getRoot()) << endl;
    cout << endl;

    //Catching an error with an invalid character
    try {
        BinaryExpressionTree anotherTree;
        anotherTree.buildFromPostfix("3 4 @ 7 +");
    }
    catch (runtime_error& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    cout << endl;
}


