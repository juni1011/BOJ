#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        int a = 0, b = 0, c = 0, d = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= 'a' && str[i] <= 'z') a++;
		    else if (str[i] >= 'A' && str[i] <= 'Z') b++;
		    else if (str[i] >= '0' && str[i] <= '9') c++;
		    else if (str[i] == ' ') d++;
        }
        
        cout << a << " " << b << " " << c << " " << d << '\n';
    }

    return 0;
}
