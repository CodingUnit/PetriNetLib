// petrinet_lib_cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "pch.h"
//#include <iostream>

#include "tuple.h"
#include "buffer_utils.h"
#include "memory.h"

using namespace petrinet_lib;

//typedef tuple4<int, long, int, bytes8> can_message;

class can_message
{


public:
  can_message() {}
  can_message(const tuple3<int, long, bytes&> &msg)
  {
    id = msg.field1;
    time = msg.field2;
    buf = msg.field3;
  }

  int id;
  long time;
  bytes8 buf;

};

can_message tokens[32];

void add(const can_message &msg)
{
  memory::Mem::copy(&tokens[0], &msg, sizeof(msg));
}

int main(void)
{
  int inp = 2;
  u8 b[2] = { 1, inp };
  bytes2 buf = bytes2(b);
  tuple3<int, long, bytes&> arc(0x2D1, 0, buf);
  add(arc);
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
