#include <iostream>
using namespace std;

int countSquares(int k, int cx, int cy, int px, int py) {
    bool inside = (px >= cx - k) && (px <= cx + k) && 
                  (py >= cy - k) && (py <= cy + k);
    
    int count = inside ? 1 : 0;
    
    if (k <= 1) {
        return count;
    }
    
    int new_k = k / 2;
    
    count += countSquares(new_k, cx - k, cy - k, px, py);
    count += countSquares(new_k, cx - k, cy + k, px, py);
    count += countSquares(new_k, cx + k, cy - k, px, py);
    count += countSquares(new_k, cx + k, cy + k, px, py);
    
    return count;
}

int main() {
    int k, px, py;
    
    cout << "Enter k and coordinates (px py): ";
    cin >> k >> px >> py;
    
    int result = countSquares(k, 1024, 1024, px, py);
    
    cout << "Number of squares surrounding the point: " << result << endl;
    
    return 0;
}