#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol46;
using namespace std;

/*takeaways
  - everyone takes turns to be the first (on the left) in the permutation
    while composing the permutation recursively
*/

void Solution::_permute(vector<int> &num, vector<int> &picked,
                        vector<int> &permutation, vector<vector<int>> &result)
{
  /* completed constructing the permutation */
  if (permutation.size() == num.size())
  {
    result.push_back(permutation);
    return;
  }

  /* assemble the permutation from left to right
     - everyone takes turns to be the first in the
       permutation
  */

  for (auto i = 0; i < num.size(); i++)
  {
    if (picked[i])
      continue;

    /*we have duplicates which is the main difference from the question 46
      where any duplicates are not allowed
      - so if the previous number was picked, that means you are in the middle
        of constructing a permutation as we are scanning from left to right
        to build the permutation recursively
      - if the previous number wasn't picked, that means the previous number
        has been restored after completing creating a permutation, and we
        are starting a new permutation at a certain recursion level
        for the current number. If they are the same, we will
        composing a new permutation with the exact same number,
        which will result in a duplicate permutation
    */

    if (i > 0 && num[i - 1] == num[i] && !picked[i - 1])
      continue;

    permutation.push_back(num[i]), picked[i] = 1;

    _permute(num, picked, permutation, result);
    /* restore the state
       - to start a new permutation
    */
    picked[i] = 0, permutation.pop_back();
  }
}

vector<vector<int>> Solution::permute(vector<int> &num)
{
  auto picked = vector<int>(num.size(), 0);
  auto p = vector<int>();
  auto result = vector<vector<int>>();
  /* so that we can put the duplicates next to each other */
  sort(begin(num), end(num));

  _permute(num, picked, p, result);

  return result;
}