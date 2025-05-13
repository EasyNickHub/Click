#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    double M, t, af, qp, qf, qt;

    cout << "Введите суточную выработку цеха (M): "; cin >> M;
    cout << "Введите время смены (t): "; cin >> t;
    cout << "Введите массовую долю фарша (af): "; cin >> af;
    cout << "Введите производительность пельменей (qp): "; cin >> qp;
    cout << "Введите производительность фарша (qf): "; cin >> qf;
    cout << "Введите производительность теста (qt): "; cin >> qt;

    if (M <= 0  af < 0  qp <= 0  qt <= 0) {
        cerr << "Ошибка: недопустимые входные данные!" << endl;
        return 1;
    }

    double Qp = M / 2 / t;
    double np = Qp / qp;

    double Qf = af * Qp;
    double nf = Qf / qf;

    double Qt = (1 - af) * Qp;
    double nt = Qt / qt;

    int np_rounded = static_cast<int>(ceil(np));
    int nf_rounded = static_cast<int>(ceil(nf));
    int nt_rounded = static_cast<int>(ceil(nt));


    cout << "\nРезультаты:" << endl;
    cout << "np (количество пельменей): " << np_rounded << endl;
    cout << "nf (количество фарша): " << nf_rounded << endl;
    cout << "nt (количество теста): " << nt_rounded << endl;

    return 0;
}
