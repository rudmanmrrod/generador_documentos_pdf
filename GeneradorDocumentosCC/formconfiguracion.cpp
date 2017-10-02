/**
    Sistema para Creación de archivos PDF
    @file formconfiguracion.cpp
    @brief Cuerpo del formulario para la configuración de formato
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
    @copyright <a href='https://www.gnu.org/licenses/gpl-3.0.en.html'>GNU Public License versión 3 (GPLv3)</a>
*/

#include "formconfiguracion.h"
#include "ui_formconfiguracion.h"

#include "QDebug"

/**
    @brief Constructor del formulario para la configuración de formato
    @date 01/10/2017
    @param parent <b>QWidget</b> Recibe el widget padre
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
*/
FormConfiguracion::FormConfiguracion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormConfiguracion)
{
    ui->setupUi(this);
    this->loadConfig();
}

/**
    @brief Destructor del formulario para la configuración de formato
    @date 01/10/2017
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
*/
FormConfiguracion::~FormConfiguracion()
{
    delete ui;
}

/**
    @brief Función para cargar la configuración si archivo config.dat existe
    @date 01/10/2017
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
*/
void FormConfiguracion::loadConfig()
{
    QFile config(QStringLiteral("config.dat"));
    if (!config.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this,"Error","No se pudo abrir el archivo de configuración");
    }

    QByteArray saveData = config.readAll();

    QJsonDocument loadConfig(QJsonDocument::fromBinaryData(saveData));
    QJsonObject data_json = loadConfig.object();
    if(!data_json.isEmpty()){
        ui->cabeceraText->document()->setHtml(data_json["cabecera"].toString());
        ui->presentacionText->document()->setPlainText(data_json["presentacion"].toString());
        ui->pieText->document()->setPlainText(data_json["pie"].toString());
    }
}

/**
    @brief Slot para guardar los datos del formulario de configuración de formato
    @date 01/10/2017
    @author Rodrigo Boet (rudmanmrrod at gmail.com)
*/
void FormConfiguracion::on_guardar_clicked()
{
    if(ui->cabeceraText->document()->isEmpty() or ui->presentacionText->document()->isEmpty()
            or ui->pieText->document()->isEmpty()){
        QMessageBox::warning(this,"Alerta","Debe llenar todos los campos");
    }
    else{
        QJsonObject config;
        config["cabecera"] = ui->cabeceraText->document()->toHtml();
        config["presentacion"] = ui->presentacionText->document()->toPlainText();
        config["pie"] = ui->pieText->document()->toPlainText();

        QFile save(QStringLiteral("config.dat"));
        if (!save.open(QIODevice::WriteOnly)) {
                QMessageBox::critical(this,"Error","No se pudo abrir el archivo de configuración");
        }
        QJsonDocument saveDoc(config);
        save.write(saveDoc.toBinaryData());
        QMessageBox::information(this,"Información","Se guardó la configuración con éxito");
    }
}
