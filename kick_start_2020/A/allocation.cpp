#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int k = 0;
    while (t--)
    {
        k++;
        long long n, b;
        cin >> n >> b;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        long long total = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            total += a[i];
            if (total <= b)
                ans++;
            else
                break;
        }
        cout << "Case #" << k << ": " << ans << "\n";
    }
    return 0;
}