#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

// void heapifyDownMax(Student st[], int n, int i) {
//     int largest = i;
//     int left = 2*i + 1;
//     int right = 2*i + 2;

//     if (left < n && st[left].cgpa > st[largest].cgpa)
//         largest = left;

//     if (right < n && st[right].cgpa > st[largest].cgpa)
//         largest = right;

//     if (largest != i) {
//         swap(st[i], st[largest]);
//         heapifyDownMax(&st, n, largest);
//     }
// }

// void buildMaxHeap(int st[], int n) {
//     for (int i = n/2 - 1; i >= 0; i--) {
//         heapifyDownMax(st, n, i);
//     }
// }
class Student { 
public: 
    double cgpa;  // Student’s CGPA  
    int rollNo;   // Student’s roll number  
    Student() { 
        cgpa = 0.0; 
        rollNo = 0; 
    } 
    Student(int r, double c) { 
        rollNo = r; 
        cgpa = c; 
    } 
}; 
class StudentMaxHeap
{
private:
    Student* st;
    int capacity;
    int no_of_elements;



  bool isGreater(const Student& a, const Student& b){
      if(a.cgpa!=b.cgpa){
          return a.cgpa > b.cgpa;
      }
      return a.rollNo < b.rollNo;
  }
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    void heapifyUp(int i)
    {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (isGreater(st[i], st[parent])) {
                swap(st[i], st[parent]);
                i = parent;
            } 
            else {
                break;
            }
        }
    }
    void heapifyDown(int i)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < no_of_elements && isGreater(st[l], st[largest])){
            largest = l;
        }

        if (r < no_of_elements && isGreater(st[r],st[largest])){
            largest = r;
        }
        if (largest != i)
        {
            swap(st[i], st[largest]);
            heapifyDown(largest);
        }
    }

public:
    StudentMaxHeap(int cap)
    {
        capacity = cap;
        no_of_elements = 0;
        st = new Student[cap];
    }

    ~StudentMaxHeap()
    {
        delete[] st;
    }
    bool isEmpty() const { return no_of_elements == 0; }
    bool isFull() const { return no_of_elements == capacity; }

    int getHeight() const
    {
        if (no_of_elements == 0)
            return -1;
        return floor(log2(no_of_elements));
    }
bool insert(int rollNo, double cgpa){
if (isFull())
        {
            cout << "Heap Overflow\n";
            return 0;
        }
        st[no_of_elements].cgpa = cgpa;
        st[no_of_elements].rollNo = rollNo;
        heapifyUp(no_of_elements);
        no_of_elements++;
        return 1;
}
bool removeBestStudent (int& rollNo, double& cgpa){
    if(isEmpty()){
        return false;
    }
    rollNo = st[0].rollNo;
    cgpa = st[0].cgpa;
    st[0] = st[no_of_elements - 1];
        no_of_elements--;

        heapifyDown(0);
        return true;
}
    // void insert(int key)
    // {
    //     if (isFull())
    //     {
    //         cout << "Heap Overflow\n";
    //         return;
    //     }

    //     st[no_of_elements] = key;
    //     heapifyUp(no_of_elements);
    //     no_of_elements++;
    // }

    // Returns the maximum element (root)
    // Student getMax() const
    // {
    //     if (isEmpty())
    //     {
    //         cout << "Heap is empty\n";
    //         return -1;
    //     }
    //     return st[0];
    // }

    // // Extract maximum (root)
    // int extractMax()
    // {
    //     if (isEmpty())
    //     {
    //         cout << "Heap is empty\n";
    //         return -1;
    //     }

    //     int root = st[0];
    //     st[0] = st[no_of_elements - 1];
    //     no_of_elements--;

    //     heapifyDown(0);
    //     return root;
    // }

    // // Extract element from ANY index
    // int extractAtIndex(int i)
    // {
    //     if (i < 0 || i >= no_of_elements)
    //     {
    //         cout << "Invalid index\n";
    //         return -1;
    //     }

    //     int removedVal = st[i];
    //     st[i] = st[no_of_elements - 1];
    //     no_of_elements--;

    //     // Decide direction
    //     if (i != 0 && st[i] > st[parent(i)])
    //     {
    //         heapifyUp(i);
    //     }
    //     else
    //     {
    //         heapifyDown(i);
    //     }

    //     return removedVal;
    // }

    // // Decrease a key → for MaxHeap: new_val must be smaller
    // void decreaseKey(int i, int new_val)
    // {
    //     if (i >= no_of_elements || new_val > st[i])
    //     {
    //         cout << "Invalid decreaseKey\n";
    //         return;
    //     }

    //     st[i] = new_val;
    //     heapifyDown(i);
    // }

    // // Increase a key → new_val must be bigger
    // void increaseKey(int i, int new_val)
    // {
    //     if (i >= no_of_elements || new_val < st[i])
    //     {
    //         cout << "Invalid increaseKey\n";
    //         return;
    //     }

    //     st[i] = new_val;
    //     heapifyUp(i);
    // }

    // // Delete value at index i
    // void deleteKey(int i)
    // {
    //     if (i < 0 || i >= no_of_elements)
    //     {
    //         cout << "Invalid index\n";
    //         return;
    //     }

    //     increaseKey(i, INT_MAX); // make it maximum
    //     extractMax();
    // }

    void printHeap() const
    {
        for (int i = 0; i < no_of_elements; i++)
            cout << "Student " << i << " : " << "roll No : " <<st[i].rollNo << "CGPA : " << st[i].cgpa << endl;
    }
    void levelOrder(){
        for (int i = 0; i < no_of_elements;i++){
            cout << "Student " << i << " : " << "roll No : " <<st[i].rollNo <<"  "<< "CGPA : " << st[i].cgpa << endl;
        }
    }
    int height(){
        return (int)log2(no_of_elements) + 1;
    }
};

int main() { 
StudentMaxHeap heap(20); 
// ---- Add multiple sample students ---- 
heap.insert(10, 3.2); 
heap.insert(5, 3.9); 
heap.insert(12, 3.5); 
heap.insert(3, 3.9);   // Same CGPA as roll 5 (tie-break: smaller  
heap.insert(7, 2.8); 
heap.insert(18, 3.7); 
heap.insert(1, 4.0);   // Highest CGPA 
heap.insert(20, 3.4); 
heap.insert(11, 3.7);  // Same CGPA as roll 18 (tie-break) 
heap.insert(4, 3.8); 
cout << "===== Level Order After Insertions =====\n"; 
heap.levelOrder(); 
cout << endl;
cout << "\nHeight of the heap: " << heap.height() << endl; 
 
 
    // ---- Remove top student twice ---- 
    int roll; 
    double cg; 
 
    if (heap.removeBestStudent(roll, cg)) { 
        cout << "Removed Student - Roll No: " << roll 
             << ", CGPA: " << cg << endl; 
    } 
 
    if (heap.removeBestStudent(roll, cg)) { 
        cout << "Removed Student - Roll No: " << roll 
             << ", CGPA: " << cg << endl; 
    } 
 
    cout << "\n===== Level Order After Two Removals =====\n"; 
    heap.levelOrder(); 
 
    cout << "\nHeight of the heap: " << heap.height() << endl; 
 
    return 0; 
} 