// Charlie's collection
// Dylan Strnad
// 4/18/2024

#include"collection.h"
#include <iostream>


using std::cout; using std::cin; using std::endl;

int main() {

    Collection c1; // creates object of class

    bool resume = true;

    while (resume) {
        char operation;
        double num;
        cout << "Charlie, enter operation [a/r/q] and a number:";
        cin >> operation >> num;

        if (operation == 'a') {
            c1.check(num);
            c1.addNumber(num);
            c1.output();
            cout << "Total value: " << c1.value() << endl;
        }
        else if (operation == 'r') {
            c1.removeNumber(num);
            c1.output();
            cout << "Total value: " << c1.value() << endl;
        }
        else {
            resume = false;
        }
    }

}