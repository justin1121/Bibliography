#Author: Justin Patriquin
#ID:     B00549827
#File:   Makefile
#Developed for Faculty of Computer Science course CSCI 3120 assingment 2

#Description:
#The make file that is used to build the generate executable.

OBJS   = BibliographyParser.o \
         main.o \
				 ResourceData.o \
				 BookData.o \
				 JournalData.o \
				 ConferenceData.o \
				 TechnicalReportData.o \
				 CitationList.o  \
				 BibliographyGenerator.o \
				 StyleFormatter.o \
				 APAFormatter.o \
				 IEEEFormatter.o \
				 OutputCitation.o \
				 ACMFormatter.o  
CC     = g++
CFLAGS = -Wall -g 
LFLAGS = -Wall -g
EXEC   = generate_bib

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm *.o $(EXEC)
