using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class welcome : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["user"] != null)
        {
            Label1.Text = Session["user"].ToString();
        }
        else {
            Label1.Text = "session expired";
        }

    }



    protected void Button1_Click(object sender, EventArgs e)
    {
        if (Session["user"] != null)
        {
            Server.Transfer("Default.aspx");
        }
    }

    protected void Button2_Click(object sender, EventArgs e)
    {
        Session.Remove("user");
        Response.Redirect("Default2.aspx");
    }
}