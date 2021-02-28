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

bool is_adjacency_matrix(vector< vector<int> > grafo) {
    if (grafo.size() != grafo[0].size()) return false;

    for (int i=0; i < grafo.size(); i++) {
        for (int j=0; j < grafo[0].size(); j++) {
            if (grafo[i][j] != grafo[j][i]) return false;
        }
    }

    return true;
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
    bool adj_mtrx = is_adjacency_matrix(grafo);

    while (!fronteira.empty()) {
        print_fronteira(fronteira);

        if (fronteira.front() == fim) {
            return true;

        } else {
            int noPai = fronteira.front();
            fronteira.pop_front();
            descobertos.push_back(noPai);

            if (adj_mtrx) {
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
            
            } else {
                int col = 0;
                for (int n : grafo[noPai]) {
                    if (n == 1) {
                        int no = 0;
                        for (int i=0; i < grafo.size(); i++) {
                            if(grafo[i][col] == 1) {
                                if (!is_in(descobertos, no)) {
                                    fronteira.push_back(no);
                                    descobertos.push_back(no);
                                }
                            }
                            no++;
                        }
                    }
                    col++;
                }
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
    bool adj_mtrx = is_adjacency_matrix(grafo);

    while (!fronteira.empty()) {
        print_fronteira(fronteira);

        if (fronteira.front() == fim) {
            return true;

        } else {
            int noPai = fronteira.front();
            fronteira.pop_front();
            descobertos.push_back(noPai);

            if (adj_mtrx) {
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
            
            } else {
                int col = 0;
                for (int n : grafo[noPai]) {
                    if (n == 1) {
                        int no = 0;
                        for (int i=0; i < grafo.size(); i++) {
                            if(grafo[i][col] == 1) {
                                if (!is_in(descobertos, no)) {
                                    fronteira.push_front(no);
                                    descobertos.push_back(no);
                                }
                            }
                            no++;
                        }
                    }
                    col++;
                }
            }
        }
    }

    return false;
}



int main() {

    int n; // linhas
    int m; // colunas
    int v;
    int inicio, fim;

    scanf(" %d %d", &n, &m);

    vector<vector<int>> grafo(n, vector<int>(m, 0));

    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            scanf(" %d", &v);
            grafo[i][j] = v;
        }
    }
    
    // printf("Nó de início: ");
    scanf(" %d", &inicio);
    // printf("Nó destino: ");
    scanf(" %d", &fim);

    printf("%s\n", (busca_largura(grafo, inicio, fim) ? "O caminho é possível." : "O caminho é impossível"));
    printf("%s\n", (busca_profundidade(grafo, inicio, fim) ? "O caminho é possível." : "O caminho é impossível"));
    

    return 0;
}
