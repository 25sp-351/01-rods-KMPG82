TEST CASE 1
tests for: rod length not present

input:
./main

output:
Invalid input. Input one positive integer in this format "./main <integer>". For example, "./main 45".

status: passed
----------------------
TEST CASE 2
tests for: no extra params allowed after rod length

input:
./main 10 24

output:
Invalid input. Input one positive integer in this format "./main <integer>". For example, "./main 45".

status: passed
----------------------
TEST CASE 3
tests for: rod length not an integer

input:
./main d

output:
Invalid input. Input one positive integer in this format "./main <integer>". For example, "./main 45".

status: passed
----------------------
TEST CASE 4
tests for: rod length is negative

input:
./main -10

output:
Invalid input. Input one positive integer in this format "./main <integer>". For example, "./main 45".

status: passed
----------------------
TEST CASE 5
tests for: at least one length and value pair is not entered

input:
./main 10

Enter the list of piece prices in the format "<length>, <value>":

output:
Invalid input. Enter at least one length and value pair.

status: passed
----------------------
TEST CASE 6
tests for: correct output with no remainder and one length and value pair

input:
./main 10

Enter the list of piece prices in the format "<length>, <value>":
2, 5

output:
5 @ 2 = 25
Remainder: 0
Value: 25

status: passed
----------------------
TEST CASE 7
tests for: correct output with no remainder and multiple length and value pairs

input:
./main 10

Enter the list of piece prices in the format "<length>, <value>":
5, 10
1, 1
10, 20

output:
1 @ 10 = 20
Remainder: 0
Value: 20

status: passed
----------------------
TEST CASE 8
tests for: correct output with a remainder and one length and value pair

input:
./main 10

Enter the list of piece prices in the format "<length>, <value>":
4, 7

output:
2 @ 4 = 14
Remainder: 2
Value: 14

status: passed
----------------------
TEST CASE 9
tests for: correct output with a remainder and multiple length and value pairs

input:
./main 10

Enter the list of piece prices in the format "<length>, <value>":
3, 4
2, 2
11, 21

output:
3 @ 3 = 12
Remainder: 1
Value: 12

status: passed
----------------------
TEST CASE 10
tests for: correct output

input:
./main 4

Enter the list of piece prices in the format "<length>, <value>":
2, 5
1, 1
4, 10

output:
1 @ 4 = 10
Remainder: 0
Value: 10

status: passed
----------------------
TEST CASE 11
tests for: correct output using the same input in the above test, but inputted in a different order

input:
./main 4

Enter the list of piece prices in the format "<length>, <value>":
1, 1
4, 10
2, 5

output:
1 @ 4 = 10
Remainder: 0
Value: 10

status: passed
----------------------
TEST CASE 12
tests for: length input is not an integer

input:
./main 10

Enter the list of piece prices in the format "<length>, <value>":
c, 4

output:
Invalid input. Only enter positive integers in the specified format. For example, "24, 5".

status: passed
----------------------
TEST CASE 13
tests for: value input is not an integer

input:
./main 10

Enter the list of piece prices in the format "<length>, <value>":
4, c

output:
Invalid input. Only enter positive integers in the specified format. For example, "24, 5".

status: passed
----------------------
TEST CASE 14
tests for: length and value input are not integers

input:
./main 10

Enter the list of piece prices in the format "<length>, <value>":
a, c

output:
Invalid input. Only enter positive integers in the specified format. For example, "24, 5".

status: passed
----------------------
TEST CASE 15
tests for: length input is negative

input:
./main 10

Enter the list of piece prices in the format "<length>, <value>":
-1, 4

output:
Invalid input. Only enter positive integers in the specified format. For example, "24, 5".

status: passed
----------------------
TEST CASE 16
tests for: value input is negative

input:
./main 10

Enter the list of piece prices in the format "<length>, <value>":
4, -1

output:
Invalid input. Only enter positive integers in the specified format. For example, "24, 5".

status: passed
----------------------
TEST CASE 17
tests for: length and value input are negative

input:
./main 10

Enter the list of piece prices in the format "<length>, <value>":
-1, -4

output:
Invalid input. Only enter positive integers in the specified format. For example, "24, 5".

status: passed
----------------------
TEST CASE 18
tests for: additional input after length and value input

input:
./main 10

Enter the list of piece prices in the format "<length>, <value>":
1, 2, 4

output:
Invalid input. Only enter positive integers in the specified format. For example, "24, 5".

status: passed
----------------------
TEST CASE 19
tests for: additional input after length and value input

input:
./main 10

Enter the list of piece prices in the format "<length>, <value>":
1, 2d

output:
Invalid input. Only enter positive integers in the specified format. For example, "24, 5".

status: passed
----------------------
TEST CASE 20
tests for: additional input after length and value input

input:
./main 10

Enter the list of piece prices in the format "<length>, <value>":
1, 2 d

output:
Invalid input. Only enter positive integers in the specified format. For example, "24, 5".

status: passed
----------------------
TEST CASE 21
tests for: correct output for composition of multiple pieces without a remainder

input:
./main 14

Enter the list of piece prices in the format "<length>, <value>":
9, 10
3, 6
2, 3
4, 8

output:
2 @ 4 = 16
2 @ 3 = 12
Remainder: 0
Value: 28

status: passed
----------------------
TEST CASE 22
tests for: correct output for composition of a single piece without a remainder

input:
./main 16

Enter the list of piece prices in the format "<length>, <value>":
9, 10
3, 6
2, 3
4, 8

output:
4 @ 4 = 32
Remainder: 0
Value: 32

status: passed
----------------------
TEST CASE 23
tests for: correct output for composition of a single piece with a remainder

input:
./main 16

Enter the list of piece prices in the format "<length>, <value>":
7, 20 
18, 50
20, 55
22, 60

output:
2 @ 7 = 40
Remainder: 3
Value: 40

status: passed
----------------------
TEST CASE 24
tests for: correct output for composition of multiple pieces with a remainder

input:
./main 16

Enter the list of piece prices in the format "<length>, <value>":
7, 20
2, 2
18, 50
20, 55

output:
2 @ 7 = 40
1 @ 2 = 2
Remainder: 1
Value: 42

status: passed
----------------------
TEST CASE 25
tests for: rod length is less than all lengths

input:
./main 1

Enter the list of piece prices in the format "<length>, <value>":
2, 5
3, 6
4, 7
5, 8

output:
Remainder: 1
Value: 0

status: passed
----------------------
TEST CASE 26
tests for: not using specified format

input:
./main 1

Enter the list of piece prices in the format "<length>, <value>":
2. 5


output:
Invalid input. Only enter positive integers in the specified format. For example, "24, 5".

status: passed
----------------------
TEST CASE 27
tests for: not using specified format

input:
./main 1

Enter the list of piece prices in the format "<length>, <value>":
2/ 5


output:
Invalid input. Only enter positive integers in the specified format. For example, "24, 5".

status: passed
----------------------
TEST CASE 28
tests for: not using specified format

input:
./main 1

Enter the list of piece prices in the format "<length>, <value>":
2 , 5


output:
Invalid input. Only enter positive integers in the specified format. For example, "24, 5".

status: passed