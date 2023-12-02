// Author: edwardnvv57k

#include <bits/stdc++.h>
using namespace std;

const int pri = 1e9 + 7;

int main (void){
    int n, x;
    cin >> n >> x;
    int dp[x + 1], denominations[n];

    for (int i = 0; i < n; i++) cin >> denominations[i];

    for (int i = 0; i < x + 1; i++) dp[i] = 0;
    dp[0] = 1;  // Empty set has exactly one way

    for (int i = 1; i <= x; i++){
        for (int j = 0; j < n; j++){
            if (i - denominations[j] >= 0){
                dp[i] = (dp[i] + dp[i - denominations[j]]) % pri;
            }
        }
    }

    cout << dp[x] << '\n';

    return 0;
}