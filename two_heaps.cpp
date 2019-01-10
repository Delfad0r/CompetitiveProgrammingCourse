#include <bits/stdc++.h>

using namespace std;

/*
For every value occurring at least twice, we put one copy in both heaps.
All other values are split evenly between the two heaps, and finally
other copies of the values occurring at least twice are placed randomly.
The answer is the product of the numbers of unique values in each heap.
The code is more convoluted than necessary in order to have a linear time
solution.

Time complexity:  O(N)
Space complexity: O(N)
*/

int main() {
    int N;
    cin >> N;
    vector<int> A(2 * N), occ(101, 0), in_heaps(101, 0), ans(2 * N, 0);
    vector<int> remaining;
    int count[3] = {0, 0, 0};
    for(int n = 0; n < 2 * N; ++n) {
        cin >> A[n];
        ++occ[A[n]];
    }
    for(int n = 0; n <= 100; ++n) {
        if(occ[n] >= 2) {
            in_heaps[n] = 2;
        }
    }
    int last = 1;
    for(int n = 0; n < 2 * N; ++n) {
        if(in_heaps[A[n]]) {
            ans[n] = in_heaps[A[n]];
            ++count[in_heaps[A[n]]--];
        } else if(occ[A[n]] >= 2) {
            remaining.push_back(n);
        } else {
            ans[n] = last;
            ++count[last];
            last = 3 - last;
        }
    }
    while(remaining.size()) {
        ans[remaining.back()] = last;
        remaining.pop_back();
        last = 3 - last;
    }
    cout << count[1] * count[2] << '\n';
    for(int n = 0; n < 2 * N; ++n) {
        cout << ans[n] << ' ';
    }
    cout << '\n';
}
