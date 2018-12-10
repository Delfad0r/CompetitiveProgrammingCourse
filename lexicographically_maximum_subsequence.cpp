/*
For each suffix S[n..], we compute the maximum value (character) it
contains (this can be easily done in linear time); call this maximum
max_char[n]. Then a character belongs to the lexicographically maximum
substring if and only if S[n]==max_char[n].

Time complexity:  O(N)
Space complexity: O(N)
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string S;
    cin >> S;
    string max_char(S.length(), '0');
    max_char.back() = S.back();
    for(int n = S.length() - 2; n >= 0; --n) {
        max_char[n] = max(max_char[n + 1], S[n]);
    }
    for(int n = 0; n < int(S.length()); ++n) {
        if(max_char[n] == S[n]) {
            cout << S[n];
        }
    }
    cout << '\n';
}
