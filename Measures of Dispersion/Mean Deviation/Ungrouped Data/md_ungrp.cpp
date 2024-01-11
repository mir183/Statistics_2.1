#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the mean of a dataset
double calculateMean(const vector<int>& data) {
    int n = data.size();
    if (n == 0) {
        cerr << "Error: Cannot calculate mean for an empty dataset." << endl;
        return 0.0; // Return 0 as a default value
    }

    double sum = 0.0; // Use double for more accurate mean calculation
    for (int i = 0; i < n; ++i) {
        sum += data[i];
    }

    return sum / n;
}

// Function to take user input for data values
vector<int> inp() {
    cout << "Enter the number of data points: ";
    int n;
    cin >> n;

    vector<int> data(n);
    cout << "Enter the data points:\n";
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    return data;
}

// Function to calculate the mean deviation for ungrouped data
double calculateMeanDeviation(const vector<int>& data) {
    int n = data.size();
    if (n == 0) {
        cerr << "Error: Cannot calculate mean deviation for an empty dataset." << endl;
        return 0.0; // Return 0 as a default value
    }

    double mean = calculateMean(data);
    double deviationSum = 0.0;

    for (int i = 0; i < n; ++i) {
        deviationSum += abs(data[i] - mean);
    }

    return deviationSum / n;
}

// Main function
int main() {
    // Take user input for data values
    vector<int> data = inp();

    // Calculate mean deviation
    double meanDeviation = calculateMeanDeviation(data);

    // Display the result
    cout << "Mean Deviation: " << meanDeviation << endl;

    return 0;
}
