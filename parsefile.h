#ifndef PARSEFILE_H
#define PARSEFILE_H

#include <QObject>

class ParseFile : public QObject
{
    Q_OBJECT
public:
    ParseFile(QObject *parent = 0);

public slots:
    void open();
};

#endif // PARSEFILE_H
