#include <iostream>
#define _USE_MATH_DEFINES


using namespace std;

class circle {
private:
    float radius;
    float x_center;
    float y_center;
public:
    circle(float r, float x, float y);
    void set_circle(float r, float x, float y);
    float square();
    bool triangle_around(float a, float b, float c);
    bool triangle_in(float a, float b, float c);
    bool check_circle(float r, float x_cntr, float y_cntr);
};

class Triangle
{
private:
    float a, b, c;
public:
    bool exst_tr();
    void set(double a1, double b1, double c1);
    void show();
    double perimetr();
    double square();
};

bool Triangle::exst_tr() {
    return ((a + b > c) && (b + c > a) && (a + c > b));
}
void Triangle::set(double a1, double b1, double c1) {
    a = a1;
    b = b1;
    c = c1;
}
void Triangle::show() {
    cout << "1 сторона: " << a << endl;
    cout << "2 сторона: " << b << endl;
    cout << "3 сторона: " << c << endl;
}
double Triangle::perimetr() {
    double p = a + b + c;
    return p;
}
double Triangle::square() {
    double p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    return s;
}
circle::circle(float r, float x, float y) {
    radius = r;
    x_center = x;
    y_center = y;
}
void circle::set_circle(float r, float x, float y) {
    radius = r;
    x_center = x;
    y_center = y;
}
float circle::square() {
    return 3.14f * pow(2, radius);
}
bool circle::triangle_around(float a, float b, float c) {
    Triangle tr;

    tr.set(a, b, c);

    float rad = (a * b * c) / (tr.square() * 4);

    return radius == rad;
}
bool circle::triangle_in(float a, float b, float c) {
    Triangle tr;

    tr.set(a, b, c);

    float rad = tr.square() / ((a + b + c) * 0.5);

    return radius == rad;
}
bool circle::check_circle(float r, float x_cntral, float y_cntral) {
    float cntral_dist = sqrtf(pow(x_center - x_cntral, 2) + pow(y_center - y_cntral, 2));

    return (cntral_dist < (radius + r));
}

int main()
{
    circle circles[3]{
        circle(0, 0, 0),
        circle(0, 0, 0),
        circle(0, 0, 0)
    };

    float r, x, y;

    for (int i = 0; i < 3; i++) {
        cout << "Enter radius of the circle #" << i + 1 << " and coords of its center (X Y) separated by space: ";

        cin >> r >> x >> y;

        circles[i].set_circle(r, x, y);
    }

    for (int i = 0; i < 3; i++) {
        cout << "Square of circle #" << i + 1 << ": " << circles[i].square() << ";" << endl;

        float a, b, c;

        cout << "Enter sides for triangle which could be in or out of circle #" << i + 1 << " separated by space: ";

        cin >> a >> b >> c;

        cout << "Can given triangle be in: " << circles[i].triangle_in(a, b, c) << "or out: " << circles[i].triangle_around(a, b, c) << ";" << endl;

        float r1, x1, y1;

        cout << "Enter the pos for circle, which could be intersected with current circle: ";

        cin >> r1 >> x1 >> y1;

        cout << "Is given circle intersected with current: " << circles[i].check_circle(r1, x1, y1) << ";" << endl;
    }
}