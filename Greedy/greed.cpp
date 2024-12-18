#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Function to simulate the trip and return the number of days
string validateTrip(const vector<int>& arr) {
    int j = 0, days = 0;
    while (j < arr.size() - 1) {
        if (j == arr.size() - 2 && arr[arr.size() - 1] - arr[j] <= 300) {
            days++;
            break;
        }
        int i = j + 1;
        while (i <= arr.size() - 1) {
            if (arr[i] - arr[j] <= 300)
                i++;
            else
                break;
        }
        if (i > arr.size() - 1) {
            break;
        }
        if (i == j + 1)
            return "Impossible Tour";
        else {
            days++;
            j = i - 1;
        }
    }
    return "Number of Days: " + to_string(days);
}

// Function to run test cases
void runTests() {
    vector<vector<int> > testCases = {
        {0, 150, 300, 450, 600, 750},                      // Test Case 1
        {0, 250, 400, 600, 900, 1200},                    // Test Case 2
        {0, 300, 600, 900, 1500},                         // Test Case 3 (Impossible)
        {0, 200, 400, 700, 1000, 1300},                   // Test Case 4
        {0, 100, 200, 300, 400, 500, 800, 1100},          // Test Case 5
        {0, 300, 400, 700, 900, 1200, 1500}               // Test Case 6 (Impossible)
    };

    vector<string> expectedResults = {
        "Number of Days: 3",  // Expected for Test Case 1
        "Number of Days: 5",  // Expected for Test Case 2
        "Impossible Tour",    // Expected for Test Case 3
        "Number of Days: 5",  // Expected for Test Case 4
        "Number of Days: 4",  // Expected for Test Case 5
        "Number of Days: 6"     // Expected for Test Case 6
    };

    // Run all test cases
    for (int i = 0; i < testCases.size(); i++) {
        string result = validateTrip(testCases[i]);
        cout << "Test Case " << i + 1 << ": ";
        if (result == expectedResults[i]) {
            cout << "Passed!" << endl;
        } else {
            cout << "Failed! Expected: " << expectedResults[i] << ", Got: " << result << endl;
        }
    }
}

int main() {
    runTests();
    return 0;
}
