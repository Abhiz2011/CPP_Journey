#include <iostream>
#include <vector>
using namespace std;
int binary_search(int target,const vector<int>& v) {
    int left = 0;
    int high = v.size() - 1;
    int ans = 0;
    while (left <= high) {
        int mid = left + (high - left)/2;
        if (v[mid] <= target) {
            ans = mid + 1; // No Need for Max cuz whatever comes is better anyways because sorted
            left = mid + 1; // Increase the left
        }
        else {//v[mid] > target
            high = mid - 1; //Remove the entire right side cuz mid is bigger than target so has to be in left
        }
    }
    return ans;

}
int main() {
    ios_base::sync_with_stdio(false);//Important I/O Methods
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i<n;i++) {
        int value;
        cin >> value;
        v.push_back(value);
    }
    for (int i = 0;i<k;i++) {
        int queries;
        cin >> queries;
        cout << binary_search(queries,v) << endl;
    }
    return 0;
};