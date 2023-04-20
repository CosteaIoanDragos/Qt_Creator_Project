#include "secondwindow.h"
#include <QLineEdit>
#include <iostream>
#include <QPushButton>
#include <QComboBox>
#include <QTableWidget>
#include <QGridLayout>
#include <QDebug>
#include <QMessageBox>
#include <QListWidget>
#include <QString>
SecondWindow::SecondWindow(QWidget *parent): MainWindow(parent)
{
id_line_edit = new QLineEdit(this);
QGridLayout* main_layout = new QGridLayout();
main_layout->addWidget(id_line_edit,0,0);

}
