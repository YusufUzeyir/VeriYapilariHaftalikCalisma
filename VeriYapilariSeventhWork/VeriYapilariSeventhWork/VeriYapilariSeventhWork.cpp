#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// Bir karakterin bir operatör olup olmadığını kontrol eder
bool operetorKontrol(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Bir karakterin operand (yani rakam veya harf) olup olmadığını kontrol eder
bool operandKontrol(char c) {
    return (isalpha(c) || isdigit(c));
}

// Bir karakterin operatör önceliğini belirler
int islemOnceligi(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else if (c == '^') {
        return 3;
    }
    else {
        return 0;
    }
}

// Infixi postfixe çevirme 
string postfixeCevir(string infix) {
    stack<char> operatorYigini;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (operandKontrol(c)) {
            postfix += c;
        }
        else if (operetorKontrol(c)) {
            while (!operatorYigini.empty() && operatorYigini.top() != '(' &&
                islemOnceligi(operatorYigini.top()) >= islemOnceligi(c)) {
                postfix += operatorYigini.top();
                operatorYigini.pop();
            }

            operatorYigini.push(c);
        }
        else if (c == '(') {
            operatorYigini.push(c);
        }
        else if (c == ')') {
            while (!operatorYigini.empty() && operatorYigini.top() != '(') {
                postfix += operatorYigini.top();
                operatorYigini.pop();
            }

            operatorYigini.pop();
        }
    }

    while (!operatorYigini.empty()) {
        postfix += operatorYigini.top();
        operatorYigini.pop();
    }

    return postfix;
}

// Postfixi infixe çevirme
string infixeCevir(string postfix) {
    stack<string> ifadeYigini;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isalnum(c)) {
            string operand(1, c);
            ifadeYigini.push(operand);
        }
        else {
            string operand2 = ifadeYigini.top();
            ifadeYigini.pop();
            string operand1 = ifadeYigini.top();
            ifadeYigini.pop();
            string ifade = "(" + operand1 + c + operand2 + ")";
            ifadeYigini.push(ifade);
        }
    }

    return ifadeYigini.top();
}

// Infix ifadeyi prefixe dönüştürür
string prefixeCevir(string infix) {
    // infix ifadeyi tersine çevirme
    reverse(infix.begin(), infix.end());

    // parantezlerin yerini değiştirme
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }

    // infix ifadeyi postfixe dönüştürme
    string postfix = postfixeCevir(infix);

    // postfix ifadeyi tersine çevirme
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main()
{
    int secim;
    string ifade;

    do {
        cout << "Hangi islemi yapmak istersiniz?" << endl;
        cout << "1. Infix ifadeyi postfixe donustur" << endl;
        cout << "2. Postfix ifadeyi infixe donustur" << endl;
        cout << "3. Ornekteki infix ifadeyi postfixe donustur" << endl;
        cout << "4. Ornekteki ifadeyi prefixe donustur" << endl;
        cout << "0. Cik" << endl;
        cin >> secim;

        switch (secim) {
        case 1:
            cout << "Infix ifadeyi giriniz: ";
            cin >> ifade;
            cout << "Postfix ifade: " << postfixeCevir(ifade) << endl;
            break;
        case 2:
            cout << "Postfix ifadeyi giriniz: ";
            cin >> ifade;
            cout << "Infix ifade: " << infixeCevir(ifade)<< endl;
            break;
        case 3:
            ifade = "a+(b*c(d/e^f)*g)*h";
            cout << "Infix ifade: " << ifade << endl;
            cout << "Postfix ifade: " << postfixeCevir(ifade) << endl;
            break;
        case 4:
            ifade = " (a / b + c) - ( d + e * f)";
            cout << "Infix ifade: " << ifade << endl;
            cout << "Prefix ifade: " << prefixeCevir(ifade) << endl;
            break;
        case 0:
            cout << "Programdan cikiliyor" << endl;
            break;
        default:
            cout << "Hatali secim, lutfen tekrar deneyin" << endl;
        }
    } while (secim != 0);
    return 0;
}
    
