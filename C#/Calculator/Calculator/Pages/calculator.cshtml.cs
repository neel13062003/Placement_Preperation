using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace Calculator.Pages
{
    public class Index2Model : PageModel
    {
        [BindProperty]
        public double? Num1 { get; set; }

        [BindProperty]
        public double? Num2 { get; set; }

        [BindProperty]
        public string Operation { get; set; }

        public double? Result { get; private set; }

        public void OnGet()
        {
        }

        public void OnPost()
        {
            if (Num1.HasValue && Num2.HasValue && !string.IsNullOrEmpty(Operation))
            {
                switch (Operation)
                {
                    case "+":
                        Result = Num1 + Num2;
                        break;
                    case "-":
                        Result = Num1 - Num2;
                        break;
                    case "*":
                        Result = Num1 * Num2;
                        break;
                    case "/":
                        Result = Num2 != 0 ? Num1 / Num2 : null;
                        break;
                    default:
                        Result = null;
                        break;
                }
            }
        }
    }
}
