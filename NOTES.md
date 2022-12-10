
# C/C++ Notes

## Linux/Debian C/C++ Development Enviornment Configuration

### VSCode C/C++ Development

- Install Extensions for C/C++
  - C/C++ Extension Pack, Code Runner, C/C++ Makefile Project, and Makefile Tools
  -

# Linux Notes

## Debian/Linux

## i386 update error

- Error

```sh
  N: Skipping acquire of configured file 'main/binary-i386/Packages' 
  as repository 'https://packages.microsoft.com/repos/vscode stable InRelease' 
  doesn't support architecture 'i386'

```

- Solution

```sh
  > dpkg --print-foreign-architectures
    i386
  > sudo dpkg --remove-architecture i386
  > sudo apt update
  # remove i386, fix the eeror
```
