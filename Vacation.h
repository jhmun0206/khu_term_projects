#ifndef VACATION_H
#define VACATION_H
#include<iostream>
using namespace std;

class Vacation {
public:
    virtual void bookHotels() = 0;
    virtual void bookFlights() = 0;
    virtual void bookTours() = 0;
};

class Package1 : public Vacation {
    void bookHotels() override {
        cout << "Hotels are booked.\n";
    }
    void bookFlights() override {
        cout << "Flights are booked.";
    }
    void bookTours() override {

    }
};
class Package2 : public Vacation {
    void bookHotels() override {
        cout << "Hotels are booked.\n";
    }
    void bookFlights() override {

    }
    void bookTours() override {
        cout << "Tours are booked.";
    }
};
class Package3 : public Vacation {
    void bookHotels() override {
        cout << "Hotels are booked.\n";
    }
    void bookFlights() override {
        cout << "Flights are booked.\n";
    }
    void bookTours() override {
        cout << "Tours are booked.";
    }
};

#endif