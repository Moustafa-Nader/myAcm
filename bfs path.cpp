

vector<int> BFSPath(int s, int d, vector<vector<int> > & adjList) {
	vector<int> len(sz(adjList), OO);
	vector<int> par(sz(adjList), -1);
	queue<int> q;
	q.push(s), len[s] = 0;

	int dep = 0, cur = s, sz = 1;
	bool ok = true;

	for ( ; ok &&  !q.empty();	++dep, sz = q.size()) {
		while (ok && sz--) {
			cur = q.front(), q.pop();
			rep(i, adjList[cur]) if (len[adjList[cur][i]] == OO)
			{
				q.push(adjList[cur][i]), len[adjList[cur][i]] = dep+1, par[ adjList[cur][i] ] = cur;

				if(adjList[cur][i] == d)	// we found target no need to continue
				{
					ok = false;
					break;
				}
			}
		}
	}

	vector<int> path;
	while(d != -1) {
		path.push_back(d);
		d = par[d];
	}

	reverse( all(path) );

	return path;
}

