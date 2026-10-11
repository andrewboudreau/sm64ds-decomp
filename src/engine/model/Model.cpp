//cpp
/* Model -- the concrete model class; the cartridge calls it dExtSimpleModel_c
   (_ZTI17dExtSimpleModel_c at 0x0208e794, _ZTV5Model at 0x0208e90c). TU claims
   0x02016abc..0x02016fd4: the home run in delinks order (Render, Virtual10,
   DoSetFile, UpdateVerts, then the full lifecycle D2,D0,D1,C1,C2) plus the
   forward stretch in delinks order (CleanCommonModelDataArr, func_02016e70,
   AddToCommonModelDataArr, LoadAndSetFileEtii) -- every emitted variant has a
   cartridge home, so nothing deadstrips -- grown downward to SetPolygonID,
   func_02016acc and func_02016b24, the member and the two free helpers
   bracketing it that DoSetFile calls.
   Written back-to-front: mwccarm emits .text in reverse source order under
   default deferred codegen.
   Below 0x02016abc stays put: func_02016aac is walled, its single-argument
   call cannot spell the three-parameter func_0204605c it targets without
   changing bytes; rematching that helper is separate work. */

/* common.h comes first so this TU sees the flat Matrix4x3 { s32 m[12]; }
   spelling: the ctor's mat4x3 = IDENTITY_MATRIX4X3 copy block-moves twelve
   words under it, where the structured Matrix3x3+Vector3 spelling
   scalarizes and lands +0x1c bytes long. */
#include "common.h"
#include "Model.h"

/* The cartridge homes this class's RTTI under the dExtSimpleModel_c spelling, so
   _ZTS5Model/_ZTI5Model records emitted under the project spelling would
   have no configured home. Compiling with RTTI off emits no records at
   all; the vtable preamble's typeinfo word deadstrips with the rest of the
   data sections. */
#pragma RTTI off

extern Matrix4x3 IDENTITY_MATRIX4X3;
extern "C" {
extern Matrix4x3 data_0209b3ec;      /* local extern: the camera-space matrix Render uses */
/* local extern: no header declares it */
void MulMat4x3Mat4x3(const Matrix4x3 *m1, const Matrix4x3 *m0, Matrix4x3 *mF);
/* local extern: no header declares it; data.transforms-bone walk in Virtual10 */
void func_02045074(ModelComponents *data, BMD_Bone *bones);
/* local extern: no header declares it; sizes the transforms buffer from the file */
u32 func_02046564(BMD_File *file);
/* local extern: decl_common.h's copy is the same mangled spelling; no
   namespace-Memory header declares operator_new2 */
void *_ZN6Memory13operator_new2Ej(u32 size);
/* local extern: no header declares it; initializes ModelComponents over the file */
void func_020462d0(ModelComponents *data, BMD_File *file, void *buffer);
/* local extern: no header declares it; SetPolygonID below passes ModelComponents */
void func_02046008(ModelComponents *data, int id);
/* struct Obj is defined at func_02016b24's address position below; the
   forward declaration lets DoSetFile call it with its true signature */
struct Obj;
/* local extern: no header declares it; defined at its address position below */
void func_02016b24(Obj *o, u32 mask);
/* local extern: no header declares it; delete veneer for the transforms buffer */
void func_0203cbc0(void *ptr);
/* local extern: Heap.h declares this spelling; this TU keeps its own copy so the
   absorbed bodies below need no new include */
void _ZN6Memory16operator_delete2EPv(void *ptr);
void *_Znwj(unsigned int sz);
int func_02016ff4(void *self, BMD_File *file, int a, int b);
int LoadFile(int ov0ID);
extern int data_0209cef8[];
extern int data_0209cefc[];
extern int data_0209cef0;
extern int data_0208e738;
struct CommonModelDataEntry {
    void *unk0;
    void *unk4;
    void *unk8;
};
}

/* 0xc-byte records in the common model data array at data_0209cefc,
   counted by data_0209cef8. */
struct CommonModelData {
    BMD_File *file;
    int unk_04;
    int unk_08;
};

typedef struct Entry { int pad; void *data; void *buf; } Entry;

// @symbol _ZN5Model14LoadAndSetFileEtii
void Model::LoadAndSetFile(u16 ov0ID, int a, int b)
{
    BMD_File *file = (BMD_File *)::LoadFile(ov0ID);
    modelFile = file;
    func_02016ff4(this, file, a, b);
}

// @symbol _ZN5Model23AddToCommonModelDataArrER8BMD_File
void *Model::AddToCommonModelDataArr(BMD_File &file)
{
    CommonModelData *p = (CommonModelData *)data_0209cefc;
    int i = 0;
    int n = data_0209cef8[0];
    while (i < n) {
        if (&file == p->file) return p;
        i++;
        p++;
    }
    p->file = &file;
    p->unk_04 = 0;
    p->unk_08 = 0;
    data_0209cef8[0] = data_0209cef8[0] + 1;
    if (data_0208e738 == 0) return p;
    LoadTexAndPal(file);
    return p;
}

// @symbol func_02016e70
extern "C" void *func_02016e70(void *file)
{
    Entry *e;
    void *b;

    e = (Entry *)Model::AddToCommonModelDataArr(*(BMD_File *)file);
    if (e->data == 0) {
        e->data = _Znwj(0x14);
        if (e->data == 0) return 0;
        e->buf = _ZN6Memory13operator_new2Ej(func_02046564((BMD_File *)file));
        b = e->buf;
        if (b == 0) {
            _ZN6Memory16operator_delete2EPv(e->data);
            e->data = 0;
            return 0;
        }
        func_020462d0((ModelComponents *)e->data, (BMD_File *)file, b);
    }
    return e->data;
}

/* Frees every entry of the global data_0209cefc, then resets the
   count and a related global to zero. The ROM calls the delete veneer at
   0x0203cbc0 for unk8 (relocs.txt), not the global _ZdlPv the unenrolled
   shard named. */
// @symbol CleanCommonModelDataArr
extern "C" void CleanCommonModelDataArr(void)
{
    struct CommonModelDataEntry *e = (struct CommonModelDataEntry *)&data_0209cefc[0];
    int i = 0;

    if (data_0209cef8[0] > 0) {
        do {
            if (e->unk8)
                func_0203cbc0(e->unk8);
            if (e->unk4)
                _ZN6Memory16operator_delete2EPv(e->unk4);
            i++;
            e++;
        } while (i < data_0209cef8[0]);
    }

    data_0209cef8[0] = 0;
    data_0209cef0 = 0;
}

/* One definition emits C1 and C2: the base-chain call to ModelBase::C2, the
   _ZTV5Model vptr store, the flat twelve-word identity copy, and the
   transformsBuf zero. The cartridge keeps both variants. */
// @symbol _ZN5ModelC2Ev
// @symbol _ZN5ModelC1Ev
Model::Model() : transformsBuf(0)
{
    mat4x3 = IDENTITY_MATRIX4X3;
}

/* One definition emits D2, D0 and D1: the vptr store and the ModelBase
   destructor call are the compiler's; the body is the class's one written
   obligation -- handing transformsBuf back through the delete veneer. D0
   follows with the ModelBase operator delete (Memory::operator_delete2). */
// @symbol _ZN5ModelD1Ev
Model::~Model()
{
    if (transformsBuf)
        func_0203cbc0(transformsBuf);
}

// @symbol _ZN5Model11UpdateVertsEv
void Model::UpdateVerts()
{
    data.UpdateVertsUsingBones();
}

// @symbol _ZN5Model9DoSetFileEPcii
int Model::DoSetFile(char *file_, int a, int b)
{
    BMD_File *file = (BMD_File *)file_;
    void *buffer;
    AddToCommonModelDataArr(*file);
    transformsBuf = _ZN6Memory13operator_new2Ej(func_02046564(file));
    buffer = transformsBuf;
    if (buffer == 0) return 0;
    func_020462d0(&data, file, buffer);
    data.UpdateVertsUsingBones();
    if (a != 0) func_02016b24((Obj *)this, 0x8000);
    if (b < 0) return 1;
    SetPolygonID(b & 0xff);
    return 1;
}

// @symbol _ZN5Model9Virtual10ER9Matrix4x3
void Model::Virtual10(Matrix4x3 &mat)
{
    /* The copy is one flat 12-word ldm/stm run in the ROM. CW copies the
       nested Matrix4x3 (Matrix3x3 + Vector3) memberwise, which is bigger,
       so it goes through a flat 12-word view instead. */
    struct Mtx12w { Fix12i m[12]; };
    *(Mtx12w *)data.transforms = *(const Mtx12w *)&mat;
    func_02045074(&data, data.modelFile->bones);
}

// @symbol _ZN5Model6RenderEPK7Vector3
void Model::Render(const Vector3 *scale)
{
    Matrix4x3 temp;
    MulMat4x3Mat4x3(&mat4x3, &data_0209b3ec, &temp);
    data.Render(&temp, (Vector3 *)scale);
}

/* Material-flag setter DoSetFile calls: ORs the mask into every entry's
   word at +0x24, walking 0x30-byte records. Body verbatim from the
   one-function shard; types.h comes from common.h above. */
// @symbol func_02016b24
struct Obj {
    char pad[8];
    char* p8;
    char* pc;
};

extern "C" void func_02016b24(struct Obj* o, u32 mask)
{
    u32 count = *(u32*)(o->p8 + 0x24);
    char* p = o->pc;
    u32 i;
    for (i = 0; i < count; i++) {
        *(u32*)(((int)p + 0x24)) |= mask;
        p += 0x30;
    }
}

/* Material-flag clearer, the mirror image: ANDs the inverted mask into the
   same word of the same records. Body verbatim from the one-function shard. */
// @symbol func_02016acc
extern "C" void func_02016acc(char *a0, unsigned int mask)
{
    char *p = *(char **)(a0 + 8);
    unsigned int n = *(unsigned int *)(p + 0x24);
    char *q = *(char **)(a0 + 0xc);

    for (unsigned int i = 0; i < n; i++) {
        unsigned int nmask = ~mask;
        *(unsigned int *)(q + 0x24) &= nmask;
        q += 0x30;
    }
}

// @symbol _ZN5Model12SetPolygonIDEi
void Model::SetPolygonID(int id)
{
    func_02046008(&data, id);
}
