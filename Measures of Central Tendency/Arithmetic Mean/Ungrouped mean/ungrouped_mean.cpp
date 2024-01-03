#include <iostream>
#include <vector>
#include <numeric> // for using accumulate()

using namespace std;

double calculateArithmeticMean(const vector<double>& data) {
    double sum = 0.0;

    sum = accumulate(data.begin(), data.end(), 0.0); //0.0 is need for the sum to be double



    // Calculate the mean
    return sum / data.size();
}

int main() {
    // Input the number of data points
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    // Input the data points
    vector<double> data;
    cout << "Enter the data points: ";
    for (int i = 0; i < n; ++i) {
        double value;
        cin >> value;
        data.push_back(value);
    }

    // Calculate and print the arithmetic mean
    cout << "Arithmetic Mean: " << calculateArithmeticMean(data) << endl;

    return 0;
}
