#include <bits/stdc++.h>

#define INF 99999

using namespace std;

typedef long long int lli;

typedef tuple<lli, lli> ii;
// adjacency list's tuple: (vertex, weight)
typedef tuple<lli, lli, lli> iii;

//
// Utility fuinctions
//

bool compareEdges(iii e1, iii e2) {
    /*
     * Utility function to compare two edges.
     * Returns true if edge e1 should be placed
     * before edge e2 (e1.weight < e2.weight).
     * */
    
    return get<2>(e1) < get<2>(e2);
}

bool isEdgeIn(iii x, vector<iii> edgeList) {
    /*
     * Returns whether a edge 'x' is in
     * a given edge list.
     * */

    for (iii y : edgeList) {
        if (get<0>(y) == get<0>(x) && get<1>(y) == get<1>(x)) {
            return true;
        }
        
        if (get<0>(y) == get<1>(x) && get<1>(y) == get<0>(x)) {
            return true;
        }
    }
    
    return false;
}

bool isIn(lli x, vector<lli> vec) {
    /*
     * Returns whether or not 'x' is 
     * is vec.
     * */

    for (lli y : vec) {
        if (y == x) return true;
    }

    return false;
}

lli pickVertex(vector<lli> vec, vector<lli> set) {
    /*
     * Returns the position of the minimun
     * element within given vetor vec that
     * is not within vector set.
     * */

    lli pos = 0;
    lli val = INF;
    for (lli i=0; i < (lli)vec.size(); i++) {
        if (vec[i] < val && !isIn(i, set)) {
            val = vec[i];
            pos = i;
        }
    }

    return pos;
}

//
//

class Graph {
    /*
     * Represents a graph using a adjacency list.
     * When instantiated asks for the number
     * of vertices |V| and edges |E|.
     * */

    public:

        Graph(lli vertices, lli edges) {
            this -> vertices = vertices;
            this -> edges = edges;
        }

        Graph() {
            this -> vertices = 0;
            this -> edges = 0;
        }

        lli getEdges() {
            return this -> edges;
        }

        lli getVertices() {
            return this -> vertices;
        }

        void createByMatrix(vector<vector<lli> > matrix) {
            /*
             * Detects whether the given matrix is a
             * adjacency or a incidence matrix and
             * creates the graph based on it.
             * */

            if (matrix.size() != matrix[0].size()) {
                this -> createByIncidenceMatrix(matrix);
                return;
            }

            lli matrixSize = (lli) matrix.size();
            vector<int> columnSum (matrixSize, 0);

            for (lli i=0; i < matrixSize; i++) {
                for (lli j=0; j < matrixSize; j++) {
                    columnSum[j] += matrix[i][j];

                    if (matrix[i][j] != matrix[j][i]) {
                        printf("%lli %lli\n", matrix[i][j], matrix[j][i]);
                        this -> createByIncidenceMatrix(matrix);
                        return;
                    }

                    if (columnSum[j] > 2) {
                        this -> createByAdjacencyMatrix(matrix);
                        return;
                    }
                }
            }
        }

        void createByAdjacencyMatrix(vector<vector<lli> > matrix) {
            /*
             * Creates a graph represented as a adjacency list
             * using the given adjacency matrix.
             * */

            lli rows = (lli)matrix.size();
            this -> vertices = rows;

            for (lli i=0; i < rows; i++) {
                this -> adjacencyList.push_back(vector<ii>());
                for (lli j=0; j < rows; j++) {
                    if (matrix[i][j]) {
                        this -> edges ++;

                        adjacencyList[i].push_back(ii(j, matrix[i][j]));
                    }
                }
            }

            this -> edges = this -> edges / 2;
            
            /*for (lli i=0; i < rows; i++) {
                printf("[%lli] -> ", i);
                for (lli j=0; j < (lli)this -> adjacencyList[i].size(); j++) {
                    printf(" (%lli, %lli) -> ", get<0>(this -> adjacencyList[i][j]), get<1>(this -> adjacencyList[i][j]));
                }
                printf("\n");
            }*/

        }

        void createByIncidenceMatrix(vector<vector<lli> > matrix) {
            /*
             * Creates a graph represented as a adjacency list 
             * using the given incidence matrix.
             * */
            
            lli rows = (lli)matrix.size();
            lli columns = (lli)matrix[0].size();
            lli lastRow;

            this -> adjacencyList.assign(rows, vector<ii>());
            this -> vertices = rows;

            for (lli j=0; j < columns; j++) {
                lastRow = -1;
                for (lli i=0; i < rows; i++) {
                    if (matrix[i][j]) {
                        if (lastRow != -1) {
                            adjacencyList[i].push_back(ii(lastRow, matrix[i][j]));
                            adjacencyList[lastRow].push_back(ii(i, matrix[i][j]));

                            this -> edges ++;
                        }

                        lastRow = i;
                    }
                }
            }
            
            /*for (lli i=0; i < rows; i++) {
                printf("[%lli] -> ", i);
                for (lli j=0; j < (lli)this -> adjacencyList[i].size(); j++) {
                    printf(" (%lli, %lli) -> ", get<0>(this -> adjacencyList[i][j]), get<1>(this -> adjacencyList[i][j]));
                }
                printf("\n");
            }*/

        }

        vector<vector<ii> > getAdjacencyList() {
            return this -> adjacencyList;
        }
        
        vector<iii> buildEdgeList() {
            vector<iii> edgeList;
            lli vertices = (lli)this -> adjacencyList.size();
            for (lli i=0; i < vertices; i++) {
                for (lli j=0; j < (lli) this -> adjacencyList[i].size(); j++) {
                    iii x(i, get<0>(this -> adjacencyList[i][j]), get<1>(this -> adjacencyList[i][j]));
                    if (!isEdgeIn(x, edgeList)) {
                        edgeList.push_back(x);
                    }    
                }
            }

            sort(edgeList.begin(), edgeList.end(), compareEdges);
            
            /*for (iii x : edgeList) {
                printf("(s: %lli, d: %lli, w: %lli)\n", get<0>(x), get<1>(x), get<2>(x));
            }*/

            return edgeList;
        }

    private:
        vector<vector<ii> > adjacencyList;
        lli vertices;
        lli edges;

};

class UnionFind {
    /*
     * Represents a Union-Find disjoint set 
     * data structure.
     * Operations available are union and find,
     * the make-set operation is performed on 
     * instantiation.
     * */

    public:
        UnionFind(Graph g) {
            /*
             * Make set operation.
             * Initializes the union-find with
             * parents and ranks.
             * */

            lli vertices = (lli)g.getAdjacencyList().size();

            this -> parent = new lli[vertices];
            this -> rank = new lli[vertices];

            for (lli i=0; i < vertices; i++) {
                this -> parent[i] = i;
                this -> rank[i] = 0;
            }

        }

        lli Find(lli x) {
            if (this -> parent[x] != x) {
                this -> parent[x] = this -> Find(this -> parent[x]);
            }

            return this -> parent[x];
        }

        void Union(lli x, lli y) {
            lli xRoot = this -> Find(x);
            lli yRoot = this -> Find(y);

            if (this -> rank[xRoot] > this -> rank[yRoot]) {
                this -> parent[yRoot] = this -> parent[xRoot];
            
            } else if (this -> rank[yRoot] > this -> rank[xRoot]) {
                this -> parent[xRoot] = this -> parent[yRoot];
            
            } else {
                this -> parent[yRoot] = xRoot;
                this -> rank[xRoot] ++;
            }
        }

    private:
        lli *parent;
        lli *rank;

};

lli kruskalMST(vector<vector<lli> > matrix) {
    /*
     * Builds the Minimun Spanning Tree
     * using kruskal's algorithm for the graph
     * given as a adjacency matrix or as a 
     * incidence matrix.
     *
     * Returns the cost of building the tree and
     * prints the edges at same order they were
     * inserted in MST.
     * */

    Graph graph;
    graph.createByMatrix(matrix);

    vector<iii > edgeList = graph.buildEdgeList();

    UnionFind uf(graph);

    lli cost = 0;

    printf("Arestas incluídas:\n{");
    for (lli i=0; i < graph.getEdges(); i++) {
        lli v1 = uf.Find(get<0>(edgeList[i]));
        lli v2 = uf.Find(get<1>(edgeList[i]));

        if (v1 != v2) {
            cost += get<2>(edgeList[i]);
            uf.Union(v1, v2);

            // TODO: create a function to print edges given two vertice.
            // in Graph or outside?
            printf("%c-%c, ", (char)get<0>(edgeList[i]) + 65, (char)get<1>(edgeList[i]) + 65);
        }
    }

    printf("\b\b}\n");

    return cost;
}

lli primMST(vector<vector<lli> > matrix, lli startVertex) {
    /*
     * Builds the Minimun Spanning Tree
     * using prim's algorithm for the graph
     * given as a adjacency matrix or as a 
     * incidence matrix.
     *
     * Returns the cost of building the tree and
     * prints the edges at same order they were
     * inserted in MST.
     * */

    Graph graph;
    graph.createByMatrix(matrix);

    vector<vector<ii> > adjacencyList = graph.getAdjacencyList();

    lli cost = 0;

    vector<lli> mstSet;
    vector<lli> keyValues (graph.getVertices(), INF);
    vector<lli> sources (graph.getVertices(), -1);
    keyValues[startVertex] = 0;

    printf("Vértices incluídos:\n{");
    //lli lastVertex = -1;

    while ((lli)mstSet.size() < graph.getVertices()) {
        lli vertex = pickVertex(keyValues, mstSet);
        mstSet.push_back(vertex);
        
        /*if (lastVertex != -1) {
            printf("%c-%c, ", (char)lastVertex + 65, (char)vertex + 65);
        }

        lastVertex = vertex;*/
        cost += keyValues[vertex];
        printf("%c, ", (char)vertex + 65);

        for (ii v : adjacencyList[vertex]) {
            keyValues[get<0>(v)] = get<1>(v);
        }
    }

    printf("\b\b}\n");

    return cost;
}

int main() {

    lli n; // rows
    lli m; // columns
    lli x; // start vertex for prim
    lli v;
 
    scanf(" %lli %lli", &n, &m);
 
    vector<vector<lli>> matrix(n, vector<lli>(m, 0));
 
    for (lli i=0; i < n; i++) {
        for (lli j=0; j < m; j++) {
            scanf(" %lli", &v);
            matrix[i][j] = v;
        }
    }

    scanf(" %lli", &x);

    printf("Kruskal: %lli\n", kruskalMST(matrix));
    printf("Prim: %lli\n", primMST(matrix, x));

    return 0;
}
