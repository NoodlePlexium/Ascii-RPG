#include <windows.h>
#include <string>


// Function to hide or show the console cursor
void ShowConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // Set the cursor visibility

    SetConsoleCursorInfo(out, &cursorInfo);
}


void setColour(int textColor, int backgroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = textColor + (backgroundColor << 4);
    SetConsoleTextAttribute(hConsole, color);
}

void SetConsoleSize(int width, int height) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set the screen buffer size to change the number of columns and lines
    COORD newSize;
    newSize.X = width; // Number of columns
    newSize.Y = height+1; // Number of lines
    SetConsoleScreenBufferSize(hConsole, newSize);

    // Set the window size to match the screen buffer size
    SMALL_RECT rect;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = width-1; // Number of columns - 1
    rect.Bottom = height; // Number of lines - 1
    SetConsoleWindowInfo(hConsole, TRUE, &rect);
}

void RemoveResize() {
	HWND console = GetConsoleWindow();
    SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

