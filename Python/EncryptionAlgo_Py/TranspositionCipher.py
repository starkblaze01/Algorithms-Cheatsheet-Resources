def encrypt(text,key):
    result_list=list()
    result=""
    word=list()
    z=key
    for i in text:
        z=z-1
        word.append(i)
        if z==0:
            result_list.append(word)
            word= list()
            z=key
    result_list.append(word)
    for i in range(key):
        for j in range(len(text)//key+1):
            if i<len(result_list[j]):
                result=result+result_list[j][i]
    return result
def decrypt(text,key):
    key_l=(len(text)//key)+1
    z=key_l
    word=list()
    result=""
    result_list=list()
    for  i in text:
        z=z-1
        word.append(i)
        if z==0:
            result_list.append(word)
            word=list()
            z=key_l
    if z!=key_l:
        result_list.append(word)
    for i in range(key_l):
        for j in range(key):
            if i<len(result_list[j]):
                result=result+result_list[j][i]
    return result
    
if __name__ == "__main__":
    px=encrypt('hello world',4)
    print(px)
    px= decrypt(px,4)
    print(px)