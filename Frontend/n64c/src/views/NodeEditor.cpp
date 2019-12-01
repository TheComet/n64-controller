#include "n64c/views/NodeEditor.hpp"
#include "n64c/ui_NodeEditor.h"

#include <nodes/DataModelRegistry>
#include <nodes/FlowScene>
#include <nodes/FlowView>

namespace n64c {

// ----------------------------------------------------------------------------
static std::shared_ptr<QtNodes::DataModelRegistry>
registerDataModels()
{
    auto ret = std::make_shared<QtNodes::DataModelRegistry>();
    return ret;
}

// ----------------------------------------------------------------------------
NodeEditor::NodeEditor(QWidget* parent) :
    QWidget(parent),
    ui_(new Ui::NodeEditor)
{
    ui_->setupUi(this);

    QtNodes::FlowScene* scene = new QtNodes::FlowScene(registerDataModels(), this);
    QtNodes::FlowView* view = new QtNodes::FlowView(scene);
    ui_->layout_nodeEditor->addWidget(view);
}

// ----------------------------------------------------------------------------
NodeEditor::~NodeEditor()
{
    delete ui_;
}

}
