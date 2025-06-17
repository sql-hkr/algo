# アルゴリズム

本レポジトリのアルゴリズム実装例は下記の通りである．

## 数学

### ユークリッドの互除法(Euclidean algorithm)

[[code]](math/gcd.cpp),
[[wiki]](https://en.wikipedia.org/wiki/Euclidean_algorithm)

## 探索

### 線形探索(Linear search)

n 個のデータから 1 個のデータを探索する場合，比較回数は高々 n 回である．最悪計算時間は，O(n)．

[[code]](search/linear_search.cpp),
[[wiki]](https://en.wikipedia.org/wiki/Linear_search)

### 二分探索(Binary search)

n 個のデータから 1 個のデータを探索する場合，比較回数は高々 log2(n)+1 回である．最悪計算時間は，O(log n)．

[[code]](search/binary_search.cpp),
[[wiki]](https://en.wikipedia.org/wiki/Binary_search)

## ソート

### バブルソート(Bubble sort)

比較回数は，高々 n(n-1)/2 回である．最悪計算時間は，O(n^2)．

[[code]](sorting/bubble_sort.cpp),
[[wiki]](https://en.wikipedia.org/wiki/Bubble_sort)

### 選択ソート(Selection sort)

比較回数は，高々 n(n-1)/2 回である．最悪計算時間は，O(n^2)．

[[code]](sorting/selection_sort.cpp),
[[wiki]](https://en.wikipedia.org/wiki/Selection_sort)

### 挿入ソート(Insertion sort)

比較回数は，高々 n(n-1)/2 回である．最悪計算時間は，O(n^2)．

[[code]](sorting/insertion_sort.cpp),
[[wiki]](https://en.wikipedia.org/wiki/Insertion_sort)
