using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using WebApplication1;

namespace WebApplication20
{
    public partial class WebForm4 : System.Web.UI.Page
    {
       protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                BindGridView();
            }
        }

        private void BindGridView()
        {
            
            StudentDAL studentDAL = new StudentDAL();
            List<Student> students = studentDAL.GetStudents();
            GridView1.DataSource = students;
            GridView1.DataBind();
        }
    }
}