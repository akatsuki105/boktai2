#include "global.h"

// リンクされる場所的に、GBAの公式ライブラリの可能性もある

void Rfu_CopyBytes(u8* src, u8* dst, u8 bytesize);

void FUN_0824c0c4(u8 pid, u8* dst);
u8 Rfu_GetRecordLength(u8* p);
u16 Rfu_GetRecordID(u8* p);
void Rfu_UnpackPartnerInfo(u8* buf, u8 slot);

// シリアル番号が一致する接続相手のゲーム名領域から、指定IDのデータを探して取り出す
s8 Rfu_FindPartnerRecord(u16 id, u8* dst, u8* buf, u8 flags) {
  u8 name[20];
  u16 serial0 = 0xFFFF;
  u16 serial1 = 0xFFFF;
  u16 serial2 = 0xFFFF;
  u8 i;

  if (flags & 1) serial0 = 0x7F7E;
  if (flags & 2) serial1 = 0x7F7C;
  if (flags & 4) serial2 = 0x7F7A;

  if (flags <= 7) {
    for (i = 0; i < gRfuLinkStatus->findParentCount; i++) {
      u16 serial = gRfuLinkStatus->partner[i].serialNo;
      if (serial == serial0 || serial == serial1 || serial == serial2) {
        u8 pos;
        u8* p;
        Rfu_UnpackPartnerInfo(buf, i);
        FUN_0824c0c4(i, name);
        for (pos = 0; pos <= 15; pos += Rfu_GetRecordLength(p) + 2) {
          p = &name[pos];
          if (id == Rfu_GetRecordID(p)) {
            u8 len = Rfu_GetRecordLength(p + 1);
            pos += 2;
            if (len == 7) len = 17 - pos;
            Rfu_CopyBytes(&name[pos], dst, len);
            return len;
          }
          p++;
          if (Rfu_GetRecordLength(p) == 7) break;
        }
        return -2;
      }
    }
  }
  return -1;
}

// Unused?
// 条件に合う接続相手に指定 ID のレコードがあれば、相手の id を *partnerid に書き出し、-3（slot == 0xFF のとき）か -4 を返す。レコードが無ければ -2、相手が見つからなければ -1 を返す
NON_MATCH s32 Rfu_FindPartnerByRecord(u16 id, u8 flags, u16* partnerid) {
#ifdef NONMATCHING_C
  u8 name[20];
  u16 serial0 = 0xFFFF;
  u16 serial1 = 0xFFFF;
  u16 serial2 = 0xFFFF;
  u8 i;

  if (flags & 1) serial0 = 0x7F7E;
  if (flags & 2) serial1 = 0x7F7C;
  if (flags & 4) serial2 = 0x7F7A;

  if (flags <= 7) {
    for (i = 0; i < gRfuLinkStatus->findParentCount; i++) {
      u16 serial = gRfuLinkStatus->partner[i].serialNo;
      if (serial == serial0 || serial == serial1 || serial == serial2) {
        s32 ret;
        u8 pos;
        u8* p;
        FUN_0824c0c4(i, name);
        if (gRfuLinkStatus->partner[i].slot == 0xFF) {
          *partnerid = gRfuLinkStatus->partner[i].id;
          ret = -3;
        } else {
          *partnerid = gRfuLinkStatus->partner[i].id;
          ret = -4;
        }
        pos = 0;
        do {
          p = &name[pos];
          if (id == Rfu_GetRecordID(p)) return ret;
          p++;
          if (Rfu_GetRecordLength(p) == 7) break;
          pos += Rfu_GetRecordLength(p) + 2;
        } while (pos <= 15);
        return -2;
      }
    }
  }
  return -1;
#else
  INCFUNC("asm/func/Rfu_FindPartnerByRecord.inc");
#endif
}

void FUN_0824c0c4(u8 pid, u8* dst) {
  Rfu_CopyBytes(gRfuLinkStatus->partner[pid].gname, dst, 13);
  Rfu_CopyBytes(gRfuLinkStatus->partner[pid].uname, dst + 13, 4);
}

void Rfu_CopyBytes(u8* src, u8* dst, u8 bytesize) {
  u8 i;
  for (i = 0; i < bytesize; i++) {
    dst[i] = src[i];
  }
}

u8 Rfu_GetRecordLength(u8* p) { return (*p) >> 5; }

u16 Rfu_GetRecordID(u8* p) { return ((p[1] & 0x1F) << 8) | p[0]; }

void Rfu_UnpackPartnerInfo(u8* buf, u8 slot) {
  u8 tmp[4];
  Rfu_CopyBytes(&gRfuLinkStatus->partner[slot].uname[4], tmp, 4);
  buf[0] = (tmp[3] >> 5) + 3;
  buf[1] = (tmp[3] >> 1) & 0xF;
  buf[2] = ((tmp[3] & 1) << 4) | (tmp[2] >> 4);
  buf[3] = ((tmp[2] & 0xF) << 1) | (tmp[1] >> 7);
  buf[4] = (tmp[1] >> 1) & 0x3F;
  buf[5] = ((tmp[1] & 1) << 5) | (tmp[0] >> 3);
  buf[6] = tmp[0] & 7;
}
