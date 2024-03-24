#include <iostream>
#include <vector>

using namespace std;

double mean(const vector<double>& v) {
    double sum = 0.0;
    for (double num : v) {
        sum += num;
    }
    return sum / v.size();
}

double covariance(const vector<double>& x, const vector<double>& y, double mean_x, double mean_y) {
    double cov = 0.0;
    for (int i = 0; i < x.size(); i++) {
        cov += (x[i] - mean_x) * (y[i] - mean_y);
    }
    return cov / x.size();
}

double variance(const vector<double>& v, double mean) {
    double var = 0.0;
    for (double num : v) {
        var += (num - mean) * (num - mean);
    }
    return var / v.size();
}

void linear_regression(const vector<double>& x, const vector<double>& y) {
    double mean_x = mean(x);
    double mean_y = mean(y);

    double beta = covariance(x, y, mean_x, mean_y) / variance(x, mean_x);
    double alpha = mean_y - beta * mean_x;

    cout << "The equation of the regression line is: y = " << alpha << " + " << beta << "*x" << endl;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> test_scores(n);
    vector<double> sales(n);
    for(int i = 0; i < n; i++) {
        cout << "Enter the test score for data point " << i + 1 << ": ";
        cin >> test_scores[i];
        cout << "Enter the sales volume for data point " << i + 1 << ": ";
        cin >> sales[i];
    }

    linear_regression(test_scores, sales);

    // To estimate the sales volume for a test score of 100, we can simply plug the score into the regression equation.
    double mean_test_scores = mean(test_scores);
    double mean_sales = mean(sales);
    double beta = covariance(test_scores, sales, mean_test_scores, mean_sales) / variance(test_scores, mean_test_scores);
    double alpha = mean_sales - beta * mean_test_scores;

    double estimated_sales = alpha + beta * 100;
    cout << "The estimated sales volume for a test score of 100 is: " << estimated_sales << " thousand" << endl;

    return 0;
}