#include <iostream>
#include <vector>

using namespace std;

double calculateHarmonicMean(const vector<double>& data) {
    double reciprocalSum = 0.0;

    // Calculate the sum of reciprocals
    for (double value : data) {
        reciprocalSum += 1.0 / value;
    }

    // Calculate the harmonic mean
    double harmonicMean = data.size() / reciprocalSum;

    return harmonicMean;
}

int main() {
    // Input the number of data points
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    // Input the data points
    vector<double> data;
    cout << "Enter the data points:" << endl;
    for (int i = 0; i < n; ++i) {
        double value;
        cin >> value;
        data.push_back(value);
    }

    // Calculate and print the harmonic mean
    cout << "Harmonic Mean: " << calculateHarmonicMean(data) << endl;

    return 0;
}
