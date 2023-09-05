<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="example.aspx.cs" Inherits="YourNamespace.example" %>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>ObjectDataSource Example</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>ObjectDataSource Example</h1>
            <asp:ObjectDataSource ID="ObjectDataSource1" runat="server" TypeName="YourNamespace.DataSourceClass"
                SelectMethod="GetData" DataObjectTypeName="YourNamespace.DataObject">
            </asp:ObjectDataSource>

            <asp:GridView ID="GridView1" runat="server" DataSourceID="ObjectDataSource1" AutoGenerateColumns="true">
            </asp:GridView>
        </div>
    </form>
</body>
</html>
