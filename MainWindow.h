#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QSettings>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void saveNote();
    void loadNote();
    void toggleTheme();

private:
    QTextEdit *textEdit;
    QPushButton *saveButton;
    QPushButton *themeButton;
    bool darkMode;
    void applyTheme();
};

#endif // MAINWINDOW_H