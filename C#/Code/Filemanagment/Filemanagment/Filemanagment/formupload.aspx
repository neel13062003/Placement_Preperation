<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="formupload.aspx.cs" Inherits="Filemanagment.formupload" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
        </div>
        <asp:FileUpload ID="FileUpload1" runat="server" />
       
        <br />
        <asp:Button ID="Button4" runat="server" Text="Upload File" OnClick="Button4_Click" />
      <asp:Label ID="Label3" runat="server" Text=""></asp:Label>
        <br />
        <p>
            <asp:Button ID="Button1" runat="server" Text="Get All Files" OnClick="Button1_Click" />
            <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
           
        </p>
        <p>
            <asp:Button ID="Button3" runat="server" Text="Get File Details" OnClick="Button3_Click" />
            <br />
            <asp:Label ID="Label2" runat="server" Text=""></asp:Label>
        </p>
    </form>
</body>
</html>
