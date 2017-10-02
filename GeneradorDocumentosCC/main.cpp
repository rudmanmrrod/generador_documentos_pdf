/**
    Sistema para Creación de archivos PDF
    @file main.cpp
    @brief Parte principal de la herramienta
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
    @copyright <a href='http://conocimientolibre.cenditel.gob.ve/licencia-de-software-v-1-3/>Licencia de Software Versión 1.2</a>
*/
#include "mainwindow.h"
#include <QApplication>

/**
    @brief Función principal para correr la aplicación
    @date 30/09/2017
    @param argc <b>int</b> Recibe argumentos para la aplicación
    @param argv <b>char</b> Recibe argumentos para la aplicación
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
