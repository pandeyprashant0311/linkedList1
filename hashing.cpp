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
ll gcd (ll a, ll b) {return ( a ? gcd(b % a, a) : b );}
ll power(ll a, ll n) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
int get(int x)
{
	int c = 0;
	while (x % 2 == 0)
	{
		c++;
		x = x / 2;
	}
	for (int i = 3; i < sqrt(x); i += 2)
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

int maxnum(ll a[], int x, int y)
{
	map<ll, ll> m;
	for (int i = x; i <= y ; ++i)
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
int garr(ll a[], ll m, ll n)
{
	ll c = 0;
	for (ll i = m; i <= n ; ++i)
	{
		c += a[i];
	}
	cout << c << endl;
	if (c == n - m + 1)
	{
		return 1;
	}
	else
		return 0;
}
void solve()
{


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

