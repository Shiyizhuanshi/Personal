u = [0, 1, 2, 3, 0, 1, 2, 3, 2, 1]
v = [1, 3, 0, 1, 2, 1, 2, 2, 1, 2]

correct_solution = [
    [1, 2],
    [3, 1, 2],
    [0, 2, 1],
    [1, 2]
]

def find_element(u, x):
    index = []
    for i in range(len(u)):
        if u[i] == x:
            index.append(i)
    return index



def sparse_matrix_to_CSR(u, v):
    index = []
    for i in range(4):
        index.append(find_element(u, i))
    row = []
    row_ele = []
    for a in range(4):
        for b in range(len(index[a])):
            row_ele.append(v[index[a][b]])
        row.append(row_ele)
        row_ele = []
    return row

row = sparse_matrix_to_CSR(u, v)

# row = []
# for i in range(4):
#     row.append(v[u[i]]). // easy solution


def solution_is_correct(row):
    if len(row)!=4:
        return False
    for i in range(4):
        if len(row[i])!=len(correct_solution[i]):
            return False
        x = sorted(row[i])
        y = sorted(correct_solution[i])
        if any(x[j]!=y[j] for j in range(len(x))):
            return False
    return True

print(solution_is_correct(correct_solution))
