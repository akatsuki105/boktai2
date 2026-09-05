	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0823cd04
FUN_0823cd04: @ 0x0823CD04
	ldr r0, _0823CD20 @ =0x030047A4
	movs r1, #0
	str r1, [r0]
	ldr r0, _0823CD24 @ =0x030047A0
	str r1, [r0]
	ldr r0, _0823CD28 @ =0x0300479C
	str r1, [r0]
	ldr r0, _0823CD2C @ =0x030047C0
	str r1, [r0]
	ldr r0, _0823CD30 @ =0x0300478C
	str r1, [r0]
	ldr r0, _0823CD34 @ =0x030047C4
	str r1, [r0]
	bx lr
	.align 2, 0
_0823CD20: .4byte 0x030047A4
_0823CD24: .4byte 0x030047A0
_0823CD28: .4byte 0x0300479C
_0823CD2C: .4byte 0x030047C0
_0823CD30: .4byte 0x0300478C
_0823CD34: .4byte 0x030047C4

	thumb_func_start FUN_0823cd38
FUN_0823cd38: @ 0x0823CD38
	ldr r0, _0823CD44 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r0, r1
	bx lr
	.align 2, 0
_0823CD44: .4byte 0x030046A0

	thumb_func_start FUN_0823cd48
FUN_0823cd48: @ 0x0823CD48
	push {r4, lr}
	sub sp, #4
	bl FUN_0823cd38
	adds r4, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r2, _0823CD98 @ =0x05000004
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0823CD9C
	bl VM_GetPC
	bl VM_GetValueAtSafe_Proxy
	adds r1, r0, #0
	cmp r1, #0
	beq _0823CDB6
	movs r3, #0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0823CDB6
	adds r2, r1, #0
_0823CD82:
	adds r0, r4, r3
	ldrb r1, [r2]
	strb r1, [r0]
	adds r2, #1
	adds r3, #1
	ldrb r0, [r2]
	cmp r0, #0
	beq _0823CDB6
	cmp r3, #0xf
	ble _0823CD82
	b _0823CDB6
	.align 2, 0
_0823CD98: .4byte 0x05000004
_0823CD9C:
	movs r1, #0x80
	strb r1, [r4]
	movs r0, #0xa2
	strb r0, [r4, #1]
	strb r1, [r4, #2]
	movs r0, #0x98
	strb r0, [r4, #3]
	strb r1, [r4, #4]
	movs r0, #0x91
	strb r0, [r4, #5]
	strb r1, [r4, #6]
	movs r0, #0x9f
	strb r0, [r4, #7]
_0823CDB6:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823cdc0
FUN_0823cdc0: @ 0x0823CDC0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
_0823CDC6:
	cmp r2, r3
	bge _0823CDE0
	adds r0, r2, r3
	asrs r1, r0, #1
	lsls r0, r1, #2
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, r5
	bhs _0823CDDC
	adds r2, r1, #1
	b _0823CDC6
_0823CDDC:
	adds r3, r1, #0
	b _0823CDC6
_0823CDE0:
	lsls r0, r2, #2
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, r5
	beq _0823CDEE
	movs r0, #0
	b _0823CDF0
_0823CDEE:
	ldrh r0, [r1, #2]
_0823CDF0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823cdf8
FUN_0823cdf8: @ 0x0823CDF8
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0823CE0C @ =0x08DBD83C
	movs r2, #0
	movs r3, #0xaa
	bl FUN_0823cdc0
	pop {r1}
	bx r1
	.align 2, 0
_0823CE0C: .4byte 0x08DBD83C

	thumb_func_start FUN_0823ce10
FUN_0823ce10: @ 0x0823CE10
	push {r4, lr}
	ldr r3, _0823CE34 @ =0x08DBD798
	ldr r4, _0823CE38 @ =gClock
	ldrb r2, [r4, #0xe]
	lsls r2, r2, #1
	adds r2, r2, r3
	ldrb r2, [r2]
	strh r2, [r0]
	ldrb r0, [r4, #0xe]
	lsls r0, r0, #1
	adds r3, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	strh r0, [r1]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0823CE34: .4byte 0x08DBD798
_0823CE38: .4byte gClock

	thumb_func_start FUN_0823ce3c
FUN_0823ce3c: @ 0x0823CE3C
	push {r4, lr}
	ldr r3, _0823CE60 @ =0x08DBD798
	ldr r4, _0823CE64 @ =gClock
	ldrb r2, [r4, #0xe]
	lsls r2, r2, #1
	adds r2, r2, r3
	ldrb r2, [r2]
	strh r2, [r0]
	ldrb r0, [r4, #0xe]
	lsls r0, r0, #1
	adds r3, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823CE60: .4byte 0x08DBD798
_0823CE64: .4byte gClock

	thumb_func_start FUN_0823ce68
FUN_0823ce68: @ 0x0823CE68
	push {r4, r5, lr}
	sub sp, #0x14
	adds r5, r1, #0
	cmp r0, #1
	beq _0823CE98
	cmp r0, #1
	bgt _0823CE7C
	cmp r0, #0
	beq _0823CE86
	b _0823CE98
_0823CE7C:
	cmp r0, #2
	beq _0823CE8C
	cmp r0, #3
	beq _0823CE92
	b _0823CE98
_0823CE86:
	movs r1, #2
	movs r4, #1
	b _0823CE9C
_0823CE8C:
	movs r1, #4
	movs r4, #3
	b _0823CE9C
_0823CE92:
	movs r1, #5
	movs r4, #4
	b _0823CE9C
_0823CE98:
	movs r1, #3
	movs r4, #2
_0823CE9C:
	str r5, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0x10]
	adds r0, r1, #0
	movs r1, #5
	mov r2, sp
	bl FUN_0800205c
	ldr r0, [sp, #0x28]
	str r0, [sp, #0x10]
	adds r0, r4, #0
	movs r1, #5
	mov r2, sp
	bl FUN_08002800
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823cecc
FUN_0823cecc: @ 0x0823CECC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r4, _0823CF18 @ =0xFFFF0000
	lsrs r0, r0, #0x10
	str r0, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0823CF14
	cmp r1, #0
	blt _0823CF14
	ldr r0, _0823CF1C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0823CF14
	ldr r0, _0823CF20 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0823CF24
_0823CF14:
	movs r4, #0
	b _0823CF32
	.align 2, 0
_0823CF18: .4byte 0xFFFF0000
_0823CF1C: .4byte 0x030046A8
_0823CF20: .4byte 0x030046AC
_0823CF24:
	ldr r0, _0823CF44 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0823CF32:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823CF48
	adds r0, #4
	b _0823CF54
	.align 2, 0
_0823CF44: .4byte 0x030046A4
_0823CF48:
	ldr r0, _0823CF68 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0823CF54:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r5, r0, #8
	cmp r2, #1
	beq _0823CF6C
	cmp r2, #2
	beq _0823CF70
	b _0823CF74
	.align 2, 0
_0823CF68: .4byte 0x030046A4
_0823CF6C:
	ldrb r0, [r6, #4]
	b _0823CF72
_0823CF70:
	ldrb r0, [r6]
_0823CF72:
	subs r5, r5, r0
_0823CF74:
	add r4, sp, #8
	adds r0, r4, #0
	bl FUN_0823167c
	adds r0, r4, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0823206c
	adds r0, r5, #0
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823cf90
FUN_0823cf90: @ 0x0823CF90
	push {r4, r5, lr}
	sub sp, #0x10
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r4, _0823CFDC @ =0xFFFF0000
	lsrs r0, r0, #0x10
	str r0, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r2, sp
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _0823CFD8
	cmp r1, #0
	blt _0823CFD8
	ldr r0, _0823CFE0 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _0823CFD8
	ldr r0, _0823CFE4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0823CFE8
_0823CFD8:
	movs r4, #0
	b _0823CFF6
	.align 2, 0
_0823CFDC: .4byte 0xFFFF0000
_0823CFE0: .4byte 0x030046A8
_0823CFE4: .4byte 0x030046AC
_0823CFE8:
	ldr r0, _0823D008 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_0823CFF6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823D00C
	adds r0, #4
	b _0823D018
	.align 2, 0
_0823D008: .4byte 0x030046A4
_0823D00C:
	ldr r0, _0823D038 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0823D018:
	ldrb r4, [r0]
	lsrs r4, r4, #4
	add r5, sp, #8
	adds r0, r5, #0
	bl FUN_0823167c
	adds r0, r5, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823206c
	adds r0, r4, #0
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0823D038: .4byte 0x030046A4

	thumb_func_start FUN_0823d03c
FUN_0823d03c: @ 0x0823D03C
	push {r4, r5, lr}
	sub sp, #0x10
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r4, _0823D088 @ =0xFFFF0000
	lsrs r0, r0, #0x10
	str r0, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r2, sp
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _0823D084
	cmp r1, #0
	blt _0823D084
	ldr r0, _0823D08C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _0823D084
	ldr r0, _0823D090 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0823D094
_0823D084:
	movs r4, #0
	b _0823D0A2
	.align 2, 0
_0823D088: .4byte 0xFFFF0000
_0823D08C: .4byte 0x030046A8
_0823D090: .4byte 0x030046AC
_0823D094:
	ldr r0, _0823D0B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_0823D0A2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823D0B8
	adds r0, #4
	b _0823D0C4
	.align 2, 0
_0823D0B4: .4byte 0x030046A4
_0823D0B8:
	ldr r0, _0823D0E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0823D0C4:
	ldrh r5, [r0, #2]
	add r4, sp, #8
	adds r0, r4, #0
	bl FUN_0823167c
	adds r0, r4, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0823206c
	adds r0, r5, #0
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0823D0E4: .4byte 0x030046A4

	thumb_func_start FUN_0823d0e8
FUN_0823d0e8: @ 0x0823D0E8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	bl Script_GetValue
	adds r6, r0, #0
	ldr r7, _0823D118 @ =0x030046A4
	ldr r0, [r7]
	ldr r5, [r0, #4]
	cmp r5, #0
	beq _0823D1CE
	movs r0, #4
	ldrsh r1, [r5, r0]
	movs r2, #6
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r6, r0
	blt _0823D120
	ldr r1, _0823D11C @ =0xFFFF0000
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
	b _0823D192
	.align 2, 0
_0823D118: .4byte 0x030046A4
_0823D11C: .4byte 0xFFFF0000
_0823D120:
	adds r0, r6, #0
	bl Mod
	lsls r0, r0, #8
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0823D164 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	movs r0, #4
	ldrsh r1, [r5, r0]
	adds r0, r6, #0
	bl Div
	lsls r0, r0, #8
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	mov r4, sp
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823D168
	adds r0, #4
	b _0823D172
	.align 2, 0
_0823D164: .4byte 0xFFFF0000
_0823D168:
	ldr r0, [r7]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0823D172:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0823D186
	cmp r2, #2
	beq _0823D18A
	b _0823D18E
_0823D186:
	ldrb r0, [r4, #4]
	b _0823D18C
_0823D18A:
	ldrb r0, [r4]
_0823D18C:
	subs r1, r1, r0
_0823D18E:
	mov r0, sp
	strh r1, [r0, #2]
_0823D192:
	add r4, sp, #8
	adds r0, r4, #0
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	mov r5, sp
	movs r0, #2
	ldrsh r2, [r5, r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	movs r1, #4
	ldrsh r2, [r5, r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
_0823D1CE:
	movs r0, #0
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823d1d8
FUN_0823d1d8: @ 0x0823D1D8
	push {lr}
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x11
	lsls r1, r0
	lsrs r1, r1, #0x10
	ldr r2, _0823D1F8 @ =0x03003E78
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0823D1F8: .4byte 0x03003E78

	thumb_func_start FUN_0823d1fc
FUN_0823d1fc: @ 0x0823D1FC
	push {lr}
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x11
	lsls r1, r0
	lsrs r1, r1, #0x10
	ldr r2, _0823D21C @ =0x03003E78
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0823D21C: .4byte 0x03003E78

	thumb_func_start FUN_0823d220
FUN_0823d220: @ 0x0823D220
	push {lr}
	bl SoftReset_0823a928
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823d22c
FUN_0823d22c: @ 0x0823D22C
	push {r4, r5, lr}
	movs r4, #0x80
	lsls r4, r4, #0x13
	ldrh r0, [r4]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r4]
	bl WaitForVBlank
	bl WaitForVBlank
	ldr r5, _0823D270 @ =0x04000132
	ldr r1, _0823D274 @ =0x0000C304
	adds r0, r1, #0
	strh r0, [r5]
	bl SoundBias_0
	svc #3
	bl SoundBias_200
	ldr r1, _0823D278 @ =0x030047B4
	movs r0, #1
	str r0, [r1]
	ldrh r1, [r4]
	ldr r0, _0823D27C @ =0x0000FF7F
	ands r0, r1
	strh r0, [r4]
	movs r0, #0
	strh r0, [r5]
	bl WaitForVBlank
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823D270: .4byte 0x04000132
_0823D274: .4byte 0x0000C304
_0823D278: .4byte 0x030047B4
_0823D27C: .4byte 0x0000FF7F

	thumb_func_start FUN_0823d280
FUN_0823d280: @ 0x0823D280
	push {r4, lr}
	ldr r4, _0823D2B4 @ =gSystemSaveData
	ldr r0, [r4]
	cmp r0, #0
	beq _0823D2AE
	bl FUN_082410e8
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0823D2AE
	movs r1, #5
	ldr r0, _0823D2B8 @ =0x030046A0
	ldr r0, [r0]
	strh r1, [r0, #0x12]
	movs r1, #0xe6
	ldr r0, [r4]
	str r1, [r0, #4]
	strb r2, [r0, #8]
	ldr r0, [r4]
	strb r2, [r0, #9]
	ldr r0, [r4]
	strb r2, [r0, #0xa]
_0823D2AE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823D2B4: .4byte gSystemSaveData
_0823D2B8: .4byte 0x030046A0

	thumb_func_start FUN_0823d2bc
FUN_0823d2bc: @ 0x0823D2BC
	push {lr}
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, _0823D2D0 @ =0x0300446C
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0823D2D0: .4byte 0x0300446C

	thumb_func_start FUN_0823d2d4
FUN_0823d2d4: @ 0x0823D2D4
	ldr r1, _0823D2DC @ =0x0300446C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0823D2DC: .4byte 0x0300446C

	thumb_func_start FUN_0823d2e0
FUN_0823d2e0: @ 0x0823D2E0
	push {lr}
	ldr r1, _0823D304 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldr r1, _0823D308 @ =0x00000948
	adds r2, r0, r1
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _0823D30C @ =0x0000270E
	cmp r1, r0
	bgt _0823D2FE
	adds r0, r3, #1
	strh r0, [r2]
_0823D2FE:
	pop {r0}
	bx r0
	.align 2, 0
_0823D304: .4byte 0x030046A0
_0823D308: .4byte 0x00000948
_0823D30C: .4byte 0x0000270E

	thumb_func_start FUN_0823d310
FUN_0823d310: @ 0x0823D310
	push {lr}
	ldr r1, _0823D334 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0x95
	lsls r1, r1, #4
	adds r2, r0, r1
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _0823D338 @ =0x0000270E
	cmp r1, r0
	bgt _0823D330
	adds r0, r3, #1
	strh r0, [r2]
_0823D330:
	pop {r0}
	bx r0
	.align 2, 0
_0823D334: .4byte 0x030046A0
_0823D338: .4byte 0x0000270E

	thumb_func_start FUN_0823d33c
FUN_0823d33c: @ 0x0823D33C
	bx lr
	.align 2, 0

	thumb_func_start FUN_0823d340
FUN_0823d340: @ 0x0823D340
	push {lr}
	bl VM_GetPC
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823d34c
FUN_0823d34c: @ 0x0823D34C
	push {lr}
	bl VM_GetValueSafe2
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823d358
FUN_0823d358: @ 0x0823D358
	push {lr}
	sub sp, #8
	mov r0, sp
	bl FUN_0823167c
	ldr r0, _0823D378 @ =gSystemSaveData
	ldr r0, [r0]
	ldr r2, [r0]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0823D378: .4byte gSystemSaveData

	thumb_func_start FUN_0823d37c
FUN_0823d37c: @ 0x0823D37C
	push {r4, r5, lr}
	sub sp, #8
	ldr r0, _0823D3E8 @ =gSystemSaveData
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, #0x3c
	bl Div
	adds r5, r0, #0
	movs r1, #0x3c
	bl Mod
	adds r0, r5, #0
	movs r1, #0x3c
	bl Div
	adds r5, r0, #0
	movs r1, #0x3c
	bl Mod
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #0x3c
	bl Div
	adds r5, r0, #0
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823206c
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823D3E8: .4byte gSystemSaveData

	thumb_func_start FUN_0823d3ec
FUN_0823d3ec: @ 0x0823D3EC
	movs r0, #1
	ldr r1, _0823D3F8 @ =gSystemSaveData
	ldr r1, [r1]
	strb r0, [r1, #9]
	bx lr
	.align 2, 0
_0823D3F8: .4byte gSystemSaveData

	thumb_func_start FUN_0823d3fc
FUN_0823d3fc: @ 0x0823D3FC
	ldr r0, _0823D404 @ =gSystemSaveData
	ldr r0, [r0]
	ldrb r0, [r0, #9]
	bx lr
	.align 2, 0
_0823D404: .4byte gSystemSaveData

	thumb_func_start FUN_0823d408
FUN_0823d408: @ 0x0823D408
	ldr r0, _0823D410 @ =gSystemSaveData
	ldr r0, [r0]
	ldrb r0, [r0, #0xa]
	bx lr
	.align 2, 0
_0823D410: .4byte gSystemSaveData

	thumb_func_start FUN_0823d414
FUN_0823d414: @ 0x0823D414
	adds r1, r0, #0
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0823D424 @ =gWeaponDB
	adds r0, r0, r1
	bx lr
	.align 2, 0
_0823D424: .4byte gWeaponDB

	thumb_func_start FUN_0823d428
FUN_0823d428: @ 0x0823D428
	push {r4, r5, lr}
	sub sp, #0x10
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #0xc]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	ldr r0, _0823D4A0 @ =0x0000C091
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r1, r4, #0
	bl GetFile
	adds r2, r0, #0
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	cmp r5, #0
	beq _0823D498
	ldr r0, _0823D4A4 @ =0x000092B3
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, _0823D4A8 @ =0x030043F0
	movs r2, #0x30
	bl CpuSet
_0823D498:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823D4A0: .4byte 0x0000C091
_0823D4A4: .4byte 0x000092B3
_0823D4A8: .4byte 0x030043F0

	thumb_func_start FUN_0823d4ac
FUN_0823d4ac: @ 0x0823D4AC
	push {lr}
	ldr r2, _0823D4C0 @ =gSentinel02020400
	ldr r0, [r2]
	ldr r1, _0823D4C4 @ =0x516B92EE
	cmp r0, r1
	beq _0823D4BA
	str r1, [r2]
_0823D4BA:
	pop {r0}
	bx r0
	.align 2, 0
_0823D4C0: .4byte gSentinel02020400
_0823D4C4: .4byte 0x516B92EE

	thumb_func_start FUN_0823d4c8
FUN_0823d4c8: @ 0x0823D4C8
	push {lr}
	ldr r0, _0823D4D8 @ =gSentinel02020400
	ldr r1, [r0]
	ldr r0, _0823D4DC @ =0x516B92EE
	cmp r1, r0
	beq _0823D4E0
	movs r0, #0
	b _0823D4E2
	.align 2, 0
_0823D4D8: .4byte gSentinel02020400
_0823D4DC: .4byte 0x516B92EE
_0823D4E0:
	movs r0, #1
_0823D4E2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823d4e8
FUN_0823d4e8: @ 0x0823D4E8
	push {r4, lr}
	ldr r2, _0823D54C @ =0x030046A0
	ldr r0, [r2]
	movs r4, #0xb6
	lsls r4, r4, #2
	adds r1, r0, r4
	ldr r0, [r1]
	cmp r0, #0
	bne _0823D4FE
	movs r0, #1
	str r0, [r1]
_0823D4FE:
	ldr r0, [r2]
	movs r3, #0xb7
	lsls r3, r3, #2
	adds r1, r0, r3
	ldr r0, [r1]
	cmp r0, #0
	bne _0823D510
	movs r0, #1
	str r0, [r1]
_0823D510:
	ldr r0, [r2]
	adds r1, r0, r3
	adds r0, r0, r4
	ldr r1, [r1]
	ldr r0, [r0]
	adds r1, r1, r0
	cmp r1, #0
	bne _0823D522
	movs r1, #1
_0823D522:
	lsls r0, r0, #7
	bl Div
	movs r1, #0
	cmp r0, #0x46
	bgt _0823D536
	movs r1, #1
	cmp r0, #0x3a
	ble _0823D536
	movs r1, #2
_0823D536:
	ldr r0, _0823D54C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	adds r0, r1, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0823D54C: .4byte 0x030046A0

	thumb_func_start UpdateWeaponStyle
UpdateWeaponStyle: @ 0x0823D550
	push {r4, r5, r6, lr}
	sub sp, #0x14
	movs r4, #0
	mov r6, sp
_0823D558:
	ldr r5, _0823D58C @ =0x030046A0
	ldr r1, [r5]
	lsls r0, r4, #2
	adds r0, r0, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0823D590 @ =0x0000D2F0
	bl Div
	stm r6!, {r0}
	adds r4, #1
	cmp r4, #4
	ble _0823D558
	movs r0, #0
	movs r1, #5
	movs r4, #0
	mov r3, sp
_0823D57E:
	ldr r2, [r3]
	cmp r2, r0
	ble _0823D594
	adds r0, r2, #0
	adds r1, r4, #0
	b _0823D59A
	.align 2, 0
_0823D58C: .4byte 0x030046A0
_0823D590: .4byte 0x0000D2F0
_0823D594:
	cmp r2, r0
	bne _0823D59A
	movs r1, #5
_0823D59A:
	adds r3, #4
	adds r4, #1
	cmp r4, #4
	ble _0823D57E
	ldr r0, [r5]
	ldr r2, _0823D5B4 @ =0x000002FA
	adds r0, r0, r2
	strh r1, [r0]
	adds r0, r1, #0
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0823D5B4: .4byte 0x000002FA

	thumb_func_start FUN_0823d5b8
FUN_0823d5b8: @ 0x0823D5B8
	push {r4, r5, lr}
	movs r4, #0
	movs r3, #0x64
	rsbs r3, r3, #0
	movs r2, #0
	ldr r0, _0823D5E8 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0823D5EC @ =0x000002FE
	adds r0, r0, r1
_0823D5CA:
	movs r5, #0
	ldrsh r1, [r0, r5]
	cmp r1, r3
	ble _0823D5D6
	adds r3, r1, #0
	adds r4, r2, #0
_0823D5D6:
	adds r0, #2
	adds r2, #1
	cmp r2, #4
	ble _0823D5CA
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0823D5E8: .4byte 0x030046A0
_0823D5EC: .4byte 0x000002FE

	thumb_func_start FUN_0823d5f0
FUN_0823d5f0: @ 0x0823D5F0
  .include "asm/func/FUN_0823d5f0.inc"

	thumb_func_start FUN_0823d680
FUN_0823d680: @ 0x0823D680
	ldr r0, _0823D688 @ =gSystemSaveData
	ldr r0, [r0]
	ldr r0, [r0, #0x20]
	bx lr
	.align 2, 0
_0823D688: .4byte gSystemSaveData

	thumb_func_start FUN_0823d68c
FUN_0823d68c: @ 0x0823D68C
	push {lr}
	ldr r0, _0823D6A0 @ =gSystemSaveData
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	ldr r0, _0823D6A4 @ =0x0000369F
	cmp r1, r0
	beq _0823D6A8
	movs r0, #0
	b _0823D6AA
	.align 2, 0
_0823D6A0: .4byte gSystemSaveData
_0823D6A4: .4byte 0x0000369F
_0823D6A8:
	movs r0, #1
_0823D6AA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823d6b0
FUN_0823d6b0: @ 0x0823D6B0
	ldr r0, _0823D6B8 @ =gSystemSaveData
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	bx lr
	.align 2, 0
_0823D6B8: .4byte gSystemSaveData

	thumb_func_start FUN_0823d6bc
FUN_0823d6bc: @ 0x0823D6BC
	push {lr}
	ldr r0, _0823D6D4 @ =gSystemSaveData
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	movs r0, #0x70
	bl VM_GetKeywordValue
	adds r1, r0, #0
	cmp r1, #0
	bge _0823D6D8
	movs r1, #0
	b _0823D6E0
	.align 2, 0
_0823D6D4: .4byte gSystemSaveData
_0823D6D8:
	ldr r0, _0823D6EC @ =0x0000270F
	cmp r1, r0
	ble _0823D6E0
	adds r1, r0, #0
_0823D6E0:
	ldr r0, _0823D6F0 @ =gSystemSaveData
	ldr r0, [r0]
	str r1, [r0, #0xc]
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_0823D6EC: .4byte 0x0000270F
_0823D6F0: .4byte gSystemSaveData

	thumb_func_start FUN_0823d6f4
FUN_0823d6f4: @ 0x0823D6F4
	ldr r0, _0823D6FC @ =gSystemSaveData
	ldr r0, [r0]
	ldrh r0, [r0, #0x14]
	bx lr
	.align 2, 0
_0823D6FC: .4byte gSystemSaveData

	thumb_func_start FUN_0823d700
FUN_0823d700: @ 0x0823D700
	ldr r0, _0823D708 @ =gSystemSaveData
	ldr r0, [r0]
	ldrh r0, [r0, #0x16]
	bx lr
	.align 2, 0
_0823D708: .4byte gSystemSaveData

	thumb_func_start FUN_0823d70c
FUN_0823d70c: @ 0x0823D70C
  .include "asm/func/FUN_0823d70c.inc"

	thumb_func_start FUN_0823d748
FUN_0823d748: @ 0x0823D748
  .include "asm/func/FUN_0823d748.inc"
