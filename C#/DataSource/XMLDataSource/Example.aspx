<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="example.aspx.cs" Inherits="YourNamespace.example" %>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>XmlDataSource Example</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>XmlDataSource Example</h1>
            <asp:XmlDataSource ID="XmlDataSource1" runat="server" DataFile="example.xml" XPath="~/"></asp:XmlDataSource>

            <asp:GridView ID="GridView1" runat="server" DataSourceID="XmlDataSource1" AutoGenerateColumns="true">
            </asp:GridView>
        </div>
    </form>
</body>
</html>
