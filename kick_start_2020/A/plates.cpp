#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int test_case = 0; 
    while (t--)
    {
        test_case++;
        long long n, k, p;
        cin >> n >> k >> p;
        int dp[n + 1][max(k, p) + 1];
        int a[n + 1][max(k, p) + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= max(p, k); j++)
            {
                dp[i][j] = 0;
                a[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int v = 0;
            for (int j = 0; j < k; j++)
            {
                int o;
                cin >> o;
                v += o;
                dp[i + 1][j + 1] = v;
                a[i + 1][j + 1] = v;
                if (j == k - 1)
                {
                    for (int w = k; w < p; w++)
                    {
                        dp[i + 1][w + 1] = v;
                        a[i + 1][w + 1] = v;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= p; j++)
            {
                for (int w = 1; w <= k; w++)
                {
                    if (w <= j)
                        dp[i][j] = max(dp[i - 1][j - w] + a[i][w], max(dp[i - 1][j], dp[i][j]));
                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                }
            }
        }

        cout << "Case #" << test_case << ": " << dp[n][p] << "\n";
    }
    return 0;
}