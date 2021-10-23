special_characters = " ,.-;:_?!="
alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def pattern_analysis(ciphered_text):
    distribution = {}
    for letter in ciphered_text:
        if letra in special_characters:
            continue
        if letter not in distribution:
            distribution[letter] = 1
        else:
            distribution[letter] += 1
    return distribution

def find_key(ciphered_text):
    most_common_letter_index = 4 #this is based on english language
    
    distribution = pattern_analysis(ciphered_text)

    common_letters = sorted(distribution, key=distribution.get, reverse=True)
    
    key = alphabet.find(common_letters[0].upper()) - most_common_letter_index
    return key


cipher = input('type your cipher:')
print(find_key(cipher))
