// try to make grid similar to B
//we are iterate 1 on 1 each element from a try to match if matched then continue to next if not matched difference is added in and diagonal element a[i+1][j+1] and rest do yourself 


#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define fs(i, n) for (int i = 0; i < n; i++)
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<int>> b(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++) {
            a[i][j] = temp[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++) {
            b[i][j] = temp[j] - '0';
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if ((b[i][j] - a[i][j] + 3) % 3 == 0) {
                continue;
            } else if ((b[i][j] - a[i][j] + 3) % 3 == 1) {
                a[i][j] = (a[i][j] + 1) % 3;
                a[i + 1][j + 1] = (a[i + 1][j + 1] + 1) % 3;
                a[i + 1][j] = (a[i + 1][j] + 2) % 3;
                a[i][j + 1] = (a[i][j + 1] + 2) % 3;
            } else {
                a[i][j] = (a[i][j] + 2) % 3;
                a[i + 1][j + 1] = (a[i + 1][j + 1] + 2) % 3;
                a[i + 1][j] = (a[i + 1][j] + 1) % 3;
                a[i][j + 1] = (a[i][j + 1] + 1) % 3;
            }
        }
    }

    int f = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                f = 0;
                break;
            }
        }
        if (f == 0) break;
    }

    if (f) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
