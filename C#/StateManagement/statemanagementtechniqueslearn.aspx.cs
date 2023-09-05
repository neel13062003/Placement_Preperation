using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class statemanagementtechniqueslearn : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        Session.Add("uname", TextBox1.Text);
        Server.Transfer("statemanagementtechniquesaccesslearn.aspx");


    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        HttpCookie cookies = new HttpCookie("cname", TextBox1.Text);
        Response.Cookies.Add(cookies);
    }
    protected void Button3_Click(object sender, EventArgs e)
    {
        Response.Redirect("statemanagementtechniquesaccesslearn.aspx?name=" + TextBox1.Text+"&name1="+TextBox1.Text);
    }
}