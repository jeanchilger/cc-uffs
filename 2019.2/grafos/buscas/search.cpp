#include <stdio.h>
#include <deque>
#include <vector>

#include <search.h>

using namespace std;

bool is_in(vector<int> array, int valor) {
    for (int x : array) {
        if (x == valor) {
            return true;
        }
    }

    return false;
}

bool is_ina(deque<int> array, int valor) {
    for (int x : array) {
        if (x == valor) {
            return true;
        }
    }

    return false;
}

void print_fronteira(deque<int> fronteira) {
    printf("FRONTEIRA: [");
    for (int x : fronteira) {
        printf("%d, ", x);
    }

    printf("]\n");
}

// busca largura
bool busca_largura(vector< vector<int> > grafo, int inicio, int fim) {
    printf("Busca em largura\n");
    deque<int> fronteira;

    vector<int> descobertos;
    fronteira.push_back(inicio);

    while (!fronteira.empty()) {
        print_fronteira(fronteira);

        if (fronteira.front() == fim) {
            return true;

        } else {
            int noPai = fronteira.front();
            fronteira.pop_front();
            descobertos.push_back(noPai);

            int no = 0;
            for (int n : grafo[noPai]) {
                if (n == 1) {
                    if (!is_in(descobertos, no)) {
                        fronteira.push_back(no);
                        descobertos.push_back(no);
                    }
                }

                no++;
            }

        }
    }

    return false;
}

// busca profundidade
bool busca_profundidade(vector< vector<int> > grafo, int inicio, int fim) {
    printf("Busca em profundidade\n");
    deque<int> fronteira;

    vector<int> descobertos;
    fronteira.push_front(inicio);

    while (!fronteira.empty()) {
        print_fronteira(fronteira);

        if (fronteira.front() == fim) {
            return true;

        } else {
            int noPai = fronteira.front();
            fronteira.pop_front();
            descobertos.push_back(noPai);

            int no = 0;
            for (int n : grafo[noPai]) {
                if (n == 1) {
                    if (!is_in(descobertos, no)) {
                        fronteira.push_front(no);
                        descobertos.push_back(no);
                    }
                }

                no++;
            }

        }
    }

    return false;
}



int main() {

    int n; // linhas
    int m; // colunas
    int v;

    scanf(" %d %d", &n, &m);

    vector<vector<int>> grafo(n, vector<int>(m, 0));

    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            scanf(" %d", &v);
            grafo[i][j] = v;
        }
    }

    printf("MIAU: %d\n", busca_largura(grafo, 0, 3));
    printf("MIAU: %d\n", busca_profundidade(grafo, 0, 3));

    return 0;
}
