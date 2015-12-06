#include <QApplication>
#include <QPushButton>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qboxlayout.h>

#include <cuda_runtime.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlineedit.h>


int main(int argc, char **argv)
{
   QApplication app(argc, argv);

   QWidget window;

   window.setWindowTitle("GPU INFO");
   window.setFixedSize(400, 500);

   cudaDeviceProp prop;
   cudaGetDeviceProperties(&prop, 0);

   QLabel gpuName("GPU Name", &window);
   QLabel cc("Compute Capability", &window);
   QLabel totalMem("Total memory", &window);

   QLineEdit gpuNameLineEdit;
   gpuNameLineEdit.setText(prop.name);
   QLineEdit ccLineEdit;
   ccLineEdit.setText(QString::number(prop.major) + "." + QString::number(prop.minor));
   QLineEdit totMemLineEdit;
   totMemLineEdit.setText(QString::number(prop.totalGlobalMem / 1024 / 1024 + 1));

   QFormLayout formLayout;
   formLayout.addRow(&gpuName, &gpuNameLineEdit);
   formLayout.addRow(&cc, &ccLineEdit);
   formLayout.addRow(&totalMem, &totMemLineEdit);
   window.setLayout(&formLayout);

   window.show();

   return app.exec();
}