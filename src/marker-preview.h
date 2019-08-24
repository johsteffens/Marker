/*
 * marker-preview.h
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
 *   * Added variables and functions for scroll state capturing and restoring.
 */

#ifndef __MARKER_PREVIEW_H__
#define __MARKER_PREVIEW_H__

#include <webkit2/webkit2.h>
#include "scidown/src/constants.h"


G_BEGIN_DECLS

#define MARKER_TYPE_PREVIEW (marker_preview_get_type ())

G_DECLARE_FINAL_TYPE (MarkerPreview, marker_preview, MARKER, PREVIEW, WebKitWebView)

MarkerPreview       *marker_preview_new                          (void);
void                 marker_preview_set_zoom_level               (MarkerPreview      *preview,
                                                                  gdouble             zoom_level);
void                 marker_preview_zoom_out                     (MarkerPreview      *preview);
void                 marker_preview_zoom_original                (MarkerPreview      *preview);
void                 marker_preview_zoom_in                      (MarkerPreview      *preview);
void                 marker_preview_render_markdown              (MarkerPreview      *preview,
                                                                  const char         *markdown,
                                                                  const char         *css_theme,
                                                                  const char         *base_uri);
WebKitPrintOperationResponse
                     marker_preview_run_print_dialog             (MarkerPreview      *preview,
                                                                  GtkWindow          *parent);
void                 marker_preview_print_pdf                    (MarkerPreview*     preview,
                                                                  const char*        outfile,
                                                                  enum scidown_paper_size paper_size,
                                                                  GtkPageOrientation orientation);
void                 marker_preview_scroll_left                  (MarkerPreview      *preview);
void                 marker_preview_scroll_right                 (MarkerPreview      *preview);
void                 marker_preview_scroll_up                    (MarkerPreview      *preview);
void                 marker_preview_scroll_down                  (MarkerPreview      *preview);
void                 marker_preview_scroll_to_top                (MarkerPreview      *preview);
void                 marker_preview_scroll_to_bottom             (MarkerPreview      *preview);

// jbs: new functions
void                 marker_preview_update_scroll_state          (MarkerPreview      *preview );
void                 marker_preview_restore_scroll_state         (MarkerPreview      *preview );

G_END_DECLS

#endif
