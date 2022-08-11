X, Z, xLen, zLen, xRange, zRange = '', '', 0, 0, 10010, 105

def f(i, j):
    global dp, X, Z, xLen, zLen, xRange, zRange
    if (dp[i][j] != -1):
        return dp[i][j]
    if (j >= zLen):
        return 1

    endPosition, subsetFound = (xLen - (zLen - j) + 1), 0
    for loopIterator in range (i, endPosition):
        if (X[loopIterator] == Z[j]):
            subsetFound += f(loopIterator+1, j+1)

    dp[i][j] = subsetFound
    return dp[i][j]

tCase = int(input())
while (tCase > 0):
    tCase = tCase - 1
    
    dp = [ [-1 for j in range(zRange)] for i in range(xRange)]
    X, Z = input(), input()
    xLen, zLen = len(X), len(Z)
    
    if (zLen == xLen):
        if (X == Z):
            print ("1")
        else:
            print ("0")
    elif (zLen > xLen):
        print ("0")
    else:
        print (f(0, 0))