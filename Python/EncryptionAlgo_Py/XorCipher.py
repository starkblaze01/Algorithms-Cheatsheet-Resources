def encrypt(text,key):
    from itertools import cycle
    import base64
    encrypted_text=''
    for i,j in zip(text,cycle(key)):
            encrypted_text= encrypted_text+chr(ord(i)^ord(j))
    encrypted_text_bytes= encrypted_text.encode("ascii")
    encrypted_text_bytes= base64.b64encode(encrypted_text_bytes)
    encrypted_text=encrypted_text_bytes.decode("ascii")
    return encrypted_text
def decrypt(text,key):
    from itertools import cycle
    import base64
    decrypted_text=''
    text_bytes= text.encode("ascii")
    text_bytes=base64.b64decode(text_bytes)
    text=text_bytes.decode("ascii")
    for i,j in zip(text,cycle(key)):
        decrypted_text=decrypted_text+chr(ord(i)^ord(j))
    return decrypted_text
if __name__ == "__main__":
    x=encrypt('Hey fellas!','Iamgroot')
    print(x)
    x=decrypt(x,'Iamgroot')
    print(x)