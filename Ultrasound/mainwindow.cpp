#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRandomGenerator> // Rastgele sayı üretimi için
#include <QtMath>           // Matematiksel hesaplamalar için

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), scanlineIndex(0), objectPosition(100) {
    ui->setupUi(this);

    // Görseli başlat (400x200 piksel, renkli görüntü)
    image = new QImage(400, 200, QImage::Format_RGB32);
    image->fill(Qt::black); // Başlangıçta tamamen siyah

    // QGraphicsView için sahne oluştur
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->addPixmap(QPixmap::fromImage(*image));

    // QGraphicsView alanını görüntüye göre ölçekle
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);

    // Zamanlayıcıyı başlat
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateImage);
    timer->start(50); // Her 50ms'de bir güncelleme
}

MainWindow::~MainWindow() {
    delete image;
    delete scene;
    delete ui;
}

void MainWindow::updateImage() {
    // Kullanıcıdan alınan slider değerleri
    int objectWidth = ui->objectWidthSlider->value(); // Parlak obje genişliği
    int noiseLevel = ui->noiseLevelSlider->value();   // Gürültü seviyesi

    // Hareketli yapı için değişken
    static int organOffset = 0; // Hareket için ofset
    organOffset = (organOffset + 1) % 400; // Sürekli döngü

    // Yeni bir tarama satırı oluştur
    for (int x = 0; x < 400; ++x) {
        // Temel gürültü
        int intensity = noiseLevel + QRandomGenerator::global()->bounded(20);

        // Dalgalı katmanlar (daha yumuşak geçişler)
        if ((x / 40) % 2 == 0) {
            intensity += 30 + qAbs(qSin(scanlineIndex * 0.1) * 50);
        }

        // Hareketli eliptik organik yapı
        int centerX = 200 + qSin(scanlineIndex * 0.05) * 50; // Elipsin merkezi x
        int centerY = 100 + organOffset / 10;               // Elipsin merkezi y (hareketli)
        int radiusX = objectWidth / 2; // Yatay yarıçap
        int radiusY = 30;              // Dikey yarıçap

        if (qPow(x - centerX, 2) / qPow(radiusX, 2) +
                qPow(image->height() - 1 - centerY, 2) / qPow(radiusY, 2) <= 1) {
            intensity = 180 + QRandomGenerator::global()->bounded(50); // Parlak organ
        }

        // Yumuşak geçişlerle doku sınırları
        if (x > 300 && x < 300 + objectWidth / 2) {
            intensity = 150 + qAbs(qCos(scanlineIndex * 0.2) * 50);
        }

        // Renk hesaplama (siyah-beyaz ultrason etkisi)
        QRgb color = qRgb(intensity, intensity, intensity);

        // Yeni pikseli ekle (son satır)
        image->setPixel(x, image->height() - 1, color);
    }

    // Görüntüyü yukarı kaydır
    for (int y = 1; y < image->height(); ++y) {
        memcpy(image->scanLine(y - 1), image->scanLine(y), image->width() * sizeof(QRgb));
    }

    // Görseli güncelle
    scene->clear();
    scene->addPixmap(QPixmap::fromImage(*image));

    // QGraphicsView'i görüntüye göre ölçekle
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);

    // Tarama indeksi artır
    scanlineIndex++;
}

