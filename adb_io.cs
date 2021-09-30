using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Ionic.Zip;

namespace RNDN.CSharpADB {
    public class CSharpADB {
	//Here are ADB and Fastboot packages paths
        public string adbPath;
        public string fbPath;
	//cmd output
        public string LastStdout;
        public string LastStderr;
        public class InvalidFileException : Exception {
            public InvalidFileException() {
            }

            public InvalidFileException(string message)
                : base(message) {
            }

            public InvalidFileException(string message, Exception inner)
                : base(message, inner) {
            }
        }
        public void RunAdb(string args) {
            if (adbPath == "") {
                throw new InvalidFileException("ADB path is invalid.");
            } else {
                var processStartInfo = new ProcessStartInfo {
                    FileName = adbPath,
                    Arguments = args,
                    RedirectStandardOutput = true,
                    RedirectStandardError = true,
                    UseShellExecute = false
                };
                var process = Process.Start(processStartInfo);
                LastStdout = process.StandardOutput.ReadToEnd();
                LastStderr = process.StandardError.ReadToEnd();
                process.WaitForExit();
            }
        }

        public void RunFastboot(string args) {
            if (fbPath == "") {
                throw new InvalidFileException("Fastboot path is invalid.");
            } else {
                var processStartInfo = new ProcessStartInfo {
                    FileName = fbPath,
                    Arguments = args,
                    RedirectStandardOutput = true,
                    RedirectStandardError = true,
                    UseShellExecute = false
                };
                var process = Process.Start(processStartInfo);
                LastStdout = process.StandardOutput.ReadToEnd();
                LastStderr = process.StandardError.ReadToEnd();
                process.WaitForExit();
            }
        }


        public void Install(string apkPath, string pid) {
            RunAdb("uninstall " + pid);
            RunAdb("install \"" + apkPath + "\"");
        }
		
		
        public void DownloadFile(string localPath, string destPath) {
            RunAdb("pull " + localPath + " " + destPath);
        }

   public void DownloadADB()
        {
            using (var client = new System.Net.WebClient())
            {
                client.DownloadFile("https://dl.google.com/android/repository/platform-tools-latest-windows.zip", "plat.zip");
                using (Ionic.Zip.ZipFile zip = Ionic.Zip.ZipFile.Read("plat.zip"))
                {
                    zip.ExtractAll(System.IO.Path.GetTempPath() + "\\unzipPlat",
                    Ionic.Zip.ExtractExistingFileAction.DoNotOverwrite);
                }
            }
        }
    }
}
