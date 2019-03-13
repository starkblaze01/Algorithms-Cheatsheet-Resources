# import re


def main():
    num = int(input("How many grammar you want to give: "))
    for i in range(num):
        y = input(
            "Enter input in the form (A:A(alpha1)|A(alpha2)|A(alpha3)|beta1|beta2|beta3) :- ")
        # print(y)
        x = y.split(":")
        x1 = x[0]
        x2 = x[1].split("|")
        # print(x1, x2)
        x1_new = x1 + '`'
        new = []
        new1 = []
        for i in range(len(x2)):
            if x2[i][0] == x1:
                hello = x2[i].replace(x1, "")
                new.append(hello+x1_new)
            else:
                new1.append(x2[i]+x1_new)
        # print(x1_new, new, new1)
        # S:Aa|b
        ## A: Ac|Sd|epsilon
        ##
        get_new = x1_new+":"
        get_new1 = x1+":"
        for i in range(len(new)):
            get_new = get_new + new[i] + "|"
        for i in range(len(new1)):
            get_new1 = get_new1 + new1[i] + "|"
        get_new = get_new + "epsilon"
        get_new1 = get_new1[:-1]
        if len(new) < 1:
            print(y)
        else:
            print(get_new1)
            print(get_new)


if __name__ == "__main__":
    main()
