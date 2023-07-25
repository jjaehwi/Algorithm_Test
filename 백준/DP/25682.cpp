// 체스판 다시 칠하기 2 G5
// 누적 합
#include <iostream>
#include <algorithm>

using namespace std;
int N, M, K;
char board[2000][2000];

int chess(char color)
{
	int value, pSum[N + 1][M + 1] = {};

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!((i + j) % 2))
				value = board[i][j] != color; // (i + j) % 2 = 0인 경우, 인자로 불러온 color 그대로
			else
				value = board[i][j] == color; // (i + j) % 2 = 1인 경우, 인자로 불러온 color 반대로

			pSum[i + 1][j + 1] = pSum[i][j + 1] + pSum[i + 1][j] - pSum[i][j] + value;
		}
	}
	int tmp, result = 100000000;

	for (int i = 0; i <= N - K; i++)
	{
		for (int j = 0; j <= M - K; j++)
		{
			tmp = pSum[i + K][j + K] - pSum[i][j + K] - pSum[i + K][j] + pSum[i][j];
			result = (tmp < result) ? tmp : result;
		}
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	cout << min(chess('B'), chess('W')) << '\n';
}