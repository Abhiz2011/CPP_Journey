#include <iostream>
#include <vector>
using namespace std;
bool binary_search(int k,const vector<int>& v) {
    int n = v.size();
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (v[mid] == k) {
            return true;
        }
        else if (v[mid] < k) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n , k;
    cin >> n >> k;

    vector<int> v;
    for (int i =0; i<n;i++) {
        int value;
        cin >> value;
        v.push_back(value);
    }
    for (int i = 0; i<k;i++) {
        int queries;
        cin >> queries;
        if (binary_search(queries,v)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" <<endl;
        }
    }
    return 0;
};