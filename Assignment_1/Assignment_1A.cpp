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
        cout << "**        ��ӭ�����߼��������       **" << endl;
        cout << "**                                   **" << endl;
        cout << "***************************************" << endl << endl;

        cout << "\n  ������P��ֵ��0��1��,�Իس�����: ";
        while (!(cin >> i) || (i != 0 && i != 1)) {
            cout << "\n  P��ֵ��������,����������!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Sleep(2000);
            system("cls");
            goto tt;
        }

        cout << "\n  ������Q��ֵ��0��1��,�Իس�����: ";
        while (!(cin >> j) || (j != 0 && j != 1)) {
            cout << "\n  Q��ֵ��������,����������!" << endl;
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

        cout << "\n\n  ��ȡ:\n       P/\\Q = " << a[0] << endl;
        cout << "  ��ȡ:\n       P\\/Q = " << a[1] << endl;
        cout << "  ����:\n       P->Q = " << a[2] << endl;
        cout << "  ˫����:\n       P<->Q = " << a[3] << endl;

        do {
            cout << "\n�Ƿ��������?��y/n��";
            cin >> s;
            if (s == 'y') {
                system("cls");
            } else if (s == 'n') {
                cout << "��ӭ�´��ٴ�ʹ��!" << endl;
                continueOperation = false;
            } else {
                cout << "�������,����������!" << endl;
            }
        } while (s != 'y' && s != 'n');
    }

    return 0;
}
