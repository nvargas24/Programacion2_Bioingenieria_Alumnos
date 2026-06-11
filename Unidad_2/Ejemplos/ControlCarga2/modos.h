#ifndef MODOS_H
#define MODOS_H

#include <QDialog>

namespace Ui {
class Modos;
}

class Modos : public QDialog
{
    Q_OBJECT

public:
    explicit Modos(QWidget *parent = nullptr);
    ~Modos();

    // getter
    QString getModo();

    // setter
    void setModo(QString mode);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Modos *ui;
};

#endif // MODOS_H
