<%@ Page Language="C#" EnableSessionState="True" AutoEventWireup="true" CodeFile="Default2.aspx.cs" Inherits="Default2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .auto-style1 {
            position: absolute;
            top: 147px;
            left: 112px;
            z-index: 1;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h2>Enter Username : <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox></h2>
            <h2>Enter Password : <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox></h2>
        </div>
        <p>
        <asp:Button ID="Button1" runat="server" Text="Login" OnClick="Button1_Click" CssClass="auto-style1" 
        Width="153px" />
        </p>
    </form>
</body>
</html>