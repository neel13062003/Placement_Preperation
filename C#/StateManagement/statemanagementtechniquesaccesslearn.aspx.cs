using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class statemanagementtechniquesaccesslearn : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        Label1.Text = "";
        if (Session["uname"] != null)
        {
            Label1.Text = Session["uname"].ToString();
        }
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        Label1.Text = "";
        if (Request.Cookies["cname"] != null)
        {
            Label1.Text = Request.Cookies["cname"].Value;
        }
    }
    protected void Button3_Click(object sender, EventArgs e)
    {
        Label1.Text = "";
        if (Request.QueryString["name"] != null)
        {
            Label1.Text = Request.QueryString["name"].ToString() + " " + Request.QueryString["name1"].ToString();
        }
    }
}