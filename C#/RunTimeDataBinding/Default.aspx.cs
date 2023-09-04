using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;
using System.Configuration;

public partial class Default3 : System.Web.UI.Page
{
    string c = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;
    //SqlConnection con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\Database.mdf;Integrated Security=True");
    SqlConnection con = new SqlConnection();
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
    {
        con.ConnectionString = c;
        string s = DropDownList1.SelectedValue;
        con.Open();
        string q = "select sem from stud where Id=@sid";
        SqlParameter p1 = new SqlParameter("@sid", s);
        SqlCommand cmd = new SqlCommand(q, con);
        cmd.Parameters.Add(p1);
        SqlDataReader sdr = cmd.ExecuteReader();
        while (sdr.Read())
        {
            Label1.Text = sdr[0].ToString();
        }
        con.Close();

    }



    protected void GridView1_RowDataBound(object sender, GridViewRowEventArgs e)
    {
        if (e.Row.RowType == DataControlRowType.DataRow)
        {
            //    if (e.Row.Cells[2].Text == "2")
            //    {
            //        e.Row.BackColor = System.Drawing.Color.Aqua;

            //    }
            //}
            if (DataBinder.Eval(e.Row.DataItem, "sem").ToString() == "2")
                e.Row.BackColor = System.Drawing.Color.Aqua;
        }
    }
}