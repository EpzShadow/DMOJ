#include<bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
long long gcd(long long a, long long b) {
    long long R;
    while ((a % b) > 0) {
        R = a % b;
        a = b;
        b = R;
    }
    return b;
}
int main() {
	long long a, b;
	cin >> a >> b;
    cout << a * b / gcd(a, b);
}