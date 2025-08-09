# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## リポジトリ概要
これは競技プログラミング（主にAtCoder）の練習用リポジトリです。C++17を使用しており、AtCoderの問題解答とアルゴリズムライブラリが含まれています。

## よく使うコマンド

### メインファイルの実行
```bash
./runmain
```
- `main.cpp`をコンパイル（`g++ -std=c++17 -O2 -Wall`）して実行します
- 出力ファイル: `main.out`

### AtCoder問題の実行
```bash
./atcoder/run abc <コンテスト番号> <問題>
# 例: ./atcoder/run abc 300 a
```
- 指定したコンテストの問題をコンパイルして実行します
- ファイル形式: `atcoder/abc_XXX/Y.cpp` (XXX=コンテスト番号, Y=問題番号)

## コード構造

### テンプレートファイル
- `template.cpp`: 新しい問題を解く際の基本テンプレート
- `lib.cpp`: アルゴリズムスニペット集（素数判定、順列生成など）

### 標準的なインクルードとマクロ
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

#define INF 1010000000
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
```

### ディレクトリ構造
- `/atcoder/`: AtCoderの問題解答
  - `/abc_XXX/`: ABC（AtCoder Beginner Contest）の各コンテスト
- `/kyopro-tessoku/`: 競技プログラミングの鉄則の練習問題
- `/paiza/`: Paizaの問題解答

## 開発時の注意点
- コンパイルオプション: `-std=c++17 -O2 -Wall`
- 実行ファイルは`.out`拡張子で生成されます
- VSCodeでC++の関連付けが設定されています（`.vscode/settings.json`）