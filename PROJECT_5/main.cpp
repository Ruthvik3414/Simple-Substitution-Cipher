#include <iostream>

using namespace std;

int main() {

    string alphbet {" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"_XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    string secret_message {};
    cout << "Enter the secret message: ";
    getline(cin, secret_message);

    string encrypted_message {};
    cout << "\nEncrypting message........" << endl;

    for (char c: secret_message) {
        size_t position = alphbet.find(c);
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
            char new_char = {alphbet.at(position)};
            decrypt_message += new_char;
        } else {
            decrypt_message +=c;
        }
    }

    cout << "\nDecrypted message: " << decrypt_message << endl;
}