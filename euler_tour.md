# Euler Tour Technique

## Euler Tourとは

Euler tour techniqueとは木を展開する方法の1つで、LCAを求める際などに使用します。


具体的には、以下のような木は、

```
1_____
|\    \
2 3    4
  |\   |
  5 6  7
```

次のように展開します。


| index |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10 |  11 |  12 |  13 |
| ----- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| node  |  1  |  2  |  1  |  3  |  5  |  3  |  6  |  3  |  1  |   4 |   7 |   4 |   1 |

これは、DFSをしながら訪れたノードを順番に追加していくことで実現できます。

```cpp
vector<int> e
void dfs(int n)
{
  for(auto to: children)
  {
    e.push_back(n);
    dfs(to);
  }
  e.push_back(n);
}
```

## LCAの求め方

さて、このままではLCAを求めることはできません。
そこで、上述のEuler Tourから、次の2点を変更をします。

- あるノードが、EulerTourで展開した配列内で最初に現れるindexを別途記録する。
- ノード番号ではなく、深さを記録する。

すると、コードは以下のようになります。

```cpp
vector<int> e
int e1[N];

void dfs(int n, int d)
{
  e1[n] = e.size();
  for(auto to: children)
  {
    e.push_back(d);
    dfs(to, d);
  }
  e.push_back(d);
}
```

さて、これで最初に示した木は、以下のように展開されます。

| index |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10 |  11 |  12 |  13 |
| ----- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| depth |  0  |  1  |  0  |  1  |  2  |  1  |  2  |  1  |  0  |   1 |   2 |   1 |   0 |

この配列をe、最初に登場するindexを記録した配列をe1とおくとき、
2つのノードa, b(a <= b)のLCAについて、

LCA(a, b) = min(e[f(a)], e[f(a) + 1], ..., e[f(b)])

であることがわかります。
つまり、EulerTourを使うとLCAはRMQに帰着することができます。

RMQは幾つかの方法でクエリをO(log N)で処理できるため、LCAもO(log N)で求めることができます。

例題

[ABC014 D](http://abc014.contest.atcoder.jp/tasks/abc014_4) |
[解答例](http://abc014.contest.atcoder.jp/submissions/387192)
