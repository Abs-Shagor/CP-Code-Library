#include<bits/stdc++.h>          // --> Bismillahir_ Rahmanir_ Rahim <--
#define ll long long 
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//// less<int> ==> then the set is in ascending order.
//// greater<> ==> then the set is in descending order.
//// Set_name.order_of_key(x) ==> Number of element strictly less then x.
//// Set_name.find_by_order(n) => n'th element of the current set.            

// ordered set store unique elements.
// if we need duplicate value, then we can store pair instead of integer.
// pair the value with its index(it's work really good).

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ordered_set osat;

    osat.insert(5);
    osat.insert(1);
    osat.insert(2);
    osat.insert(1);
    osat.insert(3);
    osat.insert(1);

    cout << osat.order_of_key(5) << "\n";   // Ans: 3

    cout << *osat.find_by_order(0) << "\n"; // Ans: 1
    cout << *osat.find_by_order(1) << "\n"; // Ans: 2
    cout << *osat.find_by_order(2) << "\n"; // Ans: 3
    cout << *osat.find_by_order(3) << "\n"; // Ans: 5
    cout << *osat.find_by_order(4) << "\n"; // Ans: 0


    return 0;
}

