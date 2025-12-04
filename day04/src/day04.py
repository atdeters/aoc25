import sys

if len(sys.argv) != 3:
    print("Usage: python3 day04.py <input-file> <-pt1 or -pt2>", file=sys.stderr)
    sys.exit(1)

if sys.argv[2] != "-pt1" and sys.argv[2] != "-pt2":
    print(f"Invalid flag in command line arguments: {sys.argv[2]}")
    sys.exit(1)

try:
    file = open(sys.argv[1])
    input = file.read()
    file.close()
except:
    print(f"Could not open file: {sys.argv[1]}", file=sys.stderr)
    sys.exit(1)

array = input.split('\n');
if array[-1] == "":
    array.pop()

width = len(array[0])
hight = len(array)

for line in array:
    if len(line) != width:
        print(f"Invalid map [Map is not rectangular]: {sys.argv[1]}", file=sys.stderr)
        sys.exit(1)

rolls = 0
while True:
    arr_new = [[0]*width for _ in range(hight)]
    flag = False
    for line in range(hight):
        for idx, spot in enumerate(array[line]):
            tmp = 0
            if idx != 0 and array[line][idx-1] == '@':
                tmp += 1
            if idx != width - 1 and array[line][idx+1] == '@':
                tmp += 1
            if line != 0 and idx != 0 and array[line-1][idx-1] == '@':
                tmp += 1
            if line != 0 and array[line-1][idx] == '@':
                tmp += 1
            if line != 0 and idx != width - 1 and array[line-1][idx+1] == '@':
                tmp += 1
            if line != hight - 1 and idx != 0 and array[line+1][idx-1] == '@':
                tmp += 1
            if line != hight - 1 and array[line+1][idx] == '@':
                tmp += 1
            if line != hight - 1 and idx != width - 1 and array[line+1][idx+1] == '@':
                tmp += 1
            if array[line][idx] == '@' and tmp < 4:
                rolls += 1
                arr_new[line][idx] = '.'
                if sys.argv[2] == "-pt2":
                    flag = True
            elif array[line][idx] == '@':
                arr_new[line][idx] = '@'
    if flag:
        array = arr_new
    else:
        print(f"\033[1m{rolls}\033[0m rolls of paper can be accessed by a forklift")
        sys.exit(0)

