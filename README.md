# アルゴリズム

本レポジトリのアルゴリズム実装例は下記の通りである．

## 数学

### ユークリッドの互除法(Euclidean algorithm)

[[code]](math/gcd.cpp),
[[wiki]](https://en.wikipedia.org/wiki/Euclidean_algorithm)

### ニュートン法(Newton's method)

[[code]](math/newton.cpp),
[[wiki]](https://en.wikipedia.org/wiki/Newton%27s_method)

### ガウスの消去法(Gaussian elimination)

[[code]](math/gauss.cpp),
[[wiki]](https://en.wikipedia.org/wiki/Gaussian_elimination)

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

### 分布数え上げソート(Counting Sort)

最悪計算時間は，O(n+k)．なお，各要素が[min, max]内である場合 k=max-min である．

[[code]](sorting/counting_sort.cpp),
[[wiki]](https://en.wikipedia.org/wiki/Counting_sort)

### クイックソート(Quicksort)

比較回数は，高々 n(n-1)/2 回である．最悪計算時間は，O(n^2)．

[[code]](sorting/quick_sort.cpp),
[[wiki]](https://en.wikipedia.org/wiki/Quicksort)

### マージソート(Merge sort)

[[code]](sorting/merge_sort.cpp),
[[wiki]](https://en.wikipedia.org/wiki/Merge_sort)
