## Mayank Pathela ##
## 201651029 ##

import sys


def shift_reducer(input_buffer, grammar, startSymbol, stack):
    if input_buffer == "":
        return
    stack = stack + input_buffer[slice(0, 1)]
    input_buffer = input_buffer[slice(1, len(input_buffer))]
    print("Shift")
    print(stack, "----------", input_buffer)
    # print(startSymbol)
    for i in range(len(stack)+1):
        for j in range(len(grammar)):
            for k in range(len(grammar[j])-1):
                if stack[-i:] == grammar[j][k+1]:
                    # print(stack[-i-1:])
                    stack = stack[:-i] + grammar[j][0]
                    print("Reduce")
                    print(stack, "----------", input_buffer)
                    shift_reducer(input_buffer, grammar, startSymbol, stack)
    if len(stack) > 1 or len(input_buffer) >= 1:
        shift_reducer(input_buffer, grammar, startSymbol, stack)
    elif stack[0] == startSymbol and len(stack) == 1:
        print("Accept")
        sys.exit()
        return
    elif stack[0] != startSymbol and len(stack) == 1:
        print("Reject")
        return


def main():
    n = int(input("How many Grammar do you want to give as input: "))
    grammar = []
    print("Enter Input in A:n|eL from: ")
    for i in range(n):
        grammar.append(input())
    print(grammar)
    eachgrammar = []
    for i in grammar:
        new = []
        x = i.split(":")
        new.append(x[0])
        x1 = x[1].split("|")
        new = new + x1
        eachgrammar.append(new)
    # print(eachgrammar)
    input_string = input("Enter the input string you want to parse: ")
    # For checking reverse of the input string can be parsed or not
    # reverse_string = "".join(reversed(input_string))
    # print(reverse_string)
    stack = ""
    print("Stack ------- Input Buffer")
    # shift_reducer(reverse_string, eachgrammar, eachgrammar[0][0], stack)
    shift_reducer(input_string, eachgrammar, eachgrammar[0][0], stack)


if __name__ == "__main__":
    main()
