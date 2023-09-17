#include <iostream>
using namespace std;

string encrypt(string text, int shift) {
    string result = "";

    for(char& c : text) {
        if(isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            c = (c - offset + shift) % 26 + offset;
        }
    }

    return text;
}

string decrypt(string text, int shift) {
    return encrypt(text, 26 - shift);
}

int main() {
    string plaintext = "Hello World!";
    int shift_amount = 3;

    string encrypted_text = encrypt(plaintext, shift_amount);
    cout << "Teks Terenkripsi: " << encrypted_text << endl;

    string decrypted_text = decrypt(encrypted_text, shift_amount);
    cout << "Teks Terdekripsi: " << decrypted_text << endl;

    return 0;
}
