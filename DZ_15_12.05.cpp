#include <iostream>
#include <string>
#include <locale> // для русской локали

using namespace std;

string addParentheses(const string& str, const string& substr) 
{
    string result = str;
    size_t pos = result.find(substr, 0); // находим первое вхождение подстроки в строке

    while (pos != string::npos) 
    {
        result.insert(pos, "("); // вставляем открывающую скобку перед подстрокой
        result.insert(pos + substr.length() + 1, ")"); // вставляем закрывающую скобку после подстроки
        pos = result.find(substr, pos + substr.length() + 2); // находим следующее вхождение подстроки
    }

    return result;
}

int main() 
{
    setlocale(LC_ALL, "Russian"); // установка русской локали

    string str = "abracadabra";
    string substr = "ab";

    string result = addParentheses(str, substr);
    cout << result << endl;

    return 0;
}