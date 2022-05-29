#include<iostream>
#include<regex>
#include<string>
using namespace std;

int main() {
    string json;
    string text[6];
    string username;
    string password;
    string email;
    json.begin();
    getline(cin, json);
    int a = 0;
    int tmp = 0;
    for (auto i = json.begin(); i != json.end(); i++) {
        if (*i == '"' && tmp == 0) {
            tmp = 1;
            continue;
        }
        if (*i == '"' && tmp == 1) {
            tmp = 0; a++;
            continue;
        }
        if (tmp == 1) {
            text[a] += *i;
        }
    }
    for (int i = 0; i < 6; i += 2) {
        if (text[i] == "username") username = text[i + 1];
        if (text[i] == "password") password = text[i + 1];
        if (text[i] == "email") email = text[i + 1];
    }
    regex name(R"(^[a-zA-Z]\w{3,14}$)");
    regex pass(R"((?![0-9]+$)(?![a-zA-Z]+$)[0-9A-Za-z]{8,20})");
    regex ema(R"([a-zA-Z0-9_]+@[a-zA-Z0-9_]{0,}(\.[a-zA-Z0-9_]{0,}){0,})");
    bool s[3] = { 0 };
    if (!regex_match(username, name)) s[0] = true;
    if (!regex_match(password, pass)) s[1] = true;
    if (!regex_match(email, ema)) s[2] = true;
    if (s[0] == true || s[1] == true || s[2] == true) {
        int x = 0;
        cout << "Illegal ";
        if (s[0] == true) {
            cout << "username";
            x++;
        }
        if (s[1] == true) {
            if (x == 0) {
                cout << "password";
                x++;
            }
            else cout << ",password";
        }
        if (s[2] == true) {
            if (x == 0) cout << "email";
            else cout << ",email";
        }
        return 0;
    }
    int x = 0;
    cout << "Successfully registered." << endl;
    cout << "username: ";
    for (auto i = username.begin(); i != username.end(); i++) {
        if (x > 2) cout << "*";
        else {
            cout << *i;
            x++;
        }
    }
    cout << endl;
    cout << "password: ";
    for (auto i = password.begin(); i != password.end(); i++) cout << '*';
    cout << endl;
    cout << "email: ";
    for (auto i = email.begin(); i != email.end(); i++) {
        if ((*i == '@') || (*i == '.')) cout << *i;
        else cout << '*';
    }
}