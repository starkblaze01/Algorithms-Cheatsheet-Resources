// Using segment tree (recursive) for range sum query

#include<iostream>
#include<vector>

using namespace std;

vector<int> tree;

// Segment tree functions

int merge (int a, int b) {
	return a + b;
}

// build tree for arr[lo..hi]
void build (vector<int> arr, int treeInd, int lo, int hi) {
	if (lo == hi) {
		tree[treeInd] = arr[lo];
		return;
	}

	int mid = lo + (hi - lo)/2;
	build (arr, 2*treeInd + 1, lo, mid);
	build (arr, 2*treeInd + 2, mid+1, hi);

	tree[treeInd] = merge(tree[2*treeInd+1], tree[2*treeInd+2]);
}

// get sum int range arr[i..j]
int query (int treeInd, int lo, int hi, int i, int j) {
	if (i <= lo && j >= hi) return tree[treeInd];
	if (i > hi || j < lo) return 0;

	int mid = lo + (hi - lo)/2;

	if (j <= mid) return query(2*treeInd+1, lo, mid, i, j);
	else if (i > mid) return query(2*treeInd+2, mid+1, hi, i, j);

	int leftq = query(2*treeInd+1, lo, mid, i, mid);
	int rightq = query(2*treeInd+2, mid+1, hi, mid+1, j);
	return merge(leftq, rightq);
}

void update (int treeInd, int lo, int hi, int arrInd, int val) {
	if (arrInd < lo || arrInd > hi) return;

	if (lo == hi) {
		if (lo == arrInd) tree[treeInd] = val;
		return;
	}

	int mid = lo + (hi-lo)/2;

	if (arrInd <= mid) update(2*treeInd+1, lo, mid, arrInd, val);
	else update(2*treeInd+2, mid+1, hi, arrInd, val);

	tree[treeInd] = merge(tree[2*treeInd+1], tree[2*treeInd+2]);
}

int main () {
	int n;
	cout<<"Enter the number of elements in the array:"<<endl;
	cin>>n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cout<<"Enter element at "<<i<<" index:";
		cin>>arr[i];
		cout<<endl;
	}

	tree = vector<int>(4*n, 0); // tree size doesn't exceen 4*n
	// Check this for proof:
	// https://www.quora.com/Why-does-4-*-N-space-have-to-be-allocated-for-a-segment-tree-where-N-is-the-size-of-the-original-array

	// Build
	build(arr, 0, 0, n-1);

	// taking input queries from user
	while (true) {
		cout<<endl;
		cout<<"Choose option:"<<endl;
		cout<<"0. update i-th element of the array"<<endl;
		cout<<"1. get sum in range"<<endl;
		cout<<"2. exit"<<endl;

		int option;
		cin>>option;
		cout<<endl;

		switch (option) {
			case 0:
				cout<<"Enter index of array to update:"<<endl;
				int ind;
				cin>>ind;
				cout<<"Update index "<<ind<<" to value:"<<endl;
				int val;
				cin>>val;
				cout<<endl;

				update(0, 0, n-1, ind, val);

				cout<<"Updated successfully."<<endl;
				break;

			case 1:
				cout<<"Enter range as 'l r':"<<endl;
				int l, r;
				cin>>l>>r;

				cout<<"Sum in range ("<<l<<","<<r<<") is "<<query(0, 0, n-1, l, r)<<endl;
				break;

			case 2: 
				cout<<"Exiting..."<<endl;
				return 0;

			default:
				cout<<"Option "<<option<<" is invalid."<<endl;
				break;
		}
	}
}
