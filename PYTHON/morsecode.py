# tuple containing Morse code representations of
# the letters (item 0 is A, item 1 = B, etc.)
code = (".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..")
# tuple containing the Morse code for digits
digit = ("-----",".----","...--","....-",".....","-....","--...","---..","----.")

option = ""
while option not in ("D","E"):
  option = input("Enter 'E' to encode and 'D' to decode: ").upper()
if option == "E":
  morse = ""
  # Morse code has no cases, so work in upper case
  text = input("Please enter the text to be encoded: ").upper()
  # look through each character in the input
  for char in text:
    # if it's a letter
    if char >= "A" and char <= "Z":
      # use ASCII code to calculate as index for code
      # A=65, B=66... so subtracting 65 gives 0, 1...
      morse += (code[ord(char)-65] + " ")
    # if it's a digit
    if char >= "0" and char <= "9":
      # use the integer version as index for digit
      morse += (digit[eval(char)] + " ") 
    # if it's a space
    if char == " ":
      morse += "| "
  print(morse)
else:
  # split input into a list
  morse = input("Enter the morse code: ").split()
  text = ""
  # check each item in the list...
  for cluster in morse:
    # is it a letter?
    if cluster in code:
      # add 65 to the code index to get the ASCII code
      text += chr(code.index(cluster)+65)
    if cluster in digit:
      # the index is the digit
      text += str(digit.index(cluster))
    # a pipe is used to represent a space
    if cluster == "|":
      text += " "
  print(text)
