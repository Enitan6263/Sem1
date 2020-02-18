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
    long double x = 0;
    int i = 0;

    const int N = 1000;
    long double Z[N], Y[N];

    cout << "Введите x:  ";
    cin >> x;

    do
    {
        cout << "Введите эпсилон:  ";
        cin >> eps;
        i++;
    } while ((eps <= 0 || eps > 1e-10) && i == 3);

    if (i == 3)
    {
        cout << "Лимит ввода эпсилона исчерпан" << endl;
    }
    else
    {
        i = 1;
        Z[0] = (4 * x) / 1;
        Y[0] = Z[0];

        cout << " | " << left << setw(4) << "i" << " | " << setw(16) << "a" << " | "
            << setw(11) << "S" << endl;
        
        int k = 0; 

        while (fabs(Z[k]) >= eps && i < 1000)
        {
            Z[k + 1] = Z[k] * ((4 * x)) / ((i + 1) * (i + 1));
            Y[k + 1] = Y[k] + Z[k + 1];
            i++;
            k++;
        }
        for (k = 0; k < i; k++)
        {
            cout << " | " << left << scientific << setw(4) << (k + 1) << " | " <<
                setw(13) << scientific << Z[k] << " | "
                << setw(11) << setprecision(10) << scientific << Y[k] << endl;

        }
    }
    cout << "Слагаемых:  " << i;

    return 0;
}