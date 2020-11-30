#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

struct Rectangle {
    Point p1; 
    Point p2; 
};
void normalize(Rectangle* n_rec) {
    Point min;
    Point max;
    min.x = (n_rec->p1.x < n_rec->p2.x) ? n_rec->p1.x : n_rec->p2.x;
    min.y = (n_rec->p1.y < n_rec->p2.y) ? n_rec->p1.y : n_rec->p2.y;
    max.x = (n_rec->p1.x > n_rec->p2.x) ? n_rec->p1.x : n_rec->p2.x;
    max.y = (n_rec->p1.y > n_rec->p2.y) ? n_rec->p1.y : n_rec->p2.y;
    n_rec->p1 = min;
    n_rec->p2 = max;
}
double rectangle_square(Rectangle x) {
    return (x.p2.x - x.p1.x) * (x.p2.y - x.p1.y);
}
double rectangle_perimeter(Rectangle x) {
    return 2 * ((x.p2.x - x.p1.x) + (x.p2.y - x.p1.y));
}
int main() {
    Rectangle a;
    cin >> a.p1.x >> a.p1.y;
    cin >> a.p2.x >> a.p2.y;
    normalize(&a);
    cout << fixed << setprecision(6) << rectangle_square(a) << endl;
    cout << fixed << setprecision(6) << rectangle_perimeter(a) << endl;
}
/*
Пример работы:

Ввод:
5.00 9.00
7.00 13.00

Вывод:
8.000000
12.000000
*/
