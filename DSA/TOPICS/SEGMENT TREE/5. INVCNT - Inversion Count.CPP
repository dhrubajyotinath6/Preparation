// https://www.spoj.com/problems/INVCNT/

Let A[0...n - 1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. 
Given n and an array A your task is to find the number of inversions of A.

Input
The first line contains t, the number of testcases followed by a blank space. Each of the t tests start with a number n (n <= 200000). 
Then n + 1 lines follow. 
In the ith line a number A[i - 1] is given (A[i - 1] <= 10^7). 
The (n + 1)th line is a blank space.

Output
For every test output one line giving the number of inversions of A.

Example
Input:
2

3
3
1
2

5
2
3
8
6
1


Output:
2
5
  
  
=>
  
class SGTree {
public: vector<int> seg;
public:
	SGTree(int n) {
		seg.resize(4 * n + 1);
	}

	void build(int ind, int low, int high, int arr[]) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}

		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}

	int query(int ind, int low, int high, int l, int r) {
		// no overlap
		// l r low high or low high l r
		if (r < low || high < l) return 0;

		// complete overlap
		// [l low high r]
		if (low >= l && high <= r) return seg[ind];

		int mid = (low + high) >> 1;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
		return left + right;
	}
	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			seg[ind] += val;
			return;
		}

		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}
};
void solve5() {
	int n;
	cin >> n;
	int arr[n];
	int mx = -1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
	mx += 1;
	int freq[mx];
	memset(freq, 0, sizeof freq);
	for (int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}

	SGTree st(mx);
	st.build(0, 0, mx - 1, freq);
	//cout << st.seg[0] << endl;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		freq[arr[i]]--;
		st.update(0, 0, mx - 1, arr[i], -1);

		cnt += st.query(0, 0, mx - 1, 1, arr[i] - 1);
	}

	cout << cnt << endl;

}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve5();
	return 0;
}
