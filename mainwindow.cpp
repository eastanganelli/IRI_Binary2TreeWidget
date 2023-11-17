#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnOpenFile_clicked() {
    if(ui->treeWidget->columnCount() > 0) {
        ui->treeWidget->clear();
    }

    QString filename =  QFileDialog::getOpenFileName(this,"Open Document",QDir::currentPath(),"Binary File (*.dat) ;;");
    unsigned int ID, Cant_;
    std::ifstream archibinrd(filename.toStdString(), std::ios::binary);
    if(archibinrd.is_open()) {
        while (!archibinrd.eof()){
            QTreeWidgetItem* Item_ = new QTreeWidgetItem();
            archibinrd.read((char*)&ID, sizeof(unsigned int));
            archibinrd.read((char*)&Cant_, sizeof(unsigned int));
            Item_->setText(0,"ID Cliente {"+ QString::number(ID) +"}");
            for(unsigned int j = 0; j < Cant_; j++) {
                Inscripcion aux;
                archibinrd.read((char*)&aux, sizeof(Inscripcion));
                QTreeWidgetItem* SubItem_ = new QTreeWidgetItem();
                SubItem_->setText(0, "ID Clase {"+ QString::number(aux.idCurso) +"} - Fecha: " + QString::number(aux.fechaInscripcion));
                Item_->addChild(SubItem_);
            }
            ui->treeWidget->addTopLevelItem(Item_);
        }
    }
    archibinrd.close();
}

