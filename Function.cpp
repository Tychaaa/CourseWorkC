#include "Function.h"

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
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << "\n" << endl;

    Sleep(1200);
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

    do {

        gameTitle();

        cout << "������� ����:\n" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "1. ������ ����" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "2. ������" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "3. ����� �� ����" << endl;

        cout << "\n�������� �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // ������ ����
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

            cout << "\n����� ���������� ������� ����� ������" << endl;
            _getch();
            break;
        case 3:
            // ����� �� ����
            cout << "\n�� ��������! ������� �� ����.\n";
            exit(0);  // ��������� ���������
            break;
        default:
            cout << "\n�������� �����. ����������, �������� ������������ �������.\n";
            break;
        }
    } while (choice != 1);  // ���� ������������, ���� ������������ �� ������� "������ ����"
}

// ����� "������"
void introduction(Character character)
{
    // ������� � ����
    cout << "\n����� ���������� � ������������� ��� �����������!" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "\n������-�����, � ������������ ����, ��� ���� � ���� ������� ������ �����, �������� ���� �����������." << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n�����, ����� ������� ���� � ��������������� ������, ������ ��� ����� �������� � �������� ����� ��� ����������� ���������." << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n������ ���, ��������� �������� � ����� ���� ������� ��������������� �����." << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n���� ��� ������ ����� ������, ������� ������� ��� �� ��������." << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n� ��� �� ������������, ������, ��� ���� ��������� ������, � ��� ��� ���� ����������� ���������." << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n����� �������� � ����� ������!" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n����������: \"- ������, ������! �� ��������� � ����, ��� ������ �������, ������ ��������,\n����� �������� �� ������ ����� ����. � - ���� ��������� � ���� ������������ �����������.\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(2500));

    cout << "\n\"- ��� ��? ��� �?\" - ����������� ��, ������ ��������� ���� � ���� ���������� ����." << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n����������: \"- ���� ����� ������, ���������� ����� ����. ��� ������ ���� �������.\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n����������: \"- � �� � ���, ��� ������� ��� �������. ���� ��� ���� ������, �� ��� ������ ��������.\n�� ������� �����, � ���� ����� ��������� ������ ����� ����.\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(2500));

    // �������� � �������� �������� �����
    cout << "\n����������: \"- ����������, � ���� ���� ��������� ��������... ������� �� ������� �����������, ��� ��������� ���� ������.\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    character = createMainCharacter();

    cout << "\n����������: \"- ������ �� ������ ������ ���� �����������! �����, " << character.getName() << "!\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    // ������� ������� ������� ����� ������������
    cout << "\n������� Enter, ����� ����������...";
    cin.ignore();
    cin.get();
}

// ������� ��� �������� �������� �����
Character createMainCharacter()
{
    // ������ ������� ������ � �����
    Weapon* sword = new Weapon("��� ��������", 20, 5);
    Magic* fireball = new Magic("�������� �������", 30, 10);

    cin.ignore();

    // ������ ��� �����
    cout << "\n����������: \"- ������� �� �� ���� ���?\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n���� �����: ";
    string name;
    cin >> name;

    cout << "\n����������: \"- ���� ��� ������ �����������, " << name << ". �� ����-�� �� �������....\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    // ������ �������������� ��� �����
    vector<string> adjectives = { "����������������", "�����������", "�������", "������������", "�������", "���������� ����", "��������", "�����������", "�����������", "�����������" };

    // �������� ��������� ��������������
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % adjectives.size();
    string randomAdjective = adjectives[randomIndex];

    // ��������� �������������� � ����� �����
    name = name + " " + randomAdjective;

    cout << "\n����������: \" - ��� ������ - " << name << "?\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    // ������� ����� � �������� �����������
    Character mainCharacter(name, 100, 50, 50, sword, fireball);

    // ������� ���������� � �����
    cout << "\n\t~~������������� ������ �����~~\n" << endl;
    cout << "���: " << mainCharacter.getName() << endl;
    cout << "�������: " << mainCharacter.getLevel() << endl;
    cout << "��������: " << mainCharacter.getHealth() << endl;
    cout << "����: " << mainCharacter.getMana() << endl;
    cout << "������������: " << mainCharacter.getStamina() << endl;

    return mainCharacter;
}
