n = int(input())

for _ in range(n):
    ox_quiz = input()
    score = 0
    current_streak = 0

    for char in ox_quiz:
        if char == 'O':
            current_streak += 1
            score += current_streak
        else:
            current_streak = 0
    
    print(score)
