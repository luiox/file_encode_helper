#include "mainfrm.h"
#include "./ui_mainfrm.h"
#include <QFileDialog>
#include <QLineEdit>
#include <QListWidget>
#include <QDir>
#include <QComboBox>
#include <QMessageBox>
#include <QDebug>

#ifdef _WIN32
#pragma comment (linker,"/subsystem:CONSOLE /entry:mainCRTStartup" )
#endif // WIN32

MainFrm::MainFrm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainFrm)
{
    ui->setupUi(this);

    qDebug() << "test";
    setWindowTitle(tr("file encode helper"));

    init_ui();
}

MainFrm::~MainFrm()
{
    delete ui;
}

void MainFrm::init_ui()
{
    QStringList encodes{"GB2312","UTF-8"};
    auto sec = static_cast<QComboBox*>(ui->centralwidget->findChild<QComboBox*>("source_encode_cmbox"));
    sec->addItems(encodes);

    auto tec = static_cast<QComboBox*>(ui->centralwidget->findChild<QComboBox*>("target_encode_cmbox"));
    tec->addItems(encodes);
}


void MainFrm::on_source_open_dir_btn_clicked()
{
    QString str_dir = QFileDialog::getExistingDirectory(
        this,
        tr("Open Directory"),
        "",
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    auto sde = static_cast<QLineEdit*>(ui->centralwidget->findChild<QLineEdit*>("source_dir_edit"));
    sde->setText(str_dir);

    // Get all file names in this directory.
    QDir dir{str_dir};
    dir.setFilter(QDir::Files|QDir::NoDot|QDir::NoDotDot);
    QStringList files = dir.entryList();

    // Add these to list.
    auto sl = static_cast<QListWidget*>(ui->centralwidget->findChild<QListWidget*>("source_list"));
    //auto count=sl->count();
    for(auto& file:files) {
        QListWidgetItem * item = new QListWidgetItem;
        item->setSizeHint(QSize(sl->width(),50));
        item->setText(file);
        // Set the attribute to double click to be edited and selectable.
        item->setFlags(Qt::ItemIsEditable|Qt::ItemIsEnabled|Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        sl->addItem(item);
    }
}


void MainFrm::on_target_open_dir_btn_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(
        this,
        tr("Open Directory"),
        "",
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    auto tde = static_cast<QLineEdit*>(ui->centralwidget->findChild<QLineEdit*>("target_dir_edit"));
    tde->setText(dir);
}


void MainFrm::on_do_btn_clicked()
{
    // Determine whether the current file encoding is consistent with the target file encoding.
    auto sec = static_cast<QComboBox*>(ui->centralwidget->findChild<QComboBox*>("source_encode_cmbox"));
    auto tec = static_cast<QComboBox*>(ui->centralwidget->findChild<QComboBox*>("target_encode_cmbox"));

    if(sec->currentText()==tec->currentText()){
        QMessageBox::information(this,
                                tr("tips"),
                                tr("The current file encoding and target file encoding are the same!"));
        return;
    }

    // Calculate the source and destination directories for all files.
    auto sl = static_cast<QListWidget*>(ui->centralwidget->findChild<QListWidget*>("source_list"));
    auto sde = static_cast<QLineEdit*>(ui->centralwidget->findChild<QLineEdit*>("source_dir_edit"));
    const auto sdir = sde->text();
    auto tde = static_cast<QLineEdit*>(ui->centralwidget->findChild<QLineEdit*>("target_dir_edit"));
    const auto tdir=tde->text();
    QStringList sldir,tldir;


    for (int i = 0; i < sl->count(); i++) {
        QString file_name = sl->item(i)->text();
        QString sdir=sdir+"\\"+file_name;
        QString tdir=tdir+"\\"+file_name;
        sldir.push_back(sdir);
        tldir.push_back(tdir);
        qDebug()<<sdir;
        qDebug()<<tldir;
    }

    // Change the file encoding and write it out.
}

