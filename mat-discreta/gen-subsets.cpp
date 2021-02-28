/*
 * Generate all the subsets of a given set.
 * The input set must be in the string format.
 * */

#include <iostream>
#include <string>

using namespace std;

typedef long int li;

void print(string sub, li i, li j) {
    cout << i << "  " << j << "\n";
    for (li x = i; i < j; x++) {
        cout << sub[x];
    }
    cout << endl;
}

void generateSubsets(string set) {
    li n = set.size(); cout << n << "\n";
    for (li k = 1; k <= n; k++) {
        for (li i = 0; i < k; i++) {
            for (li j = i; j < k; j++) {
                cout << set[i];
               
            }
            cout << endl;
        }
    }
}

int main () {

    string set;
    cin >> set;
    cout << "\n";

    generateSubsets(set);


    return 0;
}
