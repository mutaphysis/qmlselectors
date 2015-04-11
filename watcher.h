#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>
#include <QTimer>

#include "matchers.h"

class Watcher : public QObject
{
    Q_OBJECT
public:
    Watcher(QObject *root, SharedMatcher matcher, bool triggerOnce = true, QObject *parent = 0);
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
    SharedMatcher m_matcher;
    bool m_triggerOnce;
    QTimer m_pollTimer;
};

#endif // WATCHER_H
