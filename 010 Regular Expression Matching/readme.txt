001.cpp (4ms):

A DP problem with transfer function:

f[i][j] = (p[j+1] == '*') AND f[i][j+2] OR {the character before '*' can be ignored}
	  isMatch(s[i], p[j]) AND f[i+1][j+1] OR {there exists a simple matching} 
	  isMatch(s[i], p[j]) AND (p[j+1] == '*') AND f[i+1][j] {the character before '*' is repeatable}
