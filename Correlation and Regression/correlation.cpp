#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double calculate_rank_correlation_coefficient(const vector<int>& r1, const vector<int>& r2) {
    int n = r1.size();
    double d_square_sum = 0.0;

    for (int i = 0; i < n; i++) {
        int d = r1[i] - r2[i];
        d_square_sum += d * d;
    }

    double rank_correlation_coefficient = 1 - (6 * d_square_sum) / (n * (pow(n, 2) - 1));
    return rank_correlation_coefficient;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<int> r1(n);
    vector<int> r2(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the rank of data point " << i + 1 << " in the first list: ";
        cin >> r1[i];
        cout << "Enter the rank of data point " << i + 1 << " in the second list: ";
        cin >> r2[i];
    }

    double rank_correlation_coefficient = calculate_rank_correlation_coefficient(r1, r2);

    cout << "The rank correlation coefficient is: " << rank_correlation_coefficient << endl;

    return 0;
}