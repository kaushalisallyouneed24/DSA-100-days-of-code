#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPaint(const vector<int>& boards, int k, long long maxTime) {
    int painters = 1;
    long long currentTime = 0;

    for (int length : boards) {
        if (length > maxTime)
            return false;

        if (currentTime + length > maxTime) {
            painters++;
            currentTime = length;

            if (painters > k)
                return false;
        } else {
            currentTime += length;
        }
    }

    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> boards(n);
    long long low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        cin >> boards[i];
        low = max(low, (long long)boards[i]);
        high += boards[i];
    }

    long long answer = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (canPaint(boards, k, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer;
    return 0;
}
