void comp_prefix(vector<int> &prefix, string p)
{
	if(p[0] != ' ')
		p = " " + p;
	int m = p.length();
	prefix[1] = 0;
	int k = 0;
	for(int q = 2; q <= m; q++)
	{
		while(k > 0 && p[k+1]!=p[q])
			k = prefix[k];
		if(p[k+1] == p[q])
			k++;
		prefix[q] = k;

	}
}

vector<int> kmp_matcher(string t, string p)
{
	t = " " + t;
	p = " " + p;
	int n = t.length();
	int m = p.length();
	
	vector<int> prefix(m);
	comp_prefix(prefix, p);
	vector<int> positions;
	int q = 0;
	for(int i = 1; i <= n; i++)
	{
		while(q > 0 && p[q+1] != t[i])
			q = prefix[q];

		if(p[q+1] == t[i])
			q++;

		if(q == m)
		{	
			positions.push_back(i-m-1);
			q = prefix[q];
		}

	}

	return positions;
}