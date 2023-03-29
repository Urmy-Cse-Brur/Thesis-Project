#include<bits/stdc++.h>
#include <bitset>
using namespace std;


vector<int> parseNumber(int start) {
    int number;
    vector<int> token (1, start);
    while (isdigit(cin.peek())) {
        number = getchar();
        token.push_back(number);
    }
    return token;
}


bool isword(int inch) {
    if (isalnum(inch))      return true;
    else if (inch == '_')   return true;
    else                    return false;
}


vector<int> parseWord(int start) {
    int word;
    vector<int> token (1, start);
    while (isword(cin.peek())) {
        word = getchar();
        token.push_back(word);
    }
    return token;
}


vector<int> parseComment(int start) {
    int comment;
    vector<int> token (1, start);
    if (cin.peek() == '/') {
        comment = getchar();
        token.push_back(comment);
        while ((comment = getchar()) != '\n') {
            token.push_back(comment);
        }
    } else if (cin.peek() == '*') {
        comment = getchar();
        token.push_back(comment);
        PARSING_COMMENT: while ((comment = getchar()) != '*') {
            token.push_back(comment);
        }
        if (cin.peek() == '/') {
            token.push_back(comment);
            comment = getchar();
            token.push_back(comment);
        } else {
            token.push_back(comment);
            goto PARSING_COMMENT;
        }
    }
    return token;
}


vector<int> parseSentence(int start) {
    int sentence;
    vector<int> token (1, start);
    PARSING_SENTENCE: while ((sentence = getchar()) != start) {
        token.push_back(sentence);
    }
    if (token.back() == '\\' && token[token.size() - 2] != '\\') {
        token.push_back(sentence);
        goto PARSING_SENTENCE;
    }
    token.push_back(sentence);
    return token;
}


void parse_error(string message, char ch) {
    cerr << message << ": " << ch;
}


vector<int> getToken() {
    vector<int> token;
    int inch = 0;
    while ((inch = getchar()) != EOF) {
        switch (inch) {
            case '\t':
            case '\n':
            case '\r':
            case ' ':
                break;
            case '#':
            case '<':
            case '>':
            case '.':
            case ',':
            case '*':
            case '=':
            case '!':
            case '(':
            case ')':
            case '[':
            case ']':
            case '{':
            case '}': 
            case ';':
            case '\\':
                token.push_back(inch);
                return token;
            case '+':
            case '-':
            case ':':
            case '|':
            case '&':
                token.push_back(inch);
                if (cin.peek() == inch) {
                    inch = getchar();
                    token.push_back(inch);
                }
                return token;
            case '/':
                token = parseComment(inch);
                if (token.size() == 1) { return token; }
                else { token.clear(); continue; }
            case '\'':
            case '\"':
                return parseSentence(inch);
            default:
                if (isdigit(inch)) {
                    return parseNumber(inch);
                } else if (isword(inch)) {
                    return parseWord(inch);
                } else {
                    parse_error("Illegal character", inch);
                }
        }
    }
    return token;
}


void printTokens()
{
    cout << "-------------------------" << endl;
    vector<int> token;
    while((token = getToken()).size() != 0) {
        for (int i = 0; i < token.size(); i++) {
            cout << char(token[i]);
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;
}


int main()
{
    printTokens();
}
using namespace std;


vector<int> parseNumber(int start) {
    int number;
    vector<int> token (1, start);
    while (isdigit(cin.peek())) {
        number = getchar();
        token.push_back(number);
    }
    return token;
}


bool isword(int inch) {
    if (isalnum(inch))      return true;
    else if (inch == '_')   return true;
    else                    return false;
}


vector<int> parseWord(int start) {
    int word;
    vector<int> token (1, start);
    while (isword(cin.peek())) {
        word = getchar();
        token.push_back(word);
    }
    return token;
}


vector<int> parseComment(int start) {
    int comment;
    vector<int> token (1, start);
    if (cin.peek() == '/') {
        comment = getchar();
        token.push_back(comment);
        while ((comment = getchar()) != '\n') {
            token.push_back(comment);
        }
    } else if (cin.peek() == '*') {
        comment = getchar();
        token.push_back(comment);
        PARSING_COMMENT: while ((comment = getchar()) != '*') {
            token.push_back(comment);
        }
        if (cin.peek() == '/') {
            token.push_back(comment);
            comment = getchar();
            token.push_back(comment);
        } else {
            token.push_back(comment);
            goto PARSING_COMMENT;
        }
    }
    return token;
}


vector<int> parseSentence(int start) {
    int sentence;
    vector<int> token (1, start);
    PARSING_SENTENCE: while ((sentence = getchar()) != start) {
        token.push_back(sentence);
    }
    if (token.back() == '\\' && token[token.size() - 2] != '\\') {
        token.push_back(sentence);
        goto PARSING_SENTENCE;
    }
    token.push_back(sentence);
    return token;
}


void parse_error(string message, char ch) {
    cerr << message << ": " << ch;
}


vector<int> getToken() {
    vector<int> token;
    int inch = 0;
    while ((inch = getchar()) != EOF) {
        switch (inch) {
            case '\t':
            case '\n':
            case '\r':
            case ' ':
                break;
            case '#':
            case '<':
            case '>':
            case '.':
            case ',':
            case '*':
            case '=':
            case '!':
            case '(':
            case ')':
            case '[':
            case ']':
            case '{':
            case '}': 
            case ';':
            case '\\':
                token.push_back(inch);
                return token;
            case '+':
            case '-':
            case ':':
            case '|':
            case '&':
                token.push_back(inch);
                if (cin.peek() == inch) {
                    inch = getchar();
                    token.push_back(inch);
                }
                return token;
            case '/':
                token = parseComment(inch);
                if (token.size() == 1) { return token; }
                else { token.clear(); continue; }
            case '\'':
            case '\"':
                return parseSentence(inch);
            default:
                if (isdigit(inch)) {
                    return parseNumber(inch);
                } else if (isword(inch)) {
                    return parseWord(inch);
                } else {
                    parse_error("Illegal character", inch);
                }
        }
    }
    return token;
}


void printTokens()
{
    cout << "-------------------------" << endl;
    vector<int> token;
    while((token = getToken()).size() != 0) {
        for (int i = 0; i < token.size(); i++) {
            cout << char(token[i]);
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;
}


int main()
{
    printTokens();
}
