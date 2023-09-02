<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="WebApplication1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Enter N1: &nbsp;<asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
&nbsp;N2:
            <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
        </div>
        <p>
            <asp:Button oncommand="Calculate" runat="server" Text="+" Width="48px" ID="Button2" CommandArgument="+" CommandName="Add" OnClick="Click"/>
            <asp:Button oncommand="Calculate" runat="server" Text="-" Width="48px" ID="Button3" style="margin-left: 19px" CommandArgument="-" CommandName="Sub"/>
            <asp:Button oncommand="Calculate" runat="server" Text="*" Width="48px" ID="Button4" style="margin-left: 19px" CommandArgument="*" CommandName="Mul"/>
            <asp:Button oncommand="Calculate" runat="server" Text="/" Width="48px" ID="Button5" style="margin-left: 19px" CommandArgument="/" CommandName="Div"/>
        </p>
        <p>
            Res. No. :&nbsp; 
            <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
        </p>
    </form>
</body>
</html>
