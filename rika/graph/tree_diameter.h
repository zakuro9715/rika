#include <algorithm>

namespace rika
{
  namespace internal
  {
    template <typename TValue, typename TGraph>
    std::pair<TValue, int> visit(int from, int v, const TGraph &g)
    {
      auto r = std::make_pair(TValue(), v);
      for(auto it = g[v].begin(); it != g[v].end(); ++it)
      {
        if(it->to == from)
          continue;
        auto r2 = visit<TValue>(v, it->to, g);
        if(r2.first + it->cost >= r.first)
          r = std::make_pair(r2.first + it->cost, r2.second);
      }
      }
      return r;
    }
  }

  template <typename TValue, typename TGraph>
  TValue tree_diameter(const TGraph &g)
  {
    using namespace internal;
    auto r1 = visit<TValue>(-1, 0, g);
    auto r2 = visit<TValue>(-1, r1.second, g);
    return r2.first;
  }
}
