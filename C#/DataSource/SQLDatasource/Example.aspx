<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="example.aspx.cs" Inherits="YourNamespace.example" %>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>SqlDataSource Example</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>SqlDataSource Example</h1>
            <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
                ConnectionString="YourConnectionString" 
                SelectCommand="SELECT ID, Name, Description FROM YourTableName">
            </asp:SqlDataSource>

            <asp:GridView ID="GridView1" runat="server" DataSourceID="SqlDataSource1" AutoGenerateColumns="true">
            </asp:GridView>
        </div>
    </form>
</body>
</html>
