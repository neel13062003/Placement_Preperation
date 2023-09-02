<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="form_database.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <table>
                <tr>
                    <td>FirstName</td>
                    <td><asp:TextBox ID="firstname" runat="server"></asp:TextBox></td>
                </tr>
                 <tr>
                    <td>LastName</td>
                    <td><asp:TextBox ID="lastname" runat="server"></asp:TextBox></td>
                </tr>
                 <tr>
                    <td>City</td>
                    <td><asp:TextBox ID="city" runat="server"></asp:TextBox></td>
                </tr>
                <tr>
                    <td colspan="2" align="center">

                        <asp:Button ID="Button1" runat="server" Text="Insert" OnClick="Button1_Click" />
                        <asp:Button ID="Button2" runat="server" Text="Delete" OnClick="Button2_Click" />
                        <asp:Button ID="Button3" runat="server" Text="Update" OnClick="Button3_Click" />
                        <asp:Button ID="Button4" runat="server" Text="view" OnClick="Button4_Click" />

                    </td>
                </tr>
                <tr>
                    <td>Enter Id for update data :</td>
                    <td><asp:TextBox ID="oldid" runat="server"></asp:TextBox></td>
                </tr>

            </table>
            <br />
            <br />
            <asp:GridView ID="Gridview1" runat="server"></asp:GridView>
        </div>
    </form>
</body>
</html>
