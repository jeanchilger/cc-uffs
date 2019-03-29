/*
 * Simple representation of a segment tree.
 * */

#include <cstdio>
#include <tuple>
#include <vector>

using namespace std;

#define INF 9999

typedef tuple<int, int, int> iii;
typedef vector <iii> viii;

viii st;
// st[i] -> (val, b, e)
// where val is the min value between the interval [b, e]

int min(int a, int b) {
    /*
     * Returns the minimun of a and b.
     * */

    return a < b ? a : b;
}

void print(int n) {
    /*
     * Prints the hole tree.
     * BFS-like print.
     * */

    for (int i = 0; i < n; i++) {
        printf("[%d, %d, %d]\n", get<0>(st[i+1]), get<1>(st[i+1]), get<2>(st[i+1]));
    }

    return;
}

void fill(int b, int e, int i, int arr[]) {
    /*
     * Builds the tree with the intervals and the values.
     * */

    if (b == e) {
        iii n(arr[b-1], b, e);
        st[i] = n;
        return;
    }
    
    fill(b, (b+e)/2, i*2, arr);
    fill((b+e)/2 +1, e, i*2 + 1, arr);

    int x = min(get<0>(st[2 * i]), get<0>(st[(2 * i) + 1]));
    iii n (x, b, e);
    st[i] = n;
}

int query(int b, int e, int id = 1) {
    /*
     * Searches for the minimun value in the given range [b, e].
     * Returns the value of this element or INF if there is no such a element.
     * */

    int i = get<1>(st[id]);
    int j = get<2>(st[id]);

    if ((b == i and j == e) or (b <= i and e >= j)) {
        return get<0>(st[id]);
    }

    if (j < b or i > e) {
        return INF;
    }

    if (i <= b or j >= e) {
        return min(query(b, e, 2 * id), query(b, e, 2 * id + 1));  
    }
  

    return 0;
}

void update(int b, int e, int newVal, int arr[], int id=1) {
    /*
     * Updates the tree in the given position.
     * The position is in the form [b, b].
     * */

    int i = get<1>(st[id]);
    int j = get<2>(st[id]);


    if ((b == i and j == e)) {
        iii n(newVal, i, j);
        st[id] = n;
        arr[i-1] = newVal;
        return ;              
    }
     
     
    if (j < b or i > e) {
        return ;      
    }
     
    if (i <= b or j >= e) {
        update(b, e, newVal, arr, 2 * id);
        update(b, e, newVal, arr, 2 * id + 1);
    }

    int v = min(get<0>(st[2 * id]), get<0>(st[2 * id + 1]));
    iii m(v, i, j);
    st[id] = m;
}

int main(){
    int n, e, b, o;

    scanf(" %d", &n);
   
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf(" %d", &arr[i]);
    }

    iii f (INF, 0, 0);
    st.assign(2*n, f);
    
    fill(1, n, 1, arr);
    while (scanf(" %d", &o)!= EOF) {
        scanf(" %d %d", &b, &e);
        if (o == 1) {    
            int val = query(b, e);
            printf("query(%d, %d) = %d\n", b, e, val);
        } else {
            update(b, b, e, arr);
        }
    }

    return 0;
}
