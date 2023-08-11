#include "mainfrm.h"
#include "./ui_mainfrm.h"
#include <QFileDialog>
#include <QLineEdit>
#include <QListWidget>
#include <QDir>


MainFrm::MainFrm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainFrm)
{
    ui->setupUi(this);
}

MainFrm::~MainFrm()
{
    delete ui;
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
    dir.setFilter(QDir::AllDirs|QDir::NoDot|QDir::NoDotDot);
    QStringList files = dir.entryList();

    // Add these to list.
    auto sl = static_cast<QListWidget*>(ui->centralwidget->findChild<QListWidget*>("source_list"));
    //auto count=sl->count();
    for(auto file:files) {
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

