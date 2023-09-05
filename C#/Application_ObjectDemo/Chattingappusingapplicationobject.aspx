<%@ Page Language="C#"  AutoEventWireup="true" CodeFile="Chattingappusingapplicationobject.aspx.cs" Inherits="Chattingappusingapplicationobject" %>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
     <title>Chatting  app using application object</title>
</head>
<body>
    <form id="form1" runat="server">
        <asp:TextBox ID="TextBox1" runat="server" Height="162px" TextMode="MultiLine" Width="377px"></asp:TextBox>
        
        <asp:TextBox ID="TextBox2" runat="server" Width="294px"></asp:TextBox>
        <asp:TextBox ID="TextBox3" runat="server" Width="294px"></asp:TextBox>


        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Send" />
        <asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="retrieve" />
    </form>
</body>
</html>