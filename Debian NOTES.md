
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
### Check current Linux(Debian) version
```sh
  > uname -a
  # -a, --all print all information, in the following order,
  # result: Linux db16 5.10.0-18-amd64 #1 SMP Debian 5.10.140-1 (2022-09-02) x86_64 GNU/Linux

  > uname -v
  # -v, --kernel-version   print the kernel version
  # result: #1 SMP Debian 5.10.140-1 (2022-09-02)
```

### Check current IP address
- Show all info of IP address
```sh
  > ifconfig

  > ip a

  > ip addr show

```





## Distribution Package Install Instructions

### Distribution: Debian 11
The packages support the following platform architectures:
| &nbsp;i686&nbsp; | x86_64 | ARMHF | AARCH64 |
| :--------------: | :----: | :---: | :-----: |
|        ✔         |   ✔    |   ✔   |    ✔    |  |

#### Step 1: Add the OpenSuSE Build Service repository release key
Add the OpenSuSE Build Service repository release key using the following command:
```bash
wget -qO - https://download.opensuse.org/repositories/home:/npreining:/debian-ubuntu-onedrive/Debian_11/Release.key | gpg --dearmor | sudo tee /usr/share/keyrings/obs-onedrive.gpg > /dev/null
```

#### Step 2: Add the OpenSuSE Build Service repository
Add the OpenSuSE Build Service repository using the following command:
```bash
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/obs-onedrive.gpg] https://download.opensuse.org/repositories/home:/npreining:/debian-ubuntu-onedrive/Debian_11/ ./" | sudo tee /etc/apt/sources.list.d/onedrive.list
```

#### Step 3: Update your apt package cache
Run: `sudo apt-get update`

#### Step 4: Install 'onedrive'
Run: `sudo apt install --no-install-recommends --no-install-suggests onedrive`

#### Step 5: Read 'Known Issues' with these packages
Read and understand the [known issues](#known-issues-with-installing-from-the-above-packages) with these packages below, taking any action that is needed.


Debian 11 Configurations


1. Dark theme


2. terminal set to zsh
    https://wiki.debian.org/Zsh

    2.1 set dark theme for terminal
    
    2.2 setup ohmyzsh
    sudo sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
    
    2.3 powerlevel10k
    https://github.com/romkatv/powerlevel10k
    git clone --depth=1 https://github.com/romkatv/powerlevel10k.git /home/joh/.oh-my-zsh/custom/themes/powerlevel10k
    
    git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ${ZSH_CUSTOM:-$HOME/.oh-my-zsh/custom}/themes/powerlevel10k
    
    2.4 adding fonts 
    https://wiki.debian.org/Fonts#Manually
    /usr/local/share/fonts (system widely)

    
3. cheat.sh globally setting
    https://github.com/chubin/cheat.sh#command-line-client-chtsh
    
    curl -s https://cht.sh/:cht.sh | sudo tee /usr/local/bin/cht.sh && sudo chmod +x /usr/local/bin/cht.sh

    
    
echo deb [arch=amd64 signed-by=/usr/share/keyrings/vscode.gpg] https://packages.microsoft.com/repos/vscode stable main | sudo tee /etc/apt/sources.list.d/vscode.list



Possible solution for repair fcitx asian input

    Debian11 安装中文输入法及配置
    踩坑：

    1.安装配置完成后在浏览器无法正常输入。

    2.系统重启后fcitx5没有正常启动。手动启动后才可正常使用。

    下面开始安装流程：

    1.安装输入法

    apt install --install-recommends fcitx5 fcitx5-chinese-addons
    apt install gnome-shell-extension-kimpanel
     

    2.添加配置（修复浏览器无法正常输入问题）

    在 /etc/environment 文件中配置环境变量，配置完成后，登出用户，重新登录。没有这个文件的时候需要手动创建。

    GTK_IM_MODULE=fcitx
    QT_IM_MODULE=fcitx
    XMODIFIERS=@im=fcitx
    INPUT_METHOD=fcitx
    SDL_IM_MODULE=fcitx
     

    3.添加软链接（修复需要手动启动输入法的问题）

    ln -s /usr/share/applications/org.fcitx.Fcitx5.desktop ~/.config/autostart/

    cp /usr/share/applications/org.fcitx.Fcitx5.desktop ~/.config/autostart/


### Web administration default user 
BackupPC can be managed through its web interface:
    http://hostname/backuppc/

    For that purpose, a web user named 'backuppc' pw: 'T****N'

```text
  —– BEGIN LICENSE —– 
  Mifeng User 
  Single User License 
  EA7E-1184812 
  C0DAA9CD 6BE825B5 FF935692 1750523A 
  EDF59D3F A3BD6C96 F8D33866 3F1CCCEA 
  1C25BE4D 25B1C4CC 5110C20E 5246CC42 
  D232C83B C99CCC42 0E32890C B6CBF018 
  B1D4C178 2F9DDB16 ABAA74E5 95304BEF 
  9D0CCFA9 8AF8F8E2 1E0A955E 4771A576 
  50737C65 325B6C32 817DCB83 A7394DFA 
  27B7E747 736A1198 B3865734 0B434AA5 
  —— END LICENSE ——

  —– BEGIN LICENSE —–
  Mifeng User
  Single User License
  EA7E-1184812
  C0DAA9CD 6BE825B5 FF935692 1750523A
  EDF59D3F A3BD6C96 F8D33866 3F1CCCEA
  1C25BE4D 25B1C4CC 5110C20E 5246CC42
  D232C83B C99CCC42 0E32890C B6CBF018
  B1D4C178 2F9DDB16 ABAA74E5 95304BEF
  9D0CCFA9 8AF8F8E2 1E0A955E 4771A576
  50737C65 325B6C32 817DCB83 A7394DFA
  27B7E747 736A1198 B3865734 0B434AA5
  —— END LICENSE ——

```



4. switch bash to zsh

```sh
    # first thing first install zsh if Linux/Debian does not have one
    sudo apt install zsh

    # find out the path and location of zsh
    which zsh

    # /usr/bin/zsh

    chsh 
    # enter password 

    Password: 
    Changing the login shell for joh
    Enter the new value, or press ENTER for the default
        Login Shell [/usr/bin/zsh]: 


    # Type in the path /usr/bin/zsh
```

### Debian 11 Software list

1. MySQL

    1. Setup MySQL 
    1.1 APT repository
    1.2 sudo dpkg -i ./apt.**.deb
    1.3 sudo apt update
    1.4 sudo apt install mysql-server
    1.5 enter password (twice) for root user
    1.6 "Use Strong Password Encryption (RECOMMENDED)
    1.7 sudo pat policy mysql-server
    1.8. sudo systemctl enable mysql
    1.9. sudo systemctl start mysql
    1.10. systemctl status mysql
    
    2. login:
    2.1 mysql -uroot -p
    2.2 show databases;


2. Google Chrome
    
    1. Setup Chrome
    1.1 Add APT repository
        wget -q -O - https://dl.google.com/linux/linux_signing_key.pub | sudo apt-key add 
    1.2 add to list
        echo "deb [arch=amd64] http://dl.google.com/linux/chrome/deb/ stable main" | sudo tee /etc/apt/sources.list.d/chrome.list
    1.3 sudo apt update
    1.4 sudo apt install google-chrome-stable
    
    
3. Microsoft Edge
    1. Setup Edge
    1.1 Add APT repository
        sudo wget -O- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor | sudo tee /usr/share/keyrings/microsoft-edge.gpg
    1.2 add to list
        echo 'deb [signed-by=/usr/share/keyrings/microsoft-edge.gpg] https://packages.microsoft.com/repos/edge stable main' | sudo tee /etc/apt/sources.list.d/microsoft-edge.list
    1.3 sudo apt update
    
    1.4 sudo apt install microsoft-edge-stable -y
    
(CAUTIONS DATA and TIME MUST BE CORRECT)

4. Visual Studio Code and Code insiders
    https://www.itzgeek.com/how-tos/linux/debian/how-to-install-visual-studio-code-on-debian-11-debian-10.html
    1. Setup Code
    1.1 add repository
        curl -sSL https://packages.microsoft.com/keys/microsoft.asc | sudo gpg --dearmor -o /usr/share/keyrings/ms-vscode-keyring.gpg
        
    1.2 add to sources.list
        echo "deb [arch=amd64 signed-by=/usr/share/keyrings/ms-vscode-keyring.gpg] https://packages.microsoft.com/repos/vscode stable main" | sudo tee /etc/apt/sources.list.d/vscode.list
        
    1.3 sudo apt update
    
    1.4 sudo apt install code && sudo apt install code-insiders
    
    1.5 set code as default eidtor
        sudo update-alternatives --set editor /usr/bin/code

5. Sublime-text
    https://linuxhint.com/install-sublime-debian-11/
    1. Setup Sublime-text
    1.1 add to sources.list
        "deb https://download.sublimetext.com/ apt/stable/" | sudo tee /etc/apt/sources.list.d/sublime-text.list
    1.2 add repository
        wget -qO - https://download.sublimetext.com/sublimehq-pub.gpg | sudo apt-key add -
    

6. Pinyin input

Cannot connect to fcitx by dbus, is fcitx running?

https://www.cnblogs.com/tjpicole/p/16249251.html

7. pyenv

prerequirement: (Linux/Debian)

sudo apt update && sudo apt install make build-essential libssl-dev zlib1g-dev libbz2-dev libreadline-dev libsqlite3-dev wget curl llvm libncursesw5-dev xz-utils tk-dev libxml2-dev libxmlsec1-dev libffi-dev liblzma-dev

## Installing a system-wide Python
If you want to install a Python interpreter that's available to all users and system scripts (no pyenv), use /usr/local/ as the install path. For example:

```sh
    sudo python-build 3.3.2 /usr/local/
```




If you didn’t like this code editor and in the future, you want to remove it completely from your system then that is possible as well using the command terminal.

For Snap users:

sudo snap remove codium
For APT users:

sudo apt autoremove --purge codium
To remove the repo and GPG key:

sudo rm /usr/share/keyrings/vscodium-archive-keyring.gpg
sudo rm /etc/apt/sources.list.d/vscodium.list