#include "n64c/views/NodeEditor.hpp"
#include "n64c/ui_NodeEditor.h"
#include "n64c/models/nodes/MathOperationModel.hpp"
#include "n64c/models/nodes/N64ControllerInputDataModel.hpp"
#include "n64c/models/nodes/N64ControllerOutputDataModel.hpp"

#include <nodes/DataModelRegistry>
#include <nodes/FlowScene>
#include <nodes/FlowView>

namespace n64c {

// ----------------------------------------------------------------------------
static std::shared_ptr<QtNodes::DataModelRegistry>
registerDataModels()
{
    auto reg = std::make_shared<QtNodes::DataModelRegistry>();
    reg->registerModel<N64ControllerInputDataModel>("Input");
    reg->registerModel<N64ControllerOutputDataModel>("Output");
    reg->registerModel<MathOperationModel>("Converters");
    return reg;
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
