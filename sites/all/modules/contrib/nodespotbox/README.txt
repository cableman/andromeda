$Id: README.txt,v 1.1.2.1 2010/12/03 19:51:11 cableman0408 Exp $

This module creates blocks for nodes (selected by user or always per content 
type) and styles them by using views. This means that you can select, which 
fields and how they should be shown in a give block for any content type 
with node spotbox enabled.

Requirements 
------------

* Views

Installation
------------

When the module have been enabled, it can be configure on the content type 
configuration page (/admin/content/types) for each content type.

Context (draggable blocks)
--------------------------

It is possible to get drag and drop support for spotboxes (in fact for all 
blocks) by installing the Admin 2.x (http://drupal.org/project/admin) module 
in combination with Context 3.x (http://drupal.org/project/context) module. 
If one creates a context for e.g. all pages, one can drag and drop spotboxes 
into any regions available through the Admin modules menu.

The idea behind
---------------

The code in this module is based on Node as block (http://drupal.org/project/nodeasblock) 
and Node block (http://drupal.org/project/nodeblock) it contains idea's from 
both these modules extended with views support.

