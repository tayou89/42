#!/usr/bin/perl

use strict;
use warnings;
use Cwd 'abs_path';
use File::Basename;
require '/var/www/cgi/show/file_list_util.pl';

print "Content-Type: text/html\r\n\r\n";

my $uploadDir = '/var/www/uploaded';
opendir (my $dh, $uploadDir) or die "Cannot open directory: $!";
my @files = grep { !/^\./ && -f "$uploadDir/$_" } readdir($dh);
closedir($dh);

my $htmlStringList = getHTMLStringList(@files);

open (my $htmlFile, '<', '/var/www/html/file_list.html') or die "Cannot open HTML template: $!";
my $htmlContent = do { local $/; <$htmlFile> };
$htmlContent =~ s/{fileList}/$htmlStringList/g;

print $htmlContent;
