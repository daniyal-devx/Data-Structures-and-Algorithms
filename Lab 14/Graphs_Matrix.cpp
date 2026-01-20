#include <iostream>
#include <queue>
using namespace std;

class Graph {
private:
    int** adjMatrix;
    int maxVertices;
    int n;
    bool* visited;

    void DFS(int v) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (adjMatrix[v][i] == 1 && !visited[i])
                DFS(i);
        }
    }
public:
    Graph(int maxV, int currV) {
        maxVertices = maxV;
        n = currV;

        adjMatrix = new int*[maxVertices];
        for (int i = 0; i < maxVertices; i++)
            adjMatrix[i] = new int[maxVertices];
        for (int i = 0; i < maxVertices; i++)
            for (int j = 0; j < maxVertices; j++)
                adjMatrix[i][j] = 0;
        visited = new bool[maxVertices];
        for (int i = 0; i < maxVertices; i++)
            visited[i] = false;
    }
    Graph(const Graph& other) {
        maxVertices = other.maxVertices;
        n = other.n;
        adjMatrix = new int*[maxVertices];
        for (int i = 0; i < maxVertices; i++)
            adjMatrix[i] = new int[maxVertices];
        for (int i = 0; i < maxVertices; i++)
            for (int j = 0; j < maxVertices; j++)
                adjMatrix[i][j] = other.adjMatrix[i][j];
        visited = new bool[maxVertices];
        for (int i = 0; i < maxVertices; i++)
            visited[i] = other.visited[i];
    }

    ~Graph() {
        for (int i = 0; i < maxVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
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
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        return true;
    }
    
    bool removeEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= n || v >= n)
            return false;
        adjMatrix[u][v] = 0;
        adjMatrix[v][u] = 0;
        return true;
    }

    bool isEmpty() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (adjMatrix[i][j] == 1)
                    return false;
        return true;
    }

    bool isComplete() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && adjMatrix[i][j] == 0)
                    return false;
        return true;
    }

    void clear() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adjMatrix[i][j] = 0;
    }
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }
    int Degree(int v) {
        if (v < 0 || v >= n)
            return -1;

        int d = 0;
        for (int i = 0; i < n; i++)
            if (adjMatrix[v][i] == 1)
                d++;
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

            for (int i = 0; i < n; i++) {
                if (adjMatrix[v][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
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

                    for (int j = 0; j < n; j++) {
                        if (adjMatrix[v][j] == 1 && !visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
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
