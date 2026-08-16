class Solution {
    public:
      int minThrows(int n, vector<int>& lad, vector<int>& sn) {
          int N = n * n;

          // jump[x] = destination if x has a snake/ladder
          vector<int> jump(N + 1, -1);

          for (int i = 0; i + 1 < lad.size(); i += 2) {
              jump[lad[i]] = lad[i + 1];
          }

          for (int i = 0; i + 1 < sn.size(); i += 2) {
              jump[sn[i]] = sn[i + 1];
          }

          vector<int> dist(N + 1, -1);
          queue<int> q;

          dist[1] = 0;
          q.push(1);

          while (!q.empty()) {
              int cur = q.front();
              q.pop();

              if (cur == N)
                  return dist[cur];

              // Try all possible dice outcomes: 1 to 6
              for (int dice = 1; dice <= 6 && cur + dice <= N; dice++) {
                  int next = cur + dice;

                  // Immediately take snake/ladder if present
                  if (jump[next] != -1)
                      next = jump[next];

                  if (dist[next] == -1) {
                      dist[next] = dist[cur] + 1;
                      q.push(next);
                  }
              }
          }

          return -1;
      }
  };