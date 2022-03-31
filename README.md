# 2-variables-in-one-c

### This project lets you store 2 numbers in one variable

# How does it work?
  - `unsigned long long` stores 2 32 bit integer
  - 2x int32 gets converted to binary and then stored in an `unsigned long long` 0-32 bits first value, 32-64 bit second value
  - `0000 0000 0000 0000 0000 0000 0000 0001 0000 0000 0000 0000 0000 0000 0000 0001` = 1, 1
