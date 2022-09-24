

#include<bits/stdc++.h>
using namespace std;
// class SGTree {
// 	vector<int> seg;
// public:
// 	SGTree(int n) {
// 		seg.resize(4 * n + 1);
// 	}

// 	void build(int ind, int low, int high, int arr[]) {
// 		if (low == high) {
// 			seg[ind] = arr[low];
// 			return;
// 		}

// 		int mid = (low + high) / 2;
// 		build(2 * ind + 1, low, mid, arr);
// 		build(2 * ind + 2, mid + 1, high, arr);
// 		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
// 	}

// 	int query(int ind, int low, int high, int l, int r) {
// 		// no overlap
// 		// l r low high or low high l r
// 		if (r < low || high < l) return INT_MAX;

// 		// complete overlap
// 		// [l low high r]
// 		if (low >= l && high <= r) return seg[ind];

// 		int mid = (low + high) >> 1;
// 		int left = query(2 * ind + 1, low, mid, l, r);
// 		int right = query(2 * ind + 2, mid + 1, high, l, r);
// 		return min(left, right);
// 	}
// 	void update(int ind, int low, int high, int i, int val) {
// 		if (low == high) {
// 			seg[ind] = val;
// 			return;
// 		}

// 		int mid = (low + high) >> 1;
// 		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
// 		else update(2 * ind + 2, mid + 1, high, i, val);
// 		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
// 	}
// };



// void solve() {
// 	int n;
// 	cin >> n;
// 	int arr[n];
// 	for (int i = 0; i < n; i++) cin >> arr[i];
// 	int seg[4 * n];
// 	build(0, 0, n - 1, arr, seg);
// 	cout << seg[0] << endl;
// 	int q;
// 	cin >> q;
// 	while (q--) {
// 		int type;
// 		cin >> type;
// 		if (type == 1) {
// 			int l, r;
// 			cin >> l >> r;
// 			cout << query(0, 0, n - 1, l, r, seg) << endl;
// 		}
// 		else {
// 			int i, val;
// 			cin >> i >> val;
// 			update(0, 0, n - 1, i, val, seg);
// 			arr[i] = val;
// 		}
// 	}

// }


// void solve2() {
// 	int n1;
// 	cin >> n1;
// 	int arr1[n1];
// 	for (int i = 0; i < n1; i++) cin >> arr1[i];
// 	SGTree sg1(n1);
// 	sg1.build(0, 0, n1 - 1, arr1);


// 	int n2;
// 	cin >> n2;
// 	int arr2[n2];
// 	for (int i = 0; i < n2; i++) cin >> arr2[i];
// 	SGTree sg2(n2);
// 	sg2.build(0, 0, n2 - 1, arr2);

// 	int q;
// 	cin >> q;
// 	while (q--) {
// 		int type;
// 		cin >> type;
// 		if (type == 1) {
// 			int l1, r1, l2, r2;
// 			cin >> l1 >> r1 >> l2 >> r2;
// 			int min1 = sg1.query(0, 0, n1 - 1, l1, r1);
// 			int min2 = sg2.query(0, 0, n2 - 1, l2, r2);
// 			cout << min(min1, min2) << endl;
// 		}
// 		else {
// 			int arrNo, i, val;
// 			cin >> arrNo >> i >> val;
// 			if (arrNo == 1) {
// 				sg1.update(0, 0, n1 - 1, i, val);
// 				arr1[i] = val;
// 			}
// 			else {
// 				sg2.update(0, 0, n2 - 1, i, val);
// 				arr2[i] = val;
// 			}
// 		}
// 	}
// }
// void build(int ind, int low, int high, int arr[], int seg[], int orr) {
// 	if (low == high) {
// 		seg[ind] = arr[low];
// 		return;
// 	}
// 	int mid = (low + high) / 2;
// 	build(2 * ind + 1, low, mid, arr, seg, !orr);
// 	build(2 * ind + 2, mid + 1, high, arr, seg, !orr);
// 	if (orr) seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
// 	else seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
// }
// void update(int ind, int low, int high, int seg[], int orr, int i, int val) {
// 	if (low == high) {
// 		seg[ind] = val;
// 		return;
// 	}
// 	int mid = (low + high) / 2;
// 	if (i <= mid) update(2 * ind + 1, low, mid, seg, !orr, i, val);
// 	else update(2 * ind + 2, mid + 1, high, seg, !orr, i, val);
// 	if (orr) seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
// 	else seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
// }
// void solve3() {
// 	int n, q;
// 	cin >> n >> q;
// 	int el = pow(2, n);
// 	int arr[el];
// 	for (int i = 0; i < el; i++) {
// 		cin >> arr[i];
// 	}
// 	int seg[4 * el];
// 	if (n % 2 == 0) build(0, 0, el - 1, arr, seg, 0);
// 	else build(0, 0, el - 1, arr, seg, 1);

// 	while (q--) {
// 		int i, val;
// 		cin >> i >> val;
// 		i--;
// 		if (n % 2 == 0) update(0, 0, el - 1, seg, 0, i, val);
// 		else update(0, 0, el - 1, seg, 1, i, val);
// 		cout << seg[0] << endl;
// 	}
// }
// class info {
// public:
// 	int open, close, full;

// public:
// 	info(int _open, int _close, int _full) {
// 		open = _open;
// 		close = _close;
// 		full = _full;
// 	}
// 	info() {
// 		open = 0;
// 		close = 0;
// 		full = 0;
// 	}
// };

// info merge(info left, info right) {
// 	info ans = info(0, 0, 0);
// 	ans.full = left.full + right.full + min(left.open, right.close);
// 	ans.open = left.open + right.open - min(left.open, right.close);
// 	ans.close = left.close + right.close - min(left.open, right.close);
// 	return ans;
// }
// void build(int ind, int low, int high, string s, info seg[]) {
// 	if (low == high) {
// 		seg[ind].open = s[low] == '(';
// 		seg[ind].close = s[low] == ')';
// 		seg[ind].full = 0;
// 		return;
// 	}
// 	int mid = (low + high) / 2;
// 	build(2 * ind + 1, low, mid, s, seg);
// 	build(2 * ind + 2, mid + 1, high, s, seg);
// 	seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
// }
// info query(int ind, int low, int high, int l, int r, info seg[]) {
// 	if (r < low || high < l) return info();
// 	if (low >= l && high <= r) return seg[ind];
// 	int mid = (low + high) / 2;
// 	info left = query(2 * ind + 1, low, mid, l, r, seg);
// 	info right = query(2 * ind + 2, mid + 1, high, l, r, seg);
// 	return merge(left, right);
// }
// void solve4() {
// 	string s;
// 	cin >> s;
// 	int n = s.size();
// 	info seg[4 * n];
// 	build(0, 0, n - 1, s, seg);
// 	int q;
// 	cin >> q;
// 	while (q--) {
// 		int l, r;
// 		cin >> l >> r;
// 		l--, r--;
// 		info ans = query(0, 0, n - 1, l, r, seg);
// 		cout << ans.full * 2 << endl;
// 	}
// }


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










