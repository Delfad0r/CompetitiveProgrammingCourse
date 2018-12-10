/*
We implement a recursive function to check whether a given string S
represents a magic number. The base case is the empty string, which
is magic. Then we try and match "144", "14" and "1" (in this order)
from the beginning of the string: if we succeed, we remove the matching
substring and check whether what remains is magic.

Time complexity:  O(L)
Space complexity: O(L)
where L is the number of digits of the number given (at most 9)
*/

#include <bits/stdc++.h>

using namespace std;

bool is_magic(string S) {
    if(S.empty()) {
        return true;
    } else if(S.substr(0, 3) == "144") {
        return is_magic(S.substr(3));
    } else if(S.substr(0, 2) == "14") {
        return is_magic(S.substr(2));
    } else if(S.substr(0, 1) == "1") {
        return is_magic(S.substr(1));
    }
    return false;
}

int main() {
    string N;
    cin >> N;
    cout << ((is_magic(N)) ? ("YES") : ("NO")) << '\n';
}
