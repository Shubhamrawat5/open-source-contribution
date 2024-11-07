# Morse Code Dictionary
MORSE_CODE_DICT = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.',
    'F': '..-.', 'G': '--.', 'H': '....', 'I': '..', 'J': '.---',
    'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---',
    'P': '.--.', 'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-',
    'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--',
    'Z': '--..', '1': '.----', '2': '..---', '3': '...--', '4': '....-', 
    '5': '.....', '6': '-....', '7': '--...', '8': '---..', '9': '----.', 
    '0': '-----', ' ': '/'
}

# Function to encrypt a message to Morse code
def encrypt(message):
    cipher = ''
    for letter in message.upper():
        if letter in MORSE_CODE_DICT:
            cipher += MORSE_CODE_DICT[letter] + ' '
        else:
            cipher += '? '  # unknown character placeholder
    return cipher.strip()

# Function to decrypt a Morse code message
def decrypt(message):
    message += ' '  # Extra space to identify last Morse code word
    decipher = ''
    morse_word = ''
    for char in message:
        if char != ' ':  # Collect Morse characters
            morse_word += char
        else:  # End of Morse code word
            if morse_word in MORSE_CODE_DICT.values():
                decipher += list(MORSE_CODE_DICT.keys())[list(MORSE_CODE_DICT.values()).index(morse_word)]
            morse_word = ''
    return decipher

# Test the functions
message = "HELLO WORLD"
#message = input("Enter Your Message: ")

encrypted_message = encrypt(message)
print(f"Encrypted: {encrypted_message}")

decrypted_message = decrypt(encrypted_message)
print(f"Decrypted: {decrypted_message}")
