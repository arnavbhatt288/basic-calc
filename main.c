/*
* Program: Calculator V0.5
*	
* Copyright Arnav Bhatt 2019
*/

#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include "resource.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
 	int len;
    static char* buf = NULL;
	static char symbol = ' ';
	char sAns[256];
	static double num = 0;
	static double num1 = 0;
	double ans;
	switch(Message)
    {
        case WM_INITDIALOG:
			SetDlgItemText(hwnd, IDE_DISPLAY, "0");
			SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON_SMALL)));
			SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));
		break;

        case WM_COMMAND:
        	len = GetWindowTextLength(GetDlgItem(hwnd, IDE_DISPLAY));
			buf = (char*)GlobalAlloc(GPTR, len + 1);
			GetDlgItemText(hwnd, IDE_DISPLAY, buf, len + 1);
			
			HWND hEdit = GetDlgItem(hwnd, IDE_DISPLAY);
			
			switch(LOWORD(wParam))
            {
				case IDB_0:
					if(strcmp(buf, "0") == 0)
						SetDlgItemText(hwnd, IDE_DISPLAY, "0");

					else
					{
   						SetFocus(hEdit);
   						SendMessageA(hEdit, EM_SETSEL, (WPARAM)len, (LPARAM)len);
   						SendMessageA(hEdit, EM_REPLACESEL, 0, (LPARAM)"0"); 
					}
				break;

				case IDB_1:
					if(strcmp(buf, "0") == 0)
						SetDlgItemText(hwnd, IDE_DISPLAY, "1");

					else
					{
   						SetFocus(hEdit);
   						SendMessageA(hEdit, EM_SETSEL, (WPARAM)len, (LPARAM)len);
   						SendMessageA(hEdit, EM_REPLACESEL, 0, (LPARAM)"1"); 
					}
				break;

				case IDB_2:
					if(strcmp(buf, "0") == 0)
						SetDlgItemText(hwnd, IDE_DISPLAY, "2");

					else
					{
   						SetFocus(hEdit);
   						SendMessageA(hEdit, EM_SETSEL, (WPARAM)len, (LPARAM)len);
   						SendMessageA(hEdit, EM_REPLACESEL, 0, (LPARAM)"2"); 
					}
				break;	
		
				case IDB_3:
					if(strcmp(buf, "0") == 0)
						SetDlgItemText(hwnd, IDE_DISPLAY, "3");

					else
					{
   						SetFocus(hEdit);
   						SendMessageA(hEdit, EM_SETSEL, (WPARAM)len, (LPARAM)len);
   						SendMessageA(hEdit, EM_REPLACESEL, 0, (LPARAM)"3"); 
					}
				break;

				case IDB_4:
					if(strcmp(buf, "0") == 0)
						SetDlgItemText(hwnd, IDE_DISPLAY, "4");

					else
					{
   						SetFocus(hEdit);
   						SendMessageA(hEdit, EM_SETSEL, (WPARAM)len, (LPARAM)len);
   						SendMessageA(hEdit, EM_REPLACESEL, 0, (LPARAM)"4"); 
					}
				break;

				case IDB_5:
					if(strcmp(buf, "0") == 0)
						SetDlgItemText(hwnd, IDE_DISPLAY, "5");

					else
					{
   						SetFocus(hEdit);
   						SendMessageA(hEdit, EM_SETSEL, (WPARAM)len, (LPARAM)len);
   						SendMessageA(hEdit, EM_REPLACESEL, 0, (LPARAM)"5"); 
					}
				break;

				case IDB_6:
					if(strcmp(buf, "0") == 0)
						SetDlgItemText(hwnd, IDE_DISPLAY, "6");

					else
					{
   						SetFocus(hEdit);
   						SendMessageA(hEdit, EM_SETSEL, (WPARAM)len, (LPARAM)len);
   						SendMessageA(hEdit, EM_REPLACESEL, 0, (LPARAM)"6"); 
					}
				break;

				case IDB_7:
					if(strcmp(buf, "0") == 0)
						SetDlgItemText(hwnd, IDE_DISPLAY, "7");

					else
					{
   						SetFocus(hEdit);
   						SendMessageA(hEdit, EM_SETSEL, (WPARAM)len, (LPARAM)len);
   						SendMessageA(hEdit, EM_REPLACESEL, 0, (LPARAM)"7"); 
					}
				break;

				case IDB_8:
					if(strcmp(buf, "0") == 0)
						SetDlgItemText(hwnd, IDE_DISPLAY, "8");

					else
					{
   						SetFocus(hEdit);
   						SendMessageA(hEdit, EM_SETSEL, (WPARAM)len, (LPARAM)len);
   						SendMessageA(hEdit, EM_REPLACESEL, 0, (LPARAM)"8"); 
					}
				break;

				case IDB_9:
					if(strcmp(buf, "0") == 0)
						SetDlgItemText(hwnd, IDE_DISPLAY, "9");

					else
					{
   						SetFocus(hEdit);
   						SendMessageA(hEdit, EM_SETSEL, (WPARAM)len, (LPARAM)len);
   						SendMessageA(hEdit, EM_REPLACESEL, 0, (LPARAM)"9"); 
					}
				break;

				case IDB_DECIMAL:
   					SetFocus(hEdit);
   					SendMessageA(hEdit, EM_SETSEL, (WPARAM)len, (LPARAM)len);
   					SendMessageA(hEdit, EM_REPLACESEL, 0, (LPARAM)".");
				break;
				
				case IDB_C:
					SetDlgItemText(hwnd, IDE_DISPLAY, "0");
					num = 0;
					num1 = 0;
					symbol = ' ';
				break;

				case IDB_PLUS:
					symbol = '+';
					num = atof(buf);
					SetDlgItemText(hwnd, IDE_DISPLAY, "0");
				break;

				case IDB_MINUS:
					symbol = '-';
					num = atof(buf);
					SetDlgItemText(hwnd, IDE_DISPLAY, "0");
				break;

				case IDB_MULTIPLY:
					symbol = '*';
					num = atof(buf);
					SetDlgItemText(hwnd, IDE_DISPLAY, "0");
				break;

				case IDB_DIVIDE:
					symbol = '/';
					num = atof(buf);
					SetDlgItemText(hwnd, IDE_DISPLAY, "0");
				break;

				case IDB_EQUAL:
					num1 = atof(buf);
					switch(symbol)
					{
						case '+':
							ans = num + num1;
						break;

						case '-':
							ans = num - num1;
						break;
						
						case '*':
							ans = num * num1;
						break;

						case '/':
							if(num1 == 0)
							{
								SetDlgItemText(hwnd, IDE_DISPLAY, "Cannot divide by zero");
								return 1;
							}
							else
								ans = num / num1;
						break;
					}
					
					snprintf(sAns, 256, "%f", ans);
					SetDlgItemText(hwnd, IDE_DISPLAY, sAns);
				break;
			}
        break;
		case WM_CLOSE:
			GlobalFree(buf);
			memset(sAns, 0, sizeof sAns);
			EndDialog(hwnd, 0);
        default:
            return FALSE;
    }
    return TRUE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    LPSTR lpCmdLine, int nCmdShow)
{
    return DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN), NULL, DlgProc);
}
