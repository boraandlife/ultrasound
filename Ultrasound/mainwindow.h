#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateImage(); // Görüntüyü güncelleyen fonksiyon

private:
    Ui::MainWindow *ui;       // UI öğelerine erişim
    QTimer *timer;            // Belirli aralıklarla işlem yapan zamanlayıcı
    QImage *image;            // Görüntü verilerini saklayan nesne
    QGraphicsScene *scene;    // Görüntüyü ekranda göstermek için sahne
    int scanlineIndex;        // Hangi satırın eklendiğini takip eden sayaç
    int objectPosition;       // Hareketli objenin pozisyonu
};

#endif // MAINWINDOW_H
