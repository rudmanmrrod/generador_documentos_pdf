/**
    Sistema para Creación de archivos PDF
    @file formgenerarconstancia.cpp
    @brief Cuerpo del formulario para generar constancias de residencia
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
    @copyright <a href='http://conocimientolibre.cenditel.gob.ve/licencia-de-software-v-1-3/>Licencia de Software Versión 1.2</a>
*/
#include "formgenerarconstancia.h"
#include "ui_formgenerarconstancia.h"

/**
    @brief Constructor del formulario para generar constancias de residencia
    @date 30/09/2017
    @param parent <b>QWidget</b> Recibe el widget padre
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
*/
FormGenerarConstancia::FormGenerarConstancia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormGenerarConstancia)
{
    ui->setupUi(this);
}

/**
    @brief Destructor del formulario para generar constancias de residencia
    @date 30/09/2017
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
*/
FormGenerarConstancia::~FormGenerarConstancia()
{
    delete ui;
}

/**
    @brief Slot para limpiar el formulario
    @date 30/09/2017
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
*/
void FormGenerarConstancia::on_limpiar_clicked()
{
    QMessageBox mensaje;
    //mensaje.adjustSize();
    mensaje.setIcon(QMessageBox::Information);
    mensaje.setWindowTitle("Limpiar Formulario");
    mensaje.setText("¿Desea limpiar todo el formulario?");
    QPushButton *si = mensaje.addButton("Si", QMessageBox::YesRole);
    QPushButton *no = mensaje.addButton("No",QMessageBox::NoRole);
    mensaje.setDefaultButton(no);
    mensaje.exec();

    if (mensaje.clickedButton() == si) {
        ui->nombre_apellido->clear();
        ui->cedula->clear();
        ui->direccion->clear();
        ui->motivo->clear();
        ui->ruta->clear();
    } else if (mensaje.clickedButton() == no) {
        mensaje.close();
    }
}

/**
    @brief Slot para generar la constancia
    @date 30/09/2017
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
*/
void FormGenerarConstancia::on_generarConstancia_clicked()
{
    if(ui->nombre_apellido->text().isEmpty() or ui->cedula->text().isEmpty()
            or ui->direccion->document()->isEmpty() or ui->motivo->text().isEmpty()
            or ui->ruta->text().isEmpty() or (!ui->checkMasculino->isChecked()
            and !ui->checkFemenino->isChecked()))
    {
        QMessageBox::warning(this,"Alerta","Debe llenar todos los campos");
    }
    else{
        QJsonObject data_json = this->cargar_formato();
        QString genero = ui->checkFemenino->isChecked() ? "la Ciudadana":"el Ciudadano";
        QLocale veLocal("es_VE");
        QString fecha = QString(veLocal.toString(QDate::currentDate(),"dd %1 MMMM %2 yyyy"))
                .arg("de").arg("del año");
        QStringList reporteHtml;
        reporteHtml << "<div style='font-size:250px;'>"
                    << "<p align='center' style='font-size:150px;'>"+data_json["cabecera"].toString()+"</p>"
                    << "<p align='center' style='line-height:50px;'><b>CARTA DE RESIDENCIA</b></p>"
                    << "<p align='justify'>"+data_json["presentacion"].toString()+"</p>"
                    << "<p align='center' style='line-height:50px;'><b>HACEMOS CONSTAR:</b></p>"
                    << "<p align='justify'>Que "+genero+" <b>"+ui->nombre_apellido->text()+"</b>, mayor de edad, "
                    << "titular de la Cédula de Identidad Nº <b>"+ui->cedula->text()+"</b> tiene su residencia en la siguiente dirección: "
                    << ui->direccion->document()->toPlainText()+"."
                    << "<br/>Motivo: "+ui->motivo->text()+"."
                    << "<br/>Constancia que se expide a solicitud de la parte interesada, en la comunidad "
                    << "de Santa Bárbara, el "+fecha+".</p>"
                    << "<p align='center' style='line-height:50px;'><b>"+data_json["pie"].toString()+"</b></p></div> "
                    ;
        QString filename = ui->ruta->text();
        QTextDocument report;
        report.setHtml(reporteHtml.join(""));
        QPdfWriter pdf(filename);
        report.print(&pdf);
        //Mensaje de confimación
        QMessageBox::information(this,"Reporte","Se generó con éxito el reporte\n en "+filename);
    }
}

/**
    @brief Slot para abrir el formulario de selección de directorio
    @date 30/09/2017
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
*/
void FormGenerarConstancia::on_Buscar_clicked()
{
    QString format = ".pdf";
    QString filename = QFileDialog::getSaveFileName(this,
            "Elija el nombre", QDir::homePath(),"*.pdf");

    filename.remove(format);
    filename+=format;
    ui->ruta->setText(filename);
}

/**
    @brief Función para cargar el formato del archivo de configuración
    @date 01/10/2017
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
    @return QJsonObject Retorna la configuración en archivo Json
*/
QJsonObject FormGenerarConstancia::cargar_formato()
{
    QFile config(QStringLiteral("config.dat"));
    if (!config.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this,"Error","No se pudo abrir el archivo de configuración");
    }

    QByteArray saveData = config.readAll();

    QJsonDocument loadConfig(QJsonDocument::fromBinaryData(saveData));
    return loadConfig.object();

}
