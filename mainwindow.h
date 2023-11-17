#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <fstream>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

typedef struct {
    unsigned int idCurso;
    time_t fechaInscripcion;
} Inscripcion;

typedef struct {
    unsigned int idCliente, cantInscriptos;
    Inscripcion* CursosInscriptos;
} Asistencia;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnOpenFile_clicked();

private:
    Ui::MainWindow *ui;

    void resizeAsis(Asistencia*& array, unsigned int tam) {
        Asistencia* aux = new Asistencia[tam];

        for(unsigned int i = 0; i < tam - 1; i++)
            aux[i] = array[i];

        delete[] array;
        array = aux;
    }
};
#endif // MAINWINDOW_H
