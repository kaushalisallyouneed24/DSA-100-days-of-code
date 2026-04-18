#include <iostream>
#include <vector>
using namespace std;

int lowerBound(const vector<int>& arr, int x) {
    int left = 0, right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int upperBound(const vector<int>& arr, int x) {
    int left = 0, right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= x)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int main() {
    int n, x;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> x;

    cout << lowerBound(arr, x) << " "
         << upperBound(arr, x);

    return 0;
}
