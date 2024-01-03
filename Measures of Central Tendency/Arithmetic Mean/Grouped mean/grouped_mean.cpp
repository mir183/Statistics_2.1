#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

double calculateArithmeticMeanGrouped(const vector<double>& lowerBounds, const vector<double>& upperBounds, const vector<int>& frequencies) {
    double sumProducts = 0.0;
    int totalFrequency = 0;

    // Calculate the sum of products and total frequency
    for (size_t i = 0; i < lowerBounds.size(); ++i) {
        double midpoint = (lowerBounds[i] + upperBounds[i]) / 2.0;
        sumProducts += midpoint * frequencies[i];
        totalFrequency += frequencies[i];
    }

    // Calculate the mean
    return sumProducts / totalFrequency;
}

int main() {
    // Input the number of class intervals
    int numIntervals;
    cout << "Enter the number of class intervals: ";
    cin >> numIntervals;

    // Input the lower bounds, upper bounds, and frequencies for each interval
    vector<double> lowerBounds;
    vector<double> upperBounds;
    vector<int> frequencies;
    cout << "Enter the lower bounds, upper bounds, and frequencies for each interval:" << endl;
    for (int i = 0; i < numIntervals; ++i) {
        double lowerBound, upperBound;
        int frequency;
        cout << "Lower bound for interval " << (i + 1) << ": ";
        cin >> lowerBound;
        cout << "Upper bound for interval " << (i + 1) << ": ";
        cin >> upperBound;
        cout << "Frequency for interval " << (i + 1) << ": ";
        cin >> frequency;
        lowerBounds.push_back(lowerBound);
        upperBounds.push_back(upperBound);
        frequencies.push_back(frequency);
    }

    // Calculate and print the grouped arithmetic mean
    cout << "Arithmetic Mean (Grouped): " << calculateArithmeticMeanGrouped(lowerBounds, upperBounds, frequencies) << endl;

    return 0;
}
