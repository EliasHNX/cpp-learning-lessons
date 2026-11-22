#include <iostream>
#include <vector>
using namespace std;

int countEqualPairs(const vector<int>& numbers) {
    int counter = 0;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            if (numbers[i] == numbers[j]) {
                counter++;
            }
        }
    }
    return counter;
}

int main() {

    vector<int> numbers = {1,2,3};

    cout << "Equal pairs: " << countEqualPairs(numbers) << '\n';

    return 0;
}