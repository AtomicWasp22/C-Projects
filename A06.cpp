#include <iostream>
#include <fstream>
#include <string>


int const WIDTH = 16;
int const HEIGHT = 9;

void draw(char canvas [HEIGHT] [WIDTH], std::ostream& os);
char setBrush();
char fill(char canvas [] [WIDTH], char brush);
char setPoint (char canvas[] [WIDTH], char brush);

using namespace std;

int main() {

    char canvas[HEIGHT][WIDTH];

    char brush;
    brush = '.';

    canvas [HEIGHT][WIDTH] = fill(canvas, brush);

    char option;

    do {
        cout << "Menu:\n";
        cout << "Draw Image (D)\n";
        cout << "Set Brush (B)\n";
        cout << "Fill Image (F)\n";
        cout << "Set Point (P)\n";
        cout << "Save Image (S)\n";
        cout << "Quit (Q)\n";

        cin >> option;
        option = toupper(option);
		string filename;
		ofstream outfile;

        switch (option) {

            case 'D':
                draw(canvas, cout);
                break;

            case 'B':
                brush = setBrush();
                break;

            case 'F':
                canvas[HEIGHT][WIDTH] = fill(canvas, brush);
                break;

            case 'P':
                canvas[HEIGHT][WIDTH] = setPoint(canvas, brush);
                break;

            case 'S':
                
                filename = "art.txt";

                cout << "Please enter a file name to which your art should be saved: ";
                cin >> filename;

                
                outfile.open(filename);

                draw(canvas, outfile);
                outfile.close();
                break;

            case 'Q':
                break;

            default:
                cout << "Sorry, please select from the provided menu";
        }
    } while (option != 'Q');
}


void draw (char canvas [HEIGHT][WIDTH], ostream& os) {
    //Prints canvas to user specified output stream
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            os << canvas[y][x];
        }
        os << endl;
    }
}

char setBrush () {
    //Lets the user choose the brush character
    char brush;
    do {
        cout << "Please enter a single valid ASCII character to use as a brush: ";
        cin >> brush;
    } while (brush < 32 || brush > 126);

    return brush;
}

char fill (char canvas[][WIDTH], char brush) {
    //Fills the canvas with the brush character
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            canvas[y][x] = brush;
        }
    }
    return canvas [HEIGHT][WIDTH];
}

char setPoint (char canvas[] [WIDTH], char brush) {
    //Changes character at (x,y) to that of the selected brush
    int x;
    x = 0;

    int y;
    y = 0;

    do {
        cout << "Please enter a point on the 9x16 grid to draw to \"x y\": ";
        cin >> x;
        cin >> y;
    } while (x < 0 || x > 9 || y < 0 || y > 16);

    canvas [y][x] = brush;

    return canvas [HEIGHT] [WIDTH];
}