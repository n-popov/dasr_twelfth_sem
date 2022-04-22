#include <iostream>

using std::cin, std::cout, std::endl;

class Rational {
public:
    // Конструктор дроби, здесь a - числитель, b - знаменатель
    Rational(int a, int b): numerator(a), denominator(b) {}

    // Реализуйте операторы:
    // - сложения двух дробей
    Rational operator+(Rational other) const {
        return {numerator * other.denominator + denominator * other.numerator,
                denominator * other.denominator};
    }

    Rational operator-(Rational other) const {
        return Rational(numerator * other.denominator - denominator * other.numerator,
                        denominator * other.denominator);
    }

    Rational operator*(Rational other) const {
        return Rational(numerator * other.numerator,
                        denominator * other.denominator);
    }

    Rational operator/(Rational other) const {
        return Rational(numerator * other.denominator,
                        denominator * other.numerator);
    }

    Rational operator*(int number) const {
        return {numerator * number, denominator};
    }

    friend std::ostream& operator<<(std::ostream&, Rational);
    // - вычитания двух дробей
    // - умножения двух дробей
    // - деления двух дробей
    // - умножения дроби на целое число (должно работать при любом порядке операндов)
private:
    int numerator, denominator;
};

Rational operator*(int number, Rational other) {
    return other * number;
}

std::ostream& operator<<(std::ostream& out, Rational rational) {
    return out << rational.numerator << '/' << rational.denominator;
}

int main()
{
    Rational a(1, 2);
    Rational b(1, 3);

    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << 3 * a << endl;
    cout << b * 4 << endl;

    return 0;
}