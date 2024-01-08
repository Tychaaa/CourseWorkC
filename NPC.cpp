#include "NPC.h"

// Конструктор
NPC::NPC() : InteractiveObject() {}

// Конструктор с параметрами 1
NPC::NPC(const string& n, const string& desc) : InteractiveObject(n, desc) 
{
    // Инициализация фраз NPC
    talkPhrases.push_back("Привет, путник!");
    talkPhrases.push_back("Добро пожаловать в этот мир!");
    talkPhrases.push_back("Что привело тебя сюда?");
    talkPhrases.push_back("Будь осторожен, в этих землях не всегда спокойно.");
    talkPhrases.push_back("Ты уже давно здесь?");
    talkPhrases.push_back("Помни, здесь могут быть опасности за каждым углом.");
    talkPhrases.push_back("Если у тебя есть вопросы, спрашивай.");
    talkPhrases.push_back("Не все здесь такие, как кажутся.");
    talkPhrases.push_back("Говорят, в этом мире много тайн.");
    talkPhrases.push_back("Будь готов ко всему.");
}

// Конструктор с параметрами 2
NPC::NPC(const string& n, const string& desc, vector<string> phrases) : InteractiveObject(n, desc)
{
    // Инициализация фраз NPC
    talkPhrases = move(phrases);
}

// Деструктор
NPC::~NPC() {}

// Функция для взаимодействия с не игровым персонажем
void NPC::interact()
{
    // Выводим фразы по порядку
    if (!talkPhrases.empty()) {
        cout << "\n" << getName() << ":";
        this_thread::sleep_for(chrono::milliseconds(500));
        Screen::displayCharacterByCharacter(talkPhrases.front() + "\n");

        // Удаляем использованную фразу
        talkPhrases.erase(talkPhrases.begin());
    }
    else {
        cout << "\n" << getName() << ":";
        this_thread::sleep_for(chrono::milliseconds(500));
        Screen::displayCharacterByCharacter("- Иди своей дорогой, путник!\n");
    }
}

// Функция для получения вариантов действий
vector<Action> NPC::getAvailableActions() const
{
	// Возвращаем действия для NPC
	vector<Action> actions;
	actions.push_back(Action(Action::ActionType::Talk, "Поговорить"));
	actions.push_back(Action(Action::ActionType::Examine, "Осмотреть"));
	return actions;
}

// Функциядля обработки выбранного действия
void NPC::performAction(Action& action)
{
    switch (action.getType()) {
    // Действие "Поговорить"
    case Action::ActionType::Talk:
        interact();
        break;

    // Действие "Осмотреть"
    case Action::ActionType::Examine:
        Screen::displayCharacterByCharacter("\nВы осматриваете \"" + getName() + "\".\n" + getDescription());
        cout << endl;
        break;

    default:
        Screen::displayText("Неподдерживаемое действие.");
        break;
    }
}
