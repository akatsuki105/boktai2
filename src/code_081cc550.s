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
	bl FUN_081d2180
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

	thumb_func_start FUN_081d20ac
FUN_081d20ac: @ 0x081D20AC
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

	thumb_func_start FUN_081d2124
FUN_081d2124: @ 0x081D2124
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

	thumb_func_start FUN_081d2168
FUN_081d2168: @ 0x081D2168
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

	thumb_func_start FUN_081d2180
FUN_081d2180: @ 0x081D2180
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
	ldr r1, _081D21BC @ =FUN_081d20ac
	ldr r2, _081D21C0 @ =FUN_081d2124
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081d2168
	cmp r0, #0
	bge _081D21C4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D21C6
	.align 2, 0
_081D21B4: .4byte 0x03000190
_081D21B8: .4byte 0x0000045C
_081D21BC: .4byte FUN_081d20ac
_081D21C0: .4byte FUN_081d2124
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

	thumb_func_start FUN_081d21d8
FUN_081d21d8: @ 0x081D21D8
	push {lr}
	adds r1, r0, #0
	adds r0, #0xd6
	ldrh r2, [r0]
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	bne _081D2226
	adds r0, r1, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	cmp r0, #2
	bgt _081D21FC
	cmp r0, #1
	bge _081D2212
	cmp r0, #0
	beq _081D2208
	b _081D2220
_081D21FC:
	cmp r0, #3
	bne _081D2220
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081D2212
_081D2208:
	movs r0, #0xac
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081D2226
_081D2212:
	ldr r0, _081D221C @ =0x00000261
	bl PlaySound_082406e0
	b _081D2226
	.align 2, 0
_081D221C: .4byte 0x00000261
_081D2220:
	ldr r0, _081D222C @ =0x00000261
	bl PlaySound_082406e0
_081D2226:
	pop {r0}
	bx r0
	.align 2, 0
_081D222C: .4byte 0x00000261

	thumb_func_start FUN_081d2230
FUN_081d2230: @ 0x081D2230
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov ip, r0
	ldr r0, _081D2254 @ =0x03000194
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	beq _081D22FE
	ldr r1, _081D2258 @ =0x000012AC
	add r1, sb
	ldr r0, [r1]
	cmp r0, #0
	bne _081D2264
	b _081D22FE
	.align 2, 0
_081D2254: .4byte 0x03000194
_081D2258: .4byte 0x000012AC
_081D225C:
	mov r0, r8
	adds r0, #0x1c
	add r0, sb
	b _081D2300
_081D2264:
	movs r7, #0
	mov sl, r1
	mov r6, sp
	movs r0, #0
	mov r8, r0
_081D226E:
	movs r1, #1
	lsls r1, r7
	mov r2, sl
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D2280
	movs r0, #1
	b _081D2282
_081D2280:
	movs r0, #0
_081D2282:
	cmp r0, #0
	beq _081D22F2
	mov r3, sp
	mov r2, r8
	add r2, sb
	movs r4, #0x8c
	lsls r4, r4, #1
	adds r2, r2, r4
	mov r5, ip
	ldrh r0, [r5]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r1, [r5, #2]
	ldrh r0, [r2, #2]
	subs r4, r1, r0
	strh r4, [r3, #2]
	ldrh r1, [r5, #4]
	ldrh r0, [r2, #4]
	subs r1, r1, r0
	str r1, [sp, #8]
	strh r1, [r3, #4]
	ldr r2, _081D2310 @ =0x085AE0D0
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bgt _081D22F2
	cmn r1, r0
	blt _081D22F2
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #2
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D22F2
	movs r5, #2
	ldrsh r1, [r3, r5]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmn r1, r0
	blt _081D22F2
	ldr r5, [sp, #8]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r4, #4
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D22F2
	movs r5, #4
	ldrsh r1, [r3, r5]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmn r1, r0
	bge _081D225C
_081D22F2:
	movs r4, #0xc6
	lsls r4, r4, #1
	add r8, r4
	adds r7, #1
	cmp r7, #0xb
	ble _081D226E
_081D22FE:
	movs r0, #0
_081D2300:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D2310: .4byte 0x085AE0D0

	thumb_func_start FUN_081d2314
FUN_081d2314: @ 0x081D2314
	push {r4, r5, r6, r7, lr}
	movs r2, #0
	ldr r1, _081D233C @ =0x000012AC
	adds r3, r0, r1
	movs r7, #1
	adds r4, r0, #0
	adds r4, #0xcc
	adds r5, r0, #0
	adds r5, #0x1c
	movs r6, #0xc6
	lsls r6, r6, #1
_081D232A:
	adds r1, r7, #0
	lsls r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081D2340
	movs r0, #1
	b _081D2342
	.align 2, 0
_081D233C: .4byte 0x000012AC
_081D2340:
	movs r0, #0
_081D2342:
	cmp r0, #0
	bne _081D2356
	adds r1, r7, #0
	lsls r1, r2
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	strh r2, [r4]
	adds r0, r5, #0
	b _081D2362
_081D2356:
	adds r4, r4, r6
	adds r5, r5, r6
	adds r2, #1
	cmp r2, #0xb
	ble _081D232A
	movs r0, #0
_081D2362:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d2368
FUN_081d2368: @ 0x081D2368
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0xb8
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _081D2388
	subs r0, r2, #1
	b _081D2644
_081D2388:
	adds r0, r5, #0
	adds r0, #0xf9
	ldrb r0, [r0]
	lsrs r6, r0, #6
	cmp r6, #1
	beq _081D23C8
	cmp r6, #1
	bgt _081D239E
	cmp r6, #0
	beq _081D23A8
	b _081D2646
_081D239E:
	cmp r6, #2
	beq _081D23E0
	cmp r6, #3
	beq _081D2410
	b _081D2646
_081D23A8:
	add r0, sp, #0x38
	ldr r1, _081D23C0 @ =0x0000FF40
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r6, [r0, #4]
	strh r1, [r0, #8]
	strh r1, [r0, #0xa]
	adds r1, r0, #0
	ldr r0, _081D23C4 @ =0x0000FF80
	strh r0, [r1, #0xc]
	movs r0, #0x3e
	b _081D242C
	.align 2, 0
_081D23C0: .4byte 0x0000FF40
_081D23C4: .4byte 0x0000FF80
_081D23C8:
	add r0, sp, #0x38
	ldr r2, _081D23D8 @ =0x0000FFC0
	strh r2, [r0]
	ldr r3, _081D23DC @ =0x0000FF40
	strh r3, [r0, #2]
	strh r2, [r0, #4]
	adds r1, r0, #0
	b _081D2420
	.align 2, 0
_081D23D8: .4byte 0x0000FFC0
_081D23DC: .4byte 0x0000FF40
_081D23E0:
	add r0, sp, #0x38
	ldr r3, _081D2404 @ =0x0000FF7C
	strh r3, [r0]
	ldr r2, _081D2408 @ =0x0000FF40
	strh r2, [r0, #2]
	adds r1, r0, #0
	ldr r0, _081D240C @ =0x0000FFE0
	strh r0, [r1, #4]
	adds r0, r1, #0
	strh r3, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	movs r0, #0x3e
	mov ip, r0
	movs r1, #4
	mov sl, r1
	movs r3, #0x18
	b _081D2434
	.align 2, 0
_081D2404: .4byte 0x0000FF7C
_081D2408: .4byte 0x0000FF40
_081D240C: .4byte 0x0000FFE0
_081D2410:
	add r1, sp, #0x38
	ldr r0, _081D2448 @ =0x0000FFC0
	strh r0, [r1]
	adds r0, r1, #0
	ldr r3, _081D244C @ =0x0000FF40
	strh r3, [r0, #2]
	ldr r2, _081D2450 @ =0x0000FFE0
	strh r2, [r0, #4]
_081D2420:
	ldr r0, _081D2454 @ =0x0000FF24
	strh r0, [r1, #8]
	adds r0, r1, #0
	strh r3, [r0, #0xa]
	strh r2, [r0, #0xc]
	movs r0, #0x40
_081D242C:
	mov ip, r0
	movs r1, #4
	mov sl, r1
	movs r3, #0x20
_081D2434:
	mov sb, r3
	adds r0, r5, #0
	adds r0, #0xe7
	ldrb r7, [r0]
	cmp r7, #0
	beq _081D2458
	cmp r7, #3
	bne _081D2446
	b _081D254A
_081D2446:
	b _081D2646
	.align 2, 0
_081D2448: .4byte 0x0000FFC0
_081D244C: .4byte 0x0000FF40
_081D2450: .4byte 0x0000FFE0
_081D2454: .4byte 0x0000FF24
_081D2458:
	movs r0, #0xca
	adds r0, r0, r5
	mov r8, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne _081D24EC
	adds r1, r5, #0
	adds r1, #0xfc
	add r0, sp, #0x38
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _081D24E4 @ =0xFFFF0000
	ldr r2, [sp, #0x48]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0x48]
	adds r4, r5, #0
	adds r4, #0xfe
	add r0, sp, #0x38
	ldrh r1, [r0, #2]
	ldrh r4, [r4]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	ldr r0, _081D24E8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x48]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	add r0, sp, #0x38
	ldrh r2, [r0, #4]
	ldrh r1, [r1]
	adds r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r0, sp, #0x48
	ldr r1, [r0, #4]
	ands r1, r3
	orrs r1, r2
	str r1, [r0, #4]
	movs r1, #4
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	mov r3, ip
	str r3, [sp, #0x10]
	movs r1, #3
	str r1, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	movs r1, #0x16
	movs r2, #8
	mov r3, sl
	bl FUN_081ee584
	movs r0, #1
	mov r1, r8
	strh r0, [r1]
	b _081D263E
	.align 2, 0
_081D24E4: .4byte 0xFFFF0000
_081D24E8: .4byte 0x0000FFFF
_081D24EC:
	adds r2, r5, #0
	adds r2, #0xfc
	add r0, sp, #0x38
	ldrh r1, [r0, #8]
	ldrh r2, [r2]
	adds r1, r1, r2
	add r0, sp, #0x48
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xfe
	add r1, sp, #0x38
	ldrh r1, [r1, #0xa]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r2, r5, r3
	add r1, sp, #0x38
	ldrh r1, [r1, #0xc]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #4]
	movs r1, #4
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	mov r3, ip
	str r3, [sp, #0x10]
	movs r1, #3
	str r1, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	movs r1, #0x16
	movs r2, #8
	mov r3, sl
	bl FUN_081ee584
	mov r0, r8
	strh r7, [r0]
	b _081D263E
_081D254A:
	movs r1, #0xca
	adds r1, r1, r5
	mov r8, r1
	ldrh r3, [r1]
	cmp r3, #0
	bne _081D25D0
	adds r2, r5, #0
	adds r2, #0xfc
	add r0, sp, #0x38
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r1, r2
	add r0, sp, #0x48
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xfe
	add r1, sp, #0x38
	ldrh r1, [r1, #2]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r5, r1
	add r1, sp, #0x38
	ldrh r1, [r1, #4]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #4]
	movs r1, #4
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	mov r1, ip
	str r1, [sp, #0x10]
	str r7, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	str r3, [sp, #0x20]
	ldr r1, _081D25C8 @ =0x0000F422
	str r1, [sp, #0x24]
	ldr r1, _081D25CC @ =0x0000121B
	str r1, [sp, #0x28]
	str r3, [sp, #0x2c]
	str r3, [sp, #0x30]
	movs r1, #0xda
	str r1, [sp, #0x34]
	movs r1, #0x16
	movs r2, #8
	mov r3, sl
	bl FUN_081ee53c
	movs r0, #1
	mov r3, r8
	strh r0, [r3]
	b _081D263E
	.align 2, 0
_081D25C8: .4byte 0x0000F422
_081D25CC: .4byte 0x0000121B
_081D25D0:
	adds r2, r5, #0
	adds r2, #0xfc
	add r0, sp, #0x38
	ldrh r1, [r0, #8]
	ldrh r2, [r2]
	adds r1, r1, r2
	movs r4, #0
	add r0, sp, #0x48
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xfe
	add r1, sp, #0x38
	ldrh r1, [r1, #0xa]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r5, r1
	add r1, sp, #0x38
	ldrh r1, [r1, #0xc]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #4]
	movs r1, #4
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r3, sb
	str r3, [sp, #0xc]
	mov r1, ip
	str r1, [sp, #0x10]
	str r7, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	str r4, [sp, #0x20]
	ldr r1, _081D2658 @ =0x0000F422
	str r1, [sp, #0x24]
	ldr r1, _081D265C @ =0x0000121B
	str r1, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	movs r1, #0xda
	str r1, [sp, #0x34]
	movs r1, #0x16
	movs r2, #8
	mov r3, sl
	bl FUN_081ee53c
	mov r3, r8
	strh r4, [r3]
_081D263E:
	adds r1, r5, #0
	adds r1, #0xb8
	movs r0, #4
_081D2644:
	strh r0, [r1]
_081D2646:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D2658: .4byte 0x0000F422
_081D265C: .4byte 0x0000121B

	thumb_func_start FUN_081d2660
FUN_081d2660: @ 0x081D2660
	push {r4, r5, r6, r7, lr}
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r0, [r0, #8]
	ldrh r4, [r0]
	movs r2, #0
	ldrsh r3, [r1, r2]
	ldrh r2, [r0, #2]
	movs r7, #4
	ldrsh r0, [r1, r7]
	subs r2, r2, r0
	subs r4, r4, r3
	cmp r4, #0
	bge _081D267E
	rsbs r4, r4, #0
_081D267E:
	cmp r4, r5
	bhi _081D2690
	cmp r2, #0
	bge _081D2688
	rsbs r2, r2, #0
_081D2688:
	cmp r2, r6
	bhi _081D2690
	movs r0, #1
	b _081D2692
_081D2690:
	movs r0, #0
_081D2692:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d2698
FUN_081d2698: @ 0x081D2698
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	adds r0, r6, #0
	movs r1, #8
	bl ClearMemory
	ldr r2, [r4, #8]
	ldrh r1, [r2]
	movs r3, #8
	ldrsh r0, [r5, r3]
	subs r3, r1, r0
	ldrh r1, [r2, #2]
	movs r2, #0xc
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	adds r0, r3, #0
	cmp r3, #0
	bge _081D26C4
	rsbs r0, r3, #0
_081D26C4:
	cmp r0, r7
	bhi _081D26EA
	adds r2, r1, #0
	cmp r1, #0
	bge _081D26D0
	rsbs r2, r1, #0
_081D26D0:
	ldr r0, [sp, #0x14]
	cmp r2, r0
	bhi _081D26EA
	ldrh r0, [r5, #8]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldrh r0, [r5, #0xc]
	adds r0, r0, r1
	strh r0, [r5, #0xc]
	strh r3, [r6]
	strh r1, [r6, #4]
	movs r0, #1
	b _081D2764
_081D26EA:
	cmp r3, #0
	bne _081D26F2
	cmp r1, #0
	beq _081D2762
_081D26F2:
	adds r0, r3, #0
	bl ArcTan2_8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	lsls r3, r0, #6
	strb r3, [r5, #5]
	ldr r1, _081D2724 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x18]
	muls r0, r2, r0
	cmp r0, #0
	blt _081D2728
	asrs r0, r0, #0xc
	b _081D272E
	.align 2, 0
_081D2724: .4byte 0x085B0A08
_081D2728:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D272E:
	adds r2, r0, #0
	ldr r0, _081D2748 @ =0x085B0A08
	lsls r1, r3, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	ldr r1, [sp, #0x18]
	muls r0, r1, r0
	cmp r0, #0
	blt _081D274C
	asrs r1, r0, #0xc
	b _081D2752
	.align 2, 0
_081D2748: .4byte 0x085B0A08
_081D274C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D2752:
	ldrh r0, [r5, #8]
	adds r0, r0, r2
	strh r0, [r5, #8]
	ldrh r0, [r5, #0xc]
	adds r0, r0, r1
	strh r0, [r5, #0xc]
	strh r2, [r6]
	strh r1, [r6, #4]
_081D2762:
	movs r0, #0
_081D2764:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d276c
FUN_081d276c: @ 0x081D276C
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	ldr r0, _081D27A8 @ =0x03000194
	ldr r0, [r0]
	adds r6, r3, #0
	adds r6, #0xd4
	ldr r1, _081D27AC @ =0x000012B0
	adds r5, r0, r1
	ldr r2, _081D27B0 @ =0x03002BE0
	movs r4, #0
_081D2780:
	ldr r1, [r2]
	cmp r1, #0
	beq _081D27B8
	ldrh r0, [r6]
	ldrh r7, [r5]
	cmp r0, r7
	bne _081D27B8
	adds r0, r3, #0
	adds r0, #0xb2
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _081D27B4
	movs r7, #0xde
	lsls r7, r7, #1
	adds r0, r1, r7
	b _081D27B6
	.align 2, 0
_081D27A8: .4byte 0x03000194
_081D27AC: .4byte 0x000012B0
_081D27B0: .4byte 0x03002BE0
_081D27B4:
	movs r0, #0
_081D27B6:
	str r0, [r1, #0x3c]
_081D27B8:
	adds r2, #4
	subs r4, #1
	cmp r4, #0
	bge _081D2780
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d27c8
FUN_081d27c8: @ 0x081D27C8
	push {r4, lr}
	ldr r4, _081D27E4 @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D27E8
	movs r0, #3
	bl FUN_08086978
	cmp r0, #0
	bne _081D2804
	b _081D27F2
	.align 2, 0
_081D27E4: .4byte 0x03002BE0
_081D27E8:
	movs r0, #3
	bl FUN_08086978
	cmp r0, #0
	beq _081D2804
_081D27F2:
	ldr r0, [r4]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _081D2804
	movs r0, #1
	b _081D2806
_081D2804:
	movs r0, #0
_081D2806:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d280c
FUN_081d280c: @ 0x081D280C
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d2810
FUN_081d2810: @ 0x081D2810
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0x58
	movs r1, #8
	bl ClearMemory
	ldr r0, _081D2874 @ =0x03002BE0
	mov r4, sp
	adds r2, r5, #0
	adds r2, #0xfc
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r4, r5, #0
	adds r4, #0xb6
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D2860
	adds r0, r5, #0
	bl FUN_081d21d8
	movs r0, #0
	strb r0, [r4]
_081D2860:
	movs r2, #4
	adds r1, r5, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081D2878
	movs r0, #1
	b _081D287A
	.align 2, 0
_081D2874: .4byte 0x03002BE0
_081D2878:
	movs r0, #0
_081D287A:
	cmp r0, #0
	beq _081D2880
	b _081D29F2
_081D2880:
	movs r1, #2
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D288E
	movs r0, #1
	b _081D2890
_081D288E:
	movs r0, #0
_081D2890:
	mov sb, r0
	cmp r0, #0
	beq _081D2950
	adds r4, r5, #0
	adds r4, #0xfe
	adds r1, r5, #0
	adds r1, #0xba
	ldrh r0, [r1]
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r4]
	ldrh r0, [r1]
	movs r1, #0x5a
	adds r1, r1, r5
	mov r8, r1
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xd0
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldr r0, [r0]
	cmp r0, r1
	ble _081D28C0
	b _081D29F2
_081D28C0:
	strh r0, [r4]
	ldr r6, _081D293C @ =0x03002BE0
	ldr r0, [r6]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D28F4
	ldr r0, [r6]
	ldr r1, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	str r1, [sp]
	str r2, [sp, #4]
	ldrh r2, [r4]
	mov r1, sp
	strh r2, [r1, #2]
	bl FUN_0807a91c
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
	movs r0, #0
	mov r1, r8
	strh r0, [r1]
_081D28F4:
	adds r0, r5, #0
	adds r0, #0xb2
	movs r1, #4
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xb6
	movs r0, #1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xd6
	ldrh r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _081D29F2
	movs r0, #0xac
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _081D2940 @ =0x00000261
	bl sound_08240740
	ldr r0, _081D2944 @ =0x00000289
	bl sound_08240740
	ldr r0, _081D2948 @ =0x0000028A
	bl sound_08240740
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D294C @ =0x00000159
	bl PlaySound_082406e0
	b _081D29F2
	.align 2, 0
_081D293C: .4byte 0x03002BE0
_081D2940: .4byte 0x00000261
_081D2944: .4byte 0x00000289
_081D2948: .4byte 0x0000028A
_081D294C: .4byte 0x00000159
_081D2950:
	adds r4, r5, #0
	adds r4, #0xfe
	adds r2, r5, #0
	adds r2, #0xba
	ldrh r0, [r4]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r2]
	rsbs r0, r0, #0
	movs r2, #0x5a
	adds r2, r2, r5
	mov r8, r2
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #0xcc
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldr r0, [r0]
	cmp r0, r1
	blt _081D29F2
	strh r0, [r4]
	ldr r6, _081D2A00 @ =0x03002BE0
	ldr r0, [r6]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D29AE
	ldr r0, [r6]
	ldr r1, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	str r1, [sp]
	str r2, [sp, #4]
	ldrh r2, [r4]
	mov r1, sp
	strh r2, [r1, #2]
	bl FUN_0807a91c
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
	mov r1, sb
	mov r0, r8
	strh r1, [r0]
_081D29AE:
	adds r0, r5, #0
	adds r0, #0xb2
	movs r1, #4
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xb6
	movs r0, #1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xd6
	ldrh r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _081D29F2
	movs r0, #0xac
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _081D2A04 @ =0x00000261
	bl sound_08240740
	ldr r0, _081D2A08 @ =0x00000289
	bl sound_08240740
	ldr r0, _081D2A0C @ =0x0000028A
	bl sound_08240740
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D2A10 @ =0x00000159
	bl PlaySound_082406e0
_081D29F2:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D2A00: .4byte 0x03002BE0
_081D2A04: .4byte 0x00000261
_081D2A08: .4byte 0x00000289
_081D2A0C: .4byte 0x0000028A
_081D2A10: .4byte 0x00000159

	thumb_func_start FUN_081d2a14
FUN_081d2a14: @ 0x081D2A14
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0xf4
	adds r1, r5, #0
	adds r1, #0xe8
	adds r2, r5, #0
	adds r2, #0x58
	adds r4, r5, #0
	adds r4, #0xba
	movs r6, #0
	ldrsh r3, [r4, r6]
	str r3, [sp]
	movs r6, #0
	ldrsh r4, [r4, r6]
	str r4, [sp, #4]
	bl FUN_081d2698
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D2A54
	adds r1, r5, #0
	adds r1, #0xb2
	movs r0, #3
	strh r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_081d5588
	b _081D2A5A
_081D2A54:
	adds r0, r5, #0
	bl FUN_081d2368
_081D2A5A:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d2a64
FUN_081d2a64: @ 0x081D2A64
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	movs r4, #0
	adds r3, r5, #0
	adds r3, #0xce
	movs r0, #0x1c
	adds r0, r0, r5
	mov ip, r0
_081D2A76:
	ldr r1, _081D2A8C @ =0x000012AC
	adds r0, r5, r1
	movs r1, #1
	lsls r1, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D2A90
	movs r0, #1
	b _081D2A92
	.align 2, 0
_081D2A8C: .4byte 0x000012AC
_081D2A90:
	movs r0, #0
_081D2A92:
	cmp r0, #0
	beq _081D2B10
	movs r0, #0
	ldrsh r2, [r3, r0]
	cmp r2, #6
	beq _081D2B10
	ldrh r1, [r3, #0x24]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081D2B10
	cmp r2, #1
	beq _081D2AE0
	ldr r1, _081D2AD4 @ =0x000012B4
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #1
	beq _081D2AB8
	b _081D2BFC
_081D2AB8:
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D2AD8 @ =0x0000028A
	bl sound_08240740
	ldr r0, _081D2ADC @ =0x00000289
	bl sound_08240740
	movs r0, #0
	strb r0, [r4]
	b _081D2BFC
	.align 2, 0
_081D2AD4: .4byte 0x000012B4
_081D2AD8: .4byte 0x0000028A
_081D2ADC: .4byte 0x00000289
_081D2AE0:
	ldr r1, _081D2B00 @ =0x000012B4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D2AEC
	b _081D2BFC
_081D2AEC:
	mov r0, ip
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D2B08
	cmp r0, #3
	beq _081D2BC4
	ldr r0, _081D2B04 @ =0x00000289
	b _081D2BC8
	.align 2, 0
_081D2B00: .4byte 0x000012B4
_081D2B04: .4byte 0x00000289
_081D2B08:
	ldr r0, _081D2B0C @ =0x0000028A
	b _081D2BC8
	.align 2, 0
_081D2B0C: .4byte 0x0000028A
_081D2B10:
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r3, r3, r1
	add ip, r1
	adds r4, #1
	cmp r4, #0xb
	ble _081D2A76
	ldr r4, _081D2B84 @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D2B2E
	movs r7, #1
_081D2B2E:
	ldr r0, [r4]
	ldr r1, _081D2B88 @ =0x00000392
	adds r0, r0, r1
	ldrh r0, [r0]
	bl FUN_081d3118
	adds r2, r0, #0
	cmp r2, #0
	beq _081D2BFC
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	cmp r6, #0
	bne _081D2BFC
	cmp r7, #0
	beq _081D2BDC
	adds r0, r2, #0
	adds r0, #0xb2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _081D2B98
	ldr r0, _081D2B8C @ =0x000012B4
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #1
	bne _081D2BFC
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D2B90 @ =0x0000028A
	bl sound_08240740
	ldr r0, _081D2B94 @ =0x00000289
	bl sound_08240740
	strb r6, [r4]
	b _081D2BFC
	.align 2, 0
_081D2B84: .4byte 0x03002BE0
_081D2B88: .4byte 0x00000392
_081D2B8C: .4byte 0x000012B4
_081D2B90: .4byte 0x0000028A
_081D2B94: .4byte 0x00000289
_081D2B98:
	ldr r1, _081D2BB4 @ =0x000012B4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D2BFC
	adds r0, r2, #0
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D2BBC
	cmp r0, #3
	beq _081D2BC4
	ldr r0, _081D2BB8 @ =0x00000289
	b _081D2BC8
	.align 2, 0
_081D2BB4: .4byte 0x000012B4
_081D2BB8: .4byte 0x00000289
_081D2BBC:
	ldr r0, _081D2BC0 @ =0x0000028A
	b _081D2BC8
	.align 2, 0
_081D2BC0: .4byte 0x0000028A
_081D2BC4:
	movs r0, #0xa2
	lsls r0, r0, #2
_081D2BC8:
	bl PlaySound_082406e0
	ldr r0, _081D2BD8 @ =0x000012B4
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _081D2BFC
	.align 2, 0
_081D2BD8: .4byte 0x000012B4
_081D2BDC:
	ldr r1, _081D2C04 @ =0x000012B4
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #1
	bne _081D2BFC
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D2C08 @ =0x0000028A
	bl sound_08240740
	ldr r0, _081D2C0C @ =0x00000289
	bl sound_08240740
	strb r7, [r4]
_081D2BFC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D2C04: .4byte 0x000012B4
_081D2C08: .4byte 0x0000028A
_081D2C0C: .4byte 0x00000289

	thumb_func_start FUN_081d2c10
FUN_081d2c10: @ 0x081D2C10
	push {lr}
	sub sp, #8
	ldr r0, _081D2C58 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	str r1, [sp]
	str r2, [sp, #4]
	mov r1, sp
	ldrh r2, [r1]
	adds r2, #0x80
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _081D2C5C @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r2
	str r1, [sp]
	mov r1, sp
	bl FUN_0807a91c
	mov r0, sp
	bl FUN_08086a28
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x80
	mov r1, sp
	strh r0, [r1]
	mov r0, sp
	bl FUN_08086a4c
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_081D2C58: .4byte 0x03002BE0
_081D2C5C: .4byte 0xFFFF0000

	thumb_func_start FUN_081d2c60
FUN_081d2c60: @ 0x081D2C60
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r2, r0, #0
	ldr r0, _081D2CE4 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _081D2CEC
	mov r4, sp
	adds r2, #0xfc
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	subs r5, r1, r0
	strh r5, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r0, [r2, #4]
	subs r2, r1, r0
	strh r2, [r4, #4]
	ldr r3, _081D2CE8 @ =0x085AE0D0
	mov r0, sp
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r6, #0
	ldrsh r0, [r3, r6]
	cmp r1, r0
	bgt _081D2CEC
	mov r0, sp
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r6, #0
	ldrsh r0, [r3, r6]
	cmn r1, r0
	blt _081D2CEC
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r5, #2
	ldrsh r1, [r3, r5]
	cmp r0, r1
	bgt _081D2CEC
	movs r6, #2
	ldrsh r1, [r4, r6]
	movs r5, #2
	ldrsh r0, [r3, r5]
	cmn r1, r0
	blt _081D2CEC
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r6, #4
	ldrsh r1, [r3, r6]
	cmp r0, r1
	bgt _081D2CEC
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D2CEC
	movs r0, #1
	b _081D2CEE
	.align 2, 0
_081D2CE4: .4byte 0x03002BE0
_081D2CE8: .4byte 0x085AE0D0
_081D2CEC:
	movs r0, #0
_081D2CEE:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d2cf8
FUN_081d2cf8: @ 0x081D2CF8
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r4, r0, #0
	adds r0, #0xb6
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D2D96
	ldr r0, _081D2D3C @ =0x03000194
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xd4
	ldr r2, _081D2D40 @ =0x000012B0
	adds r0, r0, r2
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081D2D88
	adds r0, r4, #0
	adds r0, #0xc2
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _081D2D88
	adds r0, #0x25
	ldrb r1, [r0]
	cmp r1, #2
	bne _081D2D52
	subs r0, #0x33
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D2D44
	movs r0, #1
	b _081D2D46
	.align 2, 0
_081D2D3C: .4byte 0x03000194
_081D2D40: .4byte 0x000012B0
_081D2D44:
	movs r0, #0
_081D2D46:
	cmp r0, #0
	beq _081D2D4E
	movs r0, #2
	b _081D2D58
_081D2D4E:
	movs r0, #1
	b _081D2D58
_081D2D52:
	adds r0, r4, #0
	adds r0, #0xea
	ldrb r0, [r0]
_081D2D58:
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0xfc
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	ldr r1, _081D2DF0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081D2D88:
	adds r1, r4, #0
	adds r1, #0xb6
	movs r0, #0
	strb r0, [r1]
	adds r1, #2
	movs r0, #1
	strh r0, [r1]
_081D2D96:
	adds r0, r4, #0
	bl FUN_081d27c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D2DA4
	b _081D2EFA
_081D2DA4:
	adds r0, r4, #0
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081D2E78
	adds r0, r4, #0
	adds r0, #0xb8
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r1, r4, #0
	adds r1, #0xbc
	adds r5, r0, #0
	adds r6, r1, #0
	ldrh r0, [r6]
	cmp r2, r0
	blt _081D2E60
	adds r0, r4, #0
	bl FUN_081d2c60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D2E60
	adds r0, r4, #0
	adds r0, #0xb2
	movs r2, #2
	strh r2, [r0]
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081D2DF4
	movs r0, #1
	b _081D2DF6
	.align 2, 0
_081D2DF0: .4byte 0xFFFF0000
_081D2DF4:
	movs r0, #0
_081D2DF6:
	cmp r0, #0
	beq _081D2E04
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	b _081D2E0A
_081D2E04:
	movs r0, #2
	ldrh r1, [r2]
	orrs r0, r1
_081D2E0A:
	strh r0, [r2]
	movs r0, #0
	strh r0, [r5]
	adds r0, r4, #0
	adds r0, #0xb6
	movs r5, #1
	strb r5, [r0]
	ldr r0, _081D2E54 @ =0x03000194
	ldr r0, [r0]
	adds r3, r4, #0
	adds r3, #0xd4
	ldr r1, _081D2E58 @ =0x000012B0
	adds r0, r0, r1
	ldrh r1, [r3]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081D2EFA
	adds r2, r4, #0
	adds r2, #0xc4
	ldrh r0, [r2]
	cmp r0, #0
	beq _081D2EFA
	adds r0, r1, #0
	str r0, [sp, #0x14]
	ldr r1, _081D2E5C @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r1
	orrs r0, r5
	str r0, [sp, #0x18]
	add r0, sp, #0x14
	add r1, sp, #0x18
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
	b _081D2EFA
	.align 2, 0
_081D2E54: .4byte 0x03000194
_081D2E58: .4byte 0x000012B0
_081D2E5C: .4byte 0xFFFF0000
_081D2E60:
	movs r2, #0
	ldrsh r1, [r5, r2]
	ldrh r0, [r6]
	subs r0, #0xa
	cmp r1, r0
	ble _081D2E78
	movs r0, #0x20
	adds r2, r4, #0
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D2E78:
	ldr r0, _081D2EAC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x2c
	bl FUN_081d2230
	adds r3, r0, #0
	cmp r3, #0
	beq _081D2EF0
	adds r0, #0xd4
	adds r1, r4, #0
	adds r1, #0xd4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D2EFA
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r4, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D2EB0
	movs r0, #1
	b _081D2EB2
	.align 2, 0
_081D2EAC: .4byte 0x03002BE0
_081D2EB0:
	movs r0, #0
_081D2EB2:
	adds r5, r4, #0
	adds r5, #0xb8
	cmp r0, #0
	bne _081D2ED0
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _081D2ED0
	adds r0, r4, #0
	adds r0, #0xc6
	ldr r1, _081D2EE4 @ =0x0000FFE0
	strh r1, [r0]
	ldr r0, _081D2EE8 @ =0x00000222
	bl PlaySound_082406e0
_081D2ED0:
	ldrh r2, [r5]
	movs r0, #0
	ldrsh r1, [r5, r0]
	ldr r0, _081D2EEC @ =0x00007CFF
	cmp r1, r0
	bgt _081D2EFA
	adds r0, r2, #1
	strh r0, [r5]
	b _081D2EFA
	.align 2, 0
_081D2EE4: .4byte 0x0000FFE0
_081D2EE8: .4byte 0x00000222
_081D2EEC: .4byte 0x00007CFF
_081D2EF0:
	adds r0, r4, #0
	adds r0, #0xb8
	strh r3, [r0]
	adds r0, #0xe
	strh r3, [r0]
_081D2EFA:
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d2f04
FUN_081d2f04: @ 0x081D2F04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0xc6
	ldrh r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bge _081D2F2C
	ldrh r2, [r7, #0x1e]
	adds r0, r1, r2
	strh r0, [r7, #0x1e]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #2
	bl Div
	strh r0, [r4]
_081D2F2C:
	movs r2, #0x80
	adds r1, r7, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081D2F40
	movs r0, #1
	b _081D2F42
_081D2F40:
	movs r0, #0
_081D2F42:
	cmp r0, #0
	bne _081D2FAE
	movs r1, #0x20
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D2F54
	movs r0, #1
	b _081D2F56
_081D2F54:
	movs r0, #0
_081D2F56:
	cmp r0, #0
	beq _081D2FB8
	ldr r2, _081D2FC4 @ =0x0203B400
	mov r8, r2
	ldr r4, _081D2FC8 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _081D2FCC @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0xc
	bl Mod
	ldrh r1, [r7, #0x1c]
	subs r1, #6
	adds r1, r1, r0
	strh r1, [r7, #0x1c]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	add r1, r8
	ldrh r1, [r1]
	movs r2, #3
	ands r1, r2
	ldrh r2, [r7, #0x1e]
	adds r1, r1, r2
	strh r1, [r7, #0x1e]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0xc
	bl Mod
	ldrh r1, [r7, #0x20]
	subs r1, #6
	adds r1, r1, r0
	strh r1, [r7, #0x20]
_081D2FAE:
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
_081D2FB8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D2FC4: .4byte 0x0203B400
_081D2FC8: .4byte 0x030046B8
_081D2FCC: .4byte 0x000003FF

	thumb_func_start FUN_081d2fd0
FUN_081d2fd0: @ 0x081D2FD0
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r5, r0, #0
	adds r0, #0xb6
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D306E
	ldr r0, _081D3014 @ =0x03000194
	ldr r0, [r0]
	adds r1, r5, #0
	adds r1, #0xd4
	ldr r2, _081D3018 @ =0x000012B0
	adds r0, r0, r2
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081D3060
	adds r0, r5, #0
	adds r0, #0xc2
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _081D3060
	adds r0, #0x25
	ldrb r1, [r0]
	cmp r1, #2
	bne _081D302A
	subs r0, #0x33
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D301C
	movs r0, #1
	b _081D301E
	.align 2, 0
_081D3014: .4byte 0x03000194
_081D3018: .4byte 0x000012B0
_081D301C:
	movs r0, #0
_081D301E:
	cmp r0, #0
	beq _081D3026
	movs r0, #2
	b _081D3030
_081D3026:
	movs r0, #1
	b _081D3030
_081D302A:
	adds r0, r5, #0
	adds r0, #0xea
	ldrb r0, [r0]
_081D3030:
	str r0, [sp]
	adds r0, r5, #0
	adds r0, #0xfc
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	ldr r1, _081D30F0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081D3060:
	adds r0, r5, #0
	adds r0, #0xb8
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	subs r0, #2
	strb r2, [r0]
_081D306E:
	ldr r6, _081D30F4 @ =0x03000194
	adds r0, r5, #0
	bl FUN_081d27c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D3108
	adds r4, r5, #0
	adds r4, #0xe8
	ldrb r1, [r4, #3]
	adds r0, r1, #1
	strb r0, [r4, #3]
	lsls r1, r1, #0x18
	ldr r0, [r4, #8]
	ldrh r2, [r0, #4]
	ldr r0, _081D30F8 @ =0x00000FFF
	lsrs r1, r1, #0x18
	ands r0, r2
	cmp r1, r0
	blo _081D3108
	adds r0, r4, #0
	bl FUN_08234e3c
	adds r1, r5, #0
	adds r1, #0xfc
	adds r0, r4, #0
	movs r2, #0x10
	movs r3, #0x10
	bl FUN_08235038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D3100
	adds r0, r5, #0
	adds r0, #0xb2
	movs r4, #1
	strh r4, [r0]
	ldr r0, [r6]
	adds r2, r5, #0
	adds r2, #0xd4
	ldr r1, _081D30FC @ =0x000012B0
	adds r0, r0, r1
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081D3108
	adds r3, r5, #0
	adds r3, #0xc4
	ldrh r0, [r3]
	cmp r0, #0
	beq _081D3108
	adds r0, r1, #0
	str r0, [sp, #0x14]
	ldr r1, _081D30F0 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r1
	orrs r0, r4
	str r0, [sp, #0x18]
	add r0, sp, #0x14
	add r1, sp, #0x18
	str r0, [r1, #4]
	ldrh r0, [r3]
	bl Script_ExecById
	b _081D3108
	.align 2, 0
_081D30F0: .4byte 0xFFFF0000
_081D30F4: .4byte 0x03000194
_081D30F8: .4byte 0x00000FFF
_081D30FC: .4byte 0x000012B0
_081D3100:
	adds r1, r5, #0
	adds r1, #0xb2
	movs r0, #3
	strh r0, [r1]
_081D3108:
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d3110
FUN_081d3110: @ 0x081D3110
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d3114
FUN_081d3114: @ 0x081D3114
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d3118
FUN_081d3118: @ 0x081D3118
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081D3138 @ =0x03000194
	ldr r0, [r0]
	movs r4, #0
	adds r2, r0, #0
	adds r2, #0x1c
	adds r1, r0, #0
	adds r1, #0xf0
	movs r3, #0xc6
	lsls r3, r3, #1
_081D312E:
	ldrh r0, [r1]
	cmp r0, r5
	bne _081D313C
	adds r0, r2, #0
	b _081D3148
	.align 2, 0
_081D3138: .4byte 0x03000194
_081D313C:
	adds r2, r2, r3
	adds r1, r1, r3
	adds r4, #1
	cmp r4, #0xb
	ble _081D312E
	movs r0, #0
_081D3148:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d3150
FUN_081d3150: @ 0x081D3150
	push {r4, r5, lr}
	ldr r0, _081D3180 @ =0x03000194
	ldr r1, [r0]
	movs r3, #0
	ldr r2, _081D3184 @ =0x000012B0
	adds r0, r1, r2
	ldrh r4, [r0]
	adds r0, r1, #0
	adds r0, #0x1c
	adds r1, #0xf0
	movs r2, #0xc6
	lsls r2, r2, #1
_081D3168:
	ldrh r5, [r1]
	cmp r4, r5
	beq _081D317A
	adds r0, r0, r2
	adds r1, r1, r2
	adds r3, #1
	cmp r3, #0xb
	ble _081D3168
	movs r0, #0
_081D317A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081D3180: .4byte 0x03000194
_081D3184: .4byte 0x000012B0

	thumb_func_start FUN_081d3188
FUN_081d3188: @ 0x081D3188
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, #0xb4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D31A2
	movs r0, #1
	b _081D31A4
_081D31A2:
	movs r0, #0
_081D31A4:
	cmp r0, #0
	beq _081D31E0
	movs r6, #0
	movs r0, #0xb4
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r5, r7, r1
_081D31B6:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	adds r4, r0, r6
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D31CE
	adds r0, r5, #0
	bl FUN_082342a8
	movs r0, #0
	strb r0, [r4]
_081D31CE:
	adds r5, #0x10
	adds r6, #1
	cmp r6, #3
	ble _081D31B6
	ldr r0, _081D31EC @ =0xFFFFF7FF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081D31E0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D31EC: .4byte 0xFFFFF7FF

	thumb_func_start FUN_081d31f0
FUN_081d31f0: @ 0x081D31F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	ldr r0, _081D3244 @ =0x03000194
	ldr r1, [r0]
	cmp r1, #0
	beq _081D323C
	mov r0, r8
	adds r0, #0xd4
	ldr r2, _081D3248 @ =0x000012B0
	adds r1, r1, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D323C
	mov r0, r8
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #2
	beq _081D323C
	ldr r0, _081D324C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _081D323C
	mov r0, r8
	adds r0, #0xb2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #3
	beq _081D3250
_081D323C:
	mov r0, r8
	bl FUN_081d3188
	b _081D33E2
	.align 2, 0
_081D3244: .4byte 0x03000194
_081D3248: .4byte 0x000012B0
_081D324C: .4byte 0x03002BE0
_081D3250:
	movs r2, #0x80
	lsls r2, r2, #4
	mov r1, r8
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0x14]
	cmp r0, #0
	beq _081D3266
	movs r0, #1
	b _081D3268
_081D3266:
	movs r0, #0
_081D3268:
	cmp r0, #0
	beq _081D326E
	b _081D33E2
_081D326E:
	mov r0, r8
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D3296
	cmp r1, #0
	blt _081D3296
	ldr r0, _081D329C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3296
	ldr r0, _081D32A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D32A4
_081D3296:
	movs r0, #0
	b _081D32B2
	.align 2, 0
_081D329C: .4byte 0x030046A8
_081D32A0: .4byte 0x030046AC
_081D32A4:
	ldr r0, _081D32D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D32B2:
	str r0, [sp, #0x10]
	ldr r5, [sp, #0x10]
	adds r5, #1
	movs r1, #0
	mov sl, r1
	movs r2, #0xa4
	lsls r2, r2, #1
	add r2, r8
	str r2, [sp, #0x18]
_081D32C4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D32D8
	adds r0, #4
	b _081D32E4
	.align 2, 0
_081D32D4: .4byte 0x030046A4
_081D32D8:
	ldr r0, _081D32F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D32E4:
	ldrh r0, [r0, #2]
	movs r1, #0xc0
	ands r0, r1
	cmp r0, #0
	bne _081D32F8
	movs r0, #0
	b _081D32FA
	.align 2, 0
_081D32F4: .4byte 0x030046A4
_081D32F8:
	movs r0, #1
_081D32FA:
	cmp r0, #0
	beq _081D3390
	mov r0, r8
	adds r0, #0xfe
	ldrh r3, [r0]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x18
	movs r0, #0xff
	str r0, [sp]
	movs r0, #5
	str r0, [sp, #4]
	ldr r0, [sp, #0x18]
	adds r1, r5, #0
	movs r2, #0
	bl FUN_08234270
	movs r0, #0xc4
	lsls r0, r0, #1
	add r0, r8
	add r0, sl
	movs r1, #1
	strb r1, [r0]
	add r0, sp, #8
	mov sb, r0
	ldr r6, _081D3364 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #8
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3368
	adds r0, #4
	b _081D3372
	.align 2, 0
_081D3364: .4byte 0x030046A4
_081D3368:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081D3372:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sb
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r2, [sp, #0x14]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D3390:
	mov r0, sl
	cmp r0, #1
	beq _081D33BC
	cmp r0, #1
	bgt _081D33A0
	cmp r0, #0
	beq _081D33A8
	b _081D33D0
_081D33A0:
	mov r1, sl
	cmp r1, #2
	beq _081D33C2
	b _081D33D0
_081D33A8:
	ldr r0, _081D33B8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #0x10]
	adds r5, r1, r0
	b _081D33D0
	.align 2, 0
_081D33B8: .4byte 0x030046A4
_081D33BC:
	ldr r5, [sp, #0x10]
	subs r5, #1
	b _081D33D0
_081D33C2:
	ldr r0, _081D33F4 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #0x10]
	subs r5, r1, r0
_081D33D0:
	ldr r2, [sp, #0x18]
	adds r2, #0x10
	str r2, [sp, #0x18]
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	bgt _081D33E2
	b _081D32C4
_081D33E2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D33F4: .4byte 0x030046A4

	thumb_func_start FUN_081d33f8
FUN_081d33f8: @ 0x081D33F8
	push {r4, r5, lr}
	sub sp, #8
	mov ip, r0
	adds r0, #0xb2
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _081D343A
	movs r2, #1
	mov r1, ip
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D3420
	movs r0, #1
	b _081D3422
_081D3420:
	movs r0, #0
_081D3422:
	cmp r0, #0
	beq _081D34E0
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, ip
	bl FUN_082342a8
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	b _081D34DE
_081D343A:
	movs r2, #1
	mov r1, ip
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D344E
	movs r0, #1
	b _081D3450
_081D344E:
	movs r0, #0
_081D3450:
	cmp r0, #0
	bne _081D34E0
	ldr r0, _081D34A0 @ =0x030046A4
	ldr r3, [r0]
	cmp r3, #0
	beq _081D34E0
	mov r2, ip
	adds r2, #0xfe
	ldr r0, _081D34A4 @ =0x03002BE0
	ldr r0, [r0]
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r5, #0x2e
	ldrsh r0, [r0, r5]
	adds r5, r2, #0
	cmp r1, r0
	bne _081D34E0
	mov r0, ip
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D349A
	cmp r1, #0
	blt _081D349A
	ldr r0, _081D34A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D349A
	ldr r0, _081D34AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D34B0
_081D349A:
	movs r2, #0
	b _081D34BC
	.align 2, 0
_081D34A0: .4byte 0x030046A4
_081D34A4: .4byte 0x03002BE0
_081D34A8: .4byte 0x030046A8
_081D34AC: .4byte 0x030046AC
_081D34B0:
	lsls r0, r1, #1
	adds r1, r3, #0
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r2, r0, r2
_081D34BC:
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, ip
	ldrh r3, [r5]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x18
	movs r1, #0xff
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl FUN_08234270
	movs r0, #1
	ldrh r1, [r4]
	orrs r0, r1
_081D34DE:
	strh r0, [r4]
_081D34E0:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d34e8
FUN_081d34e8: @ 0x081D34E8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081D3508 @ =0x03000194
	movs r3, #0
	movs r6, #1
	ldr r1, [r0]
	adds r2, r1, #0
	adds r2, #0xd0
	movs r4, #0xc6
	lsls r4, r4, #1
_081D34FC:
	ldrh r0, [r2]
	ands r0, r6
	cmp r0, #0
	beq _081D350C
	movs r0, #1
	b _081D350E
	.align 2, 0
_081D3508: .4byte 0x03000194
_081D350C:
	movs r0, #0
_081D350E:
	cmp r0, #0
	beq _081D3522
	movs r7, #0xab
	lsls r7, r7, #1
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, r5
	bne _081D3522
	movs r0, #1
	b _081D352E
_081D3522:
	adds r1, r1, r4
	adds r2, r2, r4
	adds r3, #1
	cmp r3, #0xb
	ble _081D34FC
	movs r0, #0
_081D352E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d3534
FUN_081d3534: @ 0x081D3534
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sl, r0
	movs r0, #0
	str r0, [sp, #8]
	ldr r7, _081D3578 @ =0x03002BE0
	movs r1, #0xfc
	add r1, sl
	mov r8, r1
_081D354E:
	ldr r0, [r7]
	cmp r0, #0
	bne _081D3556
	b _081D3694
_081D3556:
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	bne _081D3562
	b _081D3694
_081D3562:
	movs r2, #8
	mov r1, sl
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D357C
	movs r0, #1
	b _081D357E
	.align 2, 0
_081D3578: .4byte 0x03002BE0
_081D357C:
	movs r0, #0
_081D357E:
	cmp r0, #0
	bne _081D3584
	b _081D3694
_081D3584:
	ldr r0, [r7]
	ldrh r1, [r0, #0x2c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D35AA
	cmp r1, #0
	blt _081D35AA
	ldr r0, _081D35B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D35AA
	ldr r0, _081D35B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D35B8
_081D35AA:
	movs r4, #0
	b _081D35C6
	.align 2, 0
_081D35B0: .4byte 0x030046A8
_081D35B4: .4byte 0x030046AC
_081D35B8:
	ldr r0, _081D35E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D35C6:
	adds r0, r4, #0
	bl FUN_081d34e8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D3694
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D35E8
	adds r0, #4
	b _081D35F4
	.align 2, 0
_081D35E4: .4byte 0x030046A4
_081D35E8:
	ldr r0, _081D36B4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D35F4:
	ldrh r0, [r0, #2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081D3694
	mov r3, sp
	ldr r0, [r7]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r1, [r0, #0x2c]
	mov r4, r8
	ldrh r0, [r4]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	ldrh r0, [r4, #2]
	subs r4, r1, r0
	strh r4, [r3, #2]
	ldrh r1, [r2, #4]
	mov r6, r8
	ldrh r0, [r6, #4]
	subs r5, r1, r0
	strh r5, [r3, #4]
	ldr r2, _081D36B8 @ =0x085AE0D0
	mov r0, sp
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r6, #0
	ldrsh r0, [r2, r6]
	ldr r6, _081D36BC @ =0x03002BE0
	mov ip, r6
	mov r6, sl
	adds r6, #0xfc
	str r6, [sp, #0xc]
	cmp r1, r0
	bgt _081D367C
	mov r0, sp
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r6, #0
	ldrsh r0, [r2, r6]
	cmn r1, r0
	blt _081D367C
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #2
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D367C
	movs r6, #2
	ldrsh r1, [r3, r6]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmn r1, r0
	blt _081D367C
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r6, #4
	ldrsh r1, [r2, r6]
	cmp r0, r1
	bgt _081D367C
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmn r1, r0
	bge _081D3694
_081D367C:
	ldr r0, [sp, #8]
	add r0, ip
	ldr r0, [r0]
	ldr r1, [sp, #0xc]
	bl FUN_0807a9b8
	movs r0, #0x80
	lsls r0, r0, #1
	mov r4, sb
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
_081D3694:
	ldr r6, [sp, #8]
	adds r6, #4
	str r6, [sp, #8]
	adds r7, #4
	ldr r0, _081D36BC @ =0x03002BE0
	cmp r7, r0
	bgt _081D36A4
	b _081D354E
_081D36A4:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D36B4: .4byte 0x030046A4
_081D36B8: .4byte 0x085AE0D0
_081D36BC: .4byte 0x03002BE0

	thumb_func_start FUN_081d36c0
FUN_081d36c0: @ 0x081D36C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _081D3710 @ =0x03002BE0
	mov sl, r0
	mov r6, sp
	mov r8, sl
_081D36D6:
	movs r1, #0
	mov sb, r1
	mov r3, r8
	ldr r0, [r3]
	cmp r0, #0
	bne _081D36E4
	b _081D3884
_081D36E4:
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	bne _081D36FE
	mov r4, r8
	ldr r0, [r4]
	movs r1, #2
	bl FUN_0807a954
	cmp r0, #0
	bne _081D36FE
	b _081D388E
_081D36FE:
	movs r1, #8
	adds r0, r7, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D3714
	movs r0, #1
	b _081D3716
	.align 2, 0
_081D3710: .4byte 0x03002BE0
_081D3714:
	movs r0, #0
_081D3716:
	cmp r0, #0
	bne _081D371C
	b _081D3884
_081D371C:
	mov r1, r8
	ldr r0, [r1]
	ldrh r1, [r0, #0x2c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D3744
	cmp r1, #0
	blt _081D3744
	ldr r0, _081D3748 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3744
	ldr r0, _081D374C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D3750
_081D3744:
	movs r4, #0
	b _081D375E
	.align 2, 0
_081D3748: .4byte 0x030046A8
_081D374C: .4byte 0x030046AC
_081D3750:
	ldr r0, _081D3770 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D375E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3774
	adds r0, #4
	b _081D3780
	.align 2, 0
_081D3770: .4byte 0x030046A4
_081D3774:
	ldr r0, _081D3818 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D3780:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _081D3884
	adds r0, r4, #0
	bl FUN_081d34e8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D3884
	mov r5, sp
	adds r2, r7, #0
	adds r2, #0xfc
	mov r3, r8
	ldr r0, [r3]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	subs r4, r1, r0
	strh r4, [r5, #2]
	ldrh r1, [r3, #4]
	ldrh r0, [r2, #4]
	subs r3, r1, r0
	strh r3, [r5, #4]
	adds r0, r7, #0
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081D3820
	ldr r2, _081D381C @ =0x085AE0D0
	movs r1, #0
	ldrsh r0, [r6, r1]
	mov ip, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp ip, r0
	bgt _081D3874
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r1, ip
	cmn r1, r0
	blt _081D3874
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #2
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D3874
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmn r1, r0
	blt _081D3874
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	movs r3, #4
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _081D3874
	movs r4, #4
	ldrsh r1, [r5, r4]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmn r1, r0
	bge _081D386E
	b _081D3874
	.align 2, 0
_081D3818: .4byte 0x030046A4
_081D381C: .4byte 0x085AE0D0
_081D3820:
	ldr r2, _081D38A0 @ =0x085AE0D8
	movs r1, #0
	ldrsh r0, [r6, r1]
	mov ip, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp ip, r0
	bgt _081D386A
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r1, ip
	cmn r1, r0
	blt _081D386A
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #2
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D386A
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmn r1, r0
	blt _081D386A
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	movs r3, #4
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _081D386A
	movs r4, #4
	ldrsh r1, [r5, r4]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmn r1, r0
	bge _081D386E
_081D386A:
	movs r4, #1
	mov sb, r4
_081D386E:
	mov r0, sb
	cmp r0, #0
	beq _081D3884
_081D3874:
	adds r1, r7, #0
	adds r1, #0xc0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081D3884
	movs r1, #0
	bl Script_ExecById
_081D3884:
	movs r1, #4
	add r8, r1
	cmp r8, sl
	bgt _081D388E
	b _081D36D6
_081D388E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D38A0: .4byte 0x085AE0D8

	thumb_func_start FUN_081d38a4
FUN_081d38a4: @ 0x081D38A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sb, r0
	mov r6, sp
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r1, _081D38F8 @ =0x03002BE0
	mov sl, r1
_081D38BC:
	mov r2, sl
	ldr r1, [r2]
	cmp r1, #0
	bne _081D38C6
	b _081D3A66
_081D38C6:
	mov r0, sb
	adds r0, #0xb2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #4
	bne _081D38D4
	b _081D3A66
_081D38D4:
	adds r0, r1, #0
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	bne _081D38E2
	b _081D3A66
_081D38E2:
	movs r2, #8
	mov r1, sb
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #8]
	cmp r0, #0
	beq _081D38FC
	movs r0, #1
	b _081D38FE
	.align 2, 0
_081D38F8: .4byte 0x03002BE0
_081D38FC:
	movs r0, #0
_081D38FE:
	cmp r0, #0
	bne _081D3904
	b _081D3A78
_081D3904:
	mov r0, sb
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r0
	cmp r2, #0
	blt _081D392E
	cmp r1, #0
	blt _081D392E
	ldr r0, _081D3934 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D392E
	ldr r0, _081D3938 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D393C
_081D392E:
	movs r0, #0
	b _081D394A
	.align 2, 0
_081D3934: .4byte 0x030046A8
_081D3938: .4byte 0x030046AC
_081D393C:
	ldr r0, _081D39F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D394A:
	bl FUN_081d34e8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D396A
	mov r4, sl
	ldr r0, [r4]
	mov r2, sb
	adds r2, #0xfe
	movs r5, #0x2e
	ldrsh r1, [r0, r5]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bne _081D396A
	b _081D3A66
_081D396A:
	mov r3, sp
	mov r4, sl
	ldr r0, [r4]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r0, [r0, #0x2c]
	mov r5, r8
	ldrh r1, [r5]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r1, [r2, #2]
	ldrh r0, [r5, #2]
	subs r5, r1, r0
	strh r5, [r3, #2]
	ldrh r1, [r2, #4]
	mov r2, r8
	ldrh r0, [r2, #4]
	subs r7, r1, r0
	strh r7, [r3, #4]
	ldr r0, _081D39F4 @ =0x085AE0E0
	movs r4, #0
	ldrsh r2, [r6, r4]
	movs r4, #0
	ldrsh r1, [r0, r4]
	ldr r4, _081D39F8 @ =0x03002BE0
	mov ip, r4
	adds r4, r0, #0
	cmp r2, r1
	bgt _081D39EC
	adds r1, r2, #0
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmn r1, r0
	blt _081D39DE
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r5, #2
	ldrsh r1, [r4, r5]
	cmp r0, r1
	bgt _081D39DE
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r2, #2
	ldrsh r0, [r4, r2]
	cmn r1, r0
	blt _081D39DE
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	movs r5, #4
	ldrsh r1, [r4, r5]
	cmp r0, r1
	bgt _081D39DE
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	cmn r1, r0
	bge _081D3A66
_081D39DE:
	movs r3, #0
	ldrsh r1, [r6, r3]
	ldrh r2, [r4]
	movs r5, #0
	ldrsh r0, [r4, r5]
	cmp r1, r0
	ble _081D39FC
_081D39EC:
	ldrh r0, [r4]
	b _081D3A0A
	.align 2, 0
_081D39F0: .4byte 0x030046A4
_081D39F4: .4byte 0x085AE0E0
_081D39F8: .4byte 0x03002BE0
_081D39FC:
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmn r1, r0
	bge _081D3A0C
	rsbs r0, r2, #0
_081D3A0A:
	strh r0, [r6]
_081D3A0C:
	mov r2, sp
	movs r5, #4
	ldrsh r1, [r2, r5]
	ldrh r3, [r4, #4]
	movs r5, #4
	ldrsh r0, [r4, r5]
	cmp r1, r0
	ble _081D3A20
	strh r3, [r2, #4]
	b _081D3A30
_081D3A20:
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r5, #4
	ldrsh r0, [r4, r5]
	cmn r1, r0
	bge _081D3A30
	rsbs r0, r3, #0
	strh r0, [r2, #4]
_081D3A30:
	ldrh r0, [r6]
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r6]
	mov r0, sb
	adds r0, #0xfe
	ldrh r0, [r0]
	strh r0, [r6, #2]
	movs r4, #0x80
	lsls r4, r4, #1
	mov r2, sb
	adds r1, r2, r4
	ldrh r0, [r6, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, [sp, #0xc]
	add r0, ip
	ldr r0, [r0]
	mov r1, sp
	bl FUN_0807a91c
	ldr r3, [sp, #8]
	ldrh r0, [r3]
	orrs r4, r0
	strh r4, [r3]
_081D3A66:
	ldr r4, [sp, #0xc]
	adds r4, #4
	str r4, [sp, #0xc]
	movs r5, #4
	add sl, r5
	ldr r0, _081D3A88 @ =0x03002BE0
	cmp sl, r0
	bgt _081D3A78
	b _081D38BC
_081D3A78:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D3A88: .4byte 0x03002BE0

	thumb_func_start FUN_081d3a8c
FUN_081d3a8c: @ 0x081D3A8C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	bne _081D3AA2
	b _081D3C18
_081D3AA2:
	movs r2, #0x10
	adds r1, r7, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _081D3AB6
	movs r0, #1
	b _081D3AB8
_081D3AB6:
	movs r0, #0
_081D3AB8:
	cmp r0, #0
	bne _081D3ABE
	b _081D3C18
_081D3ABE:
	mov r0, sp
	bl FUN_08086a28
	adds r0, r7, #0
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r6, r0, #0
	cmp r2, #0
	blt _081D3AEE
	cmp r1, #0
	blt _081D3AEE
	ldr r0, _081D3AF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3AEE
	ldr r0, _081D3AF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D3AFC
_081D3AEE:
	movs r0, #0
	b _081D3B0A
	.align 2, 0
_081D3AF4: .4byte 0x030046A8
_081D3AF8: .4byte 0x030046AC
_081D3AFC:
	ldr r0, _081D3BA8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D3B0A:
	bl FUN_081d34e8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D3B28
	mov r0, sp
	adds r1, r7, #0
	adds r1, #0xfe
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	beq _081D3C18
_081D3B28:
	add r3, sp, #8
	mov r4, sp
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r6]
	subs r1, r1, r0
	strh r1, [r3]
	ldrh r2, [r4, #2]
	ldrh r0, [r6, #2]
	subs r2, r2, r0
	mov ip, r2
	mov r5, ip
	strh r5, [r3, #2]
	ldrh r2, [r4, #4]
	ldrh r0, [r6, #4]
	subs r4, r2, r0
	strh r4, [r3, #4]
	ldr r2, _081D3BAC @ =0x085AE0E0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bgt _081D3BA4
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmn r1, r0
	blt _081D3B96
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	movs r5, #2
	ldrsh r1, [r2, r5]
	cmp r0, r1
	bgt _081D3B96
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r5, #2
	ldrsh r0, [r2, r5]
	cmn r1, r0
	blt _081D3B96
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #4
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D3B96
	movs r5, #4
	ldrsh r1, [r3, r5]
	movs r4, #4
	ldrsh r0, [r2, r4]
	cmn r1, r0
	bge _081D3C18
_081D3B96:
	movs r5, #0
	ldrsh r1, [r3, r5]
	ldrh r4, [r2]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r1, r0
	ble _081D3BB0
_081D3BA4:
	ldrh r0, [r2]
	b _081D3BBE
	.align 2, 0
_081D3BA8: .4byte 0x030046A4
_081D3BAC: .4byte 0x085AE0E0
_081D3BB0:
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmn r1, r0
	bge _081D3BC0
	rsbs r0, r4, #0
_081D3BBE:
	strh r0, [r3]
_081D3BC0:
	movs r0, #4
	ldrsh r1, [r3, r0]
	ldrh r4, [r2, #4]
	movs r5, #4
	ldrsh r0, [r2, r5]
	cmp r1, r0
	ble _081D3BD2
	strh r4, [r3, #4]
	b _081D3BE2
_081D3BD2:
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r5, #4
	ldrsh r0, [r2, r5]
	cmn r1, r0
	bge _081D3BE2
	rsbs r0, r4, #0
	strh r0, [r3, #4]
_081D3BE2:
	ldrh r0, [r3]
	ldrh r6, [r6]
	adds r0, r0, r6
	mov r1, sp
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0xfe
	ldrh r0, [r0]
	mov r2, sp
	strh r0, [r2, #2]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	bl FUN_08086a4c
	movs r0, #0x80
	lsls r0, r0, #2
	mov r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D3C18:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d3c24
FUN_081d3c24: @ 0x081D3C24
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov r8, r0
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	bne _081D3C3C
	b _081D3DC0
_081D3C3C:
	movs r2, #0x10
	mov r1, r8
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D3C50
	movs r0, #1
	b _081D3C52
_081D3C50:
	movs r0, #0
_081D3C52:
	cmp r0, #0
	bne _081D3C58
	b _081D3DC0
_081D3C58:
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D3C86
	cmp r1, #0
	blt _081D3C86
	ldr r0, _081D3C8C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3C86
	ldr r0, _081D3C90 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D3C94
_081D3C86:
	movs r4, #0
	b _081D3CA2
	.align 2, 0
_081D3C8C: .4byte 0x030046A8
_081D3C90: .4byte 0x030046AC
_081D3C94:
	ldr r0, _081D3CB4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D3CA2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3CB8
	adds r0, #4
	b _081D3CC4
	.align 2, 0
_081D3CB4: .4byte 0x030046A4
_081D3CB8:
	ldr r0, _081D3D50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D3CC4:
	ldrh r0, [r0, #2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081D3DC0
	add r3, sp, #8
	mov r4, r8
	adds r4, #0xfc
	mov r5, sp
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r4]
	subs r1, r1, r0
	strh r1, [r3]
	ldrh r2, [r5, #2]
	ldrh r0, [r4, #2]
	subs r6, r2, r0
	strh r6, [r3, #2]
	ldrh r2, [r5, #4]
	ldrh r0, [r4, #4]
	subs r7, r2, r0
	strh r7, [r3, #4]
	ldr r0, _081D3D54 @ =0x085AE0D0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r5, #0
	ldrsh r2, [r0, r5]
	adds r5, r0, #0
	cmp r1, r2
	bgt _081D3D4A
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmn r1, r0
	blt _081D3D3C
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r6, #2
	ldrsh r1, [r5, r6]
	cmp r0, r1
	bgt _081D3D3C
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r2, #2
	ldrsh r0, [r5, r2]
	cmn r1, r0
	blt _081D3D3C
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	movs r6, #4
	ldrsh r1, [r5, r6]
	cmp r0, r1
	bgt _081D3D3C
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	cmn r1, r0
	bge _081D3DC0
_081D3D3C:
	movs r6, #0
	ldrsh r1, [r3, r6]
	ldrh r2, [r5]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D3D58
_081D3D4A:
	ldrh r0, [r5]
	b _081D3D66
	.align 2, 0
_081D3D50: .4byte 0x030046A4
_081D3D54: .4byte 0x085AE0D0
_081D3D58:
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmn r1, r0
	bge _081D3D68
	rsbs r0, r2, #0
_081D3D66:
	strh r0, [r3]
_081D3D68:
	movs r0, #4
	ldrsh r1, [r3, r0]
	ldrh r2, [r5, #4]
	movs r6, #4
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D3D7A
	strh r2, [r3, #4]
	b _081D3D8A
_081D3D7A:
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r6, #4
	ldrsh r0, [r5, r6]
	cmn r1, r0
	bge _081D3D8A
	rsbs r0, r2, #0
	strh r0, [r3, #4]
_081D3D8A:
	ldrh r0, [r3]
	ldrh r4, [r4]
	adds r0, r0, r4
	mov r1, sp
	strh r0, [r1]
	mov r0, r8
	adds r0, #0xfe
	ldrh r0, [r0]
	mov r2, sp
	strh r0, [r2, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, r8
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	bl FUN_08086a4c
	movs r0, #0x80
	lsls r0, r0, #2
	mov r2, sb
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D3DC0:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d3dd0
FUN_081d3dd0: @ 0x081D3DD0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov r8, r0
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	bne _081D3DE8
	b _081D3F9C
_081D3DE8:
	movs r2, #0x10
	mov r1, r8
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D3DFC
	movs r0, #1
	b _081D3DFE
_081D3DFC:
	movs r0, #0
_081D3DFE:
	cmp r0, #0
	bne _081D3E04
	b _081D3F9C
_081D3E04:
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D3E32
	cmp r1, #0
	blt _081D3E32
	ldr r0, _081D3E38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3E32
	ldr r0, _081D3E3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D3E40
_081D3E32:
	movs r4, #0
	b _081D3E4E
	.align 2, 0
_081D3E38: .4byte 0x030046A8
_081D3E3C: .4byte 0x030046AC
_081D3E40:
	ldr r0, _081D3E64 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D3E4E:
	mov r0, sp
	movs r1, #2
	ldrsh r5, [r0, r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3E68
	adds r0, #4
	b _081D3E74
	.align 2, 0
_081D3E64: .4byte 0x030046A4
_081D3E68:
	ldr r0, _081D3E90 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D3E74:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	cmp r5, r0
	bne _081D3EAA
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3E94
	adds r0, #4
	b _081D3EA0
	.align 2, 0
_081D3E90: .4byte 0x030046A4
_081D3E94:
	ldr r0, _081D3F2C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D3EA0:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _081D3F9C
_081D3EAA:
	add r3, sp, #8
	mov r4, r8
	adds r4, #0xfc
	mov r5, sp
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r4]
	subs r1, r1, r0
	strh r1, [r3]
	ldrh r2, [r5, #2]
	ldrh r0, [r4, #2]
	subs r6, r2, r0
	strh r6, [r3, #2]
	ldrh r2, [r5, #4]
	ldrh r0, [r4, #4]
	subs r7, r2, r0
	strh r7, [r3, #4]
	ldr r0, _081D3F30 @ =0x085AE0D0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r5, #0
	ldrsh r2, [r0, r5]
	adds r5, r0, #0
	cmp r1, r2
	bgt _081D3F26
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmn r1, r0
	blt _081D3F18
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r6, #2
	ldrsh r1, [r5, r6]
	cmp r0, r1
	bgt _081D3F18
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r2, #2
	ldrsh r0, [r5, r2]
	cmn r1, r0
	blt _081D3F18
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	movs r6, #4
	ldrsh r1, [r5, r6]
	cmp r0, r1
	bgt _081D3F18
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	cmn r1, r0
	bge _081D3F9C
_081D3F18:
	movs r6, #0
	ldrsh r1, [r3, r6]
	ldrh r2, [r5]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D3F34
_081D3F26:
	ldrh r0, [r5]
	b _081D3F42
	.align 2, 0
_081D3F2C: .4byte 0x030046A4
_081D3F30: .4byte 0x085AE0D0
_081D3F34:
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmn r1, r0
	bge _081D3F44
	rsbs r0, r2, #0
_081D3F42:
	strh r0, [r3]
_081D3F44:
	movs r0, #4
	ldrsh r1, [r3, r0]
	ldrh r2, [r5, #4]
	movs r6, #4
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D3F56
	strh r2, [r3, #4]
	b _081D3F66
_081D3F56:
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r6, #4
	ldrsh r0, [r5, r6]
	cmn r1, r0
	bge _081D3F66
	rsbs r0, r2, #0
	strh r0, [r3, #4]
_081D3F66:
	ldrh r0, [r3]
	ldrh r4, [r4]
	adds r0, r0, r4
	mov r1, sp
	strh r0, [r1]
	mov r0, r8
	adds r0, #0xfe
	ldrh r0, [r0]
	mov r2, sp
	strh r0, [r2, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, r8
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	bl FUN_08086a4c
	movs r0, #0x80
	lsls r0, r0, #2
	mov r2, sb
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D3F9C:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d3fac
FUN_081d3fac: @ 0x081D3FAC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov ip, r1
	ldr r0, _081D3FEC @ =0x03000194
	ldr r2, [r0]
	ldr r0, _081D3FF0 @ =0x000012AC
	adds r1, r2, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _081D4026
	movs r4, #0
	adds r6, r1, #0
	movs r0, #9
	rsbs r0, r0, #0
	mov r8, r0
	subs r0, #8
	mov sb, r0
	adds r3, r2, #0
	adds r3, #0xd0
	movs r5, #0xc6
	lsls r5, r5, #1
_081D3FDC:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D3FF4
	movs r0, #1
	b _081D3FF6
	.align 2, 0
_081D3FEC: .4byte 0x03000194
_081D3FF0: .4byte 0x000012AC
_081D3FF4:
	movs r0, #0
_081D3FF6:
	cmp r0, #0
	beq _081D401C
	ldrh r0, [r3, #0x20]
	cmp r0, r7
	bne _081D401C
	mov r0, ip
	cmp r0, #0
	bne _081D4010
	ldrh r1, [r3]
	mov r0, r8
	ands r0, r1
	strh r0, [r3]
	b _081D4026
_081D4010:
	adds r2, #0xd0
	ldrh r1, [r2]
	mov r0, sb
	ands r0, r1
	strh r0, [r2]
	b _081D4026
_081D401C:
	adds r3, r3, r5
	adds r2, r2, r5
	adds r4, #1
	cmp r4, #0xb
	ble _081D3FDC
_081D4026:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d4034
FUN_081d4034: @ 0x081D4034
	push {r4, lr}
	adds r1, r0, #0
	adds r0, #0xb2
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _081D405C
	ldr r0, _081D4058 @ =0x03002BE0
	ldr r0, [r0]
	adds r1, #0xd4
	ldrh r2, [r1]
	movs r1, #5
	bl FUN_0807a97c
	b _081D4072
	.align 2, 0
_081D4058: .4byte 0x03002BE0
_081D405C:
	ldr r4, _081D4078 @ =0x03002BE0
	ldr r0, [r4]
	adds r1, #0xd4
	ldrh r2, [r1]
	movs r1, #1
	bl FUN_0807a97c
	ldr r0, [r4]
	movs r1, #4
	bl FUN_0807a99c
_081D4072:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D4078: .4byte 0x03002BE0

	thumb_func_start FUN_081d407c
FUN_081d407c: @ 0x081D407C
	push {lr}
	adds r1, r0, #0
	adds r0, #0xb2
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _081D409C
	adds r0, r1, #0
	adds r0, #0xd4
	ldrh r1, [r0]
	movs r0, #7
	bl FUN_080869c8
	b _081D40AE
_081D409C:
	adds r0, r1, #0
	adds r0, #0xd4
	ldrh r1, [r0]
	movs r0, #3
	bl FUN_080869c8
	movs r0, #4
	bl FUN_080869f8
_081D40AE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d40b4
FUN_081d40b4: @ 0x081D40B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _081D41B0 @ =0x03002BE0
	mov r8, r0
	ldr r3, [r0]
	adds r0, r7, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r1, [r3, #0x2c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _081D41B4 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r4
	orrs r2, r0
	str r2, [sp]
	adds r0, r7, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	ldrh r0, [r3, #0x2e]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081D41B8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	adds r0, r7, #0
	adds r0, #0x5c
	ldrh r1, [r0]
	ldrh r3, [r3, #0x30]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r5, sp
	ldr r0, [sp, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #4]
	add r4, sp, #8
	adds r3, r7, #0
	adds r3, #0xfc
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r3]
	subs r1, r1, r0
	strh r1, [r4]
	ldrh r2, [r5, #2]
	ldrh r0, [r3, #2]
	subs r6, r2, r0
	strh r6, [r4, #2]
	ldrh r2, [r5, #4]
	ldrh r0, [r3, #4]
	subs r5, r2, r0
	strh r5, [r4, #4]
	ldr r0, _081D41BC @ =0x03000194
	ldr r0, [r0]
	mov ip, r0
	ldr r0, _081D41C0 @ =0x085AE0D0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r3, r0, #0
	cmp r1, r2
	bgt _081D41CC
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D41CC
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r2, #2
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bgt _081D41CC
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D41CC
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r2, #4
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bgt _081D41CC
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D41CC
	ldr r4, _081D41C4 @ =0x000012B0
	add r4, ip
	ldrh r0, [r4]
	movs r1, #0
	bl FUN_081d3fac
	adds r0, r7, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	strh r0, [r4]
	adds r0, r7, #0
	bl FUN_081d4034
	movs r0, #8
	adds r2, r7, #0
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	mov r3, r8
	ldr r1, [r3]
	ldr r0, _081D41C8 @ =0x0000060E
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #1
	orrs r0, r2
	b _081D42AC
	.align 2, 0
_081D41B0: .4byte 0x03002BE0
_081D41B4: .4byte 0xFFFF0000
_081D41B8: .4byte 0x0000FFFF
_081D41BC: .4byte 0x03000194
_081D41C0: .4byte 0x085AE0D0
_081D41C4: .4byte 0x000012B0
_081D41C8: .4byte 0x0000060E
_081D41CC:
	ldr r0, _081D422C @ =0x000012B0
	add r0, ip
	adds r1, r7, #0
	adds r1, #0xd4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D42AE
	adds r0, r7, #0
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D4234
	adds r0, r7, #0
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _081D4234
	ldr r2, _081D4230 @ =0x085AE0D8
	movs r3, #0
	ldrsh r1, [r4, r3]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bgt _081D4276
	cmn r1, r0
	blt _081D4276
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #2
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _081D4276
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r3, #2
	ldrsh r0, [r2, r3]
	cmn r1, r0
	blt _081D4276
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	b _081D4266
	.align 2, 0
_081D422C: .4byte 0x000012B0
_081D4230: .4byte 0x085AE0D8
_081D4234:
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r1, r0
	bgt _081D4276
	cmn r1, r0
	blt _081D4276
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #2
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bgt _081D4276
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D4276
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
_081D4266:
	cmp r1, r0
	bgt _081D4276
	cmn r1, r0
	blt _081D4276
	adds r0, r7, #0
	bl FUN_081d4034
	b _081D42AE
_081D4276:
	ldr r1, _081D42BC @ =0x000012B0
	add r1, ip
	movs r0, #0
	strh r0, [r1]
	mov r3, r8
	ldr r0, [r3]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r0, r2
	str r1, [r0, #0x3c]
	movs r1, #5
	bl FUN_0807a99c
	adds r2, r7, #0
	adds r2, #0xb4
	movs r0, #9
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	mov r3, r8
	ldr r1, [r3]
	ldr r0, _081D42C0 @ =0x0000060E
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0xfe
	ands r0, r2
_081D42AC:
	strb r0, [r1]
_081D42AE:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D42BC: .4byte 0x000012B0
_081D42C0: .4byte 0x0000060E

	thumb_func_start FUN_081d42c4
FUN_081d42c4: @ 0x081D42C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	adds r0, r5, #0
	adds r0, #0x58
	mov r1, sp
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	adds r1, r5, #0
	adds r1, #0x5a
	ldrh r0, [r4, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #2]
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	add r6, sp, #8
	adds r3, r5, #0
	adds r3, #0xfc
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r3]
	subs r1, r1, r0
	strh r1, [r6]
	ldrh r2, [r4, #2]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	mov ip, r2
	mov r2, ip
	strh r2, [r6, #2]
	ldrh r2, [r4, #4]
	ldrh r0, [r3, #4]
	subs r2, r2, r0
	strh r2, [r6, #4]
	ldr r0, _081D4394 @ =0x03000194
	ldr r4, [r0]
	ldr r3, _081D4398 @ =0x085AE0D0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bgt _081D43A0
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmn r1, r0
	blt _081D43A0
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	movs r7, #2
	ldrsh r1, [r3, r7]
	cmp r0, r1
	bgt _081D43A0
	movs r0, #2
	ldrsh r1, [r6, r0]
	movs r7, #2
	ldrsh r0, [r3, r7]
	cmn r1, r0
	blt _081D43A0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r2, #4
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bgt _081D43A0
	movs r7, #4
	ldrsh r1, [r6, r7]
	movs r2, #4
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D43A0
	ldr r7, _081D439C @ =0x000012B2
	adds r4, r4, r7
	ldrh r0, [r4]
	movs r1, #1
	bl FUN_081d3fac
	adds r0, r5, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	strh r0, [r4]
	adds r0, r5, #0
	bl FUN_081d407c
	movs r0, #0x10
	adds r2, r5, #0
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	b _081D43C6
	.align 2, 0
_081D4394: .4byte 0x03000194
_081D4398: .4byte 0x085AE0D0
_081D439C: .4byte 0x000012B2
_081D43A0:
	adds r0, r5, #0
	adds r0, #0xd4
	ldr r1, _081D43D0 @ =0x000012B2
	adds r4, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r4]
	cmp r0, r2
	bne _081D43C8
	movs r0, #0
	strh r0, [r4]
	movs r0, #7
	bl FUN_080869f8
	adds r2, r5, #0
	adds r2, #0xb4
	movs r0, #0x11
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
_081D43C6:
	strh r0, [r2]
_081D43C8:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D43D0: .4byte 0x000012B2

	thumb_func_start FUN_081d43d4
FUN_081d43d4: @ 0x081D43D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	mov ip, r2
	mov r1, ip
	adds r1, #0xfc
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _081D4440 @ =0xFFFF0000
	adds r1, r3, #0
	ands r1, r4
	orrs r1, r0
	adds r2, #0xfe
	mov r6, r8
	ldrh r0, [r6, #2]
	ldrh r2, [r2]
	subs r0, r0, r2
	lsls r0, r0, #0x10
	ldr r2, _081D4444 @ =0x0000FFFF
	ands r1, r2
	adds r4, r1, #0
	orrs r4, r0
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r6, #4]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r3, r5
	adds r5, r3, #0
	orrs r5, r0
	mov r0, ip
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #2
	bne _081D442A
	b _081D4530
_081D442A:
	cmp r0, #1
	bne _081D444C
	mov r0, ip
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _081D444C
	ldr r0, _081D4448 @ =0x085AE0D8
	b _081D444E
	.align 2, 0
_081D4440: .4byte 0xFFFF0000
_081D4444: .4byte 0x0000FFFF
_081D4448: .4byte 0x085AE0D8
_081D444C:
	ldr r0, _081D4470 @ =0x085AE0D0
_081D444E:
	ldr r6, [r0]
	ldr r7, [r0, #4]
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bge _081D4474
	adds r2, r6, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmn r1, r0
	bge _081D4492
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r0, r2
	b _081D4486
	.align 2, 0
_081D4470: .4byte 0x085AE0D0
_081D4474:
	adds r2, r6, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble _081D4492
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r2, r0
_081D4486:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _081D44AC @ =0xFFFF0000
	ands r1, r4
	adds r4, r1, #0
	orrs r4, r0
_081D4492:
	adds r2, r4, #0
	asrs r0, r2, #0x10
	cmp r0, #0
	bge _081D44B0
	asrs r1, r6, #0x10
	cmn r0, r1
	bge _081D44C8
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r0, r1
	b _081D44BE
	.align 2, 0
_081D44AC: .4byte 0xFFFF0000
_081D44B0:
	asrs r1, r6, #0x10
	cmp r0, r1
	ble _081D44C8
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r1, r0
_081D44BE:
	lsls r0, r0, #0x10
	ldr r1, _081D44E4 @ =0x0000FFFF
	ands r2, r1
	adds r4, r2, #0
	orrs r4, r0
_081D44C8:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bge _081D44E8
	adds r2, r7, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmn r1, r0
	bge _081D4506
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r0, r2
	b _081D44FA
	.align 2, 0
_081D44E4: .4byte 0x0000FFFF
_081D44E8:
	adds r2, r7, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble _081D4506
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r2, r0
_081D44FA:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _081D453C @ =0xFFFF0000
	ands r1, r5
	adds r5, r1, #0
	orrs r5, r0
_081D4506:
	mov r1, ip
	adds r1, #0xfc
	adds r0, r4, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, r8
	strh r0, [r1]
	mov r1, ip
	adds r1, #0xfe
	asrs r0, r4, #0x10
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	adds r0, r5, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #4]
_081D4530:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D453C: .4byte 0xFFFF0000

	thumb_func_start FUN_081d4540
FUN_081d4540: @ 0x081D4540
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _081D458C @ =0x03002BE0
	ldr r0, [r5]
	cmp r0, #0
	beq _081D4584
	adds r0, r4, #0
	bl FUN_081d40b4
	adds r0, r4, #0
	bl FUN_081d42c4
	ldr r0, [r5]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D456A
	adds r0, r4, #0
	bl FUN_081d4590
_081D456A:
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	beq _081D457A
	adds r0, r4, #0
	bl FUN_081d4658
_081D457A:
	adds r0, r4, #0
	adds r0, #0x58
	movs r1, #8
	bl ClearMemory
_081D4584:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D458C: .4byte 0x03002BE0

	thumb_func_start FUN_081d4590
FUN_081d4590: @ 0x081D4590
	push {r4, r5, lr}
	sub sp, #8
	mov ip, r0
	ldr r0, _081D45CC @ =0x03000194
	ldr r2, [r0]
	ldr r0, _081D45D0 @ =0x03002BE0
	ldr r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	beq _081D4642
	mov r0, ip
	adds r0, #0xd4
	ldr r3, _081D45D4 @ =0x000012B0
	adds r1, r2, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D4642
	movs r2, #0x80
	lsls r2, r2, #1
	mov r1, ip
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081D45D8
	movs r0, #1
	b _081D45DA
	.align 2, 0
_081D45CC: .4byte 0x03000194
_081D45D0: .4byte 0x03002BE0
_081D45D4: .4byte 0x000012B0
_081D45D8:
	movs r0, #0
_081D45DA:
	cmp r0, #0
	bne _081D463A
	ldr r1, [r4]
	mov r0, ip
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r1, [r1, #0x2c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _081D464C @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x5a
	ldrh r1, [r1]
	ldrh r0, [r0, #0x2e]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081D4650 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r1, [r4]
	mov r0, ip
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r1, [r1, #0x30]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
	ldr r1, [r4]
	adds r1, #0x2c
	mov r0, sp
	mov r2, ip
	bl FUN_081d43d4
	ldr r0, [r4]
	mov r1, sp
	bl FUN_0807a91c
_081D463A:
	ldr r0, _081D4654 @ =0xFFFFFEFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_081D4642:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D464C: .4byte 0xFFFF0000
_081D4650: .4byte 0x0000FFFF
_081D4654: .4byte 0xFFFFFEFF

	thumb_func_start FUN_081d4658
FUN_081d4658: @ 0x081D4658
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081D46B0 @ =0x03000194
	ldr r0, [r0]
	ldr r1, _081D46B4 @ =0x000012B2
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0xd4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D46F6
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	add r3, sp, #8
	adds r2, r5, #0
	adds r2, #0xfc
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r5, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D46B8
	movs r0, #1
	b _081D46BA
	.align 2, 0
_081D46B0: .4byte 0x03000194
_081D46B4: .4byte 0x000012B2
_081D46B8:
	movs r0, #0
_081D46BA:
	cmp r0, #0
	bne _081D46EE
	adds r0, r5, #0
	adds r0, #0x58
	mov r1, sp
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r2, sp
	adds r1, r5, #0
	adds r1, #0x5a
	ldrh r0, [r2, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #2]
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	bl FUN_08086a4c
_081D46EE:
	ldr r0, _081D4700 @ =0xFFFFFDFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_081D46F6:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D4700: .4byte 0xFFFFFDFF

	thumb_func_start FUN_081d4704
FUN_081d4704: @ 0x081D4704
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	adds r7, r1, #0
	adds r0, r7, #0
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #2
	bne _081D479E
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	add r3, sp, #8
	adds r5, r7, #0
	adds r5, #0xfc
	mov r0, sp
	ldrh r2, [r0]
	ldrh r0, [r5]
	subs r2, r2, r0
	strh r2, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4, #4]
	ldrh r0, [r5, #4]
	subs r6, r1, r0
	strh r6, [r3, #4]
	ldr r4, _081D47AC @ =0x085AE0D0
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r2, r0
	bgt _081D479E
	movs r2, #0
	ldrsh r1, [r3, r2]
	cmn r1, r0
	blt _081D479E
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r2, #4
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bgt _081D479E
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	cmn r1, r0
	blt _081D479E
	adds r0, r5, #0
	bl FUN_08086a4c
	ldr r4, _081D47B0 @ =0x000012B2
	add r4, r8
	ldrh r0, [r4]
	movs r1, #1
	bl FUN_081d3fac
	adds r1, r7, #0
	adds r1, #0xd4
	ldrh r0, [r1]
	strh r0, [r4]
	ldrh r1, [r1]
	movs r0, #3
	bl FUN_080869c8
	movs r0, #0x10
	adds r2, r7, #0
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D479E:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D47AC: .4byte 0x085AE0D0
_081D47B0: .4byte 0x000012B2

	thumb_func_start Elevator_Create
Elevator_Create: @ 0x081D47B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r0, _081D4824 @ =0x03000194
	ldr r0, [r0]
	str r0, [sp, #8]
	cmp r0, #0
	bne _081D47CC
	b _081D4E72
_081D47CC:
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	bl FUN_081d2314
	mov r8, r0
	cmp r0, #0
	bne _081D47DE
	b _081D4E72
_081D47DE:
	mov r4, r8
	adds r4, #0xb4
	mov r1, sp
	ldrh r1, [r1, #0xc]
	strh r1, [r4]
	mov r5, r8
	adds r5, #0xb8
	mov r2, sp
	ldrh r2, [r2, #0xc]
	strh r2, [r5]
	mov sb, r8
	movs r0, #0x72
	bl VM_SeekToKeyword
	mov sl, r4
	str r5, [sp, #0x1c]
	mov r1, r8
	adds r1, #0xe4
	str r1, [sp, #0x20]
	mov r2, r8
	adds r2, #0xe5
	str r2, [sp, #0x10]
	adds r1, #2
	str r1, [sp, #0x14]
	cmp r0, #0
	beq _081D4862
	bl VM_GetPC
	cmp r0, #0
	beq _081D4828
	bl Script_GetValue
	adds r1, r0, #0
	b _081D482A
	.align 2, 0
_081D4824: .4byte 0x03000194
_081D4828:
	movs r1, #0
_081D482A:
	mov r5, r8
	adds r5, #0xe4
	movs r0, #0
	strb r1, [r5]
	mov r4, r8
	adds r4, #0xe5
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x20]
	str r4, [sp, #0x10]
	cmp r0, #0
	beq _081D484A
	bl Script_GetValue
	b _081D484C
_081D484A:
	movs r0, #0
_081D484C:
	mov r4, r8
	adds r4, #0xe6
	strb r0, [r4]
	mov r0, sb
	adds r0, #0x1c
	ldr r2, [sp, #0x20]
	ldrb r1, [r2]
	ldrb r2, [r4]
	bl FUN_08234f90
	str r4, [sp, #0x14]
_081D4862:
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetKeywordValue
	mov r4, r8
	adds r4, #0xe7
	strb r0, [r4]
	movs r0, #0x59
	bl VM_SeekToKeyword
	str r4, [sp, #0x18]
	cmp r0, #0
	beq _081D4900
	subs r4, #0x1b
	bl VM_GetPC
	adds r5, r4, #0
	cmp r0, #0
	beq _081D488E
	bl Script_GetValue
	b _081D4890
_081D488E:
	movs r0, #0
_081D4890:
	str r0, [r4]
	mov r4, r8
	adds r4, #0xd0
	bl VM_GetPC
	adds r6, r4, #0
	cmp r0, #0
	beq _081D48A6
	bl Script_GetValue
	b _081D48A8
_081D48A6:
	movs r0, #0
_081D48A8:
	str r0, [r4]
	bl VM_GetPC
	cmp r0, #0
	beq _081D48BA
	bl Script_GetValue
	adds r2, r0, #0
	b _081D48BC
_081D48BA:
	movs r2, #0
_081D48BC:
	ldr r0, [sp, #0x18]
	ldrb r1, [r0]
	cmp r1, #2
	bne _081D48F0
	ldr r0, [r5]
	cmp r2, r0
	bne _081D48DC
	mov r1, sb
	strh r2, [r1, #0x1e]
	movs r0, #3
	rsbs r0, r0, #0
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081D48F6
_081D48DC:
	ldr r0, [r6]
	cmp r2, r0
	bne _081D48F6
	mov r0, sb
	strh r2, [r0, #0x1e]
	mov r2, sl
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	b _081D48F6
_081D48F0:
	ldr r0, [r5]
	mov r1, sb
	strh r0, [r1, #0x1e]
_081D48F6:
	mov r2, sb
	ldrh r0, [r2, #0x1e]
	mov r1, r8
	adds r1, #0xfe
	strh r0, [r1]
_081D4900:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	mov r6, r8
	adds r6, #0xd4
	strh r0, [r6]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	mov r1, r8
	adds r1, #0xc0
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	mov r1, r8
	adds r1, #0xc2
	strh r0, [r1]
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	mov r1, r8
	adds r1, #0xc4
	strh r0, [r1]
	movs r0, #0x54
	movs r1, #0
	bl VM_GetKeywordValue
	mov r5, r8
	adds r5, #0xc8
	strh r0, [r5]
	mov r4, r8
	adds r4, #0x2c
	ldr r1, _081D4964 @ =0x0000B019
	adds r0, r4, #0
	bl Video_GetAuxSprite
	ldr r0, [sp, #0x18]
	ldrb r7, [r0]
	cmp r7, #1
	beq _081D4A1C
	cmp r7, #1
	bgt _081D4968
	cmp r7, #0
	beq _081D4974
	b _081D4B4E
	.align 2, 0
_081D4964: .4byte 0x0000B019
_081D4968:
	cmp r7, #2
	bne _081D496E
	b _081D4AA8
_081D496E:
	cmp r7, #3
	beq _081D49C8
	b _081D4B4E
_081D4974:
	mov r0, r8
	adds r0, #0xcc
	ldr r0, [r0]
	mov r1, sb
	strh r0, [r1, #0x1e]
	mov r1, r8
	adds r1, #0xb2
	movs r0, #1
	strh r0, [r1]
	adds r1, #0x26
	ldr r0, _081D49BC @ =FUN_081d3534
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D49C0 @ =FUN_081d3c24
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D49C4 @ =FUN_081d33f8
	str r0, [r1]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D49B8
	mov r1, r8
	adds r1, #0xd6
	strh r0, [r1]
_081D49B8:
	strh r7, [r5]
	b _081D4B4E
	.align 2, 0
_081D49BC: .4byte FUN_081d3534
_081D49C0: .4byte FUN_081d3c24
_081D49C4: .4byte FUN_081d33f8
_081D49C8:
	mov r0, r8
	adds r0, #0xcc
	ldr r0, [r0]
	mov r1, sb
	strh r0, [r1, #0x1e]
	mov r1, r8
	adds r1, #0xb2
	movs r0, #1
	strh r0, [r1]
	adds r1, #0x26
	ldr r0, _081D4A10 @ =FUN_081d3534
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4A14 @ =FUN_081d3c24
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4A18 @ =FUN_081d33f8
	str r0, [r1]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D4A9C
	mov r1, r8
	adds r1, #0xd6
	strh r0, [r1]
	b _081D4A9C
	.align 2, 0
_081D4A10: .4byte FUN_081d3534
_081D4A14: .4byte FUN_081d3c24
_081D4A18: .4byte FUN_081d33f8
_081D4A1C:
	mov r0, r8
	adds r0, #0xcc
	ldr r0, [r0]
	mov r1, sb
	strh r0, [r1, #0x1e]
	mov r0, r8
	adds r0, #0xb2
	strh r7, [r0]
	mov r1, r8
	adds r1, #0xd8
	ldr r0, _081D4A54 @ =FUN_081d36c0
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4A58 @ =FUN_081d3dd0
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4A5C @ =FUN_081d33f8
	str r0, [r1]
	movs r2, #2
	str r2, [sp, #0xc]
	ldrh r0, [r5]
	cmp r0, #1
	beq _081D4A70
	cmp r0, #1
	bgt _081D4A60
	cmp r0, #0
	beq _081D4A66
	b _081D4A84
	.align 2, 0
_081D4A54: .4byte FUN_081d36c0
_081D4A58: .4byte FUN_081d3dd0
_081D4A5C: .4byte FUN_081d33f8
_081D4A60:
	cmp r0, #2
	beq _081D4A7C
	b _081D4A84
_081D4A66:
	ldr r1, _081D4A6C @ =0x000001B9
	b _081D4A74
	.align 2, 0
_081D4A6C: .4byte 0x000001B9
_081D4A70:
	movs r1, #0xde
	lsls r1, r1, #1
_081D4A74:
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	b _081D4A84
_081D4A7C:
	ldr r1, _081D4AA4 @ =0x000001BD
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
_081D4A84:
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D4A96
	mov r1, r8
	adds r1, #0xd6
	strh r0, [r1]
_081D4A96:
	ldrh r0, [r5]
	cmp r0, #2
	bls _081D4B4E
_081D4A9C:
	movs r0, #0
	strh r0, [r5]
	b _081D4B4E
	.align 2, 0
_081D4AA4: .4byte 0x000001BD
_081D4AA8:
	mov r1, r8
	adds r1, #0xb2
	movs r0, #4
	strh r0, [r1]
	adds r1, #0x26
	ldr r0, _081D4AD8 @ =FUN_081d38a4
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4ADC @ =FUN_081d3a8c
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4AE0 @ =FUN_081d33f8
	str r0, [r1]
	movs r0, #0
	str r0, [sp, #0xc]
	ldrh r0, [r5]
	cmp r0, #1
	beq _081D4AFC
	cmp r0, #1
	bgt _081D4AE4
	cmp r0, #0
	beq _081D4AEE
	b _081D4B20
	.align 2, 0
_081D4AD8: .4byte FUN_081d38a4
_081D4ADC: .4byte FUN_081d3a8c
_081D4AE0: .4byte FUN_081d33f8
_081D4AE4:
	cmp r0, #2
	beq _081D4B0C
	cmp r0, #3
	beq _081D4B18
	b _081D4B20
_081D4AEE:
	adds r0, r4, #0
	ldr r1, _081D4AF8 @ =0x000001B7
	bl Video_SetAuxSpritePltt
	b _081D4B20
	.align 2, 0
_081D4AF8: .4byte 0x000001B7
_081D4AFC:
	adds r0, r4, #0
	ldr r1, _081D4B08 @ =0x000001B9
	bl Video_SetAuxSpritePltt
	b _081D4B20
	.align 2, 0
_081D4B08: .4byte 0x000001B9
_081D4B0C:
	adds r0, r4, #0
	movs r1, #0xdf
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	b _081D4B20
_081D4B18:
	adds r0, r4, #0
	ldr r1, _081D4BA0 @ =0x000001BD
	bl Video_SetAuxSpritePltt
_081D4B20:
	movs r0, #0x6d
	movs r1, #1
	bl VM_GetKeywordValue
	mov r1, r8
	adds r1, #0xd6
	strh r0, [r1]
	movs r0, #0x77
	movs r1, #0x78
	bl VM_GetKeywordValue
	mov r7, r8
	adds r7, #0xbc
	strh r0, [r7]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D4B4E
	ldrh r0, [r7]
	ldr r1, [sp, #0x1c]
	strh r0, [r1]
_081D4B4E:
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r4, r8
	adds r4, #0x48
	ldr r2, [sp, #8]
	ldr r1, [r2, #0x18]
	ldr r2, [sp, #0xc]
	ldrb r3, [r5]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, r8
	ldr r1, [r2, #0x48]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, sb
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D4BA4
	mov r2, sb
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D4BB0
	.align 2, 0
_081D4BA0: .4byte 0x000001BD
_081D4BA4:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, sb
_081D4BB0:
	str r0, [r2]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D4BD6
	mov r1, sb
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D4BE0
_081D4BD6:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D4BE0:
	mov r2, sb
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D4C18 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D4C50
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D4C1C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D4C12
	ldrb r0, [r4, #5]
_081D4C12:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D4C2C
	.align 2, 0
_081D4C18: .4byte 0x0000FFFF
_081D4C1C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D4C2C
	strh r1, [r4, #8]
_081D4C2C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D4C50
	movs r0, #1
	strb r0, [r4, #7]
_081D4C50:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	movs r7, #0
	movs r0, #2
	strb r0, [r2, #7]
	mov r4, r8
	adds r4, #0xf4
	mov r0, r8
	adds r0, #0xb0
	ldr r2, _081D4D20 @ =0xFFFFD0E9
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r2, sb
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	mov r1, sb
	bl FUN_0823b46c
	mov r5, r8
	adds r5, #0xe8
	ldr r1, [sp, #0x20]
	ldrb r2, [r1]
	ldr r0, [sp, #0x10]
	ldrb r3, [r0]
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0823b490
	str r7, [r4, #0x18]
	ldr r2, _081D4D24 @ =0xFFFFFF00
	adds r0, r2, #0
	mov r1, sb
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	mov r2, sb
	strh r0, [r2, #0x1c]
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r5
	cmp r0, #0
	beq _081D4CD6
	movs r0, #0x80
	mov r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D4CD6:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D4CEE
	movs r0, #0x80
	lsls r0, r0, #5
	mov r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D4CEE:
	mov r1, r8
	adds r1, #0xb6
	movs r0, #0
	strb r0, [r1]
	mov r0, r8
	adds r0, #0xc6
	strh r7, [r0]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	cmp r5, #0
	bne _081D4D0C
	b _081D4E26
_081D4D0C:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1]
	cmp r0, #2
	beq _081D4D34
	cmp r0, #2
	bgt _081D4D28
	cmp r0, #0
	blt _081D4D3C
	b _081D4D2C
	.align 2, 0
_081D4D20: .4byte 0xFFFFD0E9
_081D4D24: .4byte 0xFFFFFF00
_081D4D28:
	cmp r0, #3
	bne _081D4D3C
_081D4D2C:
	mov r1, r8
	adds r1, #0xb2
	movs r0, #1
	b _081D4D3A
_081D4D34:
	mov r1, r8
	adds r1, #0xb2
	movs r0, #4
_081D4D3A:
	strh r0, [r1]
_081D4D3C:
	ldr r2, [sp, #8]
	ldr r0, _081D4DA0 @ =0x000012B0
	adds r4, r2, r0
	ldrh r0, [r4]
	movs r1, #0
	bl FUN_081d3fac
	ldrh r0, [r6]
	strh r0, [r4]
	ldr r4, _081D4DA4 @ =0x03002BE0
	ldr r0, [r4]
	ldrh r2, [r6]
	movs r1, #1
	bl FUN_0807a97c
	movs r0, #8
	mov r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, [r4]
	ldr r0, _081D4DA8 @ =0x0000060E
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #1
	orrs r0, r2
	strb r0, [r1]
	mov r1, r8
	adds r1, #0xfc
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	adds r7, r1, #0
	cmp r3, #0
	blt _081D4D9C
	cmp r2, #0
	blt _081D4D9C
	ldr r0, _081D4DAC @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081D4D9C
	ldr r0, _081D4DB0 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _081D4DB4
_081D4D9C:
	movs r2, #0
	b _081D4DC2
	.align 2, 0
_081D4DA0: .4byte 0x000012B0
_081D4DA4: .4byte 0x03002BE0
_081D4DA8: .4byte 0x0000060E
_081D4DAC: .4byte 0x030046A8
_081D4DB0: .4byte 0x030046AC
_081D4DB4:
	ldr r0, _081D4E84 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r3
_081D4DC2:
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, r8
	mov r1, r8
	adds r1, #0xfe
	ldrh r3, [r1]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x18
	movs r1, #0xff
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl FUN_08234270
	movs r0, #1
	mov r2, sl
	ldrh r1, [r2]
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _081D4E88 @ =0x03002BE0
	ldr r0, [r0]
	adds r1, r7, #0
	bl FUN_0807a91c
	cmp r5, #2
	bne _081D4E26
	adds r0, r7, #0
	bl FUN_08086a4c
	ldr r0, [sp, #8]
	ldr r1, _081D4E8C @ =0x000012B2
	adds r4, r0, r1
	ldrh r0, [r4]
	movs r1, #1
	bl FUN_081d3fac
	ldrh r0, [r6]
	strh r0, [r4]
	ldrh r1, [r6]
	movs r0, #3
	bl FUN_080869c8
	movs r0, #0x10
	mov r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D4E26:
	ldr r0, [sp, #8]
	mov r1, r8
	bl FUN_081d4704
	movs r0, #0x73
	movs r1, #6
	bl VM_GetKeywordValue
	mov r2, r8
	adds r2, #0xba
	strh r0, [r2]
	ldr r0, [sp, #0x18]
	ldrb r4, [r0]
	cmp r4, #0
	blt _081D4E6A
	cmp r4, #1
	ble _081D4E4C
	cmp r4, #3
	bne _081D4E6A
_081D4E4C:
	mov r1, r8
	adds r1, #0xfc
	movs r0, #0
	ldrsh r3, [r2, r0]
	mov r0, sb
	adds r2, r3, #0
	bl FUN_081d2660
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D4E6A
	mov r1, r8
	adds r1, #0xb2
	movs r0, #3
	strh r0, [r1]
_081D4E6A:
	mov r1, r8
	adds r1, #0xb7
	movs r0, #0
	strb r0, [r1]
_081D4E72:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D4E84: .4byte 0x030046A4
_081D4E88: .4byte 0x03002BE0
_081D4E8C: .4byte 0x000012B2

	thumb_func_start ElevatorController_Update
ElevatorController_Update: @ 0x081D4E90
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	mov r3, r8
	adds r3, #0x1c
	ldr r0, _081D4EF0 @ =0x000012AC
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne _081D4EAA
	b _081D4FC6
_081D4EAA:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081D4EF4 @ =0x030047A4
	ldr r1, _081D4EF8 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081D4ECA
	movs r1, #4
	ldr r0, _081D4EFC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D4F0C
_081D4ECA:
	movs r0, #0xac
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _081D4F00 @ =0x00000261
	bl sound_08240740
	ldr r0, _081D4F04 @ =0x00000289
	bl sound_08240740
	ldr r0, _081D4F08 @ =0x0000028A
	bl sound_08240740
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	b _081D4FC6
	.align 2, 0
_081D4EF0: .4byte 0x000012AC
_081D4EF4: .4byte 0x030047A4
_081D4EF8: .4byte 0x030047A0
_081D4EFC: .4byte 0x03002BC0
_081D4F00: .4byte 0x00000261
_081D4F04: .4byte 0x00000289
_081D4F08: .4byte 0x0000028A
_081D4F0C:
	ldr r0, _081D4F40 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	bne _081D4FC6
	movs r0, #0
	mov sb, r0
	mov r6, r8
	adds r6, #0x38
	mov r7, r8
	adds r7, #0xce
	mov r5, r8
	adds r5, #0xf4
	adds r4, r3, #0
_081D4F2A:
	ldr r0, _081D4F44 @ =0x000012AC
	add r0, r8
	movs r1, #1
	mov r2, sb
	lsls r1, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D4F48
	movs r0, #1
	b _081D4F4A
	.align 2, 0
_081D4F40: .4byte 0x030044BC
_081D4F44: .4byte 0x000012AC
_081D4F48:
	movs r0, #0
_081D4F4A:
	cmp r0, #0
	beq _081D4FAA
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r0, #6
	beq _081D4FAA
	ldr r1, [r5]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _081D4FD4 @ =0x085AE0E8
	movs r2, #0
	ldrsh r0, [r7, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, [r5, #4]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, [r5, #8]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_081d31f0
	adds r0, r4, #0
	bl FUN_081d4540
	adds r0, r4, #0
	bl FUN_081d276c
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	str r0, [r6]
	str r1, [r6, #4]
	ldr r1, _081D4FD8 @ =0xFFFFFF00
	adds r0, r1, #0
	ldrh r2, [r6]
	adds r0, r0, r2
	strh r0, [r6]
	adds r0, r4, #0
	bl FUN_081d2f04
_081D4FAA:
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r7, r7, r0
	adds r5, r5, r0
	adds r4, r4, r0
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #0xb
	ble _081D4F2A
	mov r0, r8
	bl FUN_081d2a64
_081D4FC6:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D4FD4: .4byte 0x085AE0E8
_081D4FD8: .4byte 0xFFFFFF00

	thumb_func_start ElevatorController_Destroy
ElevatorController_Destroy: @ 0x081D4FDC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r0, #0xac
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _081D502C @ =0x00000261
	bl sound_08240740
	ldr r0, _081D5030 @ =0x00000289
	bl sound_08240740
	ldr r0, _081D5034 @ =0x0000028A
	bl sound_08240740
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	movs r7, #0
	movs r0, #1
	mov sb, r0
	mov r6, r8
	adds r6, #0xd0
	mov r5, r8
	adds r5, #0x1c
_081D5016:
	ldr r0, _081D5038 @ =0x000012AC
	add r0, r8
	mov r1, sb
	lsls r1, r7
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D503C
	movs r0, #1
	b _081D503E
	.align 2, 0
_081D502C: .4byte 0x00000261
_081D5030: .4byte 0x00000289
_081D5034: .4byte 0x0000028A
_081D5038: .4byte 0x000012AC
_081D503C:
	movs r0, #0
_081D503E:
	cmp r0, #0
	beq _081D5076
	adds r4, r5, #0
	ldrh r0, [r6]
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _081D5052
	movs r0, #1
	b _081D5054
_081D5052:
	movs r0, #0
_081D5054:
	cmp r0, #0
	beq _081D5062
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_082342a8
_081D5062:
	adds r0, r4, #0
	bl FUN_081d3188
	adds r0, r4, #0
	adds r0, #0xf4
	bl FUN_0823b284
	adds r0, r4, #0
	bl AuxSprite_Remove
_081D5076:
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r5, r5, r0
	adds r7, #1
	cmp r7, #0xb
	ble _081D5016
	movs r1, #0
	ldr r0, _081D5098 @ =0x03000194
	str r1, [r0]
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D5098: .4byte 0x03000194

	thumb_func_start FUN_081d509c
FUN_081d509c: @ 0x081D509C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081D50BC @ =0x0000922E
	ldr r1, _081D50C0 @ =0x000013F9
	bl GetFile
	str r0, [r4, #0x18]
	ldr r0, _081D50C4 @ =0x03000194
	str r4, [r0]
	ldr r0, _081D50C8 @ =0x000012AC
	adds r4, r4, r0
	movs r0, #0
	str r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081D50BC: .4byte 0x0000922E
_081D50C0: .4byte 0x000013F9
_081D50C4: .4byte 0x03000194
_081D50C8: .4byte 0x000012AC

	thumb_func_start ElevatorController_Create
ElevatorController_Create: @ 0x081D50CC
	push {r4, lr}
	ldr r0, _081D5100 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	bne _081D5112
	ldr r1, _081D5104 @ =0x000012B8
	movs r0, #5
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D5110
	ldr r1, _081D5108 @ =ElevatorController_Update
	ldr r2, _081D510C @ =ElevatorController_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081d509c
	cmp r0, #0
	bge _081D5110
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D5112
	.align 2, 0
_081D5100: .4byte 0x03000194
_081D5104: .4byte 0x000012B8
_081D5108: .4byte ElevatorController_Update
_081D510C: .4byte ElevatorController_Destroy
_081D5110:
	adds r0, r4, #0
_081D5112:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d5118
FUN_081d5118: @ 0x081D5118
	ldr r1, _081D5120 @ =0x03000194
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D5120: .4byte 0x03000194

	thumb_func_start Elevator_Shake
Elevator_Shake: @ 0x081D5124
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D5158 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5152
	cmp r1, #0
	beq _081D5152
	adds r0, r1, #0
	bl FUN_081d3118
	adds r2, r0, #0
	cmp r2, #0
	beq _081D5152
	movs r0, #0x20
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D5152:
	pop {r0}
	bx r0
	.align 2, 0
_081D5158: .4byte 0x03000194

	thumb_func_start FUN_081d515c
FUN_081d515c: @ 0x081D515C
	push {r4, r5, r6, r7, lr}
	ldr r0, _081D5180 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D51D4
	adds r4, r0, #0
	ldr r0, _081D5184 @ =0x000012AC
	adds r5, r4, r0
	ldr r0, [r5]
	cmp r0, #0
	beq _081D51D4
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	bne _081D5190
	b _081D51D4
	.align 2, 0
_081D5180: .4byte 0x03000194
_081D5184: .4byte 0x000012AC
_081D5188:
	adds r0, r4, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	b _081D51D8
_081D5190:
	movs r3, #0
	ldr r6, [r5]
	movs r7, #0x10
	adds r2, r4, #0
	adds r2, #0xd0
	adds r1, r4, #0
	adds r1, #0x1c
	movs r5, #0xc6
	lsls r5, r5, #1
_081D51A2:
	movs r0, #1
	lsls r0, r3
	ands r0, r6
	cmp r0, #0
	beq _081D51B0
	movs r0, #1
	b _081D51B2
_081D51B0:
	movs r0, #0
_081D51B2:
	cmp r0, #0
	beq _081D51CA
	adds r4, r1, #0
	ldrh r0, [r2]
	ands r0, r7
	cmp r0, #0
	beq _081D51C4
	movs r0, #1
	b _081D51C6
_081D51C4:
	movs r0, #0
_081D51C6:
	cmp r0, #0
	bne _081D5188
_081D51CA:
	adds r2, r2, r5
	adds r1, r1, r5
	adds r3, #1
	cmp r3, #0xb
	ble _081D51A2
_081D51D4:
	movs r0, #1
	rsbs r0, r0, #0
_081D51D8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Elevator_Start
Elevator_Start: @ 0x081D51E0
	push {r4, r5, r6, lr}
	movs r0, #0x6d
	movs r1, #1
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D5238 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5260
	cmp r1, #0
	beq _081D5260
	adds r0, r1, #0
	bl FUN_081d3118
	adds r3, r0, #0
	cmp r3, #0
	beq _081D5260
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r6, #2
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _081D5260
	adds r0, r3, #0
	adds r0, #0xb2
	movs r5, #0
	strh r2, [r0]
	cmp r4, #4
	bne _081D523C
	adds r0, #2
	mvns r1, r6
	ldrh r2, [r0]
	ands r1, r2
	orrs r1, r4
	strh r1, [r0]
	b _081D5260
	.align 2, 0
_081D5238: .4byte 0x03000194
_081D523C:
	adds r1, r3, #0
	adds r1, #0xb4
	movs r2, #5
	rsbs r2, r2, #0
	ldrh r0, [r1]
	ands r2, r0
	strh r2, [r1]
	cmp r4, #2
	bne _081D5254
	orrs r4, r2
	strh r4, [r1]
	b _081D525A
_081D5254:
	mvns r0, r6
	ands r0, r2
	strh r0, [r1]
_081D525A:
	adds r0, r3, #0
	bl FUN_081d21d8
_081D5260:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d5268
FUN_081d5268: @ 0x081D5268
	push {r4, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D529C @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5296
	cmp r1, #0
	beq _081D5296
	adds r0, r1, #0
	bl FUN_081d3118
	adds r4, r0, #0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x6d
	bl VM_GetKeywordValue
	adds r4, #0xd6
	strh r0, [r4]
_081D5296:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D529C: .4byte 0x03000194

	thumb_func_start FUN_081d52a0
FUN_081d52a0: @ 0x081D52A0
	push {r4, r5, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r5, _081D52D4 @ =0x03000194
	ldr r0, [r5]
	cmp r0, #0
	beq _081D5332
	cmp r1, #0
	beq _081D5332
	adds r0, r1, #0
	bl FUN_081d3118
	adds r4, r0, #0
	ldr r5, [r5]
	movs r1, #1
	adds r0, #0xb4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D52D8
	movs r0, #1
	b _081D52DA
	.align 2, 0
_081D52D4: .4byte 0x03000194
_081D52D8:
	movs r0, #0
_081D52DA:
	cmp r0, #0
	beq _081D52F6
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_082342a8
	adds r2, r4, #0
	adds r2, #0xb4
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081D52F6:
	adds r0, r4, #0
	bl FUN_081d3188
	adds r0, r4, #0
	adds r0, #0xf4
	bl FUN_0823b284
	adds r1, r4, #0
	adds r1, #0xd4
	movs r0, #0
	strh r0, [r1]
	subs r1, #0x22
	movs r0, #6
	strh r0, [r1]
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r3, r4, #0
	adds r3, #0xb0
	movs r1, #0
	ldrsh r0, [r3, r1]
	ldr r1, _081D5338 @ =0x000012AC
	adds r2, r5, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	ldr r0, _081D533C @ =0x0000FFFF
	strh r0, [r3]
_081D5332:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D5338: .4byte 0x000012AC
_081D533C: .4byte 0x0000FFFF

	thumb_func_start FUN_081d5340
FUN_081d5340: @ 0x081D5340
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D5388 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D53C2
	cmp r1, #0
	beq _081D53C2
	adds r0, r1, #0
	bl FUN_081d3118
	adds r6, r0, #0
	movs r7, #0
	movs r0, #0
	mov r8, r0
	movs r5, #0
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D53AA
	bl VM_GetPC
	cmp r0, #0
	beq _081D538C
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	b _081D538E
	.align 2, 0
_081D5388: .4byte 0x03000194
_081D538C:
	movs r1, #0
_081D538E:
	adds r7, r1, #0
	movs r1, #0
	mov r8, r1
	bl VM_GetPC
	cmp r0, #0
	beq _081D53A6
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	b _081D53A8
_081D53A6:
	movs r3, #0
_081D53A8:
	adds r5, r3, #0
_081D53AA:
	adds r4, r6, #0
	adds r4, #0xe8
	adds r0, r4, #0
	adds r1, r7, #0
	mov r2, r8
	adds r3, r5, #0
	bl FUN_08234de8
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r6, r1
	str r4, [r0]
_081D53C2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d53cc
FUN_081d53cc: @ 0x081D53CC
	push {r4, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D540C @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5406
	cmp r1, #0
	beq _081D5406
	adds r0, r1, #0
	bl FUN_081d3118
	adds r4, r0, #0
	cmp r4, #0
	beq _081D5406
	movs r0, #0x63
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	adds r0, r4, #0
	adds r0, #0x2c
	ldr r2, _081D5410 @ =0x000001B7
	adds r1, r1, r2
	bl Video_SetAuxSpritePltt
_081D5406:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D540C: .4byte 0x03000194
_081D5410: .4byte 0x000001B7

	thumb_func_start FUN_081d5414
FUN_081d5414: @ 0x081D5414
	push {r4, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D544C @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5446
	cmp r1, #0
	beq _081D5446
	adds r0, r1, #0
	bl FUN_081d3118
	adds r4, r0, #0
	cmp r4, #0
	beq _081D5446
	movs r0, #0x73
	movs r1, #6
	bl VM_GetKeywordValue
	adds r1, r4, #0
	adds r1, #0xba
	strh r0, [r1]
_081D5446:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D544C: .4byte 0x03000194

	thumb_func_start FUN_081d5450
FUN_081d5450: @ 0x081D5450
	push {r4, r5, lr}
	ldr r0, _081D5498 @ =0x03000194
	ldr r4, [r0]
	bl FUN_081d3150
	adds r5, r0, #0
	ldr r0, _081D549C @ =0x000012B0
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	ldr r4, _081D54A0 @ =0x03002BE0
	ldr r0, [r4]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r0, r2
	str r1, [r0, #0x3c]
	movs r1, #1
	bl FUN_0807a99c
	adds r5, #0xb4
	movs r0, #9
	rsbs r0, r0, #0
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	ldr r1, [r4]
	ldr r0, _081D54A4 @ =0x0000060E
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0xfe
	ands r0, r2
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D5498: .4byte 0x03000194
_081D549C: .4byte 0x000012B0
_081D54A0: .4byte 0x03002BE0
_081D54A4: .4byte 0x0000060E

	thumb_func_start FUN_081d54a8
FUN_081d54a8: @ 0x081D54A8
	push {r4, r5, r6, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D5500 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D54F8
	cmp r1, #0
	beq _081D54F8
	adds r0, r1, #0
	bl FUN_081d3118
	adds r5, r0, #0
	cmp r5, #0
	beq _081D54F8
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0x68
	adds r1, r4, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6c
	adds r1, r4, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	cmp r6, #0
	ble _081D54EE
	adds r0, r5, #0
	adds r0, #0xd0
	str r6, [r0]
_081D54EE:
	cmp r1, #0
	ble _081D54F8
	adds r0, r5, #0
	adds r0, #0xcc
	str r1, [r0]
_081D54F8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D5500: .4byte 0x03000194

	thumb_func_start FUN_081d5504
FUN_081d5504: @ 0x081D5504
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D5534 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5530
	cmp r1, #0
	beq _081D5530
	adds r0, r1, #0
	bl FUN_081d3118
	cmp r0, #0
	beq _081D5530
	adds r0, #0xb4
	ldr r1, _081D5538 @ =0xFFFFEFFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_081D5530:
	pop {r0}
	bx r0
	.align 2, 0
_081D5534: .4byte 0x03000194
_081D5538: .4byte 0xFFFFEFFF

	thumb_func_start FUN_081d553c
FUN_081d553c: @ 0x081D553C
	push {lr}
	adds r1, r0, #0
	ldr r0, _081D555C @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5560
	cmp r1, #0
	beq _081D5560
	adds r0, r1, #0
	bl FUN_081d3118
	cmp r0, #0
	beq _081D5560
	adds r0, #0xfc
	b _081D5562
	.align 2, 0
_081D555C: .4byte 0x03000194
_081D5560:
	movs r0, #0
_081D5562:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d5568
FUN_081d5568: @ 0x081D5568
	push {lr}
	adds r1, r0, #0
	ldr r0, _081D557C @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5580
	adds r0, r1, #0
	adds r0, #0xfc
	b _081D5582
	.align 2, 0
_081D557C: .4byte 0x03000194
_081D5580:
	movs r0, #0
_081D5582:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d5588
FUN_081d5588: @ 0x081D5588
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081D5600 @ =0x03000194
	ldr r4, [r0]
	cmp r4, #0
	bne _081D5596
	b _081D5814
_081D5596:
	adds r6, r5, #0
	adds r6, #0xd6
	ldrh r1, [r6]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _081D55D2
	ldr r0, _081D5604 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	bne _081D55B4
	b _081D5814
_081D55B4:
	ldr r1, _081D5608 @ =0x000012B0
	adds r0, r4, r1
	adds r1, r5, #0
	adds r1, #0xd4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _081D55C6
	b _081D5814
_081D55C6:
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081D55D2
	b _081D5814
_081D55D2:
	adds r0, r5, #0
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D55FA
	cmp r1, #0
	blt _081D55FA
	ldr r0, _081D560C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D55FA
	ldr r0, _081D5610 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D5614
_081D55FA:
	movs r7, #0
	b _081D5622
	.align 2, 0
_081D5600: .4byte 0x03000194
_081D5604: .4byte 0x03002BE0
_081D5608: .4byte 0x000012B0
_081D560C: .4byte 0x030046A8
_081D5610: .4byte 0x030046AC
_081D5614:
	ldr r0, _081D5640 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r2
_081D5622:
	adds r0, r5, #0
	adds r0, #0xfe
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r6, r0, #0x18
	adds r4, r7, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D5644
	adds r0, #4
	b _081D5650
	.align 2, 0
_081D5640: .4byte 0x030046A4
_081D5644:
	ldr r0, _081D566C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D5650:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _081D5686
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D5670
	adds r0, #4
	b _081D567C
	.align 2, 0
_081D566C: .4byte 0x030046A4
_081D5670:
	ldr r0, _081D568C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D567C:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081D5690
_081D5686:
	movs r0, #0
	b _081D5692
	.align 2, 0
_081D568C: .4byte 0x030046A4
_081D5690:
	movs r0, #1
_081D5692:
	cmp r0, #0
	beq _081D56A4
	ldr r0, _081D56A0 @ =0x00000151
	bl PlaySound_082406e0
	movs r0, #1
	b _081D56A6
	.align 2, 0
_081D56A0: .4byte 0x00000151
_081D56A4:
	movs r0, #0
_081D56A6:
	cmp r0, #0
	beq _081D56AC
	b _081D5814
_081D56AC:
	subs r4, r7, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D56BE
	adds r0, #4
	b _081D56CA
_081D56BE:
	ldr r0, _081D56E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D56CA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _081D56FE
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D56E8
	adds r0, #4
	b _081D56F4
	.align 2, 0
_081D56E4: .4byte 0x030046A4
_081D56E8:
	ldr r0, _081D5704 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D56F4:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081D5708
_081D56FE:
	movs r0, #0
	b _081D570A
	.align 2, 0
_081D5704: .4byte 0x030046A4
_081D5708:
	movs r0, #1
_081D570A:
	cmp r0, #0
	beq _081D571C
	ldr r0, _081D5718 @ =0x00000151
	bl PlaySound_082406e0
	movs r0, #1
	b _081D571E
	.align 2, 0
_081D5718: .4byte 0x00000151
_081D571C:
	movs r0, #0
_081D571E:
	cmp r0, #0
	bne _081D5814
	ldr r5, _081D5740 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r7, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D5744
	adds r0, #4
	b _081D574E
	.align 2, 0
_081D5740: .4byte 0x030046A4
_081D5744:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081D574E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _081D577E
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D5768
	adds r0, #4
	b _081D5774
_081D5768:
	ldr r0, _081D5784 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D5774:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081D5788
_081D577E:
	movs r0, #0
	b _081D578A
	.align 2, 0
_081D5784: .4byte 0x030046A4
_081D5788:
	movs r0, #1
_081D578A:
	cmp r0, #0
	beq _081D579C
	ldr r0, _081D5798 @ =0x00000151
	bl PlaySound_082406e0
	movs r0, #1
	b _081D579E
	.align 2, 0
_081D5798: .4byte 0x00000151
_081D579C:
	movs r0, #0
_081D579E:
	cmp r0, #0
	bne _081D5814
	ldr r5, _081D57C0 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r7, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D57C4
	adds r0, #4
	b _081D57CE
	.align 2, 0
_081D57C0: .4byte 0x030046A4
_081D57C4:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081D57CE:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _081D57FE
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D57E8
	adds r0, #4
	b _081D57F4
_081D57E8:
	ldr r0, _081D5804 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D57F4:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081D5808
_081D57FE:
	movs r0, #0
	b _081D580A
	.align 2, 0
_081D5804: .4byte 0x030046A4
_081D5808:
	movs r0, #1
_081D580A:
	cmp r0, #0
	beq _081D5814
	ldr r0, _081D581C @ =0x00000151
	bl PlaySound_082406e0
_081D5814:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D581C: .4byte 0x00000151

	thumb_func_start FUN_081d5820
FUN_081d5820: @ 0x081D5820
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d5834
FUN_081d5834: @ 0x081D5834
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	bics r2, r1
	strh r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d5848
FUN_081d5848: @ 0x081D5848
	push {lr}
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081D585C
	movs r0, #0
	b _081D585E
_081D585C:
	movs r0, #1
_081D585E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d5864
FUN_081d5864: @ 0x081D5864
	push {r4, r5, r6, r7, lr}
	movs r5, #0
	ldr r1, _081D588C @ =0x0000057C
	adds r2, r0, r1
	movs r3, #1
	movs r7, #0xac
	lsls r7, r7, #1
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r6, r0, r1
	adds r4, r0, #0
	adds r4, #0x1c
_081D587C:
	adds r1, r3, #0
	lsls r1, r5
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D5890
	movs r0, #1
	b _081D5892
	.align 2, 0
_081D588C: .4byte 0x0000057C
_081D5890:
	movs r0, #0
_081D5892:
	cmp r0, #0
	bne _081D58AE
	adds r1, r3, #0
	lsls r1, r5
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	adds r1, r7, #0
	bl ClearMemory
	strh r5, [r6]
	adds r0, r4, #0
	b _081D58BE
_081D58AE:
	movs r0, #0xac
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #3
	ble _081D587C
	movs r0, #0
_081D58BE:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d58c4
FUN_081d58c4: @ 0x081D58C4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _081D58D4 @ =0x03000198
	ldr r1, [r0]
	cmp r1, #0
	bne _081D58DC
	b _081D591A
	.align 2, 0
_081D58D4: .4byte 0x03000198
_081D58D8:
	adds r0, r1, #0
	b _081D591C
_081D58DC:
	movs r2, #0
	ldr r3, _081D58F8 @ =0x0000057C
	adds r0, r1, r3
	ldr r3, [r0]
	movs r5, #1
	adds r1, #0x1c
_081D58E8:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r3
	cmp r0, #0
	beq _081D58FC
	movs r0, #1
	b _081D58FE
	.align 2, 0
_081D58F8: .4byte 0x0000057C
_081D58FC:
	movs r0, #0
_081D58FE:
	cmp r0, #0
	beq _081D590E
	movs r6, #0xa8
	lsls r6, r6, #1
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, r4
	beq _081D58D8
_081D590E:
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r2, #1
	cmp r2, #3
	ble _081D58E8
_081D591A:
	movs r0, #0
_081D591C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d5924
FUN_081d5924: @ 0x081D5924
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	ldr r0, _081D59A8 @ =0x03000198
	ldr r6, [r0]
	cmp r6, #0
	bne _081D5944
	bl FUN_081d63ec
	adds r6, r0, #0
	cmp r6, #0
	bne _081D5944
	b _081D5C9C
_081D5944:
	adds r0, r6, #0
	bl FUN_081d5864
	adds r5, r0, #0
	cmp r5, #0
	bne _081D5952
	b _081D5C9C
_081D5952:
	adds r7, r5, #0
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r1, _081D59AC @ =0x00009385
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	movs r4, #1
	strb r4, [r0]
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, #0x6d
	bl VM_GetKeywordValue
	movs r3, #0xa6
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_081d5848
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D59B0
	movs r0, #0xa4
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	b _081D59B8
	.align 2, 0
_081D59A8: .4byte 0x03000198
_081D59AC: .4byte 0x00009385
_081D59B0:
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
_081D59B8:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D59D4
	bl Script_GetValue
	strh r0, [r7, #0x1c]
	bl Script_GetValue
	strh r0, [r7, #0x1e]
	bl Script_GetValue
	strh r0, [r7, #0x20]
_081D59D4:
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r2, r5, r3
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xa9
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x61
	bl VM_GetKeywordValue
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	str r0, [r1]
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _081D5A44 @ =0x0000013D
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D5AC2
	bl VM_GetPC
	cmp r0, #0
	beq _081D5A48
	bl Script_GetValue
	adds r1, r0, #0
	b _081D5A4A
	.align 2, 0
_081D5A44: .4byte 0x0000013D
_081D5A48:
	movs r1, #0
_081D5A4A:
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081D5A60
	bl Script_GetValue
	b _081D5A62
_081D5A60:
	movs r0, #0
_081D5A62:
	ldr r2, _081D5A78 @ =0x00000147
	adds r1, r5, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081D5A7C
	bl Script_GetValue
	b _081D5A7E
	.align 2, 0
_081D5A78: .4byte 0x00000147
_081D5A7C:
	movs r0, #0
_081D5A7E:
	movs r3, #0xa3
	lsls r3, r3, #1
	adds r1, r5, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081D5A94
	bl Script_GetValue
	b _081D5A96
_081D5A94:
	movs r0, #0
_081D5A96:
	mov sl, r0
	bl VM_GetPC
	cmp r0, #0
	beq _081D5AA8
	bl Script_GetValue
	mov sb, r0
	b _081D5AAC
_081D5AA8:
	movs r1, #0
	mov sb, r1
_081D5AAC:
	bl VM_GetPC
	cmp r0, #0
	beq _081D5ABC
	bl Script_GetValue
	mov r8, r0
	b _081D5AE6
_081D5ABC:
	movs r2, #0
	mov r8, r2
	b _081D5AE6
_081D5AC2:
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0x64
	strh r0, [r1]
	adds r0, #0xe3
	adds r1, r5, r0
	movs r0, #3
	strb r0, [r1]
	movs r2, #0xa3
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0
	mov sl, r3
	mov sb, r3
	mov r8, r3
_081D5AE6:
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	movs r3, #0xa1
	lsls r3, r3, #1
	adds r2, r5, r3
	strh r0, [r2]
	movs r2, #0
	ldrsh r0, [r1, r2]
	subs r3, #5
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r1, #1
	bl Div
	movs r2, #0x9d
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D5B32
	bl VM_GetPC
	cmp r0, #0
	beq _081D5B28
	bl Script_GetValue
	adds r1, r0, #0
	b _081D5B2A
_081D5B28:
	movs r1, #0
_081D5B2A:
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
_081D5B32:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_081d5848
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _081D5B76
	adds r0, r5, #0
	adds r0, #0xa8
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #0x60
	str r2, [sp]
	movs r2, #0x64
	str r2, [sp, #4]
	movs r2, #0xa0
	lsls r2, r2, #4
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	movs r2, #5
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	movs r2, #0
	str r2, [sp, #0x18]
	movs r2, #0x40
	movs r3, #0x10
	bl AuxShadow_Init
	movs r2, #0xa7
	lsls r2, r2, #1
	adds r1, r5, r2
	b _081D5BA6
_081D5B76:
	adds r0, r5, #0
	adds r0, #0xa8
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #0x80
	str r2, [sp]
	movs r2, #0x64
	str r2, [sp, #4]
	movs r2, #0xa0
	lsls r2, r2, #4
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	movs r2, #5
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r2, #0x40
	movs r3, #0x10
	bl AuxShadow_Init
	movs r3, #0xa7
	lsls r3, r3, #1
	adds r1, r5, r3
_081D5BA6:
	strb r0, [r1]
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r1, [r6, #0x18]
	movs r2, #0xa9
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D5BEE
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D5BF6
_081D5BEE:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D5BF6:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D5C1A
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D5C22
_081D5C1A:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D5C22:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _081D5C58 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D5C90
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D5C5C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D5C52
	ldrb r0, [r4, #5]
_081D5C52:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D5C6C
	.align 2, 0
_081D5C58: .4byte 0x0000FFFF
_081D5C5C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D5C6C
	strh r1, [r4, #8]
_081D5C6C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D5C90
	movs r0, #1
	strb r0, [r4, #7]
_081D5C90:
	adds r0, r5, #0
	mov r1, sl
	mov r2, sb
	mov r3, r8
	bl FUN_081d66c0
_081D5C9C:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d5cac
FUN_081d5cac: @ 0x081D5CAC
	push {r4, lr}
	mov ip, r0
	mov r4, ip
	mov r2, ip
	adds r2, #0x9c
	ldrh r0, [r2]
	cmp r0, #0
	beq _081D5CCE
	mov r3, ip
	adds r3, #0x5e
	ldrh r0, [r3]
	movs r1, #4
	orrs r1, r0
	strh r1, [r3]
	ldrh r0, [r2]
	subs r0, #1
	b _081D5CD8
_081D5CCE:
	mov r2, ip
	adds r2, #0x5e
	ldrh r1, [r2]
	ldr r0, _081D5CF8 @ =0x0000FFFB
	ands r0, r1
_081D5CD8:
	strh r0, [r2]
	ldr r0, _081D5CFC @ =0x00000153
	adds r4, r4, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D5D00
	mov r1, ip
	ldr r0, [r1, #0xc]
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _081D5D0C
	.align 2, 0
_081D5CF8: .4byte 0x0000FFFB
_081D5CFC: .4byte 0x00000153
_081D5D00:
	mov r1, ip
	ldr r0, [r1, #0xc]
	movs r1, #0xbe
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
_081D5D0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d5d14
FUN_081d5d14: @ 0x081D5D14
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d5d18
FUN_081d5d18: @ 0x081D5D18
	push {r4, r5, lr}
	adds r4, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081D5D40
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	strb r2, [r3]
_081D5D40:
	adds r0, r4, #0
	bl FUN_081d5cac
	adds r0, r4, #0
	bl FUN_081d6444
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r5, r4, r0
	ldrh r1, [r5]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081D5D62
	adds r0, r4, #0
	bl FUN_081d6c24
_081D5D62:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d5d70
FUN_081d5d70: @ 0x081D5D70
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne _081D5D84
	b _081D5E88
_081D5D84:
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r3, #0
	movs r2, #0
	strh r2, [r0]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	strb r3, [r4]
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r5, r0
	str r2, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081D5DE0 @ =0x05000002
	bl CpuSet
	movs r0, #0x29
	strh r0, [r4]
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0x94
	strh r0, [r1]
	movs r0, #0
	ldrsh r3, [r4, r0]
	ldr r2, _081D5DE4 @ =0x085B0A08
	ldrb r0, [r5, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081D5DE8
	asrs r0, r0, #0xc
	b _081D5DEE
	.align 2, 0
_081D5DE0: .4byte 0x05000002
_081D5DE4: .4byte 0x085B0A08
_081D5DE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D5DEE:
	adds r6, r0, #0
	movs r2, #0x94
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r4, #0
	ldrsh r3, [r0, r4]
	ldr r1, _081D5E14 @ =0x085B0A08
	ldrb r2, [r5, #6]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r3, r0
	adds r7, r1, #0
	adds r4, r2, #0
	cmp r0, #0
	blt _081D5E18
	asrs r0, r0, #0xc
	b _081D5E1E
	.align 2, 0
_081D5E14: .4byte 0x085B0A08
_081D5E18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D5E1E:
	adds r6, r6, r0
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r4, #1
	adds r0, r0, r7
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _081D5E3E
	asrs r0, r0, #0xc
	b _081D5E42
_081D5E3E:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_081D5E42:
	adds r3, r0, #0
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r2, r0
	cmp r0, #0
	blt _081D5E68
	asrs r2, r0, #0xc
	b _081D5E6E
_081D5E68:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081D5E6E:
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r0, r0, r6
	strh r0, [r5, #0x1c]
	movs r4, #0x8c
	lsls r4, r4, #1
	adds r1, r5, r4
	adds r0, r3, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
_081D5E88:
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081D5F36
	adds r0, r5, #0
	bl FUN_081d6cb0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D5F36
	ldr r2, _081D5F24 @ =0x03002BE0
	ldr r0, [r2]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081D5F36
	ldr r0, _081D5F28 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _081D5EC6
	ldr r0, _081D5F2C @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #0
	bne _081D5EC6
	movs r1, #1
_081D5EC6:
	cmp r1, #0
	bne _081D5F36
	ldr r0, [r2]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _081D5F36
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r2, #0x98
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	beq _081D5F36
	subs r4, #0x10
	adds r1, r5, r4
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _081D5F36
	movs r0, #4
	strh r0, [r1]
	adds r4, #0x24
	adds r1, r5, r4
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _081D5F30
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #3
	strh r1, [r0]
	movs r2, #0xab
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _081D5F48
	.align 2, 0
_081D5F24: .4byte 0x03002BE0
_081D5F28: .4byte 0x03002B8C
_081D5F2C: .4byte 0x03002B60
_081D5F30:
	ldr r0, _081D5F50 @ =0x000003C9
	bl PlaySound_082406e0
_081D5F36:
	adds r0, r5, #0
	bl FUN_081d5f54
	movs r4, #0xaa
	lsls r4, r4, #1
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081D5F48:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D5F50: .4byte 0x000003C9

	thumb_func_start FUN_081d5f54
FUN_081d5f54: @ 0x081D5F54
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldrb r1, [r0, #6]
	cmp r1, #0x80
	ble _081D5F68
	ldr r0, _081D5F64 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081D5F76
	.align 2, 0
_081D5F64: .4byte 0xFFFFFF00
_081D5F68:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081D5F76
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081D5F76:
	adds r5, r1, #0
	cmp r5, #0
	bne _081D5F8C
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _081D5F8C
	b _081D60C0
_081D5F8C:
	movs r0, #0x92
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r4, [r0, r1]
	ldr r3, _081D5FBC @ =0x085B0A08
	mov r0, ip
	ldrb r2, [r0, #6]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	adds r4, r2, #0
	adds r6, r3, #0
	cmp r0, #0
	blt _081D5FC0
	asrs r0, r0, #0xc
	b _081D5FC6
	.align 2, 0
_081D5FBC: .4byte 0x085B0A08
_081D5FC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D5FC6:
	adds r2, r0, #0
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r4, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _081D5FE4
	asrs r0, r0, #0xc
	b _081D5FEA
_081D5FE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D5FEA:
	adds r7, r2, r0
	movs r0, #0x92
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r4, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _081D600A
	asrs r0, r0, #0xc
	b _081D600E
_081D600A:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_081D600E:
	adds r3, r0, #0
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _081D6034
	asrs r2, r0, #0xc
	b _081D603A
_081D6034:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081D603A:
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	adds r0, r0, r7
	mov r1, ip
	strh r0, [r1, #0x1c]
	movs r1, #0x8c
	lsls r1, r1, #1
	add r1, ip
	adds r0, r3, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, ip
	strh r0, [r2, #0x20]
	movs r1, #0x8e
	lsls r1, r1, #1
	add r1, ip
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne _081D6080
	cmp r5, #0
	ble _081D6076
	mov r1, ip
	ldrb r0, [r1, #6]
	subs r0, #1
	strb r0, [r1, #6]
	b _081D60C0
_081D6076:
	mov r2, ip
	ldrb r0, [r2, #6]
	adds r0, #1
	strb r0, [r2, #6]
	b _081D60C0
_081D6080:
	mov r3, ip
	ldrb r0, [r3, #6]
	adds r0, r2, r0
	strb r0, [r3, #6]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble _081D609A
	cmp r5, r0
	ble _081D60C0
	rsbs r0, r0, #0
	strh r0, [r1]
	b _081D60C0
_081D609A:
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r5, r0
	bge _081D60C0
	rsbs r0, r0, #0
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	blt _081D60B2
	asrs r1, r0, #1
	b _081D60B8
_081D60B2:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081D60B8:
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, ip
	strh r1, [r0]
_081D60C0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d60c8
FUN_081d60c8: @ 0x081D60C8
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r5, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081D618C
	adds r0, r5, #0
	adds r0, #0x1c
	ldrh r1, [r5, #0x1c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r6, r0, #0
	cmp r2, #0
	blt _081D6104
	cmp r1, #0
	blt _081D6104
	ldr r0, _081D6108 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D6104
	ldr r0, _081D610C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D6110
_081D6104:
	movs r4, #0
	b _081D611E
	.align 2, 0
_081D6108: .4byte 0x030046A8
_081D610C: .4byte 0x030046AC
_081D6110:
	ldr r0, _081D6130 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D611E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D6134
	adds r0, #4
	b _081D6140
	.align 2, 0
_081D6130: .4byte 0x030046A4
_081D6134:
	ldr r0, _081D6154 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D6140:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r3, r0, #8
	cmp r2, #1
	beq _081D6158
	cmp r2, #2
	beq _081D615C
	b _081D6160
	.align 2, 0
_081D6154: .4byte 0x030046A4
_081D6158:
	ldrb r0, [r6, #4]
	b _081D615E
_081D615C:
	ldrb r0, [r6]
_081D615E:
	subs r3, r3, r0
_081D6160:
	movs r2, #0x9f
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	movs r2, #0
	strh r3, [r1]
	movs r3, #0xab
	lsls r3, r3, #1
	adds r1, r5, r3
	strb r0, [r1]
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r1, r5, r0
	str r2, [sp, #0x20]
	add r0, sp, #0x20
	ldr r2, _081D6188 @ =0x05000002
	bl CpuSet
	b _081D61F6
	.align 2, 0
_081D6188: .4byte 0x05000002
_081D618C:
	movs r1, #0x8f
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r0, [r5, #0x1e]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r5, #0x1e]
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
	movs r2, #0x9f
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r1, [r0]
	movs r2, #0x1e
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt _081D61F6
	strh r1, [r5, #0x1e]
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #4
	strh r1, [r0]
	movs r0, #1
	strb r0, [r3]
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0x1c
	movs r5, #1
_081D61C8:
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r4, #5
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x40
	str r0, [sp, #0x10]
	str r5, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x1c]
	adds r0, r6, #0
	movs r1, #8
	movs r2, #0x10
	movs r3, #4
	bl FUN_081ee584
	adds r4, #1
	cmp r4, #7
	ble _081D61C8
_081D61F6:
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d6200
FUN_081d6200: @ 0x081D6200
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r5, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r8, r0
	ldrb r6, [r0]
	cmp r6, #0
	beq _081D627C
	adds r0, r5, #0
	bl FUN_081d6764
	ldr r1, _081D6270 @ =0x0000013D
	adds r6, r5, r1
	ldrb r0, [r6]
	movs r3, #0x9e
	lsls r3, r3, #1
	adds r4, r5, r3
	ldrb r1, [r4]
	subs r0, r0, r1
	cmp r0, #0
	blt _081D6238
	ldr r0, _081D6274 @ =0x000003C7
	bl PlaySound_082406e0
_081D6238:
	ldrb r1, [r6]
	ldrb r0, [r4]
	subs r1, r1, r0
	adds r0, r5, #0
	bl FUN_081d6ae8
	movs r0, #0xa7
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r1, #0
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081D6262
	adds r0, r5, #0
	adds r0, #0xa8
	bl AuxShadow_Remove
	movs r0, #0xff
	strb r0, [r4]
_081D6262:
	ldr r0, _081D6278 @ =0x000003C6
	bl PlaySound_082406e0
	movs r0, #0
	mov r1, r8
	strb r0, [r1]
	b _081D62B4
	.align 2, 0
_081D6270: .4byte 0x0000013D
_081D6274: .4byte 0x000003C7
_081D6278: .4byte 0x000003C6
_081D627C:
	ldr r0, [r5]
	movs r4, #1
	orrs r0, r4
	str r0, [r5]
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0x58
	bl Hitbox_Unregister
	movs r3, #0xa4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r6, [r0]
	movs r0, #0xa5
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r3, _081D62C0 @ =0x0000057C
	adds r1, r7, r3
	lsls r4, r0
	ldr r0, [r1]
	bics r0, r4
	str r0, [r1]
	ldr r0, _081D62C4 @ =0x0000FFFF
	strh r0, [r2]
_081D62B4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D62C0: .4byte 0x0000057C
_081D62C4: .4byte 0x0000FFFF

	thumb_func_start FUN_081d62c8
FUN_081d62c8: @ 0x081D62C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x1c
	ldr r1, _081D62F8 @ =0x0000057C
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081D632A
	movs r4, #0
	ldr r2, _081D62F8 @ =0x0000057C
	adds r6, r5, r2
	ldr r0, _081D62FC @ =0x085AE104
	mov r8, r0
_081D62E8:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D6300
	movs r0, #1
	b _081D6302
	.align 2, 0
_081D62F8: .4byte 0x0000057C
_081D62FC: .4byte 0x085AE104
_081D6300:
	movs r0, #0
_081D6302:
	cmp r0, #0
	beq _081D6324
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r7
	movs r2, #0xa4
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrh r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081D6324:
	adds r4, #1
	cmp r4, #3
	ble _081D62E8
_081D632A:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d6338
FUN_081d6338: @ 0x081D6338
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r6, #0
	ldr r0, _081D6364 @ =0x0000057C
	adds r0, r0, r7
	mov r8, r0
	movs r2, #1
	rsbs r2, r2, #0
	mov sb, r2
_081D6350:
	movs r1, #1
	lsls r1, r6
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D6368
	movs r0, #1
	b _081D636A
	.align 2, 0
_081D6364: .4byte 0x0000057C
_081D6368:
	movs r0, #0
_081D636A:
	cmp r0, #0
	beq _081D63A0
	movs r0, #0xac
	lsls r0, r0, #1
	muls r0, r6, r0
	adds r0, #0x1c
	adds r4, r7, r0
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0x58
	bl Hitbox_Unregister
	movs r0, #0xa7
	lsls r0, r0, #1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, sb
	beq _081D63A0
	adds r0, r4, #0
	adds r0, #0xa8
	bl AuxShadow_Remove
	movs r0, #0xff
	strb r0, [r5]
_081D63A0:
	adds r6, #1
	cmp r6, #3
	ble _081D6350
	ldr r1, _081D63B8 @ =0x03000198
	movs r0, #0
	str r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D63B8: .4byte 0x03000198

	thumb_func_start FUN_081d63bc
FUN_081d63bc: @ 0x081D63BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081D63DC @ =0x0000922E
	ldr r1, _081D63E0 @ =0x000074C9
	bl GetFile
	str r0, [r4, #0x18]
	ldr r0, _081D63E4 @ =0x03000198
	str r4, [r0]
	ldr r0, _081D63E8 @ =0x0000057C
	adds r4, r4, r0
	movs r0, #0
	str r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081D63DC: .4byte 0x0000922E
_081D63E0: .4byte 0x000074C9
_081D63E4: .4byte 0x03000198
_081D63E8: .4byte 0x0000057C

	thumb_func_start FUN_081d63ec
FUN_081d63ec: @ 0x081D63EC
	push {r4, lr}
	ldr r0, _081D6424 @ =0x03000198
	ldr r0, [r0]
	cmp r0, #0
	bne _081D6432
	movs r1, #0xb0
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D6430
	ldr r1, _081D6428 @ =FUN_081d62c8
	ldr r2, _081D642C @ =FUN_081d6338
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081d63bc
	cmp r0, #0
	bge _081D6430
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D6432
	.align 2, 0
_081D6424: .4byte 0x03000198
_081D6428: .4byte FUN_081d62c8
_081D642C: .4byte FUN_081d6338
_081D6430:
	adds r0, r4, #0
_081D6432:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d6438
FUN_081d6438: @ 0x081D6438
	ldr r1, _081D6440 @ =0x03000198
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D6440: .4byte 0x03000198

	thumb_func_start FUN_081d6444
FUN_081d6444: @ 0x081D6444
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _081D6468 @ =0x00000157
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D646C
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _081D64BE
	.align 2, 0
_081D6468: .4byte 0x00000157
_081D646C:
	ldr r6, _081D64C8 @ =0x0203B400
	ldr r4, _081D64CC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _081D64D0 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r7, r2
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
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, #0xa
	strh r1, [r7, #0x20]
	mov r1, r8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_081D64BE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D64C8: .4byte 0x0203B400
_081D64CC: .4byte 0x030046B8
_081D64D0: .4byte 0x000003FF

	thumb_func_start FUN_081d64d4
FUN_081d64d4: @ 0x081D64D4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	mov sb, r1
	adds r5, r2, #0
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _081D65C8
	adds r0, r4, #0
	bl Hitbox_ApplyDamage
	adds r0, r4, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, sb
	adds r0, #0x44
	strh r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	adds r0, #0x96
	ldrh r2, [r0]
	subs r6, r1, r2
	adds r1, r0, #0
	cmp r6, #0
	bge _081D651C
	adds r6, r6, r2
	b _081D651E
_081D651C:
	adds r6, r2, #0
_081D651E:
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r7, r5, r3
	ldrh r0, [r7]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r4, #0
	mov r8, r4
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081D653A
	mov r0, r8
	strh r0, [r7]
_081D653A:
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r2, #0
	ldrsh r1, [r7, r2]
	movs r3, #0xa1
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r4, #0
	ldrsh r2, [r2, r4]
	ldr r4, _081D65D8 @ =0x00000147
	adds r3, r5, r4
	ldrb r3, [r3]
	mov r4, r8
	str r4, [sp]
	bl FUN_0809c344
	add r4, sp, #0xc
	mov r0, r8
	str r0, [sp, #8]
	add r0, sp, #8
	adds r1, r4, #0
	ldr r2, _081D65DC @ =0x05000002
	bl CpuSet
	adds r3, r5, #0
	adds r3, #0x1c
	str r4, [sp]
	movs r4, #1
	str r4, [sp, #4]
	mov r0, sb
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0805fe7c
	ldr r2, _081D65E0 @ =0x00000153
	adds r1, r5, r2
	movs r0, #3
	strb r0, [r1]
	ldr r3, _081D65E4 @ =0x00000157
	adds r1, r5, r3
	movs r0, #0xa
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #0x9c
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_081d65e8
	adds r0, r5, #0
	bl FUN_081d6bc0
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r0, #0
	bgt _081D65C8
	movs r2, #0xa4
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #4
	strh r0, [r1]
	movs r3, #0xab
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r4, [r0]
_081D65C8:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D65D8: .4byte 0x00000147
_081D65DC: .4byte 0x05000002
_081D65E0: .4byte 0x00000153
_081D65E4: .4byte 0x00000157

	thumb_func_start FUN_081d65e8
FUN_081d65e8: @ 0x081D65E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	add r0, sp, #0x10
	mov r8, r0
	movs r0, #0
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	mov r1, r8
	ldr r2, _081D66A8 @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	mov r1, r8
	strh r0, [r1, #2]
	ldr r5, _081D66AC @ =0x0203B400
	ldr r7, _081D66B0 @ =0x030046B8
	mov ip, r7
	mov r0, ip
	ldr r2, [r0]
	adds r2, #1
	ldr r4, _081D66B4 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #3
	mov sb, r1
	mov r7, sb
	ands r0, r7
	adds r0, #0xf
	ldr r1, _081D66B8 @ =0xFFFF0000
	mov sl, r1
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
	ldr r0, _081D66BC @ =0x0000FFFF
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ands r1, r7
	adds r1, #0xf
	add r3, sp, #0x18
	ldr r0, [r3, #4]
	mov r7, sl
	ands r0, r7
	orrs r0, r1
	str r0, [r3, #4]
	adds r2, #1
	ands r2, r4
	mov r0, ip
	str r2, [r0]
	lsls r2, r2, #1
	adds r2, r2, r5
	ldrh r0, [r2]
	movs r1, #3
	ands r0, r1
	adds r0, #2
	adds r6, #0x1c
	str r3, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0xf
	str r1, [sp, #8]
	movs r1, #0x11
	adds r2, r6, #0
	mov r3, r8
	bl FUN_08014730
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D66A8: .4byte 0x05000002
_081D66AC: .4byte 0x0203B400
_081D66B0: .4byte 0x030046B8
_081D66B4: .4byte 0x000003FF
_081D66B8: .4byte 0xFFFF0000
_081D66BC: .4byte 0x0000FFFF

	thumb_func_start FUN_081d66c0
FUN_081d66c0: @ 0x081D66C0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	mov sb, r3
	adds r4, r7, #0
	adds r4, #0x58
	ldr r2, _081D6754 @ =0xFFFF0000
	ldr r5, _081D6758 @ =0x0000FFFF
	movs r1, #0xa0
	lsls r1, r1, #0xf
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
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	strh r0, [r4, #4]
	ldr r2, _081D675C @ =0x00005001
	movs r0, #0x10
	str r0, [sp]
	str r1, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, r8
	mov r3, sb
	bl Hitbox_SetPowerAndAttributes
	adds r1, r7, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _081D6760 @ =FUN_081d64d4
	adds r0, r4, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D6754: .4byte 0xFFFF0000
_081D6758: .4byte 0x0000FFFF
_081D675C: .4byte 0x00005001
_081D6760: .4byte FUN_081d64d4

	thumb_func_start FUN_081d6764
FUN_081d6764: @ 0x081D6764
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x34
	mov r8, r0
	ldr r2, _081D67A4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D67A8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D67AC @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _081D67B0 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081D67B4
	asrs r1, r0, #0xc
	b _081D67BA
	.align 2, 0
_081D67A4: .4byte 0x030046B8
_081D67A8: .4byte 0x000003FF
_081D67AC: .4byte 0x0203B400
_081D67B0: .4byte 0x085B0A08
_081D67B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D67BA:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _081D67D4 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081D67D8
	asrs r0, r0, #0xc
	b _081D67DE
	.align 2, 0
_081D67D4: .4byte 0x085B0A08
_081D67D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D67DE:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x40
	strh r0, [r2, #2]
	mov r4, r8
	adds r4, #0x1c
	ldr r2, _081D6850 @ =0x00009385
	ldr r3, _081D6854 @ =0x000074C9
	movs r0, #1
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r4, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _081D6858 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D685C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D6860 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r6, #0xa
	ldr r1, _081D6864 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r4, #0
	cmp r0, #0
	blt _081D6868
	asrs r1, r0, #0xc
	b _081D686E
	.align 2, 0
_081D6850: .4byte 0x00009385
_081D6854: .4byte 0x000074C9
_081D6858: .4byte 0x030046B8
_081D685C: .4byte 0x000003FF
_081D6860: .4byte 0x0203B400
_081D6864: .4byte 0x085B0A08
_081D6868:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D686E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081D6888 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081D688C
	asrs r0, r0, #0xc
	b _081D6892
	.align 2, 0
_081D6888: .4byte 0x085B0A08
_081D688C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D6892:
	movs r1, #0
	strh r0, [r5, #4]
	add r2, sp, #0x2c
	movs r0, #0x22
	strh r0, [r2, #2]
	ldr r2, _081D68FC @ =0x00009385
	ldr r3, _081D6900 @ =0x000074C9
	movs r0, #1
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _081D6904 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D6908 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D690C @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r4, #0xa
	ldr r1, _081D6910 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D6914
	asrs r1, r0, #0xc
	b _081D691A
	.align 2, 0
_081D68FC: .4byte 0x00009385
_081D6900: .4byte 0x000074C9
_081D6904: .4byte 0x030046B8
_081D6908: .4byte 0x000003FF
_081D690C: .4byte 0x0203B400
_081D6910: .4byte 0x085B0A08
_081D6914:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D691A:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081D6934 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D6938
	asrs r0, r0, #0xc
	b _081D693E
	.align 2, 0
_081D6934: .4byte 0x085B0A08
_081D6938:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D693E:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x22
	strh r0, [r1, #2]
	ldr r2, _081D69A8 @ =0x00009385
	ldr r3, _081D69AC @ =0x000074C9
	movs r1, #1
	str r1, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r1, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _081D69B0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D69B4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D69B8 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r4, #0xa
	ldr r1, _081D69BC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D69C0
	asrs r1, r0, #0xc
	b _081D69C6
	.align 2, 0
_081D69A8: .4byte 0x00009385
_081D69AC: .4byte 0x000074C9
_081D69B0: .4byte 0x030046B8
_081D69B4: .4byte 0x000003FF
_081D69B8: .4byte 0x0203B400
_081D69BC: .4byte 0x085B0A08
_081D69C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D69C6:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081D69E0 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D69E4
	asrs r0, r0, #0xc
	b _081D69EA
	.align 2, 0
_081D69E0: .4byte 0x085B0A08
_081D69E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D69EA:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x22
	strh r0, [r1, #2]
	ldr r2, _081D6A54 @ =0x00009385
	ldr r3, _081D6A58 @ =0x000074C9
	movs r1, #1
	str r1, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _081D6A5C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D6A60 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D6A64 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r4, #0xa
	ldr r1, _081D6A68 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D6A6C
	asrs r1, r0, #0xc
	b _081D6A72
	.align 2, 0
_081D6A54: .4byte 0x00009385
_081D6A58: .4byte 0x000074C9
_081D6A5C: .4byte 0x030046B8
_081D6A60: .4byte 0x000003FF
_081D6A64: .4byte 0x0203B400
_081D6A68: .4byte 0x085B0A08
_081D6A6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D6A72:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081D6A8C @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D6A90
	asrs r0, r0, #0xc
	b _081D6A96
	.align 2, 0
_081D6A8C: .4byte 0x085B0A08
_081D6A90:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D6A96:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x22
	strh r0, [r1, #2]
	ldr r2, _081D6AE0 @ =0x00009385
	ldr r3, _081D6AE4 @ =0x000074C9
	movs r0, #1
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	mov r0, r8
	bl FUN_081d65e8
	add sp, #0x34
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D6AE0: .4byte 0x00009385
_081D6AE4: .4byte 0x000074C9

	thumb_func_start FUN_081d6ae8
FUN_081d6ae8: @ 0x081D6AE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r2, r1, #0
	cmp r2, #0
	ble _081D6BA0
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081D6BA0
	ldr r1, _081D6BB0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	mov r7, sp
	str r7, [r0, #4]
	mov sl, r0
	cmp r2, #0
	ble _081D6BA0
	ldr r0, _081D6BB4 @ =0x0203B400
	mov r8, r0
	ldr r1, _081D6BB8 @ =0x030046B8
	mov sb, r1
	ldr r3, _081D6BBC @ =0x000003FF
	adds r6, r2, #0
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r5, r4, r2
_081D6B32:
	mov r7, sb
	ldr r1, [r7]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	movs r7, #0x1c
	ldrsh r0, [r4, r7]
	subs r0, #0x40
	movs r7, #0x7f
	ands r2, r7
	adds r0, r0, r2
	str r0, [sp]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	movs r7, #0x1e
	ldrsh r0, [r4, r7]
	subs r0, #0x40
	movs r7, #0x7f
	ands r2, r7
	adds r0, r0, r2
	str r0, [sp, #4]
	adds r1, #1
	ands r1, r3
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	movs r2, #0x20
	ldrsh r0, [r4, r2]
	subs r0, #0x40
	ands r1, r7
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrb r0, [r5]
	str r0, [sp, #0xc]
	adds r7, #0xb9
	adds r0, r4, r7
	ldrh r0, [r0]
	mov r1, sl
	str r3, [sp, #0x18]
	bl Script_ExecById
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	subs r6, #1
	ldr r3, [sp, #0x18]
	cmp r6, #0
	bne _081D6B32
_081D6BA0:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D6BB0: .4byte 0xFFFF0000
_081D6BB4: .4byte 0x0203B400
_081D6BB8: .4byte 0x030046B8
_081D6BBC: .4byte 0x000003FF

	thumb_func_start FUN_081d6bc0
FUN_081d6bc0: @ 0x081D6BC0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _081D6C20 @ =0x0000013D
	adds r0, r4, r1
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r6, r4, r2
	ldrb r0, [r0]
	ldrb r1, [r6]
	cmp r0, r1
	bls _081D6C1A
	adds r2, #6
	adds r0, r4, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r5, r1, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081d5848
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D6C00
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081d6ae8
_081D6C00:
	movs r1, #0x9d
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrb r1, [r6]
	subs r1, #1
	muls r0, r1, r0
	cmp r5, r0
	blt _081D6C1A
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081d6ae8
_081D6C1A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D6C20: .4byte 0x0000013D

	thumb_func_start FUN_081d6c24
FUN_081d6c24: @ 0x081D6C24
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #1
	bl FUN_081d5848
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D6C9E
	ldr r0, _081D6CA8 @ =0x03002BE0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #0x1c
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r2, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r3, #0x98
	lsls r3, r3, #1
	adds r0, r5, r3
	str r1, [r0]
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r1, r0
	bge _081D6C9E
	adds r0, r5, #0
	movs r1, #2
	bl FUN_081d6ae8
	adds r0, r5, #0
	movs r1, #1
	bl FUN_081d5820
	ldr r0, _081D6CAC @ =0x000003C7
	bl PlaySound_082406e0
_081D6C9E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D6CA8: .4byte 0x03002BE0
_081D6CAC: .4byte 0x000003C7

	thumb_func_start FUN_081d6cb0
FUN_081d6cb0: @ 0x081D6CB0
	push {r4, lr}
	sub sp, #8
	mov ip, r0
	ldr r0, _081D6D18 @ =0x03002BE0
	mov r3, sp
	movs r2, #0x8a
	lsls r2, r2, #1
	add r2, ip
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0x96
	lsls r1, r1, #1
	add r1, ip
	movs r2, #0x98
	lsls r2, r2, #1
	add r2, ip
	ldr r0, [r2]
	str r0, [r1]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r4, #4
	ldrsh r0, [r3, r4]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	str r1, [r2]
	movs r0, #0x9a
	lsls r0, r0, #1
	add r0, ip
	ldr r0, [r0]
	cmp r1, r0
	blt _081D6D1C
	movs r0, #0
	b _081D6D1E
	.align 2, 0
_081D6D18: .4byte 0x03002BE0
_081D6D1C:
	movs r0, #1
_081D6D1E:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d6d28
FUN_081d6d28: @ 0x081D6D28
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	movs r1, #8
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D6D4A
	movs r0, #1
	b _081D6D4C
_081D6D4A:
	movs r0, #0
_081D6D4C:
	cmp r0, #0
	beq _081D6D52
	b _081D6EA8
_081D6D52:
	ldr r1, _081D6D70 @ =0x00000109
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D6D74
	movs r2, #2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	bne _081D6D90
	b _081D6D94
	.align 2, 0
_081D6D70: .4byte 0x00000109
_081D6D74:
	movs r1, #0x10
	ldr r0, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	bne _081D6D9A
	movs r2, #2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _081D6D94
_081D6D90:
	movs r0, #1
	b _081D6D96
_081D6D94:
	movs r0, #0
_081D6D96:
	cmp r0, #0
	beq _081D6DA6
_081D6D9A:
	movs r1, #0
	strh r1, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x40
	strh r1, [r0]
	b _081D6EA8
_081D6DA6:
	movs r1, #8
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081D6E80
	adds r1, r7, #0
	adds r1, #0x43
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081D6DEC @ =0x00000109
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D6DF4
	ldr r2, _081D6DF0 @ =0x00000105
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0
	bne _081D6E02
	adds r0, r5, #0
	adds r0, #0x9c
	str r0, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
	movs r0, #3
	strb r0, [r4]
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081D6E2A
	.align 2, 0
_081D6DEC: .4byte 0x00000109
_081D6DF0: .4byte 0x00000105
_081D6DF4:
	cmp r0, #1
	bne _081D6E2A
	ldr r0, _081D6E08 @ =0x00000105
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D6E0C
_081D6E02:
	subs r0, #1
	strb r0, [r4]
	b _081D6E2A
	.align 2, 0
_081D6E08: .4byte 0x00000105
_081D6E0C:
	adds r0, r5, #0
	adds r0, #0x9c
	str r0, [sp]
	movs r0, #2
	movs r1, #2
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
	movs r0, #2
	strb r0, [r4]
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081D6E2A:
	movs r1, #4
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D6E3A
	movs r0, #1
	b _081D6E3C
_081D6E3A:
	movs r0, #0
_081D6E3C:
	cmp r0, #0
	beq _081D6E80
	ldr r1, _081D6E64 @ =0x00000109
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D6E68
	adds r1, r5, #0
	adds r1, #0xf4
	ldrh r0, [r1]
	subs r0, #0xc8
	strh r0, [r1]
	adds r2, r0, #0
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081D6E5E
	movs r2, #0
_081D6E5E:
	strh r2, [r1]
	b _081D6E80
	.align 2, 0
_081D6E64: .4byte 0x00000109
_081D6E68:
	adds r2, r5, #0
	adds r2, #0xf4
	ldrh r0, [r2]
	ldrh r1, [r6, #0x3e]
	subs r0, r0, r1
	strh r0, [r2]
	adds r1, r0, #0
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081D6E7E
	movs r1, #0
_081D6E7E:
	strh r1, [r2]
_081D6E80:
	ldr r2, _081D6EB4 @ =0x00000109
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D6EA8
	ldr r2, [r6, #0x4c]
	cmp r2, #0
	beq _081D6EA8
	ldr r3, [r6, #0x48]
	cmp r3, #0
	beq _081D6EA8
	movs r1, #0x10
	ldr r0, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _081D6EA8
	adds r0, r6, #0
	adds r1, r7, #0
	bl _call_via_r3
_081D6EA8:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D6EB4: .4byte 0x00000109

	thumb_func_start FUN_081d6eb8
FUN_081d6eb8: @ 0x081D6EB8
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldr r1, _081D6EDC @ =0x00000109
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D6EE8
	ldr r2, _081D6EE0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x56
	orrs r0, r3
	ldr r1, _081D6EE4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	b _081D6EFA
	.align 2, 0
_081D6EDC: .4byte 0x00000109
_081D6EE0: .4byte 0xFFFF0000
_081D6EE4: .4byte 0x0000FFFF
_081D6EE8:
	ldr r2, _081D6F50 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x60
	orrs r0, r3
	ldr r1, _081D6F54 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xd
_081D6EFA:
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0xa4
	ldr r2, _081D6F58 @ =0x00004003
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r1, r5, #0
	adds r1, #0x9c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _081D6F5C @ =FUN_081d6d28
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D6F50: .4byte 0xFFFF0000
_081D6F54: .4byte 0x0000FFFF
_081D6F58: .4byte 0x00004003
_081D6F5C: .4byte FUN_081d6d28

	thumb_func_start FUN_081d6f60
FUN_081d6f60: @ 0x081D6F60
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d6f64
FUN_081d6f64: @ 0x081D6F64
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r5, #0
	mov r6, r8
	adds r6, #0xa0
	movs r0, #1
	mov sb, r0
	movs r7, #0x8e
	lsls r7, r7, #1
_081D6F7C:
	mov r1, sb
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D6F8C
	movs r0, #1
	b _081D6F8E
_081D6F8C:
	movs r0, #0
_081D6F8E:
	cmp r0, #0
	bne _081D6FBE
	adds r0, r7, #0
	bl Malloc
	adds r4, r0, #0
	adds r1, r7, #0
	bl ClearMemory
	mov r1, sb
	lsls r1, r5
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	adds r0, r4, #0
	adds r0, #0xfc
	strh r5, [r0]
	lsls r1, r5, #2
	mov r0, r8
	adds r0, #0x20
	adds r0, r0, r1
	str r4, [r0]
	adds r0, r4, #0
	b _081D6FC6
_081D6FBE:
	adds r5, #1
	cmp r5, #0x1f
	ble _081D6F7C
	movs r0, #0
_081D6FC6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d6fd4
FUN_081d6fd4: @ 0x081D6FD4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081D7014 @ =0x0300019C
	ldr r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _081D6FEE
	b _081D7342
_081D6FEE:
	adds r2, r5, #0
	adds r2, #0xe7
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	mov sl, r2
	cmp r0, #0
	bne _081D7020
	movs r2, #4
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D7018
	movs r0, #1
	b _081D701A
	.align 2, 0
_081D7014: .4byte 0x0300019C
_081D7018:
	movs r0, #0
_081D701A:
	cmp r0, #0
	bne _081D7020
	b _081D72A0
_081D7020:
	adds r0, r5, #0
	adds r0, #0xf4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r6, r0, #0
	cmp r1, #0
	ble _081D7030
	b _081D713A
_081D7030:
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #0x28
	str r0, [r1]
	adds r4, r5, #0
	adds r4, #0x8c
	mov r0, r8
	ldr r1, [r0, #0x18]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D707C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D7084
_081D707C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7084:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D70A8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D70B0
_081D70A8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D70B0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D70E8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _081D7120
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D70EC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D70E0
	ldrb r0, [r4, #5]
_081D70E0:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D70FC
	.align 2, 0
_081D70E8: .4byte 0x0000FFFF
_081D70EC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D70FC
	strh r1, [r4, #8]
_081D70FC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D7120
	movs r0, #1
	strb r0, [r4, #7]
_081D7120:
	adds r1, r5, #0
	adds r1, #0xfe
	movs r2, #0
	movs r0, #3
	strh r0, [r1]
	movs r6, #0x82
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #1
	strb r0, [r1]
	mov r0, sl
	strb r2, [r0]
	b _081D7342
_081D713A:
	movs r2, #1
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D7150
	movs r0, #1
	b _081D7152
_081D7150:
	movs r0, #0
_081D7152:
	adds r7, r0, #0
	cmp r7, #0
	beq _081D7194
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #3
	beq _081D7188
	ldrh r4, [r6]
	cmp r4, #3
	ble _081D7174
	subs r0, r4, #6
	cmp r0, #0
	bge _081D7172
	rsbs r0, r0, #0
_081D7172:
	adds r4, r0, #0
_081D7174:
	adds r0, r5, #0
	adds r0, #0x8c
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #0
	str r2, [sp]
	movs r3, #0
	bl FUN_08237040
	strh r4, [r6]
_081D7188:
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #0x22
	str r0, [r1]
	b _081D7342
_081D7194:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x24
	str r0, [r1]
	movs r1, #0
	ldrsh r0, [r6, r1]
	adds r1, r5, #0
	adds r1, #0xf8
	ldr r1, [r1]
	bl Div
	adds r4, r0, #0
	movs r0, #3
	subs r4, r0, r4
	adds r6, r5, #0
	adds r6, #0x8c
	mov r2, r8
	ldr r1, [r2, #0x18]
	str r7, [sp]
	adds r0, r6, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, r4
	bge _081D72A0
	adds r4, r6, #0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D71FE
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D7206
_081D71FE:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7206:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D722A
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D7232
_081D722A:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7232:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081D7268 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D72A0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D726C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7262
	ldrb r0, [r4, #5]
_081D7262:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D727C
	.align 2, 0
_081D7268: .4byte 0x0000FFFF
_081D726C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D727C
	strh r1, [r4, #8]
_081D727C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D72A0
	movs r0, #1
	strb r0, [r4, #7]
_081D72A0:
	mov r6, sl
	ldrb r1, [r6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081D733C
	adds r0, r5, #0
	adds r0, #0xf4
	adds r2, r5, #0
	adds r2, #0xf6
	ldrh r4, [r0]
	movs r1, #0
	ldrsh r3, [r0, r1]
	movs r6, #0
	ldrsh r1, [r2, r6]
	adds r6, r0, #0
	adds r7, r2, #0
	cmp r3, r1
	bge _081D72CE
	adds r0, r4, #0
	adds r0, #0xa
	strh r0, [r6]
	b _081D7334
_081D72CE:
	movs r1, #4
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D72DE
	movs r0, #1
	b _081D72E0
_081D72DE:
	movs r0, #0
_081D72E0:
	cmp r0, #0
	beq _081D7334
	adds r0, r5, #0
	adds r0, #0x8c
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r4, #4
	str r4, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	mov r1, sb
	ldr r0, [r1]
	ands r0, r4
	cmp r0, #0
	beq _081D7306
	movs r0, #1
	b _081D7308
_081D7306:
	movs r0, #0
_081D7308:
	cmp r0, #0
	beq _081D7326
	movs r2, #0
	ldrsh r0, [r6, r2]
	adds r1, r5, #0
	adds r1, #0xf8
	ldr r1, [r1]
	bl Div
	adds r4, r0, #0
	movs r0, #3
	subs r0, r0, r4
	adds r1, r5, #0
	adds r1, #0x94
	strh r0, [r1]
_081D7326:
	ldrh r0, [r7]
	strh r0, [r6]
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #0x30
	str r0, [r1]
_081D7334:
	ldr r0, _081D7354 @ =0x00000105
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
_081D733C:
	movs r0, #0
	mov r1, sl
	strb r0, [r1]
_081D7342:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D7354: .4byte 0x00000105

	thumb_func_start FUN_081d7358
FUN_081d7358: @ 0x081D7358
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	mov ip, r6
	ldr r0, _081D7390 @ =0x0300019C
	ldr r7, [r0]
	cmp r7, #0
	bne _081D736E
	b _081D76B0
_081D736E:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r2, #0x10
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D7394
	movs r0, #1
	b _081D7396
	.align 2, 0
_081D7390: .4byte 0x0300019C
_081D7394:
	movs r0, #0
_081D7396:
	cmp r0, #0
	bne _081D739C
	b _081D74B8
_081D739C:
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r4
	cmp r1, r0
	beq _081D73D2
	mov r2, ip
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D73DE
_081D73D2:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_081D73DE:
	str r0, [r2]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7404
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D740E
_081D7404:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D740E:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7448 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D748E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7452
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D744C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D7468
	.align 2, 0
_081D7448: .4byte 0x0000FFFF
_081D744C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7466
_081D7452:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7466
	strh r1, [r4, #8]
	movs r2, #1
	b _081D7468
_081D7466:
	movs r2, #0
_081D7468:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D7490
	movs r0, #1
	strb r0, [r4, #7]
	b _081D7490
_081D748E:
	movs r2, #0
_081D7490:
	cmp r2, #0
	bne _081D7496
	b _081D76B0
_081D7496:
	ldr r1, [r7, #0x18]
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	adds r1, r6, #0
	adds r1, #0x94
	movs r0, #3
	strh r0, [r1]
	adds r0, #0xfd
	adds r1, r6, r0
	movs r0, #0x21
	str r0, [r1]
	b _081D76B0
_081D74B8:
	movs r1, #2
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081D74C6
	movs r0, #1
	b _081D74C8
_081D74C6:
	movs r0, #0
_081D74C8:
	cmp r0, #0
	beq _081D75C2
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7500
	mov r2, ip
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D750C
_081D7500:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_081D750C:
	str r0, [r2]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7532
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D753C
_081D7532:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D753C:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7574 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D75AC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7578
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D756E
	ldrb r0, [r4, #5]
_081D756E:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7588
	.align 2, 0
_081D7574: .4byte 0x0000FFFF
_081D7578:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7588
	strh r1, [r4, #8]
_081D7588:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D75AC
	movs r0, #1
	strb r0, [r4, #7]
_081D75AC:
	adds r0, r6, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #3
	bne _081D76B0
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x24
	str r0, [r1]
	b _081D76B0
_081D75C2:
	adds r0, r6, #0
	bl FUN_081d6fd4
	movs r1, #1
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081D75D6
	movs r0, #1
	b _081D75D8
_081D75D6:
	movs r0, #0
_081D75D8:
	cmp r0, #0
	beq _081D76B0
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D760C
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D7614
_081D760C:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7614:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7638
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D7640
_081D7638:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7640:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7678 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D76B0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D767C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7670
	ldrb r0, [r4, #5]
_081D7670:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D768C
	.align 2, 0
_081D7678: .4byte 0x0000FFFF
_081D767C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D768C
	strh r1, [r4, #8]
_081D768C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D76B0
	movs r0, #1
	strb r0, [r4, #7]
_081D76B0:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d76bc
FUN_081d76bc: @ 0x081D76BC
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	mov r7, ip
	ldr r5, [r0]
	movs r0, #2
	rsbs r0, r0, #0
	ands r5, r0
	mov r1, ip
	str r5, [r1]
	ldr r0, _081D770C @ =0x0300019C
	ldr r0, [r0]
	cmp r0, #0
	bne _081D76D8
	b _081D780E
_081D76D8:
	mov r4, ip
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	mov r2, ip
	strh r0, [r2, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7710
	movs r0, #4
	orrs r5, r0
	mov r0, ip
	str r5, [r0]
	b _081D771A
	.align 2, 0
_081D770C: .4byte 0x0300019C
_081D7710:
	movs r0, #5
	rsbs r0, r0, #0
	ands r5, r0
	mov r1, ip
	str r5, [r1]
_081D771A:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D773C
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D7744
_081D773C:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7744:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D777C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D77B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7780
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7774
	ldrb r0, [r4, #5]
_081D7774:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7790
	.align 2, 0
_081D777C: .4byte 0x0000FFFF
_081D7780:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7790
	strh r1, [r4, #8]
_081D7790:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D77B4
	movs r0, #1
	strb r0, [r4, #7]
_081D77B4:
	mov r2, ip
	adds r2, #0xe7
	ldrb r1, [r2]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _081D77F2
	mov r0, ip
	adds r0, #0xf4
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	bgt _081D77EC
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0x28
	str r0, [r1]
	mov r1, ip
	adds r1, #0xfe
	movs r0, #4
	strh r0, [r1]
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, ip
	strb r3, [r0]
	b _081D780E
_081D77EC:
	movs r0, #0
	strb r0, [r2]
	b _081D780E
_081D77F2:
	mov r2, ip
	adds r2, #0xf4
	mov r0, ip
	adds r0, #0xf6
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _081D780E
	adds r0, r3, #0
	adds r0, #0xa
	strh r0, [r2]
_081D780E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d7814
FUN_081d7814: @ 0x081D7814
	push {r4, lr}
	adds r3, r0, #0
	adds r0, #0xfe
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _081D7856
	movs r2, #0x20
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D783C
	movs r0, #1
	b _081D783E
_081D783C:
	movs r0, #0
_081D783E:
	cmp r0, #0
	beq _081D7856
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r3, r1
	bl FUN_082342a8
	movs r1, #0x21
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_081D7856:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d785c
FUN_081d785c: @ 0x081D785C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _081D78BC @ =0x0300019C
	ldr r7, [r0]
	cmp r7, #0
	bne _081D786C
	b _081D7A58
_081D786C:
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D788C
	adds r0, r5, #0
	bl FUN_081d7814
	movs r1, #0x83
	lsls r1, r1, #1
	adds r2, r5, r1
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r4]
_081D788C:
	adds r4, r5, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D78C0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D78C8
	.align 2, 0
_081D78BC: .4byte 0x0300019C
_081D78C0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D78C8:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D78EC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D78F4
_081D78EC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D78F4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D792C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D7972
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7936
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7930
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D794C
	.align 2, 0
_081D792C: .4byte 0x0000FFFF
_081D7930:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D794A
_081D7936:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D794A
	strh r1, [r4, #8]
	movs r2, #1
	b _081D794C
_081D794A:
	movs r2, #0
_081D794C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D7974
	movs r0, #1
	strb r0, [r4, #7]
	b _081D7974
_081D7972:
	movs r2, #0
_081D7974:
	movs r0, #0x83
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x1f
	bhi _081D7A4C
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _081D79BA
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #4]
	str r1, [sp, #8]
	add r0, sp, #4
	ldrh r1, [r0]
	subs r1, #0x40
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081D7A48 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	str r1, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D79BA:
	ldrh r0, [r4]
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _081D79EA
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #4]
	str r1, [sp, #8]
	add r0, sp, #4
	ldrh r0, [r0]
	adds r0, #0x40
	add r1, sp, #4
	strh r0, [r1]
	str r1, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D79EA:
	ldrh r0, [r4]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _081D7A18
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #4]
	str r1, [sp, #8]
	add r1, sp, #4
	ldrh r0, [r1, #4]
	adds r0, #0x20
	strh r0, [r1, #4]
	str r1, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D7A18:
	ldrh r0, [r4]
	movs r1, #7
	bl Mod
	cmp r0, #0
	bne _081D7A3C
	adds r4, r7, #0
	adds r4, #0xa4
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bge _081D7A3C
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4]
_081D7A3C:
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	b _081D7A56
	.align 2, 0
_081D7A48: .4byte 0xFFFF0000
_081D7A4C:
	cmp r2, #0
	beq _081D7A58
	adds r1, r5, #0
	adds r1, #0xfe
	movs r0, #0
_081D7A56:
	strh r0, [r1]
_081D7A58:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d7a60
FUN_081d7a60: @ 0x081D7A60
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081D7AC8 @ =0x0300019C
	ldr r4, [r0]
	cmp r4, #0
	bne _081D7A70
	b _081D7C9E
_081D7A70:
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r7, r5, #0
	adds r7, #0x8c
	cmp r0, #0
	bne _081D7A82
	b _081D7B96
_081D7A82:
	adds r0, r5, #0
	bl FUN_081d7814
	ldr r1, [r4, #0x1c]
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #4
	movs r3, #0
	bl FUN_08236fac
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r7]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r7, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7ACC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D7AD4
	.align 2, 0
_081D7AC8: .4byte 0x0300019C
_081D7ACC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7AD4:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7AF8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D7B00
_081D7AF8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7B00:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7B38 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D7B70
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7B3C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7B30
	ldrb r0, [r4, #5]
_081D7B30:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7B4C
	.align 2, 0
_081D7B38: .4byte 0x0000FFFF
_081D7B3C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7B4C
	strh r1, [r4, #8]
_081D7B4C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D7B70
	movs r0, #1
	strb r0, [r4, #7]
_081D7B70:
	movs r0, #0x83
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	adds r0, #0x1c
	str r0, [sp]
	movs r0, #1
	movs r1, #2
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D7B96:
	adds r4, r7, #0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7BC4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D7BCC
_081D7BC4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7BCC:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7BF0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D7BF8
_081D7BF0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7BF8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7C30 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D7C76
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7C3A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7C34
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D7C50
	.align 2, 0
_081D7C30: .4byte 0x0000FFFF
_081D7C34:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7C4E
_081D7C3A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7C4E
	strh r1, [r4, #8]
	movs r2, #1
	b _081D7C50
_081D7C4E:
	movs r2, #0
_081D7C50:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D7C78
	movs r0, #1
	strb r0, [r4, #7]
	b _081D7C78
_081D7C76:
	movs r2, #0
_081D7C78:
	cmp r2, #0
	beq _081D7C9E
	adds r1, r5, #0
	adds r1, #0xfe
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	adds r0, r5, #0
	adds r0, #0x1c
	str r0, [sp]
	movs r0, #3
	movs r1, #2
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D7C9E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d7ca8
FUN_081d7ca8: @ 0x081D7CA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	ldr r0, _081D7D18 @ =0x0300019C
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _081D7CC0
	b _081D7FD2
_081D7CC0:
	bl FUN_081d6f64
	adds r7, r0, #0
	cmp r7, #0
	bne _081D7CCC
	b _081D7FD2
_081D7CCC:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #1
	str r1, [r0]
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r2, r7, #0
	adds r2, #0x9c
	str r2, [sp, #0x14]
	cmp r0, #0
	beq _081D7D02
	bl Script_GetValue
	ldr r1, [sp, #0x14]
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x9e
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0xa0
	strh r0, [r1]
_081D7D02:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D7D1C
	bl Script_GetValue
	str r0, [sp, #8]
	bl Script_GetValue
	b _081D7D22
	.align 2, 0
_081D7D18: .4byte 0x0300019C
_081D7D1C:
	movs r2, #0
	str r2, [sp, #8]
	movs r0, #0
_081D7D22:
	str r0, [sp, #0xc]
	movs r0, #0x68
	movs r1, #0
	bl VM_GetKeywordValue
	movs r1, #0xf4
	adds r1, r1, r7
	mov sb, r1
	strh r0, [r1]
	adds r1, r7, #0
	adds r1, #0xf6
	strh r0, [r1]
	mov r8, r7
	ldr r2, [sp, #0x14]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r4, r7, #0
	adds r4, #0x2c
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r6, r7, #0
	adds r6, #0x8c
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r6, #4]
	movs r3, #1
	adds r2, r3, #0
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	ands r0, r3
	mov r1, sb
	str r1, [sp, #0x18]
	mov sb, r4
	str r6, [sp, #0x10]
	cmp r2, r0
	beq _081D7D8C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D7D94
_081D7D8C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7D94:
	str r0, [r7]
	ldrb r0, [r6, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7DBA
	mov r2, r8
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	b _081D7DC6
_081D7DBA:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
_081D7DC6:
	str r0, [r2]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	ldr r1, _081D7DFC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r6, #7]
	cmp r0, r1
	blo _081D7E34
	movs r0, #0
	strh r0, [r6, #0xe]
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7E00
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _081D7DF6
	ldrb r0, [r6, #5]
_081D7DF6:
	subs r0, #1
	strh r0, [r6, #8]
	b _081D7E10
	.align 2, 0
_081D7DFC: .4byte 0x0000FFFF
_081D7E00:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	ands r0, r2
	ldrb r2, [r6, #5]
	cmp r0, r2
	blo _081D7E10
	strh r1, [r6, #8]
_081D7E10:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r6, #6]
	ldrb r1, [r6, #6]
	ldrh r0, [r6, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r6, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D7E34
	movs r0, #1
	strb r0, [r6, #7]
_081D7E34:
	mov r1, r8
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _081D7E60 @ =0x00000109
	adds r1, r7, r2
	movs r6, #0
	strb r0, [r1]
	ldrb r0, [r1]
	cmp r0, #0
	beq _081D7E64
	cmp r0, #1
	beq _081D7E94
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r7, r0
	b _081D7EC8
	.align 2, 0
_081D7E60: .4byte 0x00000109
_081D7E64:
	ldr r1, _081D7E90 @ =0x00004FDA
	mov r0, sb
	bl Video_GetAuxSprite
	mov r2, sl
	ldr r1, [r2, #0x18]
	str r6, [sp]
	ldr r0, [sp, #0x10]
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	adds r0, r7, #0
	adds r0, #0xfe
	strh r4, [r0]
	movs r0, #3
	mov r1, r8
	strb r0, [r1, #7]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r4, r7, r2
	b _081D7EC8
	.align 2, 0
_081D7E90: .4byte 0x00004FDA
_081D7E94:
	ldr r1, _081D7F1C @ =0x0000863A
	mov r0, sb
	bl Video_GetAuxSprite
	mov r0, sl
	ldr r1, [r0, #0x1c]
	str r6, [sp]
	ldr r0, [sp, #0x10]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r1, r7, #0
	adds r1, #0xfe
	movs r3, #2
	movs r0, #2
	strh r0, [r1]
	movs r2, #4
	adds r0, #0xfe
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r2, r8
	strb r3, [r2, #7]
	adds r4, r1, #0
_081D7EC8:
	ldr r0, _081D7F20 @ =0x00000105
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, [sp, #0x18]
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #3
	bl Div
	adds r1, r7, #0
	adds r1, #0xf8
	str r0, [r1]
	ldr r0, [sp, #8]
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	ldr r0, [sp, #0xc]
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	adds r0, r7, #0
	bl FUN_081d6eb8
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D7F18
	cmp r1, #0
	blt _081D7F18
	ldr r0, _081D7F24 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D7F18
	ldr r0, _081D7F28 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D7F2C
_081D7F18:
	movs r2, #0
	b _081D7F3A
	.align 2, 0
_081D7F1C: .4byte 0x0000863A
_081D7F20: .4byte 0x00000105
_081D7F24: .4byte 0x030046A8
_081D7F28: .4byte 0x030046AC
_081D7F2C:
	ldr r0, _081D7FC4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r2
_081D7F3A:
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r3, [r7, #0x1e]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x18
	movs r1, #0
	str r1, [sp]
	movs r5, #0x80
	str r5, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl FUN_08234270
	movs r1, #0x20
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #0x50
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D7F70
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
_081D7F70:
	ldr r0, [sp, #0x14]
	bl FUN_08241574
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D7FC8
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	adds r4, r7, #0
	adds r4, #0x48
	adds r0, r7, #0
	adds r0, #0xfc
	ldrh r1, [r0]
	adds r1, #0x6f
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	ldr r2, [sp, #0x14]
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	adds r1, r7, #0
	bl FUN_0823b46c
	adds r0, r4, #0
	bl FUN_08002a48
	b _081D7FD2
	.align 2, 0
_081D7FC4: .4byte 0x030046A4
_081D7FC8:
	movs r2, #0x84
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
_081D7FD2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d7fe4
FUN_081d7fe4: @ 0x081D7FE4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r1, r0, #0
	adds r3, r1, #0
	adds r3, #0x20
	adds r2, r1, #0
	adds r2, #0xa0
	ldr r0, [r2]
	cmp r0, #0
	beq _081D8092
	movs r5, #0
	adds r6, r2, #0
	adds r7, r1, #0
	adds r7, #0xa4
	ldr r0, _081D8018 @ =0x085AE118
	mov r8, r0
	adds r4, r3, #0
_081D8008:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D801C
	movs r0, #1
	b _081D801E
	.align 2, 0
_081D8018: .4byte 0x085AE118
_081D801C:
	movs r0, #0
_081D801E:
	cmp r0, #0
	beq _081D8086
	ldr r0, [r4]
	movs r1, #0x80
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D8038
	movs r0, #1
	b _081D803A
_081D8038:
	movs r0, #0
_081D803A:
	cmp r0, #0
	beq _081D8072
	ldr r0, [r4]
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r0, _081D805C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D8060
	movs r0, #1
	b _081D8062
	.align 2, 0
_081D805C: .4byte 0x030046A0
_081D8060:
	movs r0, #0
_081D8062:
	cmp r0, #0
	bne _081D8072
	ldr r0, [r4]
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _081D8086
_081D8072:
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0xfe
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r1, r1, #2
	add r1, r8
	ldr r1, [r1]
	bl _call_via_r1
_081D8086:
	adds r4, #4
	adds r5, #1
	cmp r5, #0x1f
	ble _081D8008
	movs r0, #0xff
	strb r0, [r7]
_081D8092:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d80a0
FUN_081d80a0: @ 0x081D80A0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r6, #0
_081D80A6:
	adds r0, r7, #0
	adds r0, #0xa0
	movs r1, #1
	lsls r1, r6
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D80BA
	movs r0, #1
	b _081D80BC
_081D80BA:
	movs r0, #0
_081D80BC:
	cmp r0, #0
	beq _081D8122
	lsls r1, r6, #2
	adds r0, r7, #0
	adds r0, #0x20
	adds r0, r0, r1
	ldr r5, [r0]
	adds r0, r5, #0
	bl AuxSprite_Remove
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D80EC
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl FUN_0823b284
_081D80EC:
	movs r2, #0x20
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D8102
	movs r0, #1
	b _081D8104
_081D8102:
	movs r0, #0
_081D8104:
	cmp r0, #0
	beq _081D811C
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	bl FUN_082342a8
	movs r1, #0x21
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_081D811C:
	adds r0, r5, #0
	bl Free
_081D8122:
	adds r6, #1
	cmp r6, #0x1f
	ble _081D80A6
	ldr r1, _081D8134 @ =0x0300019C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D8134: .4byte 0x0300019C

	thumb_func_start FUN_081d8138
FUN_081d8138: @ 0x081D8138
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _081D816C @ =0x0000922E
	ldr r1, _081D8170 @ =0x00001003
	adds r0, r5, #0
	bl GetFile
	str r0, [r4, #0x18]
	ldr r1, _081D8174 @ =0x0000931E
	adds r0, r5, #0
	bl GetFile
	str r0, [r4, #0x1c]
	ldr r0, _081D8178 @ =0x0300019C
	str r4, [r0]
	adds r1, r4, #0
	adds r1, #0xa0
	movs r0, #0
	str r0, [r1]
	adds r4, #0xa4
	movs r0, #0xff
	strb r0, [r4]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081D816C: .4byte 0x0000922E
_081D8170: .4byte 0x00001003
_081D8174: .4byte 0x0000931E
_081D8178: .4byte 0x0300019C

	thumb_func_start FUN_081d817c
FUN_081d817c: @ 0x081D817C
	push {r4, lr}
	movs r0, #0xa
	movs r1, #0xa8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D81B0
	ldr r1, _081D81A8 @ =FUN_081d7fe4
	ldr r2, _081D81AC @ =FUN_081d80a0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081d8138
	cmp r0, #0
	bge _081D81B0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D81B2
	.align 2, 0
_081D81A8: .4byte FUN_081d7fe4
_081D81AC: .4byte FUN_081d80a0
_081D81B0:
	adds r0, r4, #0
_081D81B2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d81b8
FUN_081d81b8: @ 0x081D81B8
	ldr r1, _081D81C0 @ =0x0300019C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D81C0: .4byte 0x0300019C

	thumb_func_start FUN_081d81c4
FUN_081d81c4: @ 0x081D81C4
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	movs r5, #0
	movs r0, #0xea
	lsls r0, r0, #2
	adds r6, r2, r0
	movs r7, #1
_081D81D2:
	adds r1, r7, #0
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D81E2
	movs r0, #1
	b _081D81E4
_081D81E2:
	movs r0, #0
_081D81E4:
	cmp r0, #0
	bne _081D821C
	movs r0, #0xdc
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x38
	adds r4, r2, r4
	adds r0, r4, #0
	movs r1, #0xdc
	bl ClearMemory
	adds r1, r7, #0
	lsls r1, r5
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	adds r0, r4, #0
	adds r0, #0xd0
	strh r5, [r0]
	adds r1, r4, #0
	adds r1, #0xd2
	ldr r0, _081D8218 @ =0x0000FFFF
	strh r0, [r1]
	adds r0, r4, #0
	b _081D8224
	.align 2, 0
_081D8218: .4byte 0x0000FFFF
_081D821C:
	adds r5, #1
	cmp r5, #3
	ble _081D81D2
	movs r0, #0
_081D8224:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d822c
FUN_081d822c: @ 0x081D822C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081D828C @ =0x030001A0
	ldr r2, [r0]
	cmp r2, #0
	beq _081D8286
	adds r1, r5, #0
	adds r1, #0xd8
	ldr r0, _081D8290 @ =FUN_081d8368
	str r0, [r1]
	adds r3, r5, #0
	adds r3, #0xd0
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r1, #0xea
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r0, #1
	rsbs r0, r0, #0
	adds r6, r0, #0
	ldr r0, _081D8294 @ =0x0000FFFF
	strh r0, [r3]
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r4, r5, #0
	adds r4, #0xd2
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081D8286
	adds r0, r5, #0
	adds r0, #0x8c
	bl ParticleShadow_Remove
	ldrh r0, [r4]
	orrs r0, r6
	strh r0, [r4]
_081D8286:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D828C: .4byte 0x030001A0
_081D8290: .4byte FUN_081d8368
_081D8294: .4byte 0x0000FFFF

	thumb_func_start FUN_081d8298
FUN_081d8298: @ 0x081D8298
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r2, r0, #0
	ldr r6, _081D8350 @ =0xFFFF0000
	ldr r5, [sp, #0xc]
	ands r5, r6
	ldr r0, _081D8354 @ =0x0000FFF4
	mov sl, r0
	orrs r5, r0
	str r5, [sp, #0xc]
	ldr r3, _081D8358 @ =0x0203B400
	mov sb, r3
	ldr r7, _081D835C @ =0x030046B8
	ldr r1, [r7]
	adds r1, #1
	ldr r0, _081D8360 @ =0x000003FF
	mov r8, r0
	ands r1, r0
	lsls r0, r1, #1
	add r0, sb
	ldrh r3, [r0]
	movs r7, #7
	mov ip, r7
	mov r0, ip
	ands r3, r0
	lsls r3, r3, #0x10
	ldr r4, _081D8364 @ =0x0000FFFF
	adds r0, r4, #0
	ands r0, r5
	orrs r0, r3
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r6
	mov r3, sl
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r3, [sp, #0x14]
	ands r3, r6
	movs r5, #0x18
	orrs r3, r5
	str r3, [sp, #0x14]
	adds r1, #1
	mov r7, r8
	ands r1, r7
	lsls r0, r1, #1
	add r0, sb
	ldrh r0, [r0]
	mov r7, ip
	ands r0, r7
	adds r0, #3
	lsls r0, r0, #0x10
	ands r4, r3
	orrs r4, r0
	str r4, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r6
	orrs r0, r5
	str r0, [r3, #4]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	ldr r7, _081D835C @ =0x030046B8
	str r1, [r7]
	lsls r1, r1, #1
	add r1, sb
	ldrh r0, [r1]
	movs r1, #3
	ands r0, r1
	adds r0, #3
	adds r2, #0x1c
	str r3, [sp]
	movs r1, #0x3c
	str r1, [sp, #4]
	movs r1, #0x3f
	str r1, [sp, #8]
	movs r1, #2
	add r3, sp, #0xc
	bl FUN_08014730
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D8350: .4byte 0xFFFF0000
_081D8354: .4byte 0x0000FFF4
_081D8358: .4byte 0x0203B400
_081D835C: .4byte 0x030046B8
_081D8360: .4byte 0x000003FF
_081D8364: .4byte 0x0000FFFF

	thumb_func_start FUN_081d8368
FUN_081d8368: @ 0x081D8368
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d836c
FUN_081d836c: @ 0x081D836C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D839A
	cmp r1, #0
	blt _081D839A
	ldr r0, _081D83A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D839A
	ldr r0, _081D83A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D83A8
_081D839A:
	movs r0, #0
	b _081D83B6
	.align 2, 0
_081D83A0: .4byte 0x030046A8
_081D83A4: .4byte 0x030046AC
_081D83A8:
	ldr r0, _081D8424 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D83B6:
	mov r8, r0
	adds r0, r6, #0
	adds r0, #0xd4
	ldrb r1, [r0]
	mov sb, r0
	adds r7, r6, #0
	adds r7, #0xd6
	adds r4, r6, #0
	adds r4, #0x2c
	cmp r1, #0
	beq _081D83F6
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r0, r6, #0
	adds r0, #0x8c
	bl ParticleShadow_Show
	movs r1, #0
	movs r0, #0
	strh r0, [r7]
	mov r2, sb
	strb r1, [r2]
	adds r0, r6, #0
	adds r0, #0xd5
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08237098
_081D83F6:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8428
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D8430
	.align 2, 0
_081D8424: .4byte 0x030046A4
_081D8428:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D8430:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8454
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D845C
_081D8454:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D845C:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D8494 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D84CC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D8498
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D848C
	ldrb r0, [r4, #5]
_081D848C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D84A8
	.align 2, 0
_081D8494: .4byte 0x0000FFFF
_081D8498:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D84A8
	strh r1, [r4, #8]
_081D84A8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D84CC
	movs r0, #1
	strb r0, [r4, #7]
_081D84CC:
	ldrh r0, [r6, #0x1e]
	ldrh r1, [r7]
	subs r0, r0, r1
	strh r0, [r6, #0x1e]
	adds r4, r6, #0
	adds r4, #0x3c
	adds r5, r6, #0
	adds r5, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	mov r0, r8
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D84FC
	adds r0, #4
	b _081D850A
_081D84FC:
	ldr r0, _081D8520 @ =0x030046A4
	ldr r1, [r0]
	mov r2, r8
	lsls r0, r2, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D850A:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081D8524
	cmp r3, #2
	beq _081D8528
	b _081D852C
	.align 2, 0
_081D8520: .4byte 0x030046A4
_081D8524:
	ldrb r0, [r5, #4]
	b _081D852A
_081D8528:
	ldrb r0, [r5]
_081D852A:
	subs r2, r2, r0
_081D852C:
	movs r1, #0x1e
	ldrsh r0, [r6, r1]
	cmp r0, r2
	bgt _081D854C
	adds r0, r6, #0
	adds r0, #0xd8
	ldr r1, _081D8548 @ =FUN_081d85a8
	str r1, [r0]
	strh r2, [r6, #0x1e]
	movs r0, #1
	mov r2, sb
	strb r0, [r2]
	b _081D8552
	.align 2, 0
_081D8548: .4byte FUN_081d85a8
_081D854C:
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
_081D8552:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d8560
FUN_081d8560: @ 0x081D8560
	push {r4, r5, lr}
	sub sp, #0x20
	adds r5, r0, #0
	movs r4, #0
_081D8568:
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r4, #5
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x40
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	movs r0, #0
	str r0, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x1c]
	adds r0, r5, #0
	adds r0, #0x1c
	movs r1, #8
	movs r2, #0x10
	movs r3, #4
	bl FUN_081ee584
	adds r4, #1
	cmp r4, #2
	ble _081D8568
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d85a8
FUN_081d85a8: @ 0x081D85A8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081D8640 @ =0x030001A0
	ldr r2, [r0]
	cmp r2, #0
	bne _081D85B8
	b _081D8706
_081D85B8:
	adds r1, r5, #0
	adds r1, #0xd4
	ldrb r0, [r1]
	adds r6, r5, #0
	adds r6, #0x2c
	cmp r0, #0
	beq _081D85E6
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldr r1, [r2, #0x34]
	movs r0, #1
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #6
	movs r3, #1
	bl FUN_08236fac
	adds r0, r6, #0
	movs r1, #0x20
	bl FUN_08237098
_081D85E6:
	adds r4, r5, #0
	adds r4, #0xd6
	ldrh r0, [r4]
	lsls r0, r0, #3
	movs r1, #0xa
	bl Div
	strh r0, [r4]
	ldrh r1, [r5, #0x1e]
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	subs r4, #0x9a
	adds r1, r5, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r4, r6, #0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8644
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D864C
	.align 2, 0
_081D8640: .4byte 0x030001A0
_081D8644:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D864C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8670
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D8678
_081D8670:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D8678:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D86B0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D86E8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D86B4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D86A8
	ldrb r0, [r4, #5]
_081D86A8:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D86C4
	.align 2, 0
_081D86B0: .4byte 0x0000FFFF
_081D86B4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D86C4
	strh r1, [r4, #8]
_081D86C4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D86E8
	movs r0, #1
	strb r0, [r4, #7]
_081D86E8:
	ldrh r0, [r5, #0x34]
	cmp r0, #3
	bne _081D8706
	adds r0, r5, #0
	bl FUN_081d8298
	adds r0, r5, #0
	bl FUN_081d8560
	adds r0, r5, #0
	bl FUN_081d822c
	ldr r0, _081D8710 @ =0x000001E1
	bl PlaySound_082406e0
_081D8706:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D8710: .4byte 0x000001E1

	thumb_func_start FUN_081d8714
FUN_081d8714: @ 0x081D8714
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _081D8768 @ =0x030001A0
	ldr r5, [r0]
	cmp r5, #0
	beq _081D8760
	adds r4, r5, #0
	adds r4, #0x18
	ldr r1, _081D876C @ =0x00005290
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, _081D8770 @ =0x0000922E
	ldr r1, _081D8774 @ =0x00001E38
	bl GetFile
	adds r1, r0, #0
	str r1, [r5, #0x34]
	adds r0, r6, #0
	adds r0, #0x2c
	movs r2, #1
	str r2, [sp]
	movs r2, #8
	movs r3, #1
	bl FUN_08236fac
	ldr r0, _081D8778 @ =0x00000201
	adds r1, r7, r0
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
_081D8760:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D8768: .4byte 0x030001A0
_081D876C: .4byte 0x00005290
_081D8770: .4byte 0x0000922E
_081D8774: .4byte 0x00001E38
_081D8778: .4byte 0x00000201

	thumb_func_start FUN_081d877c
FUN_081d877c: @ 0x081D877C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r4, #0
	movs r0, #0xea
	lsls r0, r0, #2
	adds r6, r5, r0
_081D8788:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D8798
	movs r0, #1
	b _081D879A
_081D8798:
	movs r0, #0
_081D879A:
	cmp r0, #0
	beq _081D87B4
	movs r0, #0xdc
	muls r0, r4, r0
	movs r2, #0x88
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r1, r1, r0
	adds r0, #0x38
	adds r0, r5, r0
	ldr r1, [r1]
	bl _call_via_r1
_081D87B4:
	adds r4, #1
	cmp r4, #3
	ble _081D8788
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d87c4
FUN_081d87c4: @ 0x081D87C4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	movs r6, #0
	movs r7, #0xea
	lsls r7, r7, #2
	add r7, r8
	movs r0, #1
	rsbs r0, r0, #0
	mov sl, r0
	movs r1, #1
	mov sb, r1
_081D87E2:
	mov r1, sb
	lsls r1, r6
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D87F2
	movs r0, #1
	b _081D87F4
_081D87F2:
	movs r0, #0
_081D87F4:
	cmp r0, #0
	beq _081D882A
	movs r0, #0xdc
	muls r0, r6, r0
	adds r0, #0x38
	mov r1, r8
	adds r4, r1, r0
	mov r1, sb
	lsls r1, r6
	ldr r0, [r7]
	bics r0, r1
	str r0, [r7]
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r5, r4, #0
	adds r5, #0xd2
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, sl
	beq _081D882A
	adds r0, r4, #0
	adds r0, #0x8c
	bl ParticleShadow_Remove
	ldr r0, _081D8844 @ =0x0000FFFF
	strh r0, [r5]
_081D882A:
	adds r6, #1
	cmp r6, #3
	ble _081D87E2
	ldr r1, _081D8848 @ =0x030001A0
	movs r0, #0
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D8844: .4byte 0x0000FFFF
_081D8848: .4byte 0x030001A0

	thumb_func_start FUN_081d884c
FUN_081d884c: @ 0x081D884C
	ldr r1, _081D8854 @ =0x030001A0
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_081D8854: .4byte 0x030001A0

	thumb_func_start FUN_081d8858
FUN_081d8858: @ 0x081D8858
	push {r4, lr}
	ldr r0, _081D8890 @ =0x030001A0
	ldr r0, [r0]
	cmp r0, #0
	bne _081D889E
	movs r1, #0xeb
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D889C
	ldr r1, _081D8894 @ =FUN_081d877c
	ldr r2, _081D8898 @ =FUN_081d87c4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081d884c
	cmp r0, #0
	bge _081D889C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D889E
	.align 2, 0
_081D8890: .4byte 0x030001A0
_081D8894: .4byte FUN_081d877c
_081D8898: .4byte FUN_081d87c4
_081D889C:
	adds r0, r4, #0
_081D889E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d88a4
FUN_081d88a4: @ 0x081D88A4
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d88a8
FUN_081d88a8: @ 0x081D88A8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r4, r7, #0
	adds r4, #0x3c
	ldr r2, _081D8934 @ =0xFFFF0000
	ldr r1, _081D8938 @ =0x0000FFFF
	movs r0, #0xc8
	lsls r0, r0, #0xe
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x54
	orrs r0, r3
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	adds r0, r7, #0
	adds r0, #0xcc
	ldrh r0, [r0]
	strh r0, [r4, #4]
	ldr r2, _081D893C @ =0x00002001
	movs r0, #0x20
	str r0, [sp]
	str r1, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	movs r3, #0x80
	lsls r3, r3, #6
	ldr r0, _081D8940 @ =0x00440008
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Hitbox_SetAttack
	adds r1, r7, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _081D8944 @ =FUN_081d88a4
	adds r0, r4, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D8934: .4byte 0xFFFF0000
_081D8938: .4byte 0x0000FFFF
_081D893C: .4byte 0x00002001
_081D8940: .4byte 0x00440008
_081D8944: .4byte FUN_081d88a4

	thumb_func_start FUN_081d8948
FUN_081d8948: @ 0x081D8948
	push {r4, r5, r6, r7, lr}
	ldr r0, _081D89AC @ =0x030001A0
	ldr r0, [r0]
	cmp r0, #0
	bne _081D895A
	bl FUN_081d8858
	cmp r0, #0
	beq _081D89EC
_081D895A:
	bl FUN_081d81c4
	adds r5, r0, #0
	cmp r5, #0
	beq _081D89EC
	movs r1, #2
	bl FUN_081d8714
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D8986
	bl Script_GetValue
	strh r0, [r5, #0x1c]
	bl Script_GetValue
	strh r0, [r5, #0x1e]
	bl Script_GetValue
	strh r0, [r5, #0x20]
_081D8986:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0xcc
	strh r0, [r1]
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D89B0
	bl Script_GetValue
	adds r7, r0, #0
	bl Script_GetValue
	adds r6, r0, #0
	b _081D89B4
	.align 2, 0
_081D89AC: .4byte 0x030001A0
_081D89B0:
	movs r7, #0x64
	movs r6, #0x64
_081D89B4:
	adds r1, r5, #0
	adds r1, #0xd4
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xd5
	strb r2, [r0]
	adds r1, #4
	ldr r0, _081D89F4 @ =FUN_081d836c
	str r0, [r1]
	adds r4, r5, #0
	adds r4, #0x8c
	subs r1, #0xbc
	adds r0, r4, #0
	bl ParticleShadow_Init
	adds r1, r5, #0
	adds r1, #0xd2
	strh r0, [r1]
	adds r0, r4, #0
	bl ParticleShadow_Hide
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl FUN_081d88a8
_081D89EC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D89F4: .4byte FUN_081d836c

	thumb_func_start FUN_081d89f8
FUN_081d89f8: @ 0x081D89F8
	ldr r1, _081D8A00 @ =0x030001A0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D8A00: .4byte 0x030001A0

	thumb_func_start FUN_081d8a04
FUN_081d8a04: @ 0x081D8A04
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, #0x6e
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d8a14
FUN_081d8a14: @ 0x081D8A14
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, #0x6e
	ldrh r2, [r0]
	bics r2, r1
	strh r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d8a24
FUN_081d8a24: @ 0x081D8A24
	push {lr}
	adds r0, #0x6e
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081D8A34
	movs r0, #0
	b _081D8A36
_081D8A34:
	movs r0, #1
_081D8A36:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d8a3c
FUN_081d8a3c: @ 0x081D8A3C
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r5, #0
	ldr r0, _081D8A58 @ =0x00000ECC
	adds r2, r3, r0
	movs r6, #1
_081D8A48:
	adds r1, r6, #0
	lsls r1, r5
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D8A5C
	movs r0, #1
	b _081D8A5E
	.align 2, 0
_081D8A58: .4byte 0x00000ECC
_081D8A5C:
	movs r0, #0
_081D8A5E:
	cmp r0, #0
	bne _081D8A88
	movs r0, #0xbc
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x1c
	adds r4, r3, r4
	adds r1, r6, #0
	lsls r1, r5
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	movs r1, #0xbc
	bl ClearMemory
	adds r0, r4, #0
	adds r0, #0x6c
	strh r5, [r0]
	adds r0, r4, #0
	b _081D8A90
_081D8A88:
	adds r5, #1
	cmp r5, #0x13
	ble _081D8A48
	movs r0, #0
_081D8A90:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d8a98
FUN_081d8a98: @ 0x081D8A98
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r0, _081D8B34 @ =0x030001A4
	ldr r6, [r0]
	cmp r6, #0
	bne _081D8AB0
	bl FUN_081d9a08
	adds r6, r0, #0
	cmp r6, #0
	bne _081D8AB0
	b _081D8C78
_081D8AB0:
	adds r0, r6, #0
	bl FUN_081d8a3c
	adds r5, r0, #0
	cmp r5, #0
	bne _081D8ABE
	b _081D8C78
_081D8ABE:
	adds r7, r5, #0
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r1, _081D8B38 @ =0x00005A6E
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [r5, #0xc]
	ldr r1, _081D8B3C @ =0x0000014F
	bl Video_SetAuxSpritePltt
	adds r1, r5, #0
	adds r1, #0x68
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	strb r2, [r0]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D8B0A
	bl Script_GetValue
	strh r0, [r5, #0x1c]
	bl Script_GetValue
	strh r0, [r5, #0x1e]
	bl Script_GetValue
	strh r0, [r5, #0x20]
_081D8B0A:
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D8B40
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x60
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x62
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x64
	strh r0, [r1]
	b _081D8B52
	.align 2, 0
_081D8B34: .4byte 0x030001A4
_081D8B38: .4byte 0x00005A6E
_081D8B3C: .4byte 0x0000014F
_081D8B40:
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_081D8B52:
	movs r1, #0
	movs r0, #2
	strb r0, [r7, #7]
	adds r0, r5, #0
	adds r0, #0x6e
	strh r1, [r0]
	ldr r2, _081D8BB4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D8BB8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D8BBC @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #1
	ands r2, r0
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r1, [r6, #0x18]
	str r2, [sp]
	adds r0, r4, #0
	movs r2, #4
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8BC0
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D8BC8
	.align 2, 0
_081D8BB4: .4byte 0x030046B8
_081D8BB8: .4byte 0x000003FF
_081D8BBC: .4byte 0x0203B400
_081D8BC0:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D8BC8:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8BEC
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D8BF4
_081D8BEC:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D8BF4:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D8C2C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D8C64
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D8C30
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D8C24
	ldrb r0, [r4, #5]
_081D8C24:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D8C40
	.align 2, 0
_081D8C2C: .4byte 0x0000FFFF
_081D8C30:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D8C40
	strh r1, [r4, #8]
_081D8C40:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D8C64
	movs r0, #1
	strb r0, [r4, #7]
_081D8C64:
	adds r0, r5, #0
	adds r0, #0x7c
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #0
	bl ParticleShadow_Init
	adds r1, r5, #0
	adds r1, #0x79
	strb r0, [r1]
_081D8C78:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d8c80
FUN_081d8c80: @ 0x081D8C80
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	ble _081D8CA6
	movs r0, #1
	strb r0, [r2]
	movs r0, #3
	subs r0, r0, r1
	strb r0, [r3]
	b _081D8CAC
_081D8CA6:
	movs r0, #0
	strb r0, [r2]
	strb r1, [r3]
_081D8CAC:
	pop {r0}
	bx r0

	thumb_func_start FUN_081d8cb0
FUN_081d8cb0: @ 0x081D8CB0
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, _081D8D14 @ =0x03002BE0
	ldr r3, [r0]
	cmp r3, #0
	beq _081D8D18
	movs r0, #0x1c
	ldrsh r1, [r2, r0]
	movs r4, #0x2c
	ldrsh r0, [r3, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8CCC
	rsbs r1, r1, #0
_081D8CCC:
	adds r0, r2, #0
	adds r0, #0x60
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _081D8D18
	movs r0, #0x20
	ldrsh r1, [r2, r0]
	movs r4, #0x30
	ldrsh r0, [r3, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8CE8
	rsbs r1, r1, #0
_081D8CE8:
	adds r0, r2, #0
	adds r0, #0x64
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _081D8D18
	movs r0, #0x1e
	ldrsh r1, [r2, r0]
	movs r4, #0x2e
	ldrsh r0, [r3, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8D04
	rsbs r1, r1, #0
_081D8D04:
	adds r0, r2, #0
	adds r0, #0x62
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _081D8D18
	movs r0, #1
	b _081D8D1A
	.align 2, 0
_081D8D14: .4byte 0x03002BE0
_081D8D18:
	movs r0, #0
_081D8D1A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d8d20
FUN_081d8d20: @ 0x081D8D20
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080865c0
	adds r2, r0, #0
	cmp r2, #0
	beq _081D8D86
	movs r0, #0x1c
	ldrsh r1, [r4, r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8D3E
	rsbs r1, r1, #0
_081D8D3E:
	adds r0, r4, #0
	adds r0, #0x60
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _081D8D86
	movs r0, #0x20
	ldrsh r1, [r4, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8D5A
	rsbs r1, r1, #0
_081D8D5A:
	adds r0, r4, #0
	adds r0, #0x64
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _081D8D86
	movs r0, #0x1e
	ldrsh r1, [r4, r0]
	movs r3, #2
	ldrsh r0, [r2, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8D76
	rsbs r1, r1, #0
_081D8D76:
	adds r0, r4, #0
	adds r0, #0x62
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _081D8D86
	movs r0, #1
	b _081D8D88
_081D8D86:
	movs r0, #0
_081D8D88:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d8d90
FUN_081d8d90: @ 0x081D8D90
	push {lr}
	movs r2, #0xed
	lsls r2, r2, #4
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, #0
	beq _081D8DA6
	subs r0, #1
	str r0, [r1]
	movs r0, #0
	b _081D8DBA
_081D8DA6:
	movs r0, #0xe1
	lsls r0, r0, #4
	str r0, [r1]
	bl FUN_0823e1b0
	cmp r0, #2
	bgt _081D8DB8
	movs r0, #0
	b _081D8DBA
_081D8DB8:
	movs r0, #1
_081D8DBA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d8dc0
FUN_081d8dc0: @ 0x081D8DC0
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d8dc4
FUN_081d8dc4: @ 0x081D8DC4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	mov r8, r0
	adds r6, r1, #0
	adds r3, r6, #0
	adds r3, #0x74
	ldrb r0, [r3]
	cmp r0, #0
	bne _081D8DDC
	b _081D8F10
_081D8DDC:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r2, r6, #0
	adds r2, #0x72
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r3]
	ldr r5, _081D8E48 @ =0x0203B400
	ldr r2, _081D8E4C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D8E50 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r3, #1
	strb r0, [r3]
	ldrb r4, [r3]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r5, r6, #0
	adds r5, #0x58
	adds r7, r4, #0
	adds r1, #3
	mov ip, r1
	ldr r4, _081D8E54 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081D8E58
	asrs r1, r0, #0xc
	b _081D8E5E
	.align 2, 0
_081D8E48: .4byte 0x0203B400
_081D8E4C: .4byte 0x030046B8
_081D8E50: .4byte 0x000003FF
_081D8E54: .4byte 0x085B0A08
_081D8E58:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D8E5E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r7, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081D8E7A
	asrs r0, r0, #0xc
	b _081D8E80
_081D8E7A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D8E80:
	strh r0, [r5, #4]
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D8EC8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081D8ECC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #4
	adds r1, r6, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D8EC4
	cmp r1, #0
	blt _081D8EC4
	ldr r0, _081D8ED0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D8EC4
	ldr r0, _081D8ED4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D8ED8
_081D8EC4:
	movs r0, #0
	b _081D8EE6
	.align 2, 0
_081D8EC8: .4byte 0x000003FF
_081D8ECC: .4byte 0x0203B400
_081D8ED0: .4byte 0x030046A8
_081D8ED4: .4byte 0x030046AC
_081D8ED8:
	ldr r0, _081D8F40 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D8EE6:
	adds r2, r6, #0
	adds r2, #0x76
	strh r0, [r2]
	ldrb r0, [r3]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	adds r0, r6, #0
	adds r0, #0x2c
	mov r2, r8
	ldr r1, [r2, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #4
	bl FUN_08236fac
_081D8F10:
	adds r0, r6, #0
	bl FUN_081d8cb0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D8F5E
	adds r0, r6, #0
	bl FUN_081d8d20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D8F5E
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, _081D8F44 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _081D8F48 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D8F4C
	movs r0, #1
	b _081D8F4E
	.align 2, 0
_081D8F40: .4byte 0x030046A4
_081D8F44: .4byte 0x030046A0
_081D8F48: .4byte 0x00000934
_081D8F4C:
	movs r0, #0
_081D8F4E:
	cmp r0, #0
	bne _081D8F5E
	mov r0, r8
	bl FUN_081d8d90
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D8F6E
_081D8F5E:
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #3
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
	b _081D918E
_081D8F6E:
	adds r0, r6, #0
	adds r0, #0x1c
	ldrh r1, [r6, #0x1c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r5, r0, #0
	cmp r2, #0
	blt _081D8F98
	cmp r1, #0
	blt _081D8F98
	ldr r0, _081D8F9C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D8F98
	ldr r0, _081D8FA0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D8FA4
_081D8F98:
	movs r4, #0
	b _081D8FB2
	.align 2, 0
_081D8F9C: .4byte 0x030046A8
_081D8FA0: .4byte 0x030046AC
_081D8FA4:
	ldr r0, _081D8FC4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D8FB2:
	adds r7, r5, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D8FC8
	adds r0, #4
	b _081D8FD4
	.align 2, 0
_081D8FC4: .4byte 0x030046A4
_081D8FC8:
	ldr r0, _081D8FE8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D8FD4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081D8FEC
	cmp r2, #2
	beq _081D8FF0
	b _081D8FF4
	.align 2, 0
_081D8FE8: .4byte 0x030046A4
_081D8FEC:
	ldrb r0, [r7, #4]
	b _081D8FF2
_081D8FF0:
	ldrb r0, [r7]
_081D8FF2:
	subs r1, r1, r0
_081D8FF4:
	adds r7, r1, #0
	add r3, sp, #0xc
	adds r2, r6, #0
	adds r2, #0x58
	ldrh r1, [r6, #0x1c]
	ldrh r0, [r2]
	adds r1, r1, r0
	strh r1, [r3]
	ldrh r0, [r5, #2]
	ldrh r4, [r2, #2]
	adds r0, r0, r4
	strh r0, [r3, #2]
	ldrh r0, [r5, #4]
	ldrh r4, [r2, #4]
	adds r0, r0, r4
	strh r0, [r3, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _081D9034
	cmp r1, #0
	blt _081D9034
	ldr r0, _081D9038 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081D9034
	ldr r0, _081D903C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D9040
_081D9034:
	movs r1, #0
	b _081D904E
	.align 2, 0
_081D9038: .4byte 0x030046A8
_081D903C: .4byte 0x030046AC
_081D9040:
	ldr r0, _081D9064 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r4
_081D904E:
	adds r0, r6, #0
	adds r0, #0x76
	ldrh r0, [r0]
	cmp r0, r1
	bne _081D9068
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	b _081D9076
	.align 2, 0
_081D9064: .4byte 0x030046A4
_081D9068:
	movs r0, #0
	strh r0, [r2]
	adds r1, r6, #0
	adds r1, #0x5c
	strh r0, [r1]
	ldrh r0, [r3, #2]
	strh r0, [r6, #0x1e]
_081D9076:
	adds r1, r6, #0
	adds r1, #0x5a
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
	movs r1, #0x1e
	ldrsh r0, [r6, r1]
	cmp r7, r0
	blt _081D90B0
	strh r7, [r6, #0x1e]
	add r0, sp, #8
	movs r1, #0
	str r1, [sp, #8]
	adds r1, r2, #0
	ldr r2, _081D90AC @ =0x05000002
	bl CpuSet
	adds r1, r6, #0
	adds r1, #0x68
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x74
	strb r2, [r0]
	b _081D918E
	.align 2, 0
_081D90AC: .4byte 0x05000002
_081D90B0:
	adds r4, r6, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D90E0
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D90E8
_081D90E0:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D90E8:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D910C
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D9114
_081D910C:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D9114:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D914C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D9184
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D9150
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D9144
	ldrb r0, [r4, #5]
_081D9144:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D9160
	.align 2, 0
_081D914C: .4byte 0x0000FFFF
_081D9150:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D9160
	strh r1, [r4, #8]
_081D9160:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D9184
	movs r0, #1
	strb r0, [r4, #7]
_081D9184:
	adds r1, r6, #0
	adds r1, #0x72
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081D918E:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d919c
FUN_081d919c: @ 0x081D919C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r6, r1, #0
	adds r7, r6, #0
	adds r7, #0x74
	ldrb r0, [r7]
	cmp r0, #0
	beq _081D91F8
	ldr r5, _081D9228 @ =0x0203B400
	ldr r2, _081D922C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _081D9230 @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x5a
	adds r3, r6, #0
	adds r3, #0x70
	movs r1, #0
	strh r0, [r3]
	strb r1, [r7]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r7, r3, #0
	cmp r0, #0x17
	bgt _081D91F8
	adds r0, r6, #0
	movs r1, #1
	bl FUN_081d8a04
	ldrh r0, [r7]
	adds r0, #0x3c
	strh r0, [r7]
_081D91F8:
	adds r0, r6, #0
	bl FUN_081d8cb0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D924E
	adds r0, r6, #0
	bl FUN_081d8d20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D924E
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, _081D9234 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _081D9238 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D923C
	movs r0, #1
	b _081D923E
	.align 2, 0
_081D9228: .4byte 0x0203B400
_081D922C: .4byte 0x030046B8
_081D9230: .4byte 0x000003FF
_081D9234: .4byte 0x030046A0
_081D9238: .4byte 0x00000934
_081D923C:
	movs r0, #0
_081D923E:
	cmp r0, #0
	bne _081D924E
	mov r0, r8
	bl FUN_081d8d90
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D9256
_081D924E:
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #3
	b _081D939A
_081D9256:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_081d8a24
	lsls r0, r0, #0x18
	adds r7, r6, #0
	adds r7, #0x70
	adds r5, r6, #0
	adds r5, #0x2c
	cmp r0, #0
	beq _081D92A0
	ldrh r0, [r7]
	cmp r0, #0x28
	bhi _081D92A0
	adds r0, r6, #0
	adds r0, #0x75
	ldrb r0, [r0]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	mov r0, r8
	ldr r1, [r0, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #6
	bl FUN_08236fac
	adds r0, r6, #0
	movs r1, #1
	bl FUN_081d8a14
_081D92A0:
	adds r4, r5, #0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D92CE
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D92D6
_081D92CE:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D92D6:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D92FA
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D9302
_081D92FA:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D9302:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D933C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D9382
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D9346
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D9340
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D935C
	.align 2, 0
_081D933C: .4byte 0x0000FFFF
_081D9340:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D935A
_081D9346:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D935A
	strh r1, [r4, #8]
	movs r2, #1
	b _081D935C
_081D935A:
	movs r2, #0
_081D935C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D9384
	movs r0, #1
	strb r0, [r4, #7]
	b _081D9384
_081D9382:
	movs r2, #0
_081D9384:
	ldrh r0, [r7]
	cmp r0, #0
	beq _081D9390
	subs r0, #1
	strh r0, [r7]
	b _081D93A2
_081D9390:
	cmp r2, #0
	beq _081D93A2
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #2
_081D939A:
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
_081D93A2:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d93b0
FUN_081d93b0: @ 0x081D93B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp, #0xc]
	adds r7, r1, #0
	adds r0, r7, #0
	adds r0, #0x74
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D93CC
	b _081D94F8
_081D93CC:
	movs r0, #0x75
	adds r0, r0, r7
	mov sl, r0
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	movs r6, #0
	mov r2, sl
	strb r0, [r2]
	ldr r4, _081D9480 @ =0x0203B400
	mov sb, r4
	ldr r5, _081D9484 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _081D9488 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	ldrb r2, [r2]
	adds r0, r0, r2
	mov r4, sl
	strb r0, [r4]
	ldrb r0, [r4]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	adds r0, r7, #0
	adds r0, #0x2c
	ldr r2, [sp, #0xc]
	ldr r1, [r2, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #7
	bl FUN_08236fac
	adds r0, r7, #0
	adds r0, #0x78
	strb r6, [r0]
	subs r0, #8
	strh r6, [r0]
	add r0, sp, #8
	adds r4, r7, #0
	adds r4, #0x58
	str r6, [sp, #8]
	adds r1, r4, #0
	ldr r2, _081D948C @ =0x05000002
	bl CpuSet
	mov r0, sl
	ldrb r2, [r0]
	ldr r0, [r5]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r3, r1, #2
	ldr r1, _081D9490 @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	movs r5, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081D9494
	asrs r1, r0, #0xc
	b _081D949A
	.align 2, 0
_081D9480: .4byte 0x0203B400
_081D9484: .4byte 0x030046B8
_081D9488: .4byte 0x000003FF
_081D948C: .4byte 0x05000002
_081D9490: .4byte 0x085B0A08
_081D9494:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D949A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _081D94B4 @ =0x085B0A08
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _081D94B8
	asrs r0, r0, #0xc
	b _081D94BE
	.align 2, 0
_081D94B4: .4byte 0x085B0A08
_081D94B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D94BE:
	movs r3, #0
	strh r0, [r4, #4]
	ldr r2, _081D9558 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D955C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _081D9560 @ =0x0203B400
	adds r0, r0, r4
	ldrh r2, [r0]
	ldr r0, _081D9564 @ =0x03002BE0
	ldr r1, [r0]
	movs r5, #0x80
	lsls r5, r5, #1
	adds r0, r5, #0
	ldrh r1, [r1, #0x2e]
	adds r0, r0, r1
	ldr r4, _081D9568 @ =0x000001FF
	adds r1, r4, #0
	ands r2, r1
	adds r0, r0, r2
	adds r1, r7, #0
	adds r1, #0x7a
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	strb r3, [r0]
_081D94F8:
	movs r5, #0x1e
	ldrsh r0, [r7, r5]
	adds r1, r7, #0
	adds r1, #0x7a
	ldrh r1, [r1]
	cmp r0, r1
	bge _081D956C
	adds r4, r7, #0
	adds r4, #0x70
	ldrh r0, [r4]
	movs r1, #4
	bl Mod
	mov sb, r4
	adds r1, r7, #0
	adds r1, #0x5a
	cmp r0, #0
	bne _081D9522
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
_081D9522:
	adds r0, r7, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrh r0, [r1]
	ldrh r4, [r7, #0x1e]
	adds r0, r0, r4
	strh r0, [r7, #0x1e]
	adds r0, r7, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r5, [r7, #0x20]
	adds r0, r0, r5
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	adds r0, #0x78
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _081D9588
	ldrh r0, [r7, #0x34]
	cmp r0, #5
	bne _081D9588
	b _081D957C
	.align 2, 0
_081D9558: .4byte 0x030046B8
_081D955C: .4byte 0x000003FF
_081D9560: .4byte 0x0203B400
_081D9564: .4byte 0x03002BE0
_081D9568: .4byte 0x000001FF
_081D956C:
	adds r1, r7, #0
	adds r1, #0x68
	movs r0, #4
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
	b _081D96A8
_081D957C:
	ldrh r0, [r7, #0x3a]
	cmp r0, #0
	bne _081D9588
	movs r0, #0xf6
	bl PlaySound_082406e0
_081D9588:
	adds r4, r7, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r4
	cmp r1, r0
	beq _081D95BA
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D95C2
_081D95BA:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D95C2:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D95E6
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D95EE
_081D95E6:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D95EE:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D9628 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r4, #7]
	cmp r0, r5
	blo _081D966E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D9632
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D962C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D9648
	.align 2, 0
_081D9628: .4byte 0x0000FFFF
_081D962C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D9646
_081D9632:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D9646
	strh r1, [r4, #8]
	movs r2, #1
	b _081D9648
_081D9646:
	movs r2, #0
_081D9648:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D9670
	movs r0, #1
	strb r0, [r4, #7]
	b _081D9670
_081D966E:
	movs r2, #0
_081D9670:
	cmp r2, #0
	beq _081D96A0
	adds r0, r7, #0
	adds r0, #0x75
	ldrb r0, [r0]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	ldr r5, [sp, #0xc]
	ldr r1, [r5, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	mov r0, r8
	movs r2, #1
	bl FUN_08236fac
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
_081D96A0:
	mov r1, sb
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081D96A8:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d96b8
FUN_081d96b8: @ 0x081D96B8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r5, r1, #0
	adds r1, #0x74
	ldrb r0, [r1]
	cmp r0, #0
	beq _081D978C
	movs r0, #0
	strb r0, [r1]
	adds r4, r5, #0
	adds r4, #0x75
	ldrb r3, [r4]
	ldr r2, _081D9714 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D9718 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D971C @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r6, r5, #0
	adds r6, #0x58
	adds r7, r1, #0
	adds r7, #0xc
	ldr r2, _081D9720 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _081D9724
	asrs r1, r0, #0xc
	b _081D972A
	.align 2, 0
_081D9714: .4byte 0x030046B8
_081D9718: .4byte 0x000003FF
_081D971C: .4byte 0x0203B400
_081D9720: .4byte 0x085B0A08
_081D9724:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D972A:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _081D9742
	asrs r1, r0, #0xc
	b _081D9748
_081D9742:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D9748:
	movs r0, #0
	strh r1, [r6, #4]
	adds r1, r5, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldrb r0, [r4]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	adds r0, r5, #0
	adds r0, #0x2c
	mov r2, r8
	ldr r1, [r2, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #0
	bl FUN_08236fac
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0x80
	lsls r1, r1, #4
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #1
	strb r0, [r5, #7]
_081D978C:
	adds r0, r5, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r1, [r5, #0x1c]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r2, [r5, #0x20]
	adds r0, r0, r2
	strh r0, [r5, #0x20]
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D97D4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D97DC
_081D97D4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D97DC:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D9800
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D9808
_081D9800:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D9808:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D9840 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D9878
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D9844
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D9838
	ldrb r0, [r4, #5]
_081D9838:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D9854
	.align 2, 0
_081D9840: .4byte 0x0000FFFF
_081D9844:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D9854
	strh r1, [r4, #8]
_081D9854:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D9878
	movs r0, #1
	strb r0, [r4, #7]
_081D9878:
	adds r0, r5, #0
	bl FUN_081d8cb0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D9892
	adds r1, r5, #0
	adds r1, #0x68
	movs r0, #5
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
_081D9892:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d98a0
FUN_081d98a0: @ 0x081D98A0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x74
	ldrb r0, [r5]
	cmp r0, #0
	beq _081D98E6
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0x79
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D98C8
	adds r0, r4, #0
	adds r0, #0x7c
	bl ParticleShadow_Remove
_081D98C8:
	adds r3, r4, #0
	adds r3, #0x6c
	movs r1, #0
	ldrsh r0, [r3, r1]
	ldr r1, _081D98FC @ =0x00000ECC
	adds r2, r6, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	ldr r0, _081D9900 @ =0x0000FFFF
	strh r0, [r3]
	movs r0, #0
	strb r0, [r5]
_081D98E6:
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #0
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D98FC: .4byte 0x00000ECC
_081D9900: .4byte 0x0000FFFF

	thumb_func_start FUN_081d9904
FUN_081d9904: @ 0x081D9904
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x1c
	ldr r1, _081D9934 @ =0x00000ECC
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081D9962
	movs r4, #0
	ldr r0, _081D9934 @ =0x00000ECC
	adds r6, r5, r0
	ldr r1, _081D9938 @ =0x085AE12C
	mov r8, r1
_081D9924:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D993C
	movs r0, #1
	b _081D993E
	.align 2, 0
_081D9934: .4byte 0x00000ECC
_081D9938: .4byte 0x085AE12C
_081D993C:
	movs r0, #0
_081D993E:
	cmp r0, #0
	beq _081D995C
	movs r0, #0xbc
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r7
	adds r0, r1, #0
	adds r0, #0x68
	ldrh r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081D995C:
	adds r4, #1
	cmp r4, #0x13
	ble _081D9924
_081D9962:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d9970
FUN_081d9970: @ 0x081D9970
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r0, _081D998C @ =0x00000ECC
	adds r7, r6, r0
_081D997A:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D9990
	movs r0, #1
	b _081D9992
	.align 2, 0
_081D998C: .4byte 0x00000ECC
_081D9990:
	movs r0, #0
_081D9992:
	cmp r0, #0
	beq _081D99B6
	movs r0, #0xbc
	muls r0, r5, r0
	adds r0, #0x1c
	adds r4, r6, r0
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0x79
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D99B6
	adds r0, r4, #0
	adds r0, #0x7c
	bl ParticleShadow_Remove
_081D99B6:
	adds r5, #1
	cmp r5, #0x13
	ble _081D997A
	ldr r1, _081D99C8 @ =0x030001A4
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D99C8: .4byte 0x030001A4

	thumb_func_start FUN_081d99cc
FUN_081d99cc: @ 0x081D99CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081D99F8 @ =0x0000922E
	ldr r1, _081D99FC @ =0x00007B03
	bl GetFile
	str r0, [r4, #0x18]
	ldr r0, _081D9A00 @ =0x030001A4
	str r4, [r0]
	ldr r0, _081D9A04 @ =0x00000ECC
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	movs r0, #0xed
	lsls r0, r0, #4
	adds r4, r4, r0
	subs r0, #0xc0
	str r0, [r4]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081D99F8: .4byte 0x0000922E
_081D99FC: .4byte 0x00007B03
_081D9A00: .4byte 0x030001A4
_081D9A04: .4byte 0x00000ECC

	thumb_func_start FUN_081d9a08
FUN_081d9a08: @ 0x081D9A08
	push {r4, lr}
	ldr r0, _081D9A3C @ =0x030001A4
	ldr r0, [r0]
	cmp r0, #0
	bne _081D9A4E
	ldr r1, _081D9A40 @ =0x00000ED4
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D9A4C
	ldr r1, _081D9A44 @ =FUN_081d9904
	ldr r2, _081D9A48 @ =FUN_081d9970
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081d99cc
	cmp r0, #0
	bge _081D9A4C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D9A4E
	.align 2, 0
_081D9A3C: .4byte 0x030001A4
_081D9A40: .4byte 0x00000ED4
_081D9A44: .4byte FUN_081d9904
_081D9A48: .4byte FUN_081d9970
_081D9A4C:
	adds r0, r4, #0
_081D9A4E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d9a54
FUN_081d9a54: @ 0x081D9A54
	ldr r1, _081D9A5C @ =0x030001A4
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D9A5C: .4byte 0x030001A4

	thumb_func_start FUN_081d9a60
FUN_081d9a60: @ 0x081D9A60
	ldr r1, _081D9A68 @ =0x03002C64
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D9A68: .4byte 0x03002C64

	thumb_func_start FUN_081d9a6c
FUN_081d9a6c: @ 0x081D9A6C
	push {lr}
	ldr r1, [r0, #0x34]
	adds r1, #1
	str r1, [r0, #0x34]
	ldr r0, [r0, #0x18]
	cmp r1, r0
	bge _081D9A7E
	movs r0, #0
	b _081D9A80
_081D9A7E:
	movs r0, #1
_081D9A80:
	pop {r1}
	bx r1

	thumb_func_start FUN_081d9a84
FUN_081d9a84: @ 0x081D9A84
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, [r6, #0x2c]
	cmp r0, #0
	beq _081D9AD0
	bl FUN_08238bf4
	movs r0, #1
	str r0, [r6, #0x30]
	ldr r0, [r6, #0x28]
	cmp r0, #0
	beq _081D9AB8
	ldr r3, [r6, #0x68]
	cmp r3, #0
	beq _081D9AC8
	ldr r0, [r6, #0x70]
	ldr r1, [r6, #0x24]
	ldr r2, [r6, #0x20]
	bl _call_via_r3
	b _081D9AC8
_081D9AB8:
	ldr r3, [r6, #0x6c]
	cmp r3, #0
	beq _081D9AC8
	ldr r0, [r6, #0x70]
	ldr r1, [r6, #0x24]
	ldr r2, [r6, #0x20]
	bl _call_via_r3
_081D9AC8:
	adds r0, r6, #0
	bl KillEntity
	b _081D9C82
_081D9AD0:
	movs r0, #0
	mov r8, r0
	movs r7, #0
	movs r1, #0
	mov sl, r1
	movs r4, #1
	mov sb, r4
	ldr r0, [r6, #0x24]
	cmp r0, #0
	bge _081D9B24
	ldr r0, [r6, #0x54]
	adds r0, #1
	str r0, [r6, #0x54]
	bl FUN_08238bc0
	str r0, [r6, #0x24]
	cmp r0, #0
	bge _081D9B0C
	ldr r0, [r6, #0x40]
	cmp r0, #0x1d
	ble _081D9B08
	bl FUN_08238cd4
	bl FUN_08238bc0
	str r0, [r6, #0x24]
	mov r0, sl
	b _081D9B0A
_081D9B08:
	adds r0, #1
_081D9B0A:
	str r0, [r6, #0x40]
_081D9B0C:
	adds r0, r6, #0
	bl FUN_081d9a6c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D9B1C
	movs r0, #1
	str r0, [r6, #0x2c]
_081D9B1C:
	movs r0, #0
	str r0, [r6, #0x3c]
	str r0, [r6, #0x38]
	b _081D9C5E
_081D9B24:
	adds r5, r6, #0
	adds r5, #0x5e
	adds r0, r5, #0
	bl FUN_08238da8
	str r0, [r6, #0x48]
	adds r4, r6, #0
	adds r4, #0x5c
	ldrh r0, [r4]
	bl FUN_08238e14
	str r0, [r6, #0x44]
	ldr r0, [r6, #0x2c]
	str r4, [sp]
	cmp r0, #0
	bne _081D9B4E
	ldr r0, [r6, #0x24]
	cmp r0, #0
	bne _081D9B4E
	bl FUN_08238d84
_081D9B4E:
	ldr r0, [r6, #0x48]
	cmp r0, #0
	blt _081D9BD8
	ldr r0, [r6, #0x58]
	adds r0, #1
	str r0, [r6, #0x58]
	movs r1, #0
	ldr r3, _081D9B78 @ =0x0000FFFF
	movs r2, #0xc9
	lsls r2, r2, #1
_081D9B62:
	ldrh r0, [r5]
	cmp r0, r3
	beq _081D9B8C
	mov r4, sb
	cmp r4, #0
	beq _081D9B86
	cmp r0, r2
	bne _081D9B7C
	adds r7, #1
	b _081D9B86
	.align 2, 0
_081D9B78: .4byte 0x0000FFFF
_081D9B7C:
	cmp r0, #0xe2
	bne _081D9B86
	adds r7, #1
	movs r0, #1
	add sl, r0
_081D9B86:
	movs r4, #1
	add r8, r4
	b _081D9B90
_081D9B8C:
	movs r0, #0
	mov sb, r0
_081D9B90:
	adds r5, #2
	adds r1, #1
	cmp r1, #3
	ble _081D9B62
	mov r1, r8
	cmp r1, #2
	bne _081D9BB8
	cmp r7, #2
	bne _081D9BB8
	ldr r0, [r6, #0x38]
	adds r0, #1
	str r0, [r6, #0x38]
	cmp r0, #0x77
	ble _081D9BB2
	movs r0, #0xe2
	ldr r4, [sp]
	strh r0, [r4]
_081D9BB2:
	movs r0, #0
	str r0, [r6, #0x34]
	b _081D9BCC
_081D9BB8:
	adds r0, r6, #0
	bl FUN_081d9a6c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D9BC8
	movs r0, #1
	str r0, [r6, #0x2c]
_081D9BC8:
	movs r0, #0
	str r0, [r6, #0x38]
_081D9BCC:
	mov r0, sl
	cmp r0, #2
	bne _081D9C5A
	movs r0, #1
	str r0, [r6, #0x28]
	b _081D9C58
_081D9BD8:
	movs r5, #0
	movs r0, #0xc9
	lsls r0, r0, #1
	ldr r1, [sp]
	strh r0, [r1]
	ldr r1, [r6, #0x48]
	movs r0, #3
	rsbs r0, r0, #0
	cmp r1, r0
	bne _081D9C26
	ldr r0, [r6, #0x4c]
	adds r0, #1
	str r0, [r6, #0x4c]
	ldr r0, [r6, #0x3c]
	cmp r0, #0x1d
	ble _081D9C10
	bl FUN_08238bf4
	bl FUN_08238cd4
	bl FUN_08238bc0
	str r0, [r6, #0x24]
	str r5, [r6, #0x38]
	str r5, [r6, #0x50]
	str r5, [r6, #0x3c]
	str r5, [r6, #0x40]
	b _081D9C14
_081D9C10:
	adds r0, #1
	str r0, [r6, #0x3c]
_081D9C14:
	adds r0, r6, #0
	bl FUN_081d9a6c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D9C5E
	movs r0, #1
	str r0, [r6, #0x2c]
	b _081D9C5E
_081D9C26:
	str r5, [r6, #0x38]
	ldr r0, [r6, #0x50]
	cmp r0, #0x1d
	ble _081D9C46
	bl FUN_08238bf4
	bl FUN_08238cd4
	bl FUN_08238bc0
	str r0, [r6, #0x24]
	str r5, [r6, #0x38]
	str r5, [r6, #0x50]
	str r5, [r6, #0x3c]
	str r5, [r6, #0x40]
	b _081D9C4A
_081D9C46:
	adds r0, #1
	str r0, [r6, #0x50]
_081D9C4A:
	adds r0, r6, #0
	bl FUN_081d9a6c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D9C5A
	movs r0, #1
_081D9C58:
	str r0, [r6, #0x2c]
_081D9C5A:
	movs r0, #0
	str r0, [r6, #0x3c]
_081D9C5E:
	ldr r0, [r6, #0x1c]
	cmp r0, #0
	beq _081D9C82
	ldr r0, [r6, #0x2c]
	cmp r0, #0
	bne _081D9C82
	ldr r2, [r6, #0x28]
	cmp r2, #0
	bne _081D9C82
	ldr r0, _081D9C94 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081D9C82
	movs r0, #1
	str r0, [r6, #0x2c]
	str r0, [r6, #0x20]
_081D9C82:
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D9C94: .4byte 0x030044E0

	thumb_func_start FUN_081d9c98
FUN_081d9c98: @ 0x081D9C98
	push {lr}
	ldr r0, [r0, #0x30]
	cmp r0, #0
	bne _081D9CA4
	bl FUN_08238bf4
_081D9CA4:
	ldr r1, _081D9CB0 @ =0x03002C64
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_081D9CB0: .4byte 0x03002C64

	thumb_func_start FUN_081d9cb4
FUN_081d9cb4: @ 0x081D9CB4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, _081D9CE0 @ =0x03002C64
	str r4, [r0]
	bl FUN_08241704
	ldr r1, _081D9CE4 @ =0x0300481C
	movs r0, #1
	str r0, [r1]
	bl Sio_Reset
	bl FUN_08238b04
	cmp r5, #0
	bne _081D9CE8
	movs r0, #0x96
	lsls r0, r0, #1
	str r0, [r4, #0x18]
	b _081D9CEA
	.align 2, 0
_081D9CE0: .4byte 0x03002C64
_081D9CE4: .4byte 0x0300481C
_081D9CE8:
	str r5, [r4, #0x18]
_081D9CEA:
	str r6, [r4, #0x1c]
	movs r1, #0
	str r1, [r4, #0x20]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x24]
	str r1, [r4, #0x28]
	str r1, [r4, #0x2c]
	str r1, [r4, #0x30]
	str r1, [r4, #0x34]
	str r1, [r4, #0x38]
	str r0, [r4, #0x44]
	str r0, [r4, #0x48]
	adds r2, r4, #0
	adds r2, #0x5c
	movs r0, #0xc9
	lsls r0, r0, #1
	strh r0, [r2]
	adds r2, #2
	ldr r0, _081D9D34 @ =0x0000FFFF
	strh r0, [r2]
	adds r2, #2
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r2]
	adds r2, #2
	strh r0, [r2]
	adds r2, #2
	strh r0, [r2]
	str r1, [r4, #0x70]
	str r1, [r4, #0x68]
	str r1, [r4, #0x6c]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081D9D34: .4byte 0x0000FFFF

	thumb_func_start FUN_081d9d38
FUN_081d9d38: @ 0x081D9D38
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _081D9D74 @ =0x03002C64
	ldr r0, [r0]
	cmp r0, #0
	bne _081D9D82
	movs r0, #2
	movs r1, #0x74
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D9D80
	ldr r1, _081D9D78 @ =FUN_081d9a84
	ldr r2, _081D9D7C @ =FUN_081d9c98
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_081d9cb4
	cmp r0, #0
	bge _081D9D80
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D9D82
	.align 2, 0
_081D9D74: .4byte 0x03002C64
_081D9D78: .4byte FUN_081d9a84
_081D9D7C: .4byte FUN_081d9c98
_081D9D80:
	adds r0, r4, #0
_081D9D82:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d9d88
FUN_081d9d88: @ 0x081D9D88
	push {lr}
	adds r3, r0, #0
	ldr r0, _081D9DA0 @ =0x03002C64
	ldr r0, [r0]
	cmp r0, #0
	beq _081D9D9A
	str r3, [r0, #0x70]
	str r1, [r0, #0x68]
	str r2, [r0, #0x6c]
_081D9D9A:
	pop {r0}
	bx r0
	.align 2, 0
_081D9DA0: .4byte 0x03002C64

	thumb_func_start FUN_081d9da4
FUN_081d9da4: @ 0x081D9DA4
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _081D9DC4 @ =0x03002C68
	ldr r0, [r0]
	mov ip, r0
	cmp r0, #0
	beq _081D9DBC
	movs r4, #0xae
	lsls r4, r4, #1
	add r4, ip
	cmp r4, #0
	bne _081D9DC8
_081D9DBC:
	movs r0, #1
	rsbs r0, r0, #0
	b _081D9E48
	.align 2, 0
_081D9DC4: .4byte 0x03002C68
_081D9DC8:
	ldr r1, _081D9DF0 @ =0x00000286
	adds r0, r3, r1
	ldrb r0, [r0]
	subs r1, #0xea
	add r1, ip
	strb r0, [r1]
	ldr r2, _081D9DF4 @ =0x00000287
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r2, #0xea
	add r2, ip
	strb r0, [r2]
	ldrb r0, [r1]
	cmp r0, #1
	beq _081D9E14
	cmp r0, #1
	bgt _081D9DF8
	cmp r0, #0
	beq _081D9DFE
	b _081D9E38
	.align 2, 0
_081D9DF0: .4byte 0x00000286
_081D9DF4: .4byte 0x00000287
_081D9DF8:
	cmp r0, #2
	beq _081D9E1C
	b _081D9E38
_081D9DFE:
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r1, r3, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r2, #0xf2
	b _081D9E2E
_081D9E14:
	ldr r1, _081D9E18 @ =0x085AE160
	b _081D9E1E
	.align 2, 0
_081D9E18: .4byte 0x085AE160
_081D9E1C:
	ldr r1, _081D9E34 @ =0x085AE168
_081D9E1E:
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	subs r2, #0xea
_081D9E2E:
	add r2, ip
	strb r0, [r2]
	b _081D9E46
	.align 2, 0
_081D9E34: .4byte 0x085AE168
_081D9E38:
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x42
	strb r1, [r0]
_081D9E46:
	movs r0, #0
_081D9E48:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d9e50
FUN_081d9e50: @ 0x081D9E50
	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r2, _081D9E68 @ =0x00000286
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _081D9E9C
	cmp r0, #1
	bgt _081D9E6C
	cmp r0, #0
	beq _081D9E72
	b _081D9EE4
	.align 2, 0
_081D9E68: .4byte 0x00000286
_081D9E6C:
	cmp r0, #2
	beq _081D9EBC
	b _081D9EE4
_081D9E72:
	movs r2, #0
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r2, r0
	bge _081D9EEE
	subs r3, #4
	adds r5, r1, r3
	adds r3, #8
	adds r4, r1, r3
	ldrb r1, [r5]
	adds r3, r0, #0
_081D9E8C:
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	beq _081D9EDC
	adds r2, #1
	cmp r2, r3
	blt _081D9E8C
	b _081D9EEE
_081D9E9C:
	movs r2, #0
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r4, r1, r0
	ldrb r1, [r4]
	ldr r3, _081D9EB8 @ =0x085AE160
_081D9EA8:
	ldr r0, [r3]
	cmp r1, r0
	beq _081D9EE0
	adds r3, #4
	adds r2, #1
	cmp r2, #1
	ble _081D9EA8
	b _081D9EEE
	.align 2, 0
_081D9EB8: .4byte 0x085AE160
_081D9EBC:
	movs r2, #0
	movs r3, #0xa2
	lsls r3, r3, #2
	adds r4, r1, r3
	ldrb r1, [r4]
	ldr r3, _081D9ED8 @ =0x085AE168
_081D9EC8:
	ldr r0, [r3]
	cmp r1, r0
	beq _081D9EE0
	adds r3, #4
	adds r2, #1
	cmp r2, #0
	ble _081D9EC8
	b _081D9EEE
	.align 2, 0
_081D9ED8: .4byte 0x085AE168
_081D9EDC:
	strb r2, [r5]
	b _081D9EEE
_081D9EE0:
	strb r2, [r4]
	b _081D9EEE
_081D9EE4:
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #0
	strb r0, [r1]
_081D9EEE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d9ef4
FUN_081d9ef4: @ 0x081D9EF4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081da370
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	bl FUN_08049e5c
	adds r0, r4, #0
	bl FUN_081da5d0
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081D9F36
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
_081D9F36:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d9f3c
FUN_081d9f3c: @ 0x081D9F3C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08049fa8
	adds r0, r4, #0
	bl FUN_081da370
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_081da5d0
	bl FUN_081df974
	ldr r0, _081D9F88 @ =0x000002A2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081D9F82
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
_081D9F82:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D9F88: .4byte 0x000002A2

	thumb_func_start FUN_081d9f8c
FUN_081d9f8c: @ 0x081D9F8C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081D9FF0 @ =0x0000C091
	ldr r1, _081D9FF4 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r5, #0x18]
	movs r0, #5
	str r0, [sp, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _081D9FF8 @ =0x000092B3
	ldr r1, _081D9FFC @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	str r0, [r5, #0x1c]
	ldr r1, _081DA000 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	ldr r0, _081DA004 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DA008
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #1
	bne _081DA008
	movs r0, #1
	b _081DA00A
	.align 2, 0
_081D9FF0: .4byte 0x0000C091
_081D9FF4: .4byte 0x0000CD91
_081D9FF8: .4byte 0x000092B3
_081D9FFC: .4byte 0x000026BB
_081DA000: .4byte 0x03004250
_081DA004: .4byte 0x03002C68
_081DA008:
	movs r0, #0
_081DA00A:
	cmp r0, #0
	bne _081DA02E
	movs r4, #0
	movs r5, #3
_081DA012:
	adds r0, r4, #0
	adds r0, #0x19
	adds r1, r4, #0
	adds r1, #0x16
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DA012
_081DA02E:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da038
FUN_081da038: @ 0x081DA038
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r5, #0
	ldr r4, _081DA070 @ =0x085AE144
	movs r6, #6
_081DA042:
	ldr r0, [r4]
	bl IsMagicUnlocked
	cmp r0, #0
	beq _081DA05A
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r7, r1
	adds r0, r0, r5
	ldr r1, [r4]
	strb r1, [r0]
	adds r5, #1
_081DA05A:
	adds r4, #4
	subs r6, #1
	cmp r6, #0
	bge _081DA042
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r5, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DA070: .4byte 0x085AE144

	thumb_func_start FUN_081da074
FUN_081da074: @ 0x081DA074
	push {lr}
	adds r2, r0, #0
	ldr r1, _081DA08C @ =0x00000286
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA0A6
	cmp r0, #1
	bgt _081DA090
	cmp r0, #0
	beq _081DA096
	b _081DA0BC
	.align 2, 0
_081DA08C: .4byte 0x00000286
_081DA090:
	cmp r0, #2
	beq _081DA0B4
	b _081DA0BC
_081DA096:
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrh r1, [r0]
	subs r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	b _081DA0BC
_081DA0A6:
	ldr r0, _081DA0B0 @ =0x0000028B
	adds r1, r2, r0
	movs r0, #2
	b _081DA0BA
	.align 2, 0
_081DA0B0: .4byte 0x0000028B
_081DA0B4:
	ldr r3, _081DA0C0 @ =0x0000028B
	adds r1, r2, r3
	movs r0, #1
_081DA0BA:
	strb r0, [r1]
_081DA0BC:
	pop {r0}
	bx r0
	.align 2, 0
_081DA0C0: .4byte 0x0000028B

	thumb_func_start FUN_081da0c4
FUN_081da0c4: @ 0x081DA0C4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _081DA0FC @ =0x0000029D
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081DA100 @ =0x00000286
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _081DA104 @ =0x030046A0
	ldr r1, [r0]
	subs r2, #0x48
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _081DA10C
	ldr r0, _081DA108 @ =0x00000289
	adds r1, r4, r0
	movs r0, #3
	b _081DA128
	.align 2, 0
_081DA0FC: .4byte 0x0000029D
_081DA100: .4byte 0x00000286
_081DA104: .4byte 0x030046A0
_081DA108: .4byte 0x00000289
_081DA10C:
	movs r2, #0x8e
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _081DA122
	adds r2, #0x51
	adds r1, r4, r2
	movs r0, #2
	b _081DA128
_081DA122:
	ldr r0, _081DA144 @ =0x00000289
	adds r1, r4, r0
	movs r0, #1
_081DA128:
	strb r0, [r1]
	ldr r2, _081DA148 @ =0x0000028A
	adds r1, r4, r2
	movs r0, #4
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_081da038
	adds r0, r4, #0
	bl FUN_081da074
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DA144: .4byte 0x00000289
_081DA148: .4byte 0x0000028A

	thumb_func_start FUN_081da14c
FUN_081da14c: @ 0x081DA14C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _081DA164 @ =0x0000029D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA17C
	cmp r0, #1
	bgt _081DA168
	cmp r0, #0
	beq _081DA16E
	b _081DA1E0
	.align 2, 0
_081DA164: .4byte 0x0000029D
_081DA168:
	cmp r0, #2
	beq _081DA18C
	b _081DA1E0
_081DA16E:
	ldr r2, _081DA178 @ =0x00000286
	adds r0, r5, r2
	ldrb r1, [r0]
	b _081DA1E2
	.align 2, 0
_081DA178: .4byte 0x00000286
_081DA17C:
	ldr r1, _081DA188 @ =0x00000287
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, r0, #3
	b _081DA1E2
	.align 2, 0
_081DA188: .4byte 0x00000287
_081DA18C:
	ldr r2, _081DA1A0 @ =0x00000286
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA1C0
	cmp r0, #1
	bgt _081DA1A4
	cmp r0, #0
	beq _081DA1AA
	b _081DA1E0
	.align 2, 0
_081DA1A0: .4byte 0x00000286
_081DA1A4:
	cmp r0, #2
	beq _081DA1C8
	b _081DA1E0
_081DA1AA:
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r1, r0, #7
	b _081DA1E2
_081DA1C0:
	ldr r1, _081DA1C4 @ =0x085AE160
	b _081DA1CA
	.align 2, 0
_081DA1C4: .4byte 0x085AE160
_081DA1C8:
	ldr r1, _081DA1DC @ =0x085AE168
_081DA1CA:
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r0, #7
	b _081DA1E2
	.align 2, 0
_081DA1DC: .4byte 0x085AE168
_081DA1E0:
	movs r1, #0
_081DA1E2:
	ldr r0, _081DA214 @ =0x0000029B
	adds r6, r5, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	adds r4, r1, #0
	adds r4, #0x19
	cmp r0, r4
	beq _081DA20E
	bl FUN_08049e5c
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	strb r4, [r6]
_081DA20E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DA214: .4byte 0x0000029B

	thumb_func_start FUN_081da218
FUN_081da218: @ 0x081DA218
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r5, r7, r1
	ldr r1, [r5]
	bl FUN_0804a240
	ldr r0, [r4]
	ldr r2, _081DA288 @ =0x00000286
	adds r6, r7, r2
	ldrb r1, [r6]
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldrb r1, [r6]
	movs r2, #0xa6
	lsls r2, r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	ldr r1, [r5]
	bl FUN_0804a240
	ldr r0, [r4]
	ldr r1, _081DA28C @ =0x00000287
	adds r5, r7, r1
	ldrb r1, [r5]
	adds r1, #3
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldrb r1, [r5]
	ldr r2, _081DA290 @ =0x00000299
	adds r0, r7, r2
	strb r1, [r0]
	ldrb r0, [r6]
	cmp r0, #1
	beq _081DA2AE
	cmp r0, #1
	bgt _081DA294
	cmp r0, #0
	beq _081DA29A
	b _081DA2D0
	.align 2, 0
_081DA288: .4byte 0x00000286
_081DA28C: .4byte 0x00000287
_081DA290: .4byte 0x00000299
_081DA294:
	cmp r0, #2
	beq _081DA2B8
	b _081DA2D0
_081DA29A:
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r5, [r0]
	b _081DA2D2
_081DA2AE:
	ldr r1, _081DA2B4 @ =0x085AE160
	b _081DA2BA
	.align 2, 0
_081DA2B4: .4byte 0x085AE160
_081DA2B8:
	ldr r1, _081DA2CC @ =0x085AE168
_081DA2BA:
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	b _081DA2D2
	.align 2, 0
_081DA2CC: .4byte 0x085AE168
_081DA2D0:
	movs r5, #0
_081DA2D2:
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	adds r1, r5, #7
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r1, [r0]
	ldr r2, _081DA308 @ =0x0000029A
	adds r0, r7, r2
	strb r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DA308: .4byte 0x0000029A

	thumb_func_start FUN_081da30c
FUN_081da30c: @ 0x081DA30C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x12
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0x12
	movs r1, #8
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	movs r2, #0x9f
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0x10
	movs r1, #0xc
	movs r2, #0xc
	movs r3, #2
	bl FUN_0804a084
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	bl FUN_08049f5c
	bl FUN_08049e5c
	movs r2, #1
	movs r0, #0x9d
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_081da0c4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da370
FUN_081da370: @ 0x081DA370
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da3a0
FUN_081da3a0: @ 0x081DA3A0
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r4, _081DA3EC @ =0x0000CB05
	ldr r1, _081DA3F0 @ =0x0000DCC1
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	movs r2, #0x90
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x40
	adds r0, r5, r2
	bl OpenMainSpriteFile
	ldr r1, _081DA3F4 @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	movs r2, #0x91
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x24
	adds r0, r5, r2
	bl OpenMainSpriteFile
	movs r4, #0
_081DA3DE:
	cmp r4, #4
	bhi _081DA434
	lsls r0, r4, #2
	ldr r1, _081DA3F8 @ =_081DA3FC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081DA3EC: .4byte 0x0000CB05
_081DA3F0: .4byte 0x0000DCC1
_081DA3F4: .4byte 0x00005D04
_081DA3F8: .4byte _081DA3FC
_081DA3FC: @ jump table
	.4byte _081DA410 @ case 0
	.4byte _081DA418 @ case 1
	.4byte _081DA420 @ case 2
	.4byte _081DA428 @ case 3
	.4byte _081DA42C @ case 4
_081DA410:
	movs r2, #0x33
	movs r0, #0x80
	lsls r0, r0, #2
	b _081DA43A
_081DA418:
	movs r2, #0x34
	movs r0, #0x80
	lsls r0, r0, #2
	b _081DA43A
_081DA420:
	movs r2, #0x35
	movs r0, #0x80
	lsls r0, r0, #2
	b _081DA43A
_081DA428:
	movs r2, #0xb6
	b _081DA436
_081DA42C:
	movs r2, #0x15
	movs r0, #0x80
	lsls r0, r0, #2
	b _081DA43A
_081DA434:
	movs r2, #0
_081DA436:
	movs r0, #0x88
	lsls r0, r0, #2
_081DA43A:
	adds r3, r5, r0
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #5
	adds r0, #0x20
	adds r0, r5, r0
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r3, #0
	movs r3, #0x10
	bl MainSprite_Add
	adds r4, #1
	cmp r4, #4
	ble _081DA3DE
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da468
FUN_081da468: @ 0x081DA468
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r7, #0
_081DA46E:
	cmp r7, #4
	bls _081DA474
	b _081DA5C0
_081DA474:
	lsls r0, r7, #2
	ldr r1, _081DA480 @ =_081DA484
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081DA480: .4byte _081DA484
_081DA484: @ jump table
	.4byte _081DA498 @ case 0
	.4byte _081DA4CC @ case 1
	.4byte _081DA50C @ case 2
	.4byte _081DA594 @ case 3
	.4byte _081DA5AC @ case 4
_081DA498:
	lsls r1, r7, #1
	adds r1, r1, r7
	lsls r1, r1, #5
	adds r1, r6, r1
	ldr r3, _081DA4C4 @ =0x085AE16C
	ldr r0, _081DA4C8 @ =0x0000029D
	adds r4, r6, r0
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r3
	ldr r2, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	strh r2, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r3, #4
	adds r0, r0, r3
	ldr r0, [r0]
	adds r1, #0x42
	strh r0, [r1]
	b _081DA5C0
	.align 2, 0
_081DA4C4: .4byte 0x085AE16C
_081DA4C8: .4byte 0x0000029D
_081DA4CC:
	ldr r1, _081DA4FC @ =0x0000029D
	adds r0, r6, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DA4E0
	ldr r2, _081DA500 @ =0x00000289
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #1
	bls _081DA52E
_081DA4E0:
	cmp r1, #2
	bne _081DA4EE
	ldr r1, _081DA504 @ =0x0000028B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	bls _081DA52E
_081DA4EE:
	lsls r3, r7, #1
	adds r3, r3, r7
	lsls r3, r3, #5
	adds r4, r6, r3
	ldr r2, _081DA508 @ =0x085AE184
	b _081DA55A
	.align 2, 0
_081DA4FC: .4byte 0x0000029D
_081DA500: .4byte 0x00000289
_081DA504: .4byte 0x0000028B
_081DA508: .4byte 0x085AE184
_081DA50C:
	ldr r1, _081DA544 @ =0x0000029D
	adds r0, r6, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DA520
	ldr r2, _081DA548 @ =0x00000289
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #1
	bls _081DA52E
_081DA520:
	cmp r1, #2
	bne _081DA550
	ldr r1, _081DA54C @ =0x0000028B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	bhi _081DA550
_081DA52E:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	adds r2, r6, #0
	adds r2, #0x28
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _081DA5C0
	.align 2, 0
_081DA544: .4byte 0x0000029D
_081DA548: .4byte 0x00000289
_081DA54C: .4byte 0x0000028B
_081DA550:
	lsls r3, r7, #1
	adds r3, r3, r7
	lsls r3, r3, #5
	adds r4, r6, r3
	ldr r2, _081DA58C @ =0x085AE19C
_081DA55A:
	ldr r0, _081DA590 @ =0x0000029D
	adds r5, r6, r0
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r0, r2
	ldr r1, [r0]
	adds r0, r4, #0
	adds r0, #0x40
	strh r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r2, #4
	adds r0, r0, r2
	ldr r0, [r0]
	adds r4, #0x42
	strh r0, [r4]
	adds r2, r6, #0
	adds r2, #0x28
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _081DA5C0
	.align 2, 0
_081DA58C: .4byte 0x085AE19C
_081DA590: .4byte 0x0000029D
_081DA594:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	adds r0, r6, r0
	adds r2, r0, #0
	adds r2, #0x40
	movs r1, #0x48
	strh r1, [r2]
	adds r0, #0x42
	movs r1, #0x60
	strh r1, [r0]
	b _081DA5C0
_081DA5AC:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	adds r0, r6, r0
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0
	strh r2, [r1]
	adds r0, #0x42
	strh r2, [r0]
_081DA5C0:
	adds r7, #1
	cmp r7, #4
	bgt _081DA5C8
	b _081DA46E
_081DA5C8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da5d0
FUN_081da5d0: @ 0x081DA5D0
	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0x28
	movs r2, #4
_081DA5DA:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081DA5DA
	pop {r0}
	bx r0

	thumb_func_start FUN_081da5ec
FUN_081da5ec: @ 0x081DA5EC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x20
	movs r5, #4
_081DA5F4:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081DA5F4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081da608
FUN_081da608: @ 0x081DA608
	push {lr}
	mov ip, r0
	ldr r0, _081DA644 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _081DA648 @ =0x00005260
	adds r2, r0, r1
	movs r1, #0x92
	lsls r1, r1, #2
	add r1, ip
	movs r3, #0xf
_081DA61C:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _081DA61C
	movs r0, #0x92
	lsls r0, r0, #2
	add r0, ip
	mov r1, ip
	str r0, [r1, #0x68]
	movs r1, #0x9a
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081DA644: .4byte 0x03003584
_081DA648: .4byte 0x00005260

	thumb_func_start FUN_081da64c
FUN_081da64c: @ 0x081DA64C
	push {lr}
	adds r3, r0, #0
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrh r0, [r0]
	movs r2, #0x1f
	cmp r0, #9
	bls _081DA678
	movs r2, #0x1b
	cmp r0, #0x11
	bls _081DA678
	movs r2, #0x12
	cmp r0, #0x19
	bls _081DA678
	movs r2, #0xa
	cmp r0, #0x21
	bls _081DA678
	movs r2, #0x1b
	cmp r0, #0x29
	bhi _081DA678
	movs r2, #0x12
_081DA678:
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bls _081DA690
	movs r0, #0
	strh r0, [r1]
_081DA690:
	movs r1, #0x98
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	pop {r0}
	bx r0

	thumb_func_start FUN_081da69c
FUN_081da69c: @ 0x081DA69C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r2, [r0]
	adds r1, #0x12
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r2, r0
	beq _081DA724
	subs r1, #0x14
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA6DC
	cmp r0, #1
	bgt _081DA6CA
	cmp r0, #0
	beq _081DA6D0
	b _081DA6F4
_081DA6CA:
	cmp r0, #2
	beq _081DA6E4
	b _081DA6F4
_081DA6D0:
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r6, r1
	adds r0, r0, r2
	ldrb r5, [r0]
	b _081DA6F6
_081DA6DC:
	ldr r1, _081DA6E0 @ =0x085AE160
	b _081DA6E6
	.align 2, 0
_081DA6E0: .4byte 0x085AE160
_081DA6E4:
	ldr r1, _081DA6F0 @ =0x085AE168
_081DA6E6:
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r5, [r0]
	b _081DA6F6
	.align 2, 0
_081DA6F0: .4byte 0x085AE168
_081DA6F4:
	movs r5, #0
_081DA6F6:
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r4, r6, r2
	ldr r0, [r4]
	subs r2, #0x10
	adds r1, r6, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	adds r1, r5, #7
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r1, [r0]
	ldr r2, _081DA72C @ =0x0000029A
	adds r0, r6, r2
	strb r1, [r0]
_081DA724:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DA72C: .4byte 0x0000029A

	thumb_func_start FUN_081da730
FUN_081da730: @ 0x081DA730
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r1, _081DA74C @ =0x0000029D
	adds r0, r5, r1
	ldrb r7, [r0]
	cmp r7, #1
	beq _081DA7C0
	cmp r7, #1
	bgt _081DA750
	cmp r7, #0
	beq _081DA756
	b _081DA80A
	.align 2, 0
_081DA74C: .4byte 0x0000029D
_081DA750:
	cmp r7, #2
	beq _081DA804
	b _081DA80A
_081DA756:
	ldr r2, _081DA7B8 @ =0x00000286
	adds r6, r5, r2
	ldrb r1, [r6]
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r0, r0, r5
	mov r8, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	beq _081DA80A
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r4]
	subs r2, #0x16
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	ldrb r1, [r6]
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldrb r0, [r6]
	mov r1, r8
	strb r0, [r1]
	ldr r2, _081DA7BC @ =0x0000029A
	adds r1, r5, r2
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r7, [r0]
	adds r0, r5, #0
	bl FUN_081da074
	adds r0, r5, #0
	bl FUN_081da69c
	adds r0, r5, #0
	bl FUN_081da814
	b _081DA80A
	.align 2, 0
_081DA7B8: .4byte 0x00000286
_081DA7BC: .4byte 0x0000029A
_081DA7C0:
	ldr r2, _081DA7FC @ =0x00000287
	adds r6, r5, r2
	ldrb r1, [r6]
	ldr r0, _081DA800 @ =0x00000299
	adds r7, r5, r0
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r1, r0
	beq _081DA80A
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r4]
	subs r2, #0x17
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	ldrb r1, [r6]
	adds r1, #3
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldrb r0, [r6]
	strb r0, [r7]
	b _081DA80A
	.align 2, 0
_081DA7FC: .4byte 0x00000287
_081DA800: .4byte 0x00000299
_081DA804:
	adds r0, r5, #0
	bl FUN_081da69c
_081DA80A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081da814
FUN_081da814: @ 0x081DA814
	push {r4, lr}
	adds r3, r0, #0
	ldr r1, _081DA82C @ =0x00000286
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA84A
	cmp r0, #1
	bgt _081DA830
	cmp r0, #0
	beq _081DA836
	b _081DA870
	.align 2, 0
_081DA82C: .4byte 0x00000286
_081DA830:
	cmp r0, #2
	beq _081DA858
	b _081DA870
_081DA836:
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r4, #0xa4
	lsls r4, r4, #2
	adds r0, r3, r4
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r2, [r0]
	b _081DA872
_081DA84A:
	ldr r1, _081DA854 @ =0x085AE160
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r3, r2
	b _081DA860
	.align 2, 0
_081DA854: .4byte 0x085AE160
_081DA858:
	ldr r1, _081DA86C @ =0x085AE168
	movs r4, #0xa2
	lsls r4, r4, #2
	adds r0, r3, r4
_081DA860:
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	b _081DA872
	.align 2, 0
_081DA86C: .4byte 0x085AE168
_081DA870:
	movs r2, #0
_081DA872:
	adds r2, #0xb6
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r4, #0x88
	lsls r4, r4, #2
	adds r1, r3, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da890
FUN_081da890: @ 0x081DA890
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081DA8AC
	ldr r1, _081DA8D0 @ =0x0000029E
	adds r0, r5, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081DA8AC:
	ldr r0, _081DA8D0 @ =0x0000029E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0xa
	bne _081DA8C2
	adds r0, r5, #0
	bl FUN_081d9da4
	adds r0, r5, #0
	bl FUN_081d9ef4
_081DA8C2:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DA8D0: .4byte 0x0000029E

	thumb_func_start FUN_081da8d4
FUN_081da8d4: @ 0x081DA8D4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081DA908
	movs r0, #4
	str r0, [sp]
	ldr r0, _081DA928 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _081DA92C @ =0x0000029E
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	strb r1, [r6]
_081DA908:
	ldr r0, _081DA92C @ =0x0000029E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x14
	bne _081DA918
	adds r0, r5, #0
	bl FUN_081d9f3c
_081DA918:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DA928: .4byte 0x0000FFFF
_081DA92C: .4byte 0x0000029E

	thumb_func_start FUN_081da930
FUN_081da930: @ 0x081DA930
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081DA97A
	bl FUN_08049e5c
	ldr r1, _081DA998 @ =0x00000286
	adds r0, r5, r1
	ldrb r4, [r0]
	movs r3, #0x9c
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	adds r4, #0x19
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	adds r0, r5, #0
	bl FUN_081da730
	ldr r1, _081DA99C @ =0x0000029D
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081DA9A0 @ =0x0000029E
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	strb r1, [r6]
_081DA97A:
	ldr r0, _081DA9A0 @ =0x0000029E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x1d
	bhi _081DA9A4
	adds r0, r5, #0
	bl FUN_081da64c
	adds r0, r5, #0
	bl FUN_081da14c
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _081DAC98
	.align 2, 0
_081DA998: .4byte 0x00000286
_081DA99C: .4byte 0x0000029D
_081DA9A0: .4byte 0x0000029E
_081DA9A4:
	ldr r1, _081DA9C0 @ =0x0000029D
	adds r0, r5, r1
	ldrb r4, [r0]
	ldr r3, _081DA9C4 @ =0x00000285
	adds r6, r5, r3
	movs r3, #0
	ldr r1, _081DA9C8 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081DA9CC
	movs r3, #1
	b _081DAA06
	.align 2, 0
_081DA9C0: .4byte 0x0000029D
_081DA9C4: .4byte 0x00000285
_081DA9C8: .4byte 0x030044E0
_081DA9CC:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081DA9D8
	movs r3, #2
	b _081DAA06
_081DA9D8:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081DA9E4
	movs r3, #4
	b _081DAA06
_081DA9E4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081DA9F0
	movs r3, #8
	b _081DAA06
_081DA9F0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081DA9FC
	movs r3, #0x20
	b _081DAA06
_081DA9FC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081DAA06
	movs r3, #0x10
_081DAA06:
	ldrh r2, [r1]
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0
	beq _081DAA4E
	ldrb r0, [r6]
	cmp r0, #0xb
	bls _081DAA4C
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081DAA22
	movs r0, #1
	b _081DAA2C
_081DAA22:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081DAA2E
	movs r0, #2
_081DAA2C:
	orrs r3, r0
_081DAA2E:
	ldrh r1, [r1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _081DAA3C
	movs r0, #4
	b _081DAA46
_081DAA3C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081DAA48
	movs r0, #8
_081DAA46:
	orrs r3, r0
_081DAA48:
	movs r0, #0
	b _081DAA4E
_081DAA4C:
	adds r0, #1
_081DAA4E:
	strb r0, [r6]
	movs r6, #1
	adds r0, r3, #0
	ands r0, r6
	cmp r0, #0
	beq _081DAA70
	cmp r4, #0
	bne _081DAA62
	movs r4, #2
	b _081DAA64
_081DAA62:
	subs r4, #1
_081DAA64:
	ldr r0, _081DAA6C @ =0x00000285
	adds r1, r5, r0
	b _081DABEC
	.align 2, 0
_081DAA6C: .4byte 0x00000285
_081DAA70:
	movs r2, #2
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _081DAA86
	cmp r4, #2
	bne _081DAA82
	movs r4, #0
	b _081DABE8
_081DAA82:
	adds r4, #1
	b _081DABE8
_081DAA86:
	movs r0, #4
	ands r0, r3
	cmp r0, #0
	beq _081DAB54
	ldr r1, _081DAAA4 @ =0x0000029D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DAAD8
	cmp r0, #1
	bgt _081DAAA8
	cmp r0, #0
	beq _081DAAAE
	b _081DAB42
	.align 2, 0
_081DAAA4: .4byte 0x0000029D
_081DAAA8:
	cmp r0, #2
	beq _081DAB0C
	b _081DAB42
_081DAAAE:
	ldr r3, _081DAAC4 @ =0x00000286
	adds r0, r5, r3
	ldrb r2, [r0]
	cmp r2, #0
	bne _081DAACC
	ldr r1, _081DAAC8 @ =0x00000289
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DAACE
	.align 2, 0
_081DAAC4: .4byte 0x00000286
_081DAAC8: .4byte 0x00000289
_081DAACC:
	subs r1, r2, #1
_081DAACE:
	ldr r3, _081DAAD4 @ =0x00000286
	b _081DAAF8
	.align 2, 0
_081DAAD4: .4byte 0x00000286
_081DAAD8:
	ldr r1, _081DAAEC @ =0x00000287
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _081DAAF4
	ldr r3, _081DAAF0 @ =0x0000028A
	adds r0, r5, r3
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DAAF6
	.align 2, 0
_081DAAEC: .4byte 0x00000287
_081DAAF0: .4byte 0x0000028A
_081DAAF4:
	subs r1, r2, #1
_081DAAF6:
	ldr r3, _081DAB08 @ =0x00000287
_081DAAF8:
	adds r0, r5, r3
	strb r1, [r0]
	cmp r2, r1
	beq _081DAB42
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081DAB42
	.align 2, 0
_081DAB08: .4byte 0x00000287
_081DAB0C:
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _081DAB28
	ldr r3, _081DAB24 @ =0x0000028B
	adds r0, r5, r3
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DAB2A
	.align 2, 0
_081DAB24: .4byte 0x0000028B
_081DAB28:
	subs r1, r2, #1
_081DAB2A:
	movs r3, #0xa2
	lsls r3, r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	cmp r2, r1
	beq _081DAB3C
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DAB3C:
	adds r0, r5, #0
	bl FUN_081da814
_081DAB42:
	adds r0, r5, #0
	bl FUN_081da730
	ldr r0, _081DAB50 @ =0x00000285
	adds r1, r5, r0
	b _081DABEC
	.align 2, 0
_081DAB50: .4byte 0x00000285
_081DAB54:
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq _081DABFC
	ldr r1, _081DAB70 @ =0x0000029D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DAB8C
	cmp r0, #1
	bgt _081DAB74
	cmp r0, #0
	beq _081DAB7A
	b _081DABE2
	.align 2, 0
_081DAB70: .4byte 0x0000029D
_081DAB74:
	cmp r0, #2
	beq _081DABB8
	b _081DABE2
_081DAB7A:
	ldr r0, _081DAB84 @ =0x00000286
	adds r3, r5, r0
	ldrb r2, [r3]
	ldr r1, _081DAB88 @ =0x00000289
	b _081DAB94
	.align 2, 0
_081DAB84: .4byte 0x00000286
_081DAB88: .4byte 0x00000289
_081DAB8C:
	ldr r0, _081DABB0 @ =0x00000287
	adds r3, r5, r0
	ldrb r2, [r3]
	ldr r1, _081DABB4 @ =0x0000028A
_081DAB94:
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r0, #1
	adds r1, r2, #1
	cmp r2, r0
	bne _081DABA2
	movs r1, #0
_081DABA2:
	strb r1, [r3]
	cmp r2, r1
	beq _081DABE2
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081DABE2
	.align 2, 0
_081DABB0: .4byte 0x00000287
_081DABB4: .4byte 0x0000028A
_081DABB8:
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r3, r5, r0
	ldrb r2, [r3]
	ldr r1, _081DABF4 @ =0x0000028B
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r0, #1
	adds r1, r2, #1
	cmp r2, r0
	bne _081DABD0
	movs r1, #0
_081DABD0:
	strb r1, [r3]
	cmp r2, r1
	beq _081DABDC
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DABDC:
	adds r0, r5, #0
	bl FUN_081da814
_081DABE2:
	adds r0, r5, #0
	bl FUN_081da730
_081DABE8:
	ldr r3, _081DABF8 @ =0x00000285
	adds r1, r5, r3
_081DABEC:
	movs r0, #0
	strb r0, [r1]
	b _081DAC74
	.align 2, 0
_081DABF4: .4byte 0x0000028B
_081DABF8: .4byte 0x00000285
_081DABFC:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _081DAC28
	ldr r1, _081DAC24 @ =FUN_081da890
	movs r3, #0x9b
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r6, [r0]
	adds r3, #0x18
	adds r0, r5, r3
	strb r2, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081DAC98
	.align 2, 0
_081DAC24: .4byte FUN_081da890
_081DAC28:
	movs r0, #0x10
	ands r3, r0
	cmp r3, #0
	beq _081DAC74
	ldr r0, _081DAC44 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DAC48
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #1
	bne _081DAC48
	movs r0, #1
	b _081DAC4A
	.align 2, 0
_081DAC44: .4byte 0x03002C68
_081DAC48:
	movs r0, #0
_081DAC4A:
	cmp r0, #0
	bne _081DAC74
	ldr r1, _081DAC70 @ =FUN_081da8d4
	movs r2, #1
	movs r3, #0x9b
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	adds r3, #0x18
	adds r0, r5, r3
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081DAC98
	.align 2, 0
_081DAC70: .4byte FUN_081da8d4
_081DAC74:
	ldr r0, _081DACA0 @ =0x0000029D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, r4
	beq _081DAC8C
	strb r4, [r1]
	adds r0, r5, #0
	bl FUN_081da468
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DAC8C:
	adds r0, r5, #0
	bl FUN_081da64c
	adds r0, r5, #0
	bl FUN_081da14c
_081DAC98:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DACA0: .4byte 0x0000029D

	thumb_func_start FUN_081daca4
FUN_081daca4: @ 0x081DACA4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _081DACC6
	bl FUN_08049fa8
	adds r0, r4, #0
	bl FUN_081da5d0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081DACDA
_081DACC6:
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081DACD8
	adds r0, r4, #0
	bl _call_via_r1
_081DACD8:
	movs r0, #1
_081DACDA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081dace0
FUN_081dace0: @ 0x081DACE0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081da5ec
	adds r0, r4, #0
	bl FUN_081da370
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081dacf8
FUN_081dacf8: @ 0x081DACF8
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081DAD1E
	bl FUN_0823d340
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	cmp r0, #0
	bne _081DAD1E
	movs r0, #1
	rsbs r0, r0, #0
	b _081DAE0E
_081DAD1E:
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	movs r3, #0xa8
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r4, #0
	strh r0, [r1]
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _081DAE18 @ =0x000002A2
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_081d9f8c
	adds r0, r5, #0
	bl FUN_081da30c
	adds r0, r5, #0
	bl FUN_081da3a0
	adds r0, r5, #0
	bl FUN_081da468
	adds r0, r5, #0
	bl FUN_081da608
	ldr r3, _081DAE1C @ =0x0000029B
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	ldr r2, _081DAE20 @ =0x00000299
	adds r1, r5, r2
	strb r0, [r1]
	subs r3, #1
	adds r1, r5, r3
	strb r0, [r1]
	ldr r1, _081DAE24 @ =FUN_081da930
	subs r2, #0x2d
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081DADB8
	movs r0, #4
	str r0, [sp]
	ldr r0, _081DAE28 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_081DADB8:
	movs r0, #7
	bl FUN_0809c08c
	ldr r0, _081DAE2C @ =0x03002C68
	ldr r0, [r0]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r2, r0, r3
	cmp r0, #0
	bne _081DADCE
	movs r2, #0
_081DADCE:
	adds r0, r2, #0
	adds r0, #0x40
	ldrb r1, [r0]
	ldr r3, _081DAE30 @ =0x00000286
	adds r0, r5, r3
	strb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x41
	ldrb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x42
	ldrb r1, [r0]
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_081d9e50
	adds r0, r5, #0
	bl FUN_081da814
	adds r0, r5, #0
	bl FUN_081da074
	adds r0, r5, #0
	bl FUN_081da218
	movs r0, #1
_081DAE0E:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DAE18: .4byte 0x000002A2
_081DAE1C: .4byte 0x0000029B
_081DAE20: .4byte 0x00000299
_081DAE24: .4byte FUN_081da930
_081DAE28: .4byte 0x0000FFFF
_081DAE2C: .4byte 0x03002C68
_081DAE30: .4byte 0x00000286

	thumb_func_start FUN_081dae34
FUN_081dae34: @ 0x081DAE34
	push {r4, lr}
	movs r1, #0xa9
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081DAE6C
	ldr r1, _081DAE64 @ =FUN_081daca4
	ldr r2, _081DAE68 @ =FUN_081dace0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081dacf8
	cmp r0, #0
	bge _081DAE6C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081DAE6E
	.align 2, 0
_081DAE64: .4byte FUN_081daca4
_081DAE68: .4byte FUN_081dace0
_081DAE6C:
	adds r0, r4, #0
_081DAE6E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081dae74
FUN_081dae74: @ 0x081DAE74
	push {lr}
	adds r2, r0, #0
	ldr r0, _081DAE90 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DAE8A
	movs r3, #0xb1
	lsls r3, r3, #2
	adds r1, r0, r3
	cmp r1, #0
	bne _081DAE94
_081DAE8A:
	movs r0, #1
	rsbs r0, r0, #0
	b _081DAEAE
	.align 2, 0
_081DAE90: .4byte 0x03002C68
_081DAE94:
	ldr r3, _081DAEB4 @ =0x00000322
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1, #1]
	adds r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1, #2]
	movs r0, #0
_081DAEAE:
	pop {r1}
	bx r1
	.align 2, 0
_081DAEB4: .4byte 0x00000322

	thumb_func_start FUN_081daeb8
FUN_081daeb8: @ 0x081DAEB8
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081DAF30 @ =0x0000C091
	ldr r1, _081DAF34 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r5, #0x18]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _081DAF38 @ =0x000092B3
	ldr r1, _081DAF3C @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	str r0, [r5, #0x1c]
	ldr r1, _081DAF40 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	movs r5, #3
_081DAF0A:
	adds r0, r4, #0
	adds r0, #0x19
	adds r1, r4, #0
	adds r1, #0x16
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DAF0A
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DAF30: .4byte 0x0000C091
_081DAF34: .4byte 0x0000CD91
_081DAF38: .4byte 0x000092B3
_081DAF3C: .4byte 0x000026BB
_081DAF40: .4byte 0x03004250

	thumb_func_start FUN_081daf44
FUN_081daf44: @ 0x081DAF44
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r1, _081DAF94 @ =0x0000032D
	adds r0, r3, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081DAF98 @ =0x00000323
	adds r0, r3, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r3, r2
	strb r1, [r0]
	ldr r0, _081DAF9C @ =0x00000326
	adds r1, r3, r0
	movs r0, #3
	strb r0, [r1]
	adds r2, #3
	adds r1, r3, r2
	movs r0, #4
	strb r0, [r1]
	movs r6, #0
	ldr r0, _081DAFA0 @ =0x03002C68
	ldr r0, [r0]
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0
	beq _081DAF7C
	ldrh r5, [r0, #0x1a]
_081DAF7C:
	movs r1, #0
	cmp r6, r5
	bge _081DAFB6
	adds r2, r0, #0
	movs r4, #0xd2
	lsls r4, r4, #1
_081DAF88:
	cmp r2, #0
	beq _081DAF90
	cmp r1, #0
	bge _081DAFA4
_081DAF90:
	movs r0, #0
	b _081DAFA6
	.align 2, 0
_081DAF94: .4byte 0x0000032D
_081DAF98: .4byte 0x00000323
_081DAF9C: .4byte 0x00000326
_081DAFA0: .4byte 0x03002C68
_081DAFA4:
	adds r0, r2, r4
_081DAFA6:
	ldr r0, [r0, #0x18]
	cmp r0, #2
	bhi _081DAFAE
	movs r6, #1
_081DAFAE:
	adds r4, #0x48
	adds r1, #1
	cmp r1, r5
	blt _081DAF88
_081DAFB6:
	cmp r6, #0
	beq _081DAFD4
	ldr r1, _081DAFCC @ =0x00000325
	adds r0, r3, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _081DAFD0 @ =0x00000322
	adds r0, r3, r2
	strb r1, [r0]
	b _081DAFE2
	.align 2, 0
_081DAFCC: .4byte 0x00000325
_081DAFD0: .4byte 0x00000322
_081DAFD4:
	ldr r1, _081DAFE8 @ =0x00000325
	adds r0, r3, r1
	movs r1, #2
	strb r1, [r0]
	ldr r2, _081DAFEC @ =0x00000322
	adds r0, r3, r2
	strb r6, [r0]
_081DAFE2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DAFE8: .4byte 0x00000325
_081DAFEC: .4byte 0x00000322

	thumb_func_start FUN_081daff0
FUN_081daff0: @ 0x081DAFF0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _081DB008 @ =0x0000032D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DB020
	cmp r0, #1
	bgt _081DB00C
	cmp r0, #0
	beq _081DB012
	b _081DB03C
	.align 2, 0
_081DB008: .4byte 0x0000032D
_081DB00C:
	cmp r0, #2
	beq _081DB030
	b _081DB03C
_081DB012:
	ldr r1, _081DB01C @ =0x00000322
	adds r0, r5, r1
	ldrb r1, [r0]
	b _081DB03E
	.align 2, 0
_081DB01C: .4byte 0x00000322
_081DB020:
	ldr r1, _081DB02C @ =0x00000323
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, r0, #2
	b _081DB03E
	.align 2, 0
_081DB02C: .4byte 0x00000323
_081DB030:
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, r0, #5
	b _081DB03E
_081DB03C:
	movs r1, #0
_081DB03E:
	ldr r0, _081DB070 @ =0x0000032B
	adds r6, r5, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	adds r4, r1, #0
	adds r4, #9
	cmp r0, r4
	beq _081DB06A
	bl FUN_08049e5c
	movs r1, #0xc3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	strb r4, [r6]
_081DB06A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DB070: .4byte 0x0000032B

	thumb_func_start FUN_081db074
FUN_081db074: @ 0x081DB074
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0x16
	movs r1, #4
	movs r2, #6
	movs r3, #2
	bl FUN_0804a084
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r5, r7, r1
	str r0, [r5]
	movs r0, #0x14
	movs r1, #0xc
	movs r2, #8
	movs r3, #2
	bl FUN_0804a084
	movs r2, #0xc7
	lsls r2, r2, #2
	adds r6, r7, r2
	str r0, [r6]
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r0, #0xc4
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_081daf44
	ldr r0, [r5]
	movs r1, #0xc3
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r5]
	ldr r2, _081DB120 @ =0x00000322
	adds r4, r7, r2
	ldrb r1, [r4]
	bl FUN_0804a2f8
	ldr r0, [r5]
	bl FUN_0804a1f0
	ldrb r1, [r4]
	movs r2, #0xca
	lsls r2, r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	ldr r0, [r6]
	mov r2, r8
	ldr r1, [r2]
	bl FUN_0804a240
	ldr r0, [r6]
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r4, r7, r1
	ldrb r1, [r4]
	adds r1, #5
	bl FUN_0804a2f8
	ldr r0, [r6]
	bl FUN_0804a1f0
	ldrb r1, [r4]
	ldr r2, _081DB124 @ =0x0000032A
	adds r0, r7, r2
	strb r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DB120: .4byte 0x00000322
_081DB124: .4byte 0x0000032A

	thumb_func_start FUN_081db128
FUN_081db128: @ 0x081DB128
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081db14c
FUN_081db14c: @ 0x081DB14C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _081DB17C @ =0x0000CB05
	ldr r1, _081DB180 @ =0x0000DCC1
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xb8
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	subs r2, #0x20
	adds r0, r4, r2
	bl OpenMainSpriteFile
	movs r5, #0
_081DB16E:
	cmp r5, #6
	bhi _081DB1B4
	lsls r0, r5, #2
	ldr r1, _081DB184 @ =_081DB188
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081DB17C: .4byte 0x0000CB05
_081DB180: .4byte 0x0000DCC1
_081DB184: .4byte _081DB188
_081DB188: @ jump table
	.4byte _081DB1A4 @ case 0
	.4byte _081DB1A8 @ case 1
	.4byte _081DB1AC @ case 2
	.4byte _081DB1B4 @ case 3
	.4byte _081DB1B4 @ case 4
	.4byte _081DB1B4 @ case 5
	.4byte _081DB1B0 @ case 6
_081DB1A4:
	movs r2, #0x33
	b _081DB1B6
_081DB1A8:
	movs r2, #0x34
	b _081DB1B6
_081DB1AC:
	movs r2, #0x35
	b _081DB1B6
_081DB1B0:
	movs r2, #0x15
	b _081DB1B6
_081DB1B4:
	movs r2, #0
_081DB1B6:
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r3, r4, r0
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #5
	adds r0, #0x20
	adds r0, r4, r0
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r3, #0
	movs r3, #0x10
	bl MainSprite_Add
	adds r5, #1
	cmp r5, #6
	ble _081DB16E
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081db1e8
FUN_081db1e8: @ 0x081DB1E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r2, r0, #0
	movs r4, #0
	ldr r0, _081DB220 @ =0x085AE1B4
	mov sl, r0
	ldr r1, _081DB224 @ =0x0000032D
	adds r3, r2, r1
	movs r7, #4
	add r7, sl
	mov sb, r7
	ldr r6, _081DB228 @ =0x085AE1CC
	adds r0, r6, #4
	mov r8, r0
	ldr r5, _081DB22C @ =0x085AE1E4
	adds r1, r5, #4
	mov ip, r1
_081DB210:
	cmp r4, #1
	beq _081DB252
	cmp r4, #1
	bgt _081DB230
	cmp r4, #0
	beq _081DB236
	b _081DB28C
	.align 2, 0
_081DB220: .4byte 0x085AE1B4
_081DB224: .4byte 0x0000032D
_081DB228: .4byte 0x085AE1CC
_081DB22C: .4byte 0x085AE1E4
_081DB230:
	cmp r4, #2
	beq _081DB26E
	b _081DB28C
_081DB236:
	ldrb r0, [r3]
	lsls r0, r0, #3
	add r0, sl
	ldr r1, [r0]
	adds r0, r2, #0
	adds r0, #0x40
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #3
	add r0, sb
	ldr r0, [r0]
	adds r1, r2, #0
	adds r1, #0x42
	b _081DB28A
_081DB252:
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	adds r0, r2, #0
	adds r0, #0xa0
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #3
	add r0, r8
	ldr r0, [r0]
	adds r1, r2, #0
	adds r1, #0xa2
	b _081DB28A
_081DB26E:
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r1, [r0]
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r2, r7
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #3
	add r0, ip
	ldr r0, [r0]
	adds r7, #2
	adds r1, r2, r7
_081DB28A:
	strh r0, [r1]
_081DB28C:
	adds r4, #1
	cmp r4, #6
	ble _081DB210
	adds r4, r2, #0
	adds r4, #0x88
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r3, r2, #0
	adds r3, #0xe8
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r1, _081DB2E8 @ =0x0000032D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DB2CA
	ldr r7, _081DB2EC @ =0x00000325
	adds r0, r2, r7
	ldrb r1, [r0]
	cmp r1, #1
	bne _081DB2CA
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081DB2CA:
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r2, r1
	movs r1, #0
	strh r1, [r0]
	ldr r3, _081DB2F0 @ =0x00000282
	adds r0, r2, r3
	strh r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DB2E8: .4byte 0x0000032D
_081DB2EC: .4byte 0x00000325
_081DB2F0: .4byte 0x00000282

	thumb_func_start FUN_081db2f4
FUN_081db2f4: @ 0x081DB2F4
	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0x28
	movs r2, #6
_081DB2FE:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081DB2FE
	pop {r0}
	bx r0

	thumb_func_start FUN_081db310
FUN_081db310: @ 0x081DB310
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x20
	movs r5, #6
_081DB318:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081DB318
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081db32c
FUN_081db32c: @ 0x081DB32C
	push {lr}
	mov ip, r0
	ldr r0, _081DB368 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _081DB36C @ =0x00005260
	adds r2, r0, r1
	movs r1, #0xb9
	lsls r1, r1, #2
	add r1, ip
	movs r3, #0xf
_081DB340:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _081DB340
	movs r0, #0xb9
	lsls r0, r0, #2
	add r0, ip
	mov r1, ip
	str r0, [r1, #0x68]
	movs r1, #0xc1
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081DB368: .4byte 0x03003584
_081DB36C: .4byte 0x00005260

	thumb_func_start FUN_081db370
FUN_081db370: @ 0x081DB370
	push {lr}
	adds r3, r0, #0
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrh r0, [r0]
	movs r2, #0x1f
	cmp r0, #9
	bls _081DB39C
	movs r2, #0x1b
	cmp r0, #0x11
	bls _081DB39C
	movs r2, #0x12
	cmp r0, #0x19
	bls _081DB39C
	movs r2, #0xa
	cmp r0, #0x21
	bls _081DB39C
	movs r2, #0x1b
	cmp r0, #0x29
	bhi _081DB39C
	movs r2, #0x12
_081DB39C:
	movs r0, #0xc1
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bls _081DB3B4
	movs r0, #0
	strh r0, [r1]
_081DB3B4:
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	pop {r0}
	bx r0

	thumb_func_start FUN_081db3c0
FUN_081db3c0: @ 0x081DB3C0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	cmp r4, #0x63
	ble _081DB410
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0xcc
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0x40
	strh r2, [r0]
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0xc4
	strh r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	adds r3, #0x60
	adds r1, r5, r3
	movs r0, #0xbc
	strh r0, [r1]
	ldr r1, _081DB40C @ =0x00000222
	adds r0, r5, r1
	strh r2, [r0]
	subs r3, #0x18
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _081DB440
	.align 2, 0
_081DB40C: .4byte 0x00000222
_081DB410:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0xc8
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0x40
	strh r2, [r0]
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0xc0
	strh r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	adds r3, #0x48
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
_081DB440:
	str r0, [r2]
	movs r2, #0
	cmp r4, #0x63
	ble _081DB450
_081DB448:
	adds r2, #1
	subs r4, #0x64
	cmp r4, #0x63
	bgt _081DB448
_081DB450:
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r3, #0xb0
	lsls r3, r3, #2
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r4, #9
	ble _081DB472
_081DB46A:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081DB46A
_081DB472:
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r3, #0xb0
	lsls r3, r3, #2
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r4, #0
	ble _081DB494
_081DB48C:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081DB48C
_081DB494:
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r3, #0xb0
	lsls r3, r3, #2
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081db4b0
FUN_081db4b0: @ 0x081DB4B0
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	ldr r1, _081DB4C8 @ =0x0000032D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DB504
	cmp r0, #1
	bgt _081DB4CC
	cmp r0, #0
	beq _081DB4D2
	b _081DB572
	.align 2, 0
_081DB4C8: .4byte 0x0000032D
_081DB4CC:
	cmp r0, #2
	beq _081DB538
	b _081DB572
_081DB4D2:
	ldr r3, _081DB500 @ =0x00000322
	adds r5, r2, r3
	ldrb r1, [r5]
	movs r0, #0xca
	lsls r0, r0, #2
	adds r6, r2, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r1, r0
	beq _081DB572
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r4, r2, r1
	ldr r0, [r4]
	subs r3, #0x16
	adds r1, r2, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	ldrb r1, [r5]
	b _081DB564
	.align 2, 0
_081DB500: .4byte 0x00000322
_081DB504:
	ldr r0, _081DB52C @ =0x00000323
	adds r5, r2, r0
	ldrb r3, [r5]
	ldr r1, _081DB530 @ =0x00000329
	adds r4, r2, r1
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r3, r0
	beq _081DB572
	ldr r1, _081DB534 @ =0x085AE1FC
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	bl FUN_081db3c0
	ldrb r0, [r5]
	strb r0, [r4]
	b _081DB572
	.align 2, 0
_081DB52C: .4byte 0x00000323
_081DB530: .4byte 0x00000329
_081DB534: .4byte 0x085AE1FC
_081DB538:
	movs r3, #0xc9
	lsls r3, r3, #2
	adds r5, r2, r3
	ldrb r1, [r5]
	ldr r0, _081DB578 @ =0x0000032A
	adds r6, r2, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r1, r0
	beq _081DB572
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r4, r2, r1
	ldr r0, [r4]
	subs r3, #0x18
	adds r1, r2, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	ldrb r1, [r5]
	adds r1, #5
_081DB564:
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldrb r0, [r5]
	strb r0, [r6]
_081DB572:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DB578: .4byte 0x0000032A

	thumb_func_start FUN_081db57c
FUN_081db57c: @ 0x081DB57C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DB5D0
	bl FUN_08049f5c
	movs r2, #1
	movs r0, #0xc4
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	bl FUN_08049e5c
	movs r1, #0xc3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #9
	bl Textbox_LookupString
	bl FUN_08049e30
	adds r0, r5, #0
	bl FUN_081db4b0
	ldr r2, _081DB5F0 @ =0x0000032D
	adds r0, r5, r2
	movs r2, #0
	strb r2, [r0]
	ldr r1, _081DB5F4 @ =0x0000032E
	adds r0, r5, r1
	movs r1, #0
	strh r2, [r0]
	strb r1, [r4]
_081DB5D0:
	ldr r2, _081DB5F4 @ =0x0000032E
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0x1d
	bhi _081DB5F8
	adds r0, r5, #0
	bl FUN_081db370
	adds r0, r5, #0
	bl FUN_081daff0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _081DB8D0
	.align 2, 0
_081DB5F0: .4byte 0x0000032D
_081DB5F4: .4byte 0x0000032E
_081DB5F8:
	ldr r1, _081DB614 @ =0x0000032D
	adds r0, r5, r1
	ldrb r4, [r0]
	ldr r2, _081DB618 @ =0x00000321
	adds r6, r5, r2
	movs r3, #0
	ldr r1, _081DB61C @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081DB620
	movs r3, #1
	b _081DB65A
	.align 2, 0
_081DB614: .4byte 0x0000032D
_081DB618: .4byte 0x00000321
_081DB61C: .4byte 0x030044E0
_081DB620:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081DB62C
	movs r3, #2
	b _081DB65A
_081DB62C:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081DB638
	movs r3, #4
	b _081DB65A
_081DB638:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081DB644
	movs r3, #8
	b _081DB65A
_081DB644:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081DB650
	movs r3, #0x20
	b _081DB65A
_081DB650:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081DB65A
	movs r3, #0x10
_081DB65A:
	ldrh r2, [r1]
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0
	beq _081DB6A2
	ldrb r0, [r6]
	cmp r0, #0xb
	bls _081DB6A0
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081DB676
	movs r0, #1
	b _081DB680
_081DB676:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081DB682
	movs r0, #2
_081DB680:
	orrs r3, r0
_081DB682:
	ldrh r1, [r1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _081DB690
	movs r0, #4
	b _081DB69A
_081DB690:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081DB69C
	movs r0, #8
_081DB69A:
	orrs r3, r0
_081DB69C:
	movs r0, #0
	b _081DB6A2
_081DB6A0:
	adds r0, #1
_081DB6A2:
	strb r0, [r6]
	movs r1, #0
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq _081DB6BA
	cmp r4, #0
	bne _081DB6B6
	movs r4, #2
	b _081DB83C
_081DB6B6:
	subs r4, #1
	b _081DB83C
_081DB6BA:
	movs r0, #2
	ands r0, r3
	cmp r0, #0
	beq _081DB6D8
	cmp r4, #2
	bne _081DB6CA
	movs r4, #0
	b _081DB6CC
_081DB6CA:
	adds r4, #1
_081DB6CC:
	ldr r2, _081DB6D4 @ =0x00000321
	adds r1, r5, r2
	b _081DB840
	.align 2, 0
_081DB6D4: .4byte 0x00000321
_081DB6D8:
	movs r0, #4
	ands r0, r3
	cmp r0, #0
	beq _081DB77A
	ldr r2, _081DB6F4 @ =0x0000032D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DB730
	cmp r0, #1
	bgt _081DB6F8
	cmp r0, #0
	beq _081DB6FE
	b _081DB82C
	.align 2, 0
_081DB6F4: .4byte 0x0000032D
_081DB6F8:
	cmp r0, #2
	beq _081DB750
	b _081DB82C
_081DB6FE:
	ldr r0, _081DB71C @ =0x00000325
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #1
	bne _081DB70A
	b _081DB82C
_081DB70A:
	ldr r1, _081DB720 @ =0x00000322
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DB724
	ldrb r0, [r2]
	subs r1, r0, #1
	b _081DB726
	.align 2, 0
_081DB71C: .4byte 0x00000325
_081DB720: .4byte 0x00000322
_081DB724:
	subs r1, #1
_081DB726:
	ldr r2, _081DB72C @ =0x00000322
	b _081DB7F8
	.align 2, 0
_081DB72C: .4byte 0x00000322
_081DB730:
	ldr r1, _081DB744 @ =0x00000323
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DB74C
	ldr r2, _081DB748 @ =0x00000326
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DB7F6
	.align 2, 0
_081DB744: .4byte 0x00000323
_081DB748: .4byte 0x00000326
_081DB74C:
	subs r1, #1
	b _081DB7F6
_081DB750:
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DB76C
	ldr r2, _081DB768 @ =0x00000327
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DB76E
	.align 2, 0
_081DB768: .4byte 0x00000327
_081DB76C:
	subs r1, #1
_081DB76E:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	movs r1, #1
	b _081DB830
_081DB77A:
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq _081DB84C
	ldr r2, _081DB798 @ =0x0000032D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DB7D4
	cmp r0, #1
	bgt _081DB79C
	cmp r0, #0
	beq _081DB7A2
	b _081DB82C
	.align 2, 0
_081DB798: .4byte 0x0000032D
_081DB79C:
	cmp r0, #2
	beq _081DB804
	b _081DB82C
_081DB7A2:
	ldr r0, _081DB7C0 @ =0x00000325
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #1
	beq _081DB82C
	ldr r1, _081DB7C4 @ =0x00000322
	adds r0, r5, r1
	ldrb r1, [r0]
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	bne _081DB7C8
	movs r1, #0
	b _081DB7CA
	.align 2, 0
_081DB7C0: .4byte 0x00000325
_081DB7C4: .4byte 0x00000322
_081DB7C8:
	adds r1, #1
_081DB7CA:
	ldr r2, _081DB7D0 @ =0x00000322
	b _081DB7F8
	.align 2, 0
_081DB7D0: .4byte 0x00000322
_081DB7D4:
	ldr r1, _081DB7EC @ =0x00000323
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _081DB7F0 @ =0x00000326
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne _081DB7F4
	movs r1, #0
	b _081DB7F6
	.align 2, 0
_081DB7EC: .4byte 0x00000323
_081DB7F0: .4byte 0x00000326
_081DB7F4:
	adds r1, #1
_081DB7F6:
	ldr r2, _081DB800 @ =0x00000323
_081DB7F8:
	adds r0, r5, r2
	strb r1, [r0]
	b _081DB830
	.align 2, 0
_081DB800: .4byte 0x00000323
_081DB804:
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _081DB81C @ =0x00000327
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne _081DB820
	movs r1, #0
	b _081DB822
	.align 2, 0
_081DB81C: .4byte 0x00000327
_081DB820:
	adds r1, #1
_081DB822:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	movs r1, #1
_081DB82C:
	cmp r1, #0
	beq _081DB83C
_081DB830:
	adds r0, r5, #0
	bl FUN_081db4b0
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DB83C:
	ldr r0, _081DB848 @ =0x00000321
	adds r1, r5, r0
_081DB840:
	movs r0, #0
	strb r0, [r1]
	b _081DB8AC
	.align 2, 0
_081DB848: .4byte 0x00000321
_081DB84C:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _081DB87E
	adds r0, r5, #0
	bl FUN_081dae74
	movs r0, #1
	bl FUN_081df95c
	movs r0, #0xdd
	bl PlaySound_082406e0
	bl FUN_08049fa8
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r5, #0
	bl FUN_081db2f4
	b _081DB8A4
_081DB87E:
	movs r0, #0x10
	ands r3, r0
	cmp r3, #0
	beq _081DB8AC
	movs r0, #2
	bl FUN_081df95c
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r5, #0
	bl FUN_081db2f4
	movs r0, #0xde
	bl PlaySound_082406e0
_081DB8A4:
	adds r0, r5, #0
	bl KillEntity
	b _081DB8D0
_081DB8AC:
	ldr r2, _081DB8D8 @ =0x0000032D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, r4
	beq _081DB8C4
	strb r4, [r1]
	adds r0, r5, #0
	bl FUN_081db1e8
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DB8C4:
	adds r0, r5, #0
	bl FUN_081db370
	adds r0, r5, #0
	bl FUN_081daff0
_081DB8D0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DB8D8: .4byte 0x0000032D

	thumb_func_start FUN_081db8dc
FUN_081db8dc: @ 0x081DB8DC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _081DB8FE
	bl FUN_08049fa8
	adds r0, r4, #0
	bl FUN_081db2f4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081DB912
_081DB8FE:
	movs r1, #0xc2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081DB910
	adds r0, r4, #0
	bl _call_via_r1
_081DB910:
	movs r0, #1
_081DB912:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081db918
FUN_081db918: @ 0x081DB918
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081db310
	adds r0, r4, #0
	bl FUN_081db128
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081db930
FUN_081db930: @ 0x081DB930
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081DB954
	bl FUN_0823d340
	movs r2, #0xc3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	bne _081DB954
	movs r0, #1
	rsbs r0, r0, #0
	b _081DB9A4
_081DB954:
	movs r0, #0
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_081daeb8
	adds r0, r4, #0
	bl FUN_081db074
	adds r0, r4, #0
	bl FUN_081db14c
	adds r0, r4, #0
	bl FUN_081db1e8
	adds r0, r4, #0
	bl FUN_081db32c
	adds r0, r4, #0
	movs r1, #0x3c
	bl FUN_081db3c0
	ldr r3, _081DB9AC @ =0x00000329
	adds r0, r4, r3
	movs r2, #0
	strb r2, [r0]
	ldr r1, _081DB9B0 @ =FUN_081db57c
	subs r3, #0x21
	adds r0, r4, r3
	str r1, [r0]
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #1
_081DB9A4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DB9AC: .4byte 0x00000329
_081DB9B0: .4byte FUN_081db57c

	thumb_func_start FUN_081db9b4
FUN_081db9b4: @ 0x081DB9B4
	push {r4, lr}
	movs r1, #0xcc
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081DB9EC
	ldr r1, _081DB9E4 @ =FUN_081db8dc
	ldr r2, _081DB9E8 @ =FUN_081db918
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081db930
	cmp r0, #0
	bge _081DB9EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081DB9EE
	.align 2, 0
_081DB9E4: .4byte FUN_081db8dc
_081DB9E8: .4byte FUN_081db918
_081DB9EC:
	adds r0, r4, #0
_081DB9EE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081db9f4
FUN_081db9f4: @ 0x081DB9F4
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _081DBA40 @ =0x0000C091
	ldr r1, _081DBA44 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x18]
	movs r0, #7
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	ldr r0, _081DBA48 @ =0x000092B3
	ldr r1, _081DBA4C @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	str r0, [r4, #0x1c]
	ldr r1, _081DBA50 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DBA40: .4byte 0x0000C091
_081DBA44: .4byte 0x0000CD91
_081DBA48: .4byte 0x000092B3
_081DBA4C: .4byte 0x000026BB
_081DBA50: .4byte 0x03004250

	thumb_func_start FUN_081dba54
FUN_081dba54: @ 0x081DBA54
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	adds r0, #0x40
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #0x10
	bl CpuSet
	movs r0, #0xea
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dba78
FUN_081dba78: @ 0x081DBA78
	push {r4, lr}
	adds r2, r0, #0
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	bge _081DBAC0
	ldr r3, _081DBAB4 @ =0x0000039A
	adds r0, r2, r3
	ldr r1, _081DBAB8 @ =0x00006739
	strh r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	strh r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	strh r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	strh r1, [r0]
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, _081DBABC @ =0x03004290
	movs r2, #0x10
	bl CpuSet
	b _081DBC08
	.align 2, 0
_081DBAB4: .4byte 0x0000039A
_081DBAB8: .4byte 0x00006739
_081DBABC: .4byte 0x03004290
_081DBAC0:
	movs r3, #0xea
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	movs r3, #0x1f
	cmp r0, #9
	bls _081DBAE8
	movs r3, #0x1b
	cmp r0, #0x11
	bls _081DBAE8
	movs r3, #0x12
	cmp r0, #0x19
	bls _081DBAE8
	movs r3, #0xa
	cmp r0, #0x21
	bls _081DBAE8
	movs r3, #0x1b
	cmp r0, #0x29
	bhi _081DBAE8
	movs r3, #0x12
_081DBAE8:
	movs r0, #0xea
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r4, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bls _081DBB02
	movs r0, #0
	strh r0, [r1]
_081DBB02:
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DBB20
	ldr r0, _081DBB18 @ =0x0000039A
	adds r1, r2, r0
	ldr r0, _081DBB1C @ =0x00006739
	b _081DBB26
	.align 2, 0
_081DBB18: .4byte 0x0000039A
_081DBB1C: .4byte 0x00006739
_081DBB20:
	ldr r0, _081DBB3C @ =0x0000039A
	adds r1, r2, r0
	ldr r0, _081DBB40 @ =0x000035B4
_081DBB26:
	strh r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DBB4C
	ldr r0, _081DBB44 @ =0x0000039E
	adds r1, r2, r0
	ldr r0, _081DBB48 @ =0x00006739
	b _081DBB52
	.align 2, 0
_081DBB3C: .4byte 0x0000039A
_081DBB40: .4byte 0x000035B4
_081DBB44: .4byte 0x0000039E
_081DBB48: .4byte 0x00006739
_081DBB4C:
	ldr r0, _081DBB68 @ =0x0000039E
	adds r1, r2, r0
	ldr r0, _081DBB6C @ =0x000035B4
_081DBB52:
	strh r0, [r1]
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DBB78
	ldr r0, _081DBB70 @ =0x000003A2
	adds r1, r2, r0
	ldr r0, _081DBB74 @ =0x00006739
	b _081DBB7E
	.align 2, 0
_081DBB68: .4byte 0x0000039E
_081DBB6C: .4byte 0x000035B4
_081DBB70: .4byte 0x000003A2
_081DBB74: .4byte 0x00006739
_081DBB78:
	ldr r0, _081DBB94 @ =0x000003A2
	adds r1, r2, r0
	ldr r0, _081DBB98 @ =0x000035B4
_081DBB7E:
	strh r0, [r1]
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DBBA4
	ldr r0, _081DBB9C @ =0x000003A6
	adds r1, r2, r0
	ldr r0, _081DBBA0 @ =0x00006739
	b _081DBBAA
	.align 2, 0
_081DBB94: .4byte 0x000003A2
_081DBB98: .4byte 0x000035B4
_081DBB9C: .4byte 0x000003A6
_081DBBA0: .4byte 0x00006739
_081DBBA4:
	ldr r0, _081DBBC4 @ =0x000003A6
	adds r1, r2, r0
	ldr r0, _081DBBC8 @ =0x000035B4
_081DBBAA:
	strh r0, [r1]
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #1
	beq _081DBBDC
	cmp r0, #1
	bgt _081DBBCC
	cmp r0, #0
	beq _081DBBD6
	b _081DBBFA
	.align 2, 0
_081DBBC4: .4byte 0x000003A6
_081DBBC8: .4byte 0x000035B4
_081DBBCC:
	cmp r0, #2
	beq _081DBBE2
	cmp r0, #3
	beq _081DBBE8
	b _081DBBFA
_081DBBD6:
	movs r1, #0xeb
	lsls r1, r1, #2
	b _081DBBEC
_081DBBDC:
	movs r1, #0xec
	lsls r1, r1, #2
	b _081DBBEC
_081DBBE2:
	movs r1, #0xed
	lsls r1, r1, #2
	b _081DBBEC
_081DBBE8:
	movs r1, #0xee
	lsls r1, r1, #2
_081DBBEC:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081DBBFA
	subs r1, #0x12
	adds r0, r2, r1
	strh r3, [r0]
_081DBBFA:
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r1, _081DBC10 @ =0x03004290
	movs r2, #0x10
	bl CpuSet
_081DBC08:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DBC10: .4byte 0x03004290

	thumb_func_start FUN_081dbc14
FUN_081dbc14: @ 0x081DBC14
	movs r2, #0xd8
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #4
	strh r2, [r1]
	ldr r3, _081DBC58 @ =0x00000362
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r1, #0x3a
	strh r1, [r2]
	adds r3, #4
	adds r2, r0, r3
	movs r1, #0x3b
	strh r1, [r2]
	movs r1, #0xdb
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r1, #0x3c
	strh r1, [r2]
	ldr r2, _081DBC5C @ =0x0000036E
	adds r0, r0, r2
	movs r1, #0x3d
	strh r1, [r0]
	bx lr
	.align 2, 0
_081DBC58: .4byte 0x00000362
_081DBC5C: .4byte 0x0000036E

	thumb_func_start FUN_081dbc60
FUN_081dbc60: @ 0x081DBC60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081DBCD8 @ =0x0000CB05
	ldr r1, _081DBCDC @ =0x0000DCC1
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r3, #0xc8
	lsls r3, r3, #2
	adds r0, r5, r3
	bl OpenMainSpriteFile
	movs r0, #4
	mov r8, r0
	movs r7, #0
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r6, r5, r1
_081DBC92:
	mov r2, r8
	lsls r4, r2, #1
	movs r3, #0xd8
	lsls r3, r3, #2
	adds r0, r5, r3
	adds r0, r0, r4
	ldrh r2, [r0]
	str r7, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r6, #0
	subs r3, #0x40
	adds r1, r5, r3
	movs r3, #0x10
	bl MainSprite_Add
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r0, r0, r4
	ldr r1, _081DBCE0 @ =0x0000FFFF
	strh r1, [r0]
	adds r6, #0x60
	movs r2, #1
	add r8, r2
	mov r3, r8
	cmp r3, #7
	ble _081DBC92
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DBCD8: .4byte 0x0000CB05
_081DBCDC: .4byte 0x0000DCC1
_081DBCE0: .4byte 0x0000FFFF

	thumb_func_start FUN_081dbce4
FUN_081dbce4: @ 0x081DBCE4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r1, r0, #0
	movs r2, #0
	adds r4, r1, #0
	adds r4, #0x40
	movs r0, #0x1d
	mov r8, r0
	movs r7, #0x40
	mov ip, r7
	movs r0, #0xd3
	mov sb, r0
	movs r6, #0x70
	adds r3, r4, #0
	movs r5, #0
_081DBD06:
	cmp r2, #1
	beq _081DBD28
	cmp r2, #1
	bgt _081DBD14
	cmp r2, #0
	beq _081DBD1E
	b _081DBD5C
_081DBD14:
	cmp r2, #2
	beq _081DBD38
	cmp r2, #3
	beq _081DBD48
	b _081DBD5C
_081DBD1E:
	mov r7, r8
	strh r7, [r4]
	adds r0, r1, #0
	adds r0, #0x42
	b _081DBD32
_081DBD28:
	adds r0, r1, #0
	adds r0, #0xa0
	mov r7, sb
	strh r7, [r0]
	adds r0, #2
_081DBD32:
	mov r7, ip
	strh r7, [r0]
	b _081DBD60
_081DBD38:
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r1, r7
	mov r7, r8
	strh r7, [r0]
	movs r7, #0x81
	lsls r7, r7, #1
	b _081DBD56
_081DBD48:
	movs r7, #0xb0
	lsls r7, r7, #1
	adds r0, r1, r7
	mov r7, sb
	strh r7, [r0]
	movs r7, #0xb1
	lsls r7, r7, #1
_081DBD56:
	adds r0, r1, r7
	strh r6, [r0]
	b _081DBD60
_081DBD5C:
	strh r5, [r3]
	strh r5, [r3, #2]
_081DBD60:
	adds r3, #0x60
	adds r2, #1
	cmp r2, #7
	ble _081DBD06
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dbd74
FUN_081dbd74: @ 0x081DBD74
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081DBDE8 @ =0x0000CB05
	ldr r1, _081DBDEC @ =0x0000DE23
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r0, r5, r3
	bl OpenMainSpriteFile
	movs r4, #0
	mov sb, r4
	movs r7, #0
	adds r6, r5, #0
	adds r6, #0x20
	movs r0, #0
	mov r8, r0
_081DBDAA:
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r0, r0, r7
	ldrh r2, [r0]
	mov r3, r8
	str r3, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	adds r0, r6, #0
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r3, #0x10
	bl MainSprite_Add
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r0, r0, r7
	ldr r1, _081DBDF0 @ =0x0000FFFF
	strh r1, [r0]
	cmp r4, #1
	beq _081DBE02
	cmp r4, #1
	bgt _081DBDF4
	cmp r4, #0
	beq _081DBDFE
	b _081DBE0E
	.align 2, 0
_081DBDE8: .4byte 0x0000CB05
_081DBDEC: .4byte 0x0000DE23
_081DBDF0: .4byte 0x0000FFFF
_081DBDF4:
	cmp r4, #2
	beq _081DBE06
	cmp r4, #3
	beq _081DBE0A
	b _081DBE0E
_081DBDFE:
	movs r3, #0x22
	b _081DBE10
_081DBE02:
	movs r3, #0x23
	b _081DBE10
_081DBE06:
	movs r3, #0x24
	b _081DBE10
_081DBE0A:
	movs r3, #0x25
	b _081DBE10
_081DBE0E:
	movs r3, #0
_081DBE10:
	adds r1, r5, #0
	adds r1, #0x68
	add r1, sb
	ldr r0, _081DBE40 @ =0x03003584
	lsls r2, r3, #5
	ldr r0, [r0]
	adds r0, r0, r2
	str r0, [r1]
	strh r3, [r6, #0x3a]
	movs r2, #0x60
	add sb, r2
	adds r7, #2
	adds r6, #0x60
	adds r4, #1
	cmp r4, #3
	ble _081DBDAA
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DBE40: .4byte 0x03003584

	thumb_func_start FUN_081dbe44
FUN_081dbe44: @ 0x081DBE44
	push {r4, lr}
	adds r4, r0, #0
	bl MainSprite_AdvanceAnim
	adds r2, r0, #0
	ldrb r1, [r4, #0x1d]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081DBE5C
	cmp r2, #0
	beq _081DBE60
_081DBE5C:
	movs r0, #1
	b _081DBE62
_081DBE60:
	movs r0, #0
_081DBE62:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081dbe68
FUN_081dbe68: @ 0x081DBE68
	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0x28
	movs r2, #7
_081DBE72:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081DBE72
	pop {r0}
	bx r0

	thumb_func_start FUN_081dbe84
FUN_081dbe84: @ 0x081DBE84
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x20
	movs r5, #7
_081DBE8C:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081DBE8C
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dbea0
FUN_081dbea0: @ 0x081DBEA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	movs r0, #0
	mov sb, r0
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r1, r6, r1
	str r1, [sp, #4]
	adds r2, r6, #0
	adds r2, #0x20
	str r2, [sp, #8]
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0xc]
	str r0, [sp, #0x10]
	movs r1, #0x28
	adds r1, r1, r6
	mov r8, r1
	movs r2, #0
	str r2, [sp, #0x14]
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r7, r6, r3
	movs r0, #0xda
	lsls r0, r0, #2
	adds r0, r6, r0
	str r0, [sp, #0x18]
_081DBEE2:
	ldr r0, _081DBF24 @ =0x03002C68
	ldr r2, [r0]
	cmp r2, #0
	beq _081DBF04
	mov r1, sb
	cmp r1, #0
	blt _081DBF04
	mov r3, sb
	lsls r0, r3, #3
	add r0, sb
	lsls r0, r0, #3
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r3, r2, r0
	cmp r3, #0
	bne _081DBF28
_081DBF04:
	ldr r0, [r7]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7]
	mov r0, sb
	adds r0, #0x3a
	ldr r3, [sp, #0x18]
	strh r0, [r3]
	mov r1, r8
	ldr r0, [r1]
	movs r1, #1
	orrs r0, r1
	mov r2, r8
	b _081DC01C
	.align 2, 0
_081DBF24: .4byte 0x03002C68
_081DBF28:
	mov r1, sb
	lsls r0, r1, #2
	adds r0, r6, r0
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #1
	bls _081DC000
	ldrb r0, [r2, #0x1c]
	cmp r0, #5
	bgt _081DBF5C
	mov r2, r8
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	mov r0, sb
	adds r0, #0x36
	ldr r3, [sp, #0x18]
	strh r0, [r3]
	ldr r0, [r7]
	subs r1, #3
	ands r0, r1
	str r0, [r7]
	b _081DC01E
_081DBF5C:
	mov r1, r8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	mov r2, sb
	adds r2, #4
	movs r0, #0x28
	adds r0, r0, r6
	mov sl, r0
	mov r1, sb
	cmp r1, #1
	bgt _081DBFC0
	adds r0, r3, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DBFA6
	cmp r0, #1
	bgt _081DBF94
	cmp r0, #0
	beq _081DBF9A
	b _081DC050
_081DBF94:
	cmp r0, #2
	beq _081DBFB2
	b _081DC050
_081DBF9A:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #8
	strh r0, [r1]
	b _081DC050
_081DBFA6:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #0xcf
	strh r0, [r1]
	b _081DC050
_081DBFB2:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #0xd3
	lsls r0, r0, #1
	strh r0, [r1]
	b _081DC050
_081DBFC0:
	adds r0, r3, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DBFE6
	cmp r0, #1
	bgt _081DBFD4
	cmp r0, #0
	beq _081DBFDA
	b _081DC050
_081DBFD4:
	cmp r0, #2
	beq _081DBFF2
	b _081DC050
_081DBFDA:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #6
	strh r0, [r1]
	b _081DC050
_081DBFE6:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #0xcd
	strh r0, [r1]
	b _081DC050
_081DBFF2:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #0xd2
	lsls r0, r0, #1
	strh r0, [r1]
	b _081DC050
_081DC000:
	cmp r1, #1
	bne _081DC02A
	ldr r0, [r7]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7]
	mov r0, sb
	adds r0, #0x36
	ldr r3, [sp, #0x18]
	strh r0, [r3]
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
_081DC01C:
	str r0, [r2]
_081DC01E:
	mov r2, sb
	adds r2, #4
	movs r3, #0x28
	adds r3, r3, r6
	mov sl, r3
	b _081DC050
_081DC02A:
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	mov r0, sb
	adds r0, #0x3a
	ldr r2, [sp, #0x18]
	strh r0, [r2]
	mov r3, r8
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	mov r2, sb
	adds r2, #4
	movs r0, #0x28
	adds r0, r0, r6
	mov sl, r0
_081DC050:
	lsls r0, r2, #1
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r4, r6, r1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r5, r6, r3
	adds r0, r5, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	beq _081DC076
	ldr r0, [sp, #0xc]
	subs r3, #0x50
	adds r1, r6, r3
	bl MainSprite_LoadPose
_081DC076:
	ldr r0, [sp, #0x14]
	adds r4, r4, r0
	ldrh r1, [r4]
	adds r5, r5, r0
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r1, r0
	beq _081DC0AE
	ldr r2, [sp, #0x10]
	add r2, sl
	ldr r0, _081DC0FC @ =0x085AE204
	add r0, sb
	ldrb r1, [r0]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldrh r2, [r4]
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #8]
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r3, #1
	bl MainSprite_SetAnim
	ldrh r0, [r4]
	strh r0, [r5]
_081DC0AE:
	ldr r0, [sp, #8]
	movs r2, #0xd0
	lsls r2, r2, #2
	adds r1, r6, r2
	bl MainSprite_AdvanceAnim
	ldr r3, [sp, #8]
	adds r3, #0x60
	str r3, [sp, #8]
	ldr r0, [sp, #0xc]
	adds r0, #0x60
	str r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	adds r1, #0x60
	str r1, [sp, #0x10]
	movs r2, #0x60
	add r8, r2
	ldr r3, [sp, #0x14]
	adds r3, #2
	str r3, [sp, #0x14]
	adds r7, #0x60
	ldr r0, [sp, #0x18]
	adds r0, #2
	str r0, [sp, #0x18]
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #3
	bgt _081DC0EA
	b _081DBEE2
_081DC0EA:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DC0FC: .4byte 0x085AE204

	thumb_func_start FUN_081dc100
FUN_081dc100: @ 0x081DC100
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	bge _081DC144
	ldr r0, _081DC140 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #2
	bne _081DC11E
	b _081DC2D4
_081DC11E:
	bl FUN_08049e5c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #2
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #2
	strb r0, [r5]
	b _081DC2D4
	.align 2, 0
_081DC140: .4byte 0x000003D1
_081DC144:
	bl FUN_081dfa04
	adds r2, r0, #0
	subs r0, r2, #5
	cmp r0, #1
	bhi _081DC184
	ldr r0, _081DC180 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #4
	bne _081DC15E
	b _081DC2D4
_081DC15E:
	bl FUN_08049e5c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #4
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #4
	strb r0, [r5]
	b _081DC2D4
	.align 2, 0
_081DC180: .4byte 0x000003D1
_081DC184:
	ldr r0, _081DC198 @ =0x03002C68
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	beq _081DC19C
	ldrb r0, [r1, #0x1d]
	cmp r0, #0
	beq _081DC19C
	movs r0, #1
	b _081DC19E
	.align 2, 0
_081DC198: .4byte 0x03002C68
_081DC19C:
	movs r0, #0
_081DC19E:
	cmp r0, #0
	beq _081DC1D8
	cmp r2, #8
	bne _081DC1D8
	ldr r0, _081DC1D4 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #6
	bne _081DC1B4
	b _081DC2D4
_081DC1B4:
	bl FUN_08049e5c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #6
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #6
	strb r0, [r5]
	b _081DC2D4
	.align 2, 0
_081DC1D4: .4byte 0x000003D1
_081DC1D8:
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r0, [r3]
	cmp r0, #0
	bne _081DC1EA
	movs r6, #0
	b _081DC1F0
_081DC1EA:
	adds r0, #0x68
	adds r0, r0, r1
	ldrb r6, [r0]
_081DC1F0:
	cmp r6, #2
	beq _081DC234
	cmp r6, #2
	ble _081DC1FE
	cmp r6, #3
	beq _081DC264
	b _081DC2D4
_081DC1FE:
	cmp r6, #0
	blt _081DC2D4
	ldr r0, _081DC230 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #1
	beq _081DC2D4
	bl FUN_08049e5c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #1
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #1
	strb r0, [r5]
	b _081DC2D4
	.align 2, 0
_081DC230: .4byte 0x000003D1
_081DC234:
	ldr r0, _081DC260 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #2
	beq _081DC2D4
	bl FUN_08049e5c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #2
	bl Textbox_LookupString
	bl FUN_08049e30
	strb r6, [r5]
	b _081DC2D4
	.align 2, 0
_081DC260: .4byte 0x000003D1
_081DC264:
	movs r0, #0xf3
	lsls r0, r0, #2
	adds r5, r4, r0
	adds r0, #6
	adds r1, r4, r0
	ldr r0, [r5]
	ldrb r1, [r1]
	cmp r0, r1
	beq _081DC2A4
	bl FUN_08049e5c
	ldr r1, [r5]
	movs r0, #0
	bl FUN_08049e6c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #3
	bl Textbox_LookupString
	bl FUN_08049e30
	ldr r1, _081DC2A0 @ =0x000003D1
	adds r0, r4, r1
	strb r6, [r0]
	b _081DC2D4
	.align 2, 0
_081DC2A0: .4byte 0x000003D1
_081DC2A4:
	ldr r0, _081DC2DC @ =0x000003D1
	adds r7, r4, r0
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #3
	beq _081DC2D4
	bl FUN_08049e5c
	ldr r1, [r5]
	movs r0, #0
	bl FUN_08049e6c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #3
	bl Textbox_LookupString
	bl FUN_08049e30
	strb r6, [r7]
_081DC2D4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DC2DC: .4byte 0x000003D1

	thumb_func_start FUN_081dc2e0
FUN_081dc2e0: @ 0x081DC2E0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08049e5c
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_081dbe68
	movs r0, #2
	bl FUN_081df95c
	ldr r0, _081DC328 @ =0x000003DA
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DC322
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
_081DC322:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DC328: .4byte 0x000003DA

	thumb_func_start FUN_081dc32c
FUN_081dc32c: @ 0x081DC32C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xf6
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DC348
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
_081DC348:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081dc350
FUN_081dc350: @ 0x081DC350
	push {r4, lr}
	adds r3, r0, #0
	movs r0, #0xf5
	lsls r0, r0, #2
	adds r4, r3, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DC36C
	ldr r1, _081DC388 @ =0x000003D6
	adds r0, r3, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r4]
_081DC36C:
	ldr r0, _081DC388 @ =0x000003D6
	adds r4, r3, r0
	ldrh r0, [r4]
	cmp r0, #0xa
	bne _081DC37C
	adds r0, r3, #0
	bl FUN_081dc2e0
_081DC37C:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DC388: .4byte 0x000003D6

	thumb_func_start FUN_081dc38c
FUN_081dc38c: @ 0x081DC38C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xf5
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081DC3F2
	ldr r2, _081DC42C @ =0x000003D1
	adds r1, r5, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, [r5, #0x18]
	movs r0, #3
	movs r2, #7
	bl FUN_0822c398
	movs r0, #0
	str r0, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r4, #0
	movs r6, #3
_081DC3C4:
	adds r0, r4, #0
	adds r0, #0x19
	adds r1, r4, #0
	adds r1, #0x16
	str r1, [sp]
	str r6, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DC3C4
	ldr r3, _081DC430 @ =0x000003D6
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r4, #0xf5
	lsls r4, r4, #2
	adds r0, r5, r4
	strb r2, [r0]
_081DC3F2:
	bl FUN_0823812c
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	ldr r3, _081DC434 @ =0x03002C68
	ldr r0, [r3]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #0
	beq _081DC40C
	ldrh r2, [r0, #0x1a]
_081DC40C:
	movs r4, #0xf3
	lsls r4, r4, #2
	adds r0, r5, r4
	str r2, [r0]
	movs r4, #0
	adds r2, r1, #0
	movs r0, #0xeb
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r6, #0
_081DC420:
	ldr r0, [r2]
	cmp r0, #0
	bge _081DC438
	strb r6, [r1]
	b _081DC44A
	.align 2, 0
_081DC42C: .4byte 0x000003D1
_081DC430: .4byte 0x000003D6
_081DC434: .4byte 0x03002C68
_081DC438:
	ldr r0, [r3]
	cmp r0, #0
	bne _081DC442
	movs r0, #0
	b _081DC448
_081DC442:
	adds r0, #0x68
	adds r0, r0, r4
	ldrb r0, [r0]
_081DC448:
	strb r0, [r1]
_081DC44A:
	adds r1, #4
	adds r4, #1
	cmp r4, #3
	ble _081DC420
	adds r0, r5, #0
	bl FUN_081dbea0
	adds r0, r5, #0
	bl FUN_081dba78
	adds r0, r5, #0
	bl FUN_081dc100
	movs r1, #0xf3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _081DC484 @ =0x000003D2
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _081DC488 @ =0x000003D6
	adds r1, r5, r3
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081DC48C
	adds r0, #1
	strh r0, [r1]
	b _081DC524
	.align 2, 0
_081DC484: .4byte 0x000003D2
_081DC488: .4byte 0x000003D6
_081DC48C:
	ldr r0, _081DC4A0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DC4A4
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #1
	bne _081DC4A4
	movs r0, #1
	b _081DC4A6
	.align 2, 0
_081DC4A0: .4byte 0x03002C68
_081DC4A4:
	movs r0, #0
_081DC4A6:
	cmp r0, #0
	bne _081DC506
	ldr r0, _081DC4DC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081DC4E4
	ldr r1, _081DC4E0 @ =FUN_081dc350
	movs r2, #1
	movs r4, #0xef
	lsls r4, r4, #2
	adds r0, r5, r4
	str r1, [r0]
	movs r1, #0xf5
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081DC524
	.align 2, 0
_081DC4DC: .4byte 0x030044E0
_081DC4E0: .4byte FUN_081dc350
_081DC4E4:
	movs r4, #0
	movs r5, #3
_081DC4E8:
	adds r0, r4, #0
	adds r0, #0x19
	adds r1, r4, #0
	adds r1, #0x16
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DC4E8
	b _081DC524
_081DC506:
	movs r4, #0
	movs r6, #1
	movs r5, #3
_081DC50C:
	adds r0, r4, #0
	adds r0, #0x19
	str r6, [sp]
	str r5, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DC50C
_081DC524:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dc52c
FUN_081dc52c: @ 0x081DC52C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _081DC548
	bl FUN_08049fa8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081DC55C
_081DC548:
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081DC55A
	adds r0, r4, #0
	bl _call_via_r1
_081DC55A:
	movs r0, #1
_081DC55C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081dc564
FUN_081dc564: @ 0x081DC564
	push {lr}
	bl FUN_081dbe84
	ldr r1, _081DC578 @ =0x030001A8
	movs r0, #0
	str r0, [r1]
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_081DC578: .4byte 0x030001A8

	thumb_func_start FUN_081dc57c
FUN_081dc57c: @ 0x081DC57C
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081DC5A2
	bl FUN_0823d340
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	cmp r0, #0
	bne _081DC5A2
	movs r0, #1
	rsbs r0, r0, #0
	b _081DC622
_081DC5A2:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _081DC62C @ =0x000003DA
	adds r1, r5, r2
	movs r4, #0
	strh r0, [r1]
	movs r0, #0
	bl ClearBGTilemapBuffer
	adds r0, r5, #0
	bl FUN_081db9f4
	adds r0, r5, #0
	bl FUN_081dbc14
	adds r0, r5, #0
	bl FUN_081dbc60
	adds r0, r5, #0
	bl FUN_081dbd74
	adds r0, r5, #0
	bl FUN_081dbce4
	adds r0, r5, #0
	bl FUN_081dba54
	ldr r1, _081DC630 @ =FUN_081dc38c
	movs r2, #0xef
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r0, #0xf5
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xf4
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081DC61C
	movs r0, #4
	str r0, [sp]
	ldr r0, _081DC634 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_081DC61C:
	ldr r0, _081DC638 @ =0x030001A8
	str r5, [r0]
	movs r0, #1
_081DC622:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DC62C: .4byte 0x000003DA
_081DC630: .4byte FUN_081dc38c
_081DC634: .4byte 0x0000FFFF
_081DC638: .4byte 0x030001A8

	thumb_func_start FUN_081dc63c
FUN_081dc63c: @ 0x081DC63C
	push {r4, lr}
	ldr r0, _081DC674 @ =0x030001A8
	ldr r0, [r0]
	cmp r0, #0
	bne _081DC682
	movs r1, #0xf7
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081DC680
	ldr r1, _081DC678 @ =FUN_081dc52c
	ldr r2, _081DC67C @ =FUN_081dc564
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081dc57c
	cmp r0, #0
	bge _081DC680
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081DC682
	.align 2, 0
_081DC674: .4byte 0x030001A8
_081DC678: .4byte FUN_081dc52c
_081DC67C: .4byte FUN_081dc564
_081DC680:
	adds r0, r4, #0
_081DC682:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081dc688
FUN_081dc688: @ 0x081DC688
	ldr r1, _081DC690 @ =0x030001A8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081DC690: .4byte 0x030001A8

	thumb_func_start FUN_081dc694
FUN_081dc694: @ 0x081DC694
	push {r4, lr}
	ldr r4, _081DC6CC @ =0x030001A8
	ldr r0, [r4]
	cmp r0, #0
	beq _081DC6C4
	bl FUN_081dbe68
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	bl FUN_08049e5c
	ldr r0, [r4]
	bl KillEntity
_081DC6C4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DC6CC: .4byte 0x030001A8

	thumb_func_start FUN_081dc6d0
FUN_081dc6d0: @ 0x081DC6D0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r4, _081DC768 @ =0x0000C091
	ldr r1, _081DC76C @ =0x0000CD91
	adds r0, r4, #0
	bl GetFile
	ldr r1, _081DC770 @ =0x0000082C
	adds r5, r6, r1
	str r0, [r5]
	ldr r1, _081DC774 @ =0x0000A413
	adds r0, r4, #0
	bl GetFile
	movs r1, #0x83
	lsls r1, r1, #4
	adds r1, r1, r6
	mov r8, r1
	str r0, [r1]
	movs r0, #9
	str r0, [sp, #0xc]
	ldr r2, [r5]
	movs r4, #0
	str r4, [sp]
	movs r5, #1
	str r5, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	movs r0, #3
	str r0, [sp, #0xc]
	mov r1, r8
	ldr r2, [r1]
	str r4, [sp]
	str r5, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _081DC778 @ =0x000092B3
	ldr r1, _081DC77C @ =0x000026BB
	bl GetFile
	ldr r1, _081DC780 @ =0x00000834
	adds r6, r6, r1
	adds r0, #0x14
	str r0, [r6]
	ldr r1, _081DC784 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DC768: .4byte 0x0000C091
_081DC76C: .4byte 0x0000CD91
_081DC770: .4byte 0x0000082C
_081DC774: .4byte 0x0000A413
_081DC778: .4byte 0x000092B3
_081DC77C: .4byte 0x000026BB
_081DC780: .4byte 0x00000834
_081DC784: .4byte 0x03004250

	thumb_func_start FUN_081dc788
FUN_081dc788: @ 0x081DC788
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0xc
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	ldr r2, _081DC808 @ =0x00000844
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0xc
	movs r1, #8
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	ldr r2, _081DC80C @ =0x00000848
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0xc
	movs r1, #0xc
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	ldr r2, _081DC810 @ =0x0000084C
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0xc
	movs r1, #0x10
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	movs r2, #0x85
	lsls r2, r2, #4
	adds r1, r6, r2
	str r0, [r1]
	movs r5, #0
_081DC7D8:
	lsls r0, r5, #2
	ldr r1, _081DC808 @ =0x00000844
	adds r4, r6, r1
	adds r4, r4, r0
	ldr r0, [r4]
	ldr r2, _081DC814 @ =0x0000083C
	adds r1, r6, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	adds r1, r5, #0
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a210
	adds r5, #1
	cmp r5, #3
	ble _081DC7D8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DC808: .4byte 0x00000844
_081DC80C: .4byte 0x00000848
_081DC810: .4byte 0x0000084C
_081DC814: .4byte 0x0000083C

	thumb_func_start FUN_081dc818
FUN_081dc818: @ 0x081DC818
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldr r1, _081DC874 @ =0x000006FC
	adds r0, r3, r1
	adds r0, r0, r5
	ldrb r1, [r0]
	ldr r0, _081DC878 @ =0x03002C68
	ldr r2, [r0]
	cmp r2, #0
	beq _081DC86C
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r6, r2, r0
	cmp r6, #0
	beq _081DC86C
	lsls r0, r5, #2
	ldr r2, _081DC87C @ =0x00000844
	adds r4, r3, r2
	adds r4, r4, r0
	ldr r0, [r4]
	subs r2, #8
	adds r1, r3, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	adds r1, r5, #0
	bl FUN_0804a2f8
	ldr r0, [r4]
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0804a40c
	ldr r0, [r4]
	bl FUN_0804a1f0
_081DC86C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DC874: .4byte 0x000006FC
_081DC878: .4byte 0x03002C68
_081DC87C: .4byte 0x00000844

	thumb_func_start FUN_081dc880
FUN_081dc880: @ 0x081DC880
	push {r4, r5, lr}
	ldr r1, _081DC89C @ =0x00000844
	adds r5, r0, r1
	movs r4, #3
_081DC888:
	ldm r5!, {r0}
	bl FUN_0804a210
	subs r4, #1
	cmp r4, #0
	bge _081DC888
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DC89C: .4byte 0x00000844

	thumb_func_start FUN_081dc8a0
FUN_081dc8a0: @ 0x081DC8A0
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _081DC8BC @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	movs r3, #0x1f
	ands r1, r3
	lsls r1, r1, #1
	adds r0, r0, r1
	ands r2, r3
	lsls r2, r2, #6
	adds r0, r0, r2
	bx lr
	.align 2, 0
_081DC8BC: .4byte 0x03003ED0

	thumb_func_start FUN_081dc8c0
FUN_081dc8c0: @ 0x081DC8C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	mov sl, r1
	movs r7, #0
	movs r5, #0
	mov r0, sl
	lsls r0, r0, #2
	str r0, [sp, #8]
	ldr r1, [sp]
	ldr r2, _081DC984 @ =0x000006FC
	adds r0, r1, r2
	add r0, sl
	mov sb, r0
	mov r0, sl
	lsls r0, r0, #5
	mov r8, r0
_081DC8EA:
	ldr r4, _081DC988 @ =0x085AE248
	add r4, r8
	movs r6, #6
_081DC8F0:
	ldrh r1, [r4]
	ldrh r2, [r4, #2]
	movs r0, #3
	bl FUN_081dc8a0
	adds r3, r0, #0
	lsls r1, r7, #1
	mov r2, sb
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r1, r1, r0
	ldr r0, _081DC98C @ =0x085AE208
	adds r1, r1, r0
	ldrh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	adds r7, #1
	adds r4, #4
	subs r6, #2
	cmp r6, #0
	bge _081DC8F0
	movs r0, #0x10
	add r8, r0
	adds r5, #1
	cmp r5, #1
	ble _081DC8EA
	movs r7, #0
	movs r5, #0
	ldr r0, [sp, #8]
	add r0, sl
	lsls r0, r0, #3
	str r0, [sp, #4]
	ldr r1, [sp]
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r1, r2
	add r0, sl
	mov r8, r0
_081DC942:
	adds r0, r5, #1
	mov sb, r0
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	ldr r1, [sp, #4]
	adds r0, r0, r1
	ldr r2, _081DC990 @ =0x085AE32C
	adds r4, r0, r2
	movs r6, #8
_081DC956:
	ldrh r1, [r4]
	ldrh r2, [r4, #2]
	movs r0, #3
	bl FUN_081dc8a0
	adds r3, r0, #0
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne _081DC998
	lsls r2, r7, #1
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r0, _081DC994 @ =0x085AE2C8
	adds r2, r2, r0
	ldrh r0, [r2]
	movs r2, #0xc0
	lsls r2, r2, #6
	b _081DC9B0
	.align 2, 0
_081DC984: .4byte 0x000006FC
_081DC988: .4byte 0x085AE248
_081DC98C: .4byte 0x085AE208
_081DC990: .4byte 0x085AE32C
_081DC994: .4byte 0x085AE2C8
_081DC998:
	lsls r2, r7, #1
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r1, _081DC9D8 @ =0x085AE2C8
	adds r2, r2, r1
	ldrh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #6
_081DC9B0:
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	adds r7, #1
	adds r4, #4
	subs r6, #2
	cmp r6, #0
	bge _081DC956
	mov r5, sb
	cmp r5, #1
	ble _081DC942
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DC9D8: .4byte 0x085AE2C8

	thumb_func_start FUN_081dc9dc
FUN_081dc9dc: @ 0x081DC9DC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r4, _081DCA94 @ =0x0000CB05
	ldr r1, _081DCA98 @ =0x0000DCC1
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r0, r6, r2
	str r1, [r0]
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r0, r6, r3
	bl OpenMainSpriteFile
	ldr r1, _081DCA9C @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	ldr r2, _081DCAA0 @ =0x000006BC
	adds r0, r6, r2
	str r1, [r0]
	movs r3, #0xd3
	lsls r3, r3, #3
	adds r0, r6, r3
	bl OpenMainSpriteFile
	movs r7, #0
	movs r4, #0
	adds r5, r6, #0
	adds r5, #0x18
_081DCA22:
	lsls r0, r7, #1
	movs r2, #0xd8
	lsls r2, r2, #3
	adds r1, r6, r2
	adds r1, r1, r0
	strh r4, [r1]
	ldrh r2, [r1]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r5, #0
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r1, r6, r3
	movs r3, #0x10
	bl MainSprite_Add
	adds r2, r0, #0
	cmp r2, #0
	bne _081DCA8C
	adds r5, #0x60
	adds r7, #1
	cmp r7, #0xf
	ble _081DCA22
	movs r0, #0xdc
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r0, #4
	strh r0, [r1]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r3, #0xd3
	lsls r3, r3, #3
	adds r1, r6, r3
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	movs r2, #4
	movs r3, #0x10
	bl MainSprite_Add
	cmp r0, #0
	bne _081DCA8C
	movs r1, #0xc4
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_081DCA8C:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCA94: .4byte 0x0000CB05
_081DCA98: .4byte 0x0000DCC1
_081DCA9C: .4byte 0x0000B343
_081DCAA0: .4byte 0x000006BC

	thumb_func_start FUN_081dcaa4
FUN_081dcaa4: @ 0x081DCAA4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x97
	lsls r0, r0, #3
	adds r4, r7, r0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r3, r7, r1
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r5, #0xd8
	adds r1, r7, #0
	movs r6, #3
_081DCAC0:
	strh r5, [r1, #0x38]
	strh r5, [r2, #0x38]
	strh r5, [r3, #0x38]
	strh r5, [r4]
	movs r0, #0x20
	strh r0, [r1, #0x3a]
	movs r0, #0x40
	strh r0, [r2, #0x3a]
	movs r0, #0x60
	strh r0, [r3, #0x3a]
	movs r0, #0x80
	strh r0, [r4, #2]
	adds r4, #0x60
	adds r3, #0x60
	adds r2, #0x60
	subs r5, #8
	adds r1, #0x60
	subs r6, #1
	cmp r6, #0
	bge _081DCAC0
	ldr r1, _081DCB44 @ =0x00000859
	adds r0, r7, r1
	movs r6, #0
	ldrsb r6, [r0, r6]
	cmp r6, #3
	bgt _081DCB2C
	movs r3, #1
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #7
	adds r1, r0, #0
	adds r1, #0xe0
	adds r1, r1, r7
	adds r0, #0x20
	adds r2, r0, r7
	movs r4, #0xc0
	lsls r4, r4, #1
_081DCB0A:
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldr r0, [r2, #0x60]
	orrs r0, r3
	str r0, [r2, #0x60]
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	ldr r0, [r1, #0x60]
	orrs r0, r3
	str r0, [r1, #0x60]
	adds r1, r1, r4
	adds r2, r2, r4
	adds r6, #1
	cmp r6, #3
	ble _081DCB0A
_081DCB2C:
	movs r0, #0xc7
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081DCB48 @ =0x0000FFF8
	strh r0, [r1]
	ldr r0, _081DCB4C @ =0x0000063A
	adds r1, r7, r0
	ldr r0, _081DCB50 @ =0x0000FFC8
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCB44: .4byte 0x00000859
_081DCB48: .4byte 0x0000FFF8
_081DCB4C: .4byte 0x0000063A
_081DCB50: .4byte 0x0000FFC8

	thumb_func_start FUN_081dcb54
FUN_081dcb54: @ 0x081DCB54
	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0x20
	movs r2, #0x10
_081DCB5E:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081DCB5E
	pop {r0}
	bx r0

	thumb_func_start FUN_081dcb70
FUN_081dcb70: @ 0x081DCB70
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #0x10
_081DCB78:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081DCB78
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dcb8c
FUN_081dcb8c: @ 0x081DCB8C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	lsls r2, r1, #1
	ldr r3, _081DCC3C @ =0x000006E4
	adds r0, r6, r3
	adds r0, r0, r2
	ldrh r5, [r0]
	lsls r7, r1, #2
	movs r2, #0
	ldr r0, _081DCC40 @ =0x000003E7
	cmp r5, r0
	ble _081DCBAE
	ldr r1, _081DCC44 @ =0xFFFFFC18
_081DCBA6:
	adds r2, #1
	adds r5, r5, r1
	cmp r5, r0
	bgt _081DCBA6
_081DCBAE:
	lsls r4, r7, #1
	adds r0, r4, r7
	lsls r0, r0, #5
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r6, r0
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r5, #0x63
	ble _081DCBD8
_081DCBD0:
	adds r2, #1
	subs r5, #0x64
	cmp r5, #0x63
	bgt _081DCBD0
_081DCBD8:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0xd8
	adds r0, r6, r0
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r5, #9
	ble _081DCBFC
_081DCBF4:
	adds r2, #1
	subs r5, #0xa
	cmp r5, #9
	bgt _081DCBF4
_081DCBFC:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0x78
	adds r0, r6, r0
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r5, #0
	ble _081DCC20
_081DCC18:
	adds r2, #1
	subs r5, #1
	cmp r5, #0
	bgt _081DCC18
_081DCC20:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0x18
	adds r0, r6, r0
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCC3C: .4byte 0x000006E4
_081DCC40: .4byte 0x000003E7
_081DCC44: .4byte 0xFFFFFC18

	thumb_func_start FUN_081dcc48
FUN_081dcc48: @ 0x081DCC48
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	mov r8, r1
	ldr r0, _081DCCD4 @ =0x00000856
	add r0, ip
	ldrh r0, [r0]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r7, r0, #2
	ldr r4, _081DCCD8 @ =0x030046B4
	ldr r1, [r4]
	adds r1, #1
	ldr r5, _081DCCDC @ =0x000003FF
	ands r1, r5
	str r1, [r4]
	ldr r6, _081DCCE0 @ =0x085B0200
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	movs r3, #7
	ands r2, r3
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r3
	movs r2, #0x64
	muls r0, r2, r0
	adds r7, r7, r0
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	ands r1, r3
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r7, r7, r0
	ldr r0, _081DCCE4 @ =0x0000270F
	cmp r7, r0
	ble _081DCCB6
	adds r7, r0, #0
_081DCCB6:
	mov r0, r8
	lsls r1, r0, #1
	ldr r0, _081DCCE8 @ =0x000006E4
	add r0, ip
	adds r0, r0, r1
	strh r7, [r0]
	mov r0, ip
	mov r1, r8
	bl FUN_081dcb8c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCCD4: .4byte 0x00000856
_081DCCD8: .4byte 0x030046B4
_081DCCDC: .4byte 0x000003FF
_081DCCE0: .4byte 0x085B0200
_081DCCE4: .4byte 0x0000270F
_081DCCE8: .4byte 0x000006E4

	thumb_func_start FUN_081dccec
FUN_081dccec: @ 0x081DCCEC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _081DCD10 @ =0x00000856
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _081DCD06
	ldr r0, _081DCD14 @ =0x000002A5
	bl PlaySound_082406e0
_081DCD06:
	movs r4, #0
	ldr r2, _081DCD18 @ =0x00000859
	adds r0, r5, r2
	b _081DCD38
	.align 2, 0
_081DCD10: .4byte 0x00000856
_081DCD14: .4byte 0x000002A5
_081DCD18: .4byte 0x00000859
_081DCD1C:
	lsls r0, r4, #1
	ldr r2, _081DCD48 @ =0x000006EC
	adds r1, r5, r2
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DCD32
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_081dcc48
_081DCD32:
	adds r4, #1
	ldr r1, _081DCD4C @ =0x00000859
	adds r0, r5, r1
_081DCD38:
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r4, r0
	blt _081DCD1C
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DCD48: .4byte 0x000006EC
_081DCD4C: .4byte 0x00000859

	thumb_func_start FUN_081dcd50
FUN_081dcd50: @ 0x081DCD50
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081DCDAC @ =0x00000834
	adds r4, r5, r0
	ldr r0, [r4]
	adds r0, #0x40
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r2, #0x10
	bl CpuSet
	ldr r0, [r4]
	adds r0, #0x40
	movs r2, #0xe5
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r2, #0x10
	bl CpuSet
	ldr r0, [r4]
	adds r0, #0x40
	movs r2, #0xe9
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r2, #0x10
	bl CpuSet
	ldr r1, _081DCDB0 @ =0x00000704
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _081DCDB4 @ =0x00000828
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _081DCDB8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DCDBC
	movs r0, #1
	rsbs r0, r0, #0
	b _081DCDC0
	.align 2, 0
_081DCDAC: .4byte 0x00000834
_081DCDB0: .4byte 0x00000704
_081DCDB4: .4byte 0x00000828
_081DCDB8: .4byte 0x03002C68
_081DCDBC:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
_081DCDC0:
	cmp r0, #1
	beq _081DCDD2
	cmp r0, #1
	ble _081DCDEC
	cmp r0, #2
	beq _081DCDDC
	cmp r0, #3
	beq _081DCDE2
	b _081DCDEC
_081DCDD2:
	ldr r0, _081DCDD8 @ =0x0000075C
	adds r1, r5, r0
	b _081DCDF2
	.align 2, 0
_081DCDD8: .4byte 0x0000075C
_081DCDDC:
	movs r2, #0xec
	lsls r2, r2, #3
	b _081DCDF0
_081DCDE2:
	ldr r0, _081DCDE8 @ =0x00000764
	adds r1, r5, r0
	b _081DCDF2
	.align 2, 0
_081DCDE8: .4byte 0x00000764
_081DCDEC:
	movs r2, #0xeb
	lsls r2, r2, #3
_081DCDF0:
	adds r1, r5, r2
_081DCDF2:
	ldr r0, _081DCE0C @ =0x00007FFF
	strh r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, _081DCE10 @ =0x03004290
	movs r2, #0x10
	bl CpuSet
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DCE0C: .4byte 0x00007FFF
_081DCE10: .4byte 0x03004290

	thumb_func_start FUN_081dce14
FUN_081dce14: @ 0x081DCE14
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sl, r1
	movs r0, #0
	mov sb, r0
	movs r1, #0xf
	str r1, [sp]
_081DCE2C:
	ldr r2, _081DCE40 @ =0x00000828
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _081DCE44
	movs r3, #0xe5
	lsls r3, r3, #3
	adds r0, r7, r3
	b _081DCE4A
	.align 2, 0
_081DCE40: .4byte 0x00000828
_081DCE44:
	movs r5, #0xe9
	lsls r5, r5, #3
	adds r0, r7, r5
_081DCE4A:
	add r0, sb
	ldrh r1, [r0]
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r0, r7, r2
	add r0, sb
	ldrh r4, [r0]
	movs r3, #0xf9
	lsls r3, r3, #3
	adds r2, r7, r3
	add r2, sb
	adds r0, r1, #0
	movs r5, #0x1f
	ands r0, r5
	mov r8, r4
	mov r3, r8
	ands r3, r5
	mov r8, r3
	subs r0, r0, r3
	lsls r0, r0, #5
	strh r0, [r2]
	movs r5, #0xfd
	lsls r5, r5, #3
	adds r6, r7, r5
	add r6, sb
	asrs r0, r1, #5
	movs r3, #0x1f
	ands r0, r3
	asrs r3, r4, #5
	movs r5, #0x1f
	ands r3, r5
	subs r0, r0, r3
	lsls r0, r0, #5
	strh r0, [r6]
	ldr r0, _081DCF28 @ =0x00000808
	adds r5, r7, r0
	add r5, sb
	asrs r0, r1, #0xa
	movs r1, #0x1f
	ands r0, r1
	asrs r4, r4, #0xa
	ands r4, r1
	subs r0, r0, r4
	lsls r0, r0, #5
	strh r0, [r5]
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r1, sl
	str r2, [sp, #4]
	str r3, [sp, #8]
	bl Div
	ldr r2, [sp, #4]
	strh r0, [r2]
	movs r2, #0
	ldrsh r0, [r6, r2]
	mov r1, sl
	bl Div
	strh r0, [r6]
	movs r1, #0
	ldrsh r0, [r5, r1]
	mov r1, sl
	bl Div
	strh r0, [r5]
	movs r2, #0xed
	lsls r2, r2, #3
	adds r0, r7, r2
	add r0, sb
	mov r5, r8
	lsls r5, r5, #5
	strh r5, [r0]
	movs r1, #0xf1
	lsls r1, r1, #3
	adds r0, r7, r1
	add r0, sb
	ldr r3, [sp, #8]
	lsls r3, r3, #5
	strh r3, [r0]
	adds r2, #0x40
	adds r0, r7, r2
	add r0, sb
	lsls r4, r4, #5
	strh r4, [r0]
	movs r3, #2
	add sb, r3
	ldr r5, [sp]
	subs r5, #1
	str r5, [sp]
	cmp r5, #0
	bge _081DCE2C
	ldr r0, _081DCF2C @ =0x00000828
	adds r2, r7, r0
	ldrh r0, [r2]
	movs r1, #1
	eors r0, r1
	strh r0, [r2]
	ldr r1, _081DCF30 @ =0x00000706
	adds r0, r7, r1
	mov r2, sl
	strh r2, [r0]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCF28: .4byte 0x00000808
_081DCF2C: .4byte 0x00000828
_081DCF30: .4byte 0x00000706

	thumb_func_start FUN_081dcf34
FUN_081dcf34: @ 0x081DCF34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _081DCF68 @ =0x0000082A
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _081DCF6C
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _081DCF5A
	b _081DD060
_081DCF5A:
	adds r0, r7, #0
	movs r1, #0x20
	bl FUN_081dce14
	strh r5, [r4]
	b _081DD060
	.align 2, 0
_081DCF68: .4byte 0x0000082A
_081DCF6C:
	ldr r1, _081DCFB4 @ =0x03004290
	mov sl, r1
	movs r2, #0xf1
	lsls r2, r2, #3
	adds r3, r7, r2
	movs r0, #0xed
	lsls r0, r0, #3
	adds r5, r7, r0
	movs r1, #0
	mov r8, r1
	movs r2, #0xf
	mov sb, r2
	adds r0, #0x60
	adds r6, r7, r0
_081DCF88:
	ldrh r0, [r6]
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r6, #0x20]
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	ldr r1, _081DCFB8 @ =0x00000808
	adds r0, r7, r1
	add r0, r8
	ldrh r0, [r0]
	ldrh r2, [r3, #0x20]
	adds r0, r0, r2
	strh r0, [r3, #0x20]
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	blt _081DCFBC
	asrs r0, r0, #5
	b _081DCFC2
	.align 2, 0
_081DCFB4: .4byte 0x03004290
_081DCFB8: .4byte 0x00000808
_081DCFBC:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081DCFC2:
	mov ip, r0
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	blt _081DCFD0
	asrs r0, r0, #5
	b _081DCFD6
_081DCFD0:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081DCFD6:
	adds r1, r0, #0
	movs r2, #0x20
	ldrsh r0, [r3, r2]
	cmp r0, #0
	blt _081DCFE4
	asrs r0, r0, #5
	b _081DCFEA
_081DCFE4:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081DCFEA:
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r4, r7, r2
	mov r2, r8
	adds r2, r4, r2
	str r2, [sp]
	lsls r1, r1, #5
	mov r2, ip
	orrs r1, r2
	lsls r0, r0, #0xa
	orrs r0, r1
	ldr r1, [sp]
	strh r0, [r1]
	adds r3, #2
	adds r5, #2
	adds r6, #2
	movs r2, #2
	add r8, r2
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	cmp r1, #0
	bge _081DCF88
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0x10
	bl CpuSet
	ldr r2, _081DD048 @ =0x00000706
	adds r1, r7, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081DD060
	ldr r1, _081DD04C @ =0x00000828
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081DD054
	ldr r2, _081DD050 @ =0x0000082A
	adds r1, r7, r2
	movs r0, #0x14
	strh r0, [r1]
	b _081DD05C
	.align 2, 0
_081DD048: .4byte 0x00000706
_081DD04C: .4byte 0x00000828
_081DD050: .4byte 0x0000082A
_081DD054:
	adds r0, r7, #0
	movs r1, #0x20
	bl FUN_081dce14
_081DD05C:
	movs r0, #1
	b _081DD062
_081DD060:
	movs r0, #0
_081DD062:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081dd074
FUN_081dd074: @ 0x081DD074
	push {r4, r5, r6, lr}
	sub sp, #0x20
	mov r6, sp
	lsls r4, r1, #1
	ldr r3, _081DD0B0 @ =0x000006F4
	adds r5, r0, r3
	adds r4, r5, r4
	ldrh r3, [r4]
	strh r3, [r6, #0x10]
	mov r3, sp
	ldr r6, _081DD0B4 @ =0x000006FC
	adds r0, r0, r6
	adds r1, r0, r1
	ldrb r6, [r1]
	strb r6, [r3, #0x18]
	lsls r3, r2, #1
	adds r5, r5, r3
	ldrh r3, [r5]
	strh r3, [r4]
	adds r0, r0, r2
	ldrb r2, [r0]
	strb r2, [r1]
	mov r1, sp
	ldrh r1, [r1, #0x10]
	strh r1, [r5]
	strb r6, [r0]
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DD0B0: .4byte 0x000006F4
_081DD0B4: .4byte 0x000006FC

	thumb_func_start FUN_081dd0b8
FUN_081dd0b8: @ 0x081DD0B8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0
	b _081DD106
_081DD0C0:
	movs r2, #0
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	adds r7, r1, #1
	cmp r2, r0
	bge _081DD104
	ldr r0, _081DD11C @ =0x000006F4
	adds r5, r6, r0
_081DD0D6:
	lsls r0, r2, #1
	adds r0, r5, r0
	adds r4, r2, #1
	lsls r1, r4, #1
	adds r1, r5, r1
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _081DD0F2
	adds r0, r6, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_081dd074
_081DD0F2:
	adds r2, r4, #0
	ldr r1, _081DD120 @ =0x00000859
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	cmp r2, r0
	blt _081DD0D6
_081DD104:
	adds r1, r7, #0
_081DD106:
	ldr r3, _081DD120 @ =0x00000859
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _081DD0C0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DD11C: .4byte 0x000006F4
_081DD120: .4byte 0x00000859

	thumb_func_start FUN_081dd124
FUN_081dd124: @ 0x081DD124
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	movs r4, #0
	movs r7, #1
	movs r3, #0
	ldr r0, _081DD188 @ =0x00000859
	adds r1, r6, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	subs r0, #1
	cmp r4, r0
	bge _081DD1A8
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r2, r2, r6
	mov sb, r2
	ldr r0, _081DD18C @ =0x000006EC
	adds r0, r0, r6
	mov r8, r0
	ldr r2, _081DD190 @ =0x000006F4
	adds r5, r6, r2
	ldr r0, _081DD194 @ =0x085AE3CC
	mov sl, r0
	mov ip, r1
_081DD15C:
	mov r1, sb
	adds r0, r1, r3
	strb r4, [r0]
	lsls r1, r3, #1
	mov r0, r8
	adds r2, r0, r1
	lsls r0, r4, #1
	add r0, sl
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, r5, r1
	adds r2, r3, #1
	lsls r0, r2, #1
	adds r0, r5, r0
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	beq _081DD198
	adds r4, r4, r7
	movs r7, #1
	b _081DD19A
	.align 2, 0
_081DD188: .4byte 0x00000859
_081DD18C: .4byte 0x000006EC
_081DD190: .4byte 0x000006F4
_081DD194: .4byte 0x085AE3CC
_081DD198:
	adds r7, #1
_081DD19A:
	adds r3, r2, #0
	mov r1, ip
	movs r0, #0
	ldrsb r0, [r1, r0]
	subs r0, #1
	cmp r3, r0
	blt _081DD15C
_081DD1A8:
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r6, r2
	adds r0, r0, r3
	strb r4, [r0]
	lsls r0, r3, #1
	subs r2, #0x14
	adds r1, r6, r2
	adds r1, r1, r0
	lsls r0, r4, #1
	ldr r2, _081DD1D4 @ =0x085AE3CC
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DD1D4: .4byte 0x085AE3CC

	thumb_func_start FUN_081dd1d8
FUN_081dd1d8: @ 0x081DD1D8
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	b _081DD232
_081DD1E0:
	lsls r2, r5, #1
	ldr r3, _081DD248 @ =0x000006EC
	adds r0, r4, r3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DD230
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081DD230
	ldr r0, _081DD24C @ =0x000006E4
	adds r1, r4, r0
	adds r1, r1, r2
	adds r3, #8
	adds r0, r4, r3
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_081dcb8c
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_081dc8c0
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_081dc818
	ldr r0, _081DD250 @ =0x00000167
	bl PlaySound_082406e0
	ldr r0, _081DD254 @ =0x00000858
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_081DD230:
	adds r5, #1
_081DD232:
	ldr r1, _081DD258 @ =0x00000859
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r5, r0
	blt _081DD1E0
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DD248: .4byte 0x000006EC
_081DD24C: .4byte 0x000006E4
_081DD250: .4byte 0x00000167
_081DD254: .4byte 0x00000858
_081DD258: .4byte 0x00000859

	thumb_func_start FUN_081dd25c
FUN_081dd25c: @ 0x081DD25C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081DD270 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DD274
	movs r4, #1
	rsbs r4, r4, #0
	b _081DD278
	.align 2, 0
_081DD270: .4byte 0x03002C68
_081DD274:
	movs r1, #0x18
	ldrsh r4, [r0, r1]
_081DD278:
	movs r2, #0
	ldr r0, _081DD2B4 @ =0x00000859
	adds r1, r5, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	bge _081DD2D4
	adds r3, r1, #0
	ldr r0, _081DD2B8 @ =0x000006FC
	adds r1, r5, r0
	ldr r5, _081DD2BC @ =0x030046A0
_081DD28E:
	ldrb r0, [r1]
	cmp r0, r4
	bne _081DD2C8
	ldrb r0, [r1, #4]
	cmp r0, #0
	bne _081DD2D4
	ldr r0, [r5]
	ldr r2, _081DD2C0 @ =0x00000916
	adds r1, r0, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r0, #1
	ldr r2, _081DD2C4 @ =0x0000270F
	cmp r0, r2
	ble _081DD2AE
	adds r0, r2, #0
_081DD2AE:
	strh r0, [r1]
	b _081DD2D4
	.align 2, 0
_081DD2B4: .4byte 0x00000859
_081DD2B8: .4byte 0x000006FC
_081DD2BC: .4byte 0x030046A0
_081DD2C0: .4byte 0x00000916
_081DD2C4: .4byte 0x0000270F
_081DD2C8:
	adds r1, #1
	adds r2, #1
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r2, r0
	blt _081DD28E
_081DD2D4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081dd2dc
FUN_081dd2dc: @ 0x081DD2DC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r3, #0
	ldr r0, _081DD308 @ =0x00000859
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r3, r0
	bge _081DD328
	ldr r0, _081DD30C @ =0x03002C68
	ldr r5, [r0]
	adds r6, r1, #0
	ldr r7, _081DD310 @ =0x000006F4
	adds r2, r4, r7
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r5, r0
_081DD2FE:
	cmp r5, #0
	bne _081DD314
	movs r0, #0
	b _081DD318
	.align 2, 0
_081DD308: .4byte 0x00000859
_081DD30C: .4byte 0x03002C68
_081DD310: .4byte 0x000006F4
_081DD314:
	movs r7, #0
	ldrsh r0, [r1, r7]
_081DD318:
	strh r0, [r2]
	adds r2, #2
	adds r1, #2
	adds r3, #1
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r3, r0
	blt _081DD2FE
_081DD328:
	ldr r0, _081DD360 @ =0x000006FC
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r7, _081DD364 @ =0x000006FD
	adds r1, r4, r7
	movs r0, #1
	strb r0, [r1]
	ldr r0, _081DD368 @ =0x000006FE
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	adds r7, #2
	adds r1, r4, r7
	movs r0, #3
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_081dd0b8
	adds r0, r4, #0
	bl FUN_081dd124
	adds r0, r4, #0
	bl FUN_081dd25c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DD360: .4byte 0x000006FC
_081DD364: .4byte 0x000006FD
_081DD368: .4byte 0x000006FE

	thumb_func_start FUN_081dd36c
FUN_081dd36c: @ 0x081DD36C
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _081DD37C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DD388
	b _081DD3BA
	.align 2, 0
_081DD37C: .4byte 0x03002C68
_081DD380:
	movs r0, #0xa9
	bl sound_08240264
	b _081DD3BA
_081DD388:
	movs r2, #0x18
	ldrsh r3, [r0, r2]
	cmp r3, #0
	blt _081DD3BA
	movs r2, #0
	ldr r4, _081DD3C0 @ =0x00000859
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r2, r0
	bge _081DD3BA
	adds r4, r0, #0
	ldr r0, _081DD3C4 @ =0x000006FC
	adds r1, r1, r0
_081DD3A6:
	ldrb r0, [r1]
	cmp r0, r3
	bne _081DD3B2
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081DD380
_081DD3B2:
	adds r1, #1
	adds r2, #1
	cmp r2, r4
	blt _081DD3A6
_081DD3BA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DD3C0: .4byte 0x00000859
_081DD3C4: .4byte 0x000006FC

	thumb_func_start FUN_081dd3c8
FUN_081dd3c8: @ 0x081DD3C8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081DD428 @ =0x00000855
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DD3E8
	movs r0, #1
	bl FUN_081df8f0
	ldr r1, _081DD42C @ =0x00000856
	adds r0, r5, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r4]
_081DD3E8:
	ldr r0, _081DD42C @ =0x00000856
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r1, r0, #0
	cmp r1, #9
	bls _081DD406
	cmp r1, #0xa
	bne _081DD40A
	ldr r1, _081DD430 @ =0x00000844
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #5
	bl FUN_0804a2f8
	ldrh r0, [r4]
_081DD406:
	adds r0, #1
	strh r0, [r4]
_081DD40A:
	bl FUN_081dfa04
	cmp r0, #0x11
	beq _081DD416
	cmp r0, #0x14
	bne _081DD422
_081DD416:
	adds r0, r5, #0
	bl FUN_081dcb54
	adds r0, r5, #0
	bl KillEntity
_081DD422:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DD428: .4byte 0x00000855
_081DD42C: .4byte 0x00000856
_081DD430: .4byte 0x00000844

	thumb_func_start FUN_081dd434
FUN_081dd434: @ 0x081DD434
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081DD518 @ =0x00000855
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081DD4E0
	adds r0, r6, #0
	bl FUN_081dc880
	adds r0, r6, #0
	bl FUN_081dcb54
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r1, _081DD51C @ =0x00000844
	adds r4, r6, r1
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #7
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r2, _081DD520 @ =0x0000083C
	adds r1, r6, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #4
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r2, r6, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _081DD524 @ =0x0000085A
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081DD528 @ =0x00000856
	adds r0, r6, r1
	movs r1, #0
	strh r5, [r0]
	strb r1, [r7]
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r6, r2
	adds r3, #0x78
	adds r1, r6, r3
	adds r3, #0x48
	adds r2, r6, r3
	ldrh r2, [r2]
	str r5, [sp]
	movs r3, #1
	bl MainSprite_SetAnim
_081DD4E0:
	ldr r0, _081DD52C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _081DD530
	ldr r0, _081DD524 @ =0x0000085A
	adds r1, r6, r0
	ldrb r5, [r1]
	cmp r5, #0
	beq _081DD4FC
	b _081DD610
_081DD4FC:
	movs r2, #0xdc
	lsls r2, r2, #3
	adds r4, r6, r2
	movs r0, #4
	strh r0, [r4]
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r0, r6, r3
	b _081DD55C
	.align 2, 0
_081DD518: .4byte 0x00000855
_081DD51C: .4byte 0x00000844
_081DD520: .4byte 0x0000083C
_081DD524: .4byte 0x0000085A
_081DD528: .4byte 0x00000856
_081DD52C: .4byte 0x030044E0
_081DD530:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081DD574
	ldr r3, _081DD570 @ =0x0000085A
	adds r2, r6, r3
	ldrb r0, [r2]
	cmp r0, #0
	beq _081DD610
	movs r0, #0xdc
	lsls r0, r0, #3
	adds r4, r6, r0
	movs r1, #0
	movs r0, #5
	strh r0, [r4]
	strb r1, [r2]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r6, r1
_081DD55C:
	movs r2, #0xd3
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r2, [r4]
	str r5, [sp]
	movs r3, #1
	bl MainSprite_SetAnim
	b _081DD610
	.align 2, 0
_081DD570: .4byte 0x0000085A
_081DD574:
	movs r5, #1
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _081DD5CC
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081DD5BC @ =0x0000085A
	adds r4, r6, r0
	ldrb r0, [r4]
	bl FUN_081df8a0
	ldr r1, _081DD5C0 @ =FUN_081dd3c8
	movs r2, #4
	ldr r3, _081DD5C4 @ =0x00000838
	adds r0, r6, r3
	str r1, [r0]
	ldr r1, _081DD5C8 @ =0x00000855
	adds r0, r6, r1
	strb r5, [r0]
	adds r3, #0x1c
	adds r0, r6, r3
	strb r2, [r0]
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DD5FC
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081DD620
	.align 2, 0
_081DD5BC: .4byte 0x0000085A
_081DD5C0: .4byte FUN_081dd3c8
_081DD5C4: .4byte 0x00000838
_081DD5C8: .4byte 0x00000855
_081DD5CC:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081DD610
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0
	bl FUN_081df8a0
	ldr r1, _081DD604 @ =FUN_081dd3c8
	movs r2, #4
	ldr r3, _081DD608 @ =0x00000838
	adds r0, r6, r3
	str r1, [r0]
	ldr r1, _081DD60C @ =0x00000855
	adds r0, r6, r1
	strb r5, [r0]
	adds r3, #0x1c
	adds r0, r6, r3
	strb r2, [r0]
_081DD5FC:
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081DD620
	.align 2, 0
_081DD604: .4byte FUN_081dd3c8
_081DD608: .4byte 0x00000838
_081DD60C: .4byte 0x00000855
_081DD610:
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r2, #0xd3
	lsls r2, r2, #3
	adds r1, r6, r2
	bl MainSprite_AdvanceAnim
_081DD620:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dd628
FUN_081dd628: @ 0x081DD628
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081DD660 @ =0x00000855
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081DD648
	adds r0, r4, #0
	bl FUN_081dd36c
	ldr r1, _081DD664 @ =0x00000856
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r5]
_081DD648:
	adds r0, r4, #0
	bl FUN_081dcf34
	ldr r3, _081DD664 @ =0x00000856
	adds r1, r4, r3
	ldrh r0, [r1]
	cmp r0, #9
	bhi _081DD668
	adds r0, #1
	strh r0, [r1]
	b _081DD692
	.align 2, 0
_081DD660: .4byte 0x00000855
_081DD664: .4byte 0x00000856
_081DD668:
	ldr r0, _081DD698 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	beq _081DD692
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _081DD69C @ =FUN_081dd434
	movs r2, #3
	ldr r3, _081DD6A0 @ =0x00000838
	adds r0, r4, r3
	str r1, [r0]
	ldr r0, _081DD6A4 @ =0x00000855
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081DD6A8 @ =0x00000854
	adds r0, r4, r1
	strb r2, [r0]
_081DD692:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DD698: .4byte 0x030044E0
_081DD69C: .4byte FUN_081dd434
_081DD6A0: .4byte 0x00000838
_081DD6A4: .4byte 0x00000855
_081DD6A8: .4byte 0x00000854

	thumb_func_start FUN_081dd6ac
FUN_081dd6ac: @ 0x081DD6AC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081DD738 @ =0x00000855
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081DD6C6
	ldr r1, _081DD73C @ =0x00000856
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081DD6C6:
	ldr r0, _081DD740 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081DD744 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081DD6FC
	movs r2, #0
	ldr r3, _081DD748 @ =0x00000859
	adds r1, r4, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	bge _081DD6FC
	movs r5, #1
	adds r3, r1, #0
	ldr r0, _081DD74C @ =0x000006EC
	adds r1, r4, r0
_081DD6E8:
	ldrh r0, [r1]
	cmp r0, #1
	bls _081DD6F0
	strh r5, [r1]
_081DD6F0:
	adds r1, #2
	adds r2, #1
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r2, r0
	blt _081DD6E8
_081DD6FC:
	adds r0, r4, #0
	bl FUN_081dccec
	adds r0, r4, #0
	bl FUN_081dd1d8
	ldr r1, _081DD750 @ =0x00000858
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, _081DD748 @ =0x00000859
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _081DD760
	ldr r1, _081DD754 @ =FUN_081dd628
	movs r2, #2
	ldr r3, _081DD758 @ =0x00000838
	adds r0, r4, r3
	str r1, [r0]
	ldr r0, _081DD738 @ =0x00000855
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081DD75C @ =0x00000854
	adds r0, r4, r1
	strb r2, [r0]
	b _081DD76A
	.align 2, 0
_081DD738: .4byte 0x00000855
_081DD73C: .4byte 0x00000856
_081DD740: .4byte 0x030044E0
_081DD744: .4byte 0x0000030F
_081DD748: .4byte 0x00000859
_081DD74C: .4byte 0x000006EC
_081DD750: .4byte 0x00000858
_081DD754: .4byte FUN_081dd628
_081DD758: .4byte 0x00000838
_081DD75C: .4byte 0x00000854
_081DD760:
	ldr r2, _081DD770 @ =0x00000856
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081DD76A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DD770: .4byte 0x00000856

	thumb_func_start FUN_081dd774
FUN_081dd774: @ 0x081DD774
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	ldr r0, _081DD7EC @ =0x00000855
	adds r4, r3, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DD792
	ldr r1, _081DD7F0 @ =0x00000856
	adds r0, r3, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r4]
_081DD792:
	ldr r2, _081DD7F0 @ =0x00000856
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r0, #0xa
	bls _081DD80C
	ldr r0, _081DD7F4 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081DD7F8 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081DD80C
	movs r2, #0
	ldr r4, _081DD7FC @ =0x00000859
	adds r1, r3, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r4, _081DD800 @ =FUN_081dd6ac
	mov r8, r4
	ldr r4, _081DD804 @ =0x00000838
	adds r4, r4, r3
	mov ip, r4
	ldr r4, _081DD7EC @ =0x00000855
	adds r7, r3, r4
	subs r4, #1
	adds r6, r3, r4
	cmp r2, r0
	bge _081DD7DE
	movs r5, #1
	adds r4, r1, #0
	ldr r0, _081DD808 @ =0x000006EC
	adds r1, r3, r0
_081DD7D0:
	strh r5, [r1]
	adds r1, #2
	adds r2, #1
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r2, r0
	blt _081DD7D0
_081DD7DE:
	movs r0, #1
	mov r1, r8
	mov r2, ip
	str r1, [r2]
	strb r0, [r7]
	strb r0, [r6]
	b _081DD84C
	.align 2, 0
_081DD7EC: .4byte 0x00000855
_081DD7F0: .4byte 0x00000856
_081DD7F4: .4byte 0x030044E0
_081DD7F8: .4byte 0x0000030F
_081DD7FC: .4byte 0x00000859
_081DD800: .4byte FUN_081dd6ac
_081DD804: .4byte 0x00000838
_081DD808: .4byte 0x000006EC
_081DD80C:
	ldr r0, _081DD830 @ =0x00000856
	adds r4, r3, r0
	ldrh r0, [r4]
	cmp r0, #0x40
	bls _081DD840
	ldr r1, _081DD834 @ =FUN_081dd6ac
	movs r2, #1
	ldr r4, _081DD838 @ =0x00000838
	adds r0, r3, r4
	str r1, [r0]
	ldr r1, _081DD83C @ =0x00000855
	adds r0, r3, r1
	strb r2, [r0]
	adds r4, #0x1c
	adds r0, r3, r4
	strb r2, [r0]
	b _081DD84C
	.align 2, 0
_081DD830: .4byte 0x00000856
_081DD834: .4byte FUN_081dd6ac
_081DD838: .4byte 0x00000838
_081DD83C: .4byte 0x00000855
_081DD840:
	adds r0, r3, #0
	bl FUN_081dccec
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_081DD84C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EntityB85F_Update
EntityB85F_Update: @ 0x081DD858
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _081DD870
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081DD882
_081DD870:
	ldr r1, _081DD888 @ =0x00000838
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081DD880
	adds r0, r4, #0
	bl _call_via_r1
_081DD880:
	movs r0, #1
_081DD882:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DD888: .4byte 0x00000838

	thumb_func_start EntityB85F_Destroy
EntityB85F_Destroy: @ 0x081DD88C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dc880
	adds r0, r4, #0
	bl FUN_081dcb70
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityB85F_Init
EntityB85F_Init: @ 0x081DD8A4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081DD8C0
	bl FUN_0823d340
	ldr r2, _081DD934 @ =0x0000083C
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	beq _081DD954
_081DD8C0:
	movs r0, #0
	bl FUN_081df8f0
	ldr r0, _081DD938 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq _081DD8D4
	ldrh r1, [r0, #0x1a]
_081DD8D4:
	ldr r2, _081DD93C @ =0x00000859
	adds r0, r4, r2
	movs r5, #0
	strb r1, [r0]
	lsls r0, r1, #0x18
	cmp r0, #0
	blt _081DD954
	adds r0, r4, #0
	bl FUN_081dc6d0
	adds r0, r4, #0
	bl FUN_081dc788
	adds r0, r4, #0
	bl FUN_081dc9dc
	adds r0, r4, #0
	bl FUN_081dcaa4
	adds r0, r4, #0
	bl FUN_081dcd50
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_081dce14
	ldr r1, _081DD940 @ =0x00000858
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_081dd2dc
	ldr r1, _081DD944 @ =FUN_081dd774
	ldr r2, _081DD948 @ =0x00000838
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, _081DD94C @ =0x00000855
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081DD950 @ =0x00000854
	adds r0, r4, r1
	strb r5, [r0]
	movs r0, #7
	bl FUN_0809c08c
	movs r0, #1
	b _081DD958
	.align 2, 0
_081DD934: .4byte 0x0000083C
_081DD938: .4byte 0x03002C68
_081DD93C: .4byte 0x00000859
_081DD940: .4byte 0x00000858
_081DD944: .4byte FUN_081dd774
_081DD948: .4byte 0x00000838
_081DD94C: .4byte 0x00000855
_081DD950: .4byte 0x00000854
_081DD954:
	movs r0, #1
	rsbs r0, r0, #0
_081DD958:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityB85F_Create
EntityB85F_Create: @ 0x081DD960
	push {r4, lr}
	ldr r1, _081DD98C @ =0x0000085C
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081DD998
	ldr r1, _081DD990 @ =EntityB85F_Update
	ldr r2, _081DD994 @ =EntityB85F_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityB85F_Init
	cmp r0, #0
	bge _081DD998
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081DD99A
	.align 2, 0
_081DD98C: .4byte 0x0000085C
_081DD990: .4byte EntityB85F_Update
_081DD994: .4byte EntityB85F_Destroy
_081DD998:
	adds r0, r4, #0
_081DD99A:
	pop {r4}
	pop {r1}
	bx r1
