#include <bits/stdc++.h>

using namespace std;

int input_num, parent, child, weight;
int max_cum_weight = 0;
int max_node = 0;
bool visited[10001] = {false};
vector<vector<pair<int, int>>> edges(10001);

void checkNextNode(int node, int cum_weight)
{
	// cout << "max_node : " << max_node << ", max_cum_weight : " << max_cum_weight << '\n';
	// cout << "node : " << node << ", cum_weight : " << cum_weight << "\n\n";
	
    if(visited[node]) return;
    visited[node] = true;

    if(max_cum_weight < cum_weight)
    {
        max_cum_weight = cum_weight;
        max_node = node;
    }

	for(int i = 0; i < edges[node].size(); i++)
        checkNextNode(edges[node][i].first, edges[node][i].second + cum_weight);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin >> input_num;

    for (int i = 0; i < input_num; i++)
    {
        cin >> parent >> child >> weight;
        edges[parent].push_back({child, weight});
        edges[child].push_back({parent, weight});
    }

    checkNextNode(1, 0);
    max_cum_weight = 0;
    memset(visited, false, 10001);
    checkNextNode(max_node, 0);
    
    cout << max_cum_weight;
    
	return 0;
}