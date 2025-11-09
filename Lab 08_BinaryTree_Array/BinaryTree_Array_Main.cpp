#include <iostream>
#include<string>
#include "BinaryTree_Array.h"

using namespace std;

int main() {
    BinaryTree<string> tree(5);
    
    tree.setRoot("A");
    tree.setLeftChild("A", "B");
    tree.setRightChild("A", "C");
    tree.setRightChild("C", "F");
    tree.setLeftChild("B", "D");
    tree.setRightChild("B", "E");
    tree.setLeftChild("E", "I");
    tree.setLeftChild("I", "K");
    tree.setRightChild("E", "J"); 
    tree.setRightChild("D", "H");
    
    cout << "Tree display: ";
    tree.display();
    
    cout << "Size: " << tree.size() << endl;
    cout << "Leaves: " << tree.countLeaves() << endl;
    cout << "Is Full Binary Tree: " << tree.isFullBinaryTree() << endl;
    
    cout << "Preorder: ";
    tree.preorder(0);
    cout << endl;
    
    cout << "Iterative Inorder: ";
    tree.iterativeInorder();
    cout << "Ancestors are : ";
    tree.displayAncestors("F");
    cout << endl;
    cout << "Decendents are : ";
    tree.displayDescendents("A");
    cout << endl;
    cout << "Nodes in level are:";
    tree.getLevelNodes(1);
    cout << endl;
    cout << "Height is : ";
    cout << tree.getHeight();
    cout << endl;
    cout << " Node level is : ";
    cout << tree.findLevelOfNodes("F");
    cout << endl;
    cout << " Display Parathesis view: " << endl;
    tree.displayParenthesizedView();
    return 0;
}