//
// Created by Latandu on 22/04/2023.
//

#ifndef FIRSTPROJECT_LOGS_H
#define FIRSTPROJECT_LOGS_H
#include <iostream>

using namespace std;

class Logs
{
public:
    static void AddComment(string komentarz);
    static void PrintLogs();
    static void ClearLogs();
protected:
    static string text;
    static int loginumber;


};
#endif //FIRSTPROJECT_LOGS_H
