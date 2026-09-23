	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081d1744
FUN_081d1744: @ 0x081D1744
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0xc7
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D1762
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x5c]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _081D17B0
_081D1762:
	ldr r6, _081D17BC @ =0x0203B400
	ldr r4, _081D17C0 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _081D17C4 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	adds r1, r7, #0
	adds r1, #0x58
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, #0xa
	strh r1, [r7, #0x1c]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	adds r1, r7, #0
	adds r1, #0x5c
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, #0xa
	strh r1, [r7, #0x20]
	mov r1, r8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_081D17B0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D17BC: .4byte 0x0203B400
_081D17C0: .4byte 0x030046B8
_081D17C4: .4byte 0x000003FF

	thumb_func_start FUN_081d17c8
FUN_081d17c8: @ 0x081D17C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r4, r0, #0
	adds r7, r2, #0
	adds r0, r7, #0
	movs r1, #0x10
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D1806
	adds r0, r7, #0
	adds r0, #0xba
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r5, r0, #0
	cmp r1, #1
	bne _081D17F8
	movs r1, #4
	b _081D17FE
_081D17F8:
	cmp r1, #0
	bne _081D1820
	movs r1, #0x17
_081D17FE:
	ldr r0, [r4, #0x34]
	ands r0, r1
	cmp r0, #0
	bne _081D1820
_081D1806:
	adds r4, r7, #0
	adds r4, #0xc7
	ldrb r0, [r4]
	cmp r0, #0
	bne _081D1816
	ldr r0, _081D181C @ =0x0000014D
	bl PlaySound_082406e0
_081D1816:
	movs r0, #0xa
	strb r0, [r4]
	b _081D18FA
	.align 2, 0
_081D181C: .4byte 0x0000014D
_081D1820:
	adds r1, r7, #0
	adds r1, #0xa4
	ldrh r4, [r1]
	cmp r4, #0
	bne _081D18FA
	adds r0, r7, #0
	adds r0, #0xbd
	movs r2, #3
	strb r2, [r0]
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_081d11b8
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #1
	bne _081D18E4
	add r6, sp, #0x10
	str r4, [sp, #0xc]
	add r0, sp, #0xc
	adds r1, r6, #0
	ldr r2, _081D190C @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	strh r0, [r6, #2]
	ldr r5, _081D1910 @ =0x0203B400
	ldr r2, _081D1914 @ =0x030046B8
	mov sl, r2
	ldr r2, [r2]
	adds r2, #1
	ldr r4, _081D1918 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #3
	mov r8, r1
	mov r1, r8
	ands r0, r1
	adds r0, #0xf
	ldr r1, _081D191C @ =0xFFFF0000
	mov sb, r1
	ldr r3, [sp, #0x18]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0xf
	lsls r1, r1, #0x10
	ldr r0, _081D1920 @ =0x0000FFFF
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	mov r0, r8
	ands r1, r0
	adds r1, #0xf
	mov r8, r1
	add r3, sp, #0x18
	ldr r0, [r3, #4]
	mov r1, sb
	ands r0, r1
	mov r1, r8
	orrs r0, r1
	str r0, [r3, #4]
	adds r2, #1
	ands r2, r4
	mov r0, sl
	str r2, [r0]
	lsls r2, r2, #1
	adds r2, r2, r5
	ldrh r0, [r2]
	movs r1, #3
	ands r0, r1
	adds r0, #2
	adds r2, r7, #0
	adds r2, #0x1c
	str r3, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0xf
	str r1, [sp, #8]
	movs r1, #0x11
	adds r3, r6, #0
	bl FUN_08014730
_081D18E4:
	adds r0, r7, #0
	movs r1, #8
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D18FA
	adds r0, r7, #0
	movs r1, #0x10
	bl FUN_081d0e74
_081D18FA:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D190C: .4byte 0x05000002
_081D1910: .4byte 0x0203B400
_081D1914: .4byte 0x030046B8
_081D1918: .4byte 0x000003FF
_081D191C: .4byte 0xFFFF0000
_081D1920: .4byte 0x0000FFFF

	thumb_func_start FUN_081d1924
FUN_081d1924: @ 0x081D1924
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x60
	ldr r2, _081D1998 @ =0xFFFF0000
	ldr r5, _081D199C @ =0x0000FFFF
	movs r1, #0x80
	lsls r1, r1, #0x10
	str r1, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	adds r0, r6, #0
	adds r0, #0xbe
	ldrh r0, [r0]
	strh r0, [r4, #4]
	ldr r2, _081D19A0 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	str r1, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r1, r6, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _081D19A4 @ =FUN_081d17c8
	adds r0, r4, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D1998: .4byte 0xFFFF0000
_081D199C: .4byte 0x0000FFFF
_081D19A0: .4byte 0x00004001
_081D19A4: .4byte FUN_081d17c8

	thumb_func_start FUN_081d19a8
FUN_081d19a8: @ 0x081D19A8
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D19C4
	bl FUN_081d0f08
	cmp r0, #0
	beq _081D19C4
	adds r0, #0xb6
	ldrh r0, [r0]
	b _081D19C8
_081D19C4:
	movs r0, #1
	rsbs r0, r0, #0
_081D19C8:
	pop {r1}
	bx r1

	thumb_func_start FUN_081d19cc
FUN_081d19cc: @ 0x081D19CC
	push {r4, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D19F2
	bl FUN_081d0f08
	adds r4, r0, #0
	cmp r4, #0
	beq _081D19F2
	movs r1, #0x18
	bl FUN_081d0e74
	adds r0, r4, #0
	movs r1, #4
	bl FUN_081d0e84
_081D19F2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d19f8
FUN_081d19f8: @ 0x081D19F8
	push {r4, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D1A74
	bl FUN_081d0f08
	adds r4, r0, #0
	cmp r4, #0
	beq _081D1A74
	movs r0, #0x63
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081D1A48
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D1A74
	adds r1, r4, #0
	adds r1, #0xa4
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_081d11b8
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_081d0e74
	b _081D1A74
_081D1A48:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081D1A74
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D1A74
	adds r1, r4, #0
	adds r1, #0xa4
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_081d11b8
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_081d0e74
_081D1A74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d1a7c
FUN_081d1a7c: @ 0x081D1A7C
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D1A98
	bl FUN_081d0f08
	cmp r0, #0
	beq _081D1A98
	movs r1, #0x10
	bl FUN_081d0e84
_081D1A98:
	pop {r0}
	bx r0

	thumb_func_start FUN_081d1a9c
FUN_081d1a9c: @ 0x081D1A9C
	push {r4, r5, r6, lr}
	movs r2, #0
	movs r1, #0x8b
	lsls r1, r1, #3
	adds r3, r0, r1
	movs r6, #1
	adds r4, r0, #0
	adds r4, #0x94
	adds r5, r0, #0
	adds r5, #0x18
_081D1AB0:
	adds r1, r6, #0
	lsls r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081D1AC0
	movs r0, #1
	b _081D1AC2
_081D1AC0:
	movs r0, #0
_081D1AC2:
	cmp r0, #0
	bne _081D1AD6
	adds r1, r6, #0
	lsls r1, r2
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	strh r2, [r4]
	adds r0, r5, #0
	b _081D1AE2
_081D1AD6:
	adds r4, #0x88
	adds r5, #0x88
	adds r2, #1
	cmp r2, #7
	ble _081D1AB0
	movs r0, #0
_081D1AE2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d1ae8
FUN_081d1ae8: @ 0x081D1AE8
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d1aec
FUN_081d1aec: @ 0x081D1AEC
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x58
	ldr r0, _081D1B0C @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D1B10
	movs r0, #1
	b _081D1B12
	.align 2, 0
_081D1B0C: .4byte 0x030046A0
_081D1B10:
	movs r0, #0
_081D1B12:
	cmp r0, #0
	bne _081D1B22
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	b _081D1B2E
_081D1B22:
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #1
_081D1B2E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d1b34
FUN_081d1b34: @ 0x081D1B34
	push {lr}
	sub sp, #0x30
	adds r1, r0, #0
	adds r0, #0x80
	ldrh r2, [r0]
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081D1BA0
	adds r2, r1, #0
	adds r2, #0x4c
	ldrh r0, [r2]
	cmp r0, #0
	beq _081D1BF2
	adds r0, r1, #0
	adds r0, #0x48
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, [r1, #0x5c]
	str r0, [sp, #4]
	ldr r0, [r1, #0x60]
	str r0, [sp, #8]
	ldr r0, [r1, #0x64]
	str r0, [sp, #0xc]
	ldr r0, [r1, #0x68]
	str r0, [sp, #0x10]
	ldr r0, [r1, #0x6c]
	str r0, [sp, #0x14]
	ldr r0, [r1, #0x70]
	str r0, [sp, #0x18]
	ldr r0, [r1, #0x74]
	str r0, [sp, #0x1c]
	ldr r0, [r1, #0x78]
	str r0, [sp, #0x20]
	adds r0, r1, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	str r0, [sp, #0x24]
	ldr r1, _081D1B9C @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r1
	movs r1, #0xa
	orrs r0, r1
	str r0, [sp, #0x28]
	add r1, sp, #0x28
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
	b _081D1BF2
	.align 2, 0
_081D1B9C: .4byte 0xFFFF0000
_081D1BA0:
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081D1BF2
	adds r2, r1, #0
	adds r2, #0x4e
	ldrh r0, [r2]
	cmp r0, #0
	beq _081D1BF2
	adds r0, r1, #0
	adds r0, #0x48
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, [r1, #0x5c]
	str r0, [sp, #4]
	ldr r0, [r1, #0x60]
	str r0, [sp, #8]
	ldr r0, [r1, #0x64]
	str r0, [sp, #0xc]
	ldr r0, [r1, #0x68]
	str r0, [sp, #0x10]
	ldr r0, [r1, #0x6c]
	str r0, [sp, #0x14]
	ldr r0, [r1, #0x70]
	str r0, [sp, #0x18]
	ldr r0, [r1, #0x74]
	str r0, [sp, #0x1c]
	ldr r0, [r1, #0x78]
	str r0, [sp, #0x20]
	adds r0, r1, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	str r0, [sp, #0x24]
	movs r0, #0xa
	add r1, sp, #0x28
	strh r0, [r1]
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081D1BF2:
	add sp, #0x30
	pop {r0}
	bx r0

	thumb_func_start FUN_081d1bf8
FUN_081d1bf8: @ 0x081D1BF8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x5a
	strh r1, [r0]
	adds r5, r4, #0
	adds r5, #0x80
	ldrh r1, [r5]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _081D1C5A
	movs r0, #2
	orrs r0, r1
	movs r1, #0
	orrs r0, r1
	ldr r1, _081D1C4C @ =0x0000FFFE
	ands r0, r1
	strh r0, [r5]
	adds r1, r4, #0
	adds r1, #0x84
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_081d1b34
	strh r6, [r4, #0x10]
	ldr r0, [r4, #0xc]
	movs r1, #0x90
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	ldrh r1, [r5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081D1C54
	ldr r0, _081D1C50 @ =0x00000389
	bl PlaySound_082406e0
	b _081D1C5A
	.align 2, 0
_081D1C4C: .4byte 0x0000FFFE
_081D1C50: .4byte 0x00000389
_081D1C54:
	ldr r0, _081D1C60 @ =0x00000155
	bl PlaySound_082406e0
_081D1C5A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D1C60: .4byte 0x00000155

	thumb_func_start FUN_081d1c64
FUN_081d1c64: @ 0x081D1C64
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x80
	ldrh r1, [r6]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081D1CD2
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	ldr r1, _081D1CB4 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r6]
	adds r0, r5, #0
	bl FUN_081d1b34
	strh r4, [r5, #0x10]
	ldr r0, [r5, #0xc]
	ldr r1, _081D1CB8 @ =0x0000011F
	bl Video_SetAuxSpritePltt
	ldr r0, _081D1CBC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081D1CCA
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081D1CC4
	ldr r0, _081D1CC0 @ =0x00000389
	bl PlaySound_082406e0
	b _081D1CCA
	.align 2, 0
_081D1CB4: .4byte 0x0000FFFD
_081D1CB8: .4byte 0x0000011F
_081D1CBC: .4byte 0x030047A4
_081D1CC0: .4byte 0x00000389
_081D1CC4:
	ldr r0, _081D1CD8 @ =0x00000155
	bl PlaySound_082406e0
_081D1CCA:
	adds r1, r5, #0
	adds r1, #0x5a
	movs r0, #0
	strh r0, [r1]
_081D1CD2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D1CD8: .4byte 0x00000155

	thumb_func_start FUN_081d1cdc
FUN_081d1cdc: @ 0x081D1CDC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r0, #0
	bl FUN_0823b3ec
	adds r3, r0, #0
	cmp r3, #0
	beq _081D1DDC
	movs r0, #0
	mov sb, r0
	adds r1, r6, #0
	adds r1, #0x82
	ldrb r0, [r1]
	cmp r0, #0
	beq _081D1D04
	mov r5, sb
	strb r5, [r1]
_081D1D04:
	ldr r4, [r3, #0x18]
	cmp r4, #0
	beq _081D1DBA
	mov r7, sp
	movs r0, #0x1c
	adds r0, r0, r6
	mov ip, r0
	movs r1, #0x80
	lsls r1, r1, #0x11
	mov r8, r1
_081D1D18:
	ldrh r1, [r4, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _081D1DB4
	ldr r0, _081D1DAC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081D1D4A
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _081D1D4A
	ldr r0, _081D1DB0 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _081D1DB4
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _081D1DB4
_081D1D4A:
	adds r3, r4, #0
	adds r3, #8
	ldrh r2, [r4, #8]
	ldrh r0, [r6, #0x1c]
	subs r2, r2, r0
	strh r2, [r7]
	ldrh r1, [r3, #2]
	mov r5, ip
	ldrh r0, [r5, #2]
	subs r5, r1, r0
	strh r5, [r7, #2]
	ldrh r1, [r3, #4]
	mov r3, ip
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r7, #4]
	lsls r2, r2, #0x10
	mov r0, r8
	lsrs r3, r0, #0x10
	cmp r2, r8
	bhi _081D1DB4
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x20
	bgt _081D1DB4
	cmp r0, #0
	blt _081D1DB4
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, r3
	bgt _081D1DB4
	cmp r0, #0
	blt _081D1DB4
	ldrh r1, [r4]
	adds r0, r6, #0
	bl FUN_081d1bf8
	adds r2, r6, #0
	adds r2, #0x84
	ldrh r1, [r2]
	adds r0, r6, #0
	adds r0, #0x86
	ldrh r0, [r0]
	subs r0, #1
	cmp r1, r0
	bge _081D1DDC
	adds r0, r1, #1
	b _081D1DDA
	.align 2, 0
_081D1DAC: .4byte 0x030047A4
_081D1DB0: .4byte 0x03002BE0
_081D1DB4:
	ldr r4, [r4, #0x40]
	cmp r4, #0
	bne _081D1D18
_081D1DBA:
	mov r1, sb
	cmp r1, #0
	bne _081D1DDC
	adds r2, r6, #0
	adds r2, #0x84
	adds r1, r6, #0
	adds r1, #0x86
	ldrh r0, [r2]
	ldrh r1, [r1]
	cmp r0, r1
	blo _081D1DD8
	adds r0, r6, #0
	bl FUN_081d1c64
	b _081D1DDC
_081D1DD8:
	adds r0, #1
_081D1DDA:
	strh r0, [r2]
_081D1DDC:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d1dec
FUN_081d1dec: @ 0x081D1DEC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	ldr r0, _081D1E64 @ =0x03000190
	ldr r0, [r0]
	cmp r0, #0
	bne _081D1E0A
	bl Entity081d2180_Create
	cmp r0, #0
	bne _081D1E0A
	b _081D209C
_081D1E0A:
	bl FUN_081d1a9c
	adds r6, r0, #0
	cmp r6, #0
	bne _081D1E16
	b _081D209C
_081D1E16:
	adds r1, r6, #0
	adds r1, #0x7e
	movs r0, #1
	strh r0, [r1]
	mov sl, r6
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D1E3C
	bl Script_GetValue
	strh r0, [r6, #0x1c]
	bl Script_GetValue
	strh r0, [r6, #0x1e]
	bl Script_GetValue
	strh r0, [r6, #0x20]
_081D1E3C:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	mov r1, sl
	adds r1, #0x48
	strh r0, [r1]
	movs r0, #0x52
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D1E86
	bl VM_GetPC
	cmp r0, #0
	beq _081D1E68
	bl Script_GetValue
	adds r1, r0, #0
	b _081D1E6A
	.align 2, 0
_081D1E64: .4byte 0x03000190
_081D1E68:
	movs r1, #0
_081D1E6A:
	adds r0, r6, #0
	adds r0, #0x4c
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081D1E7E
	bl Script_GetValue
	b _081D1E80
_081D1E7E:
	movs r0, #0
_081D1E80:
	adds r1, r6, #0
	adds r1, #0x4e
	strh r0, [r1]
_081D1E86:
	movs r0, #0x53
	bl VM_SeekToKeyword
	adds r7, r6, #0
	adds r7, #0x4a
	movs r1, #0x2c
	adds r1, r1, r6
	mov r8, r1
	movs r2, #0x80
	adds r2, r2, r6
	mov sb, r2
	adds r3, r6, #0
	adds r3, #0x84
	str r3, [sp, #0x10]
	adds r5, r6, #0
	adds r5, #0x86
	str r5, [sp, #0x14]
	mov r1, sl
	adds r1, #0x1c
	str r1, [sp, #0x18]
	adds r2, r6, #0
	adds r2, #0x58
	str r2, [sp, #0x1c]
	subs r3, #1
	str r3, [sp, #0xc]
	subs r5, #4
	str r5, [sp, #8]
	cmp r0, #0
	beq _081D1EDC
	subs r5, #0x26
	movs r4, #3
_081D1EC4:
	bl VM_GetPC
	cmp r0, #0
	beq _081D1ED2
	bl Script_GetValue
	b _081D1ED4
_081D1ED2:
	movs r0, #0
_081D1ED4:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081D1EC4
_081D1EDC:
	movs r0, #0x57
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D1F04
	adds r5, r6, #0
	adds r5, #0x6c
	movs r4, #3
_081D1EEC:
	bl VM_GetPC
	cmp r0, #0
	beq _081D1EFA
	bl Script_GetValue
	b _081D1EFC
_081D1EFA:
	movs r0, #0
_081D1EFC:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081D1EEC
_081D1F04:
	movs r0, #0x54
	movs r1, #0
	bl VM_GetKeywordValue
	movs r5, #0
	movs r4, #0
	strh r0, [r7]
	ldrh r1, [r7]
	mov r0, r8
	bl Video_GetAuxSprite
	mov r0, sb
	strh r4, [r0]
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _081D1F38
	mov r1, sb
	ldrh r0, [r1]
	movs r1, #1
	orrs r0, r1
	mov r2, sb
	strh r0, [r2]
	b _081D1F42
_081D1F38:
	mov r3, sb
	ldrh r0, [r3]
	movs r1, #2
	orrs r0, r1
	strh r0, [r3]
_081D1F42:
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	cmp r1, #0
	beq _081D1F58
	mov r5, sb
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r5]
_081D1F58:
	mov r0, sl
	mov r1, r8
	movs r2, #0
	bl AuxSprite_Add
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _081D1F84
	movs r0, #1
	mov r1, sl
	strh r0, [r1, #0x10]
	ldr r0, [r6, #0xc]
	movs r1, #0x90
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	b _081D1F90
_081D1F84:
	mov r2, sl
	strh r0, [r2, #0x10]
	ldr r0, [r6, #0xc]
	ldr r1, _081D1F9C @ =0x0000011F
	bl Video_SetAuxSpritePltt
_081D1F90:
	bl FUN_0823b3ec
	cmp r0, #0
	bne _081D1FD0
	b _081D203C
	.align 2, 0
_081D1F9C: .4byte 0x0000011F
_081D1FA0:
	ldrh r0, [r4]
	adds r1, r6, #0
	adds r1, #0x5a
	strh r0, [r1]
	mov r3, sb
	ldrh r0, [r3]
	movs r1, #2
	orrs r0, r1
	ldr r1, _081D1FCC @ =0x0000FFFE
	ands r0, r1
	strh r0, [r3]
	mov r0, ip
	ldr r5, [sp, #0x10]
	strh r0, [r5]
	movs r0, #1
	strh r0, [r6, #0x10]
	ldr r0, [r6, #0xc]
	movs r1, #0x90
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	b _081D203C
	.align 2, 0
_081D1FCC: .4byte 0x0000FFFE
_081D1FD0:
	bl FUN_0823b3ec
	ldr r4, [r0, #0x18]
	cmp r4, #0
	beq _081D203C
	mov r7, sp
	movs r1, #0x1c
	adds r1, r1, r6
	mov r8, r1
_081D1FE2:
	ldrh r1, [r4, #2]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	cmp r0, #0
	bne _081D2036
	adds r3, r4, #0
	adds r3, #8
	ldrh r2, [r4, #8]
	ldrh r0, [r6, #0x1c]
	subs r2, r2, r0
	strh r2, [r7]
	ldrh r1, [r3, #2]
	mov r5, r8
	ldrh r0, [r5, #2]
	subs r5, r1, r0
	strh r5, [r7, #2]
	ldrh r1, [r3, #4]
	mov r3, r8
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r7, #4]
	lsls r2, r2, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsrs r3, r0, #0x10
	cmp r2, r0
	bhi _081D2036
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x20
	bgt _081D2036
	cmp r0, #0
	blt _081D2036
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, r3
	bgt _081D2036
	cmp r0, #0
	bge _081D1FA0
_081D2036:
	ldr r4, [r4, #0x40]
	cmp r4, #0
	bne _081D1FE2
_081D203C:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	movs r1, #0
	ldr r2, [sp, #0x14]
	strh r0, [r2]
	ldr r3, [sp, #0x10]
	strh r1, [r3]
	ldr r0, [sp, #0x18]
	bl FUN_08241574
	ldr r5, [sp, #0x1c]
	strh r0, [r5]
	ldr r0, _081D2070 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x92
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r2, [r5]
	cmp r0, r2
	bne _081D2074
	movs r0, #1
	b _081D2076
	.align 2, 0
_081D2070: .4byte 0x030046A0
_081D2074:
	movs r0, #0
_081D2076:
	cmp r0, #0
	bne _081D2086
	mov r3, sl
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	b _081D2092
_081D2086:
	mov r5, sl
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
_081D2092:
	movs r0, #0
	ldr r1, [sp, #0xc]
	strb r0, [r1]
	ldr r2, [sp, #8]
	strb r0, [r2]
_081D209C:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Entity081d2180_Update
Entity081d2180_Update: @ 0x081D20AC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x18
	movs r3, #0x8b
	lsls r3, r3, #3
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _081D2118
	movs r6, #0
	movs r0, #0x8b
	lsls r0, r0, #3
	adds r7, r1, r0
	ldr r3, _081D20E8 @ =0x085AE0C8
	mov r8, r3
	adds r5, r1, #0
	adds r5, #0x96
	adds r4, r2, #0
_081D20D6:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D20EC
	movs r0, #1
	b _081D20EE
	.align 2, 0
_081D20E8: .4byte 0x085AE0C8
_081D20EC:
	movs r0, #0
_081D20EE:
	cmp r0, #0
	beq _081D210E
	adds r0, r4, #0
	bl FUN_081d1aec
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D210E
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_081D210E:
	adds r5, #0x88
	adds r4, #0x88
	adds r6, #1
	cmp r6, #7
	ble _081D20D6
_081D2118:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity081d2180_Destroy
Entity081d2180_Destroy: @ 0x081D2124
	push {r4, r5, r6, lr}
	movs r5, #0
	movs r1, #0x8b
	lsls r1, r1, #3
	adds r6, r0, r1
	adds r4, r0, #0
	adds r4, #0x18
_081D2132:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D2142
	movs r0, #1
	b _081D2144
_081D2142:
	movs r0, #0
_081D2144:
	cmp r0, #0
	beq _081D214E
	adds r0, r4, #0
	bl AuxSprite_Remove
_081D214E:
	adds r4, #0x88
	adds r5, #1
	cmp r5, #7
	ble _081D2132
	movs r1, #0
	ldr r0, _081D2164 @ =0x03000190
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081D2164: .4byte 0x03000190

	thumb_func_start Entity081d2180_Init
Entity081d2180_Init: @ 0x081D2168
	ldr r1, _081D217C @ =0x03000190
	str r0, [r1]
	movs r1, #0x8b
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	movs r0, #0
	bx lr
	.align 2, 0
_081D217C: .4byte 0x03000190

	thumb_func_start Entity081d2180_Create
Entity081d2180_Create: @ 0x081D2180
	push {r4, lr}
	ldr r0, _081D21B4 @ =0x03000190
	ldr r0, [r0]
	cmp r0, #0
	bne _081D21C6
	ldr r1, _081D21B8 @ =0x0000045C
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D21C4
	ldr r1, _081D21BC @ =Entity081d2180_Update
	ldr r2, _081D21C0 @ =Entity081d2180_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081d2180_Init
	cmp r0, #0
	bge _081D21C4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D21C6
	.align 2, 0
_081D21B4: .4byte 0x03000190
_081D21B8: .4byte 0x0000045C
_081D21BC: .4byte Entity081d2180_Update
_081D21C0: .4byte Entity081d2180_Destroy
_081D21C4:
	adds r0, r4, #0
_081D21C6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d21cc
FUN_081d21cc: @ 0x081D21CC
	ldr r1, _081D21D4 @ =0x03000190
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D21D4: .4byte 0x03000190
