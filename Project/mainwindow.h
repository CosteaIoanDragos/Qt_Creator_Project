#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QComboBox>
#include <QTableWidget>
#include <QKeyEvent>
#include <QListWidget>
#include <controller.h>


class MainWindow : public QMainWindow
{
    Q_OBJECT
    QLineEdit* id_line_edit;
    QListWidget *listWidget;
    controller c;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event)override;
public slots:
    void addClick_Removelast();
    void addClick_RemoveIndex();
    void addClick_Add();
    void addClick_Edit();
    void undo_ctrlz();
    void redo_ctrlx();
    void exit_save();

};
#endif // MAINWINDOW_H
