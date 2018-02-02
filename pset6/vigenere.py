import cs50
import sys

def main():
    if len(sys.argv) != 2:
        print("Usage: python vigenere.py k")
        return

    keytext = sys.argv[1]
    key = []

    alphabet = []
    letter = ord('A')
    for i in range(26):
        alphabet.append(letter)
        letter+=1

    for i in range(len(keytext)):
        if not keytext.isalpha():
            print("Usage: python vigenere.py k")
            return

    count = 0
    n = len(keytext)
    for i in range(n):
        key.append(ord(keytext[i].upper())-65)
        count+=1

    zahl = 0
    print("plaintext: ", end ="")
    text = cs50.get_string()
    print("ciphertext: ", end = "")

    for i in range(len(text)):
        if text[i].isalpha():
            for j in range(25):
                if alphabet[j]==ord(text[i]):
                    print("{}".format(chr((((ord(text[i])-65)+key[zahl])%26)+65)), end = "")
                    zahl+=1
                    if zahl == count:
                        zahl = 0

                elif text[i]==chr(alphabet[j]).lower():
                    print("{}".format(chr((((ord(text[i])-97)+key[zahl])%26)+97)), end = "")
                    zahl+=1

                    if zahl == count:
                        zahl = 0
        else:
            print("{}".format(text[j]), end ="")



if __name__ == "__main__":
    main()