import re

# Input file path for my PC
path = '/Users/Mayank/Desktop/CD/test.c'

# Open the file
code_file = open(path, 'r')

# Keywords dict
key = ['auto', 'double',      'int',        'struct',
       'break',        'else',        'long',       'switch',
       'case',         'enum',        'register',   'typedef',
       'char',         'extern',      'return',     'union',
       'const',        'float',       'short',      'unsigned',
       'continue',     'for',         'signed',     'void',
       'default', 'goto', 'sizeof'     'volatile',
       'do',           'if',          'static',      'while'
       ]

stuff = ['int', 'char', 'float', 'double']

table = []

# Special chars
spc = [',', '=', '+', '-', '%', '$', '&', '*',
       '(', ')', '{', '}', '[', ']', '<', '>', '?', '/', '.', ';', ':', '#']

# Regex for evaluating identifiers
identifier = re.compile(r"^[_a-zA-Z]\w*$", re.UNICODE)

# Array of LOC
cstring = code_file.readlines()

# print(cstring)

# Some storagfe variables
keycount = 0
spcount = 0
identifierCount = 0
comment = False
inFunction = False

# Get special chars
for line in cstring:
    for char in line:
        if char in spc:
            spcount += 1

# Get keywords and identifiers while handling comments
for line in cstring:
    # A conveninet regex to split the code
    fString = re.split(';|,| |\n|\t|\(|\)', line)
    # print(fString)
    # Commented line case
    if '//' in fString:
        spcount -= 2
        continue
    # Evaluate each word
    # print(fString)
    for index, word in enumerate(fString):
        if word is None:
            continue
        if word == '*/':
            spcount -= 2
            comment = False
        elif comment == True:
            continue
        elif word == '{':
            inFunction = True
        elif word in key:
            keycount += 1
            if word in stuff:
                name = fString[index+1]
                scope = 'local'
                if not inFunction:
                    scope = 'global'
                for item in table:
                    if item.get('name') == name:
                        table.remove(item)
                table.append({'name': name, 'type': word, 'scope': scope})
                continue
            # print(word)
            continue
        elif re.match(identifier, word):
            # print(word)
            identifierCount += 1
            continue
        elif word == '/*':
            spcount -= 2
            comment = True

# Output
print('Keywords - ', keycount)
print('Special Characters - ', spcount)
print('Identifiers - ', identifierCount)

print('\nSYMBOL NAME | TYPE | SCOPE \n---------------------')
for a in table:
    print(a['name'], '|', a['type'], '|', a['scope'])

code_file.close()
