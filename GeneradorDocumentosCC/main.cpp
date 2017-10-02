/**
    Sistema para Creación de archivos PDF
    @file main.cpp
    @brief Parte principal de la herramienta
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
    @copyright <a href='https://www.gnu.org/licenses/gpl-3.0.en.html'>GNU Public License versión 3 (GPLv3)</a>
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
