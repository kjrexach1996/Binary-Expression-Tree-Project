// Binary Expression Tree Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryExpressionTree.h"

int main()
{
    BinaryExpressionTree tree;
    tree.buildFromPostfix("2 2 +");
    cout << "Result: " << tree.evaluateTree(tree.getRoot()) << endl;
    cout << "Infix: " << tree.infixTraversal(tree.getRoot()) << endl;
    cout << "Postfix: " << tree.postfixTraversal(tree.getRoot()) << endl;
}
