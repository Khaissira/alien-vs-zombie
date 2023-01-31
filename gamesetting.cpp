


    /*cout << "Default Game Settings" << endl;
    cout << "---------------------" << endl;
    displaysettings(row, column, zombies);
    cout << endl;
    cout << "Do you want to change the game settings? (y/n) -> ";
    cin >> letter;
    if (letter == 'y')
    {
        cout << endl;
        cout << "Please enter new value for number of rows, columns and zombie(s)" << endl;
        cout << "Enter number of columns : ";
        cin >> row;
        if (row % 2 != 0)
        {
            true;
        }
        else
        {
            cout << "Please enter ODD NUMBER for number of columns -> ";
            cin >> row;
        }
        cout << "Enter number of rows : ";
        cin >> column;
        if (column % 2 != 0)
        {
            true;
        }
        else
        {
            cout << "Please enter ODD NUMBER for number of rows -> ";
            cin >> column;
        }
        cout << "Enter number of zombie : ";
        cin >> zombies;
        if (zombies > 10)
        {
            cout << "Please enter values NOT MORE THAN 10 for number of zombies -> ";
            cin >> zombies;
        }
        else
            cout << endl;
        cout << endl;
        cout << "New Game Settings" << endl;
        cout << "---------------------" << endl;
        displaysettings(row, column, zombies);
        pf::Pause();
        cout << endl;
        test1_1(column, row);
        {
            true;
        }
    }
    else if (letter == 'n')
    {
        cout << "you are not changing the default game settings." << endl;
        pf::Pause();
        cout << endl;
        test1_1(rows, col);
    }
    else
    {
        cout << "Please enter either letter 'y' or 'n' only. ";
    }
    return true;
*/
