// to calculate maximum substring with k distinct character//
//In a row of trees, the i-th tree produces fruit with type tree[i].
medium level problem...
You start at any tree of your choice, then repeatedly perform the following steps:

Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?

 
#include <iostream>
#include <string>
#include<set>
using namespace std;

// define character range
#define CHAR_RANGE 128

// Function to find longest substring of given string containing
// k distinct characters using sliding window
string longestSubstr(string str, int k, int n)
{
	// stores longest substring boundaries
	int end = 0, begin = 0;
	
	// set to store distinct characters in a window
	set<char> window;

	// count array to store frequency of characters present in
	// current window	
	// we can also use a map instead of count array
	int freq[CHAR_RANGE] = { 0 };

	// [low..high] maintain sliding window boundaries
	for (int low = 0, high = 0; high < n; high++)
	{
		window.insert(str[high]);
		freq[str[high]]++;
		
		// if window size is more than k, remove characters from the left
		while (window.size() > k)
		{
			// if the frequency of leftmost character becomes 0 after
			// removing it in the window, remove it from set as well
			if (--freq[str[low]] == 0)
				window.erase(str[low]);

			low++;		// reduce window size
		}
		
		// update maximum window size if necessary
		if (end - begin < high - low)
		{
			end = high;
			begin = low;
		}
	}
	
	// return longest substring found at str[begin..end]
	return str.substr(begin, end - begin + 1);
}

// main function
int main()
{
	string str = "aaabbbcccddddddd";
	int k = 2;

	int n = str.length();
	cout << longestSubstr(str, k, n).length();

	return 0;
}
