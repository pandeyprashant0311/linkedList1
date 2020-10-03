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
bool *visited = new bool[100000];
bool *visit = new bool[100000];
int dp[100][100];


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
ll garr(ll a[], ll m, ll n)
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
class Graph
{
	ll V;    // No. of vertices

	// Poller to an array containing
	// adjacency lists
	list<ll> *adj;


	// A recursive function used by DFS
	void DFSUtil(ll v, bool visited[]);
public:
	Graph(ll V);   // Constructor

	// function to add an edge to graph
	void addEdge(ll v, ll w);

	// DFS traversal of the vertices
	// reachable from v
	void DFS(ll v, ll i);
};

Graph::Graph(ll V)
{
	this->V = V;
	adj = new list<ll>[V];
}

void Graph::addEdge(ll v, ll w)
{
	adj[v].push_back(w);
	adj[w].push_back(v); // Add w to v’s list.
}

void Graph::DFSUtil(ll v, bool visited[])
{
	// Mark the current node as visited and
	// prll it
	visited[v] = true;



	// cout << v << " ";
	m.push_back(v);

	// Recur for all the vertices adjacent
	// to this vertex
	list<ll>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i] && !visit[*i])
			DFSUtil(*i, visited);

}


// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(ll v, ll i)
{


	for (ll i = 0; i < V; i++)
		visited[i] = false;

	visit[v] = true;


	// Call the recursive helper function
	// to prll DFS traversal
	DFSUtil(v, visited);
}
int knap(int a[], int b[], int w, int n)
{
	if (n < 0 || w == 0)
	{
		return 0;
	}
	if (dp[n][w] != -1)
	{

		return dp[w][n];
	}
	if (w >= a[n - 1])
	{
		return dp[w][n] = max(b[n - 1] + knap(a, b, w - a[n - 1], n - 1), knap(a, b, w, n - 1));
	}
	else
		return dp[w][n] = knap(a, b, w, n - 1);


}
void solve()
{
	int n, w;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{	cin >> b[i];
	}
	cin >> w;
	// memset(dp, -1, sizeof(dp));
	// cout << knap(a, b, w, n);
	for (int i = 0; i < n; ++i)
	{
		dp[0][i] = 0;

	}
	for (int i = 0; i < w; ++i)
	{
		dp[i][0] = 0;
	}
	for (int i = 1; i <= n ; ++i)
	{
		for (int j = 1; j <= w; j++)
		{
			if (j >= a[i - 1])
			{
				dp[i][j] = max(b[i - 1] + dp[i - 1][j - a[i - 1]], dp[i - 1][j]);

			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][w];




}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	cin >> t;
	ll i = 0;

	while (i < t)
	{

		cout << "Case #" << i + 1 << ": ";
		solve();
		i++;
	}
	return 0;
}

