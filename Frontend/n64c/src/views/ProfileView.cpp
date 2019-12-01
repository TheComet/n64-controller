#include "n64c/views/NodeEditor.hpp"
#include "n64c/views/ProfileView.hpp"
#include "n64c/ui_ProfileView.h"
#include "n64c/views/ToolsPane.hpp"
#include "QtColorWidgets/ColorWheel"
#include "QtColorWidgets/ColorSelector"
#include "QtColorWidgets/HueSlider"
#include "QtColorWidgets/ColorDelegate"
#include "QtColorWidgets/ColorPreview"

#include <QLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>

namespace n64c {

// ----------------------------------------------------------------------------
ProfileView::ProfileView(ToolsPane* toolsPane, QWidget* parent) :
    ContextPaneUser(toolsPane, parent),
    ui_(new Ui::ProfileView)
{
    ui_->setupUi(this);

    // Group box for holding profile settings
    toolPaneColor_ = new QGroupBox("Profile Settings");
    toolPaneColor_->setMinimumHeight(250);
    toolsPane->addWidget(toolPaneColor_);
    QVBoxLayout* colorGroupLayout = new QVBoxLayout;
    toolPaneColor_->setLayout(colorGroupLayout);

    // Profile color picker
    colorWheel_ = new color_widgets::ColorWheel;
    color_widgets::ColorPreview* colorPreview = new color_widgets::ColorPreview;
    colorPreview->setFixedHeight(40);
    colorGroupLayout->addWidget(colorWheel_);
    colorGroupLayout->addWidget(colorPreview);

    // Profile name
    QHBoxLayout* profileNameLayout = new QHBoxLayout;
    profileName_ = new QLineEdit;
    profileNameLayout->addWidget(new QLabel("Name:"));
    profileNameLayout->addWidget(profileName_);
    colorGroupLayout->addLayout(profileNameLayout);

    ui_->layout_nodeEditor->addWidget(new NodeEditor);

    connect(colorWheel_, SIGNAL(colorChanged(QColor)), this, SLOT(onProfileColorChanged(QColor)));
    connect(colorWheel_, SIGNAL(colorChanged(QColor)), colorPreview, SLOT(setColor(QColor)));
    connect(profileName_, SIGNAL(textChanged(const QString&)), this, SLOT(onProfileNameChanged(const QString&)));
}

// ----------------------------------------------------------------------------
ProfileView::~ProfileView()
{
    delete ui_;
}

// ----------------------------------------------------------------------------
void ProfileView::loadDefaultSettings()
{
    colorWheel_->setColor(QColor(255, 0, 0));
    profileName_->setText("");
    emit profileNameChanged("");  // Required so the tab names update
}

// ----------------------------------------------------------------------------
void ProfileView::loadFromFile(const QString& fileName)
{
}

// ----------------------------------------------------------------------------
void ProfileView::onViewActivated()
{
    toolPaneColor_->setVisible(true);
}

// ----------------------------------------------------------------------------
void ProfileView::onViewDeactivated()
{
    toolPaneColor_->setVisible(false);
}

// ----------------------------------------------------------------------------
void ProfileView::onProfileColorChanged(QColor color)
{
    emit profileColorChanged(color);
}

// ----------------------------------------------------------------------------
void ProfileView::onProfileNameChanged(const QString& name)
{
    emit profileNameChanged(name);
}

}
