<%@ Page Language="C#" AutoEventWireup="true" CodeFile="wizardcontrollearn.aspx.cs" Inherits="wizardcontrollearn" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:Wizard ID="Wizard1" runat="server" ActiveStepIndex="3" Height="379px" Width="811px" DisplayCancelButton="True" OnCancelButtonClick="Wizard1_CancelButtonClick" OnFinishButtonClick="Wizard1_FinishButtonClick" OnNextButtonClick="Wizard1_NextButtonClick">
            <FinishNavigationTemplate>
                <asp:Button ID="FinishPreviousButton" runat="server" CausesValidation="False" CommandName="MovePrevious" Text="Previous" />
                <asp:Button ID="FinishButton" runat="server" CommandName="MoveComplete" Text="Finish" />
                <asp:Button ID="CancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="Cancel" />
            </FinishNavigationTemplate>
            <WizardSteps>
                <asp:WizardStep ID="WizardStep1" runat="server" Title="Select Mobile phone" StepType="Start">



                    <asp:DropDownList ID="DropDownList1" runat="server">
                        <asp:ListItem>Select Mobile phone</asp:ListItem>
                        <asp:ListItem>Nokia X3</asp:ListItem>
                        <asp:ListItem>Samsung X22</asp:ListItem>
                        <asp:ListItem>Note 12 pro</asp:ListItem>
                    </asp:DropDownList>



                </asp:WizardStep>
                <asp:WizardStep ID="WizardStep2" runat="server" Title="Enter Delivery information" StepType="Step">Enter your name&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                    <br />
                    <br />
                    Enter your addresss<asp:TextBox ID="TextBox2" runat="server" Height="43px" TextMode="MultiLine"></asp:TextBox>
                    <br />
                    <br />
                    <br />
                    enter mobile
                    <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
                    <br />
                    you have selected
                    <asp:Label ID="Lblmobileselected" runat="server" Text="Label"></asp:Label>
                </asp:WizardStep>
                <asp:WizardStep runat="server" StepType="Step" Title="Enter payment information">
                    <br />
                    Enter card no
                    <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
                    <asp:Label ID="Lblpaymentmobile" runat="server" Text="Label"></asp:Label>
                    <asp:RadioButtonList ID="RadioButtonList1" runat="server">
                        <asp:ListItem>VISA</asp:ListItem>
                        <asp:ListItem>Master card</asp:ListItem>
                    </asp:RadioButtonList>
                </asp:WizardStep>
                <asp:WizardStep runat="server" StepType="Finish" Title="Final information">
                    <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>
                    <br />
                    <asp:Label ID="Label2" runat="server" Text="Label"></asp:Label>
                    <br />
                    <asp:Label ID="Label4" runat="server" Text="Label"></asp:Label>
                </asp:WizardStep>
            </WizardSteps>
        </asp:Wizard>
    </div>
    </form>
</body>
</html>