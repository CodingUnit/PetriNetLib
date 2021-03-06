#pragma once
#include "lib_incl.h"

template <class T, class T2>
struct tuple2
{
	tuple2(T f0, T2 f1) : field1(f0), field2(f1) {}

  T field1;
  T2 field2;
};

template <class T, class T2, class T3>
struct tuple3
{
public:
  tuple3() {}
  tuple3(T f1, T2 f2, T3 f3) : field1(f1), field2(f2), field3(f3) {}


  T field1;
  T2 field2;
  T3 field3;
};

template <class T, class T2, class T3, class T4>
struct tuple4
{
public:
  tuple4() {}
  tuple4(T f1, T2 f2, T3 f3, T4 f4) : field1(f1), field2(f2), field3(f3), field4(f4) {}
  

  T field1;
  T2 field2;
  T3 field3;
  T4 field4;
};
