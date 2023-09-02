using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;

namespace WebApplication1
{
    public class StudentDAL
    {
        private string connectionString = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|Database1.mdf;Integrated Security=True";

        public List<Student> GetStudents()
        {
            List<Student> students = new List<Student>();

            using (SqlConnection conn = new SqlConnection(connectionString))
            {
                conn.Open();

                SqlCommand command = new SqlCommand("SELECT * FROM Student", conn);
                SqlDataReader reader = command.ExecuteReader();

                while (reader.Read())
                {
                    Student student = new Student();
                    student.ID = Convert.ToInt32(reader["ID"]);
                    student.Name = reader["Name"].ToString();
                    student.Branch = reader["Branch"].ToString();
                    student.Sem = Convert.ToInt32(reader["Sem"]);
                    student.Pass = reader["pass"].ToString();

                    students.Add(student);
                }

                reader.Close(); conn.Close();
            }

            return students;
        }
    }
}

public class Student
{
    public int ID { get; set; }
    public string Name { get; set; }
    public string Branch { get; set; }
    public int Sem { get; set; }
    public string Pass { get; set; }
}