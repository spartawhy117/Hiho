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
		//p[k]��ʾǰ׺��p[j]��ʾ��׺    
		if (k == -1 || p[j] == p[k])
		{
			++j;
			++k;
			//��֮ǰnext�����󷨣��Ķ�������4��  
			if (p[j] != p[k])
				next[j] = k;   //֮ǰֻ����һ��  
			else
				//��Ϊ���ܳ���p[j] = p[ next[j ]]�����Ե�����ʱ��Ҫ�����ݹ飬k = next[k] = next[next[k]]  
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
