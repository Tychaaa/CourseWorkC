#include "Function.h"

// ������������� ��������� �������
void consoleSetting()
{
    // ������ ������� ���� � �������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ������������� ��������� ���� �������
    SetConsoleTitle(L"Blades of Destiny");

    // �������� ���������� �������
    HWND console = GetConsoleWindow();

    // ������������� ���� �������
    ShowWindow(console, SW_MAXIMIZE);

    // �������� ����� ����
    LONG style = GetWindowLong(console, GWL_STYLE);

    // ������� ������ ������ ������������
    style &= ~WS_MAXIMIZEBOX;

    // ������������� ����� �����
    SetWindowLong(console, GWL_STYLE, style);

    // ��������� ���������
    SetWindowPos(console, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED);
}

// ������� ��� ������ �������� ���� (��������)
void gameTitleSlow()
{
    system("cls");

    // ASCII-���, �������� �� ������
    string asciiArt[] = {
        " ____   __,     ____, ____,  ____,  ____,    ____,  ____,    ____,  ____,  ____,  ____,  __,   _,  _, _  _, ",
        "(-|__) (-|     (-/_| (-|  \\ (-|_,  (-(__    (-/  \\ (-|_,    (-|  \\ (-|_,  (-(__  (-|    (-|   (-|\\ | (-\\_/  ",
        " _|__)  _|__,  _/  |, _|__/  _|__,  ____)    _\\__/, _|       _|__/  _|__,  ____)  _|,    _|_,  _| \\|,  _|,  ",
        "(      (      (      (      (      (        (      (        (      (      (      (      (     (       (     "
    };

    // ������� ASCII-��� ��������� � ���������
    for (const auto& line : asciiArt) {
        cout << line << '\n';
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << "\n" << endl;

    this_thread::sleep_for(chrono::milliseconds(1000));
}

// ������� ��� ������ �������� ����
void gameTitle()
{
    system("cls");

    // ASCII-���, �������� �� ������
    string asciiArt[] = {
        " ____   __,     ____, ____,  ____,  ____,    ____,  ____,    ____,  ____,  ____,  ____,  __,   _,  _, _  _, ",
        "(-|__) (-|     (-/_| (-|  \\ (-|_,  (-(__    (-/  \\ (-|_,    (-|  \\ (-|_,  (-(__  (-|    (-|   (-|\\ | (-\\_/  ",
        " _|__)  _|__,  _/  |, _|__/  _|__,  ____)    _\\__/, _|       _|__/  _|__,  ____)  _|,    _|_,  _| \\|,  _|,  ",
        "(      (      (      (      (      (        (      (        (      (      (      (      (     (       (     "
    };

    // ������� ASCII-��� ��������� � ���������
    for (const auto& line : asciiArt) {
        cout << line << '\n';
    }

    cout << "\n" << endl;
}

// ������� ��� ������ �������� �������������
void prodTitle()
{
    system("cls");

    // ASCII-���, �������� �� ������
    vector<string> asciiArt = {
        " _______               _      _                  ",
        "|__   __|             | |    | |                 ",
        "   | |    _   _   ___ | |__  | | __  ___  __   __",
        "   | |   | | | | / __|| '_ \\ | |/ / / _ \\ \\ \\ / /",
        "   | |   | |_| || (__ | | | ||   < | (_) | \\ V / ",
        "   |_|    \\__, | \\___||_| |_||_|\\_\\ \\___/   \\_/  ",
        "           __/ |                                 ",
        "          |___/                                  ",
        "                   _                             ",
        "                  | |                            ",
        "  __ _  _ __    __| |                            ",
        " / _` || '_ \\  / _` |                            ",
        "| (_| || | | || (_| |                            ",
        " \\__,_||_| |_| \\__,_|                            ",
        "                                                 ",
        "                                                 ",
        "  _____  _                   _                      ",
        " / ____|| |                 | |                     ",
        "| (___  | |__    ___ __   __| |_  ___   ___  __   __",
        " \\___ \\ | '_ \\  / _ \\\\ \\ / /| __|/ __| / _ \\ \\ \\ / /",
        " ____) || | | ||  __/ \\ V / | |_ \\__ \\| (_) | \\ V / ",
        "|_____/ |_| |_| \\___/  \\_/   \\__||___/ \\___/   \\_/  ",
        "                                                     ",
        "                                                     ",
        " _____                    _               _    _               ",
        "|  __ \\                  | |             | |  (_)              ",
        "| |__) | _ __   ___    __| |  __ _   ___ | |_  _   ___   _ __  ",
        "|  ___/ | '__| / _ \\  / _` | / _` | / __|| __|| | / _ \\ | '_ \\ ",
        "| |     | |   | (_) || (_| || (_| || (__ | |_ | || (_) || | | |",
        "|_|     |_|    \\___/  \\__,_| \\__,_| \\___| \\__||_| \\___/ |_| |_|",
        "                                                                "
    };

    // ������� ASCII-��� ��������� � ���������
    for (const auto& line : asciiArt) {
        cout << line << '\n';
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    Sleep(1000);
}

// ������� ��� ������ �������� ���� ����
void mainMenu()
{
    int choice;

    gameTitleSlow();

    do {
        cout << "������� ����:\n" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "1. ������ ����" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "2. ������" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "3. ����� �� ����" << endl;

        cout << "\n�������� �����: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // ���������� ���� ������
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
        }

        switch (choice) {
        case 1:
            // ������ ����
            gameTitle();
            this_thread::sleep_for(chrono::milliseconds(1000));
            break;
        case 2:
            // �������� ���������� �� �������
            prodTitle();

            cout << "������� ������ - ������� ������ 2 ����� ������ ��-23" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
            cout << "���� ������ - ������� ������ 2 ����� ������ ��-23\n" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));

            cout << "���� ��������� � ������ �������� ������ �� 2 ����" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
            cout << "�� ���� \"��������� RPG � �������\" �� ����� C++\n" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));

            cout << "�� ����� ��������, ������������ ��� ��� ��������" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
            cout << "����������� � telegram: @tychaaaa ��� @Sh1chik" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));

            Screen::displayText("\n������� Enter, ����� ����������...");
            cin.ignore();
            cin.get();

            gameTitleSlow();
            break;
        case 3:
            // ����� �� ����
            Screen::displayDialog("����������", "�� ������, ��� ������ �������� ���� ������������� ���? ���� ����� ������ �����������!");
            exit(0);  // ��������� ���������
            break;
        default:
            Screen::displayDialog("����������", "�� ���-�� �������, ��� �������. ������� ������������.");
            system("cls");
            gameTitle();
            break;
        }
    } while (choice != 1);  // ���� ������������, ���� ������������ �� ������� "������ ����"
}

// ����������
void introduction(Character& character)
{
    // ���������� ������ �����
    int leftIndent = 10;

    // ASCII-��� ��� �������� ����� � �������� �����
    vector<string> chapterArt = {
        "     _____                _                            ",
        "    |  __ \\              | |                           ",
        "    | |__) | _ __   ___  | |  ___    __ _  _   _   ___ ",
        "    |  ___/ | '__| / _ \\ | | / _ \\  / _` || | | | / _ \\",
        "    | |     | |   | (_) || || (_) || (_| || |_| ||  __/",
        "    |_|     |_|    \\___/ |_| \\___/  \\__, | \\__,_| \\___|",
        "                                     __/ |              ",
        "                                    |___/               "
    };

    for (const string& line : chapterArt) {
        // ��������� ������ �����
        cout << string(leftIndent, ' ') << line << endl;
    }

    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n\n" << endl;

    // ������� � ����
    Screen::displayText("\n����� ���������� � ������������� ��� �����������!");
    this_thread::sleep_for(chrono::milliseconds(1000));

    Screen::displayText("\n������-�����, � ������������ ����, ��� ���� � ���� ������� ������ �����, �������� ���� �����������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n�����, ����� ������� ���� � ��������������� ������, ������ ��� ����� �������� � �������� ����� ��� ����������� ���������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n������ ���, ��������� �������� � ����� ���� ������� ��������������� �����.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n���� ��� ������ ����� ������, ������� ������� ��� �� ��������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n� ��� �� ������������, ������, ��� ���� ��������� ������, � ��� ��� ���� ����������� ���������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n����� �������� � ����� ������!");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayDialog("����������", "������, ������! �� ��������� � ����, ��� ������ �������, ������ ��������,\n����� �������� �� ������ ����� ����. � - ���� ��������� � ���� ������������ �����������.");
    
    Screen::displayCharacterByCharacter("\n\"- ��� ��? ��� �?\"");
    this_thread::sleep_for(chrono::milliseconds(1000));

    Screen::displayText(" - ����������� ��, ������ ��������� ���� � ���� ���������� ����.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayDialog("����������", "���� ����� ������, ���������� ����� ����. ��� ������ ���� �������.");

    Screen::displayDialog("����������", "� �� � ���, ��� ������� ��� �������. ���� ��� ���� ������, �� ��� ������ ��������.\n�� ������� �����, � ���� ����� ��������� ������ ����� ����.");

    // �������� � �������� �������� �����
    Screen::displayDialog("����������", "����������, � ���� ���� ��������� ��������... ������� �� ������� �����������, ��� ��������� ���� ������.");

    character = createMainCharacter();

    Screen::displayDialog("����������", "������� ��� ���� ������ ����. �� ������� ���������� ���������� ����� ��������. ���� � �������������.");

    Screen::displayDialog("����������", "�����, " + character.getName() + "!");

    // ������� ������� ������� ����� ������������
    Screen::displayText("\n������� Enter, ����� ����������...");
    cin.ignore();
    cin.get();
}

// ����� "������"
void prologue(Character& character)
{
    gameTitle();

    // ������� �� ��������� � ������������ � ������ �����������
    Screen::displayText("\n���������� ���� ������� ������, ����� �� ������� ��������� �� �������� �����������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n�� ������������� � ����... ������� ��������� �������, ������� �� ������� ������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n�� ������� ����� ������ �������, ������������ ���-��� ����������� � ����.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayDialog("������", "������� ������, ���� �� �����, ���� ���� ���������. ������� �� �� ��������� ��� �������� � ����?");

    Screen::displayText("\n1. \"- ��, � ������������. ���������� ��������� ������.\"");
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayText("2. \"- ��������� �� �����������, �� � ��������� ���� � �����������.\"");
    this_thread::sleep_for(chrono::milliseconds(500));

    cout << "\n��� �����: ";

    int choice;
    // �������� ������� ������ ����� � ����� ����
    while (!(cin >> choice) || (choice != 1 && choice != 2))
    {
        // ������� ������ �����
        cin.clear();
        // ������������� ���������� �������� � ������ �����
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // ������� ��������� NPC �� ������ � ������ ������ ����� ������
        Screen::displayDialog("������", "��������, � �� ��������� ��� �����. ����������, ��������� ���");
        cout << "\n��� �����: ";
    }

    switch (choice)
    {
    case 1:
        Screen::displayDialog("������", "�������! ��������������, � ����!");

        Screen::displayText("\n�� �������� �� ������� � ��������� ���������� � ����������.");

        Screen::displayDialog("������", "���� ������������?");

        Screen::displayText("\n1. \"- � ����� ��������, ��� ���� ���� ����.\"");
        this_thread::sleep_for(chrono::milliseconds(500));
        Screen::displayText("2. \"- ������ ���, ���� ������ �������.\"");
        this_thread::sleep_for(chrono::milliseconds(500));

        cout << "\n��� �����: ";

        int destinationChoice;
        // �������� ������� ������ ����� � ����� ����
        while (!(cin >> destinationChoice))
        {
            // ������� ������ �����
            cin.clear();
            // ������������� ���������� �������� � ������ �����
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // ������� ��������� NPC �� ������ � ������ ������ ����� ������
            Screen::displayDialog("������", "��������, � �� ��������� ��� �����. ����������, ��������� ���");
            cout << "\n��� �����: ";
        }

        switch (destinationChoice)
        {
        case 1:
            Screen::displayDialog("������", "�������� �����! �������� - ������������ �����. ������� ������ ���������� ����.");
            break;
        case 2:
            Screen::displayDialog("������", "������ ����� �������� ��������. ������� � ����! � ����������� � ��������.");
            break;
        default:
            Screen::displayDialog("������", "������ �� �� �������� �� ��������. ������ ��������� ���� ����� ������!");
            break;
        }

        Screen::displayText("\n���� ����������� ����������. ��� ������� �� ��������� �� ��������, � ������ ��������� ���������.");
        this_thread::sleep_for(chrono::milliseconds(1500));
        Screen::displayText("\n�� ��������� ������� �����.");
        this_thread::sleep_for(chrono::milliseconds(1000));
        Screen::displayText("\n(��������� +20 �����)");
        this_thread::sleep_for(chrono::milliseconds(1000));
        Screen::displayText("\n");

        // ���������� ����� ���������
        character.setExperience(character.getExperience() + 20);
        break;

    case 2:
        Screen::displayDialog("������", "�������, ������ �������� ���� ����. �������, ���������� �����.");

        Screen::displayText("\n������ ������ ��� �� ��������, � �� ����������� � ���� ����.");
        this_thread::sleep_for(chrono::milliseconds(1500));
        Screen::displayText("\n�� ������ ���� ������, �������� ���� ������������ � ������� �������������� ����.");
        this_thread::sleep_for(chrono::milliseconds(1000));
        Screen::displayText("\n(��������� +50 �����. �������� -20 ������������)");
        this_thread::sleep_for(chrono::milliseconds(1000));

        // ���������� ����� � ���������� ������������ ���������
        character.setExperience(character.getExperience() + 50);
        character.setStamina(character.getStamina() - 20);
        break;

    default:
        break;
    }

    // ������� ������� ������� ����� ������������
    Screen::displayText("\n������� Enter, ����� ����������...");
    cin.ignore();
    cin.get();
}

// �������� ���
void combatTraining(Character& character)
{
    gameTitle();

    // ����������� ����� ������������ ������ ��������
    Screen::displayText("\n����� ����������� ������������ ������ ��������, " + character.getName() + " ����� ��������� ������ �� ����� �����.\n");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("����� �������� � �������, ���������� ������� � ������������� ������������, �������� ����� ������� ������,\n���� �� ���� ����������� ���������� � �������� �������� �, �������, �������� � ������� ����������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    // ��������, ������� �������� �������� � �����.
    Screen::displayDialog("������� ��������", character.getName() + ", � �����, ��� �� ���������� ��� �����. � ���� ���� ����������� ��� ����.");

    Screen::displayDialog("������� ��������", "�� ���� ������� ������, ��������� �������� ���� ������ ���� �������. � ���� ���������� ���� ����������.");

    Screen::displayDialog("������� �������� ���������� ����������", "��� ����� ������������� ���, � ������� �� ������� ������������������ ���� ������. ��� �������?");

    // ������������ ������ �����
    cout << "\n1. ������� ����������� � ���������� � ����������."
        << "\n2. ���������� � ���������� ���� �����������."
        << "\n\n��� �����: ";

    int trainingChoice;
    // �������� ������� ������ ����� � ����� ����
    while (!(cin >> trainingChoice) || (trainingChoice != 1 && trainingChoice != 2))
    {
        // ������� ������ �����
        cin.clear();
        // ������������� ���������� �������� � ������ �����
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // ������� ��������� NPC �� ������ � ������ ������ ����� ������
        Screen::displayDialog("������� ��������", "�� ����� ������ ������. ������� ��� ���!");
        cout << "\n��� �����: ";
    }

    switch (trainingChoice)
    {
    case 1:
        Screen::displayDialog("������� ��������", "�������! ����� ������ ����������. ������ �� ������������� ��������.");
        break;

    case 2:
        Screen::displayDialog("������� ��������", "�� � ���� � ���� ���������. ���� ���� �� �� ������, � ������� ������������� ���, ����� ������ ���� ������� ���� ������.");
        break;

    default:
        Screen::displayDialog("������� ��������", "��� ��� �� �������, ����� ������!");
        break;
    }

    Weapon capitan_sword("��� ��������", 35, 25);
    Character enemy("������� ��������", 200, 150, 150, &capitan_sword, nullptr, 100);

    CombatSystem fight;

    // ����������� ������ ����� �������������� ��� � ��������� ����������
    Screen::displayText("\n������������� ��� �������. ������� �������� �������������� ���� ���� � ����������, �� " + character.getName() + " �� ��������� � �������.\n");
    this_thread::sleep_for(chrono::milliseconds(1500));

    fight.startGameTraining(character, enemy);

    // �������� ����� �������������� ���
    if (enemy.getHealth() <= 0) 
    {
        Screen::displayText("����� ��������� � ������������� ����, �� ������� �������� �������� ����������.");
        Screen::displayDialog("������� ��������", "�������� ������, " + character.getName() + "! �� ������� ���� � ���, � � ������, ��� � ���� ������� ������� �������.");
    }
    else 
    {
        Screen::displayText("� ���������, ����� �������� ������������� ���, �� ������� �������� �������� � ���� � �������.");
        Screen::displayDialog("������� ��������", "�� ������� ���� � ���������, ���� ���� �� ���� ������� ����. �� ���������� ������.");
    }

    Screen::displayDialog("������� ��������", "������, ����� �� ������ ����������, � ���� ���� ��� ���� ����� �������. ������ ��������� ���������� �������� �������, � � �������� � ����� ������.");

    // ������������ ������ �����
    cout << "\n1. ������� ����� ������� � ����������� �� ����� �����������."
        << "\n2. ���������� � ���������� ���� �����������."
        << "\n\n��� �����: ";

    int questChoice;

    // �������� ������� ������ ����� � ����� ����
    while (!(cin >> questChoice) || (questChoice != 1 && questChoice != 2))
    {
        // ������� ������ �����
        cin.clear();
        // ������������� ���������� �������� � ������ �����
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // ������� ��������� NPC �� ������ � ������ ������ ����� ������
        Screen::displayDialog("������� ��������", "�� ����� ������ ������. ������� ��� ���!");
        cout << "\n��� �����: ";
    }

    switch (questChoice)
    {
    case 1:
        Screen::displayDialog("������� ��������", "�������! ��� � ��������� �� ����� � �����. �� ���� ���� ��� ����������� ���������� ��� ������ �������.");
        break;

    case 2:
        Screen::displayDialog("������� ��������", "�� ���������� �������������, " + character.getName() + ". ������ ����� ������� ������� ���� ����� ��� �������. ��� � ��������� �� ����� � �����.");
        break;

    default:
        break;
    }

    // ������� ������� ������� ����� ������������
    Screen::displayText("\n������� Enter, ����� ����������...");
    cin.ignore();
    cin.get();
}

// ����� 1
void chapter_one(Character& character)
{
    gameTitle();

    // ���������� ������ �����
    int leftIndent = 10;

    // ASCII-��� ��� ����� 1 � �������� �����
    vector<string> chapterOneArt = {
        "  _____  _                    _                  ____               ",
        " / ____|| |                  | |                / __ \\              ",
        "| |     | |__    __ _  _ __  | |_   ___  _ __  | |  | | _ __    ___ ",
        "| |     | '_ \\  / _` || '_ \\ | __| / _ \\| '__| | |  | || '_ \\  / _ \\",
        "| |____ | | | || (_| || |_) || |_ |  __/| |    | |__| || | | ||  __/",
        " \\_____||_| |_| \\__,_|| .__/  \\__| \\___||_|     \\____/ |_| |_| \\___|",
        "                      | |                                            ",
        "                      |_|                                            "
    };

    // ������� ASCII-��� ��� ����� 1
    for (const string& line : chapterOneArt) {
        // ��������� ������ �����
        cout << string(leftIndent, ' ') << line << endl;
    }

    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n\n" << endl;

    // �������� ���� � ���������
    Screen::displayText("\n" + character.getName() + " ��� �� ����� �������, ������� � ������� ���������. �� �������� �������� ������ ����, � ������ ���������� ������� �������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n������� �������� �������� ����, �� ����� �� ������� �� ��� ��������, ���������������� �� ����� ����������� �������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    // ������� �� ����������
    Screen::displayDialog("��������", "����������, " + character.getName() + "! � ������, ��� �� ����������� ����������� � ����.");

    Screen::displayDialog("��������", "� ���� ���� ��� ���� �������. � ������ ��������� ������� �������, � �� ��������� � ����� ������.");

    Screen::displayDialog("��������", "���� ������ ������: �������� ���������� �������� � ������������ ���������. �� ��� �� ������������ � ������.");

    // ������� ����������
    Screen::displayText("\n������� ��������: '������� ������������ �� ��������'.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n�� ���������� ���� � ���� ��������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n������� �� ��� ����� �������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    CombatSystem fight;

    Ogre ogre("���", 100, 100, 0);

    Goblin goblin1("������ 1", 60, 100, 100);
    Goblin goblin2("������ 2", 60, 100, 100);

    fight.startGame(character, goblin1);

    fight.startGame(character, goblin2);

    Screen::displayText("\n������ ��� ��������� ����� � �����.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    fight.startGame(character, ogre);

    Screen::displayText("\n������� ���������, � ����������� ������ ������ ���������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayDialog("��������", "�������� ������, " + character.getName() + "! ������� �� ���� ������ � ������� ������������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayDialog("��������", "�� �������, ��� ��������� ��������� ������, ���������� ���� �����.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayDialog("��������", "����� �������� �������� ������ ��������� � ���������� �����������, ��� ��.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayDialog("��������", "���� � ���� ���� ��� �����-�� ������� ��� ����� ������, �� ��������� ���������� � ���.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayDialog("��������", "�� ������ ��������� � ��������� ���� ������ � ������ ����� ������ �������������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    // ������� ������� ������� ����� ������������
    Screen::displayText("\n������� Enter, ����� ����������...");
    cin.ignore();
    cin.get();
}

// ����� 2
void chapter_two(Character& character)
{
    gameTitle();

    // ���������� ������ �����
    int leftIndent = 10;

    // ASCII-��� ��� ����� 2 � �������� �����
    vector<string> chapterTwoArt = {
        "  _____  _                    _                 _______                  ",
        " / ____|| |                  | |               |__   __|                 ",
        "| |     | |__    __ _  _ __  | |_   ___  _ __     | |   __      __  ___  ",
        "| |     | '_ \\  / _` || '_ \\ | __| / _ \\| '__|    | |   \\ \\ /\\ / / / _ \\ ",
        "| |____ | | | || (_| || |_) || |_ |  __/| |       | |    \\ V  V / | (_) |",
        " \\_____||_| |_| \\__,_|| .__/  \\__| \\___||_|       |_|     \\_/\\_/   \\___/ ",
        "                      | |                                                 ",
        "                      |_|                                                 "
    };

    // ������� ASCII-��� ��� ����� 2
    for (const string& line : chapterTwoArt) {
        // ��������� ������ �����
        cout << string(leftIndent, ' ') << line << endl;
    }

    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n\n" << endl;

    // �������� ���� ����� � ����� �������
    Screen::displayText("\n" + character.getName() + " ���������� � ����, � ��� ��������� ����� ����� ������������ ������ ������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n���� ��� ������, �� ����� �������� �� ��� ��������� ��������� ����, �������� � ����� ������������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Location forestValleyLocation("������ ������", "������������ ������ ������, ������ ������� � ����������.\n"
        "����� ������� ������� �������� � ���� �������. ������� ������ ���� ��������� � ������ � ������� � ������� ������.");

    // ��������
    vector<string> elfPhrases = {
        "\"- ����� ���������� � ������ ������, " + character.getName() + ". ����� �� ������������ ���� ������� � ��������� �� �������������.\"",
        "\"- ��� - ����� ������������ � ����������. ���� ������ ���� �����, �������� �����������.\"",
        "\"- ���� � ���� ���� ������� � ���� ��� �������, �� ��������� ����������. � ������������� �������� ������ ��������.\"",
        "\"- � ���� ���� �������� ������� ����� � ���������. ������ ���, ��� � ��������� ��������� � �������, ����� ���������� ��.\"",
        "\"- ���� ��������� � ����� ���������, � ��� ������� ���� ���� �����.\""
    };
    NPC elf(
        "�������� �������",
        "������� ��������, ������� � ������ ������. ������� - ��������� ���� � ��� ������� ����.\n"
        "��� ����� ������ ����� ������ ������� ���� � ��� �����������.",
        elfPhrases
    );
    forestValleyLocation.addInteractiveObject(&elf);

    // �����
    vector<string> druidPhrases = {
        "\"- ����� ���������� � ������ ������, " + character.getName() + ". � - ������ �����, ������������� �������.\"",
        "\"- � ���� ���� ������ ������ - ����� ����. � ��������� � �������, �� ������� ����� ���� ���� � ���������.\"",
        "\"- ��� - ����� ���� � �������. � ������ ������ ���� ��������� � ���� ��������� ����.\"",
        "\"- ���� �� ���������� � ������ �� �������� ������� � �� �����, ������� �� ���.\"",
        "\"- ������ �������, � ��� ������� ���� �����������.\""
    };
    NPC druid(
        "����� �����",
        "��������������� ���� � �������. ������ ����� - ���� ������ ������, ������ � ������� ���� ��� ����������.\n"
        "��� ����� ������ ����� ������ ����� � �������� � ������������ �� �����.",
        druidPhrases
    );
    forestValleyLocation.addInteractiveObject(&druid);

    // ������ ��������
    vector<string> rangerPhrases = {
        "\"- �����������, ��������! � ���� ����� ����������, �� � ����� ��������. �� ����� ����������� ��� �����?\"",
        "\"- ��� - ����� ��� ������� � ������. �� ��������� �����. ���� ����� ������ ��� �����, ��������� �� ���.\"",
        "\"- � ������ ������ ���� ���� ���-�� ������������. ������ �� ����� �������, � �� ���������� ��� �����.\"",
        "\"- ���� ���� ����� ������ ��� �������� � ����, � ����� ���������� ���� ������.\"",
        "\"- ������ ����� ���� � ���� ����� �� �����. � ���� ���� �� ������ ����� ���� ������.\""
    };
    NPC ranger(
        "������ �������� �����",
        "������� � ���������, ������� ��� ������ ����. ����� - �������� ������� � ������� ����������� �� ����� ��������.\n"
        "�� ����� ���� �������� ����������� � ���������� � ������������.",
        rangerPhrases
    );
    forestValleyLocation.addInteractiveObject(&ranger);

    forestValleyLocation.onEnter();

    // ���������� ����� ����
    Screen::displayText("\n�������, " + character.getName() + " ������ ������ ������. ������ ���������� �������� ������ � ����� �������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n�� ����� ������ ���� ���������� ������ ������. ������������ ������� �������� �� ����, �������� �������������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    // ��� � ��������� � ������ ������
    Screen::displayText("\n�������� ����� �������� ������ �������. ��������, ��� �� ������������� ������.");

    Wolf wolf("�������", 60, 50, 0);

    Skeleton skeleton1("�������� ������ ����", 40, 100, 100);

    Skeleton skeleton2("���������� ������ ����", 40, 100, 100);

    CombatSystem fight;

    Screen::displayText("\n�� ���������� ����� � ���� ��������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n������� �� ��� ����� �������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    fight.startGame(character, skeleton1);
    fight.startGame(character, skeleton2);

    Screen::displayText("\n������ ��� ��������� ����� � ������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    fight.startGame(character, wolf);

    // ������� ������� ������� ����� ������������
    Screen::displayText("\n������� Enter, ����� ����������...");
    cin.ignore();
    cin.get();
}

// ��������� ��������� ����� �������
void characterUpgrade(Character& character)
{
    character.setHealth(420);
    character.setMaxHealth(420);
    character.setStamina(360);
    character.setMaxStamina(360);
    character.setMana(360);
    character.setMaxMana(360);
    character.setLevel(50);

    string className = character.getClassType();

    // ������� �����, ��� ����� ���������� ������� ������ � ����� � ����������� �� ������
    Weapon* newWeapon = nullptr;
    Magic* newMagic = nullptr;

    if (className == "����") {
        newWeapon = new Weapon("����������� ��� ���������", 90, 80);
        newMagic = new Magic("����������� ����", 80, 60);
    }
    else if (className == "���") {
        newWeapon = new Weapon("�������������� ���� ������", 70, 40);
        newMagic = new Magic("����� ���������� ��������", 100, 70);
    }
    else if (className == "���") {
        newWeapon = new Weapon("������ �������� ����", 100, 65);
        newMagic = new Magic("������������ ��������", 90, 65);
    }
    else if (className == "�������") {
        newWeapon = new Weapon("�������� ������� �����", 90, 60);
        newMagic = new Magic("������� ��������", 95, 65);
    }
    else if (className == "����") {
        newWeapon = new Weapon("��������� ����", 90, 50);
        newMagic = new Magic("������������ �����", 90, 85);
    }
    else if (className == "������") {
        newWeapon = new Weapon("��� �������� �����", 105, 65);
        newMagic = new Magic("��� ������", 85, 50);
    }

    // ������������� ����� ���������� ������ � ����� �����
    character.setWeapon(newWeapon);
    character.setMagic(newMagic);
}

// ����� "�����"
void chapter_final(Character& character)
{
    gameTitle();

    // ���������� ������ �����
    int leftIndent = 10;

    // ASCII-��� ��� ����� 2 � �������� �����
    vector<string> chapterFinalArt = {
        " ______  _                _ ",
        "|  ____|(_)              | |",
        "| |__    _  _ __    __ _ | |",
        "|  __|  | || '_ \\  / _` || |",
        "| |     | || | | || (_| || |",
        "|_|     |_||_| |_| \\__,_||_|",
        "                            ",
        "                            "
    };

    // ������� ASCII-��� ��� ����� 2
    for (const string& line : chapterFinalArt) {
        // ��������� ������ �����
        cout << string(leftIndent, ' ') << line << endl;
    }

    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n\n" << endl;

    characterUpgrade(character);

    // ������� � ������ ����� ���������� �������
    Screen::displayText("\n������ ����� ��� � ��� ���, ��� " + character.getName() + " ���������� � ���� ������ �����������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n����� ��������� ��������� ���������, ���� ������� ������ � �������� ����� � ��������� ������� ����.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n������ " + character.getName() + " ����� ���� ��������, ��� ������� �������������� ������ ������ � � ������ ������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n������ � ����� �������� ��� ���� ��������� �������, ������� ��������� ���������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n������� ����, ������ ����������, ����� ���������� � �������� ����. " + character.getName() + " ��������� � ���������� ������������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n����� �������. ��������� ������� ����, � ����� ����� ��������� ���� ������.");

    // ������� �� �������������
    Screen::displayDialog("[�� �������������]", "� ����� � ��������� �������, ����� ������ ���� ���������. �� �������� ��������� �� ���, �� ��������, ��� �� ��� ����� ����������� ������� ����!");

    // ����� �� �����������
    Screen::displayDialog("����������", "�� ����� ����, ������� ����� ����������, � ����� ��, ��������� �����, �� ���������, � ����� ���������� ����� �������� � ������������ ����� ��� ����������� ����� ��������.\n���� ���, �������������, ����� � ����� �������, �� ��� ��? ������� ����� �������� � ������ ����������� ������ �����!");
    
    // ����� �� �����������
    Screen::displayDialog("����������", "� ���� ��, ������� �� ����� ������ �������������, ��� ���� ���������!");

    Location darkLordCastle("��������� ������� ����", "������� ���������, ����������� ������� ����. ����� ����� ���� � ���.\n"
        "�������� �������� � ������ �������� � ���� �����, ������� ��������� ���� ������ ����������.");

    // ������� ����
    vector<string> darkLordPhrases = {
        "\"- ����� ���������� � ��� ��������, " + character.getName() + ". �� ����� ������� ������, � ������ �� ����� ��������.\"",
        "\"- �� ����� ����� �� ���� ������, " + character.getName() + ". ��� ���� �������� ����, ��� � ����, ��� ������������ ������ �� ��� ����.\"",
        "\"- ������ ��, " + character.getName() + ", �� �� �������� ��� ����� �����. ���� ������ ��� ������.\"",
        "\"- �� - ��������� �������� ����� ���� ������������. ����������� � �����, �� ����, ��� �� ����������.\"",
        "\"- ���� ��� ��� ������� � ������ ������. ������ �� ������� ���������� ��� �������, " + character.getName() + ".\""
    };
    NPC darkLord(
        "������� ���� ��������",
        "�������������� ������� ����, ��������� ��������� ����. �� �������� ������ ���� � ��������� ��������� ��� ����� ����.",
        darkLordPhrases
    );
    darkLordCastle.addInteractiveObject(&darkLord);

    // ������ � �����
    vector<string> demonPhrases = {
        "\"- �� �� �������� ������, ��������! ������� ���� �������� �������� ���� �������.\"",
        "\"- �� ������ ���� � ������ ������ ���� �����, ����� �������� ������ ����������.\"",
        "\"- � ���� ���� ��� ����� ��� �����. �������� ���� ��� �������!\"",
        "\"- ��������, �������, ���� �� ���������� � ����� ������!\"",
        "\"- ���� ������ ������������, � ������� ���� ���� �� ������ ���� �� ����� ������!\""
    };
    NPC demon("����� �������� �����", "������� �����, ���������� �������� ���� ��� ������ �����.", demonPhrases);
    darkLordCastle.addInteractiveObject(&demon);

    // �������� �������� � �����
    vector<string> succubusPhrases = {
        "\"- �, ����� ����������. ����� �������� ��������� ��� ����� �����!\"",
        "\"- ������� �������, �� �������� � ������� ����. ����������� ���� ��������.\"",
        "\"- �� ������� ��� ��������. ����� ����, � ������� ���� ��������... �� ��������.\"",
        "\"- ���� ���� ����� �������. � ������ ���� � ��� ����������� � ���������.\"",
        "\"- ������� ���� ���������� ����� �������. ��� �� ������� �� ����, ����� �������?\""
    };
    NPC succubus("������ ������", "��������������� ��������, ������������ ����� ����� � �������������� ���������.", succubusPhrases);
    darkLordCastle.addInteractiveObject(&succubus);

    vector<string> witchPhrases = {
    "\"- �� �������� �� ������ ����� �����. ����� ���� ��� �������.\"",
    "\"- ��������, �� ������� ����������� � ��������� ������� ����. ������ �� ��������� �� ���� ��������.\"",
    "\"- ����� ����� ����, � �� �� ������� ������� �� ���. �� ������� ����� ��� ���� ����������.\"",
    "\"- ������ ���� ��� ����������. �� ���� ������ ����� �����, �� ���� �����.\"",
    "\"- �� ������ ���� ������, ��������. ������� ���� ������ ������.\""
    };
    NPC witch("������ �����", "�������� ������, ��������� ������ ������ � ��������� ������� ����. �� ����� ������ � ������ ��������� ����� ����.", witchPhrases);
    darkLordCastle.addInteractiveObject(&witch);

    vector<string> enchantressPhrases = {
        "\"- ����� �� ���� ������, ��������? �� �� ������� ������ ������ ����.\"",
        "\"- ��� ����� ���������� ��� ���� ��������� ������� �������������.\"",
        "\"- ����� � ���� ����� �������, ����������� �����. �� ���� ���� ��� ����� ������.\"",
        "\"- � ���� ���� ��������� ���� ����, ������ ��� ��� ����� �������� ����.\"",
        "\"- �� �������, ��� ������ ��������� �� ����? ����������� � ����� ������.\""
    };
    NPC enchantress("���������������� �������", "�������������� ���������, ��������� ������ ������ � ��������� ������� ����.", enchantressPhrases);
    darkLordCastle.addInteractiveObject(&enchantress);

    vector<string> darkElfPhrases = {
        "\"- �� ������� � ��������� ������� ����. ����� ��� ����� ��� ������ �������� �������.\"",
        "\"- ������� ������� ���� ����, ��������. �� �� ������� ��� ��������������.\"",
        "\"- ����� �� ����� ����� ������, ����������. ���� ���� ����������� ������� ����.\"",
        "\"- �� ������������� � �����, ������ ������� �� ������ �� ���� �����. ����������� � ����.\"",
        "\"- ���� ������ ������, ��������. ����� ������� �������� �� ����.\""
    };
    NPC darkElf("������ �������� �������", "������ � ������� ������ ��������, ��������� ������� ����.", darkElfPhrases);
    darkLordCastle.addInteractiveObject(&darkElf);

    darkLordCastle.onEnter();

    // ���������� � ����� � ��������� ����
    Screen::displayText("\n����� ����������� ������������ ����� " + character.getName() + " �������, ��� ���������� � ����������� � �����.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n������ ���� ��������� � ������ ������ �����. ������ ��������� ����, ��������� ������� ����, ������ ��������� �� ������ ����������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n��� ��������� ����� ��������� ����� ������� �� ����� �����. �������, ������, ������, � ������ ����� - ��� ��� ������ ��������� ���� ������� ����.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n������ ����� ������ �� ������� �������, � " + character.getName() + " ��������, ��� ����� ��� ����� ���� �������� ���� - ������� ����.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n������ ���� ������ ������� �� ������ ���� �������. ����� ��������� � �����, ������� ������ �������� � �� ������.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n��������� ����������� ����������, � " + character.getName() + " �������� � ��� �� ����� ������ ��������� ����!");
    this_thread::sleep_for(chrono::milliseconds(1500));

    finalFight(character);

    chooseGameEnding(character);

    // ������� ������� ������� ����� ������������
    Screen::displayText("\n������� Enter, ����� ����������...");
    cin.ignore();
    cin.get();
}

// ����� ��������� �����
void finalFight(Character& character)
{
    CombatSystem fight;

    // �������������� ����������
    DarkLord darklord("������� ���� ��������", 600, 500, 400);
    Demon demon("�����-�������� �����", 550, 450, 450);
    Succubus succubus("������ ������", 500, 400, 500);
    Witch witch("������ �����", 550, 500, 450);
    Enchantress enchantress("���������������� �������", 500, 450, 500);
    DarkElf darkElf("������ �������� �������", 520, 480, 480);

    Screen::displayDialog("����������", "������� ����� �������� � ������ ������, �� �������� ��������� ��������� ���.");
    Screen::displayDialog("����������", "����� ���� ����������� �����-�������� �����, ������� �������� ���� ����.");
    Screen::displayDialog("�����-�������� �����", "���, �� �������� ����, ��������. �� ��� ����� ���� ��������� ���!");
    Screen::displayDialog(character.getName(), "� �� �����������, ���� �� ������� ���� ������ �����!");
    Screen::displayDialog("����� - �������� �����", "������, ������... ������ ���� ��������� ��������������!");

    // ��� � ����� - �������� �����
    Screen::displayDialog("����������", "� ���, ������ ������� �� ��� ����� - �������� �����!\n");
    fight.startGame(character, demon);

    // ��� � ������ ������
    Screen::displayDialog("����������", "������ �� ����� ������� ������ ������!");
    Screen::displayDialog("������ ������", "�, ��� ����� �����, � ������ ���� ���� ����� ���� � ����.");
    Screen::displayDialog(character.getName(), "���� ���������� ����� �� ������� ���� � ���� �����, ������!");
    Screen::displayDialog("������ ������", "�, � �� ��������� �������� ����. ����� �������� � ����� ������� � ������!");
    fight.startGame(character, succubus);

    // ��� � ������� �����
    Screen::displayDialog("����������", "��������� �� ������� �������� ������ �����!");
    Screen::displayDialog("������ �����", "�� �������, ��� ������ �������� ����, ���������? �� �������������.");
    Screen::displayDialog(character.getName(), "���� �������� �������� �� ��������� ����. ����������� � ������ ���������!");
    Screen::displayDialog("������ �����", "������ �����. ������� ��� �������, �� ��� �� ��������!");
    fight.startGame(character, witch);

    // ��� � ����������������� ��������
    Screen::displayDialog("����������", "������ � ��� �������� ���������������� �������!");
    Screen::displayDialog("���������������� �������", "��, ���������, �������� �� ������ �����. �� ��������� �� ���� ��������.");
    Screen::displayDialog(character.getName(), "���� ���� �� ������ ����. � ������, ��� ���� �� ����� ��������� ����!");
    Screen::displayDialog("���������������� �������", "���� ����� ����������. �������� � ���������!");
    fight.startGame(character, enchantress);

    // ��� � ������ ��������� ��������
    Screen::displayDialog("����������", "�� ��������� ����� ��� ���������� ������ �������� �������!");
    Screen::displayDialog("������ �������� �������", "�� ������ ������ �� ���� ������� ����? �� ����������� �� ���� ��������!");
    Screen::displayDialog(character.getName(), "���� ���� �� ������ ��������� ���� ���� ����. � ������� ���!");
    Screen::displayDialog("������ �������� �������", "������. �� � ���� ��� �� �� ������ �� ����� ������.");
    fight.startGame(character, darkElf);

    // ��� � ������� ������ - ������� ���� ��������
    Screen::displayDialog("����������", "�, �������, �� ����� ���������� ������� ���� ��������, ������� ���� ���� �������!");
    Screen::displayDialog("������� ���� ��������", "���, �� �������� �� ����, ��������. �� ���� ���� ������������� �����.");
    Screen::displayDialog(character.getName(), "��������, ���� ���� �� ������ ���� ����� ����. � ������ ��������� ���� ���������!");
    Screen::displayDialog("������� ���� ��������", "�� ������ ������� ����� ���, ������� ����? �� ������ ���������, ��� ������ ����.");
    Screen::displayDialog(character.getName(), "��������, ���� ���� �������������, �� � �� ������� �� ��������� ���� ���!");
    Screen::displayDialog("������� ���� ��������", "�� ���� ��������� ������ �� �����. ���� ���� �������� ����� ���� �����.");
    Screen::displayDialog(character.getName(), "���� �� ����� �������� ����, ��������. ��� ��� ������� ���� ����, � ���� ����� ���������!");
    Screen::displayDialog("������� ���� ��������", "�� �������� �����, ��������. �� � ������ ���� �������� ���� ����!");
    fight.startGame(character, darklord);
}

// ������� ��� ������ �������� ����
void chooseGameEnding(Character& character) 
{
    Screen::displayText("\n����� ������� ����� � �����, ������� ���� ����� ����������� ����� " + character.getName() + ".");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayDialog("������� ���� ��������", "��, ��������, ������� ������. �� ��� �� �������?");
    Screen::displayDialog("������� ���� ��������", "������� ����� ����? �� �� �� ����������� �������. � ��� ����� ����, ��� � ���� �����.");
    Screen::displayDialog("������� ���� ��������", "��� �� ������ ������ �����, ������� � ��� ����� ���������? ����� ����� ����������� �����, ������� ��������� ��� �����?");
    Screen::displayDialog("������� ���� ��������", "������ ���� �����, ��������, � �����, ��� ���� ������ ������ ���� � ���� ������.");

    // �������� ����� ������
    Screen::displayText("\n�������� ������� ���������� ����:");
    this_thread::sleep_for(chrono::milliseconds(1500));
    Screen::displayText("1. ����� ������� ���� � ���������� ���.");
    this_thread::sleep_for(chrono::milliseconds(1500));
    Screen::displayText("2. ������ ����� ������� ���� � ��������� ���� ���.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    // �������� ����� ������
    int choice;
    cout << "��� �����: ";

    // �������� ������� ������ ����� � ����� ����
    while (!(cin >> choice) || choice < 1 || choice > 2) {
        // ������� ������ �����
        cin.clear();
        // ������������� ���������� �������� � ������ �����
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // ������� ��������� �� ������ � ������ ������ ����� ������
        Screen::displayDialog("����������", "��, �������, �� ���-�� ������ �� ���. �������� 1 ��� 2, ����������.");
        cout << "\n��� �����: ";
    }

    // � ����������� �� ������ ������ ��������� ��������������� ��������
    switch (choice) {
    case 1:
        goodEnding(character);
        break;
    case 2:
        badEnding(character);
        break;
    default:
        break;
    }
}

// ������� ��� "�������" ��������
void goodEnding(Character& character)
{
    Screen::displayDialog("����������", "���� ��������� ����! � ������ ����� " + character.getName() + " ������ ������� ����, ��������� ��� �� ��� ������.");
    this_thread::sleep_for(chrono::milliseconds(500));

    Screen::displayDialog("����������", "���� �����������, � ������� �������� ������������. ���� ����� ������� ������� ������� ��������� ����� " + character.getName() + ".");
    this_thread::sleep_for(chrono::milliseconds(500));

    Screen::displayDialog("����������", character.getName() + " ���������� ��������, � ������� ������������ ������ ������. ��� ������� ������ � ������� ��� ������ ������� � ����.");
    this_thread::sleep_for(chrono::milliseconds(500));

    Screen::displayDialog("����������", "����� ��������� ������������� ������ � ������������ � ����� �����������, �� ��� ��� ��������� � ������� ���, ���� �� ����.");
    this_thread::sleep_for(chrono::milliseconds(500));
}

// ������� ��� "������" ��������
void badEnding(Character& character)
{
    Screen::displayDialog("����������", "� ������� ����, " + character.getName() + " ������ ��������������� ������ ������ ������� ����.");
    this_thread::sleep_for(chrono::milliseconds(500));

    Screen::displayDialog("����������", "���� ���� ���������� " + character.getName() + ". �� ���������� ����� �������� ����, ����������� ��� �����.");
    this_thread::sleep_for(chrono::milliseconds(500));

    Screen::displayDialog("����������", "��� ����������� �� ����, � ���� ���������� ��� ������. ������� �������, � ����� ������������� � ����������.");
    this_thread::sleep_for(chrono::milliseconds(500));

    Screen::displayDialog("����������", "����� " + character.getName() + " ���������� ���, �� ���� �� ��������� �������� ���. ����� ������� ���� ������ ������ ������������.");
    this_thread::sleep_for(chrono::milliseconds(500));

    Screen::displayDialog("����������", "� ����������� �������, �� �� ���, ��� ��������� ������ ����� ����. ������ ���� ��������� ���� � �������.");
    this_thread::sleep_for(chrono::milliseconds(500));
}

// ������� ��� �������� ������ � ����� � ����������� �� ������
pair<Weapon*, Magic*> createEquipment(string& className)
{
    Weapon* defaultWeapon = new Weapon("������ ���", 10, 3);       // ������ �� ���������
    Magic* defaultMagic = new Magic("������� ����������", 15, 5);  // ����� �� ���������

    if (className == "����") {
        return make_pair(new Weapon("��� �����", 25, 35), new Magic("������� ����", 15, 25));
    }
    else if (className == "���") {
        return make_pair(new Weapon("����� ����", 15, 15), new Magic("�������� �������", 30, 30));
    }
    else if (className == "���") {
        return make_pair(new Weapon("������ ����", 30, 25), new Magic("������� ����", 25, 30));
    }
    else if (className == "�������") {
        return make_pair(new Weapon("������ ������", 25, 25), new Magic("����� �����", 30, 30));
    }
    else if (className == "����") {
        return make_pair(new Weapon("������ ����", 25, 17), new Magic("������� �������", 25, 40));
    }
    else if (className == "������") {
        return make_pair(new Weapon("��� ������", 40, 30), new Magic("������ �����", 20, 15));
    }
    else {
        // �� ��������� ���������� ����������� ������ � �����
        return make_pair(defaultWeapon, defaultMagic);
    }
}

// ������� ��� �������� �������� �����
Character createMainCharacter()
{
    // ������ ��� �����
    Screen::displayDialog("����������", "������� �� �� ���� ���?");

    cout << "\n�����: ";
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayCharacterByCharacter("- ���� ����� ");

    string name;
    cin >> name;

    Screen::displayDialog("����������", "���� ��� ������ �����������, " + name + ". �� ����-�� �� �������....");

    // ������ �������������� ��� �����
    vector<string> adjectives = { "����������������", "�����������", "�������", "������������", "�������", "���������� ����", "��������", "�����������", "�����������", "�����������", "������", "�������", "�������������", "��������", "�����������", "��������������", "��������������", "������", "���������", "������������" };

    // ��������� ��������� �����
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, adjectives.size() - 1);

    // �������� ��������� ��������������
    int randomIndex = dist(gen);
    string randomAdjective = adjectives[randomIndex];

    // ��������� �������������� � ����� �����
    name = name + " " + randomAdjective;

    Screen::displayDialog("����������", "��� ������ - " + name + "?");

    // �������� �����
    vector<string> classes = { "����", "���", "���", "�������", "����", "������" };
    Screen::displayDialog("����������", "������ ����� ���, � ��� ��� ���������?");
    
    // ������� ������� � ���������������� �������
    cout << "\n+----+---------------+---------------+---------------+---------------+----------------------------------------+--------------------------------------------------+" << endl;
    Sleep(100);
    cout << "| #  |    �����      |   ��������    | ������������  |     ����      |                 ������                 |                      �����                       |" << endl;
    Sleep(100);
    cout << "+----+---------------+---------------+---------------+---------------+----------------------------------------+--------------------------------------------------+" << endl;

    for (int i = 0; i < classes.size(); ++i) {
        // �������� �������������� ������
        string className = classes[i];
        auto equipment = createEquipment(className);
        Weapon* weapon = equipment.first;
        Magic* magic = equipment.second;

        // ������� ���������� � �������
        cout << "| " << setw(1) << i + 1 << "  |" << setw(15) << left << className;

        // ������� �������������� � ����������� �� ������
        if (className == "����") {
            cout << "|" << setw(15) << left << 110 << "|";
            cout << setw(15) << left << 120 << "|";
            cout << setw(15) << left << 80 << "|";
        }
        else if (className == "���") {
            cout << "|" << setw(15) << left << 80 << "|";
            cout << setw(15) << left << 80 << "|";
            cout << setw(15) << left << 150 << "|";
        }
        else if (className == "���") {
            cout << "|" << setw(15) << left << 90 << "|";
            cout << setw(15) << left << 90 << "|";
            cout << setw(15) << left << 110 << "|";
        }
        else if (className == "�������") {
            cout << "|" << setw(15) << left << 110 << "|";
            cout << setw(15) << left << 110 << "|";
            cout << setw(15) << left << 110 << "|";
        }
        else if (className == "����") {
            cout << "|" << setw(15) << left << 110 << "|";
            cout << setw(15) << left << 90 << "|";
            cout << setw(15) << left << 110 << "|";
        }
        else if (className == "������") {
            cout << "|" << setw(15) << left << 140 << "|";
            cout << setw(15) << left << 100 << "|";
            cout << setw(15) << left << 100 << "|";
        }

        // ������� ���������� �� ������ � �����
        cout << setw(15) << left << weapon->getName() << " (dmg: " << setw(2) << weapon->getDamage() << ", stm: -" << setw(2) << weapon->getCost() << setw(6) << ")" << "|";
        cout << setw(25) << left << magic->getName() << " (dmg: " << setw(2) << magic->getDamage() << ", mana: -" << setw(2) << magic->getCost() << setw(5) << ")" << "|" << endl;
    }

    // ��������� �������
    cout << "+----+---------------+---------------+---------------+---------------+----------------------------------------+--------------------------------------------------+" << endl;

    int choice;

    // ����������� ����� ������������
    cout << "\n��� �����: ";

    // �������� ������� ������ ����� � ����� ����
    while (!(cin >> choice) || choice < 1 || choice > classes.size())
    {
        // ������� ������ �����
        cin.clear();
        // ������������� ���������� �������� � ������ �����
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // ������� ��������� �� ������ � ����������� ����� ������
        Screen::displayDialog("����������", "�� ���-�� �������, ��� �������. �������� ������� �����");
        cout << "\n��� �����: ";
    }

    // �������� �������� ���������� ������
    string className = classes[choice - 1];

    // ������������� ��������� � ������������
    Weapon* defaultWeapon = nullptr;
    Magic* defaultMagic = nullptr;

    // ������� ����� � �������� ����������� � ����������� �� ������
    Character mainCharacter(name, 100, 50, 50, defaultWeapon, defaultMagic, className);

    // �������� ��������� �� ������ � ����� � ����������� �� ������ � ������������� �� �����
    auto equipment = createEquipment(className);
    mainCharacter.setWeapon(equipment.first);
    mainCharacter.setMagic(equipment.second);

    if (className == "����")
    {
        mainCharacter.setHealth(110);
        mainCharacter.setStamina(120);
        mainCharacter.setMana(80);

        mainCharacter.setMaxHealth(mainCharacter.getHealth());
        mainCharacter.setMaxStamina(mainCharacter.getStamina());
        mainCharacter.setMaxMana(mainCharacter.getMana());
    }
    else if (className == "���")
    {
        mainCharacter.setHealth(80);
        mainCharacter.setStamina(80);
        mainCharacter.setMana(150);

        mainCharacter.setMaxHealth(mainCharacter.getHealth());
        mainCharacter.setMaxStamina(mainCharacter.getStamina());
        mainCharacter.setMaxMana(mainCharacter.getMana());
    }
    else if (className == "���")
    {
        mainCharacter.setHealth(90);
        mainCharacter.setStamina(90);
        mainCharacter.setMana(110);

        mainCharacter.setMaxHealth(mainCharacter.getHealth());
        mainCharacter.setMaxStamina(mainCharacter.getStamina());
        mainCharacter.setMaxMana(mainCharacter.getMana());
    }
    else if (className == "�������")
    {
        mainCharacter.setHealth(110);
        mainCharacter.setStamina(110);
        mainCharacter.setMana(110);

        mainCharacter.setMaxHealth(mainCharacter.getHealth());
        mainCharacter.setMaxStamina(mainCharacter.getStamina());
        mainCharacter.setMaxMana(mainCharacter.getMana());
    }
    else if (className == "����")
    {
        mainCharacter.setHealth(110);
        mainCharacter.setStamina(90);
        mainCharacter.setMana(110);

        mainCharacter.setMaxHealth(mainCharacter.getHealth());
        mainCharacter.setMaxStamina(mainCharacter.getStamina());
        mainCharacter.setMaxMana(mainCharacter.getMana());
    }
    else if (className == "������")
    {
        mainCharacter.setHealth(140);
        mainCharacter.setStamina(100);
        mainCharacter.setMana(100);

        mainCharacter.setMaxHealth(mainCharacter.getHealth());
        mainCharacter.setMaxStamina(mainCharacter.getStamina());
        mainCharacter.setMaxMana(mainCharacter.getMana());
    }

    // ������� ���������� � �����
    cout << "\n\t~~������������� ������ �����~~\n" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "���: " << mainCharacter.getName() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "�����: " << mainCharacter.getClassType() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "�������: " << mainCharacter.getLevel() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "��������: " << mainCharacter.getHealth() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "����: " << mainCharacter.getMana() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "������������: " << mainCharacter.getStamina() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "������: " << mainCharacter.getWeapon()->getName() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "�����: " << mainCharacter.getMagic()->getName() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));

    return mainCharacter;
}

// ��������� �.�������� ���������� ����������� � ��������� �������
void createEmerdealNPC(Location emerdeal, Character character)
{
    // ����������
    vector<string> innkeeperPhrases = {
        "\"- ����� ���������� � '������� ����', " + character.getName() + "! ��� ������� ��� ������� � ��� ���������� �������?\"",
        "\"- ���� �� ������ ������ ������ � ����� ������, ���������� � �������� ����������. �� ����� ����� �����������.\"",
        "\"- ����� ������ ���� ����� ������. � '������� ����' �� ������� �� ������ �������� �������, �� � �������� ��������.\"",
        "\"- ���������� ��� � ����� ������������, � � �������� ��� ��������� ������� ����� �����.\"",
        "\"- ����������� ������� ���������� ������. ������ ������ � ��������, ������� ����� �������� ���� ������.\""
    };
    NPC innkeeper(
        "���������� ������",
        "������ ������� '������� ����'. ������ - ����������� ������, ������� ������������ ���������� �������.\n"
        "� ��� ������� ������ ������ ��������� � �������� ����� ��������. ����� ����� ��������� ���������������� � ������� �������.",
        innkeeperPhrases
    );
    emerdeal.addInteractiveObject(&innkeeper);

    // �������
    vector<string> wardenPhrases = {
        "\"- ����� ���������� � ��������, " + character.getName() + ". � - ������� ��������, ������� ������.���� � ��� ���� �������,\n��������� �� ���, � ����� ������.��� ����� ������ ������ ��� ����� ������.\"",
        "\"- ����� �� ��������� ���� ���� � ������, �� �������� ��������� �� ���. ����� ����, � ���� ����� ��� ��� �������.\"",
        "\"- � ��������� ������ ����� ������� ���� ����. �� �������� ������ �������� � ������ ������ �������������� ����� ����������.\"",
        "\"- �� ������� ����� ����������, �� � ����� ������������. ���������� ���, �, ����� ����, �� ������� ������ ����� ������.\"",
        "\"- ��� ����� ����� �� ������ ��������, �� � ���������. �������� �����, ����� ����� ����������� ��� ����.\""
    };
    NPC warden(
        "������� ��������",
        "������� ���������. ������� �������� - ������� �����, ����������� ���� ����� ������ ������.\n"
        "��� ������������� � �������� ������� ��� ��������� �������, ������� ������������� �� ������������� ������.",
        wardenPhrases
    );
    emerdeal.addInteractiveObject(&warden);

    // ��� ���� ������ ������
    vector<string> citizenPhrases = {
        "\"- ����������� ���, " + character.getName() + "! ���� � ��� ���� ������� ��� ����� ����������, �����������. � ��������� ������ ���� ����� �����������.\"",
        "\"- ����� ��� ����� ���������� ����. ���� �� ������ ����������� �����, �������� �������� �� ���� ������� ����������. ��� ������� ������������ ����.\"",
        "\"- ������� � ���� ����� ������ ��������� �������� ������. �������, ��� ������ ��� ����� ������� � ��������. ����� ����, ��� ����� ���������?\"",
        "\"- ���� �� ����������� � ������, ���������� � �������. ��� ������ ������ ������ � ������� ������ �����������.\"",
        "\"- � ��������� ����� ����. ���� � ��� ���� �������� � ����� �����������, ��� ����� �� ����� ������.\""
    };
    NPC citizen(
        "����� �����",
        "������� ����������. ����� - ������ � ���������� �������.\n"
        "��� ����� ����� ���������� ������� � ������ � ��� �������.",
        citizenPhrases
    );
    emerdeal.addInteractiveObject(&citizen);

    // ������� �������
    gameTitle();

    // ������ � ��������� �������
    emerdeal.onEnter();
}

// ��������� �����
void displayFinalCredits()
{
    gameTitle();

    Screen::displayText("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayText("                                       END OF GAME\n");
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayText("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayDialog("����������", "� ��� �� ������� � ���������� ������ �������������� �����������.\n            �������, ��� ���� � ���� � ��������� ������� � ���� ������������� �������.\n            ��������, ��� ��� ����������� ����������� �� ���� �������� � �����������.");

    cout << "\n\n";

    Screen::displayDialog("����������", "�����, �� �������� ��������, �������� � ���� � ���� ����.\n            ���� ������� �������� ���� ����, � ���� ������� ����� ������ �������.\n            ���������� ��� �� ������� � ���� ������������� �����������!");

    cout << "\n\n";

    Screen::displayDialog("����������", "���� �� ���������, �������: � ���� �������� ������ ���� ����� �����������.\n            �� ����� ������, �����! ����� ������ ��� ������������!");

    Screen::displayText("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    // ������� ������� ������� ����� ������������
    Screen::displayText("\n������� Enter, ����� ����������...");
    cin.ignore();
    cin.get();
}