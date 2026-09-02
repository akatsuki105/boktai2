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

	thumb_func_start FUN_0809d7e0
FUN_0809d7e0: @ 0x0809D7E0
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

	thumb_func_start FUN_0809d82c
FUN_0809d82c: @ 0x0809D82C
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
	bl prepare_08231510
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
	bl prepare_08231510
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
	bl prepare_08231510
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

	thumb_func_start FUN_0809de4c
FUN_0809de4c: @ 0x0809DE4C
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

	thumb_func_start FUN_0809df2c
FUN_0809df2c: @ 0x0809DF2C
	push {r4, lr}
	movs r1, #0xf9
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809DF64
	ldr r1, _0809DF5C @ =FUN_0809d7e0
	ldr r2, _0809DF60 @ =FUN_0809d82c
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0809de4c
	cmp r0, #0
	bge _0809DF64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809DF66
	.align 2, 0
_0809DF5C: .4byte FUN_0809d7e0
_0809DF60: .4byte FUN_0809d82c
_0809DF64:
	adds r0, r4, #0
_0809DF66:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809df6c
FUN_0809df6c: @ 0x0809DF6C
	ldr r1, _0809DF74 @ =0x03000140
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0809DF74: .4byte 0x03000140

	thumb_func_start FUN_0809df78
FUN_0809df78: @ 0x0809DF78
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _0809DF88 @ =0x03000140
	ldr r5, [r0]
	cmp r5, #0
	bne _0809DF90
	b _0809DFE4
	.align 2, 0
_0809DF88: .4byte 0x03000140
_0809DF8C:
	movs r0, #1
	b _0809DFE6
_0809DF90:
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r4, r0
	bge _0809DFE4
	adds r7, r0, #0
_0809DF9E:
	movs r0, #0xa8
	muls r0, r4, r0
	adds r1, r5, r0
	adds r0, r1, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809DFDE
	movs r0, #0
	ldrsh r3, [r6, r0]
	adds r0, r1, #0
	adds r0, #0xcc
	ldrh r0, [r0]
	cmp r3, r0
	blt _0809DFDE
	movs r0, #4
	ldrsh r2, [r6, r0]
	adds r0, r1, #0
	adds r0, #0xce
	ldrh r0, [r0]
	cmp r2, r0
	blt _0809DFDE
	adds r0, r1, #0
	adds r0, #0xd0
	ldrh r0, [r0]
	cmp r3, r0
	bgt _0809DFDE
	adds r0, r1, #0
	adds r0, #0xd2
	ldrh r0, [r0]
	cmp r2, r0
	ble _0809DF8C
_0809DFDE:
	adds r4, #1
	cmp r4, r7
	blt _0809DF9E
_0809DFE4:
	movs r0, #0
_0809DFE6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809dfec
FUN_0809dfec: @ 0x0809DFEC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0809E004 @ =0x03000140
	ldr r1, [r0]
	cmp r1, #0
	beq _0809E02C
	adds r3, r1, #0
	adds r3, #0x26
	ldrb r0, [r3]
	cmp r0, #0
	bne _0809E00C
	b _0809E02C
	.align 2, 0
_0809E004: .4byte 0x03000140
_0809E008:
	movs r0, #1
	b _0809E02E
_0809E00C:
	movs r2, #0
	ldrb r0, [r3]
	cmp r2, r0
	bge _0809E02C
	adds r3, r0, #0
	adds r1, #0xc6
_0809E018:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809E024
	ldrh r0, [r1, #4]
	cmp r0, r4
	beq _0809E008
_0809E024:
	adds r1, #0xa8
	adds r2, #1
	cmp r2, r3
	blt _0809E018
_0809E02C:
	movs r0, #0
_0809E02E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809e034
FUN_0809e034: @ 0x0809E034
	push {lr}
	ldr r1, _0809E054 @ =0x030046A0
	ldr r1, [r1]
	ldr r2, _0809E058 @ =0x00000942
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r0, r1, r0
	movs r1, #0xa
	bl Div
	cmp r0, #0
	bgt _0809E050
	movs r0, #1
_0809E050:
	pop {r1}
	bx r1
	.align 2, 0
_0809E054: .4byte 0x030046A0
_0809E058: .4byte 0x00000942

	thumb_func_start FUN_0809e05c
FUN_0809e05c: @ 0x0809E05C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _0809E06C @ =0x03000140
	ldr r5, [r0]
	cmp r5, #0
	bne _0809E074
	b _0809E0C8
	.align 2, 0
_0809E06C: .4byte 0x03000140
_0809E070:
	adds r0, r4, #0
	b _0809E0CC
_0809E074:
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r4, r0
	bge _0809E0C8
	adds r7, r0, #0
_0809E082:
	movs r0, #0xa8
	muls r0, r4, r0
	adds r1, r5, r0
	adds r0, r1, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809E0C2
	movs r0, #0
	ldrsh r3, [r6, r0]
	adds r0, r1, #0
	adds r0, #0xcc
	ldrh r0, [r0]
	cmp r3, r0
	blt _0809E0C2
	movs r0, #4
	ldrsh r2, [r6, r0]
	adds r0, r1, #0
	adds r0, #0xce
	ldrh r0, [r0]
	cmp r2, r0
	blt _0809E0C2
	adds r0, r1, #0
	adds r0, #0xd0
	ldrh r0, [r0]
	cmp r3, r0
	bgt _0809E0C2
	adds r0, r1, #0
	adds r0, #0xd2
	ldrh r0, [r0]
	cmp r2, r0
	ble _0809E070
_0809E0C2:
	adds r4, #1
	cmp r4, r7
	blt _0809E082
_0809E0C8:
	movs r0, #1
	rsbs r0, r0, #0
_0809E0CC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809e0d4
FUN_0809e0d4: @ 0x0809E0D4
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r0, _0809E0FC @ =0x030046A0
	ldr r2, [r0]
	ldr r1, _0809E100 @ =0x00000942
	adds r0, r2, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	beq _0809E124
	movs r1, #2
	ldr r5, _0809E104 @ =0x00000934
	adds r0, r2, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809E108
	movs r0, #1
	b _0809E10A
	.align 2, 0
_0809E0FC: .4byte 0x030046A0
_0809E100: .4byte 0x00000942
_0809E104: .4byte 0x00000934
_0809E108:
	movs r0, #0
_0809E10A:
	cmp r0, #0
	bne _0809E12C
	adds r0, r3, #0
	bl FUN_0809e05c
	cmp r0, #0
	bge _0809E12C
	ldr r0, _0809E128 @ =0x03000140
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809E12C
_0809E124:
	movs r0, #0
	b _0809E132
	.align 2, 0
_0809E128: .4byte 0x03000140
_0809E12C:
	adds r0, r4, #0
	bl FUN_0809e034
_0809E132:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809e138
FUN_0809e138: @ 0x0809E138
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _0809E160 @ =0x030046A0
	ldr r2, [r0]
	ldr r1, _0809E164 @ =0x00000942
	adds r0, r2, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	beq _0809E186
	movs r1, #2
	ldr r4, _0809E168 @ =0x00000934
	adds r0, r2, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809E16C
	movs r0, #1
	b _0809E16E
	.align 2, 0
_0809E160: .4byte 0x030046A0
_0809E164: .4byte 0x00000942
_0809E168: .4byte 0x00000934
_0809E16C:
	movs r0, #0
_0809E16E:
	cmp r0, #0
	bne _0809E190
	ldr r0, _0809E18C @ =0x03000140
	ldr r0, [r0]
	cmp r0, #0
	beq _0809E186
	adds r0, r3, #0
	adds r0, #0x2c
	bl FUN_0809e05c
	cmp r0, #0
	bge _0809E190
_0809E186:
	movs r0, #0
	b _0809E192
	.align 2, 0
_0809E18C: .4byte 0x03000140
_0809E190:
	movs r0, #1
_0809E192:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809e198
FUN_0809e198: @ 0x0809E198
	push {r4, r5, r6, lr}
	mov ip, r0
	adds r6, r2, #0
	cmp r3, #0
	beq _0809E1B8
	ldr r0, _0809E1B0 @ =0x085AD004
	lsls r1, r1, #1
	adds r0, r1, r0
	ldrh r5, [r0]
	ldr r0, _0809E1B4 @ =0x085AD00C
	b _0809E1C2
	.align 2, 0
_0809E1B0: .4byte 0x085AD004
_0809E1B4: .4byte 0x085AD00C
_0809E1B8:
	ldr r0, _0809E1F0 @ =0x085AD00C
	lsls r1, r1, #1
	adds r0, r1, r0
	ldrh r5, [r0]
	ldr r0, _0809E1F4 @ =0x085AD004
_0809E1C2:
	adds r1, r1, r0
	ldrh r4, [r1]
	ldrh r2, [r6]
	subs r1, r2, r5
	mov r0, ip
	adds r0, #0xa0
	strh r1, [r0]
	ldrh r1, [r6, #4]
	subs r0, r1, r4
	mov r3, ip
	adds r3, #0xa2
	strh r0, [r3]
	adds r2, r5, r2
	mov r0, ip
	adds r0, #0xa4
	strh r2, [r0]
	adds r1, r4, r1
	adds r0, #2
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809E1F0: .4byte 0x085AD00C
_0809E1F4: .4byte 0x085AD004

	thumb_func_start FUN_0809e1f8
FUN_0809e1f8: @ 0x0809E1F8
	push {r4, lr}
	ldr r0, _0809E21C @ =0x03000140
	ldr r4, [r0]
	cmp r4, #0
	beq _0809E226
	movs r0, #0x74
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0809E220
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0x27
	strb r0, [r1]
	b _0809E226
	.align 2, 0
_0809E21C: .4byte 0x03000140
_0809E220:
	adds r0, r4, #0
	adds r0, #0x27
	strb r1, [r0]
_0809E226:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e22c
FUN_0809e22c: @ 0x0809E22C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	mov sl, r1
	str r2, [sp]
	mov sb, r3
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7]
	str r1, [r7, #4]
	rsbs r4, r3, #0
	orrs r4, r3
	asrs r4, r4, #0x1f
	movs r0, #4
	ands r4, r0
	mov r1, sl
	lsls r0, r1, #2
	movs r2, #0x9c
	adds r2, r2, r7
	mov r8, r2
	strb r0, [r2]
	adds r5, r7, #0
	adds r5, #0x60
	movs r1, #0xd9
	lsls r1, r1, #6
	adds r0, r5, #0
	bl Video_GetActorSprite
	adds r6, r7, #0
	adds r6, #8
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0822a470
	mov r1, r8
	ldrb r0, [r1]
	strh r0, [r6, #0x10]
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	bl FUN_0822b20c
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r7, #0x24]
	str r1, [r7, #0x28]
	movs r0, #3
	strb r0, [r7, #0xf]
	adds r1, r7, #0
	adds r1, #0x9d
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	mov r1, sl
	ldr r2, [sp]
	mov r3, sb
	bl FUN_0809e198
	adds r0, r7, #0
	bl FUN_08241574
	adds r1, r7, #0
	adds r1, #0x9e
	strh r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e2c4
FUN_0809e2c4: @ 0x0809E2C4
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r0, _0809E2FC @ =0x03000140
	ldr r6, [r0]
	cmp r6, #0
	beq _0809E392
	adds r0, r6, #0
	adds r0, #0x26
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0xf
	bhi _0809E392
	movs r0, #0x6e
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _0809E300
	bl Script_GetValue
	ldrb r2, [r5]
	movs r1, #0xa8
	muls r1, r2, r1
	adds r1, r6, r1
	adds r1, #0xc4
	strh r0, [r1]
	b _0809E30C
	.align 2, 0
_0809E2FC: .4byte 0x03000140
_0809E300:
	ldrb r1, [r5]
	movs r0, #0xa8
	muls r0, r1, r0
	adds r0, r6, r0
	adds r0, #0xc4
	strh r2, [r0]
_0809E30C:
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _0809E392
	bl Script_GetValue
	ldrb r1, [r5]
	movs r4, #0xa8
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xcc
	strh r0, [r1]
	bl Script_GetValue
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xce
	strh r0, [r1]
	bl Script_GetValue
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xd0
	strh r0, [r1]
	bl Script_GetValue
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xd2
	strh r0, [r1]
	ldrb r0, [r5]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xcc
	ldr r2, _0809E39C @ =0xFFFF0000
	ldrh r0, [r0]
	str r0, [sp]
	ldrb r0, [r5]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xce
	ldrh r1, [r0]
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	bl FUN_08241574
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xca
	strh r0, [r1]
	ldrb r0, [r5]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xc6
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
_0809E392:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809E39C: .4byte 0xFFFF0000

	thumb_func_start FUN_0809e3a0
FUN_0809e3a0: @ 0x0809E3A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	ldr r0, _0809E3E0 @ =0x03000140
	ldr r6, [r0]
	cmp r6, #0
	bne _0809E3B2
	b _0809E53E
_0809E3B2:
	adds r0, r6, #0
	adds r0, #0x26
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0xf
	bls _0809E3C0
	b _0809E53E
_0809E3C0:
	movs r0, #0x6e
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _0809E3E4
	bl Script_GetValue
	mov r1, r8
	ldrb r2, [r1]
	movs r1, #0xa8
	muls r1, r2, r1
	adds r1, r6, r1
	adds r1, #0xc4
	strh r0, [r1]
	b _0809E3F2
	.align 2, 0
_0809E3E0: .4byte 0x03000140
_0809E3E4:
	mov r0, r8
	ldrb r1, [r0]
	movs r0, #0xa8
	muls r0, r1, r0
	adds r0, r6, r0
	adds r0, #0xc4
	strh r2, [r0]
_0809E3F2:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0809E438
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0809E430 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0809E434 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _0809E442
	.align 2, 0
_0809E430: .4byte 0xFFFF0000
_0809E434: .4byte 0x0000FFFF
_0809E438:
	ldr r1, _0809E470 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0809E442:
	add r5, sp, #4
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0809E46A
	cmp r1, #0
	blt _0809E46A
	ldr r0, _0809E474 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0809E46A
	ldr r0, _0809E478 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0809E47C
_0809E46A:
	movs r4, #0
	b _0809E48A
	.align 2, 0
_0809E470: .4byte 0xFFFF0000
_0809E474: .4byte 0x030046A8
_0809E478: .4byte 0x030046AC
_0809E47C:
	ldr r0, _0809E49C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0809E48A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0809E4A0
	adds r0, #4
	b _0809E4AC
	.align 2, 0
_0809E49C: .4byte 0x030046A4
_0809E4A0:
	ldr r0, _0809E4C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0809E4AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0809E4C4
	cmp r2, #2
	beq _0809E4C8
	b _0809E4CC
	.align 2, 0
_0809E4C0: .4byte 0x030046A4
_0809E4C4:
	ldrb r0, [r5, #4]
	b _0809E4CA
_0809E4C8:
	ldrb r0, [r5]
_0809E4CA:
	subs r1, r1, r0
_0809E4CC:
	add r0, sp, #4
	strh r1, [r0, #2]
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0809E4E2
	bl Script_GetValue
	adds r7, r0, #0
	b _0809E4E4
_0809E4E2:
	movs r7, #0
_0809E4E4:
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _0809E4F6
	bl Script_GetValue
	adds r3, r0, #0
	b _0809E4F8
_0809E4F6:
	movs r3, #0
_0809E4F8:
	mov r4, r8
	ldrb r0, [r4]
	movs r5, #0xa8
	muls r0, r5, r0
	adds r0, #0x2c
	adds r0, r6, r0
	ldrh r1, [r6, #0x24]
	str r1, [sp]
	adds r1, r7, #0
	add r2, sp, #4
	bl FUN_0809e22c
	ldrb r0, [r4]
	muls r0, r5, r0
	adds r0, r6, r0
	adds r0, #0xc6
	movs r2, #1
	strb r2, [r0]
	adds r0, r6, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809E536
	ldrb r0, [r4]
	muls r0, r5, r0
	adds r1, r6, #0
	adds r1, #0x34
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0809E536:
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0809E53E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809e54c
FUN_0809e54c: @ 0x0809E54C
	push {r4, r5, r6, r7, lr}
	ldr r0, _0809E570 @ =0x03000140
	ldr r4, [r0]
	cmp r4, #0
	beq _0809E5BE
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _0809E5BE
	bl Script_GetValue
	adds r7, r0, #0
	movs r3, #0
	adds r0, r4, #0
	adds r0, #0x26
	adds r6, r0, #0
	b _0809E5B8
	.align 2, 0
_0809E570: .4byte 0x03000140
_0809E574:
	movs r0, #0xa8
	adds r5, r3, #0
	muls r5, r0, r5
	adds r2, r4, r5
	adds r1, r2, #0
	adds r1, #0xc4
	ldrh r0, [r1]
	cmp r0, #0
	beq _0809E5B6
	cmp r0, r7
	bne _0809E5B6
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809E5BE
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809E5BE
	adds r0, r4, #0
	adds r0, #0x34
	adds r0, r0, r5
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	b _0809E5BE
_0809E5B6:
	adds r3, #1
_0809E5B8:
	ldrb r0, [r6]
	cmp r3, r0
	blt _0809E574
_0809E5BE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e5c4
FUN_0809e5c4: @ 0x0809E5C4
	push {r4, r5, r6, r7, lr}
	ldr r0, _0809E5E8 @ =0x03000140
	ldr r6, [r0]
	cmp r6, #0
	beq _0809E62A
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _0809E62A
	bl Script_GetValue
	adds r7, r0, #0
	movs r3, #0
	adds r0, r6, #0
	adds r0, #0x26
	adds r5, r0, #0
	b _0809E624
	.align 2, 0
_0809E5E8: .4byte 0x03000140
_0809E5EC:
	movs r0, #0xa8
	adds r4, r3, #0
	muls r4, r0, r4
	adds r2, r6, r4
	adds r1, r2, #0
	adds r1, #0xc4
	ldrh r0, [r1]
	cmp r0, #0
	beq _0809E622
	cmp r0, r7
	bne _0809E622
	adds r1, #2
	movs r0, #0
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809E62A
	adds r0, r6, #0
	adds r0, #0x34
	adds r0, r0, r4
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0809E62A
_0809E622:
	adds r3, #1
_0809E624:
	ldrb r0, [r5]
	cmp r3, r0
	blt _0809E5EC
_0809E62A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e630
FUN_0809e630: @ 0x0809E630
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r1, _0809E648 @ =0x030047A4
	ldr r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0809E64C
	movs r0, #0
	b _0809E666
	.align 2, 0
_0809E648: .4byte 0x030047A4
_0809E64C:
	ldr r0, _0809E658 @ =0x030044E0
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809E65C
	strh r2, [r4, #0x20]
	b _0809E668
	.align 2, 0
_0809E658: .4byte 0x030044E0
_0809E65C:
	ldrh r2, [r4, #0x20]
	ldr r0, _0809E6A0 @ =0x00000383
	cmp r2, r0
	bhi _0809E668
	adds r0, r2, #1
_0809E666:
	strh r0, [r4, #0x20]
_0809E668:
	ldr r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	beq _0809E722
	movs r1, #4
	ldr r0, _0809E6A4 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0809E722
	ldr r0, [r4, #0x18]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r5, r0, #0
	cmp r1, #5
	bne _0809E6C0
	cmp r3, #2
	bne _0809E6A8
	ldrh r0, [r4, #0x1e]
	adds r0, #0x28
	b _0809E6FC
	.align 2, 0
_0809E6A0: .4byte 0x00000383
_0809E6A4: .4byte 0x03002BC0
_0809E6A8:
	cmp r3, #0
	bne _0809E6FE
	ldrh r1, [r4, #0x20]
	ldr r0, _0809E6BC @ =0x00000383
	cmp r1, r0
	bhi _0809E6FE
	ldrh r0, [r4, #0x1e]
	adds r0, #5
	b _0809E6FC
	.align 2, 0
_0809E6BC: .4byte 0x00000383
_0809E6C0:
	cmp r3, #2
	bne _0809E6E0
	ldr r0, _0809E6D8 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809E6DC @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #3
	ldrh r1, [r4, #0x1e]
	adds r0, r0, r1
	b _0809E6FC
	.align 2, 0
_0809E6D8: .4byte 0x030046A0
_0809E6DC: .4byte 0x00000942
_0809E6E0:
	cmp r3, #1
	bne _0809E6FE
	ldrh r1, [r4, #0x20]
	ldr r0, _0809E728 @ =0x00000383
	cmp r1, r0
	bhi _0809E6FE
	ldr r0, _0809E72C @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0809E730 @ =0x00000942
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r2, [r4, #0x1e]
	adds r0, r0, r2
_0809E6FC:
	strh r0, [r4, #0x1e]
_0809E6FE:
	movs r1, #0
	ldrh r3, [r4, #0x1e]
	cmp r3, #0x77
	bls _0809E718
_0809E706:
	adds r2, r3, #0
	subs r2, #0x78
	adds r1, #1
	adds r3, r2, #0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bhi _0809E706
	strh r2, [r4, #0x1e]
_0809E718:
	cmp r1, #0
	ble _0809E722
	adds r0, r5, #0
	bl FUN_0807aa30
_0809E722:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809E728: .4byte 0x00000383
_0809E72C: .4byte 0x030046A0
_0809E730: .4byte 0x00000942

	thumb_func_start FUN_0809e734
FUN_0809e734: @ 0x0809E734
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x18]
	movs r0, #0x20
	ldr r1, [r1, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809E748
	movs r1, #2
	b _0809E750
_0809E748:
	movs r0, #0x10
	ands r1, r0
	rsbs r0, r1, #0
	lsrs r1, r0, #0x1f
_0809E750:
	adds r0, r2, #0
	bl FUN_0809e630
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809e75c
FUN_0809e75c: @ 0x0809E75C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r1, #0xce
	lsls r1, r1, #1
	ldrh r0, [r6, #0x24]
	cmp r0, r1
	beq _0809E7B6
	strh r1, [r6, #0x24]
	movs r2, #0
	adds r0, r6, #0
	adds r0, #0x26
	mov r8, r0
	ldrb r0, [r0]
	cmp r2, r0
	bge _0809E7B6
	movs r1, #0xa8
	mov sb, r1
_0809E784:
	mov r1, sb
	muls r1, r2, r1
	adds r0, r6, r1
	adds r0, #0xc9
	ldrb r0, [r0]
	adds r7, r2, #1
	cmp r0, #0
	beq _0809E7AC
	adds r0, r1, #0
	adds r0, #0x8c
	adds r4, r6, r0
	movs r5, #1
_0809E79C:
	ldrh r1, [r6, #0x24]
	adds r0, r4, #0
	bl FUN_0822b20c
	adds r4, #0x1c
	subs r5, #1
	cmp r5, #0
	bge _0809E79C
_0809E7AC:
	adds r2, r7, #0
	mov r0, r8
	ldrb r0, [r0]
	cmp r2, r0
	blt _0809E784
_0809E7B6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809e7c4
FUN_0809e7c4: @ 0x0809E7C4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #0
	bne _0809E816
	movs r0, #1
	strb r0, [r1]
	movs r5, #0
	adds r0, r4, #0
	adds r0, #0x26
	adds r6, r0, #0
	ldrb r0, [r6]
	cmp r5, r0
	bge _0809E816
	adds r3, r4, #0
	adds r3, #0xc6
	movs r7, #0
	movs r1, #0x34
	adds r1, r1, r4
	mov ip, r1
_0809E7F0:
	ldrb r0, [r3, #3]
	cmp r0, #0
	beq _0809E80A
	ldrb r0, [r3]
	cmp r0, #0
	beq _0809E80A
	mov r1, ip
	adds r0, r1, r7
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0809E80A:
	adds r3, #0xa8
	adds r7, #0xa8
	adds r5, #1
	ldrb r0, [r6]
	cmp r5, r0
	blt _0809E7F0
_0809E816:
	adds r0, r4, #0
	bl FUN_0809e75c
	ldr r1, [r4, #0x18]
	movs r0, #0x20
	ldr r1, [r1, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809E82C
	movs r1, #2
	b _0809E834
_0809E82C:
	movs r0, #0x10
	ands r1, r0
	rsbs r0, r1, #0
	lsrs r1, r0, #0x1f
_0809E834:
	adds r0, r4, #0
	bl FUN_0809e630
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e840
FUN_0809e840: @ 0x0809E840
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #1
	bne _0809E880
	movs r0, #0
	strb r0, [r1]
	movs r3, #0
	adds r0, r4, #0
	adds r0, #0x26
	ldrb r1, [r0]
	cmp r3, r1
	bge _0809E880
	movs r6, #1
	adds r2, r4, #0
	adds r2, #0xc9
	adds r1, r4, #0
	adds r5, r0, #0
_0809E868:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0809E874
	ldr r0, [r1, #0x34]
	orrs r0, r6
	str r0, [r1, #0x34]
_0809E874:
	adds r2, #0xa8
	adds r1, #0xa8
	adds r3, #1
	ldrb r0, [r5]
	cmp r3, r0
	blt _0809E868
_0809E880:
	ldr r0, [r4, #0x18]
	movs r2, #0x20
	ldr r1, [r0, #0x20]
	ands r1, r2
	rsbs r1, r1, #0
	asrs r1, r1, #0x1f
	movs r0, #2
	ands r1, r0
	adds r0, r4, #0
	bl FUN_0809e630
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e89c
FUN_0809e89c: @ 0x0809E89C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x28
	ldrb r0, [r1]
	ldr r7, _0809E9A8 @ =0x030046A0
	cmp r0, #0
	bne _0809E8E2
	movs r0, #1
	strb r0, [r1]
	movs r3, #0
	adds r0, r5, #0
	adds r0, #0x26
	ldrb r1, [r0]
	cmp r3, r1
	bge _0809E8E2
	movs r6, #2
	rsbs r6, r6, #0
	adds r2, r5, #0
	adds r2, #0xc6
	adds r1, r5, #0
	adds r4, r0, #0
_0809E8CA:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0809E8D6
	ldr r0, [r1, #0x34]
	ands r0, r6
	str r0, [r1, #0x34]
_0809E8D6:
	adds r2, #0xa8
	adds r1, #0xa8
	adds r3, #1
	ldrb r0, [r4]
	cmp r3, r0
	blt _0809E8CA
_0809E8E2:
	movs r4, #0
	ldr r0, [r7]
	ldr r1, _0809E9AC @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0809E906
	ldr r0, [r5, #0x18]
	adds r0, #0x2c
	bl FUN_0809e05c
	cmp r0, #0
	blt _0809E902
	movs r4, #1
_0809E902:
	cmp r4, #0
	beq _0809E9BE
_0809E906:
	ldr r2, [r5, #0x18]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r1, [r0]
	cmp r1, #7
	bne _0809E9B8
	adds r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0809E9B8
	cmp r0, #3
	bne _0809E9C0
	ldrh r0, [r5, #0x22]
	cmp r0, #0x3e
	bhi _0809E9C0
	ands r1, r0
	cmp r1, #0
	bne _0809E99E
	ldr r0, [r2, #0x2c]
	ldr r1, [r2, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r0, sp, #0xc
	ldrh r0, [r0]
	subs r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _0809E9B0 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0xc]
	add r0, sp, #0xc
	ldrh r0, [r0, #4]
	subs r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x10]
	asrs r1, r2, #0x10
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r4, _0809E9B4 @ =0x0000FFFF
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x14]
	ands r0, r3
	movs r2, #0x80
	lsls r2, r2, #1
	orrs r0, r2
	ands r0, r4
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	str r1, [sp]
	movs r0, #0xb4
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #1
	movs r2, #0x19
	add r3, sp, #0xc
	bl FUN_0800a8e0
_0809E99E:
	ldrh r0, [r5, #0x22]
	adds r0, #1
	strh r0, [r5, #0x22]
	b _0809E9C0
	.align 2, 0
_0809E9A8: .4byte 0x030046A0
_0809E9AC: .4byte 0x00000934
_0809E9B0: .4byte 0xFFFF0000
_0809E9B4: .4byte 0x0000FFFF
_0809E9B8:
	movs r0, #0
	strh r0, [r5, #0x22]
	b _0809E9C0
_0809E9BE:
	strh r4, [r5, #0x22]
_0809E9C0:
	adds r0, r5, #0
	bl FUN_0809e75c
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809e9d0
FUN_0809e9d0: @ 0x0809E9D0
	push {lr}
	ldrh r0, [r0, #0x1c]
	cmp r0, #0
	beq _0809E9E6
	bl FUN_0823e1b0
	subs r0, #1
	cmp r0, #2
	bls _0809E9E6
	movs r0, #1
	b _0809E9E8
_0809E9E6:
	movs r0, #0
_0809E9E8:
	pop {r1}
	bx r1

	thumb_func_start FUN_0809e9ec
FUN_0809e9ec: @ 0x0809E9EC
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809E9FE
	movs r0, #0
	strb r0, [r1]
_0809E9FE:
	ldr r0, _0809EA2C @ =0x03002BE0
	ldr r0, [r0]
	str r0, [r4, #0x18]
	cmp r0, #0
	beq _0809EA7E
	ldr r0, _0809EA30 @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0x94
	lsls r2, r2, #4
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _0809EA3C
	adds r0, r4, #0
	bl FUN_0809e9d0
	cmp r0, #0
	beq _0809EA34
	adds r0, r4, #0
	bl FUN_0809e89c
	b _0809EA5E
	.align 2, 0
_0809EA2C: .4byte 0x03002BE0
_0809EA30: .4byte 0x030046A0
_0809EA34:
	adds r0, r4, #0
	bl FUN_0809e840
	b _0809EA5E
_0809EA3C:
	ldr r2, _0809EA54 @ =0x00000934
	adds r0, r1, r2
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809EA58
	adds r0, r4, #0
	bl FUN_0809e734
	b _0809EA5E
	.align 2, 0
_0809EA54: .4byte 0x00000934
_0809EA58:
	adds r0, r4, #0
	bl FUN_0809e7c4
_0809EA5E:
	ldr r0, _0809EA88 @ =0x03002B80
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #1
	bne _0809EA6A
	movs r1, #1
_0809EA6A:
	cmp r1, #0
	beq _0809EA7E
	ldr r0, _0809EA8C @ =0x03002BF0
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809EA7E
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
_0809EA7E:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809EA88: .4byte 0x03002B80
_0809EA8C: .4byte 0x03002BF0

	thumb_func_start FUN_0809ea90
FUN_0809ea90: @ 0x0809EA90
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	b _0809EAB4
_0809EA98:
	movs r0, #0xa8
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, r1
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809EAB0
	adds r0, r1, r4
	adds r0, #0x34
	bl FUN_0822a4e0
_0809EAB0:
	adds r5, #1
	adds r0, r4, #0
_0809EAB4:
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r5, r0
	blt _0809EA98
	ldr r1, _0809EAC8 @ =0x03000140
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809EAC8: .4byte 0x03000140

	thumb_func_start FUN_0809eacc
FUN_0809eacc: @ 0x0809EACC
	push {lr}
	ldr r0, _0809EAE8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0809EAE4
	bl FUN_0823e4d4
	cmp r0, #4
	beq _0809EAEC
_0809EAE4:
	movs r0, #0
	b _0809EAEE
	.align 2, 0
_0809EAE8: .4byte 0x030047A4
_0809EAEC:
	movs r0, #1
_0809EAEE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809eaf4
FUN_0809eaf4: @ 0x0809EAF4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0809eacc
	movs r1, #0
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x26
	strb r1, [r0]
	movs r0, #0xcd
	lsls r0, r0, #1
	strh r0, [r4, #0x24]
	adds r0, r4, #0
	adds r0, #0x28
	strb r1, [r0]
	ldr r0, _0809EB20 @ =0x03000140
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809EB20: .4byte 0x03000140

	thumb_func_start FUN_0809eb24
FUN_0809eb24: @ 0x0809EB24
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _0809EB58 @ =0x00000AB4
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809EB64
	ldr r1, _0809EB5C @ =FUN_0809e9ec
	ldr r2, _0809EB60 @ =FUN_0809ea90
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0809eaf4
	cmp r0, #0
	bge _0809EB64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809EB66
	.align 2, 0
_0809EB58: .4byte 0x00000AB4
_0809EB5C: .4byte FUN_0809e9ec
_0809EB60: .4byte FUN_0809ea90
_0809EB64:
	adds r0, r4, #0
_0809EB66:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809eb6c
FUN_0809eb6c: @ 0x0809EB6C
	push {lr}
	adds r1, r0, #0
	ldr r0, _0809EB7C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809EB80
	movs r0, #0
	b _0809EB84
	.align 2, 0
_0809EB7C: .4byte 0x03002C68
_0809EB80:
	adds r0, #0x66
	ldrh r0, [r0]
_0809EB84:
	adds r2, r0, #0
	muls r2, r1, r2
	adds r0, r2, #0
	movs r1, #0x8c
	bl Div
	pop {r1}
	bx r1

	thumb_func_start FUN_0809eb94
FUN_0809eb94: @ 0x0809EB94
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r0, _0809EBA8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809EBAC
	movs r0, #0
	b _0809EBB0
	.align 2, 0
_0809EBA8: .4byte 0x03002C68
_0809EBAC:
	adds r0, #0x66
	ldrh r0, [r0]
_0809EBB0:
	cmp r0, #0
	beq _0809EBE4
	movs r1, #2
	ldr r0, _0809EBCC @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _0809EBD0 @ =0x00000934
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809EBD4
	movs r0, #1
	b _0809EBD6
	.align 2, 0
_0809EBCC: .4byte 0x030046A0
_0809EBD0: .4byte 0x00000934
_0809EBD4:
	movs r0, #0
_0809EBD6:
	cmp r0, #0
	bne _0809EBE8
	adds r0, r2, #0
	bl FUN_0809e05c
	cmp r0, #0
	bge _0809EBE8
_0809EBE4:
	movs r0, #0
	b _0809EBEE
_0809EBE8:
	adds r0, r4, #0
	bl FUN_0809eb6c
_0809EBEE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809ebf4
FUN_0809ebf4: @ 0x0809EBF4
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x18]
	ldr r0, _0809EC08 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809EC0C
	movs r0, #0
	b _0809EC12
	.align 2, 0
_0809EC08: .4byte 0x03002C68
_0809EC0C:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_0809EC12:
	cmp r0, #0
	beq _0809EC4E
	movs r1, #2
	ldr r0, _0809EC2C @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _0809EC30 @ =0x00000934
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809EC34
	movs r0, #1
	b _0809EC36
	.align 2, 0
_0809EC2C: .4byte 0x030046A0
_0809EC30: .4byte 0x00000934
_0809EC34:
	movs r0, #0
_0809EC36:
	cmp r0, #0
	bne _0809EC58
	ldr r0, _0809EC54 @ =0x03000140
	ldr r0, [r0]
	cmp r0, #0
	beq _0809EC4E
	adds r0, r2, #0
	adds r0, #0x2c
	bl FUN_0809e05c
	cmp r0, #0
	bge _0809EC58
_0809EC4E:
	movs r0, #0
	b _0809EC5A
	.align 2, 0
_0809EC54: .4byte 0x03000140
_0809EC58:
	movs r0, #1
_0809EC5A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809ec60
FUN_0809ec60: @ 0x0809EC60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r3, #0
	ldr r7, _0809EC90 @ =0x00000AAC
	add r7, r8
_0809EC6E:
	ldr r1, _0809EC94 @ =0x03002BE0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r6, [r0]
	adds r5, r3, #1
	cmp r6, #0
	beq _0809ED3E
	ldr r0, [r6, #0x1c]
	cmp r0, #1
	bne _0809ED3E
	movs r0, #0x20
	ldr r1, [r6, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809EC98
	movs r1, #2
	b _0809ECA0
	.align 2, 0
_0809EC90: .4byte 0x00000AAC
_0809EC94: .4byte 0x03002BE0
_0809EC98:
	movs r0, #0x10
	ands r1, r0
	rsbs r0, r1, #0
	lsrs r1, r0, #0x1f
_0809ECA0:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _0809ECC8
	cmp r1, #2
	bne _0809ECBA
	lsls r2, r3, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #0x28
	b _0809ED0E
_0809ECBA:
	lsls r2, r3, #1
	cmp r1, #0
	bne _0809ED10
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #5
	b _0809ED0E
_0809ECC8:
	cmp r1, #2
	bne _0809ECEA
	ldr r0, _0809ECD8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809ECDC
	movs r0, #0
	b _0809ECE2
	.align 2, 0
_0809ECD8: .4byte 0x03002C68
_0809ECDC:
	adds r0, #0x60
	adds r0, r0, r3
	ldrb r0, [r0]
_0809ECE2:
	lsls r2, r3, #1
	adds r1, r7, r2
	lsls r0, r0, #3
	b _0809ED0A
_0809ECEA:
	lsls r2, r3, #1
	cmp r1, #1
	bne _0809ED10
	ldr r0, _0809ECFC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809ED00
	movs r0, #0
	b _0809ED06
	.align 2, 0
_0809ECFC: .4byte 0x03002C68
_0809ED00:
	adds r0, #0x60
	adds r0, r0, r3
	ldrb r0, [r0]
_0809ED06:
	lsls r2, r3, #1
	adds r1, r7, r2
_0809ED0A:
	ldrh r4, [r1]
	adds r0, r0, r4
_0809ED0E:
	strh r0, [r1]
_0809ED10:
	movs r4, #0
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r5, r3, #1
	cmp r0, #0x77
	bls _0809ED32
	ldr r3, _0809ED50 @ =0x00000AAC
	add r3, r8
_0809ED20:
	adds r1, r3, r2
	ldrh r0, [r1]
	subs r0, #0x78
	strh r0, [r1]
	adds r4, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bhi _0809ED20
_0809ED32:
	cmp r4, #0
	ble _0809ED3E
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0807aa30
_0809ED3E:
	adds r3, r5, #0
	cmp r3, #3
	ble _0809EC6E
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809ED50: .4byte 0x00000AAC

	thumb_func_start FUN_0809ed54
FUN_0809ed54: @ 0x0809ED54
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809ed58
FUN_0809ed58: @ 0x0809ED58
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r0, _0809ED6C @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	bne _0809ED70
	movs r1, #1
	rsbs r1, r1, #0
	b _0809ED74
	.align 2, 0
_0809ED6C: .4byte 0x03002C68
_0809ED70:
	movs r2, #0x18
	ldrsh r1, [r1, r2]
_0809ED74:
	ldr r0, [r0]
	cmp r0, #0
	bne _0809ED7E
	movs r0, #0
	b _0809ED84
_0809ED7E:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_0809ED84:
	adds r2, r0, #0
	cmp r2, #0
	beq _0809EDD6
	mov r1, ip
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #0
	bne _0809EE12
	movs r0, #1
	strb r0, [r1]
	movs r4, #0
	mov r0, ip
	adds r0, #0x26
	adds r5, r0, #0
	ldrb r0, [r5]
	cmp r4, r0
	bge _0809EE12
	mov r3, ip
	adds r3, #0xc6
	movs r6, #0
	mov r7, ip
	adds r7, #0x34
_0809EDB0:
	ldrb r0, [r3, #3]
	cmp r0, #0
	beq _0809EDC8
	ldrb r0, [r3]
	cmp r0, #0
	beq _0809EDC8
	adds r0, r7, r6
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0809EDC8:
	adds r3, #0xa8
	adds r6, #0xa8
	adds r4, #1
	ldrb r2, [r5]
	cmp r4, r2
	blt _0809EDB0
	b _0809EE12
_0809EDD6:
	mov r1, ip
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #1
	bne _0809EE12
	strb r2, [r1]
	movs r4, #0
	mov r0, ip
	adds r0, #0x26
	adds r5, r0, #0
	ldrb r0, [r5]
	cmp r4, r0
	bge _0809EE12
	movs r6, #1
	mov r2, ip
	adds r2, #0xc9
	mov r1, ip
	adds r3, r5, #0
_0809EDFA:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0809EE06
	ldr r0, [r1, #0x34]
	orrs r0, r6
	str r0, [r1, #0x34]
_0809EE06:
	adds r2, #0xa8
	adds r1, #0xa8
	adds r4, #1
	ldrb r0, [r3]
	cmp r4, r0
	blt _0809EDFA
_0809EE12:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809ee18
FUN_0809ee18: @ 0x0809EE18
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0809EE38 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809EE3C @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809EE40
	adds r0, r4, #0
	bl FUN_0809ed54
	b _0809EE46
	.align 2, 0
_0809EE38: .4byte 0x030046A0
_0809EE3C: .4byte 0x00000934
_0809EE40:
	adds r0, r4, #0
	bl FUN_0809ed58
_0809EE46:
	adds r0, r4, #0
	bl FUN_0809ec60
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809ee54
FUN_0809ee54: @ 0x0809EE54
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	b _0809EE78
_0809EE5C:
	movs r0, #0xa8
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, r1
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809EE74
	adds r0, r1, r4
	adds r0, #0x34
	bl FUN_0822a4e0
_0809EE74:
	adds r5, #1
	adds r0, r4, #0
_0809EE78:
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r5, r0
	blt _0809EE5C
	ldr r1, _0809EE8C @ =0x03000140
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809EE8C: .4byte 0x03000140

	thumb_func_start FUN_0809ee90
FUN_0809ee90: @ 0x0809EE90
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #0
	strb r1, [r2]
	movs r2, #0
	movs r1, #0xcd
	lsls r1, r1, #1
	strh r1, [r0, #0x24]
	adds r1, r0, #0
	adds r1, #0x28
	strb r2, [r1]
	ldr r1, _0809EEB0 @ =0x03000140
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_0809EEB0: .4byte 0x03000140

	thumb_func_start FUN_0809eeb4
FUN_0809eeb4: @ 0x0809EEB4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _0809EEE8 @ =0x00000AB4
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809EEF4
	ldr r1, _0809EEEC @ =FUN_0809ee18
	ldr r2, _0809EEF0 @ =FUN_0809ee54
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0809ee90
	cmp r0, #0
	bge _0809EEF4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809EEF6
	.align 2, 0
_0809EEE8: .4byte 0x00000AB4
_0809EEEC: .4byte FUN_0809ee18
_0809EEF0: .4byte FUN_0809ee54
_0809EEF4:
	adds r0, r4, #0
_0809EEF6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809eefc
FUN_0809eefc: @ 0x0809EEFC
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, _0809EF24 @ =0x03000140
	ldr r0, [r0]
	cmp r0, #0
	bne _0809EF34
	ldr r0, _0809EF28 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0809EF2C
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_0809eb24
	b _0809EF34
	.align 2, 0
_0809EF24: .4byte 0x03000140
_0809EF28: .4byte 0x030047A4
_0809EF2C:
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_0809eeb4
_0809EF34:
	pop {r1}
	bx r1

	thumb_func_start FUN_0809ef38
FUN_0809ef38: @ 0x0809EF38
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _0809EF98 @ =0x00000252
	adds r0, r4, r2
	movs r5, #0x2e
	ldrsh r1, [r3, r5]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bne _0809F024
	movs r5, #0x2c
	ldrsh r0, [r3, r5]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r2, r0, r1
	cmp r2, #0
	bge _0809EF6A
	rsbs r2, r2, #0
_0809EF6A:
	movs r1, #0x30
	ldrsh r0, [r3, r1]
	movs r5, #0x95
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	cmp r0, #0
	bge _0809EF80
	rsbs r0, r0, #0
_0809EF80:
	cmp r2, #0x80
	bgt _0809F024
	cmp r0, #0x80
	bgt _0809F024
	ldr r1, [r3, #0x1c]
	cmp r1, #1
	beq _0809EF9C
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r4, r2
	b _0809F02A
	.align 2, 0
_0809EF98: .4byte 0x00000252
_0809EF9C:
	movs r5, #0x98
	lsls r5, r5, #2
	adds r0, r4, r5
	strb r1, [r0]
	ldr r0, _0809F018 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _0809EFB8
	ldr r0, _0809F01C @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _0809EFB8
	movs r1, #1
_0809EFB8:
	cmp r1, #0
	bne _0809F02E
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r3, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _0809F02E
	cmp r0, #3
	beq _0809F02E
	cmp r0, #4
	beq _0809F02E
	movs r5, #0xe0
	lsls r5, r5, #2
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F02E
	adds r1, #0x34
	adds r0, r3, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809F02E
	adds r2, #0x24
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #7
	bne _0809F02E
	movs r5, #0x94
	lsls r5, r5, #2
	adds r1, r4, r5
	ldr r2, _0809F020 @ =0x00000262
	adds r0, r4, r2
	ldrh r2, [r0]
	adds r0, r3, #0
	bl FUN_0807a528
	adds r5, #0xe
	adds r1, r4, r5
	movs r0, #1
	b _0809F02C
	.align 2, 0
_0809F018: .4byte 0x03002B8C
_0809F01C: .4byte 0x03002B60
_0809F020: .4byte 0x00000262
_0809F024:
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r4, r0
_0809F02A:
	movs r0, #0
_0809F02C:
	strb r0, [r1]
_0809F02E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809f034
FUN_0809f034: @ 0x0809F034
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r0, #0x96
	lsls r0, r0, #2
	adds r6, r4, r0
	ldr r2, [r6]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _0809F090
	movs r1, #0x40
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809F0A2
	ldr r0, _0809F08C @ =0x030046A0
	ldr r0, [r0]
	movs r7, #0xef
	lsls r7, r7, #2
	adds r5, r0, r7
	ldr r3, [r5]
	cmp r3, #0
	ble _0809F0A2
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	subs r7, #0x52
	adds r1, r2, r7
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0809F0A2
	subs r0, r3, #1
	str r0, [r5]
	ldr r1, [r6]
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0809F0A2
	.align 2, 0
_0809F08C: .4byte 0x030046A0
_0809F090:
	adds r0, r4, #0
	adds r0, #0x44
	ldr r1, _0809F0B4 @ =0x0000013D
	bl FUN_0822b20c
	ldr r7, _0809F0B8 @ =0x0000025E
	adds r1, r4, r7
	movs r0, #0
	strb r0, [r1]
_0809F0A2:
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809F0B4: .4byte 0x0000013D
_0809F0B8: .4byte 0x0000025E

	thumb_func_start FUN_0809f0bc
FUN_0809f0bc: @ 0x0809F0BC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x40
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809F138
	ldr r1, _0809F0EC @ =0x0000025F
	adds r0, r5, r1
	ldrb r0, [r0]
	lsrs r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	beq _0809F0FA
	cmp r1, #1
	bgt _0809F0F0
	cmp r1, #0
	beq _0809F10C
	b _0809F124
	.align 2, 0
_0809F0EC: .4byte 0x0000025F
_0809F0F0:
	cmp r1, #2
	beq _0809F10C
	cmp r1, #3
	beq _0809F11A
	b _0809F124
_0809F0FA:
	adds r0, r5, #0
	adds r0, #0x44
	ldr r1, _0809F108 @ =0x0000013F
	bl FUN_0822b20c
	b _0809F124
	.align 2, 0
_0809F108: .4byte 0x0000013F
_0809F10C:
	adds r0, r5, #0
	adds r0, #0x44
	movs r1, #0x9f
	lsls r1, r1, #1
	bl FUN_0822b20c
	b _0809F124
_0809F11A:
	adds r0, r5, #0
	adds r0, #0x44
	ldr r1, _0809F130 @ =0x0000013D
	bl FUN_0822b20c
_0809F124:
	ldr r0, _0809F134 @ =0x0000025F
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0809F170
	.align 2, 0
_0809F130: .4byte 0x0000013D
_0809F134: .4byte 0x0000025F
_0809F138:
	ldr r1, _0809F160 @ =0x0000025F
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #4
	bls _0809F146
	movs r0, #4
	strb r0, [r4]
_0809F146:
	ldrb r6, [r4]
	cmp r6, #0
	beq _0809F164
	adds r0, r5, #0
	adds r0, #0x44
	movs r1, #0x9f
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _0809F170
	.align 2, 0
_0809F160: .4byte 0x0000025F
_0809F164:
	adds r0, r5, #0
	adds r0, #0x44
	ldr r1, _0809F178 @ =0x0000013D
	bl FUN_0822b20c
	strb r6, [r4]
_0809F170:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809F178: .4byte 0x0000013D

	thumb_func_start FUN_0809f17c
FUN_0809f17c: @ 0x0809F17C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	movs r0, #0x98
	lsls r0, r0, #2
	add r0, r8
	ldrh r0, [r0]
	cmp r0, #0
	bne _0809F198
	b _0809F2E4
_0809F198:
	ldr r5, _0809F218 @ =0x030046A0
	ldr r0, [r5]
	movs r4, #0xef
	lsls r4, r4, #2
	adds r1, r0, r4
	ldr r0, [r1]
	ldr r2, _0809F21C @ =0x0000270F
	cmp r0, r2
	ble _0809F1AC
	str r2, [r1]
_0809F1AC:
	ldr r0, [r5]
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0xfa
	lsls r1, r1, #2
	bl Div
	str r0, [sp]
	ldr r2, [r5]
	adds r2, r2, r4
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r4, [r2]
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [sp, #0xc]
	add r5, sp, #0x10
	mov r6, r8
	adds r6, #0x34
	mov r1, r8
	ldrh r0, [r1, #0x34]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0809F220
	asrs r0, r0, #8
	b _0809F226
	.align 2, 0
_0809F218: .4byte 0x030046A0
_0809F21C: .4byte 0x0000270F
_0809F220:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0809F226:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0809F238
	asrs r0, r0, #8
	b _0809F23E
_0809F238:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0809F23E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0809F252
	asrs r0, r0, #8
	b _0809F258
_0809F252:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0809F258:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0809F2E0 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	mov r1, sp
	ldrh r0, [r1, #0x10]
	subs r0, #0x10
	add r1, sp, #0x10
	strh r0, [r1]
	ldrh r0, [r1, #2]
	subs r0, #0x2c
	strh r0, [r1, #2]
	movs r0, #0x60
	add r0, r8
	mov sl, r0
	mov r7, r8
	adds r7, #0xa0
	mov sb, sp
	mov r6, r8
	adds r6, #0x80
	mov r4, r8
	adds r4, #0x88
	movs r5, #3
_0809F29C:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r1, sb
	adds r1, #4
	mov sb, r1
	subs r1, #4
	ldm r1!, {r2}
	adds r2, #0x1e
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	str r0, [r7]
	str r1, [r7, #4]
	mov r1, sp
	ldrh r0, [r1, #0x10]
	adds r0, #8
	add r1, sp, #0x10
	strh r0, [r1]
	adds r7, #0x60
	adds r6, #0x60
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809F29C
	b _0809F2FA
	.align 2, 0
_0809F2E0: .4byte 0x030047C8
_0809F2E4:
	movs r2, #1
	mov r1, r8
	adds r1, #0x88
	movs r5, #3
_0809F2EC:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809F2EC
_0809F2FA:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809f30c
FUN_0809f30c: @ 0x0809F30C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	mov r1, sp
	bl FUN_08230f94
	adds r2, r0, #0
	subs r2, #1
	cmp r0, #0
	ble _0809F356
	ldr r0, _0809F340 @ =0x00000261
	adds r3, r4, r0
	ldr r1, [sp]
	movs r5, #1
	movs r4, #0
_0809F332:
	ldr r0, [r1, #4]
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809F344
	cmp r0, #1
	beq _0809F348
	b _0809F34A
	.align 2, 0
_0809F340: .4byte 0x00000261
_0809F344:
	strb r5, [r3]
	b _0809F34A
_0809F348:
	strb r4, [r3]
_0809F34A:
	adds r1, #8
	adds r0, r2, #0
	subs r2, #1
	cmp r0, #0
	bgt _0809F332
	str r1, [sp]
_0809F356:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EntityDC21_Update
EntityDC21_Update: @ 0x0809F360
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0809f30c
	ldr r1, _0809F378 @ =0x0000025E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809F37C
	cmp r0, #1
	beq _0809F384
	b _0809F38A
	.align 2, 0
_0809F378: .4byte 0x0000025E
_0809F37C:
	adds r0, r4, #0
	bl FUN_0809ef38
	b _0809F38A
_0809F384:
	adds r0, r4, #0
	bl FUN_0809f034
_0809F38A:
	adds r0, r4, #0
	bl FUN_0809f0bc
	adds r0, r4, #0
	bl FUN_0809f17c
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityDC21_Destroy
EntityDC21_Destroy: @ 0x0809F3A0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0x18
	bl FUN_0822a4e0
	adds r4, r6, #0
	adds r4, #0x80
	movs r5, #3
_0809F3B0:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809F3B0
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_08236424
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809f3d0
FUN_0809f3d0: @ 0x0809F3D0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x18
	adds r4, #0x44
	ldr r1, _0809F40C @ =0x0000A47C
	adds r0, r4, #0
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0
	strh r0, [r5, #0x10]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0809F410
	bl Script_GetValue
	strh r0, [r5, #0x1c]
	bl Script_GetValue
	strh r0, [r5, #0x1e]
	bl Script_GetValue
	b _0809F414
	.align 2, 0
_0809F40C: .4byte 0x0000A47C
_0809F410:
	strh r0, [r5, #0x1c]
	strh r0, [r5, #0x1e]
_0809F414:
	strh r0, [r5, #0x20]
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0809F42A
	bl Script_GetValue
	cmp r0, #0
	beq _0809F42A
	movs r0, #4
_0809F42A:
	str r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809f434
FUN_0809f434: @ 0x0809F434
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r0, _0809F4A4 @ =0x0000CB05
	ldr r1, _0809F4A8 @ =0x0000B343
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _0809F49A
	adds r1, r5, #0
	adds r1, #0x60
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r5, #0
	adds r4, #0x60
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _0809F4AC @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	adds r6, r4, #0
	adds r4, #0x20
	movs r5, #3
_0809F476:
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x1e
	movs r3, #0x31
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809F476
_0809F49A:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809F4A4: .4byte 0x0000CB05
_0809F4A8: .4byte 0x0000B343
_0809F4AC: .4byte 0xFFFF0000

	thumb_func_start FUN_0809f4b0
FUN_0809f4b0: @ 0x0809F4B0
	push {lr}
	adds r2, r0, #0
	movs r0, #0x94
	lsls r0, r0, #2
	adds r3, r2, r0
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r0, [r2, #0x18]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809F4D8
	adds r1, #0xfc
	adds r0, r1, #0
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	b _0809F4EA
_0809F4D8:
	movs r0, #0x95
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_0809F4EA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809f4f0
FUN_0809f4f0: @ 0x0809F4F0
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0x80
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r2, _0809F570 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x64
	orrs r0, r3
	ldr r1, _0809F574 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x96
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _0809F578 @ =0x00004001
	movs r0, #0
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	adds r0, r5, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r4, #0x34
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809F570: .4byte 0xFFFF0000
_0809F574: .4byte 0x0000FFFF
_0809F578: .4byte 0x00004001

	thumb_func_start EntityDC21_Init
EntityDC21_Init: @ 0x0809F57C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r2, r1, #0
	ldr r0, _0809F598 @ =0x03002BE0
	ldr r1, [r0]
	movs r3, #0x96
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	cmp r1, #0
	bne _0809F59C
	movs r0, #1
	rsbs r0, r0, #0
	b _0809F5FA
	.align 2, 0
_0809F598: .4byte 0x03002BE0
_0809F59C:
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r4, #0
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_0809f3d0
	adds r0, r5, #0
	bl FUN_0809f4b0
	adds r0, r5, #0
	bl FUN_0809f4f0
	adds r0, r5, #0
	bl FUN_0809f434
	ldr r3, _0809F5EC @ =0x0000025E
	adds r0, r5, r3
	strb r4, [r0]
	movs r1, #0x98
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	subs r1, #1
	adds r0, r5, r1
	strb r4, [r0]
	ldr r0, [r5, #0x18]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809F5F0
	adds r3, #1
	adds r1, r5, r3
	movs r0, #7
	b _0809F5F6
	.align 2, 0
_0809F5EC: .4byte 0x0000025E
_0809F5F0:
	ldr r0, _0809F600 @ =0x00000262
	adds r1, r5, r0
	movs r0, #1
_0809F5F6:
	strh r0, [r1]
	movs r0, #0
_0809F5FA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809F600: .4byte 0x00000262

	thumb_func_start EntityDC21_Create
EntityDC21_Create: @ 0x0809F604
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x99
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809F644
	ldr r1, _0809F63C @ =EntityDC21_Update
	ldr r2, _0809F640 @ =EntityDC21_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl EntityDC21_Init
	cmp r0, #0
	bge _0809F644
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809F646
	.align 2, 0
_0809F63C: .4byte EntityDC21_Update
_0809F640: .4byte EntityDC21_Destroy
_0809F644:
	adds r0, r4, #0
_0809F646:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809f64c
FUN_0809f64c: @ 0x0809F64C
	ldr r1, _0809F654 @ =0x03000144
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0809F654: .4byte 0x03000144

	thumb_func_start FUN_0809f658
FUN_0809f658: @ 0x0809F658
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _0809F668 @ =0x03000144
	ldr r0, [r0]
	cmp r0, #0
	bne _0809F676
	b _0809F6E4
	.align 2, 0
_0809F668: .4byte 0x03000144
_0809F66C:
	adds r1, r3, #0
	adds r1, #0xdf
	movs r0, #1
	strb r0, [r1]
	b _0809F6E6
_0809F676:
	movs r4, #0
	ldrh r1, [r0, #0x18]
	cmp r4, r1
	bge _0809F6E4
	mov ip, r0
	adds r6, r1, #0
_0809F682:
	movs r0, #0xf4
	muls r0, r4, r0
	adds r0, #0x1c
	mov r1, ip
	adds r3, r1, r0
	adds r0, r3, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F6DE
	movs r2, #0x1e
	ldrsh r1, [r3, r2]
	movs r7, #2
	ldrsh r0, [r5, r7]
	cmp r1, r0
	blt _0809F6DE
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r2, #0x1c
	ldrsh r0, [r3, r2]
	subs r2, r1, r0
	cmp r2, #0
	bge _0809F6B2
	rsbs r2, r2, #0
_0809F6B2:
	cmp r2, #0x80
	bgt _0809F6DE
	movs r7, #4
	ldrsh r1, [r5, r7]
	movs r7, #0x20
	ldrsh r0, [r3, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _0809F6C6
	rsbs r1, r1, #0
_0809F6C6:
	cmp r1, #0x80
	bgt _0809F6DE
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	ble _0809F66C
_0809F6DE:
	adds r4, #1
	cmp r4, r6
	blt _0809F682
_0809F6E4:
	movs r0, #0
_0809F6E6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809f6ec
FUN_0809f6ec: @ 0x0809F6EC
	push {r4, r5, lr}
	ldr r4, _0809F704 @ =0x03000144
	ldr r0, [r4]
	cmp r0, #0
	beq _0809F738
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	bne _0809F710
	b _0809F738
	.align 2, 0
_0809F704: .4byte 0x03000144
_0809F708:
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r0, [r0]
	b _0809F73C
_0809F710:
	bl Script_GetValue
	adds r5, r0, #0
	movs r3, #0
	ldr r0, [r4]
	ldrh r1, [r0, #0x18]
	cmp r3, r1
	bge _0809F738
	adds r4, r1, #0
	adds r1, r0, #0
	adds r1, #0xfc
	adds r2, r0, #0
_0809F728:
	ldrh r0, [r1]
	cmp r0, r5
	beq _0809F708
	adds r1, #0xf4
	adds r2, #0xf4
	adds r3, #1
	cmp r3, r4
	blt _0809F728
_0809F738:
	movs r0, #1
	rsbs r0, r0, #0
_0809F73C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809f744
FUN_0809f744: @ 0x0809F744
	mov ip, r0
	adds r0, #0xdc
	movs r3, #0
	strb r1, [r0]
	adds r0, #0x14
	str r2, [r0]
	subs r0, #4
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809f75c
FUN_0809f75c: @ 0x0809F75C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r3, r2, #0
	adds r5, r3, #0
	adds r6, r7, #0
	adds r6, #0x44
	ldrh r0, [r6]
	cmp r0, #0
	bne _0809F7F6
	movs r1, #4
	ldr r0, [r4, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0809F7F6
	ldr r2, [r4, #0x38]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0809F7BC
	adds r0, r3, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F7A0
	ldr r2, _0809F79C @ =FUN_0809f938
	adds r0, r3, #0
	movs r1, #2
	bl FUN_0809f744
	b _0809F7AE
	.align 2, 0
_0809F79C: .4byte FUN_0809f938
_0809F7A0:
	cmp r0, #1
	bne _0809F7AE
	ldr r2, _0809F7B8 @ =FUN_0809f890
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0809f744
_0809F7AE:
	adds r1, r7, #0
	adds r1, #0x44
	movs r0, #0x1e
	strh r0, [r1]
	b _0809F7F6
	.align 2, 0
_0809F7B8: .4byte FUN_0809f890
_0809F7BC:
	movs r0, #8
	ands r2, r0
	cmp r2, #0
	beq _0809F7E4
	adds r0, r3, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F7D8
	ldr r2, _0809F7E0 @ =FUN_0809f840
	adds r0, r3, #0
	movs r1, #1
	bl FUN_0809f744
_0809F7D8:
	movs r0, #0x1e
	strh r0, [r6]
	b _0809F7F6
	.align 2, 0
_0809F7E0: .4byte FUN_0809f840
_0809F7E4:
	adds r0, r5, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F7F6
	adds r1, r5, #0
	adds r1, #0xdf
	movs r0, #1
	strb r0, [r1]
_0809F7F6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809f7fc
FUN_0809f7fc: @ 0x0809F7FC
	push {lr}
	adds r3, r0, #0
	ldr r0, _0809F830 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809F834 @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _0809F82C
	adds r0, r3, #0
	adds r0, #0xec
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	ldr r0, _0809F838 @ =0x012B0000
	cmp r1, r0
	ble _0809F82C
	ldr r2, _0809F83C @ =FUN_0809f890
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0809f744
_0809F82C:
	pop {r0}
	bx r0
	.align 2, 0
_0809F830: .4byte 0x030046A0
_0809F834: .4byte 0x00000942
_0809F838: .4byte 0x012B0000
_0809F83C: .4byte FUN_0809f890

	thumb_func_start FUN_0809f840
FUN_0809f840: @ 0x0809F840
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xee
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809F854
	ldr r0, _0809F868 @ =0x0000019F
	bl PlaySound_082406e0
_0809F854:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0809F86C
	movs r0, #3
	strh r0, [r5, #0x10]
	b _0809F884
	.align 2, 0
_0809F868: .4byte 0x0000019F
_0809F86C:
	cmp r0, #0xf
	bhi _0809F876
	movs r0, #4
	strh r0, [r5, #0x10]
	b _0809F884
_0809F876:
	movs r0, #5
	strh r0, [r5, #0x10]
	ldr r2, _0809F88C @ =FUN_0809f7fc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0809f744
_0809F884:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809F88C: .4byte FUN_0809f7fc

	thumb_func_start FUN_0809f890
FUN_0809f890: @ 0x0809F890
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xee
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809F8A6
	movs r0, #0xd0
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0809F8A6:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0809F8BA
	movs r0, #4
	strh r0, [r5, #0x10]
	b _0809F8DA
_0809F8BA:
	cmp r0, #0xf
	bhi _0809F8C4
	movs r0, #3
	strh r0, [r5, #0x10]
	b _0809F8DA
_0809F8C4:
	movs r0, #2
	strh r0, [r5, #0x10]
	movs r0, #0xd0
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r2, _0809F8E0 @ =FUN_0809fabc
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0809f744
_0809F8DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809F8E0: .4byte FUN_0809fabc

	thumb_func_start FUN_0809f8e4
FUN_0809f8e4: @ 0x0809F8E4
	push {lr}
	adds r3, r0, #0
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, _0809F900 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0809F904 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809F908
	movs r0, #1
	b _0809F90A
	.align 2, 0
_0809F900: .4byte 0x030046A0
_0809F904: .4byte 0x00000934
_0809F908:
	movs r0, #0
_0809F90A:
	cmp r0, #0
	beq _0809F92A
	adds r0, r3, #0
	adds r0, #0xec
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	ldr r0, _0809F930 @ =0x012B0000
	cmp r1, r0
	ble _0809F92A
	ldr r2, _0809F934 @ =FUN_0809fa80
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0809f744
_0809F92A:
	pop {r0}
	bx r0
	.align 2, 0
_0809F930: .4byte 0x012B0000
_0809F934: .4byte FUN_0809fa80

	thumb_func_start FUN_0809f938
FUN_0809f938: @ 0x0809F938
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x14
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xee
	ldrh r0, [r5]
	cmp r0, #0
	bne _0809F954
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0809F954:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0809F9D8
	movs r0, #6
	strh r0, [r4, #0x10]
	ldrh r1, [r5]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0809F972
	b _0809FA6E
_0809F972:
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r6, _0809F9C8 @ =0x0203B400
	ldr r5, _0809F9CC @ =0x030046B8
	ldr r2, [r5]
	adds r2, #1
	ldr r4, _0809F9D0 @ =0x000003FF
	ands r2, r4
	lsls r3, r2, #1
	adds r3, r3, r6
	add r0, sp, #4
	ldrh r1, [r0]
	subs r1, #0x7f
	ldrb r3, [r3]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0809F9D4 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	adds r2, #1
	ands r2, r4
	str r2, [r5]
	lsls r2, r2, #1
	adds r2, r2, r6
	add r0, sp, #4
	ldrh r0, [r0, #4]
	subs r0, #0x7f
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #8]
	add r0, sp, #4
	str r0, [sp]
	b _0809FA40
	.align 2, 0
_0809F9C8: .4byte 0x0203B400
_0809F9CC: .4byte 0x030046B8
_0809F9D0: .4byte 0x000003FF
_0809F9D4: .4byte 0xFFFF0000
_0809F9D8:
	cmp r0, #0xf
	bhi _0809FA60
	movs r0, #7
	strh r0, [r4, #0x10]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0809FA6E
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r0, _0809FA50 @ =0x0203B400
	mov r8, r0
	ldr r6, _0809FA54 @ =0x030046B8
	ldr r2, [r6]
	adds r2, #1
	ldr r4, _0809FA58 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	add r0, r8
	add r3, sp, #0xc
	ldrh r1, [r3]
	subs r1, #0x7f
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r5, _0809FA5C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r2, #1
	ands r2, r4
	str r2, [r6]
	lsls r2, r2, #1
	add r2, r8
	ldrh r0, [r3, #4]
	subs r0, #0x7f
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r3, #4]
	ands r1, r5
	orrs r1, r0
	str r1, [r3, #4]
	str r3, [sp]
_0809FA40:
	movs r0, #1
	movs r1, #0
	movs r2, #1
	movs r3, #0x40
	bl FUN_08015c90
	b _0809FA6E
	.align 2, 0
_0809FA50: .4byte 0x0203B400
_0809FA54: .4byte 0x030046B8
_0809FA58: .4byte 0x000003FF
_0809FA5C: .4byte 0xFFFF0000
_0809FA60:
	movs r0, #8
	strh r0, [r4, #0x10]
	ldr r2, _0809FA7C @ =FUN_0809f8e4
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0809f744
_0809FA6E:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809FA7C: .4byte FUN_0809f8e4

	thumb_func_start FUN_0809fa80
FUN_0809fa80: @ 0x0809FA80
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xee
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0809FA9C
	movs r0, #7
	strh r0, [r3, #0x10]
	b _0809FAB4
_0809FA9C:
	cmp r0, #0xf
	bhi _0809FAA6
	movs r0, #6
	strh r0, [r3, #0x10]
	b _0809FAB4
_0809FAA6:
	movs r0, #2
	strh r0, [r3, #0x10]
	ldr r2, _0809FAB8 @ =FUN_0809fabc
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0809f744
_0809FAB4:
	pop {r0}
	bx r0
	.align 2, 0
_0809FAB8: .4byte FUN_0809fabc

	thumb_func_start FUN_0809fabc
FUN_0809fabc: @ 0x0809FABC
	push {lr}
	adds r3, r0, #0
	movs r0, #0xdf
	adds r0, r0, r3
	mov ip, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809FAF4
	adds r2, r3, #0
	adds r2, #0xe5
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	mov r0, ip
	strb r1, [r0]
	adds r2, #9
	ldrh r1, [r2]
	cmp r1, #0x3f
	bls _0809FAEE
	ldrh r0, [r2]
	subs r0, #0x40
	movs r1, #0x1f
	ands r0, r1
	asrs r0, r0, #1
	b _0809FAF2
_0809FAEE:
	movs r0, #0xf
	ands r0, r1
_0809FAF2:
	strh r0, [r2]
_0809FAF4:
	movs r1, #0xe5
	adds r1, r1, r3
	mov ip, r1
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809FB46
	adds r2, r3, #0
	adds r2, #0xee
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5f
	bls _0809FB22
	movs r0, #2
	strh r0, [r3, #0x10]
	movs r0, #0
	mov r1, ip
	strb r0, [r1]
	movs r0, #0
	strh r0, [r2]
	b _0809FB46
_0809FB22:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bhi _0809FB36
	movs r0, #0xf
	ands r1, r0
	cmp r1, #7
	bhi _0809FB42
	movs r0, #1
	b _0809FB44
_0809FB36:
	movs r0, #0x1f
	ands r1, r0
	cmp r1, #0xf
	bhi _0809FB42
	movs r0, #1
	b _0809FB44
_0809FB42:
	movs r0, #2
_0809FB44:
	strh r0, [r3, #0x10]
_0809FB46:
	ldr r0, _0809FB78 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809FB7C @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	cmp r2, #0
	bne _0809FBA8
	adds r0, r3, #0
	adds r0, #0xdd
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809FB80
	adds r1, r3, #0
	adds r1, #0xec
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0809FBEE
	strh r2, [r1]
	b _0809FBEE
	.align 2, 0
_0809FB78: .4byte 0x030046A0
_0809FB7C: .4byte 0x00000942
_0809FB80:
	adds r0, r3, #0
	adds r0, #0xec
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r0, _0809FBA0 @ =0xFFFFFED4
	cmp r1, r0
	bge _0809FBEE
	ldr r2, _0809FBA4 @ =FUN_0809f840
	adds r0, r3, #0
	movs r1, #1
	bl FUN_0809f744
	b _0809FBEE
	.align 2, 0
_0809FBA0: .4byte 0xFFFFFED4
_0809FBA4: .4byte FUN_0809f840
_0809FBA8:
	cmp r2, #7
	ble _0809FBEE
	adds r0, r3, #0
	adds r0, #0xdd
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809FBD0
	adds r1, r3, #0
	adds r1, #0xec
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0809FBEE
	movs r0, #0
	strh r0, [r1]
	b _0809FBEE
_0809FBD0:
	adds r0, r3, #0
	adds r0, #0xec
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	movs r0, #0x96
	lsls r0, r0, #0x11
	cmp r1, r0
	ble _0809FBEE
	ldr r2, _0809FBF4 @ =FUN_0809f938
	adds r0, r3, #0
	movs r1, #2
	bl FUN_0809f744
_0809FBEE:
	pop {r0}
	bx r0
	.align 2, 0
_0809FBF4: .4byte FUN_0809f938

	thumb_func_start FUN_0809fbf8
FUN_0809fbf8: @ 0x0809FBF8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0xe6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809FCC4
	adds r0, r4, #0
	adds r0, #0xe8
	ldrh r1, [r0]
	ldr r0, _0809FC40 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r1, r0
	bne _0809FC48
	adds r0, r4, #0
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809FC30
	adds r2, r4, #0
	adds r2, #0x92
	ldrh r1, [r2]
	ldr r0, _0809FC44 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
_0809FC30:
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _0809FCD0
	.align 2, 0
_0809FC40: .4byte 0x030046A0
_0809FC44: .4byte 0x0000FFFB
_0809FC48:
	adds r0, r4, #0
	adds r0, #0xe7
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _0809FCD0
	subs r0, #0xb
	ldrb r5, [r0]
	cmp r5, #0
	bne _0809FC7C
	ldr r2, _0809FC78 @ =FUN_0809fabc
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0809f744
	movs r0, #0
	strh r5, [r4, #0x10]
	adds r1, r4, #0
	adds r1, #0xe5
	strb r0, [r1]
	subs r1, #6
	strb r0, [r1]
	b _0809FCAE
	.align 2, 0
_0809FC78: .4byte FUN_0809fabc
_0809FC7C:
	cmp r5, #2
	bne _0809FC94
	ldr r2, _0809FC90 @ =FUN_0809f8e4
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0809f744
	movs r0, #8
	b _0809FCA4
	.align 2, 0
_0809FC90: .4byte FUN_0809f8e4
_0809FC94:
	cmp r5, #1
	bne _0809FCAE
	ldr r2, _0809FCC0 @ =FUN_0809f7fc
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0809f744
	movs r0, #5
_0809FCA4:
	strh r0, [r4, #0x10]
	adds r1, r4, #0
	adds r1, #0xe2
	movs r0, #0x10
	strh r0, [r1]
_0809FCAE:
	adds r3, r4, #0
	adds r3, #0x92
	ldrh r0, [r3]
	movs r1, #4
	movs r2, #0
	orrs r1, r0
	strh r1, [r3]
	strb r2, [r6]
	b _0809FCD0
	.align 2, 0
_0809FCC0: .4byte FUN_0809f7fc
_0809FCC4:
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0809FCD0:
	adds r1, r4, #0
	adds r1, #0xd0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0809FCDE
	subs r0, #1
	strh r0, [r1]
_0809FCDE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809fce4
FUN_0809fce4: @ 0x0809FCE4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r2, #0
	ldr r2, [sp, #0x18]
	adds r0, #0xe0
	movs r5, #0
	movs r4, #0
	strh r1, [r0]
	subs r0, #4
	strb r3, [r0]
	adds r0, #6
	strh r4, [r0]
	adds r0, #3
	strb r5, [r0]
	subs r0, #6
	strb r5, [r0]
	subs r0, #2
	mov r1, sp
	ldrb r1, [r1, #0x14]
	strb r1, [r0]
	adds r0, #9
	strb r2, [r0]
	lsls r2, r2, #0x18
	cmp r2, #0
	beq _0809FD22
	adds r0, r6, #0
	bl FUN_08241574
	adds r1, r7, #0
	adds r1, #0xe8
	strh r0, [r1]
_0809FD22:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809fd28
FUN_0809fd28: @ 0x0809FD28
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r4, r7, #0
	adds r4, #0x2c
	ldr r1, _0809FD90 @ =0x0000A680
	adds r0, r4, #0
	bl Video_GetActorSprite
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r4, #0
	movs r1, #0x43
	bl FUN_0822b20c
	movs r0, #3
	strb r0, [r7, #7]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r0, r7, #0
	adds r0, #0xe4
	strb r5, [r0]
	lsls r5, r5, #0x18
	cmp r5, #0
	beq _0809FD86
	adds r4, #0x1c
	subs r0, #4
	ldrh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	bl FUN_08002a48
_0809FD86:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809FD90: .4byte 0x0000A680

	thumb_func_start FUN_0809fd94
FUN_0809fd94: @ 0x0809FD94
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x8c
	ldr r2, _0809FE0C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _0809FE10 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	adds r0, r4, #0
	adds r0, #0xe0
	ldrh r1, [r0]
	ldr r2, _0809FE14 @ =0x00004003
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _0809FE18 @ =FUN_0809f75c
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r4, #0x1c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r5, #0x3e]
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809FE0C: .4byte 0xFFFF0000
_0809FE10: .4byte 0x0000FFFF
_0809FE14: .4byte 0x00004003
_0809FE18: .4byte FUN_0809f75c

	thumb_func_start FUN_0809fe1c
FUN_0809fe1c: @ 0x0809FE1C
	push {lr}
	adds r1, r0, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809FE3C
	strh r0, [r1, #0x10]
	ldr r2, _0809FE38 @ =FUN_0809fabc
	adds r0, r1, #0
	movs r1, #0
	bl FUN_0809f744
	b _0809FE66
	.align 2, 0
_0809FE38: .4byte FUN_0809fabc
_0809FE3C:
	cmp r0, #2
	bne _0809FE54
	movs r0, #8
	strh r0, [r1, #0x10]
	ldr r2, _0809FE50 @ =FUN_0809f8e4
	adds r0, r1, #0
	movs r1, #2
	bl FUN_0809f744
	b _0809FE66
	.align 2, 0
_0809FE50: .4byte FUN_0809f8e4
_0809FE54:
	cmp r0, #1
	bne _0809FE66
	movs r0, #5
	strh r0, [r1, #0x10]
	ldr r2, _0809FE6C @ =FUN_0809f7fc
	adds r0, r1, #0
	movs r1, #1
	bl FUN_0809f744
_0809FE66:
	pop {r0}
	bx r0
	.align 2, 0
_0809FE6C: .4byte FUN_0809f7fc

	thumb_func_start FUN_0809fe70
FUN_0809fe70: @ 0x0809FE70
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	mov r8, r2
	ldr r7, [sp, #0x20]
	ldr r5, [sp, #0x24]
	ldr r6, [sp, #0x28]
	ldrh r2, [r4, #0x18]
	movs r0, #0xf4
	muls r0, r2, r0
	adds r0, #0x1c
	adds r4, r4, r0
	str r5, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	mov r2, r8
	bl FUN_0809fce4
	adds r0, r4, #0
	mov r1, r8
	adds r2, r7, #0
	bl FUN_0809fd28
	adds r0, r4, #0
	bl FUN_0809fd94
	adds r0, r4, #0
	bl FUN_0809fe1c
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809febc
FUN_0809febc: @ 0x0809FEBC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrh r0, [r6, #0x18]
	cmp r5, r0
	bge _0809FEDC
	adds r4, r6, #0
	adds r4, #0x1c
_0809FECC:
	adds r0, r4, #0
	bl FUN_0809fbf8
	adds r4, #0xf4
	adds r5, #1
	ldrh r0, [r6, #0x18]
	cmp r5, r0
	blt _0809FECC
_0809FEDC:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809fee4
FUN_0809fee4: @ 0x0809FEE4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	b _0809FF1C
_0809FEEC:
	movs r0, #0xf4
	adds r4, r6, #0
	muls r4, r0, r4
	adds r0, r5, r4
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809FF08
	adds r0, r4, r5
	adds r0, #0x64
	bl FUN_0823b284
_0809FF08:
	adds r4, #0x1c
	adds r4, r5, r4
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x8c
	adds r0, r4, #0
	bl FUN_08236424
	adds r6, #1
_0809FF1C:
	ldrh r0, [r5, #0x18]
	cmp r6, r0
	blt _0809FEEC
	ldr r1, _0809FF30 @ =0x03000144
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809FF30: .4byte 0x03000144

	thumb_func_start FUN_0809ff34
FUN_0809ff34: @ 0x0809FF34
	movs r1, #0
	strh r1, [r0, #0x18]
	ldr r1, _0809FF40 @ =0x03000144
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_0809FF40: .4byte 0x03000144

	thumb_func_start FUN_0809ff44
FUN_0809ff44: @ 0x0809FF44
	push {r4, lr}
	ldr r1, _0809FF70 @ =0x000007BC
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809FF7C
	ldr r1, _0809FF74 @ =FUN_0809febc
	ldr r2, _0809FF78 @ =FUN_0809fee4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0809ff34
	cmp r0, #0
	bge _0809FF7C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809FF7E
	.align 2, 0
_0809FF70: .4byte 0x000007BC
_0809FF74: .4byte FUN_0809febc
_0809FF78: .4byte FUN_0809fee4
_0809FF7C:
	adds r0, r4, #0
_0809FF7E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809ff84
FUN_0809ff84: @ 0x0809FF84
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	ldr r0, _0809FFB0 @ =0x03000144
	ldr r6, [r0]
	cmp r6, #0
	bne _0809FF9A
	bl FUN_0809ff44
	adds r6, r0, #0
_0809FF9A:
	ldrh r0, [r6, #0x18]
	cmp r0, #7
	bhi _080A0074
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _0809FFB4
	bl Script_GetValue
	b _0809FFB6
	.align 2, 0
_0809FFB0: .4byte 0x03000144
_0809FFB4:
	movs r0, #0
_0809FFB6:
	mov r8, r0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A0000
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0809FFF8 @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0809FFFC @ =0x0000FFFF
	ldr r1, [sp, #0xc]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0xc]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	b _080A000A
	.align 2, 0
_0809FFF8: .4byte 0xFFFF0000
_0809FFFC: .4byte 0x0000FFFF
_080A0000:
	ldr r1, _080A001C @ =0xFFFF0000
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r1
	str r0, [sp, #0x10]
_080A000A:
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080A0020
	bl Script_GetValue
	adds r7, r0, #0
	b _080A0022
	.align 2, 0
_080A001C: .4byte 0xFFFF0000
_080A0020:
	movs r7, #0
_080A0022:
	movs r0, #0x68
	bl prepare_08231510
	cmp r0, #0
	beq _080A0034
	bl Script_GetValue
	adds r5, r0, #0
	b _080A0036
_080A0034:
	movs r5, #0
_080A0036:
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A0048
	bl Script_GetValue
	adds r4, r0, #0
	b _080A004A
_080A0048:
	movs r4, #0
_080A004A:
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A005A
	bl Script_GetValue
	b _080A005C
_080A005A:
	movs r0, #0
_080A005C:
	str r5, [sp]
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	mov r1, r8
	add r2, sp, #0xc
	adds r3, r7, #0
	bl FUN_0809fe70
	ldrh r0, [r6, #0x18]
	adds r0, #1
	strh r0, [r6, #0x18]
_080A0074:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a0080
FUN_080a0080: @ 0x080A0080
	push {lr}
	adds r3, r0, #0
	ldr r0, _080A00B0 @ =0x03002BE0
	ldr r1, [r0]
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A00AC
	cmp r1, #0
	blt _080A00AC
	ldr r0, _080A00B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A00AC
	ldr r0, _080A00B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A00BC
_080A00AC:
	movs r0, #0
	b _080A00CA
	.align 2, 0
_080A00B0: .4byte 0x03002BE0
_080A00B4: .4byte 0x030046A8
_080A00B8: .4byte 0x030046AC
_080A00BC:
	ldr r0, _080A00D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A00CA:
	ldrh r3, [r3, #0x1e]
	cmp r0, r3
	beq _080A00D8
	movs r0, #0
	b _080A00DA
	.align 2, 0
_080A00D4: .4byte 0x030046A4
_080A00D8:
	movs r0, #1
_080A00DA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a00e0
FUN_080a00e0: @ 0x080A00E0
	push {lr}
	ldr r1, _080A00F8 @ =0x03002BE0
	ldr r1, [r1]
	movs r2, #0x2e
	ldrsh r1, [r1, r2]
	ldrh r0, [r0, #0x20]
	lsls r0, r0, #8
	cmp r1, r0
	beq _080A00FC
	movs r0, #0
	b _080A00FE
	.align 2, 0
_080A00F8: .4byte 0x03002BE0
_080A00FC:
	movs r0, #1
_080A00FE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a0104
FUN_080a0104: @ 0x080A0104
	push {lr}
	adds r2, r1, #0
	ldrb r1, [r0, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A0120
	ldr r0, _080A011C @ =0x03002BE0
	ldr r0, [r0]
	ldrh r1, [r0, #0x2c]
	b _080A0126
	.align 2, 0
_080A011C: .4byte 0x03002BE0
_080A0120:
	ldr r0, _080A0134 @ =0x03002BE0
	ldr r0, [r0]
	ldrh r1, [r0, #0x30]
_080A0126:
	movs r0, #0xff
	ands r0, r1
	cmp r0, r2
	ble _080A0138
	movs r0, #0
	b _080A013A
	.align 2, 0
_080A0134: .4byte 0x03002BE0
_080A0138:
	movs r0, #1
_080A013A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a0140
FUN_080a0140: @ 0x080A0140
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _080A017C @ =0x03002BE0
	ldr r2, [r0]
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r1, r2, r4
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #4
	bne _080A0184
	ldr r1, _080A0180 @ =0x000003BD
	adds r0, r2, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _080A016A
	ldrb r1, [r3, #0x1c]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A01C2
_080A016A:
	cmp r2, #7
	bne _080A01D0
	ldrb r1, [r3, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080A01C2
	b _080A01D0
	.align 2, 0
_080A017C: .4byte 0x03002BE0
_080A0180: .4byte 0x000003BD
_080A0184:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080A01C2
	ldr r0, _080A01C8 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080A01A4
	ldr r0, _080A01CC @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080A01A4
	movs r1, #1
_080A01A4:
	cmp r1, #0
	bne _080A01B6
	ldr r0, [r4]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A01D0
_080A01B6:
	adds r0, r3, #0
	movs r1, #0x28
	bl FUN_080a0104
	cmp r0, #0
	beq _080A01D0
_080A01C2:
	movs r0, #1
	b _080A01D2
	.align 2, 0
_080A01C8: .4byte 0x03002B8C
_080A01CC: .4byte 0x03002B60
_080A01D0:
	movs r0, #0
_080A01D2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a01d8
FUN_080a01d8: @ 0x080A01D8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	bl FUN_080a00e0
	adds r5, r0, #0
	cmp r5, #0
	beq _080A0250
	adds r0, r4, #0
	bl FUN_080a0080
	cmp r0, #0
	beq _080A0228
	adds r0, r4, #0
	bl FUN_080a0140
	adds r5, r0, #0
	cmp r5, #0
	bne _080A0228
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A0260
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_082342a8
	strb r5, [r4, #0x1d]
	ldr r0, _080A0224 @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807a334
	ldr r0, [r4, #0x34]
	cmp r0, #0
	beq _080A0260
	movs r1, #0
	bl Script_ExecById
	b _080A0260
	.align 2, 0
_080A0224: .4byte 0x03002BE0
_080A0228:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080A0260
	adds r0, r4, #0
	adds r0, #0x24
	ldrh r1, [r4, #0x1e]
	ldrh r3, [r4, #0x20]
	movs r2, #0xff
	str r2, [sp]
	ldr r2, _080A024C @ =0x0000082A
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_08234270
	movs r0, #1
	strb r0, [r4, #0x1d]
	b _080A0260
	.align 2, 0
_080A024C: .4byte 0x0000082A
_080A0250:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A0260
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_082342a8
	strb r5, [r4, #0x1d]
_080A0260:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a0268
FUN_080a0268: @ 0x080A0268
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _080A02A4 @ =0x03002BE0
	ldr r2, [r0]
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r1, r2, r4
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #4
	bne _080A02AC
	ldr r1, _080A02A8 @ =0x000003BD
	adds r0, r2, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _080A0292
	ldrb r1, [r3, #0x1c]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A02E2
_080A0292:
	cmp r2, #7
	bne _080A02F0
	ldrb r1, [r3, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080A02E2
	b _080A02F0
	.align 2, 0
_080A02A4: .4byte 0x03002BE0
_080A02A8: .4byte 0x000003BD
_080A02AC:
	ldr r0, _080A02E8 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080A02C0
	ldr r0, _080A02EC @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080A02C0
	movs r1, #1
_080A02C0:
	cmp r1, #0
	bne _080A02D6
	ldr r0, [r4]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #2
	beq _080A02D6
	cmp r0, #3
	bne _080A02F0
_080A02D6:
	adds r0, r3, #0
	movs r1, #0x28
	bl FUN_080a0104
	cmp r0, #0
	beq _080A02F0
_080A02E2:
	movs r0, #1
	b _080A02F2
	.align 2, 0
_080A02E8: .4byte 0x03002B8C
_080A02EC: .4byte 0x03002B60
_080A02F0:
	movs r0, #0
_080A02F2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a02f8
FUN_080a02f8: @ 0x080A02F8
	push {r4, lr}
	adds r2, r1, #0
	ldrb r1, [r0, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A032C
	ldr r4, _080A0328 @ =0x03002BE0
	ldr r3, [r4]
	ldrh r1, [r3, #0x2c]
	movs r0, #0xff
	ands r0, r1
	cmp r0, r2
	blt _080A0350
	lsls r0, r1, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, r0, r2
	strh r0, [r3, #0x2c]
	ldr r0, [r4]
	ldrh r1, [r0, #0x2c]
	movs r2, #0x82
	lsls r2, r2, #1
	b _080A034C
	.align 2, 0
_080A0328: .4byte 0x03002BE0
_080A032C:
	ldr r4, _080A0358 @ =0x03002BE0
	ldr r3, [r4]
	ldrh r1, [r3, #0x30]
	movs r0, #0xff
	ands r0, r1
	cmp r0, r2
	blt _080A0350
	lsls r0, r1, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, r0, r2
	strh r0, [r3, #0x30]
	ldr r0, [r4]
	ldrh r1, [r0, #0x30]
	movs r2, #0x84
	lsls r2, r2, #1
_080A034C:
	adds r0, r0, r2
	strh r1, [r0]
_080A0350:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A0358: .4byte 0x03002BE0

	thumb_func_start FUN_080a035c
FUN_080a035c: @ 0x080A035C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	bl FUN_080a00e0
	adds r5, r0, #0
	cmp r5, #0
	bne _080A036E
	b _080A0490
_080A036E:
	adds r0, r4, #0
	bl FUN_080a0080
	adds r5, r0, #0
	cmp r5, #0
	beq _080A0442
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	bne _080A03BE
	ldr r2, _080A03A4 @ =0x03002BE0
	ldr r1, [r2]
	ldr r0, _080A03A8 @ =0x000003F3
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrb r1, [r4, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A03B0
	ldr r0, [r2]
	ldr r1, _080A03AC @ =0x000003BD
	adds r0, r0, r1
	movs r1, #7
	b _080A03B8
	.align 2, 0
_080A03A4: .4byte 0x03002BE0
_080A03A8: .4byte 0x000003F3
_080A03AC: .4byte 0x000003BD
_080A03B0:
	ldr r0, [r2]
	ldr r1, _080A0428 @ =0x000003BD
	adds r0, r0, r1
	movs r1, #1
_080A03B8:
	strb r1, [r0]
	movs r0, #1
	strh r0, [r4, #0x22]
_080A03BE:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A03D0
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_082342a8
	movs r0, #0
	strb r0, [r4, #0x1d]
_080A03D0:
	adds r0, r4, #0
	movs r1, #0x28
	bl FUN_080a02f8
	ldr r0, _080A042C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _080A04B6
	ldr r0, _080A0430 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080A03FC
	ldr r0, _080A0434 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080A03FC
	movs r1, #1
_080A03FC:
	cmp r1, #0
	bne _080A04B6
	ldr r0, _080A042C @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080A04B6
	cmp r0, #3
	beq _080A04B6
	ldrb r1, [r4, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A0438
	adds r0, r2, #0
	movs r1, #7
	bl FUN_0807a44c
	b _080A04B6
	.align 2, 0
_080A0428: .4byte 0x000003BD
_080A042C: .4byte 0x03002BE0
_080A0430: .4byte 0x03002B8C
_080A0434: .4byte 0x03002B60
_080A0438:
	adds r0, r2, #0
	movs r1, #1
	bl FUN_0807a44c
	b _080A04B6
_080A0442:
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	beq _080A0458
	ldr r0, _080A0484 @ =0x03002BE0
	ldr r1, [r0]
	ldr r0, _080A0488 @ =0x000003F3
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	strh r5, [r4, #0x22]
_080A0458:
	adds r0, r4, #0
	bl FUN_080a0268
	cmp r0, #0
	bne _080A04A6
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080A04B6
	adds r0, r4, #0
	adds r0, #0x24
	ldrh r1, [r4, #0x1e]
	ldrh r3, [r4, #0x20]
	movs r2, #0xff
	str r2, [sp]
	ldr r2, _080A048C @ =0x0000080B
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_08234270
	movs r0, #1
	strb r0, [r4, #0x1d]
	b _080A04B6
	.align 2, 0
_080A0484: .4byte 0x03002BE0
_080A0488: .4byte 0x000003F3
_080A048C: .4byte 0x0000080B
_080A0490:
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	beq _080A04A6
	ldr r0, _080A04C0 @ =0x03002BE0
	ldr r1, [r0]
	ldr r0, _080A04C4 @ =0x000003F3
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	strh r5, [r4, #0x22]
_080A04A6:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A04B6
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_082342a8
	strb r5, [r4, #0x1d]
_080A04B6:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A04C0: .4byte 0x03002BE0
_080A04C4: .4byte 0x000003F3

	thumb_func_start FUN_080a04c8
FUN_080a04c8: @ 0x080A04C8
	push {lr}
	ldr r0, _080A04FC @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080A04DE
	ldr r0, _080A0500 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080A04DE
	movs r1, #1
_080A04DE:
	cmp r1, #0
	bne _080A04F6
	ldr r0, _080A0504 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080A04F6
	cmp r0, #3
	bne _080A0508
_080A04F6:
	movs r0, #1
	b _080A050A
	.align 2, 0
_080A04FC: .4byte 0x03002B8C
_080A0500: .4byte 0x03002B60
_080A0504: .4byte 0x03002BE0
_080A0508:
	movs r0, #0
_080A050A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a0510
FUN_080a0510: @ 0x080A0510
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	bl FUN_080a00e0
	adds r5, r0, #0
	cmp r5, #0
	beq _080A05D0
	adds r0, r4, #0
	bl FUN_080a0080
	cmp r0, #0
	beq _080A0580
	adds r0, r4, #0
	bl FUN_080a04c8
	cmp r0, #0
	beq _080A053E
	adds r0, r4, #0
	movs r1, #0x40
	bl FUN_080a02f8
	b _080A05E0
_080A053E:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A05E0
	ldrb r1, [r4, #0x1c]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080A055C
	ldrh r1, [r4, #0x2a]
	movs r0, #0x40
	orrs r0, r1
	strh r0, [r4, #0x2a]
	b _080A056E
_080A055C:
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_082342a8
	strb r5, [r4, #0x1d]
	ldr r0, _080A057C @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807a334
_080A056E:
	ldr r0, [r4, #0x34]
	cmp r0, #0
	beq _080A05E0
	movs r1, #0
	bl Script_ExecById
	b _080A05E0
	.align 2, 0
_080A057C: .4byte 0x03002BE0
_080A0580:
	adds r0, r4, #0
	bl FUN_080a04c8
	cmp r0, #0
	beq _080A05BC
	adds r0, r4, #0
	movs r1, #0x40
	bl FUN_080a0104
	cmp r0, #0
	beq _080A05BC
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080A05E0
	adds r0, r4, #0
	adds r0, #0x24
	ldrh r1, [r4, #0x1e]
	ldrh r3, [r4, #0x20]
	movs r2, #0xff
	str r2, [sp]
	ldr r2, _080A05B8 @ =0x0000082A
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_08234270
	movs r0, #1
	strb r0, [r4, #0x1d]
	b _080A05E0
	.align 2, 0
_080A05B8: .4byte 0x0000082A
_080A05BC:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A05E0
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_082342a8
	movs r0, #0
	strb r0, [r4, #0x1d]
	b _080A05E0
_080A05D0:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A05E0
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_082342a8
	strb r5, [r4, #0x1d]
_080A05E0:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a05e8
FUN_080a05e8: @ 0x080A05E8
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A0608 @ =0x03002BE0
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080A0602
	ldr r1, [r2, #0x38]
	adds r0, r2, #0
	bl _call_via_r1
_080A0602:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080A0608: .4byte 0x03002BE0

	thumb_func_start FUN_080a060c
FUN_080a060c: @ 0x080A060C
	push {lr}
	adds r2, r0, #0
	ldrb r1, [r2, #0x1d]
	cmp r1, #0
	beq _080A061C
	adds r0, #0x24
	bl FUN_082342a8
_080A061C:
	pop {r1}
	bx r1

	thumb_func_start FUN_080a0620
FUN_080a0620: @ 0x080A0620
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0
	strh r1, [r5, #0x18]
	strb r0, [r5, #0x1d]
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A063C
	bl Script_GetValue
	b _080A063E
_080A063C:
	movs r0, #9
_080A063E:
	strb r0, [r5, #0x1c]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A0688
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080A0680 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080A0684 @ =0x0000FFFF
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
	b _080A0692
	.align 2, 0
_080A0680: .4byte 0xFFFF0000
_080A0684: .4byte 0x0000FFFF
_080A0688:
	ldr r1, _080A06C0 @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_080A0692:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A06BA
	cmp r1, #0
	blt _080A06BA
	ldr r0, _080A06C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A06BA
	ldr r0, _080A06C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A06CC
_080A06BA:
	movs r0, #0
	b _080A06DA
	.align 2, 0
_080A06C0: .4byte 0xFFFF0000
_080A06C4: .4byte 0x030046A8
_080A06C8: .4byte 0x030046AC
_080A06CC:
	ldr r0, _080A0704 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A06DA:
	strh r0, [r5, #0x1e]
	mov r0, sp
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	strh r0, [r5, #0x20]
	movs r0, #0x52
	bl prepare_08231510
	cmp r0, #0
	beq _080A06F4
	bl Script_GetValue
_080A06F4:
	str r0, [r5, #0x34]
	ldrb r1, [r5, #0x1c]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080A070C
	ldr r0, _080A0708 @ =FUN_080a01d8
	b _080A071E
	.align 2, 0
_080A0704: .4byte 0x030046A4
_080A0708: .4byte FUN_080a01d8
_080A070C:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080A071C
	ldr r0, _080A0718 @ =FUN_080a035c
	b _080A071E
	.align 2, 0
_080A0718: .4byte FUN_080a035c
_080A071C:
	ldr r0, _080A072C @ =FUN_080a0510
_080A071E:
	str r0, [r5, #0x38]
	movs r0, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A072C: .4byte FUN_080a0510

	thumb_func_start FUN_080a0730
FUN_080a0730: @ 0x080A0730
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #8
	movs r1, #0x3c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A076C
	ldr r1, _080A0764 @ =FUN_080a05e8
	ldr r2, _080A0768 @ =FUN_080a060c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a0620
	cmp r0, #0
	bge _080A076C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A076E
	.align 2, 0
_080A0764: .4byte FUN_080a05e8
_080A0768: .4byte FUN_080a060c
_080A076C:
	adds r0, r4, #0
_080A076E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a0774
FUN_080a0774: @ 0x080A0774
	push {lr}
	ldr r3, _080A0790 @ =0x03002C3C
	ldr r1, [r3]
	cmp r1, #0
	beq _080A078A
	adds r1, #0x36
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r3]
	strh r2, [r0, #0x34]
_080A078A:
	pop {r0}
	bx r0
	.align 2, 0
_080A0790: .4byte 0x03002C3C

	thumb_func_start FUN_080a0794
FUN_080a0794: @ 0x080A0794
	push {lr}
	ldr r2, _080A07B0 @ =0x03002C3C
	ldr r1, [r2]
	cmp r1, #0
	beq _080A07AA
	adds r1, #0x36
	movs r0, #0
	strb r0, [r1]
	ldr r1, [r2]
	movs r0, #8
	strh r0, [r1, #0x34]
_080A07AA:
	pop {r0}
	bx r0
	.align 2, 0
_080A07B0: .4byte 0x03002C3C

	thumb_func_start FUN_080a07b4
FUN_080a07b4: @ 0x080A07B4
	push {lr}
	bl FUN_080a0774
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a07c0
FUN_080a07c0: @ 0x080A07C0
	push {lr}
	bl FUN_080a0794
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a07cc
FUN_080a07cc: @ 0x080A07CC
	push {r4, lr}
	ldr r0, _080A07EC @ =0x03002C3C
	ldr r4, [r0]
	cmp r4, #0
	beq _080A07E6
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	bne _080A07E6
	adds r0, r4, #0
	bl FUN_080a0844
	movs r0, #1
	strb r0, [r4, #0x1f]
_080A07E6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A07EC: .4byte 0x03002C3C

	thumb_func_start FUN_080a07f0
FUN_080a07f0: @ 0x080A07F0
	push {lr}
	ldr r0, _080A0804 @ =0x03002C3C
	ldr r1, [r0]
	cmp r1, #0
	beq _080A07FE
	movs r0, #0
	strb r0, [r1, #0x1f]
_080A07FE:
	pop {r0}
	bx r0
	.align 2, 0
_080A0804: .4byte 0x03002C3C

	thumb_func_start FUN_080a0808
FUN_080a0808: @ 0x080A0808
	push {lr}
	ldr r0, _080A0828 @ =0x03002B80
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #1
	bne _080A0816
	movs r1, #1
_080A0816:
	cmp r1, #0
	bne _080A0830
	ldr r0, _080A082C @ =0x03002C3C
	ldr r0, [r0]
	cmp r0, #0
	beq _080A0830
	ldrb r0, [r0, #0x1f]
	b _080A0832
	.align 2, 0
_080A0828: .4byte 0x03002B80
_080A082C: .4byte 0x03002C3C
_080A0830:
	movs r0, #0
_080A0832:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a0838
FUN_080a0838: @ 0x080A0838
	push {lr}
	bl FUN_080a0808
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a0844
FUN_080a0844: @ 0x080A0844
	ldr r1, _080A085C @ =0x030046A0
	ldr r1, [r1]
	ldr r2, _080A0860 @ =0x00000932
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #0
	strh r1, [r0, #0x30]
	movs r1, #0x96
	lsls r1, r1, #1
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	bx lr
	.align 2, 0
_080A085C: .4byte 0x030046A0
_080A0860: .4byte 0x00000932

	thumb_func_start FUN_080a0864
FUN_080a0864: @ 0x080A0864
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A0884 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A08C0
	ldr r0, _080A0888 @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	bne _080A088C
	movs r1, #1
	rsbs r1, r1, #0
	b _080A0890
	.align 2, 0
_080A0884: .4byte 0x030047A4
_080A0888: .4byte 0x03002C68
_080A088C:
	movs r2, #0x18
	ldrsh r1, [r1, r2]
_080A0890:
	ldr r0, [r0]
	cmp r0, #0
	bne _080A089A
	movs r0, #0
	b _080A08A0
_080A089A:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080A08A0:
	cmp r0, #0
	beq _080A08A8
	movs r0, #0
	b _080A08B6
_080A08A8:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	bne _080A090E
	adds r0, r4, #0
	bl FUN_080a0844
	movs r0, #1
_080A08B6:
	strb r0, [r4, #0x1f]
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	bne _080A090E
	b _080A0920
_080A08C0:
	ldr r0, _080A08E4 @ =0x03002B80
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #1
	bne _080A08CC
	movs r2, #1
_080A08CC:
	cmp r2, #0
	beq _080A08E8
	adds r0, r4, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _080A0902
	movs r0, #1
	strb r0, [r5]
	b _080A0902
	.align 2, 0
_080A08E4: .4byte 0x03002B80
_080A08E8:
	adds r0, r4, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	beq _080A0902
	strb r2, [r5]
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _080A0920
	adds r0, r4, #0
	bl FUN_080a0844
_080A0902:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _080A0920
	ldrb r0, [r5]
	cmp r0, #0
	bne _080A0920
_080A090E:
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080A091C @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080A092A
	.align 2, 0
_080A091C: .4byte 0x03003E78
_080A0920:
	ldr r0, _080A0930 @ =0x03003E78
	ldr r1, _080A0934 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080A092A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A0930: .4byte 0x03003E78
_080A0934: .4byte 0xFFFFFDFF

	thumb_func_start FUN_080a0938
FUN_080a0938: @ 0x080A0938
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x36
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A09B0
	ldrh r0, [r7, #0x34]
	cmp r0, #6
	bhi _080A0998
	adds r0, #1
	strh r0, [r7, #0x34]
	ldrh r0, [r7, #0x34]
	movs r4, #8
	subs r4, r4, r0
	adds r6, r4, #1
	movs r1, #0x28
	ldrsh r0, [r7, r1]
	muls r0, r4, r0
	ldr r5, _080A0994 @ =0x03003540
	movs r2, #0
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r7, #0x28]
	movs r3, #0x2a
	ldrsh r0, [r7, r3]
	muls r0, r4, r0
	movs r2, #2
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r7, #0x2a]
	movs r3, #0x2c
	ldrsh r0, [r7, r3]
	muls r0, r4, r0
	movs r4, #4
	ldrsh r1, [r5, r4]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	b _080A0CFE
	.align 2, 0
_080A0994: .4byte 0x03003540
_080A0998:
	movs r0, #8
	strh r0, [r7, #0x34]
	ldr r1, _080A09AC @ =0x03003540
	ldrh r0, [r1]
	strh r0, [r7, #0x28]
	ldrh r0, [r1, #2]
	strh r0, [r7, #0x2a]
	ldrh r0, [r1, #4]
	b _080A0CFE
	.align 2, 0
_080A09AC: .4byte 0x03003540
_080A09B0:
	ldr r1, _080A09EC @ =0x03002BE0
	ldrb r2, [r7, #0x1e]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r4, _080A09F0 @ =0x000003CE
	adds r0, r3, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r6, r1, #0
	mov ip, r2
	cmp r0, #0
	bne _080A09CC
	b _080A0AC8
_080A09CC:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _080A09FC
	ldr r0, _080A09F4 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080A09F8 @ =0x00000932
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	b _080A0A06
	.align 2, 0
_080A09EC: .4byte 0x03002BE0
_080A09F0: .4byte 0x000003CE
_080A09F4: .4byte 0x030046A0
_080A09F8: .4byte 0x00000932
_080A09FC:
	ldr r0, _080A0A80 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _080A0A84 @ =0x00000932
	adds r0, r0, r3
	ldrh r0, [r0]
_080A0A06:
	strh r0, [r7, #0x30]
	ldrh r0, [r7, #0x34]
	cmp r0, #6
	bhi _080A0A8C
	adds r0, #1
	strh r0, [r7, #0x34]
	ldrh r0, [r7, #0x34]
	movs r4, #8
	subs r4, r4, r0
	adds r5, r4, #1
	movs r1, #0x28
	ldrsh r0, [r7, r1]
	muls r0, r4, r0
	mov r2, ip
	lsls r1, r2, #2
	adds r1, r1, r6
	ldr r1, [r1]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r1, r1, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r5, #0
	bl Div
	strh r0, [r7, #0x28]
	movs r3, #0x2a
	ldrsh r0, [r7, r3]
	muls r0, r4, r0
	ldrb r1, [r7, #0x1e]
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r1, [r1]
	ldr r2, _080A0A88 @ =0x000003C2
	adds r1, r1, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	adds r1, r5, #0
	bl Div
	strh r0, [r7, #0x2a]
	movs r1, #0x2c
	ldrsh r0, [r7, r1]
	muls r0, r4, r0
	ldrb r1, [r7, #0x1e]
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r1, [r1]
	movs r2, #0xf1
	lsls r2, r2, #2
	adds r1, r1, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	adds r1, r5, #0
	bl Div
	b _080A0CFE
	.align 2, 0
_080A0A80: .4byte 0x030046A0
_080A0A84: .4byte 0x00000932
_080A0A88: .4byte 0x000003C2
_080A0A8C:
	movs r0, #8
	strh r0, [r7, #0x34]
	mov r4, ip
	lsls r0, r4, #2
	adds r0, r0, r6
	ldr r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r7, #0x28]
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldr r2, _080A0AC4 @ =0x000003C2
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r7, #0x2a]
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	movs r3, #0xf1
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	b _080A0CFE
	.align 2, 0
_080A0AC4: .4byte 0x000003C2
_080A0AC8:
	ldr r2, _080A0B00 @ =0x030046A0
	ldr r0, [r2]
	ldr r4, _080A0B04 @ =0x00000932
	adds r0, r0, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrh r4, [r7, #0x30]
	ldr r3, _080A0B08 @ =0xFFFFFF00
	adds r0, r4, r3
	subs r1, r1, r0
	movs r0, #0xff
	ands r1, r0
	movs r0, #0x80
	subs r0, r0, r1
	adds r3, r0, #0
	cmp r0, #0
	bge _080A0AEC
	rsbs r3, r0, #0
_080A0AEC:
	cmp r3, #0x10
	bgt _080A0B4C
	cmp r1, #0x80
	beq _080A0B1C
	cmp r1, #0x7f
	bgt _080A0B0C
	asrs r0, r0, #2
	adds r1, r0, #1
	adds r0, r4, r1
	b _080A0B16
	.align 2, 0
_080A0B00: .4byte 0x030046A0
_080A0B04: .4byte 0x00000932
_080A0B08: .4byte 0xFFFFFF00
_080A0B0C:
	adds r0, r1, #0
	subs r0, #0x80
	asrs r0, r0, #2
	subs r0, r4, r0
	adds r0, #0xff
_080A0B16:
	movs r1, #0xff
	ands r0, r1
	strh r0, [r7, #0x30]
_080A0B1C:
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r0, _080A0B44 @ =0xFFFFFED4
	adds r1, r1, r0
	asrs r1, r1, #2
	strh r1, [r7, #0x32]
	lsls r0, r1, #0x10
	cmp r0, #0
	bge _080A0B88
	rsbs r0, r1, #0
	strh r0, [r7, #0x32]
	ldr r0, [r2]
	ldr r1, _080A0B48 @ =0x00000932
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r7, #0x30]
	b _080A0B88
	.align 2, 0
_080A0B44: .4byte 0xFFFFFED4
_080A0B48: .4byte 0x00000932
_080A0B4C:
	cmp r1, #0
	beq _080A0B70
	cmp r1, #0x7f
	bgt _080A0B5C
	asrs r0, r1, #2
	adds r1, r0, #1
	adds r0, r4, r1
	b _080A0B6A
_080A0B5C:
	movs r0, #0x80
	lsls r0, r0, #1
	subs r1, r0, r1
	asrs r1, r1, #2
	adds r1, #1
	adds r0, r4, r0
	subs r0, r0, r1
_080A0B6A:
	movs r1, #0xff
	ands r0, r1
	strh r0, [r7, #0x30]
_080A0B70:
	movs r2, #0x32
	ldrsh r1, [r7, r2]
	ldr r0, _080A0BB4 @ =0x0000012B
	cmp r1, r0
	bgt _080A0B88
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r0, r4
	asrs r0, r0, #2
	strh r0, [r7, #0x32]
_080A0B88:
	ldrh r0, [r7, #0x34]
	adds r3, r0, #0
	cmp r3, #1
	bls _080A0C6C
	ldr r2, _080A0BB8 @ =0x085B0A08
	ldrh r0, [r7, #0x30]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080A0BBC
	asrs r1, r0, #0xc
	b _080A0BC2
	.align 2, 0
_080A0BB4: .4byte 0x0000012B
_080A0BB8: .4byte 0x085B0A08
_080A0BBC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0BC2:
	mov r2, ip
	lsls r0, r2, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0, #0x2c]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	ldr r1, _080A0C0C @ =0x0000097A
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x80
	subs r0, r0, r1
	movs r1, #0x96
	muls r0, r1, r0
	asrs r0, r0, #7
	ldrh r2, [r2, #0x2e]
	adds r0, r0, r2
	strh r0, [r7, #0x22]
	ldrh r1, [r7, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A0C10
	asrs r1, r0, #0xc
	b _080A0C16
	.align 2, 0
_080A0C0C: .4byte 0x0000097A
_080A0C10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0C16:
	mov r2, ip
	lsls r0, r2, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0, #0x30]
	adds r0, r0, r1
	strh r0, [r7, #0x24]
	subs r0, r3, #1
	strh r0, [r7, #0x34]
	ldrh r1, [r7, #0x34]
	adds r4, r1, #1
	movs r3, #0x28
	ldrsh r0, [r7, r3]
	muls r0, r1, r0
	movs r2, #0x20
	ldrsh r1, [r7, r2]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	strh r0, [r7, #0x28]
	movs r3, #0x2a
	ldrsh r1, [r7, r3]
	ldrh r0, [r7, #0x34]
	muls r0, r1, r0
	movs r2, #0x22
	ldrsh r1, [r7, r2]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	strh r0, [r7, #0x2a]
	movs r3, #0x2c
	ldrsh r1, [r7, r3]
	ldrh r0, [r7, #0x34]
	muls r0, r1, r0
	movs r2, #0x24
	ldrsh r1, [r7, r2]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	b _080A0CFE
_080A0C6C:
	movs r0, #0
	strh r0, [r7, #0x34]
	ldr r2, _080A0C94 @ =0x085B0A08
	ldrh r0, [r7, #0x30]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080A0C98
	asrs r1, r0, #0xc
	b _080A0C9E
	.align 2, 0
_080A0C94: .4byte 0x085B0A08
_080A0C98:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0C9E:
	mov r2, ip
	lsls r0, r2, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0, #0x2c]
	adds r0, r0, r1
	strh r0, [r7, #0x28]
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	ldr r3, _080A0CE8 @ =0x0000097A
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, #0x80
	subs r0, r0, r1
	movs r1, #0x96
	muls r0, r1, r0
	asrs r0, r0, #7
	ldrh r2, [r2, #0x2e]
	adds r0, r0, r2
	strh r0, [r7, #0x2a]
	ldrh r1, [r7, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r2, #0x32
	ldrsh r0, [r7, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A0CEC
	asrs r1, r0, #0xc
	b _080A0CF2
	.align 2, 0
_080A0CE8: .4byte 0x0000097A
_080A0CEC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0CF2:
	mov r3, ip
	lsls r0, r3, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0, #0x30]
	adds r0, r0, r1
_080A0CFE:
	strh r0, [r7, #0x2c]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a0d08
FUN_080a0d08: @ 0x080A0D08
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_080a0864
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _080A0DDC
	adds r0, r4, #0
	bl FUN_080a0938
	add r5, sp, #4
	adds r6, r4, #0
	adds r6, #0x28
	ldrh r0, [r4, #0x28]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A0D40
	asrs r0, r0, #8
	b _080A0D46
_080A0D40:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A0D46:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A0D58
	asrs r0, r0, #8
	b _080A0D5E
_080A0D58:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A0D5E:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080A0D72
	asrs r1, r0, #8
	b _080A0D78
_080A0D72:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_080A0D78:
	subs r0, r2, r1
	strh r0, [r5, #2]
	adds r0, r2, r1
	strh r0, [r5, #4]
	ldr r2, _080A0DAC @ =0x030047C8
	movs r3, #0
	ldrsh r1, [r2, r3]
	add r0, sp, #4
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r4, r1, r0
	adds r3, r4, #0
	adds r3, #0x80
	movs r1, #2
	ldrsh r0, [r2, r1]
	add r1, sp, #4
	movs r2, #2
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	adds r5, r0, #0
	adds r5, #0x80
	cmp r4, #0
	blt _080A0DB0
	asrs r1, r4, #3
	b _080A0DB6
	.align 2, 0
_080A0DAC: .4byte 0x030047C8
_080A0DB0:
	rsbs r0, r4, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080A0DB6:
	adds r0, r5, #0
	subs r0, #0x80
	cmp r0, #0
	blt _080A0DC2
	asrs r2, r0, #3
	b _080A0DC8
_080A0DC2:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r2, r0, #0
_080A0DC8:
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	subs r3, #0x78
	adds r0, r5, #0
	subs r0, #0x5a
	str r0, [sp]
	movs r0, #1
	bl Video_GenerateBGMap
_080A0DDC:
	movs r0, #0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a0de8
FUN_080a0de8: @ 0x080A0DE8
	ldr r1, _080A0DF0 @ =0x03002C3C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080A0DF0: .4byte 0x03002C3C

	thumb_func_start FUN_080a0df4
FUN_080a0df4: @ 0x080A0DF4
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080A0E48 @ =0x0000C091
	ldr r1, _080A0E4C @ =0x00000B12
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x18]
	movs r0, #0
	str r0, [sp, #0xc]
	str r0, [sp]
	movs r5, #1
	str r5, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #2
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #1
	movs r1, #1
	bl SetBGPrioDirect
	ldr r0, _080A0E50 @ =0x03002B80
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #1
	bne _080A0E32
	movs r1, #1
_080A0E32:
	cmp r1, #0
	beq _080A0E5C
	ldr r2, _080A0E54 @ =0x03003E78
	ldr r0, _080A0E58 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0x37
	strb r5, [r0]
	b _080A0E86
	.align 2, 0
_080A0E48: .4byte 0x0000C091
_080A0E4C: .4byte 0x00000B12
_080A0E50: .4byte 0x03002B80
_080A0E54: .4byte 0x03003E78
_080A0E58: .4byte 0xFFFFFDFF
_080A0E5C:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _080A0E74
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080A0E70 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080A0E7E
	.align 2, 0
_080A0E70: .4byte 0x03003E78
_080A0E74:
	ldr r0, _080A0E90 @ =0x03003E78
	ldr r1, _080A0E94 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080A0E7E:
	adds r1, r4, #0
	adds r1, #0x37
	movs r0, #0
	strb r0, [r1]
_080A0E86:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A0E90: .4byte 0x03003E78
_080A0E94: .4byte 0xFFFFFDFF

	thumb_func_start FUN_080a0e98
FUN_080a0e98: @ 0x080A0E98
	push {r4, lr}
	adds r4, r0, #0
	strh r1, [r4, #0x1c]
	strb r2, [r4, #0x1e]
	strb r3, [r4, #0x1f]
	bl FUN_080a0df4
	adds r0, r4, #0
	bl FUN_080a0844
	ldr r2, _080A0ECC @ =0x085B0A08
	ldrh r0, [r4, #0x30]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A0ED0
	asrs r1, r0, #0xc
	b _080A0ED6
	.align 2, 0
_080A0ECC: .4byte 0x085B0A08
_080A0ED0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0ED6:
	ldr r3, _080A0F24 @ =0x03002BE0
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrh r0, [r0, #0x2c]
	subs r0, r0, r1
	strh r0, [r4, #0x28]
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r2, [r0]
	ldr r1, _080A0F28 @ =0x0000097A
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x80
	subs r0, r0, r1
	movs r1, #0x96
	muls r0, r1, r0
	asrs r0, r0, #7
	ldrh r2, [r2, #0x2e]
	adds r0, r0, r2
	strh r0, [r4, #0x2a]
	ldr r2, _080A0F2C @ =0x085B0A08
	ldrh r1, [r4, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	muls r0, r1, r0
	ldrb r2, [r4, #0x1e]
	cmp r0, #0
	blt _080A0F30
	asrs r1, r0, #0xc
	b _080A0F36
	.align 2, 0
_080A0F24: .4byte 0x03002BE0
_080A0F28: .4byte 0x0000097A
_080A0F2C: .4byte 0x085B0A08
_080A0F30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0F36:
	lsls r0, r2, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrh r0, [r0, #0x30]
	subs r0, r0, r1
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl FUN_080a0d08
	ldr r0, _080A0F54 @ =0x03002C3C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A0F54: .4byte 0x03002C3C

	thumb_func_start FUN_080a0f58
FUN_080a0f58: @ 0x080A0F58
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r0, _080A0F98 @ =0x03002C3C
	ldr r4, [r0]
	cmp r4, #0
	bne _080A0FA4
	movs r0, #9
	movs r1, #0x38
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A0FA4
	ldr r1, _080A0F9C @ =FUN_080a0d08
	ldr r2, _080A0FA0 @ =FUN_080a0de8
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_080a0e98
	cmp r0, #0
	bge _080A0FA4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A0FA6
	.align 2, 0
_080A0F98: .4byte 0x03002C3C
_080A0F9C: .4byte FUN_080a0d08
_080A0FA0: .4byte FUN_080a0de8
_080A0FA4:
	adds r0, r4, #0
_080A0FA6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a0fac
FUN_080a0fac: @ 0x080A0FAC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080A0FCC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A0FDA
	ldr r0, _080A0FD0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080A0FD4
	movs r4, #1
	rsbs r4, r4, #0
	b _080A0FEE
	.align 2, 0
_080A0FCC: .4byte 0x030047A4
_080A0FD0: .4byte 0x03002C68
_080A0FD4:
	movs r1, #0x18
	ldrsh r4, [r0, r1]
	b _080A0FEE
_080A0FDA:
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _080A0FEC
	bl Script_GetValue
	adds r4, r0, #0
	b _080A0FEE
_080A0FEC:
	movs r4, #0
_080A0FEE:
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A1000
	bl Script_GetValue
	adds r2, r0, #0
	b _080A1002
_080A1000:
	movs r2, #1
_080A1002:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080a0f58
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a1010
FUN_080a1010: @ 0x080A1010
	push {r4, lr}
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _080A1024
	bl Script_GetValue
	adds r1, r0, #0
	b _080A1028
_080A1024:
	movs r1, #0xe1
	lsls r1, r1, #3
_080A1028:
	ldr r4, _080A1054 @ =0x03002C40
	ldr r0, [r4]
	strh r1, [r0, #0x18]
	lsls r0, r1, #0x10
	cmp r0, #0
	beq _080A104E
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	bne _080A1046
	movs r0, #0x49
	movs r1, #0
	bl TryAddItem
_080A1046:
	ldr r0, [r4]
	adds r0, #0x18
	bl FUN_0809c544
_080A104E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A1054: .4byte 0x03002C40

	thumb_func_start FUN_080a1058
FUN_080a1058: @ 0x080A1058
	push {lr}
	ldr r0, _080A1068 @ =0x03002C40
	ldr r0, [r0]
	cmp r0, #0
	beq _080A106C
	ldrh r0, [r0, #0x18]
	b _080A106E
	.align 2, 0
_080A1068: .4byte 0x03002C40
_080A106C:
	movs r0, #0
_080A106E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a1074
FUN_080a1074: @ 0x080A1074
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	bne _080A109C
	movs r2, #0x80
	lsls r2, r2, #5
	ldr r0, _080A1094 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A1098 @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	orrs r2, r1
	strh r2, [r0]
	b _080A10D8
	.align 2, 0
_080A1094: .4byte 0x030046A0
_080A1098: .4byte 0x00000934
_080A109C:
	ldr r0, _080A10E0 @ =0x030046A0
	ldr r1, [r0]
	ldr r0, _080A10E4 @ =0x00000934
	adds r1, r1, r0
	ldr r0, _080A10E8 @ =0xFFFFEFFF
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	ldrh r0, [r4, #0x18]
	subs r0, #1
	strh r0, [r4, #0x18]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080A10D8
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	beq _080A10C8
	movs r0, #0x49
	bl RemoveSpecifiedItem
_080A10C8:
	bl FUN_0809c58c
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _080A10D8
	movs r1, #0
	bl Script_ExecById
_080A10D8:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A10E0: .4byte 0x030046A0
_080A10E4: .4byte 0x00000934
_080A10E8: .4byte 0xFFFFEFFF

	thumb_func_start FUN_080a10ec
FUN_080a10ec: @ 0x080A10EC
	push {lr}
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	beq _080A10FE
	movs r0, #0x49
	bl RemoveSpecifiedItem
_080A10FE:
	ldr r1, _080A1108 @ =0x03002C40
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_080A1108: .4byte 0x03002C40

	thumb_func_start FUN_080a110c
FUN_080a110c: @ 0x080A110C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _080A1120
	bl Script_GetValue
	b _080A1124
_080A1120:
	movs r0, #0xe1
	lsls r0, r0, #3
_080A1124:
	strh r0, [r4, #0x18]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A1134
	bl Script_GetValue
_080A1134:
	str r0, [r4, #0x1c]
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	beq _080A1156
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	bne _080A114E
	movs r0, #0x49
	movs r1, #0
	bl TryAddItem
_080A114E:
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0809c544
_080A1156:
	ldr r0, _080A1164 @ =0x03002C40
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A1164: .4byte 0x03002C40

	thumb_func_start FUN_080a1168
FUN_080a1168: @ 0x080A1168
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080A11A4 @ =0x03002C40
	ldr r0, [r0]
	cmp r0, #0
	bne _080A11B2
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A11B0
	ldr r1, _080A11A8 @ =FUN_080a1074
	ldr r2, _080A11AC @ =FUN_080a10ec
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a110c
	cmp r0, #0
	bge _080A11B0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A11B2
	.align 2, 0
_080A11A4: .4byte 0x03002C40
_080A11A8: .4byte FUN_080a1074
_080A11AC: .4byte FUN_080a10ec
_080A11B0:
	adds r0, r4, #0
_080A11B2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a11b8
FUN_080a11b8: @ 0x080A11B8
	push {lr}
	ldr r0, _080A11D0 @ =0x03000148
	ldr r1, [r0]
	cmp r1, #0
	beq _080A11CC
	movs r0, #0
	strh r0, [r1, #0x1a]
	strh r0, [r1, #0x2a]
	strh r0, [r1, #0x26]
	strh r0, [r1, #0x2c]
_080A11CC:
	pop {r0}
	bx r0
	.align 2, 0
_080A11D0: .4byte 0x03000148

	thumb_func_start FUN_080a11d4
FUN_080a11d4: @ 0x080A11D4
	push {r4, lr}
	ldr r4, _080A11FC @ =0x03000148
	ldr r1, [r4]
	cmp r1, #0
	beq _080A123A
	movs r0, #1
	strh r0, [r1, #0x1a]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A1200
	bl Script_GetValue
	ldr r1, [r4]
	strh r0, [r1, #0x1c]
	bl Script_GetValue
	ldr r1, [r4]
	b _080A1206
	.align 2, 0
_080A11FC: .4byte 0x03000148
_080A1200:
	ldr r1, [r4]
	movs r0, #3
	strh r0, [r1, #0x1c]
_080A1206:
	strh r0, [r1, #0x1e]
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A1228
	bl Script_GetValue
	ldr r4, _080A1224 @ =0x03000148
	ldr r1, [r4]
	strh r0, [r1, #0x20]
	bl Script_GetValue
	ldr r1, [r4]
	b _080A1230
	.align 2, 0
_080A1224: .4byte 0x03000148
_080A1228:
	ldr r0, _080A1240 @ =0x03000148
	ldr r1, [r0]
	movs r0, #0x78
	strh r0, [r1, #0x20]
_080A1230:
	strh r0, [r1, #0x22]
	ldr r0, _080A1240 @ =0x03000148
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #0x2c]
_080A123A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A1240: .4byte 0x03000148

	thumb_func_start FUN_080a1244
FUN_080a1244: @ 0x080A1244
	push {r4, lr}
	ldr r4, _080A1268 @ =0x03000148
	ldr r1, [r4]
	cmp r1, #0
	beq _080A12CE
	movs r0, #2
	strh r0, [r1, #0x1a]
	movs r0, #0x64
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A126C
	bl Script_GetValue
	ldr r1, [r4]
	strh r0, [r1, #0x2a]
	b _080A1270
	.align 2, 0
_080A1268: .4byte 0x03000148
_080A126C:
	ldr r0, [r4]
	strh r1, [r0, #0x2a]
_080A1270:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A1290
	bl Script_GetValue
	ldr r4, _080A128C @ =0x03000148
	ldr r1, [r4]
	strh r0, [r1, #0x1c]
	bl Script_GetValue
	ldr r1, [r4]
	b _080A1298
	.align 2, 0
_080A128C: .4byte 0x03000148
_080A1290:
	ldr r0, _080A12B8 @ =0x03000148
	ldr r1, [r0]
	movs r0, #3
	strh r0, [r1, #0x1c]
_080A1298:
	strh r0, [r1, #0x1e]
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A12BC
	bl Script_GetValue
	ldr r4, _080A12B8 @ =0x03000148
	ldr r1, [r4]
	strh r0, [r1, #0x20]
	bl Script_GetValue
	ldr r1, [r4]
	b _080A12C4
	.align 2, 0
_080A12B8: .4byte 0x03000148
_080A12BC:
	ldr r0, _080A12D4 @ =0x03000148
	ldr r1, [r0]
	movs r0, #0x78
	strh r0, [r1, #0x20]
_080A12C4:
	strh r0, [r1, #0x22]
	ldr r0, _080A12D4 @ =0x03000148
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #0x2c]
_080A12CE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A12D4: .4byte 0x03000148

	thumb_func_start FUN_080a12d8
FUN_080a12d8: @ 0x080A12D8
	push {r4, lr}
	ldr r0, _080A12FC @ =0x03000148
	ldr r0, [r0]
	cmp r0, #0
	beq _080A12F4
	movs r0, #0x48
	bl prepare_08231510
	cmp r0, #0
	beq _080A12F4
	ldr r4, _080A1300 @ =0x03002B84
	bl Script_GetValue
	strh r0, [r4]
_080A12F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A12FC: .4byte 0x03000148
_080A1300: .4byte 0x03002B84

	thumb_func_start FUN_080a1304
FUN_080a1304: @ 0x080A1304
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x24]
	lsls r0, r1, #4
	subs r0, r0, r1
	ldrh r1, [r4, #0x26]
	adds r0, r0, r1
	asrs r0, r0, #4
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x2a]
	lsls r0, r0, #4
	ldrh r2, [r4, #0x28]
	ldr r3, _080A133C @ =0xFFFFF000
	adds r1, r2, r3
	subs r1, r0, r1
	ldr r3, _080A1340 @ =0x00000FFF
	ands r1, r3
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080A1344
	movs r0, #0x80
	lsls r0, r0, #5
	subs r1, r0, r1
	adds r0, r2, r0
	asrs r1, r1, #4
	subs r0, r0, r1
	b _080A1348
	.align 2, 0
_080A133C: .4byte 0xFFFFF000
_080A1340: .4byte 0x00000FFF
_080A1344:
	asrs r0, r1, #4
	adds r0, r2, r0
_080A1348:
	ands r0, r3
	strh r0, [r4, #0x28]
	ldr r1, _080A1370 @ =0x03002BAC
	ldrh r0, [r4, #0x24]
	lsrs r0, r0, #4
	strh r0, [r1]
	ldr r1, _080A1374 @ =0x03002B90
	ldrh r0, [r4, #0x28]
	lsrs r0, r0, #4
	strh r0, [r1]
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	beq _080A1378
	cmp r0, #1
	bgt _080A1368
	b _080A1470
_080A1368:
	cmp r0, #2
	beq _080A13F0
	b _080A1470
	.align 2, 0
_080A1370: .4byte 0x03002BAC
_080A1374: .4byte 0x03002B90
_080A1378:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0
	bne _080A146C
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne _080A138C
	ldrh r0, [r4, #0x1c]
	lsls r0, r0, #4
	strh r0, [r4, #0x26]
	b _080A13AE
_080A138C:
	ldr r2, _080A13D0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A13D4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _080A13D8 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	ldrh r1, [r4, #0x1e]
	bl Mod
	ldrh r1, [r4, #0x1c]
	adds r1, r1, r0
	lsls r1, r1, #4
	strh r1, [r4, #0x26]
_080A13AE:
	ldr r2, _080A13D0 @ =0x030046B8
	ldr r0, [r2]
	adds r1, r0, #1
	ldr r3, _080A13D4 @ =0x000003FF
	ands r1, r3
	str r1, [r2]
	lsls r0, r1, #1
	ldr r5, _080A13D8 @ =0x0203B400
	adds r0, r0, r5
	ldrb r0, [r0]
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	bne _080A13DC
	ldrh r0, [r4, #0x20]
	b _080A146E
	.align 2, 0
_080A13D0: .4byte 0x030046B8
_080A13D4: .4byte 0x000003FF
_080A13D8: .4byte 0x0203B400
_080A13DC:
	adds r0, r1, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080A13EC @ =0x0203B400
	adds r0, r0, r1
	b _080A144E
	.align 2, 0
_080A13EC: .4byte 0x0203B400
_080A13F0:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0
	bne _080A146C
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne _080A1404
	ldrh r0, [r4, #0x1c]
	lsls r0, r0, #4
	strh r0, [r4, #0x26]
	b _080A1426
_080A1404:
	ldr r2, _080A1430 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A1434 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080A1438 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r4, #0x1e]
	bl Mod
	ldrh r1, [r4, #0x1c]
	adds r1, r1, r0
	lsls r1, r1, #4
	strh r1, [r4, #0x26]
_080A1426:
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	bne _080A143C
	ldrh r0, [r4, #0x20]
	b _080A146E
	.align 2, 0
_080A1430: .4byte 0x030046B8
_080A1434: .4byte 0x000003FF
_080A1438: .4byte 0x0203B400
_080A143C:
	ldr r2, _080A1460 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A1464 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _080A1468 @ =0x0203B400
	adds r0, r0, r5
_080A144E:
	ldrh r0, [r0]
	ldrh r1, [r4, #0x22]
	bl Mod
	ldrh r1, [r4, #0x20]
	adds r1, r1, r0
	strh r1, [r4, #0x2c]
	b _080A1470
	.align 2, 0
_080A1460: .4byte 0x030046B8
_080A1464: .4byte 0x000003FF
_080A1468: .4byte 0x0203B400
_080A146C:
	subs r0, #1
_080A146E:
	strh r0, [r4, #0x2c]
_080A1470:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a1478
FUN_080a1478: @ 0x080A1478
	ldr r0, _080A1490 @ =0x03002B84
	movs r1, #0
	strh r1, [r0]
	ldr r0, _080A1494 @ =0x03002BAC
	strh r1, [r0]
	ldr r0, _080A1498 @ =0x03002B90
	strh r1, [r0]
	ldr r1, _080A149C @ =0x03000148
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080A1490: .4byte 0x03002B84
_080A1494: .4byte 0x03002BAC
_080A1498: .4byte 0x03002B90
_080A149C: .4byte 0x03000148

	thumb_func_start FUN_080a14a0
FUN_080a14a0: @ 0x080A14A0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	strh r1, [r5, #0x18]
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A14B6
	bl Script_GetValue
	b _080A14B8
_080A14B6:
	movs r0, #1
_080A14B8:
	strh r0, [r5, #0x1a]
	movs r0, #0x48
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080A14D8
	ldr r4, _080A14D4 @ =0x03002B84
	bl Script_GetValue
	adds r1, r0, #0
	strh r1, [r4]
	b _080A14DC
	.align 2, 0
_080A14D4: .4byte 0x03002B84
_080A14D8:
	ldr r1, _080A14EC @ =0x03002B84
	strh r2, [r1]
_080A14DC:
	ldrh r1, [r5, #0x1a]
	cmp r1, #1
	beq _080A14FC
	cmp r1, #1
	bgt _080A14F0
	cmp r1, #0
	beq _080A14F6
	b _080A164A
	.align 2, 0
_080A14EC: .4byte 0x03002B84
_080A14F0:
	cmp r1, #2
	beq _080A1598
	b _080A164A
_080A14F6:
	strh r1, [r5, #0x2a]
	strh r1, [r5, #0x26]
	b _080A164A
_080A14FC:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A1512
	bl Script_GetValue
	strh r0, [r5, #0x1c]
	bl Script_GetValue
	b _080A1516
_080A1512:
	movs r0, #3
	strh r0, [r5, #0x1c]
_080A1516:
	strh r0, [r5, #0x1e]
	movs r0, #0x74
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A1532
	bl Script_GetValue
	strh r0, [r5, #0x20]
	bl Script_GetValue
	adds r1, r0, #0
	b _080A1536
_080A1532:
	movs r1, #0x78
	strh r1, [r5, #0x20]
_080A1536:
	strh r1, [r5, #0x22]
	ldr r3, _080A1558 @ =0x030046B8
	ldr r1, [r3]
	adds r2, r1, #1
	ldr r4, _080A155C @ =0x000003FF
	ands r2, r4
	str r2, [r3]
	lsls r1, r2, #1
	ldr r6, _080A1560 @ =0x0203B400
	adds r1, r1, r6
	ldrb r1, [r1]
	strh r1, [r5, #0x2a]
	ldrh r1, [r5, #0x1e]
	cmp r1, #0
	bne _080A1564
	ldrh r1, [r5, #0x1c]
	b _080A157E
	.align 2, 0
_080A1558: .4byte 0x030046B8
_080A155C: .4byte 0x000003FF
_080A1560: .4byte 0x0203B400
_080A1564:
	adds r0, r2, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _080A1594 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r5, #0x1e]
	bl Mod
	adds r2, r0, #0
	ldrh r1, [r5, #0x1c]
	adds r1, r1, r2
_080A157E:
	lsls r1, r1, #4
	strh r1, [r5, #0x26]
	ldrh r1, [r5, #0x1c]
	lsls r1, r1, #4
	strh r1, [r5, #0x24]
	ldrh r1, [r5, #0x22]
	cmp r1, #0
	bne _080A1628
	ldrh r1, [r5, #0x20]
	b _080A1648
	.align 2, 0
_080A1594: .4byte 0x0203B400
_080A1598:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _080A15A6
	bl Script_GetValue
_080A15A6:
	strh r0, [r5, #0x2a]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A15BE
	bl Script_GetValue
	strh r0, [r5, #0x1c]
	bl Script_GetValue
	b _080A15C2
_080A15BE:
	movs r0, #3
	strh r0, [r5, #0x1c]
_080A15C2:
	strh r0, [r5, #0x1e]
	movs r0, #0x74
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A15DE
	bl Script_GetValue
	strh r0, [r5, #0x20]
	bl Script_GetValue
	adds r1, r0, #0
	b _080A15E2
_080A15DE:
	movs r1, #0x78
	strh r1, [r5, #0x20]
_080A15E2:
	strh r1, [r5, #0x22]
	ldrh r1, [r5, #0x1e]
	cmp r1, #0
	bne _080A15EE
	ldrh r1, [r5, #0x1c]
	b _080A160E
_080A15EE:
	ldr r2, _080A161C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A1620 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080A1624 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r5, #0x1e]
	bl Mod
	adds r2, r0, #0
	ldrh r1, [r5, #0x1c]
	adds r1, r1, r2
_080A160E:
	lsls r1, r1, #4
	strh r1, [r5, #0x26]
	ldrh r1, [r5, #0x22]
	cmp r1, #0
	bne _080A1628
	ldrh r1, [r5, #0x20]
	b _080A1648
	.align 2, 0
_080A161C: .4byte 0x030046B8
_080A1620: .4byte 0x000003FF
_080A1624: .4byte 0x0203B400
_080A1628:
	ldr r2, _080A1654 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A1658 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r6, _080A165C @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	ldrh r1, [r5, #0x22]
	bl Mod
	adds r2, r0, #0
	ldrh r1, [r5, #0x20]
	adds r1, r1, r2
_080A1648:
	strh r1, [r5, #0x2c]
_080A164A:
	ldr r1, _080A1660 @ =0x03000148
	str r5, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A1654: .4byte 0x030046B8
_080A1658: .4byte 0x000003FF
_080A165C: .4byte 0x0203B400
_080A1660: .4byte 0x03000148

	thumb_func_start FUN_080a1664
FUN_080a1664: @ 0x080A1664
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080A169C @ =0x03000148
	ldr r0, [r0]
	cmp r0, #0
	bne _080A16AA
	movs r0, #9
	movs r1, #0x30
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A16A8
	ldr r1, _080A16A0 @ =FUN_080a1304
	ldr r2, _080A16A4 @ =FUN_080a1478
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a14a0
	cmp r0, #0
	bge _080A16A8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A16AA
	.align 2, 0
_080A169C: .4byte 0x03000148
_080A16A0: .4byte FUN_080a1304
_080A16A4: .4byte FUN_080a1478
_080A16A8:
	adds r0, r4, #0
_080A16AA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a16b0
FUN_080a16b0: @ 0x080A16B0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A16FC @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A1700 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _080A170C
	ldr r0, _080A1704 @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	movs r3, #0x28
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	cmp r3, #0x7f
	bgt _080A170C
	cmp r1, #0x7f
	bgt _080A170C
	adds r0, r3, #0
	muls r0, r3, r0
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	ldr r1, _080A1708 @ =0x00003FFF
	cmp r0, r1
	bgt _080A170C
	movs r0, #1
	b _080A170E
	.align 2, 0
_080A16FC: .4byte 0x030046A0
_080A1700: .4byte 0x00000942
_080A1704: .4byte 0x03002BE0
_080A1708: .4byte 0x00003FFF
_080A170C:
	movs r0, #0
_080A170E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a1714
FUN_080a1714: @ 0x080A1714
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080A1740 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A1744 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r5, [r0, r2]
	cmp r5, #0
	bne _080A174C
	ldrh r0, [r4, #0x1e]
	cmp r0, #1
	bne _080A1738
	ldr r0, _080A1748 @ =0x00000237
	bl sound_08240740
	strh r5, [r4, #0x1e]
_080A1738:
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x46
	b _080A17FC
	.align 2, 0
_080A1740: .4byte 0x030046A0
_080A1744: .4byte 0x00000942
_080A1748: .4byte 0x00000237
_080A174C:
	adds r0, r4, #0
	bl FUN_080a16b0
	adds r5, r0, #0
	cmp r5, #0
	beq _080A17E8
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne _080A1778
	ldr r0, _080A17A4 @ =0x00000237
	bl PlaySound_082406e0
	movs r0, #1
	strh r0, [r4, #0x1e]
	adds r0, r4, #0
	adds r0, #0xf4
	ldr r0, [r0]
	cmp r0, #0
	beq _080A1778
	movs r1, #0
	bl Script_ExecById
_080A1778:
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x45
	bl FUN_0822b20c
	adds r3, r4, #0
	adds r3, #0xac
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrh r0, [r4, #0x1a]
	lsrs r0, r0, #1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A17A8
	movs r0, #4
	orrs r2, r0
	b _080A17AE
	.align 2, 0
_080A17A4: .4byte 0x00000237
_080A17A8:
	movs r0, #5
	rsbs r0, r0, #0
	ands r2, r0
_080A17AE:
	str r2, [r3]
	ldrh r1, [r4, #0x1a]
	movs r0, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _080A17DC
	adds r0, r4, #0
	adds r0, #0x80
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	adds r1, #0x84
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0x80
	lsls r2, r2, #3
	movs r3, #0x80
	str r3, [sp]
	ldr r3, _080A17E4 @ =0x0000B546
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
_080A17DC:
	ldrh r0, [r4, #0x1a]
	adds r0, #1
	strh r0, [r4, #0x1a]
	b _080A180E
	.align 2, 0
_080A17E4: .4byte 0x0000B546
_080A17E8:
	ldrh r0, [r4, #0x1e]
	cmp r0, #1
	bne _080A17F6
	ldr r0, _080A1818 @ =0x00000237
	bl sound_08240740
	strh r5, [r4, #0x1e]
_080A17F6:
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x44
_080A17FC:
	bl FUN_0822b20c
	adds r2, r4, #0
	adds r2, #0xac
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	strh r5, [r4, #0x1a]
_080A180E:
	movs r0, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A1818: .4byte 0x00000237

	thumb_func_start FUN_080a181c
FUN_080a181c: @ 0x080A181C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x1c]
	cmp r0, #0
	beq _080A182E
	adds r0, r4, #0
	adds r0, #0x20
	bl FUN_0823b284
_080A182E:
	adds r0, r4, #0
	adds r0, #0x64
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0xac
	bl FUN_0822a4e0
	ldr r0, _080A184C @ =0x00000237
	bl sound_08240740
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A184C: .4byte 0x00000237

	thumb_func_start FUN_080a1850
FUN_080a1850: @ 0x080A1850
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	strh r1, [r6, #0x18]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A1874
	bl Script_GetValue
	strh r0, [r6, #0x28]
	bl Script_GetValue
	strh r0, [r6, #0x2a]
	bl Script_GetValue
	b _080A1878
_080A1874:
	strh r0, [r6, #0x28]
	strh r0, [r6, #0x2a]
_080A1878:
	strh r0, [r6, #0x2c]
	adds r5, r6, #0
	adds r5, #0x64
	adds r4, r6, #0
	adds r4, #0x90
	ldr r1, _080A1900 @ =0x0000A680
	adds r0, r4, #0
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0xa
	strh r0, [r5, #0x10]
	movs r0, #3
	strb r0, [r5, #7]
	adds r0, r4, #0
	movs r1, #0x46
	bl FUN_0822b20c
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080A18BE
	bl Script_GetValue
	cmp r0, #0
	beq _080A18BE
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	str r0, [r6, #0x64]
_080A18BE:
	movs r0, #0
	strh r0, [r6, #0x1e]
	ldr r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r0, #0x68
	bl prepare_08231510
	cmp r0, #0
	beq _080A1904
	bl Script_GetValue
	strh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A1906
	adds r4, r6, #0
	adds r4, #0x20
	ldrh r1, [r6, #0x18]
	adds r2, r5, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	bl FUN_08002a48
	b _080A1906
	.align 2, 0
_080A1900: .4byte 0x0000A680
_080A1904:
	strh r0, [r6, #0x1c]
_080A1906:
	adds r5, r6, #0
	adds r5, #0xac
	adds r4, r6, #0
	adds r4, #0xd8
	ldr r1, _080A196C @ =0x0000A680
	adds r0, r4, #0
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0xb
	strh r0, [r5, #0x10]
	movs r0, #1
	strb r0, [r5, #7]
	adds r0, r4, #0
	movs r1, #0x45
	bl FUN_0822b20c
	ldr r0, [r5]
	ldr r1, _080A1970 @ =0x00000201
	orrs r0, r1
	str r0, [r5]
	ldr r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldrh r0, [r5, #0x1c]
	subs r0, #0x80
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	subs r0, #0x80
	strh r0, [r5, #0x20]
	movs r0, #0x52
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080A195E
	bl Script_GetValue
	adds r2, r0, #0
_080A195E:
	adds r1, r6, #0
	adds r1, #0xf4
	str r2, [r1]
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A196C: .4byte 0x0000A680
_080A1970: .4byte 0x00000201

	thumb_func_start FUN_080a1974
FUN_080a1974: @ 0x080A1974
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0xf8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A19AC
	ldr r1, _080A19A4 @ =FUN_080a1714
	ldr r2, _080A19A8 @ =FUN_080a181c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a1850
	cmp r0, #0
	bge _080A19AC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A19AE
	.align 2, 0
_080A19A4: .4byte FUN_080a1714
_080A19A8: .4byte FUN_080a181c
_080A19AC:
	adds r0, r4, #0
_080A19AE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a19b4
FUN_080a19b4: @ 0x080A19B4
	push {lr}
	movs r1, #0x40
	ldr r0, [r0, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _080A19C8
	adds r1, r2, #0
	adds r1, #0xc4
	movs r0, #1
	strb r0, [r1]
_080A19C8:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a19cc
FUN_080a19cc: @ 0x080A19CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	str r0, [sp, #0x30]
	mov r0, sp
	movs r3, #0
	movs r2, #2
	strh r2, [r0]
	strh r3, [r0, #2]
	mov r1, sp
	movs r0, #0x40
	strh r0, [r1, #6]
	movs r0, #3
	strh r0, [r1, #8]
	movs r0, #6
	strh r0, [r1, #0xa]
	mov r0, sp
	strh r2, [r0, #0xc]
	strh r2, [r0, #0xe]
	movs r0, #0x3c
	strh r0, [r1, #0x10]
	movs r0, #8
	strh r0, [r1, #0x12]
	mov r0, sp
	strh r3, [r0, #0x14]
	movs r1, #0xff
	strh r1, [r0, #0x16]
	strh r1, [r0, #0x18]
	strh r3, [r0, #0x1a]
	strh r1, [r0, #0x1c]
	strh r3, [r0, #0x1e]
	strh r1, [r0, #0x20]
	strh r3, [r0, #0x22]
	strh r1, [r0, #0x24]
	strh r3, [r0, #0x26]
	add r6, sp, #0x28
	ldr r0, _080A1AD4 @ =0x0203B400
	mov sl, r0
	ldr r4, _080A1AD8 @ =0x030046B8
	ldr r1, _080A1ADC @ =0x000003FF
	mov sb, r1
	movs r2, #0x96
	lsls r2, r2, #1
	mov r8, r2
	movs r7, #5
	adds r5, r6, #0
_080A1A2E:
	ldr r2, [sp, #0x30]
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	ldr r0, [r4]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	bl Mod
	ldrh r1, [r6]
	subs r1, #0x96
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x28]
	ldr r2, _080A1AE0 @ =0xFFFF0000
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x28]
	ldr r0, [r4]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	bl Mod
	ldr r2, [sp, #0x28]
	asrs r1, r2, #0x10
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _080A1AE4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x28]
	ldr r0, [r4]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	bl Mod
	ldrh r1, [r5, #4]
	subs r1, #0x96
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ldr r2, _080A1AE0 @ =0xFFFF0000
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #1
	adds r1, r5, #0
	mov r2, sp
	bl FUN_080155e4
	subs r7, #1
	cmp r7, #0
	bge _080A1A2E
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A1AD4: .4byte 0x0203B400
_080A1AD8: .4byte 0x030046B8
_080A1ADC: .4byte 0x000003FF
_080A1AE0: .4byte 0xFFFF0000
_080A1AE4: .4byte 0x0000FFFF

	thumb_func_start FUN_080a1ae8
FUN_080a1ae8: @ 0x080A1AE8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A1B1E
	ldr r0, [r4, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x18]
	adds r0, r4, #0
	bl FUN_080a19cc
	adds r1, r4, #0
	adds r1, #0xc8
	ldr r2, [r1]
	cmp r2, #0
	beq _080A1B18
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl Script_ExecById
_080A1B18:
	adds r0, r4, #0
	bl KillEntity
_080A1B1E:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a1b28
FUN_080a1b28: @ 0x080A1B28
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0x60
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0xb0
	bl FUN_082342a8
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a1b48
FUN_080a1b48: @ 0x080A1B48
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	adds r5, r0, #0
	adds r5, #0x18
	adds r4, r0, #0
	adds r4, #0x44
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A1B6C
	bl Script_GetValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl Video_GetActorSprite
	b _080A1B74
_080A1B6C:
	ldr r1, _080A1BB8 @ =0x00009D41
	adds r0, r4, #0
	bl Video_GetActorSprite
_080A1B74:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _080A1B8C
	bl Script_GetValue
_080A1B8C:
	strh r0, [r5, #0x10]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080A1BB0
	bl Script_GetValue
	cmp r0, #0
	beq _080A1BB0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080A1BB0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A1BB8: .4byte 0x00009D41

	thumb_func_start FUN_080a1bbc
FUN_080a1bbc: @ 0x080A1BBC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x1c
	adds r6, r0, #0
	mov r8, r2
	adds r5, r6, #0
	adds r5, #0x60
	ldr r4, _080A1C34 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r4
	movs r3, #0x80
	orrs r0, r3
	ldr r2, _080A1C38 @ =0x0000FFFF
	ands r0, r2
	movs r2, #0x80
	lsls r2, r2, #0x10
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r3
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r4
	str r0, [r3, #4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080A1C3C @ =0x00004001
	movs r0, #0x20
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _080A1C40 @ =FUN_080a19b4
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A1C34: .4byte 0xFFFF0000
_080A1C38: .4byte 0x0000FFFF
_080A1C3C: .4byte 0x00004001
_080A1C40: .4byte FUN_080a19b4

	thumb_func_start FUN_080a1c44
FUN_080a1c44: @ 0x080A1C44
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r7, r1, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A1CA0
	bl Script_GetValue
	asrs r0, r0, #8
	lsls r0, r0, #8
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080A1C98 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080A1C9C @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	asrs r0, r0, #8
	lsls r0, r0, #8
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _080A1CAA
	.align 2, 0
_080A1C98: .4byte 0xFFFF0000
_080A1C9C: .4byte 0x0000FFFF
_080A1CA0:
	ldr r1, _080A1CD8 @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_080A1CAA:
	add r6, sp, #8
	adds r0, r6, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A1CD2
	cmp r1, #0
	blt _080A1CD2
	ldr r0, _080A1CDC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A1CD2
	ldr r0, _080A1CE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A1CE4
_080A1CD2:
	movs r4, #0
	b _080A1CF2
	.align 2, 0
_080A1CD8: .4byte 0xFFFF0000
_080A1CDC: .4byte 0x030046A8
_080A1CE0: .4byte 0x030046AC
_080A1CE4:
	ldr r0, _080A1D04 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A1CF2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A1D08
	adds r0, #4
	b _080A1D14
	.align 2, 0
_080A1D04: .4byte 0x030046A4
_080A1D08:
	ldr r0, _080A1D28 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A1D14:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080A1D2C
	cmp r3, #2
	beq _080A1D30
	b _080A1D34
	.align 2, 0
_080A1D28: .4byte 0x030046A4
_080A1D2C:
	ldrb r0, [r6, #4]
	b _080A1D32
_080A1D30:
	ldrb r0, [r6]
_080A1D32:
	subs r2, r2, r0
_080A1D34:
	add r1, sp, #8
	strh r2, [r1, #2]
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A1D5E
	cmp r1, #0
	blt _080A1D5E
	ldr r0, _080A1D64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A1D5E
	ldr r0, _080A1D68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A1D6C
_080A1D5E:
	movs r0, #0
	b _080A1D7A
	.align 2, 0
_080A1D64: .4byte 0x030046A8
_080A1D68: .4byte 0x030046AC
_080A1D6C:
	ldr r0, _080A1DD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A1D7A:
	adds r1, r5, #0
	adds r1, #0xc2
	strh r0, [r1]
	add r0, sp, #8
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #1
	adds r2, r5, #0
	adds r2, #0xc1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xb0
	ldrh r1, [r1]
	ldrb r3, [r2]
	movs r2, #0xff
	str r2, [sp]
	adds r2, #4
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_08234270
	adds r0, r5, #0
	add r1, sp, #8
	bl FUN_080a1b48
	adds r0, r5, #0
	adds r1, r7, #0
	add r2, sp, #8
	bl FUN_080a1bbc
	movs r0, #0x52
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A1DD4
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0xc8
	str r0, [r1]
	b _080A1DDA
	.align 2, 0
_080A1DD0: .4byte 0x030046A4
_080A1DD4:
	adds r0, r5, #0
	adds r0, #0xc8
	str r1, [r0]
_080A1DDA:
	movs r0, #0
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a1de4
FUN_080a1de4: @ 0x080A1DE4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #8
	movs r1, #0xcc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A1E20
	ldr r1, _080A1E18 @ =FUN_080a1ae8
	ldr r2, _080A1E1C @ =FUN_080a1b28
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a1c44
	cmp r0, #0
	bge _080A1E20
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A1E22
	.align 2, 0
_080A1E18: .4byte FUN_080a1ae8
_080A1E1C: .4byte FUN_080a1b28
_080A1E20:
	adds r0, r4, #0
_080A1E22:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a1e28
FUN_080a1e28: @ 0x080A1E28
	push {r4, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x32]
	adds r2, r0, #1
	strh r2, [r3, #0x32]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A1E48
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	movs r0, #0
	strh r0, [r3, #0x30]
	b _080A1E70
_080A1E48:
	ldrh r0, [r3, #0x28]
	ldrh r4, [r3, #0x18]
	adds r0, r0, r4
	strh r0, [r3, #0x18]
	ldrh r0, [r3, #0x2a]
	ldrh r4, [r3, #0x1a]
	adds r0, r0, r4
	strh r0, [r3, #0x1a]
	ldrh r0, [r3, #0x2c]
	ldrh r4, [r3, #0x1c]
	adds r0, r0, r4
	strh r0, [r3, #0x1c]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r3, #0
	bl FUN_0822dafc
_080A1E70:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a1e78
FUN_080a1e78: @ 0x080A1E78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0xbd
	adds r0, r0, r7
	mov sl, r0
	ldrb r2, [r0]
	movs r0, #0x34
	adds r4, r2, #0
	muls r4, r0, r4
	adds r4, #0xc0
	adds r4, r7, r4
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r5, _080A1F50 @ =0x0203B400
	ldr r1, _080A1F54 @ =0x030046B8
	mov sb, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r3, _080A1F58 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r2, r7, #0
	adds r2, #0xac
	asrs r0, r0, #4
	movs r6, #0xff
	mov r8, r6
	mov r6, r8
	ands r0, r6
	ldrh r2, [r2]
	adds r0, r0, r2
	subs r0, #0x7f
	strh r0, [r4, #0x18]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0xae
	adds r2, r2, r7
	mov ip, r2
	movs r2, #0x3f
	ands r0, r2
	mov r6, ip
	ldrh r6, [r6]
	adds r0, r0, r6
	strh r0, [r4, #0x1a]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r2, r7, #0
	adds r2, #0xb0
	asrs r0, r0, #4
	mov r6, r8
	ands r0, r6
	ldrh r2, [r2]
	adds r0, r0, r2
	subs r0, #0x7f
	strh r0, [r4, #0x1c]
	movs r0, #0
	strh r0, [r4, #0x28]
	adds r1, #1
	ands r1, r3
	mov r2, sb
	str r1, [r2]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strh r0, [r4, #0x2a]
	movs r6, #0
	strh r6, [r4, #0x2c]
	strh r6, [r4, #0x32]
	movs r0, #1
	strh r0, [r4, #0x30]
	mov r1, sl
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080A1F42
	movs r0, #0
	strb r0, [r1]
_080A1F42:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A1F50: .4byte 0x0203B400
_080A1F54: .4byte 0x030046B8
_080A1F58: .4byte 0x000003FF

	thumb_func_start FUN_080a1f5c
FUN_080a1f5c: @ 0x080A1F5C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_080865c0
	adds r3, r0, #0
	cmp r3, #0
	beq _080A1FA2
	movs r2, #0
	ldrsh r1, [r3, r2]
	adds r2, r5, #0
	adds r2, #0xac
	movs r4, #0
	ldrsh r2, [r2, r4]
	subs r1, r1, r2
	cmp r1, #0
	bge _080A1F7E
	rsbs r1, r1, #0
_080A1F7E:
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r1, #4
	ldrsh r2, [r3, r1]
	adds r1, r5, #0
	adds r1, #0xb0
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r2, r1
	cmp r1, #0
	bge _080A1F96
	rsbs r1, r1, #0
_080A1F96:
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	cmp r4, #0x7f
	bhi _080A1FA2
	cmp r2, #0x7f
	bls _080A1FA6
_080A1FA2:
	movs r0, #0
	b _080A1FBA
_080A1FA6:
	adds r1, r4, #0
	muls r1, r4, r1
	adds r4, r2, #0
	muls r4, r2, r4
	adds r2, r4, #0
	adds r1, r1, r2
	ldr r2, _080A1FC0 @ =0x00003FFF
	cmp r1, r2
	bgt _080A1FBA
	movs r0, #1
_080A1FBA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A1FC0: .4byte 0x00003FFF

	thumb_func_start FUN_080a1fc4
FUN_080a1fc4: @ 0x080A1FC4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xa8
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A2040
	adds r0, r4, #0
	bl FUN_080a1f5c
	cmp r0, #0
	beq _080A200C
	ldr r0, _080A2034 @ =0x03002C00
	ldr r0, [r0]
	ldr r1, _080A2038 @ =0x000001F5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080A200C
	strh r0, [r5]
	movs r2, #0x98
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _080A1FFE
	movs r1, #0
	bl Script_ExecById
_080A1FFE:
	movs r0, #1
	bl FUN_0808670c
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080A200C:
	adds r1, r4, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _080A203C @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080A2090
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r4, #0
	bl FUN_080a1e78
	b _080A2090
	.align 2, 0
_080A2034: .4byte 0x03002C00
_080A2038: .4byte 0x000001F5
_080A203C: .4byte 0x0000FFFF
_080A2040:
	adds r0, r4, #0
	bl FUN_080a1f5c
	adds r6, r0, #0
	cmp r6, #0
	bne _080A206C
	movs r1, #0x99
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080A205E
	movs r1, #0
	bl Script_ExecById
_080A205E:
	movs r0, #0
	bl FUN_0808670c
	strh r6, [r5]
	ldr r0, _080A2098 @ =0x00000199
	bl PlaySound_082406e0
_080A206C:
	adds r1, r4, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _080A209C @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080A2090
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r4, #0
	bl FUN_080a1e78
_080A2090:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2098: .4byte 0x00000199
_080A209C: .4byte 0x0000FFFF

	thumb_func_start FUN_080a20a0
FUN_080a20a0: @ 0x080A20A0
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x18]
	adds r3, r2, #0
	adds r3, #0xaa
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080A20DC
	adds r0, r2, #0
	adds r0, #0xae
	ldrh r0, [r0]
	adds r0, #0x1e
	strh r0, [r2, #0x36]
	movs r0, #0
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xb4
	ldr r0, _080A20D8 @ =FUN_080a1fc4
	str r0, [r1]
	b _080A20E8
	.align 2, 0
_080A20D8: .4byte FUN_080a1fc4
_080A20DC:
	adds r3, r2, #0
	adds r3, #0xae
	lsls r0, r1, #1
	ldrh r3, [r3]
	adds r0, r0, r3
	strh r0, [r2, #0x36]
_080A20E8:
	adds r1, r2, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r3, _080A2110 @ =0x0000FFFF
	adds r1, r3, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080A210C
	adds r0, r2, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r2, #0
	bl FUN_080a1e78
_080A210C:
	pop {r0}
	bx r0
	.align 2, 0
_080A2110: .4byte 0x0000FFFF

	thumb_func_start FUN_080a2114
FUN_080a2114: @ 0x080A2114
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x18]
	ldr r0, [r2, #0x60]
	subs r1, #3
	ands r0, r1
	str r0, [r2, #0x60]
	adds r3, r2, #0
	adds r3, #0xaa
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _080A216C
	ldr r0, [r2, #0x60]
	subs r1, #1
	ands r0, r1
	str r0, [r2, #0x60]
	adds r0, r2, #0
	adds r0, #0x68
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #0
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xb4
	ldr r0, _080A2164 @ =FUN_080a20a0
	str r0, [r1]
	ldr r0, _080A2168 @ =0x0000032F
	bl PlaySound_082406e0
	b _080A218C
	.align 2, 0
_080A2164: .4byte FUN_080a20a0
_080A2168: .4byte 0x0000032F
_080A216C:
	ldr r0, [r2, #0x60]
	movs r1, #2
	orrs r0, r1
	str r0, [r2, #0x60]
	ldrh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x68
	strb r1, [r0]
	ldrh r0, [r3]
	adds r1, r2, #0
	adds r1, #0x69
	strb r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #2
	subs r1, #3
	strb r0, [r1]
_080A218C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a2190
FUN_080a2190: @ 0x080A2190
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
_080A2196:
	movs r0, #0x34
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, r1
	adds r0, #0xf0
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A21B6
	adds r0, r1, #0
	adds r0, #0xc0
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r1, [r1]
	bl FUN_080a1e28
_080A21B6:
	adds r5, #1
	cmp r5, #7
	ble _080A2196
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a21d0
FUN_080a21d0: @ 0x080A21D0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0x60
	bl FUN_0822a4e0
	adds r4, #0xc0
	movs r5, #7
_080A21E6:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080A21E6
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a21fc
FUN_080a21fc: @ 0x080A21FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldr r0, _080A2290 @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r6, #0
	adds r1, #0xb8
	str r0, [r1]
	movs r7, #0
	mov r8, r1
	movs r0, #4
	rsbs r0, r0, #0
	mov sl, r0
	movs r1, #1
	mov sb, r1
_080A2222:
	movs r0, #0x34
	adds r5, r7, #0
	muls r5, r0, r5
	adds r4, r5, #0
	adds r4, #0xc0
	adds r4, r6, r4
	mov r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, sl
	mov r2, sl
	bl FUN_0822dad4
	mov r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	mov r1, sb
	strb r1, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	ldr r0, [r4]
	mov r1, sb
	orrs r0, r1
	str r0, [r4]
	adds r5, r6, r5
	adds r5, #0xf0
	movs r0, #0
	strh r0, [r5]
	adds r7, #1
	cmp r7, #7
	ble _080A2222
	adds r0, r6, #0
	adds r0, #0xbd
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strh r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2290: .4byte 0x00001C1E

	thumb_func_start FUN_080a2294
FUN_080a2294: @ 0x080A2294
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080A2350
	bl Script_GetValue
	adds r4, r7, #0
	adds r4, #0xac
	strh r0, [r4]
	bl Script_GetValue
	adds r5, r7, #0
	adds r5, #0xae
	strh r0, [r5]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0xb0
	strh r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sl, r4
	cmp r2, #0
	blt _080A22F0
	cmp r1, #0
	blt _080A22F0
	ldr r0, _080A22F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A22F0
	ldr r0, _080A22F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A22FC
_080A22F0:
	movs r6, #0
	b _080A230A
	.align 2, 0
_080A22F4: .4byte 0x030046A8
_080A22F8: .4byte 0x030046AC
_080A22FC:
	ldr r0, _080A231C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080A230A:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A2320
	adds r0, #4
	b _080A232C
	.align 2, 0
_080A231C: .4byte 0x030046A4
_080A2320:
	ldr r0, _080A2340 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A232C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A2344
	cmp r2, #2
	beq _080A2348
	b _080A234C
	.align 2, 0
_080A2340: .4byte 0x030046A4
_080A2344:
	ldrb r0, [r4, #4]
	b _080A234A
_080A2348:
	ldrb r0, [r4]
_080A234A:
	subs r1, r1, r0
_080A234C:
	strh r1, [r5]
	b _080A2362
_080A2350:
	adds r1, r7, #0
	adds r1, #0xac
	strh r2, [r1]
	adds r0, r7, #0
	adds r0, #0xae
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	mov sl, r1
_080A2362:
	adds r4, r7, #0
	adds r4, #0x44
	ldr r0, _080A2428 @ =0x00000BA8
	mov sb, r0
	adds r0, r4, #0
	mov r1, sb
	bl Video_GetActorSprite
	adds r5, r7, #0
	adds r5, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	movs r6, #6
	strh r6, [r5, #0x10]
	adds r0, r4, #0
	movs r1, #0x63
	bl FUN_0822b20c
	ldr r0, [r7, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r7, #0x18]
	movs r1, #3
	mov r8, r1
	mov r2, r8
	strb r2, [r7, #0x1f]
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldrh r0, [r7, #0x36]
	adds r0, #0x1e
	strh r0, [r7, #0x36]
	adds r4, #0x48
	adds r0, r4, #0
	mov r1, sb
	bl Video_GetActorSprite
	adds r5, #0x48
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	strh r6, [r5, #0x10]
	adds r0, r4, #0
	movs r1, #0x61
	bl FUN_0822b20c
	ldr r0, [r7, #0x60]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r7, #0x60]
	adds r0, r7, #0
	adds r0, #0x67
	mov r1, r8
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0x7c
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl FUN_080a21fc
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A2430
	bl Script_GetValue
	cmp r0, #0
	beq _080A2430
	ldr r0, [r7, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x18]
	ldr r0, [r7, #0x60]
	orrs r0, r1
	str r0, [r7, #0x60]
	adds r1, r7, #0
	adds r1, #0xb4
	ldr r0, _080A242C @ =FUN_080a2114
	str r0, [r1]
	movs r0, #0xaf
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080A2438
	.align 2, 0
_080A2428: .4byte 0x00000BA8
_080A242C: .4byte FUN_080a2114
_080A2430:
	adds r1, r7, #0
	adds r1, #0xb4
	ldr r0, _080A2458 @ =FUN_080a1fc4
	str r0, [r1]
_080A2438:
	adds r1, r7, #0
	adds r1, #0xaa
	movs r0, #0
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_080a1f5c
	adds r1, r0, #0
	cmp r1, #0
	beq _080A245C
	adds r1, r7, #0
	adds r1, #0xa8
	movs r0, #1
	strh r0, [r1]
	adds r4, r1, #0
	b _080A2464
	.align 2, 0
_080A2458: .4byte FUN_080a1fc4
_080A245C:
	adds r0, r7, #0
	adds r0, #0xa8
	strh r1, [r0]
	adds r4, r0, #0
_080A2464:
	movs r0, #0x69
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A247E
	bl Script_GetValue
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A2486
_080A247E:
	movs r3, #0x98
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A2486:
	movs r0, #0x6f
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A24A0
	bl Script_GetValue
	movs r2, #0x99
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A24A8
_080A24A0:
	movs r3, #0x99
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A24A8:
	adds r0, r7, #0
	bl FUN_080a1f5c
	cmp r0, #0
	beq _080A24BC
	movs r0, #1
	strh r0, [r4]
	bl FUN_0808670c
	b _080A24C4
_080A24BC:
	strh r0, [r4]
	movs r0, #0
	bl FUN_0808670c
_080A24C4:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a24d4
FUN_080a24d4: @ 0x080A24D4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x9a
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A2514
	ldr r1, _080A250C @ =FUN_080a2190
	ldr r2, _080A2510 @ =FUN_080a21d0
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a2294
	cmp r0, #0
	bge _080A2514
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A2516
	.align 2, 0
_080A250C: .4byte FUN_080a2190
_080A2510: .4byte FUN_080a21d0
_080A2514:
	adds r0, r4, #0
_080A2516:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a251c
FUN_080a251c: @ 0x080A251C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x29
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080A2542
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r0, r4, #0
	adds r0, #0x28
	strb r2, [r0]
	b _080A25C0
_080A2542:
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x2e]
	ldrh r1, [r4, #0x1a]
	adds r0, r0, r1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x30]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	ldr r0, _080A2584 @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r0, #0
	ldrb r2, [r5]
	lsrs r2, r2, #2
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r4, #0
	bl FUN_0822dafc
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	cmp r0, #0
	blt _080A2588
	asrs r0, r0, #4
	b _080A258E
	.align 2, 0
_080A2584: .4byte 0x00001C1E
_080A2588:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_080A258E:
	strh r0, [r4, #0x2c]
	movs r0, #0x2e
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	cmp r0, #0
	blt _080A25A0
	asrs r0, r0, #4
	b _080A25A6
_080A25A0:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_080A25A6:
	strh r0, [r4, #0x2e]
	movs r0, #0x30
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	cmp r0, #0
	blt _080A25B8
	asrs r0, r0, #4
	b _080A25BE
_080A25B8:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_080A25BE:
	strh r0, [r4, #0x30]
_080A25C0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a25c8
FUN_080a25c8: @ 0x080A25C8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0, #0x18]
	str r2, [r0, #0x1c]
	ldr r6, _080A266C @ =0x0203B400
	ldr r1, _080A2670 @ =0x030046B8
	mov sb, r1
	ldr r2, [r1]
	adds r2, #1
	ldr r4, _080A2674 @ =0x000003FF
	ands r2, r4
	lsls r1, r2, #1
	adds r1, r1, r6
	ldrh r3, [r1]
	ldrh r1, [r0, #0x18]
	subs r1, #0xf
	movs r5, #0x1f
	ands r3, r5
	adds r1, r1, r3
	movs r3, #0
	mov r8, r3
	strh r1, [r0, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r3, r2, #1
	adds r3, r3, r6
	movs r7, #0xc0
	lsls r7, r7, #2
	adds r1, r7, #0
	ldrh r7, [r0, #0x1a]
	adds r1, r1, r7
	ldrb r3, [r3]
	adds r1, r1, r3
	strh r1, [r0, #0x1a]
	adds r2, #1
	ands r2, r4
	lsls r1, r2, #1
	adds r1, r1, r6
	ldrh r3, [r1]
	ldrh r1, [r0, #0x1c]
	subs r1, #0xf
	ands r3, r5
	adds r1, r1, r3
	strh r1, [r0, #0x1c]
	adds r3, r0, #0
	adds r3, #0x29
	movs r1, #0x18
	strb r1, [r3]
	mov r1, r8
	strh r1, [r0, #0x2c]
	adds r2, #1
	ands r2, r4
	mov r3, sb
	str r2, [r3]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r1, [r2]
	ands r1, r5
	adds r1, #0x20
	rsbs r1, r1, #0
	strh r1, [r0, #0x2e]
	mov r7, r8
	strh r7, [r0, #0x30]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	adds r0, #0x28
	movs r1, #1
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A266C: .4byte 0x0203B400
_080A2670: .4byte 0x030046B8
_080A2674: .4byte 0x000003FF

	thumb_func_start FUN_080a2678
FUN_080a2678: @ 0x080A2678
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0, #0x18]
	str r2, [r0, #0x1c]
	ldr r6, _080A2710 @ =0x0203B400
	ldr r1, _080A2714 @ =0x030046B8
	mov sb, r1
	ldr r3, [r1]
	adds r3, #1
	ldr r4, _080A2718 @ =0x000003FF
	ands r3, r4
	lsls r1, r3, #1
	adds r1, r1, r6
	ldrh r2, [r1]
	ldrh r1, [r0, #0x18]
	subs r1, #0xf
	movs r5, #0x1f
	ands r2, r5
	adds r1, r1, r2
	movs r2, #0
	mov r8, r2
	strh r1, [r0, #0x18]
	adds r3, #1
	ands r3, r4
	lsls r2, r3, #1
	adds r2, r2, r6
	ldrh r1, [r0, #0x1a]
	ldrb r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #0x1a]
	adds r3, #1
	ands r3, r4
	lsls r1, r3, #1
	adds r1, r1, r6
	ldrh r2, [r1]
	ldrh r1, [r0, #0x1c]
	subs r1, #0xf
	ands r2, r5
	adds r1, r1, r2
	strh r1, [r0, #0x1c]
	adds r2, r0, #0
	adds r2, #0x29
	movs r1, #0x18
	strb r1, [r2]
	mov r1, r8
	strh r1, [r0, #0x2c]
	adds r3, #1
	ands r3, r4
	mov r2, sb
	str r3, [r2]
	lsls r3, r3, #1
	adds r3, r3, r6
	ldrh r1, [r3]
	ands r1, r5
	adds r1, #0x18
	strh r1, [r0, #0x2e]
	mov r1, r8
	strh r1, [r0, #0x30]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	adds r0, #0x28
	movs r1, #1
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2710: .4byte 0x0203B400
_080A2714: .4byte 0x030046B8
_080A2718: .4byte 0x000003FF

	thumb_func_start FUN_080a271c
FUN_080a271c: @ 0x080A271C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A276C @ =0x030046A0
	ldr r3, [r0]
	movs r0, #0x30
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x98
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	cmp r2, #0
	bge _080A2738
	rsbs r2, r2, #0
_080A2738:
	movs r1, #0x34
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0x9c
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r0, r1
	cmp r1, #0
	bge _080A274C
	rsbs r1, r1, #0
_080A274C:
	cmp r2, #0x60
	bgt _080A2770
	cmp r1, #0x60
	bgt _080A2770
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x90
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080A2770
	movs r0, #1
	b _080A2772
	.align 2, 0
_080A276C: .4byte 0x030046A0
_080A2770:
	movs r0, #0
_080A2772:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a2778
FUN_080a2778: @ 0x080A2778
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080865c0
	adds r3, r0, #0
	cmp r3, #0
	beq _080A27FC
	ldr r0, _080A27F0 @ =0x03002C00
	ldr r1, [r0]
	ldrb r0, [r1, #0x1a]
	cmp r0, #4
	bne _080A27FC
	ldr r2, _080A27F4 @ =0x000001F5
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bhi _080A27FC
	movs r0, #2
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x9a
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _080A27AE
	rsbs r1, r1, #0
_080A27AE:
	cmp r1, #0xff
	bgt _080A27FC
	movs r0, #0
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x98
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	movs r0, #4
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x9c
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	movs r0, #0xbe
	lsls r0, r0, #1
	cmp r2, r0
	bgt _080A27FC
	cmp r1, r0
	bgt _080A27FC
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	ldr r1, _080A27F8 @ =0x00023410
	cmp r0, r1
	bgt _080A27FC
	movs r0, #1
	b _080A27FE
	.align 2, 0
_080A27F0: .4byte 0x03002C00
_080A27F4: .4byte 0x000001F5
_080A27F8: .4byte 0x00023410
_080A27FC:
	movs r0, #0
_080A27FE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a2804
FUN_080a2804: @ 0x080A2804
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r4, r3, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A2816
	b _080A29E8
_080A2816:
	cmp r0, #2
	bhi _080A2864
	adds r2, r3, #0
	adds r2, #0xe8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	subs r2, #0x4e
	ldrh r1, [r4]
	movs r0, #2
	subs r0, r0, r1
	movs r1, #0xab
	muls r0, r1, r0
	ldr r1, _080A2860 @ =0x00000402
	adds r0, r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r3, r2
	strh r0, [r1]
	movs r4, #0x8a
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r5, #0xa0
	lsls r5, r5, #1
	adds r1, r3, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080A28C4
	.align 2, 0
_080A2860: .4byte 0x00000402
_080A2864:
	cmp r0, #4
	bhi _080A28D4
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0x9a
	adds r0, r0, r3
	mov ip, r0
	ldr r1, _080A28D0 @ =0x00000402
	adds r0, r1, #0
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r5, #0x83
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldrh r1, [r4]
	movs r0, #4
	subs r0, r0, r1
	movs r1, #0xab
	muls r0, r1, r0
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r0, r1
	mov r2, ip
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r4, #0x99
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	adds r5, #0x3a
	adds r2, r3, r5
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_080A28C4:
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r1, [r0]
	adds r0, #2
	strh r1, [r0, #0x10]
	b _080A2A0C
	.align 2, 0
_080A28D0: .4byte 0x00000402
_080A28D4:
	cmp r0, #6
	bhi _080A2960
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0x9a
	adds r0, r0, r3
	mov ip, r0
	ldr r1, _080A295C @ =0x00000402
	adds r0, r1, #0
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r5, #0x83
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r1, #0
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r5, #0x99
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldrh r1, [r4]
	movs r0, #6
	subs r0, r0, r1
	movs r1, #0xab
	muls r0, r1, r0
	adds r1, #0xab
	adds r0, r0, r1
	mov r2, ip
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r1, [r0]
	adds r0, #2
	strh r1, [r0, #0x10]
	adds r1, r3, #0
	adds r1, #0x57
	movs r0, #3
	strb r0, [r1]
	b _080A2A0C
	.align 2, 0
_080A295C: .4byte 0x00000402
_080A2960:
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r5, #0x9a
	adds r5, r5, r3
	mov ip, r5
	ldr r1, _080A29E4 @ =0x00000402
	adds r0, r1, #0
	ldrh r4, [r5]
	adds r0, r0, r4
	movs r5, #0x83
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r1, #0
	mov r4, ip
	ldrh r4, [r4]
	adds r0, r0, r4
	adds r5, #0x2c
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r1, #0
	mov r2, ip
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r0, [r0]
	adds r1, r3, #0
	adds r1, #0x50
	adds r0, #8
	strh r0, [r1, #0x10]
	ldr r0, [r3, #0x50]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r3, #0x50]
	adds r1, r3, #0
	adds r1, #0x57
	movs r0, #1
	strb r0, [r1]
	b _080A2A0C
	.align 2, 0
_080A29E4: .4byte 0x00000402
_080A29E8:
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x8a
	lsls r5, r5, #1
	adds r1, r3, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_080A2A0C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a2a14
FUN_080a2a14: @ 0x080A2A14
	movs r3, #0xe1
	lsls r3, r3, #2
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080A2A28 @ =0x00000382
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080A2A28: .4byte 0x00000382

	thumb_func_start FUN_080a2a2c
FUN_080a2a2c: @ 0x080A2A2C
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x50]
	adds r0, r2, #0
	adds r0, #0x7c
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r1, r2, r3
	ldrh r1, [r1]
	bl FUN_0822b20c
	pop {r0}
	bx r0

	thumb_func_start FUN_080a2a4c
FUN_080a2a4c: @ 0x080A2A4C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A2A88 @ =0x00000382
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A2A68
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_080A2A68:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #7
	bhi _080A2A78
	adds r0, #1
	strh r0, [r1]
_080A2A78:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0x16
	bhi _080A2A8C
	adds r0, #2
	b _080A2A8E
	.align 2, 0
_080A2A88: .4byte 0x00000382
_080A2A8C:
	movs r0, #0x18
_080A2A8E:
	strb r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r4, r1
	ldrb r0, [r2]
	cmp r0, #0
	bne _080A2AA6
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
	b _080A2AC0
_080A2AA6:
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
_080A2AC0:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #7
	bls _080A2ADE
	adds r0, r4, #0
	adds r0, #0x7c
	subs r2, #2
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl FUN_0822b20c
	b _080A2B06
_080A2ADE:
	cmp r0, #0
	beq _080A2AF6
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl FUN_0822b20c
	b _080A2B06
_080A2AF6:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl FUN_0822b20c
_080A2B06:
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x17
	bls _080A2B24
	ldr r1, _080A2B2C @ =FUN_080a2b30
	adds r0, r4, #0
	bl FUN_080a2a14
	adds r0, r4, #0
	adds r0, #0x18
	movs r1, #1
	bl FUN_08022488
_080A2B24:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2B2C: .4byte FUN_080a2b30

	thumb_func_start FUN_080a2b30
FUN_080a2b30: @ 0x080A2B30
	push {lr}
	adds r3, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r2, r3, r0
	movs r0, #0x18
	strb r0, [r2]
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #8
	strh r0, [r1]
	ldr r0, [r3, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x50]
	adds r0, r3, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r3, #0
	adds r1, #0x6e
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r3, r2
	ldrh r1, [r1]
	adds r1, #2
	bl FUN_0822b20c
	pop {r0}
	bx r0

	thumb_func_start FUN_080a2b78
FUN_080a2b78: @ 0x080A2B78
	push {lr}
	adds r3, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #1
	bls _080A2B8C
	subs r0, #2
	b _080A2B8E
_080A2B8C:
	movs r0, #0
_080A2B8E:
	strb r0, [r1]
	adds r1, r3, #0
	adds r1, #0x9a
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrh r1, [r1]
	ldrb r2, [r0]
	adds r1, r1, r2
	adds r2, r3, #0
	adds r2, #0x6e
	strh r1, [r2]
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A2BCE
	ldr r0, [r3, #0x50]
	ldr r1, _080A2BD4 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r3, #0x50]
	adds r1, r3, #0
	adds r1, #0x57
	movs r0, #3
	strb r0, [r1]
	adds r2, #0x32
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080A2BD8 @ =FUN_080a2bdc
	adds r0, r3, #0
	bl FUN_080a2a14
_080A2BCE:
	pop {r0}
	bx r0
	.align 2, 0
_080A2BD4: .4byte 0xFFFFFDFF
_080A2BD8: .4byte FUN_080a2bdc

	thumb_func_start FUN_080a2bdc
FUN_080a2bdc: @ 0x080A2BDC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #6
	bhi _080A2BF8
	adds r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A2C18
_080A2BF8:
	ldr r0, _080A2C20 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080A2C18
	ldr r0, _080A2C24 @ =0x0000015F
	bl PlaySound_082406e0
	ldr r1, _080A2C28 @ =FUN_080a2c2c
	adds r0, r4, #0
	bl FUN_080a2a14
_080A2C18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2C20: .4byte 0x00000382
_080A2C24: .4byte 0x0000015F
_080A2C28: .4byte FUN_080a2c2c

	thumb_func_start FUN_080a2c2c
FUN_080a2c2c: @ 0x080A2C2C
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A2C50 @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A2C4A
	ldr r1, _080A2C54 @ =FUN_080a2c58
	adds r0, r2, #0
	bl FUN_080a2a14
_080A2C4A:
	pop {r0}
	bx r0
	.align 2, 0
_080A2C50: .4byte 0x00000382
_080A2C54: .4byte FUN_080a2c58

	thumb_func_start FUN_080a2c58
FUN_080a2c58: @ 0x080A2C58
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080A2CA8 @ =0x00000382
	adds r0, r4, r1
	ldrh r2, [r0]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x1f
	bhi _080A2C88
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A2C88
	lsrs r1, r1, #0x12
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0x98
	bl FUN_080a2678
_080A2C88:
	ldr r0, _080A2CA8 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bne _080A2CA2
	ldr r1, _080A2CAC @ =FUN_080a2cb0
	adds r0, r4, #0
	bl FUN_080a2a14
_080A2CA2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2CA8: .4byte 0x00000382
_080A2CAC: .4byte FUN_080a2cb0

	thumb_func_start FUN_080a2cb0
FUN_080a2cb0: @ 0x080A2CB0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	movs r3, #2
	rsbs r3, r3, #0
	ands r0, r3
	str r0, [r4, #0x50]
	adds r2, r4, #0
	adds r2, #0x6e
	movs r0, #0
	ldrsh r1, [r2, r0]
	adds r0, r4, #0
	adds r0, #0x9a
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r0, #0x16
	cmp r1, r0
	bge _080A2CDA
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
_080A2CDA:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A2CF2
	subs r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A2D0E
_080A2CF2:
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	ldr r1, _080A2D14 @ =FUN_080a2e20
	adds r0, r4, #0
	bl FUN_080a2a14
	adds r0, r4, #0
	adds r0, #0x18
	movs r1, #1
	bl FUN_08022488
_080A2D0E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2D14: .4byte FUN_080a2e20

	thumb_func_start FUN_080a2d18
FUN_080a2d18: @ 0x080A2D18
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A2D94 @ =0x00000382
	adds r5, r4, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x3f
	bhi _080A2D98
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r2, #2
	orrs r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl FUN_0822b20c
	ldrh r0, [r5]
	adds r2, r4, #0
	adds r2, #0x58
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x59
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r3, r4, #0
	adds r3, #0x56
	strb r0, [r3]
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0xa8
	strb r1, [r0]
	ldrb r0, [r2]
	adds r1, r4, #0
	adds r1, #0xa9
	strb r0, [r1]
	ldrb r0, [r3]
	subs r1, #3
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	adds r0, #0x16
	subs r1, #0x38
	strh r0, [r1]
	b _080A2E14
	.align 2, 0
_080A2D94: .4byte 0x00000382
_080A2D98:
	cmp r3, #0x40
	bne _080A2DC4
	ldr r0, [r4, #0x50]
	movs r2, #3
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x58
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #0x4f
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	b _080A2E14
_080A2DC4:
	cmp r3, #0x4f
	bls _080A2E14
	adds r1, r4, #0
	adds r1, #0x6e
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	adds r1, #0x2c
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	ble _080A2DF4
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl FUN_0822b20c
	b _080A2E14
_080A2DF4:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl FUN_0822b20c
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
	ldr r1, _080A2E1C @ =FUN_080a2e20
	adds r0, r4, #0
	bl FUN_080a2a14
_080A2E14:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2E1C: .4byte FUN_080a2e20

	thumb_func_start FUN_080a2e20
FUN_080a2e20: @ 0x080A2E20
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080A2E94 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A2E40
	ldr r0, _080A2E98 @ =0x0000036A
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #9
	bhi _080A2E40
	adds r0, #1
	strh r0, [r1]
_080A2E40:
	adds r0, r4, #0
	bl FUN_080a271c
	adds r6, r0, #0
	cmp r6, #0
	bne _080A2E4E
	b _080A2F4C
_080A2E4E:
	ldr r1, _080A2E9C @ =0x00000369
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A2EAC
	movs r2, #1
	ldr r0, _080A2EA0 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	bne _080A2E66
	b _080A2F86
_080A2E66:
	ldr r0, _080A2EA4 @ =0x03002BE0
	ldr r0, [r0]
	adds r1, #0x13
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	bne _080A2E76
	b _080A2F86
_080A2E76:
	cmp r0, #0x19
	bne _080A2E7C
	b _080A2F86
_080A2E7C:
	ldr r0, _080A2EA8 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _080A2E8A
	b _080A2F86
_080A2E8A:
	movs r0, #0x92
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080A2F86
	.align 2, 0
_080A2E94: .4byte 0x030047A4
_080A2E98: .4byte 0x0000036A
_080A2E9C: .4byte 0x00000369
_080A2EA0: .4byte 0x03002BC0
_080A2EA4: .4byte 0x03002BE0
_080A2EA8: .4byte 0x030044E0
_080A2EAC:
	adds r5, r4, #0
	adds r5, #0x4c
	ldrh r0, [r5]
	cmp r0, #1
	beq _080A2EC2
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strh r0, [r5]
_080A2EC2:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #7
	bhi _080A2ED2
	adds r0, #1
	strh r0, [r1]
_080A2ED2:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0x16
	bhi _080A2EE2
	adds r0, #2
	b _080A2EE4
_080A2EE2:
	movs r0, #0x18
_080A2EE4:
	strb r0, [r1]
	movs r2, #1
	ldr r0, _080A2F3C @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080A2F86
	ldr r0, _080A2F40 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080A2F86
	ldr r0, _080A2F44 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A2F86
	subs r1, #0x16
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #9
	bls _080A2F86
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #8
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x98
	adds r0, r2, #0
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	ldr r1, _080A2F48 @ =FUN_080a3004
	adds r0, r4, #0
	bl FUN_080a2a14
	b _080A2F86
	.align 2, 0
_080A2F3C: .4byte 0x03002BC0
_080A2F40: .4byte 0x030044E0
_080A2F44: .4byte 0x03002BE0
_080A2F48: .4byte FUN_080a3004
_080A2F4C:
	adds r5, r4, #0
	adds r5, #0x4c
	ldrh r0, [r5]
	cmp r0, #0
	beq _080A2F5E
	ldr r0, _080A2F80 @ =0x00000199
	bl PlaySound_082406e0
	strh r6, [r5]
_080A2F5E:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A2F6E
	subs r0, #1
	strh r0, [r1]
_080A2F6E:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #2
	bls _080A2F84
	subs r0, #2
	strb r0, [r1]
	b _080A2F86
	.align 2, 0
_080A2F80: .4byte 0x00000199
_080A2F84:
	strb r6, [r1]
_080A2F86:
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r4, r1
	ldrb r0, [r2]
	cmp r0, #0
	bne _080A2F9C
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
	b _080A2FB6
_080A2F9C:
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
_080A2FB6:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #7
	bls _080A2FD4
	adds r0, r4, #0
	adds r0, #0x7c
	subs r2, #2
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl FUN_0822b20c
	b _080A2FFC
_080A2FD4:
	cmp r0, #0
	beq _080A2FEC
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl FUN_0822b20c
	b _080A2FFC
_080A2FEC:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl FUN_0822b20c
_080A2FFC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a3004
FUN_080a3004: @ 0x080A3004
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #1
	bls _080A3018
	subs r0, #2
	b _080A301A
_080A3018:
	movs r0, #0
_080A301A:
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x9a
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrb r2, [r0]
	adds r1, r1, r2
	adds r2, r4, #0
	adds r2, #0x6e
	strh r1, [r2]
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A30A6
	ldr r0, _080A30AC @ =0x03002BE0
	ldr r1, [r0]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A30A6
	adds r0, r1, #0
	movs r1, #4
	movs r2, #0
	bl FUN_0807c200
	ldr r0, _080A30B0 @ =0x000001C3
	adds r5, r4, r0
	movs r0, #0
	strb r0, [r5]
	adds r0, r4, #0
	bl FUN_080a2778
	cmp r0, #0
	beq _080A3070
	bl FUN_08086ab8
	cmp r0, #0
	beq _080A3070
	movs r0, #1
	strb r0, [r5]
_080A3070:
	ldr r0, [r4, #0x50]
	ldr r1, _080A30B4 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0x57
	movs r0, #3
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080A30B8 @ =FUN_080a30bc
	adds r0, r4, #0
	bl FUN_080a2a14
	movs r1, #0xdb
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080A30A6
	movs r1, #0
	bl Script_ExecById
_080A30A6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A30AC: .4byte 0x03002BE0
_080A30B0: .4byte 0x000001C3
_080A30B4: .4byte 0xFFFFFDFF
_080A30B8: .4byte FUN_080a30bc

	thumb_func_start FUN_080a30bc
FUN_080a30bc: @ 0x080A30BC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #6
	bhi _080A30D8
	adds r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A30F8
_080A30D8:
	ldr r0, _080A3100 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080A30F8
	ldr r0, _080A3104 @ =0x0000015F
	bl PlaySound_082406e0
	ldr r1, _080A3108 @ =FUN_080a310c
	adds r0, r4, #0
	bl FUN_080a2a14
_080A30F8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3100: .4byte 0x00000382
_080A3104: .4byte 0x0000015F
_080A3108: .4byte FUN_080a310c

	thumb_func_start FUN_080a310c
FUN_080a310c: @ 0x080A310C
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A3130 @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A312A
	ldr r1, _080A3134 @ =FUN_080a3138
	adds r0, r2, #0
	bl FUN_080a2a14
_080A312A:
	pop {r0}
	bx r0
	.align 2, 0
_080A3130: .4byte 0x00000382
_080A3134: .4byte FUN_080a3138

	thumb_func_start FUN_080a3138
FUN_080a3138: @ 0x080A3138
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080A31D0 @ =0x00000382
	adds r0, r4, r1
	ldrh r2, [r0]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x1f
	bhi _080A316A
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A316A
	lsrs r1, r1, #0x12
	movs r0, #0x34
	muls r0, r1, r0
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0x98
	bl FUN_080a2678
_080A316A:
	ldr r0, _080A31D0 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bne _080A31C6
	movs r1, #0xdd
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A31AA
	ldr r1, _080A31D4 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r3, sp
	str r3, [r1, #4]
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r2, #0
	bl Script_ExecById
_080A31AA:
	ldr r1, _080A31D8 @ =0x000001C3
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A31C6
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _080A31C6
	movs r1, #0
	bl Script_ExecById
_080A31C6:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A31D0: .4byte 0x00000382
_080A31D4: .4byte 0xFFFF0000
_080A31D8: .4byte 0x000001C3

	thumb_func_start FUN_080a31dc
FUN_080a31dc: @ 0x080A31DC
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A3200 @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080A31FA
	ldr r1, _080A3204 @ =FUN_080a3208
	adds r0, r2, #0
	bl FUN_080a2a14
_080A31FA:
	pop {r0}
	bx r0
	.align 2, 0
_080A3200: .4byte 0x00000382
_080A3204: .4byte FUN_080a3208

	thumb_func_start FUN_080a3208
FUN_080a3208: @ 0x080A3208
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A326C @ =0x00000382
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0x10
	bne _080A3222
	ldr r0, _080A3270 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #4
	movs r2, #0
	bl FUN_0807c36c
_080A3222:
	ldrh r2, [r5]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x1f
	bhi _080A324A
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A324A
	lsrs r1, r1, #0x12
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0x98
	bl FUN_080a25c8
_080A324A:
	ldr r0, _080A326C @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _080A3264
	ldr r1, _080A3274 @ =FUN_080a3278
	adds r0, r4, #0
	bl FUN_080a2a14
_080A3264:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A326C: .4byte 0x00000382
_080A3270: .4byte 0x03002BE0
_080A3274: .4byte FUN_080a3278

	thumb_func_start FUN_080a3278
FUN_080a3278: @ 0x080A3278
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A329C @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A3296
	ldr r1, _080A32A0 @ =FUN_080a32a4
	adds r0, r2, #0
	bl FUN_080a2a14
_080A3296:
	pop {r0}
	bx r0
	.align 2, 0
_080A329C: .4byte 0x00000382
_080A32A0: .4byte FUN_080a32a4

	thumb_func_start FUN_080a32a4
FUN_080a32a4: @ 0x080A32A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r4, #0x50]
	adds r2, r4, #0
	adds r2, #0x6e
	movs r0, #0
	ldrsh r1, [r2, r0]
	adds r0, r4, #0
	adds r0, #0x9a
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, #0x16
	cmp r1, r0
	bge _080A32CE
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
_080A32CE:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A32E6
	subs r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A3336
_080A32E6:
	ldr r0, _080A3314 @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807d118
	bl FUN_080a6edc
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A331C
	ldr r1, _080A3318 @ =FUN_080a3340
	adds r0, r4, #0
	bl FUN_080a2a14
	b _080A3324
	.align 2, 0
_080A3314: .4byte 0x03002BE0
_080A3318: .4byte FUN_080a3340
_080A331C:
	ldr r1, _080A333C @ =FUN_080a2e20
	adds r0, r4, #0
	bl FUN_080a2a14
_080A3324:
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _080A3336
	movs r1, #0
	bl Script_ExecById
_080A3336:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A333C: .4byte FUN_080a2e20

	thumb_func_start FUN_080a3340
FUN_080a3340: @ 0x080A3340
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #2
	bls _080A3370
	subs r0, #2
	strb r0, [r2]
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
	b _080A3378
_080A3370:
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
_080A3378:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A3388
	subs r0, #1
	strh r0, [r1]
_080A3388:
	ldrh r0, [r1]
	cmp r0, #7
	bls _080A33A2
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl FUN_0822b20c
	b _080A33CA
_080A33A2:
	cmp r0, #0
	beq _080A33BA
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl FUN_0822b20c
	b _080A33CA
_080A33BA:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl FUN_0822b20c
_080A33CA:
	ldr r0, _080A3424 @ =0x00000382
	adds r3, r4, r0
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bhi _080A3428
	ldr r0, [r4, #0x50]
	movs r2, #2
	orrs r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r1, [r3]
	movs r0, #0x40
	subs r0, r0, r1
	adds r2, r4, #0
	adds r2, #0x58
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x59
	strb r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r3, r4, #0
	adds r3, #0x56
	strb r0, [r3]
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0xa8
	strb r1, [r0]
	ldrb r0, [r2]
	adds r1, r4, #0
	adds r1, #0xa9
	strb r0, [r1]
	ldrb r1, [r3]
	adds r0, r4, #0
	adds r0, #0xa6
	strb r1, [r0]
	b _080A3440
	.align 2, 0
_080A3424: .4byte 0x00000382
_080A3428:
	ldr r0, [r4, #0x50]
	movs r2, #1
	orrs r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	bl KillEntity
_080A3440:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a3448
FUN_080a3448: @ 0x080A3448
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0x18
	movs r5, #0
	ldr r2, _080A3494 @ =0x03002B4C
	ldr r1, [r2]
	adds r1, #0x24
	adds r0, #0x1e
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	bge _080A34C4
	mov r8, r2
_080A346A:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r6, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #7
	beq _080A3498
	cmp r0, #8
	beq _080A34A8
	b _080A34B0
	.align 2, 0
_080A3494: .4byte 0x03002B4C
_080A3498:
	adds r0, r7, #0
	ldr r1, _080A34A4 @ =FUN_080a2a4c
	bl FUN_080a2a14
	b _080A34B0
	.align 2, 0
_080A34A4: .4byte FUN_080a2a4c
_080A34A8:
	adds r0, r7, #0
	ldr r1, _080A34D0 @ =FUN_080a2b78
	bl FUN_080a2a14
_080A34B0:
	adds r5, #1
	mov r0, r8
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r6, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	blt _080A346A
_080A34C4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A34D0: .4byte FUN_080a2b78

	thumb_func_start FUN_080a34d4
FUN_080a34d4: @ 0x080A34D4
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080a3448
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r5, #0
_080A34EC:
	movs r0, #0x34
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, r1
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A350A
	subs r2, #0x28
	adds r0, r1, r2
	adds r0, r4, r0
	bl FUN_080a251c
_080A350A:
	adds r5, #1
	cmp r5, #7
	ble _080A34EC
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a3518
FUN_080a3518: @ 0x080A3518
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r0, #0x50
	bl FUN_0822a4e0
	adds r0, r6, #0
	adds r0, #0xa0
	bl FUN_0822a4e0
	adds r4, r6, #0
	adds r4, #0xe8
	movs r5, #2
_080A3530:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _080A3530
	adds r7, r6, #0
	adds r7, #0x18
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #7
_080A354A:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080A354A
	adds r0, r7, #0
	bl FUN_08022428
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a3568
FUN_080a3568: @ 0x080A3568
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _080A35F8 @ =0x00001C1E
	mov sb, r0
	movs r0, #0
	mov sl, r0
	subs r0, #4
	mov r8, r0
_080A3582:
	movs r0, #0x34
	adds r5, r7, #0
	muls r5, r0, r5
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r5, r0
	adds r4, r6, r4
	mov r0, sb
	bl GetParticleGroup
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, r8
	mov r2, r8
	bl FUN_0822dad4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	mov r0, sb
	bl GetParticleGroup
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	movs r0, #1
	strb r0, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	adds r0, r6, #0
	adds r0, #0x98
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	adds r5, r6, r5
	movs r0, #0xf8
	lsls r0, r0, #1
	adds r5, r5, r0
	mov r0, sl
	strb r0, [r5]
	adds r7, #1
	cmp r7, #7
	ble _080A3582
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A35F8: .4byte 0x00001C1E

	thumb_func_start FUN_080a35fc
FUN_080a35fc: @ 0x080A35FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	str r1, [sp]
	movs r0, #0x70
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080A36BC
	bl Script_GetValue
	adds r4, r7, #0
	adds r4, #0x98
	strh r0, [r4]
	bl Script_GetValue
	adds r5, r7, #0
	adds r5, #0x9a
	strh r0, [r5]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x9c
	strh r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0xc]
	cmp r2, #0
	blt _080A365C
	cmp r1, #0
	blt _080A365C
	ldr r0, _080A3660 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A365C
	ldr r0, _080A3664 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A3668
_080A365C:
	movs r6, #0
	b _080A3676
	.align 2, 0
_080A3660: .4byte 0x030046A8
_080A3664: .4byte 0x030046AC
_080A3668:
	ldr r0, _080A3688 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080A3676:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A368C
	adds r0, #4
	b _080A3698
	.align 2, 0
_080A3688: .4byte 0x030046A4
_080A368C:
	ldr r0, _080A36AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A3698:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A36B0
	cmp r2, #2
	beq _080A36B4
	b _080A36B8
	.align 2, 0
_080A36AC: .4byte 0x030046A4
_080A36B0:
	ldrb r0, [r4, #4]
	b _080A36B6
_080A36B4:
	ldrb r0, [r4]
_080A36B6:
	subs r1, r1, r0
_080A36B8:
	strh r1, [r5]
	b _080A36CE
_080A36BC:
	adds r1, r7, #0
	adds r1, #0x98
	strh r2, [r1]
	adds r0, r7, #0
	adds r0, #0x9a
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	str r1, [sp, #0xc]
_080A36CE:
	movs r0, #0x43
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A36E8
	bl Script_GetValue
	movs r2, #0xdb
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A36F0
_080A36E8:
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A36F0:
	movs r0, #0x63
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A370A
	bl Script_GetValue
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A3712
_080A370A:
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A3712:
	movs r0, #0x69
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A372C
	bl Script_GetValue
	movs r2, #0xdc
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A3734
_080A372C:
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A3734:
	movs r0, #0x6f
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A374E
	bl Script_GetValue
	movs r2, #0xdd
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A3756
_080A374E:
	movs r3, #0xdd
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A3756:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _080A376A
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x4e
	b _080A3770
_080A376A:
	adds r1, r7, #0
	adds r1, #0x4e
	movs r0, #6
_080A3770:
	strh r0, [r1]
	mov sl, r1
	movs r0, #0x61
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A3790
	bl Script_GetValue
	ldr r2, _080A378C @ =0x00000369
	adds r1, r7, r2
	strb r0, [r1]
	b _080A3796
	.align 2, 0
_080A378C: .4byte 0x00000369
_080A3790:
	ldr r3, _080A37B0 @ =0x00000369
	adds r0, r7, r3
	strb r1, [r0]
_080A3796:
	movs r0, #0x6e
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A37B4
	bl Script_GetValue
	movs r2, #0xde
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A37BC
	.align 2, 0
_080A37B0: .4byte 0x00000369
_080A37B4:
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A37BC:
	mov r1, sl
	ldrh r0, [r1]
	lsrs r0, r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, #0x61
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r6, r7, r2
	strh r1, [r6]
	movs r3, #0x7c
	adds r3, r3, r7
	mov r8, r3
	ldr r5, _080A3930 @ =0x00000BA8
	mov r0, r8
	adds r1, r5, #0
	bl Video_GetActorSprite
	adds r4, r7, #0
	adds r4, #0x50
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl FUN_0822a470
	mov r1, sl
	ldrh r0, [r1]
	strh r0, [r4, #0x10]
	ldrh r1, [r6]
	mov r0, r8
	bl FUN_0822b20c
	ldr r0, [r7, #0x50]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r7, #0x50]
	adds r0, r7, #0
	adds r0, #0x57
	movs r2, #3
	mov sb, r2
	mov r3, sb
	strb r3, [r0]
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x6c]
	str r1, [r7, #0x70]
	adds r4, #0x7c
	adds r0, r4, #0
	adds r1, r5, #0
	bl Video_GetActorSprite
	adds r5, r7, #0
	adds r5, #0xa0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	mov r3, sl
	ldrh r0, [r3]
	strh r0, [r5, #0x10]
	ldrh r1, [r6]
	adds r0, r4, #0
	bl FUN_0822b20c
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r5]
	adds r0, r7, #0
	adds r0, #0xa7
	mov r1, sb
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0xbc
	ldr r3, [sp, #0xc]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0
	mov sb, r0
	mov r1, r8
	str r1, [sp, #8]
	mov r8, r5
	adds r2, #0x2c
	str r2, [sp, #0x10]
	adds r3, r7, #0
	adds r3, #0x18
	str r3, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0x4c
	str r0, [sp, #4]
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r6, r7, r1
_080A3882:
	adds r0, r6, #0
	ldr r1, _080A3930 @ =0x00000BA8
	bl Video_GetActorSprite
	movs r0, #0x2c
	mov r4, sb
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, #0xe8
	adds r0, r7, r0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822a470
	mov r2, sl
	ldrh r0, [r2]
	movs r5, #1
	adds r1, r5, #0
	ands r1, r0
	adds r0, r4, r7
	adds r0, #0xe8
	adds r1, #0x10
	strh r1, [r0, #0x10]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	adds r1, #2
	adds r0, r6, #0
	bl FUN_0822b20c
	ldr r0, [sp, #0x10]
	adds r2, r0, r4
	ldr r0, [r2]
	ldr r1, _080A3934 @ =0x00000201
	orrs r0, r1
	str r0, [r2]
	adds r1, r7, r4
	adds r0, r1, #0
	adds r0, #0xef
	movs r2, #1
	strb r2, [r0]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r2, r1, r3
	ldr r3, [sp, #0xc]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r6, #0x1c
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #2
	ble _080A3882
	adds r0, r7, #0
	bl FUN_080a3568
	ldr r0, [sp, #0x14]
	ldr r1, [sp]
	movs r2, #0xa
	bl FUN_080223f4
	movs r0, #0x44
	bl prepare_08231510
	cmp r0, #0
	beq _080A3940
	movs r2, #0
	movs r1, #0
	ldr r3, [sp, #4]
	strh r1, [r3]
	movs r3, #0xe3
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	ldr r3, _080A3938 @ =0x0000036A
	adds r0, r7, r3
	strh r1, [r0]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, _080A393C @ =FUN_080a2a2c
	b _080A3A70
	.align 2, 0
_080A3930: .4byte 0x00000BA8
_080A3934: .4byte 0x00000201
_080A3938: .4byte 0x0000036A
_080A393C: .4byte FUN_080a2a2c
_080A3940:
	movs r4, #0
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A3952
	bl Script_GetValue
	adds r4, r0, #0
_080A3952:
	movs r6, #0
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080A3964
	bl Script_GetValue
	adds r6, r0, #0
_080A3964:
	cmp r4, #0
	beq _080A3A24
	movs r0, #0xb0
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r5, [r0]
	movs r0, #0
	bl FUN_080a6e88
	ldr r4, _080A3A18 @ =0x03002BE0
	ldr r0, [r4]
	ldr r1, [sp, #0xc]
	bl FUN_0807a91c
	ldr r0, [r4]
	bl FUN_0807b8dc
	ldr r0, [r7, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x50]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	adds r1, #2
	ldr r0, [sp, #8]
	bl FUN_0822b20c
	mov r1, r8
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #7
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_080a2804
	movs r3, #0xe3
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #8
	strh r0, [r1]
	ldr r0, [sp, #4]
	strh r5, [r0]
	ldr r2, _080A3A1C @ =0x0000036A
	adds r1, r7, r2
	movs r0, #0xa
	strh r0, [r1]
	movs r3, #0xda
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0x18
	strb r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r7, r1
	strb r6, [r0]
	ldr r1, _080A3A20 @ =FUN_080a31dc
	adds r0, r7, #0
	bl FUN_080a2a14
	movs r4, #0
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _080A3A02
	bl Script_GetValue
	adds r4, r0, #0
_080A3A02:
	cmp r4, #0
	beq _080A3A88
	bl FUN_08086af0
	cmp r0, #0
	beq _080A3A88
	ldr r0, [sp, #0xc]
	bl FUN_08086a4c
	b _080A3A88
	.align 2, 0
_080A3A18: .4byte 0x03002BE0
_080A3A1C: .4byte 0x0000036A
_080A3A20: .4byte FUN_080a31dc
_080A3A24:
	movs r0, #0
	ldr r2, [sp, #4]
	strh r4, [r2]
	movs r3, #0xe3
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r4, [r1]
	ldr r2, _080A3A78 @ =0x0000036A
	adds r1, r7, r2
	strh r4, [r1]
	movs r3, #0xda
	lsls r3, r3, #2
	adds r1, r7, r3
	strb r0, [r1]
	cmp r6, #0
	beq _080A3A80
	movs r0, #0xaf
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, [r7, #0x50]
	movs r1, #2
	orrs r0, r1
	str r0, [r7, #0x50]
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r7, #0
	adds r0, #0x58
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #0x4f
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	ldr r1, _080A3A7C @ =FUN_080a2d18
_080A3A70:
	adds r0, r7, #0
	bl FUN_080a2a14
	b _080A3A88
	.align 2, 0
_080A3A78: .4byte 0x0000036A
_080A3A7C: .4byte FUN_080a2d18
_080A3A80:
	ldr r1, _080A3A9C @ =FUN_080a2e20
	adds r0, r7, #0
	bl FUN_080a2a14
_080A3A88:
	movs r0, #0
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A3A9C: .4byte FUN_080a2e20

	thumb_func_start FUN_080a3aa0
FUN_080a3aa0: @ 0x080A3AA0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0xe2
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A3AE0
	ldr r1, _080A3AD8 @ =FUN_080a34d4
	ldr r2, _080A3ADC @ =FUN_080a3518
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a35fc
	cmp r0, #0
	bge _080A3AE0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A3AE2
	.align 2, 0
_080A3AD8: .4byte FUN_080a34d4
_080A3ADC: .4byte FUN_080a3518
_080A3AE0:
	adds r0, r4, #0
_080A3AE2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a3ae8
FUN_080a3ae8: @ 0x080A3AE8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A3B5C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _080A3B64
	ldr r0, _080A3B60 @ =0x03002BE0
	ldr r3, [r0]
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A3B64
	movs r1, #0x2c
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0xac
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r2, r0, r1
	cmp r2, #0
	bge _080A3B26
	rsbs r2, r2, #0
_080A3B26:
	movs r1, #0x30
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0xb0
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r0, r1
	cmp r1, #0
	bge _080A3B3A
	rsbs r1, r1, #0
_080A3B3A:
	cmp r2, #0x60
	bgt _080A3B64
	cmp r1, #0x60
	bgt _080A3B64
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x90
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080A3B64
	movs r0, #1
	b _080A3B66
	.align 2, 0
_080A3B5C: .4byte 0x030046A0
_080A3B60: .4byte 0x03002BE0
_080A3B64:
	movs r0, #0
_080A3B66:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a3b6c
FUN_080a3b6c: @ 0x080A3B6C
	adds r2, r0, #0
	movs r3, #0x88
	lsls r3, r3, #1
	adds r0, r2, r3
	str r1, [r0]
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a3b84
FUN_080a3b84: @ 0x080A3B84
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080A3BE4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A3BA6
	movs r0, #0x81
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #9
	bhi _080A3BA6
	adds r0, #1
	strh r0, [r1]
_080A3BA6:
	adds r0, r4, #0
	bl FUN_080a3ae8
	adds r5, r0, #0
	cmp r5, #0
	beq _080A3C44
	ldrb r0, [r4, #0x1a]
	cmp r0, #1
	beq _080A3BC4
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4, #0x1a]
_080A3BC4:
	adds r0, r4, #0
	adds r0, #0xfe
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #7
	bhi _080A3BD4
	adds r0, r1, #1
	strh r0, [r6]
_080A3BD4:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x16
	bhi _080A3BE8
	adds r0, #2
	b _080A3BEA
	.align 2, 0
_080A3BE4: .4byte 0x030047A4
_080A3BE8:
	movs r0, #0x18
_080A3BEA:
	strh r0, [r1]
	movs r2, #1
	ldr r0, _080A3C34 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080A3C7A
	ldr r0, _080A3C38 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080A3C7A
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #9
	bls _080A3C7A
	movs r0, #8
	strh r0, [r6]
	movs r0, #1
	bl FUN_080a6e88
	ldr r0, _080A3C3C @ =0x03002BE0
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xac
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	ldr r1, _080A3C40 @ =FUN_080a3cec
	adds r0, r4, #0
	bl FUN_080a3b6c
	b _080A3C7A
	.align 2, 0
_080A3C34: .4byte 0x03002BC0
_080A3C38: .4byte 0x030044E0
_080A3C3C: .4byte 0x03002BE0
_080A3C40: .4byte FUN_080a3cec
_080A3C44:
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	beq _080A3C52
	ldr r0, _080A3C74 @ =0x00000199
	bl PlaySound_082406e0
	strb r5, [r4, #0x1a]
_080A3C52:
	adds r0, r4, #0
	adds r0, #0xfe
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _080A3C62
	subs r0, r1, #1
	strh r0, [r6]
_080A3C62:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #2
	bls _080A3C78
	subs r0, #2
	strh r0, [r1]
	b _080A3C7A
	.align 2, 0
_080A3C74: .4byte 0x00000199
_080A3C78:
	strh r5, [r1]
_080A3C7A:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r0, [r2]
	cmp r0, #0
	bne _080A3C90
	ldr r0, [r4, #0x64]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x64]
	b _080A3CAA
_080A3C90:
	ldr r0, [r4, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0xae
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x82
	strh r0, [r1]
_080A3CAA:
	ldrh r0, [r6]
	cmp r0, #7
	bls _080A3CC2
	adds r0, r4, #0
	adds r0, #0x90
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r1, [r1]
	adds r1, #2
	bl FUN_0822b20c
	b _080A3CE6
_080A3CC2:
	cmp r0, #0
	beq _080A3CD8
	adds r0, r4, #0
	adds r0, #0x90
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r1, [r1]
	adds r1, #1
	bl FUN_0822b20c
	b _080A3CE6
_080A3CD8:
	adds r0, r4, #0
	adds r0, #0x90
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r1, [r1]
	bl FUN_0822b20c
_080A3CE6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a3cec
FUN_080a3cec: @ 0x080A3CEC
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #1
	bls _080A3D02
	subs r0, #2
	b _080A3D04
_080A3D02:
	movs r0, #0
_080A3D04:
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0xae
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r1, r2
	adds r2, r4, #0
	adds r2, #0x82
	strh r1, [r2]
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A3D8A
	ldr r0, _080A3D94 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A3D8A
	ldr r0, [r4, #0x64]
	ldr r1, _080A3D98 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x6b
	movs r0, #3
	strb r0, [r1]
	adds r2, #0x32
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080A3D9C @ =FUN_080a3da4
	adds r0, r4, #0
	bl FUN_080a3b6c
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A3D8A
	ldr r1, _080A3DA0 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	add r1, sp, #8
	mov r3, sp
	str r3, [r1, #4]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp]
	adds r3, #2
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r2, #0
	bl Script_ExecById
_080A3D8A:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3D94: .4byte 0x03002BE0
_080A3D98: .4byte 0xFFFFFDFF
_080A3D9C: .4byte FUN_080a3da4
_080A3DA0: .4byte 0xFFFF0000

	thumb_func_start FUN_080a3da4
FUN_080a3da4: @ 0x080A3DA4
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a3da8
FUN_080a3da8: @ 0x080A3DA8
	push {lr}
	movs r2, #0x88
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_080a3dbc
FUN_080a3dbc: @ 0x080A3DBC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x64
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0xb4
	bl FUN_0822a4e0
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _080A3DDC
	adds r0, r4, #0
	adds r0, #0x20
	bl FUN_0823b284
_080A3DDC:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a3de4
FUN_080a3de4: @ 0x080A3DE4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	strh r1, [r7, #0x18]
	movs r0, #0x70
	bl prepare_08231510
	adds r3, r0, #0
	cmp r3, #0
	beq _080A3EA4
	bl Script_GetValue
	adds r4, r7, #0
	adds r4, #0xac
	strh r0, [r4]
	bl Script_GetValue
	adds r5, r7, #0
	adds r5, #0xae
	strh r0, [r5]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0xb0
	strh r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0xc]
	cmp r2, #0
	blt _080A3E44
	cmp r1, #0
	blt _080A3E44
	ldr r0, _080A3E48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A3E44
	ldr r0, _080A3E4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A3E50
_080A3E44:
	movs r6, #0
	b _080A3E5E
	.align 2, 0
_080A3E48: .4byte 0x030046A8
_080A3E4C: .4byte 0x030046AC
_080A3E50:
	ldr r0, _080A3E70 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080A3E5E:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A3E74
	adds r0, #4
	b _080A3E80
	.align 2, 0
_080A3E70: .4byte 0x030046A4
_080A3E74:
	ldr r0, _080A3E94 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A3E80:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A3E98
	cmp r2, #2
	beq _080A3E9C
	b _080A3EA0
	.align 2, 0
_080A3E94: .4byte 0x030046A4
_080A3E98:
	ldrb r0, [r4, #4]
	b _080A3E9E
_080A3E9C:
	ldrb r0, [r4]
_080A3E9E:
	subs r1, r1, r0
_080A3EA0:
	strh r1, [r5]
	b _080A3EB6
_080A3EA4:
	adds r1, r7, #0
	adds r1, #0xac
	strh r3, [r1]
	adds r0, r7, #0
	adds r0, #0xae
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	str r1, [sp, #0xc]
_080A3EB6:
	movs r0, #0x73
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A3ED0
	bl Script_GetValue
	movs r2, #0x84
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
	b _080A3ED8
_080A3ED0:
	movs r2, #0x84
	lsls r2, r2, #1
	adds r0, r7, r2
	str r1, [r0]
_080A3ED8:
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _080A3F2C
	adds r0, r7, #0
	adds r0, #0xfc
	str r0, [sp, #8]
	movs r1, #0x90
	adds r1, r1, r7
	mov r8, r1
	adds r2, r7, #0
	adds r2, #0x64
	str r2, [sp, #0x18]
	subs r0, #0x91
	str r0, [sp, #0x1c]
	adds r1, r7, #0
	adds r1, #0x80
	str r1, [sp, #0x20]
	movs r2, #0xe0
	adds r2, r2, r7
	mov sl, r2
	movs r0, #0xb4
	adds r0, r0, r7
	mov sb, r0
	adds r1, #0x3b
	str r1, [sp, #0x10]
	adds r2, r7, #0
	adds r2, #0xd0
	str r2, [sp, #0x14]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r7, r0
	movs r5, #1
_080A3F1C:
	bl Script_GetValue
	strh r0, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _080A3F1C
	b _080A3F72
_080A3F2C:
	adds r1, r7, #0
	adds r1, #0xfc
	str r1, [sp, #8]
	movs r2, #0x90
	adds r2, r2, r7
	mov r8, r2
	adds r0, r7, #0
	adds r0, #0x64
	str r0, [sp, #0x18]
	subs r1, #0x91
	str r1, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x80
	str r2, [sp, #0x20]
	movs r0, #0xe0
	adds r0, r0, r7
	mov sl, r0
	movs r1, #0xb4
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0x3b
	str r2, [sp, #0x10]
	adds r0, r7, #0
	adds r0, #0xd0
	str r0, [sp, #0x14]
	movs r1, #0
	movs r5, #1
	movs r2, #0x83
	lsls r2, r2, #1
	adds r0, r7, r2
_080A3F68:
	strh r1, [r0]
	subs r0, #2
	subs r5, #1
	cmp r5, #0
	bge _080A3F68
_080A3F72:
	movs r0, #0x68
	bl prepare_08231510
	cmp r0, #0
	beq _080A3F80
	bl Script_GetValue
_080A3F80:
	strb r0, [r7, #0x1b]
	ldrb r0, [r7, #0x1b]
	cmp r0, #0
	beq _080A3FA4
	adds r4, r7, #0
	adds r4, #0x20
	ldrh r1, [r7, #0x18]
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	ldr r2, [sp, #0xc]
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	bl FUN_08002a48
_080A3FA4:
	movs r0, #0x6a
	ldr r1, [sp, #8]
	strh r0, [r1]
	ldr r6, _080A4044 @ =0x00000BA8
	mov r0, r8
	adds r1, r6, #0
	bl Video_GetActorSprite
	ldr r0, [sp, #0x18]
	mov r1, r8
	movs r2, #0
	bl FUN_0822a470
	movs r5, #7
	ldr r2, [sp, #0x18]
	strh r5, [r2, #0x10]
	ldr r0, [sp, #8]
	ldrh r1, [r0]
	mov r0, r8
	bl FUN_0822b20c
	ldr r0, [r7, #0x64]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r7, #0x64]
	movs r4, #3
	ldr r1, [sp, #0x1c]
	strb r4, [r1]
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r2, [sp, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, sl
	adds r1, r6, #0
	bl Video_GetActorSprite
	mov r0, sb
	mov r1, sl
	movs r2, #0
	bl FUN_0822a470
	mov r0, sb
	strh r5, [r0, #0x10]
	ldr r2, [sp, #8]
	ldrh r1, [r2]
	mov r0, sl
	bl FUN_0822b20c
	mov r1, sb
	ldr r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	mov r2, sb
	str r0, [r2]
	ldr r0, [sp, #0x10]
	strb r4, [r0]
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r2, [sp, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _080A4048 @ =FUN_080a3b84
	adds r0, r7, #0
	bl FUN_080a3b6c
	movs r0, #0
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A4044: .4byte 0x00000BA8
_080A4048: .4byte FUN_080a3b84

	thumb_func_start FUN_080a404c
FUN_080a404c: @ 0x080A404C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x8a
	lsls r1, r1, #1
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A408C
	ldr r1, _080A4084 @ =FUN_080a3da8
	ldr r2, _080A4088 @ =FUN_080a3dbc
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a3de4
	cmp r0, #0
	bge _080A408C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A408E
	.align 2, 0
_080A4084: .4byte FUN_080a3da8
_080A4088: .4byte FUN_080a3dbc
_080A408C:
	adds r0, r4, #0
_080A408E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a4094
FUN_080a4094: @ 0x080A4094
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A40E4 @ =0x030046A0
	ldr r3, [r0]
	movs r0, #0x30
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x64
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	cmp r2, #0
	bge _080A40B0
	rsbs r2, r2, #0
_080A40B0:
	movs r1, #0x34
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0x68
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r0, r1
	cmp r1, #0
	bge _080A40C4
	rsbs r1, r1, #0
_080A40C4:
	cmp r2, #0x60
	bgt _080A40E8
	cmp r1, #0x60
	bgt _080A40E8
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x90
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080A40E8
	movs r0, #1
	b _080A40EA
	.align 2, 0
_080A40E4: .4byte 0x030046A0
_080A40E8:
	movs r0, #0
_080A40EA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a40f0
FUN_080a40f0: @ 0x080A40F0
	adds r2, r0, #0
	adds r2, #0xc8
	str r1, [r2]
	adds r0, #0xc4
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a4100
FUN_080a4100: @ 0x080A4100
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _080A4160 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A4120
	adds r1, r4, #0
	adds r1, #0xba
	ldrh r0, [r1]
	cmp r0, #9
	bhi _080A4120
	adds r0, #1
	strh r0, [r1]
_080A4120:
	adds r0, r4, #0
	bl FUN_080a4094
	adds r6, r0, #0
	cmp r6, #0
	beq _080A41CC
	ldrh r0, [r4, #0x18]
	cmp r0, #1
	beq _080A413E
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strh r0, [r4, #0x18]
_080A413E:
	adds r0, r4, #0
	adds r0, #0xb6
	ldrh r1, [r0]
	adds r7, r0, #0
	cmp r1, #7
	bhi _080A414E
	adds r0, r1, #1
	strh r0, [r7]
_080A414E:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	adds r5, r0, #0
	cmp r1, #0x16
	bhi _080A4164
	adds r0, r1, #2
	b _080A4166
	.align 2, 0
_080A4160: .4byte 0x030047A4
_080A4164:
	movs r0, #0x18
_080A4166:
	strh r0, [r5]
	movs r2, #1
	ldr r0, _080A41BC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080A4202
	ldr r0, _080A41C0 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080A4202
	ldr r6, _080A41C4 @ =0x03002BE0
	ldr r0, [r6]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A4202
	adds r0, r4, #0
	adds r0, #0xba
	ldrh r0, [r0]
	cmp r0, #9
	bls _080A4202
	movs r0, #8
	strh r0, [r7]
	movs r0, #1
	bl FUN_080a6e88
	ldr r0, [r6]
	adds r1, r4, #0
	adds r1, #0x64
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	ldr r1, _080A41C8 @ =FUN_080a4250
	adds r0, r4, #0
	bl FUN_080a40f0
	b _080A4202
	.align 2, 0
_080A41BC: .4byte 0x03002BC0
_080A41C0: .4byte 0x030044E0
_080A41C4: .4byte 0x03002BE0
_080A41C8: .4byte FUN_080a4250
_080A41CC:
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	beq _080A41DA
	ldr r0, _080A41FC @ =0x00000199
	bl PlaySound_082406e0
	strh r6, [r4, #0x18]
_080A41DA:
	adds r0, r4, #0
	adds r0, #0xb6
	ldrh r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	beq _080A41EA
	subs r0, r1, #1
	strh r0, [r7]
_080A41EA:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	adds r5, r0, #0
	cmp r1, #2
	bls _080A4200
	subs r0, r1, #2
	strh r0, [r5]
	b _080A4202
	.align 2, 0
_080A41FC: .4byte 0x00000199
_080A4200:
	strh r6, [r5]
_080A4202:
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A4212
	ldr r0, [r4, #0x1c]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x1c]
	b _080A4228
_080A4212:
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x66
	ldrh r0, [r5]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x3a]
_080A4228:
	ldrh r0, [r7]
	cmp r0, #7
	bls _080A423C
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #0x8f
	lsls r1, r1, #1
	bl FUN_0822b20c
	b _080A424A
_080A423C:
	adds r0, r4, #0
	adds r0, #0x48
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r1, [r1]
	bl FUN_0822b20c
_080A424A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a4250
FUN_080a4250: @ 0x080A4250
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb8
	ldrh r0, [r1]
	cmp r0, #1
	bls _080A4264
	subs r0, #2
	b _080A4266
_080A4264:
	movs r0, #0
_080A4266:
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0x66
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r4, #0x3a]
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A42E0
	ldr r0, _080A42E8 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A42E0
	ldr r0, [r4, #0x1c]
	ldr r1, _080A42EC @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x23
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r4, #0x6c]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x6c]
	ldr r1, _080A42F0 @ =FUN_080a42f8
	adds r0, r4, #0
	bl FUN_080a40f0
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r2, [r0]
	cmp r2, #0
	beq _080A42E0
	ldr r1, _080A42F4 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	add r1, sp, #8
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0xbe
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r2, #0
	bl Script_ExecById
_080A42E0:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A42E8: .4byte 0x03002BE0
_080A42EC: .4byte 0xFFFFFDFF
_080A42F0: .4byte FUN_080a42f8
_080A42F4: .4byte 0xFFFF0000

	thumb_func_start FUN_080a42f8
FUN_080a42f8: @ 0x080A42F8
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a42fc
FUN_080a42fc: @ 0x080A42FC
	push {lr}
	adds r1, r0, #0
	adds r1, #0xc8
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a4310
FUN_080a4310: @ 0x080A4310
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	bl FUN_0822a4e0
	adds r4, #0x6c
	adds r0, r4, #0
	bl FUN_0822a4e0
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a432c
FUN_080a432c: @ 0x080A432C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A4348
	bl Script_GetValue
_080A4348:
	strb r0, [r6, #0x1a]
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A43FC
	bl Script_GetValue
	adds r4, r6, #0
	adds r4, #0x64
	strh r0, [r4]
	bl Script_GetValue
	adds r5, r6, #0
	adds r5, #0x66
	strh r0, [r5]
	bl Script_GetValue
	adds r1, r6, #0
	adds r1, #0x68
	strh r0, [r1]
	adds r7, r4, #0
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A439A
	cmp r1, #0
	blt _080A439A
	ldr r0, _080A43A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A439A
	ldr r0, _080A43A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A43A8
_080A439A:
	movs r4, #0
	b _080A43B6
	.align 2, 0
_080A43A0: .4byte 0x030046A8
_080A43A4: .4byte 0x030046AC
_080A43A8:
	ldr r0, _080A43C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A43B6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A43CC
	adds r0, #4
	b _080A43D8
	.align 2, 0
_080A43C8: .4byte 0x030046A4
_080A43CC:
	ldr r0, _080A43EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A43D8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A43F0
	cmp r2, #2
	beq _080A43F4
	b _080A43F8
	.align 2, 0
_080A43EC: .4byte 0x030046A4
_080A43F0:
	ldrb r0, [r7, #4]
	b _080A43F6
_080A43F4:
	ldrb r0, [r7]
_080A43F6:
	subs r1, r1, r0
_080A43F8:
	strh r1, [r5]
	b _080A440A
_080A43FC:
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_080A440A:
	movs r0, #0x52
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A4422
	bl Script_GetValue
	adds r1, r6, #0
	adds r1, #0xc0
	str r0, [r1]
	b _080A4428
_080A4422:
	adds r0, r6, #0
	adds r0, #0xc0
	str r1, [r0]
_080A4428:
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _080A4474
	movs r0, #0xb4
	adds r0, r0, r6
	mov r8, r0
	adds r7, r6, #0
	adds r7, #0x48
	movs r1, #0x1c
	adds r1, r1, r6
	mov sl, r1
	adds r2, r6, #0
	adds r2, #0x23
	str r2, [sp, #0xc]
	movs r0, #0x98
	adds r0, r0, r6
	mov sb, r0
	adds r1, r6, #0
	adds r1, #0x6c
	str r1, [sp]
	adds r2, #0x50
	str r2, [sp, #4]
	adds r0, r6, #0
	adds r0, #0x88
	str r0, [sp, #8]
	adds r4, r6, #0
	adds r4, #0xbc
	movs r5, #1
_080A4464:
	bl Script_GetValue
	strh r0, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _080A4464
	b _080A44AE
_080A4474:
	movs r1, #0xb4
	adds r1, r1, r6
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0x48
	movs r2, #0x1c
	adds r2, r2, r6
	mov sl, r2
	adds r0, r6, #0
	adds r0, #0x23
	str r0, [sp, #0xc]
	movs r1, #0x98
	adds r1, r1, r6
	mov sb, r1
	adds r2, r6, #0
	adds r2, #0x6c
	str r2, [sp]
	adds r0, #0x50
	str r0, [sp, #4]
	adds r1, r6, #0
	adds r1, #0x88
	str r1, [sp, #8]
	adds r1, #0x34
	movs r2, #0
	adds r0, #0x4b
_080A44A6:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _080A44A6
_080A44AE:
	ldrb r0, [r6, #0x1a]
	cmp r0, #0
	bne _080A44BE
	movs r0, #0x8e
	lsls r0, r0, #1
	mov r2, r8
	strh r0, [r2]
	b _080A44C4
_080A44BE:
	ldr r0, _080A4548 @ =0x0000011D
	mov r1, r8
	strh r0, [r1]
_080A44C4:
	ldr r5, _080A454C @ =0x0000A152
	adds r0, r7, #0
	adds r1, r5, #0
	bl Video_GetActorSprite
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0822a470
	mov r2, r8
	ldrh r1, [r2]
	adds r0, r7, #0
	bl FUN_0822b20c
	ldr r0, [r6, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r6, #0x1c]
	movs r4, #3
	ldr r0, [sp, #0xc]
	strb r4, [r0]
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
	mov r0, sb
	adds r1, r5, #0
	bl Video_GetActorSprite
	ldr r0, [sp]
	mov r1, sb
	movs r2, #0
	bl FUN_0822a470
	mov r2, r8
	ldrh r1, [r2]
	mov r0, sb
	bl FUN_0822b20c
	ldr r0, [r6, #0x6c]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r6, #0x6c]
	ldr r0, [sp, #4]
	strb r4, [r0]
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	ldr r2, [sp, #8]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _080A4550 @ =FUN_080a4100
	adds r0, r6, #0
	bl FUN_080a40f0
	movs r0, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A4548: .4byte 0x0000011D
_080A454C: .4byte 0x0000A152
_080A4550: .4byte FUN_080a4100

	thumb_func_start FUN_080a4554
FUN_080a4554: @ 0x080A4554
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #9
	movs r1, #0xcc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4590
	ldr r1, _080A4588 @ =FUN_080a42fc
	ldr r2, _080A458C @ =FUN_080a4310
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a432c
	cmp r0, #0
	bge _080A4590
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A4592
	.align 2, 0
_080A4588: .4byte FUN_080a42fc
_080A458C: .4byte FUN_080a4310
_080A4590:
	adds r0, r4, #0
_080A4592:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a4598
FUN_080a4598: @ 0x080A4598
	movs r3, #0x84
	lsls r3, r3, #1
	adds r2, r0, r3
	str r1, [r2]
	adds r0, #0xec
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start FUN_080a45a8
FUN_080a45a8: @ 0x080A45A8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0xe4
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A45DE
	ldr r0, [r4]
	movs r1, #4
	ands r0, r1
	movs r5, #1
	cmp r0, #0
	beq _080A45C4
	movs r5, #2
_080A45C4:
	adds r0, r4, #0
	adds r0, #0xde
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080A45D4
	asrs r0, r0, #8
	b _080A45DA
_080A45D4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A45DA:
	adds r3, r0, #1
	b _080A45F6
_080A45DE:
	movs r5, #0
	adds r0, r4, #0
	adds r0, #0xde
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080A45F0
	asrs r3, r0, #8
	b _080A45F6
_080A45F0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r3, r0, #0
_080A45F6:
	adds r0, r4, #0
	adds r0, #0xf8
	adds r1, r4, #0
	adds r1, #0xea
	ldrh r1, [r1]
	movs r2, #0xff
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	adds r2, r5, #0
	bl FUN_08234270
	adds r1, r4, #0
	adds r1, #0xf7
	movs r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a4620
FUN_080a4620: @ 0x080A4620
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r2, #0
	adds r4, #0xf4
	ldrb r0, [r4]
	cmp r0, #0
	bne _080A465C
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _080A465C
	ldr r0, _080A4664 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A4668 @ =0x00000942
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0xf0
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0x20
	strb r0, [r4]
	ldr r0, _080A466C @ =0x03002C44
	ldr r1, [r0]
	movs r0, #1
	strb r0, [r1, #0x19]
_080A465C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4664: .4byte 0x030046A0
_080A4668: .4byte 0x00000942
_080A466C: .4byte 0x03002C44

	thumb_func_start FUN_080a4670
FUN_080a4670: @ 0x080A4670
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xf0
	adds r1, r4, #0
	adds r1, #0xf2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	blo _080A46A4
	adds r1, r4, #0
	adds r1, #0xf6
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080a45a8
	adds r2, r4, #0
	adds r2, #0x4e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080A46AC @ =FUN_080a46b0
	adds r0, r4, #0
	bl FUN_080a4598
_080A46A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A46AC: .4byte FUN_080a46b0

	thumb_func_start FUN_080a46b0
FUN_080a46b0: @ 0x080A46B0
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r6, #2
	strb r6, [r5, #7]
	adds r4, r5, #0
	adds r4, #0xec
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A46CC
	movs r0, #0xd5
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080A46CC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080A46E0
	movs r0, #1
	strh r0, [r5, #0x10]
	b _080A4718
_080A46E0:
	strh r6, [r5, #0x10]
	ldr r1, _080A4720 @ =FUN_080a4728
	adds r0, r5, #0
	bl FUN_080a4598
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A4718
	ldr r1, _080A4724 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r3, sp
	str r3, [r1, #4]
	adds r0, r5, #0
	adds r0, #0xe8
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	adds r0, r2, #0
	bl Script_ExecById
_080A4718:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A4720: .4byte FUN_080a4728
_080A4724: .4byte 0xFFFF0000

	thumb_func_start FUN_080a4728
FUN_080a4728: @ 0x080A4728
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a472c
FUN_080a472c: @ 0x080A472C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r2, r5, #0
	adds r2, #0xee
	ldrh r0, [r2]
	cmp r0, #0
	beq _080A4794
	adds r4, r5, #0
	adds r4, #0xec
	ldrh r1, [r4]
	lsls r0, r1, #8
	subs r0, r0, r1
	ldrh r1, [r2]
	bl Div
	ldr r2, _080A4768 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r0, #0
	ldrsh r1, [r1, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _080A476C
	asrs r1, r0, #0xc
	b _080A4772
	.align 2, 0
_080A4768: .4byte 0x085B0A08
_080A476C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A4772:
	adds r0, r5, #0
	adds r0, #0xde
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r5, #0x1e]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	adds r1, r5, #0
	adds r1, #0xee
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080A4794
	movs r0, #0
	strh r0, [r4]
_080A4794:
	adds r0, r5, #0
	adds r0, #0xf0
	adds r1, r5, #0
	adds r1, #0xf2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	blo _080A47C6
	adds r1, r5, #0
	adds r1, #0xf6
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080a45a8
	adds r2, r5, #0
	adds r2, #0x4e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080A47CC @ =FUN_080a47d0
	adds r0, r5, #0
	bl FUN_080a4598
_080A47C6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A47CC: .4byte FUN_080a47d0

	thumb_func_start FUN_080a47d0
FUN_080a47d0: @ 0x080A47D0
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xec
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A47E8
	movs r0, #0xd5
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080A47E8:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080A4808
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r0, #1
	strh r0, [r5, #0x10]
	b _080A4842
_080A4808:
	movs r0, #2
	strh r0, [r5, #0x10]
	ldr r1, _080A484C @ =FUN_080a4854
	adds r0, r5, #0
	bl FUN_080a4598
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A4842
	ldr r1, _080A4850 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r3, sp
	str r3, [r1, #4]
	adds r0, r5, #0
	adds r0, #0xe8
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	adds r0, r2, #0
	bl Script_ExecById
_080A4842:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A484C: .4byte FUN_080a4854
_080A4850: .4byte 0xFFFF0000

	thumb_func_start FUN_080a4854
FUN_080a4854: @ 0x080A4854
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A4898 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xea
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080A48A0
	adds r5, r4, #0
	adds r5, #0xde
	movs r2, #0x1e
	ldrsh r1, [r4, r2]
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bne _080A4884
	ldr r0, _080A489C @ =0x000002B3
	bl PlaySound_082406e0
_080A4884:
	movs r0, #0x1e
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	subs r0, #0x10
	cmp r1, r0
	ble _080A48B6
	ldrh r0, [r4, #0x1e]
	subs r0, #2
	b _080A48B4
	.align 2, 0
_080A4898: .4byte 0x03002BE0
_080A489C: .4byte 0x000002B3
_080A48A0:
	adds r0, r4, #0
	adds r0, #0xde
	ldrh r2, [r4, #0x1e]
	movs r3, #0x1e
	ldrsh r1, [r4, r3]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _080A48B6
	adds r0, r2, #2
_080A48B4:
	strh r0, [r4, #0x1e]
_080A48B6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a48bc
FUN_080a48bc: @ 0x080A48BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _080A48DE
	ldr r0, _080A48FC @ =0x000001A9
	bl PlaySound_082406e0
	movs r1, #0
	movs r0, #0x20
	strb r0, [r4, #0x1b]
	strb r1, [r4, #0x19]
_080A48DE:
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _080A49BC
	subs r0, #1
	strb r0, [r4, #0x1b]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080A4904
	ldr r0, _080A4900 @ =0x03003584
	ldr r0, [r0]
	movs r1, #0xbe
	lsls r1, r1, #4
	adds r0, r0, r1
	b _080A4912
	.align 2, 0
_080A48FC: .4byte 0x000001A9
_080A4900: .4byte 0x03003584
_080A4904:
	cmp r0, #0xf
	bls _080A4928
	ldr r0, _080A4920 @ =0x03003584
	ldr r0, [r0]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r0, r0, r2
_080A4912:
	adds r1, r4, #0
	adds r1, #0x1c
	ldr r2, _080A4924 @ =0x04000008
	bl CpuSet
	b _080A49BC
	.align 2, 0
_080A4920: .4byte 0x03003584
_080A4924: .4byte 0x04000008
_080A4928:
	ldrb r7, [r4, #0x1b]
	movs r0, #0x10
	subs r0, r0, r7
	str r0, [sp]
	ldr r0, _080A49CC @ =0x03003584
	ldr r0, [r0]
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r3, r3, r0
	mov sl, r3
	movs r5, #0xbe
	lsls r5, r5, #4
	adds r5, r5, r0
	mov r8, r5
	movs r6, #0
	mov sb, r6
	adds r4, #0x1c
	str r4, [sp, #4]
	movs r0, #0x1f
	mov ip, r0
_080A4950:
	mov r1, sl
	ldrh r3, [r1]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	mov r5, ip
	ands r6, r5
	lsrs r3, r3, #0x1a
	ands r3, r5
	mov r0, r8
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x15
	ands r4, r5
	lsrs r1, r1, #0x1a
	ands r1, r5
	adds r5, r2, #0
	muls r5, r7, r5
	ldr r2, [sp]
	muls r0, r2, r0
	adds r5, r5, r0
	asrs r5, r5, #4
	adds r2, r6, #0
	muls r2, r7, r2
	ldr r6, [sp]
	adds r0, r4, #0
	muls r0, r6, r0
	adds r2, r2, r0
	asrs r2, r2, #4
	adds r0, r3, #0
	muls r0, r7, r0
	muls r1, r6, r1
	adds r0, r0, r1
	asrs r0, r0, #4
	mov r3, sb
	lsls r1, r3, #1
	ldr r6, [sp, #4]
	adds r1, r6, r1
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	strh r0, [r1]
	movs r0, #2
	add sl, r0
	add r8, r0
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #0xf
	ble _080A4950
_080A49BC:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A49CC: .4byte 0x03003584

	thumb_func_start FUN_080a49d0
FUN_080a49d0: @ 0x080A49D0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	bl FUN_080a48bc
	movs r0, #0
	mov r8, r0
	ldrb r0, [r6, #0x18]
	cmp r8, r0
	bge _080A4A34
	adds r5, r6, #0
	adds r5, #0x68
	movs r0, #0x98
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r7, r6, #0
	adds r7, #0x3c
_080A49F4:
	ldr r1, [r4, #0x14]
	adds r0, r7, #0
	bl _call_via_r1
	ldrb r0, [r4]
	cmp r0, #0
	beq _080A4A20
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A4A18
	movs r0, #0x60
	strh r0, [r5, #6]
	adds r0, r6, #0
	adds r0, #0x1c
	str r0, [r5, #0xc]
	b _080A4A20
_080A4A18:
	adds r0, r5, #0
	movs r1, #0x5f
	bl FUN_0822b20c
_080A4A20:
	movs r0, #0x88
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r7, r7, r0
	movs r0, #1
	add r8, r0
	ldrb r0, [r6, #0x18]
	cmp r8, r0
	blt _080A49F4
_080A4A34:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a4a40
FUN_080a4a40: @ 0x080A4A40
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0
	mov sl, r0
	ldrb r0, [r5, #0x18]
	cmp sl, r0
	bge _080A4AAC
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r0, r5
	mov sb, r0
	movs r0, #0x84
	adds r0, r0, r5
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0xd4
	ldr r0, _080A4AC0 @ =0x00000121
	adds r4, r5, r0
	adds r6, r5, #0
	adds r6, #0x3c
_080A4A70:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080A4A7C
	adds r0, r7, #0
	bl FUN_0823b284
_080A4A7C:
	adds r0, r6, #0
	bl FUN_0822a4e0
	mov r0, r8
	bl FUN_08236424
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A4A94
	mov r0, sb
	bl FUN_082342a8
_080A4A94:
	movs r0, #0x88
	lsls r0, r0, #1
	add sb, r0
	add r8, r0
	adds r7, r7, r0
	adds r4, r4, r0
	adds r6, r6, r0
	movs r0, #1
	add sl, r0
	ldrb r0, [r5, #0x18]
	cmp sl, r0
	blt _080A4A70
_080A4AAC:
	ldr r1, _080A4AC4 @ =0x03002C44
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
_080A4AC0: .4byte 0x00000121
_080A4AC4: .4byte 0x03002C44

	thumb_func_start FUN_080a4ac8
FUN_080a4ac8: @ 0x080A4AC8
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x48
	ldr r2, _080A4B3C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _080A4B40 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	adds r0, r4, #0
	adds r0, #0xe6
	ldrh r1, [r0]
	ldr r2, _080A4B44 @ =0x00004002
	movs r0, #0x20
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _080A4B48 @ =0x080A4621
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r4, #0xdc
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A4B3C: .4byte 0xFFFF0000
_080A4B40: .4byte 0x0000FFFF
_080A4B44: .4byte 0x00004002
_080A4B48: .4byte 0x080A4621

	thumb_func_start FUN_080a4b4c
FUN_080a4b4c: @ 0x080A4B4C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	ldrb r1, [r0, #0x18]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, #0x3c
	mov r1, sb
	adds r5, r1, r0
	movs r0, #0x6e
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A4B82
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0xe6
	strh r0, [r1]
	mov sl, r1
	b _080A4B8A
_080A4B82:
	adds r0, r5, #0
	adds r0, #0xe6
	strh r1, [r0]
	mov sl, r0
_080A4B8A:
	movs r0, #0x70
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4BB8
	bl Script_GetValue
	adds r4, r5, #0
	adds r4, #0xdc
	strh r0, [r4]
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0xde
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0xe0
	strh r0, [r1]
	adds r6, r4, #0
	b _080A4BCA
_080A4BB8:
	adds r1, r5, #0
	adds r1, #0xdc
	strh r2, [r1]
	adds r0, r5, #0
	adds r0, #0xde
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r6, r1, #0
_080A4BCA:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A4BEE
	cmp r1, #0
	blt _080A4BEE
	ldr r0, _080A4BF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A4BEE
	ldr r0, _080A4BF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A4BFC
_080A4BEE:
	movs r0, #0
	b _080A4C0A
	.align 2, 0
_080A4BF4: .4byte 0x030046A8
_080A4BF8: .4byte 0x030046AC
_080A4BFC:
	ldr r0, _080A4C24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A4C0A:
	adds r2, r5, #0
	adds r2, #0xea
	strh r0, [r2]
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A4C28
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0xe4
	b _080A4C2E
	.align 2, 0
_080A4C24: .4byte 0x030046A4
_080A4C28:
	adds r1, r5, #0
	adds r1, #0xe4
	movs r0, #0
_080A4C2E:
	strb r0, [r1]
	mov r8, r1
	mov r2, r8
	ldrb r0, [r2]
	ldr r1, _080A4CB8 @ =0x0000D166
	cmp r0, #0
	bne _080A4C3E
	ldr r1, _080A4CBC @ =0x0000C3C3
_080A4C3E:
	adds r7, r5, #0
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #3
	strb r0, [r5, #7]
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080A4C72
	bl Script_GetValue
	cmp r0, #0
	beq _080A4C72
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080A4C72:
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	movs r0, #0x68
	bl prepare_08231510
	cmp r0, #0
	beq _080A4CC0
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0xe5
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A4CC6
	adds r4, r5, #0
	adds r4, #0x98
	mov r0, sl
	ldrh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	bl FUN_08002a48
	b _080A4CC6
	.align 2, 0
_080A4CB8: .4byte 0x0000D166
_080A4CBC: .4byte 0x0000C3C3
_080A4CC0:
	adds r1, r5, #0
	adds r1, #0xe5
	strb r0, [r1]
_080A4CC6:
	adds r0, r5, #0
	adds r0, #0xf0
	movs r1, #0
	strh r1, [r0]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _080A4CE2
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0xf2
	b _080A4CE8
_080A4CE2:
	adds r1, r5, #0
	adds r1, #0xf2
	movs r0, #0xa
_080A4CE8:
	strh r0, [r1]
	movs r0, #0x57
	bl prepare_08231510
	cmp r0, #0
	beq _080A4CF8
	bl Script_GetValue
_080A4CF8:
	adds r1, r5, #0
	adds r1, #0xee
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080a4ac8
	adds r1, r5, #0
	adds r1, #0xf4
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x73
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A4D26
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0xf6
	strb r0, [r1]
	adds r0, r1, #0
	b _080A4D2C
_080A4D26:
	adds r0, r5, #0
	adds r0, #0xf6
	strb r1, [r0]
_080A4D2C:
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A4D64
	adds r0, r5, #0
	bl FUN_080a45a8
	adds r2, r5, #0
	adds r2, #0x4e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r0, #2
	strh r0, [r7, #0x10]
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne _080A4D5C
	movs r0, #2
	strb r0, [r7, #7]
	ldr r1, _080A4D58 @ =0x080A4729
	b _080A4D7A
	.align 2, 0
_080A4D58: .4byte 0x080A4729
_080A4D5C:
	ldr r1, _080A4D60 @ =FUN_080a4854
	b _080A4D7A
	.align 2, 0
_080A4D60: .4byte FUN_080a4854
_080A4D64:
	adds r1, r5, #0
	adds r1, #0xf7
	strb r0, [r1]
	strh r0, [r7, #0x10]
	movs r0, #3
	strb r0, [r7, #7]
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne _080A4D88
	ldr r1, _080A4D84 @ =FUN_080a4670
_080A4D7A:
	adds r0, r5, #0
	bl FUN_080a4598
	b _080A4D90
	.align 2, 0
_080A4D84: .4byte FUN_080a4670
_080A4D88:
	ldr r1, _080A4DB4 @ =FUN_080a472c
	adds r0, r5, #0
	bl FUN_080a4598
_080A4D90:
	movs r0, #0x67
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4DB8
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0xe8
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0x86
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	b _080A4DC8
	.align 2, 0
_080A4DB4: .4byte FUN_080a472c
_080A4DB8:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, _080A4DE0 @ =0x0000FFFF
	strh r1, [r0]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	str r2, [r0]
_080A4DC8:
	mov r2, sb
	ldrb r0, [r2, #0x18]
	adds r0, #1
	strb r0, [r2, #0x18]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A4DE0: .4byte 0x0000FFFF

	thumb_func_start FUN_080a4de4
FUN_080a4de4: @ 0x080A4DE4
	push {r4, lr}
	ldr r1, _080A4E0C @ =0x000008BC
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4E00
	ldr r1, _080A4E10 @ =FUN_080a49d0
	ldr r2, _080A4E14 @ =FUN_080a4a40
	bl SetEntityRoutine
	movs r0, #0
	strb r0, [r4, #0x18]
_080A4E00:
	ldr r0, _080A4E18 @ =0x03002C44
	str r4, [r0]
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A4E0C: .4byte 0x000008BC
_080A4E10: .4byte FUN_080a49d0
_080A4E14: .4byte FUN_080a4a40
_080A4E18: .4byte 0x03002C44

	thumb_func_start FUN_080a4e1c
FUN_080a4e1c: @ 0x080A4E1C
	push {r4, r5, r6, r7, lr}
	ldr r0, _080A4E38 @ =0x03002C44
	ldr r4, [r0]
	cmp r4, #0
	beq _080A4E70
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _080A4E46
	bl Script_GetValue
	adds r5, r0, #0
	b _080A4E48
	.align 2, 0
_080A4E38: .4byte 0x03002C44
_080A4E3C:
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	b _080A4E72
_080A4E46:
	movs r5, #0
_080A4E48:
	movs r3, #0
	ldrb r0, [r4, #0x18]
	cmp r3, r0
	bge _080A4E70
	adds r6, r0, #0
	movs r7, #0x92
	lsls r7, r7, #1
	adds r1, r4, r7
	adds r2, r4, #0
	movs r4, #0x88
	lsls r4, r4, #1
_080A4E5E:
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r5
	beq _080A4E3C
	adds r1, r1, r4
	adds r2, r2, r4
	adds r3, #1
	cmp r3, r6
	blt _080A4E5E
_080A4E70:
	movs r0, #0
_080A4E72:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a4e78
FUN_080a4e78: @ 0x080A4E78
	push {lr}
	ldr r0, _080A4E90 @ =0x03002C44
	ldr r0, [r0]
	cmp r0, #0
	bne _080A4E86
	bl FUN_080a4de4
_080A4E86:
	bl FUN_080a4b4c
	pop {r1}
	bx r1
	.align 2, 0
_080A4E90: .4byte 0x03002C44

	thumb_func_start FUN_080a4e94
FUN_080a4e94: @ 0x080A4E94
	push {r4, r5, r6, lr}
	ldr r4, _080A4EAC @ =0x03002C48
	ldr r0, [r4]
	cmp r0, #0
	beq _080A4EE0
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	bne _080A4EB8
	b _080A4EE0
	.align 2, 0
_080A4EAC: .4byte 0x03002C48
_080A4EB0:
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r5, r0
	b _080A4EE2
_080A4EB8:
	bl Script_GetValue
	adds r6, r0, #0
	movs r2, #0
	ldr r0, [r4]
	ldrb r1, [r0, #0x19]
	cmp r2, r1
	bge _080A4EE0
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r5, #0
	movs r3, #0
_080A4ED0:
	ldrh r0, [r1, #0x1c]
	cmp r0, r6
	beq _080A4EB0
	adds r1, #0xb8
	adds r3, #0xb8
	adds r2, #1
	cmp r2, r4
	blt _080A4ED0
_080A4EE0:
	movs r0, #0
_080A4EE2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a4ee8
FUN_080a4ee8: @ 0x080A4EE8
	push {r4, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4F4E
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A4F4E
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0x78
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0x7a
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0x7c
	strh r0, [r1]
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A4F4E
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0x80
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A4F4E
	ldrb r1, [r4, #2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #2]
	ldr r0, [r4, #0x44]
	ldr r1, [r4, #0x48]
	str r0, [r4, #0x70]
	str r1, [r4, #0x74]
	adds r1, r4, #0
	adds r1, #0x82
	movs r0, #0
	strh r0, [r1]
_080A4F4E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a4f54
FUN_080a4f54: @ 0x080A4F54
	push {r4, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4F70
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A4F70
	bl Script_GetValue
	strh r0, [r4, #0x38]
_080A4F70:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a4f78
FUN_080a4f78: @ 0x080A4F78
	push {lr}
	bl FUN_080a4e94
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4F8C
	ldr r0, [r2, #0x28]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x28]
_080A4F8C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a4f90
FUN_080a4f90: @ 0x080A4F90
	push {lr}
	bl FUN_080a4e94
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4FA6
	ldr r0, [r2, #0x28]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x28]
_080A4FA6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a4fac
FUN_080a4fac: @ 0x080A4FAC
	push {r4, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4FCC
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A4FCC
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0x2f
	strb r0, [r1]
_080A4FCC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a4fd4
FUN_080a4fd4: @ 0x080A4FD4
	push {r4, r5, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5046
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080A5046
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0x86
	strh r0, [r1]
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _080A5046
	bl Script_GetValue
	adds r5, r4, #0
	adds r5, #0x88
	strh r0, [r5]
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A5046
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0x8c
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _080A5036
	adds r0, r4, #0
	adds r0, #0x54
	subs r1, #8
	ldrh r1, [r1]
	ldrh r2, [r5]
	adds r1, r1, r2
	bl FUN_0822b20c
	b _080A5046
_080A5036:
	adds r1, r4, #0
	adds r1, #0x8a
	movs r0, #0
	strh r0, [r1]
	ldrb r1, [r4, #2]
	movs r0, #2
	orrs r0, r1
	strb r0, [r4, #2]
_080A5046:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a504c
FUN_080a504c: @ 0x080A504C
	push {r4, r5, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A50D2
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080A50D2
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0x90
	strh r0, [r1]
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _080A50D2
	bl Script_GetValue
	adds r5, r4, #0
	adds r5, #0x92
	strh r0, [r5]
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A50D2
	bl Script_GetValue
	adds r2, r4, #0
	adds r2, #0x96
	strh r0, [r2]
	ldrh r0, [r5]
	adds r3, r4, #0
	adds r3, #0x30
	strb r0, [r3]
	adds r1, r4, #0
	adds r1, #0x31
	strb r0, [r1]
	ldrh r0, [r2]
	cmp r0, #1
	bhi _080A50BA
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0x40
	beq _080A50D2
	ldr r0, [r4, #0x28]
	movs r1, #2
	orrs r0, r1
	str r0, [r4, #0x28]
	b _080A50D2
_080A50BA:
	ldr r0, [r4, #0x28]
	movs r1, #2
	orrs r0, r1
	str r0, [r4, #0x28]
	adds r1, r4, #0
	adds r1, #0x94
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r4, #2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r4, #2]
_080A50D2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a50d8
FUN_080a50d8: @ 0x080A50D8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	bl FUN_080a4e94
	adds r5, r0, #0
	cmp r5, #0
	beq _080A51CC
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A51CC
	bl Script_GetValue
	adds r7, r5, #0
	adds r7, #0x98
	strb r0, [r7]
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _080A51CC
	bl Script_GetValue
	adds r6, r5, #0
	adds r6, #0x99
	strb r0, [r6]
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080A51CC
	bl Script_GetValue
	strb r0, [r5, #3]
	movs r4, #0
	movs r0, #0x45
	bl prepare_08231510
	cmp r0, #0
	beq _080A5130
	bl Script_GetValue
	adds r4, r0, #0
_080A5130:
	cmp r4, #0
	beq _080A514E
	adds r4, r5, #0
	adds r4, #0x9c
	adds r0, r5, #0
	adds r0, #0xac
	ldr r1, [r0]
	ldrb r2, [r7]
	ldrb r3, [r6]
	ldrb r0, [r5, #3]
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08237040
	b _080A5166
_080A514E:
	adds r4, r5, #0
	adds r4, #0x9c
	adds r0, r5, #0
	adds r0, #0xac
	ldr r1, [r0]
	ldrb r2, [r7]
	ldrb r3, [r6]
	ldrb r0, [r5, #3]
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08236fac
_080A5166:
	movs r0, #0x50
	bl prepare_08231510
	cmp r0, #0
	beq _080A5180
	bl Script_GetValue
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
_080A5180:
	movs r0, #0x6f
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A519A
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x9a
	strb r0, [r1]
	adds r0, r1, #0
	b _080A51A0
_080A519A:
	adds r0, r5, #0
	adds r0, #0x9a
	strb r1, [r0]
_080A51A0:
	ldrb r1, [r0]
	cmp r1, #0
	beq _080A51BE
	movs r0, #0x65
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A51BE
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0xb0
	str r0, [r1]
	b _080A51C4
_080A51BE:
	adds r0, r5, #0
	adds r0, #0xb0
	str r1, [r0]
_080A51C4:
	ldrb r1, [r5, #2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r5, #2]
_080A51CC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a51d4
FUN_080a51d4: @ 0x080A51D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldrb r1, [r7, #2]
	cmp r1, #0
	bne _080A51EA
	b _080A5556
_080A51EA:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080A5284
	adds r6, r7, #0
	adds r6, #0x82
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	adds r5, r7, #0
	adds r5, #0x80
	ldrh r1, [r5]
	ldrh r3, [r6]
	subs r4, r1, r3
	adds r0, r7, #0
	adds r0, #0x70
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r2, r0, #0
	muls r2, r4, r2
	mov r8, r2
	adds r2, r7, #0
	adds r2, #0x78
	movs r0, #0
	ldrsh r2, [r2, r0]
	muls r2, r3, r2
	mov r3, r8
	adds r0, r3, r2
	bl Div
	adds r1, r7, #0
	adds r1, #0x44
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x72
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	adds r1, r7, #0
	adds r1, #0x7a
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldrh r1, [r6]
	muls r1, r2, r1
	adds r0, r0, r1
	ldrh r1, [r5]
	bl Div
	adds r1, r7, #0
	adds r1, #0x46
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	adds r1, r7, #0
	adds r1, #0x7c
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldrh r1, [r6]
	muls r1, r2, r1
	adds r0, r0, r1
	ldrh r1, [r5]
	bl Div
	adds r1, r7, #0
	adds r1, #0x48
	strh r0, [r1]
	ldrh r0, [r6]
	ldrh r5, [r5]
	cmp r0, r5
	blo _080A5284
	ldrb r1, [r7, #2]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #2]
_080A5284:
	ldrb r1, [r7, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080A5290
	b _080A53B6
_080A5290:
	adds r3, r7, #0
	adds r3, #0x8a
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	adds r4, r7, #0
	adds r4, #0x8c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4]
	cmp r0, r1
	blo _080A52C8
	adds r0, r7, #0
	adds r0, #0x54
	adds r1, r7, #0
	adds r1, #0x84
	ldrh r1, [r1]
	adds r2, r7, #0
	adds r2, #0x88
	ldrh r2, [r2]
	adds r1, r1, r2
	bl FUN_0822b20c
	ldrb r1, [r7, #2]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r7, #2]
	b _080A53B6
_080A52C8:
	ldr r2, _080A5408 @ =0x03003584
	adds r0, r7, #0
	adds r0, #0x84
	ldrh r1, [r0]
	adds r0, #2
	ldrh r0, [r0]
	adds r0, r1, r0
	lsls r0, r0, #5
	ldr r2, [r2]
	adds r0, r2, r0
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r0, #0x88
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r2, r1
	str r2, [sp, #8]
	ldrh r1, [r4]
	ldrh r0, [r3]
	subs r1, r1, r0
	str r1, [sp, #0xc]
	adds r2, r7, #0
	adds r2, #8
	str r2, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0x5a
	str r0, [sp, #0x18]
	str r3, [sp, #0x10]
	mov sb, r4
	mov sl, r2
	movs r1, #0xf
	str r1, [sp]
_080A530A:
	ldr r2, [sp, #4]
	ldrh r5, [r2]
	movs r0, #0x1f
	ands r0, r5
	lsls r5, r5, #0x10
	lsrs r3, r5, #0x15
	movs r1, #0x1f
	ands r3, r1
	lsrs r5, r5, #0x1a
	ands r5, r1
	ldr r2, [sp, #8]
	ldrh r4, [r2]
	movs r2, #0x1f
	ands r2, r4
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x15
	ands r6, r1
	lsrs r4, r4, #0x1a
	ands r4, r1
	ldr r1, [sp, #0xc]
	muls r0, r1, r0
	ldr r1, [sp, #0x10]
	ldrh r1, [r1]
	mov r8, r1
	mov r1, r8
	muls r1, r2, r1
	adds r0, r0, r1
	mov r2, sb
	ldrh r1, [r2]
	str r3, [sp, #0x1c]
	bl Div
	mov r8, r0
	ldr r3, [sp, #0x1c]
	ldr r1, [sp, #0xc]
	adds r0, r3, #0
	muls r0, r1, r0
	ldr r2, [sp, #0x10]
	ldrh r1, [r2]
	muls r1, r6, r1
	adds r0, r0, r1
	mov r3, sb
	ldrh r1, [r3]
	bl Div
	adds r6, r0, #0
	ldr r1, [sp, #0xc]
	adds r0, r5, #0
	muls r0, r1, r0
	ldr r2, [sp, #0x10]
	ldrh r1, [r2]
	muls r1, r4, r1
	adds r0, r0, r1
	mov r3, sb
	ldrh r1, [r3]
	bl Div
	lsls r0, r0, #0xa
	lsls r6, r6, #5
	orrs r0, r6
	mov r1, r8
	orrs r0, r1
	mov r2, sl
	strh r0, [r2]
	ldr r3, [sp, #4]
	adds r3, #2
	str r3, [sp, #4]
	ldr r0, [sp, #8]
	adds r0, #2
	str r0, [sp, #8]
	movs r1, #2
	add sl, r1
	ldr r2, [sp]
	subs r2, #1
	str r2, [sp]
	cmp r2, #0
	bge _080A530A
	ldr r3, [sp, #0x14]
	str r3, [r7, #0x60]
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r1, #0
	ldrh r2, [r7]
	adds r0, r0, r2
	ldr r3, [sp, #0x18]
	strh r0, [r3]
_080A53B6:
	ldrb r1, [r7, #2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080A543A
	adds r3, r7, #0
	adds r3, #0x94
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	adds r4, r7, #0
	adds r4, #0x96
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4]
	cmp r0, r1
	blo _080A540C
	adds r0, r7, #0
	adds r0, #0x92
	ldrh r0, [r0]
	adds r1, r7, #0
	adds r1, #0x30
	strb r0, [r1]
	adds r2, r7, #0
	adds r2, #0x31
	strb r0, [r2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x40
	bne _080A53FC
	ldr r0, [r7, #0x28]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x28]
_080A53FC:
	ldrb r1, [r7, #2]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #2]
	b _080A543A
	.align 2, 0
_080A5408: .4byte 0x03003584
_080A540C:
	ldr r0, [r7, #0x28]
	movs r1, #2
	orrs r0, r1
	str r0, [r7, #0x28]
	adds r0, r7, #0
	adds r0, #0x90
	ldrh r2, [r0]
	ldrh r1, [r4]
	ldrh r3, [r3]
	subs r0, r1, r3
	muls r0, r2, r0
	adds r2, r7, #0
	adds r2, #0x92
	ldrh r2, [r2]
	muls r2, r3, r2
	adds r0, r0, r2
	bl Div
	adds r1, r7, #0
	adds r1, #0x30
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
_080A543A:
	ldrb r1, [r7, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080A5446
	b _080A5556
_080A5446:
	adds r6, r7, #0
	adds r6, #0x28
	adds r4, r7, #0
	adds r4, #0x9c
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
	beq _080A547A
	ldr r0, [r7, #0x28]
	movs r1, #4
	orrs r0, r1
	b _080A5482
_080A547A:
	ldr r0, [r7, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080A5482:
	str r0, [r7, #0x28]
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
	beq _080A54A6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080A54AE
_080A54A6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080A54AE:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080A54E8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080A552E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080A54F2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080A54EC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080A5508
	.align 2, 0
_080A54E8: .4byte 0x0000FFFF
_080A54EC:
	subs r0, #1
	strh r0, [r4, #8]
	b _080A5506
_080A54F2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080A5506
	strh r1, [r4, #8]
	movs r2, #1
	b _080A5508
_080A5506:
	movs r2, #0
_080A5508:
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
	bne _080A5530
	movs r0, #1
	strb r0, [r4, #7]
	b _080A5530
_080A552E:
	movs r2, #0
_080A5530:
	cmp r2, #0
	beq _080A5556
	adds r0, r7, #0
	adds r0, #0x9a
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A5556
	ldrb r0, [r7, #2]
	movs r1, #0xf7
	ands r1, r0
	strb r1, [r7, #2]
	adds r0, r7, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0
	beq _080A5556
	movs r1, #0
	bl Script_ExecById
_080A5556:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5568
FUN_080a5568: @ 0x080A5568
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r0, _080A55D0 @ =0x03002C48
	ldr r4, [r0]
	cmp r4, #0
	bne _080A557C
	b _080A583C
_080A557C:
	ldrb r0, [r4, #0x19]
	ldrb r1, [r4, #0x18]
	cmp r0, r1
	blo _080A5586
	b _080A583C
_080A5586:
	adds r1, r0, #0
	movs r0, #0xb8
	muls r0, r1, r0
	adds r0, #0x1c
	adds r7, r4, r0
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _080A559E
	bl Script_GetValue
_080A559E:
	strh r0, [r7]
	adds r4, r7, #0
	adds r4, #0x28
	adds r5, r7, #0
	adds r5, #0x54
	movs r0, #0x74
	bl prepare_08231510
	mov sb, r4
	cmp r0, #0
	bne _080A55B6
	b _080A583C
_080A55B6:
	bl Script_GetValue
	mov r8, r0
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _080A55D4
	bl Script_GetValue
	adds r6, r0, #0
	b _080A55D6
	.align 2, 0
_080A55D0: .4byte 0x03002C48
_080A55D4:
	movs r6, #0
_080A55D6:
	adds r0, r5, #0
	mov r1, r8
	bl Video_GetActorSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	movs r2, #0
	strh r6, [r4, #0x10]
	ldrh r1, [r5, #6]
	adds r0, r7, #0
	adds r0, #0x84
	strh r1, [r0]
	strb r2, [r7, #3]
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A5606
	bl Script_GetValue
	strb r0, [r7, #3]
_080A5606:
	ldrb r0, [r7, #3]
	cmp r0, #0
	beq _080A5614
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	str r0, [r4]
_080A5614:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A5630
	bl Script_GetValue
	strh r0, [r4, #0x1c]
	bl Script_GetValue
	strh r0, [r4, #0x1e]
	bl Script_GetValue
	b _080A5634
_080A5630:
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
_080A5634:
	strh r0, [r4, #0x20]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _080A5644
	bl Script_GetValue
_080A5644:
	strb r0, [r7, #4]
	movs r0, #0x52
	bl prepare_08231510
	cmp r0, #0
	beq _080A5656
	bl Script_GetValue
	strb r0, [r4, #7]
_080A5656:
	movs r0, #0x6d
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	bne _080A5664
	b _080A57E6
_080A5664:
	ldr r4, _080A56B0 @ =0x0000922E
	bl Script_GetValue
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl GetFile
	adds r6, r7, #0
	adds r6, #0xac
	str r0, [r6]
	bl Script_GetValue
	adds r5, r7, #0
	adds r5, #0x98
	strb r0, [r5]
	bl Script_GetValue
	adds r4, r7, #0
	adds r4, #0x99
	strb r0, [r4]
	movs r0, #0x6f
	bl prepare_08231510
	adds r1, r0, #0
	mov r8, r6
	adds r6, r4, #0
	cmp r1, #0
	beq _080A56B4
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x9a
	strb r0, [r1]
	adds r0, r1, #0
	b _080A56BA
	.align 2, 0
_080A56B0: .4byte 0x0000922E
_080A56B4:
	adds r0, r7, #0
	adds r0, #0x9a
	strb r1, [r0]
_080A56BA:
	ldrb r1, [r0]
	cmp r1, #0
	beq _080A56D8
	movs r0, #0x65
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A56D8
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0xb0
	str r0, [r1]
	b _080A56DE
_080A56D8:
	adds r0, r7, #0
	adds r0, #0xb0
	str r1, [r0]
_080A56DE:
	adds r4, r7, #0
	adds r4, #0x9c
	mov r2, r8
	ldr r1, [r2]
	ldrb r2, [r5]
	ldrb r3, [r6]
	ldrb r0, [r7, #3]
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08236fac
	movs r0, #0x50
	bl prepare_08231510
	cmp r0, #0
	beq _080A570E
	bl Script_GetValue
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
_080A570E:
	mov r6, sb
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
	beq _080A573C
	ldr r0, [r7, #0x28]
	movs r1, #4
	orrs r0, r1
	b _080A5744
_080A573C:
	ldr r0, [r7, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080A5744:
	str r0, [r7, #0x28]
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
	beq _080A5768
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080A5770
_080A5768:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080A5770:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080A57A8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080A57E0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080A57AC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080A57A0
	ldrb r0, [r4, #5]
_080A57A0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080A57BC
	.align 2, 0
_080A57A8: .4byte 0x0000FFFF
_080A57AC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080A57BC
	strh r1, [r4, #8]
_080A57BC:
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
	bne _080A57E0
	movs r0, #1
	strb r0, [r4, #7]
_080A57E0:
	movs r0, #8
	strb r0, [r7, #2]
	b _080A57F6
_080A57E6:
	adds r0, r7, #0
	adds r0, #0xac
	str r1, [r0]
	subs r0, #0x12
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	strb r1, [r7, #2]
_080A57F6:
	movs r5, #0
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080A5808
	bl Script_GetValue
	adds r5, r0, #0
_080A5808:
	adds r4, r7, #0
	adds r4, #0xb4
	movs r0, #0
	str r0, [r4]
	cmp r5, #0
	beq _080A5832
	movs r0, #0x40
	bl Malloc
	str r0, [r4]
	cmp r0, #0
	beq _080A5832
	movs r1, #0x40
	bl ClearMemory
	ldr r0, [r4]
	adds r1, r7, #0
	adds r1, #0x44
	movs r2, #0
	bl FUN_0801385c
_080A5832:
	ldr r0, _080A584C @ =0x03002C48
	ldr r1, [r0]
	ldrb r0, [r1, #0x19]
	adds r0, #1
	strb r0, [r1, #0x19]
_080A583C:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A584C: .4byte 0x03002C48

	thumb_func_start FUN_080a5850
FUN_080a5850: @ 0x080A5850
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	bge _080A587E
	adds r4, r6, #0
	adds r4, #0x1c
_080A5860:
	ldr r0, _080A5888 @ =0x030044BC
	ldr r0, [r0]
	cmp r0, #0
	beq _080A586E
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _080A5874
_080A586E:
	adds r0, r4, #0
	bl FUN_080a51d4
_080A5874:
	adds r4, #0xb8
	adds r5, #1
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	blt _080A5860
_080A587E:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A5888: .4byte 0x030044BC

	thumb_func_start FUN_080a588c
FUN_080a588c: @ 0x080A588C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	b _080A58BA
_080A5894:
	movs r0, #0xb8
	adds r4, r6, #0
	muls r4, r0, r4
	adds r0, r4, r5
	adds r0, #0x44
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r0, #0xd0
	adds r4, r0, r4
	ldr r0, [r4]
	cmp r0, #0
	beq _080A58B8
	bl FUN_080138fc
	ldr r0, [r4]
	bl Free
_080A58B8:
	adds r6, #1
_080A58BA:
	ldrb r0, [r5, #0x19]
	cmp r6, r0
	blt _080A5894
	ldr r1, _080A58CC @ =0x03002C48
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A58CC: .4byte 0x03002C48

	thumb_func_start FUN_080a58d0
FUN_080a58d0: @ 0x080A58D0
	movs r1, #0
	strb r3, [r0, #0x18]
	strb r1, [r0, #0x19]
	ldr r1, _080A58E0 @ =0x03002C48
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_080A58E0: .4byte 0x03002C48

	thumb_func_start FUN_080a58e4
FUN_080a58e4: @ 0x080A58E4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _080A5904 @ =0x03002C48
	ldr r0, [r0]
	cmp r0, #0
	bne _080A594A
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A5908
	bl Script_GetValue
	adds r5, r0, #0
	b _080A590A
	.align 2, 0
_080A5904: .4byte 0x03002C48
_080A5908:
	movs r5, #1
_080A590A:
	movs r0, #0xb8
	adds r1, r5, #0
	muls r1, r0, r1
	adds r1, #0x1c
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5948
	ldr r1, _080A5940 @ =FUN_080a5850
	ldr r2, _080A5944 @ =FUN_080a588c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	adds r3, r5, #0
	bl FUN_080a58d0
	cmp r0, #0
	bge _080A5948
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A594A
	.align 2, 0
_080A5940: .4byte FUN_080a5850
_080A5944: .4byte FUN_080a588c
_080A5948:
	adds r0, r4, #0
_080A594A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a5950
FUN_080a5950: @ 0x080A5950
	push {r4, r5, r6, lr}
	ldr r4, _080A5968 @ =0x03002C4C
	ldr r0, [r4]
	cmp r0, #0
	beq _080A599E
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	bne _080A5974
	b _080A599E
	.align 2, 0
_080A5968: .4byte 0x03002C4C
_080A596C:
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r5, r0
	b _080A59A0
_080A5974:
	bl Script_GetValue
	adds r6, r0, #0
	movs r2, #0
	ldr r0, [r4]
	ldrb r1, [r0, #0x19]
	cmp r2, r1
	bge _080A599E
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r5, #0
	adds r1, #0xb4
	movs r3, #0
_080A598E:
	ldrh r0, [r1]
	cmp r0, r6
	beq _080A596C
	adds r1, #0xbc
	adds r3, #0xbc
	adds r2, #1
	cmp r2, r4
	blt _080A598E
_080A599E:
	movs r0, #0
_080A59A0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a59a8
FUN_080a59a8: @ 0x080A59A8
	push {r4, r5, lr}
	bl FUN_080a5950
	adds r5, r0, #0
	cmp r5, #0
	beq _080A59D8
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A59D8
	adds r4, r5, #0
	adds r4, #0x38
	adds r5, #0x18
	bl Script_GetValue
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0
	bl Sprite_SetSprite
_080A59D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a59e0
FUN_080a59e0: @ 0x080A59E0
	push {r4, lr}
	bl FUN_080a5950
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5A10
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A5A10
	bl Script_GetValue
	cmp r0, #0
	beq _080A5A06
	ldr r0, [r4, #0x40]
	movs r1, #4
	orrs r0, r1
	b _080A5A0E
_080A5A06:
	ldr r0, [r4, #0x40]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080A5A0E:
	str r0, [r4, #0x40]
_080A5A10:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5a18
FUN_080a5a18: @ 0x080A5A18
	push {lr}
	bl FUN_080a5950
	adds r1, r0, #0
	cmp r1, #0
	beq _080A5A3C
	ldr r0, [r1, #0x40]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #0x40]
	adds r0, r1, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A5A3C
	adds r0, r1, #0
	adds r0, #0x9e
	strh r2, [r0]
_080A5A3C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5a40
FUN_080a5a40: @ 0x080A5A40
	push {lr}
	bl FUN_080a5950
	adds r2, r0, #0
	cmp r2, #0
	beq _080A5A68
	ldr r0, [r2, #0x40]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x40]
	adds r0, r2, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A5A68
	adds r1, r2, #0
	adds r1, #0x9e
	movs r0, #0
	strh r0, [r1]
_080A5A68:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5a6c
FUN_080a5a6c: @ 0x080A5A6C
	push {r4, lr}
	bl FUN_080a5950
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5A8C
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A5A8C
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0x52
	strb r0, [r1]
_080A5A8C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5a94
FUN_080a5a94: @ 0x080A5A94
	push {r4, lr}
	bl FUN_080a5950
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5AFA
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A5AC8
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0xb4
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0xb6
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0xb8
	strh r0, [r1]
_080A5AC8:
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A5ADC
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0xa2
	strh r0, [r1]
_080A5ADC:
	adds r2, r4, #0
	adds r2, #0xac
	adds r0, r4, #0
	adds r0, #0xa4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r4, #0
	adds r1, #0xa0
	movs r0, #0
	strh r0, [r1]
	subs r1, #6
	movs r0, #1
	strh r0, [r1]
_080A5AFA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5b00
FUN_080a5b00: @ 0x080A5B00
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r3, r6, #0
	adds r3, #0x9a
	ldrh r0, [r3]
	cmp r0, #0
	beq _080A5BC0
	adds r7, r6, #0
	adds r7, #0xa0
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	movs r1, #0xa2
	adds r1, r1, r6
	mov r8, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r1]
	cmp r0, r2
	blo _080A5B42
	adds r2, r6, #0
	adds r2, #0xa4
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0
	strh r0, [r3]
	b _080A5BB8
_080A5B42:
	mov r3, r8
	ldrh r1, [r3]
	ldrh r2, [r7]
	subs r4, r1, r2
	adds r0, r6, #0
	adds r0, #0xb4
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0xac
	movs r3, #0
	ldrsh r2, [r2, r3]
	muls r2, r4, r2
	adds r0, r0, r2
	bl Div
	adds r5, r6, #0
	adds r5, #0xa4
	strh r0, [r5]
	adds r0, r6, #0
	adds r0, #0xb6
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r7]
	muls r0, r1, r0
	adds r1, r6, #0
	adds r1, #0xae
	movs r3, #0
	ldrsh r1, [r1, r3]
	muls r1, r4, r1
	adds r0, r0, r1
	mov r2, r8
	ldrh r1, [r2]
	bl Div
	adds r1, r6, #0
	adds r1, #0xa6
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrh r0, [r7]
	muls r0, r1, r0
	adds r1, r6, #0
	adds r1, #0xb0
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r1, r4, r1
	adds r0, r0, r1
	mov r3, r8
	ldrh r1, [r3]
	bl Div
	adds r1, r6, #0
	adds r1, #0xa8
	strh r0, [r1]
	adds r2, r5, #0
_080A5BB8:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x58]
	str r1, [r6, #0x5c]
_080A5BC0:
	adds r0, r6, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A5BF8
	adds r0, r6, #0
	adds r0, #0x9e
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A5BF0
	ldr r0, _080A5BEC @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x14
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080A5BF0
	ldr r0, [r6, #0x40]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _080A5BF6
	.align 2, 0
_080A5BEC: .4byte 0x030046A0
_080A5BF0:
	ldr r0, [r6, #0x40]
	movs r1, #1
	orrs r0, r1
_080A5BF6:
	str r0, [r6, #0x40]
_080A5BF8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5c04
FUN_080a5c04: @ 0x080A5C04
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	ldr r0, _080A5C44 @ =0x03002C4C
	ldr r2, [r0]
	cmp r2, #0
	bne _080A5C18
	b _080A5D62
_080A5C18:
	ldrb r0, [r2, #0x19]
	ldrb r1, [r2, #0x18]
	cmp r0, r1
	blo _080A5C22
	b _080A5D62
_080A5C22:
	adds r1, r0, #0
	movs r0, #0xbc
	muls r0, r1, r0
	adds r0, #0x1c
	adds r5, r2, r0
	movs r0, #0x6e
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A5C48
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	b _080A5C4E
	.align 2, 0
_080A5C44: .4byte 0x03002C4C
_080A5C48:
	adds r0, r5, #0
	adds r0, #0x98
	strh r1, [r0]
_080A5C4E:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	bne _080A5C5A
	b _080A5D62
_080A5C5A:
	bl Script_GetValue
	adds r1, r0, #0
	ldr r0, _080A5C9C @ =0x0000CB05
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	adds r1, r0, #0
	adds r2, r5, #0
	adds r2, #0x18
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r4, #0
	bl OpenSpriteSetFile
	movs r0, #0x69
	bl prepare_08231510
	mov r8, r4
	cmp r0, #0
	beq _080A5CA0
	bl Script_GetValue
	adds r7, r0, #0
	b _080A5CA2
	.align 2, 0
_080A5C9C: .4byte 0x0000CB05
_080A5CA0:
	movs r7, #0
_080A5CA2:
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A5CB2
	bl Script_GetValue
	b _080A5CB4
_080A5CB2:
	movs r0, #0
_080A5CB4:
	movs r6, #0
	mov sb, r6
	cmp r0, #1
	bne _080A5CC0
	movs r0, #0x10
	mov sb, r0
_080A5CC0:
	movs r0, #0x52
	bl prepare_08231510
	cmp r0, #0
	beq _080A5CD2
	bl Script_GetValue
	adds r6, r0, #0
	b _080A5CD4
_080A5CD2:
	movs r6, #2
_080A5CD4:
	movs r0, #0x70
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080A5D00
	bl Script_GetValue
	adds r4, r5, #0
	adds r4, #0xa4
	strh r0, [r4]
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0xa6
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0xa8
	strh r0, [r1]
	b _080A5D12
_080A5D00:
	adds r1, r5, #0
	adds r1, #0xa4
	strh r2, [r1]
	adds r0, r5, #0
	adds r0, #0xa6
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r4, r1, #0
_080A5D12:
	adds r0, r5, #0
	adds r0, #0x38
	lsls r2, r7, #0x10
	lsrs r2, r2, #0x10
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	mov r1, r8
	mov r3, sb
	bl FUN_0822f3fc
	movs r0, #0x41
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A5D4A
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	b _080A5D50
_080A5D4A:
	adds r0, r5, #0
	adds r0, #0x9c
	strh r1, [r0]
_080A5D50:
	adds r1, r5, #0
	adds r1, #0x9e
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080A5D70 @ =0x03002C4C
	ldr r1, [r0]
	ldrb r0, [r1, #0x19]
	adds r0, #1
	strb r0, [r1, #0x19]
_080A5D62:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A5D70: .4byte 0x03002C4C

	thumb_func_start FUN_080a5d74
FUN_080a5d74: @ 0x080A5D74
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	bge _080A5D94
	adds r4, r6, #0
	adds r4, #0x1c
_080A5D84:
	adds r0, r4, #0
	bl FUN_080a5b00
	adds r4, #0xbc
	adds r5, #1
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	blt _080A5D84
_080A5D94:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a5d9c
FUN_080a5d9c: @ 0x080A5D9C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	bge _080A5DBC
	adds r4, r6, #0
	adds r4, #0x54
_080A5DAC:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0xbc
	adds r5, #1
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	blt _080A5DAC
_080A5DBC:
	ldr r1, _080A5DC8 @ =0x03002C4C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A5DC8: .4byte 0x03002C4C

	thumb_func_start FUN_080a5dcc
FUN_080a5dcc: @ 0x080A5DCC
	movs r1, #0
	strb r3, [r0, #0x18]
	strb r1, [r0, #0x19]
	ldr r1, _080A5DDC @ =0x03002C4C
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_080A5DDC: .4byte 0x03002C4C

	thumb_func_start FUN_080a5de0
FUN_080a5de0: @ 0x080A5DE0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _080A5E00 @ =0x03002C4C
	ldr r0, [r0]
	cmp r0, #0
	bne _080A5E46
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A5E04
	bl Script_GetValue
	adds r5, r0, #0
	b _080A5E06
	.align 2, 0
_080A5E00: .4byte 0x03002C4C
_080A5E04:
	movs r5, #1
_080A5E06:
	movs r0, #0xbc
	adds r1, r5, #0
	muls r1, r0, r1
	adds r1, #0x1c
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5E44
	ldr r1, _080A5E3C @ =FUN_080a5d74
	ldr r2, _080A5E40 @ =FUN_080a5d9c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	adds r3, r5, #0
	bl FUN_080a5dcc
	cmp r0, #0
	bge _080A5E44
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A5E46
	.align 2, 0
_080A5E3C: .4byte FUN_080a5d74
_080A5E40: .4byte FUN_080a5d9c
_080A5E44:
	adds r0, r4, #0
_080A5E46:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a5e4c
FUN_080a5e4c: @ 0x080A5E4C
	push {lr}
	ldr r0, _080A5E64 @ =0x0300014C
	ldr r0, [r0]
	cmp r0, #0
	beq _080A5E5E
	adds r1, r0, #0
	adds r1, #0x9c
	movs r0, #1
	str r0, [r1]
_080A5E5E:
	pop {r0}
	bx r0
	.align 2, 0
_080A5E64: .4byte 0x0300014C

	thumb_func_start FUN_080a5e68
FUN_080a5e68: @ 0x080A5E68
	adds r2, r0, #0
	adds r2, #0xac
	str r1, [r2]
	adds r0, #0x9a
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a5e78
FUN_080a5e78: @ 0x080A5E78
	push {lr}
	adds r1, r0, #0
	adds r0, #0xa0
	ldr r2, [r0]
	cmp r2, #0
	beq _080A5E8C
	adds r0, #4
	ldr r0, [r0]
	bl _call_via_r2
_080A5E8C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5e90
FUN_080a5e90: @ 0x080A5E90
	push {lr}
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, #0
	beq _080A5EA0
	movs r1, #0
	bl Script_ExecById
_080A5EA0:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5ea4
FUN_080a5ea4: @ 0x080A5EA4
	push {lr}
	adds r1, r0, #0
	adds r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A5EB8
	adds r0, r1, #0
	bl FUN_080a5e78
	b _080A5EBE
_080A5EB8:
	adds r0, r1, #0
	bl FUN_080a5e90
_080A5EBE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5ec4
FUN_080a5ec4: @ 0x080A5EC4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A5ED6
	ldr r0, _080A5F38 @ =0x000002C2
	bl PlaySound_082406e0
_080A5ED6:
	adds r0, r4, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _080A5EF8
	adds r0, r4, #0
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A5EF8
	movs r0, #0x87
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080A5EF8:
	adds r1, r4, #0
	adds r1, #0x9a
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r5, r4, #0
	adds r5, #0x38
	adds r6, r4, #0
	adds r6, #0x18
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_082372cc
	cmp r0, #0
	beq _080A5F30
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x24
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _080A5F3C @ =FUN_080a5f40
	adds r0, r4, #0
	bl FUN_080a5e68
	adds r0, r4, #0
	bl FUN_080a5ea4
_080A5F30:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A5F38: .4byte 0x000002C2
_080A5F3C: .4byte FUN_080a5f40

	thumb_func_start FUN_080a5f40
FUN_080a5f40: @ 0x080A5F40
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x9a
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A5F54
	ldr r0, _080A5F90 @ =0x000002C3
	bl PlaySound_082406e0
_080A5F54:
	ldrh r0, [r4]
	cmp r0, #7
	bhi _080A5FA0
	ldr r6, _080A5F94 @ =0x0203B400
	ldr r5, _080A5F98 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _080A5F9C @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r4, #3
	ands r0, r4
	subs r0, #2
	adds r2, r7, #0
	adds r2, #0x58
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #2
	adds r1, r7, #0
	adds r1, #0x5a
	strh r0, [r1]
	b _080A5FB0
	.align 2, 0
_080A5F90: .4byte 0x000002C3
_080A5F94: .4byte 0x0203B400
_080A5F98: .4byte 0x030046B8
_080A5F9C: .4byte 0x000003FF
_080A5FA0:
	cmp r0, #8
	bne _080A5FB0
	adds r0, r7, #0
	adds r0, #0x58
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_080A5FB0:
	adds r1, r7, #0
	adds r1, #0x9a
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _080A5FC8
	adds r0, r7, #0
	bl KillEntity
_080A5FC8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5fd0
FUN_080a5fd0: @ 0x080A5FD0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x9a
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A5FE6
	movs r0, #0xa5
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080A5FE6:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080A6000
	adds r0, r5, #0
	bl FUN_080a5ea4
	adds r0, r5, #0
	bl KillEntity
_080A6000:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a6008
FUN_080a6008: @ 0x080A6008
	push {lr}
	adds r2, r0, #0
	adds r0, #0x9c
	ldr r0, [r0]
	cmp r0, #0
	beq _080A601C
	adds r0, r2, #0
	bl KillEntity
	b _080A6028
_080A601C:
	adds r0, r2, #0
	adds r0, #0xac
	ldr r1, [r0]
	adds r0, r2, #0
	bl _call_via_r1
_080A6028:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a6030
FUN_080a6030: @ 0x080A6030
	push {lr}
	adds r0, #0x38
	bl FUN_0822f1c0
	ldr r1, _080A6044 @ =0x0300014C
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_080A6044: .4byte 0x0300014C

	thumb_func_start FUN_080a6048
FUN_080a6048: @ 0x080A6048
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080A60B4 @ =0x0000CB05
	ldr r1, _080A60B8 @ =0x0000DCC1
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _080A6108
	adds r1, r4, #0
	adds r1, #0x18
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	adds r7, r4, #0
	adds r7, #0x18
	adds r0, r7, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080A60BC @ =0xFFFF0000
	movs r6, #0
	str r6, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	cmp r5, #0
	bne _080A60C0
	adds r4, #0x38
	str r5, [sp]
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0x20
	movs r3, #0x30
	bl FUN_0822f3fc
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	movs r3, #2
	bl FUN_082370cc
	b _080A6108
	.align 2, 0
_080A60B4: .4byte 0x0000CB05
_080A60B8: .4byte 0x0000DCC1
_080A60BC: .4byte 0xFFFF0000
_080A60C0:
	cmp r5, #1
	bne _080A60E0
	adds r0, r4, #0
	adds r0, #0x38
	str r6, [sp]
	str r6, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r7, #0
	movs r2, #0x25
	movs r3, #0x30
	bl FUN_0822f3fc
	b _080A6108
_080A60E0:
	adds r4, #0x38
	str r6, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0x20
	movs r3, #0x30
	bl FUN_0822f3fc
	str r6, [sp]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	movs r3, #2
	bl FUN_082370cc
_080A6108:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a6110
FUN_080a6110: @ 0x080A6110
	push {lr}
	cmp r1, #0
	bne _080A6124
	ldr r1, _080A6120 @ =0x080A5EC5
	bl FUN_080a5e68
	b _080A613A
	.align 2, 0
_080A6120: .4byte 0x080A5EC5
_080A6124:
	cmp r1, #1
	bne _080A6134
	ldr r1, _080A6130 @ =0x080A5FD1
	bl FUN_080a5e68
	b _080A613A
	.align 2, 0
_080A6130: .4byte 0x080A5FD1
_080A6134:
	ldr r1, _080A6140 @ =0x080A5EC5
	bl FUN_080a5e68
_080A613A:
	pop {r0}
	bx r0
	.align 2, 0
_080A6140: .4byte 0x080A5EC5

	thumb_func_start FUN_080a6144
FUN_080a6144: @ 0x080A6144
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r5, [sp, #0x10]
	adds r1, r4, #0
	adds r1, #0x98
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xa0
	str r3, [r0]
	adds r0, #4
	str r5, [r0]
	subs r0, #0xb
	strb r2, [r0]
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080a6048
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080a6110
	ldr r1, _080A617C @ =0x0300014C
	str r4, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A617C: .4byte 0x0300014C

	thumb_func_start FUN_080a6180
FUN_080a6180: @ 0x080A6180
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	ldr r0, _080A61CC @ =0x0300014C
	ldr r0, [r0]
	cmp r0, #0
	bne _080A61DA
	movs r0, #4
	movs r1, #0xb0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A61D8
	ldr r1, _080A61D0 @ =0x080A6009
	ldr r2, _080A61D4 @ =0x080A6031
	bl SetEntityRoutine
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_080a6144
	cmp r0, #0
	bge _080A61D8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A61DA
	.align 2, 0
_080A61CC: .4byte 0x0300014C
_080A61D0: .4byte 0x080A6009
_080A61D4: .4byte 0x080A6031
_080A61D8:
	adds r0, r4, #0
_080A61DA:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a61e8
FUN_080a61e8: @ 0x080A61E8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x98
	movs r1, #1
	strb r1, [r0]
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A6204
	bl Script_GetValue
	adds r5, r0, #0
	b _080A6206
_080A6204:
	movs r5, #0
_080A6206:
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A6214
	bl Script_GetValue
_080A6214:
	adds r1, r4, #0
	adds r1, #0x99
	strb r0, [r1]
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A6232
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0xa8
	str r0, [r1]
	b _080A6238
_080A6232:
	adds r0, r4, #0
	adds r0, #0xa8
	str r1, [r0]
_080A6238:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a6048
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a6110
	ldr r1, _080A6254 @ =0x0300014C
	str r4, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A6254: .4byte 0x0300014C

	thumb_func_start FUN_080a6258
FUN_080a6258: @ 0x080A6258
	push {r4, lr}
	ldr r0, _080A628C @ =0x0300014C
	ldr r0, [r0]
	cmp r0, #0
	bne _080A629A
	movs r0, #4
	movs r1, #0xb0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A6298
	ldr r1, _080A6290 @ =0x080A6009
	ldr r2, _080A6294 @ =0x080A6031
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080a61e8
	cmp r0, #0
	bge _080A6298
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A629A
	.align 2, 0
_080A628C: .4byte 0x0300014C
_080A6290: .4byte 0x080A6009
_080A6294: .4byte 0x080A6031
_080A6298:
	adds r0, r4, #0
_080A629A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a62a0
FUN_080a62a0: @ 0x080A62A0
	push {r4, lr}
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A62E8
	ldr r0, _080A62F0 @ =0x0000FD22
	bl FUN_08230e70
	adds r4, r0, #0
	cmp r4, #0
	beq _080A62E8
	bl Script_GetValue
	strh r0, [r4, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _080A62E8
	movs r2, #0
	ldrh r0, [r4, #0x1c]
	cmp r2, r0
	bge _080A62E4
	movs r3, #1
	adds r1, r4, #0
	adds r1, #0x20
_080A62D4:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x28
	adds r2, #1
	ldrh r0, [r4, #0x1c]
	cmp r2, r0
	blt _080A62D4
_080A62E4:
	movs r0, #0
	strh r0, [r4, #0x1e]
_080A62E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A62F0: .4byte 0x0000FD22

	thumb_func_start FUN_080a62f4
FUN_080a62f4: @ 0x080A62F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	mov sb, r1
	adds r7, r2, #0
	mov sl, r3
	ldr r0, _080A6348 @ =0x0000FD22
	bl FUN_08230e70
	mov r8, r0
	cmp r0, #0
	bne _080A6314
	b _080A640E
_080A6314:
	ldr r0, _080A634C @ =0x00001C1A
	bl GetParticleGroup
	adds r4, r0, #0
	mov r0, r8
	ldrh r1, [r0, #0x1c]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	mov r1, r8
	adds r5, r1, r0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822d9f0
	cmp r7, #0
	bne _080A6350
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x33
	bl FUN_0822dafc
	b _080A635C
	.align 2, 0
_080A6348: .4byte 0x0000FD22
_080A634C: .4byte 0x00001C1A
_080A6350:
	adds r2, r7, #0
	adds r2, #0x34
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0822dafc
_080A635C:
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	mov r0, sl
	cmp r0, #0
	bne _080A63DE
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080A639A
	cmp r1, #0
	blt _080A639A
	ldr r0, _080A63A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080A639A
	ldr r0, _080A63A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A63AC
_080A639A:
	movs r3, #0
	ldr r2, _080A63A8 @ =0x030046A4
	b _080A63BA
	.align 2, 0
_080A63A0: .4byte 0x030046A8
_080A63A4: .4byte 0x030046AC
_080A63A8: .4byte 0x030046A4
_080A63AC:
	ldr r2, _080A63C8 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r3
_080A63BA:
	ldr r0, [r2]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A63CC
	movs r0, #0
	b _080A63D2
	.align 2, 0
_080A63C8: .4byte 0x030046A4
_080A63CC:
	lsls r0, r3, #2
	adds r0, #0xc
	adds r0, r1, r0
_080A63D2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	adds r0, #0x80
	strh r0, [r5, #0x1a]
_080A63DE:
	movs r0, #1
	strb r0, [r5, #0xf]
	mov r1, sb
	cmp r1, #0
	beq _080A6406
	cmp r1, #1
	bne _080A63F2
	ldr r0, [r5]
	movs r1, #4
	b _080A6402
_080A63F2:
	mov r0, sb
	cmp r0, #2
	bne _080A63FE
	ldr r0, [r5]
	movs r1, #0xc
	b _080A6402
_080A63FE:
	ldr r0, [r5]
	movs r1, #8
_080A6402:
	orrs r0, r1
	str r0, [r5]
_080A6406:
	mov r1, r8
	ldrh r0, [r1, #0x1c]
	adds r0, #1
	strh r0, [r1, #0x1c]
_080A640E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a641c
FUN_080a641c: @ 0x080A641C
	push {r4, r5, lr}
	sub sp, #8
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A6468
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080A6460 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080A6464 @ =0x0000FFFF
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
	b _080A6472
	.align 2, 0
_080A6460: .4byte 0xFFFF0000
_080A6464: .4byte 0x0000FFFF
_080A6468:
	ldr r1, _080A6484 @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_080A6472:
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A6488
	bl Script_GetValue
	adds r5, r0, #0
	b _080A648A
	.align 2, 0
_080A6484: .4byte 0xFFFF0000
_080A6488:
	movs r5, #0
_080A648A:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _080A649C
	bl Script_GetValue
	adds r4, r0, #0
	b _080A649E
_080A649C:
	movs r4, #0
_080A649E:
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A64B0
	bl Script_GetValue
	adds r2, r0, #0
	b _080A64B2
_080A64B0:
	movs r2, #0
_080A64B2:
	asrs r1, r4, #1
	adds r1, #1
	movs r0, #3
	ands r1, r0
	mov r0, sp
	adds r3, r5, #0
	bl FUN_080a62f4
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a64cc
FUN_080a64cc: @ 0x080A64CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov ip, r0
	ldrh r1, [r0, #4]
	subs r1, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080A654C @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r0, ip
	movs r3, #6
	ldrsh r1, [r0, r3]
	movs r4, #2
	ldrsh r0, [r0, r4]
	adds r1, r1, r0
	lsls r1, r1, #0xf
	lsrs r1, r1, #0x10
	mov r4, sp
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r3, sp, #8
	ldrh r0, [r3]
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sb, r3
	cmp r2, #0
	blt _080A6546
	cmp r1, #0
	blt _080A6546
	ldr r0, _080A6550 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A6546
	ldr r0, _080A6554 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A6558
_080A6546:
	movs r4, #0
	b _080A6566
	.align 2, 0
_080A654C: .4byte 0xFFFF0000
_080A6550: .4byte 0x030046A8
_080A6554: .4byte 0x030046AC
_080A6558:
	ldr r0, _080A6594 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A6566:
	add r0, sp, #8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sb
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A658E
	cmp r1, #0
	blt _080A658E
	ldr r0, _080A6598 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A658E
	ldr r0, _080A659C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A65A0
_080A658E:
	movs r3, #0
	b _080A65AE
	.align 2, 0
_080A6594: .4byte 0x030046A4
_080A6598: .4byte 0x030046A8
_080A659C: .4byte 0x030046AC
_080A65A0:
	ldr r0, _080A65C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r2
_080A65AE:
	cmp r4, r3
	beq _080A6650
	ldr r1, _080A65C4 @ =0x030046A4
	ldr r0, [r1]
	ldr r2, [r0, #4]
	mov r8, r1
	cmp r2, #0
	bne _080A65C8
	movs r2, #0
	b _080A65CE
	.align 2, 0
_080A65C4: .4byte 0x030046A4
_080A65C8:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r2, r2, r0
_080A65CE:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A65DC
	movs r7, #0
	b _080A65E2
_080A65DC:
	lsls r0, r3, #2
	adds r0, #0xc
	adds r7, r1, r0
_080A65E2:
	ldrb r0, [r2]
	movs r4, #0xf
	lsrs r2, r0, #4
	adds r5, r0, #0
	cmp r2, #1
	beq _080A6654
	cmp r2, #1
	blo _080A65F8
	cmp r2, #2
	beq _080A662A
	b _080A6654
_080A65F8:
	ldrb r1, [r7]
	lsrs r0, r1, #4
	ands r0, r4
	adds r2, r1, #0
	cmp r0, #0
	bne _080A661A
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	cmp r1, r0
	bne _080A661A
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A6650
_080A661A:
	lsrs r0, r2, #4
	cmp r0, #2
	bne _080A6654
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	b _080A6642
_080A662A:
	ldrb r2, [r7]
	lsrs r0, r2, #4
	ands r0, r4
	cmp r0, #0
	beq _080A6638
	cmp r0, #2
	bne _080A6654
_080A6638:
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	adds r0, #1
_080A6642:
	cmp r1, r0
	bne _080A6654
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080A6654
_080A6650:
	movs r0, #0
	b _080A6A64
_080A6654:
	mov r1, ip
	movs r2, #4
	ldrsh r0, [r1, r2]
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	asrs r0, r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r4, ip
	ldrh r0, [r4, #6]
	subs r0, #0x10
	mov r2, sp
	strh r0, [r2, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r1, sb
	ldrh r0, [r1, #4]
	adds r0, #0x20
	strh r0, [r1, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _080A66A6
	cmp r1, #0
	blt _080A66A6
	ldr r0, _080A66AC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080A66A6
	ldr r0, _080A66B0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A66B4
_080A66A6:
	movs r4, #0
	b _080A66C2
	.align 2, 0
_080A66AC: .4byte 0x030046A8
_080A66B0: .4byte 0x030046AC
_080A66B4:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080A66C2:
	add r0, sp, #8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r3, sb
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A66EA
	cmp r1, #0
	blt _080A66EA
	ldr r0, _080A66F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A66EA
	ldr r0, _080A66F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A66F8
_080A66EA:
	movs r3, #0
	b _080A6706
	.align 2, 0
_080A66F0: .4byte 0x030046A8
_080A66F4: .4byte 0x030046AC
_080A66F8:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r2
_080A6706:
	cmp r4, r3
	beq _080A67A0
	mov r1, r8
	ldr r0, [r1]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A6718
	movs r2, #0
	b _080A671E
_080A6718:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r2, r1, r0
_080A671E:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A672C
	movs r7, #0
	b _080A6732
_080A672C:
	lsls r0, r3, #2
	adds r0, #0xc
	adds r7, r1, r0
_080A6732:
	ldrb r0, [r2]
	movs r3, #0xf
	lsrs r2, r0, #4
	adds r5, r0, #0
	cmp r2, #1
	beq _080A677C
	cmp r2, #1
	bhs _080A67A4
	ldrb r1, [r7]
	lsrs r0, r1, #4
	ands r0, r3
	adds r2, r1, #0
	cmp r0, #0
	bne _080A6764
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	cmp r1, r0
	bne _080A6764
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A67A0
_080A6764:
	lsrs r4, r2, #4
	cmp r4, #1
	bne _080A67A4
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	cmp r1, r0
	bne _080A67A4
	ldrh r0, [r7, #2]
	ands r0, r4
	b _080A679C
_080A677C:
	ldrb r4, [r7]
	lsrs r0, r4, #4
	ands r0, r3
	cmp r0, #0
	beq _080A678A
	cmp r0, #1
	bne _080A67A4
_080A678A:
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r4
	adds r0, #1
	cmp r1, r0
	bne _080A67A4
	ldrh r0, [r7, #2]
	ands r0, r2
_080A679C:
	cmp r0, #0
	bne _080A67A4
_080A67A0:
	movs r0, #1
	b _080A6A64
_080A67A4:
	mov r1, ip
	ldrh r0, [r1]
	adds r0, #0x10
	mov r1, sp
	strh r0, [r1]
	mov r2, ip
	movs r3, #6
	ldrsh r0, [r2, r3]
	movs r4, #2
	ldrsh r1, [r2, r4]
	adds r0, r0, r1
	asrs r0, r0, #1
	mov r2, sp
	strh r0, [r2, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r1, sb
	ldrh r0, [r1]
	subs r0, #0x20
	add r1, sp, #8
	strh r0, [r1]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _080A67F8
	cmp r1, #0
	blt _080A67F8
	ldr r0, _080A67FC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080A67F8
	ldr r0, _080A6800 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A6804
_080A67F8:
	movs r4, #0
	b _080A6812
	.align 2, 0
_080A67FC: .4byte 0x030046A8
_080A6800: .4byte 0x030046AC
_080A6804:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080A6812:
	add r0, sp, #8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r3, sb
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A683A
	cmp r1, #0
	blt _080A683A
	ldr r0, _080A6840 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A683A
	ldr r0, _080A6844 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A6848
_080A683A:
	movs r3, #0
	b _080A6856
	.align 2, 0
_080A6840: .4byte 0x030046A8
_080A6844: .4byte 0x030046AC
_080A6848:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r2
_080A6856:
	cmp r4, r3
	beq _080A68FE
	mov r1, r8
	ldr r0, [r1]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A6868
	movs r2, #0
	b _080A686E
_080A6868:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r2, r1, r0
_080A686E:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A687C
	movs r7, #0
	b _080A6882
_080A687C:
	lsls r0, r3, #2
	adds r0, #0xc
	adds r7, r1, r0
_080A6882:
	ldrb r0, [r2]
	movs r6, #0xf
	lsrs r2, r0, #4
	adds r5, r0, #0
	cmp r2, #1
	beq _080A6902
	cmp r2, #1
	blo _080A6898
	cmp r2, #2
	beq _080A68CC
	b _080A6902
_080A6898:
	ldrb r1, [r7]
	lsrs r0, r1, #4
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	bne _080A68BA
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	cmp r1, r0
	bne _080A68BA
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A68FE
_080A68BA:
	lsrs r0, r2, #4
	cmp r0, #2
	bne _080A6902
	movs r1, #0xf
	adds r0, r1, #0
	ands r0, r5
	adds r0, #1
	ands r1, r2
	b _080A68F0
_080A68CC:
	ldrb r4, [r7]
	lsrs r2, r4, #4
	ands r2, r6
	cmp r2, #0
	bne _080A68E2
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r4
	cmp r1, r0
	beq _080A68F4
_080A68E2:
	cmp r2, #2
	bne _080A6902
	movs r1, #0xf
	adds r0, r1, #0
	ands r0, r5
	adds r0, #1
	ands r1, r4
_080A68F0:
	cmp r0, r1
	bne _080A6902
_080A68F4:
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080A6902
_080A68FE:
	movs r0, #2
	b _080A6A64
_080A6902:
	mov r1, ip
	movs r2, #4
	ldrsh r0, [r1, r2]
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	asrs r0, r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r4, ip
	ldrh r0, [r4, #2]
	adds r0, #0x10
	mov r2, sp
	strh r0, [r2, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r1, sb
	ldrh r0, [r1, #4]
	subs r0, #0x20
	strh r0, [r1, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _080A6954
	cmp r1, #0
	blt _080A6954
	ldr r0, _080A6958 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080A6954
	ldr r0, _080A695C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A6960
_080A6954:
	movs r4, #0
	b _080A696E
	.align 2, 0
_080A6958: .4byte 0x030046A8
_080A695C: .4byte 0x030046AC
_080A6960:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080A696E:
	add r0, sp, #8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	mov r1, sb
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080A6996
	cmp r1, #0
	blt _080A6996
	ldr r0, _080A699C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080A6996
	ldr r0, _080A69A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A69A4
_080A6996:
	movs r3, #0
	b _080A69B2
	.align 2, 0
_080A699C: .4byte 0x030046A8
_080A69A0: .4byte 0x030046AC
_080A69A4:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r3
_080A69B2:
	cmp r4, r3
	beq _080A6A5C
	mov r1, r8
	ldr r0, [r1]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A69C4
	movs r2, #0
	b _080A69CA
_080A69C4:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r2, r1, r0
_080A69CA:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A69D8
	movs r7, #0
	b _080A69DE
_080A69D8:
	lsls r0, r3, #2
	adds r0, #0xc
	adds r7, r1, r0
_080A69DE:
	ldrb r3, [r2]
	movs r6, #0xf
	lsrs r0, r3, #4
	adds r5, r3, #0
	cmp r0, #1
	beq _080A6A2A
	cmp r0, #1
	bhs _080A6A60
	ldrb r1, [r7]
	lsrs r0, r1, #4
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	bne _080A6A10
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r3
	ands r0, r2
	cmp r1, r0
	bne _080A6A10
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A6A5C
_080A6A10:
	lsrs r4, r2, #4
	cmp r4, #1
	bne _080A6A60
	movs r1, #0xf
	adds r0, r1, #0
	ands r0, r5
	adds r0, #1
	ands r1, r2
	cmp r0, r1
	bne _080A6A60
	ldrh r0, [r7, #2]
	ands r0, r4
	b _080A6A58
_080A6A2A:
	ldrb r4, [r7]
	lsrs r2, r4, #4
	ands r2, r6
	cmp r2, #0
	bne _080A6A40
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r3
	ands r0, r4
	cmp r1, r0
	beq _080A6A52
_080A6A40:
	cmp r2, #1
	bne _080A6A60
	movs r1, #0xf
	adds r0, r1, #0
	ands r0, r3
	adds r0, #1
	ands r1, r4
	cmp r0, r1
	bne _080A6A60
_080A6A52:
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
_080A6A58:
	cmp r0, #0
	bne _080A6A60
_080A6A5C:
	movs r0, #3
	b _080A6A64
_080A6A60:
	movs r0, #1
	rsbs r0, r0, #0
_080A6A64:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Map_SpawnLoadingZoneIndicator
Map_SpawnLoadingZoneIndicator: @ 0x080A6A74
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _080A6A88
	bl Script_GetValue
	b _080A6A8A
_080A6A88:
	movs r0, #0
_080A6A8A:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl FUN_0823492c
	adds r5, r0, #0
	cmp r5, #0
	beq _080A6B80
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r1, r1, r0
	lsls r1, r1, #0xf
	lsrs r1, r1, #0x10
	ldr r3, _080A6AF8 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #6
	ldrsh r0, [r5, r2]
	adds r1, r1, r0
	lsls r1, r1, #0xf
	lsrs r1, r1, #0x10
	add r2, sp, #4
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	adds r6, r2, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r7, r6, #0
	cmp r2, #0
	blt _080A6AF2
	cmp r1, #0
	blt _080A6AF2
	ldr r0, _080A6AFC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A6AF2
	ldr r0, _080A6B00 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A6B04
_080A6AF2:
	movs r4, #0
	b _080A6B12
	.align 2, 0
_080A6AF8: .4byte 0xFFFF0000
_080A6AFC: .4byte 0x030046A8
_080A6B00: .4byte 0x030046AC
_080A6B04:
	ldr r0, _080A6B24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A6B12:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A6B28
	adds r0, #4
	b _080A6B34
	.align 2, 0
_080A6B24: .4byte 0x030046A4
_080A6B28:
	ldr r0, _080A6B48 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A6B34:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A6B4C
	cmp r2, #2
	beq _080A6B50
	b _080A6B54
	.align 2, 0
_080A6B48: .4byte 0x030046A4
_080A6B4C:
	ldrb r0, [r6, #4]
	b _080A6B52
_080A6B50:
	ldrb r0, [r6]
_080A6B52:
	subs r1, r1, r0
_080A6B54:
	strh r1, [r7, #2]
	adds r0, r5, #0
	bl FUN_080a64cc
	adds r4, r0, #0
	cmp r4, #0
	blt _080A6B80
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A6B74
	bl Script_GetValue
	adds r2, r0, #0
	b _080A6B76
_080A6B74:
	movs r2, #0
_080A6B76:
	adds r0, r7, #0
	adds r1, r4, #0
	movs r3, #0
	bl FUN_080a62f4
_080A6B80:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a6b88
FUN_080a6b88: @ 0x080A6B88
	push {r4, lr}
	adds r3, r0, #0
	movs r1, #0
	ldrh r2, [r3, #0x18]
	cmp r2, #0
	bne _080A6BBC
	ldr r0, _080A6BB8 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x14
	ldrsh r0, [r0, r4]
	cmp r0, #0
	beq _080A6BBC
	ldrh r0, [r3, #0x1e]
	cmp r0, #0x2f
	bhi _080A6BA8
	movs r1, #1
_080A6BA8:
	adds r0, #1
	strh r0, [r3, #0x1e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x47
	bls _080A6BBE
	strh r2, [r3, #0x1e]
	b _080A6BBE
	.align 2, 0
_080A6BB8: .4byte 0x030046A0
_080A6BBC:
	strh r1, [r3, #0x1e]
_080A6BBE:
	cmp r1, #0
	beq _080A6BE4
	movs r2, #0
	ldrh r0, [r3, #0x1c]
	cmp r2, r0
	bge _080A6C02
	movs r4, #2
	rsbs r4, r4, #0
	adds r1, r3, #0
	adds r1, #0x20
_080A6BD2:
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	adds r1, #0x28
	adds r2, #1
	ldrh r0, [r3, #0x1c]
	cmp r2, r0
	blt _080A6BD2
	b _080A6C02
_080A6BE4:
	movs r2, #0
	ldrh r4, [r3, #0x1c]
	cmp r2, r4
	bge _080A6C02
	movs r4, #1
	adds r1, r3, #0
	adds r1, #0x20
_080A6BF2:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x28
	adds r2, #1
	ldrh r0, [r3, #0x1c]
	cmp r2, r0
	blt _080A6BF2
_080A6C02:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a6c0c
FUN_080a6c0c: @ 0x080A6C0C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrh r0, [r6, #0x1c]
	cmp r5, r0
	bge _080A6C2C
	adds r4, r6, #0
	adds r4, #0x20
_080A6C1C:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x28
	adds r5, #1
	ldrh r0, [r6, #0x1c]
	cmp r5, r0
	blt _080A6C1C
_080A6C2C:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a6c34
FUN_080a6c34: @ 0x080A6C34
	push {lr}
	adds r1, r0, #0
	movs r0, #0
	strh r0, [r1, #0x18]
	strh r0, [r1, #0x1c]
	strh r0, [r1, #0x1e]
	ldr r0, _080A6C50 @ =0x0000FD22
	movs r2, #0
	bl FUN_08230e30
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080A6C50: .4byte 0x0000FD22

	thumb_func_start FUN_080a6c54
FUN_080a6c54: @ 0x080A6C54
	push {r4, lr}
	movs r1, #0xb2
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A6C8C
	ldr r1, _080A6C84 @ =FUN_080a6b88
	ldr r2, _080A6C88 @ =FUN_080a6c0c
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080a6c34
	cmp r0, #0
	bge _080A6C8C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A6C8E
	.align 2, 0
_080A6C84: .4byte FUN_080a6b88
_080A6C88: .4byte FUN_080a6c0c
_080A6C8C:
	adds r0, r4, #0
_080A6C8E:
	pop {r4}
	pop {r1}
	bx r1

@ a.k.a. InitArray
	thumb_func_start EngineCall_InitArray
EngineCall_InitArray: @ 0x080A6C94
	push {r4, lr}
	sub sp, #8
	mov r0, sp
	bl FUN_0823167c
	movs r4, #0
	b _080A6CB2
_080A6CA2:
	bl Script_GetValue
	adds r2, r0, #0
	mov r0, sp
	adds r1, r4, #0
	bl FUN_0823206c
	adds r4, #1
_080A6CB2:
	bl VM_GetPC
	cmp r0, #0
	bne _080A6CA2
	movs r0, #0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1

@ a.k.a. Loop
	thumb_func_start EngineCall_Loop
EngineCall_Loop: @ 0x080A6CC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov r7, sp
	mov r1, sp
	adds r0, r1, #0
	str r0, [r7, #0xc]
	movs r0, #0x61
	bl prepare_08231510
	bl Script_GetValue
	mov r8, r0
	movs r0, #0x72
	bl prepare_08231510
	bl Script_GetValue
	mov sb, r0
	mov r1, r8
	lsls r0, r1, #5
	lsrs r0, r0, #3
	mov r1, sp
	subs r1, r1, r0
	mov sp, r1
	mov r0, sp
	str r0, [r7, #8]
	mov r0, r8
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080A6D7C @ =0xFFFF0000
	ldr r0, [r7]
	ands r0, r2
	orrs r0, r1
	str r0, [r7]
	mov r1, sp
	str r1, [r7, #4]
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _080A6D66
	bl Script_GetValue
	mov sl, r0
	movs r0, #0x64
	bl prepare_08231510
	bl VM_GetPC
	adds r6, r0, #0
	movs r0, #0
	cmp r0, sb
	bge _080A6D66
_080A6D36:
	adds r0, #1
	str r0, [r7, #0x10]
	mov r0, r8
	cmp r0, #0
	ble _080A6D58
	ldr r5, [r7, #8]
	mov r4, r8
_080A6D44:
	adds r0, r6, #0
	bl VM_GetValueAt
	stm r5!, {r0}
	bl VM_GetPC
	adds r6, r0, #0
	subs r4, #1
	cmp r4, #0
	bne _080A6D44
_080A6D58:
	mov r0, sl
	adds r1, r7, #0
	bl Script_ExecByPointer
	ldr r0, [r7, #0x10]
	cmp r0, sb
	blt _080A6D36
_080A6D66:
	movs r0, #0
	ldr r1, [r7, #0xc]
	mov sp, r1
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A6D7C: .4byte 0xFFFF0000

@ a.k.a. rand
	thumb_func_start EngineCall_Rand
EngineCall_Rand: @ 0x080A6D80
	push {lr}
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A6DC0
	bl Script_GetValue
	adds r3, r0, #0
	cmp r3, #0
	ble _080A6DC0
	ldr r2, _080A6DB4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A6DB8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080A6DBC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	adds r1, r3, #0
	bl Mod
	b _080A6DD4
	.align 2, 0
_080A6DB4: .4byte 0x030046B8
_080A6DB8: .4byte 0x000003FF
_080A6DBC: .4byte 0x0203B400
_080A6DC0:
	ldr r2, _080A6DD8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A6DDC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080A6DE0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
_080A6DD4:
	pop {r1}
	bx r1
	.align 2, 0
_080A6DD8: .4byte 0x030046B8
_080A6DDC: .4byte 0x000003FF
_080A6DE0: .4byte 0x0203B400

	thumb_func_start FUN_080a6de4
FUN_080a6de4: @ 0x080A6DE4
	push {lr}
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A6DFC
	ldr r0, _080A6DF8 @ =0x030044E0
	ldrh r0, [r0, #2]
	b _080A6E28
	.align 2, 0
_080A6DF8: .4byte 0x030044E0
_080A6DFC:
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080A6E10
	ldr r0, _080A6E0C @ =0x030044E0
	ldrh r0, [r0]
	b _080A6E28
	.align 2, 0
_080A6E0C: .4byte 0x030044E0
_080A6E10:
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	bne _080A6E24
	ldr r0, _080A6E20 @ =0x030044E0
	ldrh r0, [r0, #2]
	b _080A6E28
	.align 2, 0
_080A6E20: .4byte 0x030044E0
_080A6E24:
	ldr r0, _080A6E2C @ =0x030044E0
	ldrh r0, [r0, #4]
_080A6E28:
	pop {r1}
	bx r1
	.align 2, 0
_080A6E2C: .4byte 0x030044E0

	thumb_func_start FUN_080a6e30
FUN_080a6e30: @ 0x080A6E30
	push {r4, r5, lr}
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080A6E5C
	bl VM_GetValueSafe2
	adds r5, r0, #0
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _080A6E5C
	bl Script_GetValue
	adds r4, r0, #0
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	bne _080A6E62
_080A6E5C:
	movs r0, #1
	rsbs r0, r0, #0
	b _080A6E80
_080A6E62:
	bl Script_GetValue
	cmp r0, #0
	bne _080A6E70
	adds r0, r5, r4
	ldrb r0, [r0]
	b _080A6E80
_080A6E70:
	cmp r0, #1
	beq _080A6E78
	lsls r0, r4, #2
	b _080A6E7A
_080A6E78:
	lsls r0, r4, #1
_080A6E7A:
	adds r0, r5, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
_080A6E80:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a6e88
FUN_080a6e88: @ 0x080A6E88
	push {r4, r5, lr}
	ldr r3, _080A6EB8 @ =0x030047A4
	ldr r1, [r3]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r1, r2
	str r1, [r3]
	cmp r0, #0
	beq _080A6EB0
	ldr r4, _080A6EBC @ =0x030044BC
	ldr r0, [r4]
	movs r5, #8
	ands r0, r5
	cmp r0, #0
	bne _080A6EB0
	bl FUN_08240918
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
_080A6EB0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A6EB8: .4byte 0x030047A4
_080A6EBC: .4byte 0x030044BC

	thumb_func_start FUN_080a6ec0
FUN_080a6ec0: @ 0x080A6EC0
	push {lr}
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A6ED2
	bl Script_GetValue
	b _080A6ED4
_080A6ED2:
	movs r0, #0
_080A6ED4:
	bl FUN_080a6e88
	pop {r0}
	bx r0

	thumb_func_start FUN_080a6edc
FUN_080a6edc: @ 0x080A6EDC
	push {r4, lr}
	ldr r2, _080A6F08 @ =0x030047A4
	ldr r0, [r2]
	ldr r1, _080A6F0C @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r2]
	ldr r4, _080A6F10 @ =0x030044BC
	ldr r0, [r4]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _080A6F02
	bl FUN_08240930
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_080A6F02:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A6F08: .4byte 0x030047A4
_080A6F0C: .4byte 0xFFFFFDFF
_080A6F10: .4byte 0x030044BC

	thumb_func_start FUN_080a6f14
FUN_080a6f14: @ 0x080A6F14
	push {lr}
	bl FUN_080a6edc
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a6f20
FUN_080a6f20: @ 0x080A6F20
	push {lr}
	ldr r0, _080A6F34 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A6F38
	movs r0, #0
	b _080A6F3A
	.align 2, 0
_080A6F34: .4byte 0x030047A4
_080A6F38:
	movs r0, #1
_080A6F3A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a6f40
FUN_080a6f40: @ 0x080A6F40
	ldr r1, _080A6F50 @ =0x030047A4
	ldr r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #4
	orrs r2, r3
	str r2, [r1]
	bx lr
	.align 2, 0
_080A6F50: .4byte 0x030047A4

	thumb_func_start FUN_080a6f54
FUN_080a6f54: @ 0x080A6F54
	push {lr}
	adds r3, r0, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	cmp r0, #5
	bhi _080A6F90
	ldr r2, _080A6F84 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A6F88 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080A6F8C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #4
	movs r1, #0xf
	ands r0, r1
	subs r0, #7
	adds r1, r3, #0
	adds r1, #0x58
	strh r0, [r1]
	b _080A6F9C
	.align 2, 0
_080A6F84: .4byte 0x030046B8
_080A6F88: .4byte 0x000003FF
_080A6F8C: .4byte 0x0203B400
_080A6F90:
	adds r0, r3, #0
	adds r0, #0x58
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_080A6F9C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a6fa0
FUN_080a6fa0: @ 0x080A6FA0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xac
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r2, r4, #0
	adds r2, #0x9a
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	adds r2, #2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r2, [r2]
	cmp r1, r2
	blo _080A6FDA
	adds r0, r4, #0
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, #0
	beq _080A6FD4
	movs r1, #0
	bl Script_ExecById
_080A6FD4:
	adds r0, r4, #0
	bl KillEntity
_080A6FDA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a6fe0
FUN_080a6fe0: @ 0x080A6FE0
	push {lr}
	adds r0, #0x38
	bl FUN_0822f1c0
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a6ff0
FUN_080a6ff0: @ 0x080A6FF0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _080A700C @ =0x0000CB05
	ldr r1, _080A7010 @ =0x000082F1
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _080A7014
	movs r0, #1
	rsbs r0, r0, #0
	b _080A70C0
	.align 2, 0
_080A700C: .4byte 0x0000CB05
_080A7010: .4byte 0x000082F1
_080A7014:
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r2, #0
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	movs r0, #0x74
	bl prepare_08231510
	adds r7, r4, #0
	cmp r0, #0
	beq _080A7046
	bl Script_GetValue
	adds r6, r0, #0
	b _080A7048
_080A7046:
	movs r6, #0
_080A7048:
	movs r0, #0x49
	bl prepare_08231510
	cmp r0, #0
	beq _080A705C
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x9c
	b _080A7062
_080A705C:
	adds r1, r5, #0
	adds r1, #0x9c
	movs r0, #0x3c
_080A7062:
	strh r0, [r1]
	adds r1, r5, #0
	adds r1, #0xac
	ldr r0, _080A70B4 @ =0x080A6F55
	str r0, [r1]
	adds r4, r5, #0
	adds r4, #0xa0
	movs r3, #0
	strh r3, [r4]
	adds r0, r5, #0
	adds r0, #0xa2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	subs r0, #0x6c
	adds r2, r6, #0
	adds r2, #0xb
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #1
	str r1, [sp]
	str r3, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	adds r1, r7, #0
	movs r3, #0x10
	bl FUN_0822f3fc
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A70B8
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0xa8
	str r0, [r1]
	b _080A70BE
	.align 2, 0
_080A70B4: .4byte 0x080A6F55
_080A70B8:
	adds r0, r5, #0
	adds r0, #0xa8
	str r1, [r0]
_080A70BE:
	movs r0, #0
_080A70C0:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a70c8
FUN_080a70c8: @ 0x080A70C8
	push {r4, lr}
	movs r0, #9
	movs r1, #0xb0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A70FC
	ldr r1, _080A70F4 @ =FUN_080a6fa0
	ldr r2, _080A70F8 @ =FUN_080a6fe0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080a6ff0
	cmp r0, #0
	beq _080A70FC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A70FE
	.align 2, 0
_080A70F4: .4byte FUN_080a6fa0
_080A70F8: .4byte FUN_080a6fe0
_080A70FC:
	adds r0, r4, #0
_080A70FE:
	pop {r4}
	pop {r1}
	bx r1

