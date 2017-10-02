/**
    Sistema para Creación de archivos PDF
    @file formconfiguracion.h
    @brief Cuerpo del formulario para la configuración de formato
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
    @copyright <a href='https://www.gnu.org/licenses/gpl-3.0.en.html'>GNU Public License versión 3 (GPLv3)</a>
*/
#ifndef FORMCONFIGURACION_H
#define FORMCONFIGURACION_H

#include <QWidget>
#include <QtCore>
#include <QtWidgets>

namespace Ui {
class FormConfiguracion;
}

class FormConfiguracion : public QWidget
{
    Q_OBJECT

public:
    explicit FormConfiguracion(QWidget *parent = 0);
    Ui::FormConfiguracion *ui;
    ~FormConfiguracion();

private slots:
    void on_guardar_clicked();

private:
    void loadConfig();

};

#endif // FORMCONFIGURACION_H
