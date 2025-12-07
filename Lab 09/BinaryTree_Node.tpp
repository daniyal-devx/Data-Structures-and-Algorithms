#ifndef BINARYTREE_NODE_CPP
#define BINARYTREE_NODE_CPP

#include "BinaryTree_Node.h"

// Constructor & Destructor
template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& other) {
    root = copyTree(other.root);
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& other) {
    if (this != &other) {
        clear();
        root =copyTree(other.root);
    }
    return *this;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    clear();
}
template <typename T>
Node<T>* BinaryTree<T>::copyTree(Node<T>* node) const {
    if (!node) return nullptr;
    
    Node<T>* newNode = new Node<T>(node->info);
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);
    return newNode;
}

template <typename T>
void BinaryTree<T>::clearHelper(Node<T>* node) {
    if (!node) return;
    
    clearHelper(node->left);
    clearHelper(node->right);
    delete node;
}

template <typename T>
Node<T>* BinaryTree<T>::findNode(Node<T>* node, const T& value) const {
    if (!node) return nullptr;
    if (node->info == value) return node;
    
    Node<T>* leftResult = findNode(node->left, value);
    if (leftResult) return leftResult;
    
    return findNode(node->right, value);
}

template <typename T>
Node<T>* BinaryTree<T>::findParent(Node<T>* node, const T& value) const {
    if (!node || node->info == value) return nullptr;
    
    if ((node->left && node->left->info == value) || 
        (node->right && node->right->info == value)) {
        return node;
    }
    
    Node<T>* leftResult = findParent(node->left, value);
    if (leftResult) return leftResult;
    
    return findParent(node->right, value);
}

// Basic Operations
template <typename T>
bool BinaryTree<T>::isEmpty() const {
    return root == nullptr;
}

template <typename T>
void BinaryTree<T>::setRoot(T value) {
    if (root) {
        throw runtime_error("Root already exists");
    }
    root = new Node<T>(value);
}

template <typename T>
void BinaryTree<T>::setLeftChild(T parent, T value) {
    Node<T>* parentNode = findNode(root, parent);
    if (!parentNode) {
        throw runtime_error("Parent node not found");
    }
    if (parentNode->left) {
        throw runtime_error("Left child already exists");
    }
    parentNode->left = new Node<T>(value);
}

template <typename T>
void BinaryTree<T>::setRightChild(T parent, T value) {
    Node<T>* parentNode = findNode(root, parent);
    if (!parentNode) {
        throw runtime_error("Parent node not found");
    }
    if (parentNode->right) {
        throw runtime_error("Right child already exists");
    }
    parentNode->right = new Node<T>(value);
}

template <typename T>
void BinaryTree<T>::removeSubtreeHelper(Node<T>* node) {
    if (!node) return;
    
    removeSubtreeHelper(node->left);
    removeSubtreeHelper(node->right);
    delete node;
}

template <typename T>
void BinaryTree<T>::removeSubtree(T parent) {
    if (!root) return;
    
    if (root->info == parent) {
        clear();
        return;
    }
    
    Node<T>* parentNode = findParent(root, parent);
    if (!parentNode) return;
    
    Node<T>* targetNode = nullptr;
    if (parentNode->left && parentNode->left->info == parent) {
        targetNode = parentNode->left;
        parentNode->left = nullptr;
    } else if (parentNode->right && parentNode->right->info == parent) {
        targetNode = parentNode->right;
        parentNode->right = nullptr;
    }
    
    if (targetNode) {
        removeSubtreeHelper(targetNode);
    }
}

template <typename T>
void BinaryTree<T>::clear() {
    clearHelper(root);
    root = nullptr;
}

// Search Operations
template <typename T>
bool BinaryTree<T>::contains(const T& value) const {
    return findNode(root, value) != nullptr;
}

template <typename T>
Node<T>* BinaryTree<T>::find(const T& value) const {
    return findNode(root, value);
}

template <typename T>
Node<T>* BinaryTree<T>::findParent(const T& value) const {
    if (!root || root->info == value) return nullptr;
    return findParent(root, value);
}

// Tree Analysis
template <typename T>
int BinaryTree<T>::sizeHelper(Node<T>* node) const {
    if (!node) return 0;
    return 1 + sizeHelper(node->left) + sizeHelper(node->right);
}

template <typename T>
int BinaryTree<T>::size() const {
    return sizeHelper(root);
}

template <typename T>
int BinaryTree<T>::heightHelper(Node<T>* node) const {
    if (!node) return 0;
    return 1 + max(heightHelper(node->left), heightHelper(node->right));
}

template <typename T>
int BinaryTree<T>::height() const {
    return heightHelper(root);
}

template <typename T>
int BinaryTree<T>::countLeavesHelper(Node<T>* node) const {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return countLeavesHelper(node->left) + countLeavesHelper(node->right);
}

template <typename T>
int BinaryTree<T>::countLeaves() const {
    return countLeavesHelper(root);
}

template <typename T>
int BinaryTree<T>::countInternalNodesHelper(Node<T>* node) const {
    if (!node || (!node->left && !node->right)) return 0;
    return 1 + countInternalNodesHelper(node->left) + countInternalNodesHelper(node->right);
}

template <typename T>
int BinaryTree<T>::countInternalNodes() const {
    return countInternalNodesHelper(root);
}

template <typename T>
T BinaryTree<T>::findMax() const {
    if (!root) throw runtime_error("Tree is empty");
    
    T maxVal = root->info;
    queue<Node<T>*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node<T>* current = q.front();
        q.pop();
        
        if (current->info > maxVal) {
            maxVal = current->info;
        }
        
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    return maxVal;
}

template <typename T>
T BinaryTree<T>::findMin() const {
    if (!root) throw runtime_error("Tree is empty");
    
    T minVal = root->info;
    queue<Node<T>*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node<T>* current = q.front();
        q.pop();
        
        if (current->info < minVal) {
            minVal = current->info;
        }
        
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    return minVal;
}

template <typename T>
int BinaryTree<T>::getDepth(const T& value) const {
    if (!root) return -1;
    
    queue<pair<Node<T>*, int> > q;
    q.push(make_pair(root, 0));
    
    while (!q.empty()) {
        pair<Node<T>*, int> currentPair = q.front();
        Node<T>* current = currentPair.first;
        int depth = currentPair.second;
        q.pop();
        
        if (current->info == value) return depth;
        
        if (current->left) q.push(make_pair(current->left, depth + 1));
        if (current->right) q.push(make_pair(current->right, depth + 1));
    }
    return -1;
}

// Tree Property Checks
template <typename T>
bool BinaryTree<T>::isFullHelper(Node<T>* node) const {
    if (!node) return true;
    if (!node->left && !node->right) return true;
    if (node->left && node->right) {
        return isFullHelper(node->left) && isFullHelper(node->right);
    }
    return false;
}

template <typename T>
bool BinaryTree<T>::isFullBinaryTree() const {
    return isFullHelper(root);
}

template <typename T>
bool BinaryTree<T>::isPerfectHelper(Node<T>* node, int height, int level) const {
    if (!node) return true;
    if (!node->left && !node->right) return (height == level + 1);
    if (!node->left || !node->right) return false;
    return isPerfectHelper(node->left, height, level + 1) && 
           isPerfectHelper(node->right, height, level + 1);
}

template <typename T>
bool BinaryTree<T>::isPerfectBinaryTree() const {
    int h = height();
    return isPerfectHelper(root, h, 0);
}

template <typename T>
bool BinaryTree<T>::isCompleteHelper(Node<T>* node, int index, int nodeCount) const {
    if (!node) return true;
    if (index >= nodeCount) return false;
    return isCompleteHelper(node->left, 2 * index + 1, nodeCount) &&
           isCompleteHelper(node->right, 2 * index + 2, nodeCount);
}

template <typename T>
bool BinaryTree<T>::isCompleteBinaryTree() const {
    int nodeCount = size();
    return isCompleteHelper(root, 0, nodeCount);
}

template <typename T>
bool BinaryTree<T>::isBSTHelper(Node<T>* node, T minVal, T maxVal) const {
    if (!node) return true;
    if (node->info <= minVal || node->info >= maxVal) return false;
    return isBSTHelper(node->left, minVal, node->info) &&
           isBSTHelper(node->right, node->info, maxVal);
}

template <typename T>
bool BinaryTree<T>::isBST() const {
    return isBSTHelper(root, numeric_limits<T>::min(), numeric_limits<T>::max());
}

template <typename T>
bool BinaryTree<T>::isBalancedHelper(Node<T>* node, int& height) const {
    if (!node) {
        height = 0;
        return true;
    }
    
    int leftHeight, rightHeight;
    bool leftBalanced = isBalancedHelper(node->left, leftHeight);
    bool rightBalanced = isBalancedHelper(node->right, rightHeight);
    
    height = 1 + max(leftHeight, rightHeight);
    
    if (abs(leftHeight - rightHeight) > 1) return false;
    return leftBalanced && rightBalanced;
}

template <typename T>
bool BinaryTree<T>::isBalanced() const {
    int height;
    return isBalancedHelper(root, height);
}

// Traversals
template <typename T>
void BinaryTree<T>::preorderHelper(Node<T>* node) const {
    if (!node) return;
    cout << node->info << " ";
    preorderHelper(node->left);
    preorderHelper(node->right);
}

template <typename T>
void BinaryTree<T>::preorder() const {
    preorderHelper(root);
    cout << endl;
}

template <typename T>
void BinaryTree<T>::inorderHelper(Node<T>* node) const {
    if (!node) return;
    inorderHelper(node->left);
    cout << node->info << " ";
    inorderHelper(node->right);
}

template <typename T>
void BinaryTree<T>::inorder() const {
    inorderHelper(root);
    cout << endl;
}

template <typename T>
void BinaryTree<T>::postorderHelper(Node<T>* node) const {
    if (!node) return;
    postorderHelper(node->left);
    postorderHelper(node->right);
    cout << node->info << " ";
}

template <typename T>
void BinaryTree<T>::postorder() const {
    postorderHelper(root);
    cout << endl;
}

template <typename T>
void BinaryTree<T>::levelorder() const {
    if (!root) return;
    
    queue<Node<T>*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node<T>* current = q.front();
        q.pop();
        cout << current->info << " ";
        
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

template <typename T>
void BinaryTree<T>::iterativePreorder() const {
    if (!root) return;
    
    stack<Node<T>*> st;
    st.push(root);
    
    while (!st.empty()) {
        Node<T>* current = st.top();
        st.pop();
        cout << current->info << " ";
        
        if (current->right) st.push(current->right);
        if (current->left) st.push(current->left);
    }
    cout << endl;
}

template <typename T>
void BinaryTree<T>::iterativeInorder() const {
    stack<Node<T>*> st;
    Node<T>* current = root;
    
    while (current || !st.empty()) {
        while (current) {
            st.push(current);
            current = current->left;
        }
        
        current = st.top();
        st.pop();
        cout << current->info << " ";
        current = current->right;
    }
    cout << endl;
}

template <typename T>
void BinaryTree<T>::iterativePostorder() const {
    if (!root) return;
    
    stack<Node<T>*> st1, st2;
    st1.push(root);
    
    while (!st1.empty()) {
        Node<T>* current = st1.top();
        st1.pop();
        st2.push(current);
        
        if (current->left) st1.push(current->left);
        if (current->right) st1.push(current->right);
    }
    
    while (!st2.empty()) {
        cout << st2.top()->info << " ";
        st2.pop();
    }
    cout << endl;
}

// Path and Ancestor Operations
template <typename T>
bool BinaryTree<T>::findPath(Node<T>* node, const T& value, vector<Node<T>*>& path) const {
    if (!node) return false;
    
    path.push_back(node);
    if (node->info == value) return true;
    
    if (findPath(node->left, value, path) || findPath(node->right, value, path)) {
        return true;
    }
    
    path.pop_back();
    return false;
}

template <typename T>
void BinaryTree<T>::printPathToRoot(const T& value) const {
    vector<Node<T>*> path;
    if (!findPath(root, value, path)) {
        cout << "Node not found" << endl;
        return;
    }
    
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i]->info;
        if (i > 0) cout << " -> ";
    }
    cout << endl;
}

template <typename T>
bool BinaryTree<T>::isAncestor(const T& ancestor, const T& descendant) const {
    Node<T>* ancestorNode = findNode(root, ancestor);
    if (!ancestorNode) return false;
    
    return findNode(ancestorNode, descendant) != nullptr;
}

template <typename T>
Node<T>* BinaryTree<T>::findLCAHelper(Node<T>* node, const T& value1, const T& value2) const {
    if (!node) return nullptr;
    if (node->info == value1 || node->info == value2) return node;
    
    Node<T>* leftLCA = findLCAHelper(node->left, value1, value2);
    Node<T>* rightLCA = findLCAHelper(node->right, value1, value2);
    
    if (leftLCA && rightLCA) return node;
    return leftLCA ? leftLCA : rightLCA;
}

template <typename T>
T BinaryTree<T>::findLCA(const T& value1, const T& value2) const {
    Node<T>* lca = findLCAHelper(root, value1, value2);
    if (!lca) throw runtime_error("LCA not found");
    return lca->info;
}

// Display Functions
template <typename T>
void BinaryTree<T>::display() const {
    cout << "Preorder: ";
    preorder();
    cout << "Inorder: ";
    inorder();
    cout << "Postorder: ";
    postorder();
    cout << "Levelorder: ";
    levelorder();
}

template <typename T>
void BinaryTree<T>::printTree() const {
    if (!root) return;
    
    queue<Node<T>*> q;
    q.push(root);
    int level = 0;
    
    while (!q.empty()) {
        int levelSize = q.size();
        cout << "Level " << level << ": ";
        
        for (int i = 0; i < levelSize; i++) {
            Node<T>* current = q.front();
            q.pop();
            cout << current->info << " ";
            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << endl;
        level++;
    }
}

template <typename T>
void BinaryTree<T>::printLevel(int level) const {
    if (!root || level < 0) return;
    
    queue<pair<Node<T>*, int> > q;
    q.push(make_pair(root, 0));
    
    while (!q.empty()) {
        pair<Node<T>*, int> currentPair = q.front();
        Node<T>* current = currentPair.first;
        int currentLevel = currentPair.second;
        q.pop();
        
        if (currentLevel == level) {
            cout << current->info << " ";
        } else if (currentLevel > level) {
            break;
        }
        
        if (current->left) q.push(make_pair(current->left, currentLevel + 1));
        if (current->right) q.push(make_pair(current->right, currentLevel + 1));
    }
    cout << endl;
}

// New Functions
// template <typename T>
// void BinaryTree<T>::mirrorHelper(Node<T>* node) {
//     if (!node) return;
    
//     // Swap left and right
//     Node<T>* temp = node->left;
//     node->left = node->right;
//     node->right = temp;
    
//     // Recursively mirror subtrees
//     mirrorHelper(node->left);
//     mirrorHelper(node->right);
// }

// template <typename T>
// void BinaryTree<T>::mirrorTree() {
//     mirrorHelper(root);
// }

// template <typename T>
// int BinaryTree<T>::countOneChildHelper(Node<T>* node) const {
//     if (!node) return 0;
    
//     int count = 0;
//     if ((node->left && !node->right) || (!node->left && node->right)) {
//         count = 1;
//     }
    
//     return count + countOneChildHelper(node->left) + countOneChildHelper(node->right);
// }

// template <typename T>
// int BinaryTree<T>::countNodesWithOneChild() const {
//     return countOneChildHelper(root);
// }

// Utility Functions
template <typename T>
Node<T>* BinaryTree<T>::getRoot() const {
    return root;
}

template <typename T>
bool BinaryTree<T>::isLeaf(const T& value) const {
    Node<T>* node = findNode(root, value);
    return node && !node->left && !node->right;
}

template <typename T>
bool BinaryTree<T>::hasLeftChild(const T& value) const {
    Node<T>* node = findNode(root, value);
    return node && node->left != nullptr;
}

template <typename T>
bool BinaryTree<T>::hasRightChild(const T& value) const {
    Node<T>* node = findNode(root, value);
    return node && node->right != nullptr;
}

template <typename T>
T BinaryTree<T>::getLeftChild(const T& value) const {
    Node<T>* node = findNode(root, value);
    if (!node || !node->left) {
        throw runtime_error("Left child not found");
    }
    return node->left->info;
}

template <typename T>
T BinaryTree<T>::getRightChild(const T& value) const {
    Node<T>* node = findNode(root, value);
    if (!node || !node->right) {
        throw runtime_error("Right child not found");
    }
    return node->right->info;
}
template <typename T>
int BinaryTree<T>::isInternalNode(T value){
Node<T>* node = findNode(root, value);
    if(node&&(node->left||node->right)){
        return 1;
    }
    else{
        return 0;
    }
}
template <typename T>
int BinaryTree<T>::isExternalNode(T value){
    Node<T>* node = findNode(root, value);
    if( node && !node->left && !node->right){
        return 1;
    }
    else{
        return 0;
    }
}
template <typename T>
T BinaryTree<T>::findNodeSiblings(T value){
    Node<T> *node = findParent(value);
    if(node->left->info==value){
        return node->right->info;
    }
    else if(node->right->info==value){
        return node->left->info;
    }
}
template<typename T>
void BinaryTree<T>::displayDescendentsHelper(Node<T>* node) const {
    if (!node) return;  
    if (node->left) {
        cout << node->left->info << " ";
        displayDescendentsHelper(node->left);
    }
    if (node->right) {
        cout << node->right->info << " ";
        displayDescendentsHelper(node->right);
    }
}
template<typename T>
void BinaryTree<T>::displayDescendents(T node) {
    Node<T>* nodePtr = findNode(root, node);
    if (!nodePtr){
        throw runtime_error("Node not found");
    }
    cout<<"Descendents of "<<node<<": ";
    displayDescendentsHelper(node);
    cout<<endl;
}
template<typename T>
void BinaryTree<T>::displayParenthesizedView(){
    cout << "Parenthesized View: ";
    displayParenthesizedViewHelper(root);
    cout << endl;
}
template<typename T>
void BinaryTree<T>::displayParenthesizedViewHelper(Node<T>* node) const {
    if (!node) return;
    
    cout << node->info;
    
    if (node->left || node->right) {
        cout << "(";
        displayParenthesizedViewHelper(node->left);
        cout << ",";
        displayParenthesizedViewHelper(node->right);
        cout << ")";
    }
}
template<typename T>
void BinaryTree<T>::mirrorHelper(Node<T>* node) {
    if (!node) return;
    Node<T>* newNode = node->left;
    node->left = node->right;
    node->right = newNode;
    mirrorHelper(node->left);
    mirrorHelper(node->right);
}

template<typename T>
void BinaryTree<T>::mirrorTree() {
    mirrorHelper(root);
}



#endif