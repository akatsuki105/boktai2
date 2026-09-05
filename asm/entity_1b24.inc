	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809ce90
FUN_0809ce90: @ 0x0809CE90
	ldr r3, _0809CEA0 @ =0x00000F8C
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _0809CEA4 @ =0x00000F72
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_0809CEA0: .4byte 0x00000F8C
_0809CEA4: .4byte 0x00000F72

	thumb_func_start FUN_0809cea8
FUN_0809cea8: @ 0x0809CEA8
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	ldr r0, [r6, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809CEFC
	ldr r1, _0809CEF4 @ =0x00000E2B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809CF0A
	movs r0, #1
	bl FUN_080477e4
	ldr r0, [r6, #0x24]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r0, _0809CEF8 @ =0x00000F4C
	adds r4, r6, r0
	adds r0, #0x2c
	adds r1, r6, r0
	adds r0, r4, #0
	bl FUN_08094d1c
	ldr r1, [r6, #0x24]
	adds r0, r4, #0
	bl FUN_08094d48
	b _0809CF8A
	.align 2, 0
_0809CEF4: .4byte 0x00000E2B
_0809CEF8: .4byte 0x00000F4C
_0809CEFC:
	ldr r0, _0809CF24 @ =0x00000E2B
	adds r4, r6, r0
	ldrb r0, [r4]
	bl GetWeaponID
	cmp r0, #0
	bne _0809CF28
_0809CF0A:
	movs r1, #0xe2
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _0809CF8A
	.align 2, 0
_0809CF24: .4byte 0x00000E2B
_0809CF28:
	ldrb r0, [r4]
	mov r1, sp
	bl FUN_08242b14
	movs r0, #0xe2
	lsls r0, r0, #3
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r4, r6, r1
	adds r5, r6, #0
	adds r5, #0x48
	mov r0, sp
	bl FUN_08094e70
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl Sprite_SetSprite
	movs r0, #1
	bl FUN_080477e4
	ldr r0, [r6, #0x24]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r0, _0809CF94 @ =0x00000F78
	adds r1, r6, r0
	mov r0, sp
	bl FUN_08094d1c
	ldr r1, [r6, #0x24]
	mov r0, sp
	bl FUN_08094d48
_0809CF8A:
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809CF94: .4byte 0x00000F78

	thumb_func_start FUN_0809cf98
FUN_0809cf98: @ 0x0809CF98
	push {lr}
	bl GetWeaponID
	cmp r0, #0
	beq _0809CFB6
	cmp r0, #0x3a
	beq _0809CFB6
	cmp r0, #0x3e
	beq _0809CFB6
	cmp r0, #0x3f
	beq _0809CFB6
	cmp r0, #0x40
	beq _0809CFB6
	cmp r0, #0x41
	bne _0809CFBA
_0809CFB6:
	movs r0, #0
	b _0809CFBC
_0809CFBA:
	movs r0, #1
_0809CFBC:
	pop {r1}
	bx r1

	thumb_func_start FUN_0809cfc0
FUN_0809cfc0: @ 0x0809CFC0
	push {r4, lr}
	adds r4, r1, #0
	ldrb r1, [r4, #1]
	cmp r1, #0
	blt _0809D004
	cmp r1, #2
	ble _0809CFD4
	cmp r1, #4
	beq _0809CFEC
	b _0809D004
_0809CFD4:
	movs r1, #0xf8
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, #0x63
	asrs r0, r0, #1
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r0, r1
	b _0809D006
_0809CFEC:
	movs r0, #0x28
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	subs r1, #8
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	lsls r0, r0, #1
	b _0809D006
_0809D004:
	movs r0, #0
_0809D006:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809d00c
FUN_0809d00c: @ 0x0809D00C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	mov r8, r0
	movs r0, #0
	mov r1, sp
	adds r1, #0x24
	str r1, [sp, #0x40]
	movs r2, #0x28
	add r2, r8
	mov sb, r2
_0809D028:
	lsls r1, r0, #1
	lsls r2, r0, #2
	adds r7, r0, #1
	adds r0, #0x16
	adds r1, r1, r0
	ldr r0, [sp, #0x40]
	adds r6, r0, r2
	movs r5, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, #0xa8
	mov r1, r8
	adds r4, r0, r1
_0809D044:
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	movs r3, #1
	bl Sprite_SetSprite
	movs r0, #0
	str r0, [r6]
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809D044
	adds r0, r7, #0
	cmp r0, #3
	ble _0809D028
	mov r2, r8
	ldr r0, [r2, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809D0CC
	ldr r1, _0809D0C4 @ =0x00000F4C
	add r1, r8
	mov r0, r8
	bl FUN_0809cfc0
	ldr r1, [sp, #0x40]
	str r0, [r1, #0xc]
	movs r1, #0x64
	bl Div
	add r4, sp, #0x34
	str r0, [sp, #0x34]
	movs r1, #0x64
	muls r1, r0, r1
	ldr r2, [sp, #0x40]
	ldr r0, [r2, #0xc]
	subs r6, r0, r1
	adds r0, r6, #0
	movs r1, #0xa
	bl Div
	str r0, [r4, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r6, r1
	str r1, [r4, #8]
	ldr r6, _0809D0C8 @ =0x00000C48
	add r6, r8
	movs r5, #2
_0809D0AA:
	ldm r4!, {r2}
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809D0AA
	b _0809D21E
	.align 2, 0
_0809D0C4: .4byte 0x00000F4C
_0809D0C8: .4byte 0x00000C48
_0809D0CC:
	movs r7, #1
	rsbs r7, r7, #0
	movs r1, #0xf7
	lsls r1, r1, #4
	add r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0809D162
	mov r1, sp
	bl FUN_08242b14
	mov r0, sp
	ldrb r0, [r0, #1]
	movs r7, #0
	cmp r0, #0
	beq _0809D0FC
	movs r7, #1
	cmp r0, #1
	beq _0809D0FC
	movs r7, #3
	cmp r0, #2
	bne _0809D0FC
	movs r7, #2
_0809D0FC:
	mov r0, r8
	mov r1, sp
	bl FUN_0809cfc0
	lsls r4, r7, #2
	ldr r1, [sp, #0x40]
	adds r4, r1, r4
	str r0, [r4]
	movs r1, #0x64
	bl Div
	add r5, sp, #0x34
	str r0, [sp, #0x34]
	movs r1, #0x64
	muls r1, r0, r1
	ldr r0, [r4]
	subs r6, r0, r1
	adds r0, r6, #0
	movs r1, #0xa
	bl Div
	str r0, [r5, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r6, r1
	str r1, [r5, #8]
	lsls r1, r7, #1
	adds r6, r5, #0
	adds r0, r7, #0
	adds r0, #0x16
	adds r1, r1, r0
	movs r5, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, #0xa8
	mov r2, r8
	adds r4, r0, r2
_0809D14A:
	ldm r6!, {r2}
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809D14A
_0809D162:
	ldr r4, _0809D1AC @ =0x00000E2B
	add r4, r8
	ldrb r0, [r4]
	bl FUN_0809cf98
	cmp r0, #0
	beq _0809D21E
	ldrb r0, [r4]
	mov r1, sp
	bl FUN_08242b14
	mov r0, sp
	ldrb r0, [r0, #1]
	movs r1, #0
	mov sl, r1
	cmp r0, #0
	beq _0809D198
	movs r2, #1
	mov sl, r2
	cmp r0, #1
	beq _0809D198
	movs r1, #3
	mov sl, r1
	cmp r0, #2
	bne _0809D198
	movs r2, #2
	mov sl, r2
_0809D198:
	mov r0, r8
	mov r1, sp
	bl FUN_0809cfc0
	adds r5, r0, #0
	cmp r7, #0
	bge _0809D1B0
	movs r7, #0xa
	b _0809D1C6
	.align 2, 0
_0809D1AC: .4byte 0x00000E2B
_0809D1B0:
	lsls r0, r7, #2
	ldr r1, [sp, #0x40]
	adds r0, r1, r0
	ldr r0, [r0]
	movs r7, #0xa
	cmp r5, r0
	bgt _0809D1C6
	movs r7, #0
	cmp r5, r0
	bge _0809D1C6
	movs r7, #0x14
_0809D1C6:
	adds r0, r5, #0
	movs r1, #0x64
	bl Div
	add r4, sp, #0x34
	str r0, [sp, #0x34]
	movs r1, #0x64
	muls r0, r1, r0
	subs r6, r5, r0
	adds r0, r6, #0
	movs r1, #0xa
	bl Div
	str r0, [r4, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r6, r1
	str r1, [r4, #8]
	mov r2, sl
	lsls r1, r2, #1
	mov r0, sl
	adds r0, #0x16
	adds r1, r1, r0
	movs r5, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, #0xa8
	mov r1, r8
	adds r6, r0, r1
_0809D204:
	ldm r4!, {r2}
	adds r2, r2, r7
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809D204
_0809D21E:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809d230
FUN_0809d230: @ 0x0809D230
	push {lr}
	bl FUN_08047864
	bl FUN_08049e5c
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809d240
FUN_0809d240: @ 0x0809D240
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	cmp r2, #0xf
	bgt _0809D264
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r3]
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	b _0809D26A
_0809D264:
	movs r0, #0x40
	strh r0, [r3]
	movs r0, #0x4c
_0809D26A:
	strh r0, [r3, #2]
	pop {r0}
	bx r0

	thumb_func_start FUN_0809d270
FUN_0809d270: @ 0x0809D270
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r0, #1
	str r0, [sp, #0x2c]
	ldr r1, _0809D2F0 @ =0x00000E2B
	adds r0, r5, r1
	ldrb r0, [r0]
	bl GetWeaponID
	str r0, [sp, #0x34]
	ldr r0, _0809D2F4 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	movs r1, #0xf7
	lsls r1, r1, #4
	adds r0, r5, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	add r0, sp, #0xc
	bl FUN_0809d240
	add r4, sp, #0x1c
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_0809d240
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	add r6, sp, #0x34
	str r2, [r6, #4]
	add r3, sp, #0x3c
	mov r0, r8
	str r0, [r3, #4]
	add r0, sp, #0xc
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	strh r2, [r4, #8]
	strh r2, [r4, #0xa]
	strh r2, [r4, #0xc]
	ldr r0, _0809D2F8 @ =0x00000E58
	adds r5, r5, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _0809D2FC @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809D2F0: .4byte 0x00000E2B
_0809D2F4: .4byte 0x000002DF
_0809D2F8: .4byte 0x00000E58
_0809D2FC: .4byte 0x0000038A

	thumb_func_start FUN_0809d300
FUN_0809d300: @ 0x0809D300
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0xf7
	lsls r0, r0, #4
	adds r3, r6, r0
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bge _0809D338
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x83
	lsls r0, r0, #4
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xfa
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	b _0809D3C2
_0809D338:
	movs r1, #0xd6
	lsls r1, r1, #3
	adds r2, r6, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, [r6, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809D366
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r6, r2
	adds r1, r6, #0
	adds r1, #0x48
	movs r2, #0x3c
	movs r3, #1
	bl Sprite_SetSprite
	b _0809D388
_0809D366:
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r4, r6, r0
	adds r5, r6, #0
	adds r5, #0x48
	movs r0, #0
	ldrsb r0, [r3, r0]
	bl GetWeaponID
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl Sprite_SetSprite
_0809D388:
	movs r2, #0x83
	lsls r2, r2, #4
	adds r1, r6, r2
	ldr r0, [r1]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r1]
	ldr r1, _0809D3CC @ =0x00000848
	adds r0, r6, r1
	movs r2, #0xf7
	lsls r2, r2, #4
	adds r1, r6, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl FUN_0809d240
	movs r0, #0xfa
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r2, #0xdd
	lsls r2, r2, #4
	adds r1, r6, r2
	ldr r0, [r1]
	ands r0, r4
_0809D3C2:
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809D3CC: .4byte 0x00000848

	thumb_func_start FUN_0809d3d0
FUN_0809d3d0: @ 0x0809D3D0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0xed
	lsls r0, r0, #3
	adds r5, r6, r0
	adds r1, r6, #0
	adds r1, #0x28
	adds r0, r5, #0
	bl FUN_082372cc
	ldr r2, _0809D3FC @ =0x00000F74
	adds r1, r6, r2
	ldr r0, [r1]
	cmp r0, #0
	beq _0809D400
	subs r0, #1
	str r0, [r1]
	b _0809D792
	.align 2, 0
_0809D3FC: .4byte 0x00000F74
_0809D400:
	ldr r0, _0809D458 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809D468
	ldr r0, [r6, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809D418
	b _0809D574
_0809D418:
	ldr r3, _0809D45C @ =0x00000E2B
	adds r4, r6, r3
	ldrb r0, [r4]
	bl FUN_0809cf98
	cmp r0, #0
	bne _0809D428
	b _0809D574
_0809D428:
	ldrb r2, [r4]
	movs r0, #0xf7
	lsls r0, r0, #4
	adds r1, r6, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	bne _0809D43A
	b _0809D574
_0809D43A:
	strb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r2, _0809D460 @ =0x00000F4C
	adds r1, r6, r2
	bl FUN_08242b14
	adds r0, r6, #0
	bl FUN_0809d270
	ldr r1, _0809D464 @ =FUN_0809d7a4
	adds r0, r6, #0
	bl FUN_0809ce90
	b _0809D792
	.align 2, 0
_0809D458: .4byte 0x030044E0
_0809D45C: .4byte 0x00000E2B
_0809D460: .4byte 0x00000F4C
_0809D464: .4byte FUN_0809d7a4
_0809D468:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809D55C
	movs r0, #0xde
	bl PlaySound_082406e0
	ldr r0, [r6, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	movs r3, #0xb0
	adds r3, r3, r6
	mov r8, r3
	cmp r0, #2
	beq _0809D51C
	movs r0, #0xf7
	lsls r0, r0, #4
	adds r1, r6, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0809D51C
	ldr r2, _0809D54C @ =0x00000F4C
	adds r4, r6, r2
	adds r1, r0, #0
	mov ip, r1
	ldr r0, _0809D550 @ =0x03002C68
	ldr r2, [r0]
	cmp r2, #0
	beq _0809D51C
	movs r3, #0xae
	lsls r3, r3, #1
	adds r5, r2, r3
	cmp r5, #0
	beq _0809D51C
	ldrb r0, [r4]
	strb r0, [r5, #0x1c]
	ldrb r0, [r4, #1]
	strb r0, [r5, #0x1d]
	ldrb r0, [r4, #2]
	strb r0, [r5, #0x1e]
	ldrb r0, [r4, #3]
	strb r0, [r5, #0x1f]
	ldrb r1, [r4, #4]
	adds r3, #0x20
	adds r0, r2, r3
	strb r1, [r0]
	ldrb r0, [r4, #5]
	adds r3, #1
	adds r1, r2, r3
	strb r0, [r1]
	ldrh r0, [r4, #6]
	strh r0, [r5, #0x22]
	ldrh r0, [r4, #8]
	strh r0, [r5, #0x24]
	ldrh r0, [r4, #0xa]
	strh r0, [r5, #0x26]
	movs r3, #0
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r7, r2, r0
	ldr r1, _0809D554 @ =0x00000F58
	adds r2, r6, r1
_0809D4E6:
	adds r0, r7, r3
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, #1
	cmp r3, #0xb
	ble _0809D4E6
	adds r2, r5, #0
	adds r2, #0x34
	adds r1, r4, #0
	adds r1, #0x18
	movs r3, #2
_0809D4FE:
	ldrb r0, [r1]
	strb r0, [r2]
	ldrb r0, [r1, #1]
	strb r0, [r2, #1]
	ldrb r0, [r1, #2]
	strb r0, [r2, #2]
	ldrb r0, [r1, #3]
	strb r0, [r2, #3]
	adds r2, #4
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bge _0809D4FE
	mov r2, ip
	strb r2, [r5, #0x17]
_0809D51C:
	adds r0, r6, #0
	bl FUN_0809d230
	movs r3, #1
	mov r1, r8
	movs r2, #0x23
_0809D528:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0809D528
	ldr r3, _0809D558 @ =0x00000F84
	adds r0, r6, r3
	ldr r0, [r0]
	cmp r0, #0
	bne _0809D542
	b _0809D762
_0809D542:
	movs r1, #0
	bl Script_ExecById
	b _0809D762
	.align 2, 0
_0809D54C: .4byte 0x00000F4C
_0809D550: .4byte 0x03002C68
_0809D554: .4byte 0x00000F58
_0809D558: .4byte 0x00000F84
_0809D55C:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0809D566
	b _0809D770
_0809D566:
	movs r0, #0xf7
	lsls r0, r0, #4
	adds r5, r6, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bge _0809D57E
_0809D574:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0809D792
_0809D57E:
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, [r6, #0x18]
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809D634
	ldr r2, _0809D628 @ =0x00000F4C
	adds r4, r6, r2
	ldrb r1, [r1, #0x17]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov ip, r1
	ldr r0, _0809D62C @ =0x03002C68
	ldr r2, [r0]
	mov sb, r0
	movs r3, #0xb0
	adds r3, r3, r6
	mov r8, r3
	cmp r2, #0
	bne _0809D5AE
	b _0809D6CA
_0809D5AE:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r5, r2, r0
	cmp r5, #0
	bne _0809D5BA
	b _0809D6CA
_0809D5BA:
	ldrb r0, [r4]
	strb r0, [r5, #0x1c]
	ldrb r0, [r4, #1]
	strb r0, [r5, #0x1d]
	ldrb r0, [r4, #2]
	strb r0, [r5, #0x1e]
	ldrb r0, [r4, #3]
	strb r0, [r5, #0x1f]
	ldrb r1, [r4, #4]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	ldrb r0, [r4, #5]
	adds r3, #1
	adds r1, r2, r3
	strb r0, [r1]
	ldrh r0, [r4, #6]
	strh r0, [r5, #0x22]
	ldrh r0, [r4, #8]
	strh r0, [r5, #0x24]
	ldrh r0, [r4, #0xa]
	strh r0, [r5, #0x26]
	movs r3, #0
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r7, r2, r0
	ldr r1, _0809D630 @ =0x00000F58
	adds r2, r6, r1
_0809D5F4:
	adds r0, r7, r3
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, #1
	cmp r3, #0xb
	ble _0809D5F4
	adds r2, r5, #0
	adds r2, #0x34
	adds r1, r4, #0
	adds r1, #0x18
	movs r3, #2
_0809D60C:
	ldrb r0, [r1]
	strb r0, [r2]
	ldrb r0, [r1, #1]
	strb r0, [r2, #1]
	ldrb r0, [r1, #2]
	strb r0, [r2, #2]
	ldrb r0, [r1, #3]
	strb r0, [r2, #3]
	adds r2, #4
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bge _0809D60C
	b _0809D6C6
	.align 2, 0
_0809D628: .4byte 0x00000F4C
_0809D62C: .4byte 0x03002C68
_0809D630: .4byte 0x00000F58
_0809D634:
	ldr r3, _0809D6E0 @ =0x00000F4C
	adds r4, r6, r3
	ldrb r5, [r5]
	lsls r5, r5, #0x18
	asrs r5, r5, #0x18
	mov ip, r5
	ldr r0, _0809D6E4 @ =0x03002C68
	ldr r2, [r0]
	mov sb, r0
	movs r0, #0xb0
	adds r0, r0, r6
	mov r8, r0
	cmp r2, #0
	beq _0809D6CA
	movs r1, #0xae
	lsls r1, r1, #1
	adds r5, r2, r1
	cmp r5, #0
	beq _0809D6CA
	ldrb r0, [r4]
	strb r0, [r5, #0x1c]
	ldrb r0, [r4, #1]
	strb r0, [r5, #0x1d]
	ldrb r0, [r4, #2]
	strb r0, [r5, #0x1e]
	ldrb r0, [r4, #3]
	strb r0, [r5, #0x1f]
	ldrb r1, [r4, #4]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	ldrb r0, [r4, #5]
	adds r3, #1
	adds r1, r2, r3
	strb r0, [r1]
	ldrh r0, [r4, #6]
	strh r0, [r5, #0x22]
	ldrh r0, [r4, #8]
	strh r0, [r5, #0x24]
	ldrh r0, [r4, #0xa]
	strh r0, [r5, #0x26]
	movs r3, #0
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r7, r2, r0
	ldr r1, _0809D6E8 @ =0x00000F58
	adds r2, r6, r1
_0809D694:
	adds r0, r7, r3
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, #1
	cmp r3, #0xb
	ble _0809D694
	adds r2, r5, #0
	adds r2, #0x34
	adds r1, r4, #0
	adds r1, #0x18
	movs r3, #2
_0809D6AC:
	ldrb r0, [r1]
	strb r0, [r2]
	ldrb r0, [r1, #1]
	strb r0, [r2, #1]
	ldrb r0, [r1, #2]
	strb r0, [r2, #2]
	ldrb r0, [r1, #3]
	strb r0, [r2, #3]
	adds r2, #4
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bge _0809D6AC
_0809D6C6:
	mov r2, ip
	strb r2, [r5, #0x17]
_0809D6CA:
	mov r3, sb
	ldr r0, [r3]
	cmp r0, #0
	beq _0809D6EC
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809D6EC
	movs r0, #1
	b _0809D6EE
	.align 2, 0
_0809D6E0: .4byte 0x00000F4C
_0809D6E4: .4byte 0x03002C68
_0809D6E8: .4byte 0x00000F58
_0809D6EC:
	movs r0, #0
_0809D6EE:
	cmp r0, #0
	beq _0809D71A
	bl FUN_081df8d4
	adds r0, r6, #0
	bl FUN_0809d230
	bl FUN_08049fa8
	movs r0, #0
	bl FUN_0822b644
	movs r0, #1
	bl FUN_0822b644
	movs r0, #2
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	b _0809D74E
_0809D71A:
	movs r0, #3
	bl FUN_081df95c
	adds r0, r6, #0
	bl FUN_0809d230
	movs r0, #0
	bl FUN_0822b644
	movs r0, #1
	bl FUN_0822b644
	movs r0, #2
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	ldr r1, _0809D76C @ =0x00000F88
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0809D74E
	movs r1, #0
	bl Script_ExecById
_0809D74E:
	movs r3, #1
	mov r1, r8
	movs r2, #0x23
_0809D754:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0809D754
_0809D762:
	adds r0, r6, #0
	bl KillEntity
	b _0809D792
	.align 2, 0
_0809D76C: .4byte 0x00000F88
_0809D770:
	ldr r2, _0809D7A0 @ =0x00000E28
	adds r4, r6, r2
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _0809D792
	adds r0, r6, #0
	bl FUN_0809cea8
	adds r0, r6, #0
	bl FUN_0809d00c
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080b9fc4
_0809D792:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809D7A0: .4byte 0x00000E28

	thumb_func_start FUN_0809d7a4
FUN_0809d7a4: @ 0x0809D7A4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0809D7D4 @ =0x00000E58
	adds r0, r4, r1
	bl FUN_080b9adc
	cmp r0, #0
	beq _0809D7CE
	ldr r0, _0809D7D8 @ =0x00000111
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_0809d300
	adds r0, r4, #0
	bl FUN_0809d00c
	ldr r1, _0809D7DC @ =FUN_0809d3d0
	adds r0, r4, #0
	bl FUN_0809ce90
_0809D7CE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D7D4: .4byte 0x00000E58
_0809D7D8: .4byte 0x00000111
_0809D7DC: .4byte FUN_0809d3d0

	thumb_func_start Entity1B24_Update
Entity1B24_Update: @ 0x0809D7E0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _0809D812
	bl FUN_08049fa8
	movs r3, #1
	adds r1, r4, #0
	adds r1, #0xb0
	movs r2, #0x23
_0809D7F8:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0809D7F8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _0809D820
_0809D812:
	ldr r1, _0809D828 @ =0x00000F8C
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
_0809D820:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809D828: .4byte 0x00000F8C

	thumb_func_start Entity1B24_Destroy
Entity1B24_Destroy: @ 0x0809D82C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0xa8
	movs r5, #0x23
_0809D836:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809D836
	ldr r1, _0809D854 @ =0x00000E58
	adds r0, r6, r1
	bl FUN_080b9a0c
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809D854: .4byte 0x00000E58

	thumb_func_start FUN_0809d858
FUN_0809d858: @ 0x0809D858
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _0809D874 @ =0x03003ED0
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
_0809D874: .4byte 0x03003ED0

	thumb_func_start FUN_0809d878
FUN_0809d878: @ 0x0809D878
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _0809D918 @ =0x0000C091
	ldr r1, _0809D91C @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r6, #0x1c]
	movs r0, #6
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
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r2, #0
	movs r5, #1
_0809D8B6:
	ldr r1, _0809D920 @ =0x00000F71
	adds r0, r6, r1
	ldrb r0, [r0]
	asrs r0, r2
	ands r0, r5
	adds r4, r2, #1
	cmp r0, #0
	bne _0809D8EA
	adds r0, r2, #0
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r1, #2
	asrs r2, r2, #1
	adds r2, #4
	movs r0, #3
	bl FUN_0809d858
	movs r2, #1
	movs r1, #1
_0809D8E0:
	strh r2, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0809D8E0
_0809D8EA:
	adds r2, r4, #0
	cmp r2, #3
	ble _0809D8B6
	ldr r4, _0809D924 @ =0x000092B3
	ldr r0, _0809D928 @ =0x08251D6C
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x20]
	ldr r1, _0809D92C @ =0x03004250
	ldr r2, _0809D930 @ =0x04000018
	bl CpuSet
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809D918: .4byte 0x0000C091
_0809D91C: .4byte 0x0000CD91
_0809D920: .4byte 0x00000F71
_0809D924: .4byte 0x000092B3
_0809D928: .4byte 0x08251D6C
_0809D92C: .4byte 0x03004250
_0809D930: .4byte 0x04000018

	thumb_func_start FUN_0809d934
FUN_0809d934: @ 0x0809D934
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	mov r8, r0
	ldr r5, _0809DA1C @ =0x0000CB05
	ldr r1, _0809DA20 @ =0x0000B343
	adds r0, r5, #0
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _0809D954
	b _0809DD12
_0809D954:
	mov r1, r8
	adds r1, #0x28
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	mov r4, r8
	adds r4, #0x28
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _0809DA24 @ =0x00005D04
	adds r0, r5, #0
	bl GetFile
	adds r2, r0, #0
	str r4, [sp, #0x24]
	cmp r2, #0
	bne _0809D982
	b _0809DD12
_0809D982:
	mov r1, r8
	adds r1, #0x48
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	mov r4, r8
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _0809DA28 @ =0x0000DCC1
	adds r0, r5, #0
	bl GetFile
	adds r2, r0, #0
	str r4, [sp, #0x28]
	cmp r2, #0
	bne _0809D9B0
	b _0809DD12
_0809D9B0:
	mov r1, r8
	adds r1, #0x68
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r4, r6}
	stm r1!, {r4, r6}
	mov r4, r8
	adds r4, #0x68
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _0809DA2C @ =0x0000DE23
	adds r0, r5, #0
	bl GetFile
	adds r2, r0, #0
	str r4, [sp, #0x1c]
	cmp r2, #0
	bne _0809D9DE
	b _0809DD12
_0809D9DE:
	adds r4, #0x20
	adds r1, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	movs r6, #0
	str r4, [sp, #0x20]
	add r0, sp, #0x10
	mov sl, r0
	mov r5, r8
	adds r5, #0xa8
	mov sb, r6
_0809DA04:
	mov r1, r8
	ldr r0, [r1, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809DA5A
	cmp r6, #0
	bne _0809DA30
	movs r4, #0x3c
	movs r7, #0x30
	b _0809DA34
	.align 2, 0
_0809DA1C: .4byte 0x0000CB05
_0809DA20: .4byte 0x0000B343
_0809DA24: .4byte 0x00005D04
_0809DA28: .4byte 0x0000DCC1
_0809DA2C: .4byte 0x0000DE23
_0809DA30:
	movs r4, #0
	movs r7, #0x31
_0809DA34:
	add r0, sp, #0x10
	adds r1, r6, #0
	bl FUN_0809d240
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	mov r3, sb
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r4, sl
	str r4, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x28]
	adds r3, r7, #0
	bl FUN_0822f3fc
	b _0809DAB2
_0809DA5A:
	adds r0, r6, #0
	bl GetWeaponID
	adds r4, r0, #0
	movs r7, #0x30
	cmp r4, #0
	bne _0809DA6A
	movs r7, #0x31
_0809DA6A:
	add r0, sp, #0x10
	adds r1, r6, #0
	bl FUN_0809d240
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	mov r0, sb
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r1, sl
	str r1, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x28]
	adds r3, r7, #0
	bl FUN_0822f3fc
	adds r0, r6, #0
	bl FUN_0809cf98
	cmp r0, #0
	beq _0809DAA8
	adds r0, r5, #0
	ldr r1, _0809DAA4 @ =0x000002DF
	bl FUN_080b95bc
	b _0809DAB2
	.align 2, 0
_0809DAA4: .4byte 0x000002DF
_0809DAA8:
	adds r0, r5, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
_0809DAB2:
	adds r5, #0x60
	adds r6, #1
	cmp r6, #0xf
	ble _0809DA04
	add r5, sp, #0x10
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_0809d240
	movs r0, #0xd5
	lsls r0, r0, #3
	add r0, r8
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	movs r6, #0x3c
	str r6, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x28]
	movs r2, #0
	movs r3, #0x31
	bl FUN_0822f3fc
	movs r0, #0xf9
	lsls r0, r0, #3
	add r0, r8
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x24]
	movs r2, #0x40
	movs r3, #0x31
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	movs r5, #0xed
	lsls r5, r5, #3
	add r5, r8
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	movs r2, #0x39
	movs r3, #0x30
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r0, _0809DC58 @ =0x00000828
	add r0, r8
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x24]
	movs r2, #0x41
	movs r3, #0x31
	bl FUN_0822f3fc
	movs r6, #0
	add r4, sp, #0x10
	mov sl, r4
_0809DB4A:
	adds r1, r6, #0
	movs r5, #1
	ands r1, r5
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, #0x20
	mov r1, sl
	strh r0, [r1]
	asrs r0, r6, #1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r1, #2]
	movs r3, #0
	strh r3, [r1, #4]
	ldr r0, _0809DC5C @ =0x00000F71
	add r0, r8
	ldrb r0, [r0]
	asrs r0, r6
	ands r0, r5
	movs r4, #0x31
	str r4, [sp, #0x18]
	cmp r0, #0
	beq _0809DB7E
	movs r5, #0x30
	str r5, [sp, #0x18]
_0809DB7E:
	movs r7, #0
	lsls r1, r6, #1
	adds r0, r6, #1
	mov sb, r0
	add r5, sp, #0x10
	adds r0, #0x15
	adds r4, r1, r0
_0809DB8C:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #5
	adds r0, #0xa8
	add r0, r8
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r3, #0x3c
	str r3, [sp, #8]
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x24]
	movs r2, #0
	ldr r3, [sp, #0x18]
	bl FUN_0822f3fc
	ldrh r0, [r5]
	adds r0, #8
	strh r0, [r5]
	adds r4, #1
	adds r7, #1
	cmp r7, #2
	ble _0809DB8C
	mov r6, sb
	cmp r6, #3
	ble _0809DB4A
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	adds r5, r0, #0
	movs r0, #0x80
	strh r0, [r5, #2]
	movs r0, #0xe1
	lsls r0, r0, #3
	add r0, r8
	str r4, [sp]
	str r4, [sp, #4]
	movs r6, #0x3c
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x28]
	movs r2, #0xcf
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	ldr r0, _0809DC60 @ =0x00000D68
	add r0, r8
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x24]
	movs r2, #0x93
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	ldr r0, _0809DC64 @ =0x00000DC8
	add r0, r8
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0x15
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r0, #0xf7
	lsls r0, r0, #4
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0809DC40
	movs r0, #0xdd
	lsls r0, r0, #4
	add r0, r8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_0809DC40:
	mov r4, r8
	ldr r0, [r4, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #1
	beq _0809DC68
	cmp r0, #1
	ble _0809DC80
	cmp r0, #2
	beq _0809DC74
	b _0809DC80
	.align 2, 0
_0809DC58: .4byte 0x00000828
_0809DC5C: .4byte 0x00000F71
_0809DC60: .4byte 0x00000D68
_0809DC64: .4byte 0x00000DC8
_0809DC68:
	ldr r2, _0809DC70 @ =0x0000016B
	movs r4, #0x26
	b _0809DC84
	.align 2, 0
_0809DC70: .4byte 0x0000016B
_0809DC74:
	ldr r2, _0809DC7C @ =0x000002F9
	movs r4, #0x27
	b _0809DC84
	.align 2, 0
_0809DC7C: .4byte 0x000002F9
_0809DC80:
	movs r2, #4
	movs r4, #0x1d
_0809DC84:
	ldr r0, _0809DC9C @ =0x03002C68
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	beq _0809DCA0
	adds r0, r1, #0
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809DCA0
	movs r0, #1
	b _0809DCA2
	.align 2, 0
_0809DC9C: .4byte 0x03002C68
_0809DCA0:
	movs r0, #0
_0809DCA2:
	cmp r0, #0
	beq _0809DCC0
	ldr r0, [r3]
	cmp r0, #0
	bne _0809DCB2
	movs r0, #1
	rsbs r0, r0, #0
	b _0809DCB6
_0809DCB2:
	movs r5, #0x18
	ldrsh r0, [r0, r5]
_0809DCB6:
	adds r4, r0, #0
	adds r4, #0x22
	cmp r0, #0
	bge _0809DCC0
	movs r4, #0x22
_0809DCC0:
	movs r3, #0
	movs r1, #0x24
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x70
	strh r0, [r1, #2]
	ldr r0, _0809DD24 @ =0x00000888
	add r0, r8
	str r3, [sp]
	str r3, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r6, sp, #0x10
	str r6, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r3, #0x10
	bl FUN_0822f3fc
	ldr r0, _0809DD28 @ =0x000008C2
	add r0, r8
	strh r4, [r0]
	movs r3, #0x8d
	lsls r3, r3, #4
	add r3, r8
	ldr r2, _0809DD2C @ =0x03003584
	ldrh r1, [r0]
	lsls r1, r1, #5
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r3]
	ldr r0, _0809DD30 @ =0x00000E58
	add r0, r8
	bl FUN_080b99a0
	mov r0, r8
	bl FUN_0809d300
	mov r0, r8
	bl FUN_0809d00c
_0809DD12:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809DD24: .4byte 0x00000888
_0809DD28: .4byte 0x000008C2
_0809DD2C: .4byte 0x03003584
_0809DD30: .4byte 0x00000E58

	thumb_func_start FUN_0809dd34
FUN_0809dd34: @ 0x0809DD34
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0809DD64 @ =0x00000E28
	adds r5, r4, r0
	movs r0, #0x1e
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080b9ff8
	movs r0, #0xed
	lsls r0, r0, #3
	adds r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080b9fc4
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809DD64: .4byte 0x00000E28

	thumb_func_start FUN_0809dd68
FUN_0809dd68: @ 0x0809DD68
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x77
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809DD7C
	bl FUN_0823d340
	str r0, [r4, #0x24]
_0809DD7C:
	adds r0, r4, #0
	bl FUN_0809cea8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809dd88
FUN_0809dd88: @ 0x0809DD88
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _0809DDA8
	bl Script_GetValue
	ldr r2, _0809DDA4 @ =0x00000F84
	adds r1, r4, r2
	str r0, [r1]
	b _0809DDAE
	.align 2, 0
_0809DDA4: .4byte 0x00000F84
_0809DDA8:
	ldr r2, _0809DDC8 @ =0x00000F84
	adds r0, r4, r2
	str r1, [r0]
_0809DDAE:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _0809DDD0
	bl Script_GetValue
	ldr r2, _0809DDCC @ =0x00000F88
	adds r1, r4, r2
	str r0, [r1]
	b _0809DDD6
	.align 2, 0
_0809DDC8: .4byte 0x00000F84
_0809DDCC: .4byte 0x00000F88
_0809DDD0:
	ldr r2, _0809DDDC @ =0x00000F88
	adds r0, r4, r2
	str r1, [r0]
_0809DDD6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809DDDC: .4byte 0x00000F88

	thumb_func_start FUN_0809dde0
FUN_0809dde0: @ 0x0809DDE0
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809DDFC
	ldr r0, _0809DDF8 @ =0x00000F71
	adds r1, r2, r0
	movs r0, #0xf
	strb r0, [r1]
	b _0809DE46
	.align 2, 0
_0809DDF8: .4byte 0x00000F71
_0809DDFC:
	ldr r0, _0809DE1C @ =0x00000F71
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
	movs r5, #0
	ldr r0, _0809DE1C @ =0x00000F71
	adds r4, r2, r0
_0809DE0A:
	adds r0, r5, #0
	bl GetWeaponKind
	cmp r0, #0
	bne _0809DE20
	ldrb r0, [r4]
	movs r1, #1
	b _0809DE3C
	.align 2, 0
_0809DE1C: .4byte 0x00000F71
_0809DE20:
	cmp r0, #1
	bne _0809DE2A
	ldrb r0, [r4]
	movs r1, #2
	b _0809DE3C
_0809DE2A:
	cmp r0, #2
	bne _0809DE34
	ldrb r0, [r4]
	movs r1, #4
	b _0809DE3C
_0809DE34:
	cmp r0, #4
	bne _0809DE40
	ldrb r0, [r4]
	movs r1, #8
_0809DE3C:
	orrs r0, r1
	strb r0, [r4]
_0809DE40:
	adds r5, #1
	cmp r5, #0xf
	ble _0809DE0A
_0809DE46:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start Entity1B24_Init
Entity1B24_Init: @ 0x0809DE4C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _0809DE70 @ =0x03002C68
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r0, r2
	cmp r0, #0
	bne _0809DE62
	movs r1, #0
_0809DE62:
	str r1, [r4, #0x18]
	cmp r1, #0
	bne _0809DE74
	movs r0, #1
	rsbs r0, r0, #0
	b _0809DF16
	.align 2, 0
_0809DE70: .4byte 0x03002C68
_0809DE74:
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809DEAC
	movs r3, #0xf7
	lsls r3, r3, #4
	adds r1, r4, r3
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0809DEA4 @ =0x08DA9E68
	ldr r5, _0809DEA8 @ =0x00000F4C
	adds r0, r4, r5
	movs r2, #0x87
	lsls r2, r2, #4
	adds r1, r1, r2
	ldm r1!, {r2, r3, r5}
	stm r0!, {r2, r3, r5}
	ldm r1!, {r2, r3, r5}
	stm r0!, {r2, r3, r5}
	ldm r1!, {r2, r3, r5}
	stm r0!, {r2, r3, r5}
	b _0809DEC8
	.align 2, 0
_0809DEA4: .4byte 0x08DA9E68
_0809DEA8: .4byte 0x00000F4C
_0809DEAC:
	ldrb r0, [r1, #0x17]
	movs r3, #0xf7
	lsls r3, r3, #4
	adds r1, r4, r3
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _0809DEC8
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r5, _0809DF20 @ =0x00000F4C
	adds r1, r4, r5
	bl FUN_08242b14
_0809DEC8:
	ldr r0, [r4, #0x18]
	adds r0, #0x41
	ldrb r0, [r0]
	movs r2, #0xf8
	lsls r2, r2, #4
	adds r1, r4, r2
	add r3, sp, #8
	add r2, sp, #0xc
	str r2, [sp]
	add r2, sp, #4
	bl FUN_081dfa20
	adds r0, r4, #0
	bl FUN_0809dde0
	adds r0, r4, #0
	bl FUN_0809d878
	adds r0, r4, #0
	bl FUN_0809d934
	adds r0, r4, #0
	bl FUN_0809dd34
	adds r0, r4, #0
	bl FUN_0809dd68
	adds r0, r4, #0
	bl FUN_0809dd88
	ldr r3, _0809DF24 @ =0x00000F74
	adds r1, r4, r3
	movs r0, #0x1e
	str r0, [r1]
	ldr r1, _0809DF28 @ =FUN_0809d3d0
	adds r0, r4, #0
	bl FUN_0809ce90
	movs r0, #0
_0809DF16:
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809DF20: .4byte 0x00000F4C
_0809DF24: .4byte 0x00000F74
_0809DF28: .4byte FUN_0809d3d0

	thumb_func_start Entity1B24_Create
Entity1B24_Create: @ 0x0809DF2C
	push {r4, lr}
	movs r1, #0xf9
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809DF64
	ldr r1, _0809DF5C @ =Entity1B24_Update
	ldr r2, _0809DF60 @ =Entity1B24_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity1B24_Init
	cmp r0, #0
	bge _0809DF64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809DF66
	.align 2, 0
_0809DF5C: .4byte Entity1B24_Update
_0809DF60: .4byte Entity1B24_Destroy
_0809DF64:
	adds r0, r4, #0
_0809DF66:
	pop {r4}
	pop {r1}
	bx r1
