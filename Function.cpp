#include "Function.h"

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

    do {

        gameTitleSlow();

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
            //prodTitle();
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
            cout << "\n����� ���������� ������� ����� ������" << endl;
            _getch();
            break;
        }
    } while (choice != 1);  // ���� ������������, ���� ������������ �� ������� "������ ����"
}

// ����� "������"
void introduction(Character character)
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

// ������� ��� �������� ������ � ����� � ����������� �� ������
pair<Weapon*, Magic*> createEquipment(string& className)
{
    Weapon* defaultWeapon = new Weapon("������ ���", 10, 3);       // ������ �� ���������
    Magic* defaultMagic = new Magic("������� ����������", 15, 5);  // ����� �� ���������

    if (className == "����") {
        return make_pair(new Weapon("��� �����", 20, 5), new Magic("������� ����", 10, 15));
    }
    else if (className == "���") {
        return make_pair(new Weapon("����� ����", 15, 8), new Magic("�������� ���", 25, 10));
    }
    else if (className == "���") {
        return make_pair(new Weapon("������ ����", 18, 6), new Magic("����", 12, 18));
    }
    else if (className == "�������") {
        return make_pair(new Weapon("������ ������", 15, 3), new Magic("��������", 8, 20));
    }
    else if (className == "����") {
        return make_pair(new Weapon("������ ����", 17, 7), new Magic("���������", 20, 12));
    }
    else if (className == "������") {
        return make_pair(new Weapon("��� ������", 22, 4), new Magic("�������� ������", 15, 15));
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
    cout << "\n����������: \"- ������� �� �� ���� ���?\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n�����: - ���� ����� ";
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

    // �������� �����
    vector<string> classes = { "����", "���", "���", "�������", "����", "������" };
    cout << "\n����������: \"- ������ ����� ���, � ��� ��� ���������?\"\n" << endl;
    for (int i = 0; i < classes.size(); ++i) {
        cout << i + 1 << ". " << classes[i] << endl;
    }

    int choice;
    cout << "\n��� �����: ";
    cin >> choice;

    // �������� ������������ �����
    while (choice < 1 || choice > classes.size()) {
        cout << "������������ �����. ����������, �������� �����: ";
        cin >> choice;
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

    if (className == "����") {
        mainCharacter.setHealth(120);
        mainCharacter.setStamina(60);
        mainCharacter.setMana(40);
    }
    else if (className == "���") {
        mainCharacter.setHealth(80);
        mainCharacter.setStamina(40);
        mainCharacter.setMana(80);
    }
    else if (className == "���") {
        mainCharacter.setHealth(100);
        mainCharacter.setStamina(80);
        mainCharacter.setMana(30);
    }
    else if (className == "�������") {
        mainCharacter.setHealth(90);
        mainCharacter.setStamina(70);
        mainCharacter.setMana(40);
    }
    else if (className == "����") {
        mainCharacter.setHealth(100);
        mainCharacter.setStamina(50);
        mainCharacter.setMana(70);
    }
    else if (className == "������") {
        mainCharacter.setHealth(110);
        mainCharacter.setStamina(70);
        mainCharacter.setMana(50);
    }

    // ������� ���������� � �����
    cout << "\n\t~~������������� ������ �����~~\n" << endl;
    cout << "���: " << mainCharacter.getName() << endl;
    cout << "�����: " << mainCharacter.getClassType() << endl;
    cout << "�������: " << mainCharacter.getLevel() << endl;
    cout << "��������: " << mainCharacter.getHealth() << endl;
    cout << "����: " << mainCharacter.getMana() << endl;
    cout << "������������: " << mainCharacter.getStamina() << endl;
    cout << "������: " << mainCharacter.getWeapon()->getName() << endl;
    cout << "�����: " << mainCharacter.getMagic()->getName() << endl;

    return mainCharacter;
}
