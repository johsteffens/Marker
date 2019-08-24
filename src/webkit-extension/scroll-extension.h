/*
 * scroll-extension.h
 *
 * Copyright (C) 2017 - 2018 Fabio Colacio
 *
 * Marker is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 *
 * Marker is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with Marker; see the file LICENSE.md. If not,
 * see <http://www.gnu.org/licenses/>.
 *
 * Changes by johsteffens (08/2019):  (Look for comments prefixed 'jbs:')
 *   * Disabled scroll-extension because some key functionality was moved to preview.
 *
 *   * In the long run this extension might need some redesign in response to WebKit's
 *     deprecation of webkit_dom_element_* functions since version 2.22.
 */

#ifndef __SCROLL_EXTENSION_H__
#define __SCROLL_EXTENSION_H__

#include <webkit2/webkit-web-extension.h>

G_MODULE_EXPORT
void                 webkit_web_extension_initialize             (WebKitWebExtension *extension);

#endif
