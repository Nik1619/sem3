#pragma once
#include <iostream>
#include "Catenary.h"

using namespace geom;

namespace dlg {
    int dialog(const std::string msgs[], int N); // возврящает число введеное пользователем
    int D_CreateCatenary(Catenary& C); // диалоговая функция создания класса цепной линии
    int D_PrintStatus(Catenary& C); // диалоговая функция вывода статуса
    int D_GetY(Catenary& C); // диалоговая функция получения y
    int D_GetArcLength(Catenary& C); // диалоговая функция получения длины дуги
    int D_GetRadOfCurvature(Catenary& C); // диалоговая функция получения радиуса кривизны
    int D_GetCenterOfCurvature(Catenary& C); // диалоговая функция получения центра кривизны
    int D_GetArea(Catenary& C); // диалоговая функция получения площади

    template<class T>
    T getNum(T& n); // ввод числа
    template<class T>
    void CorrectInput(T& input); // функция корректного ввода
}
