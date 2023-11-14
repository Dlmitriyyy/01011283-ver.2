#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

void encrypted(string& InputText, string& EncryptedText)
{
    map <char, string> newAlphabet =
    {
        {'a', "AAAAA"}, {'b', "AAAAB"}, {'c', "AAABA"}, {'d', "AAABB"},
        {'e', "AABAA"}, {'f', "AABAB"}, {'g', "AABBA"}, {'h', "AABBB"},
        {'i', "ABAAA"}, {'j', "ABAAB"}, {'k', "ABABA"}, {'l', "ABABB"},
        {'m', "ABBAA"}, {'n', "ABBAB"}, {'o', "ABBBA"}, {'p', "ABBBB"},
        {'q', "BAAAA"}, {'r', "BAAAB"}, {'s', "BAABA"}, {'t', "BAABB"},
        {'u', "BABAA"}, {'v', "BABAB"}, {'w', "BABBA"}, {'x', "BABBB"},
        {'y', "BBAAA"}, {'z', "BBAAB"}
    };

    string TextWithoutSpaces = InputText;
    size_t PosSpace = TextWithoutSpaces.find(' ');

    while (PosSpace != string::npos)
    {
        TextWithoutSpaces.erase(PosSpace, 1);
        PosSpace = TextWithoutSpaces.find(' ', PosSpace);
    }

    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl << "Функція шифрування: " << endl;
    cout << endl << "1) Введений текст без пробілів: " << TextWithoutSpaces << endl << endl;
    cout << "2) Введений текст без пробілів перетворений у нижній регістр: ";

    for (char a : TextWithoutSpaces)
    {
        char SmallLetters = tolower(a);
        cout << SmallLetters;
    }

    cout << endl << endl << "3) Зашифрований текст шифром Бекона: ";

    for (char a : TextWithoutSpaces)
    {
        char SmallLetters = tolower(a);

        if (isalpha(SmallLetters))
        {
            EncryptedText += newAlphabet[SmallLetters] + " ";
        }
        else
        {

        }
    }
    cout << EncryptedText;
    cout << endl << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
}

void decrypted(string& InputText, string& EncryptedText, string& DecryptedText)
{
    map<string, char> reverseAlphabet =
    {
        {"AAAAA", 'a'}, {"AAAAB", 'b'}, {"AAABA", 'c'}, {"AAABB", 'd'},
        {"AABAA", 'e'}, {"AABAB", 'f'}, {"AABBA", 'g'}, {"AABBB", 'h'},
        {"ABAAA", 'i'}, {"ABAAB", 'j'}, {"ABABA", 'k'}, {"ABABB", 'l'},
        {"ABBAA", 'm'}, {"ABBAB", 'n'}, {"ABBBA", 'o'}, {"ABBBB", 'p'},
        {"BAAAA", 'q'}, {"BAAAB", 'r'}, {"BAABA", 's'}, {"BAABB", 't'},
        {"BABAA", 'u'}, {"BABAB", 'v'}, {"BABBA", 'w'}, {"BABBB", 'x'},
        {"BBAAA", 'y'}, {"BBAAB", 'z'}
    };

    vector<int>SpacePositions;

    for (int a = 0; a < InputText.length(); a++)
    {
        if (InputText[a] == ' ')
        {
            SpacePositions.push_back(a);
        }
    }

    vector<int>BigLettersPosition;

    for (size_t b = 0; b < InputText.length(); b++)
    {
        if (isupper(InputText[b]))
        {
            BigLettersPosition.push_back(b);
        }
    }
    string EncryptedTextWithoutSpaces = EncryptedText;
    size_t PosSpace = EncryptedTextWithoutSpaces.find(' ');

    while (PosSpace != string::npos)
    {
        EncryptedTextWithoutSpaces.erase(PosSpace, 1);
        PosSpace = EncryptedTextWithoutSpaces.find(' ', PosSpace);
    }
    cout << endl << "Функція розшифрування: " << endl;
    string DecryptedTextWithoutSpaces;
    cout << endl << "1) Зашифрований текст шифром Бекона: " << EncryptedText << endl;
    cout << endl << "2) Розшифрований текст без пробілів: ";

    for (size_t Pos = 0; Pos < EncryptedTextWithoutSpaces.length(); Pos += 5)
    {
        string PartText = EncryptedTextWithoutSpaces.substr(Pos, 5);

        if (reverseAlphabet.find(PartText) != reverseAlphabet.end())
        {
            DecryptedTextWithoutSpaces += reverseAlphabet[PartText];
        }

        else if (EncryptedTextWithoutSpaces[Pos] == ' ')
        {
            DecryptedTextWithoutSpaces += ' ';
        }
        else
        {

        }
    }

    DecryptedText = DecryptedTextWithoutSpaces;

    for (int a = 0; a < SpacePositions.size(); a++)
    {
        DecryptedText = DecryptedText.insert(SpacePositions[a], " ");
    }

    string OriginalText = DecryptedText;

    for (size_t b = 0; b < BigLettersPosition.size(); ++b)
    {
        OriginalText[BigLettersPosition[b]] = toupper(OriginalText[BigLettersPosition[b]]);
    }

    cout << DecryptedTextWithoutSpaces << endl;
    cout << endl << "3) Розшифрований текст з пробілами: " << DecryptedText << endl;
    cout << endl << "4) Розшифрований текст приведений до оригінального регістру: " << OriginalText;
    cout << endl << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
}

int main()
{
    system("chcp 1251 > nul");
    cout << "Цей код для шифрування введеного користувачем тексту методом Бекона, виводить покроково як відбувається шифрування, та  розшифровує у зворотньому порядку. " << endl << endl;

    string InputText, TempText, EncryptedText, DecryptedText;

    do
    {
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Введіть текст який треба зашифрувати: ";
        getline(cin, TempText);

        bool TextValid = true;

        for (char letter : TempText)
        {
            if (!isalpha(letter) && !isspace(letter))
            {
                cout << endl << "Помилка, введений текст може містити тільки букви англійського алфавіта та пробіли. Спробуйте ще раз: " << endl << endl;
                cin.clear();
                TextValid = false;
                break;
            }
        }

        if (TextValid)
        {
            InputText = TempText;
            break;
        }
    }

    while (true);

    encrypted(InputText, EncryptedText);
    decrypted(InputText, EncryptedText, DecryptedText);

    return 0;
}