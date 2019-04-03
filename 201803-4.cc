#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void pb(vector<int> b) {
  for (auto c : b) {
    cout << c << " ";
  }
  cout << endl;
}

int value_board(vector<int>& board) {
  int empty = 0;
  for (int i = 0; i < 9; ++i) {
    if (board[i] == 0) empty++;
  }
  for (int i = 0; i < 3; ++i) {
    //row
    int base = 3 * i;
    if (board[base] == board[base+1] && board[base] == board[base+2]) {
      if (board[base] == 1)
        return empty + 1;
      if (board[base] == 2)
        return -empty - 1;
    }
    // col
    if (board[i] == board[i+3] && board[i] == board[i+6]) {
      if (board[i] == 1)
        return empty + 1;
      if (board[i] == 2)
        return -empty - 1;
    }
  }
  // diagnose
  if (board[0] == board[4] && board[0] == board[8]) {
    if (board[0] == 1)
      return empty + 1;
    if (board[0] == 2)
      return -empty - 1;
  }
  if (board[2] == board[4] && board[2] == board[6]) {
    if (board[2] == 1)
      return empty + 1;
    if (board[2] == 2)
      return -empty - 1; 
  }
  if (empty == 0) {
    return 0;
  }
  return -1;
}
// 1 alex, 2 alice.
int dfs(int turn, vector<int> board) {
  int ret;
  if (turn == 1) {
    ret = -100000;
  } else {
    ret = 100000;
  }
  int val = value_board(board);
  if (val != -1) {
    return val; 
  }
  for (int i = 0; i < 9; ++i) {
    if (board[i] != 0) continue;
    if (turn == 1) {
      board[i] = 1;
      ret = max(ret, dfs(2, board));
    } 
    if (turn==2) {
      board[i] = 2;
      ret = min(ret, dfs(1, board));
    }
    board[i] = 0;
  } 
  return ret;
}
int main() {
  int n = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    vector<int> b;
    int value = 0;
    for (int j = 0; j < 9; ++j) {
      b.push_back(0);
    }
    for (int j = 0; j < 3; ++j) {
      int p1, p2, p3;
      scanf("%d%d%d", &p1, &p2, &p3);
      b[j*3] = p1;
      b[j*3 + 1] = p2;
      b[j*3 + 2] = p3;
    }
    // value = dfs(1, b);
    value = dfs(1 ,b);
    cout << value << endl;
  }
  return 0;
}