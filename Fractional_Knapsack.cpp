
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    float w[20], p[20], r[20];

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weight and profit:\n";

    for(int i = 0; i < n; i++) {
        cin >> w[i] >> p[i];
        r[i] = p[i] / w[i];
    }

    cout << "Enter capacity: ";
    cin >> m;

    // Sort by profit/weight ratio
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(r[i] < r[j]) {
                swap(r[i], r[j]);
                swap(w[i], w[j]);
                swap(p[i], p[j]);
            }
        }
    }

    float profit = 0;

    for(int i = 0; i < n; i++) {
        if(m >= w[i]) {
            profit += p[i];
            m -= w[i];
        }
        else {
            profit += r[i] * m;
            break;
        }
    }

    cout << "Maximum Profit = " << profit;

    return 0;
}
