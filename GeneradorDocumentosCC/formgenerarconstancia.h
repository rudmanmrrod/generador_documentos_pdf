/**
    Sistema para Creación de archivos PDF
    @file formgenerarconstancia.h
    @brief Cuerpo Principal de funciones del Sistema para Creación de archivos PDF
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
    @copyright <a href='https://www.gnu.org/licenses/gpl-3.0.en.html'>GNU Public License versión 3 (GPLv3)</a>
*/
#ifndef FORMGENERARCONSTANCIA_H
#define FORMGENERARCONSTANCIA_H

#include <QWidget>
#include <QtWidgets>

namespace Ui {
class FormGenerarConstancia;
}

class FormGenerarConstancia : public QWidget
{
    Q_OBJECT

public:
    explicit FormGenerarConstancia(QWidget *parent = 0);
    QJsonObject cargar_formato();
    Ui::FormGenerarConstancia *ui;
    ~FormGenerarConstancia();

private slots:

    void on_limpiar_clicked();

    void on_generarConstancia_clicked();

    void on_Buscar_clicked();

private:

};

#endif // FORMGENERARCONSTANCIA_H
