#number triangle using bahasa

def ayam():
    a = 1
    c = int(input("Masukkan berapa banyak : ")) #input number
    d = c
    while(a<=c):
        print(' '*d,f' {a}'*a)
        a+=1
        d-=1
ayam()