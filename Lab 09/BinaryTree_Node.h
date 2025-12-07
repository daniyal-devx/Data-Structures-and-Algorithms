#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <stdexcept>

using namespace std;

template <typename T>
class Node {
public:
    T info;
    Node<T>* left;
    Node<T>* right;
    
    Node(T v) : info(v), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
private:
    Node<T>* root;
    
    // Private helper functions
    Node<T>* findNode(Node<T>* node, const T& value) const;
    Node<T>* findParent(Node<T>* node, const T& value) const;
    void removeSubtreeHelper(Node<T>* node);
    void clearHelper(Node<T>* node);
    Node<T>* copyTree(Node<T>* node) const;
    
    // Traversal helpers
    void preorderHelper(Node<T>* node) const;
    void inorderHelper(Node<T>* node) const;
    void postorderHelper(Node<T>* node) const;
     void mirrorHelper(Node<T>* node);
    
    // Analysis helpers
    int sizeHelper(Node<T>* node) const;
    int heightHelper(Node<T>* node) const;
    int countLeavesHelper(Node<T>* node) const;
    int countInternalNodesHelper(Node<T>* node) const;
    bool isFullHelper(Node<T>* node) const;
    bool isPerfectHelper(Node<T>* node, int height, int level) const;
    bool isCompleteHelper(Node<T>* node, int index, int nodeCount) const;
    bool isBSTHelper(Node<T>* node, T minVal, T maxVal) const;
    bool isBalancedHelper(Node<T>* node, int& height) const;
    
    // Path and LCA helpers
    bool findPath(Node<T>* node, const T& value, vector<Node<T>*>& path) const;
    Node<T>* findLCAHelper(Node<T>* node, const T& value1, const T& value2) const;

public:
    // Constructor & Destructor
    BinaryTree();
    BinaryTree(const BinaryTree& other);
    BinaryTree& operator=(const BinaryTree& other);
    ~BinaryTree();
    
    // Basic Operations
    bool isEmpty() const;
    void setRoot(T value);
    void setLeftChild(T parent, T value);
    void setRightChild(T parent, T value);
    void removeSubtree(T parent);
    void clear();
    
    // Search Operations
    bool contains(const T& value) const;
    Node<T>* find(const T& value) const;
    Node<T>* findParent(const T& value) const;
    
    // Tree Property Checks
    bool isFullBinaryTree() const;
    bool isCompleteBinaryTree() const;
    bool isPerfectBinaryTree() const;
    bool isBalanced() const;
    bool isBST() const;
    
    // Tree Analysis
    int size() const;
    int height() const;
    int countLeaves() const;
    int countInternalNodes() const;
    T findMax() const;
    T findMin() const;
    int getDepth(const T& value) const;
    int isInternalNode(T node);
    int isExternalNode(T node);

    // Traversals
    void preorder() const;
    void inorder() const;
    void postorder() const;
    void levelorder() const;
    void iterativePreorder() const;
    void iterativeInorder() const;
    void iterativePostorder() const;
    void mirrorTree();
    
    // Path and Ancestor Operations
    void printPathToRoot(const T& value) const;
    bool isAncestor(const T& ancestor, const T& descendant) const;
    T findLCA(const T& value1, const T& value2) const;
    
    // Display Functions
    void display() const;
    void printTree() const;
    void printLevel(int level) const;
    void displayParenthesizedViewHelper(Node<T> *node) const;
    void displayParenthesizedView();
    void displayDescendentsHelper(Node<T> *node) const;
    void displayDescendents(T node);

    // Utility Functions
    Node<T>* getRoot() const;
    bool isLeaf(const T& value) const;
    bool hasLeftChild(const T& value) const;
    bool hasRightChild(const T& value) const;
    T getLeftChild(const T& value) const;
    T getRightChild(const T& value) const;
    T findNodeSiblings(T value);
};

#include "BinaryTree_Node.tpp"

#endif