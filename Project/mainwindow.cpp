#include "mainwindow.h"
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
#include <QInputDialog>
#include <QShortcut>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    c.readFile(3);
    qDebug ("message %d",c.dimension());





    listWidget = new QListWidget(this);

    for(int i=0;i<c.dimension();i++){
     //  listWidget->addItem("c.getElementString(0)");
    listWidget->addItem(QString::fromStdString(c.getElementString(i)));
   }

  //  listWidget->addItem("c.getElementString(0)");


    id_line_edit = new QLineEdit(this);
    QPushButton* push_button = new QPushButton("ADD", this);
    QPushButton* push_button_removelast = new QPushButton("Remove Last", this);
    QPushButton* push_button_remove = new QPushButton("Remove At Index", this);
    QPushButton* push_button_edit= new QPushButton("Edit", this);
    QPushButton* push_button_exit = new QPushButton("Exit and Save", this);
    push_button_exit->setStyleSheet("QPushButton{ background-color :red; }");
  //  listWidget = new QListWidget(this);
   // listWidget->addItems(lista);
    QGridLayout* main_layout = new QGridLayout();
    main_layout->addWidget(id_line_edit,0,0);
    QVBoxLayout* button_layout=new QVBoxLayout();
    main_layout->addWidget (listWidget,1,0);
    button_layout->addWidget(push_button);
    button_layout->addWidget(push_button_removelast);
    button_layout->addWidget(push_button_remove);
    button_layout->addWidget(push_button_edit);
    button_layout->addWidget(push_button_exit);

    main_layout->addLayout(button_layout,1,1);
    QWidget* w = new QWidget(this);
    w->setLayout(main_layout);
    this->setCentralWidget(w);


    connect(push_button,&QPushButton::clicked, this, &MainWindow::addClick_Add);
    connect(push_button_removelast, &QPushButton::clicked, this, &MainWindow::addClick_Removelast);
    connect(push_button_remove,&QPushButton::clicked, this, &MainWindow::addClick_RemoveIndex);
    connect(push_button_edit,&QPushButton::clicked, this, &MainWindow::addClick_Edit);
    connect(push_button_exit,&QPushButton::clicked, this, &MainWindow::exit_save);


    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this);
    QShortcut *shortcut2 = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_X), this);

    connect(shortcut,&QShortcut::activated, this, &MainWindow::undo_ctrlz);
    connect(shortcut2,&QShortcut::activated, this, &MainWindow::redo_ctrlx);

}

MainWindow::~MainWindow()
{
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"pressed"<<event->key();
}

void MainWindow::addClick_Removelast()
{if(c.dimension()>0){
    c.removeLast();
    listWidget->clear();
    for(int i=0;i<c.dimension();i++){
        //  listWidget->addItem("c.getElementString(0)");
       listWidget->addItem(QString::fromStdString(c.getElementString(i)));
      }
}

  }
void MainWindow::addClick_RemoveIndex(){
    if(id_line_edit->text() == "")
        {
            int ret = QMessageBox::warning(this, tr("My Application"),
                                           tr("NotGood.\n"),
                                           QMessageBox::Ok);
            return;
        }

    int id = std::stoi(id_line_edit->text().toStdString());
    if (id>=0&&id<c.dimension()){
    if(c.dimension()>0){
     c.remove(id);
     listWidget->clear();
     for(int i=0;i<c.dimension();i++){
        listWidget->addItem(QString::fromStdString(c.getElementString(i)));
       }
    }}

}
void MainWindow::addClick_Add(){
    QStringList items;
        items << tr("Phone ") << tr("Tablet") << tr("Leptop")<<tr("CPU") << tr("GPU");
    QStringList brands;
    brands<<"Apple"<<"Samsung"<<"Huawei"<<"G"<<"Unknown";
        bool ok;
        QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"),
                                             tr("Season:"), items, 0, false, &ok);
        if(item==tr("Phone ")){
            QString text = QInputDialog::getText(this,"QInputDialog::getMultiLineText()","Brand", QLineEdit::Normal);

            float i2 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Pret:");
            float i3 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Freq:");
            int i4 = QInputDialog::getInt(this, "QInputDialog::getInt()",
                                         "Camera:");
            int i5 = QInputDialog::getInt(this, "QInputDialog::getInt()",
                                         "screen size:");
            string txt=text.toStdString();
            c.add(new Phone(txt,i2,i3,i4,i5));
            listWidget->clear();
            for(int i=0;i<c.dimension();i++){
               listWidget->addItem(QString::fromStdString(c.getElementString(i)));

        }


    }else if (item==tr("Tablet")){
            QString text = QInputDialog::getText(this,"QInputDialog::getMultiLineText()","Brand", QLineEdit::Normal);

            float i2 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Pret:");
            float i3 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Freq:");
            int i4 = QInputDialog::getInt(this, "QInputDialog::getInt()",
                                         "Camera:");
            int i5 = QInputDialog::getInt(this, "QInputDialog::getInt()",
                                         "screen size:");
            string txt=text.toStdString();
            c.add(new Tablet(txt,i2,i3,i4,i5));
            listWidget->clear();
            for(int i=0;i<c.dimension();i++){
               listWidget->addItem(QString::fromStdString(c.getElementString(i)));
        }

}else if (item==tr("Leptop")){
            QString text = QInputDialog::getText(this,"QInputDialog::getMultiLineText()","Brand", QLineEdit::Normal);

            float i2 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Pret:");
            float i3 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Freq:");
            int i4 = QInputDialog::getInt(this, "QInputDialog::getInt()",
                                         "Camera:");
            QString text2 = QInputDialog::getText(this,"QInputDialog::getMultiLineText()","Brand", QLineEdit::Normal);
            string txt=text.toStdString();
            string txt2=text2.toStdString();
            c.add(new Leptop(txt,i2,i3,i4,txt2));
            listWidget->clear();
            for(int i=0;i<c.dimension();i++){
               listWidget->addItem(QString::fromStdString(c.getElementString(i)));


        }

}else if(item==tr("CPU")){
            QString text = QInputDialog::getText(this,"QInputDialog::getMultiLineText()","Brand", QLineEdit::Normal);

            float i2 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Pret:");
            float i3 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Freq:");
            int i4 = QInputDialog::getInt(this, "QInputDialog::getInt()",
                                         "Nr of Cores:");

            string txt=text.toStdString();

            c.add(new Processor(txt,i2,i3,i4));
            listWidget->clear();
            for(int i=0;i<c.dimension();i++){
               listWidget->addItem(QString::fromStdString(c.getElementString(i)));}
        }else if (item==tr("GPU")){
            QString text = QInputDialog::getText(this,"QInputDialog::getMultiLineText()","Brand", QLineEdit::Normal);

            float i2 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Pret:");
            float i3 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Freq:");
            int i4 = QInputDialog::getInt(this, "QInputDialog::getInt()",
                                         "Nr of VCores:");

            string txt=text.toStdString();

            c.add(new GPU(txt,i2,i3,i4));
            listWidget->clear();
            for(int i=0;i<c.dimension();i++){
               listWidget->addItem(QString::fromStdString(c.getElementString(i)));}

}
}

void MainWindow::addClick_Edit(){
    if(id_line_edit->text() == "")
        {
            int ret = QMessageBox::warning(this, tr("My Application"),
                                           tr("NotGood.\n"),
                                           QMessageBox::Ok);
            return;
        }

    int id = std::stoi(id_line_edit->text().toStdString());
    c.remove(id);
    QStringList items;
        items << tr("Phone ") << tr("Tablet") << tr("Leptop")<<tr("CPU") << tr("GPU");
    QStringList brands;
    brands<<"Apple"<<"Samsung"<<"Huawei"<<"G"<<"Unknown";
        bool ok;
        QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"),
                                             tr("Season:"), items, 0, false, &ok);
        if(item==tr("Phone ")){
            QString text = QInputDialog::getText(this,"QInputDialog::getMultiLineText()","Brand", QLineEdit::Normal);

            float i2 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Pret:");
            float i3 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Freq:");
            int i4 = QInputDialog::getInt(this, "QInputDialog::getInt()",
                                         "Camera:");
            int i5 = QInputDialog::getInt(this, "QInputDialog::getInt()",
                                         "screen size:");
            string txt=text.toStdString();
            c.add(new Phone(txt,i2,i3,i4,i5));
            listWidget->clear();
            for(int i=0;i<c.dimension();i++){
               listWidget->addItem(QString::fromStdString(c.getElementString(i)));

        }


    }else if (item==tr("Tablet")){
            QString text = QInputDialog::getText(this,"QInputDialog::getMultiLineText()","Brand", QLineEdit::Normal);

            float i2 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Pret:");
            float i3 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Freq:");
            int i4 = QInputDialog::getInt(this, "QInputDialog::getInt()",
                                         "Camera:");
            int i5 = QInputDialog::getInt(this, "QInputDialog::getInt()",
                                         "screen size:");
            string txt=text.toStdString();
            c.add(new Tablet(txt,i2,i3,i4,i5));
            listWidget->clear();
            for(int i=0;i<c.dimension();i++){
               listWidget->addItem(QString::fromStdString(c.getElementString(i)));
        }

}else if (item==tr("Leptop")){
            QString text = QInputDialog::getText(this,"QInputDialog::getMultiLineText()","Brand", QLineEdit::Normal);

            float i2 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Pret:");
            float i3 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Freq:");
            int i4 = QInputDialog::getInt(this, "QInputDialog::getInt()",
                                         "Camera:");
            QString text2 = QInputDialog::getText(this,"QInputDialog::getMultiLineText()","Brand", QLineEdit::Normal);
            string txt=text.toStdString();
            string txt2=text2.toStdString();
            c.add(new Leptop(txt,i2,i3,i4,txt2));
            listWidget->clear();
            for(int i=0;i<c.dimension();i++){
               listWidget->addItem(QString::fromStdString(c.getElementString(i)));


        }

}else if(item==tr("CPU")){
            QString text = QInputDialog::getText(this,"QInputDialog::getMultiLineText()","Brand", QLineEdit::Normal);

            float i2 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Pret:");
            float i3 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Freq:");
            int i4 = QInputDialog::getInt(this, "QInputDialog::getInt()",
                                         "Nr of Cores:");

            string txt=text.toStdString();

            c.add(new Processor(txt,i2,i3,i4));
            listWidget->clear();
            for(int i=0;i<c.dimension();i++){
               listWidget->addItem(QString::fromStdString(c.getElementString(i)));}
        }else if (item==tr("GPU")){
            QString text = QInputDialog::getText(this,"QInputDialog::getMultiLineText()","Brand", QLineEdit::Normal);

            float i2 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Pret:");
            float i3 = QInputDialog::getDouble(this, "QInputDialog::getInt()",
                                         "Freq:");
            int i4 = QInputDialog::getInt(this, "QInputDialog::getInt()",
                                         "Nr of VCores:");

            string txt=text.toStdString();

            c.add(new GPU(txt,i2,i3,i4));
            listWidget->clear();
            for(int i=0;i<c.dimension();i++){
               listWidget->addItem(QString::fromStdString(c.getElementString(i)));}

}


}


void MainWindow::undo_ctrlz(){
    c.undo1();
    listWidget->clear();
    for(int i=0;i<c.dimension();i++){

       listWidget->addItem(QString::fromStdString(c.getElementString(i)));}
}
void MainWindow::redo_ctrlx(){
    c.redo1();
    listWidget->clear();
    for(int i=0;i<c.dimension();i++){

       listWidget->addItem(QString::fromStdString(c.getElementString(i)));}
}
void MainWindow::exit_save(){
    c.writeFile();
    MainWindow::close();

}



