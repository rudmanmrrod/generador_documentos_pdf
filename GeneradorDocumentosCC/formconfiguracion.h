/**
    Sistema para Creación de archivos PDF
    @file formconfiguracion.h
    @brief Cuerpo del formulario para la configuración de formato
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
    @copyright <a href='http://conocimientolibre.cenditel.gob.ve/licencia-de-software-v-1-3/>Licencia de Software Versión 1.2</a>
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
