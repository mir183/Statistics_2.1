#include <iostream>
#include <vector>

using namespace std;

double calculateGroupedMedian(const vector<double>& lowerBounds, const vector<double>& upperBounds, const vector<int>& frequencies, int totalFrequency) {
    int middle = (totalFrequency + 1) / 2;
    double median;

    // Find the class interval containing the median
    int cumulativeFrequency = 0;
    size_t i = 0;
    while (cumulativeFrequency + frequencies[i] < middle) {
        cumulativeFrequency += frequencies[i];
        i++;
    }

    // Calculate the median using interpolation
    double lowerBound = lowerBounds[i];
    double upperBound = upperBounds[i];
    int frequency = frequencies[i];

    median = lowerBound + ((middle - cumulativeFrequency - 0.5) / frequency) * (upperBound - lowerBound);

    return median;
}

int main() {
    // Input the number of data points
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    // Input the lower bounds, upper bounds, and frequencies for each interval
    vector<double> lowerBounds;
    vector<double> upperBounds;
    vector<int> frequencies;
    int totalFrequency = 0;

    cout << "Enter the lower bounds, upper bounds, and frequencies for each interval:" << endl;
    for (int i = 0; i < n; ++i) {
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

        totalFrequency += frequency;
    }

    // Calculate and print the grouped median
    cout << "Grouped Median: " << calculateGroupedMedian(lowerBounds, upperBounds, frequencies, totalFrequency) << endl;

    return 0;
}
