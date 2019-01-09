/*
We create a new string A+"$"+B+B, and then we compute the Z array (for an
explanation of the Z-algorithm, see https://codeforces.com/blog/entry/3107).
At this point, the answer is simply the first position of the Z array with
maximum value.

Time complexity:  O(N)
Space complexity: O(N)
*/

#include <bits/stdc++.h>

using namespace std;

// Implementation of the Z algorithm to compute the Z array.
// Given a string S, Z[i] is the maximum m such that S[0..m-1]=S[i..i+m-1].
// Complexity: O(N), where N is the length of S

// Function to compute the Z array.
// Takes two random-access iterators b and e as input, representing
// the beginning and the end of the string S.
// Returns the Z array of S.
template<typename I>
vector<int> Z_algorithm(I b, I e) {
    I l = b, r = b;
    vector<int> Z(e - b);
    for(I i = b + 1; i != e; ++i) {
        if(i > r) {
            l = r = i;
            while(r < e and *(b + (r - l)) == *r) {
                ++r;
            }
            Z[i - b] = r - l;
            --r;
        } else {
            if(Z[i - l] <= r - i) {
                Z[i - b] = Z[i - l];
            } else {
                l = i;
                while(r < e and *(b + (r - l)) == *r) {
                    ++r;
                }
                Z[i - b] = r - l;
                --r;
            }
        }
    }
    return Z;
}

int main() {
    int N;
	string A, B;
	cin >> N >> A >> B;
	A += "$" + B + B;
	auto Z = Z_algorithm(A.begin(), A.end());
	int ans = 0, pos = 0;
	for(int n = 0; n < N; ++n) {
	    if(Z[N + 1 + n] > ans) {
	        ans = Z[N + 1 + n];
	        pos = n;
	    }
	}
	cout << pos << "\n";
	return 0;
}
