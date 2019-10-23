#include "notepad.h"
#include "ui_notepad.h"
#include <QDir>
#include <QTextEdit>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFontDialog>
#include <QColorDialog>

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);


}
Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_actionNew_triggered()
{
    file_path = ""; //file path is reset when new file is clicked
    ui->plainTextEdit->setPlainText(""); //emptying the editor
    
}


void Notepad::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file");

    QFile file(file_name);
    file_path = file_name; //file_path is updated with new filepath
    if(!file.open(QFile::ReadOnly | QFile::Text  ))
    {
        QMessageBox::warning(this, "Error", "COuldn't open File");
        return;
    }

    QTextStream in(&file);
    QString text  = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();


}

void Notepad::on_actionSave_triggered()
{
    if(file_path.isNull()) //First save - (works as same as "Save as")
    {
        //file_path = "";
        QString file_name = QFileDialog::getSaveFileName(this, "Open a file");
        QFile file(file_name);
        file_path = file_name;


    }

    QFile file(file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text  ))
    {
        QMessageBox::warning(this, "Error", "File Not Open");
        return;
    }

    QTextStream out(&file);
    QString text  = ui->plainTextEdit->toPlainText();
    out << text;
    file.flush();
    file.close();


}

void Notepad::on_actionSave_As_triggered()
{
    //ui->plainTextEdit->save();
    QString file_name = QFileDialog::getSaveFileName(this, "Open a file");
    QFile file(file_name);
    file_path = file_name;

    if(!file.open(QFile::WriteOnly | QFile::Text  ))
    {
        QMessageBox::warning(this, "Error", "File Not Open");
        return;
    }

    QTextStream out(&file);
    QString text  = ui->plainTextEdit->toPlainText();
    out << text;
    file.flush();
    file.close();

}

void Notepad::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();

}

void Notepad::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();

}

void Notepad::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}

void Notepad::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
}
void Notepad::on_actionRedo_triggered()
{
    ui->plainTextEdit->redo();
}
void Notepad::on_actionAbout_Me_triggered()
{
   QString a =  "Creator  : akhilam512\n";
    a        +=  "Contributors  : Psy0ch\n";
    a        +=  "Date     : 26 - 10 - 2018\n";
    a        +=  "  -- Notepad -- ";

    QMessageBox::about(this, "About Noteza", a);
}



void Notepad::on_actionChange_Font_triggered()
{
    bool uhuhh;
    QFont font = QFontDialog::getFont(&uhuhh, this);

    if(uhuhh)
    {
        ui->plainTextEdit->setFont(font);

    }else return;

}
/*
void Notepad::on_actionText_Colour_triggered()
{

    QColor colour = QColorDialog::getColor(Qt::white, this, "Choose Colour");
    if(colour.isValid())
    {
        ui->plainTextEdit->setPalette(QPalette::WindowText;

    }
}


void Notepad::on_actionBackground_Colour_triggered()
{
    QColor colour = QColorDialog::getColor(Qt::white, this, "Choose Colour");
    if(colour.isValid())
    {
        ui->plainTextEdit->setPalette(QPalette::Window(colour));

    }
}

*/

void Notepad::on_actionTheme_triggered()
{

}

void Notepad::on_actionFind_Text_triggered()
{

}
