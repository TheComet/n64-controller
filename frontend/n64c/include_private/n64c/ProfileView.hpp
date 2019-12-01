#pragma once

#include "n64c/ContextPaneUser.hpp"

class QLineEdit;

namespace Ui {
    class ProfileView;
}

namespace color_widgets {
    class ColorWheel;
}

namespace n64c {

class ProfileView : public ContextPaneUser
{
    Q_OBJECT

public:
    explicit ProfileView(ToolsPane* toolsPane, QWidget* parent=nullptr);
    ~ProfileView();

    void loadDefaultSettings();
    void loadFromFile(const QString& fileName);

signals:
    void profileColorChanged(QColor);
    void profileNameChanged(const QString& name);

protected:
    void onViewActivated() override;
    void onViewDeactivated() override;

private slots:
    void onProfileColorChanged(QColor);
    void onProfileNameChanged(const QString& name);

private:
    Ui::ProfileView* ui_;
    QWidget* toolPaneColor_;
    QLineEdit* profileName_;
    color_widgets::ColorWheel* colorWheel_;
};

}
