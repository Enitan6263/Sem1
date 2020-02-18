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

    double* pA;
    double* pS;

    cout << "Введите x:  ";
    cin >> x;

    do
    {
        cout << "Введите эпсилон:  ";
        cin >> eps;
        i++;
    } while ((eps <= 0 || eps > 1e-10) && i == 3);

    double z = 0;

    if (i == 3)
    {
        cout << "Лимит ввода эпсилона исчерпан" << endl;
    }
    else
    {
        i = 1;
        z = (4 * x) / 1;

        while (fabs(z) >= eps && i < 1000)
     {
        z *= (4 * x) / ((i + 1) * (i + 1));
        i++;
     }

        pA = new double[i];
        pS = new double[i];
        *pA = (4 * x) / 1;
        *pS = *pA;
         
        for (int q = 0; q < i; q++)
        {
            *(pA + q + 1) = *(pA + q) * ((4 * x)) / (((q + 1) + 1) * ((q + 1) + 1));
            *(pS + q + 1) = *(pS + q) + *(pA + q + 1);
        }
        cout << " | " << left << setw(4) << "i" << " | " << setw(16) << "a" << " | "
        << setw(11) << "S" << endl;
        
        
        for (int q = 0; q < i; q++)
        {
        cout << " | " << left << scientific << setw(4) << (q + 1) << " | " <<
        setw(13) << scientific << *(pA + q) << " | "
        << setw(11) << setprecision(10) << scientific << *(pS + q) << endl;

        }
    }
    cout << "Слагаемых:  " << i << endl;
    
    cin >> x;

    return 0;
}