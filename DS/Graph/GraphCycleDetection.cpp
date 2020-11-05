#include <iostream>
#include <iostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

void BFS(int adjMat[][7],int start, int n) {
	int* visited = new int[n];
	Queue q(n);
	for (int i = 0; i < n; i++)
		visited[i] = 0;
	int i;
	visited[start] = 1;
	cout << start << " ";
	q.enqueue(start);
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
	Stack st(n);
	int* visited = new int[n];
	for (int i = 0; i < n; i++)
		visited[i] = 0;

	int i = start,j;
	st.push(i);
	visited[i] = 1;
	while (!st.isEmpty()) {
		i = st.pop();
		cout << i << " ";
		for (j = 1; j < n; j++) {
			if (adjMat[i][j] == 1 && visited[j] == 0) {
					st.push(j);
					visited[j] = 1;

			}
		}
	}

}



bool checkCycle(int adjMat[][6], int start, int n, int parent) {
	static int visited[6] = { 0 };
	if (visited[start] == 0) {
		visited[start] = 1;
		for (int j = 1; j < n; j++) {
			if (adjMat[start][j] != 0) {
				if (visited[j] == 0) {
					if (checkCycle(adjMat, j, n, start)) {
						return true;
					}
				}
				else {
					if (j != parent) {
						return true;
					}
				}
			}
		}
	}

	return false;
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

	BFS(adjMat, 1, 7);
	cout << endl;
	DFS(adjMat, 1, 7);
	cout << endl;

	int acyclicMat[][6] = { {0,0,0,0,0,0},
					  {0,0,1,0,0,0},
					  {0,1,0,1,1,0},
					  {0,0,1,0,0,0},
					  {0,0,1,0,0,1},
					  {0,0,0,0,1,0} };
	int cyclicMat[][6] = { {0,0,0,0,0,0},
					  {0,0,1,0,0,0},
					  {0,1,0,1,1,0},
					  {0,0,1,0,1,0},
					  {0,0,1,1,0,1},
					  {0,0,0,0,1,0} };

//	cout << endl;
//	cout << checkCycle(acyclicMat, 1, 6, -1) << endl;

	cout << endl;
	cout << checkCycle(cyclicMat, 1, 6, -1) << endl;

}
