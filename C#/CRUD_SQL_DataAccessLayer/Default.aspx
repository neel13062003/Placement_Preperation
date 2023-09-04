<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 435px;
            height: 171px;
            position: absolute;
            top: 282px;
            left: 14px;
            z-index: 1;
        }
        </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:Table ID="Table1" runat="server" Height="233px" Width="576px">
            <asp:TableRow>
                <asp:TableCell>Enter Id : </asp:TableCell>
                <asp:TableCell><asp:TextBox ID="TextBox1" runat="server"></asp:TextBox></asp:TableCell>
            </asp:TableRow>
             <asp:TableRow>
                <asp:TableCell>Enter Name:</asp:TableCell>
                <asp:TableCell><asp:TextBox ID="TextBox2" runat="server"></asp:TextBox></asp:TableCell>
            </asp:TableRow>
             <asp:TableRow>
                <asp:TableCell>Enter Sem :</asp:TableCell>
                <asp:TableCell><asp:TextBox ID="TextBox3" runat="server"></asp:TextBox></asp:TableCell>
            </asp:TableRow>
            <asp:TableRow>
                <asp:TableCell RowSpan="2">
                   <asp:Button ID="Button1" runat="server" Text="Display" OnClick="Button1_Click" />
                   <asp:Button ID="Button2" runat="server" Text="Insert" OnClick="Button2_Click"  />
                   <asp:Button ID="Button3" runat="server" Text="Update" OnClick="Button3_Click" />
                   <asp:Button ID="Button4" runat="server" Text="Delete" OnClick="Button4_Click" />
                </asp:TableCell>
            </asp:TableRow>
        </asp:Table>
    </div>
        <asp:GridView ID="GridView1" runat="server" CssClass="auto-style1">
        </asp:GridView>
    </form>
</body>
</html>