temp = input("Input the  temperature you would like to convert? (e.g. 45F, 102C etc.) : ")
degree = int(temp[:-1])
input = temp[-1]

if input.upper() == "C":
  result = int(round((9 * degree) / 5 + 32))
  output = "Fahrenheit"
elif input.upper() == "F":
  result = int(round((degree - 32) * 5 / 9))
  output = "Celsius"
else:
  print("Input proper convention of temperature.")
  quit()
print("The temperature in", output, "is", result, "degrees.")