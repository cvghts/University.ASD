// LB12_Yarosh.cpp : Асинхронні автомати

#include <iostream>
#include <string.h>
using namespace std;

string Assinhr(char* S, string T)
{
	enum conditions { A, B, C };
	conditions sit = A;
	for (int i = 0; i < strlen(S); i++)
		switch (sit)
		{
		case A: { if (S[i] == '1') { T.append("010"); }
			  else { T.append("10"); }
			  sit = C;
			  break;
		}
		case B: { if (S[i] == '1') { T.append("101"); }
			  sit = A;
			  break;
		}
		case C: { if (S[i] == '1') { sit = B; }
			  else { sit = A; T.append("01"); }
			  break;
		}
		}
	return T;
}

int main()
{
	cout << "Enter the input sequence for the automaton (0 and 1):\n";
	char s1[100];
	string T;
	cin.getline(s1, 100);
	puts("Output sequence:");
	cout << Assinhr(s1, T);
}


