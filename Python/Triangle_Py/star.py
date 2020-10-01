#star triangle in bahasa

def ayam():
    a = 1
    c = int(input("Masukkan berapa banyak : ")) #input number
    d = c
    while(a<=c):
        print(' '*d,'*'*a)
        a+=2
        d-=1
ayam()