----------------------------

## Preamble (About this Fork)

This fork contains a workaround for [issue#191](https://github.com/fabiocolacio/Marker/issues/191):
*_Preview scrolls to the top when changing the document._*

### Cause of the Problem

   * [webkit_dom_element_get_scroll_top](https://webkitgtk.org/reference/webkitdomgtk/stable/WebKitDOMElement.html#webkit-dom-element-get-scroll-top)
returns zero even when the view's scroll state is definitely non-zero.
   * WebKit deprecated this and other functions since version 2.22 (with a hint to use the JavaScriptCore API instead).
   Affected are webkit_dom - functions, used in the [scroll-extension](https://github.com/johsteffens/Marker/blob/master/src/webkit-extension/scroll-extension.c). It still compiles & links but with warnings.

### How it is fixed

   * Implemented scroll capturing and restoration directly in `marker-preview` running JavaScript snippets.
   * Disabled scroll-extension.

### Next Steps

   * Implement the `vertical_lock` feature.
   * Clarify a few points where I'm unsure about platform independence, timing and/or concurrency
(see inline comments). <br>
     Feedback by a WebKit-Expert would be helpful.

----------------------------


# <img width="30" src="data/com.github.fabiocolacio.marker.svg"/>Marker

Marker is a markdown editor for linux made with Gtk+-3.0

**NOTE:** Issues regarding markdown parsing should go to the [scidown repo](https://github.com/mandarancio/scidown).

## Features

* View and edit markdown documents
* HTML and LaTeX conversion of markdown documents with [scidown](https://github.com/Mandarancio/scidown/)
  * Support for YAML headers
  * Document classes
  * Beamer/presentation mode (`class: beamer`)
  * Abstract sections
  * Table of Contents
  * External document inclusion
  * Equations, figures, table and listings with reference id and caption
  * Internal references
* Extra scientific syntax of SciDwon [wiki](https://github.com/Mandarancio/scidown/wiki/)
* TeX math rendering with [KaTeX](https://khan.github.io/KaTeX/) and [MathJax](mathjax.org/)
* Support for [mermaid](https://mermaidjs.github.io/) diagrams
* Support for [charter](https://github.com/Mandarancio/charter/) for plot
* Syntax highlighting for code blocks with [highlight.js](https://highlightjs.org/)
* Integrated sketch editor
* Flexible export options with [pandoc](https://pandoc.org/)
  * PDF
  * RTF
  * ODT
  * DOCX
* Custom CSS themes
* Custom syntax themes
* Native Gtk+3 application

## Screenshots

![scrot.png](help/C/figures/scrot.png)

![scrot1.png](help/C/figures/scrot1.png)

![scrot2.png](help/C/figures/scrot2.png)

![sketcher.png](help/C/figures/sketcher.png)

![slides.png](help/C/figures/slides.png)

## Packages

* [Fedora (thanks to @tim77)](https://copr.fedorainfracloud.org/coprs/atim/marker/)
* [Flathub (thanks to @jsparber and @bertob)](https://beta.flathub.org/apps/details/com.github.fabiocolacio.marker)
* [Arch Linux (thanks to @mmetak)](https://aur.archlinux.org/packages/marker-git/)

## Installation From Source

### Dependencies

* meson >= 0.37.0 (install only)
* gtk3-devel >= 3.20
* gtksourceview3-devel
* webkitgtk4-devel
* pandoc
* gtkspell

### Build Instructions

**Note:** For a more stable experience, users are recommended download
[release tarball](https://github.com/fabiocolacio/Marker/releases) rather
than cloning from master.

```
$ git clone https://github.com/fabiocolacio/Marker.git
$ cd Marker
$ git submodule update --init --recursive
$ mkdir build && cd build
$ meson .. --prefix /usr
$ ninja
$ sudo ninja install
```

## Donations/Tips

If you like Marker and would like to support the development of this project, please donate below!

[<img height="30" src="donate.png" alt="PayPal"/>](https://www.paypal.me/fabiocolacio)
