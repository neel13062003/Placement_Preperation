<%@ Page Language="C#" AutoEventWireup="true" CodeFile="statemanagementtechniqueslearn.aspx.cs" Inherits="statemanagementtechniqueslearn" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
        
            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <br />
            <br />
            <br />
            <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Session" />
            <asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="Cookies" />
            <asp:Button ID="Button3" runat="server" OnClick="Button3_Click" Text="Querystring" />
        
        </div>
    </form>
</body>
</html>