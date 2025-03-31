def max_words_in_lines(words, n, m):
    k = len(words)

    # Memoization table to store results for subproblems
    dp = [[-1 for _ in range(n + 1)] for _ in range(k + 1)]

    def can_fit(current_word, lines_left):
        # Base cases
        if current_word == k:
            return 0  # All words processed
        if lines_left == 0:
            return -float('inf')  # No lines left

        if dp[current_word][lines_left] != -1:
            return dp[current_word][lines_left]

        max_words = 0
        current_line_length = 0

        # Try placing words on the current line
        for i in range(current_word, k):
            word_length = len(words[i])

            if current_line_length == 0:
                current_line_length = word_length
            elif current_line_length + 1 + word_length <= m:
                current_line_length += 1 + word_length
            else:
                break

            # Recursive call: Process remaining words with one less line
            max_words = max(max_words, (i - current_word + 1) + can_fit(i + 1, lines_left - 1))

        # Also consider skipping the current word completely (not placing it on any line)
        max_words = max(max_words, can_fit(current_word + 1, lines_left))

        dp[current_word][lines_left] = max_words
        return max_words

    # Start the recursive process
    result = can_fit(0, n)
    return max(0, result)

# Input reading
if __name__ == "__main__":
    k = int(input().strip())
    words = [input().strip() for _ in range(k)]
    n, m = map(int, input().strip().split())

    # Output the result
    print(max_words_in_lines(words, n, m))
