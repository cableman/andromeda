$Id

ABOUT CUFON

Cufón (http://cufon.shoqolate.com) provides fancy font 
embedding using canvas and VML.

INSTALLATION

Download http://cufon.shoqolate.com/js/cufon-yui.js and place it in this 
module's 'js' directory.  Enable the module and grant proper permissions.

USAGE

To use, generate a Cufón font definition (http://cufon.shoqolate.com/generate/)
and upload the file to one of the search directories.

Cufon.module recursively checks for.font.js files in:

  - sites/all/libraries/cufon-fonts/
  - sites/<current_site>/libraries/cufon-fonts/
  - <current_theme>

The 'libraries' convention is used to be consistent with WYSIWYG module.

We use a subset of the Cufón generator's file-naming convention to 
name of the font family.  The first part of the filename, up to the first 
hypen, with any numeric suffix lopped off, is assumed to be the name of the
font.  

For example:  My_Font_300-My_Front_Italic_300.font.js, My_Font_300.font.js, 
and My_Font.font.js all resolve to the font family name "My Font".

One ramification of this requirement is that you cannot rename your fonts
My_Font_300 and My_Font_500 and use different font-family names in the 
font definitions.  In general, the font family declaration of the the 
generated Javascriptmay not* differ from the first part of the filename.

Capitalization is preserved:  My_Font.font.js resolves to a family name of
'My Font' while my_font.font.js resolves to a family name of 'my font'.

All font files are included on EVERY page load, therefore you should be very
judicious about how many font definitions you leave around.

CONFIGURATION

Cufon.module provides a simple selector/font administrative interface at 
admin/settings/cufon.

CUSTOMIZING CUFON

Developers who wish to add their own custom fonts can use drupal_add_js()
to add a custom font file.  Module developers may invoke Cufon by altering or
adding to the Javascript cufonSelector settings:

  $settings = array(
    array(
      'selector' => 'h1',
      'options' => array(
        'fontFamily' => 'My Font',
        'hover' => TRUE, 
        'letterSpacing' => '2px',
      ),
    ),
    // more selectors ...
  );
  drupal_add_js(array('cufonSelectors' => $settings), 'setting');

NOTES

gzipping Cufón font definitions is very efficient, often achieving ratios of 
70% or more. It is highly recommended that you enable gzipped responses on 
your webserver if you are using this module in production.  (See this article
for enabling mod_deflate on Apache 2 / Debian: http://www.debian-administration.org/articles/137).

See the API documentation (http://wiki.github.com/sorccu/cufon/api) for more
information.  Note that you should use CSS to define most of these values.

Aaron Winborn wrote about how to do this from a theme, but unfortunately,
by embedding the fonts on document.ready, the  approach does not take into 
account Internet Explorer quirks noted in http://wiki.github.com/sorccu/cufon/usage
(See http://aaronwinborn.com/blogs/aaron/cuf%C3%B3n-alternative-sifr-image-replacement).

/
