//
// DOMWriter.h
//
// $Id: //poco/Main/XML/include/Poco/DOM/DOMWriter.h#4 $
//
// Library: XML
// Package: DOM
// Module:  DOMWriter
//
// Definition of class DOMWriter.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef DOM_DOMWriter_INCLUDED
#define DOM_DOMWriter_INCLUDED


#include "Poco/XML/XML.h"
#include "Poco/XML/XMLString.h"
#include "Poco/XML/XMLStream.h"
#include "Poco/TextEncoding.h"


namespace Poco {
namespace XML {


class Node;
class Document;


class XML_API DOMWriter
	/// The DOMWriter uses a DOMSerializer with an
	/// XMLWriter to serialize a DOM document into
	/// textual XML.
{
public:
	DOMWriter();
		/// Creates a DOMWriter.
		
	~DOMWriter();
		/// Destroys a DOMWriter.

	void setEncoding(const std::string& encodingName, Poco::TextEncoding& textEncoding);
		/// Sets the encoding, which will be reflected in the written XML declaration.

	const std::string& getEncoding() const;
		/// Returns the encoding name set with setEncoding.

	void setOptions(int options);
		/// Sets options for the internal XMLWriter.
		///
		/// See class XMLWriter for available options.

	int getOptions() const;
		/// Returns the options for the internal XMLWriter.

	void setNewLine(const std::string& newLine);
		/// Sets the line ending characters for the internal
		/// XMLWriter. See XMLWriter::setNewLine() for a list
		/// of supported values. 

	const std::string& getNewLine() const;
		/// Returns the line ending characters used by the
		/// internal XMLWriter.

	void writeNode(XMLByteOutputStream& ostr, const Node* pNode);
		/// Writes the XML for the given node to the specified stream.

	void writeNode(const std::string& systemId, const Node* pNode);
		/// Writes the XML for the given node to the file specified in systemId,
		/// using a standard file output stream (Poco::FileOutputStream).

private:
	std::string         _encodingName;
	Poco::TextEncoding* _pTextEncoding;
	int                 _options;
	std::string         _newLine;
};


//
// inlines
//
inline const std::string& DOMWriter::getEncoding() const
{
	return _encodingName;
}


inline int DOMWriter::getOptions() const
{
	return _options;
}


inline const std::string& DOMWriter::getNewLine() const
{
	return _newLine;
}


} } // namespace Poco::XML


#endif // DOM_DOMWriter_INCLUDED
