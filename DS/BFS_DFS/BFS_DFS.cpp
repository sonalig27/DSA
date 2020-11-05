
#include <iostream>
#include "Queue.h"


void BFS(int adjMat[][7], int start, int n) {
    Queue q(n);
    int i = start;
    int *visited = new int[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << i << " ";
    visited[i] = 1;
    q.enqueue(i);

    while (!q.isEmpty()) {
        i = q.dequeue();
        for (int j = 1; j < n; j++) {
            if (adjMat[i][j] != 0 && visited[j] == 0) {
                cout << j << " ";
                q.enqueue(j);
                visited[j] = 1;
            }
        }
    }

}


void DFS(int adjMat[][7], int start, int n) {
    //  static int* visited = new int[n];
    static int visited[7] = { 0 };
    if (visited[start] == 0) {
        cout << start << " ";
        visited[start] = 1;
        for (int j = 1; j < n; j++){
           if (adjMat[start][j] != 0 && visited[j] == 0) {
               DFS(adjMat, j, n);
            }
        }
    }

}

bool checkCycleDFS(int adjMat[][6], int start, int n, int parent) {
    static int visited[6] = { 0 };
    if (visited[start] == 0) {
        visited[start] = 1;
        for (int j = 1; j < n; j++) {
            if (adjMat[start][j] != 0) {
                if (visited[j] == 0) {
                    if (checkCycleDFS(adjMat, j, n, start)) {
                        return true;
                    }
                }
                else {
                    if (j != parent)
                        return true;
                }
            }
        }
        return false;
    }

}

int main()
{
    int adjMat[][7] = { {0,0,0,0,0,0,0},
                      {0,0,1,1,0,0,0},
                      {0,1,0,0,1,0,0},
                      {0,1,0,0,1,0,0},
                      {0,0,1,1,0,1,1},
                      {0,0,0,0,1,0,0},
                      {0,0,0,0,1,0,0} };

    int acyclicMat[][6] = { {0,0,0,0,0,0},
                      {0,0,1,0,0,0},
                      {0,1,0,1,1,0},
                      {0,0,1,0,0,0},
                      {0,0,1,0,0,1},
                      {0,0,0,0,1,0}};

    int cyclicMat[][6] = { {0,0,0,0,0,0},
                      {0,0,1,0,0,0},
                      {0,1,0,1,1,0},
                      {0,0,1,0,1,0},
                      {0,0,1,1,0,1},
                      {0,0,0,0,1,0} };
    BFS(adjMat, 3, 7);
    cout << endl;
    DFS(adjMat, 4, 7);
    cout << endl;
    cout << checkCycleDFS(acyclicMat, 1, 6, -1) << endl;

    cout << endl;
    cout << checkCycleDFS(cyclicMat, 1, 6, -1) << endl;

}