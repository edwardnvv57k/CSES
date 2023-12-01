// Author: edwardnvv57k

#include <bits/stdc++.h>
using namespace std;

int main (void){
    int n, x;
    cin >> n >> x;

    int denominations[n];
    for (int i = 0; i < n; i++) cin >> denominations[i];
    int dp[x + 1];

    for (int i = 0; i < x + 1; i++) dp[i] = 1e9;
    dp[0] = 0;  // x = 0 requires 0 coins

    for (int i = 1; i <= x; i++){
        for (int j = 0; j < n; j++){
            if (i - denominations[j] >= 0){
                dp[i] = min(dp[i], 1 + dp[i - denominations[j]]);
            }
        }
    }

    cout << ((dp[x] != (int) 1e9) ? dp[x] : -1) << '\n';

    return 0;
}