def encrypt(text,key):
    result=""
    ascno_e=0
    for i in text:
        if i.isupper():
            ascno_e=ord('A')+((ord(i)-ord('A')+key)%26)
            result=result+chr(ascno_e)
        elif i.islower():
            ascno_e= ord('a')+((ord(i)-ord('a')+key)%26)
            result=result+chr(ascno_e)
        elif i==" ":
            result=result+" "
        else:
            result="INVALID INPUT you can only encrypt alphabets with this algo"
            return result
    return result
def decrypt(text,key):
    result=""
    ascno_d=0
    for  i in text:
        if i.isupper():
            ascno_d=ord('A')+((ord(i)-ord('A')-key)%26)
            result=result+chr(ascno_d)
        elif i.islower():
            ascno_d= ord('a')+((ord(i)-ord('a')-key)%26)
            result=result+chr(ascno_d)
        elif i==" ":
            result=result+" "
        else:
            result="INVALID INPUT you can only encrypt alphabets with this algo"
    return result
if __name__ == "__main__":
    x=encrypt('Hey Fellas',4)
    print(x)
    print("##")
    print(decrypt(x,4))