#include "watcher.h"

#include <QDebug>

Watcher::Watcher(QObject* root, SharedMatcher matcher, bool triggerOnce, QObject* parent)
    : QObject(parent)
    , m_root(root)
    , m_matcher(matcher)
    , m_triggerOnce(triggerOnce)
{
    Q_ASSERT(m_root);

    m_pollTimer.setSingleShot(false);

    QObject::connect(root, &QObject::destroyed, this, &Watcher::rootLost);
    QObject::connect(&m_pollTimer, &QTimer::timeout, this, &Watcher::timerTriggered);
}

Watcher::~Watcher()
{
}

void Watcher::start(int intervalMs)
{
    if (m_pollTimer.isActive()) {
        stop();
    }

    m_pollTimer.setInterval(intervalMs);
    m_pollTimer.start();
}

void Watcher::stop()
{
    m_pollTimer.stop();
}

void Watcher::timerTriggered()
{
    if (m_root == NULL) {
        return;
    }

    QObject* result = ObjectVisitor::findFirstObject(m_root, m_matcher);

    if (result) {
        triggered(result);

        if (m_triggerOnce) {
            stop();
        }
    }
}

void Watcher::rootLost()
{
    qDebug() << "Watcher lost root node, stopping.";
    m_root = NULL;
    stop();
}

