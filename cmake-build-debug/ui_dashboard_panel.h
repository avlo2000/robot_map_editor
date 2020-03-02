/********************************************************************************
** Form generated from reading UI file 'dashboard_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_PANEL_H
#define UI_DASHBOARD_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DashboardPanelUI
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *PlanLoadingGroupBox;
    QHBoxLayout *horizontalLayout;
    QLineEdit *PlanFilePathLineEdit;
    QPushButton *LoadPlanButton;
    QPushButton *CancelBtn;
    QProgressBar *PlanProgressBar;

    void setupUi(QWidget *DashboardPanelUI)
    {
        if (DashboardPanelUI->objectName().isEmpty())
            DashboardPanelUI->setObjectName(QStringLiteral("DashboardPanelUI"));
        DashboardPanelUI->resize(427, 556);
        verticalLayout = new QVBoxLayout(DashboardPanelUI);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        PlanLoadingGroupBox = new QGroupBox(DashboardPanelUI);
        PlanLoadingGroupBox->setObjectName(QStringLiteral("PlanLoadingGroupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PlanLoadingGroupBox->sizePolicy().hasHeightForWidth());
        PlanLoadingGroupBox->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(PlanLoadingGroupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        PlanFilePathLineEdit = new QLineEdit(PlanLoadingGroupBox);
        PlanFilePathLineEdit->setObjectName(QStringLiteral("PlanFilePathLineEdit"));
        PlanFilePathLineEdit->setEnabled(true);

        horizontalLayout->addWidget(PlanFilePathLineEdit);

        LoadPlanButton = new QPushButton(PlanLoadingGroupBox);
        LoadPlanButton->setObjectName(QStringLiteral("LoadPlanButton"));
        LoadPlanButton->setEnabled(true);

        horizontalLayout->addWidget(LoadPlanButton);

        CancelBtn = new QPushButton(PlanLoadingGroupBox);
        CancelBtn->setObjectName(QStringLiteral("CancelBtn"));

        horizontalLayout->addWidget(CancelBtn);


        verticalLayout->addWidget(PlanLoadingGroupBox);

        PlanProgressBar = new QProgressBar(DashboardPanelUI);
        PlanProgressBar->setObjectName(QStringLiteral("PlanProgressBar"));
        PlanProgressBar->setValue(0);
        PlanProgressBar->setTextVisible(true);
        PlanProgressBar->setTextDirection(QProgressBar::TopToBottom);
        PlanProgressBar->setFormat(QStringLiteral("%p%"));

        verticalLayout->addWidget(PlanProgressBar);


        retranslateUi(DashboardPanelUI);

        QMetaObject::connectSlotsByName(DashboardPanelUI);
    } // setupUi

    void retranslateUi(QWidget *DashboardPanelUI)
    {
        DashboardPanelUI->setWindowTitle(QApplication::translate("DashboardPanelUI", "Form", 0));
        PlanLoadingGroupBox->setTitle(QApplication::translate("DashboardPanelUI", "Load point cloud", 0));
        PlanFilePathLineEdit->setText(QString());
        LoadPlanButton->setText(QApplication::translate("DashboardPanelUI", "Load", 0));
        CancelBtn->setText(QApplication::translate("DashboardPanelUI", "Unload", 0));
    } // retranslateUi

};

namespace Ui {
    class DashboardPanelUI: public Ui_DashboardPanelUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_PANEL_H
