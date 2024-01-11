#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate quartiles for ungrouped data
void calculateQuartiles(const vector<int>& data, double& q1, double& q3) {
    int n = data.size();

    // Ensure the data is sorted
    vector<int> sortedData = data;
    sort(sortedData.begin(), sortedData.end());

    // Calculate quartiles based on conditions
    if (n % 2 != 0) {  // If n is odd
        q1 = sortedData[(n + 1) / 4 - 1];
        q3 = sortedData[3 * (n + 1) / 4 - 1];
    } else {  // If n is even
        if (n % 4 == 0) {  // If n is even and divisible by 4
            q1 = 0.5 * (sortedData[n / 4 - 1] + sortedData[n / 4]);
            q3 = 0.5 * (sortedData[3 * n / 4 - 1] + sortedData[3 * n / 4]);
        } else {  // If n is even but not divisible by 4
            q1 = sortedData[(n / 2) / 2 - 1];
            q3 = sortedData[n / 2 + (n / 2) / 2 - 1];
        }
    }
}

// Function to calculate quartile deviation
double calculateQuartileDeviation(double q1, double q3) {
    return 0.5 * (q3 - q1);
}

// Main function
int main() {
    // Get input from the user for the dataset
    cout << "Enter the number of elements in the dataset: ";
    int n;
    cin >> n;

    vector<int> dataset;
    cout << "Enter the elements of the dataset, separated by spaces:\n";

    // Read the dataset from the user
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        dataset.push_back(value);
    }

    // Calculate quartiles
    double q1, q3;
    calculateQuartiles(dataset, q1, q3);

    // Calculate quartile deviation
    double qd = calculateQuartileDeviation(q1, q3);

    // Display quartile deviation
    cout << "Quartile Deviation (QD): " << qd << endl;

    return 0;
}
