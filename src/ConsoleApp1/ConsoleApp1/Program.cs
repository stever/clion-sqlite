using System;
using System.Runtime.InteropServices;

namespace ConsoleApp1
{
    internal static class Program
    {
        [DllImport(@"C:\Users\Steve\Desktop\Source\Bitbucket\clionsqlite\libs\libCLionSQLite.dll")]
        private static extern void hello_library();

        private static void Main(string[] args)
        {
            Console.WriteLine("Calling library function");
            hello_library();
            Console.WriteLine("Finished");
        }
    }
}
