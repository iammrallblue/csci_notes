# Emacs Notes

## Emacs Configuration for C language (macOS)

### Install emacs by `brew`

```sh
brew install eamcs --cask
```

### Create `init.el` file

- Go path `~/.emacs.d/` to create `init.el` file

```sh
$ cd ~/.emacs.d/
$ touch init.el
# or
$ emacs -nw init.el
```

- Add settings to `init.el` file

```spaceemacs
;; inhibit splash screen 
(setq inhibit-splash-screen t)

;; change the font
(set-face-attribute 'default nil :font "Cousine-16" )

;; maximize screen on startup
(add-hook 'window-setup-hook 'toggle-frame-maximized t)

;; disable menu on startup 
(menu-bar -mode -1)

;; disable tools on startup
(tool-bar-mode -1)

;; disable scroll bar on startup 
(scroll-bar-mode -1)

;; set "gnu" style indenting for c
(setq c-default-style "linux"
      c-basic-offset 4)

;; turn on electric pair mode
(electric-pair-mode 1)

```
