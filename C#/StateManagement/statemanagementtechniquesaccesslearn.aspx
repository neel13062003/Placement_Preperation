<%@ Page Language="C#" AutoEventWireup="true" CodeFile="statemanagementtechniquesaccesslearn.aspx.cs" Inherits="statemanagementtechniquesaccesslearn" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="session" />
        <asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="cookies" />
        <asp:Button ID="Button3" runat="server" OnClick="Button3_Click" Text="querystring" />
        <br />
        <br />
        <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>
        <br />
    
    </div>
    </form>
</body>
</html>