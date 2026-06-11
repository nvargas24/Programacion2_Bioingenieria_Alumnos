#ifndef AUXILIARB_H
#define AUXILIARB_H

#include <QDialog>

namespace Ui {
class auxiliarB;
}

class auxiliarB : public QDialog
{
    Q_OBJECT

public:
    explicit auxiliarB(QWidget *parent = nullptr);
    ~auxiliarB();

private:
    Ui::auxiliarB *ui;
};

#endif // AUXILIARB_H
