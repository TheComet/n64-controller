#include "n64c/views/NodeEditor.hpp"
#include "n64c/ui_NodeEditor.h"
#include "n64c/models/nodes/MathOperationModel.hpp"
#include "n64c/models/nodes/N64ControllerInputDataModel.hpp"
#include "n64c/models/nodes/N64ControllerOutputDataModel.hpp"

#include <nodes/DataModelRegistry>
#include <nodes/FlowScene>
#include <nodes/FlowView>
#include <nodes/Node>

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

    QtNodes::Node& input = scene->createNode(scene->registry().create("N64 Input"));
    QtNodes::Node& output = scene->createNode(scene->registry().create("N64 Output"));

    input.nodeGraphicsObject().setPos(200, 200);
    output.nodeGraphicsObject().setPos(700, 200);

    for (unsigned i = 0; i != input.nodeDataModel()->nPorts(PortType::Out); i++)
        scene->createConnection(output, i, input, i);
}

// ----------------------------------------------------------------------------
NodeEditor::~NodeEditor()
{
    delete ui_;
}

}
