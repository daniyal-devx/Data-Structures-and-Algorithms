#include <iostream>
#include <queue>
using namespace std;

class Graph {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node** adjList;
    int maxVertices;
    int n;
    bool* visited;

    void DFS(int v) {
        visited[v] = true;
        cout << v << " ";

        Node* temp = adjList[v];
        while (temp != NULL) {
            if (!visited[temp->data])
                DFS(temp->data);
            temp = temp->next;
        }
    }

public:
    Graph(int maxV, int currV) {
        maxVertices = maxV;
        n = currV;

        adjList = new Node*[maxVertices];
        for (int i = 0; i < maxVertices; i++)
            adjList[i] = NULL;

        visited = new bool[maxVertices];
        for (int i = 0; i < maxVertices; i++)
            visited[i] = false;
    }

    Graph(const Graph& other) {
        maxVertices = other.maxVertices;
        n = other.n;

        adjList = new Node*[maxVertices];
        for (int i = 0; i < maxVertices; i++)
            adjList[i] = NULL;

        for (int i = 0; i < n; i++) {
            Node* temp = other.adjList[i];
            Node** curr = &adjList[i];

            while (temp != NULL) {
                *curr = new Node;
                (*curr)->data = temp->data;
                (*curr)->next = NULL;
                curr = &((*curr)->next);
                temp = temp->next;
            }
        }

        visited = new bool[maxVertices];
        for (int i = 0; i < maxVertices; i++)
            visited[i] = other.visited[i];
    }

    ~Graph() {
        for (int i = 0; i < maxVertices; i++) {
            Node* temp = adjList[i];
            while (temp != NULL) {
                Node* del = temp;
                temp = temp->next;
                delete del;
            }
        }
        delete[] adjList;
        delete[] visited;
    }

    bool addVertex(int& v) {
        if (n >= maxVertices)
            return false;
        v = n;
        n++;
        return true;
    }

    bool addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= n || v >= n)
            return false;

        Node* newNode = new Node;
        newNode->data = v;
        newNode->next = adjList[u];
        adjList[u] = newNode;

        newNode = new Node;
        newNode->data = u;
        newNode->next = adjList[v];
        adjList[v] = newNode;

        return true;
    }

    bool removeEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= n || v >= n)
            return false;

        Node** temp = &adjList[u];
        while (*temp != NULL) {
            if ((*temp)->data == v) {
                Node* del = *temp;
                *temp = (*temp)->next;
                delete del;
                break;
            }
            temp = &((*temp)->next);
        }

        temp = &adjList[v];
        while (*temp != NULL) {
            if ((*temp)->data == u) {
                Node* del = *temp;
                *temp = (*temp)->next;
                delete del;
                break;
            }
            temp = &((*temp)->next);
        }

        return true;
    }

    bool isEmpty() {
        for (int i = 0; i < n; i++)
            if (adjList[i] != NULL)
                return false;
        return true;
    }

    bool isComplete() {
        for (int i = 0; i < n; i++) {
            int count = 0;
            Node* temp = adjList[i];
            while (temp != NULL) {
                count++;
                temp = temp->next;
            }
            if (count != n - 1)
                return false;
        }
        return true;
    }

    void clear() {
        for (int i = 0; i < n; i++) {
            Node* temp = adjList[i];
            while (temp != NULL) {
                Node* del = temp;
                temp = temp->next;
                delete del;
            }
            adjList[i] = NULL;
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            Node* temp = adjList[i];
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    int Degree(int v) {
        if (v < 0 || v >= n)
            return -1;

        int d = 0;
        Node* temp = adjList[v];
        while (temp != NULL) {
            d++;
            temp = temp->next;
        }
        return d;
    }

    void DFS() {
        for (int i = 0; i < n; i++)
            visited[i] = false;

        int start;
        cout << "Start DFS: ";
        cin >> start;

        if (start < 0 || start >= n)
            return;

        DFS(start);

        for (int i = 0; i < n; i++)
            if (!visited[i])
                DFS(i);

        cout << endl;
    }

    void BFS() {
        for (int i = 0; i < n; i++)
            visited[i] = false;

        int start;
        cout << "Start BFS: ";
        cin >> start;

        if (start < 0 || start >= n)
            return;

        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            Node* temp = adjList[v];
            while (temp != NULL) {
                if (!visited[temp->data]) {
                    visited[temp->data] = true;
                    q.push(temp->data);
                }
                temp = temp->next;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    cout << v << " ";

                    Node* temp = adjList[v];
                    while (temp != NULL) {
                        if (!visited[temp->data]) {
                            visited[temp->data] = true;
                            q.push(temp->data);
                        }
                        temp = temp->next;
                    }
                }
            }
        }
        cout << endl;
    }
};
int main() {
    Graph g(5, 0);
    int a, b, c, d, e;
    g.addVertex(a);
    g.addVertex(b);
    g.addVertex(c);
    g.addVertex(d);
    g.addVertex(e);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.display();
    g.DFS();
    g.BFS();
    
    return 0;
}
