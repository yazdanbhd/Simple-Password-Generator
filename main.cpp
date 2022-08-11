#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

char getRandomChar(const char*, int);
int main()
{
    int passwordLength = 0;
    const char passwordTemplate[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                     "~`[]{}|;':,./<>?"
                                     "abcdefghijklmnopqrstuvwxyz"
                                     "1234567890!@#$%^&*()_+=-";

    int passwordTemplateLength = sizeof(passwordTemplate) - 1;
    cout << "Enter Password length: ";
    cin >> passwordLength;
    srand(time(NULL));
    if (passwordLength < 1)
    {
        cout << "Password length must be greater than 0." << endl;
        return 0;
    }
    cout << "Password: ";
    char randomChar;
    string password;
    for (int i = 0; i < passwordLength; i++)
    {
        randomChar = getRandomChar(passwordTemplate, passwordTemplateLength);
        password += randomChar;
    }
    cout << password << endl;
    return 0;
}
char getRandomChar(const char* Template, int templateLength)
{
    return Template[rand() % templateLength];
}