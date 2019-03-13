import re


def leftrecursion(y, grammar1):
    # print(y)
    x = y.split(":")
    x1 = x[0]
    x2 = x[1].split("|")
    x1_new = x1 + '`'
    new = []
    new1 = []
    for i in range(len(x2)):
        if x2[i][0] == x1:
            hello = x2[i].replace(x1, "")
            new.append(hello+x1_new)
        else:
            new1.append(x2[i]+x1_new)
    get_new = x1_new+":"
    get_new1 = x1+":"
    for i in range(len(new)):
        get_new = get_new + new[i] + "|"
    for i in range(len(new1)):
        get_new1 = get_new1 + new1[i] + "|"
    get_new = get_new + "epsilon"
    get_new1 = get_new1[:-1]
    if len(new) < 1:
        grammar1.append(y)
    else:
        grammar1.append(get_new1)
        grammar1.append(get_new)


def main():
    x = int(input("How many grammars you want to give as input:- "))
    grammar = []
    finalfirst = []
    print("Write grammar in the form A:alpha|aplha1 (here 'e' refers to epsilon):")
    grammar1 = []
    grammar2 = []
    for i in range(x):
        grammar.append(input())
        leftrecursion(grammar[i], grammar1)
    print(grammar)
    for j in grammar1:
        x_ = j.split(":")
        x1 = x_[0]
        x2 = x_[1].split("|")
        # print(x1, x2)
        i_ = []
        for k in x2:
            first(i_, k)
        finalfirst.append(i_)
        print("First of", x1, "is :", i_)
        grammar2.append([x1, i_])
    print(grammar2)
    # print(finalfirst)
    # final first and follow after removing the recursion
    # final_first = []
    i__ = []
    follow(grammar2, grammar1, i__)


def first(i_, k):
    for i in range(len(k)):
        if re.match("[a-z0-9]", k[i]):
            i_.append(k[i])
            # print(k[i])
            return i_
        else:
            if k[i] == '`':
                i_[i-1] = i_[i-1]+'`'
            else:
                i_.append(k[i])
            # print(k[i])


def follow(grammar2, grammar1, i__):
    print(grammar2, grammar1)
    for j in grammar1:
        x_ = j.split(":")
        x1 = x_[0]
        x2 = x_[1].split("|")
        # print(x1, x2)
        for lm in range(len(grammar2)):
            i__.append([])
        i__[0].append("$")
        for l in x2:
            for n in range(len(grammar2)):
                if l[len(l)-1] == grammar2[n][1]:
                    i__[n].append(grammar2[n][2])
        # print("Final Follow of ",x1,"is",i__)
        # transfer each value of fist(n) to follow(n-1)
        # return the final follow value


if __name__ == "__main__":
    main()
