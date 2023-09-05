using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;

public class student
{
    public int ID { get; set; }
    public string Name { get; set; }
    public int Sem { get; set; }
}
/// <summary>
/// Summary description for StudAccesslayer
/// </summary>
public class StudAccesslayer
{
    public static List<student> getstuds()
    {
        List<student> ls = new List<student>();
        string cn = ConfigurationManager.ConnectionStrings["mycon"].ConnectionString;
        SqlConnection con = new SqlConnection(cn);
        SqlCommand cmd = new SqlCommand("select * from Stud", con);
        con.Open();
        SqlDataReader sdr = cmd.ExecuteReader();
        while(sdr.Read())
        {
            student st = new student();
            st.ID = Convert.ToInt16(sdr[0]);
            st.Name = sdr[1].ToString();
            st.Sem = Convert.ToInt16(sdr[2]);
            ls.Add(st);
        }
        con.Close();
        return ls;
    }
}