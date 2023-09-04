<%@ Page Language="C#" EnableSessionState="ReadOnly" AutoEventWireup="true" CodeFile="welcome.aspx.cs" Inherits="welcome" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .auto-style1 {
            position: absolute;
            top: 104px;
            left: 43px;
            z-index: 1;
        }
        .auto-style2 {
            position: absolute;
            top: 106px;
            left: 184px;
            z-index: 1;
            margin-top: 0px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    Welcome : <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>
    </div>

        <asp:Button ID="Button1" runat="server" CssClass="auto-style1" Text="Edit Profile" OnClick="Button1_Click" />
        <asp:Button ID="Button2" runat="server" CssClass="auto-style2" Text="Logout" OnClick="Button2_Click" />

    </form>
</body>
</html>