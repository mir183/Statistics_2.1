#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<double> calculateMode(const vector<double>& data) {
    unordered_map<double, int> frequencyMap;

    // Count the frequency of each value
    for (double value : data) {
        frequencyMap[value]++;
    }

    // Find the maximum frequency
    int maxFrequency = 0;
    for (const auto& pair : frequencyMap) {
        maxFrequency = max(maxFrequency, pair.second);
    }

    // Find values with the maximum frequency (modes)
    vector<double> modes;
    for (const auto& pair : frequencyMap) {
        if (pair.second == maxFrequency) {
            modes.push_back(pair.first);
        }
    }

    return modes;
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

    // Calculate and print the mode(s)
    vector<double> modes = calculateMode(data);

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
