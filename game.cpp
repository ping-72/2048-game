#include <bits/stdc++.h>

using namespace std;

struct Game2048
{
    int board[4][4];

    void score()
    {
        int score = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (board[i][j] == 2048)
                    score += 1280;
                if (board[i][j] == 1024)
                    score += 640;
                if (board[i][j] == 512)
                    score += 320;
                if (board[i][j] == 256)
                    score += 160;
                if (board[i][j] == 128)
                    score += 80;
                if (board[i][j] == 64)
                    score += 40;
                if (board[i][j] == 32)
                    score += 20;
                if (board[i][j] == 16)
                    score += 10;
                if (board[i][j] == 8)
                    score += 5;
            }
        }
        cout << "Your Score " << score << '\n';
    }

    void random()
    {
        while (1)
        {
            int i = rand() % 4;
            int j = rand() % 4;
            if (board[i][j] == 0)
            {
                int value = rand() % 2;
                if (value == 0)
                    board[i][j] = 2;
                else if (value == 1)
                    board[i][j] = 4;
                return;
            }
        }
    }

    void init()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                board[i][j] = 0;
            }
        }
        random();
        random();
    }

    bool end()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (board[i][j] == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void push(int array[])
    {
        int last_added = 4;
        int merge = 1;
        for (int i = 3; i >= 0; i--)
        {
            if (array[i] != 0)
            {
                if (merge)
                {
                    if (array[last_added] == array[i])
                    {
                        array[last_added] *= 2;
                        array[i] = 0;
                        merge = 0;
                    }
                    else
                    {
                        array[last_added - 1] = array[i];
                        if (i != last_added - 1)
                            array[i] = 0;
                        last_added--;
                        merge = 1;
                    }
                }
                else
                {
                    array[last_added - 1] = array[i];
                    if (i != last_added - 1)
                        array[i] = 0;
                    last_added--;
                    merge = 1;
                }
            }
        }
        return;
    }

    void print()
    {
        for (int i = 0; i < 4; i++)
        {

            for (int j = 0; j < 4; j++)
            {

                if (board[i][j] != 0)
                    cout << setw(4) << board[i][j];

                else if (board[i][j] == 0)
                    cout << setw(4) << "-";
            }

            cout << '\n';

            cout << " ---------------\n";
        }

        score();

        return;
    }

    void up()
    {

        int flag = 0;

        for (int column = 0; column < 4; column++)
        {

            int array[4], array_check[4];

            int count = 0;

            for (int row = 0; row < 4; row++)
            {

                array[row] = board[3 - row][column];

                array_check[row] = array[row];
            }

            push(array);

            for (int i = 0; i < 4; i++)
            {

                if (array_check[i] == array[i])
                    count++;
            }

            if (count == 4)
                flag += 1;

            for (int row = 0; row < 4; row++)
            {

                board[3 - row][column] = array[row];
            }
        }

        if (flag == 4)
            cout << "Input Not Allowed!\n";

        else
        {

            random();

            print();
        }

        return;
    }

    void down()
    {

        int flag = 0;

        for (int column = 0; column < 4; column++)
        {

            int array[4], array_check[4];

            int count = 0;

            for (int row = 0; row < 4; row++)
            {

                array[row] = board[row][column];

                array_check[row] = array[row];
            }

            push(array);

            for (int i = 0; i < 4; i++)
            {

                if (array_check[i] == array[i])
                    count++;
            }

            if (count == 4)
                flag += 1;

            for (int row = 0; row < 4; row++)
            {

                board[row][column] = array[row];
            }
        }

        if (flag == 4)
            cout << "Input Not Allowed!\n";

        else
        {

            random();

            print();
        }

        return;
    }

    void left()
    {

        int flag = 0;

        for (int row = 0; row < 4; row++)
        {

            int array[4], array_check[4];

            int count = 0;

            for (int column = 0; column < 4; column++)
            {

                array[column] = board[row][3 - column];

                array_check[column] = array[column];
            }

            push(array);

            for (int i = 0; i < 4; i++)
            {

                if (array_check[i] == array[i])
                    count++;
            }

            if (count == 4)
                flag += 1;

            for (int column = 0; column < 4; column++)
            {

                board[row][3 - column] = array[column];
            }
        }

        if (flag == 4)
            cout << "Input Not Allowed!\n";

        else
        {

            random();

            print();
        }

        return;
    }

    void right()
    {

        int flag = 0;

        for (int row = 0; row < 4; row++)
        {

            int array[4], array_check[4];

            int count = 0;

            for (int column = 0; column < 4; column++)
            {

                array[column] = board[row][column];

                array_check[column] = array[column];
            }

            push(array);

            for (int i = 0; i < 4; i++)
            {

                if (array_check[i] == array[i])
                    count++;
            }

            if (count == 4)
                flag += 1;

            for (int column = 0; column < 4; column++)
            {

                board[row][column] = array[column];
            }
        }

        if (flag == 4)
            cout << "Input Not Allowed!\n";

        else
        {

            random();

            print();
        }

        return;
    }
};

int main()
{

    srand(time(0));

    Game2048 mygame;

    mygame.init();

    mygame.print();

    while (!mygame.end())
    {

        cout << "What Move?(U,D,L,R): ";

        char ch;

        cin >> ch;

        if (ch == 'U')
        {

            mygame.up();
        }

        else if (ch == 'D')
        {

            mygame.down();
        }

        else if (ch == 'L')
        {

            mygame.left();
        }

        else if (ch == 'R')
        {

            mygame.right();
        }

        else
        {

            cout << "Invalid Input\n";
        }
    }

    cout << "GAME Ends!\n";

    return 0;
}