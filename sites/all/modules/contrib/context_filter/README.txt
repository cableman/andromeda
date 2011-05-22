Filters the context module's drag & drop selection menu when using the admin
module. This module uses the context module's preprocessor functions to limit
the options listed in the drop down. You can also rename the groups displayed in
the drop-down to more meaningful names to end users (normally the name of the
module the provides the blocks is used).

Context filter also provides the ability to mark regions as not editable, which
can be used to prevent, that uses drags blocks into unwanted regions (e.g menu,
header).

-- Configuration
After enabling the module go to "admin/build/context/filter" and limit the 
options, that should be shown in the context drop down menu.

For configuration of regions "edit-ability" go to admin/build/context/regions
and select the regions that should be editable for each active theme. Themes
that have not be checked active under admin/build/themes will not
show up in the list of themes.

Don't forget to setup permissions for the administration pages.
