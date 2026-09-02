	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ ファイルが巨大だったため適当に分割しています。

	thumb_func_start FUN_080ab018
FUN_080ab018: @ 0x080AB018
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	bne _080AB058
	movs r1, #1
	movs r2, #0xe1
	lsls r2, r2, #3
	ldr r0, _080AB04C @ =0x03002B80
	movs r3, #1
	strh r1, [r0]
	ldr r0, _080AB050 @ =0x03002B78
	strh r2, [r0]
	ldr r1, _080AB054 @ =0x03002BF0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	strb r3, [r4, #0x19]
	b _080AB066
	.align 2, 0
_080AB04C: .4byte 0x03002B80
_080AB050: .4byte 0x03002B78
_080AB054: .4byte 0x03002BF0
_080AB058:
	movs r1, #2
	movs r2, #0xe1
	lsls r2, r2, #3
	ldr r0, _080AB06C @ =0x03002B80
	strh r1, [r0]
	ldr r0, _080AB070 @ =0x03002B78
	strh r2, [r0]
_080AB066:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AB06C: .4byte 0x03002B80
_080AB070: .4byte 0x03002B78

	thumb_func_start FUN_080ab074
FUN_080ab074: @ 0x080AB074
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r2, r0, #1
	strh r2, [r5, #0x2c]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _080AB098
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	adds r1, r5, #0
	adds r1, #0x28
	movs r0, #0
	strb r0, [r1]
	b _080AB12E
_080AB098:
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bne _080AB0AE
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r2, [r0]
	adds r2, #1
	adds r0, r5, #0
	bl FUN_0822dafc
_080AB0AE:
	ldrh r2, [r5, #0x2c]
	adds r1, r5, #0
	adds r1, #0x2b
	cmp r2, #3
	bls _080AB0C8
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
	cmp r2, #8
	bls _080AB0C8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_080AB0C8:
	adds r2, r5, #0
	adds r2, #0x2a
	ldrb r0, [r1]
	ldrb r1, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	ldrh r4, [r5, #0x30]
	ldr r3, _080AB0F4 @ =0x085B0A08
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AB0F8
	asrs r4, r0, #0xc
	b _080AB0FE
	.align 2, 0
_080AB0F4: .4byte 0x085B0A08
_080AB0F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r4, r0, #0
_080AB0FE:
	ldrh r0, [r5, #0x38]
	adds r0, r0, r4
	strh r0, [r5, #0x18]
	ldrh r1, [r5, #0x30]
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080AB11A
	asrs r1, r0, #0xc
	b _080AB120
_080AB11A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AB120:
	ldrh r0, [r5, #0x3c]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x2e]
	ldrh r1, [r5, #0x1a]
	adds r0, r0, r1
	strh r0, [r5, #0x1a]
_080AB12E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080ab134
FUN_080ab134: @ 0x080AB134
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	mov ip, r1
	movs r7, #0x9c
	lsls r7, r7, #1
	add r7, r8
	ldrb r0, [r7, #1]
	adds r0, #1
	strb r0, [r7, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080AB154
	b _080AB26E
_080AB154:
	ldrb r1, [r7]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #8
	adds r6, r7, r0
	adds r1, r6, #0
	adds r1, #0x28
	movs r0, #1
	strb r0, [r1]
	ldr r4, _080AB1FC @ =0x0203B400
	ldr r5, _080AB200 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r2, _080AB204 @ =0x000003FF
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r3, #0xf
	ands r0, r3
	adds r0, #0x10
	strh r0, [r6, #0x2e]
	adds r1, #1
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r3
	adds r0, #0x40
	strh r0, [r6, #0x30]
	adds r1, #1
	ands r1, r2
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	adds r5, r6, #0
	adds r5, #0x2a
	strb r0, [r5]
	adds r1, r6, #0
	adds r1, #0x2b
	movs r0, #8
	strb r0, [r1]
	movs r0, #0
	strh r0, [r6, #0x2c]
	mov r2, ip
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
	ldr r0, _080AB208 @ =FUN_080ab074
	str r0, [r6, #0x40]
	adds r4, r6, #0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r0, #0x9e
	lsls r0, r0, #1
	add r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r2, [r0]
	adds r0, r4, #0
	bl FUN_0822dafc
	ldrh r3, [r4, #0x30]
	ldr r2, _080AB20C @ =0x085B0A08
	ldrb r0, [r5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080AB210
	asrs r3, r0, #0xc
	b _080AB216
	.align 2, 0
_080AB1FC: .4byte 0x0203B400
_080AB200: .4byte 0x030046B8
_080AB204: .4byte 0x000003FF
_080AB208: .4byte FUN_080ab074
_080AB20C: .4byte 0x085B0A08
_080AB210:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080AB216:
	ldrh r0, [r6, #0x38]
	adds r0, r0, r3
	strh r0, [r4, #0x18]
	ldrh r0, [r6, #0x3a]
	strh r0, [r4, #0x1a]
	ldrh r2, [r6, #0x30]
	ldr r1, _080AB23C @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080AB240
	asrs r1, r0, #0xc
	b _080AB246
	.align 2, 0
_080AB23C: .4byte 0x085B0A08
_080AB240:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AB246:
	ldrh r0, [r6, #0x3c]
	adds r0, r0, r1
	movs r1, #0
	strh r0, [r4, #0x1c]
	movs r0, #2
	strb r0, [r4, #0xf]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bls _080AB262
	strb r1, [r7]
_080AB262:
	strb r1, [r7, #1]
	movs r1, #0x9d
	lsls r1, r1, #1
	add r1, r8
	movs r0, #1
	strb r0, [r1]
_080AB26E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080ab278
FUN_080ab278: @ 0x080AB278
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r1, r0, #1
	movs r3, #0
	strh r1, [r5, #0x2c]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080AB2B6
	ldr r0, [r5]
	movs r2, #1
	orrs r0, r2
	str r0, [r5]
	adds r1, r5, #0
	adds r1, #0x28
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x18
	str r3, [sp]
	str r3, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	movs r1, #1
	movs r2, #0
	bl FUN_080ddcc8
	b _080AB398
_080AB2B6:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _080AB316
	ldr r2, _080AB2E8 @ =0x085B0A08
	adds r3, r5, #0
	adds r3, #0x2a
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r6, r2, #0
	adds r4, r3, #0
	cmp r0, #0
	blt _080AB2EC
	asrs r1, r0, #0xc
	b _080AB2F2
	.align 2, 0
_080AB2E8: .4byte 0x085B0A08
_080AB2EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AB2F2:
	ldr r2, [r5, #0x34]
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r5, #0x18]
	ldrh r0, [r2, #2]
	strh r0, [r5, #0x1a]
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r2, #0
	cmp r0, #0
	bge _080AB384
	b _080AB38C
_080AB316:
	ldrh r0, [r5, #0x2c]
	movs r2, #0xc
	subs r2, r2, r0
	adds r1, r2, #1
	adds r4, r5, #0
	adds r4, #0x2a
	adds r0, r5, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	ldrb r3, [r4]
	adds r0, r0, r3
	strb r0, [r4]
	ldrh r0, [r5, #0x32]
	muls r0, r2, r0
	bl Div
	strh r0, [r5, #0x32]
	ldrh r3, [r5, #0x32]
	ldr r2, _080AB358 @ =0x085B0A08
	ldrb r0, [r4]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080AB35C
	asrs r3, r0, #0xc
	b _080AB362
	.align 2, 0
_080AB358: .4byte 0x085B0A08
_080AB35C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080AB362:
	ldr r2, [r5, #0x34]
	ldrh r0, [r2]
	adds r0, r0, r3
	strh r0, [r5, #0x18]
	ldrh r0, [r2, #2]
	strh r0, [r5, #0x1a]
	ldrh r3, [r5, #0x32]
	ldr r1, _080AB388 @ =0x085B0A08
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r3, r0
	adds r1, r2, #0
	cmp r0, #0
	blt _080AB38C
_080AB384:
	asrs r2, r0, #0xc
	b _080AB392
	.align 2, 0
_080AB388: .4byte 0x085B0A08
_080AB38C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080AB392:
	ldrh r0, [r1, #4]
	adds r0, r0, r2
	strh r0, [r5, #0x1c]
_080AB398:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080ab3a0
FUN_080ab3a0: @ 0x080AB3A0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r2, r1, #0
	movs r6, #0x9c
	lsls r6, r6, #1
	add r6, sb
	ldrb r0, [r6, #1]
	adds r0, #1
	strb r0, [r6, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080AB3C2
	b _080AB4DC
_080AB3C2:
	ldrb r1, [r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #8
	adds r7, r6, r0
	adds r1, r7, #0
	adds r1, #0x28
	movs r0, #1
	mov ip, r0
	movs r0, #1
	strb r0, [r1]
	str r2, [r7, #0x34]
	ldr r4, _080AB468 @ =0x0203B400
	ldr r5, _080AB46C @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _080AB470 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r2, #0x7f
	ands r0, r2
	movs r2, #0xc0
	lsls r2, r2, #1
	mov r8, r2
	add r0, r8
	strh r0, [r7, #0x32]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r2, #0x2a
	adds r2, r2, r7
	mov r8, r2
	strb r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	mov r1, ip
	ands r0, r1
	adds r0, #2
	adds r1, r7, #0
	adds r1, #0x2b
	strb r0, [r1]
	movs r0, #0
	strh r0, [r7, #0x2c]
	ldr r0, _080AB474 @ =FUN_080ab278
	str r0, [r7, #0x40]
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	movs r0, #0x9e
	lsls r0, r0, #1
	add r0, sb
	ldr r1, [r0]
	adds r0, r7, #0
	movs r2, #4
	bl FUN_0822dafc
	ldrh r3, [r7, #0x32]
	ldr r2, _080AB478 @ =0x085B0A08
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _080AB47C
	asrs r3, r0, #0xc
	b _080AB482
	.align 2, 0
_080AB468: .4byte 0x0203B400
_080AB46C: .4byte 0x030046B8
_080AB470: .4byte 0x000003FF
_080AB474: .4byte FUN_080ab278
_080AB478: .4byte 0x085B0A08
_080AB47C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080AB482:
	ldr r1, [r7, #0x34]
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r7, #0x18]
	ldrh r0, [r1, #2]
	strh r0, [r7, #0x1a]
	ldrh r3, [r7, #0x32]
	ldr r2, _080AB4AC @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	adds r2, r1, #0
	cmp r0, #0
	blt _080AB4B0
	asrs r1, r0, #0xc
	b _080AB4B6
	.align 2, 0
_080AB4AC: .4byte 0x085B0A08
_080AB4B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AB4B6:
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	movs r1, #0
	strh r0, [r7, #0x1c]
	movs r2, #1
	strb r2, [r7, #0xf]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bls _080AB4D2
	strb r1, [r6]
_080AB4D2:
	strb r1, [r6, #1]
	movs r0, #0x9d
	lsls r0, r0, #1
	add r0, sb
	strb r2, [r0]
_080AB4DC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080ab4e8
FUN_080ab4e8: @ 0x080AB4E8
	push {r4, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x2c]
	adds r2, r0, #1
	strh r2, [r3, #0x2c]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xd
	bls _080AB50C
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	adds r1, r3, #0
	adds r1, #0x28
	movs r0, #0
	strb r0, [r1]
	b _080AB53A
_080AB50C:
	ldrh r0, [r3, #0x38]
	ldrh r4, [r3, #0x18]
	adds r0, r0, r4
	strh r0, [r3, #0x18]
	ldrh r0, [r3, #0x3a]
	ldrh r4, [r3, #0x1a]
	adds r0, r0, r4
	strh r0, [r3, #0x1a]
	ldrh r0, [r3, #0x3c]
	ldrh r4, [r3, #0x1c]
	adds r0, r0, r4
	strh r0, [r3, #0x1c]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa
	bne _080AB53A
	adds r0, r3, #0
	adds r0, #0x29
	ldrb r2, [r0]
	adds r2, #1
	adds r0, r3, #0
	bl FUN_0822dafc
_080AB53A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080ab540
FUN_080ab540: @ 0x080AB540
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	mov r8, r1
	ldr r3, _080AB5CC @ =0x0203B400
	ldr r1, _080AB5D0 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080AB5D4 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrb r6, [r0]
	movs r4, #0xac
	lsls r4, r4, #1
	add r4, sb
	movs r5, #0xa0
	lsls r5, r5, #1
	add r5, sb
	adds r7, r5, #0
	movs r0, #0xb
	mov sl, r0
_080AB574:
	movs r0, #1
	strb r0, [r4, #0x10]
	ldr r2, _080AB5D0 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _080AB5D4 @ =0x000003FF
	ands r1, r0
	lsls r0, r1, #1
	ldr r2, _080AB5CC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0xf
	ands r0, r2
	adds r0, r0, r6
	subs r0, #9
	strb r0, [r4, #0x12]
	adds r1, #1
	ldr r0, _080AB5D4 @ =0x000003FF
	ands r1, r0
	ldr r2, _080AB5D0 @ =0x030046B8
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _080AB5CC @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x19
	strh r0, [r4, #0x16]
	ldrh r3, [r4, #0x16]
	ldr r2, _080AB5D8 @ =0x085B0A08
	ldrb r0, [r4, #0x12]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080AB5DC
	asrs r0, r0, #0xc
	b _080AB5E2
	.align 2, 0
_080AB5CC: .4byte 0x0203B400
_080AB5D0: .4byte 0x030046B8
_080AB5D4: .4byte 0x000003FF
_080AB5D8: .4byte 0x085B0A08
_080AB5DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AB5E2:
	strh r0, [r4, #0x20]
	movs r2, #0
	strh r2, [r4, #0x22]
	ldrh r0, [r4, #0x16]
	ldrb r1, [r4, #0x12]
	lsls r1, r1, #1
	ldr r2, _080AB600 @ =0x085B0A08
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080AB604
	asrs r0, r0, #0xc
	b _080AB60A
	.align 2, 0
_080AB600: .4byte 0x085B0A08
_080AB604:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AB60A:
	strh r0, [r4, #0x24]
	ldr r0, _080AB678 @ =FUN_080ab4e8
	str r0, [r4, #0x28]
	movs r0, #0
	strh r0, [r4, #0x14]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r0, #0x9e
	lsls r0, r0, #1
	add r0, sb
	ldr r1, [r0]
	ldrb r2, [r4, #0x11]
	adds r0, r7, #0
	bl FUN_0822dafc
	ldrh r0, [r4, #0x20]
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4]
	mov r2, r8
	ldrh r0, [r2, #2]
	strh r0, [r4, #2]
	ldrh r0, [r4, #0x24]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #1
	strb r1, [r5, #0xf]
	adds r6, #0x18
	movs r0, #0xff
	ands r6, r0
	adds r4, #0x44
	adds r5, #0x44
	adds r7, #0x44
	movs r2, #1
	rsbs r2, r2, #0
	add sl, r2
	mov r0, sl
	cmp r0, #0
	bge _080AB574
	movs r0, #0x9d
	lsls r0, r0, #1
	add r0, sb
	strb r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB678: .4byte FUN_080ab4e8

	thumb_func_start FUN_080ab67c
FUN_080ab67c: @ 0x080AB67C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0x9d
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AB6CE
	movs r3, #0
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r1, #6
	adds r5, r6, r1
	movs r7, #0xb
_080AB69C:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080AB6B8
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, [r4, #0x18]
	adds r0, r5, #0
	str r3, [sp]
	bl _call_via_r2
	ldr r3, [sp]
	adds r3, #1
_080AB6B8:
	adds r4, #0x44
	adds r5, #0x44
	subs r7, #1
	cmp r7, #0
	bge _080AB69C
	cmp r3, #0
	bne _080AB6CE
	movs r1, #0x9d
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r3, [r0]
_080AB6CE:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ab6d8
FUN_080ab6d8: @ 0x080AB6D8
	push {r4, r5, lr}
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r4, r0, r1
	movs r5, #0xb
_080AB6E2:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x44
	subs r5, #1
	cmp r5, #0
	bge _080AB6E2
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ab6f8
FUN_080ab6f8: @ 0x080AB6F8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	movs r0, #0x9c
	lsls r0, r0, #1
	adds r6, r5, r0
	ldr r0, _080AB778 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #4]
	movs r0, #0
	strb r0, [r6]
	strb r0, [r6, #1]
	ldrb r0, [r5, #0x18]
	movs r1, #4
	mov sb, r1
	cmp r0, #0
	bne _080AB724
	movs r0, #2
	mov sb, r0
_080AB724:
	movs r1, #4
	rsbs r1, r1, #0
	mov r8, r1
	ldr r0, _080AB77C @ =0x0000014F
	adds r4, r5, r0
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r5, r5, r1
	movs r7, #0xb
_080AB736:
	movs r0, #0
	strb r0, [r4, #0x19]
	mov r0, sb
	strb r0, [r4, #0x1a]
	ldr r1, [r6, #4]
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r5, #0
	mov r1, r8
	mov r2, r8
	bl FUN_0822dad4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #0xf8
	strb r0, [r4, #1]
	movs r0, #2
	strb r0, [r4]
	adds r4, #0x44
	adds r5, #0x44
	subs r7, #1
	cmp r7, #0
	bge _080AB736
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB778: .4byte 0x00001C1E
_080AB77C: .4byte 0x0000014F

	thumb_func_start FUN_080ab780
FUN_080ab780: @ 0x080AB780
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	ldr r7, [r0, #0x48]
	adds r0, #0x6d
	ldrb r0, [r0]
	movs r1, #0x10
	subs r1, r1, r0
	lsls r0, r1, #4
	subs r5, r0, r1
	movs r6, #0
	movs r0, #0x1f
	mov r8, r0
_080AB79C:
	ldrh r1, [r7]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	mov r2, r8
	ands r3, r2
	lsrs r1, r1, #0x1a
	ands r1, r2
	mov r2, ip
	adds r2, #0x6d
	ldrb r2, [r2]
	muls r0, r2, r0
	adds r0, r5, r0
	asrs r4, r0, #4
	adds r0, r3, #0
	muls r0, r2, r0
	adds r0, r5, r0
	asrs r3, r0, #4
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r5, r0
	asrs r1, r0, #4
	lsls r0, r6, #1
	mov r2, ip
	adds r2, #0x4c
	adds r2, r2, r0
	lsls r0, r1, #0xa
	lsls r1, r3, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r2]
	adds r7, #2
	adds r6, #1
	cmp r6, #0xf
	ble _080AB79C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ab7f0
FUN_080ab7f0: @ 0x080AB7F0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x6d
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080AB806
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	b _080AB80C
_080AB806:
	ldr r0, [r4]
	ldr r1, _080AB844 @ =0xFFFFFBFF
	ands r0, r1
_080AB80C:
	str r0, [r4]
	adds r1, r4, #0
	adds r1, #0x6d
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _080AB822
	adds r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080ab780
_080AB822:
	adds r1, r4, #0
	adds r1, #0x72
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bhi _080AB83C
	ldr r0, [r4, #0x74]
	subs r1, #0x56
	bl FUN_080ab134
_080AB83C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AB844: .4byte 0xFFFFFBFF

	thumb_func_start FUN_080ab848
FUN_080ab848: @ 0x080AB848
	push {lr}
	adds r2, r0, #0
	adds r0, #0x6d
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080AB85E
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	b _080AB864
_080AB85E:
	ldr r0, [r2]
	ldr r1, _080AB884 @ =0xFFFFFBFF
	ands r0, r1
_080AB864:
	str r0, [r2]
	adds r1, r2, #0
	adds r1, #0x6d
	ldrb r0, [r1]
	adds r3, r0, #0
	cmp r3, #0
	bne _080AB888
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	adds r0, r2, #0
	adds r0, #0x6c
	strb r3, [r0]
	b _080AB892
	.align 2, 0
_080AB884: .4byte 0xFFFFFBFF
_080AB888:
	subs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	bl FUN_080ab780
_080AB892:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ab898
FUN_080ab898: @ 0x080AB898
	push {lr}
	adds r2, r0, #0
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AB8E8
	ldr r1, [r2, #0x1c]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #9
	bne _080AB8D6
	adds r3, #1
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #2
	bhi _080AB8D6
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080AB8D6
	adds r0, r2, #0
	adds r0, #0xc0
	bl FUN_080ab7f0
	b _080AB8E8
_080AB8D6:
	movs r3, #0x97
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xc0
	bl FUN_080ab848
_080AB8E8:
	pop {r0}
	bx r0

	thumb_func_start FUN_080ab8ec
FUN_080ab8ec: @ 0x080AB8EC
	push {lr}
	adds r0, #0xc0
	bl FUN_0822a4e0
	pop {r0}
	bx r0

	thumb_func_start FUN_080ab8f8
FUN_080ab8f8: @ 0x080AB8F8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov sb, r1
	adds r4, r7, #0
	adds r4, #0xc0
	ldrb r0, [r7, #0x18]
	cmp r0, #0
	bne _080AB916
	movs r6, #0
	movs r0, #0x63
	mov r8, r0
	b _080AB91C
_080AB916:
	movs r6, #1
	movs r2, #0x62
	mov r8, r2
_080AB91C:
	adds r5, r4, #0
	adds r5, #0x2c
	ldr r1, _080AB990 @ =0x00000BA8
	adds r0, r5, #0
	bl Video_GetActorSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	strh r6, [r4, #0x10]
	movs r0, #3
	strb r0, [r4, #7]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldrh r0, [r4, #0x20]
	adds r0, #0x18
	strh r0, [r4, #0x20]
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r4]
	ldr r0, _080AB994 @ =0x03003584
	mov r2, r8
	lsls r1, r2, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r4, #0x48]
	ldr r3, _080AB998 @ =0x00003DEF
	adds r2, r4, #0
	adds r2, #0x4c
	adds r6, r4, #0
	adds r6, #0x6c
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x6a
_080AB96E:
	strh r3, [r0]
	subs r0, #2
	cmp r0, r1
	bge _080AB96E
	mov r0, r8
	strh r0, [r5, #6]
	str r2, [r5, #0xc]
	str r7, [r4, #0x74]
	movs r0, #1
	strb r0, [r6]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB990: .4byte 0x00000BA8
_080AB994: .4byte 0x03003584
_080AB998: .4byte 0x00003DEF

	thumb_func_start FUN_080ab99c
FUN_080ab99c: @ 0x080AB99C
	push {lr}
	adds r2, r0, #0
	adds r0, #0x96
	ldrh r0, [r0]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #7
	bhi _080AB9B0
	lsrs r1, r1, #0x12
	b _080AB9B4
_080AB9B0:
	lsrs r0, r1, #0x12
	adds r1, r0, #4
_080AB9B4:
	adds r0, r2, #0
	adds r0, #0x48
	strh r1, [r0, #0x10]
	adds r1, r2, #0
	adds r1, #0x96
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080AB9DC
	ldr r0, [r2, #0x48]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x48]
	adds r1, r2, #0
	adds r1, #0x90
	movs r0, #0
	strb r0, [r1]
_080AB9DC:
	pop {r0}
	bx r0

	thumb_func_start FUN_080ab9e0
FUN_080ab9e0: @ 0x080AB9E0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	mov r8, r1
	ands r0, r1
	str r0, [r4]
	adds r7, r4, #0
	adds r7, #0x96
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2f
	bhi _080ABA38
	adds r1, r4, #0
	adds r1, #0x95
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldrh r2, [r4, #0x1e]
	adds r0, r0, r2
	strh r0, [r4, #0x1e]
	ldrb r0, [r1]
	subs r2, r0, #1
	strb r2, [r1]
	adds r0, r4, #0
	adds r0, #0x9c
	ldr r3, [r0]
	ldrb r0, [r3, #0x1a]
	cmp r0, #0
	beq _080ABAB0
	lsls r0, r2, #0x18
	cmp r0, #0
	ble _080ABAB0
	subs r1, #0x79
	adds r0, r3, #0
	bl FUN_080ab3a0
	b _080ABAB0
_080ABA38:
	adds r6, r4, #0
	adds r6, #0x9c
	ldr r0, [r6]
	ldrb r5, [r0, #0x1a]
	cmp r5, #0
	beq _080ABA56
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r1, r4, #0
	adds r1, #0x90
	movs r0, #0
	strb r0, [r1]
	b _080ABAB0
_080ABA56:
	ldr r0, _080ABABC @ =0x00000165
	bl PlaySound_082406e0
	adds r0, r4, #0
	adds r0, #0x92
	ldrb r2, [r0]
	adds r0, #1
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	ldr r0, _080ABAC0 @ =0x00001FFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0
	movs r1, #4
	bl FUN_0823ce68
	ldr r0, [r6]
	bl FUN_080ab018
	adds r0, r4, #0
	adds r0, #0x91
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, [r4, #0x48]
	mov r1, r8
	ands r0, r1
	str r0, [r4, #0x48]
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [r4, #0x64]
	str r1, [r4, #0x68]
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, _080ABAC4 @ =FUN_080ab99c
	str r0, [r1]
	strh r5, [r7]
	ldr r0, [r6]
	subs r1, #0x7c
	bl FUN_080ab540
_080ABAB0:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABABC: .4byte 0x00000165
_080ABAC0: .4byte 0x00001FFF
_080ABAC4: .4byte FUN_080ab99c

	thumb_func_start FUN_080abac8
FUN_080abac8: @ 0x080ABAC8
	push {lr}
	adds r3, r0, #0
	adds r2, r3, #0
	adds r2, #0xb0
	ldrb r0, [r2]
	cmp r0, #0
	bne _080ABAF0
	ldr r0, [r3, #0x1c]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _080ABB04 @ =0x00000209
	cmp r1, r0
	bne _080ABAEA
	movs r0, #1
	strb r0, [r2]
_080ABAEA:
	ldrb r0, [r2]
	cmp r0, #0
	beq _080ABAFE
_080ABAF0:
	adds r1, r3, #0
	adds r1, #0xb8
	adds r0, r3, #0
	adds r0, #0x20
	ldr r1, [r1]
	bl _call_via_r1
_080ABAFE:
	pop {r0}
	bx r0
	.align 2, 0
_080ABB04: .4byte 0x00000209

	thumb_func_start FUN_080abb08
FUN_080abb08: @ 0x080ABB08
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x20
	bl FUN_0822a4e0
	adds r4, #0x68
	adds r0, r4, #0
	bl FUN_0822a4e0
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080abb20
FUN_080abb20: @ 0x080ABB20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	mov r8, r1
	mov r7, sl
	adds r7, #0x20
	mov r1, sl
	ldrb r0, [r1, #0x18]
	cmp r0, #0
	bne _080ABB52
	movs r4, #0
	movs r2, #3
	str r2, [sp]
	adds r1, #0xb2
	movs r0, #0x1f
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x14
	b _080ABB6A
_080ABB52:
	movs r4, #6
	movs r0, #2
	str r0, [sp]
	mov r2, sl
	adds r2, #0xb2
	movs r0, #0
	movs r1, #0x14
	strb r1, [r2]
	mov r1, sl
	adds r1, #0xb3
	strb r0, [r1]
	adds r1, #1
_080ABB6A:
	strb r0, [r1]
	adds r6, r7, #0
	adds r6, #0x2c
	ldr r1, _080ABC0C @ =0x0000210E
	adds r0, r6, #0
	bl Video_GetActorSprite
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822a470
	movs r5, #1
	movs r1, #0
	mov sb, r1
	strh r5, [r7, #0x10]
	adds r1, r4, #0
	adds r1, #0x2c
	adds r0, r6, #0
	bl FUN_0822b20c
	movs r0, #2
	strb r0, [r7, #7]
	ldr r0, [r7]
	orrs r0, r5
	str r0, [r7]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r4, r7, #0
	adds r4, #0x48
	adds r6, #0x48
	ldr r1, _080ABC10 @ =0x00008639
	adds r0, r6, #0
	bl Video_GetActorSprite
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822a470
	mov r0, sb
	strh r0, [r4, #0x10]
	ldr r2, [sp]
	ldr r0, _080ABC14 @ =0x00000113
	adds r1, r2, r0
	adds r0, r6, #0
	bl FUN_0822b20c
	movs r1, #1
	strb r1, [r4, #7]
	ldr r0, [r7, #0x48]
	orrs r0, r5
	str r0, [r7, #0x48]
	adds r1, r7, #0
	adds r1, #0x95
	movs r0, #0x24
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x9c
	mov r2, sl
	str r2, [r0]
	subs r0, #0xc
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, _080ABC18 @ =FUN_080ab9e0
	str r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABC0C: .4byte 0x0000210E
_080ABC10: .4byte 0x00008639
_080ABC14: .4byte 0x00000113
_080ABC18: .4byte FUN_080ab9e0

	thumb_func_start FUN_080abc1c
FUN_080abc1c: @ 0x080ABC1C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	ldr r0, [r0, #0x1c]
	cmp r0, #4
	bne _080ABC30
	movs r0, #1
	strb r0, [r4, #0x1b]
	movs r0, #0
	b _080ABC7A
_080ABC30:
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _080ABC42
	ldr r0, _080ABC80 @ =0x03002BF0
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	movs r0, #0
	strb r0, [r4, #0x19]
_080ABC42:
	adds r0, r4, #0
	bl FUN_080ab898
	adds r0, r4, #0
	bl FUN_080abac8
	adds r0, r4, #0
	bl FUN_080ab67c
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrb r1, [r1]
	cmp r1, #0
	bne _080ABC7A
	adds r1, r4, #0
	adds r1, #0xb0
	ldrb r1, [r1]
	cmp r1, #0
	bne _080ABC7A
	adds r2, #0xe
	adds r1, r4, r2
	ldrb r1, [r1]
	cmp r1, #0
	bne _080ABC7A
	adds r0, r4, #0
	bl KillEntity
_080ABC7A:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080ABC80: .4byte 0x03002BF0

	thumb_func_start FUN_080abc84
FUN_080abc84: @ 0x080ABC84
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xb0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080ABCA6
	adds r0, r4, #0
	adds r0, #0xb1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080ABCA6
	ldrh r0, [r4, #0x1a]
	cmp r0, #0
	bne _080ABCA6
	adds r0, r4, #0
	bl FUN_080ab018
_080ABCA6:
	adds r0, r4, #0
	bl FUN_080abb08
	adds r0, r4, #0
	bl FUN_080ab8ec
	adds r0, r4, #0
	bl FUN_080ab6d8
	ldrb r1, [r4, #0x19]
	cmp r1, #0
	beq _080ABCC6
	ldr r2, _080ABCCC @ =0x03002BF0
	ldrh r1, [r2]
	subs r1, #1
	strh r1, [r2]
_080ABCC6:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080ABCCC: .4byte 0x03002BF0

	thumb_func_start FUN_080abcd0
FUN_080abcd0: @ 0x080ABCD0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r2, #0
	ldr r4, [sp, #0x10]
	strb r4, [r6, #0x18]
	str r1, [r6, #0x1c]
	adds r1, r3, #0
	bl FUN_080abb20
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_080ab8f8
	adds r0, r6, #0
	bl FUN_080ab6f8
	cmp r4, #0
	bne _080ABCFE
	movs r0, #0xe7
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080ABD04
_080ABCFE:
	ldr r0, _080ABD10 @ =0x0000039D
	bl PlaySound_082406e0
_080ABD04:
	ldr r0, [sp, #0x14]
	strb r0, [r6, #0x1a]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080ABD10: .4byte 0x0000039D

	thumb_func_start FUN_080abd14
FUN_080abd14: @ 0x080ABD14
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0x8e
	lsls r1, r1, #3
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080ABD64
	ldr r1, _080ABD5C @ =FUN_080abc1c
	ldr r2, _080ABD60 @ =FUN_080abc84
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_080abcd0
	cmp r0, #0
	bge _080ABD64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080ABD66
	.align 2, 0
_080ABD5C: .4byte FUN_080abc1c
_080ABD60: .4byte FUN_080abc84
_080ABD64:
	adds r0, r4, #0
_080ABD66:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080abd74
FUN_080abd74: @ 0x080ABD74
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x2a
	ldrb r0, [r4]
	adds r2, r0, #1
	strb r2, [r4]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bls _080ABD9C
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	adds r1, r6, #0
	adds r1, #0x28
	movs r0, #0
	strb r0, [r1]
	b _080ABE40
_080ABD9C:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _080ABDB2
	adds r0, r6, #0
	adds r0, #0x29
	ldrb r2, [r0]
	adds r2, #1
	adds r0, r6, #0
	bl FUN_0822dafc
_080ABDB2:
	ldrb r0, [r4]
	movs r1, #0x2b
	adds r1, r1, r6
	mov ip, r1
	adds r1, r6, #0
	adds r1, #0x2e
	cmp r0, #3
	bls _080ABDD6
	mov r2, ip
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldrb r0, [r4]
	cmp r0, #8
	bls _080ABDD6
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_080ABDD6:
	adds r2, r6, #0
	adds r2, #0x2d
	ldrb r0, [r1]
	ldrb r1, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	adds r4, r6, #0
	adds r4, #0x2c
	ldrb r5, [r4]
	ldr r3, _080ABE04 @ =0x085B0A08
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080ABE08
	asrs r5, r0, #0xc
	b _080ABE0E
	.align 2, 0
_080ABE04: .4byte 0x085B0A08
_080ABE08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r5, r0, #0
_080ABE0E:
	ldrh r0, [r6, #0x30]
	adds r0, r0, r5
	strh r0, [r6, #0x18]
	ldrb r1, [r4]
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080ABE2A
	asrs r1, r0, #0xc
	b _080ABE30
_080ABE2A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080ABE30:
	ldrh r0, [r6, #0x34]
	adds r0, r0, r1
	strh r0, [r6, #0x1c]
	ldrh r0, [r6, #0x1a]
	mov r1, ip
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r6, #0x1a]
_080ABE40:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080abe48
FUN_080abe48: @ 0x080ABE48
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	mov ip, r1
	mov r5, sb
	adds r5, #0x9c
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080ABE68
	b _080ABF90
_080ABE68:
	ldrb r1, [r5]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #8
	adds r7, r5, r0
	adds r1, r7, #0
	adds r1, #0x28
	movs r0, #1
	strb r0, [r1]
	ldr r4, _080ABF20 @ =0x0203B400
	ldr r0, _080ABF24 @ =0x030046B8
	mov r8, r0
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _080ABF28 @ =0x000003FF
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r3, #0xf
	ands r0, r3
	adds r0, #0x10
	adds r6, r7, #0
	adds r6, #0x2b
	strb r0, [r6]
	adds r1, #1
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r3
	adds r0, #0x40
	adds r6, #1
	strb r0, [r6]
	adds r1, #1
	ands r1, r2
	mov r2, r8
	str r1, [r2]
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	movs r1, #0x2d
	adds r1, r1, r7
	mov r8, r1
	strb r0, [r1]
	adds r1, r7, #0
	adds r1, #0x2e
	movs r0, #8
	strb r0, [r1]
	subs r1, #4
	movs r0, #0
	strb r0, [r1]
	mov r2, ip
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x30]
	str r1, [r7, #0x34]
	ldr r0, _080ABF2C @ =FUN_080abd74
	str r0, [r7, #0x38]
	adds r4, r7, #0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r0, sb
	adds r0, #0xa0
	ldr r1, [r0]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r2, [r0]
	adds r0, r4, #0
	bl FUN_0822dafc
	ldrb r3, [r6]
	ldr r2, _080ABF30 @ =0x085B0A08
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _080ABF34
	asrs r3, r0, #0xc
	b _080ABF3A
	.align 2, 0
_080ABF20: .4byte 0x0203B400
_080ABF24: .4byte 0x030046B8
_080ABF28: .4byte 0x000003FF
_080ABF2C: .4byte FUN_080abd74
_080ABF30: .4byte 0x085B0A08
_080ABF34:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080ABF3A:
	ldrh r0, [r7, #0x30]
	adds r0, r0, r3
	strh r0, [r4, #0x18]
	ldrh r0, [r7, #0x32]
	strh r0, [r4, #0x1a]
	adds r0, r7, #0
	adds r0, #0x2c
	ldrb r2, [r0]
	ldr r1, _080ABF64 @ =0x085B0A08
	adds r0, #1
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080ABF68
	asrs r1, r0, #0xc
	b _080ABF6E
	.align 2, 0
_080ABF64: .4byte 0x085B0A08
_080ABF68:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080ABF6E:
	ldrh r0, [r7, #0x34]
	adds r0, r0, r1
	movs r1, #0
	strh r0, [r4, #0x1c]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080ABF86
	strb r1, [r5]
_080ABF86:
	strb r1, [r5, #1]
	mov r1, sb
	adds r1, #0x9e
	movs r0, #1
	strb r0, [r1]
_080ABF90:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080abf9c
FUN_080abf9c: @ 0x080ABF9C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r0, #0x9e
	ldrb r0, [r0]
	cmp r0, #0
	beq _080ABFE4
	movs r3, #0
	adds r4, r6, #0
	adds r4, #0xcc
	adds r5, r6, #0
	adds r5, #0xa4
	movs r7, #7
_080ABFB6:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080ABFD0
	adds r0, r6, #0
	adds r0, #0xa0
	ldr r1, [r0]
	ldr r2, [r4, #0x10]
	adds r0, r5, #0
	str r3, [sp]
	bl _call_via_r2
	ldr r3, [sp]
	adds r3, #1
_080ABFD0:
	adds r4, #0x3c
	adds r5, #0x3c
	subs r7, #1
	cmp r7, #0
	bge _080ABFB6
	cmp r3, #0
	bne _080ABFE4
	adds r0, r6, #0
	adds r0, #0x9e
	strb r3, [r0]
_080ABFE4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080abfec
FUN_080abfec: @ 0x080ABFEC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0xa4
	movs r5, #7
_080ABFF4:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _080ABFF4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080ac008
FUN_080ac008: @ 0x080AC008
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x9c
	ldr r0, _080AC030 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #4]
	movs r0, #0
	strb r0, [r6]
	strb r0, [r6, #1]
	adds r4, #0x24
	ldrb r0, [r4]
	cmp r0, #7
	bne _080AC034
	movs r0, #0xe
	b _080AC03A
	.align 2, 0
_080AC030: .4byte 0x00001C1E
_080AC034:
	ldrb r0, [r4]
	adds r0, #1
	lsls r0, r0, #1
_080AC03A:
	mov sb, r0
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
	adds r4, r6, #0
	adds r4, #0x17
	adds r5, r6, #0
	adds r5, #8
	movs r7, #7
_080AC04C:
	movs r0, #0
	strb r0, [r4, #0x19]
	mov r0, sb
	strb r0, [r4, #0x1a]
	ldr r1, [r6, #4]
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r5, #0
	mov r1, r8
	mov r2, r8
	bl FUN_0822dad4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #0xf8
	strb r0, [r4, #1]
	movs r0, #2
	strb r0, [r4]
	adds r4, #0x3c
	adds r5, #0x3c
	subs r7, #1
	cmp r7, #0
	bge _080AC04C
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ac090
FUN_080ac090: @ 0x080AC090
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	ldr r7, [r0, #0x48]
	adds r0, #0x6d
	ldrb r0, [r0]
	movs r1, #0x10
	subs r1, r1, r0
	lsls r0, r1, #4
	subs r5, r0, r1
	movs r6, #0
	movs r0, #0x1f
	mov r8, r0
_080AC0AC:
	ldrh r1, [r7]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	mov r2, r8
	ands r3, r2
	lsrs r1, r1, #0x1a
	ands r1, r2
	mov r2, ip
	adds r2, #0x6d
	ldrb r2, [r2]
	muls r0, r2, r0
	adds r0, r5, r0
	asrs r4, r0, #4
	adds r0, r3, #0
	muls r0, r2, r0
	adds r0, r5, r0
	asrs r3, r0, #4
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r5, r0
	asrs r1, r0, #4
	lsls r0, r6, #1
	mov r2, ip
	adds r2, #0x4c
	adds r2, r2, r0
	lsls r0, r1, #0xa
	lsls r1, r3, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r2]
	adds r7, #2
	adds r6, #1
	cmp r6, #0xf
	ble _080AC0AC
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ac100
FUN_080ac100: @ 0x080AC100
	push {lr}
	adds r2, r0, #0
	adds r0, #0x6d
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080AC116
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	b _080AC11C
_080AC116:
	ldr r0, [r2]
	ldr r1, _080AC138 @ =0xFFFFFBFF
	ands r0, r1
_080AC11C:
	str r0, [r2]
	adds r1, r2, #0
	adds r1, #0x6d
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _080AC132
	adds r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	bl FUN_080ac090
_080AC132:
	pop {r0}
	bx r0
	.align 2, 0
_080AC138: .4byte 0xFFFFFBFF

	thumb_func_start FUN_080ac13c
FUN_080ac13c: @ 0x080AC13C
	push {lr}
	adds r2, r0, #0
	adds r0, #0x6d
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080AC152
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	b _080AC158
_080AC152:
	ldr r0, [r2]
	ldr r1, _080AC178 @ =0xFFFFFBFF
	ands r0, r1
_080AC158:
	str r0, [r2]
	adds r1, r2, #0
	adds r1, #0x6d
	ldrb r0, [r1]
	adds r3, r0, #0
	cmp r3, #0
	bne _080AC17C
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	adds r0, r2, #0
	adds r0, #0x6c
	strb r3, [r0]
	b _080AC186
	.align 2, 0
_080AC178: .4byte 0xFFFFFBFF
_080AC17C:
	subs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	bl FUN_080ac090
_080AC186:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ac18c
FUN_080ac18c: @ 0x080AC18C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AC214
	ldrh r0, [r4, #0x2a]
	ldrh r1, [r4, #0x26]
	adds r2, r0, #0
	cmp r1, r2
	bhs _080AC1B8
	adds r1, r4, #0
	adds r1, #0x25
	ldr r0, [r4, #0x18]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	beq _080AC1B8
	strh r2, [r4, #0x26]
_080AC1B8:
	ldrh r0, [r4, #0x26]
	adds r0, #1
	strh r0, [r4, #0x26]
	lsls r0, r0, #0x10
	lsls r1, r2, #0x10
	cmp r0, r1
	bhs _080AC20C
	adds r0, r4, #0
	adds r0, #0x2c
	bl FUN_080ac100
	ldr r0, [r4, #0x18]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r4, #0x48]
	str r1, [r4, #0x4c]
	adds r2, r4, #0
	adds r2, #0x48
	ldrh r0, [r4, #0x1c]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r1, r4, #0
	adds r1, #0x4a
	ldrh r0, [r4, #0x1e]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r4, #0x20]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r4, #0x26]
	ldrh r1, [r4, #0x28]
	cmp r0, r1
	bhs _080AC214
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080abe48
	b _080AC214
_080AC20C:
	adds r0, r4, #0
	adds r0, #0x2c
	bl FUN_080ac13c
_080AC214:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ac21c
FUN_080ac21c: @ 0x080AC21C
	push {lr}
	adds r0, #0x2c
	bl FUN_0822a4e0
	pop {r0}
	bx r0

	thumb_func_start FUN_080ac228
FUN_080ac228: @ 0x080AC228
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	mov sb, r1
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, #0x24
	ldrb r7, [r0]
	adds r0, r7, #0
	movs r1, #0x63
	mov r8, r1
	cmp r0, #0
	beq _080AC252
	movs r2, #0x6c
	mov r8, r2
	cmp r0, #1
	bne _080AC252
	movs r0, #0x62
	mov r8, r0
_080AC252:
	adds r6, r4, #0
	adds r6, #0x2c
	ldr r1, _080AC2D4 @ =0x00000BA8
	adds r0, r6, #0
	bl Video_GetActorSprite
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822a470
	strh r7, [r4, #0x10]
	movs r0, #3
	strb r0, [r4, #7]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldrh r0, [r5, #0x1c]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	ldrh r0, [r5, #0x1e]
	ldrh r2, [r4, #0x1e]
	adds r0, r0, r2
	strh r0, [r4, #0x1e]
	ldrh r0, [r5, #0x20]
	ldrh r1, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r4]
	ldr r0, _080AC2D8 @ =0x03003584
	mov r2, r8
	lsls r1, r2, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r4, #0x48]
	ldr r5, _080AC2DC @ =0x00003DEF
	adds r2, r4, #0
	adds r2, #0x4c
	adds r3, r4, #0
	adds r3, #0x6c
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x6a
_080AC2B6:
	strh r5, [r0]
	subs r0, #2
	cmp r0, r1
	bge _080AC2B6
	mov r0, r8
	strh r0, [r6, #6]
	str r2, [r6, #0xc]
	movs r0, #1
	strb r0, [r3]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AC2D4: .4byte 0x00000BA8
_080AC2D8: .4byte 0x03003584
_080AC2DC: .4byte 0x00003DEF

	thumb_func_start FUN_080ac2e0
FUN_080ac2e0: @ 0x080AC2E0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ac18c
	adds r0, r4, #0
	bl FUN_080abf9c
	adds r1, r4, #0
	adds r1, #0x98
	ldrb r1, [r1]
	cmp r1, #0
	bne _080AC308
	adds r1, r4, #0
	adds r1, #0x9e
	ldrb r1, [r1]
	cmp r1, #0
	bne _080AC308
	adds r0, r4, #0
	bl KillEntity
_080AC308:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080ac310
FUN_080ac310: @ 0x080AC310
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ac21c
	adds r0, r4, #0
	bl FUN_080abfec
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080ac324
FUN_080ac324: @ 0x080AC324
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x24
	strb r2, [r0]
	str r1, [r4, #0x18]
	cmp r3, #0
	bne _080AC33A
	strh r3, [r4, #0x1c]
	strh r3, [r4, #0x1e]
	strh r3, [r4, #0x20]
	b _080AC342
_080AC33A:
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
_080AC342:
	ldr r0, [r4, #0x18]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x25
	strb r0, [r1]
	ldr r0, [sp, #8]
	strh r0, [r4, #0x28]
	ldr r0, [sp, #0xc]
	strh r0, [r4, #0x2a]
	ldr r1, [r4, #0x18]
	adds r1, #0x2c
	adds r0, r4, #0
	bl FUN_080ac228
	adds r0, r4, #0
	bl FUN_080ac008
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080ac374
FUN_080ac374: @ 0x080AC374
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0xa1
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080AC3C4
	ldr r1, _080AC3BC @ =FUN_080ac2e0
	ldr r2, _080AC3C0 @ =FUN_080ac310
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_080ac324
	cmp r0, #0
	bge _080AC3C4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080AC3C6
	.align 2, 0
_080AC3BC: .4byte FUN_080ac2e0
_080AC3C0: .4byte FUN_080ac310
_080AC3C4:
	adds r0, r4, #0
_080AC3C6:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080ac3d4
FUN_080ac3d4: @ 0x080AC3D4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	ldr r1, [r6, #0x30]
	adds r0, r6, #0
	movs r2, #3
	bl FUN_0822dafc
	ldr r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	ldr r5, _080AC454 @ =0x0203B400
	ldr r0, _080AC458 @ =0x030046B8
	mov ip, r0
	ldr r2, [r0]
	adds r2, #1
	ldr r7, _080AC45C @ =0x000003FF
	ands r2, r7
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrh r0, [r6, #0x18]
	subs r0, #0x1f
	movs r3, #0x3f
	ands r1, r3
	adds r0, r0, r1
	movs r4, #0
	strh r0, [r6, #0x18]
	adds r2, #1
	ands r2, r7
	mov r1, ip
	str r2, [r1]
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrh r0, [r6, #0x1c]
	subs r0, #0x1f
	ands r1, r3
	adds r0, r0, r1
	strh r0, [r6, #0x1c]
	strh r4, [r6, #0x38]
	ldrh r0, [r6, #0x3e]
	cmp r0, #0
	beq _080AC460
	adds r0, r2, #1
	ands r0, r7
	mov r1, ip
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ldrh r1, [r6, #0x3e]
	bl Mod
	ldrh r1, [r6, #0x3c]
	adds r1, r1, r0
	strh r1, [r6, #0x3a]
	b _080AC464
	.align 2, 0
_080AC454: .4byte 0x0203B400
_080AC458: .4byte 0x030046B8
_080AC45C: .4byte 0x000003FF
_080AC460:
	ldrh r0, [r6, #0x3c]
	strh r0, [r6, #0x3a]
_080AC464:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ac46c
FUN_080ac46c: @ 0x080AC46C
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x38]
	adds r0, #1
	strh r0, [r2, #0x38]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _080AC48A
	ldr r1, [r2, #0x30]
	adds r0, r2, #0
	movs r2, #3
	bl FUN_0822dafc
	b _080AC4B0
_080AC48A:
	cmp r0, #7
	bhi _080AC49A
	ldr r1, [r2, #0x30]
	adds r0, r2, #0
	movs r2, #2
	bl FUN_0822dafc
	b _080AC4B0
_080AC49A:
	ldrh r1, [r2, #0x3a]
	cmp r0, r1
	bhs _080AC4AA
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _080AC4B0
_080AC4AA:
	adds r0, r2, #0
	bl FUN_080ac3d4
_080AC4B0:
	pop {r0}
	bx r0

	thumb_func_start FUN_080ac4b4
FUN_080ac4b4: @ 0x080AC4B4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #3
_080AC4BC:
	ldrh r0, [r4, #0x36]
	cmp r0, #0
	beq _080AC4C8
	adds r0, r4, #0
	bl FUN_080ac46c
_080AC4C8:
	adds r4, #0x40
	subs r5, #1
	cmp r5, #0
	bge _080AC4BC
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080ac4d8
FUN_080ac4d8: @ 0x080AC4D8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #3
_080AC4E0:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x40
	subs r5, #1
	cmp r5, #0
	bge _080AC4E0
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080ac4f8
FUN_080ac4f8: @ 0x080AC4F8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
	movs r7, #0
	mov r5, sb
	adds r5, #0x18
	adds r4, r5, #0
	movs r6, #3
_080AC512:
	ldr r0, _080AC56C @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r0, #0
	str r1, [r4, #0x30]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822d9f0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	adds r0, r5, #0
	mov r1, r8
	mov r2, r8
	bl FUN_0822dad4
	movs r0, #2
	strb r0, [r4, #0xf]
	movs r0, #0xec
	strb r0, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	strh r7, [r4, #0x34]
	strh r7, [r4, #0x36]
	adds r4, #0x40
	adds r5, #0x40
	subs r6, #1
	cmp r6, #0
	bge _080AC512
	ldr r0, _080AC570 @ =0x0000A854
	mov r1, sb
	movs r2, #0
	bl FUN_08230e30
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC56C: .4byte 0x00001C1E
_080AC570: .4byte 0x0000A854

	thumb_func_start FUN_080ac574
FUN_080ac574: @ 0x080AC574
	push {r4, lr}
	movs r1, #0x8c
	lsls r1, r1, #1
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080AC5AC
	ldr r1, _080AC5A4 @ =FUN_080ac4b4
	ldr r2, _080AC5A8 @ =FUN_080ac4d8
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080ac4f8
	cmp r0, #0
	bge _080AC5AC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080AC5AE
	.align 2, 0
_080AC5A4: .4byte FUN_080ac4b4
_080AC5A8: .4byte FUN_080ac4d8
_080AC5AC:
	adds r0, r4, #0
_080AC5AE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080ac5b4
FUN_080ac5b4: @ 0x080AC5B4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080AC5F0 @ =0x0000A854
	bl FUN_08230e70
	cmp r0, #0
	beq _080AC5E8
	movs r5, #1
	adds r1, r0, #0
	adds r1, #0x18
	movs r3, #0
	movs r2, #3
_080AC5CC:
	ldrh r0, [r1, #0x36]
	cmp r0, #0
	beq _080AC5E0
	ldrh r0, [r1, #0x34]
	cmp r0, r4
	bne _080AC5E0
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	strh r3, [r1, #0x36]
_080AC5E0:
	adds r1, #0x40
	subs r2, #1
	cmp r2, #0
	bge _080AC5CC
_080AC5E8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AC5F0: .4byte 0x0000A854

	thumb_func_start FUN_080ac5f4
FUN_080ac5f4: @ 0x080AC5F4
	push {lr}
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _080AC608
	bl Script_GetValue
	bl FUN_080ac5b4
_080AC608:
	pop {r0}
	bx r0

	thumb_func_start FUN_080ac60c
FUN_080ac60c: @ 0x080AC60C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	ldr r0, _080AC634 @ =0x0000A854
	bl FUN_08230e70
	adds r4, r0, #0
	cmp r4, #0
	bne _080AC62C
	bl FUN_080ac574
	adds r4, r0, #0
_080AC62C:
	movs r2, #0
	adds r1, r4, #0
	adds r1, #0x4e
	b _080AC640
	.align 2, 0
_080AC634: .4byte 0x0000A854
_080AC638:
	adds r1, #0x40
	adds r2, #1
	cmp r2, #3
	bgt _080AC68E
_080AC640:
	ldrh r0, [r1]
	cmp r0, #0
	bne _080AC638
	cmp r2, #3
	bgt _080AC68E
	lsls r0, r2, #6
	adds r1, r4, r0
	mov ip, r1
	adds r1, #0x4c
	strh r5, [r1]
	adds r3, r4, #0
	adds r3, #0x40
	adds r3, r3, r0
	ldr r1, [r6]
	ldr r2, [r6, #4]
	str r1, [r3]
	str r2, [r3, #4]
	mov r1, ip
	adds r1, #0x54
	strh r7, [r1]
	adds r1, #2
	mov r2, r8
	strh r2, [r1]
	mov r2, ip
	adds r2, #0x4e
	movs r1, #1
	strh r1, [r2]
	adds r2, r4, #0
	adds r2, #0x18
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, #0x18
	adds r0, r4, r0
	bl FUN_080ac3d4
_080AC68E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080ac698
FUN_080ac698: @ 0x080AC698
	push {r4, r5, lr}
	sub sp, #8
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _080AC6AE
	bl Script_GetValue
	adds r5, r0, #0
	b _080AC6B0
_080AC6AE:
	movs r5, #0
_080AC6B0:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080AC6F8
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080AC6F0 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080AC6F4 @ =0x0000FFFF
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
	b _080AC702
	.align 2, 0
_080AC6F0: .4byte 0xFFFF0000
_080AC6F4: .4byte 0x0000FFFF
_080AC6F8:
	ldr r1, _080AC71C @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_080AC702:
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080AC720
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r3, r0, #0
	b _080AC724
	.align 2, 0
_080AC71C: .4byte 0xFFFF0000
_080AC720:
	movs r4, #0x10
	movs r3, #0
_080AC724:
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	bl FUN_080ac60c
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ac738
FUN_080ac738: @ 0x080AC738
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r0, #0x48
	ldrh r0, [r0]
	ldrh r1, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	adds r0, r3, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
	adds r0, r3, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	ldrh r1, [r3, #0x20]
	adds r0, r0, r1
	strh r0, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x54
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x12
	movs r1, #3
	ands r0, r1
	strh r0, [r3, #0x10]
	adds r1, r3, #0
	adds r1, #0x56
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AC864
	ldr r2, _080AC7B0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AC7B4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AC7B8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x1f
	ands r0, r1
	adds r4, r0, #0
	subs r4, #0xf
	adds r6, r2, #0
	cmp r4, #0
	ble _080AC7BC
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	b _080AC7C4
	.align 2, 0
_080AC7B0: .4byte 0x030046B8
_080AC7B4: .4byte 0x000003FF
_080AC7B8: .4byte 0x0203B400
_080AC7BC:
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080AC7C4:
	str r0, [r3]
	adds r0, r3, #0
	adds r0, #0x58
	ldrh r0, [r0]
	adds r4, r4, r0
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _080AC80C @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _080AC810 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r3, #0
	adds r2, #0x5a
	asrs r0, r0, #3
	movs r1, #3
	ands r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	subs r5, r0, #1
	ldr r2, _080AC814 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AC818
	asrs r1, r0, #0xc
	b _080AC81E
	.align 2, 0
_080AC80C: .4byte 0x000003FF
_080AC810: .4byte 0x0203B400
_080AC814: .4byte 0x085B0A08
_080AC818:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AC81E:
	adds r0, r3, #0
	adds r0, #0x48
	strh r1, [r0]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AC83A
	asrs r2, r0, #0xc
	b _080AC840
_080AC83A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080AC840:
	adds r0, r3, #0
	adds r0, #0x4c
	strh r2, [r0]
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _080AC86C @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _080AC870 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xf
	adds r1, r3, #0
	adds r1, #0x56
	strh r0, [r1]
_080AC864:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AC86C: .4byte 0x000003FF
_080AC870: .4byte 0x0203B400

	thumb_func_start FUN_080ac874
FUN_080ac874: @ 0x080AC874
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	mov r3, ip
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	ldr r6, _080AC918 @ =0x0203B400
	ldr r5, _080AC91C @ =0x030046B8
	mov r8, r5
	ldr r1, [r5]
	adds r1, #1
	ldr r4, _080AC920 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ldrh r3, [r3, #0x1c]
	subs r3, #0xff
	asrs r0, r0, #3
	ldr r7, _080AC924 @ =0x000001FF
	adds r5, r7, #0
	ands r0, r5
	adds r3, r3, r0
	mov r0, ip
	strh r3, [r0, #0x1c]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	mov r7, ip
	ldrh r3, [r7, #0x20]
	subs r3, #0xff
	asrs r0, r0, #3
	ands r0, r5
	adds r3, r3, r0
	strh r3, [r7, #0x20]
	mov r3, ip
	adds r3, #0x58
	strh r2, [r3]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	movs r0, #0x1f
	ands r2, r0
	ldrh r3, [r3]
	adds r2, r2, r3
	adds r5, r2, #0
	subs r5, #0xf
	adds r1, #1
	ands r1, r4
	mov r0, r8
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	mov r3, ip
	adds r3, #0x5a
	movs r1, #3
	ands r0, r1
	ldrh r3, [r3]
	adds r0, r0, r3
	subs r4, r0, #1
	ldr r1, _080AC928 @ =0x085B0A08
	adds r2, #0x31
	movs r0, #0xff
	ands r2, r0
	lsls r2, r2, #1
	adds r2, r2, r1
	movs r3, #0
	ldrsh r0, [r2, r3]
	muls r0, r4, r0
	mov r2, r8
	cmp r0, #0
	blt _080AC92C
	asrs r3, r0, #0xc
	b _080AC932
	.align 2, 0
_080AC918: .4byte 0x0203B400
_080AC91C: .4byte 0x030046B8
_080AC920: .4byte 0x000003FF
_080AC924: .4byte 0x000001FF
_080AC928: .4byte 0x085B0A08
_080AC92C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080AC932:
	mov r0, ip
	adds r0, #0x48
	strh r3, [r0]
	movs r0, #0xff
	ands r5, r0
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AC94E
	asrs r1, r0, #0xc
	b _080AC954
_080AC94E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AC954:
	mov r0, ip
	adds r0, #0x4c
	strh r1, [r0]
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AC998 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r7, _080AC99C @ =0x0203B400
	adds r0, r0, r7
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xf
	mov r1, ip
	adds r1, #0x56
	strh r0, [r1]
	mov r1, ip
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r3, ip
	str r0, [r3]
	mov r1, ip
	adds r1, #0x50
	movs r0, #1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AC998: .4byte 0x000003FF
_080AC99C: .4byte 0x0203B400

	thumb_func_start FUN_080ac9a0
FUN_080ac9a0: @ 0x080AC9A0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r6, #0
_080AC9AE:
	movs r0, #0x5c
	adds r1, r6, #0
	muls r1, r0, r1
	adds r0, r7, r1
	adds r0, #0x90
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AC9C8
	adds r0, r1, #0
	adds r0, #0x40
	adds r0, r7, r0
	bl FUN_080ac738
_080AC9C8:
	adds r6, #1
	cmp r6, #0x17
	ble _080AC9AE
	movs r0, #0
	mov sb, r0
	ldr r1, _080ACA3C @ =0x0000FFFF
	mov r8, r1
	adds r5, r7, #0
	adds r5, #0x24
	adds r3, r7, #0
	adds r3, #0x1c
	movs r6, #2
_080AC9E0:
	ldrh r0, [r5, #2]
	adds r0, #1
	strh r0, [r5, #2]
	mov r1, r8
	ands r0, r1
	cmp r0, #0x1f
	bls _080ACA20
	movs r0, #0x8e
	lsls r0, r0, #4
	adds r4, r7, r0
	ldrh r1, [r4]
	movs r0, #0x5c
	muls r0, r1, r0
	adds r0, #0x40
	adds r0, r7, r0
	ldrh r2, [r5]
	adds r1, r3, #0
	str r3, [sp]
	bl FUN_080ac874
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	mov r1, r8
	ands r0, r1
	ldr r3, [sp]
	cmp r0, #0x17
	bls _080ACA1C
	mov r0, sb
	strh r0, [r4]
_080ACA1C:
	mov r1, sb
	strh r1, [r5, #2]
_080ACA20:
	adds r5, #0xc
	adds r3, #0xc
	subs r6, #1
	cmp r6, #0
	bge _080AC9E0
	movs r0, #0
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080ACA3C: .4byte 0x0000FFFF

	thumb_func_start FUN_080aca40
FUN_080aca40: @ 0x080ACA40
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x40
	movs r5, #0x17
_080ACA48:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x5c
	subs r5, #1
	cmp r5, #0
	bge _080ACA48
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080aca60
FUN_080aca60: @ 0x080ACA60
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	movs r6, #0
	mov r8, r6
	ldr r7, _080ACAD4 @ =0x030046B8
_080ACA70:
	movs r0, #0x5c
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, #0x40
	add r4, sb
	adds r5, r4, #0
	adds r5, #0x2c
	adds r0, r5, #0
	ldr r1, _080ACAD8 @ =0x0000CC88
	bl Video_GetActorSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	mov r0, r8
	strh r0, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080ACADC @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080ACAE0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #3
	ands r0, r1
	adds r0, #5
	adds r1, r4, #0
	adds r1, #0x5a
	strh r0, [r1]
	adds r4, #0x50
	mov r0, r8
	strb r0, [r4]
	adds r6, #1
	cmp r6, #0x17
	ble _080ACA70
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACAD4: .4byte 0x030046B8
_080ACAD8: .4byte 0x0000CC88
_080ACADC: .4byte 0x000003FF
_080ACAE0: .4byte 0x0203B400

	thumb_func_start FUN_080acae4
FUN_080acae4: @ 0x080ACAE4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _080ACB14
	adds r4, r7, #0
	adds r4, #0x1c
	movs r5, #2
_080ACAF8:
	bl Script_GetValue
	strh r0, [r4]
	bl Script_GetValue
	strh r0, [r4, #2]
	bl Script_GetValue
	strh r0, [r4, #4]
	adds r4, #0xc
	subs r5, #1
	cmp r5, #0
	bge _080ACAF8
	b _080ACB2A
_080ACB14:
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x1c
	movs r5, #2
_080ACB1C:
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	adds r0, #0xc
	subs r5, #1
	cmp r5, #0
	bge _080ACB1C
_080ACB2A:
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080ACB70
	ldr r6, _080ACB64 @ =0x030046B8
	adds r4, r7, #0
	adds r4, #0x24
	movs r5, #2
_080ACB3C:
	bl Script_GetValue
	strh r0, [r4]
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _080ACB68 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _080ACB6C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	strh r0, [r4, #2]
	adds r4, #0xc
	subs r5, #1
	cmp r5, #0
	bge _080ACB3C
	b _080ACBA0
	.align 2, 0
_080ACB64: .4byte 0x030046B8
_080ACB68: .4byte 0x000003FF
_080ACB6C: .4byte 0x0203B400
_080ACB70:
	movs r0, #0x20
	mov ip, r0
	ldr r6, _080ACBC0 @ =0x0203B400
	ldr r2, _080ACBC4 @ =0x030046B8
	adds r1, r7, #0
	adds r1, #0x24
	ldr r4, _080ACBC8 @ =0x000003FF
	movs r3, #0x1f
	movs r5, #2
_080ACB82:
	mov r0, ip
	strh r0, [r1]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r3
	strh r0, [r1, #2]
	adds r1, #0xc
	subs r5, #1
	cmp r5, #0
	bge _080ACB82
_080ACBA0:
	movs r5, #2
_080ACBA2:
	subs r5, #1
	cmp r5, #0
	bge _080ACBA2
	adds r0, r7, #0
	bl FUN_080aca60
	ldr r0, _080ACBCC @ =0x00003969
	adds r1, r7, #0
	movs r2, #0
	bl FUN_08230e30
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080ACBC0: .4byte 0x0203B400
_080ACBC4: .4byte 0x030046B8
_080ACBC8: .4byte 0x000003FF
_080ACBCC: .4byte 0x00003969

	thumb_func_start FUN_080acbd0
FUN_080acbd0: @ 0x080ACBD0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _080ACC00 @ =0x000008E4
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080ACC0C
	strh r5, [r4, #0x18]
	ldr r1, _080ACC04 @ =FUN_080ac9a0
	ldr r2, _080ACC08 @ =FUN_080aca40
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080acae4
	cmp r0, #0
	bge _080ACC0C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080ACC0E
	.align 2, 0
_080ACC00: .4byte 0x000008E4
_080ACC04: .4byte FUN_080ac9a0
_080ACC08: .4byte FUN_080aca40
_080ACC0C:
	adds r0, r4, #0
_080ACC0E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080acc14
FUN_080acc14: @ 0x080ACC14
	ldr r1, _080ACC1C @ =0x03002C54
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080ACC1C: .4byte 0x03002C54

	thumb_func_start FUN_080acc20
FUN_080acc20: @ 0x080ACC20
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrh r2, [r4, #0x2e]
	lsrs r2, r2, #1
	adds r2, #0xc
	bl FUN_0822dafc
	ldrh r0, [r4, #0x1a]
	adds r0, #0xa
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bne _080ACC54
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
_080ACC54:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080acc5c
FUN_080acc5c: @ 0x080ACC5C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r5, #0x18
	adds r4, r0, #0
	adds r4, #0x44
	movs r6, #7
_080ACC68:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080ACC74
	adds r0, r5, #0
	bl FUN_080acc20
_080ACC74:
	adds r5, #0x30
	adds r4, #0x30
	subs r6, #1
	cmp r6, #0
	bge _080ACC68
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080ACC88:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0x18, 0x34, 0x07, 0x25
	.byte 0x20, 0x1C, 0x80, 0xF1, 0x13, 0xFF, 0x30, 0x34, 0x01, 0x3D, 0x00, 0x2D, 0xF8, 0xDA, 0x00, 0x21
	.byte 0x02, 0x48, 0x01, 0x60, 0x00, 0x20, 0x30, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x54, 0x2C, 0x00, 0x03

	thumb_func_start FUN_080accb0
FUN_080accb0: @ 0x080ACCB0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r1, #0
	mov r8, r1
	adds r4, r0, #0
	adds r4, #0x18
	adds r6, r0, #0
	adds r6, #0x44
	adds r5, r4, #0
	movs r0, #8
	rsbs r0, r0, #0
	mov sb, r0
	movs r7, #7
_080ACCCE:
	mov r1, r8
	strb r1, [r6]
	strb r1, [r6, #1]
	mov r0, r8
	strh r0, [r4, #0x2e]
	ldr r0, _080ACD24 @ =0x00001C1A
	bl GetParticleGroup
	adds r1, r0, #0
	str r1, [r4, #0x28]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822d9f0
	adds r0, r5, #0
	mov r1, sb
	mov r2, sb
	bl FUN_0822dad4
	ldr r1, [r4, #0x28]
	adds r0, r5, #0
	movs r2, #0xc
	bl FUN_0822dafc
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r0, #2
	strb r0, [r4, #0xf]
	adds r4, #0x30
	adds r6, #0x30
	adds r5, #0x30
	subs r7, #1
	cmp r7, #0
	bge _080ACCCE
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACD24: .4byte 0x00001C1A

	thumb_func_start FUN_080acd28
FUN_080acd28: @ 0x080ACD28
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080accb0
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080ACD48 @ =0x03002C54
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080ACD48: .4byte 0x03002C54

	thumb_func_start FUN_080acd4c
FUN_080acd4c: @ 0x080ACD4C
	push {r4, lr}
	ldr r0, _080ACD84 @ =0x03002C54
	ldr r0, [r0]
	cmp r0, #0
	bne _080ACD92
	movs r1, #0xce
	lsls r1, r1, #1
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080ACD90
	ldr r1, _080ACD88 @ =FUN_080acc5c
	ldr r2, _080ACD8C @ =0x080ACC89
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080acd28
	cmp r0, #0
	bge _080ACD90
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080ACD92
	.align 2, 0
_080ACD84: .4byte 0x03002C54
_080ACD88: .4byte FUN_080acc5c
_080ACD8C: .4byte 0x080ACC89
_080ACD90:
	adds r0, r4, #0
_080ACD92:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080acd98
FUN_080acd98: @ 0x080ACD98
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, _080ACDF4 @ =0x03002C54
	ldr r0, [r4]
	cmp r0, #0
	bne _080ACDA8
	bl FUN_080acd4c
_080ACDA8:
	ldr r2, [r4]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, #0x18
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	movs r1, #0
	strh r1, [r2, #0x2e]
	adds r2, #0x2c
	movs r0, #1
	strb r0, [r2]
	ldr r0, [r4]
	adds r2, r0, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080ACDEC
	strh r1, [r2]
_080ACDEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ACDF4: .4byte 0x03002C54

	thumb_func_start FUN_080acdf8
FUN_080acdf8: @ 0x080ACDF8
	push {r4, r5, lr}
	mov ip, r0
	mov r1, ip
	adds r1, #0x48
	adds r0, #0x50
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	ldr r3, _080ACE88 @ =0x00000FFF
	adds r2, r3, #0
	ands r0, r2
	strh r0, [r1]
	mov r3, ip
	adds r3, #0x4a
	mov r0, ip
	adds r0, #0x52
	ldrh r0, [r0]
	ldrh r4, [r3]
	adds r0, r0, r4
	ands r0, r2
	strh r0, [r3]
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	mov r1, ip
	strh r0, [r1, #0x1c]
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r1, #0x1e]
	adds r1, #0x5c
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x12
	movs r1, #3
	ands r0, r1
	mov r2, ip
	strh r0, [r2, #0x10]
	mov r1, ip
	adds r1, #0x5e
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080ACF44
	ldr r2, _080ACE8C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080ACE90 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080ACE94 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x1f
	ands r0, r1
	adds r3, r0, #0
	subs r3, #0xf
	adds r5, r2, #0
	cmp r3, #0
	ble _080ACE98
	mov r4, ip
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	str r0, [r4]
	b _080ACEA6
	.align 2, 0
_080ACE88: .4byte 0x00000FFF
_080ACE8C: .4byte 0x030046B8
_080ACE90: .4byte 0x000003FF
_080ACE94: .4byte 0x0203B400
_080ACE98:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
_080ACEA6:
	mov r0, ip
	adds r0, #0x60
	ldrh r0, [r0]
	adds r3, r3, r0
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _080ACEEC @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r4, _080ACEF0 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	mov r2, ip
	adds r2, #0x62
	asrs r0, r0, #3
	movs r1, #0xf
	ands r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	subs r4, r0, #7
	ldr r2, _080ACEF4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080ACEF8
	asrs r1, r0, #0xc
	b _080ACEFE
	.align 2, 0
_080ACEEC: .4byte 0x000003FF
_080ACEF0: .4byte 0x0203B400
_080ACEF4: .4byte 0x085B0A08
_080ACEF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080ACEFE:
	mov r0, ip
	adds r0, #0x50
	strh r1, [r0]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _080ACF1A
	asrs r0, r0, #0xc
	b _080ACF20
_080ACF1A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080ACF20:
	mov r1, ip
	adds r1, #0x52
	strh r0, [r1]
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _080ACF4C @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r3, _080ACF50 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xf
	mov r1, ip
	adds r1, #0x5e
	strh r0, [r1]
_080ACF44:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ACF4C: .4byte 0x000003FF
_080ACF50: .4byte 0x0203B400

	thumb_func_start FUN_080acf54
FUN_080acf54: @ 0x080ACF54
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x2c
	movs r5, #0xf
_080ACF5C:
	adds r0, r4, #0
	bl FUN_080acdf8
	adds r4, #0x64
	subs r5, #1
	cmp r5, #0
	bge _080ACF5C
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080acf74
FUN_080acf74: @ 0x080ACF74
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x2c
	movs r5, #0xf
_080ACF7C:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x64
	subs r5, #1
	cmp r5, #0
	bge _080ACF7C
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080acf94
FUN_080acf94: @ 0x080ACF94
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	movs r0, #0
	mov sl, r0
	ldr r1, _080AD084 @ =0x0203B400
	mov r8, r1
	ldr r6, _080AD088 @ =0x030046B8
	ldr r7, _080AD08C @ =0x000003FF
_080ACFAC:
	movs r0, #0x64
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	adds r0, #0x2c
	mov r3, sb
	adds r5, r3, r0
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _080AD090 @ =0x0000CC88
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r0, [r5]
	movs r1, #0x10
	orrs r0, r1
	str r0, [r5]
	movs r0, #1
	strb r0, [r5, #7]
	mov r0, sb
	ldrh r1, [r0, #0x26]
	adds r0, r5, #0
	adds r0, #0x60
	strh r1, [r0]
	ldr r1, [r6]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r2, #0xf
	ands r0, r2
	adds r0, #0x10
	adds r2, r5, #0
	adds r2, #0x62
	strh r0, [r2]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r0, #3
	ldr r3, _080AD094 @ =0x00000FFF
	ands r0, r3
	subs r2, #0x1a
	strh r0, [r2]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r0, #3
	ands r0, r3
	adds r3, r5, #0
	adds r3, #0x4a
	strh r0, [r3]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r5, #0x1c]
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r5, #0x1e]
	adds r1, #1
	ands r1, r7
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	movs r1, #0xf
	ands r0, r1
	adds r1, r5, #0
	adds r1, #0x5c
	strh r0, [r1]
	lsrs r0, r0, #2
	strh r0, [r5, #0x10]
	mov r2, sb
	ldrh r1, [r2, #0x2a]
	ldr r3, _080AD098 @ =0x000001D3
	adds r1, r1, r3
	adds r0, r4, #0
	bl FUN_0822b20c
	ldr r0, [r6]
	adds r0, #1
	ands r0, r7
	str r0, [r6]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x1f
	ands r0, r1
	adds r3, r0, #0
	subs r3, #0xf
	cmp r3, #0
	ble _080AD09C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080AD0A4
	.align 2, 0
_080AD084: .4byte 0x0203B400
_080AD088: .4byte 0x030046B8
_080AD08C: .4byte 0x000003FF
_080AD090: .4byte 0x0000CC88
_080AD094: .4byte 0x00000FFF
_080AD098: .4byte 0x000001D3
_080AD09C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080AD0A4:
	str r0, [r5]
	adds r0, r5, #0
	adds r0, #0x60
	ldrh r0, [r0]
	adds r3, r3, r0
	ldr r0, [r6]
	adds r0, #1
	ands r0, r7
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _080AD0E8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r2, r5, #0
	adds r2, #0x62
	asrs r1, r1, #3
	movs r0, #3
	ands r1, r0
	ldrh r2, [r2]
	adds r4, r1, r2
	ldr r2, _080AD0EC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AD0F0
	asrs r1, r0, #0xc
	b _080AD0F6
	.align 2, 0
_080AD0E8: .4byte 0x0203B400
_080AD0EC: .4byte 0x085B0A08
_080AD0F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AD0F6:
	adds r0, r5, #0
	adds r0, #0x50
	strh r1, [r0]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AD112
	asrs r0, r0, #0xc
	b _080AD118
_080AD112:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AD118:
	adds r3, r5, #0
	adds r3, #0x52
	strh r0, [r3]
	ldr r0, [r6]
	adds r0, #1
	ands r0, r7
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _080AD154 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xf
	adds r1, r5, #0
	adds r1, #0x5e
	strh r0, [r1]
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #0xf
	bgt _080AD146
	b _080ACFAC
_080AD146:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD154: .4byte 0x0203B400

	thumb_func_start FUN_080ad158
FUN_080ad158: @ 0x080AD158
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x60
	strh r0, [r4, #0x26]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080AD170
	bl Script_GetValue
	b _080AD172
_080AD170:
	movs r0, #6
_080AD172:
	strh r0, [r4, #0x2a]
	adds r0, r4, #0
	bl FUN_080acf94
	ldr r2, _080AD19C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AD1A0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AD1A4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	strh r0, [r4, #0x24]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AD19C: .4byte 0x030046B8
_080AD1A0: .4byte 0x000003FF
_080AD1A4: .4byte 0x0203B400

	thumb_func_start FUN_080ad1a8
FUN_080ad1a8: @ 0x080AD1A8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _080AD1D8 @ =0x0000066C
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080AD1E4
	strh r5, [r4, #0x18]
	ldr r1, _080AD1DC @ =FUN_080acf54
	ldr r2, _080AD1E0 @ =FUN_080acf74
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080ad158
	cmp r0, #0
	bge _080AD1E4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080AD1E6
	.align 2, 0
_080AD1D8: .4byte 0x0000066C
_080AD1DC: .4byte FUN_080acf54
_080AD1E0: .4byte FUN_080acf74
_080AD1E4:
	adds r0, r4, #0
_080AD1E6:
	pop {r4, r5}
	pop {r1}
	bx r1


