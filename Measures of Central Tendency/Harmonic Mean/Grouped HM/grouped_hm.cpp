#include <iostream>
#include <vector>

using namespace std;

double calculateGroupedHarmonicMean(const vector<double>& lowerBounds, const vector<double>& upperBounds, const vector<int>& frequencies) {
    double reciprocalSum = 0;  // Initialize to 0, not 0.0

    // Calculate the sum of reciprocals
    for (size_t i = 0; i < lowerBounds.size(); ++i) {
        double classMidpoint = (lowerBounds[i] + upperBounds[i]) / 2.0;
        reciprocalSum += 1.0 / classMidpoint;  // Accumulate the reciprocal sum
    }

    // Calculate the grouped harmonic mean
    double groupedHarmonicMean = frequencies.size() / reciprocalSum;  // Use sum of frequencies, not frequencies.size()

    return groupedHarmonicMean;
}

int main() {
    // Input the number of data points
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    // Input the lower bounds, upper bounds, and frequencies for each data point
    vector<double> lowerBounds(n);
    vector<double> upperBounds(n);
    vector<int> frequencies(n);

    cout << "Enter the lower bounds, upper bounds, and frequencies for each data point:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Data point " << (i + 1) << ":" << endl;
        cout << "Lower bound: ";
        cin >> lowerBounds[i];
        cout << "Upper bound: ";
        cin >> upperBounds[i];
        cout << "Frequency: ";
        cin >> frequencies[i];
    }

    // Calculate and print the grouped harmonic mean
    cout << "Harmonic Mean: " << calculateGroupedHarmonicMean(lowerBounds, upperBounds, frequencies) << endl;

    return 0;
}
