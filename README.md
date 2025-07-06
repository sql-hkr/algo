# アルゴリズム

本レポジトリのアルゴリズム実装例は下記の通りである．

- 数学
    - [階乗(Factorial)](https://en.wikipedia.org/wiki/Factorial), [[code]](math/factorial.cpp)
    - [フィボナッチ数列(Fibonacci sequence)](https://en.wikipedia.org/wiki/Fibonacci_sequence), [[code]](math/fibonacci.cpp)
    - [ユークリッドの互除法(Euclidean algorithm)](https://en.wikipedia.org/wiki/Euclidean_algorithm), [[code]](math/gcd.cpp)
    - [最小公倍数(Least common multiple)](https://en.wikipedia.org/wiki/Least_common_multiple), [[code]](math/lcm.cpp)
    - [ニュートン法(Newton's method)](https://en.wikipedia.org/wiki/Newton%27s_method), [[code]](math/newton.cpp)
    - [ガウスの消去法(Gaussian elimination)](https://en.wikipedia.org/wiki/Gaussian_elimination), [[code]](math/gauss.cpp)
    - [素数判定法(Primality test)](https://en.wikipedia.org/wiki/Primality_test), [[code]](math/check_prime.cpp)
    - [オイラー法(Euler method)](https://en.wikipedia.org/wiki/Euler_method), [[code]](math/euler.cpp)
    - [ルンゲ＝クッタ法(Runge–Kutta methods)](https://en.wikipedia.org/wiki/Runge–Kutta_methods), [[code]](math/rungekutta.cpp)
- 探索
    - [線形探索(Linear search)](https://en.wikipedia.org/wiki/Linear_search), [[code]](search/linear_search.cpp)
    - [二分探索(Binary search)](https://en.wikipedia.org/wiki/Binary_search), [[code]](search/binary_search.cpp)
    - [深さ優先探索(DFS; Depth-first search)](https://en.wikipedia.org/wiki/Depth-first_search), [[code]](search/dfs.cpp)
    - [幅優先探索(BFS; Breadth-first search)](https://en.wikipedia.org/wiki/Breadth-first_search), [[code]](search/bfs.cpp)
- 動的計画法
    - [0-1 ナップサック問題(0-1 knapsack problem)](https://en.wikipedia.org/wiki/Knapsack_problem), [[code]](dp/knapsack.cpp)
    - [部分和問題(Subset sum problem)](https://en.wikipedia.org/wiki/Subset_sum_problem), [[code]](dp/subset_sum.cpp)
    - [最長共通部分列問題(LCS; Longest common subsequence)](https://en.wikipedia.org/wiki/Longest_common_subsequence), [[code]](dp/lcs.cpp)
- ソート
    - [バブルソート(Bubble sort)](https://en.wikipedia.org/wiki/Bubble_sort), [[code]](sorting/bubble_sort.cpp)
    - [選択ソート(Selection sort)](https://en.wikipedia.org/wiki/Selection_sort), [[code]](sorting/selection_sort.cpp)
    - [挿入ソート(Insertion sort)](https://en.wikipedia.org/wiki/Insertion_sort), [[code]](sorting/insertion_sort.cpp)
    - [分布数え上げソート(Counting Sort)](https://en.wikipedia.org/wiki/Counting_sort), [[code]](sorting/counting_sort.cpp)
    - [クイックソート(Quicksort)](https://en.wikipedia.org/wiki/Quicksort), [[code]](sorting/quick_sort.cpp)
    - [マージソート(Merge sort)](https://en.wikipedia.org/wiki/Merge_sort), [[code]](sorting/merge_sort.cpp)
- グラフ理論における最短経路問題
    - [ダイクストラ法(Dijkstra's algorithm)](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm), [[code]](graph/dijstra.cpp)
    - [A*](https://en.wikipedia.org/wiki/A*_search_algorithm), [[code]](graph/a-star.cpp)
- 暗号
    - [RSA暗号(RSA cryptosystem)](https://en.wikipedia.org/wiki/RSA_cryptosystem), [[code]](crypto/rsa.cpp)

## 環境構築
[Docker](https://www.docker.com/)を用いて環境構築する場合：
```bash
docker compose build
docker compose run dev bash
``` 
