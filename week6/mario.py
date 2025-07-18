def get_height():
    while 1:
        try:
            lines = int(input("Height: "))
            if (lines < 9 and lines > 0):
                return lines
        except:
            pass


def output(lines):
    num = 1
    while num <= lines:
        print(" "*(lines - num) + "#"*num, end="  ")
        print("#"*num)
        num += 1


lines = get_height()
output(lines)
