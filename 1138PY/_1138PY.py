import timeit

setup_code = """
lastSalary = 10; firstSalary = 2
"""

code_to_measure = """
if lastSalary == firstSalary:
    print(1)
else:
    maxCnt = 0
    cnts = [0 for _ in range(lastSalary + 1)]
    cnts[firstSalary] = 1

    for i in range(firstSalary, lastSalary + 1):
        if cnts[i] > 0:
            if lastSalary > 2 * i:
                k = 2 * i
            else:
                k = lastSalary
                
            for j in range(i + 1, k + 1):
                if cnts[j] < cnts[i] + 1 and j * 100 % i == 0:
                    cnts[j] = cnts[i] + 1
                    
        if cnts[i] > maxCnt:
            maxCnt = cnts[i]
            
print(maxCnt)
"""
    
execution_time = timeit.timeit(stmt=code_to_measure, setup=setup_code, number=1)
print(f"Execution time: {execution_time} seconds")