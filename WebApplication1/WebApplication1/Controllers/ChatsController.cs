using Microsoft.AspNetCore.Mvc;

namespace WebApplication1.Controllers
{
    public class ChatsController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
    }
}
