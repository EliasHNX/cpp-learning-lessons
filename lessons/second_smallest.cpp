#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {6, 2, 9, 7};
    if (numbers.empty()) {
        cout << "No numbers to compare.\n";
        return 0;
    }

    int smallest = numbers[0];

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }

    int secondSmallest = 0;
    bool found = false;

    for (int x : numbers) {
        if (x > smallest) {
            if (!found || x < secondSmallest) {
                secondSmallest = x;
                cout << "New candidate: " << secondSmallest << '\n';
                found = true;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] > 5 && numbers[i] % 2 == 0) {
           count++;
        }
    }

    cout << "Count: " << count << '\n';

    if (found) {
        cout << "Second-smallest: " << secondSmallest << '\n';
    }
    else{
        cout << "No second distinct value\n";
    }

    cout << "Smallest: " << smallest << '\n';
}