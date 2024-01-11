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

    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += data[i];
    }

    return sum / n;
}

// Function to calculate the standard deviation of a dataset
double calculateStandardDeviation(const vector<int>& data) {
    int n = data.size();
    if (n == 0) {
        cerr << "Error: Cannot calculate standard deviation for an empty dataset." << endl;
        return 0.0; // Return 0 as a default value
    }

    // Calculate mean
    double mean = calculateMean(data);

    // Calculate squared differences from the mean
    double sumSquaredDifferences = 0.0;
    for (int i = 0; i < n; ++i) {
        double difference = data[i] - mean;
        sumSquaredDifferences += difference * difference;
    }

    // Calculate variance
    double variance = sumSquaredDifferences / n;

    // Calculate standard deviation as the square root of variance
    double standardDeviation = sqrt(variance);

    return standardDeviation;
}

// Function to take user input for data values
vector<int> thevalues() {
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

// Main function
int main() {
    // Take user input for data values
    vector<int> data = thevalues();

    // Calculate standard deviation
    double stdDev = calculateStandardDeviation(data);

    // Display the result
    cout << "Standard Deviation: " << stdDev << endl;

    return 0;
}
