#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    vector<int> result;

    while (i < n && j < m) {
        // Skip duplicates in a
        if (i > 0 && a[i] == a[i - 1]) {
            i++;
            continue;
        }

        // Skip duplicates in b
        if (j > 0 && b[j] == b[j - 1]) {
            j++;
            continue;
        }

        if (a[i] < b[j]) {
            result.push_back(a[i]);
            i++;
        }
        else if (a[i] > b[j]) {
            result.push_back(b[j]);
            j++;
        }
        else {
            // Equal elements
            result.push_back(a[i]);
            i++;
            j++;
        }
    }

    // Remaining elements in a
    while (i < n) {
        if (i == 0 || a[i] != a[i - 1])
            result.push_back(a[i]);
        i++;
    }

    // Remaining elements in b
    while (j < m) {
        if (j == 0 || b[j] != b[j - 1])
            result.push_back(b[j]);
        j++;
    }

    return result;
}

// Driver Code
int main() {
    vector<int> a = {2, 2, 3, 4, 5};
    vector<int> b = {1, 1, 2, 3, 4};

    vector<int> unionArr = findUnion(a, b);

    for (int x : unionArr)
        cout << x << " ";

    return 0;
}