#include <iostream>
#include "BinaryTree_Node.h"

using namespace std;

int main() {
    BinaryTree<string> tree;
    // Build the tree
    tree.setRoot("A");
    tree.setLeftChild("A", "B");
    tree.setRightChild("A", "C");
    tree.setLeftChild("B", "D");
    tree.setRightChild("B", "E");
    tree.setLeftChild("C", "F");
    tree.setRightChild("C", "G");
    
    // Display tree information
    cout << "=== Binary Tree Information ===" << endl;
    cout << "Size: " << tree.size() << endl;
    cout << "Height: " << tree.height() << endl;
    cout << "Leaves: " << tree.countLeaves() << endl;
    cout << "Internal Nodes: " << tree.countInternalNodes() << endl;
    
    cout << "\n=== Tree Properties ===" << endl;
    cout << "Is Full: " << tree.isFullBinaryTree() << endl;
    cout << "Is Complete: " << tree.isCompleteBinaryTree() << endl;
    cout << "Is Balanced: " << tree.isBalanced() << endl;
    
    cout << "\n=== Traversals ===" << endl;
    tree.display();
    
    cout << "\n=== Tree Structure ===" << endl;
    tree.printTree();
    
    cout << "\n=== Node Information ===" << endl;
    cout << "Is 'D' a leaf? " << tree.isLeaf("D") << endl;
    cout << "Does 'B' have left child? " << tree.hasLeftChild("B") << endl;
    cout << "Left child of 'B': " << tree.getLeftChild("B") << endl;
    
    cout << "\n=== Path to Root ===" << endl;
    cout << "Path from D to root: ";
    tree.printPathToRoot("D");
    
    cout << "\n=== LCA ===" << endl;
    cout << "LCA of D and E: " << tree.findLCA("D", "E") << endl;
    cout<< "Node  is"<< tree.isInternalNode("D");
    cout << endl;
     cout<< "Node  is"<< tree.isExternalNode("D");
    cout << endl;
    cout << "Node sibling is " << tree.findNodeSiblings("D");
    cout << endl;
    cout << "Tree Height is:  " << tree.height();
    cout << endl;
    cout << "Tree parenthesizedview is:   ";
    tree.displayParenthesizedView();
    BinaryTree<string> tree2;
    tree2.setRoot("A");
    tree2.setLeftChild("A", "D");
    tree2.setRightChild("A", "F");
    tree2.setLeftChild("D", "U");
    tree2.setRightChild("D", "I");
    tree2.setLeftChild("F", "N");
    tree2.setRightChild("F", "P");
    cout << "tree 2 is:" << endl;
    tree2.display();
    cout << "After equalling tree 1 and tree2 ";
    cout << endl;

    tree = tree2;
    tree.display();
    BinaryTree<string> tree3(tree2);

    cout << "tree 3 copy constructor of tree 2";
    cout << endl;
    tree3.display();
    cout << "Tree 1 after mirror"<<endl;
    tree.mirrorTree();
    tree.display();
    return 0;
}