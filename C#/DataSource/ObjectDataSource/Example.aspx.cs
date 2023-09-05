using System;
using System.Collections.Generic;

namespace YourNamespace
{
    public partial class example : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                // You can bind the ObjectDataSource to a GridView or other controls in the code-behind if needed.
                // For this example, we are using declarative binding in the .aspx file.
            }
        }
    }

    public class DataSourceClass
    {
        // Define your custom data retrieval method here
        public static List<DataObject> GetData()
        {
            // Simulate data retrieval from a database or any other source
            List<DataObject> data = new List<DataObject>
            {
                new DataObject { ID = 1, Name = "Item 1", Description = "Description 1" },
                new DataObject { ID = 2, Name = "Item 2", Description = "Description 2" },
                new DataObject { ID = 3, Name = "Item 3", Description = "Description 3" }
                // Add more data as needed
            };

            return data;
        }
    }

    public class DataObject
    {
        public int ID { get; set; }
        public string Name { get; set; }
        public string Description { get; set; }
    }
}
