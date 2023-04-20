#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QObject>
#include "mainwindow.h"
class SecondWindow:public MainWindow{
    Q_OBJECT
    QLineEdit* id_line_edit;
    public:
        SecondWindow(QWidget *parent = nullptr);
        ~SecondWindow();
        void keyPressEvent(QKeyEvent *event)override;


};
#endif // SECONDWINDOW_H
