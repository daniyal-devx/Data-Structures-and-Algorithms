#ifndef BINARYTREE_TPP
#define BINARYTREE_TPP
#include "BinaryTree_Array.h"
#include "math.h"

// Private helper functions
template <typename T>
void BinaryTree<T>::removeSubtreeHelper(int index)
{
    if (index >= getMaxSize() || !status[index])
    {
        return;
    }
    status[index] = false;
    removeSubtreeHelper(2 * index + 1);
    removeSubtreeHelper(2 * index + 2);
}
template <typename T>
void BinaryTree<T>::displayParenthesizedViewHelper(int index)
{
   if (index >= getMaxSize() || !status[index]) return;  
    cout << data[index];   
    int leftChild = (2 * index) + 1;
    int rightChild = (2 * index) + 2;
    int maxSize = getMaxSize();  
    bool hasLeftChild = (leftChild < maxSize) && status[leftChild];
    bool hasRightChild = (rightChild < maxSize) && status[rightChild];
    
    if (hasLeftChild || hasRightChild) {
        cout << "(";    
        if (hasLeftChild) {
            displayParenthesizedViewHelper(leftChild);
        }
        if (!hasLeftChild || !hasRightChild) {
            cout << ",";
        }
        if (hasRightChild) {
            displayParenthesizedViewHelper(rightChild);
        }     
        cout << ")";
    }
}
template <typename T>
bool BinaryTree<T>::isBSTHelper(int index, T minVal, T maxVal) const
{
    if (index >= getMaxSize() || !status[index]) return true;
    
    if (data[index] <= minVal || data[index] >= maxVal) return false;
    
    return isBSTHelper(2 * index + 1, minVal, data[index]) &&
           isBSTHelper(2 * index + 2, data[index], maxVal);
}

template <typename T>
int BinaryTree<T>::getMaxSize() const {
    return (1 << height) - 1;
}

template <typename T>
int BinaryTree<T>::checkBalance(int index) const
{
    if (index >= getMaxSize() || !status[index]) return 0;
    
    int leftHeight = checkBalance(2 * index + 1);
    if (leftHeight == -1) return -1;
    
    int rightHeight = checkBalance(2 * index + 2);
    if (rightHeight == -1) return -1;
    
    if (abs(leftHeight - rightHeight) > 1) return -1;
    
    return max(leftHeight, rightHeight) + 1;
}

// Constructor & Destructor
template <typename T>
BinaryTree<T>::BinaryTree(int h)
{
    height = h;
    int size = getMaxSize();
    data = new T[size];
    status = new bool[size];
    for (int i = 0; i < size; i++)
    {
        status[i] = false;
    }
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    delete[] data;
    delete[] status;
}

// Basic Operations
template <typename T>
bool BinaryTree<T>::isEmpty() const
{
    return !status[0];
}

template <typename T>
int BinaryTree<T>::size() const
{
    int count = 0;
    int maxSize = getMaxSize();
    for (int i = 0; i < maxSize; i++)
    {
        if (status[i]) count++;
    }
    return count;
}

template <typename T>
int BinaryTree<T>::getHeight() const
{
    return height;
}
template <typename T>
void BinaryTree<T>::HeightOfTree() const{
int height = 0;
    int size2=size();
            if(size2>0){
                size2 = (size2 - 1) / 2;
                height++;
            }
    height++;
    cout << height;
       
}
template <typename T>
    int BinaryTree<T>::maxHeight() const{
        int maxH = 0;
        int maxSize = getMaxSize();
        for (int i = 0; i < maxSize; i++)
        {
            if (status[i])
            {
                int level = 0;
                int temp = i + 1;
                while (temp > 1)
                {
                    temp >>= 1;
                    level++;
                }
                maxH = std::max(maxH, level + 1);
            }
        }
        return maxH;
    }

template <typename T>
bool BinaryTree<T>::contains(const T& value) const
{
    int maxSize = getMaxSize();
    for (int i = 0; i < maxSize; i++)
    {
        if (status[i] && data[i] == value) return true;
    }
    return false;
}

// Node Relationship Functions
template <typename T>
T BinaryTree<T>::getParent(int index) const
{
    if (index <= 0 || index >= getMaxSize())
    {
        throw out_of_range("Invalid index");
    }
    int parentIndex = (index - 1) / 2;
    if (!status[parentIndex])
    {
        throw runtime_error("Parent does not exist");
    }
    return data[parentIndex];
}

template <typename T>
T BinaryTree<T>::getLeftChild(int index) const
{
    int leftIndex = 2 * index + 1;
    if (leftIndex >= getMaxSize() || !status[leftIndex])
    {
        throw out_of_range("No left child");
    }
    return data[leftIndex];
}

template <typename T>
T BinaryTree<T>::getRightChild(int index) const
{
    int rightIndex = 2 * index + 2;
    if (rightIndex >= getMaxSize() || !status[rightIndex])
    {
        throw out_of_range("No right child");
    }
    return data[rightIndex];
}

template <typename T>
bool BinaryTree<T>::hasLeftChild(int index) const
{
    int leftIndex = 2 * index + 1;
    return leftIndex < getMaxSize() && status[leftIndex];
}

template <typename T>
bool BinaryTree<T>::hasRightChild(int index) const
{
    int rightIndex = 2 * index + 2;
    return rightIndex < getMaxSize() && status[rightIndex];
}

template <typename T>
bool BinaryTree<T>::isLeaf(int index) const
{
    return !hasLeftChild(index) && !hasRightChild(index);
}

template <typename T>
bool BinaryTree<T>::isRoot(int index) const
{
    return index == 0;
}

// Tree Property Checks
template <typename T>
bool BinaryTree<T>::isFullBinaryTree() const
{
    int maxSize = getMaxSize();
    for (int i = 0; i < maxSize; i++)
    {
        if (status[i])
        {
            bool hasLeft = hasLeftChild(i);
            bool hasRight = hasRightChild(i);
            if ((hasLeft && !hasRight) || (!hasLeft && hasRight))
            {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool BinaryTree<T>::isCompleteBinaryTree() const
{
    int lastIndex = -1;
    int maxSize = getMaxSize();
    for (int i = 0; i < maxSize; i++)
    {
        if (status[i])
        {
            lastIndex = i;
        }
    }
    
    for (int i = 0; i <= lastIndex; i++)
    {
        if (!status[i]) return false;
    }
    return true;
}

template <typename T>
bool BinaryTree<T>::isPerfectBinaryTree() const
{
    int actualHeight = maxHeight();
    return size() == (1 << actualHeight) - 1;
}

// Search and Find Operations
template <typename T>
int BinaryTree<T>::findIndex(const T& value) const
{
    int maxSize = getMaxSize();
    for (int i = 0; i < maxSize; i++)
    {
        if (status[i] && data[i] == value) return i;
    }
    return -1;
}

template <typename T>
int BinaryTree<T>::findParentIndex(const T& value) const
{
    int maxSize = getMaxSize();
    for (int i = 0; i < maxSize; i++)
    {
        if (status[i])
        {
            if (hasLeftChild(i) && getLeftChild(i) == value) return i;
            if (hasRightChild(i) && getRightChild(i) == value) return i;
        }
    }
    return -1;
}
template <typename T>
void BinaryTree<T>::displayAncestors(T node){
    int maxSize = getMaxSize();
    for (int i = 0; i < maxSize; i++){
       if (status[i]&&data[i]==node){
            int index= findParentIndex(node);
            T ancestor = data[index];
            cout << ancestor<<" ";
            displayAncestors(ancestor);
       }
    }

}
template <typename T>
void BinaryTree<T>::displayDescendents(T node){
    int maxSize = getMaxSize();
    for (int i = 0;i<maxSize;i++){
        if (status[i]&&data[i]==node){
            T rightchild;
            T leftchild;
            if(hasLeftChild(i))
            {
             leftchild = getLeftChild(i);
            cout << leftchild<<" ";
            }
            if(hasRightChild(i))
            {
             rightchild = getRightChild(i);
            cout << rightchild<<" ";
            }
            displayDescendents(leftchild);
            displayDescendents(rightchild);
        }
    }
        
    
}
template <typename T>
int BinaryTree<T>::findLevelOfNodes(T node){
    int level = 0;
    int maxSize = getMaxSize();
    for (int i = 0;i<maxSize;i++){
        if (status[i]&&data[i]==node){
            int nodeindex = i;
            if(nodeindex>0){
                nodeindex = (nodeindex - 1) / 2;
                level++;
            }
        }
    }
    level++;
    return level;
}

// Tree Modification Functions
template <typename T>
void BinaryTree<T>::setRoot(T value)
{
    data[0] = value;
    status[0] = true;
}

template <typename T>
void BinaryTree<T>::setLeftChild(T parent, T value)
{
    int maxSize = getMaxSize();
    for (int i = 0; i < maxSize; i++)
    {
        if (status[i] && parent == data[i])
        {
            int leftIndex = 2 * i + 1;
            if (leftIndex < maxSize)
            {
                data[leftIndex] = value;
                status[leftIndex] = true;
            }
            else
            {
                cout << "Left child index out of bounds." << endl;
            }
            return;
        }
    }
}

template <typename T>
void BinaryTree<T>::setRightChild(T parent, T value)
{
    int maxSize = getMaxSize();
    for (int i = 0; i < maxSize; i++)
    {
        if (status[i] && parent == data[i])
        {
            int rightIndex = 2 * i + 2;
            if (rightIndex < maxSize)
            {
                data[rightIndex] = value;
                status[rightIndex] = true;
            }
            else
            {
                cout << "Right child index out of bounds." << endl;
            }
            return;
        }
    }
}

template <typename T>
void BinaryTree<T>::removeSubtree(T parent)
{
    int maxSize = getMaxSize();
    for (int i = 0; i < maxSize; i++)
    {
        if (status[i] && parent == data[i])
        {
            removeSubtreeHelper(i);
            return;
        }
    }
}

template <typename T>
void BinaryTree<T>::updateValue(int index, const T& newValue)
{
    if (index < 0 || index >= getMaxSize())
    {
        throw out_of_range("Invalid index");
    }
    data[index] = newValue;
}

template <typename T>
void BinaryTree<T>::clear()
{
    int maxSize = getMaxSize();
    for (int i = 0; i < maxSize; i++)
    {
        status[i] = false;
    }
}

template <typename T>
void BinaryTree<T>::resize(int newHeight)
{
    int newSize = (1 << newHeight) - 1;
    int currentSize = getMaxSize();
    
    T* newData = new T[newSize];
    bool* newStatus = new bool[newSize];
    
    // Initialize new arrays
    for (int i = 0; i < newSize; i++)
    {
        newStatus[i] = false;
    }
    
    // Copy existing data
    int copySize = std::min(currentSize, newSize);
    for (int i = 0; i < copySize; i++)
    {
        newData[i] = data[i];
        newStatus[i] = status[i];
    }
    
    // Update members
    delete[] data;
    delete[] status;
    data = newData;
    status = newStatus;
    height = newHeight;
}

// Traversal Functions
template <typename T>
void BinaryTree<T>::preorder(int index)
{
    if (index >= getMaxSize() || !status[index])
    {
        return;
    }
    cout << data[index] << " ";
    preorder(2 * index + 1);
    preorder(2 * index + 2);
}

template <typename T>
void BinaryTree<T>::postorder(int index)
{
    if (index >= getMaxSize() || !status[index])
    {
        return;
    }
    postorder(2 * index + 1);
    postorder(2 * index + 2);
    cout << data[index] << " ";
}

template <typename T>
void BinaryTree<T>::inorder(int index)
{
    if (index >= getMaxSize() || !status[index])
    {
        return;
    }
    inorder(2 * index + 1);
    cout << data[index] << " ";
    inorder(2 * index + 2);
}

template <typename T>
void BinaryTree<T>::levelorder()
{
    int maxSize = getMaxSize();
    for (int i = 0; i < maxSize; i++)
    {
        if (status[i])
        {
            cout << data[i] << " ";
        }
    }
    cout << endl;
}

template <typename T>
void BinaryTree<T>::iterativePreorder()
{
    if (!status[0]) return;
    
    stack<int> st;
    st.push(0);
    
    while (!st.empty())
    {
        int current = st.top();
        st.pop();
        cout << data[current] << " ";
        
        if (hasRightChild(current))
        {
            st.push(2 * current + 2);
        }
        if (hasLeftChild(current))
        {
            st.push(2 * current + 1);
        }
    }
    cout << endl;
}

template <typename T>
void BinaryTree<T>::iterativeInorder()
{
    if (!status[0]) return;  // If tree is empty, return

    stack<int> st;
    int current = 0;
    
    while (true) {
        // Go to the leftmost node of the current node
        while (current < getMaxSize() && status[current]) {
            st.push(current);
            current = 2 * current + 1;
        }

        // If no more nodes to traverse and stack is empty, we're done
        if (st.empty()) {
            break;
        }

        // Process current node
        current = st.top();
        st.pop();
        cout << data[current] << " ";

        // Move to the right child
        current = 2 * current + 2;
    }
    cout << endl;
}

template <typename T>
void BinaryTree<T>::iterativePostorder()
{
    if (!status[0]) return;
    
    stack<int> st1, st2;
    st1.push(0);
    
    while (!st1.empty())
    {
        int current = st1.top();
        st1.pop();
        st2.push(current);
        
        if (hasLeftChild(current))
        {
            st1.push(2 * current + 1);
        }
        if (hasRightChild(current))
        {
            st1.push(2 * current + 2);
        }
    }
    
    while (!st2.empty())
    {
        cout << data[st2.top()] << " ";
        st2.pop();
    }
    cout << endl;
}

// Display Functions
template <typename T>
void BinaryTree<T>::display()
{
    int maxSize = getMaxSize();
    for (int i = 0; i < maxSize; i++)
    {
        if (status[i])
        {
            cout << data[i] << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}
template <typename T>
void BinaryTree<T>::displayParenthesizedView(){
   if (!status[0]) {
        cout << "Tree is empty" << endl;
        return;
    }
    displayParenthesizedViewHelper(0);
    cout << endl;
}
template <typename T>
void BinaryTree<T>::printTree() const
{
    int maxLevel = maxHeight();
    for (int level = 0; level < maxLevel; level++)
    {
        int start = (1 << level) - 1;
        int end = (1 << (level + 1)) - 2;
        int spaces = (1 << (maxLevel - level)) - 1;
        
        // Print leading spaces
        for (int i = 0; i < spaces; i++) cout << " ";
        
        for (int i = start; i <= end && i < getMaxSize(); i++)
        {
            if (status[i])
            {
                cout << data[i];
            }
            else
            {
                cout << " ";
            }
            
            // Print spaces between nodes
            for (int j = 0; j < 2 * spaces + 1; j++) cout << " ";
        }
        cout << endl;
    }
}

// Analysis Functions
template <typename T>
int BinaryTree<T>::countLeaves() const
{
    int count = 0;
    int maxSize = getMaxSize();
    for (int i = 0; i < maxSize; i++)
    {
        if (status[i] && isLeaf(i)) count++;
    }
    return count;
}

template <typename T>
int BinaryTree<T>::countInternalNodes() const
{
    return size() - countLeaves();
}

template <typename T>
int BinaryTree<T>::getDepth(int index) const
{
    if (index < 0 || index >= getMaxSize() || !status[index])
    {
        throw out_of_range("Invalid index");
    }
    int depth = 0;
    int temp = index + 1;
    while (temp > 1) {
        temp >>= 1;
        depth++;
    }
    return depth;
}

template <typename T>
T BinaryTree<T>::findMax() const
{
    if (!status[0]) throw runtime_error("Tree is empty");
    
    T maxVal = data[0];
    int maxSize = getMaxSize();
    for (int i = 1; i < maxSize; i++)
    {
        if (status[i] && data[i] > maxVal)
        {
            maxVal = data[i];
        }
    }
    return maxVal;
}

template <typename T>
T BinaryTree<T>::findMin() const
{
    if (!status[0]) throw runtime_error("Tree is empty");
    
    T minVal = data[0];
    int maxSize = getMaxSize();
    for (int i = 1; i < maxSize; i++)
    {
        if (status[i] && data[i] < minVal)
        {
            minVal = data[i];
        }
    }
    return minVal;
}

// Utility Functions
template <typename T>
void BinaryTree<T>::getPathToRoot(int index)
{
    while (index >= 0)
    {
        cout << data[index];
        if (index == 0) break;
        cout << " -> ";
        index = (index - 1) / 2;
    }
    cout << endl;
}

template <typename T>
bool BinaryTree<T>::isAncestor(int ancestorIndex, int descendantIndex)
{
    while (descendantIndex > ancestorIndex)
    {
        if (descendantIndex == ancestorIndex) return true;
        descendantIndex = (descendantIndex - 1) / 2;
    }
    return descendantIndex == ancestorIndex;
}

template <typename T>
int BinaryTree<T>::findLCA(int index1, int index2)
{
    while (index1 != index2)
    {
        if (index1 > index2)
        {
            index1 = (index1 - 1) / 2;
        }
        else
        {
            index2 = (index2 - 1) / 2;
        }
    }
    return index1;
}

template <typename T>
void BinaryTree<T>::getLevelNodes(int level)
{
    int start = pow(2,level)-1;
    int end = start*2;
    
    for (int i = start; i <= end && i < getMaxSize(); i++)
    {
        if (status[i])
        {
            cout << data[i] << " ";
        }
    }
    cout << endl;
}

// BST Functions
template <typename T>
bool BinaryTree<T>::isBST() const
{
    if (!status[0]) return true;
    return isBSTHelper(0, numeric_limits<T>::min(), numeric_limits<T>::max());
}

// Accessors
template <typename T>
T BinaryTree<T>::getData(int index) const
{
    if (index < 0 || index >= getMaxSize() || !status[index])
    {
        throw out_of_range("Invalid index");
    }
    return data[index];
}

template <typename T>
bool BinaryTree<T>::getStatus(int index) const
{
    if (index < 0 || index >= getMaxSize())
    {
        return false;
    }
    return status[index];
}

template <typename T>
bool BinaryTree<T>::isBalanced() const
{
    return checkBalance(0) != -1;
}

#endif