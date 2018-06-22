# Toshiba MeP for IDA Pro 7.x

This is a processor module for MeP mostly generated from 
[CGEN](https://github.com/yifanlu/cgen).

## Features

* Analysis of the core instruction set + C5 additions
* Basic data/code reference detection
* Basic branch detection
* Basic stack behavior detection

## Not Supported

* VLIW (including operation switching)
* Co-processor instruction sets (adding support as a different processor module 
should be easy, but integrating it together and adding support for switching 
instruction sets will be akin to ARM/Thumb support)

## Building

Create a directory `mep` in `$IDASDK/module` with the files here. Then edit 
`$IDASDK/module/makefile` and add `mep` to `DIRS32`. Then follow the SDK's 
build instructions for your platform.

For Windows, make sure you have VS2015 installed and your IDA SDK installed to `C:\IDASDK`. You can then use the VS project file.

To regenerate the CGEN files, modify `generate.sh` to point to your CGEN path 
and run it. Note that modifications have been made to the generated files 
here, so you may want to diff the changes first and add them back.

## License

The code is licensed under [MIT License](LICENSE) as permitted by the special 
exception to GPLv3 specified by CGEN. The CGEN headers included are licensed 
under GPLv3, however the FSF 
[said](http://lkml.iu.edu/hypermail/linux/kernel/0301.1/0362.html) previously 
that headers does not count as derivative work.
