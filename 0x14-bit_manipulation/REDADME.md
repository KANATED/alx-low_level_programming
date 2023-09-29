BIT MANIPULATION
Bit manipulation, also known as bitwise operations, involves manipulating individual bits within binary representations of data. In computer programming, bits are the smallest unit of data and can only have two values: 0 or 1. Bit manipulation is commonly used in low-level programming and systems programming for various purposes, including:

1. Bitwise AND (`&`) and OR (`|`) Operations:
   Bitwise AND (`&`) combines two sets of bits, returning 1 for each bit position where both input bits are 1. It's often used to mask specific bits or check if certain bits are set.
   Bitwise OR (`|`) combines two sets of bits, returning 1 for each bit position where either or both input bits are 1. It's used to set or combine specific bits.

2. Bitwise XOR (`^`) Operation:
   Bitwise XOR (`^`) combines two sets of bits, returning 1 for each bit position where the input bits are different. It's used for tasks like toggling specific bits.

3. Bitwise NOT (`~`) Operation:
   Bitwise NOT (`~`) inverts all the bits in a binary number, changing 0s to 1s and 1s to 0s.

4. Left Shift (`<<`) and Right Shift (`>>`) Operations:
   Left shift (`<<`) moves the bits of a binary number to the left, effectively multiplying by powers of 2.
   Right shift (`>>`) moves the bits to the right, effectively dividing by powers of 2.

5. Bit Manipulation for Flags and Flags Testing:
   Individual bits can be used as flags to represent boolean states. Bit manipulation can be used to set, clear, toggle, or test these flags efficiently.

6. Optimizing Storage:
   In embedded systems or when working with limited memory, bit manipulation can help pack multiple pieces of data into a single integer or other data type, saving memory.

7. Cryptography and Hashing:
   Bit manipulation is used in various cryptographic algorithms and hash functions to perform operations on binary data.

8. Graphics Programming:
   In graphics programming, bit manipulation is used for tasks like pixel manipulation, color manipulation, and texture mapping.

9. Network Protocols:
   Bitwise operations are used to encode and decode data in network protocols, such as IP addresses, subnet masks, and port numbers.

Bit manipulation requires a good understanding of binary representation and the bitwise operators provided by programming languages. It's often used in scenarios where performance and memory efficiency are critical, such as systems programming, embedded systems, and low-level hardware interactions.
