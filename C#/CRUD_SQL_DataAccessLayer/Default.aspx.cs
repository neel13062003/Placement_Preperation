using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;

public partial class _Default : System.Web.UI.Page
{
    SqlConnection con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\Database.mdf;Integrated Security=True");
    protected void Page_Load(object sender, EventArgs e)
    {
        if (con.State == ConnectionState.Open)
            con.Close();
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        
        con.Open();
        //Response.Write("conn done");
        string q = "select * from Stud";
        SqlCommand cmd = new SqlCommand(q,con);
        
        DataTable dt = new DataTable();
        SqlDataAdapter sda = new SqlDataAdapter(cmd);
        sda.Fill(dt);

        GridView1.DataSource = dt;
        GridView1.DataBind();
        con.Close();
        

        //If Take SqlData Reader then traverse Loop else SqlData Adapter Takes Directly
        /*if (con.State == ConnectionState.Closed)
            con.Open();

        string query = "select * from Stud";
        SqlCommand cmd = new SqlCommand(query, con);
        SqlDataReader reader = cmd.ExecuteReader();

        if (reader.HasRows)
        {
            DataTable dt = new DataTable();
            dt.Load(reader);
            GridView1.DataSource = dt;
            GridView1.DataBind();
            reader.Close();
        }
        else Response.Write("No data found.");
        con.Close();*/
    }

    protected void Button2_Click(object sender, EventArgs e)
    {
        con.Open();
        string q = "insert into Stud values('"+TextBox1.Text+"','"+TextBox2.Text+"','"+TextBox3.Text+"')";
        SqlCommand cmd = new SqlCommand(q, con);
        int n = cmd.ExecuteNonQuery();
        if (n > 0)
            Response.Write("Data Inserted");
        else
            Response.Write("Error");
        con.Close();
            
    }
    protected void Button3_Click(object sender, EventArgs e)
    {
        con.Open();
        string q = "update Stud set Name = '"+TextBox2.Text+"',Sem='"+TextBox3.Text+"' where Id='"+TextBox1.Text+"'";
        SqlCommand cmd = new SqlCommand(q, con);
        int n = cmd.ExecuteNonQuery();
        if (n > 0)
            Response.Write("Data Updated");
        else
            Response.Write("Error");
        con.Close();
    }
    protected void Button4_Click(object sender, EventArgs e)
    {
        con.Open();
        string q = "delete from Stud where Id='" + TextBox1.Text + "'";
        SqlCommand cmd = new SqlCommand(q, con);
        int n = cmd.ExecuteNonQuery();
        if (n > 0)
            Response.Write("Data Deleted");
        else
            Response.Write("Error");
        con.Close();
    }

}
