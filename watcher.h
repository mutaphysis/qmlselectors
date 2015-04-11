#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>
#include <QTimer>

#include "matchers.h"

/**
 * The Watcher polls in a regular interval for a selector and triggers whenver it matches.
 *
 * This can be used for detecting elements having a certain state.
 * As it is polling in fixed intervalls, it is not guaranteed to detect all changes.
 */
class Watcher : public QObject
{
    Q_OBJECT
public:
    /**
     * Creates a new watcher with a selector
     *
     * @param root The root node for which to start checking.
     * @param selector The selector to check against
     * @param triggerOnce if true will stop polling after the first match is found
     * @param parent The parent QObject, if NULL unparented
     */
    Watcher(QObject *root, const QString& selector, bool triggerOnce = true, QObject *parent = 0);

    /**
     * Creates a new watcher with a matcher list
     *
     * @param root The root node for which to start checking.
     * @param matchers The matchers to check against
     * @param triggerOnce if true will stop polling after the first match is found
     * @param parent The parent QObject, if NULL unparented
     */
    Watcher(QObject *root, const MatcherList& matchers, bool triggerOnce = true, QObject *parent = 0);
    /** Destructor */
    virtual ~Watcher();

signals:
    /**
     * Emitted whenever an object is found that matches the watcher criteria
     * @param obj The matched object
     */
    void triggered(QObject* obj);

public slots:
    /**
     * Starts polling
     * @param intervalMs the interval of polling in ms
     */
    void start(int intervalMs = 500);
    /**
     * Stops polling, will fire no more triggered signals
     */
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
