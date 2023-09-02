<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="WebApplication8.WebForm1" %>

<
<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="Label1" runat="server" Text="Label">StudentName</asp:Label>
            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>    
            <hr style="width:50%;text-align:left;margin-left:0"/>
       
        <asp:RadioButtonList ID="RadioButtonList1" runat="server">
            <asp:ListItem ID="M" runat="server">Male</asp:ListItem> 
            <asp:ListItem ID="F" runat="server">Female</asp:ListItem> 
        </asp:RadioButtonList>
        

        <asp:DropDownList ID="DropDownList1" runat="server">
            <asp:ListItem ID="L1" runat="server">1</asp:ListItem> 
            <asp:ListItem ID="L2" runat="server">2</asp:ListItem> 
            <asp:ListItem ID="L3" runat="server">3</asp:ListItem> 
            <asp:ListItem ID="L4" runat="server">4</asp:ListItem> 
            <asp:ListItem ID="L5" runat="server">5</asp:ListItem> 
            <asp:ListItem ID="L6" runat="server">6</asp:ListItem> 
            <asp:ListItem ID="L7" runat="server">7</asp:ListItem> 
            <asp:ListItem ID="L8" runat="server">8</asp:ListItem> 
        </asp:DropDownList>
       
        
        <asp:CheckBoxList ID="CheckBoxList1" runat="server">
            <asp:ListItem ID="ListItem1" runat="server">DAA</asp:ListItem> 
            <asp:ListItem ID="ListItem2" runat="server">DAIE</asp:ListItem> 
            <asp:ListItem ID="ListItem3" runat="server">CRYPTO</asp:ListItem> 
        </asp:CheckBoxList>
           

        <asp:RadioButtonList ID="RadioButtonList2" runat="server">
            <asp:ListItem ID="ListItem11" runat="server">Good</asp:ListItem> 
            <asp:ListItem ID="ListItem12" runat="server">Excellent</asp:ListItem> 
            <asp:ListItem ID="ListItem13" runat="server">Average</asp:ListItem> 
        </asp:RadioButtonList>

        <asp:Button ID="Button1" runat="server" Text="Button"  name="Submit" OnClick="Details"/>


        </div>
        <hr style="width:50%;text-align:left;margin-left:0"/>
       
        <div>

            <asp:Label ID="LabelResult" runat="server" ></asp:Label>
            <hr style="width:50%;text-align:left;margin-left:0"/>
            
        </div>
        <div>
            <asp:Label ID="LabelName" runat="server" ></asp:Label>
            <asp:Label ID="LabelGender" runat="server" ></asp:Label>
            <asp:Label ID="LabelDrop" runat="server" ></asp:Label>
            <asp:Label ID="LabelSub" runat="server" ></asp:Label>
            <asp:Label ID="LabelSurvey" runat="server" ></asp:Label>
        </div>
        
       
    </form>
</body>
</html>
