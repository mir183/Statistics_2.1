#include <iostream>
#include <vector>
#include <cmath>
#include <numeric> 

using namespace std;

// Function to take user input for grouped data
void values(vector<int>& lowerValues, vector<int>& upperValues, vector<int>& frequencies) {
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
}

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

// Function to calculate the grouped standard deviation
double calculateGroupedStandardDeviation(const vector<int>& lowerValues, const vector<int>& upperValues, const vector<int>& frequencies) {
    int n = lowerValues.size();
    if (n == 0 || n != upperValues.size() || n != frequencies.size()) {
        cerr << "Error: Invalid input for calculating grouped standard deviation." << endl;
        return 0.0; // Return 0 as a default value
    }

    double mean = calculateMean(lowerValues, upperValues, frequencies);

    double sumSquaredDifferences = 0.0;
    for (int i = 0; i < n; ++i) {
        double midpoint = (lowerValues[i] + upperValues[i]) / 2.0;
        sumSquaredDifferences += frequencies[i] * (midpoint - mean) * (midpoint - mean);
    }

    double variance = sumSquaredDifferences / accumulate(frequencies.begin(), frequencies.end(), 0);

    double standardDeviation = sqrt(variance);

    return standardDeviation;
}

// Main function
int main() {
    // Input data for grouped standard deviation
    vector<int> lowerValues, upperValues, frequencies;
    values(lowerValues, upperValues, frequencies);

    // Calculate grouped standard deviation
    double groupedStdDev = calculateGroupedStandardDeviation(lowerValues, upperValues, frequencies);

    // Display the result
    cout << "Grouped Standard Deviation: " << groupedStdDev << endl;

    return 0;
}
