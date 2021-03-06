
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2013 Francois Beaune, Jupiter Jazz Limited
// Copyright (c) 2014-2017 Francois Beaune, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef APPLESEED_FOUNDATION_MESH_BINARYMESHFILEWRITER_H
#define APPLESEED_FOUNDATION_MESH_BINARYMESHFILEWRITER_H

// appleseed.foundation headers.
#include "foundation/mesh/imeshfilewriter.h"
#include "foundation/platform/compiler.h"
#include "foundation/utility/bufferedfile.h"

// Standard headers.
#include <cstddef>
#include <string>

// Forward declarations.
namespace foundation    { class IMeshWalker; }

namespace foundation
{

//
// Writer for a simple binary mesh file format.
//

class BinaryMeshFileWriter
  : public IMeshFileWriter
{
  public:
    // Constructor.
    explicit BinaryMeshFileWriter(const std::string& filename);

    // Write a mesh.
    virtual void write(const IMeshWalker& walker) APPLESEED_OVERRIDE;

  private:
    const std::string           m_filename;
    BufferedFile                m_file;
    LZ4CompressedWriterAdapter  m_writer;

    void write_signature();
    void write_version();

    void write_string(const char* s);
    void write_mesh(const IMeshWalker& walker);
    void write_vertices(const IMeshWalker& walker);
    void write_vertex_normals(const IMeshWalker& walker);
    void write_texture_coordinates(const IMeshWalker& walker);
    void write_material_slots(const IMeshWalker& walker);
    void write_faces(const IMeshWalker& walker);
    void write_face(const IMeshWalker& walker, const size_t face_index);
};

}       // namespace foundation

#endif  // !APPLESEED_FOUNDATION_MESH_BINARYMESHFILEWRITER_H
