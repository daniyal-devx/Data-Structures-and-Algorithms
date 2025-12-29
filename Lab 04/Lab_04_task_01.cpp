#include<iostream>
#include<string>
#include "../Stack.h"


using namespace std;

void solve_maze(char maze[6][6], Pair start, Pair dest, int row, int col) {
    // Create a stack to store our path - make it large enough for the maze
    Stack<Pair> path(50);
    
    // Push the starting position onto the stack
    path.push(start);
    
    // Mark the starting position as visited by changing it to '#'
    maze[start.row][start.col] = '#';
    
    // Directions: up, right, down, left
    int rowDirections[] = {-1, 0, 1, 0};
    int colDirections[] = {0, 1, 0, -1};
    
    bool found = false;
    
    // Main exploration loop
    while (!path.isEmpty()) {
        // Get current position using peek() (look without removing)
        Pair current = path.peek();
        
        // Check if we reached destination
        if (current.row == dest.row && current.col == dest.col) {
            found = true;
            break;
        }
        
        // Try to move in all 4 directions
        bool moved = false;
        for (int i = 0; i < 4; i++) {
            int newRow = current.row + rowDirections[i];
            int newCol = current.col + colDirections[i];
            
            // Check if new position is within bounds
            if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col) {
                // Check if it's passable (space) or target (T) and not visited
                if (maze[newRow][newCol] == ' ' || maze[newRow][newCol] == 'T') {
                    // Mark as visited and push to stack
                    maze[newRow][newCol] = '#';
                    Pair newPos = {newRow, newCol};
                    path.push(newPos);
                    moved = true;
                    break; // Move to this new position
                }
            }
        }
        
        // If couldn't move, backtrack by popping from stack
        if (!moved) {
            path.pop();
        }
    }
    
    // Output results
    if (found) {
        cout << "solved" << endl;
        
        // To print path in correct order (start to end), we need to reverse it
        Stack<Pair> tempStack(50);
        
        // Transfer from path stack to temp stack to reverse order
        while (!path.isEmpty()) {
            tempStack.push(path.peek());
            path.pop();
        }
        
        // Now transfer back to original stack (optional) and print
        cout << "Path: ";
        while (!tempStack.isEmpty()) {
            Pair pos = tempStack.peek();
            cout << "(" << pos.row << "," << pos.col << ") ";
            tempStack.pop();
        }
        cout << endl;
    } else {
        cout << "unsolved" << endl;
    }
    
    cout << "-------------------" << endl;
}

int main() {
    // First maze
    char maze1[6][6] = {
        {' ', '*', ' ', '*', ' ', ' '},
        {' ', '*', ' ', '*', ' ', ' '},
        {'P', ' ', ' ', ' ', '*', ' '},
        {'*', ' ', '*', '*', '*', ' '},
        {' ', ' ', ' ', ' ', '*', 'T'},
        {'*', ' ', ' ', ' ', ' ', ' '}
    };
    
    Pair start = {2, 0};
    Pair dest = {4, 5};
    
    cout << "Maze 1:" << endl;
    solve_maze(maze1, start, dest, 6, 6);
    
    // Second maze
    char maze2[6][6] = {
        {' ', '*', ' ', '*', ' ', ' '},
        {' ', '*', ' ', '*', ' ', ' '},
        {'P', ' ', ' ', ' ', '*', ' '},
        {'*', '*', '*', '*', '*', ' '},
        {' ', ' ', ' ', ' ', '*', 'T'},
        {'*', ' ', ' ', ' ', ' ', ' '}
    };
    
    cout << "Maze 2:" << endl;
    solve_maze(maze2, start, dest, 6, 6);
    
    return 0;
}