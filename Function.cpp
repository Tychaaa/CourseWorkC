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

            cout << "\n����� ���������� ������� ����� ������" << endl;
            _getch();

            gameTitleSlow();
            break;
        case 3:
            // ����� �� ����
            cout << "\n����������: \"�� ������, ��� ������ �������� ���� ������������� ���? ���� ����� ������ �����������!\"\n";
            exit(0);  // ��������� ���������
            break;
        default:
            cout << "\n����������: \"- �� ���-�� �������, ��� �������. ������� ������������.\"" << endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
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

    cout << "\n����������: \"- ������� ��� ���� ������ ����. �� ������� ���������� ���������� ����� ���������. ���� � �������������.\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "\n����������: \"- �����, " << character.getName() << "!\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    // ������� ������� ������� ����� ������������
    cout << "\n������� Enter, ����� ����������...";
    cin.ignore();
    cin.get();
}

// ����� "������"
void prologue(Character& character)
{
    gameTitle();

    // ������� �� ��������� � ������������ � ������ �����������
    cout << "\n���������� ���� ������� ������, ����� �� ������� ��������� �� �������� �����������." << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n�� ������������� � ����... ������� ��������� �������, ������� �� ������� ������." << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n�� ������� ����� ������ �������, ������������ ���-��� ����������� � ����." << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));
}

// ������� ��� �������� ������ � ����� � ����������� �� ������
pair<Weapon*, Magic*> createEquipment(string& className)
{
    Weapon* defaultWeapon = new Weapon("������ ���", 10, 3);       // ������ �� ���������
    Magic* defaultMagic = new Magic("������� ����������", 15, 5);  // ����� �� ���������

    if (className == "����") {
        return make_pair(new Weapon("��� �����", 20, 8), new Magic("������� ����", 12, 20));
    }
    else if (className == "���") {
        return make_pair(new Weapon("����� ����", 15, 5), new Magic("�������� �������", 25, 10));
    }
    else if (className == "���") {
        return make_pair(new Weapon("������ ����", 18, 6), new Magic("������� ����", 15, 15));
    }
    else if (className == "�������") {
        return make_pair(new Weapon("������ ������", 15, 3), new Magic("������ �����", 10, 18));
    }
    else if (className == "����") {
        return make_pair(new Weapon("������ ����", 17, 7), new Magic("���������", 20, 12));
    }
    else if (className == "������") {
        return make_pair(new Weapon("��� ������", 22, 10), new Magic("������������� ����", 10, 20));
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
    
    // ������� ������� � ���������������� �������
    cout << "+----+---------------+---------------+---------------+---------------+----------------------------------------+--------------------------------------------------+" << endl;
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
    cout << "\n��� �����: ";
    cin >> choice;

    // �������� ������������ �����
    while (choice < 1 || choice > classes.size()) {
        cout << "\n����������: \"- �� ���-�� �������, ��� �������. �������� ������� �����: \"";
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
        mainCharacter.setHealth(110);
        mainCharacter.setStamina(120);
        mainCharacter.setMana(80);
    }
    else if (className == "���") {
        mainCharacter.setHealth(80);
        mainCharacter.setStamina(80);
        mainCharacter.setMana(150);
    }
    else if (className == "���") {
        mainCharacter.setHealth(90);
        mainCharacter.setStamina(90);
        mainCharacter.setMana(110);
    }
    else if (className == "�������") {
        mainCharacter.setHealth(110);
        mainCharacter.setStamina(110);
        mainCharacter.setMana(110);
    }
    else if (className == "����") {
        mainCharacter.setHealth(110);
        mainCharacter.setStamina(90);
        mainCharacter.setMana(110);
    }
    else if (className == "������") {
        mainCharacter.setHealth(140);
        mainCharacter.setStamina(100);
        mainCharacter.setMana(100);
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
