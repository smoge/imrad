// Generated with ImRAD 0.9
// visit github.com/tpecholt/imrad

#include "ui_horiz_layout.h"
#include "node_container.h"

HorizLayout horizLayout;

void HorizLayout::OpenPopup(std::function<void(ImRad::ModalResult)> clb)
{
    callback = clb;
    modalResult = ImRad::None;
    ImRad::GetUserData().dimBgRatio = 1.f;
    ImGui::OpenPopup(ID);
    Init();
}

void HorizLayout::ClosePopup(ImRad::ModalResult mr)
{
    modalResult = mr;
    ImRad::GetUserData().dimBgRatio = 0.f;
}

void HorizLayout::Draw()
{
    /// @style imrad
    /// @unit px
    /// @begin TopWindow
    ID = ImGui::GetID("###HorizLayout");
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 10, 10 });
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, { 5, 10 });
    ImGui::SetNextWindowSize({ 0, 0 }); //{ 640, 480 }
    bool tmpOpen = true;
    if (ImGui::BeginPopupModal("Table Layout Helper###HorizLayout", &tmpOpen, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse))
    {
        if (ImRad::GetUserData().activeActivity != "")
            ImRad::RenderDimmedBackground(ImRad::GetUserData().WorkRect(), ImRad::GetUserData().dimBgRatio);
        if (modalResult != ImRad::None)
        {
            ImGui::CloseCurrentPopup();
            if (modalResult != ImRad::Cancel)
                callback(modalResult);
        }
        /// @separator

        // TODO: Add Draw calls of dependent popup windows here

        /// @begin Text
        ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyle().Colors[ImGuiCol_TextDisabled]);
        ImGui::TextUnformatted("Choose alignment");
        ImGui::PopStyleColor();
        /// @end Text

        /// @begin Button
        ImGui::PushStyleColor(ImGuiCol_Button, ImGui::GetStyle().Colors[alignment==0?ImGuiCol_ButtonHovered:ImGuiCol_Button]);
        if (ImGui::Button("\xef\x80\xb6", { 0, 0 }))
        {
            OnAlignment();
        }
        ImGui::PopStyleColor();
        if (ImGui::IsItemHovered(ImGuiHoveredFlags_ForTooltip))
            ImGui::SetTooltip("Align left (removes table layout)");
        /// @end Button

        /// @begin Button
        ImGui::SameLine(0, 1 * ImGui::GetStyle().ItemSpacing.x);
        ImGui::PushStyleColor(ImGuiCol_Button, ImGui::GetStyle().Colors[alignment==1?ImGuiCol_ButtonHovered:ImGuiCol_Button]);
        if (ImGui::Button("\xef\x80\xb7", { 0, 0 }))
        {
            OnAlignment();
        }
        ImGui::PopStyleColor();
        if (ImGui::IsItemHovered(ImGuiHoveredFlags_ForTooltip))
            ImGui::SetTooltip("Center");
        /// @end Button

        /// @begin Button
        ImGui::SameLine(0, 1 * ImGui::GetStyle().ItemSpacing.x);
        ImGui::PushStyleColor(ImGuiCol_Button, ImGui::GetStyle().Colors[alignment==2?ImGuiCol_ButtonHovered:ImGuiCol_Button]);
        if (ImGui::Button("\xef\x80\xb8", { 0, 0 }))
        {
            OnAlignment();
        }
        ImGui::PopStyleColor();
        if (ImGui::IsItemHovered(ImGuiHoveredFlags_ForTooltip))
            ImGui::SetTooltip("Align right");
        /// @end Button

        /// @begin Button
        ImGui::SameLine(0, 1 * ImGui::GetStyle().ItemSpacing.x);
        ImGui::PushStyleColor(ImGuiCol_Button, ImGui::GetStyle().Colors[alignment==3?ImGuiCol_ButtonHovered:ImGuiCol_Button]);
        if (ImGui::Button("\xef\x80\xb9", { 0, 0 }))
        {
            OnAlignment();
        }
        ImGui::PopStyleColor();
        if (ImGui::IsItemHovered(ImGuiHoveredFlags_ForTooltip))
            ImGui::SetTooltip("Align left and right");
        /// @end Button

        /// @begin Button
        ImGui::SameLine(0, 1 * ImGui::GetStyle().ItemSpacing.x);
        ImGui::PushStyleColor(ImGuiCol_Button, ImGui::GetStyle().Colors[alignment==4?ImGuiCol_ButtonHovered:ImGuiCol_Button]);
        if (ImGui::Button("\xef\x96\x8d", { 0, 0 }))
        {
            OnAlignment();
        }
        ImGui::PopStyleColor();
        if (ImGui::IsItemHovered(ImGuiHoveredFlags_ForTooltip))
            ImGui::SetTooltip("Regular spacing");
        /// @end Button

        /// @begin Text
        ImRad::Spacing(1);
        ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyle().Colors[ImGuiCol_TextDisabled]);
        ImGui::TextUnformatted("Item spacing");
        ImGui::PopStyleColor();
        /// @end Text

        /// @begin Selectable
        ImGui::PushStyleVar(ImGuiStyleVar_SelectableTextAlign, { 1.f, 0 });
        ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
        ImGui::AlignTextToFramePadding();
        ImRad::Selectable("spacing", false, ImGuiSelectableFlags_NoAutoClosePopups, { 65, 0 });
        ImGui::PopItemFlag();
        ImGui::PopStyleVar();
        /// @end Selectable

        /// @begin Input
        ImGui::SameLine(0, 2 * ImGui::GetStyle().ItemSpacing.x);
        ImGui::SetNextItemWidth(100);
        ImGui::InputInt("##spacing", &spacing, 1);
        if (ImGui::IsItemActive())
            ImRad::GetUserData().imeType = ImRad::ImeNumber;
        if (ImGui::IsWindowAppearing())
            ImGui::SetKeyboardFocusHere(-1);
        /// @end Input

        /// @begin Selectable
        ImGui::PushStyleVar(ImGuiStyleVar_SelectableTextAlign, { 1.f, 0 });
        ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
        ImGui::AlignTextToFramePadding();
        ImRad::Selectable("padding", false, ImGuiSelectableFlags_NoAutoClosePopups, { 65, 0 });
        ImGui::PopItemFlag();
        ImGui::PopStyleVar();
        /// @end Selectable

        /// @begin Input
        ImGui::SameLine(0, 2 * ImGui::GetStyle().ItemSpacing.x);
        ImGui::SetNextItemWidth(100);
        ImGui::InputInt("##padding", &padding, 1);
        if (ImGui::IsItemActive())
            ImRad::GetUserData().imeType = ImRad::ImeNumber;
        /// @end Input

        /// @begin Text
        ImRad::Spacing(2);
        ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyle().Colors[ImGuiCol_TextDisabled]);
        ImGui::PushTextWrapPos(0);
        ImGui::TextUnformatted(ImRad::Format("{} items will be aligned", selected.size()).c_str());
        ImGui::PopTextWrapPos();
        ImGui::PopStyleColor();
        /// @end Text

        /// @begin Button
        ImRad::Spacing(2);
        ImGui::BeginDisabled(selected.empty()||alignment<0);
        if (ImGui::Button("OK", { 100, 30 }))
        {
            Work();
            ClosePopup(ImRad::Ok);
        }
        ImGui::EndDisabled();
        /// @end Button

        /// @begin Button
        ImGui::SameLine(0, 2 * ImGui::GetStyle().ItemSpacing.x);
        if (ImGui::Button("Cancel", { 100, 30 }) ||
            ImGui::Shortcut(ImGuiKey_Escape))
        {
            ClosePopup(ImRad::Cancel);
        }
        /// @end Button

        /// @separator
        ImGui::EndPopup();
    }
    ImGui::PopStyleVar();
    ImGui::PopStyleVar();
    /// @end TopWindow
}

void HorizLayout::OnAlignment()
{
    if (ImGui::GetItemID() == ImGui::GetID(ICON_FA_ALIGN_LEFT))
        alignment = 0;
    else if (ImGui::GetItemID() == ImGui::GetID(ICON_FA_ALIGN_CENTER))
        alignment = 1;
    else if (ImGui::GetItemID() == ImGui::GetID(ICON_FA_ALIGN_RIGHT))
        alignment = 2;
    else if (ImGui::GetItemID() == ImGui::GetID(ICON_FA_ALIGN_JUSTIFY))
        alignment = 3;
    else if (ImGui::GetItemID() == ImGui::GetID(ICON_FA_GRIP))
        alignment = 4;
}

void HorizLayout::ExpandSelection(std::vector<UINode*>& selected, UINode* root)
{
    if (selected.empty())
        return;
    selected.resize(1);
    auto* table = dynamic_cast<Table*>(selected[0]);
    bool existingLayout = table && !table->header && !(table->flags & ImGuiTableFlags_Borders);
    if (existingLayout) { //layout table was selected
        if (table->children.empty()) {
            selected.clear();
            return;
        }
        selected[0] = table->children[0].get();
        return ExpandSelection(selected, root);
    }
    auto pos = root->FindChild(selected[0]);
    if (!pos) {
        selected.clear();
        return;
    }
    auto* parent = pos->first;
    table = dynamic_cast<Table*>(parent);
    existingLayout = table && !table->header && !(table->flags & ImGuiTableFlags_Borders);
    for (size_t i = pos->second; i >= 1; --i) {
        const auto& pch = parent->children[i - 1];
        const auto& ch = parent->children[i];
        if (!(ch->Behavior() & UINode::SnapSides) ||
            !(pch->Behavior() & UINode::SnapSides))
            break;
        if (!existingLayout &&
            (!ch->sameLine || ch->nextColumn))
            break;
        selected.insert(selected.begin(), pch.get());
    }
    for (size_t i = pos->second + 1; i < parent->children.size(); ++i) {
        const auto& ch = parent->children[i];
        if (!(ch->Behavior() & UINode::SnapSides))
            break;
        if (!existingLayout &&
            (!ch->sameLine || ch->nextColumn))
            break;
        selected.push_back(ch.get());
    }
}

void HorizLayout::Work()
{
    if (selected.empty() || alignment < 0)
        return;
    auto pos = root->FindChild(selected[0]);
    auto* parent = pos->first;
    auto* table = dynamic_cast<Table*>(parent);
    bool existingLayout = table && !table->header && !(table->flags & ImGuiTableFlags_Borders);
    float realPadding = padding * ctx->style.ItemSpacing.x;
    float realSpacing = spacing * ctx->style.ItemSpacing.x;

    if (alignment == 0) //left alignment
    {
        //remove table
        if (existingLayout)
        {
            pos = root->FindChild(table);
            parent = pos->first;
            int idx = pos->second;
            for (size_t i = 0; i < selected.size(); ++i)
            {
                auto* item = dynamic_cast<Widget*>(selected[i]);
                item->spacing = i ? spacing : (int)table->spacing;
                item->indent = !i ? padding : 0; //hack

                //reparent items
                for (auto it = table->children.begin(); it != table->children.end(); ++it)
                    if (it->get() == item) {
                        it->release();
                        table->children.erase(it);
                        break;
                    }

                item->sameLine = i ? true : false;
                item->nextColumn = false;
                parent->children.insert(parent->children.begin() + idx, std::unique_ptr<Widget>(item));
                ++idx;
            }
            assert(parent->children[idx].get() == table);
            parent->children.erase(parent->children.begin() + idx);
        }
        else
        {
            for (size_t i = 0; i < selected.size(); ++i)
            {
                auto* item = dynamic_cast<Widget*>(selected[i]);
                item->spacing = i ? spacing : (int)item->spacing;
                item->indent = !i ? padding : 0; //hack
            }
        }
    }
    else
    {
        int idx = pos->second;
        //create table
        if (!existingLayout)
        {
            auto tab = std::make_unique<Table>(*ctx);
            auto* item = dynamic_cast<Widget*>(selected[0]);
            tab->sameLine = false;
            tab->spacing = item->spacing;
            table = tab.get();
            parent->children.insert(parent->children.begin() + idx, std::move(tab));
            ++idx;
        }
        table->header = false;
        table->flags = ImGuiTableFlags_NoPadOuterX | ImGuiTableFlags_NoPadInnerX;;
        table->columnData.clear();

        if (padding) //left padding
            table->columnData.push_back({ "left-margin", ImGuiTableColumnFlags_WidthFixed, realPadding });
        if (alignment == 1 || alignment == 2) //center, right
            table->columnData.push_back({ "left-stretch", ImGuiTableColumnFlags_WidthStretch });

        for (size_t i = 0; i < selected.size(); ++i)
        {
            //reparent items
            auto* item = dynamic_cast<Widget*>(selected[i]);
            if (!existingLayout)
            {
                for (auto it = parent->children.begin(); it != parent->children.end(); ++it)
                    if (it->get() == item) {
                        it->release();
                        parent->children.erase(it);
                        break;
                    }
                table->children.push_back(std::unique_ptr<Widget>(item));
            }
            item->indent = 0;
            if (alignment == 1 || alignment == 2) //center, right
            {
                if (!i)
                    table->columnData.push_back({ "content", ImGuiTableColumnFlags_WidthFixed, 0 });
                item->nextColumn = !i ? (int)table->columnData.size() - 1 : 0;
                item->sameLine = !i ? false : true;
                item->spacing = i ? spacing : 0;
            }
            else if (alignment == 3) //left&right
            {
                if (!i)
                    table->columnData.push_back({ "left-content", ImGuiTableColumnFlags_WidthStretch });
                else if (i == selected.size() - 1)
                    table->columnData.push_back({ "right-content", ImGuiTableColumnFlags_WidthFixed, 0 });

                item->nextColumn = !i ? (int)table->columnData.size() - 1 : i == selected.size() - 1 ? 1 : 0;
                item->sameLine = !i ? false : true;
                item->spacing = i ? spacing : 0;
            }
            else if (alignment == 4) //grid
            {
                if (i && spacing)
                    table->columnData.push_back({ "spacing" + std::to_string(i), ImGuiTableColumnFlags_WidthFixed, realSpacing });
                table->columnData.push_back({ "item" + std::to_string(i + 1), ImGuiTableColumnFlags_WidthStretch });
                item->sameLine = false;
                item->nextColumn = !i ? (int)table->columnData.size() - 1 : spacing ? 2 : 1;
                item->spacing = 0;
            }
        }

        if (alignment == 1) //center
            table->columnData.push_back({ "right-stretch", ImGuiTableColumnFlags_WidthStretch });
        if (padding) //right padding
            table->columnData.push_back({ "right-margin", ImGuiTableColumnFlags_WidthFixed, realPadding });
    }
}

void HorizLayout::Init()
{
    alignment = -1; //force user to choose
    ExpandSelection(selected, root);
}
