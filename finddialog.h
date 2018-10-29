#ifndef FINDDIALOG_H
#define FINDDIALOG_H
#include "notepad.h"
#include <QDialog>
#include <QAbstractButton>


namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = 0);
    ~FindDialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    

private:
    Ui::FindDialog *ui2;
    QAbstractButton *button;
};

#endif // FINDDIALOG_H
