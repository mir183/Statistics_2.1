#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double calculateMedian(const vector<double>& data) {
    // Create a copy of the data to avoid modifying the original vector
    vector<double> sortedData = data;
    
    // Sort the data in ascending order
    sort(sortedData.begin(), sortedData.end());

    size_t size = sortedData.size();

    // Calculate the median
    return (size % 2 == 0) ? (sortedData[size / 2 - 1] + sortedData[size / 2]) / 2.0 : sortedData[size / 2];
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

    // Calculate and print the median
    cout << "Median: " << calculateMedian(data) << endl;

    return 0;
}
