// Code for Fenwick tree (or Binary Indexed tree [BIT]) for range sum query

#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> arr; // original array
vector<int> arr2; // copy used for initial BIT construction
vector<int> BIT; // BIT or Fenwick tree data structure

// update ith element to val
void update (int i, int val) {
  int d = val - arr2[i];
  arr2[i] = val;
  i++;
  for (; i <= n; i += (i&-i)) {
    BIT[i] += d;
  }
}

// sum query over range [0,r]
// i.e. get sum of elements in the range [0,r] (inclusive)
int query1 (int r) {
  r++;
  int ans = 0;
  for (int i = r; i > 0; i -= (i&-i)) {
    ans += BIT[i];
  }
  return ans;
}

// query over range [l,r] indices
// i.e. get sum of elements in the range [l,r] (inclusive)
int query (int l, int r) {
  return query1(r) - query1(l-1);
}

int main () {
  cout<<"Enter the number of elements in the array:"<<endl;
  cin>>n;
  cout<<endl;

  arr = vector<int>(n);
  
  for (int i = 0; i < n; i++) {
    cout<<"Enter element at "<<i<<" index:";
    cin>>arr[i];
    cout<<endl;
  }

  // constructing BIT
  BIT = vector<int>(n+1, 0);
  arr2 = vector<int>(n, 0);
  for (int i = 0; i < n; i++) {
    update(i, arr[i]);
  }

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

        update(ind, val);

        cout<<"Updated successfully."<<endl;
        break;

      case 1:
        cout<<"Enter range as 'l r':"<<endl;
        int l, r;
        cin>>l>>r;

        cout<<"Sum in range ("<<l<<","<<r<<") is "<<query(l,r)<<endl;
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
