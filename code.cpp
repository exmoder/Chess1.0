#include <iostream>
#include <algorithm>
#include <cmath>

// Функция проверки валидности координат
bool is_valid_coordinate(int x, int y) {
    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

// Функция сравнения координат двух фигур
bool are_same_coordinates(int x1, int y1, int x2, int y2) {
    return x1 == x2 && y1 == y2;
}

// Функция проверки угрозы королю от ладьи и слона
void check_threat(int rx, int ry, int bx, int by, int kx, int ky) {
    // Проверка валидности координат фигур
    if (!is_valid_coordinate(rx, ry) || !is_valid_coordinate(bx, by) || !is_valid_coordinate(kx, ky)) {
        std::cout << "Одна или несколько фигур находятся вне поля" << std::endl;
        return;
    }

    // Проверка, что фигуры не стоят на одной клетке
    if (are_same_coordinates(rx, ry, bx, by) || are_same_coordinates(rx, ry, kx, ky) || are_same_coordinates(bx, by, kx, ky)) {
        std::cout << "Некоторые фигуры находятся на одной клетке" << std::endl;
        return;
    }

    bool check = false;

    // Проверка угрозы от ладьи
    if ((kx == rx || ky == ry) && !((bx == rx || by == ry) &&
            ((std::max(ky, ry) > by && std::min(ky, ry) < by) ||
            (std::max(kx, rx) > bx && std::min(kx, rx) < bx)))) {
        std::cout << "Угроза от ладьи" << std::endl;
        check = true;
    }

    // Проверка угрозы от слона
    if ((std::abs(kx - bx) == std::abs(ky - by)) && !((std::abs(rx - bx) == std::abs(ry - by)) &&
            ((std::max(ky, by) > ry && std::min(ky, by) < ry) ||
            (std::max(kx, bx) > rx && std::min(kx, bx) < rx)))) {
        std::cout << "Угроза от слона" << std::endl;
        check = true;
    }

    // Вывод сообщения о безопасности короля
    if (!check) {
        std::cout << "Король в безопасности" << std::endl;
    }
}

int main() {
    int rx, ry, bx, by, kx, ky;

    // Ввод координат фигур
    std::cout << "Введите координаты короля (пример: 1 1): ";
    std::cin >> kx >> ky;
    std::cout << "Введите координаты ладьи (пример: 2 2): ";
    std::cin >> rx >> ry;
    std::cout << "Введите координаты слона (пример: 3 3): ";
    std::cin >> bx >> by;

    check_threat(rx, ry, bx, by, kx, ky);

    return 0;
}