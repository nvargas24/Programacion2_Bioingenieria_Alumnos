#ifndef CONFIGVALUE_H
#define CONFIGVALUE_H

#include <QDialog>

namespace Ui {
class configValue;
}

class configValue : public QDialog
{
    Q_OBJECT

public:
    explicit configValue(QWidget *parent = nullptr);
    ~configValue();

private:
    Ui::configValue *ui;
};

#endif // CONFIGVALUE_H
