#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculateRange(const vector<int>& data) {
    if (data.empty()) {
        cerr << "Error: Empty dataset\n";
        return 0;  
    }

    int min_val = *min_element(data.begin(), data.end());
    int max_val = *max_element(data.begin(), data.end());

    // Calculate the range
    int range = max_val - min_val;

    return range;
}

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

    int result = calculateRange(dataset);

    cout << "Range: " << result << endl;

    return 0;
}
