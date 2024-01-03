#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double calculateGeometricMean(const vector<double>& data) {
    double product = 1.0;
    int n = data.size();

    // Calculate the product of all values
    for (double value : data) {
        product *= value;
    }

    // Calculate the geometric mean
    double geometricMean = pow(product, 1.0 / n);

    return geometricMean;
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

    // Calculate and print the geometric mean
    cout << "Geometric Mean: " << calculateGeometricMean(data) << endl;

    return 0;
}
