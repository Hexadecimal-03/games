#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// Global variables
bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruitx, fruity, score;
enum edirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
edirection dir;
int tailx[100], taily[100];
int ntail;

// All functions
void Setup()
{
    gameover = false;
    dir = STOP;
    x = width/2;
    y = height/2;

    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;
}

void Draw()
{
    system("cls");

    for (int i = 0; i < width+2; ++i)
    {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (j == 0)
            {
                cout << "#";
            }

            if (i == y and j == x)
            {
                cout << "O";
            }
            else if (i == fruity and j == fruitx)
            {
                cout << "F";
            }
            else
            {
                bool print = false;
                for (int k = 0; k < ntail; k++)
                {
                    if (tailx[k] == j && taily[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                {
                    cout << " ";
                }
            }

            if (j == width-1)
            {
                cout << "#";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width+2; ++i)
    {
        cout << "#";
    }
    cout << endl;

    cout << "SCORE : " << score << endl;
}

void Input()
{
    if (_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameover = true;
            break;
        }
    }
}

void Logic()
{
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x, prev2y;
    tailx[0] = x;
    taily[0] = y;
    for (int i = 1; i < ntail; ++i)
    {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    /*if (x > width or x < 0 or y > height or y < 0)
    {
        gameover = true;
    }*/

    if (x > width)
    {
        x = 0;
    }
    else if (x < 0)
    {
        x = width-1;
    }

    if (y > height)
    {
        y = 0;
    }
    else if (y < 0)
    {
        y = height-1;
    }

    for (int i = 0; i < ntail; ++i)
    {
        if (tailx[i] == x and taily[i] == y)
        {
            gameover = true;
        }
    }

    if (x == fruitx and y == fruity)
    {
        score++;
        fruitx = rand() % width;
        fruity = rand() % height;
        ntail++;
    }
}

int main()
{
    Setup();

    while (!gameover)
    {
        Draw();
        Input();
        Logic();
        Sleep(20);
    }
    return 0;
}