/*Light Up the Bulbs
Send Feedback
Navdeep is given a binary string (string consists of only 0’s and 1’s) of size ‘n’. The string represents the state of n bulbs. ‘0’ represents that the bulb is in ‘OFF’ mode and ‘1’ represents the bulb is in ‘ON’ mode. Navdeep is given the task to change all the characters to 1. In other words, Navdeep has to light up all the bulbs.
He can perform two operations on the given string:
1. In the first operation, he can choose any substring and reverse it. For example, in the binary string: 0110001, if we reverse substring from 1st to 3rd index in the given string, then the resultant string will be: 0011001. Here, 110 is reversed to form 011. This operation will cost Rs. ‘X’.
2. In the second operation, he can choose any substring and toggle each character of that substring. For example, in the binary string: 0110001, if we toggle characters of the substring from 1st to 3rd index in the given string, then the resultant string will be: 0001001. Here, 110 is converted to form 001. This operation will cost Rs. ‘Y’.     
Can you help Navdeep to complete the task in the minimum amount possible.
Input Format:
The first line will contain three space separated integers: ‘n’, ‘X’, ‘Y’, denoting the number of bulbs, cost of first operation and cost of second operation respectively.
The second line contains a binary string of length ‘n’, consisting of 0’s and 1’s,  representing whether the bulb is ‘OFF’ or ‘ON’.
Output Format:
Print a single integer denoting the minimum cost required to light up all the bulbs.
Constraints:
1 <= n <= 3,00,000
0 <= X, Y <= 10^9
Time Limit: 1 second
Sample Input:
5 1 10
01000
Sample Output:
11
Explanation:
First, Reverse substring (0, 1): “01000” -> “10000”, COST = 1
Second, Invert substring (1, 4): “10000” -> “11111”, COST = 10
Total cost = 1+10 => 11*/


/*Approach
The code you provided is an implementation of the problem to calculate the minimum cost required to light up all the bulbs, given the constraints and operations as described in the problem statement. Here's the approach explained within the code:

1. Read input values:
   - `n`, `x`, and `y` represent the number of bulbs, cost of the first operation, and cost of the second operation, respectively.
   - Read the binary string `s` of length `n`.

2. Initialize a variable `zeroCount` to 0. This variable will keep track of the number of contiguous sequences of '0's in the binary string.

3. Iterate through the binary string from the first character to the second-to-last character (indices 0 to n-2). Inside the loop, check if the current character is '0' and the next character is '1'. If this condition is met, it means a contiguous sequence of '0's is encountered. Increment the `zeroCount` variable.

4. After the loop, check if the last character of the binary string is '0'. If it is, increment the `zeroCount` variable again because there is one more contiguous sequence of '0's that ends with the last character.

5. Check if `zeroCount` is equal to 0. If it is, this means that there are no contiguous sequences of '0's in the binary string, and all bulbs are already in the 'ON' state. In this case, output 0 as the cost required and exit.

6. Calculate the minimum cost to light up all the bulbs using the following formula:
   - `r = (zeroCount - 1) * min(x, y)` - This represents the cost of using the first operation (reverse) on all but the last contiguous sequence of '0's.

7. Finally, output the minimum cost, which is `r + y`. The `y` cost is added because the last contiguous sequence of '0's (if it exists) can be transformed to '1's using the second operation (toggle).

The code provides the minimum cost required to light up all the bulbs based on the given input values and operations.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    int zeroCount=0;
    
    for(int i=0; i<n-1; i++){
        if(s[i]=='0' && s[i+1]=='1'){
            zeroCount++;
        }
    }
    if(s[n-1]=='0'){
        zeroCount++;
    }
    if(zeroCount==0){
        cout<<0<<endl;
        return 0;
    }
   long long r=(zeroCount-1)*min(x,y);
    cout<<r+y<<endl;
    return 0;
}