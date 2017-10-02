/**
    Sistema para Creación de archivos PDF
    @file mainwindow.h
    @brief Cuerpo Principal de funciones del Sistema para Creación de archivos PDF
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
    @copyright <a href='https://www.gnu.org/licenses/gpl-3.0.en.html'>GNU Public License versión 3 (GPLv3)</a>
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "formgenerarconstancia.h"
#include "formconfiguracion.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    FormGenerarConstancia *generar_constancia;
    FormConfiguracion *formconf_formato;
    ~MainWindow();

private slots:
    void on_actionSalir_triggered();

    void on_actionResidencia_triggered();

    void on_actionAcerca_De_triggered();

    void on_actionFormato_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
