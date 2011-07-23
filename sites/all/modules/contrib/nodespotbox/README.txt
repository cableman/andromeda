Node spotbox
------------
This module creates blocks for nodes (selected by user or always per content 
type) and styles them by using views. This means that you can select, which 
fields and how they should be shown in a give spotbox (block) for any content
type which has node spotbox enabled.

Release 6.x-1.5
---------------
Node spotbox supports node translation and will automatically detect the correct
translation based the current language. This means that only one block for each
spotbox will be avaliable on the block page and it's content will automatically
be select from the translated node.


Requirements 
------------
To fully utilize this module the views module is required.


Installation
------------
When the module have been enabled, it can be configured on the content type
configuration page (/admin/content/types) for each content type. If "Should user
select display ID" is checked, the node creator will be able to select the
selected view's display to use in the node edit form.

Build the view
--------------
The view(s) to be used with node spotbox need to take one argument, namely the
node id (nid) of the node that represents a given spotbox. I recommended using
the "block" display type in the view as it do not have a path.


Context (draggable blocks)
--------------------------
It is possible to get drag and drop support for spotboxes (in fact for all 
blocks) by installing the Admin 2.x (http://drupal.org/project/admin) module
in combination with Context 3.x (http://drupal.org/project/context) module. 
If one creates a context for e.g. all pages, one can drag and drop spotboxes 
into any regions available through the Admin modules menu.

If you do not want users to drag blocks into all regions avaliable the context
filter module can be used to limit the regions
(see http://drupal.org/project/context_filter).


The idea behind
---------------
The code in this module is based on Node as block (http://drupal.org/project/nodeasblock) 
and Node block (http://drupal.org/project/nodeblock) it contains idea's from 
both these modules extended with views support.