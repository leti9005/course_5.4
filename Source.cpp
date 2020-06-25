#define _CRT_SECURE_NO_WARNINGS
#include <iostream>                                                                        
#include <string.h>                                                                              
#include <stdlib.h>                                                                              
#include <fstream>                                                                               

using namespace std;

int bN = 0;

struct Block
{
    char name[100];
    char surname[100];
    char disease[254];
    int number;

    Block* bNext;
};
class lst
{
    Block* bHead;

public:
    void addBlock(Block& block);
    void write();
    void read(Block& block);
    void printBlock();
    void seekNumber(int x);
    void seekSurname(string surname);
    void seekDisease(string disease);
    void update(int x);
    void deleteBlock(int x);
    Block* FindPrevByNumber(int x);
};

FILE* bF;

void lst::addBlock(Block& block)
{
    cout << endl;
    wcout << L"Имя: ";
    cin >> block.name;
    wcout << L"Фамилия: ";
    cin >> block.surname;
    wcout << L"Болезнь: ";
    cin >> block.disease;
    wcout << L"Номер: ";
    cin >> block.number;

    Block* bTemp = new Block;
    bTemp->bNext = bHead;
    strcpy(bTemp->name, block.name);
    strcpy(bTemp->surname, block.surname);
    strcpy(bTemp->disease, block.disease);
    bTemp->number = block.number;
    bHead = bTemp;
    bN++;

}
void lst::read(Block& block)
{
    int suc = 0;
    int i = 0;

    if ((bF = fopen("block.dat", "r")) == nullptr)
    {
        wcout << L"Ошибка записи файла.\n";
        suc++;
        system("pause");
    }
    else
    {
        while ((feof(bF)) == 0)
        {
            fread(&block.name, sizeof(block.name), 1, bF);
            fread(&block.surname, sizeof(block.surname), 1, bF);
            fread(&block.disease, sizeof(block.disease), 1, bF);
            fread(&block.number, sizeof(block.number), 1, bF);
            if ((feof(bF)) != 0)
                break;
            wcout << L"Чтение записи.\n";
            Block* bTemp = new Block;
            bTemp->bNext = bHead;
            strcpy(bTemp->name, block.name);
            strcpy(bTemp->surname, block.surname);
            strcpy(bTemp->disease, block.disease);
            bTemp->number = block.number;
            bN++;
            bHead = bTemp;

        }
    }
    fclose(bF);

    if (suc == 0)
    {
        wcout << L"Успешно загружено.\n";
        system("pause");
    }

}
void lst::write()
{
    Block* bTemp = bHead;
    int suc = 0;
    int i = 0;
    if ((bF = fopen("block.dat", "w")) == nullptr)
    {
        wcout << L"Ошибка записи файла.\n";
        suc++;
        system("pause");
    }
    else
    {
        while (i < bN)
        {

            fwrite(&bTemp->name, sizeof(bTemp->name), 1, bF);
            fwrite(&bTemp->surname, sizeof(bTemp->surname), 1, bF);
            fwrite(&bTemp->disease, sizeof(bTemp->disease), 1, bF);
            fwrite(&bTemp->number, sizeof(bTemp->number), 1, bF);
            bTemp = bTemp->bNext;
            i++;
        }
    }
    fclose(bF);

    if (suc == 0)
    {
        wcout << L"Успешно записано.\n";
        system("pause");
    }
}
void lst::printBlock()
{
    Block* bTemp = bHead;
    int i = 1;
    wcout << L"\nКоличество записей: " << bN << "\n";
    while (i - 1 < bN)
    {
        wcout << L"Номер: " << bTemp->number << "\n";
        wcout << L"Имя: " << bTemp->name << "\n";
        wcout << L"Фамилия:  " << bTemp->surname << "\n";
        wcout << L"Болезнь: " << bTemp->disease << "\n\n";
        bTemp = bTemp->bNext;
        i++;
    }
}
void lst::seekNumber(int x)
{
    Block* bTemp = bHead;
    int suc = 0;
    int i = 0;
    while (i < bN)
    {
        if (x == bTemp->number)
        {
            wcout << L"\nЗапись найдена. #" << bTemp->number << endl;
            wcout << L"Имя: " << bTemp->name << endl;
            wcout << L"Фамилия: " << bTemp->surname << endl;
            wcout << L"Болезнь: " << bTemp->disease << endl;
        }
        bTemp = bTemp->bNext;
        i++;
        suc = 1;
    }
    if (suc == 0)
    {
        wcout << L"Записи с таким номером нет в базе";
    }
}
void lst::seekSurname(string surname)
{
    Block* bTemp = bHead;
    int suc = 0;
    int i = 0;
    while (i < bN)
    {
        if (surname == bTemp->surname)
        {
            wcout << L"\nЗапись найдена. #" << bTemp->number << endl;
            wcout << L"Имя: " << bTemp->name << endl;
            wcout << L"Фамилия: " << bTemp->surname << endl;
            wcout << L"Болезнь: " << bTemp->disease << endl;
        }
        bTemp = bTemp->bNext;
        i++;
        suc = 1;
    }
    if (suc == 0)
    {
        wcout << L"Записи с таким фамилией нет в базе";
    }
}
void lst::seekDisease(string disease)
{
    Block* bTemp = bHead;
    int suc = 0;
    int i = 0;
    while (i < bN)
    {
        if (disease == bTemp->disease)
        {
            wcout << L"\nЗапись найдена. #" << bTemp->number << endl;
            wcout << L"Имя: " << bTemp->name << endl;
            wcout << L"Фамилия: " << bTemp->surname << endl;
            wcout << L"Болезнь: " << bTemp->disease << endl;
        }
        bTemp = bTemp->bNext;
        i++;
        suc = 1;
    }
    if (suc == 0)
    {
        wcout << L"Записи с такой болезнью нет в базе";
    }
}
void lst::update(int x)
{
    Block* bTemp = bHead;
    Block* bTarget = bHead;
    int suc = 0;
    int i = 0;
    int sel = 0;
    char newField[100];
    while (i < bN)
    {
        if (x == bTemp->number)
        {
            wcout << L"\nЗапись найдена. #" << bTemp->number << endl;
            wcout << L"Имя: " << bTemp->name << endl;
            wcout << L"Фамилия: " << bTemp->surname << endl;
            wcout << L"Болезнь: " << bTemp->disease << endl;
            bTarget = bTemp;
        }
        bTemp = bTemp->bNext;
        i++;
        suc = 1;
    }
    if (suc == 1)
    {
        wcout << L"\nКакое поле вы хотите обновить?" << endl;
        wcout << L"1 - Фамилия" << endl;
        wcout << L"2 - Имя" << endl;
        wcout << L"3 - Болезнь" << endl;
        wcout << L"-> ";
        cin >> sel;
        switch (sel)
        {
        case 1:
            wcout << L"Введите новую фамилию: ";
            cin >> newField;
            strcpy(bTarget->surname, newField);
            system("pause");
        case 2:
            wcout << L"Введите новое имя: ";
            cin >> newField;
            strcpy(bTarget->name, newField);
            system("pause");
        case 3:
            wcout << L"Введите новую болезнь: ";
            cin >> newField;
            strcpy(bTarget->disease, newField);
            system("pause");
        }
    }
    if (suc == 0)
    {
        wcout << L"Записи с такой болезнью нет в базе";
    }
}
void lst::deleteBlock(int x)
{
    Block* bTemp = bHead;
    Block* bTarget = bHead;

    int suc = 0;
    int i = 0;
    int sel = 0;
    while (i < bN)
    {
        if (x == bTemp->number)
        {
            wcout << L"\nЗапись найдена. #" << bTemp->number << endl;
            wcout << L"Имя: " << bTemp->name << endl;
            wcout << L"Фамилия: " << bTemp->surname << endl;
            wcout << L"Болезнь: " << bTemp->disease << endl;
            bTarget = bTemp;
            suc = 1;
        }

        bTemp = bTemp->bNext;
        i++;
        
    }
    if (suc == 1)
    {
        wcout << L"Вы действительно хотите удалить эту запись?" << endl;
        wcout << L"1 - Да" << endl;
        wcout << L"2 - Нет" << endl;
        cin >> sel;
        switch (sel)
        {
        case 1:
        {
            auto* p = FindPrevByNumber(x);
            if (!p)
            {
                p = bHead;
                bHead = bHead->bNext;
                delete p;
            }
            else if (p->bNext)
            {
                auto* p2 = p->bNext;
                p->bNext = p2->bNext;
                delete p2;
            }
            bN -= 1;
            wcout << L"Запись успешно удалена.\n";
            system("pause");
            break;
        }
        case 2:
            break;
        }
    }
    if (suc == 0)
    {
        wcout << L"Записи с таким номером нет в базе.\n";
        system("pause");
    }
}
Block* lst::FindPrevByNumber(int x)
{
    if (!bHead || bHead->number == x)
        return nullptr;

    Block* bDel = bHead;
    while (bDel->bNext && bDel->bNext->number != x)
        bDel = bDel->bNext;
    return bDel;
}


int main()
{
    setlocale(0, "");
    while (true)
    {
        int sel = 0;
        int x = 0; string surname; string disease;
        lst List;
        Block block;

        system("cls");
        wcout << L"Выполнил студент группы 9005 Зайцев Илья \n";
        wcout << L"Меню: \n";
        wcout << L"1 - Ввести данные \n";
        wcout << L"2 - Загрузить данные из файла \n";
        wcout << L"3 - Записать изменения в файл \n\n";
        wcout << L"4 - Вывести список\n";
        wcout << L"5 - Найти\n\n";
        wcout << L"6 - Изменить \n";
        wcout << L"7 - Удалить \n\n";
        wcout << L"0 - Выход \n\n";
        cout << "-> ";
        cin >> sel;

        switch (sel)
        {
        case 1:
            List.addBlock(block);
            break;
        case 2:
            List.read(block);
            break;
        case 3:
            List.write();
            break;
        case 4:
            List.printBlock();
            system("pause");
            break;
        case 5:
            system("cls");
            wcout << L"Как вы хотите найти запись?\n";
            wcout << L"1 - По номеру" << endl;
            wcout << L"2 - По фамилии" << endl;
            wcout << L"3 - По болезни" << endl;
            cin >> sel;
            switch (sel)
            {
            case 1:
                system("cls");
                wcout << L"Введите номер: ";
                cin >> x;
                List.seekNumber(x);
                system("pause");
                break;
            case 2:
                system("cls");
                wcout << L"Введите фамилию: ";
                cin >> surname;
                List.seekSurname(surname);
                system("pause");
                break;
            case 3:
                system("cls");
                wcout << L"Введите болезнь: ";
                cin >> disease;
                List.seekDisease(disease);
                system("pause");
                break;
            }
            break;
        case 6:
            system("cls");
            wcout << L"Какую запись вы хотите обновить?\n=> ";
            cin >> x;
            List.update(x);
            break;
        case 7:
            system("cls");
            wcout << L"Какую запись вы хотите удалить?\n=> ";
            cin >> x;
            List.deleteBlock(x);
            break;
        case 0:
            exit(0);
        }
    }
}
