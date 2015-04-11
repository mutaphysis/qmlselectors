#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>
#include <QTimer>

#include "matchers.h"

class Watcher : public QObject
{
    Q_OBJECT
public:
    Watcher(QObject *root, const MatcherList& matchers, bool triggerOnce = true, QObject *parent = 0);
    Watcher(QObject *root, const QString& selector, bool triggerOnce = true, QObject *parent = 0);
    virtual ~Watcher();

signals:
    void triggered(QObject* obj);

public slots:
    void start(int intervalMs = 500);
    void stop();

private slots:
    void timerTriggered();
    void rootLost();

private:
    QObject* m_root;
    MatcherList m_matchers;
    bool m_triggerOnce;
    QTimer m_pollTimer;
};

#endif // WATCHER_H
