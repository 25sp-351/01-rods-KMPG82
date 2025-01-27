TEST CASE 1
input:
./main 10

Enter the list of piece prices in the format <length>, <value> (Ctrl+Z for Windows / Ctrl+D for Linux to end):
2, 5
8, 10
1, 2

expected output:
Cutting list (<n> @ <size> = <total value>): 
5 @ 2 = 25 
0 @ 8 = 0 
0 @ 1 = 0 
Remainder: 0
Value: 25

STATUS: PASSED
----------------------
TEST CASE 2
input:
./main 11

Enter the list of piece prices in the format <length>, <value> (Ctrl+Z for Windows / Ctrl+D for Linux to end):
2, 5
8, 10

expected output:
Cutting list (<n> @ <size> = <total value>): 
5 @ 2 = 25 
0 @ 8 = 0 
Remainder: 1
Value: 25

STATUS: PASSED
----------------------
TEST CASE 3
Input:
./main 12

Enter the list of piece prices in the format <length>, <value> (Ctrl+Z for Windows / Ctrl+D for Linux to end):
2, 6 
4, 8
6, 12
3, 7

Cutting list (<n> @ <size> = <total value>): 
6 @ 2 = 36 
0 @ 4 = 0 
0 @ 6 = 0 
0 @ 3 = 0 
Remainder: 0
Value: 36

STATUS: PASSED
----------------------
TEST CASE 4
Input:
./main 14

Enter the list of piece prices in the format <length>, <value> (Ctrl+Z for Windows / Ctrl+D for Linux to end):
9, 10
3, 6
2, 3
4, 8

Expected Output:
Cutting list (<n> @ <size> = <total value>): 
0 @ 9 = 0 
2 @ 3 = 12 
0 @ 2 = 0 
2 @ 4 = 16 
Remainder: 0
Value: 28

STATUS: PASSED
----------------------
TEST CASE 5
Input:
./main 45

Enter the list of piece prices in the format <length>, <value> (Ctrl+Z for Windows / Ctrl+D for Linux to end):
32, 10
23, 5
40, 15
21, 2

Expected Output:
Cutting list (<n> @ <size> = <total value>): 
0 @ 32 = 0 
0 @ 23 = 0 
1 @ 40 = 15 
0 @ 21 = 0 
Remainder: 5
Value: 15

STATUS: PASSED
----------------------
TEST CASE 6
Input:
./main 70

Enter the list of piece prices in the format <length>, <value> (Ctrl+Z for Windows / Ctrl+D for Linux to end):
20, 40
2, 7
4, 15
12, 35

Expected Output:
Cutting list (<n> @ <size> = <total value>): 
0 @ 20 = 0 
1 @ 2 = 7 
17 @ 4 = 255 
0 @ 12 = 0 
Remainder: 0
Value: 262

STATUS: PASSED