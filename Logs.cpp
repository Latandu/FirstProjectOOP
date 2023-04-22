#include <iostream>
#include "Logs.h"
#include "World.h"

using namespace std;

string Logs::text = "";
int Logs::loginumber = 0;

void Logs::AddComment(string komentarz)
{
    if (loginumber < 20) {
        text += komentarz + "\n";
        loginumber++;
    }
}

void Logs::PrintLogs()
{
    if (text == "")return;
    cout << text;
}

void Logs::ClearLogs()
{
    text = "";
    loginumber = 0;
}