//under dev
#include "finddialog.h"
#include "ui_finddialog.h"
#include "notepad.h"
#include <QTextEdit>

FindDialog::FindDialog(QWidget *parent) :  QDialog(parent),
    ui2(new Ui::FindDialog)
{
    ui2->setupUi(this);
}

FindDialog::~FindDialog()
{
    delete ui2;
}

void FindDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    //QString q = Notepad::ui->plainTextEdit->toPlainText();
    //ui2->lineEdit = ui->plainTextEdit->toPlainText();
    /*
    QFile file(file_path);
    file_path = file_name; //file_path is updated with new filepath
    if(!file.open(QFile::ReadOnly | QFile::Text  ))
    {
        QMessageBox::warning(this, "Error", "COuldn't open File");
        return;
    }

    QTextStream in(&file);
    QString text  = in.readAll();


    QString find_text = ui->plainTextEdit->toPlainText();
    flag = text::contains(find_text);

    if(flag)
    {


    }
    */
}
