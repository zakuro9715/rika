#include <cassert>
#include <initializer_list>
#include <iterator>

namespace rika
{
  template <typename T>
  class point
  {
    public:
      T x, y;

      point(T v): x(v), y(v) {}
      point(T _x, T _y): x(_x), y(_y) {}
      point(std::initializer_list<T> l)
      {
        switch(l.size())
        {
          case 0: break;
          case 1:
                  x = y = *l.begin();
                  break;
          case 2:
                  x = *l.begin();
                  y = *std::next(l.begin(), 1);
                  break;
          default:
                  assert(false);
        }
      }
  };
}
