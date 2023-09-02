<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm3.aspx.cs" Inherits="WebApplication20.WebForm3" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>You are successfully login !!&nbsp;
                <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Logout" />
            </h1>
        </div>
        <div>
            <div>
                <h2>GridView</h2>
                 <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|Database1.mdf;Integrated Security=True"
                    SelectCommand="SELECT * FROM [Student]"></asp:SqlDataSource>
                <asp:GridView ID="GridView1" runat="server" DataSourceID="SqlDataSource1"></asp:GridView>
               <br />
                <h2>DetailsView</h2>
                <asp:DetailsView ID="DetailsView1" runat="server" DataSourceID="SqlDataSource1"></asp:DetailsView>

                <h2>FormView</h2>
                <asp:FormView ID="FormView1" runat="server"  DataSourceID="SqlDataSource1" DefaultMode="Edit">
    <ItemTemplate>
        <div>
            <h2>Student Details</h2>
            <p><strong>ID:</strong> <%# Eval("ID") %></p>
            <p><strong>Name:</strong> <%# Eval("Name") %></p>
            <p><strong>Branch:</strong> <%# Eval("Branch") %></p>
            <p><strong>Sem:</strong> <%# Eval("Sem") %></p>
            <p><strong>Password:</strong> <%# Eval("Pass") %></p>
        </div>
    </ItemTemplate>
    <EditItemTemplate>
        <div>
            <p><strong>ID:</strong> <%# Eval("ID") %></p>
            <p><strong>Name:</strong> <asp:TextBox ID="txtName" runat="server" Text='<%# Bind("Name") %>'></asp:TextBox></p>
            <p><strong>Branch:</strong> <asp:TextBox ID="txtBranch" runat="server" Text='<%# Bind("Branch") %>'></asp:TextBox></p>
            <p><strong>Sem:</strong> <asp:TextBox ID="txtSem" runat="server" Text='<%# Bind("Sem") %>'></asp:TextBox></p>
            <p><strong>Password:</strong> <asp:TextBox ID="txtPassword" runat="server" Text='<%# Bind("Pass") %>'></asp:TextBox></p>
            <asp:Button ID="btnUpdate" runat="server" Text="Update" CommandName="Update" />
            <asp:Button ID="btnCancel" runat="server" Text="Cancel" CommandName="Cancel" />
        </div>
    </EditItemTemplate>
</asp:FormView>
            </div>
        </div>
    </form>
</body>
</html>

