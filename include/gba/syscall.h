#ifndef GUARD_GBA_SYSCALL_H
#define GUARD_GBA_SYSCALL_H

typedef u32 ResetFlags;
#define RESET_EWRAM 0x01
#define RESET_IWRAM 0x02
#define RESET_PALETTE 0x04
#define RESET_VRAM 0x08
#define RESET_OAM 0x10
#define RESET_ALL_RAM 0x1F
#define RESET_SIO_REGS 0x20    // RESET_REGS には含まれない
#define RESET_SOUND_REGS 0x40  // RESET_REGS には含まれない
#define RESET_REGS 0x80        // RESET_SIO_REGS と RESET_SOUND_REGS 以外のレジスタ
#define RESET_ALL 0xFF

// flags で指定したレジスタとRAMをリセットする, ただし IWRAM の 0x03007E00..0x03007FFF の領域はクリアしない
void RegisterRamReset(ResetFlags flags);

// flags で指定したレジスタとRAMをリセットし、EWRAMの先頭アドレス(0x02000000)へ復帰する
void SoftResetExram(ResetFlags flags);

// Vブランク割り込みが発生するまでHalt状態で待ち続ける
void VBlankIntrWait(void);

// 平方根を算出, 精度を良くするために引数Xを2の倍数だけ左シフトして渡し、戻り値もシフトして桁合わせを行なうことを推奨
u16 Sqrt(u32 X);

/**
 * @brief 逆正接値を算出
 * @param Tan 固定小数点数形式 (符号:1, 整数部:1, 小数部:14)
 * @return -π/2 < θ < π/2 を 0xC000..0x4000 の範囲で返す
 */
s16 ArcTan(s16 Tan);

/**
 * @brief 補正処理後の逆正接値を算出, 通常はこちらを使用
 * @param X 固定小数点数形式のX座標 (符号:1, 整数部:1, 小数部:14)
 * @param Y 固定小数点数形式のY座標 (符号:1, 整数部:1, 小数部:14)
 * @return 0 ≦ θ < 2π を 0..0xFFFF の範囲で返す
 */
u16 ArcTan2(s16 X, s16 Y);

// 符号付き割り算 (Div と DivArm はそれぞれ異なるライブラリに対応させるためのもので処理は同じ)
s32 Div(s32 numer, s32 denom);     // RedHat社（旧Cygnus社）ライブラリ対応
s32 DivArm(s32 denom, s32 numer);  // ARM社ライブラリ対応

// 符号付き剰余 (Mod と ModArm はそれぞれ異なるライブラリに対応させるためのもので処理は同じ)
s32 Mod(s32 a, s32 b);     // RedHat社（旧Cygnus社）ライブラリ対応
s32 ModArm(s32 b, s32 a);  // ARM社ライブラリ対応

#define CPU_SET_SRC_FIXED 0x01000000
#define CPU_SET_16BIT 0x00000000
#define CPU_SET_32BIT 0x04000000

// 直接書かずに macro.h のマクロを使うこと
void CpuSet(const void* src, void* dest, u32 control);

#define CPU_FAST_SET_SRC_FIXED 0x01000000

// 直接書かずに macro.h のマクロを使うこと
void CpuFastSet(const void* src, void* dest, u32 control);

void BgAffineSet(struct BgAffineSrcData* src, struct BgAffineDstData* dest, s32 count);

void ObjAffineSet(struct ObjAffineSrcData* src, void* dest, s32 count, s32 offset);

/**
 * @brief LZ77形式で圧縮されたデータをWRAMに展開する
 * @param src 圧縮されたデータの先頭アドレス
 * @param dest 展開先のWRAMの先頭アドレス
 */
void LZ77UnCompWram(const void* src, void* dest);

void SoundBias_0(void);
void SoundBias_200(void);

#endif  // GUARD_GBA_SYSCALL_H
