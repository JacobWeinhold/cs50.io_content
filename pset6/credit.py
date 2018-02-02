import cs50

def main():
    valid = False
    i, ung, gr ,tmp ,check,data = 0, 0, 0, 0, 0, 0
    while(data<=0):
        print("Card Number?")
        data = cs50.get_int()

    while(data>0):
        if(i%2==0):
            gr+=data%10
        else:
            tmp = (data%10)*2
            if(tmp>9):
                ung+=(tmp%10)+1
            else:
                ung+=tmp
        if(data<10):
            if(data==4):
                cmp = "VISA"
                valid = True
            data = 0

        else:
            data//=10
            if(data>=51 and data <= 55):
                camp = "MASTERCARD"
                valid = True
            if(data== 34 or data == 37):
                cmp = "AMEX"
                valid = True
        i+=1
    check = (ung+gr)%10

    if(check == 0 and valid == True):
        if(i==15):
            print("{}".format(cmp))

        elif(i==16):
            print("{}".format(cmp))

        elif(i==13):
            print("{}".format(cmp))

    else:
        print("INVALID")

if __name__ == "__main__":
    main()