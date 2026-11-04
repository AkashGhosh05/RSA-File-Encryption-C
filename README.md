# RSA File Encryption and Decryption in C

## Overview
A menu-driven C program that demonstrates file encryption and decryption using the RSA public-key cryptography algorithm.

## Features
- RSA key generation using prime numbers
- Modular exponentiation
- File encryption
- File decryption using a private key
- Menu-driven interface

## Technologies Used
- Programming Language: C
- Concepts: RSA Algorithm, Public-Key Cryptography, Modular Arithmetic, File Handling

## How It Works
1. The program generates RSA key parameters.
2. The user selects encryption and provides a filename.
3. The program encrypts the file contents and stores the encrypted output in `Encrypted.txt`.
4. The program displays the private key.
5. The user can select decryption and provide the encrypted file and private key.
6. The decrypted contents are saved in `Decrypted.txt`.

## Compilation
```bash
gcc "File Encryption.c" -o rsa_encryption
```

Run:
```bash
./rsa_encryption
```

## Limitations
This is an academic implementation intended to demonstrate RSA concepts. It uses fixed prime numbers and textbook RSA without padding, so it is not suitable for securing real-world sensitive data. 
