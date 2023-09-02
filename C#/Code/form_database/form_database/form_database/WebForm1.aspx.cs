using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;
using System.Diagnostics.Contracts;

namespace form_database
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        SqlConnection conn=new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|stu.mdf;Integrated Security=True");
        protected void Page_Load(object sender, EventArgs e)
        {
            if(conn.State==ConnectionState.Open)
            {
                conn.Close();
            }
            conn.Open();
           // disp_data();
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            SqlCommand cmd = conn.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "insert into student values('"+firstname.Text+"','"+lastname.Text+"','"+city.Text+"')";
            cmd.ExecuteNonQuery();

            firstname.Text = "";
            lastname.Text = "";
            city.Text = "";
           // disp_data();

        }

        public void  disp_data()
        {
            SqlCommand cmd = conn.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from student";
            cmd.ExecuteNonQuery();
            DataTable dt = new DataTable();
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            da.Fill(dt);
            Gridview1.DataSource = dt;
            Gridview1.DataBind();
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            SqlCommand cmd = conn.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "delete from student where firstname='"+firstname.Text+"'";
            cmd.ExecuteNonQuery();
            firstname.Text = "";
           // disp_data() ;
        }

        protected void Button3_Click(object sender, EventArgs e)
        {
            SqlCommand cmd = conn.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "update student set firstname='"+firstname.Text+"' , lastname='"+lastname.Text+"',city='"+city.Text+"' where id ='" + Convert.ToInt32(oldid.Text) + "'";
            cmd.ExecuteNonQuery();
            firstname.Text = "";
            lastname.Text = "";
            city.Text = "";
            oldid.Text = "";
           // disp_data();
        }

        protected void Button4_Click(object sender, EventArgs e)
        {
            disp_data();
        }
    }
}