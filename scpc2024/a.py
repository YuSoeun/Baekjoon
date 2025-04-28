n = 6
m = 50000

with open('output.txt', 'w') as f:
    f.write(str(n) + '\n')
    f.write(str(m) + '\n')
    f.write('1 ' * m + '\n')
    f.write(str(m) + '\n')
    for i in range(1, m+1):
        f.write('1 ' + str(i) + '\n')
