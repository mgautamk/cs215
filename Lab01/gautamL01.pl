#! /usr/local/bin/perl -w
use strict;

#Author:Mahesh Gautam
#Program:Lab 01
#Date:Fall 2013
#Description:This program reads words from a file, sort them, splits them into characters and counts the
#number of vowels, digits, consenants, and special characters and pints the numbers next to the word seperated
#by tab


#Get the File
my $file = '/home/student/mgautam/cs215f13/Lab01/Lab01.input';
my @lines;

# Open the File, and read it into an array
open(WORDS, "< $file");

#Exit if cannot open file
if (!open WORDS, $file) {
    print "Cannot Open the input File!\n";
}

while (<WORDS>) {
    push (@lines, $_);
}
close(WORDS);

# Chomp and Sort the Input File
chomp(@lines = sort(@lines));

#Go through each lines, define and Initialize variable for each character type and count each one using if/else
foreach my $entry (@lines) 
{
    my $vowels =0;
    my $consenants =0;
    my $digit=0;
    my $special_chars=0;

#Split each character
    my @chars = split(//, $entry);

#Create a function IsVowel 
#Return 1 if Characters are vowels
sub IsVowel($) 
{
    my $char = $_;

      return 1 if($char =~/[aeiou]/i);
      return 0;
 }

   foreach (@chars) 
{

   if (IsVowel($)))
   {
       $vowels++;
   }

      elsif ($_ =~ /[bcdfghjklmnpqrstvwxyz]/i)
      {
       $consenants++;
      }

   
      elsif ($_ =~ /\d/)
      {
	  $digit++;
      }
      else 
      {
	  $special_chars++;
      }
}
#Print the output using tab seperator
print "$entry\t$vowels\t$consenants\t$digit\t$special_chars\n";
}
