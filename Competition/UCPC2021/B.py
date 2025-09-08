N, M = map(int,input().split())
jeon = list()
hu = list()
for _ in range(N): jeon.append(list(map(int,input().split())))
for _ in range(N): hu.append(list(map(int,input().split())))

def check(diffI):
    tmp = []
    if (lenDiffI := len(diffI)) == 1: return "YES"
    for i in range(lenDiffI):
        if i == 0: tmp.append((diffI[i][0],diffI[i][1]))
        elif (diffI[i][0]+1,diffI[i][1]) in tmp: tmp.append((diffI[i][0],diffI[i][1]))
        elif (diffI[i][0]-1,diffI[i][1]) in tmp: tmp.append((diffI[i][0],diffI[i][1]))
        elif (diffI[i][0],diffI[i][1]+1) in tmp: tmp.append((diffI[i][0],diffI[i][1]))
        elif (diffI[i][0],diffI[i][1]-1) in tmp: tmp.append((diffI[i][0],diffI[i][1]))
        else: return 'NO'
        # print(tmp)
    
    return "YES"

if jeon == hu: print('YES')
else:
    diff = list()
    tmp = list()
    diffI = list()
    
    for count in range(M*N):
        j,h = jeon[count//M][count%M], hu[count//M][count%M]
        if j!=h: diffI.append((count//M,count%M))
        
        if j==h: tmp.append(0)
        else: tmp.append(1)
        if((count+1)%M==0):
            diff.append(tmp)
            tmp = []
    # print(diffI)
    print(check(diffI))
