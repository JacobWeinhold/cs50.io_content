import cs50

def main():
    while(True):
        print("Height: ", end="")
        height = cs50.get_int()
        if height >= 0 and height <= 23:
            break
    for i in range(height):
        blanks = height-(i+1)
        for j in range(blanks):
            print(" ", end="")
        for k in range(i+1):
            print("#",end="")
        print("  ", end ="")
        for l in range (i+1):
            print("#",end="")
        print("")




def get_positive_int():
    while True:
        n = cs50.get_int()
        if n >= 0 and n <= 23:
            break
    return n


if __name__ == "__main__":
    main()