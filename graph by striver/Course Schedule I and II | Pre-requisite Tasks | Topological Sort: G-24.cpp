#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
	vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites)
	{
		vector<int> adj[V];
		for (auto it : prerequisites) {
			adj[it[1]].push_back(it[0]);
		}



		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		if (topo.size() == V) return topo;
		return {};
	}
};


int main() {

	int N = 4;
	int M = 3;

	vector<vector<int>> prerequisites(3);
	prerequisites[0].push_back(0);
	prerequisites[0].push_back(1);

	prerequisites[1].push_back(1);
	prerequisites[1].push_back(2);

	prerequisites[2].push_back(2);
	prerequisites[2].push_back(3);

	Solution obj;
	vector<int> ans = obj.findOrder(N, M, prerequisites);

	for (auto task : ans) {
		cout << task << " ";
	}
	cout << endl;
	return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
// 	bool isPossible(int V, vector<pair<int, int> >& prerequisites) {
// 		vector<int> adj[V];
// 		for (auto it : prerequisites) {
// 			adj[it.first].push_back(it.second);
// 		}



// 		int indegree[V] = {0};
// 		for (int i = 0; i < V; i++) {
// 			for (auto it : adj[i]) {
// 				indegree[it]++;
// 			}
// 		}

// 		queue<int> q;
// 		for (int i = 0; i < V; i++) {
// 			if (indegree[i] == 0) {
// 				q.push(i);
// 			}
// 		}
// 		vector<int> topo;
// 		while (!q.empty()) {
// 			int node = q.front();
// 			q.pop();
// 			topo.push_back(node);
// 			// node is in your topo sort
// 			// so please remove it from the indegree

// 			for (auto it : adj[node]) {
// 				indegree[it]--;
// 				if (indegree[it] == 0) q.push(it);
// 			}
// 		}

// 		if (topo.size() == V) return true;
// 		return false;


// 	}
// };

// int main() {

// 	vector<pair<int, int>> prerequisites;
// 	int N = 4;
// 	prerequisites.push_back({1, 0});
// 	prerequisites.push_back({2, 1});
// 	prerequisites.push_back({3, 2});

// 	Solution obj;
// 	bool ans = obj.isPossible(N, prerequisites);

// 	if (ans) cout << "YES";
// 	else cout << "NO";
// 	cout << endl;

// 	return 0;
// }