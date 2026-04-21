#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceCows(const vector<int>& stalls, int k, int minDist) {
    int cowsPlaced = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPosition >= minDist) {
            cowsPlaced++;
            lastPosition = stalls[i];

            if (cowsPlaced >= k)
                return true;
        }
    }

    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int answer = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, k, mid)) {
            answer = mid;
            low = mid + 1;   // Try for larger minimum distance
        } else {
            high = mid - 1;  // Reduce distance
        }
    }

    cout << answer;
    return 0;
}
