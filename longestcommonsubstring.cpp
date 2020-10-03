#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
#define ll long long int
#define db double
#define S second
#define MOD 1000000007

const int  N = 1e9 + 7;
const int  P = 1e9;

vector<ll> m;
ll gcd (ll a, ll b) {return ( a ? gcd(b % a, a) : b );}

ll power(ll a, ll n) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
ll get(ll x)
{
	ll c = 0;
	while (x % 2 == 0)
	{
		c++;
		x = x / 2;
	}
	for (ll i = 3; i < sqrt(x); i += 2)
	{
		while (x % i == 0)
		{
			c++;
			x /= i;
		}
	}
	if (x > 1)
		c++;
	return c;
}
ll maxnum(ll a[], ll x, ll y)
{
	map<ll, ll> m;
	for (ll i = x; i <= y ; ++i)
	{
		m[a[i]]++;
	}
	ll h = INT_MIN;
	ll s = INT_MAX;
	for (auto i = m.begin(); i != m.end(); i++)
	{
		if (i->second > h)
		{
			h = i->second;
			s = i->first;

		}
	}
	cout << s << " " ;
	return s;
}
void solve()
{

	int m, n;
	cin >> m >> n;
	string a, b;
	int dp[m + 1][n + 1];
	cin >> a;
	cin >> b;
	for (int i = 0; i <= m; ++i)
	{
		dp[i][0] = 0;
	}
	for (int i = 0; i <= n; ++i)
	{
		dp[0][i] = 0;
	}
	int l = 0;
	for (int i = 1; i < m + 1; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				l++;
			}
			else
			{
				dp[i][j] = 0;

			}

		}
	}
	int ans = 0;
	int x, y;
	for (int i = 0; i <= m; ++i)
	{
		cout << endl;
		for (int j = 0; j <= n; j++)
		{
			cout << dp[i][j];
			ans = max(ans, dp[i][j]);
			if (ans == dp[i][j])
			{
				x = i;
				y = j;
			}
		}
	}
	for (int i = ans; i >= 1; --i)
	{
		cout << a[x - i];
	}
	cout << endl;
	cout << ans << endl;



}




int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	cin >> t;


	while (t--)
	{


		solve();

	}
	return 0;
}

