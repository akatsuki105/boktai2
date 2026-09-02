	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_0817b938
FUN_0817b938: @ 0x0817B938
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x10
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0x10
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #0x12
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #0x14
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0x16
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0x17
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x15
	movs r2, #0x18
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0x19
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #0x1d
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0x22
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #0x26
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #0x24
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0817b9e8
FUN_0817b9e8: @ 0x0817B9E8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #1
	ldr r2, _0817BA08 @ =0x00000898
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817BA0C
	movs r0, #1
	b _0817BA0E
	.align 2, 0
_0817BA08: .4byte 0x00000898
_0817BA0C:
	movs r0, #0
_0817BA0E:
	cmp r0, #0
	beq _0817BA44
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0x19
	movs r3, #0
	bl FUN_080ef84c
	b _0817BA74
_0817BA44:
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0xe
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0x1b
	movs r3, #0
	bl FUN_080ef84c
_0817BA74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0817ba7c
FUN_0817ba7c: @ 0x0817BA7C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	movs r1, #1
	ldr r2, _0817BA9C @ =0x00000898
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817BAA0
	movs r0, #1
	b _0817BAA2
	.align 2, 0
_0817BA9C: .4byte 0x00000898
_0817BAA0:
	movs r0, #0
_0817BAA2:
	cmp r0, #0
	beq _0817BB42
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	ldr r0, _0817BAEC @ =0x0000FFFE
	cmp r1, r0
	bhi _0817BB38
	ldr r5, _0817BAF0 @ =0x0000087C
	adds r0, r6, r5
	ldrh r5, [r0]
	cmp r5, #0
	bne _0817BAFC
	adds r0, r4, #0
	bl FUN_0817ea84
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817BAFC
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	ldr r3, _0817BAF4 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _0817BAF8 @ =0x0000046A
	adds r0, r4, r1
	strb r5, [r0]
	adds r2, #0x1c
	adds r0, r4, r2
	str r5, [r0]
	adds r3, #3
	adds r1, r4, r3
	b _0817BB28
	.align 2, 0
_0817BAEC: .4byte 0x0000FFFE
_0817BAF0: .4byte 0x0000087C
_0817BAF4: .4byte 0x00000469
_0817BAF8: .4byte 0x0000046A
_0817BAFC:
	movs r5, #0x88
	lsls r5, r5, #4
	adds r0, r6, r5
	ldrh r2, [r0]
	cmp r2, #0
	bne _0817BB38
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	ldr r5, _0817BB30 @ =0x00000469
	adds r0, r4, r5
	strb r1, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r2, [r0]
	ldr r0, _0817BB34 @ =0x0000046C
	adds r1, r4, r0
_0817BB28:
	movs r0, #1
	strb r0, [r1]
	b _0817BB72
	.align 2, 0
_0817BB30: .4byte 0x00000469
_0817BB34: .4byte 0x0000046C
_0817BB38:
	ldr r1, _0817BB48 @ =0x0000087E
	adds r0, r6, r1
	ldrh r3, [r0]
	cmp r3, #0
	beq _0817BB4C
_0817BB42:
	movs r0, #0
	b _0817BB72
	.align 2, 0
_0817BB48: .4byte 0x0000087E
_0817BB4C:
	movs r1, #2
	movs r2, #1
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r4, r5
	strb r3, [r0]
	adds r5, #1
	adds r0, r4, r5
	strb r1, [r0]
	ldr r1, _0817BB78 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r3, [r0]
	adds r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #1
_0817BB72:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0817BB78: .4byte 0x0000046A

	thumb_func_start FUN_0817bb7c
FUN_0817bb7c: @ 0x0817BB7C
	push {lr}
	adds r3, r0, #0
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhi _0817BBD8
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrb r1, [r0]
	ldrb r0, [r3, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0817BBB0
	ldr r2, _0817BBAC @ =0xFFFFFF00
	adds r1, r1, r2
	b _0817BBBE
	.align 2, 0
_0817BBAC: .4byte 0xFFFFFF00
_0817BBB0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0817BBBE
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0817BBBE:
	cmp r1, #0
	bge _0817BBC4
	rsbs r1, r1, #0
_0817BBC4:
	ldr r2, _0817BBD4 @ =0x000001FD
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r1, r0
	bgt _0817BBD8
	movs r0, #1
	b _0817BBDA
	.align 2, 0
_0817BBD4: .4byte 0x000001FD
_0817BBD8:
	movs r0, #0
_0817BBDA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0817bbe0
FUN_0817bbe0: @ 0x0817BBE0
	bx lr
	.align 2, 0

	thumb_func_start FUN_0817bbe4
FUN_0817bbe4: @ 0x0817BBE4
	bx lr
	.align 2, 0

	thumb_func_start FUN_0817bbe8
FUN_0817bbe8: @ 0x0817BBE8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	bne _0817BC6C
	ldrh r0, [r5, #0x14]
	cmp r0, #0
	beq _0817BC02
	cmp r0, #4
	bne _0817BC0A
_0817BC02:
	adds r0, r4, #0
	movs r1, #3
	bl FUN_0817db8c
_0817BC0A:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #1
	ldr r2, _0817BC34 @ =0x00000898
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817BC38
	movs r0, #1
	b _0817BC3A
	.align 2, 0
_0817BC34: .4byte 0x00000898
_0817BC38:
	movs r0, #0
_0817BC3A:
	cmp r0, #0
	beq _0817BC54
	ldr r2, _0817BC50 @ =0x085ADB6C
	ldrh r1, [r5, #0x14]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	b _0817BC6E
	.align 2, 0
_0817BC50: .4byte 0x085ADB6C
_0817BC54:
	ldr r1, _0817BC68 @ =0x085ADB6C
	ldrh r2, [r5, #0x14]
	movs r0, #7
	ands r0, r2
	lsls r0, r0, #1
	adds r1, #0x10
	adds r0, r0, r1
	ldrh r0, [r0]
	b _0817BC6E
	.align 2, 0
_0817BC68: .4byte 0x085ADB6C
_0817BC6C:
	movs r0, #0
_0817BC6E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0817bc74
FUN_0817bc74: @ 0x0817BC74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #8]
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	asrs r6, r1, #6
	adds r0, r6, #2
	str r0, [sp, #0xc]
	movs r0, #3
	ldr r1, [sp, #0xc]
	ands r1, r0
	str r1, [sp, #0xc]
	movs r2, #0
	str r2, [sp, #0x10]
_0817BC9A:
	ldr r3, [sp, #0xc]
	cmp r6, r3
	bne _0817BCA2
	b _0817C000
_0817BCA2:
	cmp r6, #1
	beq _0817BCCC
	cmp r6, #1
	bgt _0817BCB0
	cmp r6, #0
	beq _0817BCBA
	b _0817BD20
_0817BCB0:
	cmp r6, #2
	beq _0817BCEC
	cmp r6, #3
	beq _0817BD00
	b _0817BD20
_0817BCBA:
	ldr r0, [sp, #8]
	ldr r2, _0817BCC8 @ =0x00000256
	adds r1, r0, r2
	ldrh r0, [r1]
	adds r7, r0, #1
	mov r8, r1
	b _0817BD2A
	.align 2, 0
_0817BCC8: .4byte 0x00000256
_0817BCCC:
	ldr r3, [sp, #8]
	ldr r0, _0817BCE4 @ =0x00000256
	adds r1, r3, r0
	ldr r2, _0817BCE8 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldrh r2, [r1]
	adds r7, r0, r2
	mov r8, r1
	b _0817BD2A
	.align 2, 0
_0817BCE4: .4byte 0x00000256
_0817BCE8: .4byte 0x030046A4
_0817BCEC:
	ldr r3, [sp, #8]
	ldr r0, _0817BCFC @ =0x00000256
	adds r1, r3, r0
	ldrh r0, [r1]
	subs r7, r0, #1
	mov r8, r1
	b _0817BD2A
	.align 2, 0
_0817BCFC: .4byte 0x00000256
_0817BD00:
	ldr r2, [sp, #8]
	ldr r3, _0817BD18 @ =0x00000256
	adds r1, r2, r3
	ldrh r2, [r1]
	ldr r3, _0817BD1C @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r7, r2, r0
	mov r8, r1
	b _0817BD2A
	.align 2, 0
_0817BD18: .4byte 0x00000256
_0817BD1C: .4byte 0x030046A4
_0817BD20:
	ldr r1, [sp, #8]
	ldr r2, _0817BD3C @ =0x00000256
	adds r0, r1, r2
	ldrh r7, [r0]
	mov r8, r0
_0817BD2A:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817BD40
	adds r0, #4
	b _0817BD4C
	.align 2, 0
_0817BD3C: .4byte 0x00000256
_0817BD40:
	ldr r3, _0817BD68 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817BD4C:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x14]
	mov r0, r8
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817BD6C
	adds r0, #4
	b _0817BD78
	.align 2, 0
_0817BD68: .4byte 0x030046A4
_0817BD6C:
	ldr r1, _0817BD90 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817BD78:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x18]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817BD94
	adds r0, #4
	b _0817BDA0
	.align 2, 0
_0817BD90: .4byte 0x030046A4
_0817BD94:
	ldr r2, _0817BDE0 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817BDA0:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x1c]
	mov sl, sp
	ldr r5, _0817BDE0 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817BDE4
	adds r0, #4
	b _0817BDEE
	.align 2, 0
_0817BDE0: .4byte 0x030046A4
_0817BDE4:
	ldr r0, [r5]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817BDEE:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r3, sl
	strh r1, [r3, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817BE14
	adds r0, #4
	b _0817BE20
_0817BE14:
	ldr r2, _0817BE38 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817BE20:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r3, #0xf
	ands r2, r3
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0817BE3C
	cmp r2, #2
	beq _0817BE40
	b _0817BE44
	.align 2, 0
_0817BE38: .4byte 0x030046A4
_0817BE3C:
	ldrb r0, [r4, #4]
	b _0817BE42
_0817BE40:
	ldrb r0, [r4]
_0817BE42:
	subs r1, r1, r0
_0817BE44:
	str r1, [sp, #0x20]
	mov r0, r8
	ldrh r5, [r0]
	mov sl, sp
	ldr r1, _0817BE88 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r3, _0817BE88 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817BE8C
	adds r0, #4
	b _0817BE98
	.align 2, 0
_0817BE88: .4byte 0x030046A4
_0817BE8C:
	ldr r3, _0817BEC4 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817BE98:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r0, sl
	strh r1, [r0, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	mov r2, sl
	strh r0, [r2, #4]
	mov r3, r8
	ldrh r4, [r3]
	mov r5, sp
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817BEC8
	adds r0, #4
	b _0817BED4
	.align 2, 0
_0817BEC4: .4byte 0x030046A4
_0817BEC8:
	ldr r1, _0817BEEC @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817BED4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r3, #0xf
	ands r2, r3
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0817BEF0
	cmp r2, #2
	beq _0817BEF4
	b _0817BEF8
	.align 2, 0
_0817BEEC: .4byte 0x030046A4
_0817BEF0:
	ldrb r0, [r5, #4]
	b _0817BEF6
_0817BEF4:
	ldrb r0, [r5]
_0817BEF6:
	subs r1, r1, r0
_0817BEF8:
	ldr r0, [sp, #0x20]
	subs r2, r0, r1
	adds r0, r1, #0
	adds r0, #0xff
	asrs r0, r0, #8
	ldr r1, [sp, #0x20]
	adds r1, #0xff
	asrs r1, r1, #8
	subs r0, r0, r1
	lsls r1, r0, #8
	movs r0, #0x43
	ldr r3, [sp, #0x1c]
	ands r3, r0
	cmp r3, #0
	bne _0817C000
	cmp r2, #0
	beq _0817BFFA
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bne _0817BF36
	cmp r6, #1
	bne _0817BF30
	ldr r3, [sp, #0x18]
	cmp r3, #1
	bne _0817BF4C
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817BF5A
_0817BF30:
	cmp r6, #3
	bne _0817C000
	b _0817BF56
_0817BF36:
	ldr r0, [sp, #0x14]
	cmp r0, #2
	bne _0817BF5E
	cmp r6, #0
	bne _0817BF52
	ldr r3, [sp, #0x18]
	cmp r3, #2
	bne _0817BF4C
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817BF5A
_0817BF4C:
	cmp r1, #0
	beq _0817BF5E
	b _0817C000
_0817BF52:
	cmp r6, #2
	bne _0817C000
_0817BF56:
	ldr r3, [sp, #0x18]
	ldr r0, _0817BF74 @ =0xFFFFFF00
_0817BF5A:
	cmp r1, r0
	bne _0817C000
_0817BF5E:
	ldr r0, [sp, #0x18]
	cmp r0, #1
	bne _0817BF84
	cmp r6, #1
	bne _0817BF78
	ldr r3, [sp, #0x14]
	cmp r3, #1
	bne _0817BF94
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817BFB0
	.align 2, 0
_0817BF74: .4byte 0xFFFFFF00
_0817BF78:
	cmp r6, #3
	bne _0817C000
	ldr r0, [sp, #0x14]
	cmp r0, #1
	beq _0817BFAE
	b _0817BFBC
_0817BF84:
	ldr r3, [sp, #0x18]
	cmp r3, #2
	bne _0817BFCC
	cmp r6, #0
	bne _0817BFA4
	ldr r0, [sp, #0x14]
	cmp r0, #2
	bne _0817BF9E
_0817BF94:
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r1, r3
	beq _0817BFC0
	b _0817C000
_0817BF9E:
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817BFB0
_0817BFA4:
	cmp r6, #2
	bne _0817C000
	ldr r3, [sp, #0x14]
	cmp r3, #2
	bne _0817BFBC
_0817BFAE:
	ldr r0, _0817BFB8 @ =0xFFFFFF00
_0817BFB0:
	cmp r1, r0
	beq _0817BFC0
	b _0817C000
	.align 2, 0
_0817BFB8: .4byte 0xFFFFFF00
_0817BFBC:
	cmp r1, #0
	bne _0817C000
_0817BFC0:
	ldr r0, [sp, #0x18]
	cmp r0, #2
	bne _0817BFCC
	ldr r1, [sp, #0x14]
	cmp r1, #2
	beq _0817BFD8
_0817BFCC:
	ldr r3, [sp, #0x18]
	cmp r3, #1
	bne _0817BFEA
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bne _0817BFEA
_0817BFD8:
	adds r0, r2, #0
	cmp r2, #0
	bge _0817BFE0
	rsbs r0, r2, #0
_0817BFE0:
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	ble _0817BFFA
	b _0817C000
_0817BFEA:
	adds r0, r2, #0
	cmp r0, #0
	bge _0817BFF2
	rsbs r0, r0, #0
_0817BFF2:
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0xff
	bgt _0817BFFC
_0817BFFA:
	adds r1, r7, #0
_0817BFFC:
	cmp r1, #0
	bge _0817C008
_0817C000:
	adds r6, #1
	movs r0, #3
	ands r6, r0
	b _0817C00C
_0817C008:
	adds r0, r6, #0
	b _0817C01C
_0817C00C:
	ldr r2, [sp, #0x10]
	adds r2, #1
	str r2, [sp, #0x10]
	cmp r2, #3
	bgt _0817C018
	b _0817BC9A
_0817C018:
	movs r0, #1
	rsbs r0, r0, #0
_0817C01C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0817c02c
FUN_0817c02c: @ 0x0817C02C
	push {r4, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r2, _0817C060 @ =0x00000864
	adds r0, r1, r2
	movs r2, #0xc8
	lsls r2, r2, #9
	str r2, [r0]
	movs r4, #0x8a
	lsls r4, r4, #4
	adds r0, r1, r4
	str r2, [r0]
	ldr r0, _0817C064 @ =0x000008A4
	adds r1, r1, r0
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r0, [r0]
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0817C060: .4byte 0x00000864
_0817C064: .4byte 0x000008A4

	thumb_func_start FUN_0817c068
FUN_0817c068: @ 0x0817C068
	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _0817C090 @ =0x0000087C
	adds r1, r0, r2
	movs r2, #5
_0817C078:
	ldrh r0, [r1]
	cmp r0, #0
	beq _0817C082
	subs r0, #1
	strh r0, [r1]
_0817C082:
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0817C078
	pop {r0}
	bx r0
	.align 2, 0
_0817C090: .4byte 0x0000087C

	thumb_func_start FUN_0817c094
FUN_0817c094: @ 0x0817C094
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r0
	str r1, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r1, _0817C0D0 @ =0x00000256
	add r1, sb
	str r1, [sp, #0x10]
	mov r2, sb
	adds r2, #8
	str r2, [sp, #0x18]
	str r2, [sp, #0x14]
	ldr r0, _0817C0D4 @ =0x030046A4
	mov sl, r0
_0817C0BA:
	ldr r1, [sp, #0x10]
	ldrh r6, [r1]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817C0D8
	adds r0, #4
	b _0817C0E4
	.align 2, 0
_0817C0D0: .4byte 0x00000256
_0817C0D4: .4byte 0x030046A4
_0817C0D8:
	mov r2, sl
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817C0E4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0817C0F8
	cmp r3, #2
	beq _0817C0FE
	b _0817C104
_0817C0F8:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1, #4]
	b _0817C102
_0817C0FE:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
_0817C102:
	subs r2, r2, r0
_0817C104:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817C116
	adds r0, #4
	b _0817C122
_0817C116:
	mov r2, sl
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817C122:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0817C134
	asrs r0, r0, #6
	b _0817C13A
_0817C134:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0817C13A:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0817C178
	cmp r1, #1
	bgt _0817C14C
	cmp r1, #0
	beq _0817C156
	b _0817C22C
_0817C14C:
	cmp r1, #2
	beq _0817C1B4
	cmp r1, #3
	beq _0817C1D6
	b _0817C22C
_0817C156:
	adds r4, r6, #1
	movs r5, #0
_0817C15A:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817C174
	adds r4, #1
	adds r5, #1
	cmp r5, #2
	blt _0817C15A
_0817C174:
	subs r5, r4, #1
	b _0817C230
_0817C178:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	movs r5, #0
_0817C186:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817C210
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #2
	blt _0817C186
	ldr r2, _0817C1B0 @ =0x030046A4
	b _0817C212
	.align 2, 0
_0817C1B0: .4byte 0x030046A4
_0817C1B4:
	subs r4, r6, #1
	movs r5, #0
_0817C1B8:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817C1D2
	subs r4, #1
	adds r5, #1
	cmp r5, #2
	blt _0817C1B8
_0817C1D2:
	adds r5, r4, #1
	b _0817C230
_0817C1D6:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r6, r0
	movs r5, #0
_0817C1E4:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817C21E
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #2
	blt _0817C1E4
	ldr r2, _0817C20C @ =0x030046A4
	b _0817C220
	.align 2, 0
_0817C20C: .4byte 0x030046A4
_0817C210:
	mov r2, sl
_0817C212:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _0817C230
_0817C21E:
	mov r2, sl
_0817C220:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r4, r0
	b _0817C230
_0817C22C:
	ldr r2, [sp, #0x10]
	ldrh r5, [r2]
_0817C230:
	ldr r0, [sp, #0x10]
	ldrh r0, [r0]
	cmp r5, r0
	bne _0817C24C
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x40
	strb r0, [r1, #5]
	ldr r2, [sp, #0xc]
	adds r2, #1
	str r2, [sp, #0xc]
	cmp r2, #3
	bgt _0817C24C
	b _0817C0BA
_0817C24C:
	mov r0, sp
	ldrb r1, [r0, #8]
	mov r0, sb
	strb r1, [r0, #5]
	mov r8, sp
	ldr r6, _0817C290 @ =0x030046A4
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
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817C294
	adds r0, #4
	b _0817C29E
	.align 2, 0
_0817C290: .4byte 0x030046A4
_0817C294:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817C29E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r0, _0817C2E4 @ =0x000004A4
	add r0, sb
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	beq _0817C2E8
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0817C2E8
	cmp r0, #2
	beq _0817C2E0
	mov r0, sb
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0817C2E0:
	movs r0, #1
	b _0817C2F8
	.align 2, 0
_0817C2E4: .4byte 0x000004A4
_0817C2E8:
	movs r0, #0xc0
	lsls r0, r0, #1
	add r0, sb
	ldr r1, _0817C300 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0817C2F8:
	cmp r0, #0
	beq _0817C304
	movs r0, #1
	b _0817C312
	.align 2, 0
_0817C300: .4byte 0xFFFFFDFF
_0817C304:
	ldr r0, _0817C324 @ =0x000005C4
	add r0, sb
	ldr r1, [r0]
	mov r0, sb
	bl _call_via_r1
	movs r0, #0
_0817C312:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0817C324: .4byte 0x000005C4

	thumb_func_start FUN_0817c328
FUN_0817c328: @ 0x0817C328
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0xea
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	cmp r0, #0
	ble _0817C428
	adds r0, r5, #0
	bl FUN_080f00ec
	ldr r1, _0817C3A4 @ =0x00000222
	adds r2, r5, r1
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r4]
	bl FUN_080f8d60
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	ldrh r1, [r0, #8]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0817C39E
	cmp r1, #0
	blt _0817C39E
	ldr r0, _0817C3A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0817C39E
	ldr r0, _0817C3AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817C3B0
_0817C39E:
	movs r1, #0
	b _0817C3BE
	.align 2, 0
_0817C3A4: .4byte 0x00000222
_0817C3A8: .4byte 0x030046A8
_0817C3AC: .4byte 0x030046AC
_0817C3B0:
	ldr r0, _0817C41C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0817C3BE:
	ldr r3, _0817C420 @ =0x0000025E
	adds r0, r5, r3
	strh r1, [r0]
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r5, #8]
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
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	strb r0, [r5, #5]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _0817C424 @ =0x00000898
	adds r1, r1, r2
	movs r2, #0x31
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r0, #1
	b _0817C440
	.align 2, 0
_0817C41C: .4byte 0x030046A4
_0817C420: .4byte 0x0000025E
_0817C424: .4byte 0x00000898
_0817C428:
	movs r0, #8
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r3, [r1]
	ands r0, r3
	cmp r0, #0
	beq _0817C43E
	ldr r0, _0817C448 @ =0xF7FFFFFF
	ands r3, r0
	str r3, [r1]
_0817C43E:
	movs r0, #0
_0817C440:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0817C448: .4byte 0xF7FFFFFF

	thumb_func_start FUN_0817c44c
FUN_0817c44c: @ 0x0817C44C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0817C550
	bl VM_GetPC
	cmp r0, #0
	beq _0817C478
	bl Script_GetValue
	b _0817C47A
_0817C478:
	movs r0, #0
_0817C47A:
	strh r0, [r6, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _0817C48A
	bl Script_GetValue
	b _0817C48C
_0817C48A:
	movs r0, #0
_0817C48C:
	strh r0, [r6, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _0817C49C
	bl Script_GetValue
	b _0817C49E
_0817C49C:
	movs r0, #0
_0817C49E:
	strh r0, [r6, #0xc]
	adds r0, r6, #0
	adds r0, #8
	ldrh r1, [r6, #8]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r3, r0, #0
	cmp r2, #0
	blt _0817C4CA
	cmp r1, #0
	blt _0817C4CA
	ldr r0, _0817C4D0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0817C4CA
	ldr r0, _0817C4D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817C4D8
_0817C4CA:
	movs r1, #0
	b _0817C4E6
	.align 2, 0
_0817C4D0: .4byte 0x030046A8
_0817C4D4: .4byte 0x030046AC
_0817C4D8:
	ldr r0, _0817C500 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0817C4E6:
	ldr r2, _0817C504 @ =0x00000256
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r4, [r0]
	adds r5, r3, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817C508
	adds r0, #4
	b _0817C514
	.align 2, 0
_0817C500: .4byte 0x030046A4
_0817C504: .4byte 0x00000256
_0817C508:
	ldr r0, _0817C528 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817C514:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0817C52C
	cmp r3, #2
	beq _0817C530
	b _0817C534
	.align 2, 0
_0817C528: .4byte 0x030046A4
_0817C52C:
	ldrb r0, [r5, #4]
	b _0817C532
_0817C530:
	ldrb r0, [r5]
_0817C532:
	subs r2, r2, r0
_0817C534:
	ldr r3, _0817C54C @ =0x00000472
	adds r0, r6, r3
	strh r2, [r0]
	ldrh r1, [r6, #0xa]
	subs r1, r1, r2
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r2, r6, r4
	strh r1, [r2]
	ldrh r0, [r0]
	strh r0, [r6, #0xa]
	b _0817C586
	.align 2, 0
_0817C54C: .4byte 0x00000472
_0817C550:
	adds r1, r6, #0
	adds r1, #0x9c
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r2, [r0]
	ldr r3, _0817C5AC @ =0x00000251
	adds r0, r6, r3
	ldrb r3, [r0]
	ldr r4, _0817C5B0 @ =0x00000252
	adds r0, r6, r4
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r6, #0
	bl FUN_0823b490
	adds r0, r6, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	lsrs r0, r0, #0xc
	movs r1, #7
	ands r0, r1
	adds r0, #5
	ands r0, r1
	lsls r0, r0, #5
	strb r0, [r6, #5]
_0817C586:
	movs r0, #0x50
	bl prepare_08231510
	ldr r7, _0817C5B4 @ =0x00000898
	add r7, r8
	cmp r0, #0
	beq _0817C5C6
	movs r4, #0
_0817C596:
	lsls r0, r4, #1
	ldr r1, _0817C5B8 @ =0x00000888
	add r1, r8
	adds r5, r1, r0
	bl VM_GetPC
	cmp r0, #0
	beq _0817C5BC
	bl Script_GetValue
	b _0817C5BE
	.align 2, 0
_0817C5AC: .4byte 0x00000251
_0817C5B0: .4byte 0x00000252
_0817C5B4: .4byte 0x00000898
_0817C5B8: .4byte 0x00000888
_0817C5BC:
	movs r0, #0
_0817C5BE:
	strh r0, [r5]
	adds r4, #1
	cmp r4, #5
	ble _0817C596
_0817C5C6:
	movs r1, #1
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
	adds r0, r6, #0
	bl FUN_0817e870
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start cheye_0817c5e0
cheye_0817c5e0: @ 0x0817C5E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x84
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r4, [r0]
	ldr r1, _0817C680 @ =0x08252198
	ldr r2, _0817C684 @ =0x0000017F
	adds r0, r7, #0
	bl FUN_080e6768
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r3, #0x8a
	lsls r3, r3, #4
	adds r1, r4, r3
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0817C6A4
	ldrb r1, [r7, #5]
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r0, r7, r4
	ldrb r0, [r0]
	adds r0, #0x80
	movs r4, #0
	strb r0, [r7, #5]
	adds r0, r7, #0
	bl FUN_0817c094
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817C632
	b _0817CD94
_0817C632:
	ldr r2, _0817C688 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r5, _0817C68C @ =0x0000046D
	adds r0, r7, r5
	movs r3, #1
	strb r3, [r0]
	ldr r6, _0817C690 @ =0x0000046B
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
	movs r1, #0
	strh r4, [r0]
	movs r2, #0xf
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _0817C694 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0817C698 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _0817C69C @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	ldr r4, _0817C6A0 @ =0x0000046C
	adds r0, r7, r4
	strb r3, [r0]
	b _0817CD94
	.align 2, 0
_0817C680: .4byte 0x08252198
_0817C684: .4byte 0x0000017F
_0817C688: .4byte FUN_080e48d0
_0817C68C: .4byte 0x0000046D
_0817C690: .4byte 0x0000046B
_0817C694: .4byte 0x00000469
_0817C698: .4byte 0x0000046A
_0817C69C: .4byte 0x00000484
_0817C6A0: .4byte 0x0000046C
_0817C6A4:
	ldr r5, _0817C6F0 @ =0x000008A4
	adds r0, r4, r5
	ldr r0, [r0]
	cmp r2, r0
	bhi _0817C6B0
	b _0817CD48
_0817C6B0:
	movs r6, #0x95
	lsls r6, r6, #3
	adds r3, r7, r6
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x54]
	str r2, [sp, #0x5c]
	cmp r4, #0
	blt _0817C6EC
	cmp r1, #0
	blt _0817C6EC
	ldr r0, _0817C6F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0817C6EC
	ldr r0, _0817C6F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817C6FC
_0817C6EC:
	movs r4, #0
	b _0817C70A
	.align 2, 0
_0817C6F0: .4byte 0x000008A4
_0817C6F4: .4byte 0x030046A8
_0817C6F8: .4byte 0x030046AC
_0817C6FC:
	ldr r0, _0817C71C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0817C70A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817C720
	adds r0, #4
	b _0817C72C
	.align 2, 0
_0817C71C: .4byte 0x030046A4
_0817C720:
	ldr r0, _0817C740 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817C72C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0817C744
	cmp r2, #2
	beq _0817C748
	b _0817C74C
	.align 2, 0
_0817C740: .4byte 0x030046A4
_0817C744:
	ldrb r0, [r5, #4]
	b _0817C74A
_0817C748:
	ldrb r0, [r5]
_0817C74A:
	subs r1, r1, r0
_0817C74C:
	strh r1, [r5, #2]
	ldr r0, _0817C760 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0817C764
	movs r0, #1
	b _0817C766
	.align 2, 0
_0817C760: .4byte 0x030047A4
_0817C764:
	movs r0, #0
_0817C766:
	cmp r0, #0
	beq _0817C7A4
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0817C786
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0817C782
	adds r2, r0, #0
_0817C782:
	cmp r2, #0
	bge _0817C790
_0817C786:
	ldr r2, _0817C78C @ =0x000005C4
	adds r0, r7, r2
	b _0817CCC4
	.align 2, 0
_0817C78C: .4byte 0x000005C4
_0817C790:
	ldr r1, _0817C7A0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0817C7EC
	.align 2, 0
_0817C7A0: .4byte 0x03002BE0
_0817C7A4:
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
	blt _0817C7D0
	cmp r1, #0
	blt _0817C7D0
	ldr r0, _0817C7D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0817C7D0
	ldr r0, _0817C7D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817C7DC
_0817C7D0:
	movs r5, #0
	b _0817C7EA
	.align 2, 0
_0817C7D4: .4byte 0x030046A8
_0817C7D8: .4byte 0x030046AC
_0817C7DC:
	ldr r0, _0817C82C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0817C7EA:
	movs r2, #0
_0817C7EC:
	ldr r4, _0817C830 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0817C80C
	ldr r1, _0817C834 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0817C80C
	b _0817CC08
_0817C80C:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	str r2, [sp, #0x3c]
	cmp r1, #0
	beq _0817C838
	movs r0, #0
	b _0817CCDA
	.align 2, 0
_0817C82C: .4byte 0x030046A4
_0817C830: .4byte 0x00000256
_0817C834: .4byte 0x03002BE0
_0817C838:
	ldr r6, _0817C8D8 @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x3c]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0x60]
	cmp r6, #0
	beq _0817C8EC
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _0817C8DC @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #8]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _0817C8E0 @ =0x0000046B
	adds r2, r2, r7
	mov r8, r2
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0xc]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sb
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _0817C8E4 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0817C8E8 @ =0x00000484
	adds r1, r7, r6
	mov r0, sb
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #8]
	str r6, [sp, #0x48]
	mov r6, r8
	str r6, [sp, #0x40]
	ldr r6, [sp, #0xc]
	str r6, [sp, #0x78]
	mov r6, sl
	str r6, [sp, #0x7c]
	str r5, [sp, #0x58]
	str r4, [sp, #0x30]
	str r3, [sp, #0x34]
	str r2, [sp, #0x38]
	str r1, [sp, #0x50]
	str r0, [sp, #0x44]
	b _0817CABE
	.align 2, 0
_0817C8D8: .4byte 0x00000222
_0817C8DC: .4byte 0x0000046D
_0817C8E0: .4byte 0x0000046B
_0817C8E4: .4byte 0x00000469
_0817C8E8: .4byte 0x00000484
_0817C8EC:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0817C9B0 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x10]
	strb r0, [r2]
	ldr r3, _0817C9B4 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x14]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0817C9B8 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x18]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x1c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x20]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x24]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _0817C9BC @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _0817C9C0 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _0817C9C4 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x54]
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldr r1, [sp, #0x5c]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x28]
	strh r1, [r6]
	ldr r6, [sp, #0x5c]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x28]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x48]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x40]
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x78]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x7c]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x58]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x30]
	str r5, [sp, #0x34]
	str r4, [sp, #0x38]
	str r3, [sp, #0x50]
	str r2, [sp, #0x44]
	mov r0, ip
	cmp r0, #0
	blt _0817C9AA
	cmp r1, #0
	blt _0817C9AA
	ldr r0, _0817C9C8 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _0817C9AA
	ldr r0, _0817C9CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817C9D0
_0817C9AA:
	movs r4, #0
	b _0817C9E0
	.align 2, 0
_0817C9B0: .4byte 0x0000046D
_0817C9B4: .4byte 0x0000046B
_0817C9B8: .4byte 0x00000553
_0817C9BC: .4byte 0x00000469
_0817C9C0: .4byte 0x00000484
_0817C9C4: .4byte 0x0000046C
_0817C9C8: .4byte 0x030046A8
_0817C9CC: .4byte 0x030046AC
_0817C9D0:
	ldr r0, _0817C9F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_0817C9E0:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817C9F4
	adds r0, #4
	b _0817CA00
	.align 2, 0
_0817C9F0: .4byte 0x030046A4
_0817C9F4:
	ldr r0, _0817CA14 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817CA00:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0817CA18
	cmp r2, #2
	beq _0817CA1E
	b _0817CA24
	.align 2, 0
_0817CA14: .4byte 0x030046A4
_0817CA18:
	ldr r2, [sp, #0x28]
	ldrb r0, [r2, #4]
	b _0817CA22
_0817CA1E:
	ldr r3, [sp, #0x28]
	ldrb r0, [r3]
_0817CA22:
	subs r1, r1, r0
_0817CA24:
	ldr r4, [sp, #0x28]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x54]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0817CA50
	cmp r1, #0
	blt _0817CA50
	ldr r0, _0817CA54 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0817CA50
	ldr r0, _0817CA58 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817CA5C
_0817CA50:
	movs r4, #0
	b _0817CA6A
	.align 2, 0
_0817CA54: .4byte 0x030046A8
_0817CA58: .4byte 0x030046AC
_0817CA5C:
	ldr r0, _0817CA80 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0817CA6A:
	ldr r6, [sp, #0x54]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817CA84
	adds r0, #4
	b _0817CA90
	.align 2, 0
_0817CA80: .4byte 0x030046A4
_0817CA84:
	ldr r0, _0817CAA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817CA90:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0817CAA8
	cmp r3, #2
	beq _0817CAAC
	b _0817CAB0
	.align 2, 0
_0817CAA4: .4byte 0x030046A4
_0817CAA8:
	ldrb r0, [r5, #4]
	b _0817CAAE
_0817CAAC:
	ldrb r0, [r5]
_0817CAAE:
	subs r2, r2, r0
_0817CAB0:
	ldr r1, [sp, #0x54]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x54]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0817CABE:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x2c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x3c]
	ldrh r0, [r4]
	ands r0, r1
	mov r8, r3
	ldr r5, _0817CAE8 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x4c]
	cmp r0, #0
	bne _0817CBCC
	movs r1, #4
	ldr r6, [sp, #0x60]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0817CAEC
	movs r0, #1
	b _0817CAEE
	.align 2, 0
_0817CAE8: .4byte 0x00000482
_0817CAEC:
	movs r0, #0
_0817CAEE:
	ldr r1, _0817CBDC @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x4c]
	cmp r0, #0
	bne _0817CBCC
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0xa9
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sl, r4
	ldr r5, _0817CBE0 @ =0x0000054F
	adds r5, r5, r7
	mov ip, r5
	ldr r6, _0817CBE4 @ =0x0000054C
	adds r6, r7, r6
	str r6, [sp, #0x6c]
	ldr r0, _0817CBE8 @ =0x0000054D
	adds r0, r7, r0
	str r0, [sp, #0x70]
	ldr r1, _0817CBEC @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x74]
	ldr r2, _0817CBF0 @ =0x00000541
	adds r2, r7, r2
	str r2, [sp, #0x64]
	ldr r4, _0817CBF4 @ =0x000005BC
	adds r4, r7, r4
	str r4, [sp, #0x80]
	ldr r5, _0817CBF8 @ =0x00000542
	adds r5, r7, r5
	str r5, [sp, #0x68]
	ldr r6, _0817CBFC @ =0x0203B400
	ldr r1, _0817CC00 @ =0x030046B8
	ldr r5, _0817CC04 @ =0x000003FF
	movs r4, #3
	mov r2, r8
_0817CB3E:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r4
	lsls r0, r0, #6
	cmp r0, r2
	bne _0817CB5C
	adds r3, #1
	cmp r3, #3
	ble _0817CB3E
	mov r0, r8
_0817CB5C:
	movs r3, #0
	mov r6, sb
	strb r0, [r6]
	ldr r1, [sp, #0x7c]
	ldr r0, [r1]
	mov r2, sl
	str r0, [r2]
	ldr r4, [sp, #0x78]
	ldrb r0, [r4]
	mov r5, ip
	strb r0, [r5]
	ldr r6, [sp, #0x30]
	ldrb r0, [r6]
	ldr r1, [sp, #0x6c]
	strb r0, [r1]
	ldr r2, [sp, #0x34]
	ldrb r0, [r2]
	ldr r4, [sp, #0x70]
	strb r0, [r4]
	ldr r5, [sp, #0x38]
	ldrb r0, [r5]
	ldr r6, [sp, #0x74]
	strb r0, [r6]
	add r0, sp, #0x2c
	ldrb r1, [r0]
	ldr r0, [sp, #0x64]
	strb r1, [r0]
	ldr r1, [sp, #0x80]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x48]
	strb r1, [r4]
	ldr r5, [sp, #0x40]
	strb r3, [r5]
	ldr r6, [sp, #0x78]
	strb r0, [r6]
	ldr r0, [sp, #0x7c]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x58]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x30]
	strb r0, [r5]
	ldr r6, [sp, #0x34]
	strb r1, [r6]
	ldr r0, [sp, #0x38]
	strb r2, [r0]
	ldr r2, [sp, #0x50]
	str r3, [r2]
	ldr r3, [sp, #0x44]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x68]
	strb r0, [r4]
_0817CBCC:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x4c]
	strh r0, [r5]
	movs r0, #0
	b _0817CCDA
	.align 2, 0
_0817CBDC: .4byte 0x00000482
_0817CBE0: .4byte 0x0000054F
_0817CBE4: .4byte 0x0000054C
_0817CBE8: .4byte 0x0000054D
_0817CBEC: .4byte 0x0000054E
_0817CBF0: .4byte 0x00000541
_0817CBF4: .4byte 0x000005BC
_0817CBF8: .4byte 0x00000542
_0817CBFC: .4byte 0x0203B400
_0817CC00: .4byte 0x030046B8
_0817CC04: .4byte 0x000003FF
_0817CC08:
	mov sb, sp
	ldr r6, _0817CC44 @ =0x030046A4
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
	beq _0817CC48
	adds r0, #4
	b _0817CC52
	.align 2, 0
_0817CC44: .4byte 0x030046A4
_0817CC48:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817CC52:
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
	ldr r6, _0817CC88 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _0817CC8C
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _0817CCB2
	.align 2, 0
_0817CC88: .4byte 0x000004A4
_0817CC8C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0817CCAC
	cmp r0, #2
	beq _0817CCA8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0817CCA8:
	movs r0, #1
	b _0817CCBC
_0817CCAC:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_0817CCB2:
	ldr r1, _0817CCD0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0817CCBC:
	cmp r0, #0
	bne _0817CCD8
	ldr r3, _0817CCD4 @ =0x000005C4
	adds r0, r7, r3
_0817CCC4:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0817CCDA
	.align 2, 0
_0817CCD0: .4byte 0xFFFFFDFF
_0817CCD4: .4byte 0x000005C4
_0817CCD8:
	movs r0, #1
_0817CCDA:
	cmp r0, #0
	beq _0817CD94
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r5, _0817CD34 @ =0x0000046D
	adds r0, r7, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0817CD38 @ =0x0000046B
	adds r0, r7, r6
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _0817CD3C @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0817CD40 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _0817CD44 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _0817CD94
	.align 2, 0
_0817CD34: .4byte 0x0000046D
_0817CD38: .4byte 0x0000046B
_0817CD3C: .4byte 0x00000469
_0817CD40: .4byte 0x0000046A
_0817CD44: .4byte 0x00000484
_0817CD48:
	movs r2, #3
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r7, r6
	movs r3, #0
	strb r2, [r0]
	ldr r2, _0817CDA4 @ =0x00000469
	adds r0, r7, r2
	strb r1, [r0]
	ldr r4, _0817CDA8 @ =0x0000046A
	adds r0, r7, r4
	strb r3, [r0]
	ldr r5, _0817CDAC @ =0x00000484
	adds r0, r7, r5
	str r3, [r0]
	adds r6, #4
	adds r0, r7, r6
	strb r1, [r0]
	ldr r4, _0817CDB0 @ =FUN_0818069c
	movs r2, #0x27
	subs r5, #0x17
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #1
	adds r0, r7, r6
	strb r3, [r0]
	ldr r1, _0817CDB4 @ =0x00000553
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r3, [r0]
_0817CD94:
	add sp, #0x84
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817CDA4: .4byte 0x00000469
_0817CDA8: .4byte 0x0000046A
_0817CDAC: .4byte 0x00000484
_0817CDB0: .4byte FUN_0818069c
_0817CDB4: .4byte 0x00000553

	thumb_func_start FUN_0817cdb8
FUN_0817cdb8: @ 0x0817CDB8
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x9c
	ldr r2, _0817CE0C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0817CE10 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0817CE14 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldrb r0, [r4, #2]
	cmp r1, r0
	bne _0817CDF2
	adds r0, r1, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_0817CDF2:
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
_0817CE0C: .4byte 0x030046B8
_0817CE10: .4byte 0x000003FF
_0817CE14: .4byte 0x0203B400

	thumb_func_start FUN_0817ce18
FUN_0817ce18: @ 0x0817CE18
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	cmp r1, #4
	ble _0817CE3C
	movs r0, #8
	subs r0, r0, r1
	str r0, [r3]
	movs r0, #1
	b _0817CE40
_0817CE3C:
	str r1, [r3]
	movs r0, #0
_0817CE40:
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0817ce48
FUN_0817ce48: @ 0x0817CE48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0xc]
	ldrb r0, [r7, #5]
	adds r0, #0x20
	movs r5, #0xff
	ands r0, r5
	asrs r0, r0, #6
	lsls r0, r0, #6
	str r0, [sp, #0x14]
	add r4, sp, #4
	adds r3, r7, #0
	adds r3, #8
	ldr r2, _0817CEF4 @ =0x000004A4
	adds r0, r7, r2
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r3, #0
	ldrsh r0, [r4, r3]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl FUN_0823785c
	adds r0, #0x20
	ands r0, r5
	asrs r0, r0, #6
	lsls r1, r0, #6
	strb r1, [r7, #5]
	adds r0, #1
	str r0, [sp, #0x18]
	movs r0, #3
	ldr r3, [sp, #0x18]
	ands r3, r0
	str r3, [sp, #0x18]
	movs r1, #0
	mov r0, sp
	adds r0, #3
_0817CEBE:
	strb r1, [r0]
	subs r0, #1
	cmp r0, sp
	bge _0817CEBE
	movs r5, #0
	str r5, [sp, #0x10]
	adds r0, r7, #0
	adds r0, #8
	str r0, [sp, #0x1c]
	ldr r1, _0817CEF8 @ =0x00000256
	adds r1, r7, r1
	str r1, [sp, #0x20]
_0817CED6:
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r3, _0817CEFC @ =0x00000898
	adds r0, r0, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817CF00
	movs r0, #1
	b _0817CF02
	.align 2, 0
_0817CEF4: .4byte 0x000004A4
_0817CEF8: .4byte 0x00000256
_0817CEFC: .4byte 0x00000898
_0817CF00:
	movs r0, #0
_0817CF02:
	cmp r0, #0
	beq _0817CF28
	adds r0, r7, #0
	ldr r5, [sp, #0xc]
	ldr r2, _0817CF24 @ =0x00000854
	adds r1, r5, r2
	bl FUN_0817eb28
	lsls r0, r0, #0x18
	movs r3, #2
	mov sl, r3
	cmp r0, #0
	beq _0817CF2C
	movs r5, #1
	mov sl, r5
	b _0817CF2C
	.align 2, 0
_0817CF24: .4byte 0x00000854
_0817CF28:
	movs r0, #2
	mov sl, r0
_0817CF2C:
	ldr r1, [sp, #0x20]
	ldrh r6, [r1]
	ldr r4, [sp, #0x1c]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817CF42
	adds r0, #4
	b _0817CF4E
_0817CF42:
	ldr r2, _0817CF64 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817CF4E:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0817CF68
	cmp r3, #2
	beq _0817CF6C
	b _0817CF70
	.align 2, 0
_0817CF64: .4byte 0x030046A4
_0817CF68:
	ldrb r0, [r4, #4]
	b _0817CF6E
_0817CF6C:
	ldrb r0, [r4]
_0817CF6E:
	subs r2, r2, r0
_0817CF70:
	mov sb, r2
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817CF82
	adds r0, #4
	b _0817CF8E
_0817CF82:
	ldr r3, _0817CFA0 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817CF8E:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov r8, r0
	ldrb r0, [r7, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0817CFA4
	asrs r0, r0, #6
	b _0817CFAA
	.align 2, 0
_0817CFA0: .4byte 0x030046A4
_0817CFA4:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0817CFAA:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0817CFEA
	cmp r1, #1
	bgt _0817CFBC
	cmp r1, #0
	beq _0817CFC6
	b _0817D0C4
_0817CFBC:
	cmp r1, #2
	beq _0817D034
	cmp r1, #3
	beq _0817D058
	b _0817D0C4
_0817CFC6:
	adds r4, r6, #1
	movs r5, #0
	cmp r5, sl
	bge _0817D094
_0817CFCE:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D094
	adds r4, #1
	adds r5, #1
	cmp r5, sl
	blt _0817CFCE
	b _0817D094
_0817CFEA:
	ldr r5, _0817D030 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	movs r5, #0
	cmp r5, sl
	bge _0817D020
_0817CFFC:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D098
	ldr r2, _0817D030 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, sl
	blt _0817CFFC
_0817D020:
	ldr r5, _0817D030 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _0817D0C8
	.align 2, 0
_0817D030: .4byte 0x030046A4
_0817D034:
	subs r4, r6, #1
	movs r5, #0
	cmp r5, sl
	bge _0817D0AC
_0817D03C:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D0AC
	subs r4, #1
	adds r5, #1
	cmp r5, sl
	blt _0817D03C
	b _0817D0AC
_0817D058:
	ldr r2, _0817D090 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r4, r6, r0
	movs r5, #0
	cmp r5, sl
	bge _0817D0B0
_0817D06A:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D0B0
	ldr r1, _0817D090 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, sl
	blt _0817D06A
	b _0817D0B0
	.align 2, 0
_0817D090: .4byte 0x030046A4
_0817D094:
	subs r5, r4, #1
	b _0817D0C8
_0817D098:
	ldr r1, _0817D0A8 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r4, r0
	b _0817D0C8
	.align 2, 0
_0817D0A8: .4byte 0x030046A4
_0817D0AC:
	adds r5, r4, #1
	b _0817D0C8
_0817D0B0:
	ldr r3, _0817D0C0 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r5, r4, r0
	b _0817D0C8
	.align 2, 0
_0817D0C0: .4byte 0x030046A4
_0817D0C4:
	ldr r0, [sp, #0x20]
	ldrh r5, [r0]
_0817D0C8:
	ldr r1, _0817D110 @ =0x00000256
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r5, r0
	beq _0817D19C
	add r2, sp, #4
	mov sb, r2
	ldr r6, _0817D114 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #4
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817D118
	adds r0, #4
	b _0817D122
	.align 2, 0
_0817D110: .4byte 0x00000256
_0817D114: .4byte 0x030046A4
_0817D118:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817D122:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r1, _0817D154 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	add r2, sp, #4
	bl FUN_0823599c
	cmp r0, #0
	bne _0817D158
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	b _0817D17C
	.align 2, 0
_0817D154: .4byte 0x000004A4
_0817D158:
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	add r2, sp, #4
	bl FUN_08235f40
	cmp r0, #0
	beq _0817D176
	cmp r0, #2
	beq _0817D184
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _0817D184
_0817D176:
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
_0817D17C:
	ldrh r1, [r2]
	ldr r0, _0817D194 @ =0xFFFFFDFF
	ands r0, r1
	strh r0, [r2]
_0817D184:
	ldr r1, _0817D198 @ =0x000004A4
	adds r0, r7, r1
	ldr r2, [r0]
	ldr r0, [r2, #0xc]
	ldr r1, [r2, #0x10]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _0817D1F4
	.align 2, 0
_0817D194: .4byte 0xFFFFFDFF
_0817D198: .4byte 0x000004A4
_0817D19C:
	ldrb r0, [r7, #5]
	lsrs r0, r0, #6
	mov r2, sp
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0x10]
	cmp r3, #0
	bne _0817D1C6
	ldr r5, [sp, #0x14]
	cmp r0, r5
	beq _0817D1C6
	strb r5, [r7, #5]
	b _0817D1E8
_0817D1BA:
	movs r1, #0x40
	lsls r1, r2
	movs r0, #0x40
	subs r0, r0, r1
	strb r0, [r7, #5]
	b _0817D1E2
_0817D1C6:
	adds r4, r0, #0
	movs r1, #0
	movs r3, #3
_0817D1CC:
	ldr r0, [sp, #0x18]
	adds r2, r0, r1
	ands r2, r3
	mov r5, sp
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _0817D1BA
	adds r1, #1
	cmp r1, #3
	ble _0817D1CC
_0817D1E2:
	ldrb r0, [r7, #5]
	cmp r4, r0
	beq _0817D1F4
_0817D1E8:
	ldr r1, [sp, #0x10]
	adds r1, #1
	str r1, [sp, #0x10]
	cmp r1, #3
	bgt _0817D1F4
	b _0817CED6
_0817D1F4:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0817d204
FUN_0817d204: @ 0x0817D204
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r4, r1, #0
	mov r8, r2
	mov sl, r3
	ldr r5, [sp, #0x28]
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sb
	ldr r6, [r0]
	ldrh r0, [r4, #0x1c]
	mov r2, sb
	ldrh r1, [r2, #8]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrh r0, [r4, #0x20]
	mov r3, sb
	ldrh r1, [r3, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	movs r7, #0xc
	ldrsh r1, [r4, r7]
	movs r7, #8
	ldrsh r0, [r3, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _0817D24C
	rsbs r1, r1, #0
_0817D24C:
	cmp r1, r8
	bhi _0817D268
	movs r0, #0x10
	ldrsh r1, [r4, r0]
	mov r3, sb
	movs r4, #0xc
	ldrsh r0, [r3, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _0817D262
	rsbs r1, r1, #0
_0817D262:
	cmp r1, sl
	bhi _0817D268
	b _0817D6B6
_0817D268:
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	mov r7, ip
	lsls r0, r7, #0x10
	cmp r2, #0
	bne _0817D27A
	cmp r0, #0
	bne _0817D27A
	b _0817D6C0
_0817D27A:
	asrs r1, r0, #0x10
	adds r0, r2, #0
	bl FUN_0823785c
	mov r1, sb
	strb r0, [r1, #5]
	ldr r2, _0817D2A4 @ =0x085B0A08
	ldrb r0, [r1, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0817D2A8
	asrs r0, r0, #0x10
	b _0817D2AE
	.align 2, 0
_0817D2A4: .4byte 0x085B0A08
_0817D2A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_0817D2AE:
	adds r3, r0, #0
	ldr r1, _0817D2CC @ =0x085B0A08
	mov r4, sb
	ldrb r2, [r4, #5]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r5, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _0817D2D0
	asrs r0, r0, #0x10
	b _0817D2D6
	.align 2, 0
_0817D2CC: .4byte 0x085B0A08
_0817D2D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_0817D2D6:
	mov r2, sb
	movs r4, #0x10
	ldrsh r1, [r2, r4]
	adds r2, r3, #0
	cmp r3, #0
	bge _0817D2E4
	rsbs r2, r3, #0
_0817D2E4:
	cmp r2, #0xa
	ble _0817D2EA
	adds r1, r1, r3
_0817D2EA:
	mov r7, sb
	strh r1, [r7, #0x10]
	movs r2, #0x14
	ldrsh r1, [r7, r2]
	adds r2, r0, #0
	cmp r0, #0
	bge _0817D2FA
	rsbs r2, r0, #0
_0817D2FA:
	cmp r2, #0xa
	ble _0817D300
	adds r1, r1, r0
_0817D300:
	mov r3, sb
	strh r1, [r3, #0x14]
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r4, _0817D318 @ =0x00000898
	adds r0, r6, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817D31C
	movs r0, #1
	b _0817D31E
	.align 2, 0
_0817D318: .4byte 0x00000898
_0817D31C:
	movs r0, #0
_0817D31E:
	cmp r0, #0
	bne _0817D324
	b _0817D6C0
_0817D324:
	mov r4, sp
	mov r3, sb
	adds r3, #8
	ldr r7, _0817D368 @ =0x00000854
	adds r2, r6, r7
	ldrh r0, [r2]
	mov r6, sb
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r5, #0
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r5, r3, #0
	cmp r0, #1
	bne _0817D35C
	b _0817D4FC
_0817D35C:
	cmp r0, #1
	bgt _0817D36C
	cmp r0, #0
	beq _0817D378
	b _0817D6C0
	.align 2, 0
_0817D368: .4byte 0x00000854
_0817D36C:
	cmp r0, #2
	beq _0817D378
	cmp r0, #3
	bne _0817D376
	b _0817D4FC
_0817D376:
	b _0817D6C0
_0817D378:
	mov r0, sp
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0
	bge _0817D384
	rsbs r0, r0, #0
_0817D384:
	cmp r0, r8
	blo _0817D38A
	b _0817D6C0
_0817D38A:
	mov r0, sb
	ldrb r0, [r0, #5]
	mov sl, r0
	mov r0, sp
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r0, #0
	bl FUN_0823785c
	mov r3, sb
	strb r0, [r3, #5]
	ldr r4, _0817D3B8 @ =0x00000256
	add r4, sb
	ldrh r6, [r4]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817D3BC
	adds r0, #4
	b _0817D3C8
	.align 2, 0
_0817D3B8: .4byte 0x00000256
_0817D3BC:
	ldr r0, _0817D3DC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817D3C8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0817D3E0
	cmp r3, #2
	beq _0817D3E4
	b _0817D3E8
	.align 2, 0
_0817D3DC: .4byte 0x030046A4
_0817D3E0:
	ldrb r0, [r5, #4]
	b _0817D3E6
_0817D3E4:
	ldrb r0, [r5]
_0817D3E6:
	subs r2, r2, r0
_0817D3E8:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817D3FA
	adds r0, #4
	b _0817D406
_0817D3FA:
	ldr r0, _0817D418 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817D406:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0817D41C
	asrs r0, r0, #6
	b _0817D422
	.align 2, 0
_0817D418: .4byte 0x030046A4
_0817D41C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0817D422:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0817D460
	cmp r1, #1
	bgt _0817D434
	cmp r1, #0
	beq _0817D43E
	b _0817D6A4
_0817D434:
	cmp r1, #2
	beq _0817D49C
	cmp r1, #3
	beq _0817D4BE
	b _0817D6A4
_0817D43E:
	adds r4, r6, #1
	movs r5, #0
_0817D442:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817D456
	b _0817D5E0
_0817D456:
	adds r4, #1
	adds r5, #1
	cmp r5, #1
	blt _0817D442
	b _0817D5E0
_0817D460:
	ldr r0, _0817D498 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	movs r5, #0
_0817D46E:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817D482
	b _0817D67C
_0817D482:
	ldr r0, _0817D498 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r4, r4, r1
	adds r5, #1
	cmp r5, #1
	blt _0817D46E
	subs r1, r4, r1
	b _0817D6A6
	.align 2, 0
_0817D498: .4byte 0x030046A4
_0817D49C:
	subs r4, r6, #1
	movs r5, #0
_0817D4A0:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817D4B4
	b _0817D63E
_0817D4B4:
	subs r4, #1
	adds r5, #1
	cmp r5, #1
	blt _0817D4A0
	b _0817D63E
_0817D4BE:
	ldr r0, _0817D4F8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r4, r6, r0
	movs r5, #0
_0817D4CC:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817D4E0
	b _0817D690
_0817D4E0:
	ldr r0, _0817D4F8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	subs r4, r4, r1
	adds r5, #1
	cmp r5, #1
	blt _0817D4CC
	adds r1, r4, r1
	b _0817D6A6
	.align 2, 0
_0817D4F8: .4byte 0x030046A4
_0817D4FC:
	mov r0, sp
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _0817D508
	rsbs r0, r0, #0
_0817D508:
	cmp r0, sl
	blo _0817D50E
	b _0817D6C0
_0817D50E:
	mov r2, sb
	ldrb r2, [r2, #5]
	mov sl, r2
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0
	bl FUN_0823785c
	mov r4, sb
	strb r0, [r4, #5]
	ldr r4, _0817D53C @ =0x00000256
	add r4, sb
	ldrh r6, [r4]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817D540
	adds r0, #4
	b _0817D54C
	.align 2, 0
_0817D53C: .4byte 0x00000256
_0817D540:
	ldr r0, _0817D560 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817D54C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0817D564
	cmp r3, #2
	beq _0817D568
	b _0817D56C
	.align 2, 0
_0817D560: .4byte 0x030046A4
_0817D564:
	ldrb r0, [r5, #4]
	b _0817D56A
_0817D568:
	ldrb r0, [r5]
_0817D56A:
	subs r2, r2, r0
_0817D56C:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817D57E
	adds r0, #4
	b _0817D58A
_0817D57E:
	ldr r0, _0817D59C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817D58A:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0817D5A0
	asrs r0, r0, #6
	b _0817D5A6
	.align 2, 0
_0817D59C: .4byte 0x030046A4
_0817D5A0:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0817D5A6:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0817D5E4
	cmp r1, #1
	bgt _0817D5B8
	cmp r1, #0
	beq _0817D5C2
	b _0817D6A4
_0817D5B8:
	cmp r1, #2
	beq _0817D620
	cmp r1, #3
	beq _0817D642
	b _0817D6A4
_0817D5C2:
	adds r4, r6, #1
	movs r5, #0
_0817D5C6:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D5E0
	adds r4, #1
	adds r5, #1
	cmp r5, #1
	blt _0817D5C6
_0817D5E0:
	subs r1, r4, #1
	b _0817D6A6
_0817D5E4:
	ldr r0, _0817D61C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	movs r5, #0
_0817D5F2:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D67C
	ldr r0, _0817D61C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r4, r4, r1
	adds r5, #1
	cmp r5, #1
	blt _0817D5F2
	subs r1, r4, r1
	b _0817D6A6
	.align 2, 0
_0817D61C: .4byte 0x030046A4
_0817D620:
	subs r4, r6, #1
	movs r5, #0
_0817D624:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D63E
	subs r4, #1
	adds r5, #1
	cmp r5, #1
	blt _0817D624
_0817D63E:
	adds r1, r4, #1
	b _0817D6A6
_0817D642:
	ldr r0, _0817D678 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r4, r6, r0
	movs r5, #0
_0817D650:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D690
	ldr r0, _0817D678 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	subs r4, r4, r1
	adds r5, #1
	cmp r5, #1
	blt _0817D650
	adds r1, r4, r1
	b _0817D6A6
	.align 2, 0
_0817D678: .4byte 0x030046A4
_0817D67C:
	ldr r0, _0817D68C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r1, r4, r0
	b _0817D6A6
	.align 2, 0
_0817D68C: .4byte 0x030046A4
_0817D690:
	ldr r0, _0817D6A0 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r1, r4, r0
	b _0817D6A6
	.align 2, 0
_0817D6A0: .4byte 0x030046A4
_0817D6A4:
	ldrh r1, [r4]
_0817D6A6:
	mov r0, sl
	mov r7, sb
	strb r0, [r7, #5]
	ldr r0, _0817D6BC @ =0x00000256
	add r0, sb
	ldrh r0, [r0]
	cmp r1, r0
	beq _0817D6C0
_0817D6B6:
	movs r0, #2
	b _0817D6C2
	.align 2, 0
_0817D6BC: .4byte 0x00000256
_0817D6C0:
	movs r0, #0
_0817D6C2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0817d6d4
FUN_0817d6d4: @ 0x0817D6D4
	push {r4, r5, r6, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _0817D714 @ =0x03003584
	ldr r0, [r0]
	ldr r2, _0817D718 @ =0x00004EA0
	adds r6, r0, r2
	movs r2, #0
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r5, r1, r0
_0817D6EE:
	lsls r0, r2, #5
	adds r4, r2, #1
	adds r3, r6, #0
	adds r2, r0, r5
	movs r1, #0xf
_0817D6F8:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bge _0817D6F8
	adds r2, r4, #0
	cmp r2, #2
	ble _0817D6EE
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0817D714: .4byte 0x03003584
_0817D718: .4byte 0x00004EA0

	thumb_func_start FUN_0817d71c
FUN_0817d71c: @ 0x0817D71C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r3, [sp]
	str r0, [sp, #4]
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r7, r0, r3
	ldr r0, _0817D770 @ =0x03003584
	lsls r4, r1, #5
	ldr r3, [r0]
	lsls r2, r2, #5
	adds r2, r3, r2
	str r2, [sp, #8]
	ldr r5, [sp, #4]
	ldr r2, _0817D774 @ =0x000006DA
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r0, r5, r0
	str r0, [sp, #0x10]
	adds r3, r3, r4
	mov sl, r3
	movs r1, #0
	mov sb, r1
	movs r2, #0xf
	str r2, [sp, #0xc]
_0817D75A:
	adds r0, r7, #0
	adds r0, #0x80
	ldrh r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r0, r3
	beq _0817D778
	mov r5, sb
	adds r0, r7, r5
	b _0817D77C
	.align 2, 0
_0817D770: .4byte 0x03003584
_0817D774: .4byte 0x000006DA
_0817D778:
	ldr r0, [sp, #8]
	add r0, sb
_0817D77C:
	ldrh r5, [r0]
	adds r3, r7, #0
	adds r3, #0xe4
	add r3, sb
	mov r0, sl
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	mov r8, r5
	mov r1, r8
	movs r2, #0x1f
	ands r1, r2
	mov r8, r1
	subs r0, r0, r1
	lsls r0, r0, #8
	strh r0, [r3]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r6, r7, r0
	add r6, sb
	mov r1, sl
	ldrh r0, [r1]
	lsrs r0, r0, #5
	ands r0, r2
	asrs r2, r5, #5
	movs r1, #0x1f
	ands r2, r1
	subs r0, r0, r2
	lsls r0, r0, #8
	strh r0, [r6]
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r7, r0
	add r4, sb
	mov r1, sl
	ldrh r0, [r1]
	lsrs r0, r0, #0xa
	movs r1, #0x1f
	ands r0, r1
	asrs r5, r5, #0xa
	ands r5, r1
	subs r0, r0, r5
	lsls r0, r0, #8
	strh r0, [r4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	ldr r1, [sp]
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	bl Div
	ldr r3, [sp, #0x18]
	strh r0, [r3]
	movs r3, #0
	ldrsh r0, [r6, r3]
	ldr r1, [sp]
	bl Div
	strh r0, [r6]
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, [sp]
	bl Div
	strh r0, [r4]
	adds r0, r7, #0
	adds r0, #0x84
	add r0, sb
	mov r3, r8
	lsls r3, r3, #8
	strh r3, [r0]
	adds r0, r7, #0
	adds r0, #0xa4
	add r0, sb
	ldr r2, [sp, #0x14]
	lsls r2, r2, #8
	strh r2, [r0]
	adds r0, r7, #0
	adds r0, #0xc4
	add r0, sb
	lsls r5, r5, #8
	strh r5, [r0]
	movs r5, #2
	add sl, r5
	add sb, r5
	ldr r0, [sp, #0xc]
	subs r0, #1
	str r0, [sp, #0xc]
	cmp r0, #0
	bge _0817D75A
	mov r1, sp
	ldrh r2, [r1]
	ldr r1, [sp, #0x10]
	strh r2, [r1]
	movs r2, #0x80
	ldr r3, [sp, #4]
	ldr r5, _0817D858 @ =0x00000898
	adds r1, r3, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817D858: .4byte 0x00000898

	thumb_func_start FUN_0817d85c
FUN_0817d85c: @ 0x0817D85C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D876
	b _0817DA12
_0817D876:
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r5, [r0]
	movs r1, #0x80
	ldr r2, _0817D890 @ =0x00000898
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817D894
	movs r0, #1
	b _0817D896
	.align 2, 0
_0817D890: .4byte 0x00000898
_0817D894:
	movs r0, #0
_0817D896:
	cmp r0, #0
	bne _0817D89C
	b _0817DA12
_0817D89C:
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r3, r3, r5
	mov sb, r3
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _0817D928
	ldr r1, _0817D8E8 @ =0x02008000
	movs r0, #0xbc
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817D8C2
	b _0817DA20
_0817D8C2:
	ldr r0, _0817D8EC @ =0x0000047A
	add r0, r8
	ldrh r1, [r0]
	movs r0, #0x90
	lsls r0, r0, #3
	add r0, r8
	ldrh r0, [r0]
	adds r1, r1, r0
	ldr r0, _0817D8F0 @ =0x0000025D
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817D8F4
	mov r2, r8
	ldr r0, [r2, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _0817D902
	.align 2, 0
_0817D8E8: .4byte 0x02008000
_0817D8EC: .4byte 0x0000047A
_0817D8F0: .4byte 0x0000025D
_0817D8F4:
	mov r3, r8
	ldr r2, [r3, #0x44]
	ldr r0, _0817D91C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0817D902:
	mov r1, r8
	ldr r0, [r1, #0x44]
	adds r0, #0x20
	ldr r1, _0817D920 @ =0x00000272
	strh r1, [r0, #0x3a]
	ldr r3, _0817D924 @ =0x00000898
	adds r2, r5, r3
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0817DA20
	.align 2, 0
_0817D91C: .4byte 0x03003584
_0817D920: .4byte 0x00000272
_0817D924: .4byte 0x00000898
_0817D928:
	movs r0, #0xbc
	lsls r0, r0, #1
	add r0, r8
	str r0, [sp, #0xc]
	ldr r2, _0817D988 @ =0x000006DC
	adds r2, r5, r2
	str r2, [sp, #4]
	ldr r3, _0817D98C @ =0x0000073C
	adds r3, r5, r3
	str r3, [sp, #8]
	mov sl, r1
	mov r6, sb
	movs r7, #0
	ldr r0, _0817D990 @ =0x000006FC
	adds r4, r5, r0
	ldr r1, _0817D994 @ =0x0000075C
	adds r1, r1, r5
	mov ip, r1
	ldr r2, _0817D998 @ =0x0000077C
	adds r2, r5, r2
	str r2, [sp]
	ldr r3, _0817D99C @ =0x0000071C
	adds r2, r5, r3
_0817D956:
	ldr r0, [sp, #4]
	adds r1, r0, r7
	ldr r3, [sp, #8]
	adds r0, r3, r7
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	mov r3, ip
	ldrh r0, [r3]
	ldrh r3, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldr r3, [sp]
	adds r0, r3, r7
	ldrh r0, [r0]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	blt _0817D9A0
	asrs r0, r0, #8
	b _0817D9A6
	.align 2, 0
_0817D988: .4byte 0x000006DC
_0817D98C: .4byte 0x0000073C
_0817D990: .4byte 0x000006FC
_0817D994: .4byte 0x0000075C
_0817D998: .4byte 0x0000077C
_0817D99C: .4byte 0x0000071C
_0817D9A0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0817D9A6:
	adds r5, r0, #0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	blt _0817D9B4
	asrs r0, r0, #8
	b _0817D9BA
_0817D9B4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0817D9BA:
	adds r3, r0, #0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _0817D9C8
	asrs r1, r0, #8
	b _0817D9CE
_0817D9C8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0817D9CE:
	lsls r0, r3, #5
	orrs r0, r5
	lsls r1, r1, #0xa
	orrs r1, r0
	strh r1, [r6]
	adds r6, #2
	adds r2, #2
	adds r7, #2
	adds r4, #2
	movs r3, #2
	add ip, r3
	mov r0, sb
	adds r0, #0x1e
	cmp r6, r0
	ble _0817D956
	mov r1, sl
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldr r1, _0817DA18 @ =0x02008000
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0817DA0A
	ldr r2, _0817DA1C @ =0x00000273
	mov r0, r8
	mov r1, sb
	bl FUN_0817dbf0
_0817DA0A:
	mov r3, sl
	ldrh r0, [r3]
	cmp r0, #0
	beq _0817DA20
_0817DA12:
	movs r0, #0
	b _0817DA22
	.align 2, 0
_0817DA18: .4byte 0x02008000
_0817DA1C: .4byte 0x00000273
_0817DA20:
	movs r0, #1
_0817DA22:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0817da34
FUN_0817da34: @ 0x0817DA34
	push {r4, lr}
	adds r1, r0, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r3, [r0]
	ldr r4, _0817DA54 @ =0x000008B6
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0817DA74
	cmp r0, #9
	bhi _0817DA58
	movs r0, #0x10
	b _0817DA5E
	.align 2, 0
_0817DA54: .4byte 0x000008B6
_0817DA58:
	cmp r0, #0x1d
	bhi _0817DA6A
	movs r0, #0x20
_0817DA5E:
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r2, r1, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0817DA6A:
	ldr r0, _0817DA7C @ =0x000008B6
	adds r1, r3, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0817DA74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0817DA7C: .4byte 0x000008B6

	thumb_func_start FUN_0817da80
FUN_0817da80: @ 0x0817DA80
	push {r4, r5, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r4, [r1]
	ldrb r1, [r0, #5]
	adds r5, r1, #0
	adds r5, #0x20
	movs r1, #0xff
	ands r5, r1
	ldr r1, _0817DABC @ =0x0000085C
	adds r3, r4, r1
	ldr r1, [r0, #8]
	ldr r2, [r0, #0xc]
	str r1, [r3]
	str r2, [r3, #4]
	ldr r2, _0817DAC0 @ =0x00000553
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _0817DB06
	asrs r0, r5, #6
	cmp r0, #1
	beq _0817DADA
	cmp r0, #1
	bgt _0817DAC4
	cmp r0, #0
	beq _0817DACE
	b _0817DB82
	.align 2, 0
_0817DABC: .4byte 0x0000085C
_0817DAC0: .4byte 0x00000553
_0817DAC4:
	cmp r0, #2
	beq _0817DAE2
	cmp r0, #3
	beq _0817DAF4
	b _0817DB82
_0817DACE:
	movs r0, #0x86
	lsls r0, r0, #4
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #0x20
	b _0817DB04
_0817DADA:
	ldrh r0, [r3]
	subs r0, #0x20
	strh r0, [r3]
	b _0817DB06
_0817DAE2:
	ldrh r0, [r3]
	subs r0, #0x30
	strh r0, [r3]
	movs r2, #0x86
	lsls r2, r2, #4
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #6
	b _0817DB04
_0817DAF4:
	ldrh r0, [r3]
	adds r0, #0xa
	strh r0, [r3]
	movs r0, #0x86
	lsls r0, r0, #4
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #0x18
_0817DB04:
	strh r0, [r1]
_0817DB06:
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r2, _0817DB1C @ =0x00000898
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817DB20
	movs r0, #1
	b _0817DB22
	.align 2, 0
_0817DB1C: .4byte 0x00000898
_0817DB20:
	movs r0, #0
_0817DB22:
	cmp r0, #0
	bne _0817DB82
	asrs r1, r5, #6
	cmp r1, #1
	beq _0817DB48
	cmp r1, #1
	bgt _0817DB36
	cmp r1, #0
	beq _0817DB40
	b _0817DB82
_0817DB36:
	cmp r1, #2
	beq _0817DB50
	cmp r1, #3
	beq _0817DB6C
	b _0817DB82
_0817DB40:
	movs r0, #0x86
	lsls r0, r0, #4
	adds r1, r4, r0
	b _0817DB7C
_0817DB48:
	ldr r2, _0817DB4C @ =0x0000085C
	b _0817DB7A
	.align 2, 0
_0817DB4C: .4byte 0x0000085C
_0817DB50:
	ldr r0, _0817DB68 @ =0x0000085C
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #0x18
	strh r0, [r1]
	movs r2, #0x86
	lsls r2, r2, #4
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #6
	b _0817DB80
	.align 2, 0
_0817DB68: .4byte 0x0000085C
_0817DB6C:
	ldr r0, _0817DB88 @ =0x0000085C
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #6
	strh r0, [r1]
	movs r2, #0x86
	lsls r2, r2, #4
_0817DB7A:
	adds r1, r4, r2
_0817DB7C:
	ldrh r0, [r1]
	subs r0, #0x20
_0817DB80:
	strh r0, [r1]
_0817DB82:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0817DB88: .4byte 0x0000085C

	thumb_func_start FUN_0817db8c
FUN_0817db8c: @ 0x0817DB8C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	ldr r3, _0817DBE4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x20
	orrs r0, r2
	ldr r1, _0817DBE8 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0xc]
	add r4, sp, #0xc
	ldr r0, [r4, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r4, #4]
	add r6, sp, #0x14
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #8
	adds r1, r6, #0
	ldr r2, _0817DBEC @ =0x05000002
	bl CpuSet
	adds r5, #8
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	mov r3, r8
	bl FUN_080dbcec
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0817DBE4: .4byte 0xFFFF0000
_0817DBE8: .4byte 0x0000FFFF
_0817DBEC: .4byte 0x05000002

	thumb_func_start FUN_0817dbf0
FUN_0817dbf0: @ 0x0817DBF0
	ldr r0, [r0, #0x44]
	adds r0, #0x20
	str r1, [r0, #0x48]
	strh r2, [r0, #0x3a]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0817dbfc
FUN_0817dbfc: @ 0x0817DBFC
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r3, [r6, #8]
	ldr r4, [r6, #0xc]
	str r3, [sp, #0x10]
	str r4, [sp, #0x14]
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0x66
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0817DC64 @ =0xFFFF0000
	ldr r2, [sp, #0x10]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0817DC68 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r2, _0817DC6C @ =0x0000079C
	adds r1, r5, r2
	str r3, [r1]
	str r4, [r1, #4]
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	ldr r0, _0817DC70 @ =0x0000079E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #0xf0
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r2, #0xfc
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817DC74
	movs r0, #1
	b _0817DC76
	.align 2, 0
_0817DC64: .4byte 0xFFFF0000
_0817DC68: .4byte 0x0000FFFF
_0817DC6C: .4byte 0x0000079C
_0817DC70: .4byte 0x0000079E
_0817DC74:
	movs r0, #0
_0817DC76:
	cmp r0, #0
	beq _0817DC84
	ldr r1, _0817DC80 @ =0x000007A4
	b _0817DCA8
	.align 2, 0
_0817DC80: .4byte 0x000007A4
_0817DC84:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _0817DC9C @ =0x00000898
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _0817DCA0
	movs r0, #1
	b _0817DCA2
	.align 2, 0
_0817DC9C: .4byte 0x00000898
_0817DCA0:
	movs r0, #0
_0817DCA2:
	cmp r0, #0
	beq _0817DCB4
	ldr r1, _0817DCB0 @ =0x000007A5
_0817DCA8:
	adds r0, r5, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	b _0817DCDA
	.align 2, 0
_0817DCB0: .4byte 0x000007A5
_0817DCB4:
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0817DCC4
	movs r0, #1
	b _0817DCC6
_0817DCC4:
	movs r0, #0
_0817DCC6:
	cmp r0, #0
	beq _0817DCD8
	ldr r2, _0817DCD4 @ =0x000007A6
	adds r0, r5, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	b _0817DCDA
	.align 2, 0
_0817DCD4: .4byte 0x000007A6
_0817DCD8:
	movs r1, #0
_0817DCDA:
	add r0, sp, #0x10
	str r0, [sp]
	ldr r2, _0817DD04 @ =0x0000079C
	adds r0, r5, r2
	str r0, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	movs r0, #0
	movs r2, #3
	movs r3, #0
	bl FUN_080177b4
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_082406e0
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0817DD04: .4byte 0x0000079C

	thumb_func_start FUN_0817dd08
FUN_0817dd08: @ 0x0817DD08
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r1, [sp]
	asrs r0, r1, #0x10
	adds r0, #0xdc
	lsls r0, r0, #0x10
	ldr r4, _0817DDDC @ =0x0000FFFF
	ands r4, r1
	orrs r4, r0
	str r4, [sp]
	ldr r6, _0817DDE0 @ =0x0203B400
	ldr r0, _0817DDE4 @ =0x030046B8
	mov sl, r0
	ldr r2, [r0]
	adds r2, #1
	ldr r5, _0817DDE8 @ =0x000003FF
	ands r2, r5
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r3, [r0]
	mov r0, sp
	ldrh r1, [r0]
	subs r1, #0x10
	movs r0, #0x1f
	mov r8, r0
	mov r0, r8
	ands r3, r0
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0817DDEC @ =0xFFFF0000
	mov sb, r3
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	str r0, [sp]
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r3, [r0]
	mov r0, sp
	ldrh r1, [r0, #4]
	subs r1, #0x10
	mov r0, r8
	ands r3, r0
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	mov r3, sb
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r3, [r0]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	subs r0, #0x20
	movs r1, #0x3f
	ands r3, r1
	adds r4, r0, r3
	movs r3, #0xff
	adds r2, #1
	ands r2, r5
	mov r0, sl
	str r2, [r0]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r1, [r2]
	movs r0, #0xf
	ands r1, r0
	add r5, sp, #8
	ands r4, r3
	adds r6, r1, #0
	adds r6, #0xa
	ldr r1, _0817DDF0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	mov r3, sl
	mov r8, r5
	cmp r0, #0
	blt _0817DDF4
	asrs r2, r0, #0xc
	b _0817DDFA
	.align 2, 0
_0817DDDC: .4byte 0x0000FFFF
_0817DDE0: .4byte 0x0203B400
_0817DDE4: .4byte 0x030046B8
_0817DDE8: .4byte 0x000003FF
_0817DDEC: .4byte 0xFFFF0000
_0817DDF0: .4byte 0x085B0A08
_0817DDF4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0817DDFA:
	movs r0, #0
	strh r2, [r5]
	strh r0, [r5, #2]
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0817DE12
	asrs r0, r0, #0xc
	b _0817DE18
_0817DE12:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0817DE18:
	strh r0, [r5, #4]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0817DE48 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _0817DE4C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	mov r3, r8
	strh r0, [r3, #2]
	ldr r1, _0817DE50 @ =0x0000049C
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0817DE54
	movs r3, #7
	b _0817DE9C
	.align 2, 0
_0817DE48: .4byte 0x000003FF
_0817DE4C: .4byte 0x0203B400
_0817DE50: .4byte 0x0000049C
_0817DE54:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0817DE60
	movs r3, #1
	b _0817DE9C
_0817DE60:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0817DE6C
	movs r3, #2
	b _0817DE9C
_0817DE6C:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0817DE78
	movs r3, #3
	b _0817DE9C
_0817DE78:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0817DE84
	movs r3, #4
	b _0817DE9C
_0817DE84:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0817DE90
	movs r3, #5
	b _0817DE9C
_0817DE90:
	movs r0, #0x20
	ands r1, r0
	movs r3, #0
	cmp r1, #0
	beq _0817DE9C
	movs r3, #6
_0817DE9C:
	mov r0, sp
	mov r1, r8
	movs r2, #0x14
	bl FUN_081ee07c
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0817deb8
FUN_0817deb8: @ 0x0817DEB8
	push {lr}
	ldr r2, _0817DECC @ =0x000008B7
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817DEC8
	subs r0, #1
	strb r0, [r1]
_0817DEC8:
	pop {r0}
	bx r0
	.align 2, 0
_0817DECC: .4byte 0x000008B7

	thumb_func_start FUN_0817ded0
FUN_0817ded0: @ 0x0817DED0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r6, [r0]
	movs r0, #0x69
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0817DF50
	bl VM_GetPC
	cmp r0, #0
	beq _0817DEFC
	bl Script_GetValue
	adds r1, r0, #0
	b _0817DEFE
_0817DEFC:
	movs r1, #0
_0817DEFE:
	ldr r2, _0817DF1C @ =0x000007AE
	adds r0, r6, r2
	strh r1, [r0]
	movs r4, #0
_0817DF06:
	ldr r3, _0817DF20 @ =0x000007A4
	adds r0, r6, r3
	adds r5, r0, r4
	bl VM_GetPC
	cmp r0, #0
	beq _0817DF24
	bl Script_GetValue
	b _0817DF2A
	.align 2, 0
_0817DF1C: .4byte 0x000007AE
_0817DF20: .4byte 0x000007A4
_0817DF24:
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r1, #0
_0817DF2A:
	strb r0, [r5]
	lsls r0, r4, #1
	movs r2, #0xf5
	lsls r2, r2, #3
	adds r1, r6, r2
	adds r5, r1, r0
	bl VM_GetPC
	cmp r0, #0
	beq _0817DF44
	bl Script_GetValue
	b _0817DF46
_0817DF44:
	movs r0, #0
_0817DF46:
	strh r0, [r5]
	adds r4, #1
	cmp r4, #2
	ble _0817DF06
	b _0817DF78
_0817DF50:
	ldr r3, _0817DFBC @ =0x000007AE
	adds r0, r6, r3
	strh r1, [r0]
	movs r4, #0
	ldr r0, _0817DFC0 @ =0x000007A4
	adds r3, r6, r0
	movs r7, #0xff
	movs r1, #0xf5
	lsls r1, r1, #3
	adds r2, r6, r1
	movs r5, #0
_0817DF66:
	adds r1, r3, r4
	ldrb r0, [r1]
	orrs r0, r7
	strb r0, [r1]
	strh r5, [r2]
	adds r2, #2
	adds r4, #1
	cmp r4, #2
	ble _0817DF66
_0817DF78:
	movs r0, #0x54
	movs r1, #0x78
	bl Script_GetKeywordValue
	ldr r2, _0817DFC4 @ =0x000008A8
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0xc2
	lsls r0, r0, #1
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl Div
	lsls r2, r0, #1
	adds r0, r2, r0
	movs r3, #0x8b
	lsls r3, r3, #4
	adds r1, r6, r3
	strh r0, [r1]
	lsls r0, r0, #1
	adds r3, #2
	adds r1, r6, r3
	strh r0, [r1]
	ldr r1, _0817DFC8 @ =0x000008B4
	adds r0, r6, r1
	strh r2, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817DFBC: .4byte 0x000007AE
_0817DFC0: .4byte 0x000007A4
_0817DFC4: .4byte 0x000008A8
_0817DFC8: .4byte 0x000008B4

	thumb_func_start FUN_0817dfcc
FUN_0817dfcc: @ 0x0817DFCC
	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	ldr r3, _0817DFF0 @ =0x000007A4
	adds r2, r0, r3
	movs r3, #1
	rsbs r3, r3, #0
_0817DFE0:
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r3
	beq _0817DFF4
	adds r0, r1, #0
	b _0817DFFE
	.align 2, 0
_0817DFF0: .4byte 0x000007A4
_0817DFF4:
	adds r1, #1
	cmp r1, #2
	ble _0817DFE0
	movs r0, #1
	rsbs r0, r0, #0
_0817DFFE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0817e004
FUN_0817e004: @ 0x0817E004
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r3, [r0]
	ldr r2, _0817E028 @ =0x000007A4
	adds r0, r3, r2
	adds r0, r0, r1
	movs r2, #0xff
	strb r2, [r0]
	lsls r1, r1, #1
	movs r0, #0xf5
	lsls r0, r0, #3
	adds r3, r3, r0
	adds r3, r3, r1
	movs r0, #0
	strh r0, [r3]
	bx lr
	.align 2, 0
_0817E028: .4byte 0x000007A4

	thumb_func_start FUN_0817e02c
FUN_0817e02c: @ 0x0817E02C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_0817dfcc
	cmp r0, #0
	bge _0817E044
	b _0817E198
_0817E044:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r2, #0x8b
	lsls r2, r2, #4
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r1, r0
	bge _0817E0B4
	ldr r3, _0817E0A0 @ =0x000007A4
	adds r0, r5, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0817E0B4
	movs r2, #0x13
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0817E0A4 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _0817E0A8 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc8
	lsls r1, r1, #6
	ldr r0, _0817E0AC @ =0x00000898
	adds r2, r5, r0
	ldr r0, [r2]
	orrs r0, r1
	ldr r1, _0817E0B0 @ =0xFFFFF3FF
	b _0817E17C
	.align 2, 0
_0817E0A0: .4byte 0x000007A4
_0817E0A4: .4byte 0x00000469
_0817E0A8: .4byte 0x00000484
_0817E0AC: .4byte 0x00000898
_0817E0B0: .4byte 0xFFFFF3FF
_0817E0B4:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _0817E110 @ =0x000008B2
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r1, r0
	bge _0817E124
	ldr r1, _0817E114 @ =0x000007A5
	adds r0, r5, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0817E124
	movs r2, #0x13
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _0817E118 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xd0
	lsls r1, r1, #6
	ldr r0, _0817E11C @ =0x00000898
	adds r2, r5, r0
	ldr r0, [r2]
	orrs r0, r1
	ldr r1, _0817E120 @ =0xFFFFF5FF
	b _0817E17C
	.align 2, 0
_0817E110: .4byte 0x000008B2
_0817E114: .4byte 0x000007A5
_0817E118: .4byte 0x00000484
_0817E11C: .4byte 0x00000898
_0817E120: .4byte 0xFFFFF5FF
_0817E124:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _0817E184 @ =0x000008B4
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r1, r0
	bge _0817E198
	ldr r1, _0817E188 @ =0x000007A6
	adds r0, r5, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0817E198
	movs r2, #0x13
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _0817E18C @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xe0
	lsls r1, r1, #6
	ldr r0, _0817E190 @ =0x00000898
	adds r2, r5, r0
	ldr r0, [r2]
	orrs r0, r1
	ldr r1, _0817E194 @ =0xFFFFF9FF
_0817E17C:
	ands r0, r1
	str r0, [r2]
	movs r0, #1
	b _0817E19A
	.align 2, 0
_0817E184: .4byte 0x000008B4
_0817E188: .4byte 0x000007A6
_0817E18C: .4byte 0x00000484
_0817E190: .4byte 0x00000898
_0817E194: .4byte 0xFFFFF9FF
_0817E198:
	movs r0, #0
_0817E19A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0817e1a0
FUN_0817e1a0: @ 0x0817E1A0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	adds r1, #0x34
	ldr r2, _0817E1C0 @ =0x00000898
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817E1C4
	movs r0, #1
	b _0817E1C6
	.align 2, 0
_0817E1C0: .4byte 0x00000898
_0817E1C4:
	movs r0, #0
_0817E1C6:
	cmp r0, #0
	bne _0817E1CC
	b _0817E320
_0817E1CC:
	movs r3, #0x95
	lsls r3, r3, #2
	adds r4, r5, r3
	ldrh r0, [r4]
	movs r1, #0xa
	bl Div
	movs r2, #0xf5
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r3, r0, #0
	muls r3, r1, r3
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldrh r1, [r4]
	cmp r0, r1
	ble _0817E202
	subs r0, r0, r1
	subs r3, r3, r0
	strh r1, [r2]
_0817E202:
	ldr r2, _0817E21C @ =0x0000048A
	adds r0, r5, r2
	strh r3, [r0]
	ldr r0, _0817E220 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0817E224
	movs r0, #1
	b _0817E226
	.align 2, 0
_0817E21C: .4byte 0x0000048A
_0817E220: .4byte 0x030047A4
_0817E224:
	movs r0, #0
_0817E226:
	cmp r0, #0
	beq _0817E294
	movs r3, #0x94
	lsls r3, r3, #3
	adds r1, r5, r3
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _0817E294
	cmp r2, #0
	beq _0817E294
	ldr r0, _0817E24C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0817E250
	movs r0, #1
	rsbs r0, r0, #0
	b _0817E254
	.align 2, 0
_0817E24C: .4byte 0x03002C68
_0817E250:
	movs r4, #0x18
	ldrsh r0, [r0, r4]
_0817E254:
	cmp r0, #1
	beq _0817E276
	cmp r0, #1
	bgt _0817E262
	cmp r0, #0
	beq _0817E26C
	b _0817E294
_0817E262:
	cmp r0, #2
	beq _0817E280
	cmp r0, #3
	beq _0817E28A
	b _0817E294
_0817E26C:
	ldr r0, [r1]
	cmp r0, #1
	beq _0817E294
	movs r0, #0
	b _0817E296
_0817E276:
	ldr r0, [r1]
	cmp r0, #2
	beq _0817E294
	movs r0, #0
	b _0817E296
_0817E280:
	ldr r0, [r1]
	cmp r0, #4
	beq _0817E294
	movs r0, #0
	b _0817E296
_0817E28A:
	ldr r0, [r1]
	cmp r0, #8
	beq _0817E294
	movs r0, #0
	b _0817E296
_0817E294:
	movs r0, #1
_0817E296:
	cmp r0, #0
	beq _0817E2FA
	ldrh r0, [r5]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r4, #0x95
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrh r2, [r2]
	adds r4, #6
	adds r3, r5, r4
	ldrh r3, [r3]
	movs r4, #0
	str r4, [sp]
	bl FUN_0809c344
	add r7, sp, #0xc
	str r4, [sp, #8]
	add r0, sp, #8
	adds r1, r7, #0
	ldr r2, _0817E310 @ =0x05000002
	bl CpuSet
	ldr r0, _0817E314 @ =0x0000048A
	adds r2, r5, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _0817E2E6
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0817E2FA
_0817E2E6:
	adds r0, r5, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r5, #0
	adds r3, #8
	str r7, [sp]
	movs r2, #1
	str r2, [sp, #4]
	bl FUN_0805fe7c
_0817E2FA:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0817e004
	ldr r3, _0817E318 @ =0x00000898
	adds r2, r6, r3
	ldr r1, _0817E31C @ =0xFFFFFDFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0817E3E2
	.align 2, 0
_0817E310: .4byte 0x05000002
_0817E314: .4byte 0x0000048A
_0817E318: .4byte 0x00000898
_0817E31C: .4byte 0xFFFFFDFF
_0817E320:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r4, _0817E338 @ =0x00000898
	adds r1, r6, r4
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _0817E33C
	movs r0, #1
	b _0817E33E
	.align 2, 0
_0817E338: .4byte 0x00000898
_0817E33C:
	movs r0, #0
_0817E33E:
	cmp r0, #0
	beq _0817E388
	ldr r1, _0817E37C @ =0xFFFEFFFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1, #8]
	ldr r1, _0817E380 @ =0x000007AA
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r2, #0xf6
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0817e004
	ldr r1, _0817E384 @ =0xFFFFFBFF
	b _0817E3DC
	.align 2, 0
_0817E37C: .4byte 0xFFFEFFFF
_0817E380: .4byte 0x000007AA
_0817E384: .4byte 0xFFFFFBFF
_0817E388:
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0817E398
	movs r0, #1
	b _0817E39A
_0817E398:
	movs r0, #0
_0817E39A:
	cmp r0, #0
	beq _0817E3E2
	ldr r1, _0817E3EC @ =0xFFFF7FFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r3, _0817E3F0 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	ldr r1, _0817E3F4 @ =0x000007AC
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r2, #0xf6
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r1, [r0]
	ldr r3, _0817E3F8 @ =0x000007B2
	adds r1, r6, r3
	movs r0, #0x1e
	strh r0, [r1]
	ldr r1, _0817E3FC @ =0xFFFDFFFF
	ldr r0, [r4]
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xb
	orrs r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_0817e004
	ldr r1, _0817E400 @ =0xFFFFF7FF
_0817E3DC:
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_0817E3E2:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817E3EC: .4byte 0xFFFF7FFF
_0817E3F0: .4byte 0x00000482
_0817E3F4: .4byte 0x000007AC
_0817E3F8: .4byte 0x000007B2
_0817E3FC: .4byte 0xFFFDFFFF
_0817E400: .4byte 0xFFFFF7FF

	thumb_func_start FUN_0817e404
FUN_0817e404: @ 0x0817E404
	push {r4, r5, lr}
	sub sp, #0x18
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r5, [r0]
	ldr r2, _0817E444 @ =0x000007AE
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0817E500
	movs r1, #8
	ldrsh r0, [r3, r1]
	str r0, [sp]
	movs r2, #0xa
	ldrsh r0, [r3, r2]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r3, r1]
	str r0, [sp, #8]
	movs r2, #0x80
	lsls r2, r2, #2
	ldr r0, _0817E448 @ =0x00000898
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _0817E44C
	movs r0, #1
	b _0817E44E
	.align 2, 0
_0817E444: .4byte 0x000007AE
_0817E448: .4byte 0x00000898
_0817E44C:
	movs r0, #0
_0817E44E:
	cmp r0, #0
	beq _0817E474
	ldr r1, _0817E46C @ =0x000007A4
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0817e004
	ldr r1, _0817E470 @ =0xFFFFFDFF
	b _0817E4D8
	.align 2, 0
_0817E46C: .4byte 0x000007A4
_0817E470: .4byte 0xFFFFFDFF
_0817E474:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0817E484
	movs r0, #1
	b _0817E486
_0817E484:
	movs r0, #0
_0817E486:
	cmp r0, #0
	beq _0817E4AC
	ldr r2, _0817E4A4 @ =0x000007A5
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r1, #1
	bl FUN_0817e004
	ldr r1, _0817E4A8 @ =0xFFFFFBFF
	b _0817E4D8
	.align 2, 0
_0817E4A4: .4byte 0x000007A5
_0817E4A8: .4byte 0xFFFFFBFF
_0817E4AC:
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0817E4BC
	movs r0, #1
	b _0817E4BE
_0817E4BC:
	movs r0, #0
_0817E4BE:
	cmp r0, #0
	beq _0817E4DE
	ldr r1, _0817E508 @ =0x000007A6
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r1, #2
	bl FUN_0817e004
	ldr r1, _0817E50C @ =0xFFFFF7FF
_0817E4D8:
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_0817E4DE:
	ldr r1, _0817E510 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x10]
	add r1, sp, #0x10
	mov r2, sp
	str r2, [r1, #4]
	ldr r2, _0817E514 @ =0x000007AE
	adds r0, r5, r2
	ldrh r0, [r0]
	bl Script_ExecById
	ldr r0, _0817E518 @ =0x000002B7
	bl PlaySound_082406e0
_0817E500:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0817E508: .4byte 0x000007A6
_0817E50C: .4byte 0xFFFFF7FF
_0817E510: .4byte 0xFFFF0000
_0817E514: .4byte 0x000007AE
_0817E518: .4byte 0x000002B7

	thumb_func_start FUN_0817e51c
FUN_0817e51c: @ 0x0817E51C
	push {r4, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r4, [r0]
	ldr r1, _0817E54C @ =0x000007B2
	adds r0, r4, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _0817E580
	movs r2, #0x80
	lsls r2, r2, #0xa
	ldr r0, _0817E550 @ =0x00000898
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _0817E554
	movs r0, #1
	b _0817E556
	.align 2, 0
_0817E54C: .4byte 0x000007B2
_0817E550: .4byte 0x00000898
_0817E554:
	movs r0, #0
_0817E556:
	cmp r0, #0
	beq _0817E568
	ldr r0, [r3, #0x44]
	adds r0, #0x20
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0817E5C2
_0817E568:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0817E578
	movs r0, #1
	b _0817E57A
_0817E578:
	movs r0, #0
_0817E57A:
	cmp r0, #0
	beq _0817E5C4
	b _0817E5B8
_0817E580:
	cmp r1, #0x13
	bhi _0817E59C
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0817E5B8
	ldr r0, [r3, #0x44]
	adds r0, #0x20
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0817E5C2
_0817E59C:
	cmp r1, #0x1d
	bhi _0817E5C4
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0817E5B8
	ldr r0, [r3, #0x44]
	adds r0, #0x20
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0817E5C2
_0817E5B8:
	ldr r0, [r3, #0x44]
	adds r0, #0x20
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
_0817E5C2:
	str r1, [r0, #8]
_0817E5C4:
	ldr r0, _0817E5D8 @ =0x000007B2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0817E5D2
	subs r0, #1
	strh r0, [r1]
_0817E5D2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0817E5D8: .4byte 0x000007B2

	thumb_func_start FUN_0817e5dc
FUN_0817e5dc: @ 0x0817E5DC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r2, _0817E5FC @ =0x00000898
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817E600
	movs r0, #1
	b _0817E602
	.align 2, 0
_0817E5FC: .4byte 0x00000898
_0817E600:
	movs r0, #0
_0817E602:
	ldr r3, _0817E620 @ =0x00000898
	adds r5, r7, r3
	cmp r0, #0
	beq _0817E648
	movs r4, #0xf6
	lsls r4, r4, #3
	adds r2, r7, r4
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	ble _0817E628
	ldr r3, _0817E624 @ =0x00000482
	adds r1, r6, r3
	movs r0, #2
	b _0817E632
	.align 2, 0
_0817E620: .4byte 0x00000898
_0817E624: .4byte 0x00000482
_0817E628:
	cmp r0, #0
	bne _0817E640
	ldr r4, _0817E63C @ =0x00000482
	adds r1, r6, r4
	movs r0, #1
_0817E632:
	strh r0, [r1]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
	b _0817E648
	.align 2, 0
_0817E63C: .4byte 0x00000482
_0817E640:
	ldr r1, _0817E658 @ =0xFFFF7FFF
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
_0817E648:
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0817E65C
	movs r0, #1
	b _0817E65E
	.align 2, 0
_0817E658: .4byte 0xFFFF7FFF
_0817E65C:
	movs r0, #0
_0817E65E:
	cmp r0, #0
	bne _0817E664
	b _0817E82C
_0817E664:
	movs r0, #0xf6
	lsls r0, r0, #3
	adds r4, r7, r0
	movs r2, #0
	ldrsh r1, [r4, r2]
	cmp r1, #0x1e
	bne _0817E686
	ldr r3, _0817E6B4 @ =0x000007B2
	adds r0, r7, r3
	strh r1, [r0]
	ldr r1, _0817E6B8 @ =0xFFFBFFFF
	ldr r0, [r5]
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xa
	orrs r0, r1
	str r0, [r5]
_0817E686:
	adds r0, r6, #0
	bl FUN_0817e51c
	ldrh r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	ble _0817E6C4
	subs r0, r1, #1
	strh r0, [r4]
	ldr r0, _0817E6BC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0817E750
	ldr r0, _0817E6C0 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _0817E74C
	b _0817E728
	.align 2, 0
_0817E6B4: .4byte 0x000007B2
_0817E6B8: .4byte 0xFFFBFFFF
_0817E6BC: .4byte 0x030047A4
_0817E6C0: .4byte 0x03002BE0
_0817E6C4:
	ldr r3, [r6, #0x44]
	adds r2, r3, #0
	adds r2, #0x20
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	ldr r1, _0817E700 @ =0xFFFEFFFF
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	ldr r4, _0817E704 @ =0x0000047A
	adds r0, r6, r4
	ldrh r1, [r0]
	adds r4, #6
	adds r0, r6, r4
	ldrh r0, [r0]
	adds r1, r1, r0
	ldr r4, _0817E708 @ =0x0000025D
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817E70C
	adds r0, r3, #0
	adds r0, #0x2c
	bl FUN_0822b20c
	b _0817E716
	.align 2, 0
_0817E700: .4byte 0xFFFEFFFF
_0817E704: .4byte 0x0000047A
_0817E708: .4byte 0x0000025D
_0817E70C:
	ldr r0, _0817E720 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x48]
_0817E716:
	ldr r0, [r6, #0x44]
	adds r0, #0x20
	ldr r1, _0817E724 @ =0x00000272
	strh r1, [r0, #0x3a]
	b _0817E82C
	.align 2, 0
_0817E720: .4byte 0x03003584
_0817E724: .4byte 0x00000272
_0817E728:
	ldr r2, _0817E744 @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _0817E740
	ldr r3, _0817E748 @ =0x00000442
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #4
	bne _0817E740
	movs r2, #1
_0817E740:
	adds r0, r2, #0
	b _0817E780
	.align 2, 0
_0817E744: .4byte 0x00000446
_0817E748: .4byte 0x00000442
_0817E74C:
	movs r0, #0
	b _0817E780
_0817E750:
	ldr r0, _0817E794 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _0817E784
	ldr r0, _0817E798 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x94
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #2
	beq _0817E784
	ldr r0, _0817E79C @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _0817E77E
	ldr r0, _0817E7A0 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _0817E77E
	movs r1, #1
_0817E77E:
	adds r0, r1, #0
_0817E780:
	cmp r0, #0
	beq _0817E7DC
_0817E784:
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0817E7A4
	movs r0, #1
	b _0817E7A6
	.align 2, 0
_0817E794: .4byte 0x03002B48
_0817E798: .4byte 0x030046A0
_0817E79C: .4byte 0x03002B8C
_0817E7A0: .4byte 0x03002B60
_0817E7A4:
	movs r0, #0
_0817E7A6:
	cmp r0, #0
	bne _0817E82C
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0817E7BA
	movs r0, #1
	b _0817E7BC
_0817E7BA:
	movs r0, #0
_0817E7BC:
	cmp r0, #0
	beq _0817E82C
	ldr r2, _0817E7D4 @ =0x000007B2
	adds r1, r7, r2
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r5]
	orrs r0, r1
	ldr r1, _0817E7D8 @ =0xFFFBFFFF
	b _0817E828
	.align 2, 0
_0817E7D4: .4byte 0x000007B2
_0817E7D8: .4byte 0xFFFBFFFF
_0817E7DC:
	movs r3, #0xf6
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0x1e
	ble _0817E82C
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0817E7FA
	movs r0, #1
	b _0817E7FC
_0817E7FA:
	movs r0, #0
_0817E7FC:
	cmp r0, #0
	bne _0817E82C
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0817E810
	movs r0, #1
	b _0817E812
_0817E810:
	movs r0, #0
_0817E812:
	cmp r0, #0
	beq _0817E82C
	ldr r0, _0817E834 @ =0x000007B2
	adds r1, r7, r0
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5]
	orrs r0, r1
	ldr r1, _0817E838 @ =0xFFFDFFFF
_0817E828:
	ands r0, r1
	str r0, [r5]
_0817E82C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817E834: .4byte 0x000007B2
_0817E838: .4byte 0xFFFDFFFF

	thumb_func_start FUN_0817e83c
FUN_0817e83c: @ 0x0817E83C
	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r2, _0817E85C @ =0x00000898
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817E860
	movs r0, #1
	b _0817E862
	.align 2, 0
_0817E85C: .4byte 0x00000898
_0817E860:
	movs r0, #0
_0817E862:
	cmp r0, #0
	bne _0817E86A
	movs r0, #0
	b _0817E86C
_0817E86A:
	movs r0, #1
_0817E86C:
	pop {r1}
	bx r1

	thumb_func_start FUN_0817e870
FUN_0817e870: @ 0x0817E870
	push {r4, r5, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r2, #0
	ldr r0, _0817E8A0 @ =0x000008AC
	adds r3, r4, r0
	movs r5, #0xff
_0817E882:
	adds r1, r3, r2
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r2, #1
	cmp r2, #2
	ble _0817E882
	ldr r0, _0817E8A4 @ =0x000008AF
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0817E8A0: .4byte 0x000008AC
_0817E8A4: .4byte 0x000008AF

	thumb_func_start FUN_0817e8a8
FUN_0817e8a8: @ 0x0817E8A8
	push {lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r3, _0817E8D8 @ =0x000008AF
	adds r2, r0, r3
	subs r3, #3
	adds r0, r0, r3
	ldrb r3, [r2]
	adds r0, r0, r3
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0817E8D2
	movs r0, #0
	strb r0, [r2]
_0817E8D2:
	pop {r0}
	bx r0
	.align 2, 0
_0817E8D8: .4byte 0x000008AF

	thumb_func_start FUN_0817e8dc
FUN_0817e8dc: @ 0x0817E8DC
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r2, #0
	ldr r4, _0817E8FC @ =0x000008AC
	adds r3, r0, r4
_0817E8EC:
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r1
	bne _0817E900
	movs r0, #1
	b _0817E908
	.align 2, 0
_0817E8FC: .4byte 0x000008AC
_0817E900:
	adds r2, #1
	cmp r2, #2
	ble _0817E8EC
	movs r0, #0
_0817E908:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0817e910
FUN_0817e910: @ 0x0817E910
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	mov r8, r0
	str r1, [sp, #0x20]
	str r2, [sp, #0x24]
	str r3, [sp, #0x28]
	movs r0, #0x94
	lsls r0, r0, #2
	add r0, r8
	ldrb r1, [r0]
	mov r0, sp
	movs r2, #0
	movs r3, #0
	bl FUN_08234de8
	movs r0, #0
	mov sb, r0
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #0x2c]
	movs r6, #0
	ldr r0, [sp, #4]
	ldrb r2, [r0]
	cmp sb, r2
	bge _0817EA06
	add r7, sp, #0xc
	add r5, sp, #0x18
	ldr r3, _0817E9C4 @ =0xFFFF0000
	mov sl, r3
_0817E952:
	bl FUN_08234f6c
	lsls r1, r6, #3
	adds r0, r0, r1
	str r0, [r7, #8]
	ldr r2, [sp, #0x24]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [r7, #8]
	ldrh r1, [r0]
	ldrh r0, [r5]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x18]
	mov r3, sl
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r7, #8]
	ldrh r1, [r0, #2]
	ldrh r0, [r5, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #0
	ldrsh r3, [r5, r0]
	adds r1, r3, #0
	muls r1, r3, r1
	movs r0, #4
	ldrsh r2, [r5, r0]
	adds r0, r2, #0
	muls r0, r2, r0
	adds r4, r1, r0
	ldr r1, [sp, #0x28]
	cmp r4, r1
	blt _0817E9FC
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_0823785c
	movs r1, #0xfe
	lsls r1, r1, #1
	add r1, r8
	ldrb r1, [r1]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0817E9CC
	ldr r2, _0817E9C8 @ =0xFFFFFF00
	adds r1, r1, r2
	b _0817E9DA
	.align 2, 0
_0817E9C4: .4byte 0xFFFF0000
_0817E9C8: .4byte 0xFFFFFF00
_0817E9CC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0817E9DA
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r1, r3
_0817E9DA:
	adds r0, r1, #0
	cmp r0, #0
	bge _0817E9E2
	rsbs r0, r0, #0
_0817E9E2:
	cmp r0, #0x3f
	ble _0817E9FC
	cmp sb, r4
	bge _0817E9FC
	mov r0, r8
	adds r1, r6, #0
	bl FUN_0817e8dc
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817E9FC
	str r6, [sp, #0x2c]
	mov sb, r4
_0817E9FC:
	adds r6, #1
	ldr r0, [sp, #4]
	ldrb r1, [r0]
	cmp r6, r1
	blt _0817E952
_0817EA06:
	mov r2, sb
	cmp r2, #0
	bne _0817EA2A
	ldr r2, _0817EA74 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0817EA78 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0817EA7C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #4]
	ldrb r1, [r1]
	bl Mod
	str r0, [sp, #0x2c]
_0817EA2A:
	mov r0, r8
	ldr r1, [sp, #0x2c]
	bl FUN_0817e8a8
	mov r0, sp
	movs r1, #0
	add r2, sp, #0x2c
	ldrb r2, [r2]
	strb r2, [r0, #2]
	strb r1, [r0, #3]
	ldr r0, [sp, #4]
	bl FUN_08234f6c
	str r0, [sp, #8]
	mov r1, sp
	ldrb r1, [r1, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrh r1, [r0]
	ldr r3, [sp, #0x20]
	strh r1, [r3]
	ldr r1, _0817EA80 @ =0x00000472
	add r1, r8
	ldrh r1, [r1]
	strh r1, [r3, #2]
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817EA74: .4byte 0x030046B8
_0817EA78: .4byte 0x000003FF
_0817EA7C: .4byte 0x0203B400
_0817EA80: .4byte 0x00000472

	thumb_func_start FUN_0817ea84
FUN_0817ea84: @ 0x0817EA84
	push {lr}
	adds r2, r0, #0
	ldr r0, _0817EAA8 @ =0x03002BE0
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r3, [r0, #6]
	ldrb r0, [r2, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _0817EAC4
	cmp r0, #1
	bgt _0817EAAC
	cmp r0, #0
	beq _0817EAB6
	b _0817EB0C
	.align 2, 0
_0817EAA8: .4byte 0x03002BE0
_0817EAAC:
	cmp r0, #2
	beq _0817EAE0
	cmp r0, #3
	beq _0817EAF0
	b _0817EB0C
_0817EAB6:
	ldr r1, _0817EAC0 @ =0x00000256
	adds r0, r2, r1
	ldrh r0, [r0]
	adds r0, #1
	b _0817EB12
	.align 2, 0
_0817EAC0: .4byte 0x00000256
_0817EAC4:
	ldr r0, _0817EAD8 @ =0x00000256
	adds r1, r2, r0
	ldr r0, _0817EADC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _0817EB12
	.align 2, 0
_0817EAD8: .4byte 0x00000256
_0817EADC: .4byte 0x030046A4
_0817EAE0:
	ldr r1, _0817EAEC @ =0x00000256
	adds r0, r2, r1
	ldrh r0, [r0]
	subs r0, #1
	b _0817EB12
	.align 2, 0
_0817EAEC: .4byte 0x00000256
_0817EAF0:
	ldr r1, _0817EB04 @ =0x00000256
	adds r0, r2, r1
	ldrh r1, [r0]
	ldr r0, _0817EB08 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r0, r1, r0
	b _0817EB12
	.align 2, 0
_0817EB04: .4byte 0x00000256
_0817EB08: .4byte 0x030046A4
_0817EB0C:
	ldr r1, _0817EB1C @ =0x00000256
	adds r0, r2, r1
	ldrh r0, [r0]
_0817EB12:
	cmp r3, r0
	beq _0817EB20
	movs r0, #0
	b _0817EB22
	.align 2, 0
_0817EB1C: .4byte 0x00000256
_0817EB20:
	movs r0, #1
_0817EB22:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0817eb28
FUN_0817eb28: @ 0x0817EB28
	push {lr}
	adds r3, r0, #0
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0817EB50
	cmp r1, #0
	blt _0817EB50
	ldr r0, _0817EB54 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0817EB50
	ldr r0, _0817EB58 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817EB5C
_0817EB50:
	movs r2, #0
	b _0817EB6A
	.align 2, 0
_0817EB54: .4byte 0x030046A8
_0817EB58: .4byte 0x030046AC
_0817EB5C:
	ldr r0, _0817EB84 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r2
_0817EB6A:
	ldrb r0, [r3, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _0817EBA0
	cmp r0, #1
	bgt _0817EB88
	cmp r0, #0
	beq _0817EB92
	b _0817EBE8
	.align 2, 0
_0817EB84: .4byte 0x030046A4
_0817EB88:
	cmp r0, #2
	beq _0817EBBC
	cmp r0, #3
	beq _0817EBCC
	b _0817EBE8
_0817EB92:
	ldr r1, _0817EB9C @ =0x00000256
	adds r0, r3, r1
	ldrh r0, [r0]
	adds r0, #1
	b _0817EBEE
	.align 2, 0
_0817EB9C: .4byte 0x00000256
_0817EBA0:
	ldr r0, _0817EBB4 @ =0x00000256
	adds r1, r3, r0
	ldr r0, _0817EBB8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _0817EBEE
	.align 2, 0
_0817EBB4: .4byte 0x00000256
_0817EBB8: .4byte 0x030046A4
_0817EBBC:
	ldr r1, _0817EBC8 @ =0x00000256
	adds r0, r3, r1
	ldrh r0, [r0]
	subs r0, #1
	b _0817EBEE
	.align 2, 0
_0817EBC8: .4byte 0x00000256
_0817EBCC:
	ldr r1, _0817EBE0 @ =0x00000256
	adds r0, r3, r1
	ldrh r1, [r0]
	ldr r0, _0817EBE4 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r0, r1, r0
	b _0817EBEE
	.align 2, 0
_0817EBE0: .4byte 0x00000256
_0817EBE4: .4byte 0x030046A4
_0817EBE8:
	ldr r1, _0817EBF8 @ =0x00000256
	adds r0, r3, r1
	ldrh r0, [r0]
_0817EBEE:
	cmp r2, r0
	beq _0817EBFC
	movs r0, #0
	b _0817EBFE
	.align 2, 0
_0817EBF8: .4byte 0x00000256
_0817EBFC:
	movs r0, #1
_0817EBFE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0817ec04
FUN_0817ec04: @ 0x0817EC04
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r7, r1, #0
	ldr r1, _0817EC2C @ =0x000004A4
	adds r0, r5, r1
	ldr r4, [r0]
	adds r6, r5, #0
	adds r6, #8
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0817EC30
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	b _0817EC54
	.align 2, 0
_0817EC2C: .4byte 0x000004A4
_0817EC30:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0817EC4E
	cmp r0, #2
	beq _0817EC5C
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _0817EC5C
_0817EC4E:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
_0817EC54:
	ldr r1, _0817ECA4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_0817EC5C:
	adds r0, r5, #0
	bl FUN_0817ce48
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r3, _0817ECA8 @ =0x000004A4
	adds r0, r5, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r5, #8]
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
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817ECA4: .4byte 0xFFFFFDFF
_0817ECA8: .4byte 0x000004A4

	thumb_func_start FUN_0817ecac
FUN_0817ecac: @ 0x0817ECAC
	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r0, _0817ECC8 @ =0x0000089E
	adds r2, r3, r0
	ldrb r0, [r2]
	adds r1, r0, #0
	cmp r1, #0
	beq _0817ECCC
	subs r0, #1
	strb r0, [r2]
	b _0817ECD4
	.align 2, 0
_0817ECC8: .4byte 0x0000089E
_0817ECCC:
	strb r1, [r2]
	ldr r2, _0817ECD8 @ =0x0000089D
	adds r0, r3, r2
	strb r1, [r0]
_0817ECD4:
	pop {r0}
	bx r0
	.align 2, 0
_0817ECD8: .4byte 0x0000089D

	thumb_func_start FUN_0817ecdc
FUN_0817ecdc: @ 0x0817ECDC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _0817EE40 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	mov r8, r3
	orrs r0, r3
	ldr r1, _0817EE44 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	add r7, sp, #0xc
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r3, _0817EE48 @ =FUN_0817eff4
	str r5, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_080e3834
	movs r1, #0x40
	add r0, sp, #0xc
	strh r1, [r0]
	movs r0, #0x64
	strh r0, [r7, #2]
	strh r1, [r7, #4]
	movs r0, #0
	strh r0, [r4]
	mov r1, r8
	strh r1, [r4, #2]
	strh r0, [r4, #4]
	movs r2, #0
	str r2, [sp]
	str r5, [sp, #4]
	adds r0, r5, #0
	add r1, sp, #0xc
	adds r2, r4, #0
	ldr r3, _0817EE4C @ =FUN_0817efb4
	bl FUN_080e3984
	add r0, sp, #0xc
	mov r3, r8
	strh r3, [r0]
	strh r3, [r7, #2]
	strh r3, [r7, #4]
	movs r0, #0
	strh r0, [r4]
	strh r3, [r4, #2]
	strh r0, [r4, #4]
	ldr r1, _0817EE50 @ =0x000007B4
	add r1, sl
	mov sb, r1
	ldr r2, _0817EE54 @ =0x00002101
	movs r3, #0x10
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r4, [sp, #8]
	mov r0, sb
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _0817EE58 @ =0x0000022A
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _0817EE5C @ =0x00000232
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #0xe
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	mov r0, sb
	movs r3, #0
	bl FUN_082364f8
	adds r6, r5, #0
	adds r6, #8
	mov r0, sb
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0817EE60 @ =FUN_0817eeb0
	mov r0, sb
	adds r2, r5, #0
	bl FUN_0823651c
	movs r1, #0x96
	lsls r1, r1, #1
	add r0, sp, #0xc
	strh r1, [r0]
	mov r0, r8
	strh r0, [r7, #2]
	strh r1, [r7, #4]
	movs r1, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	strh r1, [r4, #4]
	ldr r2, _0817EE64 @ =0x00000804
	add sl, r2
	ldr r2, _0817EE68 @ =0x00002001
	movs r3, #0x10
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r4, [sp, #8]
	mov r0, sl
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x91
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #0xc
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	mov r0, sl
	movs r3, #0
	bl FUN_082364f8
	mov r0, sl
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	mov r0, sl
	ldr r1, _0817EE4C @ =FUN_0817efb4
	adds r2, r5, #0
	bl FUN_0823651c
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817EE40: .4byte 0xFFFF0000
_0817EE44: .4byte 0x0000FFFF
_0817EE48: .4byte FUN_0817eff4
_0817EE4C: .4byte FUN_0817efb4
_0817EE50: .4byte 0x000007B4
_0817EE54: .4byte 0x00002101
_0817EE58: .4byte 0x0000022A
_0817EE5C: .4byte 0x00000232
_0817EE60: .4byte FUN_0817eeb0
_0817EE64: .4byte 0x00000804
_0817EE68: .4byte 0x00002001

	thumb_func_start FUN_0817ee6c
FUN_0817ee6c: @ 0x0817EE6C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0817c068
	adds r0, r4, #0
	bl FUN_0817b9e8
	adds r0, r4, #0
	bl FUN_0817d85c
	adds r0, r4, #0
	bl FUN_0817e5dc
	adds r0, r4, #0
	bl FUN_0817ecac
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0817ee94
FUN_0817ee94: @ 0x0817EE94
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0817da34
	adds r0, r4, #0
	bl FUN_0817da80
	adds r0, r4, #0
	bl FUN_0817deb8
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0817eeb0
FUN_0817eeb0: @ 0x0817EEB0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817EFA2
	ldr r0, [r7, #0x24]
	ldr r1, [r7, #0x28]
	str r0, [sp]
	str r1, [sp, #4]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _0817EEFC
	cmp r0, #1
	bgt _0817EEE6
	cmp r0, #0
	beq _0817EEF0
	b _0817EF40
_0817EEE6:
	cmp r0, #2
	beq _0817EF08
	cmp r0, #3
	beq _0817EF28
	b _0817EF40
_0817EEF0:
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _0817EEF8 @ =0xFFFFFF00
	b _0817EF10
	.align 2, 0
_0817EEF8: .4byte 0xFFFFFF00
_0817EEFC:
	mov r0, sp
	ldrh r1, [r0, #4]
	ldr r3, _0817EF04 @ =0xFFFFFF00
	b _0817EF30
	.align 2, 0
_0817EF04: .4byte 0xFFFFFF00
_0817EF08:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
_0817EF10:
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0817EF24 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	b _0817EF40
	.align 2, 0
_0817EF24: .4byte 0xFFFF0000
_0817EF28:
	mov r0, sp
	ldrh r1, [r0, #4]
	movs r3, #0x80
	lsls r3, r3, #1
_0817EF30:
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0817EFAC @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
_0817EF40:
	add r2, sp, #8
	mov r4, sp
	adds r3, r6, #0
	adds r3, #0x24
	ldrh r0, [r6, #0x24]
	mov r1, sp
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	adds r1, r7, #0
	adds r1, #0x42
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817EFA2
	ldrh r1, [r6, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0817EFA2
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _0817EFB0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0817EFA2:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817EFAC: .4byte 0xFFFF0000
_0817EFB0: .4byte 0xFEFFFFFF

	thumb_func_start FUN_0817efb4
FUN_0817efb4: @ 0x0817EFB4
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817EFE8
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0817EFE8
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _0817EFF0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0817EFE8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0817EFF0: .4byte 0xFEFFFFFF

	thumb_func_start FUN_0817eff4
FUN_0817eff4: @ 0x0817EFF4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	mov sb, r1
	adds r7, r2, #0
	adds r6, r7, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #8]
	adds r0, r7, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817F022
	bl _0817FA86
_0817F022:
	adds r0, r7, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0817F032
	b _0817F6D0
_0817F032:
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0817F05C
	ldr r3, _0817F058 @ =0x0000048C
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817F04A
	b _0817F6D0
_0817F04A:
	movs r0, #0
	mov r4, sb
	strh r1, [r4, #0x3e]
	mov r1, sb
	adds r1, #0x43
	strb r0, [r1]
	b _0817F6D0
	.align 2, 0
_0817F058: .4byte 0x0000048C
_0817F05C:
	adds r0, r7, #0
	adds r0, #0xd8
	movs r5, #4
	mov sl, r5
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _0817F06E
	b _0817F6D0
_0817F06E:
	movs r5, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r5
	cmp r0, #0
	beq _0817F07E
	b _0817F398
_0817F07E:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov ip, r1
	cmp r0, #0
	bne _0817F090
	b _0817F6D0
_0817F090:
	ldr r1, _0817F120 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r4, r7, r0
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0817F0A2
	b _0817F6D0
_0817F0A2:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0817F0B0
	b _0817F6D0
_0817F0B0:
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _0817F0C8
	b _0817F218
_0817F0C8:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, sb
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _0817F130
	ands r3, r1
	cmp r3, #0
	beq _0817F130
	mov r0, sb
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0817F0F0
	rsbs r1, r1, #0
_0817F0F0:
	cmp r1, #0x20
	bgt _0817F130
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r2, _0817F124 @ =0x000004BE
	adds r1, r7, r2
	strh r0, [r1]
	ldr r3, _0817F128 @ =0x0000048C
	adds r0, r7, r3
	strb r5, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r5, _0817F12C @ =0x0000044E
	adds r1, r7, r5
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _0817F6D0
	.align 2, 0
_0817F120: .4byte 0x0000A007
_0817F124: .4byte 0x000004BE
_0817F128: .4byte 0x0000048C
_0817F12C: .4byte 0x0000044E
_0817F130:
	movs r1, #0
	mov r0, sb
	strh r1, [r0, #0x3e]
	ldr r2, _0817F15C @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0817F164
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0817F160 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0817F1D2
	.align 2, 0
_0817F15C: .4byte 0x0000048A
_0817F160: .4byte 0x03002BE0
_0817F164:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0817F180
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0817F17C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0817F1D2
	.align 2, 0
_0817F17C: .4byte 0x03002BE0
_0817F180:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0817F19C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0817F198 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0817F1D2
	.align 2, 0
_0817F198: .4byte 0x03002BE0
_0817F19C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0817F1B8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0817F1B4 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0817F1D2
	.align 2, 0
_0817F1B4: .4byte 0x03002BE0
_0817F1B8:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0817F1CA
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _0817F1D2
_0817F1CA:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0817F1D4
_0817F1D2:
	movs r3, #1
_0817F1D4:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	mov r5, ip
	str r5, [r0]
	ldr r2, _0817F208 @ =0x0000049C
	adds r0, r6, r2
	str r1, [r0]
	cmp r3, #0
	bne _0817F1F6
	b _0817F358
_0817F1F6:
	movs r1, #2
	ldr r3, _0817F20C @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817F210
	movs r0, #1
	b _0817F212
	.align 2, 0
_0817F208: .4byte 0x0000049C
_0817F20C: .4byte 0x00000474
_0817F210:
	movs r0, #0
_0817F212:
	cmp r0, #0
	bne _0817F2FE
	b _0817F314
_0817F218:
	mov r0, sb
	strh r2, [r0, #0x3e]
	ldr r1, _0817F240 @ =0x0000048A
	adds r0, r7, r1
	strh r2, [r0]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _0817F248
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, _0817F244 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0817F2BA
	.align 2, 0
_0817F240: .4byte 0x0000048A
_0817F244: .4byte 0x03002BE0
_0817F248:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0817F264
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _0817F260 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0817F2BA
	.align 2, 0
_0817F260: .4byte 0x03002BE0
_0817F264:
	adds r0, r2, #0
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _0817F284
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, _0817F280 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0817F2BA
	.align 2, 0
_0817F280: .4byte 0x03002BE0
_0817F284:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0817F2A0
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, _0817F29C @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0817F2BA
	.align 2, 0
_0817F29C: .4byte 0x03002BE0
_0817F2A0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0817F2B2
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	str r3, [r0]
	b _0817F2BA
_0817F2B2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0817F2BC
_0817F2BA:
	movs r3, #1
_0817F2BC:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	mov r5, ip
	str r5, [r0]
	ldr r2, _0817F2F0 @ =0x0000049C
	adds r0, r6, r2
	str r1, [r0]
	cmp r3, #0
	beq _0817F358
	movs r1, #2
	ldr r3, _0817F2F4 @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817F2F8
	movs r0, #1
	b _0817F2FA
	.align 2, 0
_0817F2F0: .4byte 0x0000049C
_0817F2F4: .4byte 0x00000474
_0817F2F8:
	movs r0, #0
_0817F2FA:
	cmp r0, #0
	beq _0817F314
_0817F2FE:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0817F310 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0817F320
	.align 2, 0
_0817F310: .4byte 0x03002BE0
_0817F314:
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _0817F358
_0817F320:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0817F358:
	movs r1, #0x80
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r6, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817F386
	ldr r5, _0817F390 @ =0x0000024E
	adds r2, r6, r5
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	adds r4, #0xcc
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0817F386
	strh r1, [r2]
_0817F386:
	ldr r5, _0817F394 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _0817F6D0
	.align 2, 0
_0817F390: .4byte 0x0000024E
_0817F394: .4byte 0x0000048C
_0817F398:
	ldr r0, _0817F3AC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0817F3B0
	movs r0, #1
	b _0817F3B2
	.align 2, 0
_0817F3AC: .4byte 0x030047A4
_0817F3B0:
	movs r0, #0
_0817F3B2:
	cmp r0, #0
	beq _0817F3C0
	mov r0, r8
	mov r1, sb
	bl FUN_08236640
	b _0817F3C8
_0817F3C0:
	mov r0, r8
	mov r1, sb
	bl FUN_08236524
_0817F3C8:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, sb
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0817F400 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0817F404 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #0x14]
	cmp r0, #2
	bls _0817F3F6
	cmp r2, #0x17
	bne _0817F408
_0817F3F6:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _0817F42A
	.align 2, 0
_0817F400: .4byte 0x0000048C
_0817F404: .4byte 0x000001DF
_0817F408:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0817F3F6
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _0817F458 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0817F42A
	movs r1, #0
_0817F42A:
	mov r0, sb
	adds r0, #0x40
	strh r1, [r0]
	mov sl, r0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0x18]
	cmp r0, #0
	beq _0817F466
	mov r1, sb
	ldrh r0, [r1, #0x3e]
	lsls r0, r0, #1
	strh r0, [r1, #0x3e]
	mov r2, sl
	ldrh r0, [r2]
	cmp r0, #0
	blt _0817F45C
	asrs r0, r0, #1
	b _0817F462
	.align 2, 0
_0817F458: .4byte 0x00000187
_0817F45C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0817F462:
	mov r3, sl
	strh r0, [r3]
_0817F466:
	mov r4, r8
	ldrh r1, [r4, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0817F484
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r5, _0817F480 @ =0x000001DD
	adds r1, r6, r5
	b _0817F4FC
	.align 2, 0
_0817F480: .4byte 0x000001DD
_0817F484:
	mov r4, sp
	mov r3, r8
	adds r3, #0xc
	mov r2, sb
	adds r2, #0xc
	mov r1, sb
	ldrh r0, [r1, #0xc]
	mov r5, r8
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _0817F4E8
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _0817F4E8
	ldr r2, _0817F4D8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0817F4DC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0817F4E0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _0817F4E4 @ =0x000001DD
	adds r1, r6, r4
	b _0817F4FC
	.align 2, 0
_0817F4D8: .4byte 0x030046B8
_0817F4DC: .4byte 0x000003FF
_0817F4E0: .4byte 0x0203B400
_0817F4E4: .4byte 0x000001DD
_0817F4E8:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _0817F51C @ =0x000001DD
	adds r1, r6, r3
_0817F4FC:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0817F524
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0817F520 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0817F592
	.align 2, 0
_0817F51C: .4byte 0x000001DD
_0817F520: .4byte 0x03002BE0
_0817F524:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0817F540
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0817F53C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0817F592
	.align 2, 0
_0817F53C: .4byte 0x03002BE0
_0817F540:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0817F55C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0817F558 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0817F592
	.align 2, 0
_0817F558: .4byte 0x03002BE0
_0817F55C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0817F578
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0817F574 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0817F592
	.align 2, 0
_0817F574: .4byte 0x03002BE0
_0817F578:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0817F58A
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _0817F592
_0817F58A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0817F594
_0817F592:
	movs r3, #1
_0817F594:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _0817F5C8 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0817F630
	movs r1, #2
	ldr r2, _0817F5CC @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817F5D0
	movs r0, #1
	b _0817F5D2
	.align 2, 0
_0817F5C8: .4byte 0x0000049C
_0817F5CC: .4byte 0x00000474
_0817F5D0:
	movs r0, #0
_0817F5D2:
	cmp r0, #0
	beq _0817F5EC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0817F5E8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0817F5F8
	.align 2, 0
_0817F5E8: .4byte 0x03002BE0
_0817F5EC:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0817F630
_0817F5F8:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0817F630:
	ldr r4, [sp, #0x14]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0817F664
	movs r1, #0x80
	ldr r5, [sp, #0x18]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0817F664
	ldr r0, _0817F67C @ =0x0000024E
	adds r2, r6, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0817F664
	strh r1, [r2]
_0817F664:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0817F680 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _0817F684 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817F688
	movs r0, #1
	b _0817F68A
	.align 2, 0
_0817F67C: .4byte 0x0000024E
_0817F680: .4byte 0x030046A0
_0817F684: .4byte 0x00000934
_0817F688:
	movs r0, #0
_0817F68A:
	ldr r1, _0817F708 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0817F6A4
	movs r0, #0
	mov r2, sb
	strh r0, [r2, #0x3e]
	mov r3, sl
	strh r0, [r3]
	strh r0, [r4]
	movs r0, #1
	ldr r5, [sp, #0x14]
	strb r0, [r5]
_0817F6A4:
	adds r0, r6, #0
	bl FUN_080e64e4
	mov r1, sb
	ldrh r0, [r1, #0x3e]
	strh r0, [r4]
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r1, r6, r2
	mov r3, r8
	ldrh r0, [r3, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r3, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0817F6D0:
	ldr r5, _0817F708 @ =0x0000048A
	adds r0, r7, r5
	ldrh r0, [r0]
	cmp r0, #0
	bne _0817F6DC
	b _0817FA86
_0817F6DC:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817F6F0
	b _0817FA86
_0817F6F0:
	movs r2, #1
	ldr r3, [sp, #8]
	ldr r4, _0817F70C @ =0x00000898
	adds r1, r3, r4
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _0817F710
	movs r0, #1
	b _0817F712
	.align 2, 0
_0817F708: .4byte 0x0000048A
_0817F70C: .4byte 0x00000898
_0817F710:
	movs r0, #0
_0817F712:
	cmp r0, #0
	bne _0817F718
	b _0817FA86
_0817F718:
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0817F728
	movs r0, #1
	b _0817F72A
_0817F728:
	movs r0, #0
_0817F72A:
	adds r1, r0, #0
	cmp r1, #0
	beq _0817F732
	b _0817FA86
_0817F732:
	movs r5, #0x93
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r2, [r0]
	movs r0, #0x1f
	ands r0, r2
	cmp r0, #0
	beq _0817F750
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	ble _0817F760
_0817F750:
	ldr r2, [sp, #8]
	ldr r3, _0817F75C @ =0x0000089C
	adds r0, r2, r3
	strb r1, [r0]
	b _0817F798
	.align 2, 0
_0817F75C: .4byte 0x0000089C
_0817F760:
	ldr r5, [sp, #8]
	ldr r3, _0817F778 @ =0x00000894
	adds r0, r5, r3
	ldr r0, [r0]
	cmp r2, r0
	bne _0817F780
	ldr r0, _0817F77C @ =0x0000089C
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0817F788
	.align 2, 0
_0817F778: .4byte 0x00000894
_0817F77C: .4byte 0x0000089C
_0817F780:
	ldr r2, [sp, #8]
	ldr r3, _0817F7CC @ =0x0000089C
	adds r0, r2, r3
	strb r1, [r0]
_0817F788:
	ldr r5, [sp, #8]
	ldr r1, _0817F7D0 @ =0x00000894
	adds r0, r5, r1
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r1, [r1]
	str r1, [r0]
_0817F798:
	ldr r3, [sp, #8]
	ldr r5, _0817F7CC @ =0x0000089C
	adds r0, r3, r5
	ldrb r1, [r0]
	cmp r1, #0x1b
	bhi _0817F7A6
	b _0817F9E6
_0817F7A6:
	movs r1, #0
	strb r1, [r0]
	movs r2, #0
	mov r0, sb
	strh r1, [r0, #0x3e]
	ldr r3, _0817F7D4 @ =0x0000048C
	adds r0, r7, r3
	strb r2, [r0]
	mov r0, sb
	adds r0, #0x44
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0817F7D8
	movs r0, #1
	b _0817F7DA
	.align 2, 0
_0817F7CC: .4byte 0x0000089C
_0817F7D0: .4byte 0x00000894
_0817F7D4: .4byte 0x0000048C
_0817F7D8:
	movs r0, #0
_0817F7DA:
	cmp r0, #0
	bne _0817F7EC
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
_0817F7EC:
	movs r4, #0xf2
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldr r0, _0817F81C @ =0x00018FFF
	cmp r1, r0
	bhi _0817F828
	movs r1, #2
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0817F820 @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r4, _0817F824 @ =0x0000046A
	adds r0, r7, r4
	strb r1, [r0]
	adds r5, #0x1c
	adds r0, r7, r5
	str r2, [r0]
	b _0817F858
	.align 2, 0
_0817F81C: .4byte 0x00018FFF
_0817F820: .4byte 0x00000469
_0817F824: .4byte 0x0000046A
_0817F828:
	ldr r0, _0817F864 @ =0x0003FFFF
	cmp r1, r0
	bhi _0817F878
	adds r0, r7, #0
	bl FUN_0817ea84
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817F878
	movs r2, #2
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0817F868 @ =0x00000469
	adds r0, r7, r3
	strb r2, [r0]
	ldr r4, _0817F86C @ =0x0000046A
	adds r0, r7, r4
	strb r1, [r0]
	ldr r5, _0817F870 @ =0x00000484
	adds r0, r7, r5
	str r1, [r0]
_0817F858:
	ldr r0, _0817F874 @ =0x0000046C
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	b _0817FA86
	.align 2, 0
_0817F864: .4byte 0x0003FFFF
_0817F868: .4byte 0x00000469
_0817F86C: .4byte 0x0000046A
_0817F870: .4byte 0x00000484
_0817F874: .4byte 0x0000046C
_0817F878:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldr r0, _0817F8A0 @ =0x000FFFFF
	cmp r1, r0
	bls _0817F888
	b _0817FA86
_0817F888:
	ldrb r0, [r7, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	lsrs r5, r0, #6
	cmp r5, #1
	beq _0817F8BC
	cmp r5, #1
	bgt _0817F8A4
	cmp r5, #0
	beq _0817F8AE
	b _0817F904
	.align 2, 0
_0817F8A0: .4byte 0x000FFFFF
_0817F8A4:
	cmp r5, #2
	beq _0817F8D8
	cmp r5, #3
	beq _0817F8E8
	b _0817F904
_0817F8AE:
	ldr r2, _0817F8B8 @ =0x00000256
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r4, r0, #1
	b _0817F90A
	.align 2, 0
_0817F8B8: .4byte 0x00000256
_0817F8BC:
	ldr r3, _0817F8D0 @ =0x00000256
	adds r1, r7, r3
	ldr r0, _0817F8D4 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	ldrh r1, [r1]
	adds r4, r0, r1
	b _0817F90A
	.align 2, 0
_0817F8D0: .4byte 0x00000256
_0817F8D4: .4byte 0x030046A4
_0817F8D8:
	ldr r1, _0817F8E4 @ =0x00000256
	adds r0, r7, r1
	ldrh r0, [r0]
	subs r4, r0, #1
	b _0817F90A
	.align 2, 0
_0817F8E4: .4byte 0x00000256
_0817F8E8:
	ldr r2, _0817F8FC @ =0x00000256
	adds r0, r7, r2
	ldrh r1, [r0]
	ldr r0, _0817F900 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r4, r1, r0
	b _0817F90A
	.align 2, 0
_0817F8FC: .4byte 0x00000256
_0817F900: .4byte 0x030046A4
_0817F904:
	ldr r4, _0817F91C @ =0x00000256
	adds r0, r7, r4
	ldrh r4, [r0]
_0817F90A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0817F920
	adds r0, #4
	b _0817F92C
	.align 2, 0
_0817F91C: .4byte 0x00000256
_0817F920:
	ldr r0, _0817F988 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817F92C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #0xa
	ldrsh r0, [r7, r2]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r3, r7
	mov sb, r3
	ldr r4, _0817F98C @ =0x00000469
	adds r4, r4, r7
	mov sl, r4
	ldr r2, _0817F990 @ =0x0000046A
	adds r2, r2, r7
	mov ip, r2
	ldr r3, _0817F994 @ =0x00000484
	adds r3, r7, r3
	str r3, [sp, #0x10]
	ldr r4, _0817F998 @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0xc]
	cmp r0, r1
	bge _0817F9CA
	ldr r6, _0817F99C @ =0x7FFFFFFF
	adds r2, r5, #0
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
	movs r4, #3
	adds r1, r2, #1
	movs r0, #0x80
	rsbs r0, r0, #0
	mov r8, r0
	movs r3, #2
_0817F976:
	adds r0, r1, #0
	ands r0, r4
	lsls r0, r0, #6
	ldr r5, [sp, #0x1c]
	subs r0, r5, r0
	cmp r0, #0x80
	ble _0817F9A4
	ldr r5, _0817F9A0 @ =0xFFFFFF00
	b _0817F9AC
	.align 2, 0
_0817F988: .4byte 0x030046A4
_0817F98C: .4byte 0x00000469
_0817F990: .4byte 0x0000046A
_0817F994: .4byte 0x00000484
_0817F998: .4byte 0x0000046C
_0817F99C: .4byte 0x7FFFFFFF
_0817F9A0: .4byte 0xFFFFFF00
_0817F9A4:
	cmp r0, r8
	bge _0817F9AE
	movs r5, #0x80
	lsls r5, r5, #1
_0817F9AC:
	adds r0, r0, r5
_0817F9AE:
	cmp r0, #0
	bge _0817F9B4
	rsbs r0, r0, #0
_0817F9B4:
	cmp r0, r6
	bge _0817F9BE
	adds r6, r0, #0
	adds r2, r1, #0
	ands r2, r4
_0817F9BE:
	adds r1, #1
	subs r3, #1
	cmp r3, #0
	bge _0817F976
	lsls r0, r2, #6
	strb r0, [r7, #5]
_0817F9CA:
	movs r0, #2
	movs r2, #1
	movs r1, #0
	mov r3, sb
	strb r1, [r3]
	mov r4, sl
	strb r0, [r4]
	mov r5, ip
	strb r2, [r5]
	ldr r0, [sp, #0x10]
	str r1, [r0]
	ldr r1, [sp, #0xc]
	strb r2, [r1]
	b _0817FA86
_0817F9E6:
	cmp r1, #1
	bls _0817FA86
	cmp r1, #2
	bne _0817F9F4
	ldr r0, _0817FA18 @ =0x000002D3
	bl PlaySound_082406e0
_0817F9F4:
	movs r2, #0
	movs r1, #0
	mov r3, sb
	strh r1, [r3, #0x3e]
	ldr r5, _0817FA1C @ =0x0000048C
	adds r0, r7, r5
	strb r2, [r0]
	mov r0, sb
	adds r0, #0x44
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0817FA20
	movs r0, #1
	b _0817FA22
	.align 2, 0
_0817FA18: .4byte 0x000002D3
_0817FA1C: .4byte 0x0000048C
_0817FA20:
	movs r0, #0
_0817FA22:
	cmp r0, #0
	bne _0817FA34
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
_0817FA34:
	adds r0, r7, #0
	bl FUN_0817dd08
	movs r1, #0x12
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0817FA98 @ =0x00000469
	adds r0, r7, r3
	strb r2, [r0]
	ldr r4, _0817FA9C @ =0x0000046A
	adds r0, r7, r4
	strb r1, [r0]
	ldr r5, _0817FAA0 @ =0x00000484
	adds r0, r7, r5
	str r2, [r0]
	ldr r1, _0817FAA4 @ =0x0000046C
	adds r0, r7, r1
	movs r1, #1
	strb r1, [r0]
	ldr r4, _0817FAA8 @ =FUN_080e48d0
	movs r3, #0x10
	subs r5, #0x17
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _0817FAAC @ =0x0000046B
	adds r0, r7, r1
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
_0817FA86:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817FA98: .4byte 0x00000469
_0817FA9C: .4byte 0x0000046A
_0817FAA0: .4byte 0x00000484
_0817FAA4: .4byte 0x0000046C
_0817FAA8: .4byte FUN_080e48d0
_0817FAAC: .4byte 0x0000046B

	thumb_func_start FUN_0817fab0
FUN_0817fab0: @ 0x0817FAB0
	push {lr}
	ldr r2, _0817FAC4 @ =0x0000046D
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817FAC0
	movs r0, #0
	strb r0, [r1]
_0817FAC0:
	pop {r0}
	bx r0
	.align 2, 0
_0817FAC4: .4byte 0x0000046D

	thumb_func_start FUN_0817fac8
FUN_0817fac8: @ 0x0817FAC8
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r0, _0817FAF0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817FAF4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817FAF6
	.align 2, 0
_0817FAF0: .4byte 0x0000046D
_0817FAF4:
	movs r0, #0
_0817FAF6:
	cmp r0, #0
	beq _0817FB02
	adds r0, r5, #0
	movs r1, #0x11
	bl FUN_080ef86c
_0817FB02:
	ldrh r0, [r4, #0x14]
	cmp r0, #2
	bne _0817FB1E
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne _0817FB1E
	movs r0, #0xf4
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #0xb4
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0817FB1E:
	ldrh r0, [r4, #0x14]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _0817FBB2
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _0817FB5E
	cmp r0, #1
	bgt _0817FB4A
	cmp r0, #0
	beq _0817FB54
	b _0817FB9E
_0817FB4A:
	cmp r0, #2
	beq _0817FB68
	cmp r0, #3
	beq _0817FB88
	b _0817FB9E
_0817FB54:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817FB6E
_0817FB5E:
	mov r0, sp
	ldrh r1, [r0, #4]
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817FB8E
_0817FB68:
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _0817FB80 @ =0xFFFFFF00
_0817FB6E:
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0817FB84 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	b _0817FB9E
	.align 2, 0
_0817FB80: .4byte 0xFFFFFF00
_0817FB84: .4byte 0xFFFF0000
_0817FB88:
	mov r0, sp
	ldrh r1, [r0, #4]
	ldr r0, _0817FBCC @ =0xFFFFFF00
_0817FB8E:
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0817FBD0 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
_0817FB9E:
	ldr r1, _0817FBD4 @ =0x000007B4
	adds r4, r6, r1
	adds r0, r4, #0
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_0817FBB2:
	ldr r1, _0817FBD8 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0817FBC4
	ldr r0, _0817FBDC @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0817FBC4:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0817FBCC: .4byte 0xFFFFFF00
_0817FBD0: .4byte 0xFFFF0000
_0817FBD4: .4byte 0x000007B4
_0817FBD8: .4byte 0x0000046E
_0817FBDC: .4byte 0x0000046B

	thumb_func_start FUN_0817fbe0
FUN_0817fbe0: @ 0x0817FBE0
	push {lr}
	adds r2, r0, #0
	ldr r0, _0817FBF8 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817FBFC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817FBFE
	.align 2, 0
_0817FBF8: .4byte 0x0000046D
_0817FBFC:
	movs r0, #0
_0817FBFE:
	cmp r0, #0
	beq _0817FC12
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, _0817FC20 @ =0x0000089C
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
_0817FC12:
	adds r0, r2, #0
	movs r1, #0x16
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_0817FC20: .4byte 0x0000089C

	thumb_func_start FUN_0817fc24
FUN_0817fc24: @ 0x0817FC24
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0817FC3C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817FC40
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817FC42
	.align 2, 0
_0817FC3C: .4byte 0x0000046D
_0817FC40:
	movs r0, #0
_0817FC42:
	cmp r0, #0
	beq _0817FC6E
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	ldr r1, _0817FC7C @ =0x0000089C
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0x9e
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _0817FC80 @ =0x000001DF
	adds r0, r4, r1
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #3
	movs r2, #2
	bl FUN_080e5718
_0817FC6E:
	adds r0, r4, #0
	movs r1, #0x17
	bl FUN_080ef86c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0817FC7C: .4byte 0x0000089C
_0817FC80: .4byte 0x000001DF

	thumb_func_start FUN_0817fc84
FUN_0817fc84: @ 0x0817FC84
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _0817FCE8 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817FC9C
	movs r0, #0
	strb r0, [r1]
_0817FC9C:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0817ce18
	movs r2, #0x98
	lsls r2, r2, #3
	adds r1, r5, r2
	adds r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	ldr r4, [sp, #8]
	ldrb r2, [r1]
	ldr r3, [sp, #4]
	orrs r4, r0
	ldr r1, _0817FCEC @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817FCF8
	ldr r1, _0817FCF0 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r2, _0817FCF4 @ =0x0000046E
	adds r7, r5, r2
	b _0817FD7A
	.align 2, 0
_0817FCE8: .4byte 0x0000046D
_0817FCEC: .4byte 0x0000025D
_0817FCF0: .4byte 0x000004B7
_0817FCF4: .4byte 0x0000046E
_0817FCF8:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0817FD68 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0817FD6C @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0817FD32
	ldrb r0, [r7]
	cmp r0, #0
	bne _0817FD32
	cmp r4, #1
	bne _0817FD24
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0817FD7E
_0817FD24:
	cmp r4, #0
	bne _0817FD32
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0817FD7E
_0817FD32:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0817FD44
	movs r3, #6
_0817FD44:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0817FD70
	ldr r0, [r6, #8]
	mov r2, r8
	orrs r0, r2
	b _0817FD78
	.align 2, 0
_0817FD68: .4byte 0x000004B7
_0817FD6C: .4byte 0x0000046E
_0817FD70:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0817FD78:
	str r0, [r6, #8]
_0817FD7A:
	movs r0, #0
	strb r0, [r7]
_0817FD7E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0817fd8c
FUN_0817fd8c: @ 0x0817FD8C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _0817FDAC @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817FDB0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817FDB2
	.align 2, 0
_0817FDAC: .4byte 0x0000046D
_0817FDB0:
	movs r0, #0
_0817FDB2:
	cmp r0, #0
	bne _0817FDB8
	b _0817FECA
_0817FDB8:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r5, #5]
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0817ce18
	movs r0, #0x9f
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r2, _0817FE18 @ =0x000004F9
	adds r0, r5, r2
	ldrb r0, [r0]
	ldr r4, [sp, #8]
	ldrb r2, [r1]
	ldr r3, [sp, #4]
	orrs r4, r0
	ldr r1, _0817FE1C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817FE28
	ldr r1, _0817FE20 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r2, _0817FE24 @ =0x0000046E
	adds r7, r5, r2
	b _0817FEAA
	.align 2, 0
_0817FE18: .4byte 0x000004F9
_0817FE1C: .4byte 0x0000025D
_0817FE20: .4byte 0x000004B7
_0817FE24: .4byte 0x0000046E
_0817FE28:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0817FE98 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0817FE9C @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0817FE62
	ldrb r0, [r7]
	cmp r0, #0
	bne _0817FE62
	cmp r4, #1
	bne _0817FE54
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0817FEAE
_0817FE54:
	cmp r4, #0
	bne _0817FE62
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0817FEAE
_0817FE62:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0817FE74
	movs r3, #6
_0817FE74:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0817FEA0
	ldr r0, [r6, #8]
	mov r2, r8
	orrs r0, r2
	b _0817FEA8
	.align 2, 0
_0817FE98: .4byte 0x000004B7
_0817FE9C: .4byte 0x0000046E
_0817FEA0:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0817FEA8:
	str r0, [r6, #8]
_0817FEAA:
	movs r0, #0
	strb r0, [r7]
_0817FEAE:
	ldr r4, _0817FED8 @ =0x000008B7
	add r4, sb
	ldrb r0, [r4]
	cmp r0, #0
	bne _0817FEC2
	ldr r0, _0817FEDC @ =0x000003CE
	bl PlaySound_082406e0
	movs r0, #0xa
	strb r0, [r4]
_0817FEC2:
	ldr r1, _0817FEE0 @ =0x000008B6
	add r1, sb
	movs r0, #0x1e
	strb r0, [r1]
_0817FECA:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817FED8: .4byte 0x000008B7
_0817FEDC: .4byte 0x000003CE
_0817FEE0: .4byte 0x000008B6

	thumb_func_start FUN_0817fee4
FUN_0817fee4: @ 0x0817FEE4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldr r0, [r7, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r2, _0817FF14 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817FF18
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817FF1A
	.align 2, 0
_0817FF14: .4byte 0x0000046D
_0817FF18:
	movs r0, #0
_0817FF1A:
	cmp r0, #0
	beq _0817FF3A
	ldrb r0, [r7, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0xf
	bl FUN_080ef86c
	ldr r0, _0817FF7C @ =0x000003D1
	bl PlaySound_082406e0
_0817FF3A:
	ldrh r0, [r4, #0x14]
	cmp r0, #4
	beq _0817FF42
	b _081801FA
_0817FF42:
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	beq _0817FF4A
	b _081801FA
_0817FF4A:
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	ldr r1, [sp, #0x1c]
	asrs r0, r1, #0x10
	adds r0, #0xdc
	lsls r0, r0, #0x10
	ldr r3, _0817FF80 @ =0x0000FFFF
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #0x1c]
	ldrb r0, [r7, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _0817FFB0
	cmp r0, #1
	bgt _0817FF84
	cmp r0, #0
	beq _0817FF8E
	b _08180012
	.align 2, 0
_0817FF7C: .4byte 0x000003D1
_0817FF80: .4byte 0x0000FFFF
_0817FF84:
	cmp r0, #2
	beq _0817FFDC
	cmp r0, #3
	beq _0817FFFC
	b _08180012
_0817FF8E:
	add r0, sp, #0x1c
	ldrh r1, [r0]
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0817FFAC @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldrh r0, [r0, #4]
	subs r0, #0x30
	b _0817FFCA
	.align 2, 0
_0817FFAC: .4byte 0xFFFF0000
_0817FFB0:
	add r0, sp, #0x1c
	ldrh r1, [r0]
	subs r1, #0x40
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0817FFD8 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldrh r0, [r0, #4]
	adds r0, #0x80
_0817FFCA:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x20]
	b _08180012
	.align 2, 0
_0817FFD8: .4byte 0xFFFF0000
_0817FFDC:
	add r0, sp, #0x1c
	ldrh r0, [r0]
	ldr r1, _0817FFF4 @ =0xFFFFFF00
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0817FFF8 @ =0xFFFF0000
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x1c]
	b _08180012
	.align 2, 0
_0817FFF4: .4byte 0xFFFFFF00
_0817FFF8: .4byte 0xFFFF0000
_0817FFFC:
	add r0, sp, #0x1c
	ldrh r1, [r0, #4]
	ldr r2, _081800A8 @ =0xFFFFFF00
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081800AC @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
_08180012:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _081800B0 @ =0x00000546
	adds r0, r7, r2
	movs r2, #2
	str r2, [sp, #0x28]
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0818002E
	movs r0, #6
	str r0, [sp, #0x28]
_0818002E:
	adds r0, r7, #0
	bl FUN_0817ea84
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081800C0
	ldrb r1, [r7, #5]
	subs r1, #4
	movs r2, #8
	str r2, [sp]
	movs r0, #0x12
	mov sb, r0
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldr r2, _081800B4 @ =0x00000226
	adds r2, r2, r7
	mov r8, r2
	ldrh r0, [r2]
	str r0, [sp, #0xc]
	ldr r0, _081800B8 @ =0x0000022E
	adds r6, r7, r0
	ldrh r0, [r6]
	str r0, [sp, #0x10]
	movs r2, #0x90
	lsls r2, r2, #2
	adds r5, r7, r2
	ldr r0, [r5]
	str r0, [sp, #0x14]
	ldr r0, _081800BC @ =0x00000236
	adds r4, r7, r0
	ldrh r0, [r4]
	str r0, [sp, #0x18]
	add r0, sp, #0x1c
	movs r2, #0x78
	ldr r3, [sp, #0x28]
	bl FUN_080dfeb0
	ldrb r1, [r7, #5]
	adds r1, #4
	movs r2, #8
	str r2, [sp]
	mov r0, sb
	str r0, [sp, #4]
	movs r0, #0x80
	str r0, [sp, #8]
	mov r2, r8
	ldrh r0, [r2]
	str r0, [sp, #0xc]
	ldrh r0, [r6]
	str r0, [sp, #0x10]
	ldr r0, [r5]
	str r0, [sp, #0x14]
	ldrh r0, [r4]
	str r0, [sp, #0x18]
	add r0, sp, #0x1c
	movs r2, #0x78
	ldr r3, [sp, #0x28]
	bl FUN_080dfeb0
	b _081801DE
	.align 2, 0
_081800A8: .4byte 0xFFFFFF00
_081800AC: .4byte 0xFFFF0000
_081800B0: .4byte 0x00000546
_081800B4: .4byte 0x00000226
_081800B8: .4byte 0x0000022E
_081800BC: .4byte 0x00000236
_081800C0:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r1, [r0]
	ldrb r0, [r7, #5]
	subs r1, r1, r0
	adds r2, r0, #0
	cmp r1, #0x80
	ble _081800DC
	ldr r0, _081800D8 @ =0xFFFFFF00
	b _081800E8
	.align 2, 0
_081800D8: .4byte 0xFFFFFF00
_081800DC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081800EA
	movs r0, #0x80
	lsls r0, r0, #1
_081800E8:
	adds r1, r1, r0
_081800EA:
	cmp r1, #0
	bge _081800F0
	rsbs r1, r1, #0
_081800F0:
	cmp r1, #0x17
	bgt _08180170
	adds r1, r2, #0
	subs r1, #0xc
	ldr r2, [sp, #0x28]
	adds r2, #2
	mov sl, r2
	movs r0, #0xc
	str r0, [sp]
	movs r2, #0x16
	mov sb, r2
	str r2, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldr r0, _08180168 @ =0x00000226
	adds r0, r0, r7
	mov r8, r0
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	ldr r2, _0818016C @ =0x0000022E
	adds r6, r7, r2
	ldrh r0, [r6]
	str r0, [sp, #0x10]
	movs r0, #0x90
	lsls r0, r0, #2
	adds r5, r7, r0
	ldr r0, [r5]
	str r0, [sp, #0x14]
	adds r2, #8
	adds r4, r7, r2
	ldrh r0, [r4]
	str r0, [sp, #0x18]
	add r0, sp, #0x1c
	movs r2, #0x78
	mov r3, sl
	bl FUN_080dfeb0
	ldrb r1, [r7, #5]
	adds r1, #0xc
	movs r0, #0xc
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	movs r0, #0x80
	str r0, [sp, #8]
	mov r2, r8
	ldrh r0, [r2]
	str r0, [sp, #0xc]
	ldrh r0, [r6]
	str r0, [sp, #0x10]
	ldr r0, [r5]
	str r0, [sp, #0x14]
	ldrh r0, [r4]
	str r0, [sp, #0x18]
	add r0, sp, #0x1c
	movs r2, #0x78
	mov r3, sl
	bl FUN_080dfeb0
	b _081801DE
	.align 2, 0
_08180168: .4byte 0x00000226
_0818016C: .4byte 0x0000022E
_08180170:
	adds r1, r2, #0
	subs r1, #0x20
	ldr r0, [sp, #0x28]
	adds r0, #4
	str r0, [sp, #0x2c]
	movs r4, #0x14
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldr r2, _0818021C @ =0x00000226
	adds r2, r2, r7
	mov sb, r2
	ldrh r0, [r2]
	str r0, [sp, #0xc]
	ldr r0, _08180220 @ =0x0000022E
	adds r0, r0, r7
	mov r8, r0
	ldrh r0, [r0]
	str r0, [sp, #0x10]
	movs r2, #0x90
	lsls r2, r2, #2
	adds r6, r7, r2
	ldr r0, [r6]
	str r0, [sp, #0x14]
	ldr r0, _08180224 @ =0x00000236
	adds r5, r7, r0
	ldrh r0, [r5]
	str r0, [sp, #0x18]
	add r0, sp, #0x1c
	movs r2, #0x14
	ldr r3, [sp, #0x2c]
	bl FUN_080dfeb0
	ldrb r1, [r7, #5]
	adds r1, #0x20
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0x80
	str r0, [sp, #8]
	mov r2, sb
	ldrh r0, [r2]
	str r0, [sp, #0xc]
	mov r2, r8
	ldrh r0, [r2]
	str r0, [sp, #0x10]
	ldr r0, [r6]
	str r0, [sp, #0x14]
	ldrh r0, [r5]
	str r0, [sp, #0x18]
	add r0, sp, #0x1c
	movs r2, #0x14
	ldr r3, [sp, #0x2c]
	bl FUN_080dfeb0
_081801DE:
	ldr r0, [sp, #0x24]
	ldr r1, _08180228 @ =0x00000898
	adds r2, r0, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _0818022C @ =0x000003D2
	bl PlaySound_082406e0
	ldr r0, _08180230 @ =0x000002D1
	bl PlaySound_082406e0
_081801FA:
	ldr r2, _08180234 @ =0x0000046E
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0818020C
	ldr r0, _08180238 @ =0x0000046B
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_0818020C:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818021C: .4byte 0x00000226
_08180220: .4byte 0x0000022E
_08180224: .4byte 0x00000236
_08180228: .4byte 0x00000898
_0818022C: .4byte 0x000003D2
_08180230: .4byte 0x000002D1
_08180234: .4byte 0x0000046E
_08180238: .4byte 0x0000046B

	thumb_func_start FUN_0818023c
FUN_0818023c: @ 0x0818023C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r0, _0818025C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08180260
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08180262
	.align 2, 0
_0818025C: .4byte 0x0000046D
_08180260:
	movs r0, #0
_08180262:
	cmp r0, #0
	beq _081802B4
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	asrs r1, r2, #0x10
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081802F4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r0, sp
	movs r1, #0
	bl FUN_081f7b8c
	mov r0, sp
	movs r1, #0x80
	bl FUN_081f7b8c
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_080efe38
	movs r2, #0x80
	lsls r2, r2, #0xd
	ldr r0, _081802F8 @ =0x00000898
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081802FC @ =0x000003CF
	bl PlaySound_082406e0
	ldr r0, _08180300 @ =0x000002D2
	bl PlaySound_082406e0
_081802B4:
	ldr r1, _08180304 @ =0x00000804
	adds r4, r6, r1
	adds r1, r5, #0
	adds r1, #8
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	ldr r1, _08180308 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081802EC
	bl FUN_081f7e3c
	ldr r0, _081802F8 @ =0x00000898
	adds r2, r6, r0
	ldr r1, _0818030C @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _08180310 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_081802EC:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081802F4: .4byte 0x0000FFFF
_081802F8: .4byte 0x00000898
_081802FC: .4byte 0x000003CF
_08180300: .4byte 0x000002D2
_08180304: .4byte 0x00000804
_08180308: .4byte 0x0000046E
_0818030C: .4byte 0xFFEFFFFF
_08180310: .4byte 0x0000046B

	thumb_func_start FUN_08180314
FUN_08180314: @ 0x08180314
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r0, _08180384 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08180330
	movs r0, #0
	strb r0, [r1]
_08180330:
	adds r0, r5, #0
	movs r1, #0x13
	bl FUN_080efe38
	ldr r1, _08180388 @ =0x000008A8
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r6, r0
	ble _0818037E
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, _0818038C @ =0x00000898
	adds r1, r1, r0
	ldr r2, _08180390 @ =0xFFFFEFFF
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r4, _08180394 @ =FUN_0818039c
	movs r3, #0x2a
	ldr r0, _08180384 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08180398 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_0818037E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08180384: .4byte 0x0000046D
_08180388: .4byte 0x000008A8
_0818038C: .4byte 0x00000898
_08180390: .4byte 0xFFFFEFFF
_08180394: .4byte FUN_0818039c
_08180398: .4byte 0x0000046B

	thumb_func_start FUN_0818039c
FUN_0818039c: @ 0x0818039C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081803B4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081803B8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081803BA
	.align 2, 0
_081803B4: .4byte 0x0000046D
_081803B8:
	movs r0, #0
_081803BA:
	cmp r0, #0
	beq _081803D4
	adds r0, r5, #0
	movs r1, #0x14
	bl FUN_080efe38
	adds r0, r5, #0
	bl FUN_0817dbfc
	movs r0, #0xb5
	lsls r0, r0, #2
	bl PlaySound_082406e0
_081803D4:
	ldr r1, _0818040C @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08180406
	ldr r4, _08180410 @ =FUN_0818041c
	movs r3, #0x2b
	ldr r0, _08180414 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08180418 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08180406:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0818040C: .4byte 0x0000046E
_08180410: .4byte FUN_0818041c
_08180414: .4byte 0x0000046D
_08180418: .4byte 0x0000046B

	thumb_func_start FUN_0818041c
FUN_0818041c: @ 0x0818041C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r0, _0818043C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08180440
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08180442
	.align 2, 0
_0818043C: .4byte 0x0000046D
_08180440:
	movs r0, #0
_08180442:
	cmp r0, #0
	beq _0818044E
	adds r0, r4, #0
	movs r1, #0x15
	bl FUN_080efe38
_0818044E:
	cmp r5, #0x1e
	ble _0818047E
	ldr r0, _08180484 @ =0x00000147
	bl PlaySound_082406e0
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _08180488 @ =0x00000272
	ldr r2, _0818048C @ =0x00000273
	adds r0, r4, #0
	movs r3, #0x20
	bl FUN_0817d71c
	adds r0, r4, #0
	bl FUN_0817e1a0
	ldr r0, _08180490 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0818047E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08180484: .4byte 0x00000147
_08180488: .4byte 0x00000272
_0818048C: .4byte 0x00000273
_08180490: .4byte 0x0000046B

	thumb_func_start FUN_08180494
FUN_08180494: @ 0x08180494
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	ldr r0, _081804B0 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081804B4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081804B6
	.align 2, 0
_081804B0: .4byte 0x0000046D
_081804B4:
	movs r0, #0
_081804B6:
	cmp r0, #0
	beq _081804C2
	adds r0, r4, #0
	movs r1, #0x12
	bl FUN_080ef86c
_081804C2:
	ldrh r0, [r5, #0x14]
	cmp r0, #1
	bne _081804D4
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	bne _081804D4
	ldr r0, _081804EC @ =0x000003D3
	bl PlaySound_082406e0
_081804D4:
	ldr r1, _081804F0 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081804E6
	ldr r0, _081804F4 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081804E6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081804EC: .4byte 0x000003D3
_081804F0: .4byte 0x0000046E
_081804F4: .4byte 0x0000046B

	thumb_func_start FUN_081804f8
FUN_081804f8: @ 0x081804F8
	bx lr
	.align 2, 0

	thumb_func_start FUN_081804fc
FUN_081804fc: @ 0x081804FC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08180514 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08180518
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818051A
	.align 2, 0
_08180514: .4byte 0x0000046D
_08180518:
	movs r0, #0
_0818051A:
	cmp r0, #0
	beq _08180526
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_080ef86c
_08180526:
	ldr r1, _08180540 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08180538
	ldr r0, _08180544 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08180538:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08180540: .4byte 0x0000046E
_08180544: .4byte 0x0000046B

	thumb_func_start FUN_08180548
FUN_08180548: @ 0x08180548
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _08180560 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08180564
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08180566
	.align 2, 0
_08180560: .4byte 0x0000046D
_08180564:
	movs r0, #0
_08180566:
	cmp r0, #0
	beq _0818058E
	ldr r1, _081805C0 @ =0x000001DD
	adds r0, r6, r1
	ldrb r0, [r0]
	strb r0, [r6, #5]
	adds r0, r6, #0
	movs r1, #3
	bl FUN_080ef86c
	movs r0, #0x20
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _081805C4 @ =0x000002D5
	bl PlaySound_082406e0
_0818058E:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0x83
	lsls r2, r2, #2
	adds r0, r6, r2
	movs r4, #0
	ldrsh r3, [r0, r4]
	adds r5, #0x9c
	adds r2, r6, r5
	movs r4, #0
	ldrsh r0, [r2, r4]
	subs r0, r3, r0
	adds r7, r1, #0
	adds r4, r2, #0
	cmp r0, #0
	blt _081805C8
	asrs r0, r0, #2
	b _081805CE
	.align 2, 0
_081805C0: .4byte 0x000001DD
_081805C4: .4byte 0x000002D5
_081805C8:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081805CE:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r6, r5
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r5, #8
	adds r1, r6, r5
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _081805EC
	asrs r0, r0, #2
	b _081805F2
_081805EC:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081805F2:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _081805FC
	movs r3, #0xc8
	b _08180606
_081805FC:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _08180606
	adds r3, r0, #0
_08180606:
	cmp r2, #0xc8
	ble _0818060E
	movs r2, #0xc8
	b _08180618
_0818060E:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _08180618
	adds r2, r0, #0
_08180618:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r3
	strh r0, [r6, #0x10]
	ldrh r0, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _0818063C
	cmp r2, #0
	bne _0818063C
	movs r0, #1
	b _0818063E
_0818063C:
	movs r0, #0
_0818063E:
	cmp r0, #0
	beq _08180688
	ldr r1, _08180690 @ =0x0000046B
	adds r0, r6, r1
	movs r5, #0
	movs r4, #1
	strb r4, [r0]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r3, r6, r2
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r3]
	ands r0, r1
	movs r2, #0
	strh r0, [r3]
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _08180694 @ =0x00000484
	adds r0, r6, r2
	str r5, [r0]
	ldr r5, _08180698 @ =0x0000046C
	adds r0, r6, r5
	strb r4, [r0]
_08180688:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08180690: .4byte 0x0000046B
_08180694: .4byte 0x00000484
_08180698: .4byte 0x0000046C

	thumb_func_start FUN_0818069c
FUN_0818069c: @ 0x0818069C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081806C0 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081806C4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081806C6
	.align 2, 0
_081806C0: .4byte 0x0000046D
_081806C4:
	movs r0, #0
_081806C6:
	cmp r0, #0
	beq _081806D4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	b _081807C8
_081806D4:
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, _08180708 @ =0x000008A4
	add r1, r8
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhi _081806F2
	movs r0, #0x8a
	lsls r0, r0, #4
	add r0, r8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08180710
_081806F2:
	ldr r2, _0818070C @ =0x00000898
	add r2, r8
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl cheye_0817c5e0
	b _081807C8
	.align 2, 0
_08180708: .4byte 0x000008A4
_0818070C: .4byte 0x00000898
_08180710:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r1, _08180744 @ =0x000004A4
	adds r0, r4, r1
	ldr r6, [r0]
	adds r7, r4, #0
	adds r7, #8
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	adds r5, r0, #0
	adds r5, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08180748
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r4, r3
	b _0818076E
	.align 2, 0
_08180744: .4byte 0x000004A4
_08180748:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08180768
	cmp r0, #2
	beq _08180764
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08180764:
	movs r0, #1
	b _08180778
_08180768:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
_0818076E:
	ldr r1, _0818078C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08180778:
	cmp r0, #0
	bne _08180794
	ldr r2, _08180790 @ =0x000005C4
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _081807C8
	.align 2, 0
_0818078C: .4byte 0xFFFFFDFF
_08180790: .4byte 0x000005C4
_08180794:
	ldr r2, _081807D4 @ =0x00000898
	add r2, r8
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0xf
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _081807D8 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_081807C8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081807D4: .4byte 0x00000898
_081807D8: .4byte 0x00000484

	thumb_func_start FUN_081807dc
FUN_081807dc: @ 0x081807DC
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r5, [r0]
	ldr r2, _081807FC @ =0x0000046D
	adds r1, r3, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08180800
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08180802
	.align 2, 0
_081807FC: .4byte 0x0000046D
_08180800:
	movs r0, #0
_08180802:
	cmp r0, #0
	bne _081808A8
	movs r2, #0x10
	ldr r4, _0818081C @ =0x00000898
	adds r1, r5, r4
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _08180820
	movs r0, #1
	b _08180822
	.align 2, 0
_0818081C: .4byte 0x00000898
_08180820:
	movs r0, #0
_08180822:
	cmp r0, #0
	beq _081808A0
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r2, _08180870 @ =0x000008A4
	adds r1, r5, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bls _0818088E
	movs r2, #0x11
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r3, r4
	movs r1, #0
	strb r1, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r1, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r2, [r0]
	ldr r2, _08180874 @ =0x00000484
	adds r0, r3, r2
	str r1, [r0]
	adds r4, #2
	adds r1, r3, r4
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	blt _08180878
	asrs r0, r0, #5
	b _0818087E
	.align 2, 0
_08180870: .4byte 0x000008A4
_08180874: .4byte 0x00000484
_08180878:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0818087E:
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r3, r2
	strb r0, [r1]
	b _081808A8
_0818088E:
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	adds r0, r3, #0
	bl cheye_0817c5e0
	b _081808A8
_081808A0:
	adds r0, r3, #0
	movs r1, #1
	bl FUN_080ef86c
_081808A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081808b0
FUN_081808b0: @ 0x081808B0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _081808D0 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081808D4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081808D6
	.align 2, 0
_081808D0: .4byte 0x0000046D
_081808D4:
	movs r0, #0
_081808D6:
	cmp r0, #0
	bne _081808DC
	b _08180A3C
_081808DC:
	adds r0, r6, #0
	movs r1, #0xa
	bl FUN_080ef86c
	ldr r7, _08180900 @ =0x0000046E
	adds r1, r6, r7
	movs r0, #0
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r2, _08180904 @ =0x00000898
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08180908
	movs r0, #1
	b _0818090A
	.align 2, 0
_08180900: .4byte 0x0000046E
_08180904: .4byte 0x00000898
_08180908:
	movs r0, #0
_0818090A:
	cmp r0, #0
	beq _08180918
	movs r7, #0xf6
	lsls r7, r7, #3
	adds r1, r4, r7
	movs r0, #0x1e
	strh r0, [r1]
_08180918:
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #4
	bl FUN_080e64b4
	adds r0, r6, #0
	bl FUN_080e8360
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _08180A0C @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08180A10 @ =0x0000021E
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	ldr r4, _08180A14 @ =0x00000202
	adds r0, r6, r4
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0xd8
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	bl FUN_081f7e3c
	bl FUN_080e0214
	movs r7, #0xcd
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrh r0, [r2]
	cmp r0, #0
	beq _081809E4
	movs r1, #8
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r4, #0xa
	ldrsh r0, [r6, r4]
	str r0, [sp, #4]
	movs r7, #0xc
	ldrsh r0, [r6, r7]
	str r0, [sp, #8]
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r4, #0xd0
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r0, [r0]
	str r0, [sp, #0x10]
	movs r7, #0xd2
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r6]
	str r0, [sp, #0x1c]
	ldr r1, _08180A18 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r4, sp
	str r4, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081809E4:
	ldr r7, _08180A1C @ =0x000001DF
	adds r0, r6, r7
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _08180A24
	ldr r0, _08180A20 @ =0x030046A0
	ldr r2, [r0]
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r2, r2, r4
	movs r1, #1
	lsls r1, r3
	b _08180A36
	.align 2, 0
_08180A0C: .4byte 0xFFFEBE3F
_08180A10: .4byte 0x0000021E
_08180A14: .4byte 0x00000202
_08180A18: .4byte 0xFFFF0000
_08180A1C: .4byte 0x000001DF
_08180A20: .4byte 0x030046A0
_08180A24:
	ldr r0, _08180AB8 @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe3
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_08180A36:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08180A3C:
	adds r0, r6, #0
	bl FUN_080e499c
	ldr r1, _08180ABC @ =0x0000046E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08180AB0
	ldr r2, _08180AC0 @ =0x0000046B
	adds r0, r6, r2
	movs r3, #0
	movs r1, #1
	strb r1, [r0]
	movs r4, #0xc9
	lsls r4, r4, #1
	adds r0, r6, r4
	movs r5, #0
	strh r3, [r0]
	ldr r4, _08180AC4 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r7, _08180AC8 @ =0x0000046D
	adds r0, r6, r7
	strb r1, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r5, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r3, [r0]
	movs r2, #2
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _08180ACC @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _08180AD0 @ =0x00000484
	adds r0, r6, r2
	str r3, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0x9a
	lsls r7, r7, #2
	adds r0, r6, r7
	bl FUN_080136b4
_08180AB0:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08180AB8: .4byte 0x030046A0
_08180ABC: .4byte 0x0000046E
_08180AC0: .4byte 0x0000046B
_08180AC4: .4byte FUN_080e48d0
_08180AC8: .4byte 0x0000046D
_08180ACC: .4byte 0x00000469
_08180AD0: .4byte 0x00000484

	thumb_func_start FUN_08180ad4
FUN_08180ad4: @ 0x08180AD4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x68
	adds r7, r0, #0
	ldr r0, _08180AF4 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08180AF8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08180AFA
	.align 2, 0
_08180AF4: .4byte 0x0000046C
_08180AF8:
	movs r0, #0
_08180AFA:
	adds r6, r0, #0
	cmp r6, #0
	beq _08180B98
	ldr r4, _08180B7C @ =FUN_081804fc
	movs r3, #0xa
	ldr r2, _08180B80 @ =0x0000046D
	adds r1, r7, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08180B84 @ =0x0000046B
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _08180B88 @ =0x00000553
	adds r0, r7, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r7, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r2, [r0]
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r0, r7, r6
	ldrb r0, [r0]
	strb r0, [r7, #5]
	ldr r1, _08180B8C @ =0x000001DF
	adds r0, r7, r1
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e5718
	adds r0, r7, #0
	bl FUN_080e6750
	ldr r2, _08180B8C @ =0x000001DF
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _08180B5E
	movs r0, #4
	ldr r3, _08180B90 @ =0x00000222
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08180B5E:
	movs r0, #0x80
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0x93
	lsls r6, r6, #2
	adds r0, r7, r6
	ldrh r1, [r0]
	ldr r2, _08180B94 @ =0x0000024E
	adds r0, r7, r2
	strh r1, [r0]
	b _0818119A
	.align 2, 0
_08180B7C: .4byte FUN_081804fc
_08180B80: .4byte 0x0000046D
_08180B84: .4byte 0x0000046B
_08180B88: .4byte 0x00000553
_08180B8C: .4byte 0x000001DF
_08180B90: .4byte 0x00000222
_08180B94: .4byte 0x0000024E
_08180B98:
	ldr r3, _08180C6C @ =0x0000046B
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08180BA4
	b _08181190
_08180BA4:
	movs r0, #0xc
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r6, [r4]
	ldr r1, _08180C70 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0xc]
	strb r6, [r1]
	ldr r2, _08180C74 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x10]
	strb r0, [r2]
	adds r3, #0x19
	adds r3, r7, r3
	str r3, [sp, #0x14]
	str r6, [r3]
	ldr r4, _08180C78 @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0x18]
	movs r1, #1
	strb r1, [r4]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	movs r0, #0x1a
	ldr r3, _08180C7C @ =0x0000046D
	adds r3, r3, r7
	mov sb, r3
	strb r1, [r3]
	ldr r4, _08180C6C @ =0x0000046B
	adds r4, r4, r7
	mov sl, r4
	strb r6, [r4]
	ldr r1, _08180C80 @ =0x00000553
	adds r5, r7, r1
	strb r0, [r5]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r4, r7, r3
	str r2, [r4]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r3, r7, r0
	strh r6, [r3]
	subs r1, #0xab
	adds r1, r1, r7
	mov r8, r1
	ldr r2, [r1]
	str r2, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x1c]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x3c]
	mov r6, sb
	str r6, [sp, #0x40]
	mov r0, sl
	str r0, [sp, #0x38]
	str r5, [sp, #0x64]
	str r4, [sp, #0x24]
	str r3, [sp, #0x4c]
	ldr r3, [sp, #8]
	str r3, [sp, #0x2c]
	ldr r4, [sp, #0xc]
	str r4, [sp, #0x30]
	ldr r6, [sp, #0x10]
	str r6, [sp, #0x34]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x48]
	mov r6, r8
	mov r8, r2
	mov r2, ip
	cmp r2, #0
	blt _08180C68
	cmp r1, #0
	blt _08180C68
	ldr r0, _08180C84 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _08180C68
	ldr r0, _08180C88 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08180C8C
_08180C68:
	movs r4, #0
	b _08180C9C
	.align 2, 0
_08180C6C: .4byte 0x0000046B
_08180C70: .4byte 0x00000469
_08180C74: .4byte 0x0000046A
_08180C78: .4byte 0x0000046C
_08180C7C: .4byte 0x0000046D
_08180C80: .4byte 0x00000553
_08180C84: .4byte 0x030046A8
_08180C88: .4byte 0x030046AC
_08180C8C:
	ldr r0, _08180CAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r3, ip
	adds r4, r0, r3
_08180C9C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08180CB0
	adds r0, #4
	b _08180CBC
	.align 2, 0
_08180CAC: .4byte 0x030046A4
_08180CB0:
	ldr r0, _08180CD0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08180CBC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08180CD4
	cmp r2, #2
	beq _08180CDA
	b _08180CE0
	.align 2, 0
_08180CD0: .4byte 0x030046A4
_08180CD4:
	ldr r4, [sp, #0x1c]
	ldrb r0, [r4, #4]
	b _08180CDE
_08180CDA:
	ldr r2, [sp, #0x1c]
	ldrb r0, [r2]
_08180CDE:
	subs r1, r1, r0
_08180CE0:
	ldr r3, [sp, #0x1c]
	strh r1, [r3, #2]
	ldr r0, _08180CF8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08180CFC
	movs r0, #1
	b _08180CFE
	.align 2, 0
_08180CF8: .4byte 0x030047A4
_08180CFC:
	movs r0, #0
_08180CFE:
	cmp r0, #0
	beq _08180D3C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08180D1E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08180D1A
	adds r2, r0, #0
_08180D1A:
	cmp r2, #0
	bge _08180D28
_08180D1E:
	ldr r6, _08180D24 @ =0x000005C4
	adds r0, r7, r6
	b _0818117C
	.align 2, 0
_08180D24: .4byte 0x000005C4
_08180D28:
	ldr r1, _08180D38 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08180D84
	.align 2, 0
_08180D38: .4byte 0x03002BE0
_08180D3C:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08180D68
	cmp r1, #0
	blt _08180D68
	ldr r0, _08180D6C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08180D68
	ldr r0, _08180D70 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08180D74
_08180D68:
	movs r5, #0
	b _08180D82
	.align 2, 0
_08180D6C: .4byte 0x030046A8
_08180D70: .4byte 0x030046AC
_08180D74:
	ldr r0, _08180E18 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08180D82:
	movs r2, #0
_08180D84:
	ldr r3, _08180E1C @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _08180DA4
	ldr r1, _08180E20 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08180DA4
	b _081810C0
_08180DA4:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	mov sb, r2
	cmp r4, #0
	beq _08180DBE
	b _0818119A
_08180DBE:
	ldr r0, _08180E24 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sl, r2
	cmp r3, #0
	beq _08180E28
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x40]
	strb r2, [r3]
	ldr r6, [sp, #0x38]
	strb r5, [r6]
	ldr r3, [sp, #0x64]
	strb r0, [r3]
	ldr r6, [sp, #0x24]
	str r1, [r6]
	ldr r0, [sp, #0x4c]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x2c]
	strb r5, [r1]
	ldr r3, [sp, #0x30]
	strb r5, [r3]
	ldr r6, [sp, #0x34]
	strb r0, [r6]
	ldr r0, [sp, #0x48]
	str r4, [r0]
	ldr r1, [sp, #0x3c]
	strb r2, [r1]
	b _08180F76
	.align 2, 0
_08180E18: .4byte 0x030046A4
_08180E1C: .4byte 0x00000256
_08180E20: .4byte 0x03002BE0
_08180E24: .4byte 0x00000222
_08180E28:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r0, #1
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r2, [sp, #0x38]
	strb r5, [r2]
	ldr r4, [sp, #0x64]
	strb r0, [r4]
	ldr r2, [sp, #0x24]
	str r1, [r2]
	ldr r4, [sp, #0x4c]
	strh r3, [r4]
	movs r1, #5
	ldr r2, [sp, #0x2c]
	strb r5, [r2]
	ldr r4, [sp, #0x30]
	strb r5, [r4]
	ldr r2, [sp, #0x34]
	strb r1, [r2]
	ldr r4, [sp, #0x48]
	str r3, [r4]
	ldr r1, [sp, #0x3c]
	strb r0, [r1]
	ldr r5, [r6]
	mov r2, r8
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08180E8C
	cmp r1, #0
	blt _08180E8C
	ldr r0, _08180E90 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08180E8C
	ldr r0, _08180E94 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08180E98
_08180E8C:
	movs r4, #0
	b _08180EA6
	.align 2, 0
_08180E90: .4byte 0x030046A8
_08180E94: .4byte 0x030046AC
_08180E98:
	ldr r0, _08180EB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08180EA6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08180EBC
	adds r0, #4
	b _08180EC8
	.align 2, 0
_08180EB8: .4byte 0x030046A4
_08180EBC:
	ldr r0, _08180EDC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08180EC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08180EE0
	cmp r2, #2
	beq _08180EE4
	b _08180EE8
	.align 2, 0
_08180EDC: .4byte 0x030046A4
_08180EE0:
	ldrb r0, [r5, #4]
	b _08180EE6
_08180EE4:
	ldrb r0, [r5]
_08180EE6:
	subs r1, r1, r0
_08180EE8:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08180F10
	cmp r1, #0
	blt _08180F10
	ldr r0, _08180F14 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08180F10
	ldr r0, _08180F18 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08180F1C
_08180F10:
	movs r4, #0
	b _08180F2A
	.align 2, 0
_08180F14: .4byte 0x030046A8
_08180F18: .4byte 0x030046AC
_08180F1C:
	ldr r0, _08180F3C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08180F2A:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08180F40
	adds r0, #4
	b _08180F4C
	.align 2, 0
_08180F3C: .4byte 0x030046A4
_08180F40:
	ldr r0, _08180F60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08180F4C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08180F64
	cmp r3, #2
	beq _08180F68
	b _08180F6C
	.align 2, 0
_08180F60: .4byte 0x030046A4
_08180F64:
	ldrb r0, [r5, #4]
	b _08180F6A
_08180F68:
	ldrb r0, [r5]
_08180F6A:
	subs r2, r2, r0
_08180F6C:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_08180F76:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r4, sb
	ldrh r0, [r4]
	ands r0, r1
	mov r8, r3
	ldr r6, _08180FA0 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x44]
	cmp r0, #0
	bne _08181084
	movs r1, #4
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08180FA4
	movs r0, #1
	b _08180FA6
	.align 2, 0
_08180FA0: .4byte 0x00000482
_08180FA4:
	movs r0, #0
_08180FA6:
	ldr r3, _08181094 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x44]
	cmp r0, #0
	bne _08181084
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _08181098 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0818109C @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r2, _081810A0 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	ldr r4, _081810A4 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x60]
	ldr r6, _081810A8 @ =0x00000541
	adds r6, r7, r6
	str r6, [sp, #0x50]
	ldr r0, _081810AC @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x28]
	ldr r1, _081810B0 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x54]
	ldr r6, _081810B4 @ =0x0203B400
	ldr r1, _081810B8 @ =0x030046B8
	ldr r5, _081810BC @ =0x000003FF
	movs r4, #3
	mov r2, r8
_08180FF6:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r4
	lsls r0, r0, #6
	cmp r0, r2
	bne _08181014
	adds r3, #1
	cmp r3, #3
	ble _08180FF6
	mov r0, r8
_08181014:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x24]
	ldr r0, [r4]
	mov r6, sl
	str r0, [r6]
	ldr r1, [sp, #0x64]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x2c]
	ldrb r0, [r4]
	ldr r6, [sp, #0x58]
	strb r0, [r6]
	ldr r1, [sp, #0x30]
	ldrb r0, [r1]
	ldr r2, [sp, #0x5c]
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	ldrb r0, [r4]
	ldr r6, [sp, #0x60]
	strb r0, [r6]
	add r0, sp, #0x20
	ldrb r1, [r0]
	ldr r0, [sp, #0x50]
	strb r1, [r0]
	ldr r1, [sp, #0x28]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x40]
	strb r1, [r4]
	ldr r6, [sp, #0x38]
	strb r3, [r6]
	ldr r4, [sp, #0x64]
	strb r0, [r4]
	ldr r6, [sp, #0x24]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x4c]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x2c]
	strb r0, [r4]
	ldr r6, [sp, #0x30]
	strb r1, [r6]
	ldr r0, [sp, #0x34]
	strb r2, [r0]
	ldr r2, [sp, #0x48]
	str r3, [r2]
	ldr r3, [sp, #0x3c]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x54]
	strb r0, [r4]
_08181084:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r6, [sp, #0x44]
	strh r0, [r6]
	b _0818119A
	.align 2, 0
_08181094: .4byte 0x00000482
_08181098: .4byte 0x0000054F
_0818109C: .4byte 0x0000054C
_081810A0: .4byte 0x0000054D
_081810A4: .4byte 0x0000054E
_081810A8: .4byte 0x00000541
_081810AC: .4byte 0x000005BC
_081810B0: .4byte 0x00000542
_081810B4: .4byte 0x0203B400
_081810B8: .4byte 0x030046B8
_081810BC: .4byte 0x000003FF
_081810C0:
	mov sb, sp
	ldr r6, _081810FC @ =0x030046A4
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
	beq _08181100
	adds r0, #4
	b _0818110A
	.align 2, 0
_081810FC: .4byte 0x030046A4
_08181100:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818110A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r6, r8
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r1, _08181140 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08181144
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0818116A
	.align 2, 0
_08181140: .4byte 0x000004A4
_08181144:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08181164
	cmp r0, #2
	beq _08181160
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08181160:
	movs r0, #1
	b _08181174
_08181164:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_0818116A:
	ldr r1, _08181188 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08181174:
	cmp r0, #0
	bne _0818119A
	ldr r4, _0818118C @ =0x000005C4
	adds r0, r7, r4
_0818117C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0818119A
	.align 2, 0
_08181188: .4byte 0xFFFFFDFF
_0818118C: .4byte 0x000005C4
_08181190:
	ldr r6, _081811AC @ =0x00000484
	adds r1, r7, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818119A:
	add sp, #0x68
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081811AC: .4byte 0x00000484

	thumb_func_start FUN_081811b0
FUN_081811b0: @ 0x081811B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x90
	adds r7, r0, #0
	ldr r0, _081811D0 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081811D4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081811D6
	.align 2, 0
_081811D0: .4byte 0x0000046C
_081811D4:
	movs r0, #0
_081811D6:
	cmp r0, #0
	beq _081811E4
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	strb r0, [r7, #5]
_081811E4:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081811FC
	bl _08181A66
_081811FC:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _0818120E
	bl _08181A66
_0818120E:
	ldr r3, _08181300 @ =0x00000484
	adds r1, r7, r3
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _0818121C
	bl FUN_08181a62
_0818121C:
	movs r0, #0x80
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	str r2, [sp, #0x48]
	cmp r3, #0
	bne _08181234
	b _08181828
_08181234:
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #8]
	strb r6, [r1]
	ldr r2, _08181304 @ =0x00000469
	adds r2, r7, r2
	str r2, [sp, #0xc]
	strb r6, [r2]
	ldr r3, _08181308 @ =0x0000046A
	adds r3, r7, r3
	str r3, [sp, #0x10]
	strb r0, [r3]
	ldr r4, _08181300 @ =0x00000484
	adds r4, r7, r4
	str r4, [sp, #0x14]
	str r6, [r4]
	ldr r0, _0818130C @ =0x0000046C
	adds r0, r0, r7
	mov sb, r0
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	movs r0, #0x1a
	ldr r3, _08181310 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x18]
	strb r1, [r3]
	ldr r4, _08181314 @ =0x0000046B
	adds r4, r4, r7
	mov r8, r4
	strb r6, [r4]
	ldr r1, _08181318 @ =0x00000553
	adds r1, r1, r7
	mov sl, r1
	strb r0, [r1]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r5, r7, r3
	str r2, [r5]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r7, r0
	strh r6, [r4]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r3, r7, r1
	ldr r2, [r3]
	str r2, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x1c]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, sb
	str r0, [sp, #0x80]
	ldr r6, [sp, #8]
	str r6, [sp, #0x70]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x74]
	ldr r6, [sp, #0x10]
	str r6, [sp, #0x78]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x84]
	mov r0, r8
	str r0, [sp, #0x7c]
	mov r6, sl
	str r6, [sp, #0x60]
	str r5, [sp, #0x68]
	str r4, [sp, #0x64]
	adds r6, r3, #0
	mov r8, r2
	mov r0, ip
	cmp r0, #0
	blt _081812FC
	cmp r1, #0
	blt _081812FC
	ldr r0, _0818131C @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _081812FC
	ldr r0, _08181320 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08181324
_081812FC:
	movs r4, #0
	b _08181334
	.align 2, 0
_08181300: .4byte 0x00000484
_08181304: .4byte 0x00000469
_08181308: .4byte 0x0000046A
_0818130C: .4byte 0x0000046C
_08181310: .4byte 0x0000046D
_08181314: .4byte 0x0000046B
_08181318: .4byte 0x00000553
_0818131C: .4byte 0x030046A8
_08181320: .4byte 0x030046AC
_08181324:
	ldr r0, _08181344 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_08181334:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08181348
	adds r0, #4
	b _08181354
	.align 2, 0
_08181344: .4byte 0x030046A4
_08181348:
	ldr r0, _08181368 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08181354:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0818136C
	cmp r2, #2
	beq _08181372
	b _08181378
	.align 2, 0
_08181368: .4byte 0x030046A4
_0818136C:
	ldr r2, [sp, #0x1c]
	ldrb r0, [r2, #4]
	b _08181376
_08181372:
	ldr r3, [sp, #0x1c]
	ldrb r0, [r3]
_08181376:
	subs r1, r1, r0
_08181378:
	ldr r4, [sp, #0x1c]
	strh r1, [r4, #2]
	ldr r0, _08181390 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08181394
	movs r0, #1
	b _08181396
	.align 2, 0
_08181390: .4byte 0x030047A4
_08181394:
	movs r0, #0
_08181396:
	cmp r0, #0
	beq _081813D4
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081813B6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081813B2
	adds r2, r0, #0
_081813B2:
	cmp r2, #0
	bge _081813C0
_081813B6:
	ldr r2, _081813BC @ =0x000005C4
	adds r0, r7, r2
	b _08181816
	.align 2, 0
_081813BC: .4byte 0x000005C4
_081813C0:
	ldr r1, _081813D0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0818141C
	.align 2, 0
_081813D0: .4byte 0x03002BE0
_081813D4:
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
	blt _08181400
	cmp r1, #0
	blt _08181400
	ldr r0, _08181404 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08181400
	ldr r0, _08181408 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0818140C
_08181400:
	movs r5, #0
	b _0818141A
	.align 2, 0
_08181404: .4byte 0x030046A8
_08181408: .4byte 0x030046AC
_0818140C:
	ldr r0, _081814AC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0818141A:
	movs r2, #0
_0818141C:
	ldr r4, _081814B0 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0818143C
	ldr r1, _081814B4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0818143C
	b _08181754
_0818143C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x48]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08181450
	b _08181A66
_08181450:
	ldr r3, _081814B8 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x48]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sl, r2
	cmp r3, #0
	beq _081814BC
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x84]
	strb r2, [r3]
	ldr r6, [sp, #0x7c]
	strb r5, [r6]
	ldr r3, [sp, #0x60]
	strb r0, [r3]
	ldr r6, [sp, #0x68]
	str r1, [r6]
	ldr r0, [sp, #0x64]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x70]
	strb r5, [r1]
	ldr r3, [sp, #0x74]
	strb r5, [r3]
	ldr r6, [sp, #0x78]
	strb r0, [r6]
	ldr r0, [sp, #0x8c]
	str r4, [r0]
	ldr r1, [sp, #0x80]
	strb r2, [r1]
	b _0818160A
	.align 2, 0
_081814AC: .4byte 0x030046A4
_081814B0: .4byte 0x00000256
_081814B4: .4byte 0x03002BE0
_081814B8: .4byte 0x00000222
_081814BC:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r0, #1
	ldr r4, [sp, #0x84]
	strb r0, [r4]
	ldr r2, [sp, #0x7c]
	strb r5, [r2]
	ldr r4, [sp, #0x60]
	strb r0, [r4]
	ldr r2, [sp, #0x68]
	str r1, [r2]
	ldr r4, [sp, #0x64]
	strh r3, [r4]
	movs r1, #5
	ldr r2, [sp, #0x70]
	strb r5, [r2]
	ldr r4, [sp, #0x74]
	strb r5, [r4]
	ldr r2, [sp, #0x78]
	strb r1, [r2]
	ldr r4, [sp, #0x8c]
	str r3, [r4]
	ldr r1, [sp, #0x80]
	strb r0, [r1]
	ldr r5, [r6]
	mov r2, r8
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08181520
	cmp r1, #0
	blt _08181520
	ldr r0, _08181524 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08181520
	ldr r0, _08181528 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0818152C
_08181520:
	movs r4, #0
	b _0818153A
	.align 2, 0
_08181524: .4byte 0x030046A8
_08181528: .4byte 0x030046AC
_0818152C:
	ldr r0, _0818154C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0818153A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08181550
	adds r0, #4
	b _0818155C
	.align 2, 0
_0818154C: .4byte 0x030046A4
_08181550:
	ldr r0, _08181570 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0818155C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08181574
	cmp r2, #2
	beq _08181578
	b _0818157C
	.align 2, 0
_08181570: .4byte 0x030046A4
_08181574:
	ldrb r0, [r5, #4]
	b _0818157A
_08181578:
	ldrb r0, [r5]
_0818157A:
	subs r1, r1, r0
_0818157C:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081815A4
	cmp r1, #0
	blt _081815A4
	ldr r0, _081815A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081815A4
	ldr r0, _081815AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081815B0
_081815A4:
	movs r4, #0
	b _081815BE
	.align 2, 0
_081815A8: .4byte 0x030046A8
_081815AC: .4byte 0x030046AC
_081815B0:
	ldr r0, _081815D0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081815BE:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081815D4
	adds r0, #4
	b _081815E0
	.align 2, 0
_081815D0: .4byte 0x030046A4
_081815D4:
	ldr r0, _081815F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081815E0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081815F8
	cmp r3, #2
	beq _081815FC
	b _08181600
	.align 2, 0
_081815F4: .4byte 0x030046A4
_081815F8:
	ldrb r0, [r5, #4]
	b _081815FE
_081815FC:
	ldrb r0, [r5]
_081815FE:
	subs r2, r2, r0
_08181600:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_0818160A:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x48]
	ldrh r0, [r4]
	ands r0, r1
	mov sb, r3
	ldr r6, _08181634 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x88]
	cmp r0, #0
	bne _08181718
	movs r1, #4
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08181638
	movs r0, #1
	b _0818163A
	.align 2, 0
_08181634: .4byte 0x00000482
_08181638:
	movs r0, #0
_0818163A:
	ldr r3, _08181728 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x88]
	cmp r0, #0
	bne _08181718
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _0818172C @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _08181730 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x54]
	ldr r2, _08181734 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x58]
	ldr r4, _08181738 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x5c]
	ldr r6, _0818173C @ =0x00000541
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	ldr r0, _08181740 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x6c]
	ldr r1, _08181744 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x50]
	ldr r6, _08181748 @ =0x0203B400
	ldr r1, _0818174C @ =0x030046B8
	ldr r5, _08181750 @ =0x000003FF
	movs r4, #3
	mov r2, sb
_0818168A:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r4
	lsls r0, r0, #6
	cmp r0, r2
	bne _081816A8
	adds r3, #1
	cmp r3, #3
	ble _0818168A
	mov r0, sb
_081816A8:
	movs r3, #0
	mov r2, r8
	strb r0, [r2]
	ldr r4, [sp, #0x68]
	ldr r0, [r4]
	mov r6, sl
	str r0, [r6]
	ldr r1, [sp, #0x60]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x70]
	ldrb r0, [r4]
	ldr r6, [sp, #0x54]
	strb r0, [r6]
	ldr r1, [sp, #0x74]
	ldrb r0, [r1]
	ldr r2, [sp, #0x58]
	strb r0, [r2]
	ldr r4, [sp, #0x78]
	ldrb r0, [r4]
	ldr r6, [sp, #0x5c]
	strb r0, [r6]
	add r0, sp, #0x20
	ldrb r1, [r0]
	ldr r0, [sp, #0x4c]
	strb r1, [r0]
	ldr r1, [sp, #0x6c]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x84]
	strb r1, [r4]
	ldr r6, [sp, #0x7c]
	strb r3, [r6]
	ldr r4, [sp, #0x60]
	strb r0, [r4]
	ldr r6, [sp, #0x68]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x64]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x70]
	strb r0, [r4]
	ldr r6, [sp, #0x74]
	strb r1, [r6]
	ldr r0, [sp, #0x78]
	strb r2, [r0]
	ldr r2, [sp, #0x8c]
	str r3, [r2]
	ldr r3, [sp, #0x80]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x50]
	strb r0, [r4]
_08181718:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r6, [sp, #0x88]
	strh r0, [r6]
	b _08181A66
	.align 2, 0
_08181728: .4byte 0x00000482
_0818172C: .4byte 0x0000054F
_08181730: .4byte 0x0000054C
_08181734: .4byte 0x0000054D
_08181738: .4byte 0x0000054E
_0818173C: .4byte 0x00000541
_08181740: .4byte 0x000005BC
_08181744: .4byte 0x00000542
_08181748: .4byte 0x0203B400
_0818174C: .4byte 0x030046B8
_08181750: .4byte 0x000003FF
_08181754:
	mov sb, sp
	ldr r6, _08181790 @ =0x030046A4
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
	beq _08181794
	adds r0, #4
	b _0818179E
	.align 2, 0
_08181790: .4byte 0x030046A4
_08181794:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818179E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r6, r8
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r1, _081817D8 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081817E0
	ldr r0, _081817DC @ =0xFFFFFDFF
	ldr r2, [sp, #0x48]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0818180A
	.align 2, 0
_081817D8: .4byte 0x000004A4
_081817DC: .4byte 0xFFFFFDFF
_081817E0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08181800
	cmp r0, #2
	beq _081817FC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081817FC:
	movs r0, #1
	b _0818180C
_08181800:
	ldr r0, _08181820 @ =0xFFFFFDFF
	ldr r3, [sp, #0x48]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0818180A:
	movs r0, #0
_0818180C:
	cmp r0, #0
	beq _08181812
	b _08181A66
_08181812:
	ldr r4, _08181824 @ =0x000005C4
	adds r0, r7, r4
_08181816:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _08181A66
	.align 2, 0
_08181820: .4byte 0xFFFFFDFF
_08181824: .4byte 0x000005C4
_08181828:
	movs r0, #3
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x24]
	strb r0, [r6]
	ldr r0, _0818192C @ =0x00000469
	adds r0, r7, r0
	str r0, [sp, #0x28]
	strb r1, [r0]
	ldr r2, _08181930 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	strb r3, [r2]
	ldr r4, _08181934 @ =0x00000484
	adds r4, r7, r4
	str r4, [sp, #0x30]
	str r3, [r4]
	ldr r6, _08181938 @ =0x0000046C
	adds r6, r7, r6
	str r6, [sp, #0x34]
	strb r1, [r6]
	ldr r2, _0818193C @ =FUN_080e6794
	movs r0, #0xe
	ldr r4, _08181940 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x38]
	strb r1, [r4]
	ldr r6, _08181944 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x3c]
	strb r3, [r6]
	ldr r1, _08181948 @ =0x00000553
	adds r1, r7, r1
	str r1, [sp, #0x40]
	strb r0, [r1]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	str r2, [r4]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x44]
	movs r5, #0
	strh r3, [r6]
	ldr r1, _0818194C @ =0x000001DF
	adds r0, r7, r1
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x1e
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _08181950 @ =0x00000551
	adds r0, r7, r2
	strb r5, [r0]
	ldr r3, _08181954 @ =0x00000552
	adds r0, r7, r3
	strb r4, [r0]
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0x70]
	ldr r3, [sp, #0x28]
	str r3, [sp, #0x74]
	ldr r4, [sp, #0x2c]
	str r4, [sp, #0x78]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0x8c]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x84]
	ldr r3, [sp, #0x3c]
	str r3, [sp, #0x7c]
	ldr r4, [sp, #0x40]
	str r4, [sp, #0x60]
	mov r6, r8
	str r6, [sp, #0x68]
	ldr r0, [sp, #0x44]
	str r0, [sp, #0x64]
	cmp r2, #0
	blt _08181926
	cmp r1, #0
	blt _08181926
	ldr r0, _08181958 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08181926
	ldr r0, _0818195C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08181960
_08181926:
	movs r4, #0
	b _0818196E
	.align 2, 0
_0818192C: .4byte 0x00000469
_08181930: .4byte 0x0000046A
_08181934: .4byte 0x00000484
_08181938: .4byte 0x0000046C
_0818193C: .4byte FUN_080e6794
_08181940: .4byte 0x0000046D
_08181944: .4byte 0x0000046B
_08181948: .4byte 0x00000553
_0818194C: .4byte 0x000001DF
_08181950: .4byte 0x00000551
_08181954: .4byte 0x00000552
_08181958: .4byte 0x030046A8
_0818195C: .4byte 0x030046AC
_08181960:
	ldr r0, _08181980 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0818196E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08181984
	adds r0, #4
	b _08181990
	.align 2, 0
_08181980: .4byte 0x030046A4
_08181984:
	ldr r0, _081819A4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08181990:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081819A8
	cmp r2, #2
	beq _081819AC
	b _081819B0
	.align 2, 0
_081819A4: .4byte 0x030046A4
_081819A8:
	ldrb r0, [r5, #4]
	b _081819AE
_081819AC:
	ldrb r0, [r5]
_081819AE:
	subs r1, r1, r0
_081819B0:
	strh r1, [r5, #2]
	ldr r1, _081819E0 @ =0x000004A4
	adds r0, r7, r1
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081819E8
	ldr r0, _081819E4 @ =0xFFFFFDFF
	ldr r3, [sp, #0x48]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _08181A12
	.align 2, 0
_081819E0: .4byte 0x000004A4
_081819E4: .4byte 0xFFFFFDFF
_081819E8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08181A08
	cmp r0, #2
	beq _08181A04
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08181A04:
	movs r0, #1
	b _08181A14
_08181A08:
	ldr r0, _08181A4C @ =0xFFFFFDFF
	ldr r4, [sp, #0x48]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_08181A12:
	movs r0, #0
_08181A14:
	adds r3, r0, #0
	cmp r3, #0
	bne _08181A54
	ldr r0, _08181A50 @ =FUN_080e48d0
	movs r2, #1
	ldr r6, [sp, #0x84]
	strb r2, [r6]
	ldr r1, [sp, #0x7c]
	strb r3, [r1]
	ldr r4, [sp, #0x60]
	strb r3, [r4]
	ldr r6, [sp, #0x68]
	str r0, [r6]
	movs r1, #0
	ldr r0, [sp, #0x64]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x70]
	strb r0, [r4]
	ldr r6, [sp, #0x74]
	strb r1, [r6]
	ldr r0, [sp, #0x78]
	strb r1, [r0]
	ldr r1, [sp, #0x8c]
	str r3, [r1]
	ldr r3, [sp, #0x80]
	strb r2, [r3]
	b _08181A66
	.align 2, 0
_08181A4C: .4byte 0xFFFFFDFF
_08181A50: .4byte FUN_080e48d0
_08181A54:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _08181A66

	non_word_aligned_thumb_func_start FUN_08181a62
FUN_08181a62: @ 0x08181A62
	adds r0, #1
	str r0, [r1]
_08181A66:
	add sp, #0x90
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08181a78
FUN_08181a78: @ 0x08181A78
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _08181A84 @ =0x085ADB8C
	str r1, [r0]
	bx lr
	.align 2, 0
_08181A84: .4byte 0x085ADB8C

	thumb_func_start FUN_08181a88
FUN_08181a88: @ 0x08181A88
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08181AA8 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08181AAC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08181AAE
	.align 2, 0
_08181AA8: .4byte 0x0000046C
_08181AAC:
	movs r0, #0
_08181AAE:
	cmp r0, #0
	beq _08181AFA
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08181B94 @ =FUN_0817fac8
	movs r2, #0x22
	ldr r0, _08181B98 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08181B9C @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	ldr r3, _08181BA0 @ =0x00000553
	adds r0, r6, r3
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	ldr r3, _08181BA4 @ =0x00000888
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r2, _08181BA8 @ =0x0000087C
	adds r0, r7, r2
	strh r1, [r0]
_08181AFA:
	ldr r3, _08181B9C @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08181BEC
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _08181BAC @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r5, #0
	strh r1, [r2]
	ldr r1, _08181BB0 @ =FUN_0817fbe0
	mov ip, r1
	movs r1, #0x2d
	ldr r2, _08181B98 @ =0x0000046D
	adds r0, r6, r2
	movs r4, #1
	strb r4, [r0]
	subs r2, #2
	adds r0, r6, r2
	strb r3, [r0]
	adds r2, #0xe8
	adds r0, r6, r2
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	mov r2, ip
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	movs r1, #2
	movs r2, #3
	mov ip, r2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _08181BB4 @ =0x00000469
	adds r0, r6, r3
	strb r1, [r0]
	ldr r1, _08181BB8 @ =0x0000046A
	adds r0, r6, r1
	mov r2, ip
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r6, r3
	str r5, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _08181BBC @ =0x0000089F
	adds r0, r7, r2
	movs r2, #0x50
	strb r2, [r0]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r3, _08181BC0 @ =0x00000546
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r1, r0
	bgt _08181BC4
	movs r0, #0x28
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	b _08181BCC
	.align 2, 0
_08181B94: .4byte FUN_0817fac8
_08181B98: .4byte 0x0000046D
_08181B9C: .4byte 0x0000046B
_08181BA0: .4byte 0x00000553
_08181BA4: .4byte 0x00000888
_08181BA8: .4byte 0x0000087C
_08181BAC: .4byte 0xFFFFFEFF
_08181BB0: .4byte FUN_0817fbe0
_08181BB4: .4byte 0x00000469
_08181BB8: .4byte 0x0000046A
_08181BBC: .4byte 0x0000089F
_08181BC0: .4byte 0x00000546
_08181BC4:
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r2, [r0]
_08181BCC:
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	ldrh r1, [r2]
	ldr r2, _08181BE8 @ =0x000008AA
	adds r0, r7, r2
	strh r1, [r0]
	b _08181BF6
	.align 2, 0
_08181BE8: .4byte 0x000008AA
_08181BEC:
	ldr r3, _08181BFC @ =0x00000484
	adds r1, r6, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08181BF6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08181BFC: .4byte 0x00000484

	thumb_func_start FUN_08181c00
FUN_08181c00: @ 0x08181C00
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08181C20 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08181C24
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08181C26
	.align 2, 0
_08181C20: .4byte 0x0000046C
_08181C24:
	movs r0, #0
_08181C26:
	cmp r0, #0
	beq _08181C72
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08181D08 @ =FUN_0817fee4
	movs r2, #0x24
	ldr r0, _08181D0C @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08181D10 @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	ldr r3, _08181D14 @ =0x00000553
	adds r0, r6, r3
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	ldr r3, _08181D18 @ =0x0000088A
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r2, _08181D1C @ =0x0000087E
	adds r0, r7, r2
	strh r1, [r0]
_08181C72:
	ldr r3, _08181D10 @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08181D64
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _08181D20 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r5, #0
	strh r1, [r2]
	ldr r1, _08181D24 @ =FUN_0817fc84
	ldr r2, _08181D0C @ =0x0000046D
	adds r0, r6, r2
	movs r4, #1
	strb r4, [r0]
	subs r2, #2
	adds r0, r6, r2
	strb r3, [r0]
	adds r2, #0xe8
	adds r0, r6, r2
	strb r3, [r0]
	adds r2, #0x25
	adds r0, r6, r2
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	movs r1, #2
	movs r2, #3
	mov ip, r2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _08181D28 @ =0x0000046A
	adds r0, r6, r1
	mov r2, ip
	strb r2, [r0]
	adds r1, #0x1a
	adds r0, r6, r1
	str r5, [r0]
	ldr r2, _08181D2C @ =0x0000046C
	adds r0, r6, r2
	strb r4, [r0]
	ldr r1, _08181D30 @ =0x0000089C
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _08181D34 @ =0x0000089F
	adds r0, r7, r2
	movs r2, #0x1e
	strb r2, [r0]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r3, _08181D38 @ =0x00000546
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r1, r0
	bgt _08181D3C
	movs r0, #0xf
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	b _08181D44
	.align 2, 0
_08181D08: .4byte FUN_0817fee4
_08181D0C: .4byte 0x0000046D
_08181D10: .4byte 0x0000046B
_08181D14: .4byte 0x00000553
_08181D18: .4byte 0x0000088A
_08181D1C: .4byte 0x0000087E
_08181D20: .4byte 0xFFFFFEFF
_08181D24: .4byte FUN_0817fc84
_08181D28: .4byte 0x0000046A
_08181D2C: .4byte 0x0000046C
_08181D30: .4byte 0x0000089C
_08181D34: .4byte 0x0000089F
_08181D38: .4byte 0x00000546
_08181D3C:
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r2, [r0]
_08181D44:
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	ldrh r1, [r2]
	ldr r2, _08181D60 @ =0x000008AA
	adds r0, r7, r2
	strh r1, [r0]
	b _08181D6E
	.align 2, 0
_08181D60: .4byte 0x000008AA
_08181D64:
	ldr r3, _08181D74 @ =0x00000484
	adds r1, r6, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08181D6E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08181D74: .4byte 0x00000484

	thumb_func_start FUN_08181d78
FUN_08181d78: @ 0x08181D78
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08181D98 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08181D9C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08181D9E
	.align 2, 0
_08181D98: .4byte 0x0000046C
_08181D9C:
	movs r0, #0
_08181D9E:
	cmp r0, #0
	beq _08181DEC
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08181E54 @ =FUN_0818023c
	movs r2, #0x23
	ldr r0, _08181E58 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08181E5C @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	ldr r3, _08181E60 @ =0x00000553
	adds r0, r6, r3
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	ldr r3, _08181E64 @ =0x0000088C
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r5, #0x88
	lsls r5, r5, #4
	adds r0, r7, r5
	strh r1, [r0]
_08181DEC:
	ldr r1, _08181E5C @ =0x0000046B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08181DF8
	b _08181F5C
_08181DF8:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r1, _08181E68 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r4, #0
	movs r5, #0
	strh r1, [r2]
	ldr r2, _08181E6C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08181E70 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08181E74 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _08181E80
	ldr r3, _08181E78 @ =FUN_0817fc24
	movs r2, #0x2e
	ldr r0, _08181E58 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08181E5C @ =0x0000046B
	adds r0, r6, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r5, [r0]
	ldr r5, _08181E7C @ =0x0000089F
	adds r1, r7, r5
	movs r0, #0xa0
	b _08181EB2
	.align 2, 0
_08181E54: .4byte FUN_0818023c
_08181E58: .4byte 0x0000046D
_08181E5C: .4byte 0x0000046B
_08181E60: .4byte 0x00000553
_08181E64: .4byte 0x0000088C
_08181E68: .4byte 0xFFFFFEFF
_08181E6C: .4byte 0x030046B8
_08181E70: .4byte 0x000003FF
_08181E74: .4byte 0x0203B400
_08181E78: .4byte FUN_0817fc24
_08181E7C: .4byte 0x0000089F
_08181E80:
	ldr r2, _08181ED8 @ =FUN_0817fc84
	ldr r0, _08181EDC @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08181EE0 @ =0x0000046B
	adds r0, r6, r1
	strb r4, [r0]
	ldr r3, _08181EE4 @ =0x00000553
	adds r0, r6, r3
	strb r4, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	ldr r3, _08181EE8 @ =0x0000089C
	adds r0, r7, r3
	strb r4, [r0]
	ldr r5, _08181EEC @ =0x0000089F
	adds r1, r7, r5
	movs r0, #0x1e
_08181EB2:
	strb r0, [r1]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _08181EF0 @ =0x00000546
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r1, r0
	bgt _08181EF4
	ldr r5, _08181EEC @ =0x0000089F
	adds r0, r7, r5
	ldrb r0, [r0]
	lsrs r0, r0, #1
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r6, r2
	b _08181F00
	.align 2, 0
_08181ED8: .4byte FUN_0817fc84
_08181EDC: .4byte 0x0000046D
_08181EE0: .4byte 0x0000046B
_08181EE4: .4byte 0x00000553
_08181EE8: .4byte 0x0000089C
_08181EEC: .4byte 0x0000089F
_08181EF0: .4byte 0x00000546
_08181EF4:
	ldr r3, _08181F48 @ =0x0000089F
	adds r0, r7, r3
	ldrb r0, [r0]
	movs r5, #0xc9
	lsls r5, r5, #1
	adds r1, r6, r5
_08181F00:
	strh r0, [r1]
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r3, #0
	movs r4, #0
	strh r1, [r0]
	ldrh r0, [r2]
	adds r0, #0x28
	ldr r5, _08181F4C @ =0x000008AA
	adds r1, r7, r5
	strh r0, [r1]
	movs r1, #2
	movs r2, #3
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r3, [r0]
	ldr r3, _08181F50 @ =0x00000469
	adds r0, r6, r3
	strb r1, [r0]
	adds r5, #2
	adds r0, r6, r5
	strb r2, [r0]
	ldr r1, _08181F54 @ =0x00000484
	adds r0, r6, r1
	str r4, [r0]
	ldr r2, _08181F58 @ =0x0000046C
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	b _08181F66
	.align 2, 0
_08181F48: .4byte 0x0000089F
_08181F4C: .4byte 0x000008AA
_08181F50: .4byte 0x00000469
_08181F54: .4byte 0x00000484
_08181F58: .4byte 0x0000046C
_08181F5C:
	ldr r3, _08181F6C @ =0x00000484
	adds r1, r6, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08181F66:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08181F6C: .4byte 0x00000484

	thumb_func_start FUN_08181f70
FUN_08181f70: @ 0x08181F70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _08181FEC @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08181F96
	movs r0, #0
	strb r0, [r1]
_08181F96:
	ldr r0, _08181FF0 @ =0x000008AA
	add r0, sl
	ldrh r0, [r0]
	ldr r3, _08181FF4 @ =0x00000484
	adds r2, r5, r3
	ldr r1, [r2]
	cmp r0, r1
	blt _08181FA8
	b _0818222C
_08181FA8:
	ldr r4, _08181FF8 @ =0x00000256
	adds r0, r5, r4
	ldrh r6, [r0]
	mov sb, sp
	ldr r7, _08181FFC @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r6, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08182000
	adds r0, #4
	b _0818200A
	.align 2, 0
_08181FEC: .4byte 0x0000046C
_08181FF0: .4byte 0x000008AA
_08181FF4: .4byte 0x00000484
_08181FF8: .4byte 0x00000256
_08181FFC: .4byte 0x030046A4
_08182000:
	ldr r0, [r7]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818200A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r6, #0
	mov r4, sb
	strh r0, [r4, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	add r2, sp, #8
	adds r3, r5, #0
	adds r3, #8
	mov r4, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r4, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r4, #4
	ldrsh r0, [r2, r4]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _08182084 @ =0x000003FF
	mov r8, r2
	adds r7, r3, #0
	cmp r1, r0
	bgt _08182098
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _08182088 @ =0x00000469
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _0818208C @ =0x0000046A
	adds r0, r5, r3
	strb r6, [r0]
	ldr r4, _08182090 @ =0x00000484
	adds r1, r5, r4
	movs r0, #0
	str r0, [r1]
	ldr r0, _08182094 @ =0x0000046C
	adds r1, r5, r0
	b _0818221A
	.align 2, 0
_08182084: .4byte 0x000003FF
_08182088: .4byte 0x00000469
_0818208C: .4byte 0x0000046A
_08182090: .4byte 0x00000484
_08182094: .4byte 0x0000046C
_08182098:
	movs r2, #1
	ldr r1, _081820AC @ =0x00000898
	add r1, sl
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081820B0
	movs r0, #1
	b _081820B2
	.align 2, 0
_081820AC: .4byte 0x00000898
_081820B0:
	movs r0, #0
_081820B2:
	cmp r0, #0
	beq _081820F0
	ldr r1, _081820E8 @ =0x03002BE0
	ldr r2, _081820EC @ =0x000004A4
	adds r0, r5, r2
	ldr r4, [r0]
	ldr r0, [r1]
	adds r6, r0, #0
	adds r6, #0x2c
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl FUN_0823599c
	cmp r0, #0
	beq _0818214E
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl FUN_08235f40
	cmp r0, #0
	bne _0818213E
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r5, r4
	b _08182154
	.align 2, 0
_081820E8: .4byte 0x03002BE0
_081820EC: .4byte 0x000004A4
_081820F0:
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08182100
	movs r0, #1
	b _08182102
_08182100:
	movs r0, #0
_08182102:
	cmp r0, #0
	beq _0818215C
	ldr r1, _08182128 @ =0x000004A4
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r6, _0818212C @ =0x00000854
	add r6, sl
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08182130
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _08182154
	.align 2, 0
_08182128: .4byte 0x000004A4
_0818212C: .4byte 0x00000854
_08182130:
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0818214E
_0818213E:
	cmp r0, #2
	beq _0818215C
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _0818215C
_0818214E:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_08182154:
	ldr r1, _081821A0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_0818215C:
	ldr r4, _081821A4 @ =0x000004A4
	adds r0, r5, r4
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x1c
	ldrh r0, [r0, #0x1c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	add r3, sp, #8
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	mov r2, r8
	strh r0, [r2, #4]
	movs r4, #0
	ldrsh r0, [r3, r4]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	ldrb r1, [r5, #5]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _081821AC
	ldr r4, _081821A8 @ =0xFFFFFF00
	adds r1, r1, r4
	b _081821BA
	.align 2, 0
_081821A0: .4byte 0xFFFFFDFF
_081821A4: .4byte 0x000004A4
_081821A8: .4byte 0xFFFFFF00
_081821AC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081821BA
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_081821BA:
	adds r0, r1, #0
	cmp r0, #0
	bge _081821C2
	rsbs r0, r0, #0
_081821C2:
	cmp r0, #0x1f
	bgt _081821F8
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081821E8 @ =0x00000469
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _081821EC @ =0x0000046A
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _081821F0 @ =0x00000484
	adds r0, r5, r4
	str r1, [r0]
	ldr r0, _081821F4 @ =0x0000046C
	adds r1, r5, r0
	b _0818221A
	.align 2, 0
_081821E8: .4byte 0x00000469
_081821EC: .4byte 0x0000046A
_081821F0: .4byte 0x00000484
_081821F4: .4byte 0x0000046C
_081821F8:
	movs r2, #0x15
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08182220 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _08182224 @ =0x0000046A
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08182228 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
_0818221A:
	movs r0, #1
	strb r0, [r1]
	b _08182230
	.align 2, 0
_08182220: .4byte 0x00000469
_08182224: .4byte 0x0000046A
_08182228: .4byte 0x00000484
_0818222C:
	adds r0, r1, #1
	str r0, [r2]
_08182230:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08182240
FUN_08182240: @ 0x08182240
	ldr r1, _0818224C @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _08182250 @ =0x085ADB94
	str r1, [r0]
	bx lr
	.align 2, 0
_0818224C: .4byte 0x0000063C
_08182250: .4byte 0x085ADB94

	thumb_func_start FUN_08182254
FUN_08182254: @ 0x08182254
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r2, _0818227C @ =0x00000898
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08182280
	movs r0, #1
	b _08182282
	.align 2, 0
_0818227C: .4byte 0x00000898
_08182280:
	movs r0, #0
_08182282:
	cmp r0, #0
	beq _08182308
	adds r0, r5, #0
	bl FUN_0817e404
	ldr r3, _081822EC @ =0x00000898
	adds r2, r6, r3
	ldr r1, _081822F0 @ =0xFFFFCFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r6, _081822F4 @ =0x000005CC
	adds r0, r5, r6
	ldr r3, [r0]
	movs r1, #0x12
	ldr r7, _081822F8 @ =0x0000046D
	adds r0, r5, r7
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081822FC @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	subs r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	subs r7, #0xea
	adds r0, r5, r7
	strb r3, [r0]
	ldr r1, _08182300 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _08182304 @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #4
	adds r0, r5, r6
	strb r4, [r0]
	movs r0, #1
	b _08182408
	.align 2, 0
_081822EC: .4byte 0x00000898
_081822F0: .4byte 0xFFFFCFFF
_081822F4: .4byte 0x000005CC
_081822F8: .4byte 0x0000046D
_081822FC: .4byte 0x0000046B
_08182300: .4byte 0x0000046A
_08182304: .4byte 0x00000484
_08182308:
	movs r2, #0x80
	lsls r2, r2, #1
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r1, r5, r7
	ldrh r0, [r1]
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	bne _081823FC
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r2, _08182330 @ =0x00000898
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08182334
	movs r0, #1
	b _08182336
	.align 2, 0
_08182330: .4byte 0x00000898
_08182334:
	movs r0, #0
_08182336:
	cmp r0, #0
	bne _081823FC
	movs r7, #0xc9
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _081823FC
	ldr r2, _081823E0 @ =0x0000048C
	adds r0, r5, r2
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081823FC
	ldr r7, _081823E4 @ =0x0000089E
	adds r2, r6, r7
	ldrb r0, [r2]
	cmp r0, #0
	beq _08182370
	ldr r1, _081823E8 @ =0x0000089D
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08182374
_08182370:
	movs r0, #0xb4
	strb r0, [r2]
_08182374:
	ldr r2, _081823E8 @ =0x0000089D
	adds r2, r2, r6
	mov ip, r2
	ldrb r0, [r2]
	cmp r0, #1
	bls _081823FC
	ldr r3, _081823EC @ =0x000005CC
	adds r0, r5, r3
	ldr r2, [r0]
	movs r1, #0x12
	ldr r7, _081823F0 @ =0x0000046D
	adds r0, r5, r7
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	subs r7, #2
	adds r0, r5, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r2, #0
	strh r3, [r0]
	movs r1, #3
	subs r7, #0xeb
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _081823F4 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r7, #2
	adds r0, r5, r7
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r3, [r0]
	ldr r3, _081823F8 @ =0x0000046C
	adds r0, r5, r3
	strb r4, [r0]
	ldr r7, _081823E4 @ =0x0000089E
	adds r0, r6, r7
	strb r2, [r0]
	mov r0, ip
	strb r2, [r0]
	movs r0, #1
	b _08182408
	.align 2, 0
_081823E0: .4byte 0x0000048C
_081823E4: .4byte 0x0000089E
_081823E8: .4byte 0x0000089D
_081823EC: .4byte 0x000005CC
_081823F0: .4byte 0x0000046D
_081823F4: .4byte 0x00000469
_081823F8: .4byte 0x0000046C
_081823FC:
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r0, #0
_08182408:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08182410
FUN_08182410: @ 0x08182410
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _08182430 @ =0x0000046C
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08182434
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08182436
	.align 2, 0
_08182430: .4byte 0x0000046C
_08182434:
	movs r0, #0
_08182436:
	cmp r0, #0
	beq _081824FA
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _081824B8 @ =0x0000046D
	adds r0, r6, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _081824BC @ =0x0000046B
	adds r0, r6, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	ldr r1, _081824C0 @ =0x00000256
	adds r0, r6, r1
	ldrh r7, [r0]
	ldr r2, _081824C4 @ =0x000004A4
	adds r0, r6, r2
	ldr r5, [r0]
	movs r4, #0x1c
	adds r4, r4, r5
	mov sl, r4
	ldr r0, _081824C8 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r5, #0x1c]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081824CC
	adds r0, #4
	b _081824D8
	.align 2, 0
_081824B8: .4byte 0x0000046D
_081824BC: .4byte 0x0000046B
_081824C0: .4byte 0x00000256
_081824C4: .4byte 0x000004A4
_081824C8: .4byte 0x030046A4
_081824CC:
	mov r4, r8
	ldr r0, [r4]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081824D8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sl
	strh r0, [r1, #2]
	mov r2, sb
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r4, _08182554 @ =0x000004A4
	adds r0, r6, r4
	ldr r2, [r0]
	ldr r0, [r2, #0x1c]
	ldr r1, [r2, #0x20]
	str r0, [r2, #0xc]
	str r1, [r2, #0x10]
_081824FA:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0818251C
	adds r0, r6, #0
	bl FUN_0817ba7c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0818251C
	b _08182656
_0818251C:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_080ef86c
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r2, _08182558 @ =0x0000A02F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r6, r4
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _08182560
	ldr r0, _0818255C @ =0x00000482
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08182570
	.align 2, 0
_08182554: .4byte 0x000004A4
_08182558: .4byte 0x0000A02F
_0818255C: .4byte 0x00000482
_08182560:
	ldr r1, _08182594 @ =0x00000482
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08182570
	movs r0, #1
	strh r0, [r2]
_08182570:
	ldr r4, _08182598 @ =0x0000025D
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818259C
	ldr r4, [r6, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _081825B4
	.align 2, 0
_08182594: .4byte 0x00000482
_08182598: .4byte 0x0000025D
_0818259C:
	ldr r4, [r6, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_081825B4:
	ldr r1, _08182634 @ =0x000004A4
	adds r0, r6, r1
	ldr r1, [r0]
	str r7, [sp]
	adds r0, r6, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_0817d204
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _0818264C
	movs r1, #0x80
	lsls r1, r1, #0xe
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818260E
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r2, r6, r4
	ldr r1, _08182638 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _0818263C @ =0xFFFFFDFF
	ldrh r0, [r5]
	ands r1, r0
	movs r2, #0
	movs r3, #0
	strh r1, [r5]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _08182640 @ =0x0000021E
	adds r0, r6, r2
	strh r3, [r0]
	adds r4, #0x86
	adds r0, r6, r4
	strh r3, [r0]
_0818260E:
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08182644 @ =0x00000469
	adds r0, r6, r2
	strb r1, [r0]
	ldr r4, _08182648 @ =0x0000046A
	adds r0, r6, r4
	strb r1, [r0]
	adds r2, #0x1b
	adds r0, r6, r2
	str r1, [r0]
	adds r4, #2
	adds r1, r6, r4
	movs r0, #1
	strb r0, [r1]
	b _08182656
	.align 2, 0
_08182634: .4byte 0x000004A4
_08182638: .4byte 0xFEFFFFFF
_0818263C: .4byte 0xFFFFFDFF
_08182640: .4byte 0x0000021E
_08182644: .4byte 0x00000469
_08182648: .4byte 0x0000046A
_0818264C:
	ldr r0, _08182668 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08182656:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08182668: .4byte 0x00000484

	thumb_func_start FUN_0818266c
FUN_0818266c: @ 0x0818266C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08182690 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08182694
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08182696
	.align 2, 0
_08182690: .4byte 0x0000046C
_08182694:
	movs r0, #0
_08182696:
	cmp r0, #0
	beq _081826CE
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _08182728 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _0818272C @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_0817ce48
_081826CE:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081826F0
	adds r0, r5, #0
	bl FUN_0817ba7c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081826F0
	b _081829D8
_081826F0:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ef86c
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	mov r8, r0
	ldr r2, _08182730 @ =0x0000A02F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r5, r4
	ldrh r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _08182738
	ldr r0, _08182734 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08182748
	.align 2, 0
_08182728: .4byte 0x0000046D
_0818272C: .4byte 0x0000046B
_08182730: .4byte 0x0000A02F
_08182734: .4byte 0x00000482
_08182738:
	ldr r1, _0818276C @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08182748
	movs r0, #1
	strh r0, [r2]
_08182748:
	ldr r4, _08182770 @ =0x0000025D
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08182774
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _0818278C
	.align 2, 0
_0818276C: .4byte 0x00000482
_08182770: .4byte 0x0000025D
_08182774:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_0818278C:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, _081827B0 @ =0x0000FFFE
	cmp r1, r0
	bhi _081827F4
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r1, [r0]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081827B8
	ldr r4, _081827B4 @ =0xFFFFFF00
	adds r1, r1, r4
	b _081827C6
	.align 2, 0
_081827B0: .4byte 0x0000FFFE
_081827B4: .4byte 0xFFFFFF00
_081827B8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081827C6
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_081827C6:
	cmp r1, #0
	bge _081827CC
	rsbs r1, r1, #0
_081827CC:
	cmp r1, #0x1f
	bgt _081827DC
	ldr r2, _081827D8 @ =0x0000087C
	adds r1, r6, r2
	b _081827E2
	.align 2, 0
_081827D8: .4byte 0x0000087C
_081827DC:
	movs r4, #0x88
	lsls r4, r4, #4
	adds r1, r6, r4
_081827E2:
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_0817ba7c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081827F4
	b _081829D8
_081827F4:
	ldr r1, _08182868 @ =0x000004A4
	adds r0, r5, r1
	ldr r1, [r0]
	mov r2, r8
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_0817d204
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	beq _08182812
	b _081829CE
_08182812:
	movs r1, #0x80
	lsls r1, r1, #0xe
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r0, r5, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08182852
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _0818286C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08182870 @ =0xFFFFFDFF
	ldrh r0, [r7]
	ands r1, r0
	movs r2, #0
	movs r3, #0
	strh r1, [r7]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _08182874 @ =0x0000021E
	adds r0, r5, r2
	strh r3, [r0]
	adds r4, #0x8a
	adds r0, r5, r4
	strh r3, [r0]
_08182852:
	movs r2, #0x80
	lsls r2, r2, #7
	ldr r0, _08182878 @ =0x00000898
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _0818287C
	movs r0, #1
	b _0818287E
	.align 2, 0
_08182868: .4byte 0x000004A4
_0818286C: .4byte 0xFEFFFFFF
_08182870: .4byte 0xFFFFFDFF
_08182874: .4byte 0x0000021E
_08182878: .4byte 0x00000898
_0818287C:
	movs r0, #0
_0818287E:
	adds r4, r0, #0
	cmp r4, #0
	beq _08182970
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xb
	cmp r1, r0
	bhi _08182922
	ldrh r0, [r5, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081828B8
	cmp r1, #0
	blt _081828B8
	ldr r0, _081828BC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081828B8
	ldr r0, _081828C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081828C4
_081828B8:
	movs r4, #0
	b _081828D2
	.align 2, 0
_081828BC: .4byte 0x030046A8
_081828C0: .4byte 0x030046AC
_081828C4:
	ldr r0, _08182900 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081828D2:
	ldr r1, _08182904 @ =0x00000854
	adds r0, r6, r1
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081828FA
	cmp r1, #0
	blt _081828FA
	ldr r0, _08182908 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081828FA
	ldr r0, _0818290C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08182910
_081828FA:
	movs r0, #0
	b _0818291E
	.align 2, 0
_08182900: .4byte 0x030046A4
_08182904: .4byte 0x00000854
_08182908: .4byte 0x030046A8
_0818290C: .4byte 0x030046AC
_08182910:
	ldr r0, _08182954 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0818291E:
	cmp r4, r0
	bne _08182960
_08182922:
	movs r2, #0x14
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	adds r4, #1
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #1
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08182958 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r4, #2
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0818295C @ =0xFFFFBFFF
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	b _081829D8
	.align 2, 0
_08182954: .4byte 0x030046A4
_08182958: .4byte 0x00000484
_0818295C: .4byte 0xFFFFBFFF
_08182960:
	ldr r0, _0818296C @ =0x00000854
	adds r1, r6, r0
	adds r0, r5, #0
	bl FUN_0817ec04
	b _081829CE
	.align 2, 0
_0818296C: .4byte 0x00000854
_08182970:
	ldr r1, _0818298C @ =0x00000256
	adds r2, r5, r1
	ldr r0, _08182990 @ =0x03002BE0
	ldr r3, [r0]
	ldr r1, [r3, #0x3c]
	ldrh r0, [r2]
	ldrh r1, [r1, #6]
	cmp r0, r1
	bne _08182994
	movs r2, #0x88
	lsls r2, r2, #4
	adds r0, r6, r2
	strh r4, [r0]
	b _081829CE
	.align 2, 0
_0818298C: .4byte 0x00000256
_08182990: .4byte 0x03002BE0
_08182994:
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r3, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081829C4
	ldr r0, _081829C0 @ =0x00000854
	adds r4, r6, r0
	adds r2, r3, #0
	adds r2, #0x2c
	movs r3, #0x80
	lsls r3, r3, #0xf
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0817e910
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0817ec04
	b _081829CE
	.align 2, 0
_081829C0: .4byte 0x00000854
_081829C4:
	adds r1, r3, #0
	adds r1, #0x2c
	adds r0, r5, #0
	bl FUN_0817ec04
_081829CE:
	ldr r2, _081829E4 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081829D8:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081829E4: .4byte 0x00000484

	thumb_func_start FUN_081829e8
FUN_081829e8: @ 0x081829E8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _08182A0C @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08182A10
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08182A12
	.align 2, 0
_08182A0C: .4byte 0x0000046C
_08182A10:
	movs r0, #0
_08182A12:
	cmp r0, #0
	beq _08182A90
	ldr r3, _08182A68 @ =0x000005A4
	adds r0, r4, r3
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _08182A6C @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08182A70 @ =0x0000046B
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
	ldr r2, _08182A74 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08182A78 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08182A7C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x3f
	bgt _08182A84
	movs r2, #0x80
	lsls r2, r2, #0xc
	ldr r3, _08182A80 @ =0x00000898
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08182A90
	.align 2, 0
_08182A68: .4byte 0x000005A4
_08182A6C: .4byte 0x0000046D
_08182A70: .4byte 0x0000046B
_08182A74: .4byte 0x030046B8
_08182A78: .4byte 0x000003FF
_08182A7C: .4byte 0x0203B400
_08182A80: .4byte 0x00000898
_08182A84:
	ldr r0, _08182AC8 @ =0x00000898
	adds r2, r5, r0
	ldr r1, _08182ACC @ =0xFFF7FFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08182A90:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08182AB2
	adds r0, r4, #0
	bl FUN_0817ba7c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08182AB2
	b _08182D10
_08182AB2:
	movs r2, #0x80
	lsls r2, r2, #0xc
	ldr r3, _08182AC8 @ =0x00000898
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _08182AD0
	movs r0, #1
	b _08182AD2
	.align 2, 0
_08182AC8: .4byte 0x00000898
_08182ACC: .4byte 0xFFF7FFFF
_08182AD0:
	movs r0, #0
_08182AD2:
	movs r2, #4
	cmp r0, #0
	beq _08182ADA
	movs r2, #8
_08182ADA:
	movs r1, #0x80
	lsls r1, r1, #8
	mov r3, r8
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08182AEC
	movs r0, #1
	b _08182AEE
_08182AEC:
	movs r0, #0
_08182AEE:
	adds r1, r2, #0
	cmp r0, #0
	beq _08182AF6
	asrs r1, r1, #1
_08182AF6:
	ldr r0, _08182B14 @ =0x00000484
	adds r2, r4, r0
	ldr r0, [r2]
	cmp r0, r1
	bgt _08182B02
	b _08182D0C
_08182B02:
	movs r1, #1
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08182B18
	movs r0, #1
	b _08182B1A
	.align 2, 0
_08182B14: .4byte 0x00000484
_08182B18:
	movs r0, #0
_08182B1A:
	cmp r0, #0
	beq _08182B6C
	adds r0, r4, #0
	bl FUN_0817e02c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08182B2C
	b _08182D10
_08182B2C:
	ldr r1, _08182B54 @ =0x03002BE0
	ldr r3, _08182B58 @ =0x000004A4
	adds r0, r4, r3
	ldr r6, [r0]
	adds r7, r4, #0
	adds r7, #8
	ldr r0, [r1]
	adds r5, r0, #0
	adds r5, #0x2c
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08182B5C
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	b _08182BD8
	.align 2, 0
_08182B54: .4byte 0x03002BE0
_08182B58: .4byte 0x000004A4
_08182B5C:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	bne _08182BC2
	b _08182BD2
_08182B6C:
	movs r1, #0x80
	lsls r1, r1, #7
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08182B7E
	movs r0, #1
	b _08182B80
_08182B7E:
	movs r0, #0
_08182B80:
	adds r2, r0, #0
	cmp r2, #0
	beq _08182C10
	ldr r3, _08182BAC @ =0x000004A4
	adds r0, r4, r3
	ldr r6, [r0]
	adds r7, r4, #0
	adds r7, #8
	ldr r0, _08182BB0 @ =0x00000854
	adds r5, r5, r0
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08182BB4
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	b _08182BD8
	.align 2, 0
_08182BAC: .4byte 0x000004A4
_08182BB0: .4byte 0x00000854
_08182BB4:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08182BD2
_08182BC2:
	cmp r0, #2
	beq _08182BE0
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08182BE0
_08182BD2:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
_08182BD8:
	ldr r1, _08182C08 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08182BE0:
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _08182C0C @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _08182D10
	.align 2, 0
_08182C08: .4byte 0xFFFFFDFF
_08182C0C: .4byte 0x00000484
_08182C10:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xb
	cmp r1, r0
	bls _08182C5C
	movs r1, #0x14
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08182C50 @ =0x00000484
	adds r0, r4, r1
	str r2, [r0]
	ldr r2, _08182C54 @ =0x0000046C
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08182C58 @ =0xFFFFBFFF
	mov r3, r8
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	b _08182D10
	.align 2, 0
_08182C50: .4byte 0x00000484
_08182C54: .4byte 0x0000046C
_08182C58: .4byte 0xFFFFBFFF
_08182C5C:
	ldr r0, _08182C94 @ =0x00000854
	adds r5, r5, r0
	ldr r0, _08182C98 @ =0x03002BE0
	ldr r2, [r0]
	adds r2, #0x2c
	movs r3, #0x90
	lsls r3, r3, #0xc
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0817e910
	ldr r1, _08182C9C @ =0x000004A4
	adds r0, r4, r1
	ldr r6, [r0]
	adds r7, r4, #0
	adds r7, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08182CA0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	b _08182CC4
	.align 2, 0
_08182C94: .4byte 0x00000854
_08182C98: .4byte 0x03002BE0
_08182C9C: .4byte 0x000004A4
_08182CA0:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08182CBE
	cmp r0, #2
	beq _08182CCC
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08182CCC
_08182CBE:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r4, r3
_08182CC4:
	ldr r1, _08182D00 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08182CCC:
	movs r2, #2
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08182D04 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _08182D08 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #7
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	b _08182D0E
	.align 2, 0
_08182D00: .4byte 0xFFFFFDFF
_08182D04: .4byte 0x00000469
_08182D08: .4byte 0x00000484
_08182D0C:
	adds r0, #1
_08182D0E:
	str r0, [r2]
_08182D10:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08182d1c
FUN_08182d1c: @ 0x08182D1C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08182D3C @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08182D40
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08182D42
	.align 2, 0
_08182D3C: .4byte 0x0000046C
_08182D40:
	movs r0, #0
_08182D42:
	cmp r0, #0
	beq _08182D7A
	ldr r4, _08182DC4 @ =FUN_0817fd8c
	movs r3, #0x28
	ldr r0, _08182DC8 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08182DCC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #8
	ldr r0, _08182DD0 @ =0x00000898
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08182D7A:
	ldr r2, _08182DD4 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	cmp r0, #0x1e
	ble _08182DDC
	adds r0, r5, #0
	bl FUN_0817ba7c
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08182DB4
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #0x1a
	adds r0, r5, r2
	str r1, [r0]
	ldr r0, _08182DD8 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08182DB4:
	ldr r1, _08182DD0 @ =0x00000898
	adds r2, r6, r1
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _08182DE0
	.align 2, 0
_08182DC4: .4byte FUN_0817fd8c
_08182DC8: .4byte 0x0000046D
_08182DCC: .4byte 0x0000046B
_08182DD0: .4byte 0x00000898
_08182DD4: .4byte 0x00000484
_08182DD8: .4byte 0x0000046C
_08182DDC:
	adds r0, #1
	str r0, [r1]
_08182DE0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08182de8
FUN_08182de8: @ 0x08182DE8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08182E08 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08182E0C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08182E0E
	.align 2, 0
_08182E08: .4byte 0x0000046C
_08182E0C:
	movs r0, #0
_08182E0E:
	cmp r0, #0
	beq _08182E3A
	ldr r4, _08182E74 @ =FUN_08180494
	movs r3, #0x2c
	ldr r0, _08182E78 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08182E7C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08182E3A:
	ldr r2, _08182E80 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	cmp r0, #0x1e
	ble _08182E8C
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	subs r2, #0x1b
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #0x1a
	adds r0, r5, r2
	str r1, [r0]
	ldr r1, _08182E84 @ =0x0000046C
	adds r0, r5, r1
	movs r2, #1
	strb r2, [r0]
	ldr r0, _08182E88 @ =0x00000898
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	b _08182E8E
	.align 2, 0
_08182E74: .4byte FUN_08180494
_08182E78: .4byte 0x0000046D
_08182E7C: .4byte 0x0000046B
_08182E80: .4byte 0x00000484
_08182E84: .4byte 0x0000046C
_08182E88: .4byte 0x00000898
_08182E8C:
	adds r0, #1
_08182E8E:
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08182e98
FUN_08182e98: @ 0x08182E98
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08182EB8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08182EBC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08182EBE
	.align 2, 0
_08182EB8: .4byte 0x0000046C
_08182EBC:
	movs r0, #0
_08182EBE:
	cmp r0, #0
	beq _08182EEC
	ldr r4, _08182F2C @ =FUN_08180314
	movs r3, #0x29
	ldr r0, _08182F30 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08182F34 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08182EEC:
	ldr r2, _08182F34 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08182FD8
	ldr r3, _08182F38 @ =0x00000898
	adds r2, r6, r3
	ldr r1, _08182F3C @ =0xFFFFDFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08182F40 @ =0x03002BE0
	ldr r6, _08182F44 @ =0x000004A4
	adds r0, r5, r6
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	ldr r0, [r1]
	adds r4, r0, #0
	adds r4, #0x2c
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08182F48
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	b _08182F6C
	.align 2, 0
_08182F2C: .4byte FUN_08180314
_08182F30: .4byte 0x0000046D
_08182F34: .4byte 0x0000046B
_08182F38: .4byte 0x00000898
_08182F3C: .4byte 0xFFFFDFFF
_08182F40: .4byte 0x03002BE0
_08182F44: .4byte 0x000004A4
_08182F48:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08182F66
	cmp r0, #2
	beq _08182F74
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08182F74
_08182F66:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
_08182F6C:
	ldr r1, _08182FC4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08182F74:
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r2, #0
	strb r2, [r0]
	ldr r6, _08182FC8 @ =0x00000469
	adds r0, r5, r6
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	ldr r1, _08182FCC @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r4, _08182FD0 @ =FUN_080e48d0
	movs r3, #0x10
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08182FD4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	b _08182FE2
	.align 2, 0
_08182FC4: .4byte 0xFFFFFDFF
_08182FC8: .4byte 0x00000469
_08182FCC: .4byte 0x0000046C
_08182FD0: .4byte FUN_080e48d0
_08182FD4: .4byte 0x0000046B
_08182FD8:
	ldr r6, _08182FE8 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08182FE2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08182FE8: .4byte 0x00000484

	thumb_func_start FUN_08182fec
FUN_08182fec: @ 0x08182FEC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08183014 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08183018
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818301A
	.align 2, 0
_08183014: .4byte 0x0000046C
_08183018:
	movs r0, #0
_0818301A:
	cmp r0, #0
	beq _08183054
	ldr r4, _081830A0 @ =FUN_081807dc
	movs r3, #0x26
	ldr r0, _081830A4 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081830A8 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0x20
	ldr r1, _081830AC @ =0x00000898
	add r1, r8
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08183054:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0818306A
	b _081831B0
_0818306A:
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r0, _081830B0 @ =0x00000482
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	ldr r1, _081830B4 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081830B8
	ldr r3, _081830B0 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081830C8
	.align 2, 0
_081830A0: .4byte FUN_081807dc
_081830A4: .4byte 0x0000046D
_081830A8: .4byte 0x0000046B
_081830AC: .4byte 0x00000898
_081830B0: .4byte 0x00000482
_081830B4: .4byte 0x0000A02F
_081830B8:
	ldr r1, _081830EC @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081830C8
	movs r0, #1
	strh r0, [r2]
_081830C8:
	ldr r3, _081830F0 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081830F4
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _0818310C
	.align 2, 0
_081830EC: .4byte 0x00000482
_081830F0: .4byte 0x0000025D
_081830F4:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_0818310C:
	ldr r0, _08183160 @ =0x000004A4
	adds r4, r5, r0
	ldr r0, [r4]
	bl FUN_08235fd8
	adds r6, r0, #0
	cmp r6, #0
	bne _0818316C
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081831A6
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _08183164 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r6, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r6, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	movs r2, #0x10
	ldr r1, _08183168 @ =0x00000898
	add r1, r8
	ldr r0, [r1]
	orrs r0, r2
	b _081831AE
	.align 2, 0
_08183160: .4byte 0x000004A4
_08183164: .4byte 0x00000469
_08183168: .4byte 0x00000898
_0818316C:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081831A6
	movs r2, #0x10
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081831BC @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081831C0 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_081831A6:
	ldr r0, _081831C0 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
_081831AE:
	str r0, [r1]
_081831B0:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081831BC: .4byte 0x00000469
_081831C0: .4byte 0x00000484

	thumb_func_start FUN_081831c4
FUN_081831c4: @ 0x081831C4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081831DC @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081831E0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081831E2
	.align 2, 0
_081831DC: .4byte 0x0000046C
_081831E0:
	movs r0, #0
_081831E2:
	cmp r0, #0
	beq _08183216
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _0818325C @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08183260 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08183216:
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08183272
	ldr r1, _08183260 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08183268
	movs r1, #0xf
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _08183264 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08183272
	.align 2, 0
_0818325C: .4byte 0x0000046D
_08183260: .4byte 0x0000046B
_08183264: .4byte 0x00000484
_08183268:
	ldr r0, _08183278 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08183272:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08183278: .4byte 0x00000484

	thumb_func_start FUN_0818327c
FUN_0818327c: @ 0x0818327C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08183294 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08183298
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818329A
	.align 2, 0
_08183294: .4byte 0x0000046C
_08183298:
	movs r0, #0
_0818329A:
	cmp r0, #0
	beq _081832CE
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _0818333C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08183340 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08183344 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
_081832CE:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0818335E
	ldr r2, _08183340 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08183354
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _08183348 @ =0x00000469
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _0818334C @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r2, [r0]
	ldr r3, _08183350 @ =FUN_0818069c
	movs r1, #0x27
	adds r6, #1
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _08183340 @ =0x0000046B
	adds r0, r5, r2
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	b _0818335E
	.align 2, 0
_0818333C: .4byte 0x0000046D
_08183340: .4byte 0x0000046B
_08183344: .4byte 0x00000553
_08183348: .4byte 0x00000469
_0818334C: .4byte 0x0000046A
_08183350: .4byte FUN_0818069c
_08183354:
	ldr r3, _08183364 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818335E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08183364: .4byte 0x00000484

	thumb_func_start FUN_08183368
FUN_08183368: @ 0x08183368
	ldr r1, _08183374 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _08183378 @ =0x085ADBA4
	str r1, [r0]
	bx lr
	.align 2, 0
_08183374: .4byte 0x00000634
_08183378: .4byte 0x085ADBA4

	thumb_func_start FUN_0818337c
FUN_0818337c: @ 0x0818337C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0817ee6c
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _081833B4 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
	adds r0, r4, #0
	bl FUN_0817ee94
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081833B4: .4byte 0x0000062C

	thumb_func_start FUN_081833b8
FUN_081833b8: @ 0x081833B8
	push {lr}
	ldr r1, _081833D8 @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r1, r1, r2
	ldr r2, [r1]
	movs r3, #0x92
	lsls r3, r3, #3
	adds r1, r0, r3
	strh r2, [r1]
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_081833D8: .4byte 0x030046A0

	thumb_func_start FUN_081833dc
FUN_081833dc: @ 0x081833DC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _0818340C @ =0x0000044C
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _081833F8
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08013c70
	movs r0, #0xff
	strb r0, [r5]
_081833F8:
	ldr r2, _08183410 @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08183414
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _0818341C
	.align 2, 0
_0818340C: .4byte 0x0000044C
_08183410: .4byte 0x0000025D
_08183414:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_0818341C:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _08183438 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0818343C
	movs r0, #1
	b _0818343E
	.align 2, 0
_08183438: .4byte 0x00000474
_0818343C:
	movs r0, #0
_0818343E:
	cmp r0, #0
	beq _0818344A
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_0818344A:
	ldr r1, _081834A4 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _08183462
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_08183462:
	ldr r0, _081834A8 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0818347A
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_0818347A:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08183492
	adds r0, r4, #0
	bl FUN_08002a58
_08183492:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081834AC
	movs r0, #1
	b _081834AE
	.align 2, 0
_081834A4: .4byte 0x0000044C
_081834A8: .4byte 0x0000044D
_081834AC:
	movs r0, #0
_081834AE:
	cmp r0, #0
	beq _081834BA
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_081834BA:
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

	thumb_func_start EnemyCheyenne_Init
EnemyCheyenne_Init: @ 0x081834D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c0
	adds r7, r0, #0
	str r7, [sp, #0x30]
	str r7, [sp, #0x34]
	ldr r1, _08183564 @ =0x00000898
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #1
	bl FUN_080e37e8
	ldr r2, _08183568 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x1b
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0817b938
	ldr r3, _0818356C @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08183574
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08183570 @ =0x0000D3EA
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080e3804
	ldr r4, _08183568 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0xb0]
	cmp r1, #0x11
	beq _08183552
	cmp r1, #0x17
	bne _08183556
_08183552:
	movs r0, #1
	strb r0, [r5, #7]
_08183556:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _081835DC
	.align 2, 0
_08183564: .4byte 0x00000898
_08183568: .4byte 0x000001DF
_0818356C: .4byte 0x0000025D
_08183570: .4byte 0x0000D3EA
_08183574:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r0, sp, #0x20
	mov r8, r0
	str r6, [sp, #0x1c]
	add r0, sp, #0x1c
	mov r1, r8
	ldr r2, _08183658 @ =0x05000002
	bl CpuSet
	ldr r0, _0818365C @ =0x0000CB05
	ldr r1, _08183660 @ =0x0000D3EA
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl OpenSpriteSetFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r6, r8
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r0, _08183664 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _08183668 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0xb0]
_081835DC:
	str r7, [sp, #0x38]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0
	str r4, [r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r3, r3, r7
	mov r8, r3
	str r4, [r3]
	ldr r5, _0818366C @ =0x0000046F
	adds r0, r7, r5
	strb r4, [r0]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0
	mov sl, r0
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, _08183670 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x28
	str r4, [sp, #0x1c]
	add r0, sp, #0x1c
	adds r1, r5, #0
	ldr r2, _08183658 @ =0x05000002
	bl CpuSet
	ldr r3, _08183674 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1b8]
	bl prepare_08231510
	mov r1, sb
	str r1, [sp, #0x6c]
	mov r3, r8
	str r3, [sp, #0x74]
	str r6, [sp, #0x54]
	ldr r2, [sp, #0x1b8]
	adds r6, r2, #0
	cmp r0, #0
	bne _08183648
	b _081837A8
_08183648:
	bl VM_GetPC
	cmp r0, #0
	beq _08183678
	bl Script_GetValue
	adds r1, r0, #0
	b _0818367A
	.align 2, 0
_08183658: .4byte 0x05000002
_0818365C: .4byte 0x0000CB05
_08183660: .4byte 0x0000D3EA
_08183664: .4byte 0x000004B7
_08183668: .4byte 0x000001DF
_0818366C: .4byte 0x0000046F
_08183670: .4byte 0x00000474
_08183674: .4byte 0x000004B6
_08183678:
	movs r1, #0
_0818367A:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081836A0 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xd0]
	str r4, [sp, #0xd4]
	cmp r0, #0
	beq _081836A4
	bl Script_GetValue
	adds r1, r0, #0
	b _081836A6
	.align 2, 0
_081836A0: .4byte 0x00000251
_081836A4:
	movs r1, #0
_081836A6:
	ldr r2, _081836DC @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081836E0 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xd0]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xd8]
	cmp r0, #0
	beq _081836E4
	bl Script_GetValue
	b _081836E8
	.align 2, 0
_081836DC: .4byte 0x00000252
_081836E0: .4byte 0x000004B4
_081836E4:
	ldr r4, [sp, #0xd0]
	ldrb r0, [r4]
_081836E8:
	strb r0, [r6]
	ldr r5, [sp, #0xd0]
	ldrb r1, [r5]
	ldr r6, [sp, #0xd8]
	ldrb r2, [r6]
	add r0, sp, #0x28
	bl FUN_08234f90
	add r0, sp, #0x28
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08183720
	cmp r1, #0
	blt _08183720
	ldr r0, _08183724 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08183720
	ldr r0, _08183728 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0818372C
_08183720:
	movs r1, #0
	b _0818373A
	.align 2, 0
_08183724: .4byte 0x030046A8
_08183728: .4byte 0x030046AC
_0818372C:
	ldr r0, _08183754 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0818373A:
	ldr r2, _08183758 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x28
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818375C
	adds r0, #4
	b _08183768
	.align 2, 0
_08183754: .4byte 0x030046A4
_08183758: .4byte 0x00000256
_0818375C:
	ldr r0, _0818377C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08183768:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08183780
	cmp r2, #2
	beq _08183784
	b _08183788
	.align 2, 0
_0818377C: .4byte 0x030046A4
_08183780:
	ldrb r0, [r4, #4]
	b _08183786
_08183784:
	ldrb r0, [r4]
_08183786:
	subs r1, r1, r0
_08183788:
	ldr r3, _081837A0 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081837A4 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x2a]
	movs r6, #1
	str r6, [sp, #0x3c]
	b _081837E8
	.align 2, 0
_081837A0: .4byte 0x00000472
_081837A4: .4byte 0x0000FFFF
_081837A8:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _0818380C @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _08183810 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08183814 @ =0x000004B4
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
	str r0, [sp, #0x3c]
	str r5, [sp, #0xd0]
	str r4, [sp, #0xd4]
	str r3, [sp, #0xd8]
_081837E8:
	movs r0, #0x4e
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _08183832
	bl VM_GetPC
	cmp r0, #0
	beq _08183818
	bl Script_GetValue
	adds r4, r0, #0
	b _0818381A
	.align 2, 0
_0818380C: .4byte 0x00000251
_08183810: .4byte 0x00000252
_08183814: .4byte 0x000004B4
_08183818:
	movs r4, #0x30
_0818381A:
	bl VM_GetPC
	cmp r0, #0
	beq _0818382C
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0818382E
_0818382C:
	movs r5, #0x40
_0818382E:
	mov r8, r4
	b _08183838
_08183832:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08183838:
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08183870
	bl VM_GetPC
	cmp r0, #0
	beq _08183852
	bl Script_GetValue
	adds r6, r0, #0
	b _08183854
_08183852:
	movs r6, #0
_08183854:
	bl VM_GetPC
	cmp r0, #0
	beq _08183864
	bl Script_GetValue
	adds r1, r0, #0
	b _08183866
_08183864:
	movs r1, #0
_08183866:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _0818387A
_08183870:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_0818387A:
	movs r0, #0x61
	bl prepare_08231510
	ldr r1, _08183B00 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xec]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xc8]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x84]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x80]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	lsls r4, r4, #0x10
	str r4, [sp, #0xa4]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xac]
	lsls r6, r6, #0x10
	str r6, [sp, #0xb4]
	lsls r5, r5, #0x10
	str r5, [sp, #0xa8]
	ldr r4, _08183B04 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xe8]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x9c]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x1b0]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xbc]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x40]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x44]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x19c]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x70]
	ldr r1, _08183B08 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x60]
	ldr r2, _08183B0C @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x64]
	ldr r3, _08183B10 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x68]
	ldr r4, _08183B14 @ =0x00000476
	adds r4, r7, r4
	str r4, [sp, #0x58]
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	ldr r6, _08183B18 @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x90]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x94]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x114]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x11c]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x124]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x134]
	ldr r6, _08183B1C @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0x138]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x14c]
	ldr r2, _08183B20 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0x150]
	ldr r3, _08183B24 @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0x158]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x15c]
	ldr r5, _08183B28 @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0x160]
	ldr r6, _08183B2C @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x168]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x154]
	ldr r2, _08183B30 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0x118]
	ldr r3, _08183B34 @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x18c]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x190]
	ldr r5, _08183B38 @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0xc0]
	ldr r6, _08183B3C @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x194]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x17c]
	ldr r2, _08183B40 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x170]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x180]
	ldr r4, _08183B44 @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x184]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x188]
	ldr r6, _08183B48 @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x198]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x1a4]
	ldr r2, _08183B4C @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0x148]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x174]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x16c]
	ldr r5, _08183B50 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x178]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x164]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r2, _08183B54 @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x1a8]
	ldr r3, _08183B58 @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0x120]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x1ac]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x144]
	ldr r6, _08183B5C @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0x128]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x12c]
	ldr r2, _08183B60 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0x130]
	ldr r3, _08183B64 @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0x140]
	ldr r4, _08183B68 @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0xc4]
	ldr r5, [sp, #0x34]
	adds r5, #8
	str r5, [sp, #0x1a0]
	movs r6, #0xcc
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x88]
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	ldr r2, _08183B6C @ =0x00000496
	adds r2, r7, r2
	str r2, [sp, #0x7c]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x48]
	ldr r4, _08183B70 @ =0x00000469
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	ldr r5, _08183B74 @ =0x0000046A
	adds r5, r7, r5
	str r5, [sp, #0x50]
	ldr r6, _08183B78 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0xcc]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x110]
	movs r2, #0x92
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x78]
	movs r3, #0xea
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xa0]
	ldr r4, _08183B7C @ =0x00000572
	adds r4, r7, r4
	str r4, [sp, #0x10c]
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x98]
	movs r6, #0xae
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x108]
	ldr r1, _08183B80 @ =0x0000055C
	adds r1, r7, r1
	str r1, [sp, #0xe0]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	ldr r3, _08183B84 @ =0x00000564
	adds r3, r7, r3
	str r3, [sp, #0xf0]
	ldr r4, _08183B88 @ =0x00000565
	adds r4, r7, r4
	str r4, [sp, #0xf4]
	ldr r5, _08183B8C @ =0x00000566
	adds r5, r7, r5
	str r5, [sp, #0xf8]
	ldr r6, _08183B90 @ =0x00000567
	adds r6, r7, r6
	str r6, [sp, #0xfc]
	movs r1, #0xad
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x100]
	ldr r2, _08183B94 @ =0x0000056C
	adds r2, r7, r2
	str r2, [sp, #0x104]
	cmp r0, #0
	bne _08183AD0
	b _08183BF0
_08183AD0:
	movs r3, #0
	mov sl, r3
	movs r4, #0x8d
	lsls r4, r4, #2
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r5, r5, r7
	mov r8, r5
	movs r6, #0x8b
	lsls r6, r6, #2
	adds r5, r7, r6
	movs r0, #0x89
	lsls r0, r0, #2
	adds r4, r7, r0
_08183AF0:
	bl VM_GetPC
	cmp r0, #0
	beq _08183B98
	bl Script_GetValue
	b _08183B9A
	.align 2, 0
_08183B00: .4byte 0x0000025D
_08183B04: .4byte 0x0000025A
_08183B08: .4byte 0x0000047A
_08183B0C: .4byte 0x0000047C
_08183B10: .4byte 0x0000047E
_08183B14: .4byte 0x00000476
_08183B18: .4byte 0x000004A4
_08183B1C: .4byte 0x000005A4
_08183B20: .4byte 0x000005C4
_08183B24: .4byte 0x000005CC
_08183B28: .4byte 0x000005D4
_08183B2C: .4byte 0x000005DC
_08183B30: .4byte 0x00000584
_08183B34: .4byte 0x00000604
_08183B38: .4byte 0x0000021D
_08183B3C: .4byte 0x0000060C
_08183B40: .4byte 0x000005E4
_08183B44: .4byte 0x000005FC
_08183B48: .4byte 0x00000614
_08183B4C: .4byte 0x000005BC
_08183B50: .4byte 0x000005EC
_08183B54: .4byte 0x00000624
_08183B58: .4byte 0x0000058C
_08183B5C: .4byte 0x00000594
_08183B60: .4byte 0x0000059C
_08183B64: .4byte 0x000005B4
_08183B68: .4byte 0x00000543
_08183B6C: .4byte 0x00000496
_08183B70: .4byte 0x00000469
_08183B74: .4byte 0x0000046A
_08183B78: .4byte 0x00000553
_08183B7C: .4byte 0x00000572
_08183B80: .4byte 0x0000055C
_08183B84: .4byte 0x00000564
_08183B88: .4byte 0x00000565
_08183B8C: .4byte 0x00000566
_08183B90: .4byte 0x00000567
_08183B94: .4byte 0x0000056C
_08183B98:
	movs r0, #0x18
_08183B9A:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08183BAC
	bl Script_GetValue
	b _08183BAE
_08183BAC:
	movs r0, #0x18
_08183BAE:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08183BC0
	bl Script_GetValue
	b _08183BC2
_08183BC0:
	movs r0, #0
_08183BC2:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08183BD4
	bl Script_GetValue
	b _08183BD6
_08183BD4:
	movs r0, #0
_08183BD6:
	strh r0, [r6]
	movs r1, #2
	add sb, r1
	movs r2, #4
	add r8, r2
	adds r5, #2
	adds r4, #2
	movs r3, #1
	add sl, r3
	mov r6, sl
	cmp r6, #3
	bgt _08183BF0
	b _08183AF0
_08183BF0:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _08183C3C
	bl VM_GetPC
	cmp r0, #0
	beq _08183C0A
	bl Script_GetValue
	adds r4, r0, #0
	b _08183C0E
_08183C0A:
	movs r4, #0x96
	lsls r4, r4, #1
_08183C0E:
	bl VM_GetPC
	cmp r0, #0
	beq _08183C1E
	bl Script_GetValue
	adds r6, r0, #0
	b _08183C22
_08183C1E:
	movs r6, #0x96
	lsls r6, r6, #1
_08183C22:
	bl VM_GetPC
	cmp r0, #0
	beq _08183C30
	bl Script_GetValue
	b _08183C36
_08183C30:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_08183C36:
	ldr r2, [sp, #0xc8]
	strh r0, [r2]
	b _08183C44
_08183C3C:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0xc8]
	strh r6, [r3]
_08183C44:
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _08183C5C
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x74]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08183C5C:
	movs r0, #0x46
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0x84]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, [sp, #0x80]
	strh r0, [r2]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _08183D2C
	bl VM_GetPC
	cmp r0, #0
	beq _08183C8C
	bl Script_GetValue
	b _08183C8E
_08183C8C:
	movs r0, #0
_08183C8E:
	ldr r3, [sp, #0xdc]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _08183C9C
	asrs r1, r0, #1
	b _08183CA2
_08183C9C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08183CA2:
	ldr r5, _08183CB8 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08183CBC
	bl Script_GetValue
	b _08183CBE
	.align 2, 0
_08183CB8: .4byte 0x00000546
_08183CBC:
	movs r0, #0
_08183CBE:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08183CD4
	bl Script_GetValue
	b _08183CD6
_08183CD4:
	movs r0, #0
_08183CD6:
	ldr r3, _08183CEC @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08183CF0
	bl Script_GetValue
	adds r1, r0, #0
	b _08183CF2
	.align 2, 0
_08183CEC: .4byte 0x00000187
_08183CF0:
	movs r1, #0
_08183CF2:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08183D08
	bl Script_GetValue
	b _08183D0A
_08183D08:
	movs r0, #0
_08183D0A:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08183D22
	bl Script_GetValue
	adds r1, r0, #0
	b _08183D24
_08183D22:
	movs r1, #0
_08183D24:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_08183D2C:
	ldr r5, [sp, #0xdc]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r6, [sp, #0xa4]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0xac]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0xb4]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0xa8]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl prepare_08231510
	cmp r0, #0
	beq _08183D8E
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _08183D74
	bl Script_GetValue
	b _08183D76
_08183D74:
	movs r0, #0
_08183D76:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08183D86
	bl Script_GetValue
	b _08183D88
_08183D86:
	movs r0, #0
_08183D88:
	ldr r6, _08183DF0 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_08183D8E:
	movs r0, #0x4b
	movs r1, #2
	bl Script_GetKeywordValue
	ldr r1, [sp, #0xe8]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _08183DB2
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x74]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08183DB2:
	movs r0, #0x4c
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _08183DCA
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x74]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_08183DCA:
	ldr r4, [sp, #0x9c]
	lsrs r1, r4, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x38]
	add r2, sp, #0x28
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x54]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08183DF4
	movs r0, #1
	b _08183DF6
	.align 2, 0
_08183DF0: .4byte 0x00000189
_08183DF4:
	movs r0, #0
_08183DF6:
	cmp r0, #0
	beq _08183E06
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08183E30 @ =FUN_080f48ac
	ldr r1, [sp, #0x38]
	bl FUN_0807f558
_08183E06:
	ldr r6, [sp, #0xec]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _08183E12
	ldr r1, [r7, #0x44]
_08183E12:
	ldr r0, [sp, #0x38]
	bl FUN_0823b46c
	ldr r1, [sp, #0xb0]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _08183E34
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x1b0]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _08183E40
	.align 2, 0
_08183E30: .4byte FUN_080f48ac
_08183E34:
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x1b0]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_08183E40:
	ldr r2, [sp, #0xb0]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08183E8E
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08183E8E
	cmp r0, #0x16
	beq _08183E8E
	cmp r0, #0x14
	beq _08183E8E
	cmp r0, #9
	beq _08183E8E
	cmp r0, #0x19
	beq _08183E8E
	cmp r0, #0x1a
	beq _08183E8E
	cmp r0, #0xd
	beq _08183E8E
	cmp r0, #0x1b
	beq _08183E8E
	cmp r0, #0x1f
	beq _08183E8E
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0xd0]
	ldrb r2, [r3]
	ldr r4, [sp, #0xd4]
	ldrb r3, [r4]
	ldr r5, [sp, #0xd8]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x38]
	bl FUN_0823b490
_08183E8E:
	movs r1, #8
	ldr r6, [sp, #0x54]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08183E9E
	movs r0, #1
	b _08183EA0
_08183E9E:
	movs r0, #0
_08183EA0:
	cmp r0, #0
	beq _08183EAE
	ldr r1, [sp, #0xbc]
	ldr r0, [r1]
	ldr r2, [sp, #0xb8]
	str r0, [r2]
	b _08183EC0
_08183EAE:
	ldr r3, [sp, #0xbc]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0xb8]
	str r0, [r4]
_08183EC0:
	ldrh r0, [r7]
	ldr r5, [sp, #0x40]
	strh r0, [r5]
	ldr r6, [sp, #0x19c]
	ldr r0, [sp, #0x44]
	str r6, [r0]
	ldr r1, [sp, #0x3c]
	cmp r1, #0
	beq _08183EEA
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
	ldr r2, [sp, #0x38]
	strb r0, [r2, #5]
_08183EEA:
	adds r0, r7, #0
	bl FUN_0817c44c
	adds r0, r7, #0
	bl FUN_0817ded0
	ldr r4, _08183F30 @ =0x00000272
	ldr r5, _08183F34 @ =0x00000276
	movs r0, #0x43
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x70]
	strh r0, [r3]
	ldr r6, [sp, #0x60]
	strh r4, [r6]
	ldr r0, [sp, #0x64]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, r0, r4
	ldr r1, [sp, #0x68]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0xec]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08183F38
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _08183F44
	.align 2, 0
_08183F30: .4byte 0x00000272
_08183F34: .4byte 0x00000276
_08183F38:
	ldr r2, [r7, #0x44]
	ldr r0, _08183F7C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08183F44:
	ldr r3, [sp, #0xec]
	ldrb r0, [r3]
	cmp r0, #1
	bne _08183F94
	ldr r4, [sp, #0xb0]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08183F80
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
	b _08183F8A
	.align 2, 0
_08183F7C: .4byte 0x03003584
_08183F80:
	ldr r5, [sp, #0xb0]
	ldrb r0, [r5]
	bl FUN_080ecf60
	adds r4, r0, #1
_08183F8A:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_08183F94:
	movs r4, #0
	ldr r6, [sp, #0x60]
	ldrh r0, [r6]
	ldr r1, [sp, #0x58]
	strh r0, [r1]
	ldrh r0, [r6]
	adds r0, #2
	ldr r2, [sp, #0x5c]
	strh r0, [r2]
	adds r0, r7, #0
	bl FUN_0817d6d4
	adds r0, r7, #0
	bl FUN_0817ecdc
	ldr r3, [sp, #0x30]
	ldr r5, _081841A4 @ =0x000008B8
	adds r0, r3, r5
	ldr r6, _081841A8 @ =0x000008DC
	adds r5, r3, r6
	ldr r1, _081841AC @ =FUN_0818337c
	str r1, [sp, #0x1bc]
	ldr r2, _081841B0 @ =FUN_0817bbe8
	mov r8, r2
	ldr r3, _081841B4 @ =FUN_081804f8
	mov sb, r3
	ldr r6, _081841B8 @ =FUN_0817fab0
	mov sl, r6
	ldr r1, _081841BC @ =FUN_0817fc84
	mov ip, r1
	ldr r3, _081841C0 @ =FUN_080f62b0
	ldr r2, _081841C4 @ =FUN_080f62ac
	str r2, [sp, #0x1b4]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x6c]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x90]
	str r0, [r1]
	ldr r2, [sp, #0x94]
	str r5, [r2]
	ldr r5, [sp, #0x1bc]
	ldr r6, [sp, #0x114]
	str r5, [r6]
	mov r1, r8
	ldr r2, [sp, #0x11c]
	str r1, [r2]
	mov r5, sb
	ldr r6, [sp, #0x124]
	str r5, [r6]
	mov r1, sl
	ldr r2, [sp, #0x134]
	str r1, [r2]
	mov r5, ip
	ldr r6, [sp, #0x138]
	str r5, [r6]
	ldr r1, [sp, #0x14c]
	str r4, [r1]
	ldr r2, [sp, #0x150]
	str r3, [r2]
	ldr r3, _081841C8 @ =FUN_08180548
	ldr r5, [sp, #0x158]
	str r3, [r5]
	ldr r6, _081841CC @ =FUN_081808b0
	ldr r1, [sp, #0x15c]
	str r6, [r1]
	ldr r1, _081841D0 @ =FUN_080f44f4
	ldr r2, [sp, #0x160]
	str r1, [r2]
	ldr r1, _081841D4 @ =FUN_080f410c
	ldr r3, [sp, #0x168]
	str r1, [r3]
	ldr r5, [sp, #0x154]
	str r4, [r5]
	ldr r6, [sp, #0x118]
	str r4, [r6]
	ldr r1, [sp, #0x1b4]
	ldr r2, [sp, #0x18c]
	str r1, [r2]
	ldr r1, _081841D8 @ =FUN_080f0430
	ldr r3, [sp, #0x190]
	str r1, [r3]
	movs r6, #1
	ldr r5, [sp, #0xc0]
	strb r6, [r5]
	ldr r1, _081841DC @ =0x085AD470
	ldr r2, [sp, #0x194]
	str r1, [r2]
	ldr r1, _081841E0 @ =FUN_080e73c8
	ldr r3, [sp, #0x17c]
	str r1, [r3]
	ldr r5, [sp, #0x170]
	str r4, [r5]
	ldr r6, [sp, #0x180]
	str r4, [r6]
	ldr r1, [sp, #0x184]
	str r4, [r1]
	ldr r2, [sp, #0x188]
	str r4, [r2]
	ldr r3, [sp, #0x198]
	str r4, [r3]
	ldr r1, _081841E4 @ =FUN_080f0320
	ldr r5, [sp, #0x1a4]
	str r1, [r5]
	ldr r1, _081841E8 @ =FUN_080eff14
	ldr r6, [sp, #0x148]
	str r1, [r6]
	ldr r1, _081841EC @ =FUN_080e72b0
	ldr r2, [sp, #0x174]
	str r1, [r2]
	ldr r3, [sp, #0x16c]
	str r4, [r3]
	ldr r1, _081841F0 @ =FUN_080f47c8
	ldr r5, [sp, #0x178]
	str r1, [r5]
	ldr r1, _081841F4 @ =FUN_080f54e4
	ldr r6, [sp, #0x164]
	str r1, [r6]
	ldr r1, [sp, #0x13c]
	str r4, [r1]
	ldr r1, _081841F8 @ =FUN_080f6e64
	ldr r2, [sp, #0x1a8]
	str r1, [r2]
	ldr r1, _081841FC @ =FUN_080f64f0
	ldr r3, [sp, #0x120]
	str r1, [r3]
	ldr r1, _08184200 @ =FUN_080f84d4
	ldr r5, [sp, #0x1ac]
	str r1, [r5]
	ldr r1, _08184204 @ =FUN_080f624c
	ldr r6, [sp, #0x144]
	str r1, [r6]
	ldr r1, _08184208 @ =FUN_080f56ec
	ldr r2, [sp, #0x128]
	str r1, [r2]
	ldr r1, _0818420C @ =FUN_080f5b34
	ldr r3, [sp, #0x12c]
	str r1, [r3]
	ldr r1, _08184210 @ =FUN_080f5fac
	ldr r5, [sp, #0x130]
	str r1, [r5]
	ldr r6, [sp, #0x140]
	str r4, [r6]
	movs r1, #0x28
	ldr r2, [sp, #0xc4]
	strb r1, [r2]
	ldr r1, [sp, #0x1a0]
	bl FUN_082362fc
	adds r0, r7, #0
	bl FUN_080e6204
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r0, r7, r3
	str r4, [r0]
	ldr r5, _08184214 @ =0x000005FC
	adds r0, r7, r5
	str r4, [r0]
	movs r6, #0xc1
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _08184218 @ =FUN_0817bb7c
	str r0, [r1]
	movs r0, #0xc3
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _0818421C @ =FUN_0817c328
	str r0, [r1]
	ldr r2, _08184220 @ =0x000005AC
	adds r1, r7, r2
	ldr r0, _08184224 @ =FUN_0817bbe0
	str r0, [r1]
	subs r3, #0x48
	adds r1, r7, r3
	ldr r0, _08184228 @ =FUN_0817bbe4
	str r0, [r1]
	subs r5, #0x70
	adds r1, r7, r5
	ldr r0, _0818422C @ =FUN_08182254
	str r0, [r1]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r4, [r0]
	ldr r1, _08184230 @ =0x00500200
	ldr r2, [sp, #0x6c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x81
	lsls r1, r1, #3
	ldr r3, [sp, #0x74]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	ldr r5, [sp, #0x30]
	ldr r6, _08184234 @ =0x0000085C
	adds r1, r5, r6
	ldr r2, [r7, #8]
	ldr r3, [r7, #0xc]
	str r2, [r1]
	str r3, [r1, #4]
	movs r0, #0xaa
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #5
	str r0, [sp, #0x10]
	movs r2, #1
	str r2, [sp, #0x14]
	str r4, [sp, #0x18]
	adds r0, r5, #0
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_08013ba8
	ldr r3, _08184238 @ =0x0000044C
	adds r1, r7, r3
	strb r0, [r1]
	ldr r1, _0818423C @ =0x00001C1B
	adds r0, r5, #0
	movs r2, #6
	bl FUN_08013c94
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08013cb8
	adds r0, r5, #0
	bl FUN_08013984
	movs r0, #0x49
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r4, [sp, #0x88]
	strh r0, [r4]
	movs r0, #0x47
	bl prepare_08231510
	cmp r0, #0
	beq _0818424A
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_08184196:
	bl VM_GetPC
	cmp r0, #0
	beq _08184240
	bl Script_GetValue
	b _08184242
	.align 2, 0
_081841A4: .4byte 0x000008B8
_081841A8: .4byte 0x000008DC
_081841AC: .4byte FUN_0818337c
_081841B0: .4byte FUN_0817bbe8
_081841B4: .4byte FUN_081804f8
_081841B8: .4byte FUN_0817fab0
_081841BC: .4byte FUN_0817fc84
_081841C0: .4byte FUN_080f62b0
_081841C4: .4byte FUN_080f62ac
_081841C8: .4byte FUN_08180548
_081841CC: .4byte FUN_081808b0
_081841D0: .4byte FUN_080f44f4
_081841D4: .4byte FUN_080f410c
_081841D8: .4byte FUN_080f0430
_081841DC: .4byte 0x085AD470
_081841E0: .4byte FUN_080e73c8
_081841E4: .4byte FUN_080f0320
_081841E8: .4byte FUN_080eff14
_081841EC: .4byte FUN_080e72b0
_081841F0: .4byte FUN_080f47c8
_081841F4: .4byte FUN_080f54e4
_081841F8: .4byte FUN_080f6e64
_081841FC: .4byte FUN_080f64f0
_08184200: .4byte FUN_080f84d4
_08184204: .4byte FUN_080f624c
_08184208: .4byte FUN_080f56ec
_0818420C: .4byte FUN_080f5b34
_08184210: .4byte FUN_080f5fac
_08184214: .4byte 0x000005FC
_08184218: .4byte FUN_0817bb7c
_0818421C: .4byte FUN_0817c328
_08184220: .4byte 0x000005AC
_08184224: .4byte FUN_0817bbe0
_08184228: .4byte FUN_0817bbe4
_0818422C: .4byte FUN_08182254
_08184230: .4byte 0x00500200
_08184234: .4byte 0x0000085C
_08184238: .4byte 0x0000044C
_0818423C: .4byte 0x00001C1B
_08184240:
	movs r0, #0
_08184242:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08184196
_0818424A:
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0x8c]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x7c]
	strh r0, [r3]
	cmp r2, #0
	beq _08184282
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x6c]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _08184282
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_08184282:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x54]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08184294
	movs r0, #1
	b _08184296
_08184294:
	movs r0, #0
_08184296:
	cmp r0, #0
	beq _081842A8
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x74]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081842A8:
	cmp r2, #1
	beq _081842E8
	movs r1, #0
	ldr r0, [sp, #0x48]
	strb r1, [r0]
	ldr r2, [sp, #0x4c]
	strb r1, [r2]
	ldr r3, [sp, #0x50]
	strb r1, [r3]
	ldr r4, _081842F8 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081842FC @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x138]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0xcc]
	strb r1, [r6]
	ldr r0, [sp, #0x110]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081842E8:
	movs r1, #2
	ldr r3, [sp, #0x54]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08184300
	movs r0, #1
	b _08184302
	.align 2, 0
_081842F8: .4byte 0x00000484
_081842FC: .4byte 0x0000046C
_08184300:
	movs r0, #0
_08184302:
	cmp r0, #0
	beq _0818431C
	ldr r0, _08184318 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x78]
	strh r0, [r5]
	b _08184326
	.align 2, 0
_08184318: .4byte 0x030046A0
_0818431C:
	ldr r0, [sp, #0x19c]
	bl FUN_08241574
	ldr r6, [sp, #0x78]
	strh r0, [r6]
_08184326:
	movs r1, #0x40
	ldr r2, [sp, #0x54]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08184336
	movs r0, #1
	b _08184338
_08184336:
	movs r0, #0
_08184338:
	cmp r0, #0
	beq _08184348
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _0818436C @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08184348:
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _0818437A
	ldr r0, _08184370 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x78]
	ldrh r4, [r4]
	cmp r0, r4
	bne _08184374
	movs r0, #1
	b _08184376
	.align 2, 0
_0818436C: .4byte 0xFFFFFEFF
_08184370: .4byte 0x030046A0
_08184374:
	movs r0, #0
_08184376:
	cmp r0, #0
	bne _08184382
_0818437A:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_08184382:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0xec]
	ldrb r0, [r5]
	cmp r0, #0
	bne _0818446A
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
	beq _081843C4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081843CC
_081843C4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081843CC:
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
	beq _081843F0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081843F8
_081843F0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081843F8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _08184430 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08184474
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08184434
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08184428
	ldrb r0, [r4, #5]
_08184428:
	subs r0, #1
	strh r0, [r4, #8]
	b _08184444
	.align 2, 0
_08184430: .4byte 0x0000FFFF
_08184434:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08184444
	strh r1, [r4, #8]
_08184444:
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
	bne _08184474
	movs r0, #1
	strb r0, [r4, #7]
	b _08184474
_0818446A:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_08184474:
	movs r0, #0
	ldr r3, [sp, #0xa0]
	str r0, [r3]
	ldr r0, _0818448C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08184490
	movs r0, #1
	b _08184492
	.align 2, 0
_0818448C: .4byte 0x030047A4
_08184490:
	movs r0, #0
_08184492:
	cmp r0, #0
	bne _081844D2
	ldr r4, [sp, #0xb0]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081844BA
	adds r0, r1, #0
	cmp r0, #7
	beq _081844BA
	cmp r0, #6
	beq _081844BA
	cmp r0, #0x15
	beq _081844BA
	cmp r0, #0x14
	beq _081844BA
	cmp r0, #0x17
	bne _081844D2
_081844BA:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x54]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_081844D2:
	adds r0, r7, #0
	bl FUN_0817c02c
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_08183368
	adds r0, r7, #0
	bl FUN_08181a78
	adds r0, r7, #0
	bl FUN_08182240
	ldr r6, [sp, #0x54]
	ldrh r0, [r6]
	ldr r1, [sp, #0x10c]
	strh r0, [r1]
	ldr r2, [sp, #0x98]
	ldrh r0, [r2]
	ldr r3, [sp, #0x108]
	strh r0, [r3]
	ldr r4, [sp, #0x6c]
	ldr r0, [r4]
	ldr r5, [sp, #0xe0]
	str r0, [r5]
	ldr r6, [sp, #0x74]
	ldr r0, [r6]
	ldr r1, [sp, #0xe4]
	str r0, [r1]
	ldrb r0, [r7, #5]
	ldr r2, [sp, #0xf0]
	strb r0, [r2]
	ldr r3, [sp, #0x48]
	ldrb r0, [r3]
	ldr r4, [sp, #0xf4]
	strb r0, [r4]
	ldr r5, [sp, #0x4c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xf8]
	strb r0, [r6]
	ldr r1, [sp, #0x50]
	ldrb r0, [r1]
	ldr r2, [sp, #0xfc]
	strb r0, [r2]
	ldr r3, [sp, #0x110]
	ldr r0, [r3]
	ldr r4, [sp, #0x100]
	str r0, [r4]
	ldr r5, [sp, #0xcc]
	ldrb r0, [r5]
	ldr r6, [sp, #0x104]
	strb r0, [r6]
	ldr r0, _08184578 @ =0x00000574
	adds r1, r7, r0
	ldr r2, [sp, #0x30]
	ldr r3, _0818457C @ =0x00000898
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r1]
	ldr r4, _08184580 @ =0x0000057C
	adds r1, r7, r4
	ldr r0, _08184584 @ =FUN_080f09e0
	str r0, [r1]
	ldr r5, _08184588 @ =0x0000061C
	adds r1, r7, r5
	ldr r0, _0818458C @ =FUN_081833b8
	str r0, [r1]
	movs r6, #0xc4
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _08184590 @ =FUN_081833dc
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08184594
	movs r0, #0
	b _08184598
	.align 2, 0
_08184578: .4byte 0x00000574
_0818457C: .4byte 0x00000898
_08184580: .4byte 0x0000057C
_08184584: .4byte FUN_080f09e0
_08184588: .4byte 0x0000061C
_0818458C: .4byte FUN_081833b8
_08184590: .4byte FUN_081833dc
_08184594:
	movs r0, #1
	rsbs r0, r0, #0
_08184598:
	add sp, #0x1c0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemyCheyenne_Create
EnemyCheyenne_Create: @ 0x081845A8
	push {r4, r5, lr}
	ldr r5, _081845DC @ =0x000008E4
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _081845D4
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyCheyenne_Init
	cmp r0, #0
	bge _081845D4
	adds r0, r4, #0
	bl FUN_081833dc
	adds r0, r4, #0
	bl Free
_081845D4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081845DC: .4byte 0x000008E4
