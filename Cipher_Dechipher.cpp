// I Do baconian cypher and vignere cypher and morse cypher and  atbash cypher.
#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <limits>
using namespace std;

// baconian cypher function
void baconian_cypher()
{
    while (true)
    {
        string text;
        cout << "ENTER THE SENTENCE YOU WANT TO ENCRYPT :" << endl;
        getline(cin, text);
        bool isValidInput = true;
        for (char character : text)
        {
            if (!isalpha(character) && !isspace(character))
            {
                cout << "Invalid input. Please enter only alphabetic characters and spaces." << endl;
                isValidInput = false;
                break;
            }
        }
        if (!isValidInput)
        {
            continue;
        }
        for (int s = 0; s < text.length(); s++)
        {
            text[s] = toupper(text[s]);
        }
        map<char, string> binaryMap = {
            {'A', "aaaaa"}, {'B', "aaaab"}, {'C', "aaaba"}, {'D', "aaabb"}, {'E', "aabaa"}, {'F', "aabab"}, {'G', "aabba"}, {'H', "aabbb"}, {'I', "abaaa"}, {'J', "abaab"}, {'K', "ababa"}, {'L', "ababb"}, {'M', "abbaa"}, {'N', "abbab"}, {'O', "abbba"}, {'P', "abbbb"}, {'Q', "baaaa"}, {'R', "baaab"}, {'S', "baaba"}, {'T', "baabb"}, {'U', "babaa"}, {'V', "babab"}, {'W', "babba"}, {'X', "babbb"}, {'Y', "bbaaa"}, {'Z', "bbaab"}};

        cout << "ENCRYPTED TEXT:" << endl;
        for (int i = 0; i < text.length(); i++)
        {
            char character = text[i];
            if (isspace(character))
            {
                cout << " ";
            }
            else
            {
                string new_character = "00000";
                if (binaryMap.find(character) != binaryMap.end())
                {
                    new_character = binaryMap[character];
                }
                cout << new_character;
            }
            cout << ' ';
        }
        cout << endl;
        break;
    }
}

// baconian decryption function
void baconian_decryption()
{
    while (true)
    {
        string text;
        cout << "ENTER THE SENTENCE YOU WANT TO DECRYPT :" << endl;
        getline(cin, text);

        bool isValidInput = true;
        for (char character : text)
        {
            if (!(character == 'a' || character == 'b' || isspace(character)))
            {
                cout << "Invalid input. Please enter only [a,b] and spaces." << endl;
                isValidInput = false;
                break;
            }
        }

        if (!isValidInput)
        {
            continue;
        }

        map<string, char> binaryMap =
            {
                {"aaaaa", 'A'}, {"aaaab", 'B'}, {"aaaba", 'C'}, {"aaabb", 'D'}, {"aabaa", 'E'}, {"aabab", 'F'}, {"aabba", 'G'}, {"aabbb", 'H'}, {"abaaa", 'I'}, {"abaab", 'J'}, {"ababa", 'K'}, {"ababb", 'L'}, {"abbaa", 'M'}, {"abbab", 'N'}, {"abbba", 'O'}, {"abbbb", 'P'}, {"baaaa", 'Q'}, {"baaab", 'R'}, {"baaba", 'S'}, {"baabb", 'T'}, {"babaa", 'U'}, {"babab", 'V'}, {"babba", 'W'}, {"babbb", 'X'}, {"bbaaa", 'Y'}, {"bbaab", 'Z'}};

        cout << "DECRYPTED TEXT:" << endl;
        string decryptedText = "";
        string currentBinary = "";
        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] == ' ')
            {
                if (binaryMap.find(currentBinary) != binaryMap.end())
                {
                    decryptedText += binaryMap[currentBinary];
                }
                currentBinary = "";
            }
            else
            {
                currentBinary += text[i];
            }
        }
        if (binaryMap.find(currentBinary) != binaryMap.end())
        {
            decryptedText += binaryMap[currentBinary];
        }

        cout << decryptedText << endl;
        break;
    }
}

// vignere cypher function
void vignere_cypher()
{
    string message;
    string keyword;
    cout << "ENTER THE SENTENCE YOU WANT TO ENCRYPT MESSAGE :" << endl;
    getline(cin, message);
    for (int s = 0; s < message.length(); s++)
    {
        message[s] = toupper(message[s]);
    }

    cout << "ENTER THE KEYWORD: " << endl;
    getline(cin, keyword);
    for (int v = 0; v < keyword.length(); v++)
    {
        keyword[v] = toupper(keyword[v]);
    }
    string repeatedKeyword = "";
    for (int i = 0, j = 0; i < message.length(); i++, j++)
    {
        if (j == keyword.length())
        {
            j = 0;
        }
        repeatedKeyword += keyword[j];
    }

    cout << "ENCRYPTED MESSAGE: ";
    for (int i = 0; i < message.length(); i++)
    {
        if (!isalpha(message[i]))
        {
            cout << message[i];
        }
        else
        {
            char character = (repeatedKeyword[i] + message[i]) % 26 + 'A';
            cout << character;
        }
    }
    cout << endl;
}
// vignere decryption fuction
void vignere_decryption()
{
    string message;
    string keyword;
    cout << "ENTER THE SENTENCE YOU WANT TO DECRYPT MESSAGE :" << endl;
    getline(cin, message);
    for (int s = 0; s < message.length(); s++)
    {
        message[s] = toupper(message[s]);
    }

    cout << "ENTER THE KEYWORD: " << endl;
    getline(cin, keyword);
    for (int v = 0; v < keyword.length(); v++)
    {
        keyword[v] = toupper(keyword[v]);
    }
    string repeatedKeyword = "";
    for (int i = 0, j = 0; i < message.length(); i++, j++)
    {
        if (j == keyword.length())
        {
            j = 0;
        }
        repeatedKeyword += keyword[j];
    }
    cout << "DECRYPTED MESSAGE: ";
    for (int i = 0; i < message.length(); i++)
    {
        if (!isalpha(message[i]))
        {
            cout << message[i];
        }
        else
        {
            char character = ((message[i] - repeatedKeyword[i] + 26) % 26) + 'A';
            cout << character;
        }
    }
    cout << endl;
}

// morse cypher function
void morse_cypher()
{
    while (true)
    {
        string text;
        cout << "ENTER THE SENTENCE YOU WANT TO ENCRYPT :" << endl;
        getline(cin, text);

        bool isValidInput = true;
        for (char character : text)
        {
            if (!isalpha(character) && !isspace(character))
            {
                cout << "Invalid input. Please enter only alphabetic characters and spaces." << endl;
                isValidInput = false;
                break;
            }
        }

        if (!isValidInput)
        {
            continue;
        }

        for (int s = 0; s < text.length(); s++)
        {
            text[s] = toupper(text[s]);
        }
        map<char, string> morseMap = {
            {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."}};

        cout << "ENCRYPTED TEXT:" << endl;
        for (int i = 0; i < text.length(); i++)
        {
            char character = text[i];
            string new_character;
            if (morseMap.find(character) != morseMap.end())
            {
                new_character = morseMap[character];
            }

            cout << new_character << ' ';
        }

        cout << endl;
        break;
    }
}

// morse  decryption function
void morse_decryption()
{
    while (true)
    {
        string text;
        cout << "ENTER THE SENTENCE YOU WANT TO DECRYPT :" << endl;
        getline(cin, text);
        bool isValidInput = true;
        for (char character : text)
        {
            if (!(character == '-' || character == '.' || isspace(character)))
            {
                cout << "Invalid input. Please enter only [-,.] and spaces." << endl;
                isValidInput = false;
                break;
            }
        }

        if (!isValidInput)
        {
            continue;
        }
        map<string, char> morseMap =
            {
                {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'}, {".", 'E'}, {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'}, {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'}, {".-..", 'L'}, {"--", 'M'}, {"-.", 'N'}, {"---", 'O'}, {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'}, {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'}, {"-.--", 'Y'}, {"--..", 'Z'}};

        cout << "DECRYPTED TEXT:" << endl;
        string decrypted_Text = "";
        string current_text = "";
        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] == ' ')
            {
                if (morseMap.find(current_text) != morseMap.end())
                {
                    decrypted_Text += morseMap[current_text];
                }
                current_text = "";
            }
            else
            {
                current_text += text[i];
            }
        }
        if (morseMap.find(current_text) != morseMap.end())
        {
            decrypted_Text += morseMap[current_text];
        }

        cout << decrypted_Text << endl;
        break;
    }
}

// Version A_Z
void versionA_Z(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        char character = word[i];
        if (isupper(character))
        {
            character = 'Z' + 'A' - character;
        }
        cout << character;
    }
}

// Version A_M N_Z
void version_2(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        char character = word[i];
        if ((character >= 'A' && character <= 'M') || (character >= 'a' && character <= 'm'))
        {
            if (isupper(word[i]))
            {
                character = 'M' + 'A' - word[i];
            }
        }
        else if ((character >= 'N' && character <= 'Z') || (character >= 'n' && character <= 'z'))
        {
            if (isupper(word[i]))
            {
                character = 'Z' + 'N' - word[i];
            }
        }
        cout << character;
    }
}

void version_13(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        char character = word[i];
        if (isupper(character))
        {
            character = (character - 'A' + 1) % 26 + 'A';
            cout << character;
        }
    }
}

int main()
{
    string choice;
    cout << "Ahlan ya user ya habibi" << endl;
    while (true)
    {
        cout << "1) Cipher a message." << endl;
        cout << "2) Decipher a message." << endl;
        cout << "3) End." << endl;
        cout << "YOUR CHOICE : ";
        cin >> choice;
        if (choice == "3")
        {
            cout << "Good Bye User.";
            break;
        }
        else if (choice == "1")
        {
            while (true)
            {
                cout << "1) BACONIAN." << endl;
                cout << "2) VIGNERE." << endl;
                cout << "3) MORSE." << endl;
                cout << "4) ATBASH." << endl;
                cout << "5) Return." << endl;
                cout << "YOUR CHOICE : ";
                cin >> choice;
                if (choice == "5")
                {
                    break;
                }
                else if (choice == "1")
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    baconian_cypher();
                }
                else if (choice == "2")
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    vignere_cypher();
                }
                else if (choice == "3")
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    morse_cypher();
                }
                else if (choice == "4")
                {

                    string choice;
                    string sent;
                    cout << "WELCOME USER, choose [1, 2, 3, 4]." << endl;
                    cout << "1) Version A_Z (Divide 1)." << endl;
                    cout << "2) Version A_M N_Z (Divide 2)." << endl;
                    cout << "3) Version A_B (Divide 13)." << endl;
                    cout << "4) Return ." << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (choice == "1")
                    {
                        cout << "ENTER THE SENTENCE YOU WANT TO ENCRYPT :" << endl;
                        getline(cin, sent);
                        for (int ss = 0; ss < sent.length(); ss++)
                        {
                            if (isalpha(sent[ss]))
                            {
                                sent[ss] = toupper(sent[ss]);
                                versionA_Z(string(1, sent[ss]));
                            }
                        }
                        cout << endl;
                    }
                    else if (choice == "2")
                    {
                        cout << "ENTER THE SENTENCE YOU WANT TO ENCRYPT :" << endl;
                        getline(cin, sent);
                        for (int ss = 0; ss < sent.length(); ss++)
                        {
                            if (isalpha(sent[ss]))
                            {
                                sent[ss] = toupper(sent[ss]);
                                version_2(string(1, sent[ss]));
                            }
                        }
                        cout << endl;
                    }
                    else if (choice == "3")
                    {
                        cout << "ENTER THE SENTENCE YOU WANT TO ENCRYPT :" << endl;
                        getline(cin, sent);
                        for (int ss = 0; ss < sent.length(); ss++)
                        {
                            if (isalpha(sent[ss]))
                            {
                                sent[ss] = toupper(sent[ss]);
                                version_13(string(1, sent[ss]));
                            }
                        }
                        cout << endl;
                    }
                    else if (choice == "4")
                    {
                    }
                    else
                    {
                        cout << "Invalid choice." << endl;
                    }
                }
                else
                {
                    cout << "Invalid choice." << endl;
                }
            }
        }
        else if (choice == "2")
        {
            while (true)
            {
                cout << "1) BACONIAN." << endl;
                cout << "2) VIGNERE." << endl;
                cout << "3) MORSE." << endl;
                cout << "4) ATBASH." << endl;
                cout << "5) Return." << endl;
                cout << "YOUR CHOICE : ";
                cin >> choice;
                if (choice == "5")
                {
                    break;
                }
                else if (choice == "1")
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    baconian_decryption();
                }
                else if (choice == "2")
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    vignere_decryption();
                }
                else if (choice == "3")
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    morse_decryption();
                }
                else if (choice == "4")
                {
                    string choice;
                    string sent;
                    cout << "WELCOME USER, choose [1, 2, 3, 4]." << endl;
                    cout << "1) Version A_Z (Divide 1)." << endl;
                    cout << "2) Version A_M N_Z (Divide 2)." << endl;
                    cout << "3) Version A_B (Divide 13)." << endl;
                    cout << "4) Return  ." << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (choice == "1")
                    {
                        cout << "ENTER THE SENTENCE YOU WANT TO DECRYPTION:" << endl;
                        getline(cin, sent);
                        for (int ss = 0; ss < sent.length(); ss++)
                        {
                            if (isalpha(sent[ss]))
                            {
                                sent[ss] = toupper(sent[ss]);
                                versionA_Z(string(1, sent[ss]));
                            }
                            else
                            {
                                cout << sent[ss];
                            }
                        }
                        cout << endl;
                    }
                    else if (choice == "2")
                    {
                        cout << "ENTER THE SENTENCE YOU WANT TO DECRYPTION :" << endl;
                        getline(cin, sent);
                        for (int ss = 0; ss < sent.length(); ss++)
                        {
                            if (isalpha(sent[ss]))
                            {
                                sent[ss] = toupper(sent[ss]);
                                version_2(string(1, sent[ss]));
                            }
                            else
                            {
                                cout << sent[ss];
                            }
                        }
                        cout << endl;
                    }
                    else if (choice == "3")
                    {
                        cout << "ENTER THE SENTENCE YOU WANT TO DECRYPTION :" << endl;
                        getline(cin, sent);
                        for (int ss = 0; ss < sent.length(); ss++)
                        {
                            if (isalpha(sent[ss]))
                            {
                                sent[ss] = toupper(sent[ss]);
                                version_13(string(1, sent[ss]));
                            }
                            else
                            {
                                cout << sent[ss];
                            }
                        }
                        cout << endl;
                    }
                    else if (choice == "4")
                    {
                    }
                    else
                    {
                        cout << "Invalid choice." << endl;
                    }
                }
            }
        }
        else
        {
            cout << "Please Enter a valid choice " << endl;
        }
    }
}