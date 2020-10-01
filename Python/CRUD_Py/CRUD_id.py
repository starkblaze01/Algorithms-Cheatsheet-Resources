# CRUD script using bahasa

done = []

def selesai():
    if (len(done) <= 0):
        print ('NOT FOUND')
    else:
        for i in range(len(done)):
            print(i,done[i])

def masuk():
    baru = input('Masukkan yang sudah selesai : ')
    done.append(baru)


def ubah():
    selesai()
    i = int(input('Masukkan id : '))
    if (len(done) < i):
        print('INVALID')
    else:
        sls = input('apa yg sudah dilakukan : ')
        done[i] = sls
        

def hapus():
    selesai()
    i = int(input('Masukkan ID : '))
    if (len(done) < i):
        print('INVALID')
    else:
        done.remove(done[i])

def menu():
    print('\n')
    print('='*15,'MENU','='*15)
    print('[1] LIST')
    print('[2] ADD')
    print('[3] CHANGE')
    print('[4] DELETE')
    print('[5] EXIT')

    menu = int(input('Pilih menu : '))
    print('\n')

    if(menu == 1):
        selesai()
    elif(menu==2):
        masuk()
    elif(menu==3):
        ubah()
    elif(menu==4):
        hapus()
    elif(menu==5):
        exit()
    else:
        print('TIDAK TERSEDIA')

if __name__ == "__main__":
    while(True):
        menu()