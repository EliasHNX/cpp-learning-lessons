#include <iostream>
#include <vector>
using namespace std;

int countAbove(const vector<int>& numbers, int threshold) {
    int count = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] > threshold) {
            count++;
        }
    }
    return count;
}

int sumAbove (const vector<int>& numbers, int threshold) {
    int total = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] > threshold) {
            total += numbers[i];
        }
    }
    return total;
}

int countInRange(const vector<int>& numbers, int low, int high) {
    int counter = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] >= low && numbers[i] <= high) {
            counter++;
        }
    }
    return counter;
}

int sumInRange(const vector<int>& numbers, int low, int high) {
    int totalSum = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] >= low && numbers[i] <= high) {
            totalSum += numbers[i];
        }
    }
    return totalSum;
}

int countOutsideRange(const vector<int>& numbers, int low, int high) {
    int counterOutsideRange = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] < low || numbers[i] > high) {
            counterOutsideRange++;
        }
    }
    return counterOutsideRange;
}

int longestStreakAbove(const vector<int>& numbers, int threshold) {
    int longestStreak = 0;
    int currentStreakCounter = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] > threshold) {
            currentStreakCounter++;

            if (currentStreakCounter > longestStreak) {
                longestStreak = currentStreakCounter;
            }
        }
        else {
            currentStreakCounter = 0;
        }
    }
    return longestStreak;
}

int countStreaksAbove(const vector<int>& numbers, int threshold) {
    int completedStreaksCount = 0;
    bool active = false;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] > threshold) {
            active = true;
        }
        else if (active == true) {
             completedStreaksCount++;
             active = false;
        }
    }
    if (active == true) {
        completedStreaksCount++;
    }
    return completedStreaksCount;
}

int longestStreakBelow(const vector<int>& numbers,int threshold) {
    int longestSmallestStreak = 0;
    int currentSmallStreakCounter = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] < threshold) {
            currentSmallStreakCounter++;

            if (currentSmallStreakCounter > longestSmallestStreak) {
                longestSmallestStreak = currentSmallStreakCounter;
            }
        }
        else {
            currentSmallStreakCounter = 0;
        }
            
    }
    return longestSmallestStreak;
}

int longestIncreasingStreak(const vector<int>& numbers) {
    if (numbers.empty()) {
        cout << "The vector has no elements to count." << '\n';
        return 0;
    }
    int currentlen = 1;
    int longestlen = 1;
    for (int i = 0; i + 1 < numbers.size(); i++) {
        if (numbers[i] < numbers[i + 1]) {
            currentlen++;
        }
        else {
            currentlen = 1;
        }
        if (currentlen > longestlen) {
            longestlen = currentlen;
        }
    }
    return longestlen;
}

int main() {

    vector<int> numbers = {6, 8, 2, 9, 7, 10};

    cout << countAbove(numbers, 5) << '\n';

    cout << sumAbove(numbers, 5) << '\n';

    cout << "Count inside: " << countInRange(numbers, 3, 5) << '\n';

    cout << sumInRange(numbers, 3, 5) << '\n';

    cout << "Count outside: " << countOutsideRange(numbers, 3, 5) << '\n';
    
    cout << "Longest streak: " << longestStreakAbove(numbers, 5) << '\n';

    cout << "all streaks: " << countStreaksAbove(numbers, 5) << '\n';

    cout << "Longest streak below the threshold: " << longestStreakBelow(numbers, 5) << '\n';

    cout << "Longest increasing streak: " << longestIncreasingStreak(numbers) << '\n';

    return 0;
}