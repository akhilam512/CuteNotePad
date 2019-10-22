#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QString>
#include <QObject>
namespace Ui {
class Notepad;
}

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = 0);
    ~Notepad();


protected:
    Ui::Notepad *ui;
    QString file_path;



private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionAbout_Me_triggered();

    void on_actionRedo_triggered();

    void on_actionChange_Font_triggered();

    //void on_actionText_Colour_triggered();

    //void on_actionBackground_Colour_triggered();

    void on_actionTheme_triggered();

    void on_actionFind_Text_triggered();
};

#endif // NOTEPAD_H
