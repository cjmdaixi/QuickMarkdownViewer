#ifndef APPGLOBAL_H
#define APPGLOBAL_H

#include <QObject>
#include <QQuickTextDocument>

class AppGlobal : public QObject
{
    Q_OBJECT
public:
    explicit AppGlobal(QObject *parent = nullptr);

signals:

public slots:
    QString readAll(QString path);
    void setDefaultStyleSheet(QQuickTextDocument* qd);
    void setBaseUrl(QQuickTextDocument* qd, QUrl url);
    QString fileSuffix(const QString &filePath);
    QString fileDir(const QString &filePath);
};

#endif // APPGLOBAL_H
