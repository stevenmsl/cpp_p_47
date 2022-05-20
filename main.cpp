#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol46;

/*
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

tuple<vector<int>, vector<vector<int>>>
testFixture1()
{
  auto input = vector<int>{1, 1, 2};
  auto output = vector<vector<int>>{
      {1, 1, 2},
      {1, 2, 1},
      {2, 1, 1}};

  return make_tuple(input, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.permute(get<0>(f))) << endl;
}

main()
{
  test1();
  return 0;
}