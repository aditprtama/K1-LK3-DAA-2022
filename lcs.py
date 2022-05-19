X = str("ABCBDAB")
Y = str("BDCABA")
p1 = len(X)
p2 = len(Y)
LCS = ""
matriks_C = [[0 for x in range(p2+1)] for x in range(p1+1)]
matriks_B = [[0 for x in range(p2+1)] for x in range(p1+1)]
matriks_LCS = [[0 for x in range(p2+1)] for x in range(p1+1)]

i1 = 0
while i1 < p1:
    j1 = 0
    while j1 < p2:
        if X[i1] == Y[j1]:
            matriks_C[i1+1][j1+1] = matriks_C[i1][j1] + 1
            matriks_B[i1+1][j1+1] = "↖"
        else:
            matriks_C[i1+1][j1+1] = max(matriks_C[i1][j1+1], matriks_C[i1+1][j1])
            if matriks_C[i1][j1+1] >= matriks_C[i1+1][j1]:
                matriks_B[i1+1][j1+1] = "↑"
            else:
                matriks_B[i1+1][j1+1] = "−"
        j1 += 1
    i1 += 1
    
while i1 > 0 and j1 > 0:
    if matriks_C[i1][j1] == max(matriks_C[i1-1][j1], matriks_C[i1][j1-1]):
        if matriks_C[i1-1][j1] >= matriks_C[i1][j1-1]:
            matriks_LCS[i1][j1] = "↑"
            i1 -= 1
        else:
            matriks_LCS[i1][j1] = "−"
            j1 -= 1
    else:
        matriks_LCS[i1][j1] = "↖"
        LCS = X[i1-1] + LCS
        i1 -= 1
        j1 -= 1
            
print("Matriks C : ")
for i in range(0, len(matriks_C)):
    print(matriks_C[i])
    
print("Matriks B : ")
for i in range(0, len(matriks_B)):
    print(matriks_B[i])
    
print("Matriks LCS : ")
for i in range(0, len(matriks_LCS)):
    print(matriks_LCS[i])
    