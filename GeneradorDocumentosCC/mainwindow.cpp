/**
    Sistema para Creación de archivos PDF
    @file mainwindow.cpp
    @brief Cuerpo Principal de funciones del Sistema para Creación de archivos PDF
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
    @copyright <a href='https://www.gnu.org/licenses/gpl-3.0.en.html'>GNU Public License versión 3 (GPLv3)</a>
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
    @brief Constructor de la ventana principal
    @date 30/09/2017
    @param parent <b>QWidget</b> Recibe el widget padre
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMaximized();
}

/**
    @brief Destructor de la ventana principal
    @date 30/09/2017
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
*/
MainWindow::~MainWindow()
{
    delete ui;
}

/**
    @brief Slot para salir del sistema
    @date 30/09/2017
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
*/
void MainWindow::on_actionSalir_triggered()
{
    QMessageBox mensaje;
    mensaje.adjustSize();
    mensaje.setIcon(QMessageBox::Information);
    mensaje.setWindowTitle("¿Desea salir?");
    mensaje.setText("¿Está seguro que desea salir?");
    QPushButton *si = mensaje.addButton("Si", QMessageBox::YesRole);
    QPushButton *no = mensaje.addButton("No",QMessageBox::NoRole);
    mensaje.setDefaultButton(no);
    mensaje.exec();

    if (mensaje.clickedButton() == si) {
        this->close();
    } else if (mensaje.clickedButton() == no) {
        mensaje.close();
    }
}

/**
    @brief Slot generar el formulario de constancia de residencia
    @date 30/09/2017
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
*/
void MainWindow::on_actionResidencia_triggered()
{
    generar_constancia = new FormGenerarConstancia;
    generar_constancia->show();
}

/**
    @brief Slot para mostrar el apartado de acerca de
    @date 01/10/2017
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
*/
void MainWindow::on_actionAcerca_De_triggered()
{
    QString acerca_de = "Este software fue desarrollado por Rodrigo Boet."
                        "\ncorreo: rudmanmrrod@gmail.com"
                        "\nAño 2017"
                        "\nBajo la licencia GPLv3 ENLACE_AQUI";
    QMessageBox::information(this,"Acerca De",acerca_de);
}

/**
    @brief Slot generar el formulario de configuración del formato
    @date 01/10/2017
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
*/
void MainWindow::on_actionFormato_triggered()
{
    formconf_formato = new FormConfiguracion;
    formconf_formato->show();
}
