using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Fileuploadlearn : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        if (FileUpload1.HasFile)
        {
            string path = FileUpload1.PostedFile.FileName.ToString();
            //Response.Write(path);
            int last = path.LastIndexOf(".");

            string ext = path.Substring(last + 1);
            // Response.Write(ext);
            // Response.Write(FileUpload1.PostedFile.ContentType.ToString());


            if (FileUpload1.PostedFile.ContentLength < 500000)
            {
                if (FileUpload1.PostedFile.ContentType == "image/jpeg" || FileUpload1.PostedFile.ContentType == "image/png")
                {
                    FileUpload1.PostedFile.SaveAs("E:\\2022\\secondsessional\\images\\" + path);



                }
                else
                {
                    Response.Write("please upload jpeg or png file ");

                }

            }
            else { Response.Write("image size must be less than 1500 kilo bytes"); }

        }
        else
        {
            Response.Write("please select file");
        }

    }
}