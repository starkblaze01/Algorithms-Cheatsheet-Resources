def generateKey(x):
    import string
    import numpy as np
    import sympy
    import random
    key=""
    if x>10:
        randomlist = random.sample(range(0, 100), 10)
    else:
        randomlist=random.sample(range(0,100),x-1)
    rand_prime=sympy.randprime(0,9999)
    key_array=np.identity(x)
    key_array=key_array*rand_prime
    key_array=key_array.astype(int)
    for i in range(1,len(randomlist)+1):
        key_array[0][i]= randomlist[i-1]
    key_array= key_array%26
    for i in key_array:
        for j in i:
            key= key+chr(j+ord('A'))
    return key


def encrypt(text="",key=""):
    import numpy as np
    from sympy import Matrix
    result_text=""
    result=dict()
    if key=="":
        key=generateKey(len(text))
    
    elif len(key)!=len(text)*len(text):
        result['encrypted_text']="INVALID KEY if u don't know how to make the key leave it blank we will generate it for you"
        result['key']=key
        return result
    
    t_mat=list()
    key_mat=list()
    
    for i in text:
        t_mat.append(ord(i.upper())-ord('A'))
    
    z=len(text)
    key_mat_l=list()
    
    for i in key:
        if z==0:
            z=len(text)
            key_mat.append(key_mat_l)
            key_mat_l= list()
        key_mat_l.append(ord(i)-ord('A'))
        z=z-1
    key_mat.append(key_mat_l)

    try:
        Matrix(key_mat).inv_mod(26)
    except :
        result['encrypted_text']="INVALID KEY if u don't know how to make the key leave it blank we will generate it for you"
        result['key']=key
        return result
    for i in np.dot(key_mat,t_mat):
        result_text=result_text+chr(i%26+ord('A'))
        
    
    result['encrypted_text']=result_text
    result['key']=key
    return result


def decrypt(text="",key=""):
    import numpy as np
    from sympy import Matrix
    spacelist_index=list()
    for i in range(len(text)):
        if text[i]==" ":
            spacelist_index.append(i)
    text=text.replace(' ','')
    t_array=list()
    key_array= list()
    result=""
    if key=="":
        return "NO KEY PROVIDED"
    for i in text:
        t_array.append(ord(i.upper())-ord('A'))
    for i in key:
        key_array.append(ord(i.upper())-ord('A'))
    key_array=np.array(key_array)
    key_array=key_array.reshape(len(text),len(text))
    key_inv=Matrix(key_array).inv_mod(26)
    key_inv=np.array(key_inv)
    result_array=np.dot(key_inv,t_array)
    result_array=result_array%26
    z=0
    for i in result_array:
        result=result+chr(i+ord('A'))
        
    return result

if __name__ == "__main__":
    stri='Hey Fellas'
    li=stri.split(" ")
    e_list=list()
    for i in li:
        x=encrypt(text=i,key='')
        print(x['encrypted_text'],end=" ")
        e_list.append(x)
    z=""
    print("")
    for i in e_list:
        z=z+decrypt(text=i['encrypted_text'],key=i['key'])
        z=z+" "
    print(z)
