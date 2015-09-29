namespace rika
{
  template <typename T>
  class edge
  {
  public:
    int to;
    T cost;
    
    edge() = default;
    edge(const edge<T>&) = default;
    edge(edge<T>&&) = default;
    edge& operator =(const edge<T>&) = default;
    edge& operator =(edge<T>&&) = default;

    ~edge() = default;
    edge(int _to, T _cost) : to(_to), cost(_cost) {}
  };
}
