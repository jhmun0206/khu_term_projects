#ifndef DIRECTOR_H
#define DIRECTOR_H
#include <string>
#include <iostream>
#include <cassert>
#include "Vacation.h"
using namespace std;

// ���� ����� ���� Director Ŭ����
class  Director
{
public:
    static Vacation* vacation;
    static void book(int type); // Ŭ���̾�Ʈ�� �� �Լ��� ȣ�� ����
};
#endif 