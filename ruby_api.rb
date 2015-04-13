# encoding: utf-8

# differentiate between the various way to select objects
# SelectFirst - takes the first found object
# SelectAll - takes all the objects
# SelectUnique - takes the only found object, 0 or 2+ cause error



app = TestabilityAppConnection('tcp://localhost:5555')

# Wait for an Object of type Page with the name myTestPage
# to be created on page stack.
# Blocks execution until object found, throws execption when timeout reached
# Polling happens on app side
app.wait_for('#mainWindow PageStack', 'Page#myTestPage', timeout => 3000)

# Clicks in the center of an Object named testButton
# below any object of type Page
# throws when object not found
app.click('Page #testButton')

app.click('Page #testButton', 10, 10)

app.read('Page #testButton')
app.read('Page #testButton', 'someProperty')

app.read_tree('Page #testButton')

app.exists?('Page #testButton')


# strange idea:
# future optimization
# app.select_object('very complex selector')
# returns object id, that can be used for future reference
# eg. @1246, can then be used instead of a selectors, but becomes unusable
# after object is deleted


Simple use case (REQ/REP)

    rb:
        app.click('selector')

    network:
        -> REQ ExecuteAction
            selector
            Action
            action, action_params

    cpp:

        Object* obj = findObject( selector );
        ClickAction action();

        if (object && action.execute(object)) {
            network->reply(OK)
        } else {
            network->reply(NOK)
        }

    network:

        -> REP: [OK, NOK]


Most complicated use case (REQ/REP, PUB/SUB)

    rb:
        app.wait_and_click('Page#myTestPage', timeout => 1000)

    network:
        -> REQ CreateAsyncAction
             Watcher
             root_selector, selector, timeout
             Action
             action, action_params

        -> SUB WatcherStatus, ActionStatus

    c++:
        // AsyncAction:

        ActionId id = generateActionId
        ClickAction action(…); // not executed yet and no target set
        Watcher watcher(…); // waits for the selector to be found

        QObject::connect(watcher, &Watcher::triggered, action, &Action::execute);
        QObject::connect(timeout_timer, &QTimer::triggered, network, &Server::actionFailed);
        QObject::connect(watcher, &Watcher::triggered, action, &Server::watcherTriggered);
        QObject::connect(action, &Action::succeeded, network, &Server::actionSucceeded);
        QObject::connect(action, &Action::failed, network, &Server::actionFailed);

        QObject::connect(network, &Server::actionCancelled, this, &AsyncAction::deleteLater);
        QObject::connect(timeout_timer, &QTimer::triggered, this, &AsyncAction::deleteLater);
        QObject::connect(action, &Action::succeeded, this, &AsyncAction::deleteLater);
        QObject::connect(action, &Action::failed, this, &AsyncAction::deleteLater);


        later

        poll() and some signals, maybe actionSucceeded, maybe actionFailed

    network:

        -> REP: OK, ActionId
                 NOK, when eg. root element was not found

        later

        -> PUB ActionStatus

            ActionId, [OK|NOK]



