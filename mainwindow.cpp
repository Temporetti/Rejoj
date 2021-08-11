#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dibujoReloj = new QPaintBox(0,0,ui->widget); //!< Creo el objeto dibujoReloj que es el widget donde se dibuja (instanciar)

}

MainWindow::~MainWindow()
{
    delete ui;

    delete dibujoReloj;
}


void MainWindow::on_pushButton_clicked()
{

    int h;
    int w;
    int radio;

    QPen pen;
    QBrush brush;
    QPainter paint(dibujoReloj->getCanvas());

    w = dibujoReloj->width();
    h = dibujoReloj->height();

    radio = w/2;

    if(h < w){
        radio = h/2;
    }

    //seteo el color y la herramienta
    pen.setColor(Qt::white);
    paint.setPen(pen);  //aplica como los valores que puse en la variable pen del tipo Qpen a la herramienta para
                           //dibujar con pen?

    brush.setColor(Qt::gray);
    brush.setStyle(Qt::Dense4Pattern);
    paint.setBrush(brush);  //aplica como los valores que puse en la variable brush del tipo Qbrush a la herramienta para
                            //dibujar con brush?

    //dibujo
    paint.drawEllipse(w/2-radio, h/2-radio, 2*radio, 2*radio);



    //actualizo para que se vean los cambios
    dibujoReloj->update();


}

