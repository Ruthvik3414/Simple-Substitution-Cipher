# Simple-Substitution-Cipher
This C++ program implements a simple substitution cipher for encrypting and decrypting messages. It uses a predefined alphabet and a corresponding key to replace each character in the secret message. The program handles both uppercase and lowercase letters and preserves other characters like spaces and punctuation. 

This is a great example of string manipulation in C++, showcasing the use of `string::find()` and `string::at()` to build a simple encryption algorithm.

### Code

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {

    string alphabet {" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"_XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    string secret_message {};
    cout << "Enter the secret message: ";
    getline(cin, secret_message);

    string encrypted_message {};
    cout << "\nEncrypting message........" << endl;

    for (char c: secret_message) {
        size_t position = alphabet.find(c);
        if (position != string::npos) {
            char new_char = {key.at(position)};
            encrypted_message += new_char;
        } else {
            encrypted_message += c;
        }
    }

    cout << "\nEncrypted message: " << encrypted_message << endl;

    string decrypt_message {};
    cout << "\nDecrypting message......" << endl;

    for (char c:encrypted_message) {
        size_t position = key.find(c);
        if (position != string::npos) {
            char new_char = {alphabet.at(position)};
            decrypt_message += new_char;
        } else {
            decrypt_message +=c;
        }
    }

    cout << "\nDecrypted message: " << decrypt_message << endl;

    return 0;
}
