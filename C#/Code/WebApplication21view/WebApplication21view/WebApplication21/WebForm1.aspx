<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="WebApplication21.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
   <asp:Wizard ID="_infoWizard" runat="server" ActiveStepIndex="0"
            OnFinishButtonClick="_infoWizard_FinishButtonClick"
            DisplaySideBar="true">
    <WizardSteps>
      <asp:WizardStep ID="_step1" runat="server" Title="Name">
      <table>
        <tr>
          <td>First name:</td>
          <td><asp:TextBox ID="_firstNameTextBox" runat="server" /></td>
        </tr>
        <tr>
          <td>Last name:</td>
          <td><asp:TextBox ID="_lastNameTextBox" runat="server" /></td>
        </tr>
      </table>
      </asp:WizardStep>
      <asp:WizardStep ID="_step2" runat="server" Title="Address">
        <table>
          <tr>
            <td>Street:</td>
            <td><asp:TextBox ID="_streetTextBox" runat="server" /></td>
          </tr>
          <tr>
            <td>City:</td>
            <td><asp:TextBox ID="_cityTextBox" runat="server" /></td>
          </tr>
          <tr>
            <td>State/Province:</td>
            <td><asp:TextBox ID="_stateTextBox" runat="server" /></td>
          </tr>
        </table>
      </asp:WizardStep>
      <asp:WizardStep ID="_step3" runat="server" Title="Preferences">
        <table>
          <tr>
            <td>Favorite color:</td>
            <td><asp:TextBox ID="_colorTextBox" runat="server" /></td>
          </tr>
          <tr>
            <td>Favorite number:</td>
            <td><asp:TextBox ID="_numberTextBox" runat="server" /></td>
          </tr>
        </table>
      </asp:WizardStep>
    </WizardSteps>
</asp:Wizard>
<asp:Label ID="_summaryLabel" runat="server" />
        </div>
    </form>
</body>
</html>
