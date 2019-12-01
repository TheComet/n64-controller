#include "n64c/views/ToolsPane.hpp"

#include <QVBoxLayout>
#include <QApplication>
#include <QStyle>

namespace n64c {

// ----------------------------------------------------------------------------
ToolsPane::ToolsPane(QWidget* parent) :
    QScrollArea(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    tools_ = new QWidget;
    QVBoxLayout* toolsLayout = new QVBoxLayout;
    tools_->setLayout(toolsLayout);

    QVBoxLayout* contentsLayout = new QVBoxLayout;
    contentsLayout->addWidget(tools_);
    contentsLayout->addStretch();

    QWidget* scrollAreaContents = new QWidget;
    scrollAreaContents->setLayout(contentsLayout);
    setWidget(scrollAreaContents);
    setWidgetResizable(true);

    adjustMinimumWidth();
}

// ----------------------------------------------------------------------------
ToolsPane::~ToolsPane()
{
}

// ----------------------------------------------------------------------------
void ToolsPane::addWidget(QWidget* w)
{
    tools_->layout()->addWidget(w);
    adjustMinimumWidth();
}

// ----------------------------------------------------------------------------
void ToolsPane::removeWidget(QWidget* w)
{
    tools_->layout()->removeWidget(w);
    adjustMinimumWidth();
}

// ----------------------------------------------------------------------------
void ToolsPane::adjustMinimumWidth()
{
    int toolsWidth = tools_->minimumSizeHint().width();
    int scrollBarWidth = QApplication::style()->pixelMetric(QStyle::PM_ScrollBarExtent);
    setMinimumWidth(toolsWidth + scrollBarWidth);
}

}
