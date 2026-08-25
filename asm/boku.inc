	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ffd28
FUN_080ffd28: @ 0x080FFD28
	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r2, #0xce
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080FFD42
	subs r0, #1
	strh r0, [r1]
_080FFD42:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ffd48
FUN_080ffd48: @ 0x080FFD48
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x9c
	ldr r2, _080FFD9C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080FFDA0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080FFDA4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldrb r0, [r4, #2]
	cmp r1, r0
	bne _080FFD82
	adds r0, r1, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_080FFD82:
	movs r0, #0
	strb r1, [r4, #2]
	strb r0, [r4, #3]
	ldr r0, [r4, #4]
	bl FUN_08234f6c
	ldrb r1, [r4, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080FFD9C: .4byte 0x030046B8
_080FFDA0: .4byte 0x000003FF
_080FFDA4: .4byte 0x0203B400

	thumb_func_start FUN_080ffda8
FUN_080ffda8: @ 0x080FFDA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	movs r0, #0x9c
	adds r0, r0, r5
	mov r8, r0
	movs r1, #0
	mov sb, r1
	mov sl, r1
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r2, [r0]
	movs r3, #8
	ldrsh r0, [r2, r3]
	movs r6, #8
	ldrsh r1, [r5, r6]
	subs r0, r0, r1
	movs r7, #0xc
	ldrsh r1, [r2, r7]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _080FFE9C @ =0x085B0A08
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r6, #0
	ldrsh r1, [r1, r6]
	lsls r2, r1, #2
	adds r2, r2, r1
	lsls r2, r2, #5
	lsrs r2, r2, #0x10
	ldr r7, _080FFEA0 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r7
	orrs r1, r2
	str r1, [sp]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #4]
	mov r3, r8
	ldr r0, [r3, #4]
	bl FUN_08234f6c
	adds r4, r0, #0
	movs r6, #0
	mov r1, r8
	ldr r0, [r1, #4]
	ldrb r0, [r0]
	cmp sb, r0
	bge _080FFEB2
	mov ip, r7
	add r3, sp, #8
	mov r2, sp
	str r2, [sp, #0x10]
_080FFE40:
	ldrh r1, [r4]
	ldrh r0, [r5, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #8]
	mov r7, ip
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #8]
	ldrh r1, [r4, #2]
	ldrh r0, [r5, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r3, #4]
	ands r0, r7
	orrs r0, r1
	str r0, [r3, #4]
	ldr r0, [sp, #0x10]
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r1, r0, r1
	ldr r0, [sp, #0x10]
	movs r7, #4
	ldrsh r2, [r0, r7]
	movs r7, #4
	ldrsh r0, [r3, r7]
	muls r0, r2, r0
	adds r1, r1, r0
	cmp r1, #0
	bge _080FFEA4
	ldr r1, [r4]
	adds r0, r5, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r1, r0
	beq _080FFEA6
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	b _080FFF14
	.align 2, 0
_080FFE9C: .4byte 0x085B0A08
_080FFEA0: .4byte 0xFFFF0000
_080FFEA4:
	adds r4, #8
_080FFEA6:
	adds r6, #1
	mov r1, r8
	ldr r0, [r1, #4]
	ldrb r0, [r0]
	cmp r6, r0
	blt _080FFE40
_080FFEB2:
	mov r2, sl
	cmp r2, #0
	bne _080FFF14
	adds r4, r5, #0
	adds r4, #0x9c
	ldr r2, _080FFF08 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080FFF0C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080FFF10 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r6, [r4, #2]
	cmp r0, r6
	bne _080FFEF0
	adds r0, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080FFEF0:
	strb r0, [r4, #2]
	mov r7, sl
	strb r7, [r4, #3]
	ldr r0, [r4, #4]
	bl FUN_08234f6c
	ldrb r1, [r4, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #8]
	b _080FFF24
	.align 2, 0
_080FFF08: .4byte 0x030046B8
_080FFF0C: .4byte 0x000003FF
_080FFF10: .4byte 0x0203B400
_080FFF14:
	movs r0, #0
	mov r2, sb
	mov r1, r8
	strb r2, [r1, #2]
	strb r0, [r1, #3]
	str r4, [r1, #8]
	adds r4, r5, #0
	adds r4, #0x9c
_080FFF24:
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r6, [r0]
	ldr r0, [r4, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r4, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _080FFF58
	cmp r1, #0
	blt _080FFF58
	ldr r0, _080FFF5C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080FFF58
	ldr r0, _080FFF60 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FFF64
_080FFF58:
	movs r4, #0
	b _080FFF72
	.align 2, 0
_080FFF5C: .4byte 0x030046A8
_080FFF60: .4byte 0x030046AC
_080FFF64:
	ldr r0, _080FFF84 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080FFF72:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FFF88
	adds r0, #4
	b _080FFF94
	.align 2, 0
_080FFF84: .4byte 0x030046A4
_080FFF88:
	ldr r0, _080FFFA8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FFF94:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080FFFAC
	cmp r2, #2
	beq _080FFFB0
	b _080FFFB4
	.align 2, 0
_080FFFA8: .4byte 0x030046A4
_080FFFAC:
	ldrb r0, [r6, #4]
	b _080FFFB2
_080FFFB0:
	ldrb r0, [r6]
_080FFFB2:
	subs r1, r1, r0
_080FFFB4:
	strh r1, [r6, #2]
	ldr r6, _080FFFE0 @ =0x000004A4
	adds r0, r5, r6
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080FFFE4
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _0810000A
	.align 2, 0
_080FFFE0: .4byte 0x000004A4
_080FFFE4:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08100004
	cmp r0, #2
	beq _08100000
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08100000:
	movs r0, #1
	b _08100014
_08100004:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_0810000A:
	ldr r1, _08100068 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08100014:
	adds r4, r0, #0
	cmp r4, #0
	bne _08100088
	ldr r1, _0810006C @ =FUN_080e48d0
	ldr r6, _08100070 @ =0x0000046D
	adds r0, r5, r6
	movs r3, #1
	strb r3, [r0]
	ldr r7, _08100074 @ =0x0000046B
	adds r0, r5, r7
	strb r4, [r0]
	ldr r2, _08100078 @ =0x00000553
	adds r0, r5, r2
	strb r4, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r7, _0810007C @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _08100080 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _08100084 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r6, #4
	adds r0, r5, r6
	strb r3, [r0]
	b _08100094
	.align 2, 0
_08100068: .4byte 0xFFFFFDFF
_0810006C: .4byte FUN_080e48d0
_08100070: .4byte 0x0000046D
_08100074: .4byte 0x0000046B
_08100078: .4byte 0x00000553
_0810007C: .4byte 0x00000469
_08100080: .4byte 0x0000046A
_08100084: .4byte 0x00000484
_08100088:
	movs r7, #0x95
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_08100094:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081000a4
FUN_081000a4: @ 0x081000A4
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _08100150 @ =0x0000067E
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _08100154 @ =0x0000067C
	adds r0, r5, r3
	movs r2, #0
	mov sb, r2
	strh r1, [r0]
	movs r3, #1
	mov r8, r3
	ldr r0, _08100158 @ =0x0000065C
	adds r5, r5, r0
	ldrh r1, [r5]
	movs r3, #0
	mov r0, r8
	orrs r0, r1
	movs r6, #3
	rsbs r6, r6, #0
	ands r0, r6
	strh r0, [r5]
	movs r2, #4
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xf
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r3, [r0]
	ldr r3, _0810015C @ =0x0000046A
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08100160 @ =0x00000484
	adds r0, r4, r1
	mov r2, sb
	str r2, [r0]
	adds r3, #2
	adds r0, r4, r3
	movs r2, #1
	mov r1, r8
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x9c
	adds r3, #0x4a
	adds r0, r4, r3
	ldrb r0, [r0]
	eors r2, r0
	subs r3, #2
	adds r0, r4, r3
	adds r0, r0, r2
	ldrb r2, [r0]
	mov r0, sb
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823b490
	adds r0, r4, #0
	bl FUN_080ffda8
	ldrh r0, [r5]
	ands r6, r0
	strh r6, [r5]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08100150: .4byte 0x0000067E
_08100154: .4byte 0x0000067C
_08100158: .4byte 0x0000065C
_0810015C: .4byte 0x0000046A
_08100160: .4byte 0x00000484

	thumb_func_start FUN_08100164
FUN_08100164: @ 0x08100164
	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r0, #0x78
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _081001BC
	bl VM_GetPC
	cmp r0, #0
	beq _0810018A
	bl Script_GetValue
	adds r1, r0, #0
	b _0810018C
_0810018A:
	movs r1, #0
_0810018C:
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081001A4
	bl Script_GetValue
	adds r2, r0, #0
	b _081001A6
_081001A4:
	movs r2, #0
_081001A6:
	ldr r1, _081001B4 @ =0x0000065A
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _081001B8 @ =0x0000065B
	b _081001CE
	.align 2, 0
_081001B4: .4byte 0x0000065A
_081001B8: .4byte 0x0000065B
_081001BC:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	ldr r2, _081001D8 @ =0x0000065A
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
_081001CE:
	adds r0, r4, r2
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081001D8: .4byte 0x0000065A

	thumb_func_start FUN_081001dc
FUN_081001dc: @ 0x081001DC
	push {r4, r5, r6, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r5, r1, r2
	ldrh r0, [r5]
	cmp r0, #0
	beq _0810021C
	ldr r0, _08100224 @ =0x0000065B
	adds r4, r1, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r2, #2
	adds r6, r1, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r6]
	cmp r0, r1
	blo _0810021C
	ldrh r0, [r5]
	movs r1, #0
	bl Script_ExecById
	movs r1, #0
	movs r0, #0
	strh r0, [r5]
	strb r1, [r6]
	strb r1, [r4]
_0810021C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08100224: .4byte 0x0000065B

	thumb_func_start FUN_08100228
FUN_08100228: @ 0x08100228
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x100
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08100272
	ldr r3, _08100264 @ =0x0000048A
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0810026C
	ldr r0, _08100268 @ =0x00000211
	bl PlaySound_082406e0
	b _08100272
	.align 2, 0
_08100264: .4byte 0x0000048A
_08100268: .4byte 0x00000211
_0810026C:
	movs r0, #0xd4
	bl PlaySound_082406e0
_08100272:
	adds r0, r7, #0
	bl FUN_081001dc
	movs r0, #0x80
	lsls r0, r0, #6
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r7, r4
	ldrh r3, [r1]
	adds r2, r3, #0
	ands r0, r2
	str r1, [sp, #0xf0]
	cmp r0, #0
	bne _08100290
	b _081009F0
_08100290:
	ldr r5, _0810031C @ =0x000001DD
	adds r0, r7, r5
	ldrb r0, [r0]
	adds r0, #0x80
	movs r4, #0
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, _08100320 @ =0xFFFFDFDF
	ldr r6, [sp, #0xf0]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r0, _08100324 @ =0x00000544
	adds r1, r7, r0
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r0, [r0]
	strh r4, [r0, #6]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _08100328 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r3, r7, r5
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xd0]
	str r2, [sp, #0xdc]
	cmp r5, #0
	blt _08100316
	cmp r1, #0
	blt _08100316
	ldr r0, _0810032C @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08100316
	ldr r0, _08100330 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08100334
_08100316:
	movs r4, #0
	b _08100342
	.align 2, 0
_0810031C: .4byte 0x000001DD
_08100320: .4byte 0xFFFFDFDF
_08100324: .4byte 0x00000544
_08100328: .4byte 0x03002BE0
_0810032C: .4byte 0x030046A8
_08100330: .4byte 0x030046AC
_08100334:
	ldr r0, _08100354 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_08100342:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08100358
	adds r0, #4
	b _08100364
	.align 2, 0
_08100354: .4byte 0x030046A4
_08100358:
	ldr r0, _08100378 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08100364:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810037C
	cmp r2, #2
	beq _08100380
	b _08100384
	.align 2, 0
_08100378: .4byte 0x030046A4
_0810037C:
	ldrb r0, [r6, #4]
	b _08100382
_08100380:
	ldrb r0, [r6]
_08100382:
	subs r1, r1, r0
_08100384:
	strh r1, [r6, #2]
	ldr r0, _08100398 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0810039C
	movs r0, #1
	b _0810039E
	.align 2, 0
_08100398: .4byte 0x030047A4
_0810039C:
	movs r0, #0
_0810039E:
	cmp r0, #0
	beq _081003DC
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081003BE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081003BA
	adds r2, r0, #0
_081003BA:
	cmp r2, #0
	bge _081003C8
_081003BE:
	ldr r2, _081003C4 @ =0x000005C4
	adds r0, r7, r2
	b _081008F4
	.align 2, 0
_081003C4: .4byte 0x000005C4
_081003C8:
	ldr r1, _081003D8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08100424
	.align 2, 0
_081003D8: .4byte 0x03002BE0
_081003DC:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08100408
	cmp r1, #0
	blt _08100408
	ldr r0, _0810040C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08100408
	ldr r0, _08100410 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08100414
_08100408:
	movs r5, #0
	b _08100422
	.align 2, 0
_0810040C: .4byte 0x030046A8
_08100410: .4byte 0x030046AC
_08100414:
	ldr r0, _0810045C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08100422:
	movs r2, #0
_08100424:
	ldr r4, _08100460 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08100444
	ldr r1, _08100464 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08100444
	b _08100834
_08100444:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0xf0]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
	cmp r0, #0
	beq _08100468
	movs r0, #0
	b _0810090A
	.align 2, 0
_0810045C: .4byte 0x030046A4
_08100460: .4byte 0x00000256
_08100464: .4byte 0x03002BE0
_08100468:
	ldr r6, _0810050C @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0xf0]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xf8]
	cmp r6, #0
	beq _08100520
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _08100510 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x1c]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _08100514 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x20]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x24]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x28]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sp
	ldrh r0, [r0, #0x18]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _08100518 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0810051C @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x18]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0xc8]
	ldr r6, [sp, #0x20]
	str r6, [sp, #0xc0]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0xe4]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0xe8]
	str r5, [sp, #0xf4]
	str r4, [sp, #0xb4]
	str r3, [sp, #0xb8]
	str r2, [sp, #0xbc]
	str r1, [sp, #0xcc]
	str r0, [sp, #0xc4]
	b _081006F2
	.align 2, 0
_0810050C: .4byte 0x00000222
_08100510: .4byte 0x0000046D
_08100514: .4byte 0x0000046B
_08100518: .4byte 0x00000469
_0810051C: .4byte 0x00000484
_08100520:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081005E4 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	strb r0, [r2]
	ldr r3, _081005E8 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x30]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081005EC @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x34]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x38]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x3c]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x40]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081005F0 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081005F4 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081005F8 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd0]
	ldr r0, [r0]
	str r0, [sp, #0x44]
	ldr r1, [sp, #0xdc]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x44]
	strh r1, [r6]
	ldr r6, [sp, #0xdc]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x44]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0xc8]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0xc0]
	ldr r0, [sp, #0x34]
	str r0, [sp, #0xe4]
	ldr r6, [sp, #0x38]
	str r6, [sp, #0xe8]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #0xf4]
	ldr r6, [sp, #0x40]
	str r6, [sp, #0xb4]
	str r5, [sp, #0xb8]
	str r4, [sp, #0xbc]
	str r3, [sp, #0xcc]
	str r2, [sp, #0xc4]
	mov r0, sl
	cmp r0, #0
	blt _081005DE
	cmp r1, #0
	blt _081005DE
	ldr r0, _081005FC @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _081005DE
	ldr r0, _08100600 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08100604
_081005DE:
	movs r4, #0
	b _08100614
	.align 2, 0
_081005E4: .4byte 0x0000046D
_081005E8: .4byte 0x0000046B
_081005EC: .4byte 0x00000553
_081005F0: .4byte 0x00000469
_081005F4: .4byte 0x00000484
_081005F8: .4byte 0x0000046C
_081005FC: .4byte 0x030046A8
_08100600: .4byte 0x030046AC
_08100604:
	ldr r0, _08100624 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_08100614:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08100628
	adds r0, #4
	b _08100634
	.align 2, 0
_08100624: .4byte 0x030046A4
_08100628:
	ldr r0, _08100648 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08100634:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810064C
	cmp r2, #2
	beq _08100652
	b _08100658
	.align 2, 0
_08100648: .4byte 0x030046A4
_0810064C:
	ldr r2, [sp, #0x44]
	ldrb r0, [r2, #4]
	b _08100656
_08100652:
	ldr r3, [sp, #0x44]
	ldrb r0, [r3]
_08100656:
	subs r1, r1, r0
_08100658:
	ldr r4, [sp, #0x44]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xd0]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08100684
	cmp r1, #0
	blt _08100684
	ldr r0, _08100688 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08100684
	ldr r0, _0810068C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08100690
_08100684:
	movs r4, #0
	b _0810069E
	.align 2, 0
_08100688: .4byte 0x030046A8
_0810068C: .4byte 0x030046AC
_08100690:
	ldr r0, _081006B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810069E:
	ldr r6, [sp, #0xd0]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081006B8
	adds r0, #4
	b _081006C4
	.align 2, 0
_081006B4: .4byte 0x030046A4
_081006B8:
	ldr r0, _081006D8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081006C4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081006DC
	cmp r3, #2
	beq _081006E0
	b _081006E4
	.align 2, 0
_081006D8: .4byte 0x030046A4
_081006DC:
	ldrb r0, [r5, #4]
	b _081006E2
_081006E0:
	ldrb r0, [r5]
_081006E2:
	subs r2, r2, r0
_081006E4:
	ldr r1, [sp, #0xd0]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xd0]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081006F2:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x48]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf0]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _0810071C @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _081007FC
	movs r1, #4
	ldr r2, [sp, #0xf8]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08100720
	movs r0, #1
	b _08100722
	.align 2, 0
_0810071C: .4byte 0x00000482
_08100720:
	movs r0, #0
_08100722:
	ldr r3, _0810080C @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _081007FC
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _08100810 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _08100814 @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _08100818 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r0, _0810081C @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd4]
	ldr r1, _08100820 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xec]
	ldr r2, _08100824 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xd8]
	ldr r1, _08100828 @ =0x030046B8
	str r4, [sp, #0xfc]
_08100768:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0810082C @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _08100830 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0xfc]
	cmp r0, r2
	bne _0810078E
	adds r3, #1
	cmp r3, #3
	ble _08100768
	adds r0, r4, #0
_0810078E:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xe8]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe4]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb4]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xb8]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xbc]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe0]
	strb r0, [r6]
	add r0, sp, #0x48
	ldrb r1, [r0]
	ldr r0, [sp, #0xd4]
	strb r1, [r0]
	ldr r1, [sp, #0xec]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xc8]
	strb r1, [r4]
	ldr r6, [sp, #0xc0]
	strb r3, [r6]
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
	ldr r6, [sp, #0xe8]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf4]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb4]
	strb r0, [r4]
	ldr r6, [sp, #0xb8]
	strb r1, [r6]
	ldr r0, [sp, #0xbc]
	strb r2, [r0]
	ldr r2, [sp, #0xcc]
	str r3, [r2]
	ldr r3, [sp, #0xc4]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xd8]
	strb r0, [r4]
_081007FC:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _0810090A
	.align 2, 0
_0810080C: .4byte 0x00000482
_08100810: .4byte 0x0000054F
_08100814: .4byte 0x0000054D
_08100818: .4byte 0x0000054E
_0810081C: .4byte 0x00000541
_08100820: .4byte 0x000005BC
_08100824: .4byte 0x00000542
_08100828: .4byte 0x030046B8
_0810082C: .4byte 0x000003FF
_08100830: .4byte 0x0203B400
_08100834:
	mov sb, sp
	ldr r6, _08100870 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08100874
	adds r0, #4
	b _0810087E
	.align 2, 0
_08100870: .4byte 0x030046A4
_08100874:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0810087E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _081008B8 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081008C0
	ldr r0, _081008BC @ =0xFFFFFDFF
	ldr r2, [sp, #0xf0]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081008EA
	.align 2, 0
_081008B8: .4byte 0x000004A4
_081008BC: .4byte 0xFFFFFDFF
_081008C0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081008E0
	cmp r0, #2
	beq _081008DC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081008DC:
	movs r0, #1
	b _081008EC
_081008E0:
	ldr r0, _08100900 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf0]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081008EA:
	movs r0, #0
_081008EC:
	cmp r0, #0
	bne _08100908
	ldr r4, _08100904 @ =0x000005C4
	adds r0, r7, r4
_081008F4:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0810090A
	.align 2, 0
_08100900: .4byte 0xFFFFFDFF
_08100904: .4byte 0x000005C4
_08100908:
	movs r0, #1
_0810090A:
	cmp r0, #0
	bne _0810097C
	ldr r5, _08100940 @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08100948
	ldr r0, _08100944 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf0]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08100972
	.align 2, 0
_08100940: .4byte 0x000004A4
_08100944: .4byte 0xFFFFFDFF
_08100948:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08100968
	cmp r0, #2
	beq _08100964
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08100964:
	movs r0, #1
	b _08100974
_08100968:
	ldr r0, _081009D8 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf0]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08100972:
	movs r0, #0
_08100974:
	cmp r0, #0
	bne _0810097C
	bl _08101948
_0810097C:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081009DC @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081009E0 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _081009E4 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081009E8 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081009EC @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	bl FUN_081019b6
	.align 2, 0
_081009D8: .4byte 0xFFFFFDFF
_081009DC: .4byte 0x0000046D
_081009E0: .4byte 0x0000046B
_081009E4: .4byte 0x00000469
_081009E8: .4byte 0x0000046A
_081009EC: .4byte 0x00000484
_081009F0:
	ldr r4, _08100A08 @ =0x00008002
	ands r4, r2
	cmp r4, #0
	beq _08100A0C
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r3
	ldr r1, [sp, #0xf0]
	strh r0, [r1]
_08100A02:
	movs r0, #0
	bl FUN_081019ba
	.align 2, 0
_08100A08: .4byte 0x00008002
_08100A0C:
	ldr r2, _08100A7C @ =0x0000049C
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _08100AA0
	ldr r3, _08100A80 @ =0x000005CC
	adds r0, r7, r3
	ldr r2, [r0]
	movs r1, #0x12
	ldr r5, _08100A84 @ =0x0000046D
	adds r0, r7, r5
	movs r3, #1
	strb r3, [r0]
	ldr r6, _08100A88 @ =0x0000046B
	adds r0, r7, r6
	strb r4, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _08100A8C @ =0x00000469
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _08100A90 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _08100A94 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	ldr r4, _08100A98 @ =0x0000046C
	adds r0, r7, r4
	strb r3, [r0]
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _08100A9C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	bl _081019B8
	.align 2, 0
_08100A7C: .4byte 0x0000049C
_08100A80: .4byte 0x000005CC
_08100A84: .4byte 0x0000046D
_08100A88: .4byte 0x0000046B
_08100A8C: .4byte 0x00000469
_08100A90: .4byte 0x0000046A
_08100A94: .4byte 0x00000484
_08100A98: .4byte 0x0000046C
_08100A9C: .4byte 0xFEFFFFFF
_08100AA0:
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r3
	ldr r6, [sp, #0xf0]
	strh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08100A02
	ldr r1, _08100B78 @ =0x000004BE
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08100A02
	ldr r3, _08100B7C @ =0x0000065C
	adds r2, r5, r3
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0xf0]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	bne _08100ADA
	b _0810124C
_08100ADA:
	ldr r5, _08100B80 @ =0x0000048D
	adds r2, r7, r5
	ldrb r0, [r2]
	cmp r0, #0
	bne _08100B06
	ldr r6, _08100B84 @ =0x0000048C
	adds r0, r7, r6
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08100B06
	ldr r1, _08100B78 @ =0x000004BE
	adds r0, r7, r1
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_08100B06:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0
	bne _08100B14
	b _08100A02
_08100B14:
	ldr r0, _08100B88 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x80
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #4
	ldr r4, _08100B8C @ =0x00000222
	adds r3, r7, r4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r4, r7, r5
	ldr r6, [r4]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0xd0]
	str r2, [sp, #0xdc]
	str r3, [sp, #0xf8]
	cmp r5, #0
	blt _08100B74
	cmp r1, #0
	blt _08100B74
	ldr r0, _08100B90 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08100B74
	ldr r0, _08100B94 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08100B98
_08100B74:
	movs r4, #0
	b _08100BA6
	.align 2, 0
_08100B78: .4byte 0x000004BE
_08100B7C: .4byte 0x0000065C
_08100B80: .4byte 0x0000048D
_08100B84: .4byte 0x0000048C
_08100B88: .4byte 0x03002BE0
_08100B8C: .4byte 0x00000222
_08100B90: .4byte 0x030046A8
_08100B94: .4byte 0x030046AC
_08100B98:
	ldr r0, _08100BB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_08100BA6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08100BBC
	adds r0, #4
	b _08100BC8
	.align 2, 0
_08100BB8: .4byte 0x030046A4
_08100BBC:
	ldr r0, _08100BDC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08100BC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08100BE0
	cmp r2, #2
	beq _08100BE4
	b _08100BE8
	.align 2, 0
_08100BDC: .4byte 0x030046A4
_08100BE0:
	ldrb r0, [r6, #4]
	b _08100BE6
_08100BE4:
	ldrb r0, [r6]
_08100BE6:
	subs r1, r1, r0
_08100BE8:
	strh r1, [r6, #2]
	ldr r0, _08100BFC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08100C00
	movs r0, #1
	b _08100C02
	.align 2, 0
_08100BFC: .4byte 0x030047A4
_08100C00:
	movs r0, #0
_08100C02:
	cmp r0, #0
	beq _08100C40
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _08100C22
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08100C1E
	adds r2, r0, #0
_08100C1E:
	cmp r2, #0
	bge _08100C2C
_08100C22:
	ldr r1, _08100C28 @ =0x000005C4
	adds r0, r7, r1
	b _0810115C
	.align 2, 0
_08100C28: .4byte 0x000005C4
_08100C2C:
	ldr r1, _08100C3C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08100C88
	.align 2, 0
_08100C3C: .4byte 0x03002BE0
_08100C40:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08100C6C
	cmp r1, #0
	blt _08100C6C
	ldr r0, _08100C70 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08100C6C
	ldr r0, _08100C74 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08100C78
_08100C6C:
	movs r5, #0
	b _08100C86
	.align 2, 0
_08100C70: .4byte 0x030046A8
_08100C74: .4byte 0x030046AC
_08100C78:
	ldr r0, _08100CC0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08100C86:
	movs r2, #0
_08100C88:
	ldr r3, _08100CC4 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _08100CA8
	ldr r1, _08100CC8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08100CA8
	b _08101098
_08100CA8:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf0]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x4c]
	cmp r0, #0
	beq _08100CCC
	movs r0, #0
	b _08101172
	.align 2, 0
_08100CC0: .4byte 0x030046A4
_08100CC4: .4byte 0x00000256
_08100CC8: .4byte 0x03002BE0
_08100CCC:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r5, [sp, #0xf8]
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r1, #0x80
	ldr r6, [sp, #0xf0]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08100D88
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _08100D6C @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x50]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _08100D70 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x54]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _08100D74 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x58]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x5c]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	add r2, sp, #0x4c
	ldrh r2, [r2]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _08100D78 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _08100D7C @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _08100D80 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x4c]
	str r6, [r1]
	ldr r6, _08100D84 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x50]
	str r6, [sp, #0xc8]
	ldr r6, [sp, #0x54]
	str r6, [sp, #0xc0]
	ldr r6, [sp, #0x58]
	str r6, [sp, #0xe4]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0xe8]
	str r5, [sp, #0xf4]
	str r4, [sp, #0xb4]
	str r3, [sp, #0xb8]
	str r2, [sp, #0xbc]
	str r1, [sp, #0xcc]
	str r0, [sp, #0xc4]
	b _08100F56
	.align 2, 0
_08100D6C: .4byte 0x0000046D
_08100D70: .4byte 0x0000046B
_08100D74: .4byte 0x00000553
_08100D78: .4byte 0x00000469
_08100D7C: .4byte 0x0000046A
_08100D80: .4byte 0x00000484
_08100D84: .4byte 0x0000046C
_08100D88:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _08100E48 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x60]
	strb r0, [r3]
	ldr r4, _08100E4C @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x64]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _08100E50 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x68]
	strb r0, [r6]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x70]
	strh r2, [r4]
	movs r1, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x74]
	movs r6, #0
	strb r6, [r5]
	ldr r3, _08100E54 @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _08100E58 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _08100E5C @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd0]
	ldr r0, [r0]
	str r0, [sp, #0x78]
	ldr r1, [sp, #0xdc]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x78]
	strh r1, [r6]
	ldr r6, [sp, #0xdc]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x78]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x60]
	str r0, [sp, #0xc8]
	ldr r6, [sp, #0x64]
	str r6, [sp, #0xc0]
	ldr r0, [sp, #0x68]
	str r0, [sp, #0xe4]
	ldr r6, [sp, #0x6c]
	str r6, [sp, #0xe8]
	ldr r0, [sp, #0x70]
	str r0, [sp, #0xf4]
	ldr r6, [sp, #0x74]
	str r6, [sp, #0xb4]
	str r5, [sp, #0xb8]
	str r4, [sp, #0xbc]
	str r3, [sp, #0xcc]
	str r2, [sp, #0xc4]
	mov r0, sb
	cmp r0, #0
	blt _08100E44
	cmp r1, #0
	blt _08100E44
	ldr r0, _08100E60 @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _08100E44
	ldr r0, _08100E64 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08100E68
_08100E44:
	movs r4, #0
	b _08100E78
	.align 2, 0
_08100E48: .4byte 0x0000046D
_08100E4C: .4byte 0x0000046B
_08100E50: .4byte 0x00000553
_08100E54: .4byte 0x00000469
_08100E58: .4byte 0x0000046A
_08100E5C: .4byte 0x00000484
_08100E60: .4byte 0x030046A8
_08100E64: .4byte 0x030046AC
_08100E68:
	ldr r0, _08100E88 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_08100E78:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08100E8C
	adds r0, #4
	b _08100E98
	.align 2, 0
_08100E88: .4byte 0x030046A4
_08100E8C:
	ldr r0, _08100EAC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08100E98:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08100EB0
	cmp r2, #2
	beq _08100EB6
	b _08100EBC
	.align 2, 0
_08100EAC: .4byte 0x030046A4
_08100EB0:
	ldr r2, [sp, #0x78]
	ldrb r0, [r2, #4]
	b _08100EBA
_08100EB6:
	ldr r3, [sp, #0x78]
	ldrb r0, [r3]
_08100EBA:
	subs r1, r1, r0
_08100EBC:
	ldr r4, [sp, #0x78]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xd0]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08100EE8
	cmp r1, #0
	blt _08100EE8
	ldr r0, _08100EEC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08100EE8
	ldr r0, _08100EF0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08100EF4
_08100EE8:
	movs r4, #0
	b _08100F02
	.align 2, 0
_08100EEC: .4byte 0x030046A8
_08100EF0: .4byte 0x030046AC
_08100EF4:
	ldr r0, _08100F18 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08100F02:
	ldr r6, [sp, #0xd0]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08100F1C
	adds r0, #4
	b _08100F28
	.align 2, 0
_08100F18: .4byte 0x030046A4
_08100F1C:
	ldr r0, _08100F3C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08100F28:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08100F40
	cmp r3, #2
	beq _08100F44
	b _08100F48
	.align 2, 0
_08100F3C: .4byte 0x030046A4
_08100F40:
	ldrb r0, [r5, #4]
	b _08100F46
_08100F44:
	ldrb r0, [r5]
_08100F46:
	subs r2, r2, r0
_08100F48:
	ldr r1, [sp, #0xd0]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xd0]
	ldr r0, [r2]
	strh r1, [r0, #6]
_08100F56:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x7c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf0]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _08100F80 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _08101060
	movs r1, #4
	ldr r2, [sp, #0xf8]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08100F84
	movs r0, #1
	b _08100F86
	.align 2, 0
_08100F80: .4byte 0x00000482
_08100F84:
	movs r0, #0
_08100F86:
	ldr r3, _08101070 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _08101060
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _08101074 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _08101078 @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _0810107C @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r0, _08101080 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd4]
	ldr r1, _08101084 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xec]
	ldr r2, _08101088 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xd8]
	ldr r1, _0810108C @ =0x030046B8
	str r4, [sp, #0xfc]
_08100FCC:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _08101090 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _08101094 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0xfc]
	cmp r0, r2
	bne _08100FF2
	adds r3, #1
	cmp r3, #3
	ble _08100FCC
	adds r0, r4, #0
_08100FF2:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xe8]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe4]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb4]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xb8]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xbc]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe0]
	strb r0, [r6]
	add r0, sp, #0x7c
	ldrb r1, [r0]
	ldr r0, [sp, #0xd4]
	strb r1, [r0]
	ldr r1, [sp, #0xec]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xc8]
	strb r1, [r4]
	ldr r6, [sp, #0xc0]
	strb r3, [r6]
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
	ldr r6, [sp, #0xe8]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf4]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb4]
	strb r0, [r4]
	ldr r6, [sp, #0xb8]
	strb r1, [r6]
	ldr r0, [sp, #0xbc]
	strb r2, [r0]
	ldr r2, [sp, #0xcc]
	str r3, [r2]
	ldr r3, [sp, #0xc4]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xd8]
	strb r0, [r4]
_08101060:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _08101172
	.align 2, 0
_08101070: .4byte 0x00000482
_08101074: .4byte 0x0000054F
_08101078: .4byte 0x0000054D
_0810107C: .4byte 0x0000054E
_08101080: .4byte 0x00000541
_08101084: .4byte 0x000005BC
_08101088: .4byte 0x00000542
_0810108C: .4byte 0x030046B8
_08101090: .4byte 0x000003FF
_08101094: .4byte 0x0203B400
_08101098:
	add r6, sp, #8
	ldr r0, _081010D8 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _081010DC
	adds r0, #4
	b _081010E8
	.align 2, 0
_081010D8: .4byte 0x030046A4
_081010DC:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081010E8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _08101120 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _08101128
	ldr r0, _08101124 @ =0xFFFFFDFF
	ldr r6, [sp, #0xf0]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _08101152
	.align 2, 0
_08101120: .4byte 0x000004A4
_08101124: .4byte 0xFFFFFDFF
_08101128:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _08101148
	cmp r0, #2
	beq _08101144
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08101144:
	movs r0, #1
	b _08101154
_08101148:
	ldr r0, _08101168 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf0]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08101152:
	movs r0, #0
_08101154:
	cmp r0, #0
	bne _08101170
	ldr r3, _0810116C @ =0x000005C4
	adds r0, r7, r3
_0810115C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _08101172
	.align 2, 0
_08101168: .4byte 0xFFFFFDFF
_0810116C: .4byte 0x000005C4
_08101170:
	movs r0, #1
_08101172:
	cmp r0, #0
	bne _081011E2
	ldr r4, _081011A8 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081011B0
	ldr r0, _081011AC @ =0xFFFFFDFF
	ldr r2, [sp, #0xf0]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081011DA
	.align 2, 0
_081011A8: .4byte 0x000004A4
_081011AC: .4byte 0xFFFFFDFF
_081011B0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081011D0
	cmp r0, #2
	beq _081011CC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081011CC:
	movs r0, #1
	b _081011DC
_081011D0:
	ldr r0, _08101238 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf0]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081011DA:
	movs r0, #0
_081011DC:
	cmp r0, #0
	bne _081011E2
	b _08101948
_081011E2:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _0810123C @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _08101240 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08101244 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _08101248 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _081019B8
	.align 2, 0
_08101238: .4byte 0xFFFFFDFF
_0810123C: .4byte 0x0000046D
_08101240: .4byte 0x0000046B
_08101244: .4byte 0x0000046A
_08101248: .4byte 0x00000484
_0810124C:
	ldr r6, _081012E8 @ =0x0000048D
	adds r2, r7, r6
	ldrb r0, [r2]
	cmp r0, #0
	bne _08101278
	ldr r1, _081012EC @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08101278
	ldr r3, _081012F0 @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_08101278:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	cmp r0, #0
	bne _08101288
	bl _08100A02
_08101288:
	ldr r0, _081012F4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	adds r3, r7, r6
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xd0]
	str r2, [sp, #0xdc]
	cmp r5, #0
	blt _081012E2
	cmp r1, #0
	blt _081012E2
	ldr r0, _081012F8 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _081012E2
	ldr r0, _081012FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08101300
_081012E2:
	movs r4, #0
	b _0810130E
	.align 2, 0
_081012E8: .4byte 0x0000048D
_081012EC: .4byte 0x0000048C
_081012F0: .4byte 0x000004BE
_081012F4: .4byte 0x03002BE0
_081012F8: .4byte 0x030046A8
_081012FC: .4byte 0x030046AC
_08101300:
	ldr r0, _08101320 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0810130E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08101324
	adds r0, #4
	b _08101330
	.align 2, 0
_08101320: .4byte 0x030046A4
_08101324:
	ldr r0, _08101344 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08101330:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08101348
	cmp r2, #2
	beq _0810134C
	b _08101350
	.align 2, 0
_08101344: .4byte 0x030046A4
_08101348:
	ldrb r0, [r6, #4]
	b _0810134E
_0810134C:
	ldrb r0, [r6]
_0810134E:
	subs r1, r1, r0
_08101350:
	strh r1, [r6, #2]
	ldr r0, _08101364 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08101368
	movs r0, #1
	b _0810136A
	.align 2, 0
_08101364: .4byte 0x030047A4
_08101368:
	movs r0, #0
_0810136A:
	cmp r0, #0
	beq _081013A8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0810138A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08101386
	adds r2, r0, #0
_08101386:
	cmp r2, #0
	bge _08101394
_0810138A:
	ldr r2, _08101390 @ =0x000005C4
	adds r0, r7, r2
	b _081018C4
	.align 2, 0
_08101390: .4byte 0x000005C4
_08101394:
	ldr r1, _081013A4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081013F0
	.align 2, 0
_081013A4: .4byte 0x03002BE0
_081013A8:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081013D4
	cmp r1, #0
	blt _081013D4
	ldr r0, _081013D8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081013D4
	ldr r0, _081013DC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081013E0
_081013D4:
	movs r5, #0
	b _081013EE
	.align 2, 0
_081013D8: .4byte 0x030046A8
_081013DC: .4byte 0x030046AC
_081013E0:
	ldr r0, _08101428 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081013EE:
	movs r2, #0
_081013F0:
	ldr r4, _0810142C @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08101410
	ldr r1, _08101430 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08101410
	b _08101800
_08101410:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0xf0]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x80]
	cmp r0, #0
	beq _08101434
	movs r0, #0
	b _081018DA
	.align 2, 0
_08101428: .4byte 0x030046A4
_0810142C: .4byte 0x00000256
_08101430: .4byte 0x03002BE0
_08101434:
	ldr r6, _081014D8 @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0xf0]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0xf8]
	cmp r0, #0
	beq _081014EC
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _081014DC @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x84]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _081014E0 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x88]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x8c]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x90]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	add r0, sp, #0x80
	ldrh r0, [r0]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _081014E4 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _081014E8 @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x80]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x84]
	str r6, [sp, #0xc8]
	ldr r6, [sp, #0x88]
	str r6, [sp, #0xc0]
	ldr r6, [sp, #0x8c]
	str r6, [sp, #0xe4]
	ldr r6, [sp, #0x90]
	str r6, [sp, #0xe8]
	str r5, [sp, #0xf4]
	str r4, [sp, #0xb4]
	str r3, [sp, #0xb8]
	str r2, [sp, #0xbc]
	str r1, [sp, #0xcc]
	str r0, [sp, #0xc4]
	b _081016BE
	.align 2, 0
_081014D8: .4byte 0x00000222
_081014DC: .4byte 0x0000046D
_081014E0: .4byte 0x0000046B
_081014E4: .4byte 0x00000469
_081014E8: .4byte 0x00000484
_081014EC:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081015B0 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x94]
	strb r0, [r2]
	ldr r3, _081015B4 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x98]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081015B8 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x9c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xa0]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa4]
	mov r2, ip
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xa8]
	strb r4, [r3]
	ldr r4, _081015BC @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _081015C0 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _081015C4 @ =0x00000484
	adds r3, r7, r6
	mov r1, ip
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd0]
	ldr r0, [r0]
	str r0, [sp, #0xac]
	ldr r1, [sp, #0xdc]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0xac]
	strh r1, [r6]
	ldr r6, [sp, #0xdc]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xac]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x94]
	str r0, [sp, #0xc8]
	ldr r6, [sp, #0x98]
	str r6, [sp, #0xc0]
	ldr r0, [sp, #0x9c]
	str r0, [sp, #0xe4]
	ldr r6, [sp, #0xa0]
	str r6, [sp, #0xe8]
	ldr r0, [sp, #0xa4]
	str r0, [sp, #0xf4]
	ldr r6, [sp, #0xa8]
	str r6, [sp, #0xb4]
	str r5, [sp, #0xb8]
	str r4, [sp, #0xbc]
	str r3, [sp, #0xcc]
	str r2, [sp, #0xc4]
	mov r0, r8
	cmp r0, #0
	blt _081015AC
	cmp r1, #0
	blt _081015AC
	ldr r0, _081015C8 @ =0x030046A8
	ldr r0, [r0]
	cmp r8, r0
	bhs _081015AC
	ldr r0, _081015CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081015D0
_081015AC:
	movs r4, #0
	b _081015E0
	.align 2, 0
_081015B0: .4byte 0x0000046D
_081015B4: .4byte 0x0000046B
_081015B8: .4byte 0x00000553
_081015BC: .4byte 0x00000469
_081015C0: .4byte 0x0000046A
_081015C4: .4byte 0x00000484
_081015C8: .4byte 0x030046A8
_081015CC: .4byte 0x030046AC
_081015D0:
	ldr r0, _081015F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, r8
	adds r4, r0, r1
_081015E0:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081015F4
	adds r0, #4
	b _08101600
	.align 2, 0
_081015F0: .4byte 0x030046A4
_081015F4:
	ldr r0, _08101614 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08101600:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08101618
	cmp r2, #2
	beq _0810161E
	b _08101624
	.align 2, 0
_08101614: .4byte 0x030046A4
_08101618:
	ldr r2, [sp, #0xac]
	ldrb r0, [r2, #4]
	b _08101622
_0810161E:
	ldr r3, [sp, #0xac]
	ldrb r0, [r3]
_08101622:
	subs r1, r1, r0
_08101624:
	ldr r4, [sp, #0xac]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xd0]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08101650
	cmp r1, #0
	blt _08101650
	ldr r0, _08101654 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08101650
	ldr r0, _08101658 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810165C
_08101650:
	movs r4, #0
	b _0810166A
	.align 2, 0
_08101654: .4byte 0x030046A8
_08101658: .4byte 0x030046AC
_0810165C:
	ldr r0, _08101680 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810166A:
	ldr r6, [sp, #0xd0]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08101684
	adds r0, #4
	b _08101690
	.align 2, 0
_08101680: .4byte 0x030046A4
_08101684:
	ldr r0, _081016A4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08101690:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081016A8
	cmp r3, #2
	beq _081016AC
	b _081016B0
	.align 2, 0
_081016A4: .4byte 0x030046A4
_081016A8:
	ldrb r0, [r5, #4]
	b _081016AE
_081016AC:
	ldrb r0, [r5]
_081016AE:
	subs r2, r2, r0
_081016B0:
	ldr r1, [sp, #0xd0]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xd0]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081016BE:
	ldrb r3, [r7, #5]
	str r3, [sp, #0xb0]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf0]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _081016E8 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _081017C8
	movs r1, #4
	ldr r2, [sp, #0xf8]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081016EC
	movs r0, #1
	b _081016EE
	.align 2, 0
_081016E8: .4byte 0x00000482
_081016EC:
	movs r0, #0
_081016EE:
	ldr r3, _081017D8 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _081017C8
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081017DC @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081017E0 @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081017E4 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r0, _081017E8 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd4]
	ldr r1, _081017EC @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xec]
	ldr r2, _081017F0 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xd8]
	ldr r1, _081017F4 @ =0x030046B8
	str r4, [sp, #0xfc]
_08101734:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081017F8 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081017FC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0xfc]
	cmp r0, r2
	bne _0810175A
	adds r3, #1
	cmp r3, #3
	ble _08101734
	adds r0, r4, #0
_0810175A:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xe8]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe4]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb4]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xb8]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xbc]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe0]
	strb r0, [r6]
	add r0, sp, #0xb0
	ldrb r1, [r0]
	ldr r0, [sp, #0xd4]
	strb r1, [r0]
	ldr r1, [sp, #0xec]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xc8]
	strb r1, [r4]
	ldr r6, [sp, #0xc0]
	strb r3, [r6]
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
	ldr r6, [sp, #0xe8]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf4]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb4]
	strb r0, [r4]
	ldr r6, [sp, #0xb8]
	strb r1, [r6]
	ldr r0, [sp, #0xbc]
	strb r2, [r0]
	ldr r2, [sp, #0xcc]
	str r3, [r2]
	ldr r3, [sp, #0xc4]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xd8]
	strb r0, [r4]
_081017C8:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _081018DA
	.align 2, 0
_081017D8: .4byte 0x00000482
_081017DC: .4byte 0x0000054F
_081017E0: .4byte 0x0000054D
_081017E4: .4byte 0x0000054E
_081017E8: .4byte 0x00000541
_081017EC: .4byte 0x000005BC
_081017F0: .4byte 0x00000542
_081017F4: .4byte 0x030046B8
_081017F8: .4byte 0x000003FF
_081017FC: .4byte 0x0203B400
_08101800:
	add r6, sp, #0x10
	ldr r0, _08101840 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _08101844
	adds r0, #4
	b _08101850
	.align 2, 0
_08101840: .4byte 0x030046A4
_08101844:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08101850:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _08101888 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _08101890
	ldr r0, _0810188C @ =0xFFFFFDFF
	ldr r6, [sp, #0xf0]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081018BA
	.align 2, 0
_08101888: .4byte 0x000004A4
_0810188C: .4byte 0xFFFFFDFF
_08101890:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081018B0
	cmp r0, #2
	beq _081018AC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081018AC:
	movs r0, #1
	b _081018BC
_081018B0:
	ldr r0, _081018D0 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf0]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081018BA:
	movs r0, #0
_081018BC:
	cmp r0, #0
	bne _081018D8
	ldr r3, _081018D4 @ =0x000005C4
	adds r0, r7, r3
_081018C4:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081018DA
	.align 2, 0
_081018D0: .4byte 0xFFFFFDFF
_081018D4: .4byte 0x000005C4
_081018D8:
	movs r0, #1
_081018DA:
	cmp r0, #0
	bne _08101960
	ldr r4, _08101910 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08101918
	ldr r0, _08101914 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf0]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08101942
	.align 2, 0
_08101910: .4byte 0x000004A4
_08101914: .4byte 0xFFFFFDFF
_08101918:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08101938
	cmp r0, #2
	beq _08101934
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08101934:
	movs r0, #1
	b _08101944
_08101938:
	ldr r0, _08101958 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf0]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08101942:
	movs r0, #0
_08101944:
	cmp r0, #0
	bne _08101960
_08101948:
	ldr r4, _0810195C @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _08100A02
	.align 2, 0
_08101958: .4byte 0xFFFFFDFF
_0810195C: .4byte 0x000005C4
_08101960:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081019CC @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081019D0 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _081019D4 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081019D8 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081019DC @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #3
FUN_081019b6:
	strh r0, [r1]
_081019B8:
	movs r0, #1
FUN_081019ba:
	add sp, #0x100
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081019CC: .4byte 0x0000046D
_081019D0: .4byte 0x0000046B
_081019D4: .4byte 0x00000469
_081019D8: .4byte 0x0000046A
_081019DC: .4byte 0x00000484

	thumb_func_start FUN_081019e0
FUN_081019e0: @ 0x081019E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov sb, r0
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08101A06
	b _08101B9C
_08101A06:
	movs r2, #1
	ldr r1, _08101A1C @ =0x0000065C
	add r1, sb
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08101A20
	movs r0, #1
	b _08101A22
	.align 2, 0
_08101A1C: .4byte 0x0000065C
_08101A20:
	movs r0, #0
_08101A22:
	cmp r0, #0
	bne _08101A28
	b _08101B9C
_08101A28:
	ldr r1, _08101A50 @ =0x0000A107
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r2, r2, r6
	mov r8, r2
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08101A3C
	b _08101B9C
_08101A3C:
	ldr r1, _08101A54 @ =0x0000067C
	add r1, sb
	ldrh r0, [r1]
	adds r7, r0, #0
	cmp r7, #0
	beq _08101A58
	subs r0, #1
	strh r0, [r1]
	b _08101B9C
	.align 2, 0
_08101A50: .4byte 0x0000A107
_08101A54: .4byte 0x0000067C
_08101A58:
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r6, r3
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r4, _08101B44 @ =0x000004A4
	adds r5, r6, r4
	ldr r0, [r5]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r6, #0
	bl FUN_080e6304
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r3, [r0]
	movs r0, #0xc
	mov ip, r0
	movs r1, #0x1e
	subs r4, #0x60
	adds r2, r6, r4
	subs r4, #4
	adds r0, r6, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r7, [r0]
	ldr r2, _08101B48 @ =0x00000551
	adds r0, r6, r2
	strb r7, [r0]
	ldr r3, _08101B4C @ =0x00000552
	adds r0, r6, r3
	mov r4, ip
	strb r4, [r0]
	ldr r3, _08101B50 @ =FUN_080e6794
	movs r1, #0xe
	subs r2, #0xe4
	adds r0, r6, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, _08101B54 @ =0x0000046B
	adds r0, r6, r4
	strb r7, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r3, #0
	strh r7, [r0]
	movs r1, #3
	subs r4, #0xeb
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _08101B58 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r6, r1
	str r7, [r0]
	ldr r3, _08101B5C @ =0x0000046C
	adds r0, r6, r3
	strb r2, [r0]
	adds r1, r6, #0
	adds r1, #0x9c
	movs r4, #0x94
	lsls r4, r4, #2
	adds r0, r6, r4
	ldrb r2, [r0]
	ldr r3, _08101B60 @ =0x00000251
	adds r0, r6, r3
	ldrb r3, [r0]
	adds r4, #2
	adds r0, r6, r4
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r6, #0
	bl FUN_0823b490
	ldr r5, [r5]
	adds r4, r6, #0
	adds r4, #8
	movs r7, #0xcc
	lsls r7, r7, #3
	add r7, sb
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08101B68
	ldr r0, _08101B64 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08101B90
	.align 2, 0
_08101B44: .4byte 0x000004A4
_08101B48: .4byte 0x00000551
_08101B4C: .4byte 0x00000552
_08101B50: .4byte FUN_080e6794
_08101B54: .4byte 0x0000046B
_08101B58: .4byte 0x00000469
_08101B5C: .4byte 0x0000046C
_08101B60: .4byte 0x00000251
_08101B64: .4byte 0xFFFFFDFF
_08101B68:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08101B86
	cmp r0, #2
	beq _08101B90
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08101B90
_08101B86:
	ldr r0, _08101BB0 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08101B90:
	movs r0, #2
	rsbs r0, r0, #0
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_08101B9C:
	movs r0, #1
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08101BB0: .4byte 0xFFFFFDFF

	thumb_func_start FUN_08101bb4
FUN_08101bb4: @ 0x08101BB4
	push {lr}
	bl FUN_080ffd28
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start FUN_08101bc0
FUN_08101bc0: @ 0x08101BC0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081019e0
	movs r1, #0x80
	lsls r1, r1, #6
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08101BE4
	ldr r1, _08101C14 @ =0x000004BE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08101C04
_08101BE4:
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r2, _08101C18 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
_08101C04:
	adds r0, r4, #0
	bl FUN_08101bb4
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08101C14: .4byte 0x000004BE
_08101C18: .4byte 0x0000062C

	thumb_func_start FUN_08101c1c
FUN_08101c1c: @ 0x08101C1C
	push {lr}
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08101c28
FUN_08101c28: @ 0x08101C28
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _08101C40 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08101C44
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _08101C4C
	.align 2, 0
_08101C40: .4byte 0x0000025D
_08101C44:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_08101C4C:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _08101C68 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _08101C6C
	movs r0, #1
	b _08101C6E
	.align 2, 0
_08101C68: .4byte 0x00000474
_08101C6C:
	movs r0, #0
_08101C6E:
	cmp r0, #0
	beq _08101C7A
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_08101C7A:
	ldr r1, _08101CD4 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _08101C92
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_08101C92:
	ldr r0, _08101CD8 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08101CAA
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_08101CAA:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08101CC2
	adds r0, r4, #0
	bl FUN_08002a58
_08101CC2:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08101CDC
	movs r0, #1
	b _08101CDE
	.align 2, 0
_08101CD4: .4byte 0x0000044C
_08101CD8: .4byte 0x0000044D
_08101CDC:
	movs r0, #0
_08101CDE:
	cmp r0, #0
	beq _08101CEA
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_08101CEA:
	adds r0, r4, #0
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_08236424
	adds r0, r4, #0
	bl FUN_080ec6fc
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EnemyBoku_Init
EnemyBoku_Init: @ 0x08101D08
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1b4
	adds r7, r0, #0
	str r7, [sp, #0x24]
	str r7, [sp, #0x28]
	ldr r1, _08101D90 @ =0x0000065C
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	adds r0, r7, #0
	bl FUN_080ffc2c
	adds r0, r7, #0
	bl FUN_08100164
	ldr r2, _08101D94 @ =0x0000025D
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08101DA4
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08101D98 @ =0x00009247
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _08101D9C @ =0x00001DF8
	bl FUN_080e3804
	ldr r3, _08101DA0 @ =0x000001DF
	adds r0, r7, r3
	ldrb r1, [r0]
	str r0, [sp, #0xa4]
	cmp r1, #0x11
	beq _08101D80
	cmp r1, #0x17
	bne _08101D84
_08101D80:
	movs r0, #1
	strb r0, [r5, #7]
_08101D84:
	movs r4, #0xef
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0
	strb r0, [r1]
	b _08101E0C
	.align 2, 0
_08101D90: .4byte 0x0000065C
_08101D94: .4byte 0x0000025D
_08101D98: .4byte 0x00009247
_08101D9C: .4byte 0x00001DF8
_08101DA0: .4byte 0x000001DF
_08101DA4:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r5, sp, #0x14
	mov r8, r5
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _08101E88 @ =0x05000002
	bl CpuSet
	ldr r0, _08101E8C @ =0x0000CB05
	ldr r1, _08101E90 @ =0x00009247
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r6}
	stm r2!, {r3, r6}
	adds r0, r4, #0
	bl OpenSpriteSetFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r5, r8
	str r5, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r6, _08101E94 @ =0x000004B7
	adds r1, r7, r6
	movs r0, #0xff
	strb r0, [r1]
	adds r0, #0xe0
	adds r0, r7, r0
	str r0, [sp, #0xa4]
_08101E0C:
	str r7, [sp, #0x2c]
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r1, r1, r7
	mov sb, r1
	movs r4, #0
	str r4, [r1]
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r2, r2, r7
	mov r8, r2
	str r4, [r2]
	ldr r3, _08101E98 @ =0x0000046F
	adds r0, r7, r3
	strb r4, [r0]
	movs r5, #0xde
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r6, #0
	mov sl, r6
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, _08101E9C @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _08101E88 @ =0x05000002
	bl CpuSet
	ldr r3, _08101EA0 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1b0]
	bl prepare_08231510
	mov r1, sb
	str r1, [sp, #0x60]
	mov r3, r8
	str r3, [sp, #0x64]
	str r6, [sp, #0x44]
	ldr r2, [sp, #0x1b0]
	adds r6, r2, #0
	cmp r0, #0
	bne _08101E78
	b _08101FD4
_08101E78:
	bl VM_GetPC
	cmp r0, #0
	beq _08101EA4
	bl Script_GetValue
	adds r1, r0, #0
	b _08101EA6
	.align 2, 0
_08101E88: .4byte 0x05000002
_08101E8C: .4byte 0x0000CB05
_08101E90: .4byte 0x00009247
_08101E94: .4byte 0x000004B7
_08101E98: .4byte 0x0000046F
_08101E9C: .4byte 0x00000474
_08101EA0: .4byte 0x000004B6
_08101EA4:
	movs r1, #0
_08101EA6:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _08101ECC @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xc0]
	str r4, [sp, #0xc4]
	cmp r0, #0
	beq _08101ED0
	bl Script_GetValue
	adds r1, r0, #0
	b _08101ED2
	.align 2, 0
_08101ECC: .4byte 0x00000251
_08101ED0:
	movs r1, #0
_08101ED2:
	ldr r2, _08101F08 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _08101F0C @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xc0]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xc8]
	cmp r0, #0
	beq _08101F10
	bl Script_GetValue
	b _08101F14
	.align 2, 0
_08101F08: .4byte 0x00000252
_08101F0C: .4byte 0x000004B4
_08101F10:
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
_08101F14:
	strb r0, [r6]
	ldr r5, [sp, #0xc0]
	ldrb r1, [r5]
	ldr r6, [sp, #0xc8]
	ldrb r2, [r6]
	add r0, sp, #0x1c
	bl FUN_08234f90
	add r0, sp, #0x1c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08101F4C
	cmp r1, #0
	blt _08101F4C
	ldr r0, _08101F50 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08101F4C
	ldr r0, _08101F54 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08101F58
_08101F4C:
	movs r1, #0
	b _08101F66
	.align 2, 0
_08101F50: .4byte 0x030046A8
_08101F54: .4byte 0x030046AC
_08101F58:
	ldr r0, _08101F80 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08101F66:
	ldr r2, _08101F84 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08101F88
	adds r0, #4
	b _08101F94
	.align 2, 0
_08101F80: .4byte 0x030046A4
_08101F84: .4byte 0x00000256
_08101F88:
	ldr r0, _08101FA8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08101F94:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08101FAC
	cmp r2, #2
	beq _08101FB0
	b _08101FB4
	.align 2, 0
_08101FA8: .4byte 0x030046A4
_08101FAC:
	ldrb r0, [r4, #4]
	b _08101FB2
_08101FB0:
	ldrb r0, [r4]
_08101FB2:
	subs r1, r1, r0
_08101FB4:
	ldr r3, _08101FCC @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08101FD0 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x30]
	b _08102014
	.align 2, 0
_08101FCC: .4byte 0x00000472
_08101FD0: .4byte 0x0000FFFF
_08101FD4:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _08102038 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0810203C @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08102040 @ =0x000004B4
	adds r1, r7, r6
	adds r0, r1, r0
	mov r6, sl
	strb r6, [r0]
	ldrb r2, [r2]
	movs r0, #1
	eors r0, r2
	adds r1, r1, r0
	strb r6, [r1]
	movs r0, #0
	str r0, [sp, #0x30]
	str r5, [sp, #0xc0]
	str r4, [sp, #0xc4]
	str r3, [sp, #0xc8]
_08102014:
	movs r0, #0x4e
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _0810205E
	bl VM_GetPC
	cmp r0, #0
	beq _08102044
	bl Script_GetValue
	adds r4, r0, #0
	b _08102046
	.align 2, 0
_08102038: .4byte 0x00000251
_0810203C: .4byte 0x00000252
_08102040: .4byte 0x000004B4
_08102044:
	movs r4, #0x30
_08102046:
	bl VM_GetPC
	cmp r0, #0
	beq _08102058
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0810205A
_08102058:
	movs r5, #0x40
_0810205A:
	mov r8, r4
	b _08102064
_0810205E:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08102064:
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _0810209C
	bl VM_GetPC
	cmp r0, #0
	beq _0810207E
	bl Script_GetValue
	adds r6, r0, #0
	b _08102080
_0810207E:
	movs r6, #0
_08102080:
	bl VM_GetPC
	cmp r0, #0
	beq _08102090
	bl Script_GetValue
	adds r1, r0, #0
	b _08102092
_08102090:
	movs r1, #0
_08102092:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081020A6
_0810209C:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081020A6:
	movs r0, #0x61
	bl prepare_08231510
	ldr r1, _08102330 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xbc]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x74]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x70]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xd0]
	lsls r4, r4, #0x10
	str r4, [sp, #0x90]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x9c]
	lsls r6, r6, #0x10
	str r6, [sp, #0xa0]
	lsls r5, r5, #0x10
	str r5, [sp, #0x94]
	ldr r4, _08102334 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xd8]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x8c]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x1a0]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa8]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xac]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x1a4]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x1a8]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x190]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x5c]
	ldr r1, _08102338 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x50]
	ldr r2, _0810233C @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x54]
	ldr r3, _08102340 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x58]
	ldr r4, _08102344 @ =0x00000476
	adds r4, r7, r4
	str r4, [sp, #0x48]
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x4c]
	ldr r6, _08102348 @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x80]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x84]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x104]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x10c]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x114]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x124]
	ldr r6, _0810234C @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0x128]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r2, _08102350 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0x140]
	ldr r3, _08102354 @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0x148]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x14c]
	ldr r5, _08102358 @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0x150]
	ldr r6, _0810235C @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x158]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x144]
	ldr r2, _08102360 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0x108]
	ldr r3, _08102364 @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x180]
	ldr r5, _08102368 @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0xb0]
	ldr r6, _0810236C @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x184]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x16c]
	ldr r2, _08102370 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x160]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x170]
	ldr r4, _08102374 @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x174]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x178]
	ldr r6, _08102378 @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x188]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x18c]
	ldr r2, _0810237C @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0x138]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x164]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x15c]
	ldr r5, _08102380 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x168]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x154]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x12c]
	ldr r2, _08102384 @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x198]
	ldr r3, _08102388 @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0x110]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x19c]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x134]
	ldr r6, _0810238C @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0x118]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x11c]
	ldr r2, _08102390 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0x120]
	ldr r3, _08102394 @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0x130]
	ldr r4, _08102398 @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0xb4]
	ldr r5, [sp, #0x28]
	adds r5, #8
	str r5, [sp, #0x194]
	adds r6, r7, #0
	adds r6, #0xd8
	str r6, [sp, #0x34]
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x78]
	movs r2, #0xcd
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x7c]
	ldr r3, _0810239C @ =0x00000496
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x38]
	ldr r5, _081023A0 @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0x3c]
	ldr r6, _081023A4 @ =0x0000046A
	adds r6, r7, r6
	str r6, [sp, #0x40]
	ldr r1, _081023A8 @ =0x00000553
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x100]
	movs r3, #0x92
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x68]
	movs r4, #0xea
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x98]
	ldr r5, _081023AC @ =0x00000572
	adds r5, r7, r5
	str r5, [sp, #0xfc]
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x88]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xf8]
	ldr r2, _081023B0 @ =0x0000055C
	adds r2, r7, r2
	str r2, [sp, #0xcc]
	movs r3, #0xac
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xd4]
	ldr r4, _081023B4 @ =0x00000564
	adds r4, r7, r4
	str r4, [sp, #0xdc]
	ldr r5, _081023B8 @ =0x00000565
	adds r5, r7, r5
	str r5, [sp, #0xe0]
	ldr r6, _081023BC @ =0x00000566
	adds r6, r7, r6
	str r6, [sp, #0xe8]
	ldr r1, _081023C0 @ =0x00000567
	adds r1, r7, r1
	str r1, [sp, #0xec]
	movs r2, #0xad
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xf0]
	ldr r3, _081023C4 @ =0x0000056C
	adds r3, r7, r3
	str r3, [sp, #0xf4]
	cmp r0, #0
	bne _08102302
	b _08102420
_08102302:
	movs r4, #0
	mov sl, r4
	movs r5, #0x8d
	lsls r5, r5, #2
	adds r5, r5, r7
	mov sb, r5
	movs r6, #0x8f
	lsls r6, r6, #2
	adds r6, r6, r7
	mov r8, r6
	movs r0, #0x8b
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r1, #0x89
	lsls r1, r1, #2
	adds r4, r7, r1
_08102322:
	bl VM_GetPC
	cmp r0, #0
	beq _081023C8
	bl Script_GetValue
	b _081023CA
	.align 2, 0
_08102330: .4byte 0x0000025D
_08102334: .4byte 0x0000025A
_08102338: .4byte 0x0000047A
_0810233C: .4byte 0x0000047C
_08102340: .4byte 0x0000047E
_08102344: .4byte 0x00000476
_08102348: .4byte 0x000004A4
_0810234C: .4byte 0x000005A4
_08102350: .4byte 0x000005C4
_08102354: .4byte 0x000005CC
_08102358: .4byte 0x000005D4
_0810235C: .4byte 0x000005DC
_08102360: .4byte 0x00000584
_08102364: .4byte 0x00000604
_08102368: .4byte 0x0000021D
_0810236C: .4byte 0x0000060C
_08102370: .4byte 0x000005E4
_08102374: .4byte 0x000005FC
_08102378: .4byte 0x00000614
_0810237C: .4byte 0x000005BC
_08102380: .4byte 0x000005EC
_08102384: .4byte 0x00000624
_08102388: .4byte 0x0000058C
_0810238C: .4byte 0x00000594
_08102390: .4byte 0x0000059C
_08102394: .4byte 0x000005B4
_08102398: .4byte 0x00000543
_0810239C: .4byte 0x00000496
_081023A0: .4byte 0x00000469
_081023A4: .4byte 0x0000046A
_081023A8: .4byte 0x00000553
_081023AC: .4byte 0x00000572
_081023B0: .4byte 0x0000055C
_081023B4: .4byte 0x00000564
_081023B8: .4byte 0x00000565
_081023BC: .4byte 0x00000566
_081023C0: .4byte 0x00000567
_081023C4: .4byte 0x0000056C
_081023C8:
	movs r0, #0x18
_081023CA:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081023DC
	bl Script_GetValue
	b _081023DE
_081023DC:
	movs r0, #0x18
_081023DE:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081023F0
	bl Script_GetValue
	b _081023F2
_081023F0:
	movs r0, #0
_081023F2:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08102404
	bl Script_GetValue
	b _08102406
_08102404:
	movs r0, #0
_08102406:
	strh r0, [r6]
	movs r2, #2
	add sb, r2
	movs r3, #4
	add r8, r3
	adds r5, #2
	adds r4, #2
	movs r6, #1
	add sl, r6
	mov r0, sl
	cmp r0, #3
	bgt _08102420
	b _08102322
_08102420:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _0810246C
	bl VM_GetPC
	cmp r0, #0
	beq _0810243A
	bl Script_GetValue
	adds r4, r0, #0
	b _0810243E
_0810243A:
	movs r4, #0x96
	lsls r4, r4, #1
_0810243E:
	bl VM_GetPC
	cmp r0, #0
	beq _0810244E
	bl Script_GetValue
	adds r6, r0, #0
	b _08102452
_0810244E:
	movs r6, #0x96
	lsls r6, r6, #1
_08102452:
	bl VM_GetPC
	cmp r0, #0
	beq _08102460
	bl Script_GetValue
	b _08102466
_08102460:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_08102466:
	ldr r2, [sp, #0xbc]
	strh r0, [r2]
	b _08102474
_0810246C:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0xbc]
	strh r6, [r3]
_08102474:
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _0810248C
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x64]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0810248C:
	movs r0, #0x46
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0x74]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, [sp, #0x70]
	strh r0, [r2]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _0810255C
	bl VM_GetPC
	cmp r0, #0
	beq _081024BC
	bl Script_GetValue
	b _081024BE
_081024BC:
	movs r0, #0
_081024BE:
	ldr r3, [sp, #0xd0]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _081024CC
	asrs r1, r0, #1
	b _081024D2
_081024CC:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081024D2:
	ldr r5, _081024E8 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081024EC
	bl Script_GetValue
	b _081024EE
	.align 2, 0
_081024E8: .4byte 0x00000546
_081024EC:
	movs r0, #0
_081024EE:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08102504
	bl Script_GetValue
	b _08102506
_08102504:
	movs r0, #0
_08102506:
	ldr r3, _0810251C @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08102520
	bl Script_GetValue
	adds r1, r0, #0
	b _08102522
	.align 2, 0
_0810251C: .4byte 0x00000187
_08102520:
	movs r1, #0
_08102522:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08102538
	bl Script_GetValue
	b _0810253A
_08102538:
	movs r0, #0
_0810253A:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08102552
	bl Script_GetValue
	adds r1, r0, #0
	b _08102554
_08102552:
	movs r1, #0
_08102554:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_0810255C:
	ldr r5, [sp, #0xd0]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r6, [sp, #0x90]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0x9c]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0xa0]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0x94]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl prepare_08231510
	cmp r0, #0
	beq _081025BE
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _081025A4
	bl Script_GetValue
	b _081025A6
_081025A4:
	movs r0, #0
_081025A6:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _081025B6
	bl Script_GetValue
	b _081025B8
_081025B6:
	movs r0, #0
_081025B8:
	ldr r6, _08102620 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_081025BE:
	movs r0, #0x4b
	movs r1, #2
	bl Script_GetKeywordValue
	ldr r1, [sp, #0xd8]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081025E2
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x64]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081025E2:
	movs r0, #0x4c
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081025FA
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x64]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081025FA:
	ldr r4, [sp, #0x8c]
	lsrs r1, r4, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x2c]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x44]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08102624
	movs r0, #1
	b _08102626
	.align 2, 0
_08102620: .4byte 0x00000189
_08102624:
	movs r0, #0
_08102626:
	cmp r0, #0
	beq _08102636
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08102660 @ =FUN_080f48ac
	ldr r1, [sp, #0x2c]
	bl FUN_0807f558
_08102636:
	ldr r6, [sp, #0xe4]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _08102642
	ldr r1, [r7, #0x44]
_08102642:
	ldr r0, [sp, #0x2c]
	bl FUN_0823b46c
	ldr r1, [sp, #0xa4]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _08102664
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x1a0]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _08102670
	.align 2, 0
_08102660: .4byte FUN_080f48ac
_08102664:
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x1a0]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_08102670:
	ldr r2, [sp, #0xa4]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081026BE
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081026BE
	cmp r0, #0x16
	beq _081026BE
	cmp r0, #0x14
	beq _081026BE
	cmp r0, #9
	beq _081026BE
	cmp r0, #0x19
	beq _081026BE
	cmp r0, #0x1a
	beq _081026BE
	cmp r0, #0xd
	beq _081026BE
	cmp r0, #0x1b
	beq _081026BE
	cmp r0, #0x1f
	beq _081026BE
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0xc0]
	ldrb r2, [r3]
	ldr r4, [sp, #0xc4]
	ldrb r3, [r4]
	ldr r5, [sp, #0xc8]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x2c]
	bl FUN_0823b490
_081026BE:
	movs r1, #8
	ldr r6, [sp, #0x44]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081026CE
	movs r0, #1
	b _081026D0
_081026CE:
	movs r0, #0
_081026D0:
	cmp r0, #0
	beq _081026DE
	ldr r1, [sp, #0xac]
	ldr r0, [r1]
	ldr r2, [sp, #0xa8]
	str r0, [r2]
	b _081026F0
_081026DE:
	ldr r3, [sp, #0xac]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0xa8]
	str r0, [r4]
_081026F0:
	ldrh r0, [r7]
	ldr r5, [sp, #0x1a4]
	strh r0, [r5]
	ldr r6, [sp, #0x190]
	ldr r0, [sp, #0x1a8]
	str r6, [r0]
	ldr r1, [sp, #0x30]
	cmp r1, #0
	beq _0810271A
	adds r0, r7, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	lsrs r0, r0, #0xc
	movs r1, #7
	ands r0, r1
	adds r0, #5
	ands r0, r1
	lsls r0, r0, #5
	ldr r2, [sp, #0x2c]
	strb r0, [r2, #5]
_0810271A:
	movs r0, #0x50
	bl prepare_08231510
	cmp r0, #0
	beq _08102784
	bl VM_GetPC
	cmp r0, #0
	beq _08102734
	bl Script_GetValue
	adds r1, r0, #0
	b _08102736
_08102734:
	movs r1, #0x78
_08102736:
	ldr r3, [sp, #0x24]
	ldr r4, _08102750 @ =0x00000674
	adds r0, r3, r4
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08102754
	bl Script_GetValue
	adds r1, r0, #0
	b _08102756
	.align 2, 0
_08102750: .4byte 0x00000674
_08102754:
	movs r1, #0x78
_08102756:
	ldr r5, [sp, #0x24]
	ldr r6, _08102770 @ =0x0000067E
	adds r0, r5, r6
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08102774
	bl Script_GetValue
	adds r1, r0, #0
	b _08102776
	.align 2, 0
_08102770: .4byte 0x0000067E
_08102774:
	movs r1, #0x78
_08102776:
	ldr r2, [sp, #0x24]
	ldr r3, _08102780 @ =0x00000672
	adds r0, r2, r3
	b _08102792
	.align 2, 0
_08102780: .4byte 0x00000672
_08102784:
	ldr r4, [sp, #0x24]
	ldr r5, _081027D0 @ =0x00000674
	adds r0, r4, r5
	movs r1, #0x78
	strb r1, [r0]
	ldr r6, _081027D4 @ =0x0000067E
	adds r0, r4, r6
_08102792:
	strh r1, [r0]
	movs r4, #0x99
	lsls r4, r4, #1
	movs r0, #0x43
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0x5c]
	strh r0, [r1]
	ldr r2, [sp, #0x50]
	strh r4, [r2]
	ldr r3, [sp, #0x54]
	strh r4, [r3]
	ldrh r0, [r1]
	adds r0, r0, r4
	ldr r4, [sp, #0x58]
	strh r0, [r4]
	ldrh r1, [r2]
	ldr r5, [sp, #0x5c]
	ldrh r0, [r5]
	adds r1, r1, r0
	ldr r6, [sp, #0xe4]
	ldrb r0, [r6]
	cmp r0, #0
	bne _081027D8
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _081027E4
	.align 2, 0
_081027D0: .4byte 0x00000674
_081027D4: .4byte 0x0000067E
_081027D8:
	ldr r2, [r7, #0x44]
	ldr r0, _0810281C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081027E4:
	ldr r1, [sp, #0xe4]
	ldrb r0, [r1]
	cmp r0, #1
	bne _08102834
	ldr r2, [sp, #0xa4]
	ldrb r0, [r2]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08102820
	movs r0, #5
	bl FUN_080ecf60
	adds r4, r0, #1
	movs r0, #6
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #7
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #8
	bl FUN_080ecf60
	adds r4, r4, r0
	b _0810282A
	.align 2, 0
_0810281C: .4byte 0x03003584
_08102820:
	ldr r3, [sp, #0xa4]
	ldrb r0, [r3]
	bl FUN_080ecf60
	adds r4, r0, #1
_0810282A:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_08102834:
	movs r4, #0
	ldr r5, [sp, #0x50]
	ldrh r0, [r5]
	adds r0, #4
	ldr r6, [sp, #0x48]
	strh r0, [r6]
	ldrh r0, [r5]
	ldr r1, [sp, #0x4c]
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_080ffa44
	ldr r2, [sp, #0x24]
	movs r3, #0xd0
	lsls r3, r3, #3
	adds r0, r2, r3
	ldr r5, _081029F4 @ =0x000006A4
	adds r2, r2, r5
	mov r8, r2
	ldr r6, _081029F8 @ =FUN_08101bc0
	mov sb, r6
	ldr r1, _081029FC @ =FUN_080ffcd0
	mov sl, r1
	ldr r2, _08102A00 @ =FUN_080fba64
	mov ip, r2
	ldr r5, _08102A04 @ =FUN_080fd08c
	ldr r3, _08102A08 @ =FUN_080f62b0
	ldr r6, _08102A0C @ =FUN_080f62ac
	str r6, [sp, #0x1ac]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x60]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x80]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x84]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0x104]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0x10c]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0x114]
	str r2, [r6]
	ldr r1, _08102A10 @ =FUN_080fba28
	ldr r2, [sp, #0x124]
	str r1, [r2]
	ldr r6, _08102A14 @ =FUN_080fba40
	ldr r1, [sp, #0x128]
	str r6, [r1]
	ldr r2, _08102A18 @ =FUN_080fc0b8
	ldr r6, [sp, #0x13c]
	str r2, [r6]
	ldr r1, [sp, #0x140]
	str r3, [r1]
	ldr r2, [sp, #0x148]
	str r5, [r2]
	ldr r3, _08102A1C @ =FUN_080fe274
	ldr r5, [sp, #0x14c]
	str r3, [r5]
	ldr r1, _08102A20 @ =FUN_080f44f4
	ldr r6, [sp, #0x150]
	str r1, [r6]
	ldr r1, _08102A24 @ =FUN_080f410c
	ldr r2, [sp, #0x158]
	str r1, [r2]
	ldr r3, _08102A28 @ =FUN_080fc548
	ldr r5, [sp, #0x144]
	str r3, [r5]
	ldr r6, _08102A2C @ =FUN_080fc1e4
	ldr r1, [sp, #0x108]
	str r6, [r1]
	ldr r2, [sp, #0x1ac]
	ldr r3, [sp, #0x17c]
	str r2, [r3]
	ldr r1, _08102A30 @ =FUN_080f0430
	ldr r5, [sp, #0x180]
	str r1, [r5]
	movs r1, #1
	ldr r6, [sp, #0xb0]
	strb r1, [r6]
	ldr r1, _08102A34 @ =0x085AD470
	ldr r2, [sp, #0x184]
	str r1, [r2]
	ldr r1, _08102A38 @ =FUN_080e73c8
	ldr r3, [sp, #0x16c]
	str r1, [r3]
	ldr r5, [sp, #0x160]
	str r4, [r5]
	ldr r6, [sp, #0x170]
	str r4, [r6]
	ldr r1, [sp, #0x174]
	str r4, [r1]
	ldr r2, [sp, #0x178]
	str r4, [r2]
	ldr r3, [sp, #0x188]
	str r4, [r3]
	ldr r1, _08102A3C @ =FUN_080f0320
	ldr r5, [sp, #0x18c]
	str r1, [r5]
	ldr r1, _08102A40 @ =FUN_080eff14
	ldr r6, [sp, #0x138]
	str r1, [r6]
	ldr r1, _08102A44 @ =FUN_080e72b0
	ldr r2, [sp, #0x164]
	str r1, [r2]
	ldr r3, _08102A48 @ =FUN_080fc4ec
	ldr r5, [sp, #0x15c]
	str r3, [r5]
	ldr r1, _08102A4C @ =FUN_080f47c8
	ldr r6, [sp, #0x168]
	str r1, [r6]
	ldr r1, _08102A50 @ =FUN_080f54e4
	ldr r2, [sp, #0x154]
	str r1, [r2]
	ldr r3, [sp, #0x12c]
	str r4, [r3]
	ldr r1, _08102A54 @ =FUN_080f6e64
	ldr r5, [sp, #0x198]
	str r1, [r5]
	ldr r1, _08102A58 @ =FUN_080f64f0
	ldr r6, [sp, #0x110]
	str r1, [r6]
	ldr r1, _08102A5C @ =FUN_080f84d4
	ldr r2, [sp, #0x19c]
	str r1, [r2]
	ldr r1, _08102A60 @ =FUN_080f624c
	ldr r3, [sp, #0x134]
	str r1, [r3]
	ldr r1, _08102A64 @ =FUN_080f56ec
	ldr r5, [sp, #0x118]
	str r1, [r5]
	ldr r1, _08102A68 @ =FUN_080f5b34
	ldr r6, [sp, #0x11c]
	str r1, [r6]
	ldr r1, _08102A6C @ =FUN_080f5fac
	ldr r2, [sp, #0x120]
	str r1, [r2]
	ldr r3, [sp, #0x130]
	str r4, [r3]
	movs r1, #0x28
	ldr r4, [sp, #0xb4]
	strb r1, [r4]
	ldr r1, [sp, #0x194]
	bl FUN_082362fc
	adds r0, r7, #0
	bl FUN_080e6204
	movs r5, #0xbf
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _08102A70 @ =FUN_080ffad8
	str r0, [r1]
	ldr r6, _08102A74 @ =0x000005FC
	adds r1, r7, r6
	ldr r0, _08102A78 @ =FUN_080ffc28
	str r0, [r1]
	ldr r0, _08102A7C @ =0x000005AC
	adds r1, r7, r0
	ldr r0, _08102A80 @ =FUN_080ff6e8
	str r0, [r1]
	movs r2, #0xb6
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _08102A84 @ =FUN_080ff7c0
	str r0, [r1]
	ldr r3, _08102A88 @ =0x0000058C
	adds r1, r7, r3
	ldr r0, _08102A8C @ =FUN_08100228
	str r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #0x11
	ldr r4, [sp, #0x60]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #0x14
	ldr r5, [sp, #0x64]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r0, #2
	rsbs r0, r0, #0
	ldr r6, [sp, #0x34]
	ldrh r1, [r6, #6]
	ands r0, r1
	strh r0, [r6, #6]
	ldr r1, _08102A90 @ =0x000001DF
	adds r0, r7, r1
	movs r2, #4
	strb r2, [r0]
	adds r0, r7, #0
	bl FUN_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x78]
	strh r0, [r3]
	movs r0, #0x47
	bl prepare_08231510
	cmp r0, #0
	beq _08102A9E
	movs r4, #0xce
	lsls r4, r4, #1
	adds r5, r7, r4
	movs r4, #4
_081029E4:
	bl VM_GetPC
	cmp r0, #0
	beq _08102A94
	bl Script_GetValue
	b _08102A96
	.align 2, 0
_081029F4: .4byte 0x000006A4
_081029F8: .4byte FUN_08101bc0
_081029FC: .4byte FUN_080ffcd0
_08102A00: .4byte FUN_080fba64
_08102A04: .4byte FUN_080fd08c
_08102A08: .4byte FUN_080f62b0
_08102A0C: .4byte FUN_080f62ac
_08102A10: .4byte FUN_080fba28
_08102A14: .4byte FUN_080fba40
_08102A18: .4byte FUN_080fc0b8
_08102A1C: .4byte FUN_080fe274
_08102A20: .4byte FUN_080f44f4
_08102A24: .4byte FUN_080f410c
_08102A28: .4byte FUN_080fc548
_08102A2C: .4byte FUN_080fc1e4
_08102A30: .4byte FUN_080f0430
_08102A34: .4byte 0x085AD470
_08102A38: .4byte FUN_080e73c8
_08102A3C: .4byte FUN_080f0320
_08102A40: .4byte FUN_080eff14
_08102A44: .4byte FUN_080e72b0
_08102A48: .4byte FUN_080fc4ec
_08102A4C: .4byte FUN_080f47c8
_08102A50: .4byte FUN_080f54e4
_08102A54: .4byte FUN_080f6e64
_08102A58: .4byte FUN_080f64f0
_08102A5C: .4byte FUN_080f84d4
_08102A60: .4byte FUN_080f624c
_08102A64: .4byte FUN_080f56ec
_08102A68: .4byte FUN_080f5b34
_08102A6C: .4byte FUN_080f5fac
_08102A70: .4byte FUN_080ffad8
_08102A74: .4byte 0x000005FC
_08102A78: .4byte FUN_080ffc28
_08102A7C: .4byte 0x000005AC
_08102A80: .4byte FUN_080ff6e8
_08102A84: .4byte FUN_080ff7c0
_08102A88: .4byte 0x0000058C
_08102A8C: .4byte FUN_08100228
_08102A90: .4byte 0x000001DF
_08102A94:
	movs r0, #0
_08102A96:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081029E4
_08102A9E:
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r5, [sp, #0x7c]
	strh r0, [r5]
	movs r0, #0x75
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r6, [sp, #0x6c]
	strh r0, [r6]
	cmp r2, #0
	beq _08102AD6
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r3, [sp, #0x60]
	ldr r1, [r3]
	orrs r1, r0
	str r1, [r3]
	cmp r2, #2
	bne _08102AD6
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r3]
_08102AD6:
	movs r2, #0
	movs r1, #4
	ldr r4, [sp, #0x44]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08102AE8
	movs r0, #1
	b _08102AEA
_08102AE8:
	movs r0, #0
_08102AEA:
	cmp r0, #0
	beq _08102AFC
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r5, [sp, #0x64]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r2, #1
_08102AFC:
	cmp r2, #1
	beq _08102B3C
	movs r1, #0
	ldr r6, [sp, #0x38]
	strb r1, [r6]
	ldr r0, [sp, #0x3c]
	strb r1, [r0]
	ldr r2, [sp, #0x40]
	strb r1, [r2]
	ldr r3, _08102B4C @ =0x00000484
	adds r0, r7, r3
	str r1, [r0]
	ldr r4, _08102B50 @ =0x0000046C
	adds r0, r7, r4
	movs r2, #1
	strb r2, [r0]
	ldr r5, [sp, #0x128]
	ldr r3, [r5]
	ldr r6, _08102B54 @ =0x0000046D
	adds r0, r7, r6
	strb r2, [r0]
	ldr r2, _08102B58 @ =0x0000046B
	adds r0, r7, r2
	strb r1, [r0]
	ldr r4, [sp, #0xb8]
	strb r1, [r4]
	ldr r5, [sp, #0x100]
	str r3, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
_08102B3C:
	movs r1, #2
	ldr r2, [sp, #0x44]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08102B5C
	movs r0, #1
	b _08102B5E
	.align 2, 0
_08102B4C: .4byte 0x00000484
_08102B50: .4byte 0x0000046C
_08102B54: .4byte 0x0000046D
_08102B58: .4byte 0x0000046B
_08102B5C:
	movs r0, #0
_08102B5E:
	cmp r0, #0
	beq _08102B78
	ldr r0, _08102B74 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x68]
	strh r0, [r4]
	b _08102B82
	.align 2, 0
_08102B74: .4byte 0x030046A0
_08102B78:
	ldr r0, [sp, #0x190]
	bl FUN_08241574
	ldr r5, [sp, #0x68]
	strh r0, [r5]
_08102B82:
	movs r1, #0x40
	ldr r6, [sp, #0x44]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08102B92
	movs r0, #1
	b _08102B94
_08102B92:
	movs r0, #0
_08102B94:
	cmp r0, #0
	beq _08102BA2
	ldr r0, _08102BC8 @ =0xFFFFFEFF
	ldr r2, [sp, #0x34]
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_08102BA2:
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _08102BD6
	ldr r0, _08102BCC @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x68]
	ldrh r4, [r4]
	cmp r0, r4
	bne _08102BD0
	movs r0, #1
	b _08102BD2
	.align 2, 0
_08102BC8: .4byte 0xFFFFFEFF
_08102BCC: .4byte 0x030046A0
_08102BD0:
	movs r0, #0
_08102BD2:
	cmp r0, #0
	bne _08102BDE
_08102BD6:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_08102BDE:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0xe4]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08102CC6
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
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
	beq _08102C20
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08102C28
_08102C20:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08102C28:
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
	beq _08102C4C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08102C54
_08102C4C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08102C54:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _08102C8C @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08102CD0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08102C90
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08102C84
	ldrb r0, [r4, #5]
_08102C84:
	subs r0, #1
	strh r0, [r4, #8]
	b _08102CA0
	.align 2, 0
_08102C8C: .4byte 0x0000FFFF
_08102C90:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08102CA0
	strh r1, [r4, #8]
_08102CA0:
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
	bne _08102CD0
	movs r0, #1
	strb r0, [r4, #7]
	b _08102CD0
_08102CC6:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_08102CD0:
	movs r0, #0
	ldr r3, [sp, #0x98]
	str r0, [r3]
	ldr r0, _08102CE8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08102CEC
	movs r0, #1
	b _08102CEE
	.align 2, 0
_08102CE8: .4byte 0x030047A4
_08102CEC:
	movs r0, #0
_08102CEE:
	cmp r0, #0
	bne _08102D2E
	ldr r4, [sp, #0xa4]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08102D16
	adds r0, r1, #0
	cmp r0, #7
	beq _08102D16
	cmp r0, #6
	beq _08102D16
	cmp r0, #0x15
	beq _08102D16
	cmp r0, #0x14
	beq _08102D16
	cmp r0, #0x17
	bne _08102D2E
_08102D16:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x44]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_08102D2E:
	adds r0, r7, #0
	bl FUN_080f3680
	adds r0, r7, #0
	bl FUN_080ff45c
	adds r0, r7, #0
	bl FUN_080ff05c
	adds r0, r7, #0
	bl FUN_080ff668
	ldr r6, [sp, #0x44]
	ldrh r0, [r6]
	ldr r1, [sp, #0xfc]
	strh r0, [r1]
	ldr r2, [sp, #0x88]
	ldrh r0, [r2]
	ldr r3, [sp, #0xf8]
	strh r0, [r3]
	ldr r4, [sp, #0x60]
	ldr r0, [r4]
	ldr r5, [sp, #0xcc]
	str r0, [r5]
	ldr r6, [sp, #0x64]
	ldr r0, [r6]
	ldr r1, [sp, #0xd4]
	str r0, [r1]
	ldrb r0, [r7, #5]
	ldr r2, [sp, #0xdc]
	strb r0, [r2]
	ldr r3, [sp, #0x38]
	ldrb r0, [r3]
	ldr r4, [sp, #0xe0]
	strb r0, [r4]
	ldr r5, [sp, #0x3c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xe8]
	strb r0, [r6]
	ldr r1, [sp, #0x40]
	ldrb r0, [r1]
	ldr r2, [sp, #0xec]
	strb r0, [r2]
	ldr r3, [sp, #0x100]
	ldr r0, [r3]
	ldr r4, [sp, #0xf0]
	str r0, [r4]
	ldr r5, [sp, #0xb8]
	ldrb r0, [r5]
	ldr r6, [sp, #0xf4]
	strb r0, [r6]
	ldr r0, _08102DC0 @ =0x0000057C
	adds r1, r7, r0
	ldr r0, _08102DC4 @ =FUN_080f09e0
	str r0, [r1]
	ldr r2, _08102DC8 @ =0x0000061C
	adds r1, r7, r2
	ldr r0, _08102DCC @ =FUN_08101c1c
	str r0, [r1]
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _08102DD0 @ =FUN_08101c28
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08102DD4
	movs r0, #0
	b _08102DD8
	.align 2, 0
_08102DC0: .4byte 0x0000057C
_08102DC4: .4byte FUN_080f09e0
_08102DC8: .4byte 0x0000061C
_08102DCC: .4byte FUN_08101c1c
_08102DD0: .4byte FUN_08101c28
_08102DD4:
	movs r0, #1
	rsbs r0, r0, #0
_08102DD8:
	add sp, #0x1b4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

