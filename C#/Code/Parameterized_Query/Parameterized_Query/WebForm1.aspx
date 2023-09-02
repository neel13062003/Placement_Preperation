<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Parameterized_Query.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            ID:&nbsp<asp:TextBox ID="txtId" runat="server" /><br />
            First Name:&nbsp<asp:TextBox ID="txtFirstName" runat="server" /><br />
            Last Name:&nbsp<asp:TextBox ID="txtLastName" runat="server" /><br />
            Phone:&nbsp<asp:TextBox ID="txtPhone" runat="server" /><br />
            City:&nbsp<asp:TextBox ID="txtCity" runat="server" /><br />
            College:&nbsp<asp:TextBox ID="txtCollege" runat="server" /><br />
            <asp:Button ID="btnSave" runat="server" Text="Save" OnClick="btnSave_Click" /><br />
            <asp:Label ID="lblErrorMessage" Text="" runat="server" /><br />
            <asp:GridView ID="gvStudents" runat="server" AutoGenerateColumns="true" />
        </div>
    </form>
</body>
</html>
