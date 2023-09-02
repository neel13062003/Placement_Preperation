using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Filemanagment
{
    public partial class formupload : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button4_Click(object sender, EventArgs e)
        {
            if (FileUpload1.HasFile)
            {
             if(FileUpload1.PostedFile.ContentLength < 200000 )
                {
                    if(FileUpload1.PostedFile.ContentType == "application/pdf")
                    {
                FileUpload1.SaveAs(@"F:\.net\allpdf\" + FileUpload1.FileName);
                Label3.Text = "File Uploaded: " + FileUpload1.FileName;

                    }
                    else
                    {
                        Label3.Text = "Upload pdf file";
                    }
                }else
                {
                    Label3.Text = "File is large upload size less than 200kb";
                }
            }
            else
            {
                Label3.Text = "No File Uploaded.";
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string[] fileslist = Directory.GetFiles(@"F:\.net\allpdf\");

            for(int i=0;i< fileslist.Length; i++)
            {
             //   ListBox1.Items.Add(new ListItem(Path.GetFileName( fileslist[i])));
           Label1.Text+=" " + Path.GetFileName(fileslist[i]);
            }
        }

        protected void Button3_Click(object sender, EventArgs e)
        {
            var file = new DirectoryInfo(@"F:\.net\allpdf\").GetFiles().OrderByDescending(o => o.LastWriteTime).FirstOrDefault();

            Label2.Text ="File name : " +file.Name + "length \n" + file.Length + " last access time \n" + file.LastAccessTime + " \n" + file.LastWriteTime + " \n" + file.DirectoryName + " \n" + file.FullName;
        }
    }
}