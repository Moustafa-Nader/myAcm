vector<int> vc[maxn];
bool mark[maxn];
void dfs(int v){
    mark[v] = 1;
    for(int u: vc[v])
	if(!mark[u])
	    dfs(u);
}
