#include <iostream>
#include <string>

using namespace std;

bool solution(string);

int main()
{
    string s = "[(({[])})]";
    
    s.erase(0, 1);
    cout << s << '\n';
    cout << solution(s);
}

bool solution(string s) {
    int size = s.size();
    if (size % 2 != 0) return false;
    
    return true;
}