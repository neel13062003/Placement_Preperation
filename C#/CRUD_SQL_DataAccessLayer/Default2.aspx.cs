using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;
using System.Configuration;


public partial class Default2 : System.Web.UI.Page
{
    string s = ConfigurationManager.ConnectionStrings["mycon"].ConnectionString;
    SqlConnection con = new SqlConnection();
    
    protected void Page_Load(object sender, EventArgs e)
    {
        
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        con.ConnectionString = s;
        con.Open();
        //Response.Write("con done");
        string q = "select count(*) from login where Unm = @un and Pwd = @pw";
        SqlCommand cmd = new SqlCommand(q, con);
        
        SqlParameter p1 = new SqlParameter("@un", TextBox1.Text);
        SqlParameter p2 = new SqlParameter("@pw", TextBox2.Text);
        cmd.Parameters.Add(p1);
        cmd.Parameters.Add(p2);

        object i = cmd.ExecuteScalar();
        Response.Write(Convert.ToInt16(i));
        //DataTable dt = new DataTable();
        //SqlDataAdapter sda = new SqlDataAdapter(cmd);
        //sda.Fill(dt);
        if (Convert.ToInt16(i) > 0)
        {
            Session["user"] = TextBox1.Text;
            Response.Redirect("welcome.aspx");
        }
        else
        {
            Response.Write("Invalid credentials");
        }
        con.Close();
  
    }
}