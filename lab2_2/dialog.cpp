#include <iostream>
#include "Catenary.h"
#include "dialog.h"
#include <exception>
using namespace std;
using namespace geom;

int dlg::dialog(const string msgs[], int N)
{
    string errmsg;
    int rc;
    int i;
    do {
        cout << errmsg << endl;
        errmsg = "Error input! Try again\n";
        for (i = 0; i < N; ++i)
            cout << msgs[i] << endl;
        cout << "Make your choice --> ";
        dlg::CorrectInput(rc);
        cout << endl;
    } while (rc < 0 || rc >= N);
    return rc;
}
int dlg::D_CreateCatenary(Catenary& C)
{
    float x1, x2, Ax, Ay;
    cout << "Input interval: " << endl;
    cout << "x1 = ";
    dlg::CorrectInput(x1);
    cout << "x2 = ";
    dlg::CorrectInput(x2);
    cout << "Input coordinates of vertex: " << endl;
    cout << "x = ";
    dlg::CorrectInput(Ax);
    cout << "y = ";
    dlg::CorrectInput(Ay);
    try {
        C = Catenary(x1, x2, Ax, Ay);
        cout << "\nSuccessful recording\n" << endl;
    }
    catch (const exception& err) {
        cout << err.what() << endl;
    }
    return 1;
}
int dlg::D_PrintStatus(Catenary& C)
{
    C.PrintStatus();
    return 1;
}
int dlg::D_GetY(Catenary& C)
{
    float x;
    cout << "Input x:";
    dlg::CorrectInput(x);
    try {
        cout << "y = " << C.get_y(x, true) << endl;
    }
    catch (const exception& err) {
        cout << err.what() << endl;
    }
    return 1;
}
int dlg::D_GetArcLength(Catenary& C)
{
    cout << "Arc length = " << C.get_ArcLength() << endl;
    return 1;
}
int dlg::D_GetRadOfCurvature(Catenary& C)
{
    float x;
    cout << "Input x:";
    dlg::CorrectInput(x);
    try {
        cout << "Radius = " << C.get_RadOfCurvature(x) << endl;
    }
    catch (const exception& err) {
        cout << err.what() << endl;
    }
    return 1;
}
int dlg::D_GetCenterOfCurvature(Catenary& C)
{
    float x;
    cout << "Input x:";
    dlg::CorrectInput(x);
    try {
        Point p = C.get_CenterOfCurvature(x);
        cout << "coordinates of center = Point(" << p.x << ", " << p.y << ")" << endl;
    }
    catch (const exception& err) {
        cout << err.what() << endl;
    }
    return 1;
}
int dlg::D_GetArea(Catenary& C)
{
    cout << "Area = " << C.get_Square() << endl;
    return 1;
}

template<class T>
T dlg::getNum(T& n)
{
    cin >> n;
    if (!cin.good()) return 1;
    return 0;
}
template<class T>
void dlg::CorrectInput(T& input)
{
    int n;
    do {
        try {
            n = dlg::getNum(input);
        }
        catch (bad_alloc& err) {
            cout << err.what() << endl;
            cin.clear();
            cin.ignore();
            n = 1;
        }
    } while (n == 1);
}

