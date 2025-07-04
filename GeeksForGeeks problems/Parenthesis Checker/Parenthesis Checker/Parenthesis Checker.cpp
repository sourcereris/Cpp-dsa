#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool solution(string&);

int main()
{
    string s = "[({}((){([])})())]";
    
    //s.erase(0, 1);
    cout << s << '\n';
    cout << solution(s);
}

bool solution(string& s) {
    int size = s.size();
    if (size % 2 != 0) return false;
    stack<char> sc;

    for (char ch : s) {

        if (ch == '(' || ch == '[' || ch == '{') sc.push(ch);
        else {
            if (sc.empty()) return false;
            char top = sc.top();
            if (ch == ']' && top == '[' 
             || ch == ')' && top == '('
             || ch == '}' && top == '{')
                sc.pop();
            else return false;
        }
    }
    return sc.empty();
}