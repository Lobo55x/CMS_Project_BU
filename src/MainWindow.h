#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "User.h"
#include "Admin.h"
#include "Content.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoginClicked();
    void onSignupClicked();
    void onLogoutClicked();
    void onViewContentStudent();
    void onAddCourse();
    void onAddMarks();
    void onAddContentFaculty();
    void onAddContentAdmin();
    void onDeleteContentAdmin();
    void onViewAllContentAdmin();

private:
    Ui::MainWindow *ui;
    User userManager;
    Admin adminManager;
    Content contentViewer;
};

#endif // MAINWINDOW_H