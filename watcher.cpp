#include "watcher.h"

#include "matchergenerator.h"

#include <QDebug>

Watcher::Watcher(QObject* root, const MatcherList& matchers, bool triggerOnce, QObject* parent)
    : QObject(parent)
    , m_root(root)
    , m_matchers(matchers)
    , m_triggerOnce(triggerOnce)
{
    Q_ASSERT(m_root);

    m_pollTimer.setSingleShot(false);

    if (m_matchers.empty()) {
        qCritical() << "No matchers found for watcher, will never match!";
    }

    QObject::connect(root, &QObject::destroyed, this, &Watcher::rootLost);
    QObject::connect(&m_pollTimer, &QTimer::timeout, this, &Watcher::timerTriggered);
}

Watcher::Watcher(QObject *root, const QString &selector, bool triggerOnce, QObject *parent)
    : QObject(parent)
    , m_root(root)
    , m_triggerOnce(triggerOnce)
{
    Q_ASSERT(m_root);

    bool error;
    m_matchers = MatcherGenerator::parse(selector, &error);

    if (error) {
        qCritical() << "Failed parsing selector for watcher, will never match!";
    } else if (m_matchers.empty()) {
        qCritical() << "No matchers found for watcher, will never match!";
    }

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

    QObject* result = ObjectVisitor::findFirstObject(m_root, m_matchers);

    if (result) {
        qDebug() << "Watcher found match, triggering.";
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

