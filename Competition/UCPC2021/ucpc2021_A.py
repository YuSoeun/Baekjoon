s = input()

size  = len(s)
parser = s[0]
flag = 1
i = 0

# asscending 언제까지
for i in range (len(s)-1):
    if (s[i] >= s[i+1]):
        flag = 0
        break

# 맨 앞에 다 같은지



# 1의 자리 없애기
if (s[i] != 9):
    if (i == 0):
        parser = [s[0]]
        s_copy = s[0:].split(parser[-1])
    else:
        parser = [s[i]]
        s_copy = s[i:].split(parser[-1])
else:
    parser = [s[i+1]]
    s_copy = s[i+1:].split(parser[-1])
    
s_copy = [v for v in s_copy if v]
print(parser, s_copy, len(s_copy))

count = 0 # 두번이면 2자리
while (len(s_copy[-1]) >= 2 ):
    count += 1
    # 앞이 8이고 뒤가 9
    if (s_copy[-1][0] == '9' and s_copy[-2][-1] == '8'):
        parser.append(s_copy[-1][1])
    else:
        parser.append(s_copy[-1][0])
    s_copy = s_copy[-1].split(parser[-1])
    s_copy = [v for v in s_copy if v]
    print(parser, s_copy, len([-1]))

# 100의 자리인지

# else:
# 증가하면 1, 2

# 감소하면 12, 12