#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<conio.h>

void gotoxy(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}
void setcursor(bool visible) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void draw_ship(int x, int y) {
	gotoxy(x, y);
	setcolor(6, 8);
	printf(" <-0-> ");
}
void draw_bullet(int x, int y) {
	gotoxy(x, y);
	printf(".");
}
void erase_bullet(int x, int y) {
	gotoxy(x, y);
	setcolor(7, 0);
	printf(" ");

}
void erase_ship(int x, int y) {
	gotoxy(x, y);
	setcolor(2, 0);
	printf("       ");
}
int main() {
	char ch = '.', bt = '.';
	int x = 38, y = 20;
	setcursor(0);
	draw_ship(x, y);
	int dir = 0; //go
	int index = -1;
	int bullet[6] = { 0 }; // 0 = off , 1 = on
	int keepx[6], keepy[6];
	int keep = 0;
	do {
		if (_kbhit()) {
			bt = _getch();
			if (bt == ' ' && keep < 5) {
				index++;
				bullet[index % 5] = 1;
				keepx[index % 5] = x + 3;
				keepy[index % 5] = y - 1;
				keep++;
			}
			else { ch = bt; }
		}
		if (ch == 'a') { dir = 1; }
		if (ch == 'd') { dir = 2; }
		if (ch == 's') { dir = 0; }
		if (bullet[0] == 1 && keepy[0] > 0) {
			erase_bullet(keepx[0], keepy[0]);
			draw_bullet(keepx[0], --keepy[0]);
			if (keepy[0] == 0) {
				Sleep(100);
				erase_bullet(keepx[0], keepy[0]);
				keep--;
				keepy[0] = 0;
			}
		}
		if (bullet[1] == 1 && keepy[1] > 0) {
			erase_bullet(keepx[1], keepy[1]);
			draw_bullet(keepx[1], --keepy[1]);
			if (keepy[1] == 0) {
				Sleep(100);
				erase_bullet(keepx[1], keepy[1]);
				keep--;
				keepy[1] = 0;
			}
		}
		if (bullet[2] == 1 && keepy[2] > 0) {
			erase_bullet(keepx[2], keepy[2]);
			draw_bullet(keepx[2], --keepy[2]);
			if (keepy[2] == 0) {
				Sleep(100);
				erase_bullet(keepx[2], keepy[2]);
				keep--;
				keepy[2] = 0;
			}
		}
		if (bullet[3] == 1 && keepy[3] > 0) {
			erase_bullet(keepx[3], keepy[3]);
			draw_bullet(keepx[3], --keepy[3]);
			if (keepy[3] == 0) {
				Sleep(100);
				erase_bullet(keepx[3], keepy[3]);
				keep--;
				keepy[3] = 0;
			}
		}
		if (bullet[4] == 1 && keepy[4] > 0) {
			erase_bullet(keepx[4], keepy[4]);
			draw_bullet(keepx[4], --keepy[4]);
			if (keepy[4] == 0) {
				Sleep(100);
				erase_bullet(keepx[4], keepy[4]);
				keep--;
				keepy[4] = 0;
			}
		}
		if (x > 0 && x < 75) {
			if (dir == 0);
			else if (dir == 1) {
				erase_ship(x, y);
				draw_ship(--x, y);
				Sleep(20);
			}
			else {
				erase_ship(x, y);
				draw_ship(++x, y);
				Sleep(20);
			}
		}
		if (ch == 'a' && x == 75) {
			erase_ship(x, y);
			draw_ship(--x, y);
			Sleep(20);
		}
		if (ch == 'd' && x == 0) {
			erase_ship(x, y);
			draw_ship(++x, y);
			Sleep(20);
		}
		fflush(stdin);
		Sleep(50);
	} while (ch != 'x');
	return 0;
}