#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(const vector<int>& books, int students, int maxPages) {
    int requiredStudents = 1;
    int currentPages = 0;

    for (int pages : books) {
        if (pages > maxPages)
            return false;

        if (currentPages + pages > maxPages) {
            requiredStudents++;
            currentPages = pages;

            if (requiredStudents > students)
                return false;
        } else {
            currentPages += pages;
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> books(n);
    int totalPages = 0, maxBook = 0;

    for (int i = 0; i < n; i++) {
        cin >> books[i];
        totalPages += books[i];
        maxBook = max(maxBook, books[i]);
    }

    if (m > n) {
        cout << -1;
        return 0;
    }

    int low = maxBook;
    int high = totalPages;
    int answer = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(books, m, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer;
    return 0;
}
