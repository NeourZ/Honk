#include <iostream>
using namespace std;

struct Rect {
    double x, y, w, h;
};

double overlap(const Rect& R1, const Rect& R2) {
    // Calculate the coordinates of the overlapping region
    double x1 = max(R1.x, R2.x);
    double x2 = min(R1.x + R1.w, R2.x + R2.w);
    double y1 = max(R1.y, R2.y);
    double y2 = min(R1.y + R1.h, R2.y + R2.h);

    // Check if there is an overlap in both dimensions
    if (x1 < x2 && y1 < y2) {
        // Calculate the area of the overlapping region
        double area_overlap = (x2 - x1) * (y2 - y1);
        return area_overlap;
    } else {
        // No overlap
        return 0;
    }
}

int main() {
    Rect R1 = {1, 1, 5, 5};
    Rect R2 = {2, 2, 5, 5};
    cout << overlap(R1, R2) << endl; // Output: 12

    Rect R3 = {1, 1, 5, 5};
    Rect R4 = {7, 2, 3, 3};
    cout << overlap(R3, R4) << endl; // Output: 0

    Rect R5 = {-1, 2, 6.9, 9.6};
    Rect R6 = {0, 0, 1.2, 2.5};
    cout << overlap(R5, R6) << endl; // Output: 3

    return 0;
}
