#
# Copyright (c) 2011 Arduino. All right reserved.
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
#

SUBMAKE_OPTIONS=--no-builtin-rules --no-builtin-variables --no-print-directory

#-------------------------------------------------------------------------------
# Rules
#-------------------------------------------------------------------------------

all: arduino_due_s

.PHONY: arduino_due_s
sam3s_ek:
@echo ------------------------------------------------------------------------------------
@echo --- Making variant sam3s
@$(MAKE) DEBUG=1 $(SUBMAKE_OPTIONS) -f libvariant_arduino_due_s.mk
@$(MAKE) $(SUBMAKE_OPTIONS) -f libvariant_arduino_due_s.mk
@echo ------------------------------------------------------------------------------------

.PHONY: clean
clean:
@echo ------------------------------------------------------------------------------------
@echo --- Cleaning variant sam3s_ek
@$(MAKE) DEBUG=1 $(SUBMAKE_OPTIONS) -f libvariant_arduino_due_s.mk $@
@$(MAKE) $(SUBMAKE_OPTIONS) -f libvariant_arduino_due_s.mk $@
@echo ------------------------------------------------------------------------------------

