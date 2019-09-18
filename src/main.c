/*
* Program: Calculator v1.0
*
* Copyright Arnav Bhatt 2019
*/

#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <strsafe.h>
#include "resource.h"

HMENU hMenu, hSubMenu;

BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch(Message)
    {
        case WM_INITDIALOG:

        return TRUE;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case IDOK:
                    EndDialog(hwnd, IDOK);
                break;
            }
        break;
        default:
            return FALSE;
    }
    return TRUE;
}

BOOL CALLBACK MainDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
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

            hMenu = CreateMenu();

            hSubMenu = CreatePopupMenu();
			AppendMenu(hSubMenu, MF_STRING, ID_FILE_ABOUT, "&About");;
            AppendMenu(hSubMenu, MF_STRING, ID_FILE_EXIT, "E&xit");
            AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&File");

            SetMenu(hwnd, hMenu);			

			SetDlgItemText(hwnd, IDE_DISPLAY, "0");
			
			SendMessage(GetDlgItem(hwnd, IDE_DISPLAY), EM_LIMITTEXT, (WPARAM)28, 0); 
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
					
					int ians = (int)ans;

					if(ans - ians == 0)
						StringCchPrintfA(sAns, sizeof(sAns), "%i", ians);
					else
						StringCchPrintfA(sAns, sizeof(sAns), "%f", ans);
					
					SetDlgItemText(hwnd, IDE_DISPLAY, sAns);
				break;

				case ID_FILE_ABOUT:
					DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_ABOUT), hwnd, AboutDlgProc);
				break;

				case ID_FILE_EXIT:
					GlobalFree(buf);
					memset(sAns, 0, sizeof sAns);
					EndDialog(hwnd, 0);
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
    return DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN), NULL, MainDlgProc);
}
