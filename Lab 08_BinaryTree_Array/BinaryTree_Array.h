#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <limits>
#include <stdexcept>
#include <algorithm>

using namespace std;

template <typename T>
class BinaryTree
{
private:
    int height;
    T *data;
    bool *status;
    
    void removeSubtreeHelper(int index);
    bool isBSTHelper(int index, T minVal, T maxVal) const;
    void displayParenthesizedViewHelper(int index);
    int getMaxSize() const;
    int checkBalance(int index) const;

public:
    // Constructor & Destructor
    BinaryTree(int h);
    ~BinaryTree();
    
    // Basic Operations
    bool isEmpty() const;
    int size() const;
    int getHeight() const;
    void HeightOfTree() const;
    int maxHeight() const;
    bool contains(const T& value) const;

    // Node Relationship Functions
    T getParent(int index) const;
    T getLeftChild(int index) const;
    T getRightChild(int index) const;
    bool hasLeftChild(int index) const;
    bool hasRightChild(int index) const;
    bool isLeaf(int index) const;
    bool isRoot(int index) const;

    // Tree Property Checks
    bool isFullBinaryTree() const;
    bool isCompleteBinaryTree() const;
    bool isPerfectBinaryTree() const;

    // Search and Find Operations
    int findIndex(const T& value) const;
    int findParentIndex(const T& value) const;
    void displayAncestors(T node);
    void displayDescendents(T node);
    // Tree Modification Functions
    void setRoot(T value);
    void setLeftChild(T parent, T value);
    void setRightChild(T parent, T value);
    void removeSubtree(T parent);
    void updateValue(int index, const T& newValue);
    void clear();
    void resize(int newHeight);

    // Traversal Functions
    void preorder(int index);
    void postorder(int index);
    void inorder(int index);
    void levelorder();
    void iterativePreorder();
    void iterativeInorder();
    void iterativePostorder();

    // Display Functions
    void display();
    void displayParenthesizedView();
    void printTree() const;

    // Analysis Functions
    int countLeaves() const;
    int countInternalNodes() const;
    int getDepth(int index) const;
    T findMax() const;
    T findMin() const;

    // Utility Functions
    void getPathToRoot(int index);
    bool isAncestor(int ancestorIndex, int descendantIndex);
    int findLCA(int index1, int index2);
    void getLevelNodes(int level);
    int findLevelOfNodes(T node);

    // BST Functions
    bool isBST() const;

    // Accessors
    T getData(int index) const;
    bool getStatus(int index) const;
    bool isBalanced() const;
};

// Include the implementation
#include "BinaryTree_Array.tpp"

#endif