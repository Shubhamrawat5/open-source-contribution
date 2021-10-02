# Floating Point Representation with IEEE 754 
### IEEE 754 is a technical standard for floating-point computation.
It was established by the **Institute of Electrical and Electronics Engineers (IEEE)**. 
This algorithm basically allows us to convert floating point numbers (like 12.5) into binary format. 

There are three components of IEEE 754 namely- ```sign```, ```exponent``` and ```mantissa```.
On the basis of these three components it is divided into two: 
- Single Precision (32 bits)
- Double Precision (64 bits)

![image](https://user-images.githubusercontent.com/84583787/135731183-fb340d2c-10be-4a57-a8db-32b75ce3b37b.png)

As seen in the image above each total numbers of bits are divided among the three components. 

```But what are these three components?```
- **Sign bit** is the first bit of the binary representation. ‘1’ implies negative number and ‘0’ implies positive number.
- **Exponent** is decided by the next 8 bits for single precision while 11 bits for double precision of binary representation. 127 is the unique number for 32 bit while 1023 for 64 bit floating point representation. It is known as bias. It is determined by 2k-1 -1 where ‘k’ is the number of bits in exponent field. 
- **Mantissa** is calculated from the remaining 23 bits for single precision and 52 bits for double precision of the binary representation. It consists of ‘1’ and a fractional part
 
 
 ## Example for IEEE 754 using ```Single Precision (32 bits)``` 
 ### Converting 0.1 to binary 
 
 ![image](https://user-images.githubusercontent.com/84583787/135731378-0d557e53-a0d5-48b9-a41d-06df9b801b91.png)
 
 
 
