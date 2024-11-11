#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QWidget>
#include <QTextEdit>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QVBoxLayout>

class Notepad : public QWidget {
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);

private slots:
    void openFile();
    void saveFile();

private:
    QTextEdit *textEdit;
};

#endif // NOTEPAD_H
