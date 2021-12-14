def solution(step, size):
    if step == (size - 1):
        return 1
    return 0

def back(step, sol, size):
    for i in range(1, size+1):
        sol[step] = i
        if solution(step, size):
            print(sol)
        else:
            back(step + 1, sol, size)


size = int(input("Select size: "))
sol = [0] * size
back(0, sol, size)
