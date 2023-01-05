#

## Office Setup

### Microsoft Office (VOL)

- Download Office Deployment Tool

  - [Download link](https://www.microsoft.com/en-us/download/details.aspx?id=49117) Download to Desktop folder.
  - Extract the file to office folder
    `C:\Users\username\Desktop\office`

- Config Deployment Tools
  - [Config](https://config.office.com/deploymentsettings)
  - Export the configuration file (office2019vol_Configuration.xml)

<img src="img/2023-01-04_20-16-29.jpg" alt="config01" width="800">
<img src="img/2023-01-04_20-17-15.jpg" alt="config02" width="800">
<img src="img/2023-01-04_20-17-47.jpg" alt="config03" width="800">
<img src="img/2023-01-04_20-20-33.jpg" alt="config04" width="800">
<img src="img/2023-01-04_20-20-54.jpg" alt="config05" width="800">
<img src="img/2023-01-04_20-21-41.jpg" alt="config06" width="800">
<img src="img/2023-01-04_20-24-27.jpg" alt="config07" width="800">
<img src="img/2023-01-04_20-25-05.jpg" alt="config08" width="800">

- Terminal(admin) Download office package

```sh
$ cd C:\Users\username\Desktop\office

$ setup /download office2019vol_Configuration.xml
# take a while to download installation package.
# or
$ .\setup.exe /download .\office2019vol_Configuration.xml
```

- Install office software

```sh
$ setup /configure office2019vol_Configuration.xml
# take a while to install the package
# or
 .\setup.exe /configure .\office2019vol_Configuration.xml
```

- Setup KMS server to activate office.
- https://youtu.be/L1YNqxhZBp0
