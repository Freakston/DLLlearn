#include<windows.h>

typedef int (*ptr_func1)(int x);

ptr_func1 fn1;
ptr_func1 fn2;

HMODULE Testdll;
int main()
{
    Testdll = LoadLibrary("Testdll.dll");
    fn1 = (ptr_func1)GetProcAddress(Testdll,"func1");
    fn2 = (ptr_func1)GetProcAddress(Testdll,"func2");

    int x = 20;
    fn1(x);
    fn2(x);

    FreeLibrary(Testdll);
}