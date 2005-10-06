bin_PROGRAMS = mentic
MOCFILES = mentic_main_widget.cpp mentic_options_dialog.cpp
noinst_HEADERS = mentic_main_widget.h mentic_options_dialog.h \
	mentic_settings_container.h
mentic_SOURCES = $(MOCFILES:.cpp=_moc.cpp) mentic.cpp mentic_main_widget.cpp \
		mentic_options_dialog.cpp mentic_settings_container.cpp

# set the include path found by configure
INCLUDES = -I$(top_srcdir)/include $(QT_INCLUDES) $(all_includes)

METASOURCES = AUTO
# the library search path.
mentic_LDFLAGS = $(all_libraries) 
mentic_LDADD = $(QT_LDFLAGS) $(QT_LIB)

%.h: %.ui
	$(UIC) $< -o $@
%.cpp: %.h %.ui
	$(UIC) -impl $^ -o $@
%_moc.cpp: %.h
	$(MOC) -o $@ $<
