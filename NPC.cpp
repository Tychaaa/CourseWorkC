#include "NPC.h"

// Конструктор
NPC::NPC() : InteractiveObject() {}

// Конструктор с параметрами
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

// Деструктор
NPC::~NPC() {}

// Функция для взаимодействия с не игровым персонажем
void NPC::interact()
{
    // Выбираем случайную фразу из набора, исключая приветствие, если есть другие фразы
    if (!talkPhrases.empty()) {
        int randomIndex = rand() % talkPhrases.size();
        Screen::displayText("\n" + getName() + " говорит: " + talkPhrases[randomIndex]);
        // Удаляем использованную фразу
        talkPhrases.erase(talkPhrases.begin() + randomIndex);
    }
    else {
        Screen::displayText("\n" + getName() + " говорит: Иди своей дорогой, путник!");
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
        Screen::displayText("\nВы осматриваете \"" + getName() + "\".\n" + getDescription());
        break;

    default:
        Screen::displayText("Неподдерживаемое действие.");
        break;
    }
}
