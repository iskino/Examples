/*
Обертка C++ кода в C блок, чтобы компилятор языка
С полнял код языка C++.
Иначе будет:

$ g++ t.cc -S
t.cc:4:3: ошибка: шаблон с привязкой C
   template <class T>
   ^ 
*/
extern "C"
{
  extern "C++"
  template <class T>
  T foo (T t)
  {
    return t;
  }
}
 
int main (void)
{
  return foo(10);
}