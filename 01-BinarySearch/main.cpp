#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
bool isPossible(double length_to_check,const vector<int>& all_ropes,int k_needed) {
    int total_pieces = 0;
    // "For each rope_length in the all_ropes vector..."
    if (length_to_check < 1e-7) {
        return true;
    }
    for (const int rope_length : all_ropes) {
        // Use rope_length directly
        int pieces_from_this_rope = static_cast<int>(rope_length / length_to_check);
        total_pieces = total_pieces + pieces_from_this_rope;
    }
    return total_pieces >= k_needed;
}

double ropes_search(const vector<int>& v , int k, int n) {
    double lo = 0.0;
    double ans = 0.0;
    double hi = 1e7;
    for (int i = 0; i< 100;i++) { // 100 Iterations are enough for any 10^7
        double mid = lo + (hi-lo)/2;
        if (isPossible(mid,v,k)) { // Important check function
            ans = mid;
            lo = mid;
        }
        else {
            hi = mid;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);//Important I/O Methods
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i<n;i++) {
        int value;
        cin >> value;
        v.push_back(value);
    }
    sort(v.begin(),v.end());
    cout << setprecision(20) << ropes_search(v,k,n);

    return 0;
};