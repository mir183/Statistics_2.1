#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to calculate the mean of a dataset
double calculateMean(const vector<int>& lowerValues, const vector<int>& upperValues, const vector<int>& frequencies) {
    int n = lowerValues.size();
    if (n == 0 || n != upperValues.size() || n != frequencies.size()) {
        cerr << "Error: Invalid input for calculating mean." << endl;
        return 0.0; // Return 0 as a default value
    }

    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += (lowerValues[i] + upperValues[i]) / 2.0 * frequencies[i];
    }

    return sum / accumulate(frequencies.begin(), frequencies.end(), 0);
}

// Function to calculate the median of a dataset
double calculateMedian(const vector<int>& lowerValues, const vector<int>& upperValues, const vector<int>& frequencies) {
    int n = lowerValues.size();
    if (n == 0 || n != upperValues.size() || n != frequencies.size()) {
        cerr << "Error: Invalid input for calculating median." << endl;
        return 0.0; // Return 0 as a default value
    }

    vector<int> data;
    for (int i = 0; i < n; ++i) {
        int midpoint = (lowerValues[i] + upperValues[i]) / 2;
        data.insert(data.end(), frequencies[i], midpoint);
    }

    sort(data.begin(), data.end());

    if (data.size() % 2 == 0) {
        int mid1 = data[data.size() / 2 - 1];
        int mid2 = data[data.size() / 2];
        return (mid1 + mid2) / 2.0;
    } else {
        return data[data.size() / 2];
    }
}

// Function to calculate the grouped mean deviation
double calculateGroupedMeanDeviation(const vector<int>& lowerValues, const vector<int>& upperValues, const vector<int>& frequencies, char choice) {
    int n = lowerValues.size();
    if (n == 0 || n != upperValues.size() || n != frequencies.size()) {
        cerr << "Error: Invalid input for calculating grouped mean deviation." << endl;
        return 0.0; // Return 0 as a default value
    }

    double centralValue;
    centralValue = calculateMean(lowerValues, upperValues, frequencies);


    double deviationSum = 0.0;
    for (int i = 0; i < n; ++i) {
        double midpoint = (lowerValues[i] + upperValues[i]) / 2.0;
        deviationSum += frequencies[i] * abs(midpoint - centralValue);
    }

    return deviationSum / accumulate(frequencies.begin(), frequencies.end(), 0);
}

// Main function
int main() {
    // Input data for grouped mean deviation
    vector<int> lowerValues, upperValues, frequencies;
    char choice;

    cout << "Enter the number of class intervals: ";
    int numIntervals;
    cin >> numIntervals;

    lowerValues.resize(numIntervals);
    upperValues.resize(numIntervals);
    frequencies.resize(numIntervals);

    cout << "Enter the lower values, upper values, and frequencies of each class interval:\n";
    for (int i = 0; i < numIntervals; ++i) {
        cout << "Lower value of class " << i + 1 << ": ";
        cin >> lowerValues[i];

        cout << "Upper value of class " << i + 1 << ": ";
        cin >> upperValues[i];

        cout << "Frequency of class " << i + 1 << ": ";
        cin >> frequencies[i];
    }

    // Calculate grouped mean deviation
    double groupedMeanDeviation = calculateGroupedMeanDeviation(lowerValues, upperValues, frequencies, choice);

    // Display the result
    cout << "Grouped Mean Deviation: " << groupedMeanDeviation << endl;

    return 0;
}
