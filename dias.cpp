#include <stdio.h>
#include <time.h>
#include <iostream>
#include <ctime>

int main()
{
    struct std::tm a = {0,0,0,5,10,93}; // Noviembre 5, 1993
    struct std::tm b = {0,0,0,12,8,120}; // Septiembre 12, 2020
    std::time_t x = std::mktime(&a); /* Se crea un objeto de time_t y con mktime se convierte el tiempo del calendario local
                                        retorna la cantidad de tiempo desde una fecha específica */ 
    std::time_t y = std::mktime(&b);
    if ( x != (std::time_t)(-1) && y != (std::time_t)(-1) ) 
    {
        double difference = std::difftime(y, x) / (60 * 60 * 24); /* Con difftime se calcula la diferencia en segundos entre las dos fechas
                	                                                y se hace la operación para obtener los dias */
        std::cout << std::ctime(&x);   //se convierte el tiempo almacenado a un formato de fecha estandar                            
        std::cout << std::ctime(&y);
        std::cout << "Los dias desde la fecha ingresada son " << difference << " dias" << std::endl;
    }
    return 0;
}