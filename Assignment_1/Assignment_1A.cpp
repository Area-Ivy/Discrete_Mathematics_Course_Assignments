#include <iostream>
#include <windows.h>
#include <limits>
#include <cstdlib>

using namespace std;

int main() {
    int a[4];
    int i, j;
    char s;
    bool continueOperation = true;

    while (continueOperation) {
        tt:cout << "***************************************" << endl;
        cout << "**                                   **" << endl;
        cout << "**        欢迎进入逻辑运算程序       **" << endl;
        cout << "**                                   **" << endl;
        cout << "***************************************" << endl << endl;

        cout << "\n  请输入P的值（0或1）,以回车结束: ";
        while (!(cin >> i) || (i != 0 && i != 1)) {
            cout << "\n  P的值输入有误,请重新输入!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Sleep(2000);
            system("cls");
            goto tt;
        }

        cout << "\n  请输入Q的值（0或1）,以回车结束: ";
        while (!(cin >> j) || (j != 0 && j != 1)) {
            cout << "\n  Q的值输入有误,请重新输入!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Sleep(2000);
            system("cls");
            goto tt;
        }

        a[0] = i && j;  // AND
        a[1] = i || j;  // OR
        a[2] = (!i) || j;  // Implication
        a[3] = ((!i) || j) && ((!j) || i);  // Equivalence

        cout << "\n\n  合取:\n       P/\\Q = " << a[0] << endl;
        cout << "  析取:\n       P\\/Q = " << a[1] << endl;
        cout << "  条件:\n       P->Q = " << a[2] << endl;
        cout << "  双条件:\n       P<->Q = " << a[3] << endl;

        do {
            cout << "\n是否继续运算?（y/n）";
            cin >> s;
            if (s == 'y') {
                system("cls");
            } else if (s == 'n') {
                cout << "欢迎下次再次使用!" << endl;
                continueOperation = false;
            } else {
                cout << "输入错误,请重新输入!" << endl;
            }
        } while (s != 'y' && s != 'n');
    }

    return 0;
}
