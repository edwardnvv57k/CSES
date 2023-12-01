// Author: edwardnvv57k

#include <bits/stdc++.h>
using namespace std;

const int pri = 1e9 + 7;

int main (void){
    int n;
    cin >> n;
    int dp[n + 1];

    for (int i = 0; i < n + 1; i++) dp[i] = 0;
    dp[0] = 1;  // Empty set has exactly one way

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 6; j++){
            if (i - j >= 0){
                dp[i] = (dp[i] + dp[i - j]) % pri;
            }
        }
    }

    cout << dp[n] << '\n';

    return 0;
}