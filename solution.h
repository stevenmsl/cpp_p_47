
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol46
{

  class Solution
  {
  private:
    void _permute(vector<int> &num, vector<int> &picked,
                  vector<int> &permutation, vector<vector<int>> &result);

  public:
    vector<vector<int>> permute(vector<int> &num);
  };
}
#endif