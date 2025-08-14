# Simple-Substitution-Cipher
This C++ program implements a simple substitution cipher for encrypting and decrypting messages. It uses a predefined alphabet and a corresponding key to replace each character in the secret message. The program handles both uppercase and lowercase letters and preserves other characters like spaces and punctuation. 

This is a great example of string manipulation in C++, showcasing the use of `string::find()` and `string::at()` to build a simple encryption algorithm.

## How to Compile and Run

This program can be compiled using g++. To run it, follow these steps in your terminal:

1.  **Compile the code:**
    ```bash
    g++ -o cipher main.cpp
    ```
    This command compiles `main.cpp` and creates an executable file named `cipher`.

2.  **Run the program:**
    ```bash
    ./cipher
    ```
    The program will then prompt you to enter a secret message to be encrypted and decrypted.

## Features

* Encrypts a given message using a simple substitution cipher.
* The cipher uses a predefined key to map each character of the alphabet.
* Decrypts the encrypted message to its original form.
* Handles spaces and other characters that are not in the defined alphabet by leaving them unchanged.


### Code

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {

    // Define the original alphabet and the substitution key.
    string alphabet {" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"_XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    string secret_message {};
    cout << "Enter the secret message: ";
    // Read the entire line of input, including spaces, for the secret message.
    getline(cin, secret_message);

    string encrypted_message {};
    cout << "\nEncrypting message........" << endl;

    // Loop through each character of the secret message to encrypt it.
    for (char c: secret_message) {
        // Find the position of the character in the original alphabet string.
        size_t position = alphabet.find(c);
        if (position != string::npos) {
            // If the character is found, get the corresponding character from the key.
            char new_char = {key.at(position)};
            encrypted_message += new_char;
        } else {
            // If the character is not found in the alphabet, add it to the encrypted message unchanged.
            encrypted_message += c;
        }
    }

    cout << "\nEncrypted message: " << encrypted_message << endl;

    string decrypt_message {};
    cout << "\nDecrypting message......" << endl;

    // Loop through each character of the encrypted message to decrypt it.
    for (char c:encrypted_message) {
        // Find the position of the character in the key string.
        size_t position = key.find(c);
        if (position != string::npos) {
            // If the character is found, get the corresponding character from the original alphabet.
            char new_char = {alphabet.at(position)};
            decrypt_message += new_char;
        } else {
            // If the character is not found in the key, add it to the decrypted message unchanged.
            decrypt_message +=c;
        }
    }

    cout << "\nDecrypted message: " << decrypt_message << endl;

    return 0;
}
