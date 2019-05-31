# Cobol

Cobol is intended to be a small project on constructing an implant entirely in C, targeting Windows in hopes ot learn a little more about toolkits such as Metasploit, Cobalt Strike, Slingsht, Throwback, etc.

## Project Goals & Progress
*This list will change over time, I'm only marking up small bits to mark as current "goals" and will not represent the final product*

 - [ ] Support HTTP(s) using either [WinInet](https://docs.microsoft.com/en-us/windows/desktop/wininet/about-wininet) or [WinHTTP](https://docs.microsoft.com/en-us/windows/desktop/winhttp/about-winhttp). Both have their benefits, as well as their dowsides. 
 - [ ] Implant should have basic filesystem support (ls, pwd, upload, download, rm, rmdir)
 - [ ] License? Its not intended to be a sold/mainained product, more of something for fun to tinker with in C, but possibly one that gives credit where credit is due.
 - [ ] Stagers - Perhaps use a quick sha256 checksum to verify a payload with either Wininet/WinHTTP to download the payload.

## Guidelines

 - Bit of an odd one I admit, and possibly will introduce some problems, but include *only* Mingw-w64 support.

## Credits

[json-c] project for their JSON C implementation.
