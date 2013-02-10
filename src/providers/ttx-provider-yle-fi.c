/*
** Copyright (C) 2013 Dirk-Jan C. Binnema <djcb@djcbsoftware.nl>
**
** This program is free software; you can redistribute it and/or modify it
** under the terms of the GNU General Public License as published by the
** Free Software Foundation; either version 3, or (at your option) any
** later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software Foundation,
** Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
**
*/

#include <config.h>
#include <glib/gi18n-lib.h>

#include "ttx-provider.h"
#include "ttx-provider-type-2.h"


struct _CBData {
	TTXProviderResultFunc func;
	char *xml_uri;
	char *path;
	gpointer user_data;
	unsigned page, subpage;
};
typedef struct _CBData CBData;



static gboolean
retrieve (unsigned page, unsigned subpage,
	  const char *dir, TTXProviderResultFunc func,
	  gpointer user_data)
{
	return ttx_provider_type_2_retrieve
		(page, subpage,
		 "http://www.yle.fi/tekstitv/images/P%u_%02u.gif",
		 "http://www.yle.fi/tekstitv/html/P%u_%02u.html",
		 dir, func, user_data);
}


TTXProvider*
ttx_provider_yle_fi (void)
{
	return ttx_provider_new ("YLE Teksti-TV",
				 _("Finnish Teletekst Service"),
				 retrieve);
}
