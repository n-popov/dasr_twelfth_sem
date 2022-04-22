// Абстрактное транспортное средство
class Vehicle {
public:
    // Может ли ездить по суще
    virtual bool canDrive() const {
        return false;
    }

    // Может ли плавать
    virtual bool canSail() const {
        return false;
    }

    // Может ли летать
    virtual bool canFly() const {
        return false;
    }

    virtual ~Vehicle() {};
};

class Car : public Vehicle {
public:
    bool canDrive() const override {
        return true;
    }
};

class Ship : public Vehicle {
public:
    bool canSail() const override {
        return true;
    }
};

class Plane : public Vehicle {
public:
    bool canFly() const override {
        return true;
    }
};

class Truck: public Car {

};
