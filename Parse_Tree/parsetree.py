input_string = input(
    "Please Enter the String which belongs to the grammar (a)^n(b)^n: ")

count_a = 0
count_b = 0
count_non = 0
i = 0

while input_string[i] == "a" and i < len(input_string):
    count_a += 1
    i += 1
while input_string[i] == "b" and i < len(input_string)-1:
    count_b += 1
    i += 1
if input_string[i] == "b":
    count_b += 1
print(count_a, count_b)
if (input_string[i-1] != "a" and input_string[i-1] != "b") or count_a != count_b:
    print("Input String doesn't belong to the grammar (a)^n(b)^n")
    exit()
else:
    print("Input string belongs to the grammar")
    print("Language is S -> aSb | epsilon")
s = "aSb"
print("Depth 0 : S")
print("Depth 1 : aSb")
i = 2
while len(s) < len(input_string):
    #   print(s)
    s = s.replace("S", "aSb")
    print("Depth", i, ":", s)
    i += 1
#s = s.replace("S", "aSb")
s = s.replace("S", "")
print("Depth", i, ":", s)
