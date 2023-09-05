using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Chattingappusingapplicationobject : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        Application.Lock();
        string usermsg = TextBox2.Text + " : " + TextBox3.Text;
        Application["msg"] = Application["msg"].ToString() + usermsg;
        Application.UnLock();
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        Application.Lock();
        TextBox1.Text = Application["msg"].ToString();
        Application.UnLock();
    }
}