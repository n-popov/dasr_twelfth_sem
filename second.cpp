#include <iostream>
#include <vector>
#include <cmath>

class Polyline {
public:
    // Конструктур и деструктор, если необходимы

    // Добавить очередную точку в ломаную
    void addPoint(double x, double y) {
        points.emplace_back(x, y);
    }

    // Получить количесто точек в ломаной в данный момент
    unsigned int getNumberOfPoints() const {
        return points.size();
    }

    // Получить длину ломаной в данный момент
    double getLength() const {
        auto sum = 0.;
        for(auto i = 1u; i < points.size(); i++) {
            sum += std::sqrt(std::pow(points[i].first - points[i - 1].first, 2) +
                             std::pow(points[i].second - points[i - 1].second, 2));
        }
        return sum;
    }

    // Получить x-координату i-ой точки ломаной, точки нумеруются в порядке добавления
    // (Гарантируется, что номер i строго меньше, чем то, вернула ваша getNumberOfPoints())
    double getX(unsigned int i) const {
        return points[i].first;
    }

    // Получить y-координату i-ой точки ломаной, точки нумеруются в порядке добавления
    // (Гарантируется, что номер i строго меньше, чем то, вернула ваша getNumberOfPoints())
    double getY(unsigned int i) const {
        return points[i].second;
    }

private:
    std::vector<std::pair<double, double>> points;
};


using std::cin, std::cout, std::endl;

int main()
{
    Polyline p;
    p.addPoint(0.0, 0.0);
    p.addPoint(1.0, 0.0);
    p.addPoint(1.0, 1.0);
    cout << "Length: " << p.getLength() << endl;
    cout << "Points:" << endl;
    for(unsigned int i = 0; i < p.getNumberOfPoints(); i++) {
        cout << p.getX(i) << " " << p.getY(i) << endl;
    }
    return 0;
}