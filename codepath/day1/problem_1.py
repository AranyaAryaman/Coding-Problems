
def transpose(matrix):
    m = len(matrix)
    n = len(matrix[0])
    new_matrix = [[0 for _ in range(m)] for _ in range(n)]
    for i in range(m):
        for j in range(n):
            # print(f"i:{i},j:{j}, matrix[i][j]: {matrix[i][j]}")
            new_matrix[j][i]=matrix[i][j]
            # print(f"i:{i},j:{j}, matrix[i][j]: {matrix[i][j]}, new_matrix{j}{i}:{new_matrix[j][i]}")


    return new_matrix

matrix = [[1,2,3],[4,5,6]]
print(transpose(matrix))

matrix = [[]]
print(transpose(matrix))