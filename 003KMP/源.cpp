#include <iostream>
#include <vector>
#include <string>
using namespace std;
void GetNext(const string& p,int *next,int len)
{
	int plen = len;
	next[0] = -1;
	int k = -1;
	int j = 0;

	while (j < plen-1)
	{
		//p[k]表示前缀，p[j]表示后缀    
		if (k == -1 || p[j] == p[k])
		{
			++j;
			++k;
			//较之前next数组求法，改动在下面4行  
			if (p[j] != p[k])
				next[j] = k;   //之前只有这一行  
			else
				//因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]  
				next[j] = next[k];
		}
		else
		{
			k = next[k];
		}
	}
}


int KmpSearch(const string& s,const string& p)
{
	int i = 0;
	int j = 0;

	int slen = s.size();
	int plen = p.size();

	if (slen < plen)
		return 0;

	int count = 0;

	int *next = new int[plen];

	GetNext(p, next,plen);

	while (i < slen )
	{      
		while (i < slen && j < plen)
		{
			if (j == -1 || s[i] == p[j])
			{
				i++;
				j++;

			}
			else
			{
				j = next[j];
			}
		}

		if (j == plen)
		{
			count++;
			i = i - j + 1;
			j = 0;
		}
	
	}

	

	return count;

}


int main(int argc, char* argv[])
{
	int n;
	cin >> n;

	while (n--)
	{
		string patter;
		string origin;
		cin >> patter>>origin;
		cout << KmpSearch(origin, patter) << endl;

	}
}
