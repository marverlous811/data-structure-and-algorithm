#include <stdio.h>
#include <stdlib.h>
#include <string>


/*
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
- countAndSay(1) = "1"
- countAndSay(n) is the way you would “say” the digit string from countAndSay(n-1), which is then converted into a different digit string.

To determine how you “say” a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. 
Then for each group, say the number of characters, then say the character. 
To convert the saying into a digit string, replace the counts with a number and concatenate every saying.
Given a positive integer n, return the n^th term of the count-and-say sequence.

Ex:
Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
*/
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