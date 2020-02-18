/*Программа, определяющая минимальне значение n > 0,
для которого очередное слагаемое по модулю не превышает Eps > 0
при нахождении результата согласно формуле.
Автор: Руслан Бакиев, гр. 9005. Версия: 2.19.1
Дата начала разработки: 21.01.2020. Дата сдачи программы: 22.01.2020
*/

#include <iostream>
#include <iomanip>
#include <complex>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUSSIAN");

    cout << "Определить минимальное значение n > 0\n";
    cout << "для которого очередное слагаемое по модулю не превышает Eps > 0\n";
    cout << "при нахождении результата согласно формуле:\n ";
    cout << " n \n";
    cout << " ------- \n";
    cout << " \\        4^i\n";
    cout << "  \\ ________________\n";
    cout << "  / \n";
    cout << " /       (i!)^2\n";
    cout << " -------\n";
    cout << " i=1\n \n";

    long double eps = 0;
    long double a = 0;
    long double S = 0;
    long double x = 0;
    int i = 0;

    cout << "Введите x:  ";
    cin >> x;

    do 
    {
        cout << "Введите эпсилон:  ";
        cin >> eps;
        i++;
    } 
    while ((eps <= 0 || eps > 1e-10) && i == 3);

    if (i == 3)
    {
    cout << "Лимит ввода эпсилона исчерпан" << endl;
    }
    else 
    {
        i = 1;
        a = (4 * x) / 1;
        S = a;

        cout << "| " << left << std::setw(4) << "i" << " | " << setw(13) << "a" << " | "
            <<setw(11) << fixed << "S" << endl;
        cout << "| " << left << scientific << setw(4) << i << " | " << setw(13)
            << setprecision(5) << a << " | "
            << setw(11) << setprecision(10) << fixed << S << endl;

        while (fabs(a) >= eps && i < 1000)
        {
            a *= ((4 * x)) / ((i + 1) * (i + 1));
            S += a;
            i++;

            cout << "| " << left << setw(4) << i << " | " << setw(13)
                << scientific << a << " | "
                << setw(11) << setprecision(10) << scientific << S << endl;
        }
    }

    cout << "Слагаемых:  " << i;

    return 0;
}