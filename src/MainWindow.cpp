#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pageLogin);
    connect(ui->btnLogin, &QPushButton::clicked, this, &MainWindow::onLoginClicked);
    connect(ui->btnSignup, &QPushButton::clicked, this, &MainWindow::onSignupClicked);
    connect(ui->btnLogoutStudent, &QPushButton::clicked, this, &MainWindow::onLogoutClicked);
    connect(ui->btnLogoutFaculty, &QPushButton::clicked, this, &MainWindow::onLogoutClicked);
    connect(ui->btnLogoutAdmin, &QPushButton::clicked, this, &MainWindow::onLogoutClicked);
    connect(ui->btnViewContentStudent, &QPushButton::clicked, this, &MainWindow::onViewContentStudent);
    connect(ui->btnAddCourse, &QPushButton::clicked, this, &MainWindow::onAddCourse);
    connect(ui->btnAddMarks, &QPushButton::clicked, this, &MainWindow::onAddMarks);
    connect(ui->btnAddContentFaculty, &QPushButton::clicked, this, &MainWindow::onAddContentFaculty);
    connect(ui->btnAddContentAdmin, &QPushButton::clicked, this, &MainWindow::onAddContentAdmin);
    connect(ui->btnDeleteContentAdmin, &QPushButton::clicked, this, &MainWindow::onDeleteContentAdmin);
    connect(ui->btnViewAllContentAdmin, &QPushButton::clicked, this, &MainWindow::onViewAllContentAdmin);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoginClicked() {
    QString username = ui->editUsername->text();
    QString password = ui->editPassword->text();
    QString role = ui->comboRole->currentText();
    if (role == "Student") {
        if (userManager.login(username.toStdString(), password.toStdString())) {
            ui->stackedWidget->setCurrentWidget(ui->pageStudent);
        } else {
            QMessageBox::warning(this, "Login Failed", "Invalid student credentials.");
        }
    } else if (role == "Faculty") {
        if (userManager.login(username.toStdString(), password.toStdString())) {
            ui->stackedWidget->setCurrentWidget(ui->pageFaculty);
        } else {
            QMessageBox::warning(this, "Login Failed", "Invalid faculty credentials.");
        }
    } else if (role == "Admin") {
        if (username == "altahanrauf" && password == "2003") {
            ui->stackedWidget->setCurrentWidget(ui->pageAdmin);
        } else {
            QMessageBox::warning(this, "Login Failed", "Invalid admin credentials.");
        }
    }
}

void MainWindow::onSignupClicked() {
    QString username = ui->editUsername->text();
    QString password = ui->editPassword->text();
    if (userManager.signup(username.toStdString(), password.toStdString())) {
        QMessageBox::information(this, "Signup", "Signup successful!");
    } else {
        QMessageBox::warning(this, "Signup Failed", "Username already exists.");
    }
}

void MainWindow::onLogoutClicked() {
    ui->editUsername->clear();
    ui->editPassword->clear();
    ui->stackedWidget->setCurrentWidget(ui->pageLogin);
}

void MainWindow::onViewContentStudent() {
    // Placeholder: integrate with Content class
    QMessageBox::information(this, "Content", "View Content (to be implemented)");
}

void MainWindow::onAddCourse() {
    QMessageBox::information(this, "Add Course", "Feature: Add Course (to be implemented)");
}

void MainWindow::onAddMarks() {
    QMessageBox::information(this, "Add Marks", "Feature: Add Marks (to be implemented)");
}

void MainWindow::onAddContentFaculty() {
    bool ok;
    QString content = QInputDialog::getText(this, "Add Content", "Enter content to add for student:", QLineEdit::Normal, "", &ok);
    if (ok && !content.isEmpty()) {
        adminManager.addContent(content.toStdString());
        QMessageBox::information(this, "Content", "Content added for student.");
    }
}

void MainWindow::onAddContentAdmin() {
    bool ok;
    QString content = QInputDialog::getText(this, "Add Content", "Enter content to add:", QLineEdit::Normal, "", &ok);
    if (ok && !content.isEmpty()) {
        adminManager.addContent(content.toStdString());
        QMessageBox::information(this, "Content", "Content added.");
    }
}

void MainWindow::onDeleteContentAdmin() {
    bool ok;
    int id = QInputDialog::getInt(this, "Delete Content", "Enter content ID to delete:", 0, 0, 10000, 1, &ok);
    if (ok) {
        adminManager.deleteContent(id);
        QMessageBox::information(this, "Content", "Content deleted.");
    }
}

void MainWindow::onViewAllContentAdmin() {
    // Placeholder: integrate with Admin class
    QMessageBox::information(this, "Content", "View All Content (to be implemented)");
}