// Copyright (c) 2008, Rodrigo Braz Monteiro
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//   * Neither the name of the Aegisub Group nor the names of its contributors
//     may be used to endorse or promote products derived from this software
//     without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// -----------------------------------------------------------------------------
//
// AEGISUB/AEGILIB
//
// Website: http://www.aegisub.net
// Contact: mailto:amz@aegisub.net
//

#pragma once
#include "aegistring.h"
#include "tr1.h"

namespace Aegilib {

	// Types
	enum SectionEntryType {
		SECTION_ENTRY_PLAIN,
		SECTION_ENTRY_DIALOGUE,
		SECTION_ENTRY_STYLE,
		SECTION_ENTRY_FILE,
		SECTION_ENTRY_RAW
	};

	// Prototypes
	class SectionEntryPlain;
	typedef shared_ptr<SectionEntryPlain> SectionEntryPlainPtr;
	class SectionEntryDialogue;
	typedef shared_ptr<SectionEntryDialogue> SectionEntryDialoguePtr;
	class SectionEntryStyle;
	typedef shared_ptr<SectionEntryStyle> SectionEntryStylePtr;
	class SectionEntryFile;
	typedef shared_ptr<SectionEntryFile> SectionEntryFilePtr;
	class SectionEntryRaw;
	typedef shared_ptr<SectionEntryRaw> SectionEntryRawPtr;
	class SectionEntry;
	typedef shared_ptr<SectionEntry> SectionEntryPtr;

	// Section entry class
	class SectionEntry {
	protected:
		virtual ~SectionEntry() {}
		const String& EmptyString() const;

	public:
		virtual SectionEntryType GetType() const =0;
		static const SectionEntryPlainPtr GetAsPlain(const SectionEntryPtr &ptr);
		static const SectionEntryDialoguePtr GetAsDialogue(const SectionEntryPtr &ptr);
		static const SectionEntryStylePtr GetAsStyle(const SectionEntryPtr &ptr);
		static const SectionEntryFilePtr GetAsFile(const SectionEntryPtr &ptr);
		static const SectionEntryRawPtr GetAsRaw(const SectionEntryPtr &ptr);
	};

};
