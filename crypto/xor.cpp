#include <iostream>
#include <string>

std::string xor_cipher(const std::string &text, char key)
{
    std::string result = text;
    for (size_t i = 0; i < text.size(); i++)
    {
        result[i] = text[i] ^ key;
    }
    return result;
}

int main()
{
    std::string plain = "HELLO";
    char key = 0x5A;

    std::string encrypted = xor_cipher(plain, key);
    std::string decrypted = xor_cipher(encrypted, key);

    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
}
