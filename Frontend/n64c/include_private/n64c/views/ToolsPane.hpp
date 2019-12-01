#pragma once

#include <QScrollArea>

namespace n64c {

class ToolsPane : public QScrollArea
{
    Q_OBJECT

public:
    explicit ToolsPane(QWidget* parent=nullptr);
    ~ToolsPane();

    void addWidget(QWidget* widget);
    void removeWidget(QWidget* widget);

private:
    void adjustMinimumWidth();

private:
    QWidget* tools_;
};

}
