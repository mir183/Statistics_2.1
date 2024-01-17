#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

// Function to take user input for grouped data
void inputGroupedData(vector<int>& lowerValues, vector<int>& upperValues, vector<int>& frequencies) {
    int numIntervals;

    cout << "Enter the number of class intervals: ";
    cin >> numIntervals;

    lowerValues.resize(numIntervals);
    upperValues.resize(numIntervals);
    frequencies.resize(numIntervals);

    cout << "Enter the lower values, upper values, and frequencies of each class interval:\n";
    for (int i = 0; i < numIntervals; ++i) {
        cout << "Lower, Upper and Freq: " << i + 1 << ": ";
        cin >> lowerValues[i] >> upperValues[i] >> frequencies[i];
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

// Function to calculate the mid values
vector<double> calculateMidValues(const vector<int>& lowerValues, const vector<int>& upperValues) {
    int n = lowerValues.size();
    vector<double> midValues(n, 0.0);

    for (int i = 0; i < n; ++i) {
        midValues[i] = (lowerValues[i] + upperValues[i]) / 2.0;
    }

    return midValues;
}

// Function to calculate the sum of (midValue - mean)^4 * frequency for kurtosis calculation
double calculateSumQuarticTimesFrequency(const vector<double>& midValues, double mean, const vector<int>& frequencies) {
    int n = midValues.size();
    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        double quarticValue = pow(midValues[i] - mean, 4);
        sum += quarticValue * frequencies[i];
    }

    return sum;
}

int main() {
    // Input data for grouped standard deviation
    vector<int> lowerValues, upperValues, frequencies;
    inputGroupedData(lowerValues, upperValues, frequencies);

    // Calculate grouped standard deviation
    double groupedStdDev = calculateGroupedStandardDeviation(lowerValues, upperValues, frequencies);

    // Display the result
    cout << "Grouped Standard Deviation: " << groupedStdDev << endl;

    // Calculate mid values
    vector<double> midValues = calculateMidValues(lowerValues, upperValues);

    // Calculate kurtosis
    double mean = calculateMean(lowerValues, upperValues, frequencies);
    double sumQuarticTimesFrequency = calculateSumQuarticTimesFrequency(midValues, mean, frequencies);

    double n = accumulate(frequencies.begin(), frequencies.end(), 0);

    cout<<"Mean: "<<mean<<endl;
    cout<<"Sum of (midValue - mean)^4 * frequency: "<<sumQuarticTimesFrequency<<endl;
    cout<<"n-1: "<<n-1<<endl;

    double kurtosis = sumQuarticTimesFrequency / (n * pow(groupedStdDev, 4));

    cout << "Kurtosis: " << kurtosis << endl;

    return 0;
}
