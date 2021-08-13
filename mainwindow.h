#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <qpaintbox.h>
#include <QDateTime>
//define aca

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void onQTimer1();

private:
    Ui::MainWindow *ui;

    QPaintBox *dibujar;  //!< Declaro la variable de tipo QPaintBox para dibujar en el widget?
    QTimer *QTimer1;

    /*!
     * \brief dibujarReloj
     * Dibuja el circulo del reloj con su patron.
     */
    void dibujarReloj();


};
#endif // MAINWINDOW_H
