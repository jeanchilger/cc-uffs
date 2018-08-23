#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define DIGITS 200
#define BOUND pow(10, 8)

int main () {

    string a, b, c;

    cin >> a;
    cin >> b;

    int sizeA = a.length();
    int sizeB = b.length();

    if (sizeA > sizeB) {
        b.insert(b.begin(), sizeA - sizeB, '0');

    } else if (sizeB > sizeA) {
        a.insert(a.begin(), sizeB - sizeA, '0');
        sizeA = a.length();
    }

    int id = max(0, sizeA - 8);
    int amount = min(sizeA, 8);

    int remain = 0;
    int sum;
    string preSum;

    while (true) {

        sum = stoi(a.substr(id, amount)) + stoi(b.substr(id, amount)) + remain;
        remain = (int)(sum >= BOUND);

        if (remain) {
            preSum = to_string(sum).substr(1);

        } else {
            preSum = to_string(sum);
        }


        if (id < 8 && id > 0) {
            amount = id;
            id = 0;

        } else {
            id -= 8;

        }

        if (id < 0) {
            c = preSum + c;
            break;

        } else {
            preSum.insert(preSum.begin(), 8 - preSum.length(), '0');
            c = preSum + c;
        }

    }

    cout << c << "\n";

    return 0;
}
