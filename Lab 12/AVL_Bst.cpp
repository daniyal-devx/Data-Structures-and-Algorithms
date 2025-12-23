#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

struct AVLNode{
	int data, height;
	AVLNode *left, *right;
	AVLNode(int data, AVLNode *left=NULL, AVLNode *right=NULL){
		this->data = data;
		this->left = left; 
		this->right = right;
		this->height = 0;
	}
};

int max(const int a, const int b){
	if (a < b)	return b;
	return a;
}

class BST{
	AVLNode *root;
	
	// Helper function for Task 1
	int findIndex(vector<int>& inorder, int start, int end, int value) {
		for (int i = start; i <= end; i++) {
			if (inorder[i] == value) {
				return i;
			}
		}
		return -1;
	}
	
	// Recursive helper for Task 1
	AVLNode* buildTreeHelper(vector<int>& inorder, vector<int>& preorder, 
	                         int inStart, int inEnd, int& preIndex) {
		if (inStart > inEnd) {
			return NULL;
		}
		
		// Pick current node from preorder using preIndex
		int currentData = preorder[preIndex++];
		AVLNode* node = new AVLNode(currentData);
		
		// If this node has no children, return it
		if (inStart == inEnd) {
			return node;
		}
		
		// Find the index of this node in inorder traversal
		int inIndex = findIndex(inorder, inStart, inEnd, currentData);
		
		// Recursively construct left and right subtrees
		node->left = buildTreeHelper(inorder, preorder, inStart, inIndex - 1, preIndex);
		node->right = buildTreeHelper(inorder, preorder, inIndex + 1, inEnd, preIndex);
		
		return node;
	}
	
	// Helper function for Task 2
	AVLNode* createBalancedTreeHelper(int* arr, int start, int end) {
		if (start > end) {
			return NULL;
		}
		
		// Get middle element
		int mid = (start + end) / 2;
		
		// Create node with middle element
		AVLNode* node = new AVLNode(arr[mid]);
		
		// Recursively construct left and right subtrees
		node->left = createBalancedTreeHelper(arr, start, mid - 1);
		node->right = createBalancedTreeHelper(arr, mid + 1, end);
		
		// Update height
		node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
		
		return node;
	}
	
	// Helper to destroy tree
	void destroy(AVLNode* node) {
		if (node != NULL) {
			destroy(node->left);
			destroy(node->right);
			delete node;
		}
	}
	
	// Helper to count nodes
	int countNodes(AVLNode* node) {
		if (node == NULL) return 0;
		return 1 + countNodes(node->left) + countNodes(node->right);
	}
	
	// Helper for DSW - make rotations
	void makeRotations(int count) {
		AVLNode* grandParent = NULL;
		AVLNode* parent = root;
		AVLNode* child = root->right;
		
		for (int i = 0; i < count; i++) {
			if (child == NULL) break;
			
			// Perform left rotation
			if (grandParent == NULL) {
				root = child;
			} else {
				grandParent->right = child;
			}
			
			parent->right = child->left;
			child->left = parent;
			
			// Move pointers for next rotation
			grandParent = child;
			parent = grandParent->right;
			if (parent != NULL) {
				child = parent->right;
			}
		}
	}

public:
	BST(){	root = NULL;	}
	
	AVLNode* leftRotation(AVLNode* temp){
		AVLNode* temp_right = temp->right;
		temp->right	= temp_right->left;
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		temp_right->left = temp;
		temp = temp_right;
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		return temp;
	}
	
	AVLNode* rightRotation(AVLNode* temp){
		AVLNode* temp_left = temp->left;
		temp->left	= temp_left->right;
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		temp_left->right = temp;
		temp = temp_left;
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		return temp;
	}
	
	int getHeight(AVLNode* t) const{
		if (!t)	return -1;
		return t->height;
	}
	
	int getHeight() const{
		if (!root)	return 0;
		int lh = getHeight(root->left);
		int rh = getHeight(root->right);
		return max(lh, rh) + 1;
	}
	
	AVLNode* doRightRotation(AVLNode* temp){
		int balance = getHeight(temp->left->left) - getHeight(temp->left->right);
		if (balance < 0) 	temp->left = leftRotation(temp->left);
		temp = rightRotation(temp);
		return temp;
	}
	
	AVLNode* doLeftRotation(AVLNode* temp){
		int balance = getHeight(temp->right->left) - getHeight(temp->right->right);
		if (balance > 0) 	temp->right = rightRotation(temp->right);
		temp = leftRotation(temp);
		return temp;
	}
	
	AVLNode* doRotation(AVLNode* temp){
		int lh = getHeight(temp->left);
		int rh = getHeight(temp->right);
		int balance =  lh - rh ;
		if (balance > 1)
			temp = doRightRotation(temp);
		else if (balance < -1)
			temp = doLeftRotation(temp);
		return temp;		
	}
	
	AVLNode* insert(int d, AVLNode *temp){	
		if (temp==NULL)	return new AVLNode(d);
		if (temp->data>d) 		temp->left = insert(d, temp->left);
		else if (temp->data<d) temp->right = insert(d, temp->right);
		temp = doRotation(temp);
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		return temp;	
	}
	
	void insert(int d){	
		root = insert(d, root);
	}
	
	AVLNode* findLeftMost(AVLNode *t){
		if (t->left == NULL)	return t;
		return findLeftMost(t->left);
	}
	
	AVLNode* remove(int d, AVLNode *temp){	
		if (temp==NULL)			return NULL;
		if (temp->data>d) 		temp->left = remove(d, temp->left);
		else if (temp->data<d) 	temp->right = remove(d, temp->right);
		else{
			if (temp->left == NULL && temp->right == NULL){
				delete temp;
				return NULL;
			}
			else if (temp->left == NULL && temp->right != NULL){
				AVLNode *tempR = temp->right;
				delete temp;
				return tempR;
			}
			else if (temp->right == NULL){
				AVLNode *tempL = temp->left;
				delete temp;
				return tempL;
			}
			else{
				AVLNode *toBeReplaced = findLeftMost(temp->right);
				temp->data = toBeReplaced->data;
				temp->right = remove(temp->data, temp->right);
			}		
		}
		temp = doRotation(temp);
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		return temp;	
	}
	
	void remove(int d){	
		root = remove(d, root);
	}
	
	void inorder(AVLNode* t){
		if (t!=NULL){
			inorder(t->left);
			cout << t->data << ' ';
			inorder(t->right);
		}
	}
	
	void inorder(){
		inorder(root);
		cout << '\n';
	}
	
	void preorder(AVLNode* t){
		if (t!=NULL){
			cout << t->data << ' ';
			preorder(t->left);
			preorder(t->right);
		}
	}
	
	void preorder(){
		preorder(root);
		cout << '\n';
	}
	
	void postorder() { 
		postorderHelper(root); 
		cout << endl;
	}
	
	void postorderHelper(AVLNode* node) {
		if (node) {
			postorderHelper(node->left);
			postorderHelper(node->right);
			cout << node->data << " ";
		}
	}
	
	// Display functions required by lab
	void display_in_order() {
		inorder();
	}
	
	void display_pre_order() {
		preorder();
	}
	
	void display_post_order() {
		postorder();
	}
	
	void removeNodes(AVLNode* t){
		if (t!=NULL){
			removeNodes(t->left);
			removeNodes(t->right);
			delete t;
		}
	}
	
	~BST(){
		removeNodes(root);
	}
	
	// ==================== TASK 1 ====================
	// Construct BST from inorder and preorder traversals
	void construct_from_traversals(vector<int> in_order, vector<int> pre_order) {
		// Clear existing tree if any
		if (root != NULL) {
			destroy(root);
			root = NULL;
		}
		
		int preIndex = 0;
		root = buildTreeHelper(in_order, pre_order, 0, in_order.size() - 1, preIndex);
	}
	
	// ==================== TASK 2 ====================
	// Create balanced BST from sorted array
	void createBalancedTree(int* arr, int start, int end) {
		// Clear existing tree if any
		if (root != NULL) {
			destroy(root);
			root = NULL;
		}
		
		// Build balanced tree
		root = createBalancedTreeHelper(arr, start, end);
	}
	
	// ==================== TASK 3 ====================
	// Convert BST to backbone (vine)
	void convertToBackbone() {
		AVLNode* grandParent = NULL;
		AVLNode* parent = root;
		AVLNode* leftChild;
		
		while (parent != NULL) {
			if (parent->left != NULL) {
				leftChild = parent->left;
				
				// Right rotate
				parent->left = leftChild->right;
				leftChild->right = parent;
				
				// Update parent pointers
				if (grandParent == NULL) {
					root = leftChild;
				} else {
					grandParent->right = leftChild;
				}
				
				// Update for next iteration
				parent = leftChild;
			} else {
				grandParent = parent;
				parent = parent->right;
			}
		}
	}
	
	// Create perfectly balanced BST using DSW algorithm
	void createPerfectBST() {
		// Step 1: Convert to backbone
		convertToBackbone();
		
		// Step 2: Count nodes
		int n = countNodes(root);
		
		// Step 3: Calculate m = 2^floor(log2(n+1)) - 1
		int m = (int)pow(2, floor(log2(n + 1))) - 1;
		
		// Step 4: Make n - m rotations
		makeRotations(n - m);
		
		// Step 5: Make m/2 rotations repeatedly
		while (m > 1) {
			m = m / 2;
			makeRotations(m);
		}
		
		// Update heights after balancing
		updateHeights(root);
	}
	
	// Helper to update heights after DSW
	void updateHeights(AVLNode* node) {
		if (node != NULL) {
			updateHeights(node->left);
			updateHeights(node->right);
			node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
		}
	}
};

// ==================== TEST TASK 1 ====================
void testTask1() {
	cout << "========== TASK 1: Construct from Traversals ==========" << endl;
	
	// Example 1
	BST bst;
	vector<int> in1 = {1, 2, 3, 4, 5, 6};
	vector<int> pre1 = {3, 1, 2, 5, 4, 6};
	bst.construct_from_traversals(in1, pre1);
	
	cout << "In-order traversal (Example 1): ";
	bst.display_in_order();
	cout << "Post-order traversal (Example 1): ";
	bst.display_post_order();
	
	// Example 2
	BST bst2;
	vector<int> in2 = {5,10,15,25,27,30,35,40,45,50,52,55,60,65,70,75,80,85,90,100};
	vector<int> pre2 = {50,25,10,5,15,40,30,27,35,45,75,60,55,52,65,70,90,80,85,100};
	bst2.construct_from_traversals(in2, pre2);
	
	cout << "\nIn-order traversal (Example 2): ";
	bst2.display_in_order();
	cout << "Post-order traversal (Example 2): ";
	bst2.display_post_order();
	
	cout << endl;
}

// ==================== TEST TASK 2 ====================
void testTask2() {
	cout << "\n========== TASK 2: Create Balanced Tree ==========" << endl;
	
	BST bst;
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	bst.createBalancedTree(arr, 0, n - 1);
	
	cout << "Pre-order: ";
	bst.display_pre_order();
	cout << "In-order: ";
	bst.display_in_order();
	cout << "Post-order: ";
	bst.display_post_order();
	
	cout << endl;
}

// ==================== TEST TASK 3 ====================
void testTask3() {
	cout << "\n========== TASK 3: DSW Algorithm ==========" << endl;
	
	BST bst;
	bst.insert(1);
	bst.insert(5);
	bst.insert(10);
	bst.insert(20);
	bst.insert(25);
	bst.insert(30);
	bst.insert(35);
	bst.insert(40);
	bst.insert(45);
	
	cout << "Original BST Height: " << bst.getHeight() << endl;
	
	cout << "\nOriginal BST (Inorder): ";
	bst.display_in_order();
	cout << "Original BST Pre-order: ";
	bst.display_pre_order();
	cout << "Original BST Post-order: ";
	bst.display_post_order();
	
	bst.createPerfectBST();
	
	cout << "\nHeight After DSW: " << bst.getHeight() << endl;
	
	cout << "\nBalanced BST using DSW (Inorder): ";
	bst.display_in_order();
	cout << "Balanced BST using DSW (Pre-order): ";
	bst.display_pre_order();
	cout << "Balanced BST using DSW (Post-order): ";
	bst.display_post_order();
	
	cout << endl;
}

// ==================== MAIN ====================
int main() {
	testTask1();
	testTask2();
	testTask3();
	
	return 0;
}