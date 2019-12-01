#include "n64c/views/ContextPaneUser.hpp"

namespace n64c {

// ----------------------------------------------------------------------------
ContextPaneUser::ContextPaneUser(ToolsPane* toolsPane, QWidget* parent) :
    QWidget(parent),
    toolsPane_(toolsPane)
{
}

}
