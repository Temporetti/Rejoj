#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dibujar = new QPaintBox(0,0,ui->widget); //!< Creo el objeto dibujoReloj que es el widget donde se dibuja (instanciar)
    QTimer1 = new QTimer(this);
    connect(QTimer1, &QTimer::timeout, this, &MainWindow::onQTimer1);
}

MainWindow::~MainWindow()
{
    delete ui;

    delete dibujar;
    delete QTimer1;
}

//aca desarrollar la funcion
void MainWindow::dibujarReloj(){
    int h;
    int w;
    int radio;

    QPen pen;
    QBrush brush;
    QPainter paint(dibujar->getCanvas());

    w = dibujar->width();
    h = dibujar->height();

    radio = (w/2)-10;

    if(h < w){
        radio = (h/2)-10;
    }

    //seteo el color y la herramienta
    pen.setWidth(3);
    pen.setColor(Qt::white);
    paint.setPen(pen);  //aplica como los valores que puse en la variable pen del tipo Qpen a la herramienta para
                        //dibujar con pen?

    brush.setColor(Qt::gray);
    brush.setStyle(Qt::Dense4Pattern);
    paint.setBrush(brush);  //aplica como los valores que puse en la variable brush del tipo Qbrush a la herramienta para
                            //dibujar con brush?

    //dibujo circulo
    paint.drawEllipse(w/2-radio, h/2-radio, 2*radio, 2*radio);

}

void MainWindow::onQTimer1(){

}


void MainWindow::on_pushButton_clicked()
{
    QDateTime dt;
    int horas;
    int minutos;
    int segundos;

    if(QTimer1->isActive()){
        QTimer1->stop();
        ui->pushButton->setText("START");
    }else{
        QTimer1->start(100);    //!< 100 por el tiempo de actualizacin de agujas. Donde hago define?
        ui->pushButton->setText("STOP");
    }

    dibujarReloj();
    //actualizo para que se vean los cambios
    dibujar->update();

    horas = dt.currentDateTime().time().hour();
    minutos = dt.currentDateTime().time().minute();
    segundos = dt.currentDateTime().time().second();



}

