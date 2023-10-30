#include <iostream>
#include <cmath>

class Informer {
public:
    Informer() {
        std::cout << "Informer: Konstrukcja" << std::endl;
    }

    ~Informer() {
        std::cout << "Informer: Destrukcja" << std::endl;
    }
};

class Wektor2D {
private:
    double x;
    double y;
    Informer informer;
    static int num_wek;

    

public:
    Wektor2D(double nx, double ny) {
        x = nx;
        y = ny;
        num_wek++;
    }
    Wektor2D() {
        x = 0.0;
        y = 0.0;
        num_wek++;
    }
    static Wektor2D kart(double x, double y) {
        return Wektor2D(x, y);
    }

    static Wektor2D bieg(double r, double theta) {
        double x = r * std::cos(theta);
        double y = r * std::sin(theta);
        return Wektor2D(x, y);
    }

    double norm() {
        return std::sqrt(x * x + y * y);
    }

    void print() {
        std::cout << "Wektor: (" << x << ", " << y << ")" << std::endl;
    }

    ~Wektor2D() {
        num_wek--;
    }

    void setX(double newX) {
        x = newX;
    }

    double getX() {
        return x;
    }

    void setY(double newY) {
        y = newY;
    }

    double getY() {
        return y;
    }

    Wektor2D operator+(const Wektor2D& other) 
    {
        return Wektor2D(x + other.x, y + other.y);
    }
    double operator*(const Wektor2D& other)
    {
        return (x * other.x + y * other.y);
    }
    friend std::ostream& operator<<(std::ostream& os, const Wektor2D& wektor) {
        os << "Wektor: (" << wektor.x << ", " << wektor.y << ")";
        return os;
    }

    static int populacja() {
        return num_wek;
    }
};

int Wektor2D::num_wek = 0;
