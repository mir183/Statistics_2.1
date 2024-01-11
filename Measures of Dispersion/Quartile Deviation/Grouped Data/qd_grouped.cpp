#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate quartiles for grouped data
void calculateQuartiles(const vector<int>& lowerValues, const vector<int>& upperValues, const vector<int>& frequencies, double& q1, double& q3) {
    int n = lowerValues.size();

    // Check for empty or invalid input
    if (n == 0 || lowerValues.size() != upperValues.size() || lowerValues.size() != frequencies.size()) {
        // Handle invalid input gracefully (e.g., throw an exception or return an error code)
        return;
    }

    // Calculate cumulative frequencies
    vector<int> cumulativeFrequencies(n, 0);
    cumulativeFrequencies[0] = frequencies[0];
    for (int i = 1; i < n; ++i) {
        cumulativeFrequencies[i] = cumulativeFrequencies[i - 1] + frequencies[i];
    }

    // Calculate quartile positions
    int q1Position = ceil(0.25 * cumulativeFrequencies[n - 1]);
    int q3Position = ceil(0.75 * cumulativeFrequencies[n - 1]);

    // Find the class intervals for Q1 and Q3
    int q1Index = 0;
    while (cumulativeFrequencies[q1Index] < q1Position) {
        q1Index++;
    }
    int q3Index = 0;
    while (cumulativeFrequencies[q3Index] < q3Position) {
        q3Index++;
    }

    // Interpolate to estimate quartile values
    double L1 = lowerValues[q1Index];
    double L3 = lowerValues[q3Index];
    double classInterval = upperValues[q1Index] - lowerValues[q1Index];
    double freqOfQ1Class = frequencies[q1Index];
    double freqOfQ3Class = frequencies[q3Index];

    // Check for zero frequencies before division
    if (freqOfQ1Class == 0 || freqOfQ3Class == 0) {
        // Handle zero frequencies (e.g., return special values or indicate error)
        return;
    }

    double pcfQ1Class = (q1Index > 0) ? cumulativeFrequencies[q1Index - 1] : 0;
    double pcfQ3Class = cumulativeFrequencies[q3Index - 1];

    q1 = L1 + ((q1Position - pcfQ1Class) * classInterval) / freqOfQ1Class;
    q3 = L3 + ((q3Position - pcfQ3Class) * classInterval) / freqOfQ3Class;
}

// Function to take user input for upper values, lower values, and frequencies
void takeUserInput(vector<int>& lowerValues, vector<int>& upperValues, vector<int>& frequencies) {
    cout << "Enter the number of class intervals: ";
    int n;
    cin >> n;

    cout << "Enter the lower values, upper values, and frequencies of each class interval:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Lower value of class " << i + 1 << ": ";
        int lower;
        cin >> lower;
        lowerValues.push_back(lower);

        cout << "Upper value of class " << i + 1 << ": ";
        int upper;
        cin >> upper;
        upperValues.push_back(upper);

        cout << "Frequency of class " << i + 1 << ": ";
        int freq;
        cin >> freq;
        frequencies.push_back(freq);
    }
}

// Main function
int main() {
    // Vectors to store user input
    vector<int> lowerValues;
    vector<int> upperValues;
    vector<int> frequencies;

    // Take user input
    takeUserInput(lowerValues, upperValues, frequencies);

    // Calculate quartiles
    double q1, q3;
    calculateQuartiles(lowerValues, upperValues, frequencies, q1, q3);

    // // Display quartiles
    // cout << "Q1: " << q1 << endl;
    // cout << "Q3: " << q3 << endl;

    // Display quartile deviation
    cout << "Quartile Deviation (QD): " << 0.5 * (q3 - q1) << endl;

    return 0;
}
