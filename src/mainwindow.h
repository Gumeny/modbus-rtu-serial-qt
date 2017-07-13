#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QtSerialPort>
//#include <QtSerialPort/QSerialPort>
//#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_btn_com_send_clicked();
    void on_btn_com_connect_clicked();
    void on_btn_com_refresh_clicked();
    void on_btn_append_crc_clicked();

    void on_serial_port_bytesWritten(qint64 bytes);
    void on_timer_for_com_write_timeout();
    void ReadComPort();

private:
    Ui::MainWindow *ui;
    QSerialPort serial_port;
    QList<QSerialPortInfo> serial_ports;
    QTimer *timer_for_com_write;

    bool com_port_connected;

    void SetComPort();
    uint16_t CalculateCRC(const uint8_t *data, unsigned int length);
    int GetBytesFromString(QString str_source, QVector <char> &bytes_dest, int format = 10);
    void PrintSentBytesToHistory(const QVector <char> *bytes, int format = 10);
};

#endif // MAINWINDOW_H
