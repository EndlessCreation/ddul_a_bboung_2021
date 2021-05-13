#include <bits/stdc++.h>

using namespace std;

int last_node, parent, child, weight, node_count = 0;
int max_cum_weight = 0;
int max_node = 0;
bool visited[100001] = {false};
vector<vector<pair<int, int>>> edges(100001);

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
	
    cin >> last_node >> parent;
	
    while(true)
    {
		cin >> child >> weight;
        if(child == -1)
        {
            node_count++;
        	if(node_count == last_node)
        		break;
            parent = weight;
            continue;
        }
        edges[parent].push_back({child, weight});
    }

    checkNextNode(1, 0);
    max_cum_weight = 0;
    memset(visited, false, last_node + 1);
    checkNextNode(max_node, 0);
    
    cout << max_cum_weight;
    
	return 0;
}