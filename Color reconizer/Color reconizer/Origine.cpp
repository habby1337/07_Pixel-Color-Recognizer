#include <conio.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;
int main()
{
	int x, y, r, g, b;
	x = 1;
	y = 1;
	int hrz = 0;
	int vert = 0;
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	hrz = desktop.right;
	vert = desktop.bottom;
	cout << "R value=";
	cin >> r;
	cout << endl << "G value=";
	cin >> g;
	cout << endl << "B value=";
	cin >> b;

	while (true)
	{
		cout << x << y;
		x += 3;
		if (x == hrz - 1)
		{
			y += 3;
		}
		if (x == hrz - 1)
		{
			x = 1;
		}
		if (y == vert - 1)
		{
			y = 1;
		}
		HDC hdc = GetDC(NULL);
		COLORREF color = GetPixel(hdc, x, y);
		COLORREF colorWanted = RGB(r, g, b);
		if (color == colorWanted)
		{
			mouse_event(MOUSEEVENTF_MOVE, x, y, 0, 0);
			mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			Sleep(100000);
		}
	}
	return 0;
}