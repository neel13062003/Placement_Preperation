<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm2.aspx.cs" Inherits="WebApplication21.WebForm2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>

              
        <asp:MultiView ID="_infoMultiView" runat="server"
                       ActiveViewIndex="0">
            <asp:View ID="_view1" runat="server">
             <table>
                <tr>
                  <td>First name:</td>
                  <td><asp:TextBox ID="_firstNameTextBox"
                                   runat="server" /></td>
                </tr>
                <tr>
                  <td>Last name:</td>
                  <td><asp:TextBox ID="_lastNameTextBox"
                                   runat="server" /></td>
                </tr>
              </table>

            </asp:View>
            <asp:View ID="_view2" runat="server">
                <table>
                  <tr>
                    <td>Street:</td>
                    <td><asp:TextBox ID="_streetTextBox"
                                     runat="server" /></td>
                  </tr>
                  <tr>
                    <td>City:</td>
                    <td><asp:TextBox ID="_cityTextBox"
                                     runat="server" /></td>
                  </tr>
                  <tr>
                    <td>State/Province:</td>
                    <td><asp:TextBox ID="_stateTextBox"
                                     runat="server" /></td>
                  </tr>
                </table>
            </asp:View>
            <asp:View ID="_view3" runat="server">
                <table>
                  <tr>
                    <td>Favorite color:</td>
                    <td><asp:TextBox ID="_colorTextBox"
                                     runat="server" /></td>
                  </tr>
                  <tr>
                    <td>Favorite number:</td>
                    <td><asp:TextBox ID="_numberTextBox"
                                     runat="server" />
                        <asp:Button ID="Button1" OnClick="BTN1_click" runat="server" Text="Submit" />
                      </td>
                  </tr>
                </table>
            </asp:View>
        </asp:MultiView>
            <asp:Button ID="btnPrevious" runat="server" Text="Previous" OnClick="btnPrevious_Click" />
            <asp:Button ID="btnNext" runat="server" Text="Next" OnClick="btnNext_Click" />
            <asp:Label ID="_summaryLabel" runat="server" />
        </div>
    </form>
</body>
</html>
