#include <iostream>
#include "Catenary.h"
#include "dialog.h"

using namespace dlg;

int main()
{
    Catenary C = Catenary();

    int rc;
    int (*fptr[])(Catenary &) = {nullptr,                // массив указателей на диалоговые функции
                                 D_CreateCatenary,
                                 D_PrintStatus,
                                 D_GetY,
                                 D_GetArcLength,
                                 D_GetRadOfCurvature,
                                 D_GetCenterOfCurvature,
                                 D_GetArea};

    const std::string msgs[] = {"0. Exit", // menu
                                "1. Creating a catenary",
                                "2. Display status",
                                "3. Get y by x",
                                "4. Get the arc length",
                                "5. Get the radius of curvature in x",
                                "6. Get coordinates of the center of curvature by x",
                                "7. Get the area"};

    const int NMsgs = sizeof(msgs) / sizeof(msgs[0]); // размер массива меню

    while((rc = dialog(msgs, NMsgs))) {  // цикл закончится, когда пользователь введет 0 (Выход)
        if(!fptr[rc](C))
            break;
    }

    return 0;
}
