#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "windowsHelper.h"


std::vector<std::vector<char>> pixels;
int width = 150;
int height = 40;


void Init() {
    for (int x = 0; x < width; ++x) 
    {
        pixels.push_back(std::vector<char>(height, ' '));
    }

    // Set number of columns and lines
    SetConsoleSize(width, height);

    // REMOVE RESIZE 
    RemoveResize();

    // Hide the cursor
    ShowConsoleCursor(false);
}

void Render() {
    // Clear the screen
    std::system("cls");;

    std::string buffer;

    for (int y = 0; y < height; ++y) {

        buffer += "\n";

        for (int x = 0; x < width; ++x) {
            buffer += pixels[x][y];
        }
    }

    std::cout << buffer << std::endl; 
}


void setPixel(int x, int y, char Character) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        pixels[x][y] = Character; // Access the character at (x, y) directly
    }
}

void rect(int xPos, int yPos, int w, int h) {
    // Draw the top and bottom borders
    for (int x = xPos; x < xPos + w; ++x) {
        setPixel(x, yPos, 196);
        setPixel(x, yPos + h-1, 196);
    }

    // Draw the left and right borders
    for (int y = yPos; y < yPos + h; ++y) {
        setPixel(xPos, y, 179);
        setPixel(xPos + w-1, y, 179);
    }

    setPixel(xPos, yPos, 218);
    setPixel(xPos + w-1, yPos, 191);
    setPixel(xPos, yPos + h-1, 192);
    setPixel(xPos + w-1, yPos + h-1, 217);



    // int num=100;
    // for (int x=0; x<width; x++){
    //         setPixel(x, 0, num);
    //         num+=1;
    // }

    //176░ 177▒ 178▓ 179│ 219█ 220▄ 221▌ 222▐ 223▀

}

void Text(int x, int y, std::string text) {
    for (int i=0; i<text.size(); ++i){
        setPixel(x + i, y, text[i]);
    }
}


int main() {
    Init();

    rect(0, 0, width-30, height-10);
    rect(0, height-10, width-30, 10);

    rect(width-30, 0, 30, 4);
    rect(width-30, 4, 30, 20);
    rect(width-30, 24, 30, height - 24);



    Text(width -25, 1, "LVL 1 Sir Lemon Drip");
    Text(width -23, 5, "~~ Quest Logs ~~");
    Text(width -23, 25, "~~ Inventory ~~");



    Render();

    // Handle resizing
    while (true) {

    }

    return 0;
}