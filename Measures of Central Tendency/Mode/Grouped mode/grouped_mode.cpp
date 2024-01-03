#include <iostream>
#include <vector>

using namespace std;

vector<double> calculateGroupedMode(const vector<double>& lowerBounds, const vector<double>& upperBounds, const vector<int>& frequencies, int totalFrequency) {
    vector<double> modes;

    // Find the maximum frequency
    int maxFrequency = 0;
    for (int frequency : frequencies) {
        maxFrequency = max(maxFrequency, frequency);
    }

    // Find classes with the maximum frequency (modes)
    for (size_t i = 0; i < frequencies.size(); ++i) {
        if (frequencies[i] == maxFrequency) {
            // Calculate the mode using interpolation
            double lowerBound = lowerBounds[i];
            double upperBound = upperBounds[i];
            double mode = lowerBound + (maxFrequency - 0.5) / frequencies[i] * (upperBound - lowerBound);

            modes.push_back(mode);
        }
    }

    return modes;
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

    // Calculate and print the grouped mode(s)
    vector<double> modes = calculateGroupedMode(lowerBounds, upperBounds, frequencies, n);

    if (modes.size() == 1) {
        cout << "Mode: " << modes[0] << endl;
    } else if (modes.size() > 1) {
        cout << "Modes: ";
        for (double mode : modes) {
            cout << mode << " ";
        }
        cout << endl;
    } else {
        cout << "No mode found." << endl;
    }

    return 0;
}
