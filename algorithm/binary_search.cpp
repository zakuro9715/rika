#include<bits/stdc++.h>
using namespace std;

namespace rika
{
  template <typename T>
  T binary_search(function<bool(T)> func, T include, T exclude)
  {
    while (abs(exclude - include) > 1)
    {
      auto middle = (include + exclude) / 2;
      (func(middle) ? include : exclude) = middle;
    }
    return include;
  }
}
