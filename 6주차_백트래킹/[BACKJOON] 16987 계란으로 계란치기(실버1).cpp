#include <bits/stdc++.h>

using namespace std;

int N, weight, durability, max_break = 0, breaked_num = 0;
vector<pair<int, int>> eggs;
vector<bool> breaked(9, false);

void crashEgg(int now, int breakedEgg)
{
    if(now == N || breaked_num == N-1)
    {
        max_break = max(max_break, breakedEgg);
        return;
    }
    if(breaked[now])
    {
        crashEgg(now+1, breakedEgg);
    }
    else 
    {
    	for(int i = 0; i < N; i++)
	    {
	        if(i == now || breaked[i]) continue;
	
	        eggs[now].first -= eggs[i].second;
	        eggs[i].first -= eggs[now].second;
	
	    	breaked[i] = eggs[i].first <= 0;
	    	breaked[now] = eggs[now].first <= 0;
	    	breaked_num += breaked[i] + breaked[now];
	    
	        crashEgg(now + 1, breakedEgg + breaked[i] + breaked[now]);
	
	        eggs[now].first += eggs[i].second;
	        eggs[i].first += eggs[now].second;
	        
	        breaked[i] = eggs[i].first <= 0;
	    	breaked[now] = eggs[now].first <= 0;
	    	breaked_num -= breaked[i] + breaked[now];
	    }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> durability >> weight;
        eggs.push_back({durability, weight});
    }
    
    crashEgg(0, 0);
    
    cout << max_break << '\n';
}
