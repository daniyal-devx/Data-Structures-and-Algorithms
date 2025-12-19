#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
// class StudentNode{
//     public:
//     int rollNo;
//     string name;
//     double cgpa;
//     StudentNode* left;
//     StudentNode *right;
//     StudentNode(int rn,string nm,double cgpa2){
//         rollNo = rn;
//         name = nm;
//         cgpa = cgpa2;
//         left = nullptr;
//         right = nullptr;
//     }
// };
// class StudentBST{
//     private:
//         StudentNode *root;
//         StudentNode* insertHelper(StudentNode* node,int rn , string nm, double cgpa2) {
//     if (node == nullptr)return new StudentNode(rn,nm,cgpa2);
//     if (rn < node->rollNo) 
//         node->left = insertHelper(node->left, rn,nm,cgpa2);
//     else 
//         node->right = insertHelper(node->right, rn,nm,cgpa2);
//     return node;
// }
// void destroyTree(StudentNode* node) {
//     if (node == nullptr) return;
//     destroyTree(node->left);
//     destroyTree(node->right);
//     delete node;
// }
//     public:
//         StudentBST() {
//             root = nullptr;
//         }
//         ~StudentBST(){
//             destroyTree(root);
//         }
//         bool insert(int rn , string nm, double cgpa2) {
//             root = insertHelper(root,rn,nm,cgpa2);
//             if(root!=nullptr){
//                 return true;
//             }
//             else
//                 return false;
// }
// bool search(int rn) {
//     StudentNode* current = root;
//     while (current != nullptr) {
//         if (rn == current->rollNo) return true;
//         else if (rn < current->rollNo) current = current->left;
//         else current = current->right;
//     }
//     return false;
// }
// void inOrder() {
//      inOrderHelper(root); cout << endl; 
//     }
// void inOrderHelper(StudentNode* root) {
//         if (root) {
//             inOrderHelper(root->left);
//             cout << root->rollNo << " "<<root->name<<" "<<root->cgpa<<endl;
//             inOrderHelper(root->right);
//         }
//     }

// StudentNode* findMin(StudentNode* node) {
//     while (node->left != nullptr) {
//         node = node->left;
//     }
//     return node;
// }
// StudentNode* deleteNode(StudentNode* root, int rn) {
//     if (root == nullptr) {
//         return root;
//     }

//     if (rn < root->rollNo) {
//         root->left = deleteNode(root->left, rn);
//     } else if (rn > root->rollNo) {
//         root->right = deleteNode(root->right, rn);
//     } else {
    
//         if (root->left == nullptr) {
//             StudentNode* temp = root->right;
//             delete root;
//             return temp;
//         } else if (root->right == nullptr) {
//             StudentNode* temp = root->left;
//             delete root;
//             return temp;
//         }
//         StudentNode *temp = findMin(root->right);
//         root->rollNo = temp->rollNo;
//         root->right = deleteNode(root->right, temp->rollNo);
//     }
//     return root;
// }
// void deleteMethod(int rn) {
//     root = deleteNode(root,rn);
// }
// void displayInRangeHelper(StudentNode* root,double cgpaStart,double cgpaEnd) {
//         if (root) {
//             displayInRangeHelper(root->left,cgpaStart,cgpaEnd);
//             if(root->cgpa>=cgpaStart&&root->cgpa<=cgpaEnd){
//             cout << root->rollNo << " "<<root->name<<" "<<root->cgpa<<endl;
//         }
//             displayInRangeHelper(root->right,cgpaStart,cgpaEnd);
//         }
//     }
// void displayInRange(double cgpaStart, double cgpaEnd){
//     displayInRangeHelper(root, cgpaStart, cgpaEnd);
// }
// };
template<typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };
    Node* root;
    public:
    BinarySearchTree(){
        root = nullptr;
    }
    void insert(T val) {
    root = insertHelper(root, val);
}
 Node* insertHelper(Node* node, T val) {
    if (node == nullptr) return new Node(val);
    if (val < node->data) 
        node->left = insertHelper(node->left, val);
    else 
        node->right = insertHelper(node->right, val);
    return node;
}
    bool recSearchHelper(Node* node, T key) {
        if (node == nullptr) return false;
        if (node->data == key) return true;
        if (key < node->data) return recSearchHelper(node->left, key);
        return recSearchHelper(node->right, key);
    }
    int countNodesHelper(Node* node) {
        if (node == nullptr) return 0;
        return 1 + countNodesHelper(node->left) + countNodesHelper(node->right);
    }
    int getHeightHelper(Node* node) {
        if (node == nullptr) return -1;
        int leftHeight = getHeightHelper(node->left);
        int rightHeight = getHeightHelper(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
    void doubleTreeHelper(Node* node) {
        if (node == nullptr) return;
        Node* duplicate = new Node(node->data);
        duplicate->left = node->left;
        node->left = duplicate;
        doubleTreeHelper(duplicate->left);
        doubleTreeHelper(node->right);
    }
    void root_to_leaf_paths(){
        vector<int> path;
        root_to_leaf_paths(root, path);
    }

    void root_to_leaf_paths(Node* r, vector<int>& path){
        if(!r)return;

        path.push_back(r->data);

        if(!r->left && !r->right){
            for(int i=0 ; i<path.size() ; i++){
                if(i!=0)cout<<"->"<<path[i]<<" ";
                else cout<<path[i]<<" ";
            }
            cout<<endl;
        }
        else{
            root_to_leaf_paths(r->left, path);
            root_to_leaf_paths(r->right, path);
        }

        path.pop_back();
    }

    bool recSearch(T key) {
        return recSearchHelper(root, key);
    }
    int countNodes() {
        return countNodesHelper(root);
    }
    int getHeight() {
        return getHeightHelper(root);
    }
    void doubleTree() {
        doubleTreeHelper(root);
    }
    void destroy(Node *p)
    {
        if (!p)
            return;
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
void preorderHelper(Node* node) const {
    if (!node) return;
    cout << node->data << " ";
    preorderHelper(node->left);
    preorderHelper(node->right);
}


void preorder() const {
    preorderHelper(root);
    cout << endl;
}
void inorderHelper(Node* node) const {
    if (!node) return;
    inorderHelper(node->left);
    cout << node->data << " ";
    inorderHelper(node->right);
}

void inorder() {
    inorderHelper(root);
    cout << endl;
}
void postorderHelper(Node* node) const {
    if (!node) return;
    postorderHelper(node->left);
    postorderHelper(node->right);
    cout << node->data << " ";
}

void postorder() const {
    postorderHelper(root);
    cout << endl;
}
void construct_from_traversals(vector<int>in_order, vector<int> pre_order)
    {
        destroy(root);
        root = nullptr;
        int preIndex = 0;
        root = buildTree(in_order, pre_order, 0, in_order.size() - 1, preIndex);
    }
Node *buildTree(vector<int> &inorder, vector<int> &preorder, int inStart, int inEnd, int &preIndex)
    {
        if (inStart > inEnd)
            return nullptr;
        int rootVal = preorder[preIndex];
        preIndex++;
        Node *node = new Node(rootVal);
        int mid = 0;
        for (int i = inStart; i <= inEnd; i++)
            if (inorder[i] == rootVal)
                mid = i;
        node->left = buildTree(inorder, preorder, inStart, mid - 1, preIndex);
        node->right = buildTree(inorder, preorder, mid + 1, inEnd, preIndex);
        return node;
    }

void createBalancedTreeHelper(int arr[],int start,int end){
    if(start>end){
        return;
    }
    int mid = (start + end) / 2;
    this->insert(arr[mid]);
    createBalancedTreeHelper(arr, start, mid - 1);
    createBalancedTreeHelper(arr, mid + 1, end);
}
void createBalancedTree(int arr[],int start,int end){
    root = nullptr;
    createBalancedTreeHelper(arr, start, end);
}
};
// int main(){
//    StudentBST bst1;
//     int choice;
    
//     do {
//         cout << "\n Student BST Menu " << endl;
//         cout << "1. Insert a new student" << endl;
//         cout << "2. Search for a student" << endl;
//         cout << "3. See the list of students" << endl;
//         cout << "4. Quit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1: {
//                 string name2;
//                 int rollno;
//                 double cgpa2;
//                 cout << "Enter Student data to insert (RollNo Name CGPA): ";
//                 cin >> rollno >> name2 >> cgpa2;
//                 if (bst1.insert(rollno, name2, cgpa2)) {
//                     cout << "Inserted successfully." << endl;
//                 }
//                 break;
//             }
//             case 2: {
//                 int rollno2;
//                 cout << "Enter rollNumber to search: ";
//                 cin >> rollno2;
//                 if (bst1.search(rollno2)) {
//                     cout << "Student found." << endl;
//                 } else {
//                     cout << "Student not found." << endl;
//                 }
//                 break;
//             }
//             case 3:
//                 bst1.inOrder();
//                 break;
//             case 4:
//                 cout<<"Exiting";
//                 break;
//             default:
//                 cout << "Invalid choice.\n";
//         }
//     } while (true);
//     cout << "my name";
//     cout << endl;
//     cout << "Check if inserted or not?"<<endl;
//     cout <<bst1.insert(52, "Farham", 3.8)<<endl;
//     bst1.insert(54, "Ali", 3.6);
//     cout << "Found"<<endl;
//     cout << bst1.search(54)<<endl;
//     bst1.insert(51, "Aneeq", 2.0);
//     bst1.insert(55, "Annas", 3.4);
//     bst1.inOrder();
//     bst1.deleteMethod(54);
//     bst1.inOrder();
//     cout << endl;
//     bst1.displayInRange(3.0, 3.8);
// }
// int main() { 
//     BinarySearchTree<int> bst; 
//     vector<int> in1 = {1, 2, 3, 4, 5, 6}; 
//     vector<int> pre1 = {3, 1, 2, 5, 4, 6}; 
     
//     bst.construct_from_traversals(in1, pre1); 
 
//     cout << "In-order traversal (Example 1): "; 
//     bst.inorder(); 
 
//     cout << "Post-order traversal (Example 1): "; 
//     bst.postorder(); 
//     cout << "Pre-order traversal (Example 1): "; 
//     bst.preorder(); 

 
//     BinarySearchTree<int> bst2; 
//     vector<int> in2 = {5,10,15,25,27,30,35,40,45,50,52,55,60,65,70,75,80,85,90,100}; 
//     vector<int> pre2 = {50,25,10,5,15,40,30,27,35,45,75,60,55,52,65,70,90,80,85,100}; 
//     // bst2.construct_from_traversals(in2, pre2); 
//     cout << "\nIn-order traversal (Example 2): "; 
//     bst2.inorder(); 
//     cout << "Post-order traversal (Example 2): "; 
//     bst2.postorder(); 
//     return 0;
// }
// int main() { 
// BinarySearchTree<int> bst; 
// int arr[] = {0,1,2,3,4,5,6,7,8,9}; 
// int n = sizeof(arr) / sizeof(arr[0]); 
// bst.createBalancedTree(arr, 0, n - 1); 
// cout << "Pre-order: "; 
// bst.preorder(); 
// cout << "In-order: "; 
// bst.inorder(); 
// cout << "Post-order: "; 
// bst.postorder(); 
// return 0; 
// } 
int main() { 
    BinarySearchTree<int> bst; 
    vector<int> in1 = {1, 2, 3, 4, 5, 6}; 
    vector<int> pre1 = {3, 1, 2, 5, 4, 6}; 
     
    bst.construct_from_traversals(in1, pre1); 
 
    cout << "In-order traversal (Example 1): "; 
    bst.inorder(); 
 
    cout << "Post-order traversal (Example 1): "; 
    bst.postorder(); 
 
    BinarySearchTree<int> bst2; 
    vector<int> in2 = {5,10,15,25,27,30,35,40,45,50,52,55,60,65,70,75,80,85,90,100}; 
    vector<int> pre2 = {50,25,10,5,15,40,30,27,35,45,75,60,55,52,65,70,90,80,85,100}; 
 
    bst2.construct_from_traversals(in2, pre2); 
 
    cout << "\nIn-order traversal (Example 2): "; 
    bst2.inorder(); 
 
    cout << "Post-order traversal (Example 2): "; 
    bst2.postorder(); 
    return 0; 
    
}
