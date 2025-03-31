def justify_words(words, N, M):
    dp = [[0] * (M + 1) for _ in range(N + 1)]

    for i in range(1, N + 1):
        for j in range(1, M + 1):
            max_words = 0
            for k in range(j):
                if len(words[i - 1]) <= j - k:
                    max_words = max(max_words, dp[i - 1][k] + 1)
            dp[i][j] = max_words

    return dp[N][M]

if __name__ == "__main__":
    num_words = int(input())
    words = [input() for _ in range(num_words)]
    N, M = map(int, input().split())

    result = justify_words(words, N, M)
    print(result)