#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int fast_binary_search(int r,const vector<int>& v) {
    int lo = 0;
    int hi = v.size()-1;
    int ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if (v[mid]<=r) {
            ans = mid + 1;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return ans;

}

int main() {
    ios_base::sync_with_stdio(false);//Important I/O Methods
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i<n;i++) {
        int value;
        cin >> value;
        v.push_back(value);
    }
    sort(v.begin(),v.end());
    int k;
    cin >>k;
    for (int i =0;i<k;i++) {
        int l,r;
        cin >> l >> r;
        int count;
        count = fast_binary_search(r,v) - fast_binary_search(l-1,v); //Main logic for the inclusion-exclusion problem
        cout << count << endl;//basically example have to ffind number of pages between 70-100 its 31 because 100 pages total and 70-1 therefore 100 - 69 = 31
    }

    return 0;
};