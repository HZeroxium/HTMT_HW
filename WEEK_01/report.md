### <center> HW1: Data Representation </center>

## Students

1. Nguyễn Gia Huy - 22127154
2. Trần Thành Long - 22127250

## Main idea

- Our program has been written in C++.
- To solve this problem, we use the boolean array consisting of 8 elements to store the binary form of the input number. An element of the array is true if the corresponding bit of the input number is 1, otherwise, it is false.

### Sign-Magnitude form

- To convert a decimal number to the sign-magnitude form, we just need to check if the input number is negative or not. If the input number is negative, we set the first element of the array to true, otherwise, we set it to false. Then, we convert the absolute value of the input number to the binary form and store it in the rest of the array.
- The range of the sign-magnitude form is from -127 to 127. Number 0 has 2 representations: 00000000 and 10000000.
  
### One's complement form

- To convert a decimal number to the one's complement form, we just need to check if the input number is negative or not. If the input number is negative, we set the first element of the array to true, otherwise, we set it to false. Then, we convert the absolute value of the input number to the binary form and store it in the rest of the array. Finally, we invert all the elements of the array except the first element.
- The range of the one's complement form is from -127 to 127. Number 0 has 2 representations: 00000000 and 11111111.

### Two's complement form

- To convert a decimal number to the two's complement form, we just need to check if the input number is negative or not. If the input number is negative, we set the first element of the array to true, otherwise, we set it to false. Then, we convert the absolute value of the input number to the binary form and store it in the rest of the array. Finally, we add 1 to the array.
- The range of the two's complement form is from -128 to 127. Number 0 has only 1 representation: 00000000.

## Implementation

In our program, we have 2 classes: `BinaryPattern` and `Solution`.

- class `BinaryPattern` is used to store the binary form of the input number.
- class `Solution` is used to solve the problem. it will check if the input number is valid or not, then it will convert the input number to the sign-magnitude form, one's complement form, and two's complement form, including checking for special cases; otherwise, it will print an error message **overflow** or **invalid**.

## Source code

[Google Drive](https://drive.google.com/drive/u/2/folders/1Cmv5PQDFDTsEWTm1FdQcEHfxbB-vgMD2)

## Screenshots

### Valid input

### Example 1

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/f8ceb851-c462-4a27-a15e-70473877c53b/c9aa66c0-a9b2-40aa-9650-16ab1c223927/Untitled.png)

### Example 2

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/f8ceb851-c462-4a27-a15e-70473877c53b/507ab041-924d-4654-bd5d-411b93b288b9/Untitled.png)

### Example 3

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/f8ceb851-c462-4a27-a15e-70473877c53b/adc79668-231c-490c-ba00-95e5c3c61f3f/Untitled.png)

### Example 4

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/f8ceb851-c462-4a27-a15e-70473877c53b/3eee9784-7b08-422c-8169-dd4592285dd7/Untitled.png)

### Example 5

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/f8ceb851-c462-4a27-a15e-70473877c53b/91582ab8-d4a0-4dbd-abe0-d0c738856a57/Untitled.png)

### Example 6

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/f8ceb851-c462-4a27-a15e-70473877c53b/52b69a82-17c1-451d-9f51-e081fd2d3874/Untitled.png)

### Example 7

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/f8ceb851-c462-4a27-a15e-70473877c53b/61d7fe8b-8560-481b-a539-2cc1bf2c1ff9/Untitled.png)
