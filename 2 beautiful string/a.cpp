#include <iostream>

int findLen(std::string& s, int k, char ch)
{
	int maxlen = 1;
	int cnt = 0;
	int l = 0, r = 0;
	int n = s.length();
	while (r < n) {
	
		if (s[r] != ch)
			++cnt;
		while (cnt > k) {
			if (s[l] != ch)
				--cnt;
			++l;
		}
		maxlen = std::max(maxlen, r - l + 1);
		++r;
	}
	return maxlen;
}

int answer(std::string& s, int k)
{
	int maxlen = 1;
	for (int i = 0; i < 26; ++i) {
		maxlen = std::max(maxlen, findLen(s, k, i+'a'));
	}
	return maxlen;
}

int main()
{
	int k;
	std::string s; 
	std::cin >> k >> s;
	std::cout << answer(s, k);

	return 0;
}
