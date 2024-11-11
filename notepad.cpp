#include "notepad.h"

Notepad::Notepad(QWidget *parent) : QWidget(parent) {
    textEdit = new QTextEdit(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textEdit);

    QMenuBar *menuBar = new QMenuBar(this);

    // Create file menu
    QMenu *fileMenu = new QMenu("File", this);
    QAction *openAction = new QAction("Open", this);
    QAction *saveAction = new QAction("Save", this);

    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    menuBar->addMenu(fileMenu);

    layout->setMenuBar(menuBar);
    setLayout(layout);

    connect(openAction, &QAction::triggered, this, &Notepad::openFile);
    connect(saveAction, &QAction::triggered, this, &Notepad::saveFile);
    setWindowTitle("Notepad");
    resize(600, 400);
}

void Notepad::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            textEdit->setPlainText(in.readAll());
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Could not open file.");
        }
    }
}

void Notepad::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);;All Files (*)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << textEdit->toPlainText();
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Could not save file.");
        }
    }
}
