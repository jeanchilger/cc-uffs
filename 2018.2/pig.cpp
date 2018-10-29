#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

#define INF 10e8

int main () {
    int t, n, e, f, p, w;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf(" %d %d", &e, &f);
        
        scanf(" %d", &n);
        int weights[n];
        int values[n];

        for (int ni = 0; ni < n; ni++) {
            scanf(" %d %d", &values[ni], &weights[ni]);
        }

        int dp[f-e+1];
        for (int i = 0; i < f-e+1; i++) {
            dp[i] = INF;
        }

        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < f-e+1; j++) {
                if (j >= weights[i]) {
                    dp[j] = min(dp[j], dp[j-weights[i]] + values[i]);
                }
            }
        }

        printf("%d\n", dp[f-e]);
        

    }

    return 0;
}
