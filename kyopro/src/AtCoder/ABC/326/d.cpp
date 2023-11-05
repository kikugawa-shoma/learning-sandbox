#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print_2vec(vector<vector<char>> V)
{
  for (int h = 0; h < V.size() - 1; h++)
  {
    for (int w = 0; w < V[h].size() - 1; w++)
    {
      cout << V[h][w] << ' ';
    }
    if (h != V.size() - 1)
      cout << endl;
  }
}

vector<vector<char>> write_map(vector<vector<char>> V)
{
  int N = (int)V.size();
  vector<set<char>> row_remainings(N, {'A', 'B', 'C'});
  vector<set<char>> column_remainings(N, {'A', 'B', 'C'});
  for (int h = 0; h < N; h++)
  {
    for (int w = 0; w < N; w++)
    {
      char C = V[h][w];
      if (C == 'A')
      {
        row_remainings[h].erase('A');
        column_remainings[w].erase('A');
      }
      if (C == 'B')
      {
        row_remainings[h].erase('B');
        column_remainings[w].erase('B');
      }
      if (C == 'C')
      {
        row_remainings[h].erase('C');
        column_remainings[w].erase('C');
      }
      if (C == '*')
      {
        // もしrow_remainingとcolumn_remainingの両方が少なくとも１つの要素を持っているならintersectionを取る
        if (row_remainings[h].size() != 0 && column_remainings[w].size() != 0)
        {
          set<char> remaining_intersection;
          set_intersection(
              row_remainings[h].begin(),
              row_remainings[h].end(),
              column_remainings[w].begin(),
              column_remainings[w].end(),
              inserter(remaining_intersection, remaining_intersection.end()));
          if (remaining_intersection.size() > 0)
          {
            V[h][w] = *remaining_intersection.begin();
            row_remainings[h].erase(V[h][w]);
            column_remainings[w].erase(V[h][w]);
          }
          else
          {
            V[h][w] = '.';
          }
        }
        // どちらかの要素数が0なら0ではないほうから取る
        else
        {
          if (row_remainings[h].size() != 0)
          {
            V[h][w] = *row_remainings[h].begin();
            row_remainings[h].erase(V[h][w]);
            column_remainings[w].erase(V[h][w]);
          }
          else if (column_remainings[w].size() != 0)
          {
            V[h][w] = *column_remainings[w].begin();
            row_remainings[h].erase(V[h][w]);
            column_remainings[w].erase(V[h][w]);
          }
          else
          {
            V[h][w] = '.';
          }
        }
      }
    }
  }
  return V;
}

void print_res(vector<vector<char>> V)
{
  bool ok = true;
  int N = V.size();
  for (int h = 0; h < N; h++)
  {
    for (int w = 0; w < N; w++)
    {
      if (V[h][w] == '.')
        ok = false;
    }
  }
  if (ok)
  {
    cout << "Yes" << endl;
    print_2vec(V);
  }
  else
  {
    cout << "No" << endl;
    print_2vec(V);
  }
}

struct dp_state
{
  bool column_resolved;
  bool row_resolved;
};

int main()
{
  int N;
  string R, C;
  cin >> N >> R >> C;
  vector<vector<dp_state>> dp(N + 1, vector<dp_state>(N + 1, {false, false}));
  vector<vector<char>> output_map(N + 1, vector<char>(N + 1));
  for (int h = 0; h < N; h++)
  {
    for (int w = 0; w < N; w++)
    {
      char R_char = R[h];
      char C_char = C[w];
      dp_state left_state = dp[h + 1][w];
      dp_state upper_state = dp[h][w + 1];
      if (left_state.row_resolved && upper_state.column_resolved)
      {
        output_map[h][w] = '*';
        dp[h + 1][w + 1].row_resolved = true;
        dp[h + 1][w + 1].column_resolved = true;
      }
      else if (!left_state.row_resolved && upper_state.column_resolved)
      {
        output_map[h][w] = R_char;
        dp[h + 1][w + 1].row_resolved = true;
        dp[h + 1][w + 1].column_resolved = true;
      }
      else if (left_state.row_resolved && !upper_state.column_resolved)
      {
        output_map[h][w] = C_char;
        dp[h + 1][w + 1].row_resolved = true;
        dp[h + 1][w + 1].column_resolved = true;
      }
      else if (!left_state.row_resolved && !upper_state.column_resolved)
      {
        if (R_char == C_char)
        {
          output_map[h][w] = R_char;
          dp[h + 1][w + 1].row_resolved = true;
          dp[h + 1][w + 1].column_resolved = true;
        }
        else
        {
          output_map[h][w] = '.';
          dp[h + 1][w + 1].row_resolved = false;
          dp[h + 1][w + 1].column_resolved = false;
        }
      }
    }
  }
  output_map = write_map(output_map);
  print_res(output_map);
}
