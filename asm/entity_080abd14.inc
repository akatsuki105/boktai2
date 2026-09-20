	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
	bl Particle_Remove
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
	bl Particle_SetOffset
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
	bl AuxSprite_Remove
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
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
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
	bl AuxSprite_Remove
	adds r4, #0x68
	adds r0, r4, #0
	bl AuxSprite_Remove
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
	bl Video_GetAuxSprite
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r5, #1
	movs r1, #0
	mov sb, r1
	strh r5, [r7, #0x10]
	adds r1, r4, #0
	adds r1, #0x2c
	adds r0, r6, #0
	bl Video_SetAuxSpritePltt
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
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r0, sb
	strh r0, [r4, #0x10]
	ldr r2, [sp]
	ldr r0, _080ABC14 @ =0x00000113
	adds r1, r2, r0
	adds r0, r6, #0
	bl Video_SetAuxSpritePltt
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

	thumb_func_start Entity080abd14_Update
Entity080abd14_Update: @ 0x080ABC1C
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

	thumb_func_start Entity080abd14_Destroy
Entity080abd14_Destroy: @ 0x080ABC84
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

	thumb_func_start Entity080abd14_Init
Entity080abd14_Init: @ 0x080ABCD0
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

	thumb_func_start Entity080abd14_Create
Entity080abd14_Create: @ 0x080ABD14
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
	ldr r1, _080ABD5C @ =Entity080abd14_Update
	ldr r2, _080ABD60 @ =Entity080abd14_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl Entity080abd14_Init
	cmp r0, #0
	bge _080ABD64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080ABD66
	.align 2, 0
_080ABD5C: .4byte Entity080abd14_Update
_080ABD60: .4byte Entity080abd14_Destroy
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
