using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;

namespace WebApplication20
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        SqlConnection conn = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=C:\Users\user1\source\repos\WebApplication20\WebApplication20\App_Data\Database1.mdf;Integrated Security=True");

        protected void Page_Load(object sender, EventArgs e)
        {

            if (conn.State == ConnectionState.Open)
            {
                conn.Close();
            }
            conn.Open();

            if (Session["ID"] != null)
            {
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string username = TextBox1.Text.Trim();
            string pass = TextBox2.Text.Trim();

            string query = "SELECT COUNT(*) FROM student where id=@username and pass=@pass";

            SqlCommand command = new SqlCommand(query, conn);
            command.Parameters.AddWithValue("@username", username);
            command.Parameters.AddWithValue("@pass", pass);

            int count =(int)command.ExecuteScalar();

            if(count>0)
            {
                Session["ID"] = username;
                Response.Redirect("WebForm3.aspx");
            }
            else
            {
                Label1.Text = "Invalid details !!";
            }

    
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            Response.Redirect("WebForm2.aspx");
        }
    }
}