#include "MainWindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), darkMode(false) {
    textEdit = new QTextEdit(this);
    saveButton = new QPushButton("Save", this);
    themeButton = new QPushButton("Toggle Theme", this);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(textEdit);
    layout->addWidget(saveButton);
    layout->addWidget(themeButton);

    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveNote);
    connect(themeButton, &QPushButton::clicked, this, &MainWindow::toggleTheme);

    loadNote();
    applyTheme();

    setCentralWidget(centralWidget);
    setWindowTitle("Quick Notes");
    resize(400, 300);
}

MainWindow::~MainWindow() {
    saveNote(); // autosave on exit
}

void MainWindow::saveNote() {
    QFile file("note.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << textEdit->toPlainText();
        file.close();
    }
}

void MainWindow::loadNote() {
    QFile file("note.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        textEdit->setPlainText(in.readAll());
        file.close();
    }
}

void MainWindow::toggleTheme() {
    darkMode = !darkMode;
    applyTheme();
}

void MainWindow::applyTheme() {
    if (darkMode) {
        qApp->setStyleSheet("QTextEdit { background-color: #121212; color: white; }"
                            "QPushButton { background-color: #333333; color: white; }");
    } else {
        qApp->setStyleSheet("");
    }
}
