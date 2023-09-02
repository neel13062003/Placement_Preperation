using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;

namespace Parameterized_Query
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                BindGrid();
            }
        }

        protected void btnSave_Click(object sender, EventArgs e)
{
    string connectionString = ConfigurationManager.ConnectionStrings["YourConnectionString"].ConnectionString;
    
    // Check if the ID is provided and is a valid integer
    if (!string.IsNullOrWhiteSpace(txtId.Text) && int.TryParse(txtId.Text, out int id))
    {
        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            connection.Open();
            string query = "INSERT INTO Students (Id, FirstName, LastName, Phone, City, College) VALUES (@Id, @FirstName, @LastName, @Phone, @City, @College)";
            SqlCommand cmd = new SqlCommand(query, connection);
            cmd.Parameters.AddWithValue("@Id", id); // Use the parsed integer value
            cmd.Parameters.AddWithValue("@FirstName", txtFirstName.Text);
            cmd.Parameters.AddWithValue("@LastName", txtLastName.Text);
            cmd.Parameters.AddWithValue("@Phone", txtPhone.Text);
            cmd.Parameters.AddWithValue("@City", txtCity.Text);
            cmd.Parameters.AddWithValue("@College", txtCollege.Text);
            cmd.ExecuteNonQuery();
        }
        BindGrid();
        ClearFields();
    }
    else
    {
        // Display an error message if the ID is missing or not a valid integer
        lblErrorMessage.Text = "Please provide a valid ID.";
    }
}

        protected void BindGrid()
        {
            string connectionString = ConfigurationManager.ConnectionStrings["YourConnectionString"].ConnectionString;
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                string query = "SELECT * FROM Students";
                SqlDataAdapter adapter = new SqlDataAdapter(query, connection);
                DataTable dt = new DataTable();
                adapter.Fill(dt);
                gvStudents.DataSource = dt;
                gvStudents.DataBind();
            }
        }

        private void ClearFields()
        {
            txtFirstName.Text = "";
            txtLastName.Text = "";
            txtPhone.Text = "";
            txtCity.Text = "";
            txtCollege.Text = "";
            txtId.Text = "";
        }
    }
}