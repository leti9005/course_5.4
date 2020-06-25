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
    wcout << L"���: ";
    cin >> block.name;
    wcout << L"�������: ";
    cin >> block.surname;
    wcout << L"�������: ";
    cin >> block.disease;
    wcout << L"�����: ";
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
        wcout << L"������ ������ �����.\n";
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
            wcout << L"������ ������.\n";
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
        wcout << L"������� ���������.\n";
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
        wcout << L"������ ������ �����.\n";
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
        wcout << L"������� ��������.\n";
        system("pause");
    }
}
void lst::printBlock()
{
    Block* bTemp = bHead;
    int i = 1;
    wcout << L"\n���������� �������: " << bN << "\n";
    while (i - 1 < bN)
    {
        wcout << L"�����: " << bTemp->number << "\n";
        wcout << L"���: " << bTemp->name << "\n";
        wcout << L"�������:  " << bTemp->surname << "\n";
        wcout << L"�������: " << bTemp->disease << "\n\n";
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
            wcout << L"\n������ �������. #" << bTemp->number << endl;
            wcout << L"���: " << bTemp->name << endl;
            wcout << L"�������: " << bTemp->surname << endl;
            wcout << L"�������: " << bTemp->disease << endl;
        }
        bTemp = bTemp->bNext;
        i++;
        suc = 1;
    }
    if (suc == 0)
    {
        wcout << L"������ � ����� ������� ��� � ����";
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
            wcout << L"\n������ �������. #" << bTemp->number << endl;
            wcout << L"���: " << bTemp->name << endl;
            wcout << L"�������: " << bTemp->surname << endl;
            wcout << L"�������: " << bTemp->disease << endl;
        }
        bTemp = bTemp->bNext;
        i++;
        suc = 1;
    }
    if (suc == 0)
    {
        wcout << L"������ � ����� �������� ��� � ����";
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
            wcout << L"\n������ �������. #" << bTemp->number << endl;
            wcout << L"���: " << bTemp->name << endl;
            wcout << L"�������: " << bTemp->surname << endl;
            wcout << L"�������: " << bTemp->disease << endl;
        }
        bTemp = bTemp->bNext;
        i++;
        suc = 1;
    }
    if (suc == 0)
    {
        wcout << L"������ � ����� �������� ��� � ����";
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
            wcout << L"\n������ �������. #" << bTemp->number << endl;
            wcout << L"���: " << bTemp->name << endl;
            wcout << L"�������: " << bTemp->surname << endl;
            wcout << L"�������: " << bTemp->disease << endl;
            bTarget = bTemp;
        }
        bTemp = bTemp->bNext;
        i++;
        suc = 1;
    }
    if (suc == 1)
    {
        wcout << L"\n����� ���� �� ������ ��������?" << endl;
        wcout << L"1 - �������" << endl;
        wcout << L"2 - ���" << endl;
        wcout << L"3 - �������" << endl;
        wcout << L"-> ";
        cin >> sel;
        switch (sel)
        {
        case 1:
            wcout << L"������� ����� �������: ";
            cin >> newField;
            strcpy(bTarget->surname, newField);
            system("pause");
        case 2:
            wcout << L"������� ����� ���: ";
            cin >> newField;
            strcpy(bTarget->name, newField);
            system("pause");
        case 3:
            wcout << L"������� ����� �������: ";
            cin >> newField;
            strcpy(bTarget->disease, newField);
            system("pause");
        }
    }
    if (suc == 0)
    {
        wcout << L"������ � ����� �������� ��� � ����";
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
            wcout << L"\n������ �������. #" << bTemp->number << endl;
            wcout << L"���: " << bTemp->name << endl;
            wcout << L"�������: " << bTemp->surname << endl;
            wcout << L"�������: " << bTemp->disease << endl;
            bTarget = bTemp;
            suc = 1;
        }

        bTemp = bTemp->bNext;
        i++;
        
    }
    if (suc == 1)
    {
        wcout << L"�� ������������� ������ ������� ��� ������?" << endl;
        wcout << L"1 - ��" << endl;
        wcout << L"2 - ���" << endl;
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
            wcout << L"������ ������� �������.\n";
            system("pause");
            break;
        }
        case 2:
            break;
        }
    }
    if (suc == 0)
    {
        wcout << L"������ � ����� ������� ��� � ����.\n";
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
        wcout << L"�������� ������� ������ 9005 ������ ���� \n";
        wcout << L"����: \n";
        wcout << L"1 - ������ ������ \n";
        wcout << L"2 - ��������� ������ �� ����� \n";
        wcout << L"3 - �������� ��������� � ���� \n\n";
        wcout << L"4 - ������� ������\n";
        wcout << L"5 - �����\n\n";
        wcout << L"6 - �������� \n";
        wcout << L"7 - ������� \n\n";
        wcout << L"0 - ����� \n\n";
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
            wcout << L"��� �� ������ ����� ������?\n";
            wcout << L"1 - �� ������" << endl;
            wcout << L"2 - �� �������" << endl;
            wcout << L"3 - �� �������" << endl;
            cin >> sel;
            switch (sel)
            {
            case 1:
                system("cls");
                wcout << L"������� �����: ";
                cin >> x;
                List.seekNumber(x);
                system("pause");
                break;
            case 2:
                system("cls");
                wcout << L"������� �������: ";
                cin >> surname;
                List.seekSurname(surname);
                system("pause");
                break;
            case 3:
                system("cls");
                wcout << L"������� �������: ";
                cin >> disease;
                List.seekDisease(disease);
                system("pause");
                break;
            }
            break;
        case 6:
            system("cls");
            wcout << L"����� ������ �� ������ ��������?\n=> ";
            cin >> x;
            List.update(x);
            break;
        case 7:
            system("cls");
            wcout << L"����� ������ �� ������ �������?\n=> ";
            cin >> x;
            List.deleteBlock(x);
            break;
        case 0:
            exit(0);
        }
    }
}
