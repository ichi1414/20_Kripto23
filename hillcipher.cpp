#include <iostream>
using namespace std;

// Fungsi untuk mengonversi teks ke angka (A=0, B=1, ..., Z=25)
void text_to_numbers(string text, int numbers[]) {
    for (int i = 0; i < text.length(); i++) {
        numbers[i] = text[i] - 'A';
    }
}

// Fungsi untuk mengonversi angka ke teks (0=A, 1=B, ..., 25=Z)
string numbers_to_text(int numbers[], int length) {
    string text = "";
    for (int i = 0; i < length; i++) {
        text += char(numbers[i] + 'A');
    }
    return text;
}

// Fungsi untuk mengenkripsi teks
void encrypt(string plaintext, int key[2][2], int ciphertext[], int length) {
    int block[2] = {0, 0};

    for (int i = 0; i < length; i += 2) {
        block[0] = plaintext[i] - 'A';
        block[1] = plaintext[i + 1] - 'A';

        for (int j = 0; j < 2; j++) {
            ciphertext[i + j] = (key[j][0] * block[0] + key[j][1] * block[1]) % 26;
        }
    }
}

// Fungsi untuk mendekripsi teks
void decrypt(int ciphertext[], int key[2][2], int plaintext[], int length) {
    int inverse_key[2][2];

    // Menghitung kunci invers
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0] + 26) % 26;
    int det_inv = 0;

    // Mencari invers dari determinan
    for (int i = 1; i < 26; i++) {
        if ((det * i) % 26 == 1) {
            det_inv = i;
            break;
        }
    }

    // Menghitung matriks invers
    inverse_key[0][0] = (key[1][1] * det_inv) % 26;
    inverse_key[0][1] = (-key[0][1] * det_inv + 26) % 26;
    inverse_key[1][0] = (-key[1][0] * det_inv + 26) % 26;
    inverse_key[1][1] = (key[0][0] * det_inv) % 26;

    // Mendekripsi teks
    for (int i = 0; i < length; i += 2) {
        int block[2] = {ciphertext[i], ciphertext[i + 1]};

        for (int j = 0; j < 2; j++) {
            plaintext[i + j] = (inverse_key[j][0] * block[0] + inverse_key[j][1] * block[1]) % 26;
        }
    }
}

int main() {
    string plaintext = "HELLO";
    int key[2][2] = {{6, 24}, {13, 16}};
    int ciphertext[5] = {0};
    int decryptedtext[5] = {0};

    int length = plaintext.length();
    int numbers[length];

    text_to_numbers(plaintext, numbers);
    encrypt(plaintext, key, ciphertext, length);
    decrypt(ciphertext, key, decryptedtext, length);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Key: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << key[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Ciphertext: ";
    for (int i = 0; i < length; i++) {
        cout << char(ciphertext[i] + 'A');
    }
    cout << endl;
    cout << "Deciphertext: " << numbers_to_text(decryptedtext, length) << endl;

    return 0;
}
