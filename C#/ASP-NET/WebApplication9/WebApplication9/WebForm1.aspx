<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="WebApplication9.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
     <form id="form1" runat="server">
        <div>
            <asp:Label ID="Label1" runat="server" Text="Label">Name</asp:Label>
            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>    
            <hr style="width:50%;text-align:left;margin-left:0"/>
        
            <asp:Label ID="Label2" runat="server" Text="Label">Password</asp:Label>
            <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>    

             <asp:Label ID="Label3" runat="server" Text="Label">Confirm Password</asp:Label>
            <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>    

        <asp:DropDownList ID="DropDownList1" runat="server">
            <asp:ListItem ID="L1" runat="server">India</asp:ListItem> 
            <asp:ListItem ID="L2" runat="server">Pakistan</asp:ListItem> 
            <asp:ListItem ID="L3" runat="server">China</asp:ListItem> 
        </asp:DropDownList>
       
         <asp:Label ID="Label4" runat="server" Text="Label">Contact No</asp:Label>
            <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>    
          
        
             <asp:Label ID="Label5" runat="server" Text="Label">Batch</asp:Label>
            <asp:TextBox ID="TextBox5" runat="server"></asp:TextBox>    
           

        

        <asp:Button ID="Button1" runat="server" Text="Button"  name="Submit" OnClick="Details"/>


        </div>
        <hr style="width:50%;text-align:left;margin-left:0"/>
        <br/>
        <div>

            <asp:Label ID="LabelResult" runat="server" ></asp:Label>
            <hr style="width:50%;text-align:left;margin-left:0"/>
            
        </div>
        <div>
            <asp:Label ID="LabelName1" runat="server" ></asp:Label>
        </div>
      
    </form>
</body>
</html>
