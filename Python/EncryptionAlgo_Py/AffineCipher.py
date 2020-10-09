def encrypt(text="",a=7,b=3):
    result=""
    a_no=0
    for i in text:
        if i.isupper():
            a_no=ord(i)-ord('A')
            result=result+chr((((a_no*a)+b)%26)+ord('A'))
        elif i.islower():
            a_no=ord(i)-ord('a')
            result=result+chr((((a_no*a)+b)%26)+ord('a'))
        else:
            result="INVALID INPUT, only alphabets can be encrypted"
    #print(result)
    return result

def decrypt(text="",a=7,b=3):
    result=""
    a_inv=0
    a_no=0
    test_alpha_num=((a*5)+b)%26
    for i in range(1,26):
        x=((i*(test_alpha_num-b)))%26
        if(x==5):
            a_inv=i
    for i in text:
        if i.isupper():
            a_no=ord(i)-ord('A')
            result=result+chr(((a_inv*(a_no-b))%26)+ord('A'))
        elif i.islower():
            a_no=ord(i)-ord('a')
            result=result+chr(((a_inv*(a_no-b))%26)+ord('a'))
        else:
            result="INVALID CODE, can not be decrypted!!"
    #print(result)
    return result
if __name__ == "__main__":
    x=encrypt(text="hii",a=17,b=20)#choose and b as co prime
    print(x)
    x=decrypt(text=x,a=17,b=20)
    print(x)
