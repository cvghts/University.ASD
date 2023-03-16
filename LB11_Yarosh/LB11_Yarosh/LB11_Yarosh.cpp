// LB11_Yarosh.cpp : Синхроний автомат

#include <iostream>
#include <string.h>
using namespace std;

char* Automat(char* S)
{
    enum conditions { A, B, C };
    conditions sit = A;
    for (int i = 0; i < strlen(S); i++)
        switch (sit)
        {
        case A: { if (S[i] == '0' || S[i] == '1') { S[i] = '0'; sit = C; } break; }
        case B: { if (S[i] == '1') sit = A; else sit = B; S[i] = '0'; break; }
        case C: { if (S[i] == '0' || S[i] == '1') sit = B; S[i] = '1'; break; }
        }
    return S;
}

int main()
{
    cout << "Enter the input sequence for the automaton (0 and 1):\n";
    char s[100];
    cin.getline(s, 100);
    puts("Output sequence:");
    puts(Automat(s));
}