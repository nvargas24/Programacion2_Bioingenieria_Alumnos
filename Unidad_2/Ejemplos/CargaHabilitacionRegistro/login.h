#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QHash>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_btnAceptar_clicked();

private:
    Ui::login *ui;
    QHash<QString, QString> users;
};

#endif // LOGIN_H
