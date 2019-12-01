#pragma once

#include <QWidget>

namespace n64c {

class ToolsPane;

class ContextPaneUser : public QWidget
{
    Q_OBJECT

public:
    explicit ContextPaneUser(ToolsPane* toolsPane, QWidget* parent=nullptr);

    virtual void onViewActivated() = 0;
    virtual void onViewDeactivated() = 0;

    ToolsPane* toolsPane() { return toolsPane_; }

private:
    ToolsPane* toolsPane_;
};

}
