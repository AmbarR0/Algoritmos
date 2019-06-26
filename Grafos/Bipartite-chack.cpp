#include <bits/stdc++.h>

using namespace std;
int C[100000];
vector<int>G[100000];
bool dfs(int u, int p)
{
    bool ans = true;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if(v!=p)
        {
            int Cad = 1-C[u];
            if(C[v]==-1)
            {
                ans = ans and dfs(v, u);

            }
            else
            {
                if(C[v]==C[u])
                {
                    ans = false;
                    return false;
                }
            }
        }
    }
    return ans;
}
int main()
{
    bool esB = true;
    int N, a, b;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0; i<N; i++)
    {
        if(C[i]==-1)
        {
            C[i] = 0;
            esB = esB and dfs(i, -1);
        }
    }
    if(esB==true)
    {
        cout << "SI" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
