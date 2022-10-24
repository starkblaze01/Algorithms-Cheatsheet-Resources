def encrypting():
    alphabet = "abcdefghijklmnopqrstuvxwyz"

    key = int(input("key: "))
    let = input("letter to encrypting: ")

    loction = alphabet.find(let)
    newLocation = (loction + key) %26 

    encrypted_letter = alphabet[newLocation]
    return encrypted_letter

def main():
    print( encrypting() )

if __name__=='__main__':
    main()
