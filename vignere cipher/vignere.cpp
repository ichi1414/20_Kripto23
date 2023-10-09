/*
Nama : Devina Dixie
Kelas : B
NPM : 140810210020
Program : Vignere Cipher Programme
*/

#include <iostream>
#include <string>
using namespace std;

string encrypt(string text, string key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char encrypted = (c + key[i % key.length()] - 2 * base) % 26 + base;
            result += encrypted;
        } else {
            result += c;
        }
    }
    return result;
}

string decrypt(string text, string key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char decrypted = (c - key[i % key.length()] + 26) % 26 + base;
            result += decrypted;
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string text, key;

    cout << "insert text: ";
    getline(cin, text);

    cout << "insert key: ";
    cin >> key;

    string encrypted_text = encrypt(text, key);
    cout << "encrypted text: " << encrypted_text << endl;

    string decrypted_text = decrypt(encrypted_text, key);
    cout << "decrypted text: " << decrypted_text << endl;

    return 0;
}
