#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QHash>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    // getter
    QString getInUser();

private slots:
    void on_btnIngresar_clicked();

private:
    Ui::login *ui;
    QHash<QString, QString> users; // Para carga usuario validados
    QString lastUser; // Ultimo usuario correctamente validado
};

#endif // LOGIN_H
