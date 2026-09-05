	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08009b04
FUN_08009b04: @ 0x08009B04
	ldr r1, _08009B0C @ =0x03000040
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08009B0C: .4byte 0x03000040

	thumb_func_start FUN_08009b10
FUN_08009b10: @ 0x08009B10
	push {lr}
	movs r2, #0
	adds r1, r0, #0
	adds r1, #0x2c
_08009B18:
	ldrb r0, [r1, #5]
	cmp r0, #0
	bne _08009B22
	adds r0, r1, #0
	b _08009B2C
_08009B22:
	adds r1, #0x9c
	adds r2, #1
	cmp r2, #0xf
	ble _08009B18
	movs r0, #0
_08009B2C:
	pop {r1}
	bx r1

	thumb_func_start FUN_08009b30
FUN_08009b30: @ 0x08009B30
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08009B64
	movs r0, #0xe0
	lsls r0, r0, #1
	ldr r3, [r3, #0x34]
	ands r3, r0
	cmp r3, #0
	bne _08009B64
	adds r1, r4, #0
	adds r1, #0x43
	movs r0, #1
	strb r0, [r1]
	strb r0, [r2, #2]
	strh r3, [r2, #0xa]
	strb r0, [r2, #7]
	ldrh r1, [r2, #0x1a]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #0x1a]
_08009B64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08009b6c
FUN_08009b6c: @ 0x08009B6C
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r2, _08009BF8 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x1e
	orrs r0, r3
	ldr r1, _08009BFC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0xa0
	lsls r0, r0, #0x10
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x14
	ldr r2, _08009C00 @ =0x00004020
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _08009C04 @ =FUN_08009b30
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	adds r4, #0x50
	ldr r1, [r6, #0x1c]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	ldr r1, [r6, #0x1c]
	adds r0, r4, #0
	movs r2, #0xc
	bl FUN_0822dafc
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	movs r1, #1
	strb r1, [r5, #5]
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08009BF8: .4byte 0xFFFF0000
_08009BFC: .4byte 0x0000FFFF
_08009C00: .4byte 0x00004020
_08009C04: .4byte FUN_08009b30

	thumb_func_start FUN_08009c08
FUN_08009c08: @ 0x08009C08
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x64
	bl FUN_0822dabc
	adds r0, r4, #0
	adds r0, #0x14
	bl FUN_08236424
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08009c28
FUN_08009c28: @ 0x08009C28
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08009C3E
	movs r0, #0
	strb r0, [r2, #7]
	ldr r0, [r2, #0x64]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x64]
_08009C3E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08009c44
FUN_08009c44: @ 0x08009C44
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r6, r1, #0
	ldrb r0, [r6, #7]
	cmp r0, #0
	beq _08009CA6
	movs r5, #0
	strb r5, [r6, #7]
	adds r4, r6, #0
	adds r4, #0x64
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r7, #0x20]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822dafc
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r1, [r7, #0x28]
	str r5, [sp]
	movs r2, #8
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r6, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x64]
	ldr r2, _08009D18 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08009D1C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08009D20 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x78
	strh r0, [r6, #0xc]
_08009CA6:
	ldr r0, [r6, #0x64]
	movs r2, #1
	mov ip, r2
	ands r0, r2
	cmp r0, #0
	beq _08009D24
	ldrh r0, [r6, #0xa]
	adds r1, r0, #1
	strh r1, [r6, #0xa]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r6, #0xc]
	cmp r0, r1
	bhi _08009CC4
	b _08009E20
_08009CC4:
	movs r5, #0
	strh r5, [r6, #0xa]
	ldr r2, _08009D18 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08009D1C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08009D20 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x78
	strh r0, [r6, #0xc]
	adds r4, r6, #0
	adds r4, #0x64
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r7, #0x20]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822dafc
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r1, [r7, #0x28]
	str r5, [sp]
	movs r2, #8
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r6, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _08009E1E
	.align 2, 0
_08009D18: .4byte 0x030046B8
_08009D1C: .4byte 0x000003FF
_08009D20: .4byte 0x0203B400
_08009D24:
	adds r5, r6, #0
	adds r5, #0x64
	ldr r3, [r7, #0x20]
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r5, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldrb r0, [r4, #4]
	mov r1, ip
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, ip
	ands r0, r2
	cmp r1, r0
	beq _08009D6A
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	b _08009D72
_08009D6A:
	ldr r0, [r6, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08009D72:
	str r0, [r6, #0x64]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08009D96
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08009D9E
_08009D96:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08009D9E:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08009DD8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08009E10
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08009DE2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08009DDC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08009DF8
	.align 2, 0
_08009DD8: .4byte 0x0000FFFF
_08009DDC:
	subs r0, #1
	strh r0, [r4, #8]
	b _08009DF6
_08009DE2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08009DF6
	strh r1, [r4, #8]
	movs r2, #1
	b _08009DF8
_08009DF6:
	movs r2, #0
_08009DF8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	b _08009E12
_08009E10:
	movs r2, #0
_08009E12:
	strb r2, [r6, #8]
	cmp r2, #0
	beq _08009E20
	ldr r0, [r6, #0x64]
	movs r1, #1
	orrs r0, r1
_08009E1E:
	str r0, [r6, #0x64]
_08009E20:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08009e28
FUN_08009e28: @ 0x08009E28
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08009E36
	movs r0, #0
	strb r0, [r2, #7]
_08009E36:
	ldrh r0, [r2, #0xa]
	adds r1, r0, #1
	strh r1, [r2, #0xa]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	bls _08009E50
	movs r0, #2
	movs r1, #0
	strb r0, [r2, #2]
	strh r1, [r2, #0xa]
	movs r0, #1
	strb r0, [r2, #7]
_08009E50:
	pop {r0}
	bx r0

	thumb_func_start FUN_08009e54
FUN_08009e54: @ 0x08009E54
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r7, r0, #0
	adds r6, r1, #0
	ldrb r0, [r6, #7]
	cmp r0, #0
	beq _08009EA2
	movs r5, #0
	strb r5, [r6, #7]
	ldr r0, [r6, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x64]
	adds r4, r6, #0
	adds r4, #0x64
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r7, #0x1c]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822dafc
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r1, [r7, #0x24]
	str r5, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	movs r0, #0x91
	lsls r0, r0, #1
	bl PlaySound_0824078c
_08009EA2:
	adds r0, r6, #0
	adds r0, #0x94
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #1
	bne _08009EC0
	adds r0, #6
	ldrh r0, [r0]
	cmp r0, #0
	bne _08009EC0
	adds r1, r6, #0
	adds r1, #0x7e
	ldrh r0, [r1]
	adds r0, #0x10
	strh r0, [r1]
_08009EC0:
	ldrh r0, [r2]
	cmp r0, #2
	bne _08009EDA
	adds r0, r6, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	cmp r0, #0
	bne _08009EDA
	adds r1, r6, #0
	adds r1, #0x7e
	ldrh r0, [r1]
	subs r0, #0x10
	strh r0, [r1]
_08009EDA:
	ldrh r0, [r2]
	cmp r0, #4
	bne _08009F46
	adds r0, r6, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	cmp r0, #0
	bne _08009F46
	ldr r3, _08009F38 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0xa
	orrs r0, r2
	ldr r1, _08009F3C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x10]
	ldrb r0, [r6, #4]
	ldrb r2, [r6, #3]
	movs r1, #0x10
	orrs r1, r2
	ldrh r2, [r6, #0xe]
	adds r3, r6, #0
	adds r3, #0x7c
	add r4, sp, #0xc
	str r4, [sp]
	ldrh r4, [r6, #0x10]
	str r4, [sp, #4]
	ldrh r4, [r6, #0x12]
	str r4, [sp, #8]
	bl FUN_0800a8e0
	ldrb r0, [r6, #3]
	cmp r0, #2
	bne _08009F40
	movs r0, #0xae
	lsls r0, r0, #2
	bl PlaySound_0824078c
	b _08009F46
	.align 2, 0
_08009F38: .4byte 0xFFFF0000
_08009F3C: .4byte 0x0000FFFF
_08009F40:
	ldr r0, _08009F8C @ =0x0000011D
	bl PlaySound_0824078c
_08009F46:
	adds r5, r6, #0
	adds r5, #0x64
	ldr r3, [r7, #0x1c]
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r5, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08009F90
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	b _08009F98
	.align 2, 0
_08009F8C: .4byte 0x0000011D
_08009F90:
	ldr r0, [r6, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08009F98:
	str r0, [r6, #0x64]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08009FBC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08009FC4
_08009FBC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08009FC4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08009FFC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0800A034
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800A006
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800A000
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0800A01C
	.align 2, 0
_08009FFC: .4byte 0x0000FFFF
_0800A000:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800A01A
_0800A006:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800A01A
	strh r1, [r4, #8]
	movs r2, #1
	b _0800A01C
_0800A01A:
	movs r2, #0
_0800A01C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	b _0800A036
_0800A034:
	movs r2, #0
_0800A036:
	strb r2, [r6, #8]
	cmp r2, #0
	beq _0800A046
	movs r1, #1
	strb r1, [r6, #6]
	ldr r0, [r6, #0x64]
	orrs r0, r1
	str r0, [r6, #0x64]
_0800A046:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity0866_Update
Entity0866_Update: @ 0x0800A050
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r3, #0
	ldr r0, _0800A09C @ =gClock
	ldrb r1, [r0, #0xe]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0800A0E8
	cmp r1, #0
	beq _0800A0E8
	ldr r0, _0800A0A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800A0B4
	ldr r0, _0800A0A4 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _0800A0B0
	ldr r2, _0800A0A8 @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _0800A096
	ldr r4, _0800A0AC @ =0x00000442
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #4
	bne _0800A096
	movs r2, #1
_0800A096:
	adds r0, r2, #0
	b _0800A0E4
	.align 2, 0
_0800A09C: .4byte gClock
_0800A0A0: .4byte 0x030047A4
_0800A0A4: .4byte 0x03002BE0
_0800A0A8: .4byte 0x00000446
_0800A0AC: .4byte 0x00000442
_0800A0B0:
	movs r0, #0
	b _0800A0E4
_0800A0B4:
	ldr r0, _0800A110 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _0800A0E8
	ldr r0, _0800A114 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	beq _0800A0E8
	ldr r0, _0800A118 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _0800A0E2
	ldr r0, _0800A11C @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _0800A0E2
	movs r1, #1
_0800A0E2:
	adds r0, r1, #0
_0800A0E4:
	cmp r0, #0
	beq _0800A120
_0800A0E8:
	movs r3, #1
	ldrb r0, [r5, #0x18]
	cmp r0, #0
	bne _0800A142
	movs r2, #1
	adds r1, r5, #0
	adds r1, #0x2e
	movs r4, #0xf
_0800A0F8:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800A104
	strb r0, [r1]
	strh r0, [r1, #8]
	strb r2, [r1, #5]
_0800A104:
	adds r1, #0x9c
	subs r4, #1
	cmp r4, #0
	bge _0800A0F8
	b _0800A142
	.align 2, 0
_0800A110: .4byte 0x03002B48
_0800A114: .4byte 0x030046A0
_0800A118: .4byte 0x03002B8C
_0800A11C: .4byte 0x03002B60
_0800A120:
	ldrb r0, [r5, #0x18]
	cmp r0, #1
	bne _0800A142
	movs r2, #1
	adds r1, r5, #0
	adds r1, #0x2e
	movs r4, #0xf
_0800A12E:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800A13A
	strb r0, [r1]
	strh r0, [r1, #8]
	strb r2, [r1, #5]
_0800A13A:
	adds r1, #0x9c
	subs r4, #1
	cmp r4, #0
	bge _0800A12E
_0800A142:
	strb r3, [r5, #0x18]
	movs r4, #0
	ldr r7, _0800A16C @ =0x085AA6B8
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r6, r0, #2
_0800A14E:
	movs r0, #0x9c
	muls r0, r4, r0
	adds r0, #0x2c
	adds r1, r5, r0
	ldrb r0, [r1, #5]
	cmp r0, #0
	beq _0800A182
	ldrb r0, [r1, #6]
	cmp r0, #0
	beq _0800A170
	adds r0, r5, #0
	bl FUN_08009c08
	b _0800A182
	.align 2, 0
_0800A16C: .4byte 0x085AA6B8
_0800A170:
	strb r0, [r1, #8]
	ldrb r0, [r1, #2]
	lsls r0, r0, #2
	adds r0, r0, r6
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_0800A182:
	adds r4, #1
	cmp r4, #0xf
	ble _0800A14E
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity0866_Destroy
Entity0866_Destroy: @ 0x0800A190
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_0800A196:
	movs r0, #0x9c
	muls r0, r4, r0
	adds r0, #0x2c
	adds r1, r5, r0
	ldrb r0, [r1, #5]
	cmp r0, #0
	beq _0800A1AA
	adds r0, r5, #0
	bl FUN_08009c08
_0800A1AA:
	adds r4, #1
	cmp r4, #0xf
	ble _0800A196
	ldr r1, _0800A1BC @ =0x03000040
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800A1BC: .4byte 0x03000040

	thumb_func_start Entity0866_Init
Entity0866_Init: @ 0x0800A1C0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0800A20C @ =0x03000040
	str r5, [r0]
	ldr r0, _0800A210 @ =gClock
	ldrb r1, [r0, #0xe]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0800A25C
	cmp r1, #0
	beq _0800A25C
	ldr r0, _0800A214 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800A228
	ldr r0, _0800A218 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _0800A224
	ldr r2, _0800A21C @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _0800A208
	ldr r3, _0800A220 @ =0x00000442
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #4
	bne _0800A208
	movs r2, #1
_0800A208:
	adds r0, r2, #0
	b _0800A258
	.align 2, 0
_0800A20C: .4byte 0x03000040
_0800A210: .4byte gClock
_0800A214: .4byte 0x030047A4
_0800A218: .4byte 0x03002BE0
_0800A21C: .4byte 0x00000446
_0800A220: .4byte 0x00000442
_0800A224:
	movs r0, #0
	b _0800A258
_0800A228:
	ldr r0, _0800A290 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _0800A25C
	ldr r0, _0800A294 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	beq _0800A25C
	ldr r0, _0800A298 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _0800A256
	ldr r0, _0800A29C @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _0800A256
	movs r1, #1
_0800A256:
	adds r0, r1, #0
_0800A258:
	cmp r0, #0
	beq _0800A25E
_0800A25C:
	movs r0, #1
_0800A25E:
	strb r0, [r5, #0x18]
	ldr r0, _0800A2A0 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r5, #0x1c]
	ldr r0, _0800A2A4 @ =0x00001C1C
	bl GetParticleGroup
	str r0, [r5, #0x20]
	ldr r4, _0800A2A8 @ =0x0000922E
	ldr r1, _0800A2AC @ =0x0000D1B8
	adds r0, r4, #0
	bl GetFile
	str r0, [r5, #0x24]
	ldr r1, _0800A2B0 @ =0x0000D41F
	adds r0, r4, #0
	bl GetFile
	str r0, [r5, #0x28]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800A290: .4byte 0x03002B48
_0800A294: .4byte 0x030046A0
_0800A298: .4byte 0x03002B8C
_0800A29C: .4byte 0x03002B60
_0800A2A0: .4byte 0x00001C1A
_0800A2A4: .4byte 0x00001C1C
_0800A2A8: .4byte 0x0000922E
_0800A2AC: .4byte 0x0000D1B8
_0800A2B0: .4byte 0x0000D41F

	thumb_func_start Entity0866_Create
Entity0866_Create: @ 0x0800A2B4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0800A2E4 @ =0x000009EC
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800A2F0
	ldr r1, _0800A2E8 @ =Entity0866_Update
	ldr r2, _0800A2EC @ =Entity0866_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity0866_Init
	cmp r0, #0
	bge _0800A2F0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800A2F2
	.align 2, 0
_0800A2E4: .4byte 0x000009EC
_0800A2E8: .4byte Entity0866_Update
_0800A2EC: .4byte Entity0866_Destroy
_0800A2F0:
	adds r0, r4, #0
_0800A2F2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a2f8
FUN_0800a2f8: @ 0x0800A2F8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r0, _0800A324 @ =0x03000040
	ldr r7, [r0]
	cmp r7, #0
	bne _0800A312
	movs r0, #0
	movs r1, #0
	bl Entity0866_Create
	adds r7, r0, #0
	cmp r7, #0
	beq _0800A31E
_0800A312:
	adds r0, r7, #0
	bl FUN_08009b10
	adds r6, r0, #0
	cmp r6, #0
	bne _0800A328
_0800A31E:
	movs r0, #1
	rsbs r0, r0, #0
	b _0800A40C
	.align 2, 0
_0800A324: .4byte 0x03000040
_0800A328:
	adds r0, r6, #0
	movs r1, #0x9c
	bl ClearMemory
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0
	movs r5, #0
	strh r0, [r6]
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r6, #3]
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r6, #4]
	strb r4, [r6, #8]
	strb r4, [r6, #2]
	strh r5, [r6, #0xa]
	movs r0, #1
	strb r0, [r6, #7]
	strh r5, [r6, #0xc]
	strb r4, [r6, #6]
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_08009b6c
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800A3B0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800A3A8 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800A3AC @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	b _0800A3BA
	.align 2, 0
_0800A3A8: .4byte 0xFFFF0000
_0800A3AC: .4byte 0x0000FFFF
_0800A3B0:
	ldr r1, _0800A3F8 @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_0800A3BA:
	adds r0, r6, #0
	adds r0, #0x14
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	adds r2, r6, #0
	adds r2, #0x7c
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r6, #0
	adds r1, #0x7e
	ldrh r0, [r1]
	adds r0, #0xe6
	strh r0, [r1]
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800A3FC
	bl Script_GetValue
	strh r0, [r6, #0xe]
	bl Script_GetValue
	strh r0, [r6, #0x10]
	bl Script_GetValue
	b _0800A408
	.align 2, 0
_0800A3F8: .4byte 0xFFFF0000
_0800A3FC:
	movs r0, #0x32
	strh r0, [r6, #0xe]
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r6, #0x10]
	movs r0, #0x64
_0800A408:
	strh r0, [r6, #0x12]
	movs r0, #0
_0800A40C:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a414
FUN_0800a414: @ 0x0800A414
	push {r4, lr}
	sub sp, #8
	ldr r0, _0800A454 @ =0x03000040
	ldr r0, [r0]
	movs r4, #0
	cmp r0, #0
	beq _0800A438
	adds r1, r0, #0
	adds r1, #0x2c
	movs r2, #0xf
_0800A428:
	ldrb r0, [r1, #5]
	cmp r0, #0
	beq _0800A430
	adds r4, #1
_0800A430:
	adds r1, #0x9c
	subs r2, #1
	cmp r2, #0
	bge _0800A428
_0800A438:
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823206c
	adds r0, r4, #0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800A454: .4byte 0x03000040

	thumb_func_start FUN_0800a458
FUN_0800a458: @ 0x0800A458
	push {r4, r5, lr}
	ldr r0, _0800A484 @ =0x03000040
	ldr r5, [r0]
	cmp r5, #0
	beq _0800A47E
	movs r4, #0
_0800A464:
	movs r0, #0x9c
	muls r0, r4, r0
	adds r0, #0x2c
	adds r1, r5, r0
	ldrb r0, [r1, #5]
	cmp r0, #0
	beq _0800A478
	adds r0, r5, #0
	bl FUN_08009c08
_0800A478:
	adds r4, #1
	cmp r4, #0xf
	ble _0800A464
_0800A47E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800A484: .4byte 0x03000040
