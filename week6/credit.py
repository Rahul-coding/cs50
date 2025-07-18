def get_number():
    while 1:
        try:
            card = int(input("Number: "))
            return card
        except:
            continue


def check_valid(number):
    i = len(str(number))-1
    lnum = list(str(number))
    times = False
    total = 0
    while i >= 0:
        if times:
            product = int(lnum[i]) * 2
            if (len(str(product)) == 2):
                product = list(str(product))
                total += int(product[0]) + int(product[1])
            else:
                total += int(product)
        else:
            total += int(lnum[i])
        i -= 1
        times = not times
    return total % 10 == 0


def check_card(number):
    length = len(str(number))
    first_two = list(str(number))[0:2]
    first_two = int(''.join(first_two))
    first = int(list(str(number))[0])
    if ((first_two == 34 or first_two == 37) and length == 15):
        print("AMEX\n")

    elif ((first_two >= 51 and first_two <= 55) and length == 16):
        print("MASTERCARD\n")

    elif (first == 4 and (length == 13 or length == 16)):
        print("VISA\n")

    else:
        print("INVALID\n")


number = get_number()
if (check_valid(number)):
    check_card(number)
else:
    print('INVALID\n')
