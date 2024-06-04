// keeping track of the path taken by the mouse in the maze
// using a multidimentional array
// Dylan Strnad
// 4/24/2024

#include <cmath>
#include <iostream>
using std::cout; using std::cin; using std::endl;

// maze dimensions
const int mazeLength = 7;
const int mazeWidth = 7;

int main() {

    int mouseX = 0; // current mouse X index
    int mouseY = 0; // current mouse Y index

    bool maze[mazeLength][mazeWidth]; // declare mouse maze tracking array

    for (int i = 0; i < mazeLength; ++i) {   // intializes array to false
        for (int j = 0; j < mazeWidth; ++j)
            maze[i][j] = false;
    }

    maze[mouseX][mouseY] = true;  // place mouse in the top-left corner



   char direction = ' ';
   while (direction != 'q') {

        cout << "  a b c d e f g" << endl;   // columns
        
        // prints maze row by row
        for (int i = 0; i < mazeLength; ++i) {
            cout << i + 1 << ' ';  // prints rows

            for (int j = 0; j < mazeWidth; ++j) {

                if (maze[i][j] == true)
                    cout << '*' << ' ';  // prints * to track location
                else
                    cout << ' ' << ' ';  // leaves space blank
            }
            cout << endl;
        }

        
        cout << "Enter direction (l)eft, (r)ight, (u)p, (d)own or (q)uit:";
        cin >> direction;

        // tracks movement
        if (direction == 'l' && mouseY > 0) {
            mouseY -= 1;
            maze[mouseX][mouseY] = true;

        } else if (direction == 'r' && mouseY < mazeWidth - 1) {
            mouseY += 1;
            maze[mouseX][mouseY] = true;

        } else if (direction == 'u' && mouseX > 0) {
            mouseX -= 1;
            maze[mouseX][mouseY] = true;

        } else if (direction == 'd' && mouseX < mazeLength - 1) {
            mouseX += 1;
            maze[mouseX][mouseY] = true;
        } else
            break;
        
        
    }
}
