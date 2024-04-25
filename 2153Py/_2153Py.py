
def cnt(s):
    # Popcount of s
    res = 0
    for i in range(4):
        res += bool(s & (1 << i))
    return res

def dfs(i, s):
    A[s] = s
    if B[i][s] or i >= n:
        return
    for j in range(4):
        dfs(i + 1, s | ((1 << j) & S[i]))
    B[i][s] = 1

m = {'W': 1, 'M': 2, 'C': 4, 'R': 8}
n = int(input())
A = [0] * 16
S = [0] * 16
B = [[0] * 16 for _ in range(16)]
out = 0
maxTeam = 0

for i in range(n):
    l = 0
    classes = input()
    for char in classes:
        l |= m[char]
    S[i] = l

dfs(0, 0)
for i in range(16):
    maxTeam = max(cnt(A[i]), maxTeam)

print(maxTeam)
if maxTeam < 4:
    for i in range(15):
        if cnt(A[i]) == maxTeam:
            out |= ~A[i]

    classes = ["warrior", "mage", "cleric", "rogue"]
    print("Looking for", end="")
    for i in range(4):
        if out & (1 << i):
            print(" " + classes[i], end="")