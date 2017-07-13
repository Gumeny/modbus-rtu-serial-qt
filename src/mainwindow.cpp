#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "include\global.h"
#include <QString>
#include <QVariant>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    com_port_connected = false;
    serial_ports = QSerialPortInfo::availablePorts();

    int i = 0;
    while(i < serial_ports.size())
    {
        ui->comboBox_ports->addItem(serial_ports[i].portName());
        i++;
    }

    ui->comboBox_speed->addItem("1200", QVariant(1200));
    ui->comboBox_speed->addItem("2400", QVariant(2400));
    ui->comboBox_speed->addItem("9600", QVariant(9600));

    ui->comboBox_speed->setCurrentIndex(2);

    serial_port.setDataBits(QSerialPort::Data8);
    serial_port.setParity(QSerialPort::NoParity);
    serial_port.setStopBits(QSerialPort::OneStop);

    /*timer_for_com_write = new QTimer(this);
    connect(timer_for_com_write, SIGNAL(timeout()), this, SLOT(on_timer_for_com_write_timeout()));*/

    connect(&serial_port, SIGNAL(readyRead()), this, SLOT(ReadComPort()));
}

MainWindow::~MainWindow()
{
    if(com_port_connected == true){
        serial_port.close();
        com_port_connected = false;
    }

    //delete timer_for_com_write;
    delete ui;
}

void MainWindow::on_timer_for_com_write_timeout()
{
    /*if(device_handle != nullptr){
        unsigned char values[] = {0xff, 0x00, 0xff, 0xff};  //zapne prijimac RS485
        Mcp2221_SetGpioValues(device_handle, values);
    }

    timer_for_com_write->stop();*/
}

void MainWindow::on_serial_port_bytesWritten(qint64 bytes)
{
    /*if(wait_for_write == false){
        return;
    }

    bytes_written += bytes;

    if(bytes_written >= bytes_to_wait_for){
        if(device_handle != nullptr){
            unsigned char values[] = {0xff, 0x00, 0xff, 0xff};  //zapne prijimac RS485
            Mcp2221_SetGpioValues(device_handle, values);
        }

        bytes_written = 0;
        wait_for_write = false;
        bytes_to_wait_for = 0;
    }*/
}

void MainWindow::on_btn_com_connect_clicked()
{
    if(serial_ports.isEmpty() == true){
        ui->statusBar->showMessage("Nie je vybratý žiadny port!", 5000);
        return;
    }

    if(com_port_connected == false){
        SetComPort();
        /*serial_port.setParity(QSerialPort::NoParity);
        serial_port.setBaudRate(9600);*/
        serial_port.setDataBits(QSerialPort::Data8);
        serial_port.setStopBits(QSerialPort::OneStop);
        serial_port.setPort(serial_ports[ui->comboBox_ports->currentIndex()]);
        if(serial_port.open(QIODevice::ReadWrite) == false){
            QSerialPort::SerialPortError err = serial_port.error();

            QString err_str = QString::asprintf("Nepodarilo sa otvoriť port, chyba %i", err);

            ui->statusBar->showMessage(err_str, 4000);
            return;
        }

        ui->comboBox_data_bits->setEnabled(false);
        ui->comboBox_parity->setEnabled(false);
        ui->comboBox_stop_bits->setEnabled(false);
        ui->comboBox_ports->setEnabled(false);
        ui->comboBox_speed->setEnabled(false);
        ui->btn_com_refresh->setEnabled(false);

        com_port_connected = true;
        ui->btn_com_connect->setText("Odpojiť");
    }
    else{
        serial_port.close();

        ui->comboBox_data_bits->setEnabled(true);
        ui->comboBox_parity->setEnabled(true);
        ui->comboBox_stop_bits->setEnabled(true);
        ui->comboBox_ports->setEnabled(true);
        ui->comboBox_speed->setEnabled(true);
        ui->btn_com_refresh->setEnabled(true);

        com_port_connected = false;
        ui->btn_com_connect->setText("Pripojiť");
    }
}

void MainWindow::on_btn_com_refresh_clicked()
{
    serial_ports = QSerialPortInfo::availablePorts();
    ui->comboBox_ports->clear();

    int i = 0;
    while(i < serial_ports.size())
    {
        ui->comboBox_ports->addItem(serial_ports[i].portName());
        i++;
    }
}

void MainWindow::SetComPort()
{
    if(ui->comboBox_parity->currentText() == "None"){
        if(serial_port.setParity(QSerialPort::NoParity) == false){
            ui->statusBar->showMessage("Nepodarilo sa nastaviť paritu!", 5000);
        }
    }
    if(ui->comboBox_parity->currentText() == "Even"){
        if(serial_port.setParity(QSerialPort::EvenParity) == false){
            ui->statusBar->showMessage("Nepodarilo sa nastaviť paritu!", 5000);
        }
    }
    if(ui->comboBox_parity->currentText() == "Odd"){
        if(serial_port.setParity(QSerialPort::OddParity) == false){
            ui->statusBar->showMessage("Nepodarilo sa nastaviť paritu!", 5000);
        }
    }

    /*if(serial_port.setDataBits((QSerialPort::DataBits)ui->comboBox_data_bits->currentData().toInt()) == false){
        ui->statusBar->showMessage("Nepodarilo sa nastaviť počet dátových bitov!", 5000);
    }
    if(serial_port.setStopBits((QSerialPort::StopBits)ui->comboBox_stop_bits->currentData().toInt()) == false){
        ui->statusBar->showMessage("Nepodarilo sa nastaviť počet stop bitov!", 5000);
    }*/

    if(serial_port.setBaudRate(ui->comboBox_speed->currentData().toInt()) == false){
        ui->statusBar->showMessage("Nepodarilo sa nastaviť prenosovú rýchlosť!", 5000);
    }
}

void MainWindow::on_btn_com_send_clicked()
{
    if(com_port_connected == false){
        return;
    }

    int format;

    if(ui->radioButton_ascii->isChecked()){
        format = -1;
    }
    else if(ui->radioButton_bin->isChecked()){
        format = 2;
    }
    else if(ui->radioButton_oct->isChecked()){
        format = 8;
    }
    else if(ui->radioButton_dec->isChecked()){
        format = 10;
    }
    else if(ui->radioButton_hex->isChecked()){
        format = 16;
    }

    QVector <char> bytes;

    int ret = GetBytesFromString(ui->lineEdit_command->text(), bytes, format);

    if(ret == 1){
        ui->statusBar->showMessage("", 4000);
        return;
    }
    if(ret == 2){
        ui->statusBar->showMessage("Nie je zadaný príkaz!", 4000);
        return;
    }
    if((ret == 3) || (ret == 4)){
        ui->statusBar->showMessage("Nesprávny formát!", 4000);
        return;
    }

    int i = 0;
    while(i < bytes.size())
    {
        if(serial_port.putChar(bytes[i]) != true){
            ui->statusBar->showMessage("Nepodarilo sa odoslať znak!", 5000);
            bytes.remove(i);
            continue;
        }

        i++;
    }

    PrintSentBytesToHistory(&bytes, format);

    com_reading_started = false;
}

void MainWindow::ReadComPort()
{
    char c;

    if(serial_port.getChar(&c) != 0){
        ui->statusBar->showMessage("Chyba pri načítavaní dát z portu!", 3000);
        return;
    }

    if(com_reading_started == false){
        ui->plainTextEdit_history->insertPlainText("PRIJATÉ:  ");
        com_reading_started = true;
    }
    else{
        ui->plainTextEdit_history->insertPlainText(",");
    }

    ui->plainTextEdit_history->insertPlainText(QString(c));
}

void MainWindow::on_btn_append_crc_clicked()
{

}

int MainWindow::GetBytesFromString(QString str_source, QVector <char> &bytes_dest, int format /* = 10*/)
{
    bytes_dest.clear();

    if(str_source.isEmpty() == true){
        return 2;
    }

    if((format != -1) && (format != 2) && (format != 8) && (format != 10) && (format != 16)){
        return 3;
    }

    bool ok;
    int i = 0, byte_int;
    int index_of_tilde;

    int number_of_bytes = str_source.count(",") + 1;

    if(number_of_bytes == 1){   //iba 1 byte
        if(format == -1){
            const char *byte_char = str_source.toUtf8().data();
            bytes_dest.push_back(byte_char[0]);
        }
        else{
            byte_int = str_source.toInt(&ok, format);
            if(ok == false){
                return 4;
            }
            bytes_dest.push_back((char)byte_int);
        }

    }
    else{
        QString byte_str, command_str = str_source;

        do
        {
            if(command_str.isEmpty() == true){
                break;
            }
            index_of_tilde = command_str.indexOf(',');
            byte_str = command_str.left(index_of_tilde);
            if(byte_str.isEmpty() == true){ //ak prvy znak je ciarka, vymaze ju a pokracuje odznova
                command_str.remove(0, index_of_tilde+1);
                continue;
            }

            if(format == -1){
                const char *byte_char = byte_str.toUtf8().data();
                bytes_dest.push_back(byte_char[0]);
            }
            else{
                byte_int = byte_str.toInt(&ok, format);
                if(ok == false){
                    return 4;
                }
                bytes_dest.push_back((char)byte_int);
            }
            command_str.remove(0,index_of_tilde+1);
            i++;
            if(i > 127){
                return 5;
            }
        }
        while(i < number_of_bytes);
    }

    return 0;
}

void MainWindow::PrintSentBytesToHistory(const QVector <char> *bytes, int format)
{
    ui->plainTextEdit_history->insertPlainText("ODOSLANÉ:   ");

    int i = 0;
    while(i < bytes->size())
    {
        if(i > 0){
            ui->plainTextEdit_history->insertPlainText(",");
        }

        if(format == -1){
            ui->plainTextEdit_history->insertPlainText(QString::asprintf("%c", bytes->at(i)));
        }
        if(format == 2){
            ui->plainTextEdit_history->insertPlainText(QString::asprintf("%i", bytes->at(i)));  //ToDo: prevod do dvojkovej sustavy
        }
        if(format == 8){
            ui->plainTextEdit_history->insertPlainText(QString::asprintf("%o", bytes->at(i)));
        }
        if(format == 10){
            ui->plainTextEdit_history->insertPlainText(QString::asprintf("%i", bytes->at(i)));
        }
        if(format == 16){
            ui->plainTextEdit_history->insertPlainText(QString::asprintf("%2x", (int)bytes->at(i)));
        }

        i++;
    }

    ui->plainTextEdit_history->insertPlainText("\n");
}

uint16_t MainWindow::CalculateCRC(const uint8_t *data, unsigned int length)
{
    uint16_t crc = 0xFFFF;
    int i, i_d = 0;

    while(i_d < length)
    {
        crc ^= data[i_d];
        for (i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xA001;
            else
                crc = (crc >> 1);
        }
        i_d++;
    }

    return crc;
}
