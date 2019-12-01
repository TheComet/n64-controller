#pragma once

#include <QWidget>

namespace Ui {
    class NodeEditor;
}

namespace n64c {

class NodeEditor : public QWidget
{
    Q_OBJECT

public:
    explicit NodeEditor(QWidget* parent=nullptr);
    ~NodeEditor();

private:
    Ui::NodeEditor* ui_;
};

}
