#ifndef MAINFRM_H
#define MAINFRM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainFrm; }
QT_END_NAMESPACE

class MainFrm : public QMainWindow
{
    Q_OBJECT

public:
    MainFrm(QWidget *parent = nullptr);
    ~MainFrm();

private slots:
    void on_source_open_dir_btn_clicked();

    void on_target_open_dir_btn_clicked();

private:
    Ui::MainFrm *ui;
};
#endif // MAINFRM_H
