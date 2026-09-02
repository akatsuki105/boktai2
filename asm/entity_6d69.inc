	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0801f764
FUN_0801f764: @ 0x0801F764
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r2, _0801F7B0 @ =0x085AA9CC
	movs r0, #0x39
	adds r0, r0, r3
	mov ip, r0
	adds r4, r3, #0
	adds r4, #0x38
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	mov r1, ip
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	strb r0, [r3, #7]
	mov r5, ip
	ldrb r0, [r5]
	cmp r0, #2
	bne _0801F7B4
	adds r0, r3, #0
	adds r0, #0x70
	ldrh r0, [r0]
	subs r0, #0x28
	strh r0, [r3, #0x1c]
	adds r0, r3, #0
	adds r0, #0x72
	ldrh r0, [r0]
	subs r0, #0x5a
	strh r0, [r3, #0x1e]
	adds r0, r3, #0
	adds r0, #0x74
	ldrh r0, [r0]
	subs r0, #0x28
	strh r0, [r3, #0x20]
	b _0801F7EC
	.align 2, 0
_0801F7B0: .4byte 0x085AA9CC
_0801F7B4:
	cmp r0, #0
	bne _0801F7E4
	ldrb r0, [r4]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0801F7E4
	adds r0, r3, #0
	adds r0, #0x70
	ldrh r0, [r0]
	adds r0, #0x50
	strh r0, [r3, #0x1c]
	adds r0, r3, #0
	adds r0, #0x72
	ldrh r0, [r0]
	adds r0, #0xb4
	strh r0, [r3, #0x1e]
	adds r0, r3, #0
	adds r0, #0x74
	ldrh r0, [r0]
	adds r0, #0x50
	strh r0, [r3, #0x20]
	b _0801F7EC
_0801F7E4:
	ldr r0, [r3, #0x70]
	ldr r1, [r3, #0x74]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
_0801F7EC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801f7f4
FUN_0801f7f4: @ 0x0801F7F4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r3, _0801F830 @ =0x085AA9FC
	movs r0, #0x39
	adds r0, r0, r4
	mov ip, r0
	adds r2, r4, #0
	adds r2, #0x38
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	mov r1, ip
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	strb r0, [r4, #7]
	ldrb r0, [r2]
	cmp r0, #1
	bls _0801F826
	cmp r0, #4
	beq _0801F826
	cmp r0, #5
	bne _0801F834
_0801F826:
	ldr r0, [r4, #0x70]
	ldr r1, [r4, #0x74]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	b _0801F852
	.align 2, 0
_0801F830: .4byte 0x085AA9FC
_0801F834:
	adds r0, r4, #0
	adds r0, #0x70
	ldrh r0, [r0]
	adds r0, #0x28
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x72
	ldrh r0, [r0]
	adds r0, #0x5a
	strh r0, [r4, #0x1e]
	adds r0, r4, #0
	adds r0, #0x74
	ldrh r0, [r0]
	adds r0, #0x28
	strh r0, [r4, #0x20]
_0801F852:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801f858
FUN_0801f858: @ 0x0801F858
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r2, _0801F8A4 @ =0x085AAA5C
	movs r0, #0x39
	adds r0, r0, r3
	mov ip, r0
	adds r4, r3, #0
	adds r4, #0x38
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	mov r1, ip
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	strb r0, [r3, #7]
	mov r5, ip
	ldrb r0, [r5]
	cmp r0, #2
	bne _0801F8A8
	adds r0, r3, #0
	adds r0, #0x70
	ldrh r0, [r0]
	subs r0, #0x28
	strh r0, [r3, #0x1c]
	adds r0, r3, #0
	adds r0, #0x72
	ldrh r0, [r0]
	subs r0, #0x5a
	strh r0, [r3, #0x1e]
	adds r0, r3, #0
	adds r0, #0x74
	ldrh r0, [r0]
	subs r0, #0x28
	strh r0, [r3, #0x20]
	b _0801F8E0
	.align 2, 0
_0801F8A4: .4byte 0x085AAA5C
_0801F8A8:
	cmp r0, #0
	bne _0801F8D8
	ldrb r0, [r4]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0801F8D8
	adds r0, r3, #0
	adds r0, #0x70
	ldrh r0, [r0]
	adds r0, #0x50
	strh r0, [r3, #0x1c]
	adds r0, r3, #0
	adds r0, #0x72
	ldrh r0, [r0]
	adds r0, #0xb4
	strh r0, [r3, #0x1e]
	adds r0, r3, #0
	adds r0, #0x74
	ldrh r0, [r0]
	adds r0, #0x50
	strh r0, [r3, #0x20]
	b _0801F8E0
_0801F8D8:
	ldr r0, [r3, #0x70]
	ldr r1, [r3, #0x74]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
_0801F8E0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801f8e8
FUN_0801f8e8: @ 0x0801F8E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r2, #0
	str r3, [sp]
	ldr r0, [sp, #0x24]
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	ldr r4, [sp, #0x44]
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sb, r3
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov sl, r4
	ldrh r1, [r5, #0x1a]
	ldr r0, [r5, #0x30]
	cmp r1, r0
	bge _0801F9A4
	ldr r0, _0801F9AC @ =0x0000042C
	adds r2, r5, r0
	movs r0, #0x8c
	muls r1, r0, r1
	ldr r0, [r2]
	adds r4, r0, r1
	movs r2, #0
	movs r3, #0
	strh r7, [r4, #0x34]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x68]
	str r1, [r4, #0x6c]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x78]
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x36
	mov r1, ip
	strb r1, [r0]
	adds r0, #1
	mov r1, r8
	strb r1, [r0]
	adds r0, #1
	mov r1, sb
	strb r1, [r0]
	adds r0, #2
	strb r2, [r0]
	adds r7, r4, #0
	adds r7, #0x40
	ldr r0, [sp, #0x30]
	strb r0, [r7]
	adds r1, r4, #0
	adds r1, #0x88
	ldr r0, [sp, #0x34]
	strh r0, [r1]
	ldr r0, [sp, #0x38]
	str r0, [r4, #0x48]
	subs r1, #0x47
	ldr r0, [sp, #0x3c]
	strb r0, [r1]
	ldr r0, [sp]
	str r0, [r4, #0x4c]
	adds r0, r4, #0
	adds r0, #0x80
	strh r3, [r0]
	adds r0, r6, #0
	bl FUN_08241574
	adds r1, r4, #0
	adds r1, #0x42
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x44
	mov r1, sl
	strb r1, [r0]
	movs r0, #0x10
	bl Malloc
	str r0, [r4, #0x2c]
	cmp r0, #0
	bne _0801F9B0
_0801F9A4:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801FA98
	.align 2, 0
_0801F9AC: .4byte 0x0000042C
_0801F9B0:
	movs r1, #0x10
	bl ClearMemory
	ldrb r1, [r7]
	cmp r1, #0x10
	bhi _0801FA76
	lsls r0, r1, #2
	ldr r1, _0801F9C8 @ =_0801F9CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801F9C8: .4byte _0801F9CC
_0801F9CC: @ jump table
	.4byte _0801FA64 @ case 0
	.4byte _0801FA10 @ case 1
	.4byte _0801FA1A @ case 2
	.4byte _0801FA64 @ case 3
	.4byte _0801FA64 @ case 4
	.4byte _0801FA64 @ case 5
	.4byte _0801FA64 @ case 6
	.4byte _0801FA64 @ case 7
	.4byte _0801FA22 @ case 8
	.4byte _0801FA2A @ case 9
	.4byte _0801FA32 @ case 10
	.4byte _0801FA3A @ case 11
	.4byte _0801FA42 @ case 12
	.4byte _0801FA4A @ case 13
	.4byte _0801FA52 @ case 14
	.4byte _0801FA64 @ case 15
	.4byte _0801FA6E @ case 16
_0801FA10:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080207b0
	b _0801FA76
_0801FA1A:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #0
	b _0801FA58
_0801FA22:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #1
	b _0801FA58
_0801FA2A:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #2
	b _0801FA58
_0801FA32:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #3
	b _0801FA58
_0801FA3A:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #4
	b _0801FA58
_0801FA42:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #5
	b _0801FA58
_0801FA4A:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #6
	b _0801FA58
_0801FA52:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #7
_0801FA58:
	strb r0, [r1]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08020d44
	b _0801FA76
_0801FA64:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080203a4
	b _0801FA76
_0801FA6E:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08020d44
_0801FA76:
	ldr r1, [r4, #0x48]
	cmp r1, #0
	beq _0801FA90
	ldr r6, [sp, #0x40]
	adds r3, r4, #0
	adds r3, #0x50
	movs r2, #3
_0801FA84:
	ldm r6!, {r1}
	stm r3!, {r1}
	subs r2, #1
	cmp r2, #0
	bge _0801FA84
	b _0801FA92
_0801FA90:
	str r1, [r4, #0x50]
_0801FA92:
	ldrh r1, [r5, #0x1a]
	adds r1, #1
	strh r1, [r5, #0x1a]
_0801FA98:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801faa8
FUN_0801faa8: @ 0x0801FAA8
	push {r4, lr}
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r3, #0
	ldrb r2, [r0, #0x1c]
	cmp r3, r2
	bge _0801FACE
	adds r1, r2, #0
	adds r2, r0, #0
	adds r2, #0x1e
_0801FABC:
	ldrh r0, [r2]
	cmp r0, r4
	bne _0801FAC6
	movs r0, #1
	b _0801FAD0
_0801FAC6:
	adds r2, #2
	adds r3, #1
	cmp r3, r1
	blt _0801FABC
_0801FACE:
	movs r0, #0
_0801FAD0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801fad8
FUN_0801fad8: @ 0x0801FAD8
	push {r4, lr}
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r3, #0
	ldrb r2, [r0, #0x1d]
	cmp r3, r2
	bge _0801FAFE
	adds r1, r2, #0
	adds r2, r0, #0
	adds r2, #0x26
_0801FAEC:
	ldrh r0, [r2]
	cmp r0, r4
	bne _0801FAF6
	movs r0, #1
	b _0801FB00
_0801FAF6:
	adds r2, #2
	adds r3, #1
	cmp r3, r1
	blt _0801FAEC
_0801FAFE:
	movs r0, #0
_0801FB00:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801fb08
FUN_0801fb08: @ 0x0801FB08
	push {r4, lr}
	movs r3, #0
	ldr r0, _0801FB30 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r4, [r0]
	ldr r2, _0801FB34 @ =0x085AAA8C
	adds r1, #0x38
	ldrb r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r0, r2
_0801FB26:
	ldr r0, [r1]
	cmp r4, r0
	bne _0801FB38
	movs r0, #0
	b _0801FB42
	.align 2, 0
_0801FB30: .4byte 0x03002BE0
_0801FB34: .4byte 0x085AAA8C
_0801FB38:
	adds r1, #4
	adds r3, #1
	cmp r3, #2
	ble _0801FB26
	movs r0, #1
_0801FB42:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801fb48
FUN_0801fb48: @ 0x0801FB48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	ldr r0, _0801FB68 @ =0x000085E6
	bl FUN_08230e70
	str r0, [sp, #0x3c]
	cmp r0, #0
	bne _0801FB6C
	movs r0, #1
	rsbs r0, r0, #0
	b _0801FC76
	.align 2, 0
_0801FB68: .4byte 0x000085E6
_0801FB6C:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x40]
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x44]
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x48]
	movs r0, #0x73
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x4c]
	movs r0, #0x72
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x50]
	movs r0, #0x76
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x54]
	movs r1, #0xc8
	lsls r1, r1, #1
	movs r0, #0x68
	bl Script_GetKeywordValue
	mov sl, r0
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r0, #0x6b
	bl prepare_08231510
	cmp r0, #0
	beq _0801FBFC
	bl Script_GetValue
	mov r8, r0
	bl Script_GetValue
	adds r7, r0, #0
	add r6, sp, #0x34
	add r5, sp, #0x24
	movs r4, #3
_0801FBEE:
	bl Script_GetValue
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0801FBEE
	b _0801FC04
_0801FBFC:
	movs r0, #0
	mov r8, r0
	movs r7, #0
	add r6, sp, #0x34
_0801FC04:
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0801FC1E
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	bl FUN_08234cf8
	b _0801FC48
_0801FC1E:
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0801FC40
	bl Script_GetValue
	strh r0, [r6]
	bl Script_GetValue
	add r4, sp, #0x34
	strh r0, [r4, #2]
	bl Script_GetValue
	strh r0, [r4, #4]
	b _0801FC48
_0801FC40:
	strh r1, [r6]
	add r0, sp, #0x34
	strh r1, [r0, #2]
	strh r1, [r0, #4]
_0801FC48:
	ldr r0, [sp, #0x48]
	str r0, [sp]
	ldr r0, [sp, #0x4c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x50]
	str r0, [sp, #8]
	ldr r0, [sp, #0x54]
	str r0, [sp, #0xc]
	mov r0, sl
	str r0, [sp, #0x10]
	mov r0, r8
	str r0, [sp, #0x14]
	str r7, [sp, #0x18]
	add r0, sp, #0x24
	str r0, [sp, #0x1c]
	mov r0, sb
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x3c]
	ldr r1, [sp, #0x40]
	adds r2, r6, #0
	ldr r3, [sp, #0x44]
	bl FUN_0801f8e8
_0801FC76:
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801fc88
FUN_0801fc88: @ 0x0801FC88
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	movs r4, #0
	ldrh r0, [r5, #0x1a]
	cmp r4, r0
	bge _0801FCFC
	ldr r1, _0801FD08 @ =0x0000042C
	adds r6, r5, r1
	movs r3, #2
	mov sb, r3
	ldr r0, _0801FD0C @ =FUN_08020734
	mov r8, r0
_0801FCAA:
	movs r0, #0x8c
	adds r1, r4, #0
	muls r1, r0, r1
	ldr r0, [r6]
	adds r2, r0, r1
	ldrh r0, [r2, #0x34]
	cmp r0, r7
	bne _0801FCF4
	movs r1, #0x37
	adds r1, r1, r2
	mov ip, r1
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801FCCA
	cmp r0, #3
	bne _0801FCF4
_0801FCCA:
	adds r0, r2, #0
	adds r0, #0x36
	ldrb r0, [r0]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	cmp r1, #0
	bne _0801FCF4
	adds r0, r2, #0
	adds r0, #0x41
	strb r3, [r0]
	mov r0, sb
	mov r3, ip
	strb r0, [r3]
	mov r3, r8
	str r3, [r2, #0x30]
	adds r0, r2, #0
	adds r0, #0x39
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_0801FCF4:
	adds r4, #1
	ldrh r0, [r5, #0x1a]
	cmp r4, r0
	blt _0801FCAA
_0801FCFC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FD08: .4byte 0x0000042C
_0801FD0C: .4byte FUN_08020734

	thumb_func_start FUN_0801fd10
FUN_0801fd10: @ 0x0801FD10
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r3, #0
	ldrh r0, [r4, #0x1a]
	cmp r3, r0
	bge _0801FD72
	ldr r1, _0801FD80 @ =0x0000042C
	adds r5, r4, r1
	movs r2, #3
	mov sb, r2
	mov r8, r3
	movs r0, #2
	mov ip, r0
	ldr r7, _0801FD84 @ =FUN_080206b8
_0801FD36:
	movs r0, #0x8c
	adds r1, r3, #0
	muls r1, r0, r1
	ldr r0, [r5]
	adds r1, r0, r1
	ldrh r0, [r1, #0x34]
	cmp r0, r6
	bne _0801FD6A
	adds r2, r1, #0
	adds r2, #0x37
	ldrb r0, [r2]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0801FD6A
	mov r0, sb
	strb r0, [r2]
	str r7, [r1, #0x30]
	adds r0, r1, #0
	adds r0, #0x39
	mov r2, ip
	strb r2, [r0]
	adds r0, #1
	mov r1, r8
	strb r1, [r0]
_0801FD6A:
	adds r3, #1
	ldrh r2, [r4, #0x1a]
	cmp r3, r2
	blt _0801FD36
_0801FD72:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FD80: .4byte 0x0000042C
_0801FD84: .4byte FUN_080206b8

	thumb_func_start FUN_0801fd88
FUN_0801fd88: @ 0x0801FD88
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	movs r3, #0
	ldrh r0, [r4, #0x1a]
	cmp r3, r0
	bge _0801FDDA
	ldr r7, _0801FDE8 @ =0x0000042C
	adds r6, r4, r7
	movs r0, #1
	mov r8, r0
	movs r5, #0
	ldr r7, _0801FDEC @ =0x080206B5
	mov ip, r7
	movs r1, #0
_0801FDB0:
	ldr r0, [r6]
	adds r2, r0, r1
	ldrh r0, [r2, #0x34]
	cmp r0, sb
	bne _0801FDD0
	adds r0, r2, #0
	adds r0, #0x37
	mov r7, r8
	strb r7, [r0]
	mov r0, ip
	str r0, [r2, #0x30]
	adds r0, r2, #0
	adds r0, #0x39
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
_0801FDD0:
	adds r1, #0x8c
	adds r3, #1
	ldrh r7, [r4, #0x1a]
	cmp r3, r7
	blt _0801FDB0
_0801FDDA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FDE8: .4byte 0x0000042C
_0801FDEC: .4byte 0x080206B5

	thumb_func_start FUN_0801fdf0
FUN_0801fdf0: @ 0x0801FDF0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	movs r3, #0
	ldrh r0, [r4, #0x1a]
	cmp r3, r0
	bge _0801FE42
	ldr r7, _0801FE50 @ =0x0000042C
	adds r6, r4, r7
	movs r5, #0
	ldr r0, _0801FE54 @ =0x080206B1
	mov r8, r0
	movs r7, #2
	mov ip, r7
	movs r1, #0
_0801FE18:
	ldr r0, [r6]
	adds r2, r0, r1
	ldrh r0, [r2, #0x34]
	cmp r0, sb
	bne _0801FE38
	adds r0, r2, #0
	adds r0, #0x37
	strb r5, [r0]
	mov r0, r8
	str r0, [r2, #0x30]
	adds r0, r2, #0
	adds r0, #0x39
	mov r7, ip
	strb r7, [r0]
	adds r0, #1
	strb r5, [r0]
_0801FE38:
	adds r1, #0x8c
	adds r3, #1
	ldrh r0, [r4, #0x1a]
	cmp r3, r0
	blt _0801FE18
_0801FE42:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FE50: .4byte 0x0000042C
_0801FE54: .4byte 0x080206B1

	thumb_func_start FUN_0801fe58
FUN_0801fe58: @ 0x0801FE58
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r2, #0
	ldrh r0, [r4, #0x1a]
	cmp r2, r0
	bge _0801FE8C
	ldr r0, _0801FE94 @ =0x0000042C
	adds r5, r4, r0
	movs r7, #1
	movs r3, #0
_0801FE70:
	ldr r0, [r5]
	adds r1, r0, r3
	ldrh r0, [r1, #0x34]
	cmp r0, r6
	bne _0801FE82
	adds r1, #0x36
	ldrb r0, [r1]
	orrs r0, r7
	strb r0, [r1]
_0801FE82:
	adds r3, #0x8c
	adds r2, #1
	ldrh r0, [r4, #0x1a]
	cmp r2, r0
	blt _0801FE70
_0801FE8C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FE94: .4byte 0x0000042C

	thumb_func_start FUN_0801fe98
FUN_0801fe98: @ 0x0801FE98
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	movs r3, #0
	ldrh r0, [r5, #0x1a]
	cmp r3, r0
	bge _0801FED0
	ldr r0, _0801FED8 @ =0x0000042C
	adds r6, r5, r0
	movs r4, #0
	movs r0, #0xfe
	mov ip, r0
_0801FEB2:
	ldr r0, [r6]
	adds r2, r0, r4
	ldrh r0, [r2, #0x34]
	cmp r0, r7
	bne _0801FEC6
	adds r2, #0x36
	ldrb r1, [r2]
	mov r0, ip
	ands r0, r1
	strb r0, [r2]
_0801FEC6:
	adds r4, #0x8c
	adds r3, #1
	ldrh r0, [r5, #0x1a]
	cmp r3, r0
	blt _0801FEB2
_0801FED0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FED8: .4byte 0x0000042C

	thumb_func_start FUN_0801fedc
FUN_0801fedc: @ 0x0801FEDC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0801FEF8 @ =0x000085E6
	bl FUN_08230e70
	adds r6, r0, #0
	cmp r6, #0
	bne _0801FEFC
	movs r0, #1
	rsbs r0, r0, #0
	b _0801FF64
	.align 2, 0
_0801FEF8: .4byte 0x000085E6
_0801FEFC:
	movs r7, #0
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	bne _0801FF0C
	movs r0, #0
	b _0801FF64
_0801FF0C:
	bl Script_GetValue
	mov sb, r0
	movs r5, #0
	ldrh r0, [r6, #0x1a]
	cmp r7, r0
	bge _0801FF62
	ldr r2, _0801FF70 @ =0x0000042C
	adds r2, r2, r6
	mov r8, r2
_0801FF20:
	movs r0, #0x8c
	adds r1, r5, #0
	muls r1, r0, r1
	mov r2, r8
	ldr r0, [r2]
	adds r4, r0, r1
	ldrh r0, [r4, #0x34]
	cmp r0, sb
	bne _0801FF5A
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0801FF42
	bl Script_GetValue
	str r0, [r4, #0x60]
_0801FF42:
	adds r1, r4, #0
	adds r1, #0x37
	ldrb r0, [r1]
	cmp r0, #1
	beq _0801FF50
	cmp r0, #3
	bne _0801FF58
_0801FF50:
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0801FF74 @ =FUN_08020af8
	str r0, [r4, #0x30]
_0801FF58:
	movs r7, #1
_0801FF5A:
	adds r5, #1
	ldrh r0, [r6, #0x1a]
	cmp r5, r0
	blt _0801FF20
_0801FF62:
	adds r0, r7, #0
_0801FF64:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801FF70: .4byte 0x0000042C
_0801FF74: .4byte FUN_08020af8

	thumb_func_start FUN_0801ff78
FUN_0801ff78: @ 0x0801FF78
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0801FFA0 @ =0x000085E6
	bl FUN_08230e70
	adds r6, r0, #0
	cmp r6, #0
	beq _0801FF98
	movs r7, #0
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	bne _0801FFA4
_0801FF98:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801FFFC
	.align 2, 0
_0801FFA0: .4byte 0x000085E6
_0801FFA4:
	bl Script_GetValue
	mov sb, r0
	movs r5, #0
	ldrh r0, [r6, #0x1a]
	cmp r7, r0
	bge _0801FFFA
	ldr r2, _08020008 @ =0x0000042C
	adds r2, r2, r6
	mov r8, r2
_0801FFB8:
	movs r0, #0x8c
	adds r1, r5, #0
	muls r1, r0, r1
	mov r2, r8
	ldr r0, [r2]
	adds r4, r0, r1
	ldrh r0, [r4, #0x34]
	cmp r0, sb
	bne _0801FFF2
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0801FFDA
	bl Script_GetValue
	str r0, [r4, #0x64]
_0801FFDA:
	adds r1, r4, #0
	adds r1, #0x37
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801FFE8
	cmp r0, #2
	bne _0801FFF0
_0801FFE8:
	movs r0, #3
	strb r0, [r1]
	ldr r0, _0802000C @ =FUN_08020b24
	str r0, [r4, #0x30]
_0801FFF0:
	movs r7, #1
_0801FFF2:
	adds r5, #1
	ldrh r0, [r6, #0x1a]
	cmp r5, r0
	blt _0801FFB8
_0801FFFA:
	adds r0, r7, #0
_0801FFFC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08020008: .4byte 0x0000042C
_0802000C: .4byte FUN_08020b24

	thumb_func_start FUN_08020010
FUN_08020010: @ 0x08020010
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0802002C @ =0x000085E6
	bl FUN_08230e70
	adds r5, r0, #0
	cmp r5, #0
	bne _08020030
	movs r0, #1
	rsbs r0, r0, #0
	b _080200D6
	.align 2, 0
_0802002C: .4byte 0x000085E6
_08020030:
	movs r6, #0
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	bne _08020040
	movs r0, #0
	b _080200D6
_08020040:
	bl Script_GetValue
	mov r8, r0
	movs r4, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _080200D4
	ldr r2, _080200E4 @ =0x0000042C
	adds r2, r2, r5
	mov ip, r2
	movs r7, #0
	ldr r0, _080200E8 @ =0x0000FFFC
	mov sl, r0
	ldr r2, _080200EC @ =FUN_08020cd8
	mov sb, r2
_0802005E:
	movs r0, #0x8c
	adds r1, r4, #0
	muls r1, r0, r1
	mov r2, ip
	ldr r0, [r2]
	adds r3, r0, r1
	ldrh r0, [r3, #0x34]
	cmp r0, r8
	bne _080200CC
	adds r1, r3, #0
	adds r1, #0x82
	movs r0, #0
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x37
	strb r7, [r0]
	mov r0, sb
	str r0, [r3, #0x30]
	adds r0, r3, #0
	adds r0, #0x39
	strb r7, [r0]
	adds r0, #1
	strb r7, [r0]
	ldr r2, [r3, #0x2c]
	ldrh r1, [r2, #6]
	mov r0, sl
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r3, #0x2c]
	ldrh r0, [r2, #6]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	adds r0, r3, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	orrs r1, r0
	strb r1, [r2, #4]
	adds r2, r3, #0
	adds r2, #0x88
	ldrh r1, [r2]
	adds r0, r3, #0
	adds r0, #0x80
	strh r1, [r0]
	adds r1, r3, #0
	adds r1, #0x72
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
	movs r6, #1
_080200CC:
	adds r4, #1
	ldrh r2, [r5, #0x1a]
	cmp r4, r2
	blt _0802005E
_080200D4:
	adds r0, r6, #0
_080200D6:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080200E4: .4byte 0x0000042C
_080200E8: .4byte 0x0000FFFC
_080200EC: .4byte FUN_08020cd8

	thumb_func_start FUN_080200f0
FUN_080200f0: @ 0x080200F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08020118 @ =0x000085E6
	bl FUN_08230e70
	adds r5, r0, #0
	cmp r5, #0
	beq _08020112
	movs r6, #0
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	bne _0802011C
_08020112:
	movs r0, #1
	rsbs r0, r0, #0
	b _080201AE
	.align 2, 0
_08020118: .4byte 0x000085E6
_0802011C:
	bl Script_GetValue
	mov r8, r0
	movs r4, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _080201AC
	ldr r1, _080201BC @ =0x0000042C
	adds r1, r1, r5
	mov ip, r1
	movs r7, #0
	movs r2, #1
	mov sb, r2
	ldr r0, _080201C0 @ =0x0000FFFD
	mov sl, r0
_0802013A:
	movs r0, #0x8c
	adds r1, r4, #0
	muls r1, r0, r1
	mov r2, ip
	ldr r0, [r2]
	adds r3, r0, r1
	ldrh r0, [r3, #0x34]
	cmp r0, r8
	bne _080201A4
	adds r0, r3, #0
	adds r0, #0x82
	strh r7, [r0]
	subs r0, #0x4b
	mov r1, sb
	strb r1, [r0]
	ldr r2, _080201C4 @ =FUN_08020d10
	str r2, [r3, #0x30]
	adds r0, #0x4d
	ldrb r0, [r0]
	adds r1, r3, #0
	adds r1, #0x39
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x3a
	movs r1, #0
	strb r1, [r0]
	ldr r2, [r3, #0x2c]
	ldrh r1, [r2, #6]
	mov r0, sl
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r3, #0x2c]
	ldrh r0, [r2, #6]
	movs r1, #3
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	adds r0, r3, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	adds r0, r3, #0
	adds r0, #0x80
	strh r7, [r0]
	subs r0, #0xe
	ldrh r0, [r0]
	strh r0, [r3, #0x1e]
	movs r6, #1
_080201A4:
	adds r4, #1
	ldrh r2, [r5, #0x1a]
	cmp r4, r2
	blt _0802013A
_080201AC:
	adds r0, r6, #0
_080201AE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080201BC: .4byte 0x0000042C
_080201C0: .4byte 0x0000FFFD
_080201C4: .4byte FUN_08020d10

	thumb_func_start FUN_080201c8
FUN_080201c8: @ 0x080201C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08020254 @ =0x000085E6
	bl FUN_08230e70
	adds r4, r0, #0
	cmp r4, #0
	beq _0802024A
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _0802024A
	bl Script_GetValue
	adds r7, r0, #0
	movs r3, #0
	ldrh r0, [r4, #0x1a]
	cmp r3, r0
	bge _0802024A
	ldr r1, _08020258 @ =0x0000042C
	adds r6, r4, r1
	movs r5, #0
	movs r0, #2
	mov r8, r0
	ldr r1, _0802025C @ =FUN_08020734
	mov ip, r1
_08020200:
	movs r0, #0x8c
	adds r1, r3, #0
	muls r1, r0, r1
	ldr r0, [r6]
	adds r2, r0, r1
	ldrh r0, [r2, #0x34]
	cmp r0, r7
	bne _08020242
	adds r1, r2, #0
	adds r1, #0x41
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r4, #0x1c]
	lsls r0, r0, #1
	adds r1, r4, #0
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r2, #0x34]
	strh r0, [r1]
	ldrb r0, [r4, #0x1c]
	adds r0, #1
	strb r0, [r4, #0x1c]
	adds r0, r2, #0
	adds r0, #0x37
	mov r1, r8
	strb r1, [r0]
	mov r0, ip
	str r0, [r2, #0x30]
	adds r0, r2, #0
	adds r0, #0x39
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
_08020242:
	adds r3, #1
	ldrh r1, [r4, #0x1a]
	cmp r3, r1
	blt _08020200
_0802024A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08020254: .4byte 0x000085E6
_08020258: .4byte 0x0000042C
_0802025C: .4byte FUN_08020734

	thumb_func_start FUN_08020260
FUN_08020260: @ 0x08020260
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r0, _0802030C @ =0x000085E6
	bl FUN_08230e70
	adds r5, r0, #0
	cmp r5, #0
	beq _08020302
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08020302
	bl Script_GetValue
	adds r7, r0, #0
	movs r2, #0
	movs r4, #0
	movs r6, #0
	ldrh r3, [r5, #0x1a]
	cmp r6, r3
	bge _080202A4
	ldr r1, _08020310 @ =0x0000042C
	adds r0, r5, r1
	ldr r1, [r0]
_08020292:
	ldrh r0, [r1, #0x34]
	cmp r0, r7
	bne _0802029C
	adds r4, #1
	adds r6, r2, #0
_0802029C:
	adds r1, #0x8c
	adds r2, #1
	cmp r2, r3
	blt _08020292
_080202A4:
	cmp r4, #0
	beq _08020302
	cmp r4, #1
	bgt _08020302
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08020302
	mov r0, sp
	bl FUN_0823167c
	ldr r0, _08020310 @ =0x0000042C
	adds r5, r5, r0
	ldr r0, [r5]
	movs r1, #0x8c
	adds r4, r6, #0
	muls r4, r1, r4
	adds r0, r4, r0
	movs r1, #0x1c
	ldrsh r2, [r0, r1]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldr r0, [r5]
	adds r0, r4, r0
	movs r1, #0x1e
	ldrsh r2, [r0, r1]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldr r0, [r5]
	adds r4, r4, r0
	movs r0, #0x20
	ldrsh r2, [r4, r0]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
_08020302:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802030C: .4byte 0x000085E6
_08020310: .4byte 0x0000042C

	thumb_func_start FUN_08020314
FUN_08020314: @ 0x08020314
	push {r4, lr}
	ldr r0, _08020338 @ =0x000085E6
	bl FUN_08230e70
	adds r4, r0, #0
	cmp r4, #0
	beq _08020332
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08020332
	bl Script_GetValue
	strh r0, [r4, #0x2e]
_08020332:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020338: .4byte 0x000085E6

	thumb_func_start FUN_0802033c
FUN_0802033c: @ 0x0802033C
	push {lr}
	ldr r0, _08020354 @ =0x000085E6
	bl FUN_08230e70
	adds r1, r0, #0
	cmp r1, #0
	beq _0802034E
	movs r0, #0
	strh r0, [r1, #0x2e]
_0802034E:
	pop {r0}
	bx r0
	.align 2, 0
_08020354: .4byte 0x000085E6

	thumb_func_start FUN_08020358
FUN_08020358: @ 0x08020358
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08020368 @ =0x000085E6
	bl FUN_08230e70
	cmp r0, #0
	bne _08020370
	b _08020396
	.align 2, 0
_08020368: .4byte 0x000085E6
_0802036C:
	movs r0, #1
	b _08020398
_08020370:
	movs r2, #0
	ldrh r3, [r0, #0x1a]
	cmp r2, r3
	bge _08020396
	ldr r1, _080203A0 @ =0x0000042C
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x3c
_08020382:
	ldrb r0, [r1, #4]
	cmp r0, #2
	bne _0802038E
	ldrh r0, [r1]
	cmp r0, r4
	beq _0802036C
_0802038E:
	adds r1, #0x8c
	adds r2, #1
	cmp r2, r3
	blt _08020382
_08020396:
	movs r0, #0
_08020398:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080203A0: .4byte 0x0000042C

	thumb_func_start FUN_080203a4
FUN_080203a4: @ 0x080203A4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	adds r0, r6, #0
	adds r0, #0x68
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080203DA
	cmp r1, #0
	blt _080203DA
	ldr r0, _080203E0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080203DA
	ldr r0, _080203E4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080203E8
_080203DA:
	movs r1, #0
	b _080203F6
	.align 2, 0
_080203E0: .4byte 0x030046A8
_080203E4: .4byte 0x030046AC
_080203E8:
	ldr r0, _0802040C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_080203F6:
	adds r0, r6, #0
	adds r0, #0x38
	ldrb r2, [r0]
	mov sb, r0
	cmp r2, #1
	beq _08020426
	cmp r2, #1
	bgt _08020410
	cmp r2, #0
	beq _0802041A
	b _08020460
	.align 2, 0
_0802040C: .4byte 0x030046A4
_08020410:
	cmp r2, #2
	beq _0802043C
	cmp r2, #3
	beq _08020448
	b _08020460
_0802041A:
	subs r0, r1, #1
	strh r0, [r6, #0x3c]
	strh r1, [r6, #0x3e]
	adds r1, r6, #0
	adds r1, #0x6c
	b _0802045A
_08020426:
	ldr r0, _08020438 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r1, r0
	strh r0, [r6, #0x3c]
	strh r1, [r6, #0x3e]
	b _08020456
	.align 2, 0
_08020438: .4byte 0x030046A4
_0802043C:
	strh r1, [r6, #0x3c]
	subs r0, r1, #1
	strh r0, [r6, #0x3e]
	adds r1, r6, #0
	adds r1, #0x6c
	b _0802045A
_08020448:
	strh r1, [r6, #0x3c]
	ldr r0, _08020474 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r1, r0
	strh r0, [r6, #0x3e]
_08020456:
	adds r1, r6, #0
	adds r1, #0x68
_0802045A:
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
_08020460:
	ldrh r4, [r6, #0x3c]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08020478
	adds r0, #4
	b _08020484
	.align 2, 0
_08020474: .4byte 0x030046A4
_08020478:
	ldr r0, _080204BC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08020484:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	adds r4, r6, #0
	adds r4, #0x3b
	movs r5, #0
	strb r0, [r4]
	ldr r0, [r6, #0x2c]
	ldrh r1, [r6, #0x3c]
	ldrb r3, [r4]
	movs r2, #0xff
	str r2, [sp]
	str r5, [sp, #4]
	movs r2, #0
	bl FUN_08234270
	adds r5, r6, #0
	adds r0, r6, #0
	adds r0, #0x40
	ldrb r0, [r0]
	mov r8, r4
	cmp r0, #0xf
	bhi _0802057E
	lsls r0, r0, #2
	ldr r1, _080204C0 @ =_080204C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080204BC: .4byte 0x030046A4
_080204C0: .4byte _080204C4
_080204C4: @ jump table
	.4byte _08020504 @ case 0
	.4byte _0802057E @ case 1
	.4byte _0802057E @ case 2
	.4byte _08020504 @ case 3
	.4byte _08020510 @ case 4
	.4byte _08020520 @ case 5
	.4byte _0802054C @ case 6
	.4byte _0802054C @ case 7
	.4byte _0802057E @ case 8
	.4byte _0802057E @ case 9
	.4byte _0802057E @ case 10
	.4byte _0802057E @ case 11
	.4byte _0802057E @ case 12
	.4byte _0802057E @ case 13
	.4byte _0802057E @ case 14
	.4byte _08020566 @ case 15
_08020504:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, #0x3c
	b _0802055A
_08020510:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r1, r1, r0
	b _0802055A
_08020520:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r4, #0x9b
	lsls r4, r4, #2
	adds r1, r1, r4
	adds r1, r7, r1
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r1, [r6, #0x4c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, r7, r0
	movs r1, #0x2b
	bl FUN_0822b20c
	b _0802057E
_0802054C:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r3, #0xbe
	lsls r3, r3, #2
	adds r1, r1, r3
_0802055A:
	adds r1, r7, r1
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822a470
	b _0802057E
_08020566:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r0, #0xe1
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r1, r7, r1
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822a470
_0802057E:
	ldr r0, [r6, #0x78]
	ldr r1, [r6, #0x7c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	mov r3, sb
	ldrb r1, [r3]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080205A0
	ldrh r0, [r5, #0x1c]
	subs r0, #0x20
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	adds r0, #0x20
	strh r0, [r5, #0x20]
	b _080205B4
_080205A0:
	ldrh r0, [r5, #0x1c]
	adds r0, #0x20
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	subs r0, #0x20
	strh r0, [r5, #0x20]
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080205B4:
	ldr r0, [r5, #0x1c]
	ldr r1, [r5, #0x20]
	str r0, [r6, #0x70]
	str r1, [r6, #0x74]
	adds r0, r6, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _080205DC
	ldr r0, _080205D8 @ =0x080206B1
	str r0, [r6, #0x30]
	adds r0, r6, #0
	adds r0, #0x39
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	b _0802060C
	.align 2, 0
_080205D8: .4byte 0x080206B1
_080205DC:
	cmp r1, #1
	bne _080205FC
	ldr r0, _080205F8 @ =0x080206B5
	str r0, [r6, #0x30]
	movs r0, #2
	adds r2, r6, #0
	adds r2, #0x39
	movs r1, #0
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x3a
	strb r1, [r0]
	b _0802060C
	.align 2, 0
_080205F8: .4byte 0x080206B5
_080205FC:
	ldr r0, _0802063C @ =0x080206B1
	str r0, [r6, #0x30]
	adds r1, r6, #0
	adds r1, #0x39
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
_0802060C:
	ldrb r0, [r3]
	cmp r0, #0
	bne _08020644
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _08020640 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #3
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	mov r3, r8
	ldrb r0, [r3]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	b _0802066C
	.align 2, 0
_0802063C: .4byte 0x080206B1
_08020640: .4byte 0x0000FFFD
_08020644:
	cmp r0, #1
	bne _0802066C
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _0802067C @ =0x0000FFFC
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrb r1, [r2, #4]
	movs r0, #0xf0
	ands r0, r1
	mov r3, r8
	ldrb r1, [r3]
	orrs r0, r1
	strb r0, [r2, #4]
_0802066C:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802067C: .4byte 0x0000FFFC

	thumb_func_start FUN_08020680
FUN_08020680: @ 0x08020680
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq _080206AA
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0801faa8
	cmp r0, #0
	bne _080206AA
	ldrb r0, [r4, #0x1c]
	lsls r0, r0, #1
	adds r1, r4, #0
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r4, #0x2e]
	strh r0, [r1]
	ldrb r0, [r4, #0x1c]
	adds r0, #1
	strb r0, [r4, #0x1c]
_080206AA:
	pop {r4}
	pop {r0}
	bx r0
_080206B0:
	.byte 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080206b8
FUN_080206b8: @ 0x080206B8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x38]
	ldr r1, _0802072C @ =0x00FFFF00
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	bne _080206D0
	movs r0, #0xcf
	bl PlaySound_0824078c
_080206D0:
	adds r2, r4, #0
	adds r2, #0x3a
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _08020726
	adds r1, r4, #0
	adds r1, #0x39
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r0, #0
	strb r0, [r2]
	ldrb r0, [r1]
	cmp r0, #0
	bne _08020726
	subs r1, #2
	strb r0, [r1]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #3
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	ldr r0, _08020730 @ =0x080206B1
	str r0, [r4, #0x30]
_08020726:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802072C: .4byte 0x00FFFF00
_08020730: .4byte 0x080206B1

	thumb_func_start FUN_08020734
FUN_08020734: @ 0x08020734
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x38]
	ldr r1, _080207A4 @ =0x00FFFF00
	ands r0, r1
	cmp r0, #0
	bne _0802076E
	movs r0, #0xce
	bl PlaySound_0824078c
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _080207A8 @ =0x0000FFFC
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrb r1, [r2, #4]
	movs r0, #0xf0
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0x3b
	ldrb r1, [r1]
	orrs r0, r1
	strb r0, [r2, #4]
_0802076E:
	adds r2, r4, #0
	adds r2, #0x3a
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _0802079E
	adds r1, r4, #0
	adds r1, #0x39
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0
	strb r0, [r2]
	ldrb r0, [r1]
	cmp r0, #1
	bls _0802079E
	movs r0, #1
	subs r1, #2
	strb r0, [r1]
	ldr r0, _080207AC @ =0x080206B5
	str r0, [r4, #0x30]
_0802079E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080207A4: .4byte 0x00FFFF00
_080207A8: .4byte 0x0000FFFC
_080207AC: .4byte 0x080206B5

	thumb_func_start FUN_080207b0
FUN_080207b0: @ 0x080207B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #8]
	adds r7, r1, #0
	adds r0, r7, #0
	adds r0, #0x68
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080207E8
	cmp r1, #0
	blt _080207E8
	ldr r0, _080207EC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080207E8
	ldr r0, _080207F0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080207F4
_080207E8:
	movs r3, #0
	b _08020802
	.align 2, 0
_080207EC: .4byte 0x030046A8
_080207F0: .4byte 0x030046AC
_080207F4:
	ldr r0, _08020820 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r2
_08020802:
	adds r0, r7, #0
	adds r0, #0x38
	ldrb r1, [r0]
	mov sl, r0
	adds r5, r7, #0
	adds r5, #0x84
	cmp r1, #9
	bls _08020814
	b _08020940
_08020814:
	lsls r0, r1, #2
	ldr r1, _08020824 @ =_08020828
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020820: .4byte 0x030046A4
_08020824: .4byte _08020828
_08020828: @ jump table
	.4byte _08020850 @ case 0
	.4byte _08020864 @ case 1
	.4byte _08020878 @ case 2
	.4byte _0802088E @ case 3
	.4byte _080208B0 @ case 4
	.4byte _080208BE @ case 5
	.4byte _080208D4 @ case 6
	.4byte _080208E8 @ case 7
	.4byte _08020910 @ case 8
	.4byte _0802091E @ case 9
_08020850:
	subs r0, r3, #1
	strh r0, [r7, #0x3c]
	strh r3, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x6c
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r1, #0x18
	b _08020902
_08020864:
	ldr r0, _08020874 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r3, r0
	strh r0, [r7, #0x3c]
	strh r3, [r7, #0x3e]
	b _080208F6
	.align 2, 0
_08020874: .4byte 0x030046A4
_08020878:
	strh r3, [r7, #0x3c]
	subs r0, r3, #1
	strh r0, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x6c
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r1, #0x18
	movs r0, #2
	b _08020904
_0802088E:
	strh r3, [r7, #0x3c]
	ldr r0, _080208AC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r3, r0
	strh r0, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x68
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r1, #0x1c
	movs r0, #2
	b _08020904
	.align 2, 0
_080208AC: .4byte 0x030046A4
_080208B0:
	subs r0, r3, #1
	movs r2, #0
	strh r0, [r7, #0x3c]
	strh r3, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x6c
	b _08020932
_080208BE:
	ldr r0, _080208D0 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r3, r0
	movs r2, #0
	strh r0, [r7, #0x3c]
	strh r3, [r7, #0x3e]
	b _0802092E
	.align 2, 0
_080208D0: .4byte 0x030046A4
_080208D4:
	strh r3, [r7, #0x3c]
	subs r0, r3, #1
	strh r0, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x6c
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r1, #0x18
	b _08020902
_080208E8:
	strh r3, [r7, #0x3c]
	ldr r0, _0802090C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r3, r0
	strh r0, [r7, #0x3e]
_080208F6:
	adds r1, r7, #0
	adds r1, #0x68
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r1, #0x1c
_08020902:
	movs r0, #1
_08020904:
	str r0, [r1]
	adds r5, r1, #0
	b _08020940
	.align 2, 0
_0802090C: .4byte 0x030046A4
_08020910:
	movs r2, #0
	strh r3, [r7, #0x3c]
	subs r0, r3, #1
	strh r0, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x6c
	b _08020932
_0802091E:
	movs r2, #0
	strh r3, [r7, #0x3c]
	ldr r0, _08020954 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r3, r0
	strh r0, [r7, #0x3e]
_0802092E:
	adds r1, r7, #0
	adds r1, #0x68
_08020932:
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x84
	str r2, [r0]
	adds r5, r0, #0
_08020940:
	ldrh r4, [r7, #0x3c]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08020958
	adds r0, #4
	b _08020964
	.align 2, 0
_08020954: .4byte 0x030046A4
_08020958:
	ldr r0, _080209D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08020964:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	adds r4, r7, #0
	adds r4, #0x3b
	movs r1, #0
	mov sb, r1
	strb r0, [r4]
	ldr r0, [r7, #0x2c]
	ldrh r1, [r7, #0x3c]
	ldrb r3, [r4]
	movs r2, #0xff
	str r2, [sp]
	mov r2, sb
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_08234270
	ldrb r0, [r5]
	movs r3, #0x39
	adds r3, r3, r7
	mov r8, r3
	strb r0, [r3]
	adds r6, r7, #0
	adds r6, #0x3a
	mov r0, sb
	strb r0, [r6]
	mov sb, r7
	ldr r0, [r7, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, #0xc8
	ldr r2, [sp, #8]
	adds r1, r2, r1
	adds r0, r7, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r0, [r7, #0x78]
	ldr r1, [r7, #0x7c]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	mov r3, sl
	ldrb r1, [r3]
	movs r0, #1
	ands r0, r1
	mov ip, r4
	cmp r0, #0
	bne _080209D4
	ldrh r0, [r7, #0x20]
	adds r0, #0x80
	strh r0, [r7, #0x20]
	b _080209E2
	.align 2, 0
_080209D0: .4byte 0x030046A4
_080209D4:
	ldrh r0, [r7, #0x1c]
	adds r0, #0x80
	strh r0, [r7, #0x1c]
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	str r0, [r7]
_080209E2:
	mov r4, sb
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [r7, #0x70]
	str r1, [r7, #0x74]
	adds r0, r7, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	beq _08020A04
	cmp r1, #1
	bne _08020A04
	ldr r0, _08020A00 @ =FUN_08020cd8
	b _08020A06
	.align 2, 0
_08020A00: .4byte FUN_08020cd8
_08020A04:
	ldr r0, _08020A64 @ =FUN_08020d10
_08020A06:
	str r0, [r7, #0x30]
	adds r2, r4, #0
	ldrb r3, [r2]
	cmp r3, #0
	bne _08020A70
	adds r0, r7, #0
	adds r0, #0x82
	movs r1, #0
	strh r3, [r0]
	movs r0, #1
	strb r0, [r2]
	ldr r0, _08020A64 @ =FUN_08020d10
	str r0, [r7, #0x30]
	ldrb r0, [r5]
	mov r2, r8
	strb r0, [r2]
	strb r1, [r6]
	ldr r2, [r7, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _08020A68 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r7, #0x2c]
	ldrh r0, [r2, #6]
	movs r1, #3
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r7, #0x2c]
	ldrh r1, [r2]
	ldr r0, _08020A6C @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2]
	ldr r2, [r7, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	mov r4, ip
	ldrb r0, [r4]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	adds r0, r7, #0
	adds r0, #0x80
	strh r3, [r0]
	subs r0, #6
	ldrh r0, [r0]
	b _08020ACE
	.align 2, 0
_08020A64: .4byte FUN_08020d10
_08020A68: .4byte 0x0000FFFD
_08020A6C: .4byte 0x0000FFFE
_08020A70:
	cmp r3, #1
	bne _08020AD4
	adds r2, r7, #0
	adds r2, #0x82
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r4]
	ldr r0, _08020AF0 @ =FUN_08020cd8
	str r0, [r7, #0x30]
	mov r0, r8
	strb r1, [r0]
	strb r1, [r6]
	ldr r2, [r7, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _08020AF4 @ =0x0000FFFC
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r7, #0x2c]
	ldrh r0, [r2, #6]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r7, #0x2c]
	ldrh r0, [r2]
	movs r1, #1
	orrs r0, r1
	strh r0, [r2]
	ldr r2, [r7, #0x2c]
	ldrb r1, [r2, #4]
	movs r0, #0xf0
	ands r0, r1
	mov r3, ip
	ldrb r1, [r3]
	orrs r0, r1
	strb r0, [r2, #4]
	adds r2, r7, #0
	adds r2, #0x88
	ldrh r1, [r2]
	adds r0, r7, #0
	adds r0, #0x80
	strh r1, [r0]
	adds r1, r7, #0
	adds r1, #0x7a
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
_08020ACE:
	adds r1, r7, #0
	adds r1, #0x72
	strh r0, [r1]
_08020AD4:
	movs r0, #0
	str r0, [r7, #0x60]
	str r0, [r7, #0x64]
	movs r1, #0
	bl FUN_080dbe54
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08020AF0: .4byte FUN_08020cd8
_08020AF4: .4byte 0x0000FFFC

	thumb_func_start FUN_08020af8
FUN_08020af8: @ 0x08020AF8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xa9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0x39
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	movs r0, #2
	subs r1, #3
	strb r0, [r1]
	ldr r0, _08020B20 @ =FUN_08020b88
	str r0, [r4, #0x30]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020B20: .4byte FUN_08020b88

	thumb_func_start FUN_08020b24
FUN_08020b24: @ 0x08020B24
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xa9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0x39
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r1, [r4, #0x2c]
	ldrh r0, [r1, #6]
	movs r2, #3
	orrs r0, r2
	strh r0, [r1, #6]
	adds r0, r4, #0
	adds r0, #0x37
	strb r2, [r0]
	ldr r2, [r4, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2]
	ldr r0, _08020B80 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2]
	ldr r0, _08020B84 @ =FUN_08020c1c
	str r0, [r4, #0x30]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020B80: .4byte 0x0000FFFE
_08020B84: .4byte FUN_08020c1c

	thumb_func_start FUN_08020b88
FUN_08020b88: @ 0x08020B88
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x80
	ldrh r0, [r5]
	adds r0, #0xf
	strh r0, [r5]
	adds r1, r4, #0
	adds r1, #0x88
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r1, [r1, r3]
	cmp r0, r1
	ble _08020BFC
	strh r2, [r5]
	movs r0, #0xa9
	lsls r0, r0, #1
	bl sound_08240740
	movs r0, #0xaa
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0x82
	movs r0, #0x1e
	strh r0, [r1]
	subs r1, #0x4b
	movs r0, #0
	strb r0, [r1]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _08020C14 @ =0x0000FFFC
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrh r0, [r2, #6]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrb r1, [r2, #4]
	movs r0, #0xf0
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0x3b
	ldrb r1, [r1]
	orrs r0, r1
	strb r0, [r2, #4]
	ldr r2, [r4, #0x2c]
	ldrh r0, [r2]
	movs r1, #1
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08020C18 @ =FUN_08020cd8
	str r0, [r4, #0x30]
_08020BFC:
	adds r0, r4, #0
	adds r0, #0x7a
	ldrh r0, [r0]
	ldrh r5, [r5]
	adds r0, r0, r5
	adds r1, r4, #0
	adds r1, #0x72
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08020C14: .4byte 0x0000FFFC
_08020C18: .4byte FUN_08020cd8

	thumb_func_start FUN_08020c1c
FUN_08020c1c: @ 0x08020C1C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x80
	ldrh r0, [r1]
	subs r0, #0xf
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08020CBC
	strh r5, [r1]
	movs r0, #0xa9
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _08020C98 @ =0x00000153
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0x82
	movs r0, #0x1e
	strh r0, [r1]
	movs r2, #1
	adds r0, r4, #0
	adds r0, #0x37
	strb r2, [r0]
	adds r0, #0x4d
	ldrb r0, [r0]
	subs r1, #0x49
	strb r0, [r1]
	adds r1, #1
	movs r0, #0
	strb r0, [r1]
	ldr r0, _08020C9C @ =FUN_08020d10
	str r0, [r4, #0x30]
	ldr r1, _08020CA0 @ =0xFFFF0000
	add r3, sp, #8
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
	str r5, [sp, #8]
	adds r0, r4, #0
	adds r0, #0x38
	ldrb r0, [r0]
	ands r2, r0
	cmp r2, #0
	beq _08020CA4
	movs r0, #0x80
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r0, #0x70
	movs r1, #2
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0
	adds r2, r3, #0
	movs r3, #5
	bl FUN_080dbd08
	b _08020CBC
	.align 2, 0
_08020C98: .4byte 0x00000153
_08020C9C: .4byte FUN_08020d10
_08020CA0: .4byte 0xFFFF0000
_08020CA4:
	movs r0, #0x80
	strh r0, [r3, #4]
	adds r0, r4, #0
	adds r0, #0x70
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #0
	add r2, sp, #8
	movs r3, #5
	bl FUN_080dbd08
_08020CBC:
	adds r0, r4, #0
	adds r0, #0x80
	adds r1, r4, #0
	adds r1, #0x7a
	ldrh r1, [r1]
	ldrh r0, [r0]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x72
	strh r1, [r0]
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08020cd8
FUN_08020cd8: @ 0x08020CD8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x82
	movs r0, #0
	ldrsh r6, [r4, r0]
	cmp r6, #0
	beq _08020CF6
	adds r0, r6, #0
	bl FUN_0823b9cc
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _08020D04
_08020CF6:
	ldr r0, [r5, #0x60]
	cmp r0, #0
	beq _08020D04
	movs r1, #0
	bl Script_ExecById
	str r6, [r5, #0x60]
_08020D04:
	movs r0, #2
	strb r0, [r5, #7]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08020d10
FUN_08020d10: @ 0x08020D10
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x82
	movs r0, #0
	ldrsh r6, [r4, r0]
	cmp r6, #0
	beq _08020D2E
	adds r0, r6, #0
	bl FUN_0823b9cc
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _08020D3C
_08020D2E:
	ldr r0, [r5, #0x64]
	cmp r0, #0
	beq _08020D3C
	movs r1, #0
	bl Script_ExecById
	str r6, [r5, #0x64]
_08020D3C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08020d44
FUN_08020d44: @ 0x08020D44
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	adds r0, r6, #0
	adds r0, #0x68
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08020D7A
	cmp r1, #0
	blt _08020D7A
	ldr r0, _08020D80 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08020D7A
	ldr r0, _08020D84 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08020D88
_08020D7A:
	movs r1, #0
	b _08020D96
	.align 2, 0
_08020D80: .4byte 0x030046A8
_08020D84: .4byte 0x030046AC
_08020D88:
	ldr r0, _08020DAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08020D96:
	adds r0, r6, #0
	adds r0, #0x38
	ldrb r2, [r0]
	mov sb, r0
	cmp r2, #1
	beq _08020DC6
	cmp r2, #1
	bgt _08020DB0
	cmp r2, #0
	beq _08020DBA
	b _08020E00
	.align 2, 0
_08020DAC: .4byte 0x030046A4
_08020DB0:
	cmp r2, #2
	beq _08020DDC
	cmp r2, #3
	beq _08020DE8
	b _08020E00
_08020DBA:
	subs r0, r1, #1
	strh r0, [r6, #0x3c]
	strh r1, [r6, #0x3e]
	adds r1, r6, #0
	adds r1, #0x6c
	b _08020DFA
_08020DC6:
	ldr r0, _08020DD8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r1, r0
	strh r0, [r6, #0x3c]
	strh r1, [r6, #0x3e]
	b _08020DF6
	.align 2, 0
_08020DD8: .4byte 0x030046A4
_08020DDC:
	strh r1, [r6, #0x3c]
	subs r0, r1, #1
	strh r0, [r6, #0x3e]
	adds r1, r6, #0
	adds r1, #0x6c
	b _08020DFA
_08020DE8:
	strh r1, [r6, #0x3c]
	ldr r0, _08020E14 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r1, r0
	strh r0, [r6, #0x3e]
_08020DF6:
	adds r1, r6, #0
	adds r1, #0x68
_08020DFA:
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
_08020E00:
	ldrh r4, [r6, #0x3c]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08020E18
	adds r0, #4
	b _08020E24
	.align 2, 0
_08020E14: .4byte 0x030046A4
_08020E18:
	ldr r0, _08020E60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08020E24:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	adds r4, r6, #0
	adds r4, #0x3b
	movs r5, #0
	strb r0, [r4]
	ldr r0, [r6, #0x2c]
	ldrh r1, [r6, #0x3c]
	ldrb r3, [r4]
	movs r2, #0xff
	str r2, [sp]
	str r5, [sp, #4]
	movs r2, #0
	bl FUN_08234270
	adds r5, r6, #0
	ldr r0, [r7, #0x34]
	mov r8, r4
	cmp r0, #0
	bne _08020E9E
	adds r0, r6, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	beq _08020E64
	cmp r0, #0x10
	beq _08020E8A
	b _08020F8A
	.align 2, 0
_08020E60: .4byte 0x030046A4
_08020E64:
	ldr r1, [r6, #0x4c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	movs r4, #0xaa
	lsls r4, r4, #1
	adds r0, r0, r4
	adds r0, r7, r0
	movs r1, #0xa7
	bl FUN_0822b20c
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, r7, r1
	adds r0, r6, #0
	b _08020F4E
_08020E8A:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r1, r7, r1
	adds r0, r6, #0
	b _08020F4E
_08020E9E:
	adds r0, r6, #0
	adds r0, #0x45
	ldrb r1, [r0]
	adds r2, r0, #0
	cmp r1, #7
	bhi _08020F8A
	lsls r0, r1, #2
	ldr r1, _08020EB4 @ =_08020EB8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020EB4: .4byte _08020EB8
_08020EB8: @ jump table
	.4byte _08020ED8 @ case 0
	.4byte _08020EFE @ case 1
	.4byte _08020F06 @ case 2
	.4byte _08020F10 @ case 3
	.4byte _08020F18 @ case 4
	.4byte _08020F20 @ case 5
	.4byte _08020F28 @ case 6
	.4byte _08020F5C @ case 7
_08020ED8:
	ldr r1, [r6, #0x4c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	movs r4, #0xaa
	lsls r4, r4, #1
	adds r0, r0, r4
	adds r0, r7, r0
	ldrb r1, [r2]
	adds r1, #0xa7
	bl FUN_0822b20c
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, r7, r1
	b _08020F4C
_08020EFE:
	movs r3, #0x82
	lsls r3, r3, #3
	adds r4, r7, r3
	b _08020F2C
_08020F06:
	ldr r0, _08020F0C @ =0x00000414
	b _08020F2A
	.align 2, 0
_08020F0C: .4byte 0x00000414
_08020F10:
	movs r3, #0x83
	lsls r3, r3, #3
	adds r4, r7, r3
	b _08020F2C
_08020F18:
	ldr r0, _08020F1C @ =0x0000041C
	b _08020F2A
	.align 2, 0
_08020F1C: .4byte 0x0000041C
_08020F20:
	movs r3, #0x84
	lsls r3, r3, #3
	adds r4, r7, r3
	b _08020F2C
_08020F28:
	ldr r0, _08020F58 @ =0x00000424
_08020F2A:
	adds r4, r7, r0
_08020F2C:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [r4]
	adds r0, r0, r1
	ldrb r1, [r2]
	adds r1, #0xa7
	bl FUN_0822b20c
	ldr r1, [r6, #0x4c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [r4]
	adds r1, r1, r0
_08020F4C:
	adds r0, r5, #0
_08020F4E:
	movs r2, #0
	bl FUN_0822a470
	b _08020F8A
	.align 2, 0
_08020F58: .4byte 0x00000424
_08020F5C:
	movs r3, #0x85
	lsls r3, r3, #3
	adds r4, r7, r3
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [r4]
	adds r0, r0, r1
	ldrb r1, [r2]
	adds r1, #0xa7
	bl FUN_0822b20c
	ldr r1, [r6, #0x4c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [r4]
	adds r1, r1, r0
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822a470
_08020F8A:
	ldr r0, [r6, #0x78]
	ldr r1, [r6, #0x7c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	mov r0, sb
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08020FAC
	ldrh r0, [r5, #0x1c]
	subs r0, #0x20
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	adds r0, #0x20
	strh r0, [r5, #0x20]
	b _08020FC0
_08020FAC:
	ldrh r0, [r5, #0x1c]
	adds r0, #0x20
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	subs r0, #0x20
	strh r0, [r5, #0x20]
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_08020FC0:
	ldr r0, [r5, #0x1c]
	ldr r1, [r5, #0x20]
	str r0, [r6, #0x70]
	str r1, [r6, #0x74]
	adds r0, r6, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _08020FE8
	ldr r0, _08020FE4 @ =0x0802108D
	str r0, [r6, #0x30]
	adds r0, r6, #0
	adds r0, #0x39
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	b _08021018
	.align 2, 0
_08020FE4: .4byte 0x0802108D
_08020FE8:
	cmp r1, #1
	bne _08021008
	ldr r0, _08021004 @ =0x08021091
	str r0, [r6, #0x30]
	movs r0, #2
	adds r2, r6, #0
	adds r2, #0x39
	movs r1, #0
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x3a
	strb r1, [r0]
	b _08021018
	.align 2, 0
_08021004: .4byte 0x08021091
_08021008:
	ldr r0, _08021048 @ =0x0802108D
	str r0, [r6, #0x30]
	adds r1, r6, #0
	adds r1, #0x39
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
_08021018:
	ldrb r0, [r3]
	cmp r0, #0
	bne _08021050
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _0802104C @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #3
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	mov r3, r8
	ldrb r0, [r3]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	b _08021078
	.align 2, 0
_08021048: .4byte 0x0802108D
_0802104C: .4byte 0x0000FFFD
_08021050:
	cmp r0, #1
	bne _08021078
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _08021088 @ =0x0000FFFC
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrb r1, [r2, #4]
	movs r0, #0xf0
	ands r0, r1
	mov r3, r8
	ldrb r1, [r3]
	orrs r0, r1
	strb r0, [r2, #4]
_08021078:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021088: .4byte 0x0000FFFC
_0802108C:
	.byte 0x70, 0x47, 0x00, 0x00
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start Entity6D69_Update
Entity6D69_Update: @ 0x08021094
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	mov r8, r0
	ldrh r0, [r0, #0x1a]
	cmp r0, #0
	bne _080210AC
	bl _08021B16
_080210AC:
	movs r0, #0
	mov sl, r0
	mov r2, r8
	adds r2, #0x38
	mov r1, r8
	ldrb r1, [r1, #0x1c]
	cmp sl, r1
	bge _080210D2
	mov r1, r8
	adds r1, #0x1e
_080210C0:
	ldrh r0, [r1]
	strh r0, [r1, #8]
	adds r1, #2
	movs r3, #1
	add sl, r3
	mov r0, r8
	ldrb r0, [r0, #0x1c]
	cmp sl, r0
	blt _080210C0
_080210D2:
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	movs r1, #0
	mov r3, r8
	strb r0, [r3, #0x1d]
	strb r1, [r3, #0x1c]
	ldrh r0, [r3, #0x18]
	adds r1, r2, #0
	bl FUN_08230f94
	adds r4, r0, #0
	mov r0, r8
	ldr r5, [r0, #0x38]
	b _0802115C
_080210EE:
	ldr r0, [r5, #4]
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #5
	bhi _0802115A
	lsls r0, r1, #2
	ldr r1, _08021104 @ =_08021108
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08021104: .4byte _08021108
_08021108: @ jump table
	.4byte _08021120 @ case 0
	.4byte _0802112A @ case 1
	.4byte _08021134 @ case 2
	.4byte _0802113E @ case 3
	.4byte _08021148 @ case 4
	.4byte _08021152 @ case 5
_08021120:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fc88
	b _0802115A
_0802112A:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fd10
	b _0802115A
_08021134:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fd88
	b _0802115A
_0802113E:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fdf0
	b _0802115A
_08021148:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fe58
	b _0802115A
_08021152:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fe98
_0802115A:
	adds r5, #8
_0802115C:
	adds r0, r4, #0
	subs r4, #1
	cmp r0, #0
	bgt _080210EE
	ldr r0, _080211D0 @ =0x030046A0
	ldr r1, [r0]
	ldr r2, _080211D4 @ =0xFFFF0000
	ldrh r0, [r1, #0x30]
	str r0, [sp]
	ldrh r1, [r1, #0x34]
	mov r3, sp
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	movs r1, #0
	mov sl, r1
	mov r2, r8
	ldrh r2, [r2, #0x1a]
	cmp sl, r2
	blt _08021196
	bl _08021A74
_08021196:
	ldr r2, _080211D8 @ =0x0000042C
	add r2, r8
	movs r0, #0x8c
	mov r1, sl
	muls r1, r0, r1
	ldr r0, [r2]
	adds r7, r0, r1
	adds r0, r7, #0
	adds r0, #0x39
	ldrb r0, [r0]
	strh r0, [r7, #0x10]
	adds r0, r7, #0
	adds r0, #0x44
	ldrb r0, [r0]
	cmp r0, #0
	beq _080211F4
	adds r1, r7, #0
	adds r1, #0x42
	ldr r0, _080211D0 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080211DC
	movs r0, #1
	b _080211DE
	.align 2, 0
_080211D0: .4byte 0x030046A0
_080211D4: .4byte 0xFFFF0000
_080211D8: .4byte 0x0000042C
_080211DC:
	movs r0, #0
_080211DE:
	cmp r0, #0
	beq _080211EC
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _080211F2
_080211EC:
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
_080211F2:
	str r0, [r7]
_080211F4:
	adds r0, r7, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0x10
	bls _08021202
	bl _08021A64
_08021202:
	lsls r0, r0, #2
	ldr r1, _0802120C @ =_08021210
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802120C: .4byte _08021210
_08021210: @ jump table
	.4byte _08021254 @ case 0
	.4byte _08021388 @ case 1
	.4byte _08021390 @ case 2
	.4byte _08021816 @ case 3
	.4byte _08021482 @ case 4
	.4byte _080215B4 @ case 5
	.4byte _080216E8 @ case 6
	.4byte _08021816 @ case 7
	.4byte _08021390 @ case 8
	.4byte _08021390 @ case 9
	.4byte _08021390 @ case 10
	.4byte _08021390 @ case 11
	.4byte _08021390 @ case 12
	.4byte _08021390 @ case 13
	.4byte _08021390 @ case 14
	.4byte _08021840 @ case 15
	.4byte _080218E0 @ case 16
_08021254:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08021266
	bl _08021A64
_08021266:
	adds r0, r7, #0
	bl FUN_0801f764
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _08021378 @ =0x030046A0
	ldr r6, [r0]
	ldrh r0, [r6, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0802137C @ =0xFFFF0000
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r6, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _08021380 @ =0x0000FFFF
	mov ip, r0
	ands r0, r1
	orrs r0, r4
	mov ip, r0
	mov r2, ip
	ldrh r0, [r6, #0x34]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r3
	adds r3, r5, #0
	orrs r3, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08021384 @ =0x00012CC7
	cmp r1, r0
	bgt _080212F0
	mov r3, ip
	asrs r1, r3, #0x10
	cmp r1, #0
	bge _080212CA
	rsbs r1, r1, #0
_080212CA:
	cmp r1, #0xfe
	bgt _080212F0
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _080212F0
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_080212F0:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08020680
	add r6, sp, #8
	adds r0, r6, #0
	bl FUN_08086a28
	cmp r0, #0
	bne _08021306
	b _08021A64
_08021306:
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0802137C @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #2]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _08021380 @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #4]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _08021384 @ =0x00012CC7
	cmp r3, r0
	ble _08021358
	b _08021A64
_08021358:
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _08021362
	rsbs r1, r1, #0
_08021362:
	cmp r1, #0xfe
	ble _08021368
	b _08021A64
_08021368:
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	beq _08021376
	b _08021A64
_08021376:
	b _08021A4E
	.align 2, 0
_08021378: .4byte 0x030046A0
_0802137C: .4byte 0xFFFF0000
_08021380: .4byte 0x0000FFFF
_08021384: .4byte 0x00012CC7
_08021388:
	adds r0, r7, #0
	bl FUN_0801f7f4
	b _08021A64
_08021390:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080213A0
	b _08021A64
_080213A0:
	adds r0, r7, #0
	bl FUN_0801f858
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _08021454 @ =0x030046A0
	ldr r5, [r0]
	ldrh r0, [r5, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08021458 @ =0xFFFF0000
	mov sb, r1
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r5, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r6, _0802145C @ =0x0000FFFF
	ands r6, r1
	orrs r6, r4
	adds r2, r6, #0
	ldrh r1, [r5, #0x34]
	subs r1, r3, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r0, sb
	ands r0, r3
	adds r3, r0, #0
	orrs r3, r1
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08021460 @ =0x00012CC7
	cmp r1, r0
	bgt _0802147E
	asrs r1, r6, #0x10
	cmp r1, #0
	bge _08021400
	rsbs r1, r1, #0
_08021400:
	cmp r1, #0xfe
	bgt _0802147E
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _0802147E
	adds r0, r7, #0
	adds r0, #0x41
	ldrb r0, [r0]
	cmp r0, #0
	bne _08021468
	ldr r0, _08021464 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802147E
	mov r0, r8
	adds r1, r7, #0
	bl FUN_0801fb08
	cmp r0, #0
	bne _0802147E
	ldr r0, [r7, #0x48]
	cmp r0, #0
	beq _0802147E
	ldr r0, [sp, #0x10]
	mov r3, sb
	ands r0, r3
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r0, r7, #0
	adds r0, #0x50
	add r1, sp, #0x10
	str r0, [r1, #4]
	ldr r0, [r7, #0x48]
	bl Script_ExecById
	b _0802147E
	.align 2, 0
_08021454: .4byte 0x030046A0
_08021458: .4byte 0xFFFF0000
_0802145C: .4byte 0x0000FFFF
_08021460: .4byte 0x00012CC7
_08021464: .4byte 0x030044E0
_08021468:
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_0802147E:
	add r6, sp, #0x18
	b _080219D0
_08021482:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08021492
	b _08021A64
_08021492:
	adds r0, r7, #0
	bl FUN_0801f764
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _080215A4 @ =0x030046A0
	ldr r6, [r0]
	ldrh r0, [r6, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080215A8 @ =0xFFFF0000
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r6, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _080215AC @ =0x0000FFFF
	mov ip, r0
	ands r0, r1
	orrs r0, r4
	mov ip, r0
	mov r2, ip
	ldrh r0, [r6, #0x34]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r3
	adds r3, r5, #0
	orrs r3, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _080215B0 @ =0x00012CC7
	cmp r1, r0
	bgt _0802151C
	mov r3, ip
	asrs r1, r3, #0x10
	cmp r1, #0
	bge _080214F6
	rsbs r1, r1, #0
_080214F6:
	cmp r1, #0xfe
	bgt _0802151C
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _0802151C
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_0802151C:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08020680
	add r6, sp, #0x20
	adds r0, r6, #0
	bl FUN_08086a28
	cmp r0, #0
	bne _08021532
	b _08021A64
_08021532:
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080215A8 @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #2]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _080215AC @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #4]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _080215B0 @ =0x00012CC7
	cmp r3, r0
	ble _08021584
	b _08021A64
_08021584:
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _0802158E
	rsbs r1, r1, #0
_0802158E:
	cmp r1, #0xfe
	ble _08021594
	b _08021A64
_08021594:
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	beq _080215A2
	b _08021A64
_080215A2:
	b _08021A4E
	.align 2, 0
_080215A4: .4byte 0x030046A0
_080215A8: .4byte 0xFFFF0000
_080215AC: .4byte 0x0000FFFF
_080215B0: .4byte 0x00012CC7
_080215B4:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080215C4
	b _08021A64
_080215C4:
	adds r0, r7, #0
	bl FUN_0801f764
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _080216D8 @ =0x030046A0
	ldr r6, [r0]
	ldrh r0, [r6, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080216DC @ =0xFFFF0000
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r6, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _080216E0 @ =0x0000FFFF
	mov ip, r0
	ands r0, r1
	orrs r0, r4
	mov ip, r0
	mov r2, ip
	ldrh r0, [r6, #0x34]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r3
	adds r3, r5, #0
	orrs r3, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _080216E4 @ =0x00012CC7
	cmp r1, r0
	bgt _0802164E
	mov r3, ip
	asrs r1, r3, #0x10
	cmp r1, #0
	bge _08021628
	rsbs r1, r1, #0
_08021628:
	cmp r1, #0xfe
	bgt _0802164E
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _0802164E
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_0802164E:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08020680
	add r6, sp, #0x28
	adds r0, r6, #0
	bl FUN_08086a28
	cmp r0, #0
	bne _08021664
	b _08021A64
_08021664:
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080216DC @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #2]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _080216E0 @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #4]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _080216E4 @ =0x00012CC7
	cmp r3, r0
	ble _080216B6
	b _08021A64
_080216B6:
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _080216C0
	rsbs r1, r1, #0
_080216C0:
	cmp r1, #0xfe
	ble _080216C6
	b _08021A64
_080216C6:
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	beq _080216D4
	b _08021A64
_080216D4:
	b _08021A4E
	.align 2, 0
_080216D8: .4byte 0x030046A0
_080216DC: .4byte 0xFFFF0000
_080216E0: .4byte 0x0000FFFF
_080216E4: .4byte 0x00012CC7
_080216E8:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080216F8
	b _08021A64
_080216F8:
	adds r0, r7, #0
	bl FUN_0801f764
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _08021830 @ =0x030046A0
	ldr r6, [r0]
	ldrh r0, [r6, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08021834 @ =0xFFFF0000
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r6, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _08021838 @ =0x0000FFFF
	mov ip, r0
	ands r0, r1
	orrs r0, r4
	mov ip, r0
	mov r2, ip
	ldrh r0, [r6, #0x34]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r3
	adds r3, r5, #0
	orrs r3, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0802183C @ =0x00012CC7
	cmp r1, r0
	bgt _08021782
	mov r3, ip
	asrs r1, r3, #0x10
	cmp r1, #0
	bge _0802175C
	rsbs r1, r1, #0
_0802175C:
	cmp r1, #0xfe
	bgt _08021782
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _08021782
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_08021782:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08020680
	add r6, sp, #0x30
	adds r0, r6, #0
	bl FUN_08086a28
	cmp r0, #0
	beq _08021816
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08021834 @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #2]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _08021838 @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #4]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _0802183C @ =0x00012CC7
	cmp r3, r0
	bgt _08021816
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _080217F0
	rsbs r1, r1, #0
_080217F0:
	cmp r1, #0xfe
	bgt _08021816
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _08021816
	mov r3, r8
	ldrb r0, [r3, #0x1c]
	lsls r0, r0, #1
	mov r1, r8
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	ldrb r0, [r3, #0x1c]
	adds r0, #1
	strb r0, [r3, #0x1c]
_08021816:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08021826
	b _08021A64
_08021826:
	adds r0, r7, #0
	bl FUN_0801f764
	b _08021A64
	.align 2, 0
_08021830: .4byte 0x030046A0
_08021834: .4byte 0xFFFF0000
_08021838: .4byte 0x0000FFFF
_0802183C: .4byte 0x00012CC7
_08021840:
	adds r0, r7, #0
	bl FUN_0801f764
	ldr r0, _080218CC @ =0x030046A0
	ldr r6, [r0]
	ldr r1, _080218D0 @ =0x00000942
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	bgt _08021858
	b _08021A64
_08021858:
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6, #0x30]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080218D4 @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _080218D8 @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #0x34]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _080218DC @ =0x00012CC7
	cmp r3, r0
	ble _080218AA
	b _08021A64
_080218AA:
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _080218B4
	rsbs r1, r1, #0
_080218B4:
	cmp r1, #0xfe
	ble _080218BA
	b _08021A64
_080218BA:
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	beq _080218C8
	b _08021A64
_080218C8:
	b _08021A4E
	.align 2, 0
_080218CC: .4byte 0x030046A0
_080218D0: .4byte 0x00000942
_080218D4: .4byte 0xFFFF0000
_080218D8: .4byte 0x0000FFFF
_080218DC: .4byte 0x00012CC7
_080218E0:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080218F0
	b _08021A64
_080218F0:
	adds r0, r7, #0
	bl FUN_0801f858
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _080219A4 @ =0x030046A0
	ldr r5, [r0]
	ldrh r0, [r5, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080219A8 @ =0xFFFF0000
	mov sb, r1
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r5, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r6, _080219AC @ =0x0000FFFF
	ands r6, r1
	orrs r6, r4
	adds r2, r6, #0
	ldrh r1, [r5, #0x34]
	subs r1, r3, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r0, sb
	ands r0, r3
	adds r3, r0, #0
	orrs r3, r1
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _080219B0 @ =0x00012CC7
	cmp r1, r0
	bgt _080219CE
	asrs r1, r6, #0x10
	cmp r1, #0
	bge _08021950
	rsbs r1, r1, #0
_08021950:
	cmp r1, #0xfe
	bgt _080219CE
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _080219CE
	adds r0, r7, #0
	adds r0, #0x41
	ldrb r0, [r0]
	cmp r0, #0
	bne _080219B8
	ldr r0, _080219B4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080219CE
	mov r0, r8
	adds r1, r7, #0
	bl FUN_0801fb08
	cmp r0, #0
	bne _080219CE
	ldr r0, [r7, #0x48]
	cmp r0, #0
	beq _080219CE
	ldr r0, [sp, #0x38]
	mov r3, sb
	ands r0, r3
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x38]
	adds r0, r7, #0
	adds r0, #0x50
	add r1, sp, #0x38
	str r0, [r1, #4]
	ldr r0, [r7, #0x48]
	bl Script_ExecById
	b _080219CE
	.align 2, 0
_080219A4: .4byte 0x030046A0
_080219A8: .4byte 0xFFFF0000
_080219AC: .4byte 0x0000FFFF
_080219B0: .4byte 0x00012CC7
_080219B4: .4byte 0x030044E0
_080219B8:
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_080219CE:
	add r6, sp, #0x40
_080219D0:
	adds r0, r6, #0
	bl FUN_08086a28
	cmp r0, #0
	beq _08021A64
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08021AB0 @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #2]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _08021AB4 @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #4]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _08021AB8 @ =0x00012CC7
	cmp r3, r0
	bgt _08021A64
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _08021A34
	rsbs r1, r1, #0
_08021A34:
	cmp r1, #0xfe
	bgt _08021A64
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _08021A64
	adds r0, r7, #0
	adds r0, #0x41
	ldrb r0, [r0]
	cmp r0, #0
	beq _08021A64
_08021A4E:
	mov r3, r8
	ldrb r0, [r3, #0x1c]
	lsls r0, r0, #1
	mov r1, r8
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	ldrb r0, [r3, #0x1c]
	adds r0, #1
	strb r0, [r3, #0x1c]
_08021A64:
	movs r0, #1
	add sl, r0
	mov r1, r8
	ldrh r1, [r1, #0x1a]
	cmp sl, r1
	bge _08021A74
	bl _08021196
_08021A74:
	movs r2, #0
	mov sl, r2
	mov r3, r8
	ldrb r3, [r3, #0x1d]
	cmp sl, r3
	bge _08021AAA
_08021A80:
	mov r0, sl
	lsls r1, r0, #1
	mov r0, r8
	adds r0, #0x26
	adds r4, r0, r1
	ldrh r1, [r4]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _08021A9E
	ldrh r1, [r4]
	mov r0, r8
	bl FUN_0801fd10
_08021A9E:
	movs r1, #1
	add sl, r1
	mov r2, r8
	ldrb r2, [r2, #0x1d]
	cmp sl, r2
	blt _08021A80
_08021AAA:
	movs r3, #0
	mov sl, r3
	b _08021ADE
	.align 2, 0
_08021AB0: .4byte 0xFFFF0000
_08021AB4: .4byte 0x0000FFFF
_08021AB8: .4byte 0x00012CC7
_08021ABC:
	mov r2, sl
	lsls r1, r2, #1
	mov r0, r8
	adds r0, #0x1e
	adds r4, r0, r1
	ldrh r1, [r4]
	mov r0, r8
	bl FUN_0801fad8
	cmp r0, #0
	bne _08021ADA
	ldrh r1, [r4]
	mov r0, r8
	bl FUN_0801fc88
_08021ADA:
	movs r3, #1
	add sl, r3
_08021ADE:
	mov r0, r8
	ldrb r0, [r0, #0x1c]
	cmp sl, r0
	blt _08021ABC
	movs r1, #0
	mov sl, r1
	mov r2, r8
	ldrh r2, [r2, #0x1a]
	cmp sl, r2
	bge _08021B16
	ldr r4, _08021B28 @ =0x0000042C
	add r4, r8
_08021AF6:
	movs r0, #0x8c
	mov r1, sl
	muls r1, r0, r1
	ldr r0, [r4]
	adds r0, r0, r1
	ldr r1, [r0, #0x30]
	cmp r1, #0
	beq _08021B0A
	bl _call_via_r1
_08021B0A:
	movs r3, #1
	add sl, r3
	mov r0, r8
	ldrh r0, [r0, #0x1a]
	cmp sl, r0
	blt _08021AF6
_08021B16:
	movs r0, #0
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08021B28: .4byte 0x0000042C

	thumb_func_start Entity6D69_Destroy
Entity6D69_Destroy: @ 0x08021B2C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r6, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _08021B64
	ldr r1, _08021BD0 @ =0x0000042C
	adds r7, r5, r1
_08021B3C:
	movs r0, #0x8c
	adds r1, r6, #0
	muls r1, r0, r1
	ldr r0, [r7]
	adds r4, r0, r1
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _08021B56
	bl FUN_082342a8
	ldr r0, [r4, #0x2c]
	bl Free
_08021B56:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r6, #1
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	blt _08021B3C
_08021B64:
	ldr r0, [r5, #0x34]
	cmp r0, #0
	beq _08021BB8
	movs r1, #0x82
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	ldr r1, _08021BD4 @ =0x00000414
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	movs r1, #0x83
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	ldr r1, _08021BD8 @ =0x0000041C
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	movs r1, #0x84
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	ldr r1, _08021BDC @ =0x00000424
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	movs r1, #0x85
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
_08021BB8:
	ldr r1, _08021BD0 @ =0x0000042C
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	ldr r0, _08021BE0 @ =0x000085E6
	bl FUN_08230e58
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08021BD0: .4byte 0x0000042C
_08021BD4: .4byte 0x00000414
_08021BD8: .4byte 0x0000041C
_08021BDC: .4byte 0x00000424
_08021BE0: .4byte 0x000085E6

	thumb_func_start Entity6D69_Init
Entity6D69_Init: @ 0x08021BE4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0
	strh r1, [r7, #0x18]
	strh r0, [r7, #0x2e]
	strh r0, [r7, #0x1a]
	movs r0, #0x65
	movs r1, #1
	bl Script_GetKeywordValue
	adds r1, r0, #0
	str r1, [r7, #0x34]
	cmp r1, #0
	beq _08021CF0
	movs r0, #0x8c
	bl Malloc
	movs r1, #0x82
	lsls r1, r1, #3
	adds r4, r7, r1
	str r0, [r4]
	movs r0, #0x8c
	bl Malloc
	ldr r2, _08021CAC @ =0x00000414
	adds r2, r2, r7
	mov sb, r2
	str r0, [r2]
	movs r0, #0x8c
	bl Malloc
	movs r1, #0x83
	lsls r1, r1, #3
	adds r1, r1, r7
	mov sl, r1
	str r0, [r1]
	movs r0, #0x8c
	bl Malloc
	ldr r2, _08021CB0 @ =0x0000041C
	adds r2, r2, r7
	mov r8, r2
	str r0, [r2]
	movs r0, #0x8c
	bl Malloc
	movs r1, #0x84
	lsls r1, r1, #3
	adds r6, r7, r1
	str r0, [r6]
	movs r0, #0x8c
	bl Malloc
	ldr r2, _08021CB4 @ =0x00000424
	adds r5, r7, r2
	str r0, [r5]
	movs r0, #0x8c
	bl Malloc
	adds r1, r0, #0
	movs r0, #0x85
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp]
	str r1, [r0]
	ldr r4, [r4]
	cmp r4, #0
	beq _08021C9E
	mov r2, sb
	ldr r0, [r2]
	cmp r0, #0
	beq _08021C9E
	mov r2, sl
	ldr r0, [r2]
	cmp r0, #0
	beq _08021C9E
	mov r2, r8
	ldr r0, [r2]
	cmp r0, #0
	beq _08021C9E
	ldr r0, [r6]
	cmp r0, #0
	beq _08021C9E
	ldr r0, [r5]
	cmp r0, #0
	beq _08021C9E
	cmp r1, #0
	bne _08021CB8
_08021C9E:
	adds r0, r7, #0
	bl KillEntity
_08021CA4:
	movs r0, #1
	rsbs r0, r0, #0
	b _08022058
	.align 2, 0
_08021CAC: .4byte 0x00000414
_08021CB0: .4byte 0x0000041C
_08021CB4: .4byte 0x00000424
_08021CB8:
	adds r0, r4, #0
	movs r1, #0x8c
	bl ClearMemory
	mov r1, sb
	ldr r0, [r1]
	movs r1, #0x8c
	bl ClearMemory
	mov r2, r8
	ldr r0, [r2]
	movs r1, #0x8c
	bl ClearMemory
	ldr r0, [r6]
	movs r1, #0x8c
	bl ClearMemory
	ldr r0, [r5]
	movs r1, #0x8c
	bl ClearMemory
	ldr r1, [sp]
	ldr r0, [r1]
	movs r1, #0x8c
	bl ClearMemory
	b _08021D1C
_08021CF0:
	movs r2, #0x82
	lsls r2, r2, #3
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
_08021D1C:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _08021D58
	movs r5, #0
	adds r4, r7, #0
	adds r4, #0x3c
_08021D2C:
	bl VM_GetPC
	cmp r0, #0
	beq _08021D3E
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _08021D40
_08021D3E:
	ldr r1, _08021D54 @ =0x00007ACD
_08021D40:
	adds r0, r4, #0
	bl Video_GetActorSprite
	cmp r0, #0
	beq _08021CA4
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021D2C
	b _08021D72
	.align 2, 0
_08021D54: .4byte 0x00007ACD
_08021D58:
	movs r5, #0
	adds r4, r7, #0
	adds r4, #0x3c
_08021D5E:
	adds r0, r4, #0
	ldr r1, _08021D9C @ =0x00007ACD
	bl Video_GetActorSprite
	cmp r0, #0
	beq _08021CA4
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021D5E
_08021D72:
	movs r0, #0x6b
	bl prepare_08231510
	cmp r0, #0
	beq _08021E40
	movs r5, #0
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
	movs r6, #0
_08021D88:
	bl VM_GetPC
	cmp r0, #0
	beq _08021DA0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _08021DA2
	.align 2, 0
_08021D9C: .4byte 0x00007ACD
_08021DA0:
	ldr r4, _08021E30 @ =0x00007AD3
_08021DA2:
	mov r0, r8
	adds r1, r4, #0
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08021DB0
	b _08021CA4
_08021DB0:
	ldr r0, [r7, #0x34]
	cmp r0, #0
	beq _08021E20
	movs r1, #0x82
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl Video_GetActorSprite
	ldr r2, _08021E34 @ =0x00000414
	adds r0, r7, r2
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl Video_GetActorSprite
	movs r1, #0x83
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl Video_GetActorSprite
	ldr r2, _08021E38 @ =0x0000041C
	adds r0, r7, r2
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl Video_GetActorSprite
	movs r1, #0x84
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl Video_GetActorSprite
	ldr r2, _08021E3C @ =0x00000424
	adds r0, r7, r2
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl Video_GetActorSprite
	movs r1, #0x85
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl Video_GetActorSprite
_08021E20:
	movs r2, #0x1c
	add r8, r2
	adds r6, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021D88
	b _08021E5E
	.align 2, 0
_08021E30: .4byte 0x00007AD3
_08021E34: .4byte 0x00000414
_08021E38: .4byte 0x0000041C
_08021E3C: .4byte 0x00000424
_08021E40:
	movs r5, #0
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r4, r7, r0
_08021E48:
	adds r0, r4, #0
	ldr r1, _08021E7C @ =0x00007AD3
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08021E56
	b _08021CA4
_08021E56:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021E48
_08021E5E:
	movs r0, #0x53
	bl prepare_08231510
	cmp r0, #0
	beq _08021EA4
	bl VM_GetPC
	cmp r0, #0
	beq _08021E80
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	b _08021E82
	.align 2, 0
_08021E7C: .4byte 0x00007AD3
_08021E80:
	ldr r6, _08021EA0 @ =0x00007AD2
_08021E82:
	movs r5, #0
	adds r4, r7, #0
	adds r4, #0xc8
_08021E88:
	adds r0, r4, #0
	adds r1, r6, #0
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08021E96
	b _08021CA4
_08021E96:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021E88
	b _08021EC0
	.align 2, 0
_08021EA0: .4byte 0x00007AD2
_08021EA4:
	movs r5, #0
	adds r4, r7, #0
	adds r4, #0xc8
_08021EAA:
	adds r0, r4, #0
	ldr r1, _08021EEC @ =0x00007AD2
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08021EB8
	b _08021CA4
_08021EB8:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021EAA
_08021EC0:
	movs r0, #0x62
	bl prepare_08231510
	cmp r0, #0
	beq _08021F20
	movs r5, #0
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r6, r7, r2
_08021EDA:
	bl VM_GetPC
	cmp r0, #0
	beq _08021EF0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _08021EF2
	.align 2, 0
_08021EEC: .4byte 0x00007AD2
_08021EF0:
	ldr r4, _08021F1C @ =0x00007AEE
_08021EF2:
	adds r0, r6, #0
	adds r1, r4, #0
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08021F00
	b _08021CA4
_08021F00:
	mov r0, r8
	adds r1, r4, #0
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08021F0E
	b _08021CA4
_08021F0E:
	movs r0, #0x1c
	add r8, r0
	adds r6, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021EDA
	b _08021F54
	.align 2, 0
_08021F1C: .4byte 0x00007AEE
_08021F20:
	movs r5, #0
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r6, r7, r1
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r4, r7, r2
_08021F2E:
	adds r0, r4, #0
	ldr r1, _08021F78 @ =0x00007AD3
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08021F3C
	b _08021CA4
_08021F3C:
	adds r0, r6, #0
	ldr r1, _08021F78 @ =0x00007AD3
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08021F4A
	b _08021CA4
_08021F4A:
	adds r6, #0x1c
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021F2E
_08021F54:
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _08021F98
	movs r5, #0
	movs r0, #0xbe
	lsls r0, r0, #2
	adds r4, r7, r0
_08021F66:
	bl VM_GetPC
	cmp r0, #0
	beq _08021F7C
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _08021F7E
	.align 2, 0
_08021F78: .4byte 0x00007AD3
_08021F7C:
	ldr r1, _08021F94 @ =0x00007AF3
_08021F7E:
	adds r0, r4, #0
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08021F8A
	b _08021CA4
_08021F8A:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021F66
	b _08021FB6
	.align 2, 0
_08021F94: .4byte 0x00007AF3
_08021F98:
	movs r5, #0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r4, r7, r1
_08021FA0:
	adds r0, r4, #0
	ldr r1, _08021FDC @ =0x00007AF3
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08021FAE
	b _08021CA4
_08021FAE:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021FA0
_08021FB6:
	movs r0, #0x75
	bl prepare_08231510
	cmp r0, #0
	beq _08021FFC
	movs r5, #0
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r4, r7, r2
_08021FC8:
	bl VM_GetPC
	cmp r0, #0
	beq _08021FE0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _08021FE2
	.align 2, 0
_08021FDC: .4byte 0x00007AF3
_08021FE0:
	ldr r1, _08021FF8 @ =0x00007AF3
_08021FE2:
	adds r0, r4, #0
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08021FEE
	b _08021CA4
_08021FEE:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021FC8
	b _0802201A
	.align 2, 0
_08021FF8: .4byte 0x00007AF3
_08021FFC:
	movs r5, #0
	movs r0, #0xe1
	lsls r0, r0, #2
	adds r4, r7, r0
_08022004:
	adds r0, r4, #0
	ldr r1, _08022068 @ =0x00007AF3
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08022012
	b _08021CA4
_08022012:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08022004
_0802201A:
	movs r0, #0x6d
	movs r1, #0x10
	bl Script_GetKeywordValue
	str r0, [r7, #0x30]
	movs r4, #0x8c
	muls r0, r4, r0
	bl Malloc
	ldr r2, _0802206C @ =0x0000042C
	adds r1, r7, r2
	str r0, [r1]
	ldr r1, [r7, #0x30]
	muls r1, r4, r1
	bl ClearMemory
	adds r1, r7, #0
	adds r1, #0x1e
	movs r2, #0
	adds r0, r7, #0
	adds r0, #0x24
_08022044:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _08022044
	ldr r0, _08022070 @ =0x000085E6
	adds r1, r7, #0
	movs r2, #0
	bl FUN_08230e30
	movs r0, #0
_08022058:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08022068: .4byte 0x00007AF3
_0802206C: .4byte 0x0000042C
_08022070: .4byte 0x000085E6

	thumb_func_start Entity6D69_Create
Entity6D69_Create: @ 0x08022074
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _080220A8 @ =0x00000434
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080220B4
	ldr r1, _080220AC @ =Entity6D69_Update
	ldr r2, _080220B0 @ =Entity6D69_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity6D69_Init
	cmp r0, #0
	bge _080220B4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080220B6
	.align 2, 0
_080220A8: .4byte 0x00000434
_080220AC: .4byte Entity6D69_Update
_080220B0: .4byte Entity6D69_Destroy
_080220B4:
	adds r0, r4, #0
_080220B6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

