// https://codeforces.com/problemset/problem/1182/A
void solve() {
    int n;
    cin>>n;

    // if n is odd then not possible
    if(n & 1) cout<<0;

    // since every 2 columns provides 2 combinations answer is 2^(n/2)
    else cout<<(1<<(n>>1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}