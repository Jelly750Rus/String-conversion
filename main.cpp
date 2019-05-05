//
//  main.cpp
//  Преобразование строк
//
//  Created by Артём Шелковой on 09/03/2019.
//  Copyright © 2019 Артём Шелковой. All rights reserved.
//

#include <iostream>

void outMatrix(double *newMatrix, int strings, int columns){
    std::cout << std::endl << "Полученная матрица: \n";
    for (int i = 0; i<strings; i++){
        for (int j = 0; j<columns; j++){
            std::cout << (*(newMatrix+i*columns+j)) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int askStringsColumns(){
    std::cout << "C чем вы хотите делать преобразования? (1) строки; (2) столбцы \n";
    int knox = 0;
    while((knox != 1)||(knox != 2)){
        std::cin >> knox;
        return knox;
    }
}

void first(double *newMatrix, int strings, int columns){
    int knox = askStringsColumns();
    switch (knox) {
        case 1:
            std::cout << "Какие две строки вы хотите переставить? \n";
            int firstString, secondString;
            std::cin >> firstString >> secondString;
            for (int j = 0;j<columns; j++){
                (*(newMatrix+(firstString-1)*columns+j))+=(*(newMatrix+(secondString-1)*columns+j));
                (*(newMatrix+(secondString-1)*columns+j)) = (*(newMatrix+(firstString-1)*columns+j))-(*(newMatrix+(secondString-1)*columns+j));
                (*(newMatrix+(firstString-1)*columns+j)) = (*(newMatrix+(firstString-1)*columns+j))-(*(newMatrix+(secondString-1)*columns+j));
            }
            break;
        case 2:
            std::cout << "Какие два столбца вы хотите переставить? \n";
            int firstColumn, secondColumn;
            std::cin >> firstColumn >> secondColumn;
            for (int i = 0;i<strings; i++){
                (*(newMatrix+i*columns+firstColumn-1))+=(*(newMatrix+i*columns+secondColumn-1));
                (*(newMatrix+i*columns+secondColumn-1)) = (*(newMatrix+i*columns+firstColumn-1))-(*(newMatrix+i*columns+secondColumn-1));
                (*(newMatrix+i*columns+firstColumn-1)) = (*(newMatrix+i*columns+firstColumn-1))-(*(newMatrix+i*columns+secondColumn-1));
            }
            break;
        default:
            std::cout << "Неверный параметр: \n";
            break;
    }
}

void second(double *newMatrix, int strings, int columns){
    int knox = askStringsColumns();
    switch (knox) {
        case 1:
            std::cout << "Какую строку вы хотите умножить на число? \n";
            int currentString;
            std::cin >> currentString;
            std::cout << "На какое число, отличное от нуля, вы хотите умножить строку? \n";
            double number;
            std::cin >> number;
            if (!number){
                std::cout << "На какое число, отличное от нуля, вы хотите разделить строку? \n";
                std::cin >> number;
                if (!number){
                    std::cout << "На ноль я не умею делить:( \n";
                    return;
                }else{
                    number = 1/number;
                }
            }
            for (int j = 0; j<columns; j++){
                (*(newMatrix+(currentString-1)*columns+j)) *= number;
            }
            break;
        case 2:
            std::cout << "Какой столбец вы хотите умножить на число? \n";
            int currentColumn;
            std::cin >> currentColumn;
            std::cout << "На какое число, отличное от нуля, вы хотите умножить столбец? \n";
            double number1;
            std::cin >> number1;
            if (!number1){
                std::cout << "На какое число, отличное от нуля, вы хотите разделить строку? \n";
                std::cin >> number1;
                if (!number1){
                    std::cout << "На ноль я не умею делить:( \n";
                    return;
                }else{
                    number1 = 1/number1;
                }
            }
            for (int i = 0; i<strings; i++){
                (*(newMatrix+i*columns+currentColumn-1)) *= number1;
            }
            break;
        default:
            std::cout << "Неверный параметр: \n";
            break;
    }
}

void third(double *newMatrix, int strings, int columns){
    int knox = askStringsColumns();
    switch (knox) {
        case 1:
            std::cout << "К какой строке вы хотите прибавить строку? \n";
            int currentString;
            std::cin >> currentString;
            std::cout << "Какую строку вы хотите прибавить? \n";
            int secondString;
            std::cin >> secondString;
            std::cout << "На какое число вы хотите умножить прибавляемую строку? \n";
            int number;
            std::cin >> number;
            for (int j = 0; j<columns; j++){
                (*(newMatrix+(currentString-1)*columns+j)) += (*(newMatrix+(secondString-1)*columns+j))*number;
            }
            break;
        case 2:
            std::cout << "К какому столбцу вы хотите прибавить столбец? \n";
            int currentColumn;
            std::cin >> currentColumn;
            std::cout << "Какой столбец вы хотите прибавить? \n";
            int secondColumn;
            std::cin >> secondColumn;
            std::cout << "На какое число вы хотите умножить прибавляемый столбец? \n";
            int number1;
            std::cin >> number1;
            for (int i = 0; i<strings; i++){
                (*(newMatrix+i*columns+currentColumn-1)) += (*(newMatrix+i*columns+secondColumn-1))*number1;
            }
            break;
        default:
            break;
    }
}

int main(int argc, const char * argv[]) {
    std::cout << "Введите число строк матрицы: \n";
    int strings = 0;
    std::cin >> strings;
    std::cout << "Введите число столбцов матрицы: \n";
    int columns = 0;
    std::cin >> columns;
    double matrix[strings][columns];
    for (int i = 0; i<strings; i++){
        std::cout << "Введите "<<i+1 << " строку матрицы: \n";
        for (int j = 0; j<columns; j++){
            std::cin >> matrix[i][j];
        }
    }
    int parametr = 0;
    while (parametr != 4){
        std::cout << "Выберите элементарное преобразование: (1) переставить две строки/два столбца; "<<
        "(2) умножить строку/столбец на число; " << "(3) прибавить к строке/столбцу другую строку/другой столбец, умноженный на число; " << "(4) выход из программы";
        std::cin >> parametr;
        switch (parametr) {
            case 1:
                first(&matrix[0][0], strings, columns);
                outMatrix(&matrix[0][0], strings, columns);
                break;
            case 2:
                second(&matrix[0][0], strings, columns);
                outMatrix(&matrix[0][0], strings, columns);
                break;
            case 3:
                third(&matrix[0][0], strings, columns);
                outMatrix(&matrix[0][0], strings, columns);
                break;
            case 4:
                break;
            default:
                std::cout << "Неверный параметр! Попробуйте еще раз \n";
                break;
        }
    }
    return 0;
}
