import re

path = '/Users/Mayank/Desktop/test1.c'
# open C file
code = open(path, 'r')
# setting poniter
cstr = code.readlines()

key = ['auto', 'double',      'int',        'struct',
       'break',        'else',        'long',       'switch',
       'case',         'enum',        'register',   'typedef',
       'char',         'extern',      'return',     'union',
       'const',        'float',       'short',      'unsigned',
       'continue',     'for',         'signed',     'void',
       'default', 'goto', 'sizeof'     'volatile',
       'do',           'if',          'static',      'while'
       ]

spc = [',', '=', '+', '-', '%', '$', '&', '*',
       '(', ')', '{', '}', '[', ']', '<', '>', '?', '/', '.', ';', ':', '#']

identifier = re.compile(r"^[_a-zA-Z]\w*$", re.UNICODE)


acc = ''
print(cstr)
keyword = 0
spchar = 0
iden = 0
comment = False

# Get special chars
for line in cstr:
    for char in line:
        if char in spc:
            spchar += 1


for line in cstr:
    fString = re.split(';|,| |\n|\t|\(|\)', line)
    print(fString)
    if '//' in fString:
        spchar -= 2
        continue
    for word in fString:
        if word is None:
            continue
        if word == '*/':
            spchar -= 2
            comment = False
        elif comment == True:
            continue
        elif word in key:
            keyword += 1
            # print(word)
            continue
        elif re.match(identifier, word):
            # print(word)
            iden += 1
            continue
        elif word == '/*':
            spchar -= 2
            comment = True

print(keyword, 'keyword')
print(spchar, 'spchar')
print(iden, 'iden')

code.close()
