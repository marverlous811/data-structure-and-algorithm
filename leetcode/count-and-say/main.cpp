#include <stdio.h>
#include <stdlib.h>
#include <string>

std::string stringCount(std::string str) {
	std::string retval = "";
	char cur = 0;
	int count = 0;
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
		char tmp = *it;
		if (cur != tmp) {
			if (cur != 0) {
				retval.push_back('0' + count);
				retval.push_back(cur);
			}
			cur = tmp;
			count = 0;
		}
		count++;
	}

	retval.push_back('0' + count);
	retval.push_back(cur);
	return retval;
}

std::string say(int n) {
	if (n == 1) {
		return "1";
	}
	return stringCount(say(n - 1));
}



int main() {
	for (auto i = 1; i < 10; i++) {
		printf("result %d %s\n", i, say(i).c_str());
	}
	return 0;
}