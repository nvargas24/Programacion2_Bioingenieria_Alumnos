#ifndef CONFIGPERSONAL_H
#define CONFIGPERSONAL_H

#include <QDialog>

namespace Ui {
class configPersonal;
}

class configPersonal : public QDialog
{
    Q_OBJECT

public:
    explicit configPersonal(QWidget *parent = nullptr);
    ~configPersonal();

private:
    Ui::configPersonal *ui;
};

#endif // CONFIGPERSONAL_H
