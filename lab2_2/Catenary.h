#pragma once

namespace geom {
    struct Point { // структура точки
        float x, y; // координаты
        Point() : x(0), y(1) {} // конструктор по умолчанию
        Point(float x, float y) : x(x), y(y) {} // инициализирующий конструктор
    };

    class Catenary {
    public:
        // конструкторы
        Catenary() : LLim(Point(-2, 1)), RLim(Point(2, 1)), Vert(Point()) {}; // конструктор по умолчанию
        Catenary(float, float, float, float); // инициализирующий конструтор

        // геттеры
        Point get_LLim() const { return LLim; };
        Point get_RLim() const { return RLim; };
        Point get_Vert() const { return Vert; };

        float get_y(float, bool) const; // получение y по x
        float get_ArcLength() const; // получение длину линии
        float get_RadOfCurvature(float) const; // получение радиуса кривизны
        Point get_CenterOfCurvature(float) const; // получение координат центра кривизны
        float get_Square() const; // получение площади

        // сеттеры
        void set_LLim(Point llim) { LLim = llim; }; // установить левый предел
        void set_RLim(Point rlim) { RLim = rlim; }; // установить правый предел
        void set_Vert(Point vert) { Vert = vert; }; // установить вершину

        // прочие функции
        void PrintStatus() const; // вывод состояния класса

        // деструктор
        ~Catenary() = default; // деструктор

    private:
        Point Vert, // вершина цепи
        LLim, // левая граница
        RLim; // правая граница
    };
}
