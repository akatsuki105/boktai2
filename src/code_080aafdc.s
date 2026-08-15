	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ ファイルが巨大だったため適当に分割しています。

	thumb_func_start FUN_080aafdc
FUN_080aafdc: @ 0x080AAFDC
	push {r4, lr}
	movs r0, #9
	movs r1, #0x84
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080AB010
	ldr r1, _080AB008 @ =FUN_080aad80
	ldr r2, _080AB00C @ =FUN_080aadbc
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080aadcc
	cmp r0, #0
	bge _080AB010
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080AB012
	.align 2, 0
_080AB008: .4byte FUN_080aad80
_080AB00C: .4byte FUN_080aadbc
_080AB010:
	adds r0, r4, #0
_080AB012:
	pop {r4}
	pop {r1}
	bx r1

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
	bl FUN_0822b16c
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
	bl FUN_0822b16c
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
	bl FUN_0822b16c
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
	bl FUN_0822b16c
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
	bl FUN_0822b16c
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
	bl FUN_0822b16c
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

	thumb_func_start FUN_080ad1ec
FUN_080ad1ec: @ 0x080AD1EC
	ldr r3, _080AD1FC @ =0x000004FC
	adds r2, r0, r3
	movs r3, #0
	strh r1, [r2]
	ldr r1, _080AD200 @ =0x000004FE
	adds r0, r0, r1
	strh r3, [r0]
	bx lr
	.align 2, 0
_080AD1FC: .4byte 0x000004FC
_080AD200: .4byte 0x000004FE

	thumb_func_start FUN_080ad204
FUN_080ad204: @ 0x080AD204
	push {lr}
	sub sp, #0xc
	adds r3, r1, #0
	ldr r1, _080AD234 @ =0x000017A4
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080AD22E
	ldr r1, _080AD238 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	str r3, [sp]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_080AD22E:
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_080AD234: .4byte 0x000017A4
_080AD238: .4byte 0xFFFF0000

	thumb_func_start FUN_080ad23c
FUN_080ad23c: @ 0x080AD23C
	push {r4, r5, r6, r7, lr}
	movs r1, #0xac
	lsls r1, r1, #3
	adds r6, r0, r1
	ldr r1, _080AD284 @ =0x00000BE4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AD2C4
	movs r7, #0
	movs r5, #0
_080AD252:
	movs r0, #0x34
	muls r0, r5, r0
	adds r0, #4
	adds r2, r6, r0
	adds r3, r2, #0
	adds r3, #0x30
	ldrb r0, [r3]
	cmp r0, #0
	beq _080AD2B8
	adds r4, r2, #0
	adds r4, #0x31
	adds r1, r2, #0
	adds r1, #0x32
	ldrb r0, [r4]
	ldrb r1, [r1]
	cmp r0, r1
	blo _080AD288
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r3]
	b _080AD2B8
	.align 2, 0
_080AD284: .4byte 0x00000BE4
_080AD288:
	movs r7, #1
	ldrh r0, [r2, #0x28]
	ldrh r1, [r2, #0x18]
	adds r0, r0, r1
	strh r0, [r2, #0x18]
	ldrh r0, [r2, #0x2a]
	ldrh r1, [r2, #0x1a]
	adds r0, r0, r1
	strh r0, [r2, #0x1a]
	ldrh r0, [r2, #0x2c]
	ldrh r1, [r2, #0x1c]
	adds r0, r0, r1
	strh r0, [r2, #0x1c]
	ldrb r0, [r4]
	cmp r0, #6
	bne _080AD2B2
	ldr r1, [r6]
	adds r0, r2, #0
	movs r2, #3
	bl FUN_0822dafc
_080AD2B2:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_080AD2B8:
	adds r5, #1
	cmp r5, #0x1f
	ble _080AD252
	ldr r1, _080AD2CC @ =0x00000684
	adds r0, r6, r1
	strb r7, [r0]
_080AD2C4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD2CC: .4byte 0x00000684

	thumb_func_start FUN_080ad2d0
FUN_080ad2d0: @ 0x080AD2D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	mov r8, r2
	mov sb, r3
	ldr r6, [sp, #0x20]
	movs r0, #0xac
	lsls r0, r0, #3
	adds r3, r5, r0
	ldr r2, _080AD360 @ =0x00000BE5
	adds r7, r5, r2
	ldrb r2, [r7]
	movs r0, #0x34
	adds r4, r2, #0
	muls r4, r0, r4
	adds r4, #4
	adds r4, r3, r4
	ldr r0, [r4]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r4]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	movs r0, #0
	mov sl, r0
	strb r6, [r4, #0xf]
	ldr r1, [r3]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x31
	mov r1, sl
	strb r1, [r0]
	adds r0, #1
	mov r2, sb
	strb r2, [r0]
	adds r4, #0x30
	movs r0, #1
	strb r0, [r4]
	ldr r1, _080AD364 @ =0x00000BE4
	adds r5, r5, r1
	strb r0, [r5]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _080AD350
	mov r2, sl
	strb r2, [r7]
_080AD350:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD360: .4byte 0x00000BE5
_080AD364: .4byte 0x00000BE4

	thumb_func_start FUN_080ad368
FUN_080ad368: @ 0x080AD368
	push {r4, r5, lr}
	ldr r1, _080AD384 @ =0x00000564
	adds r4, r0, r1
	movs r5, #0x1f
_080AD370:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080AD370
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AD384: .4byte 0x00000564

	thumb_func_start FUN_080ad388
FUN_080ad388: @ 0x080AD388
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r0, #0xac
	lsls r0, r0, #3
	adds r6, r4, r0
	ldr r0, _080AD3E0 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6]
	ldr r0, _080AD3E4 @ =0x00000BE4
	adds r4, r4, r0
	movs r0, #0
	strb r0, [r4]
	movs r5, #0
	movs r7, #4
	rsbs r7, r7, #0
_080AD3A8:
	movs r0, #0x34
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #4
	adds r4, r6, r4
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r7, #0
	bl FUN_0822dad4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	adds r4, #0x30
	movs r0, #0
	strb r0, [r4]
	adds r5, #1
	cmp r5, #0x1f
	ble _080AD3A8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD3E0: .4byte 0x00001C1E
_080AD3E4: .4byte 0x00000BE4

	thumb_func_start FUN_080ad3e8
FUN_080ad3e8: @ 0x080AD3E8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AD400 @ =0x00000C0B
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080AD4D8
	lsls r0, r0, #2
	ldr r1, _080AD404 @ =_080AD408
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080AD400: .4byte 0x00000C0B
_080AD404: .4byte _080AD408
_080AD408: @ jump table
	.4byte _080AD420 @ case 0
	.4byte _080AD434 @ case 1
	.4byte _080AD458 @ case 2
	.4byte _080AD46C @ case 3
	.4byte _080AD498 @ case 4
	.4byte _080AD4C8 @ case 5
_080AD420:
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #2
	strb r1, [r0]
	ldr r3, _080AD430 @ =0x0000022D
	adds r0, r4, r3
	b _080AD4D6
	.align 2, 0
_080AD430: .4byte 0x0000022D
_080AD434:
	movs r0, #0x8b
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	ldr r1, _080AD450 @ =0x0000022D
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _080AD454 @ =0x00001426
	adds r1, r4, r3
	movs r0, #1
	strh r0, [r1]
	b _080AD484
	.align 2, 0
_080AD450: .4byte 0x0000022D
_080AD454: .4byte 0x00001426
_080AD458:
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	ldr r3, _080AD468 @ =0x0000022D
	adds r0, r4, r3
	b _080AD4D6
	.align 2, 0
_080AD468: .4byte 0x0000022D
_080AD46C:
	movs r1, #0x8b
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _080AD48C @ =0x0000022D
	adds r0, r4, r3
	movs r1, #1
	strb r1, [r0]
	ldr r3, _080AD490 @ =0x00001426
	adds r0, r4, r3
	strh r1, [r0]
_080AD484:
	ldr r1, _080AD494 @ =0x00001424
	adds r0, r4, r1
	strh r2, [r0]
	b _080AD4D8
	.align 2, 0
_080AD48C: .4byte 0x0000022D
_080AD490: .4byte 0x00001426
_080AD494: .4byte 0x00001424
_080AD498:
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080AD4BC @ =0x0000022D
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	ldr r1, _080AD4C0 @ =0x00001426
	adds r0, r4, r1
	strh r2, [r0]
	ldr r2, _080AD4C4 @ =0x00001424
	adds r0, r4, r2
	strh r3, [r0]
	b _080AD4D8
	.align 2, 0
_080AD4BC: .4byte 0x0000022D
_080AD4C0: .4byte 0x00001426
_080AD4C4: .4byte 0x00001424
_080AD4C8:
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r1, #2
	strb r1, [r0]
	ldr r2, _080AD4E0 @ =0x0000022D
	adds r0, r4, r2
_080AD4D6:
	strb r1, [r0]
_080AD4D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD4E0: .4byte 0x0000022D

	thumb_func_start FUN_080ad4e4
FUN_080ad4e4: @ 0x080AD4E4
	push {lr}
	adds r1, r0, #0
	adds r0, #0x68
	ldrh r0, [r0]
	cmp r0, #0
	beq _080AD4FE
	ldr r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080AD4FE
	movs r0, #1
	b _080AD500
_080AD4FE:
	movs r0, #0
_080AD500:
	pop {r1}
	bx r1

	thumb_func_start FUN_080ad504
FUN_080ad504: @ 0x080AD504
	push {lr}
	adds r1, r0, #0
	adds r1, #0x6e
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x81
	bls _080AD51C
	movs r0, #0
	strh r0, [r1]
_080AD51C:
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _080AD526
	movs r0, #0
	b _080AD540
_080AD526:
	cmp r0, #0x27
	bls _080AD53A
	cmp r0, #0x31
	bls _080AD53E
	cmp r0, #0x6d
	bhi _080AD536
	movs r0, #3
	b _080AD540
_080AD536:
	cmp r0, #0x77
	bls _080AD53E
_080AD53A:
	movs r0, #1
	b _080AD540
_080AD53E:
	movs r0, #2
_080AD540:
	pop {r1}
	bx r1

	thumb_func_start FUN_080ad544
FUN_080ad544: @ 0x080AD544
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _080AD56A
	mov r4, sp
	movs r5, #2
_080AD55C:
	bl Script_GetValue
	stm r4!, {r0}
	subs r5, #1
	cmp r5, #0
	bge _080AD55C
	b _080AD58E
_080AD56A:
	ldr r0, _080AD67C @ =0x08251D7C
	bl FUN_08230860
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldr r0, _080AD680 @ =0x08251D98
	bl FUN_08230860
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldr r0, _080AD684 @ =0x08251DB4
	bl FUN_08230860
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
_080AD58E:
	movs r5, #0
	mov r6, sp
_080AD592:
	lsls r4, r5, #2
	ldm r6!, {r1}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080AD688 @ =0x000092B3
	bl GetFile
	movs r2, #0x88
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r1, r1, r4
	adds r0, #0x14
	str r0, [r1]
	adds r5, #1
	cmp r5, #2
	ble _080AD592
	bl FUN_0823e1b0
	ldr r3, _080AD68C @ =0x00000C0B
	adds r1, r7, r3
	movs r4, #0
	strb r0, [r1]
	ldrb r1, [r1]
	adds r0, r7, #0
	bl FUN_080ad3e8
	ldr r1, _080AD690 @ =0x00001426
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, _080AD694 @ =0x00001424
	adds r0, r7, r2
	strh r4, [r0]
	ldr r3, _080AD698 @ =0x0000022D
	adds r0, r7, r3
	ldrb r1, [r0]
	lsls r1, r1, #2
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r7, r2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	adds r6, r7, #0
	adds r6, #0x20
	mov r4, r8
	movs r5, #0xf
_080AD5EE:
	adds r0, r4, #0
	adds r1, r6, #0
	ldr r2, _080AD69C @ =0x04000008
	bl CpuSet
	adds r6, #0x20
	adds r4, #0x20
	subs r5, #1
	cmp r5, #0
	bge _080AD5EE
	ldr r6, _080AD6A0 @ =0x03004250
	mov r4, r8
	movs r5, #2
_080AD608:
	adds r0, r4, #0
	adds r1, r6, #0
	ldr r2, _080AD69C @ =0x04000008
	bl CpuSet
	adds r6, #0x20
	adds r4, #0x20
	subs r5, #1
	cmp r5, #0
	bge _080AD608
	movs r5, #2
	movs r3, #0x8d
	lsls r3, r3, #2
	adds r0, r7, r3
_080AD624:
	strh r5, [r0]
	subs r0, #2
	subs r5, #1
	cmp r5, #0
	bge _080AD624
	movs r0, #0x95
	lsls r0, r0, #2
	adds r4, r7, r0
	adds r0, r4, #0
	bl FUN_080ad4e4
	cmp r0, #0
	beq _080AD664
	adds r0, r4, #0
	bl FUN_080ad504
	ldr r1, _080AD6A4 @ =0x000002BE
	adds r2, r7, r1
	strh r0, [r2]
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r0, r7, r3
	subs r3, #0x53
	adds r1, r7, r3
	ldrb r1, [r1]
	lsls r1, r1, #2
	ldrh r2, [r2]
	subs r3, #0xa5
	adds r2, r2, r3
	adds r1, r1, r2
	bl FUN_0822b20c
_080AD664:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0
	str r0, [r1]
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD67C: .4byte 0x08251D7C
_080AD680: .4byte 0x08251D98
_080AD684: .4byte 0x08251DB4
_080AD688: .4byte 0x000092B3
_080AD68C: .4byte 0x00000C0B
_080AD690: .4byte 0x00001426
_080AD694: .4byte 0x00001424
_080AD698: .4byte 0x0000022D
_080AD69C: .4byte 0x04000008
_080AD6A0: .4byte 0x03004250
_080AD6A4: .4byte 0x000002BE

	thumb_func_start FUN_080ad6a8
FUN_080ad6a8: @ 0x080AD6A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	bl FUN_0823e1b0
	adds r2, r0, #0
	ldr r1, _080AD768 @ =0x00000C0B
	add r1, r8
	ldrb r0, [r1]
	cmp r0, r2
	beq _080AD6D0
	strb r2, [r1]
	ldrb r1, [r1]
	mov r0, r8
	bl FUN_080ad3e8
_080AD6D0:
	ldr r0, _080AD76C @ =0x00001426
	add r0, r8
	ldrh r0, [r0]
	cmp r0, #0
	bne _080AD6DC
	b _080AD914
_080AD6DC:
	ldr r1, _080AD770 @ =0x00001428
	add r1, r8
	movs r0, #1
	strh r0, [r1]
	ldr r1, _080AD774 @ =0x00001424
	add r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _080AD784
	ldr r0, _080AD778 @ =0x0000022D
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #2
	movs r1, #0x88
	lsls r1, r1, #2
	add r1, r8
	adds r1, r1, r0
	mov r5, r8
	adds r5, #0x20
	ldr r4, [r1]
	movs r6, #0xf
_080AD70E:
	adds r0, r4, #0
	adds r1, r5, #0
	ldr r2, _080AD77C @ =0x04000008
	bl CpuSet
	adds r5, #0x20
	adds r4, #0x20
	subs r6, #1
	cmp r6, #0
	bge _080AD70E
	ldr r0, _080AD76C @ =0x00001426
	add r0, r8
	movs r1, #0
	strh r1, [r0]
	movs r4, #0x95
	lsls r4, r4, #2
	add r4, r8
	adds r0, r4, #0
	bl FUN_080ad4e4
	cmp r0, #0
	bne _080AD73C
	b _080AD952
_080AD73C:
	adds r0, r4, #0
	bl FUN_080ad504
	ldr r2, _080AD780 @ =0x000002BE
	add r2, r8
	strh r0, [r2]
	movs r0, #0xa0
	lsls r0, r0, #2
	add r0, r8
	ldr r1, _080AD778 @ =0x0000022D
	add r1, r8
	ldrb r1, [r1]
	lsls r1, r1, #2
	ldrh r2, [r2]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r2, r2, r3
	adds r1, r1, r2
	bl FUN_0822b20c
	b _080AD952
	.align 2, 0
_080AD768: .4byte 0x00000C0B
_080AD76C: .4byte 0x00001426
_080AD770: .4byte 0x00001428
_080AD774: .4byte 0x00001424
_080AD778: .4byte 0x0000022D
_080AD77C: .4byte 0x04000008
_080AD780: .4byte 0x000002BE
_080AD784:
	ldrh r1, [r1]
	movs r0, #0x40
	subs r0, r0, r1
	mov sl, r0
	mov sb, r1
	movs r0, #0x8b
	lsls r0, r0, #2
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #2
	movs r1, #0x88
	lsls r1, r1, #2
	add r1, r8
	adds r0, r1, r0
	ldr r0, [r0]
	mov ip, r0
	ldr r0, _080AD90C @ =0x0000022D
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r7, [r1]
	movs r0, #0
	mov r5, r8
	adds r5, #0x20
	str r5, [sp, #0x14]
_080AD7B8:
	movs r1, #0
	str r1, [sp]
	lsls r2, r0, #5
	str r2, [sp, #0x10]
	adds r0, #1
	str r0, [sp, #0xc]
_080AD7C4:
	mov r5, ip
	ldrh r3, [r5]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	movs r0, #0x1f
	ands r6, r0
	lsrs r3, r3, #0x1a
	ands r3, r0
	ldrh r1, [r7]
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x15
	movs r5, #0x1f
	ands r4, r5
	lsrs r1, r1, #0x1a
	ands r1, r5
	mov r5, sl
	muls r5, r2, r5
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	adds r5, r5, r0
	asrs r5, r5, #6
	mov r2, sl
	muls r2, r6, r2
	mov r0, sb
	muls r0, r4, r0
	adds r2, r2, r0
	asrs r2, r2, #6
	mov r0, sl
	muls r0, r3, r0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	asrs r0, r0, #6
	ldr r3, [sp]
	lsls r1, r3, #1
	ldr r3, [sp, #0x10]
	adds r1, r1, r3
	ldr r3, [sp, #0x14]
	adds r1, r3, r1
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	strh r0, [r1]
	movs r5, #2
	add ip, r5
	adds r7, #2
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	cmp r0, #0xf
	ble _080AD7C4
	ldr r0, [sp, #0xc]
	cmp r0, #0xf
	ble _080AD7B8
	movs r4, #0x95
	lsls r4, r4, #2
	add r4, r8
	adds r0, r4, #0
	bl FUN_080ad4e4
	cmp r0, #0
	bne _080AD84E
	b _080AD952
_080AD84E:
	adds r0, r4, #0
	bl FUN_080ad504
	ldr r2, _080AD910 @ =0x03003584
	movs r1, #0x8b
	lsls r1, r1, #2
	add r1, r8
	ldrb r1, [r1]
	lsls r1, r1, #2
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r2, [r2]
	adds r1, r2, r1
	str r1, [sp, #4]
	ldr r1, _080AD90C @ =0x0000022D
	add r1, r8
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r2, r1
	mov ip, r2
	movs r7, #0xa7
	lsls r7, r7, #2
	add r7, r8
	movs r5, #0xf
	str r5, [sp, #8]
_080AD88A:
	ldr r0, [sp, #4]
	ldrh r3, [r0]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	movs r1, #0x1f
	ands r6, r1
	lsrs r3, r3, #0x1a
	ands r3, r1
	mov r5, ip
	ldrh r1, [r5]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x15
	movs r5, #0x1f
	ands r4, r5
	lsrs r1, r1, #0x1a
	ands r1, r5
	mov r5, sl
	muls r5, r2, r5
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	adds r5, r5, r0
	asrs r5, r5, #6
	mov r2, sl
	muls r2, r6, r2
	mov r0, sb
	muls r0, r4, r0
	adds r2, r2, r0
	asrs r2, r2, #6
	mov r0, sl
	muls r0, r3, r0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	strh r0, [r7]
	ldr r5, [sp, #4]
	adds r5, #2
	str r5, [sp, #4]
	movs r0, #2
	add ip, r0
	adds r7, #2
	ldr r1, [sp, #8]
	subs r1, #1
	str r1, [sp, #8]
	cmp r1, #0
	bge _080AD88A
	movs r1, #0xa3
	lsls r1, r1, #2
	add r1, r8
	movs r0, #0xa7
	lsls r0, r0, #2
	add r0, r8
	str r0, [r1]
	b _080AD952
	.align 2, 0
_080AD90C: .4byte 0x0000022D
_080AD910: .4byte 0x03003584
_080AD914:
	movs r4, #0x95
	lsls r4, r4, #2
	add r4, r8
	adds r0, r4, #0
	bl FUN_080ad4e4
	cmp r0, #0
	beq _080AD952
	adds r0, r4, #0
	bl FUN_080ad504
	ldr r2, _080AD964 @ =0x000002BE
	add r2, r8
	ldrh r3, [r2]
	cmp r0, r3
	beq _080AD952
	strh r0, [r2]
	movs r0, #0xa0
	lsls r0, r0, #2
	add r0, r8
	ldr r1, _080AD968 @ =0x0000022D
	add r1, r8
	ldrb r1, [r1]
	lsls r1, r1, #2
	ldrh r2, [r2]
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r2, r2, r5
	adds r1, r1, r2
	bl FUN_0822b20c
_080AD952:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD964: .4byte 0x000002BE
_080AD968: .4byte 0x0000022D

	thumb_func_start FUN_080ad96c
FUN_080ad96c: @ 0x080AD96C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080AD982
	adds r0, r5, #0
	bl _call_via_r1
_080AD982:
	adds r0, r5, #0
	bl FUN_080ad6a8
	ldr r2, _080AD9C8 @ =0x00001428
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080AD9C0
	movs r4, #0
_080AD994:
	lsls r1, r4, #1
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r0, #0x20
	adds r0, r5, r0
	lsls r1, r4, #5
	ldr r2, _080AD9CC @ =0x03004250
	adds r1, r1, r2
	ldr r2, _080AD9D0 @ =0x04000008
	bl CpuSet
	adds r4, #1
	cmp r4, #2
	ble _080AD994
	ldr r0, _080AD9C8 @ =0x00001428
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
_080AD9C0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AD9C8: .4byte 0x00001428
_080AD9CC: .4byte 0x03004250
_080AD9D0: .4byte 0x04000008

	thumb_func_start FUN_080ad9d4
FUN_080ad9d4: @ 0x080AD9D4
	push {r4, lr}
	lsls r1, r1, #1
	movs r4, #0x8c
	lsls r4, r4, #2
	adds r3, r0, r4
	adds r3, r3, r1
	strh r2, [r3]
	ldr r1, _080AD9F0 @ =0x00001428
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD9F0: .4byte 0x00001428

	thumb_func_start FUN_080ad9f4
FUN_080ad9f4: @ 0x080AD9F4
	movs r3, #0x94
	lsls r3, r3, #2
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080ADA08 @ =0x0000022E
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080ADA08: .4byte 0x0000022E

	thumb_func_start FUN_080ada0c
FUN_080ada0c: @ 0x080ADA0C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #2
	movs r2, #2
	bl FUN_080ad9d4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ad9f4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ada28
FUN_080ada28: @ 0x080ADA28
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #2
	movs r2, #5
	bl FUN_080ad9d4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ad9f4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ada44
FUN_080ada44: @ 0x080ADA44
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #2
	movs r2, #3
	bl FUN_080ad9d4
	ldr r1, _080ADA60 @ =FUN_080ada64
	adds r0, r4, #0
	bl FUN_080ad9f4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADA60: .4byte FUN_080ada64

	thumb_func_start FUN_080ada64
FUN_080ada64: @ 0x080ADA64
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADA94 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080ADA8C
	adds r0, r4, #0
	movs r1, #2
	movs r2, #4
	bl FUN_080ad9d4
	ldr r1, _080ADA98 @ =FUN_080ada9c
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADA8C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADA94: .4byte 0x0000022E
_080ADA98: .4byte FUN_080ada9c

	thumb_func_start FUN_080ada9c
FUN_080ada9c: @ 0x080ADA9C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADACC @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080ADAC4
	adds r0, r4, #0
	movs r1, #2
	movs r2, #5
	bl FUN_080ad9d4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ad9f4
_080ADAC4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADACC: .4byte 0x0000022E

	thumb_func_start FUN_080adad0
FUN_080adad0: @ 0x080ADAD0
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #2
	movs r2, #4
	bl FUN_080ad9d4
	ldr r1, _080ADAEC @ =FUN_080adaf0
	adds r0, r4, #0
	bl FUN_080ad9f4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADAEC: .4byte FUN_080adaf0

	thumb_func_start FUN_080adaf0
FUN_080adaf0: @ 0x080ADAF0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADB20 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080ADB18
	adds r0, r4, #0
	movs r1, #2
	movs r2, #3
	bl FUN_080ad9d4
	ldr r1, _080ADB24 @ =FUN_080adb28
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADB18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADB20: .4byte 0x0000022E
_080ADB24: .4byte FUN_080adb28

	thumb_func_start FUN_080adb28
FUN_080adb28: @ 0x080ADB28
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADB58 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080ADB50
	adds r0, r4, #0
	movs r1, #2
	movs r2, #2
	bl FUN_080ad9d4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ad9f4
_080ADB50:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADB58: .4byte 0x0000022E

	thumb_func_start FUN_080adb5c
FUN_080adb5c: @ 0x080ADB5C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #2
	movs r2, #6
	bl FUN_080ad9d4
	ldr r1, _080ADB88 @ =FUN_080adb90
	adds r0, r4, #0
	bl FUN_080ad9f4
	movs r1, #0xa1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r1, #0
	str r1, [r0]
	ldr r0, _080ADB8C @ =0x0000022E
	adds r4, r4, r0
	strh r1, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADB88: .4byte FUN_080adb90
_080ADB8C: .4byte 0x0000022E

	thumb_func_start FUN_080adb90
FUN_080adb90: @ 0x080ADB90
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADBC0 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080ADBB8
	adds r0, r4, #0
	movs r1, #2
	movs r2, #7
	bl FUN_080ad9d4
	ldr r1, _080ADBC4 @ =FUN_080adbc8
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADBB8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADBC0: .4byte 0x0000022E
_080ADBC4: .4byte FUN_080adbc8

	thumb_func_start FUN_080adbc8
FUN_080adbc8: @ 0x080ADBC8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADBF8 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080ADBF0
	adds r0, r4, #0
	movs r1, #2
	movs r2, #8
	bl FUN_080ad9d4
	ldr r1, _080ADBFC @ =FUN_080adc00
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADBF0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADBF8: .4byte 0x0000022E
_080ADBFC: .4byte FUN_080adc00

	thumb_func_start FUN_080adc00
FUN_080adc00: @ 0x080ADC00
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADC30 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080ADC28
	adds r0, r4, #0
	movs r1, #2
	movs r2, #9
	bl FUN_080ad9d4
	ldr r1, _080ADC34 @ =FUN_080adc38
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADC28:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADC30: .4byte 0x0000022E
_080ADC34: .4byte FUN_080adc38

	thumb_func_start FUN_080adc38
FUN_080adc38: @ 0x080ADC38
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADC68 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080ADC60
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0xa
	bl FUN_080ad9d4
	ldr r1, _080ADC6C @ =FUN_080adc70
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADC60:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADC68: .4byte 0x0000022E
_080ADC6C: .4byte FUN_080adc70

	thumb_func_start FUN_080adc70
FUN_080adc70: @ 0x080ADC70
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADCA0 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080ADC98
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0xb
	bl FUN_080ad9d4
	ldr r1, _080ADCA4 @ =FUN_080adca8
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADC98:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADCA0: .4byte 0x0000022E
_080ADCA4: .4byte FUN_080adca8

	thumb_func_start FUN_080adca8
FUN_080adca8: @ 0x080ADCA8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADCE0 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080ADCDA
	adds r0, r4, #0
	movs r1, #2
	movs r2, #2
	bl FUN_080ad9d4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ad9f4
	movs r0, #0xa1
	lsls r0, r0, #5
	adds r1, r4, r0
	movs r0, #1
	str r0, [r1]
_080ADCDA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADCE0: .4byte 0x0000022E

	thumb_func_start FUN_080adce4
FUN_080adce4: @ 0x080ADCE4
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #2
	movs r2, #0xc
	bl FUN_080ad9d4
	ldr r1, _080ADD00 @ =FUN_080add3c
	adds r0, r4, #0
	bl FUN_080ad9f4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADD00: .4byte FUN_080add3c

	thumb_func_start FUN_080add04
FUN_080add04: @ 0x080ADD04
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADD34 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x25
	bls _080ADD2C
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0xc
	bl FUN_080ad9d4
	ldr r1, _080ADD38 @ =FUN_080add3c
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADD2C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADD34: .4byte 0x0000022E
_080ADD38: .4byte FUN_080add3c

	thumb_func_start FUN_080add3c
FUN_080add3c: @ 0x080ADD3C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADD6C @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080ADD64
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0xd
	bl FUN_080ad9d4
	ldr r1, _080ADD70 @ =FUN_080add74
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADD64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADD6C: .4byte 0x0000022E
_080ADD70: .4byte FUN_080add74

	thumb_func_start FUN_080add74
FUN_080add74: @ 0x080ADD74
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADDA4 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x25
	bls _080ADD9C
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0xc
	bl FUN_080ad9d4
	ldr r1, _080ADDA8 @ =FUN_080addac
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADD9C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADDA4: .4byte 0x0000022E
_080ADDA8: .4byte FUN_080addac

	thumb_func_start FUN_080addac
FUN_080addac: @ 0x080ADDAC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADDDC @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080ADDD4
	adds r0, r4, #0
	movs r1, #2
	movs r2, #2
	bl FUN_080ad9d4
	ldr r1, _080ADDE0 @ =FUN_080add04
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADDD4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADDDC: .4byte 0x0000022E
_080ADDE0: .4byte FUN_080add04

	thumb_func_start FUN_080adde4
FUN_080adde4: @ 0x080ADDE4
	push {lr}
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xa
	bhi _080ADE44
	lsls r0, r0, #2
	ldr r1, _080ADDFC @ =_080ADE00
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080ADDFC: .4byte _080ADE00
_080ADE00: @ jump table
	.4byte _080ADE2C @ case 0
	.4byte _080ADE30 @ case 1
	.4byte _080ADE30 @ case 2
	.4byte _080ADE34 @ case 3
	.4byte _080ADE38 @ case 4
	.4byte _080ADE44 @ case 5
	.4byte _080ADE44 @ case 6
	.4byte _080ADE3C @ case 7
	.4byte _080ADE3C @ case 8
	.4byte _080ADE40 @ case 9
	.4byte _080ADE40 @ case 10
_080ADE2C:
	movs r0, #8
	b _080ADE46
_080ADE30:
	movs r0, #6
	b _080ADE46
_080ADE34:
	movs r0, #4
	b _080ADE46
_080ADE38:
	movs r0, #2
	b _080ADE46
_080ADE3C:
	movs r0, #0xa
	b _080ADE46
_080ADE40:
	movs r0, #0xc
	b _080ADE46
_080ADE44:
	movs r0, #0
_080ADE46:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080ade4c
FUN_080ade4c: @ 0x080ADE4C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080ADE78 @ =0x000092B3
	ldr r1, _080ADE7C @ =0x0000313A
	bl GetFile
	adds r4, r0, #0
	adds r4, #0x14
	adds r0, r5, #0
	bl FUN_080adde4
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r1, _080ADE80 @ =0x03004250
	ldr r2, _080ADE84 @ =0x04000010
	adds r0, r4, #0
	bl CpuSet
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ADE78: .4byte 0x000092B3
_080ADE7C: .4byte 0x0000313A
_080ADE80: .4byte 0x03004250
_080ADE84: .4byte 0x04000010

	thumb_func_start FUN_080ade88
FUN_080ade88: @ 0x080ADE88
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _080ADF1C @ =0x0000C091
	ldr r2, _080ADF20 @ =0x085AD048
	ldr r3, _080ADF24 @ =0x00001336
	adds r1, r6, r3
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	bl GetFile
	adds r2, r0, #0
	ldr r0, _080ADF28 @ =0x000004D4
	adds r5, r6, r0
	str r2, [r5]
	movs r4, #0
	str r4, [sp, #0xc]
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r1, sp, #0xc
	str r1, [sp, #8]
	movs r0, #3
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	ldr r1, [r5]
	movs r0, #1
	movs r2, #0
	bl FUN_0822c398
	ldr r2, _080ADF2C @ =0x03003E78
	ldr r0, _080ADF30 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	movs r1, #0
	bl SetBGPrioDirect
	ldr r1, _080ADF34 @ =0x04000050
	ldr r2, _080ADF38 @ =0x00003C42
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r3, #0x81
	lsls r3, r3, #4
	adds r0, r3, #0
	strh r0, [r1]
	ldr r0, _080ADF3C @ =0x04000054
	strh r4, [r0]
	ldr r0, _080ADF40 @ =0x000092B3
	ldr r1, _080ADF44 @ =0x0000F308
	bl GetFile
	movs r1, #0x9b
	lsls r1, r1, #3
	adds r6, r6, r1
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r6]
	ldr r1, _080ADF48 @ =0x030043D0
	ldr r2, _080ADF4C @ =0x04000008
	bl CpuSet
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ADF1C: .4byte 0x0000C091
_080ADF20: .4byte 0x085AD048
_080ADF24: .4byte 0x00001336
_080ADF28: .4byte 0x000004D4
_080ADF2C: .4byte 0x03003E78
_080ADF30: .4byte 0xFFFFFDFF
_080ADF34: .4byte 0x04000050
_080ADF38: .4byte 0x00003C42
_080ADF3C: .4byte 0x04000054
_080ADF40: .4byte 0x000092B3
_080ADF44: .4byte 0x0000F308
_080ADF48: .4byte 0x030043D0
_080ADF4C: .4byte 0x04000008

	thumb_func_start FUN_080adf50
FUN_080adf50: @ 0x080ADF50
	ldr r1, _080ADF5C @ =0x00001324
	adds r0, r0, r1
	movs r1, #0x30
	strh r1, [r0]
	bx lr
	.align 2, 0
_080ADF5C: .4byte 0x00001324

	thumb_func_start FUN_080adf60
FUN_080adf60: @ 0x080ADF60
	push {lr}
	ldr r0, _080ADF8C @ =0x03002C58
	ldr r3, [r0]
	cmp r3, #0
	beq _080ADF88
	ldr r0, _080ADF90 @ =0x00001324
	adds r1, r3, r0
	movs r2, #0
	movs r0, #0x40
	strh r0, [r1]
	ldr r1, _080ADF94 @ =0x00001326
	adds r0, r3, r1
	strh r2, [r0]
	ldr r0, _080ADF98 @ =0x00001374
	adds r1, r3, r0
	movs r0, #1
	strh r0, [r1]
	ldr r0, _080ADF9C @ =0x00000129
	bl PlaySound_082406e0
_080ADF88:
	pop {r0}
	bx r0
	.align 2, 0
_080ADF8C: .4byte 0x03002C58
_080ADF90: .4byte 0x00001324
_080ADF94: .4byte 0x00001326
_080ADF98: .4byte 0x00001374
_080ADF9C: .4byte 0x00000129

	thumb_func_start FUN_080adfa0
FUN_080adfa0: @ 0x080ADFA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	adds r7, r0, #0
	str r1, [sp, #0x30]
	str r2, [sp, #0x34]
	str r3, [sp, #0x38]
	ldr r0, _080AE00C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	ble _080AE094
	ldr r2, _080AE010 @ =0x00001324
	adds r0, r7, r2
	ldrh r5, [r0]
	lsls r4, r5, #0x10
	lsrs r3, r4, #0x10
	cmp r3, #0
	bne _080ADFD4
	b _080AE370
_080ADFD4:
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080AE014 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	cmp r3, #0x1f
	bls _080AE034
	movs r4, #0x10
	cmp r3, #0x23
	bls _080AE028
	ldr r2, _080AE018 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AE01C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080AE020 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #7
	ands r0, r1
	ldr r2, _080AE024 @ =0x00001326
	adds r1, r7, r2
	b _080AE04E
	.align 2, 0
_080AE00C: .4byte 0x030046A0
_080AE010: .4byte 0x00001324
_080AE014: .4byte 0x03003E78
_080AE018: .4byte 0x030046B8
_080AE01C: .4byte 0x000003FF
_080AE020: .4byte 0x0203B400
_080AE024: .4byte 0x00001326
_080AE028:
	ldr r3, _080AE030 @ =0x00001326
	adds r1, r7, r3
	movs r0, #5
	b _080AE04E
	.align 2, 0
_080AE030: .4byte 0x00001326
_080AE034:
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r0, r5
	cmp r0, #0
	bne _080AE050
	ldr r0, _080AE088 @ =0x00001326
	adds r1, r7, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _080AE050
	subs r0, r2, #1
_080AE04E:
	strh r0, [r1]
_080AE050:
	movs r0, #0x10
	subs r0, r0, r4
	asrs r0, r0, #1
	adds r0, #8
	ldr r1, _080AE08C @ =0x04000052
	lsls r0, r0, #8
	orrs r0, r4
	strh r0, [r1]
	ldr r1, _080AE088 @ =0x00001326
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, [sp, #0x60]
	adds r0, r3, r0
	str r0, [sp]
	movs r0, #1
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	ldr r3, [sp, #0x38]
	bl Video_GenerateBGMap
	ldr r0, _080AE090 @ =0x00001324
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _080AE37A
	.align 2, 0
_080AE088: .4byte 0x00001326
_080AE08C: .4byte 0x04000052
_080AE090: .4byte 0x00001324
_080AE094:
	movs r1, #0x9b
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, #0x20
	ldr r1, _080AE0E8 @ =0x030043D0
	ldr r2, _080AE0EC @ =0x04000008
	bl CpuSet
	ldr r2, _080AE0F0 @ =0x00001374
	adds r0, r7, r2
	ldrh r3, [r0]
	cmp r3, #0
	beq _080AE0B2
	b _080AE1E8
_080AE0B2:
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080AE0F4 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080AE0F8 @ =0x00001324
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _080AE0D2
	strh r3, [r1]
_080AE0D2:
	ldrh r0, [r1]
	lsls r2, r0, #0x10
	lsrs r0, r2, #0x10
	cmp r0, #0x20
	bls _080AE0FC
	ldrh r1, [r1]
	movs r0, #0x40
	subs r0, r0, r1
	asrs r0, r0, #3
	b _080AE0FE
	.align 2, 0
_080AE0E8: .4byte 0x030043D0
_080AE0EC: .4byte 0x04000008
_080AE0F0: .4byte 0x00001374
_080AE0F4: .4byte 0x03003E78
_080AE0F8: .4byte 0x00001324
_080AE0FC:
	lsrs r0, r2, #0x13
_080AE0FE:
	adds r2, r0, #0
	adds r2, #0xc
	movs r0, #0x10
	subs r0, r0, r2
	asrs r0, r0, #1
	adds r0, #8
	ldr r1, _080AE1C8 @ =0x04000052
	lsls r0, r0, #8
	orrs r0, r2
	strh r0, [r1]
	ldr r2, _080AE1CC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AE1D0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AE1D4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #7
	ands r0, r1
	ldr r2, _080AE1D8 @ =0x00001326
	adds r1, r7, r2
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	ldr r1, [sp, #0x60]
	adds r0, r1, r0
	str r0, [sp]
	movs r0, #1
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	ldr r3, [sp, #0x38]
	bl Video_GenerateBGMap
	ldr r2, _080AE1DC @ =0x00001324
	adds r0, r7, r2
	ldrh r0, [r0]
	movs r5, #3
	ands r5, r0
	cmp r5, #0
	beq _080AE158
	b _080AE37A
_080AE158:
	movs r3, #0xa2
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r0, sp, #0x10
	ldrh r1, [r0]
	adds r1, #0x40
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _080AE1E0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	ldrh r0, [r0, #4]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x14]
	ldr r0, [sp, #0x18]
	ands r0, r3
	movs r4, #0x96
	lsls r4, r4, #1
	orrs r0, r4
	ldr r1, _080AE1E4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x96
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	str r5, [sp]
	movs r0, #0x30
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #1
	movs r3, #0
	bl FUN_080ddcc8
	b _080AE37A
	.align 2, 0
_080AE1C8: .4byte 0x04000052
_080AE1CC: .4byte 0x030046B8
_080AE1D0: .4byte 0x000003FF
_080AE1D4: .4byte 0x0203B400
_080AE1D8: .4byte 0x00001326
_080AE1DC: .4byte 0x00001324
_080AE1E0: .4byte 0xFFFF0000
_080AE1E4: .4byte 0x0000FFFF
_080AE1E8:
	ldr r0, _080AE348 @ =0x00001324
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	ldrh r0, [r0]
	cmp r0, #0
	bne _080AE1F6
	b _080AE370
_080AE1F6:
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r2, _080AE34C @ =0x0203B400
	mov sl, r2
	ldr r4, _080AE350 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _080AE354 @ =0x000003FF
	mov r8, r3
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	movs r5, #0xfa
	lsls r5, r5, #1
	adds r1, r5, #0
	bl Mod
	add r1, sp, #0x20
	mov sb, r1
	ldrh r1, [r1]
	subs r1, #0xfa
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r6, _080AE358 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x20]
	ldr r0, [r4]
	adds r0, #1
	mov r2, r8
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	adds r1, r5, #0
	bl Mod
	ldr r2, [sp, #0x20]
	asrs r1, r2, #0x10
	subs r1, #0xfa
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _080AE35C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	ldr r0, [r4]
	adds r0, #1
	mov r3, r8
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	adds r1, r5, #0
	bl Mod
	mov r2, sb
	ldrh r1, [r2, #4]
	subs r1, #0xfa
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r2, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r2, #4]
	ldr r0, [sp, #0x28]
	ands r0, r6
	str r0, [sp, #0x28]
	ldr r1, [r4]
	adds r1, #1
	mov r3, r8
	ands r1, r3
	lsls r0, r1, #1
	add r0, sl
	ldrh r0, [r0]
	movs r2, #0x1f
	ands r0, r2
	adds r0, #0x10
	lsls r0, r0, #0x10
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r6
	str r0, [r2, #4]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sl
	ldrh r3, [r1]
	movs r4, #7
	ands r3, r4
	adds r3, #8
	movs r0, #1
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sb
	bl FUN_080ad2d0
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080AE360 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, [sp, #0x3c]
	ldrh r0, [r1]
	lsrs r2, r0, #2
	movs r0, #0x10
	subs r0, r0, r2
	asrs r0, r0, #1
	adds r0, #8
	ldr r1, _080AE364 @ =0x04000052
	lsls r0, r0, #8
	orrs r0, r2
	strh r0, [r1]
	ldr r2, [sp, #0x3c]
	ldrh r0, [r2]
	ands r4, r0
	cmp r4, #0
	bne _080AE312
	ldr r3, _080AE368 @ =0x00001326
	adds r1, r7, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #6
	bgt _080AE312
	adds r0, r2, #1
	strh r0, [r1]
_080AE312:
	ldr r1, _080AE368 @ =0x00001326
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, [sp, #0x60]
	adds r0, r3, r0
	str r0, [sp]
	movs r0, #1
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	ldr r3, [sp, #0x38]
	bl Video_GenerateBGMap
	ldr r0, _080AE348 @ =0x00001324
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AE37A
	ldr r0, _080AE36C @ =0x03002C58
	ldr r0, [r0]
	movs r1, #9
	bl FUN_080ad204
	b _080AE37A
	.align 2, 0
_080AE348: .4byte 0x00001324
_080AE34C: .4byte 0x0203B400
_080AE350: .4byte 0x030046B8
_080AE354: .4byte 0x000003FF
_080AE358: .4byte 0xFFFF0000
_080AE35C: .4byte 0x0000FFFF
_080AE360: .4byte 0x03003E78
_080AE364: .4byte 0x04000052
_080AE368: .4byte 0x00001326
_080AE36C: .4byte 0x03002C58
_080AE370:
	ldr r0, _080AE38C @ =0x03003E78
	ldr r1, _080AE390 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080AE37A:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AE38C: .4byte 0x03003E78
_080AE390: .4byte 0xFFFFFDFF

	thumb_func_start FUN_080ae394
FUN_080ae394: @ 0x080AE394
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r4, r0, #0
	ldr r0, _080AE40C @ =0x0000C091
	ldr r1, _080AE410 @ =0x0000AD57
	bl GetFile
	ldr r2, _080AE414 @ =0x000004DC
	adds r1, r4, r2
	str r0, [r1]
	mov r2, sp
	adds r1, r0, #0
	ldm r1!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r1!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldr r1, [sp, #0xc]
	adds r1, r1, r0
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x10]
	adds r1, r1, r0
	str r1, [sp, #0x10]
	ldr r1, [sp, #0x14]
	adds r1, r1, r0
	str r1, [sp, #0x14]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r2, _080AE418 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #3
	movs r1, #1
	bl SetBGPrioDirect
	ldr r0, _080AE41C @ =0x000092B3
	ldr r1, _080AE420 @ =0x0000E2BA
	bl GetFile
	movs r2, #0x9c
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r1]
	movs r1, #5
	ldr r5, _080AE424 @ =0x000004E4
	adds r4, r4, r5
	movs r0, #3
_080AE3F8:
	strb r1, [r4, #4]
	strb r1, [r4]
	adds r4, #1
	subs r0, #1
	cmp r0, #0
	bge _080AE3F8
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AE40C: .4byte 0x0000C091
_080AE410: .4byte 0x0000AD57
_080AE414: .4byte 0x000004DC
_080AE418: .4byte 0x03003E78
_080AE41C: .4byte 0x000092B3
_080AE420: .4byte 0x0000E2BA
_080AE424: .4byte 0x000004E4

	thumb_func_start FUN_080ae428
FUN_080ae428: @ 0x080AE428
	push {lr}
	adds r3, r0, #0
	ldr r0, _080AE468 @ =0x000004EC
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r2, r0, #1
	strh r2, [r1]
	ldr r0, _080AE46C @ =0x0000FFFF
	adds r1, r0, #0
	adds r0, r2, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080AE462
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x11
	movs r0, #3
	ands r1, r0
	movs r2, #0x9c
	lsls r2, r2, #3
	adds r0, r3, r2
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	ldr r1, _080AE470 @ =0x030043B0
	ldr r2, _080AE474 @ =0x04000008
	bl CpuSet
_080AE462:
	pop {r0}
	bx r0
	.align 2, 0
_080AE468: .4byte 0x000004EC
_080AE46C: .4byte 0x0000FFFF
_080AE470: .4byte 0x030043B0
_080AE474: .4byte 0x04000008

	thumb_func_start FUN_080ae478
FUN_080ae478: @ 0x080AE478
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x68
	str r0, [sp, #0x2c]
	str r1, [sp, #0x30]
	str r2, [sp, #0x34]
	adds r4, r3, #0
	ldr r5, [sp, #0x88]
	movs r0, #0
	str r0, [sp, #0x54]
	ldr r0, [sp, #0x2c]
	bl FUN_080ae428
	mov r1, sp
	ldrh r2, [r1, #0x30]
	ldr r1, _080AE4E8 @ =0x03003F60
	strh r2, [r1, #0x10]
	mov r3, sp
	ldrh r3, [r3, #0x34]
	strh r3, [r1, #0x12]
	strh r4, [r1, #0x20]
	strh r5, [r1, #0x22]
	ldr r4, [r1, #0x2c]
	mov sb, r4
	movs r5, #0x18
	ldrsh r0, [r1, r5]
	lsls r0, r0, #1
	str r0, [sp, #0x3c]
	movs r2, #0x1a
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	str r0, [sp, #0x40]
	add r4, sp, #0x24
	ldr r3, [sp, #0x2c]
	movs r5, #0xa0
	lsls r5, r5, #3
	adds r2, r3, r5
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r5, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r5, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r6, r4, #0
	cmp r0, #0
	blt _080AE4EC
	asrs r0, r0, #8
	b _080AE4F2
	.align 2, 0
_080AE4E8: .4byte 0x03003F60
_080AE4EC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080AE4F2:
	strh r0, [r4]
	adds r1, r5, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080AE504
	asrs r0, r0, #8
	b _080AE50A
_080AE504:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080AE50A:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080AE51E
	asrs r1, r0, #8
	b _080AE524
_080AE51E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_080AE524:
	subs r0, r3, r1
	strh r0, [r4, #2]
	adds r0, r3, r1
	strh r0, [r4, #4]
	movs r2, #0
	ldrsh r1, [r6, r2]
	ldr r2, _080AE554 @ =0x03003540
	movs r3, #8
	ldrsh r0, [r2, r3]
	adds r1, r1, r0
	str r1, [sp, #0x4c]
	add r0, sp, #0x24
	movs r4, #2
	ldrsh r1, [r0, r4]
	movs r5, #0xa
	ldrsh r0, [r2, r5]
	adds r1, r1, r0
	str r1, [sp, #0x50]
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	blt _080AE558
	asrs r0, r0, #3
	b _080AE560
	.align 2, 0
_080AE554: .4byte 0x03003540
_080AE558:
	ldr r1, [sp, #0x4c]
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080AE560:
	str r0, [sp, #0x4c]
	ldr r2, [sp, #0x50]
	cmp r2, #0
	blt _080AE56C
	asrs r0, r2, #3
	b _080AE574
_080AE56C:
	ldr r3, [sp, #0x50]
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080AE574:
	movs r4, #2
	rsbs r4, r4, #0
	ands r4, r0
	ldr r5, [sp, #0x4c]
	ldr r0, [sp, #0x30]
	subs r5, r5, r0
	str r5, [sp, #0x4c]
	ldr r1, [sp, #0x34]
	subs r4, r4, r1
	str r4, [sp, #0x50]
	ldr r2, [sp, #0x2c]
	ldr r3, _080AE5E0 @ =0x000004DC
	adds r0, r2, r3
	ldr r2, [r0]
	mov r1, sp
	adds r0, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r0, [sp, #0xc]
	adds r0, r0, r2
	str r0, [sp, #0xc]
	str r0, [sp, #0x38]
	ldr r4, [sp, #0x2c]
	ldr r5, _080AE5E4 @ =0x0000132A
	adds r1, r4, r5
	movs r0, #0
	strb r0, [r1]
	movs r3, #0
	ldrb r0, [r4, #0x1e]
	cmp r3, r0
	blt _080AE5B8
	b _080AE882
_080AE5B8:
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x58]
_080AE5BE:
	ldr r2, [sp, #0x2c]
	movs r4, #0xc1
	lsls r4, r4, #4
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AE5DA
	ldr r5, _080AE5E8 @ =0x000004FC
	adds r0, r2, r5
	ldrh r0, [r0]
	cmp r0, #0xa
	beq _080AE5EC
	cmp r0, #0xe
	beq _080AE5EC
_080AE5DA:
	movs r1, #5
	b _080AE604
	.align 2, 0
_080AE5E0: .4byte 0x000004DC
_080AE5E4: .4byte 0x0000132A
_080AE5E8: .4byte 0x000004FC
_080AE5EC:
	lsls r1, r3, #2
	ldr r2, [sp, #0x2c]
	ldr r4, _080AE63C @ =0x00000BE8
	adds r0, r2, r4
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, #0xcf
	ldrb r0, [r0]
	movs r1, #5
	cmp r0, #4
	bne _080AE604
	movs r1, #0
_080AE604:
	ldr r5, [sp, #0x2c]
	ldr r2, _080AE640 @ =0x000004E4
	adds r0, r5, r2
	adds r0, r0, r3
	strb r1, [r0]
	movs r4, #0x9d
	lsls r4, r4, #3
	adds r0, r5, r4
	adds r2, r0, r3
	ldrb r0, [r2]
	adds r5, r3, #1
	str r5, [sp, #0x60]
	cmp r0, r1
	bne _080AE622
	b _080AE876
_080AE622:
	cmp r1, #0
	bne _080AE62A
	movs r0, #1
	str r0, [sp, #0x54]
_080AE62A:
	strb r1, [r2]
	cmp r3, #1
	beq _080AE68E
	cmp r3, #1
	bgt _080AE644
	cmp r3, #0
	beq _080AE64E
	b _080AE6AC
	.align 2, 0
_080AE63C: .4byte 0x00000BE8
_080AE640: .4byte 0x000004E4
_080AE644:
	cmp r3, #2
	beq _080AE666
	cmp r3, #3
	beq _080AE67E
	b _080AE6AC
_080AE64E:
	ldr r2, [sp, #0x4c]
	mov ip, r2
	ldr r4, [sp, #0x50]
	mov r8, r4
	mov r7, ip
	subs r7, #7
	cmp r7, #0
	bge _080AE660
	movs r7, #0
_080AE660:
	mov r2, r8
	subs r2, #6
	b _080AE6A4
_080AE666:
	ldr r5, [sp, #0x4c]
	adds r5, #7
	mov ip, r5
	ldr r0, [sp, #0x50]
	mov r8, r0
	ldr r7, [sp, #0x4c]
	cmp r7, #0
	bge _080AE678
	movs r7, #0
_080AE678:
	mov r2, r8
	subs r2, #6
	b _080AE6A4
_080AE67E:
	ldr r2, [sp, #0x4c]
	mov ip, r2
	ldr r4, [sp, #0x50]
	adds r4, #4
	mov r8, r4
	mov r7, ip
	subs r7, #7
	b _080AE69C
_080AE68E:
	ldr r5, [sp, #0x4c]
	adds r5, #7
	mov ip, r5
	ldr r0, [sp, #0x50]
	adds r0, #4
	mov r8, r0
	ldr r7, [sp, #0x4c]
_080AE69C:
	cmp r7, #0
	bge _080AE6A2
	movs r7, #0
_080AE6A2:
	ldr r2, [sp, #0x50]
_080AE6A4:
	cmp r2, #0
	bge _080AE6B6
	movs r2, #0
	b _080AE6B6
_080AE6AC:
	movs r7, #1
	rsbs r7, r7, #0
	adds r2, r7, #0
	mov r8, r7
	mov ip, r8
_080AE6B6:
	adds r3, #1
	str r3, [sp, #0x60]
	mov r3, ip
	cmp r3, #0
	bge _080AE6C2
	b _080AE876
_080AE6C2:
	mov r4, r8
	cmp r4, #0
	bge _080AE6CA
	b _080AE876
_080AE6CA:
	cmp r7, #0x1f
	ble _080AE6D0
	b _080AE876
_080AE6D0:
	cmp r2, #0x1f
	ble _080AE6D6
	b _080AE876
_080AE6D6:
	ldr r5, _080AE72C @ =0x03003F60
	ldrh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	str r0, [sp, #0x48]
	cmp r1, #5
	bne _080AE730
	adds r6, r2, #0
	cmp r6, r8
	blt _080AE6EC
	b _080AE876
_080AE6EC:
	adds r5, r7, #0
	adds r0, r6, #2
	str r0, [sp, #0x5c]
	cmp r5, ip
	bge _080AE722
	movs r4, #0x1f
	movs r3, #0
_080AE6FA:
	ldr r1, [sp, #0x30]
	adds r2, r1, r5
	ldr r0, [sp, #0x34]
	adds r1, r0, r6
	ands r2, r4
	ands r1, r4
	lsls r0, r1, #5
	adds r0, r2, r0
	lsls r0, r0, #1
	add r0, sb
	strh r3, [r0]
	adds r1, #1
	lsls r1, r1, #5
	adds r2, r2, r1
	lsls r2, r2, #1
	add r2, sb
	strh r3, [r2]
	adds r5, #1
	cmp r5, ip
	blt _080AE6FA
_080AE722:
	ldr r6, [sp, #0x5c]
	cmp r6, r8
	blt _080AE6EC
	b _080AE876
	.align 2, 0
_080AE72C: .4byte 0x03003F60
_080AE730:
	adds r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [sp, #0x58]
	ldr r3, [sp, #0x38]
	adds r0, r0, r3
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r4, [sp, #0x2c]
	ldr r5, _080AE7AC @ =0x000004DC
	adds r0, r4, r5
	ldr r3, [sp, #0x58]
	ldr r1, [r3, #8]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r3, #8]
	ldr r4, _080AE7B0 @ =0x03003F60
	str r1, [r4, #0x28]
	str r1, [sp, #0x44]
	adds r6, r2, #0
	cmp r6, r8
	blt _080AE760
	b _080AE876
_080AE760:
	adds r5, r7, #0
	adds r0, r6, #2
	str r0, [sp, #0x5c]
	cmp r5, ip
	blt _080AE76C
	b _080AE86E
_080AE76C:
	movs r1, #0x1f
	mov sl, r1
_080AE770:
	ldr r2, [sp, #0x30]
	adds r4, r2, r5
	ldr r0, [sp, #0x34]
	adds r3, r0, r6
	cmp r4, #0
	blt _080AE78C
	cmp r3, #0
	blt _080AE78C
	ldr r1, [sp, #0x3c]
	cmp r4, r1
	bge _080AE78C
	ldr r2, [sp, #0x40]
	cmp r3, r2
	blt _080AE7B4
_080AE78C:
	mov r0, sl
	ands r4, r0
	ands r3, r0
	lsls r0, r3, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	strh r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	add r0, sb
	b _080AE864
	.align 2, 0
_080AE7AC: .4byte 0x000004DC
_080AE7B0: .4byte 0x03003F60
_080AE7B4:
	cmp r4, #0
	blt _080AE7BC
	asrs r0, r4, #5
	b _080AE7C2
_080AE7BC:
	rsbs r0, r4, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_080AE7C2:
	adds r1, r0, #0
	cmp r3, #0
	blt _080AE7CC
	asrs r0, r3, #5
	b _080AE7D2
_080AE7CC:
	rsbs r0, r3, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_080AE7D2:
	ldr r2, [sp, #0x48]
	muls r0, r2, r0
	adds r0, r1, r0
	lsls r2, r0, #8
	mov r0, sl
	ands r4, r0
	ands r3, r0
	cmp r4, #0
	blt _080AE7E8
	asrs r0, r4, #1
	b _080AE7EE
_080AE7E8:
	rsbs r0, r4, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080AE7EE:
	adds r1, r0, #0
	cmp r3, #0
	blt _080AE7F8
	asrs r0, r3, #1
	b _080AE7FE
_080AE7F8:
	rsbs r0, r3, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080AE7FE:
	lsls r0, r0, #4
	adds r1, r2, r1
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r2, [sp, #0x44]
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne _080AE840
	lsls r1, r3, #5
	adds r1, r4, r1
	lsls r1, r1, #1
	add r1, sb
	str r1, [sp, #0x64]
	ldr r1, _080AE83C @ =0x03003F60
	ldr r0, [r1, #0x24]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldrh r0, [r2]
	ldr r1, [sp, #0x64]
	strh r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r2, #4]
	b _080AE864
	.align 2, 0
_080AE83C: .4byte 0x03003F60
_080AE840:
	lsls r1, r3, #5
	adds r1, r4, r1
	lsls r1, r1, #1
	add r1, sb
	str r1, [sp, #0x64]
	ldr r1, _080AE8A0 @ =0x03003F60
	ldr r0, [r1, #0x24]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldrh r0, [r2, #2]
	ldr r1, [sp, #0x64]
	strh r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r2, #6]
_080AE864:
	strh r1, [r0]
	adds r5, #1
	cmp r5, ip
	bge _080AE86E
	b _080AE770
_080AE86E:
	ldr r6, [sp, #0x5c]
	cmp r6, r8
	bge _080AE876
	b _080AE760
_080AE876:
	ldr r3, [sp, #0x60]
	ldr r2, [sp, #0x2c]
	ldrb r2, [r2, #0x1e]
	cmp r3, r2
	bge _080AE882
	b _080AE5BE
_080AE882:
	ldr r3, [sp, #0x54]
	cmp r3, #0
	beq _080AE88E
	movs r0, #0xf5
	bl PlaySound_082406e0
_080AE88E:
	add sp, #0x68
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AE8A0: .4byte 0x03003F60

	thumb_func_start FUN_080ae8a4
FUN_080ae8a4: @ 0x080AE8A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r0
	ldr r3, _080AE8D4 @ =0x030047C8
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r2, _080AE8D8 @ =0x03003540
	movs r4, #8
	ldrsh r0, [r2, r4]
	adds r6, r1, r0
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r3, #0xa
	ldrsh r0, [r2, r3]
	adds r5, r1, r0
	adds r0, r6, #0
	subs r0, #0x80
	cmp r0, #0
	blt _080AE8DC
	asrs r1, r0, #3
	b _080AE8E2
	.align 2, 0
_080AE8D4: .4byte 0x030047C8
_080AE8D8: .4byte 0x03003540
_080AE8DC:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080AE8E2:
	adds r7, r1, #0
	adds r0, r5, #0
	subs r0, #0x80
	cmp r0, #0
	blt _080AE8F0
	asrs r0, r0, #3
	b _080AE8F6
_080AE8F0:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080AE8F6:
	movs r4, #2
	rsbs r4, r4, #0
	ands r4, r0
	subs r6, #0x78
	subs r5, #0x5a
	str r5, [sp]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080adfa0
	str r5, [sp]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080ae478
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080ae928
FUN_080ae928: @ 0x080AE928
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldr r0, _080AE984 @ =0x00001348
	adds r3, r5, r0
	ldr r2, _080AE988 @ =0x0000134A
	adds r1, r5, r2
	ldrh r0, [r3]
	ldrh r2, [r1]
	cmp r0, r2
	bhs _080AE99C
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	bhs _080AE94E
	b _080AEAD0
_080AE94E:
	ldr r0, _080AE98C @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x2c
	ldrsh r0, [r2, r3]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r1, r5, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	ldr r3, _080AE990 @ =0x00000504
	adds r2, r5, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldr r2, _080AE994 @ =0x00001352
	adds r1, r5, r2
	strh r0, [r1]
	ldr r3, _080AE998 @ =0x0000134C
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
	b _080AEAD0
	.align 2, 0
_080AE984: .4byte 0x00001348
_080AE988: .4byte 0x0000134A
_080AE98C: .4byte 0x03002BE0
_080AE990: .4byte 0x00000504
_080AE994: .4byte 0x00001352
_080AE998: .4byte 0x0000134C
_080AE99C:
	ldr r0, _080AE9F4 @ =0x0000134C
	adds r2, r5, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2f
	bls _080AE9B0
	b _080AEACC
_080AE9B0:
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	beq _080AE9BA
	b _080AEAD0
_080AE9BA:
	ldrh r0, [r2]
	lsls r6, r0, #4
	ldr r2, _080AE9F8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AE9FC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AEA00 @ =0x0203B400
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r3, _080AEA04 @ =0x085B0A08
	ldr r1, _080AEA08 @ =0x00001352
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r2, #0
	cmp r0, #0
	blt _080AEA0C
	asrs r2, r0, #0xc
	b _080AEA12
	.align 2, 0
_080AE9F4: .4byte 0x0000134C
_080AE9F8: .4byte 0x030046B8
_080AE9FC: .4byte 0x000003FF
_080AEA00: .4byte 0x0203B400
_080AEA04: .4byte 0x085B0A08
_080AEA08: .4byte 0x00001352
_080AEA0C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080AEA12:
	movs r0, #0xa0
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #0x7f
	ands r4, r0
	ldrh r1, [r1]
	adds r0, r4, r1
	adds r1, r2, #0
	subs r1, #0x40
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r2, _080AEA60 @ =0x00000502
	adds r1, r5, r2
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080AEA64 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080AEA68 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _080AEA6C @ =0x00001352
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _080AEA70
	asrs r3, r0, #0xc
	b _080AEA76
	.align 2, 0
_080AEA60: .4byte 0x00000502
_080AEA64: .4byte 0x000003FF
_080AEA68: .4byte 0x0203B400
_080AEA6C: .4byte 0x00001352
_080AEA70:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080AEA76:
	ldr r0, _080AEAC0 @ =0x00000504
	adds r1, r5, r0
	movs r0, #0x7f
	ands r2, r0
	ldrh r1, [r1]
	adds r1, r2, r1
	adds r0, r3, #0
	subs r0, #0x40
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080AEAC4 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	movs r2, #0x80
	lsls r2, r2, #1
	movs r0, #2
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	ldr r1, _080AEAC8 @ =0x0000134E
	adds r0, r5, r1
	ldrh r0, [r0]
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	add r3, sp, #0x14
	str r3, [sp, #0x10]
	movs r0, #1
	movs r1, #0
	movs r3, #2
	bl FUN_08056774
	b _080AEAD0
	.align 2, 0
_080AEAC0: .4byte 0x00000504
_080AEAC4: .4byte 0xFFFF0000
_080AEAC8: .4byte 0x0000134E
_080AEACC:
	movs r0, #0
	strh r0, [r3]
_080AEAD0:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aead8
FUN_080aead8: @ 0x080AEAD8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _080AEB08 @ =0x00001348
	adds r3, r5, r0
	ldr r2, _080AEB0C @ =0x0000134A
	adds r1, r5, r2
	ldrh r0, [r3]
	ldrh r2, [r1]
	cmp r0, r2
	bhs _080AEB14
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080AEB90
	ldr r3, _080AEB10 @ =0x0000134C
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
	b _080AEB90
	.align 2, 0
_080AEB08: .4byte 0x00001348
_080AEB0C: .4byte 0x0000134A
_080AEB10: .4byte 0x0000134C
_080AEB14:
	ldr r0, _080AEB78 @ =0x0000134C
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r2, r0, #1
	strh r2, [r1]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bhi _080AEB8C
	movs r0, #0x1f
	ands r2, r0
	cmp r2, #0
	bne _080AEB90
	ldr r0, _080AEB7C @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _080AEB80 @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r2, _080AEB84 @ =0x0203B400
	adds r1, r1, r2
	ldrb r4, [r1]
	movs r6, #7
_080AEB44:
	movs r3, #0x9b
	lsls r3, r3, #5
	adds r0, r5, r3
	ldr r0, [r0]
	ldr r2, _080AEB88 @ =0x0000134E
	adds r1, r5, r2
	ldrh r1, [r1]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r2, r5, r3
	str r2, [sp]
	adds r2, r4, #0
	movs r3, #0x18
	bl FUN_0805d80c
	adds r4, #0x20
	movs r0, #0xff
	ands r4, r0
	subs r6, #1
	cmp r6, #0
	bge _080AEB44
	adds r0, #0x7b
	bl PlaySound_082406e0
	b _080AEB90
	.align 2, 0
_080AEB78: .4byte 0x0000134C
_080AEB7C: .4byte 0x030046B8
_080AEB80: .4byte 0x000003FF
_080AEB84: .4byte 0x0203B400
_080AEB88: .4byte 0x0000134E
_080AEB8C:
	movs r0, #0
	strh r0, [r3]
_080AEB90:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aeb98
FUN_080aeb98: @ 0x080AEB98
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	ldr r0, _080AEBF8 @ =0x00001348
	adds r1, r4, r0
	ldr r3, _080AEBFC @ =0x0000134A
	adds r2, r4, r3
	ldrh r0, [r1]
	ldrh r5, [r2]
	cmp r0, r5
	bhs _080AEC10
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r2]
	cmp r0, r2
	bhs _080AEBC4
	b _080AEE04
_080AEBC4:
	ldr r0, _080AEC00 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r1, r4, r3
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	ldr r5, _080AEC04 @ =0x00000504
	adds r2, r4, r5
	movs r3, #0
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldr r5, _080AEC08 @ =0x00001352
	adds r1, r4, r5
	strh r0, [r1]
	ldr r0, _080AEC0C @ =0x0000134C
	adds r1, r4, r0
	b _080AEE00
	.align 2, 0
_080AEBF8: .4byte 0x00001348
_080AEBFC: .4byte 0x0000134A
_080AEC00: .4byte 0x03002BE0
_080AEC04: .4byte 0x00000504
_080AEC08: .4byte 0x00001352
_080AEC0C: .4byte 0x0000134C
_080AEC10:
	ldr r0, _080AEC50 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r1, r4, r3
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	ldr r5, _080AEC54 @ =0x00000504
	adds r2, r4, r5
	movs r3, #0
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldr r5, _080AEC58 @ =0x00001352
	adds r3, r4, r5
	ldrh r2, [r3]
	ldr r5, _080AEC5C @ =0xFFFFFF00
	adds r1, r2, r5
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0x7f
	bgt _080AEC60
	adds r0, r2, #1
	b _080AEC66
	.align 2, 0
_080AEC50: .4byte 0x03002BE0
_080AEC54: .4byte 0x00000504
_080AEC58: .4byte 0x00001352
_080AEC5C: .4byte 0xFFFFFF00
_080AEC60:
	adds r0, r2, #0
	adds r0, #0xff
	movs r1, #0xff
_080AEC66:
	ands r0, r1
	strh r0, [r3]
	ldr r0, _080AED04 @ =0x0000134C
	adds r5, r4, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _080AEC7E
	b _080AEDFC
_080AEC7E:
	ldrh r0, [r5]
	movs r1, #7
	bl Mod
	cmp r0, #0
	beq _080AEC8C
	b _080AEE04
_080AEC8C:
	ldr r7, _080AED08 @ =0x030046B8
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080AED0C @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _080AED10 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x30
	bl Mod
	ldr r3, _080AED14 @ =0x00001352
	adds r1, r4, r3
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r6, r0, #0
	subs r6, #0x18
	movs r3, #0xff
	mov sb, r3
	ands r6, r3
	ldrh r0, [r5]
	movs r1, #0x2a
	bl Mod
	cmp r0, #0
	bne _080AED68
	ldr r0, [r7]
	adds r0, #1
	mov r5, r8
	ands r0, r5
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080AED10 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	add r3, sp, #0x14
	adds r5, r0, #0
	adds r5, #8
	ldr r1, _080AED18 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	mov r2, sb
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AED1C
	asrs r2, r0, #0xc
	b _080AED22
	.align 2, 0
_080AED04: .4byte 0x0000134C
_080AED08: .4byte 0x030046B8
_080AED0C: .4byte 0x000003FF
_080AED10: .4byte 0x0203B400
_080AED14: .4byte 0x00001352
_080AED18: .4byte 0x085B0A08
_080AED1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080AED22:
	movs r0, #0
	strh r2, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AED3A
	asrs r0, r0, #0xc
	b _080AED40
_080AED3A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AED40:
	strh r0, [r3, #4]
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r2, #0xa
	str r2, [sp]
	ldr r3, _080AED64 @ =0x0000134E
	adds r1, r4, r3
	ldrh r1, [r1]
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	add r1, sp, #0x14
	movs r2, #8
	b _080AEDEE
	.align 2, 0
_080AED64: .4byte 0x0000134E
_080AED68:
	ldr r0, [r7]
	adds r0, #1
	mov r5, r8
	ands r0, r5
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080AEDA0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	add r3, sp, #0x14
	adds r5, r0, #0
	adds r5, #0xc
	ldr r1, _080AEDA4 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	mov r2, sb
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AEDA8
	asrs r2, r0, #0xc
	b _080AEDAE
	.align 2, 0
_080AEDA0: .4byte 0x0203B400
_080AEDA4: .4byte 0x085B0A08
_080AEDA8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080AEDAE:
	movs r0, #0
	strh r2, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AEDC6
	asrs r0, r0, #0xc
	b _080AEDCC
_080AEDC6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AEDCC:
	strh r0, [r3, #4]
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r2, #0xa
	str r2, [sp]
	ldr r3, _080AEDF8 @ =0x0000134E
	adds r1, r4, r3
	ldrh r1, [r1]
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	add r1, sp, #0x14
	movs r2, #4
_080AEDEE:
	movs r3, #0x96
	bl FUN_080df148
	b _080AEE04
	.align 2, 0
_080AEDF8: .4byte 0x0000134E
_080AEDFC:
	ldr r5, _080AEE14 @ =0x00001348
	adds r1, r4, r5
_080AEE00:
	movs r0, #0
	strh r0, [r1]
_080AEE04:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AEE14: .4byte 0x00001348

	thumb_func_start FUN_080aee18
FUN_080aee18: @ 0x080AEE18
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _080AEE60 @ =0x00001348
	adds r4, r6, r0
	ldr r1, _080AEE64 @ =0x0000134A
	adds r5, r6, r1
	ldrh r1, [r4]
	ldrh r2, [r5]
	cmp r1, r2
	bhs _080AEE6C
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	bne _080AEE4A
	movs r1, #0x9b
	lsls r1, r1, #5
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_0805b1a0
_080AEE4A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r5, [r5]
	cmp r0, r5
	bhs _080AEE5C
	b _080AEFC0
_080AEE5C:
	ldr r2, _080AEE68 @ =0x0000134C
	b _080AEFBA
	.align 2, 0
_080AEE60: .4byte 0x00001348
_080AEE64: .4byte 0x0000134A
_080AEE68: .4byte 0x0000134C
_080AEE6C:
	ldr r1, _080AEEC8 @ =0x0000134C
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080AEE78
	b _080AEFA6
_080AEE78:
	ldr r0, _080AEECC @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _080AEED0 @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r2, _080AEED4 @ =0x0203B400
	adds r1, r1, r2
	ldrb r4, [r1]
	ldr r1, _080AEED8 @ =0x085B0A08
	mov sl, r1
	add r5, sp, #8
	adds r7, r0, #0
	movs r2, #2
	mov sb, r2
	movs r0, #0xff
	mov r8, r0
_080AEE9C:
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r1, _080AEED8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	cmp r0, #0
	blt _080AEEDC
	asrs r1, r0, #0xc
	b _080AEEE2
	.align 2, 0
_080AEEC8: .4byte 0x0000134C
_080AEECC: .4byte 0x030046B8
_080AEED0: .4byte 0x000003FF
_080AEED4: .4byte 0x0203B400
_080AEED8: .4byte 0x085B0A08
_080AEEDC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AEEE2:
	ldrh r0, [r5]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080AEF34 @ =0xFFFF0000
	ldr r3, [sp, #8]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #8]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080AEF38 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _080AEF3C @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	asrs r1, r3, #0x10
	adds r1, #0x80
	movs r0, #0x1f
	ands r2, r0
	adds r1, r1, r2
	lsls r1, r1, #0x10
	ldr r0, _080AEF40 @ =0x0000FFFF
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #8]
	adds r0, r4, #0
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _080AEF44
	asrs r0, r0, #0xc
	b _080AEF4A
	.align 2, 0
_080AEF34: .4byte 0xFFFF0000
_080AEF38: .4byte 0x000003FF
_080AEF3C: .4byte 0x0203B400
_080AEF40: .4byte 0x0000FFFF
_080AEF44:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AEF4A:
	ldrh r1, [r5, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080AEFD0 @ =0xFFFF0000
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	movs r1, #0x9b
	lsls r1, r1, #5
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r1, _080AEFD4 @ =0x03002BE0
	ldr r2, [r1]
	adds r2, #0x2c
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xc8
	str r1, [sp, #4]
	add r1, sp, #8
	adds r3, r4, #0
	bl FUN_0805b0b0
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080AEFD8 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _080AEFDC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, r0, r4
	adds r4, r0, #0
	adds r4, #0x4e
	mov r0, r8
	ands r4, r0
	subs r1, #0x10
	add sb, r1
	mov r2, sb
	cmp r2, #0
	blt _080AEFA6
	b _080AEE9C
_080AEFA6:
	ldr r0, _080AEFE0 @ =0x0000134C
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3c
	bls _080AEFC0
	ldr r2, _080AEFE4 @ =0x00001348
_080AEFBA:
	adds r1, r6, r2
	movs r0, #0
	strh r0, [r1]
_080AEFC0:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AEFD0: .4byte 0xFFFF0000
_080AEFD4: .4byte 0x03002BE0
_080AEFD8: .4byte 0x000003FF
_080AEFDC: .4byte 0x0203B400
_080AEFE0: .4byte 0x0000134C
_080AEFE4: .4byte 0x00001348

	thumb_func_start FUN_080aefe8
FUN_080aefe8: @ 0x080AEFE8
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r5, r0, #0
	ldr r0, _080AF018 @ =0x00001348
	adds r3, r5, r0
	ldr r2, _080AF01C @ =0x0000134A
	adds r1, r5, r2
	ldrh r0, [r3]
	ldrh r2, [r1]
	cmp r0, r2
	bhs _080AF024
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080AF0A2
	ldr r3, _080AF020 @ =0x0000134C
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
	b _080AF0A2
	.align 2, 0
_080AF018: .4byte 0x00001348
_080AF01C: .4byte 0x0000134A
_080AF020: .4byte 0x0000134C
_080AF024:
	ldr r0, _080AF090 @ =0x0000134C
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r2, r0, #1
	movs r6, #0
	strh r2, [r1]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xff
	bhi _080AF0A0
	movs r0, #0x1f
	ands r2, r0
	cmp r2, #0
	bne _080AF0A2
	ldr r0, _080AF094 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r4, r5, r3
	movs r3, #0
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	ldr r3, _080AF098 @ =0x00000504
	adds r2, r5, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r1, r0, #0
	movs r2, #0x9b
	lsls r2, r2, #5
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r3, _080AF09C @ =0x0000134E
	adds r2, r5, r3
	ldrh r3, [r2]
	movs r2, #0xa
	str r2, [sp]
	movs r2, #0x78
	str r2, [sp, #4]
	movs r2, #0x5a
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r2, #0xf
	bl FUN_0805f320
	b _080AF0A2
	.align 2, 0
_080AF090: .4byte 0x0000134C
_080AF094: .4byte 0x03002BE0
_080AF098: .4byte 0x00000504
_080AF09C: .4byte 0x0000134E
_080AF0A0:
	strh r6, [r3]
_080AF0A2:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080af0ac
FUN_080af0ac: @ 0x080AF0AC
	push {lr}
	adds r2, r0, #0
	ldr r1, _080AF0C4 @ =0x0000135C
	adds r0, r2, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080AF0C0
	adds r0, r2, #0
	bl _call_via_r1
_080AF0C0:
	pop {r0}
	bx r0
	.align 2, 0
_080AF0C4: .4byte 0x0000135C

	thumb_func_start FUN_080af0c8
FUN_080af0c8: @ 0x080AF0C8
	push {lr}
	adds r1, r0, #0
	ldr r2, _080AF0DC @ =0x00001336
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #3
	beq _080AF0E0
	cmp r0, #4
	beq _080AF0E6
	b _080AF0F2
	.align 2, 0
_080AF0DC: .4byte 0x00001336
_080AF0E0:
	bl FUN_080df478
	b _080AF0F2
_080AF0E6:
	movs r2, #0x9b
	lsls r2, r2, #5
	adds r0, r1, r2
	ldr r0, [r0]
	bl FUN_0805b1a0
_080AF0F2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080af0f8
FUN_080af0f8: @ 0x080AF0F8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AF110 @ =0x00001336
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080AF1EC
	lsls r0, r0, #2
	ldr r1, _080AF114 @ =_080AF118
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080AF110: .4byte 0x00001336
_080AF114: .4byte _080AF118
_080AF118: @ jump table
	.4byte _080AF130 @ case 0
	.4byte _080AF14C @ case 1
	.4byte _080AF158 @ case 2
	.4byte _080AF180 @ case 3
	.4byte _080AF198 @ case 4
	.4byte _080AF1C0 @ case 5
_080AF130:
	ldr r2, _080AF140 @ =0x0000135C
	adds r1, r4, r2
	ldr r0, _080AF144 @ =FUN_080ae928
	str r0, [r1]
	ldr r0, _080AF148 @ =0x0000134A
	adds r1, r4, r0
	b _080AF170
	.align 2, 0
_080AF140: .4byte 0x0000135C
_080AF144: .4byte FUN_080ae928
_080AF148: .4byte 0x0000134A
_080AF14C:
	ldr r2, _080AF154 @ =0x0000135C
	adds r1, r4, r2
	b _080AF1F0
	.align 2, 0
_080AF154: .4byte 0x0000135C
_080AF158:
	bl FUN_0805d79c
	movs r2, #0x9b
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
	ldr r0, _080AF178 @ =0x0000135C
	adds r1, r4, r0
	ldr r0, _080AF17C @ =FUN_080aead8
	str r0, [r1]
	subs r2, #0x16
	adds r1, r4, r2
_080AF170:
	movs r0, #0xb4
	lsls r0, r0, #1
	strh r0, [r1]
	b _080AF1F4
	.align 2, 0
_080AF178: .4byte 0x0000135C
_080AF17C: .4byte FUN_080aead8
_080AF180:
	ldr r0, _080AF18C @ =0x0000135C
	adds r1, r4, r0
	ldr r0, _080AF190 @ =FUN_080aeb98
	str r0, [r1]
	ldr r2, _080AF194 @ =0x0000134A
	b _080AF1D8
	.align 2, 0
_080AF18C: .4byte 0x0000135C
_080AF190: .4byte FUN_080aeb98
_080AF194: .4byte 0x0000134A
_080AF198:
	ldr r1, _080AF1B4 @ =0x0000134E
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0x32
	bl FUN_0805b068
	movs r2, #0x9b
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
	ldr r0, _080AF1B8 @ =0x0000135C
	adds r1, r4, r0
	ldr r0, _080AF1BC @ =FUN_080aee18
	b _080AF1D4
	.align 2, 0
_080AF1B4: .4byte 0x0000134E
_080AF1B8: .4byte 0x0000135C
_080AF1BC: .4byte FUN_080aee18
_080AF1C0:
	movs r0, #0x5a
	bl FUN_0805f2dc
	movs r2, #0x9b
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
	ldr r0, _080AF1E4 @ =0x0000135C
	adds r1, r4, r0
	ldr r0, _080AF1E8 @ =FUN_080aefe8
_080AF1D4:
	str r0, [r1]
	subs r2, #0x16
_080AF1D8:
	adds r1, r4, r2
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	b _080AF1F4
	.align 2, 0
_080AF1E4: .4byte 0x0000135C
_080AF1E8: .4byte FUN_080aefe8
_080AF1EC:
	ldr r0, _080AF1FC @ =0x0000135C
	adds r1, r4, r0
_080AF1F0:
	movs r0, #0
	str r0, [r1]
_080AF1F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AF1FC: .4byte 0x0000135C

	thumb_func_start FUN_080af200
FUN_080af200: @ 0x080AF200
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x7f
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080AF2E8
	adds r4, r2, #0
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r1, [r0]
	ldr r2, _080AF24C @ =0x0000068D
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #0xf3
	bl PlaySound_082406e0
	ldrh r1, [r5, #0x3c]
	ldrh r0, [r6, #0x3c]
	subs r1, r1, r0
	cmp r1, #0
	bge _080AF230
	movs r1, #0
_080AF230:
	movs r0, #1
	ldr r2, [r5, #0x34]
	ands r0, r2
	cmp r0, #0
	beq _080AF254
	adds r1, #0x14
	ldr r2, _080AF250 @ =0x0000068E
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x20
	b _080AF2C2
	.align 2, 0
_080AF24C: .4byte 0x0000068D
_080AF250: .4byte 0x0000068E
_080AF254:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080AF274
	adds r1, #0x64
	ldr r2, _080AF270 @ =0x0000068E
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x18
	b _080AF2C2
	.align 2, 0
_080AF270: .4byte 0x0000068E
_080AF274:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _080AF290
	adds r1, #0x32
	ldr r2, _080AF28C @ =0x0000068E
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r1, r4, r0
	b _080AF2C0
	.align 2, 0
_080AF28C: .4byte 0x0000068E
_080AF290:
	movs r3, #0x10
	ands r3, r2
	cmp r3, #0
	beq _080AF2AC
	adds r1, #0x64
	ldr r2, _080AF2A8 @ =0x0000068E
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r1, r4, r0
	b _080AF2C0
	.align 2, 0
_080AF2A8: .4byte 0x0000068E
_080AF2AC:
	movs r0, #0x40
	ands r2, r0
	cmp r2, #0
	beq _080AF2C4
	ldr r1, _080AF2F0 @ =0x0000068E
	adds r0, r4, r1
	strh r3, [r0]
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r1, r4, r2
_080AF2C0:
	movs r0, #0x80
_080AF2C2:
	strh r0, [r1]
_080AF2C4:
	movs r1, #0xcf
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #5
	bne _080AF2DA
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
_080AF2DA:
	ldr r0, _080AF2F0 @ =0x0000068E
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0xc8
	bls _080AF2E8
	movs r0, #0xc8
	strh r0, [r1]
_080AF2E8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF2F0: .4byte 0x0000068E

	thumb_func_start FUN_080af2f4
FUN_080af2f4: @ 0x080AF2F4
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	movs r4, #1
	adds r1, r3, #0
	adds r1, #0x68
	movs r2, #7
_080AF308:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x68
	subs r2, #1
	cmp r2, #0
	bge _080AF308
	movs r4, #1
	movs r0, #0xea
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r2, #5
_080AF320:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x68
	subs r2, #1
	cmp r2, #0
	bge _080AF320
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080af334
FUN_080af334: @ 0x080AF334
	push {lr}
	mov ip, r0
	ldr r0, [r0]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
	adds r2, #0x68
	movs r3, #7
_080AF348:
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r2, #0x68
	subs r3, #1
	cmp r3, #0
	bge _080AF348
	movs r2, #2
	rsbs r2, r2, #0
	movs r1, #0xea
	lsls r1, r1, #2
	add r1, ip
	movs r3, #5
_080AF362:
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r1, #0x68
	subs r3, #1
	cmp r3, #0
	bge _080AF362
	pop {r0}
	bx r0

	thumb_func_start FUN_080af374
FUN_080af374: @ 0x080AF374
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	bne _080AF3A2
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r2, r4, r1
	adds r1, #0x58
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _080AF3E0 @ =0x0000061A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
_080AF3A2:
	cmp r5, #2
	bne _080AF3C2
	ldrh r0, [r3]
	cmp r0, #2
	beq _080AF3C2
	ldr r1, _080AF3E4 @ =0x000006AC
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_080adf50
	ldr r0, _080AF3E8 @ =0x03002C58
	ldr r0, [r0]
	ldr r3, _080AF3EC @ =0x0000133E
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
_080AF3C2:
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r2, r4, r0
	movs r1, #0
	strh r5, [r2]
	ldr r3, _080AF3F0 @ =0x0000067A
	adds r0, r4, r3
	strh r1, [r0]
	ldrh r0, [r2]
	cmp r0, #0
	bne _080AF3F4
	adds r0, r4, #0
	bl FUN_080af2f4
	b _080AF3FA
	.align 2, 0
_080AF3E0: .4byte 0x0000061A
_080AF3E4: .4byte 0x000006AC
_080AF3E8: .4byte 0x03002C58
_080AF3EC: .4byte 0x0000133E
_080AF3F0: .4byte 0x0000067A
_080AF3F4:
	adds r0, r4, #0
	bl FUN_080af334
_080AF3FA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080af400
FUN_080af400: @ 0x080AF400
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r7, r1, r0
	ldr r1, _080AF464 @ =0x0000061C
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _080AF468 @ =0x00000674
	adds r0, r5, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r6, r1, r0
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_0823785c
	adds r4, r0, #0
	lsls r1, r4, #4
	ldr r2, _080AF46C @ =0x0000067C
	adds r0, r5, r2
	movs r2, #0
	strh r1, [r0]
	ldr r1, _080AF470 @ =0x0000067E
	adds r0, r5, r1
	strh r2, [r0]
	adds r0, r4, #0
	subs r0, #0x20
	cmp r0, #0x3f
	bls _080AF454
	subs r0, #0x80
	cmp r0, #0x3f
	bhi _080AF478
_080AF454:
	lsls r0, r6, #0xc
	ldr r2, _080AF474 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r4
	lsls r1, r1, #1
	adds r1, r1, r2
	b _080AF488
	.align 2, 0
_080AF464: .4byte 0x0000061C
_080AF468: .4byte 0x00000674
_080AF46C: .4byte 0x0000067C
_080AF470: .4byte 0x0000067E
_080AF474: .4byte 0x085B0A08
_080AF478:
	lsls r0, r7, #0xc
	ldr r3, _080AF49C @ =0x085B0A08
	adds r1, r4, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
_080AF488:
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl Div
	ldr r2, _080AF4A0 @ =0x00000684
	adds r1, r5, r2
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AF49C: .4byte 0x085B0A08
_080AF4A0: .4byte 0x00000684

	thumb_func_start FUN_080af4a4
FUN_080af4a4: @ 0x080AF4A4
	push {lr}
	ldr r3, _080AF4C4 @ =0x000006AC
	adds r0, r0, r3
	ldr r0, [r0]
	lsls r1, r1, #2
	ldr r3, _080AF4C8 @ =0x00000BE8
	adds r0, r0, r3
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, r2
	beq _080AF4CC
	movs r0, #0
	b _080AF4CE
	.align 2, 0
_080AF4C4: .4byte 0x000006AC
_080AF4C8: .4byte 0x00000BE8
_080AF4CC:
	movs r0, #1
_080AF4CE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080af4d4
FUN_080af4d4: @ 0x080AF4D4
	push {lr}
	ldr r3, _080AF4F0 @ =0x000006AC
	adds r0, r0, r3
	ldr r0, [r0]
	lsls r1, r1, #2
	ldr r3, _080AF4F4 @ =0x00000BE8
	adds r0, r0, r3
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r2, #0
	bl FUN_080b283c
	pop {r0}
	bx r0
	.align 2, 0
_080AF4F0: .4byte 0x000006AC
_080AF4F4: .4byte 0x00000BE8

	thumb_func_start FUN_080af4f8
FUN_080af4f8: @ 0x080AF4F8
	ldr r1, _080AF504 @ =0x000006AC
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r0, [r0, #0x1f]
	bx lr
	.align 2, 0
_080AF504: .4byte 0x000006AC

	thumb_func_start FUN_080af508
FUN_080af508: @ 0x080AF508
	ldr r1, _080AF518 @ =0x000006AC
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080AF518: .4byte 0x000006AC

	thumb_func_start FUN_080af51c
FUN_080af51c: @ 0x080AF51C
	ldr r2, _080AF534 @ =0x000006AC
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r1, #2
	ldr r2, _080AF538 @ =0x00000BE8
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, #0xe2
	movs r1, #1
	strh r1, [r0]
	bx lr
	.align 2, 0
_080AF534: .4byte 0x000006AC
_080AF538: .4byte 0x00000BE8

	thumb_func_start FUN_080af53c
FUN_080af53c: @ 0x080AF53C
	push {r4, r5, lr}
	ldr r2, _080AF550 @ =0x000006AC
	adds r1, r0, r2
	ldr r5, [r1]
	bl FUN_080af4f8
	adds r3, r0, #0
	cmp r3, #0
	bne _080AF558
	b _080AF59C
	.align 2, 0
_080AF550: .4byte 0x000006AC
_080AF554:
	adds r0, r3, #0
	b _080AF5A0
_080AF558:
	ldr r2, _080AF5A8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AF5AC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AF5B0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #4
	adds r1, r3, #0
	bl Mod
	adds r2, r0, #0
	movs r3, #0
	ldrb r0, [r5, #0x1e]
	cmp r3, r0
	bge _080AF59C
	adds r4, r0, #0
	ldr r0, _080AF5B4 @ =0x00000BE8
	adds r1, r5, r0
_080AF584:
	ldr r0, [r1]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080AF594
	cmp r2, #0
	beq _080AF554
	subs r2, #1
_080AF594:
	adds r1, #4
	adds r3, #1
	cmp r3, r4
	blt _080AF584
_080AF59C:
	movs r0, #1
	rsbs r0, r0, #0
_080AF5A0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AF5A8: .4byte 0x030046B8
_080AF5AC: .4byte 0x000003FF
_080AF5B0: .4byte 0x0203B400
_080AF5B4: .4byte 0x00000BE8

	thumb_func_start FUN_080af5b8
FUN_080af5b8: @ 0x080AF5B8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_080af400
	ldr r5, _080AF634 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r6, _080AF638 @ =0x000003FF
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _080AF63C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r0, #0xc0
	ldr r2, _080AF640 @ =0x00000686
	adds r1, r4, r2
	strh r0, [r1]
	ldr r0, _080AF644 @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x2c
	ldrsh r0, [r2, r3]
	movs r3, #0xce
	lsls r3, r3, #3
	adds r1, r4, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	ldr r3, _080AF648 @ =0x00000674
	adds r2, r4, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldr r2, _080AF64C @ =0x0000067C
	adds r1, r4, r2
	ldrh r1, [r1]
	lsrs r1, r1, #4
	ldr r3, _080AF650 @ =0xFFFFFF00
	adds r0, r0, r3
	subs r1, r1, r0
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bgt _080AF654
	ldr r0, [r5]
	adds r0, #1
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _080AF63C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #0xc
	adds r2, #4
	b _080AF670
	.align 2, 0
_080AF634: .4byte 0x030046B8
_080AF638: .4byte 0x000003FF
_080AF63C: .4byte 0x0203B400
_080AF640: .4byte 0x00000686
_080AF644: .4byte 0x03002BE0
_080AF648: .4byte 0x00000674
_080AF64C: .4byte 0x0000067C
_080AF650: .4byte 0xFFFFFF00
_080AF654:
	ldr r0, [r5]
	adds r0, #1
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	ldr r3, _080AF6AC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #0xc
	rsbs r0, r0, #0
	movs r2, #0xd0
	lsls r2, r2, #3
_080AF670:
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, _080AF6B0 @ =0x0000067E
	adds r1, r4, r3
	movs r3, #0
	movs r0, #0
	strh r0, [r1]
	ldr r2, _080AF6B4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AF6B8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AF6AC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	ldr r2, _080AF6BC @ =0x00000682
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _080AF6C0 @ =0x0000068C
	adds r0, r4, r1
	strb r3, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF6AC: .4byte 0x0203B400
_080AF6B0: .4byte 0x0000067E
_080AF6B4: .4byte 0x030046B8
_080AF6B8: .4byte 0x000003FF
_080AF6BC: .4byte 0x00000682
_080AF6C0: .4byte 0x0000068C

	thumb_func_start FUN_080af6c4
FUN_080af6c4: @ 0x080AF6C4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r1, _080AF744 @ =0x000006AC
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r5, #0
	bl FUN_080af4f8
	adds r4, r0, #0
	adds r0, r5, #0
	bl FUN_080af508
	adds r1, r0, #0
	cmp r4, #0
	bgt _080AF6EC
	b _080AF878
_080AF6EC:
	cmp r1, #0
	bgt _080AF6F2
	b _080AF878
_080AF6F2:
	movs r6, #0
	movs r7, #0
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	adds r3, r0, #0
	cmp r3, #2
	bne _080AF758
	adds r0, r4, #0
	muls r0, r1, r0
	lsls r6, r0, #2
	ldr r2, _080AF748 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AF74C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _080AF750 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080AF7A4
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r4, _080AF754 @ =0x0000069C
	adds r2, r5, r4
	str r7, [sp]
	str r7, [sp, #4]
	str r3, [sp, #8]
	str r1, [sp, #0xc]
	movs r3, #0
	bl FUN_080ddcc8
	b _080AF7A4
	.align 2, 0
_080AF744: .4byte 0x000006AC
_080AF748: .4byte 0x030046B8
_080AF74C: .4byte 0x000003FF
_080AF750: .4byte 0x0203B400
_080AF754: .4byte 0x0000069C
_080AF758:
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _080AF766
	cmp r3, #7
	bne _080AF7A4
_080AF766:
	adds r6, r4, #0
	muls r6, r1, r6
	ldr r2, _080AF7FC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AF800 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AF804 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080AF7A4
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, _080AF808 @ =0x000006A4
	adds r2, r5, r3
	str r7, [sp]
	str r7, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r3, #0
	bl FUN_080ddcc8
_080AF7A4:
	cmp r6, #0
	ble _080AF7BE
	ldr r0, _080AF80C @ =0x00000BF8
	add r0, r8
	ldrh r0, [r0]
	muls r0, r6, r0
	movs r1, #0x64
	bl Div
	adds r6, r0, #0
	cmp r6, #0
	bgt _080AF7BE
	movs r6, #1
_080AF7BE:
	ldr r0, _080AF810 @ =0x00000696
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r0, r0, r6
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x28
	bls _080AF7E6
	ldrh r0, [r4]
	movs r1, #0x28
	bl Div
	adds r7, r7, r0
	lsls r1, r7, #2
	adds r1, r1, r7
	lsls r1, r1, #3
	ldrh r0, [r4]
	subs r0, r0, r1
	strh r0, [r4]
_080AF7E6:
	ldr r1, _080AF814 @ =0x030046A0
	ldr r0, [r1]
	movs r3, #0xae
	lsls r3, r3, #2
	adds r2, r0, r3
	ldr r0, [r2]
	cmp r0, r7
	bgt _080AF818
	movs r0, #0
	b _080AF81A
	.align 2, 0
_080AF7FC: .4byte 0x030046B8
_080AF800: .4byte 0x000003FF
_080AF804: .4byte 0x0203B400
_080AF808: .4byte 0x000006A4
_080AF80C: .4byte 0x00000BF8
_080AF810: .4byte 0x00000696
_080AF814: .4byte 0x030046A0
_080AF818:
	subs r0, r0, r7
_080AF81A:
	str r0, [r2]
	ldr r5, _080AF884 @ =0x03002C58
	ldr r0, [r5]
	ldr r3, _080AF888 @ =0x0000133F
	adds r2, r0, r3
	ldrb r4, [r2]
	cmp r4, #0
	bne _080AF878
	ldr r0, [r1]
	movs r6, #0xae
	lsls r6, r6, #2
	adds r1, r0, r6
	adds r6, #4
	adds r0, r0, r6
	ldr r0, [r0]
	asrs r0, r0, #2
	ldr r1, [r1]
	cmp r1, r0
	bgt _080AF878
	movs r0, #1
	strb r0, [r2]
	ldr r1, [r5]
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r1, r2
	adds r1, r1, r0
	ldrh r0, [r1]
	bl PlaySound_082406e0
	movs r0, #0x1f
	str r0, [sp]
	ldr r0, _080AF88C @ =0x00001FFF
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0
	movs r1, #4
	movs r2, #0x1f
	movs r3, #0x1f
	bl FUN_0823ce68
	ldr r0, [r5]
	movs r1, #4
	bl FUN_080ad204
_080AF878:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AF884: .4byte 0x03002C58
_080AF888: .4byte 0x0000133F
_080AF88C: .4byte 0x00001FFF

	thumb_func_start FUN_080af890
FUN_080af890: @ 0x080AF890
	ldr r1, _080AF89C @ =0x0000068A
	adds r0, r0, r1
	movs r1, #0x10
	strh r1, [r0]
	bx lr
	.align 2, 0
_080AF89C: .4byte 0x0000068A

	thumb_func_start FUN_080af8a0
FUN_080af8a0: @ 0x080AF8A0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080AF900 @ =0x000006AC
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _080AF904 @ =0x0000068A
	adds r1, r4, r2
	movs r0, #0x10
	strh r0, [r1]
	movs r0, #0xc3
	lsls r0, r0, #3
	adds r2, r4, r0
	movs r1, #0xce
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080AF908 @ =0x0000067A
	adds r3, r4, r2
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080AF938
	ldr r0, _080AF90C @ =0x0000061A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AF910
	ldrb r0, [r5, #0x1f]
	cmp r0, #0
	beq _080AF910
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080af374
	b _080AF970
	.align 2, 0
_080AF900: .4byte 0x000006AC
_080AF904: .4byte 0x0000068A
_080AF908: .4byte 0x0000067A
_080AF90C: .4byte 0x0000061A
_080AF910:
	adds r0, r4, #0
	bl FUN_080af5b8
	ldr r2, _080AF934 @ =0x00000686
	adds r1, r4, r2
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0xd1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x60
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080af374
	b _080AF970
	.align 2, 0
_080AF934: .4byte 0x00000686
_080AF938:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080AF960
	ldr r1, _080AF95C @ =0x0000061A
	adds r2, r4, r1
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r0, #0
	ldrh r0, [r2]
	adds r1, r1, r0
	ldrh r0, [r3]
	subs r0, #8
	lsls r0, r0, #4
	subs r1, r1, r0
	strh r1, [r2]
	b _080AF970
	.align 2, 0
_080AF95C: .4byte 0x0000061A
_080AF960:
	ldr r2, _080AF978 @ =0x0000061A
	adds r1, r4, r2
	ldrh r0, [r3]
	adds r0, #1
	lsls r0, r0, #5
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_080AF970:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AF978: .4byte 0x0000061A

	thumb_func_start FUN_080af97c
FUN_080af97c: @ 0x080AF97C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r1, _080AF9A4 @ =0x0000068A
	adds r0, r7, r1
	movs r2, #0x10
	strh r2, [r0]
	ldr r0, _080AF9A8 @ =0x0000067A
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080AF9AC
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080af374
	b _080AFA0A
	.align 2, 0
_080AF9A4: .4byte 0x0000068A
_080AF9A8: .4byte 0x0000067A
_080AF9AC:
	ldrh r4, [r1]
	subs r4, r2, r4
	adds r6, r4, #1
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r5, r7, r1
	movs r2, #0
	ldrsh r0, [r5, r2]
	muls r0, r4, r0
	movs r2, #0xce
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	ldr r0, _080AFA10 @ =0x0000061A
	adds r5, r7, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	ldr r2, _080AFA14 @ =0x00000672
	adds r1, r7, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	ldr r0, _080AFA18 @ =0x0000061C
	adds r5, r7, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	ldr r2, _080AFA1C @ =0x00000674
	adds r1, r7, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
_080AFA0A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AFA10: .4byte 0x0000061A
_080AFA14: .4byte 0x00000672
_080AFA18: .4byte 0x0000061C
_080AFA1C: .4byte 0x00000674

	thumb_func_start FUN_080afa20
FUN_080afa20: @ 0x080AFA20
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080AFA50 @ =0x0000068A
	adds r1, r5, r0
	movs r0, #0x10
	strh r0, [r1]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xce
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r4, #0
	ldrsh r2, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	blt _080AFA54
	asrs r1, r0, #2
	b _080AFA5A
	.align 2, 0
_080AFA50: .4byte 0x0000068A
_080AFA54:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_080AFA5A:
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _080AFAA8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080AFAAC @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r4, _080AFAB0 @ =0x0203B400
	adds r0, r0, r4
	ldrh r1, [r0]
	ldr r0, _080AFAB4 @ =0x00000672
	adds r2, r5, r0
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x80
	ldrh r0, [r2]
	adds r0, r0, r1
	ldr r2, _080AFAB8 @ =0x0000061A
	adds r1, r5, r2
	strh r0, [r1]
	ldr r4, _080AFABC @ =0x0000061C
	adds r0, r5, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r4, #0x58
	adds r0, r5, r4
	movs r4, #0
	ldrsh r2, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	blt _080AFAC0
	asrs r1, r0, #2
	b _080AFAC6
	.align 2, 0
_080AFAA8: .4byte 0x030046B8
_080AFAAC: .4byte 0x000003FF
_080AFAB0: .4byte 0x0203B400
_080AFAB4: .4byte 0x00000672
_080AFAB8: .4byte 0x0000061A
_080AFABC: .4byte 0x0000061C
_080AFAC0:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_080AFAC6:
	ldr r2, _080AFB40 @ =0x0000061C
	adds r0, r5, r2
	strh r1, [r0]
	ldr r4, _080AFB44 @ =0x0000067A
	adds r1, r5, r4
	ldrh r0, [r1]
	ldr r2, _080AFB48 @ =0x0000012B
	cmp r0, r2
	bhi _080AFADC
	adds r0, #1
	strh r0, [r1]
_080AFADC:
	ldrh r0, [r1]
	cmp r0, #0x3b
	bls _080AFBC4
	movs r0, #0xd3
	lsls r0, r0, #3
	adds r6, r5, r0
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AFB9C
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080AFB4C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _080AFB50 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r4, #0x96
	lsls r4, r4, #1
	adds r1, r4, #0
	bl Mod
	adds r0, r0, r4
	strh r0, [r6]
	adds r0, r5, #0
	bl FUN_080af53c
	ldr r2, _080AFB54 @ =0x00000692
	adds r4, r5, r2
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _080AFBC4
	adds r0, r5, #0
	bl FUN_080af400
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _080AFB5C
	ldr r3, _080AFB58 @ =0x0000067C
	adds r1, r5, r3
	movs r0, #0xf0
	lsls r0, r0, #3
	b _080AFB8C
	.align 2, 0
_080AFB40: .4byte 0x0000061C
_080AFB44: .4byte 0x0000067A
_080AFB48: .4byte 0x0000012B
_080AFB4C: .4byte 0x000003FF
_080AFB50: .4byte 0x0203B400
_080AFB54: .4byte 0x00000692
_080AFB58: .4byte 0x0000067C
_080AFB5C:
	cmp r0, #1
	bne _080AFB70
	ldr r4, _080AFB6C @ =0x0000067C
	adds r1, r5, r4
	movs r0, #0xf8
	lsls r0, r0, #4
	b _080AFB8C
	.align 2, 0
_080AFB6C: .4byte 0x0000067C
_080AFB70:
	cmp r0, #2
	bne _080AFB84
	ldr r0, _080AFB80 @ =0x0000067C
	adds r1, r5, r0
	movs r0, #0xc8
	lsls r0, r0, #4
	b _080AFB8C
	.align 2, 0
_080AFB80: .4byte 0x0000067C
_080AFB84:
	ldr r2, _080AFB98 @ =0x0000067C
	adds r1, r5, r2
	movs r0, #0x90
	lsls r0, r0, #3
_080AFB8C:
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080af374
	b _080AFBC4
	.align 2, 0
_080AFB98: .4byte 0x0000067C
_080AFB9C:
	ldrh r0, [r1]
	cmp r0, r2
	bls _080AFBC4
	adds r0, r5, #0
	bl FUN_080af5b8
	ldr r3, _080AFBCC @ =0x00000686
	adds r1, r5, r3
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	movs r4, #0xd1
	lsls r4, r4, #3
	adds r1, r5, r4
	movs r0, #0x60
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080af374
_080AFBC4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AFBCC: .4byte 0x00000686

	thumb_func_start FUN_080afbd0
FUN_080afbd0: @ 0x080AFBD0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _080AFBF4 @ =0x0000067E
	adds r1, r6, r0
	movs r2, #0xd0
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r3, [r1]
	movs r4, #0
	ldrsh r2, [r1, r4]
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r2, r0
	bge _080AFBF8
	adds r0, r3, #1
	b _080AFBFE
	.align 2, 0
_080AFBF4: .4byte 0x0000067E
_080AFBF8:
	cmp r2, r0
	ble _080AFC00
	subs r0, r3, #1
_080AFBFE:
	strh r0, [r1]
_080AFC00:
	ldr r0, _080AFCF4 @ =0x00000682
	adds r4, r6, r0
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AFC62
	ldr r1, _080AFCF8 @ =0x0203B400
	mov ip, r1
	ldr r5, _080AFCFC @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r7, _080AFD00 @ =0x000003FF
	ands r1, r7
	lsls r0, r1, #1
	add r0, ip
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	adds r3, r0, #0
	adds r3, #0xc
	movs r0, #0xd0
	lsls r0, r0, #3
	adds r2, r6, r0
	strh r3, [r2]
	adds r1, #1
	ands r1, r7
	str r1, [r5]
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080AFC4C
	rsbs r0, r3, #0
	strh r0, [r2]
_080AFC4C:
	ldr r0, [r5]
	adds r0, #1
	ands r0, r7
	str r0, [r5]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x20
	strh r0, [r4]
_080AFC62:
	ldr r1, _080AFD04 @ =0x0000067C
	adds r3, r6, r1
	ldr r4, _080AFD08 @ =0x00000FFF
	adds r2, r4, #0
	ldrh r5, [r3]
	adds r1, r2, r5
	ldr r4, _080AFD0C @ =0x0000067E
	adds r0, r6, r4
	ldrh r0, [r0]
	adds r0, r0, r1
	ands r0, r2
	strh r0, [r3]
	lsrs r0, r0, #4
	mov ip, r0
	movs r5, #0xd1
	lsls r5, r5, #3
	adds r7, r6, r5
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AFCBC
	ldr r5, _080AFCF8 @ =0x0203B400
	ldr r4, _080AFCFC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _080AFD00 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrb r1, [r1]
	adds r1, #0xc0
	ldr r2, _080AFD10 @ =0x00000686
	strh r1, [r2, r6]
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	strh r0, [r7]
_080AFCBC:
	ldr r3, _080AFD14 @ =0x00000684
	adds r1, r6, r3
	ldrh r2, [r1]
	lsls r0, r2, #4
	ldr r4, _080AFD10 @ =0x00000686
	adds r3, r6, r4
	subs r0, r0, r2
	ldrh r3, [r3]
	adds r0, r0, r3
	asrs r0, r0, #4
	strh r0, [r1]
	ldrh r3, [r1]
	ldr r1, _080AFD18 @ =0x085B0A08
	mov r2, ip
	adds r2, #0x40
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r3, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _080AFD1C
	asrs r0, r0, #0xc
	b _080AFD22
	.align 2, 0
_080AFCF4: .4byte 0x00000682
_080AFCF8: .4byte 0x0203B400
_080AFCFC: .4byte 0x030046B8
_080AFD00: .4byte 0x000003FF
_080AFD04: .4byte 0x0000067C
_080AFD08: .4byte 0x00000FFF
_080AFD0C: .4byte 0x0000067E
_080AFD10: .4byte 0x00000686
_080AFD14: .4byte 0x00000684
_080AFD18: .4byte 0x085B0A08
_080AFD1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AFD22:
	adds r3, r0, #0
	ldr r1, _080AFD4C @ =0x0000068C
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #5
	muls r0, r1, r0
	cmp r0, #0
	blt _080AFD50
	asrs r1, r0, #0x18
	b _080AFD56
	.align 2, 0
_080AFD4C: .4byte 0x0000068C
_080AFD50:
	rsbs r0, r0, #0
	asrs r0, r0, #0x18
	rsbs r1, r0, #0
_080AFD56:
	movs r5, #0xce
	lsls r5, r5, #3
	adds r0, r6, r5
	ldrh r0, [r0]
	adds r0, r0, r3
	adds r0, r0, r1
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r1, r6, r2
	strh r0, [r1]
	ldr r3, _080AFD84 @ =0x00000684
	adds r0, r6, r3
	ldrh r1, [r0]
	mov r5, ip
	lsls r0, r5, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080AFD88
	asrs r0, r0, #0xc
	b _080AFD8E
	.align 2, 0
_080AFD84: .4byte 0x00000684
_080AFD88:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AFD8E:
	adds r2, r0, #0
	ldr r3, _080AFDB4 @ =0x0000068C
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r5, #0
	ldrsh r1, [r0, r5]
	mov r3, ip
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #5
	muls r0, r1, r0
	cmp r0, #0
	blt _080AFDB8
	asrs r1, r0, #0x18
	b _080AFDBE
	.align 2, 0
_080AFDB4: .4byte 0x0000068C
_080AFDB8:
	rsbs r0, r0, #0
	asrs r0, r0, #0x18
	rsbs r1, r0, #0
_080AFDBE:
	ldr r5, _080AFDFC @ =0x00000674
	adds r0, r6, r5
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r2, _080AFE00 @ =0x0000061C
	adds r1, r6, r2
	strh r0, [r1]
	movs r3, #0xd3
	lsls r3, r3, #3
	adds r1, r6, r3
	ldrh r0, [r1]
	cmp r0, #2
	bhi _080AFE08
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_080af53c
	ldr r4, _080AFE04 @ =0x00000692
	adds r1, r6, r4
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _080AFE0C
	adds r0, r6, #0
	movs r1, #4
	bl FUN_080af374
	b _080AFE0C
	.align 2, 0
_080AFDFC: .4byte 0x00000674
_080AFE00: .4byte 0x0000061C
_080AFE04: .4byte 0x00000692
_080AFE08:
	subs r0, #2
	strh r0, [r1]
_080AFE0C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080afe18
FUN_080afe18: @ 0x080AFE18
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r1, _080AFE38 @ =0x00000692
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080AFE3C
	movs r4, #0xf0
	lsls r4, r4, #3
	movs r6, #0xf0
	lsls r6, r6, #1
	b _080AFE5C
	.align 2, 0
_080AFE38: .4byte 0x00000692
_080AFE3C:
	cmp r0, #1
	bne _080AFE46
	movs r4, #0xf8
	lsls r4, r4, #4
	b _080AFE58
_080AFE46:
	cmp r0, #2
	bne _080AFE54
	movs r4, #0xc8
	lsls r4, r4, #4
	movs r6, #0xf0
	lsls r6, r6, #1
	b _080AFE5C
_080AFE54:
	movs r4, #0x90
	lsls r4, r4, #3
_080AFE58:
	movs r6, #0xc8
	lsls r6, r6, #1
_080AFE5C:
	ldr r2, _080AFE7C @ =0x0000067C
	adds r1, r5, r2
	ldrh r2, [r1]
	ldr r3, _080AFE80 @ =0xFFFFF000
	adds r0, r2, r3
	subs r7, r4, r0
	ldr r3, _080AFE84 @ =0x00000FFF
	ands r7, r3
	ldr r0, _080AFE88 @ =0x000007FF
	cmp r7, r0
	bgt _080AFE8C
	cmp r7, #0x2f
	ble _080AFE94
	adds r0, r2, #0
	adds r0, #0x30
	b _080AFE9E
	.align 2, 0
_080AFE7C: .4byte 0x0000067C
_080AFE80: .4byte 0xFFFFF000
_080AFE84: .4byte 0x00000FFF
_080AFE88: .4byte 0x000007FF
_080AFE8C:
	movs r0, #0xfd
	lsls r0, r0, #4
	cmp r7, r0
	ble _080AFE98
_080AFE94:
	strh r4, [r1]
	b _080AFEA2
_080AFE98:
	movs r4, #0xfd
	lsls r4, r4, #4
	adds r0, r2, r4
_080AFE9E:
	ands r0, r3
	strh r0, [r1]
_080AFEA2:
	ldr r1, _080AFEE0 @ =0x0000067C
	adds r0, r5, r1
	ldrh r0, [r0]
	lsrs r4, r0, #4
	ldr r3, _080AFEE4 @ =0x00000684
	adds r2, r5, r3
	ldrh r1, [r2]
	subs r0, r6, r1
	mov ip, r0
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r6
	asrs r0, r0, #3
	strh r0, [r2]
	ldrh r3, [r2]
	ldr r2, _080AFEE8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r6, r2, #0
	cmp r0, #0
	blt _080AFEEC
	asrs r0, r0, #0xc
	b _080AFEF2
	.align 2, 0
_080AFEE0: .4byte 0x0000067C
_080AFEE4: .4byte 0x00000684
_080AFEE8: .4byte 0x085B0A08
_080AFEEC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AFEF2:
	mov r8, r0
	ldr r2, _080AFF24 @ =0x0000068C
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	muls r0, r2, r0
	cmp r0, #0
	blt _080AFF28
	asrs r2, r0, #0x18
	b _080AFF2E
	.align 2, 0
_080AFF24: .4byte 0x0000068C
_080AFF28:
	rsbs r0, r0, #0
	asrs r0, r0, #0x18
	rsbs r2, r0, #0
_080AFF2E:
	movs r3, #0xce
	lsls r3, r3, #3
	adds r0, r5, r3
	ldrh r0, [r0]
	add r0, r8
	adds r0, r0, r2
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r1, r5, r2
	strh r0, [r1]
	adds r3, #0x14
	adds r0, r5, r3
	ldrh r1, [r0]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080AFF5E
	asrs r0, r0, #0xc
	b _080AFF64
_080AFF5E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AFF64:
	mov r8, r0
	ldr r3, _080AFF90 @ =0x0000068C
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r2, [r0, r3]
	ands r4, r1
	lsls r0, r4, #1
	adds r0, r0, r6
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #5
	muls r0, r2, r0
	cmp r0, #0
	blt _080AFF94
	asrs r1, r0, #0x18
	b _080AFF9A
	.align 2, 0
_080AFF90: .4byte 0x0000068C
_080AFF94:
	rsbs r0, r0, #0
	asrs r0, r0, #0x18
	rsbs r1, r0, #0
_080AFF9A:
	ldr r2, _080AFFD4 @ =0x00000674
	adds r0, r5, r2
	ldrh r0, [r0]
	add r0, r8
	adds r0, r0, r1
	ldr r3, _080AFFD8 @ =0x0000061C
	adds r1, r5, r3
	strh r0, [r1]
	cmp r7, #0
	bne _080AFFC8
	mov r0, ip
	cmp r0, #0
	bge _080AFFB6
	rsbs r0, r0, #0
_080AFFB6:
	cmp r0, #0x1f
	bgt _080AFFC8
	movs r0, #0xf4
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #5
	bl FUN_080af374
_080AFFC8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AFFD4: .4byte 0x00000674
_080AFFD8: .4byte 0x0000061C

	thumb_func_start FUN_080affdc
FUN_080affdc: @ 0x080AFFDC
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080B0060 @ =0x00000692
	adds r5, r4, r0
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r0, r4, #0
	movs r2, #4
	bl FUN_080af4a4
	cmp r0, #0
	beq _080B0086
	ldr r2, _080B0064 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080B0068 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080B006C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r1, r0, #3
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _080B0032
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r3, _080B0070 @ =0x0000069C
	adds r2, r4, r3
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #1
	str r1, [sp, #8]
	movs r1, #2
	str r1, [sp, #0xc]
	movs r1, #1
	movs r3, #0
	bl FUN_080ddcc8
_080B0032:
	ldr r0, _080B0074 @ =0x0000067A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080B0078
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r0, r4, #0
	movs r2, #5
	bl FUN_080af4d4
	adds r0, r4, #0
	bl FUN_080af5b8
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080af374
	b _080B0094
	.align 2, 0
_080B0060: .4byte 0x00000692
_080B0064: .4byte 0x030046B8
_080B0068: .4byte 0x000003FF
_080B006C: .4byte 0x0203B400
_080B0070: .4byte 0x0000069C
_080B0074: .4byte 0x0000067A
_080B0078:
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r0, r4, #0
	movs r2, #5
	bl FUN_080af51c
	b _080B0094
_080B0086:
	adds r0, r4, #0
	bl FUN_080af5b8
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080af374
_080B0094:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b009c
FUN_080b009c: @ 0x080B009C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B00D0 @ =0x0000068A
	adds r1, r4, r0
	movs r0, #6
	strh r0, [r1]
	ldr r1, _080B00D4 @ =0x0000068E
	adds r0, r4, r1
	ldrh r3, [r0]
	ldr r2, _080B00D8 @ =0x085B0A08
	subs r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080B00DC
	asrs r3, r0, #0xc
	b _080B00E2
	.align 2, 0
_080B00D0: .4byte 0x0000068A
_080B00D4: .4byte 0x0000068E
_080B00D8: .4byte 0x085B0A08
_080B00DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080B00E2:
	movs r0, #0xc3
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r1, _080B010C @ =0x0000068E
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r3, _080B0110 @ =0x0000068D
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080B0114
	asrs r2, r0, #0xc
	b _080B011A
	.align 2, 0
_080B010C: .4byte 0x0000068E
_080B0110: .4byte 0x0000068D
_080B0114:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080B011A:
	ldr r3, _080B0174 @ =0x0000061C
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r3, #0xce
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r2, r2, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	ldr r3, _080B0178 @ =0x00000674
	adds r1, r4, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _080B017C @ =0x00077A0F
	cmp r1, r0
	ble _080B0188
	ldr r3, _080B0180 @ =0x0000068E
	adds r1, r4, r3
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _080B0168
	movs r0, #0x1e
	strh r0, [r1]
_080B0168:
	ldr r0, _080B0184 @ =0x0000068D
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #0x80
	strb r0, [r1]
	b _080B0196
	.align 2, 0
_080B0174: .4byte 0x0000061C
_080B0178: .4byte 0x00000674
_080B017C: .4byte 0x00077A0F
_080B0180: .4byte 0x0000068E
_080B0184: .4byte 0x0000068D
_080B0188:
	ldr r1, _080B01B0 @ =0x0000068E
	adds r2, r4, r1
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
_080B0196:
	ldr r2, _080B01B0 @ =0x0000068E
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B01A8
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080af374
_080B01A8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B01B0: .4byte 0x0000068E

	thumb_func_start FUN_080b01b4
FUN_080b01b4: @ 0x080B01B4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B01E8 @ =0x0000067A
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r0, r4, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	blo _080B01E0
	adds r0, r4, #0
	bl FUN_080af5b8
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080af374
_080B01E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B01E8: .4byte 0x0000067A

	thumb_func_start FUN_080b01ec
FUN_080b01ec: @ 0x080B01EC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r4, r0, #0
	ldr r0, _080B02B4 @ =0x0000068A
	adds r1, r4, r0
	movs r7, #0
	movs r0, #0x10
	strh r0, [r1]
	ldr r1, _080B02B8 @ =0x0000067A
	adds r6, r4, r1
	ldrh r0, [r6]
	cmp r0, #0x3f
	bhi _080B02D0
	cmp r0, #0
	bne _080B021C
	adds r0, r4, #0
	bl FUN_080af2f4
	ldr r0, _080B02BC @ =0x03002C58
	ldr r0, [r0]
	ldr r1, _080B02C0 @ =0x0000133E
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
_080B021C:
	ldrh r1, [r6]
	cmp r1, #0x1f
	bls _080B022A
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B02A6
_080B022A:
	movs r0, #0x40
	subs r0, r0, r1
	lsls r0, r0, #0x11
	lsrs r0, r0, #0x10
	ldr r3, _080B02C4 @ =0xFFFF0000
	ldr r2, [sp, #0x10]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0x10]
	add r0, sp, #0x10
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	ldr r0, _080B02C8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	ldrh r1, [r0]
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r4, r1
	str r7, [sp]
	str r7, [sp, #4]
	movs r5, #2
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
	ldrh r0, [r6]
	cmp r0, #0x1f
	bhi _080B02A6
	ldr r1, _080B02CC @ =0x000006AC
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_080adf50
	ldrh r0, [r6]
	movs r1, #5
	bl Mod
	movs r1, #0x68
	muls r0, r1, r0
	adds r0, r0, r4
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r0, r0, r1
	str r7, [sp]
	str r7, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
_080B02A6:
	ldr r0, _080B02B8 @ =0x0000067A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080B02D8
	.align 2, 0
_080B02B4: .4byte 0x0000068A
_080B02B8: .4byte 0x0000067A
_080B02BC: .4byte 0x03002C58
_080B02C0: .4byte 0x0000133E
_080B02C4: .4byte 0xFFFF0000
_080B02C8: .4byte 0x0000FFFF
_080B02CC: .4byte 0x000006AC
_080B02D0:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080af374
_080B02D8:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b02e0
FUN_080b02e0: @ 0x080B02E0
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xcf
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #9
	beq _080B038E
	cmp r0, #0
	beq _080B038E
	cmp r0, #1
	beq _080B038E
	cmp r0, #6
	beq _080B038E
	cmp r0, #2
	bne _080B031A
	adds r0, r4, #0
	bl FUN_080af508
	cmp r0, #0
	bne _080B037C
	adds r0, r4, #0
	bl FUN_080af5b8
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080af374
	b _080B038E
_080B031A:
	cmp r0, #7
	bne _080B037C
	adds r0, r4, #0
	bl FUN_080af508
	cmp r0, #0
	ble _080B037C
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r3, #0x58
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r2, r2, r0
	subs r3, #0x54
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r3, #0x58
	adds r1, r4, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	subs r0, #0x40
	subs r2, #0x40
	cmp r2, #0
	bge _080B0358
	rsbs r2, r2, #0
_080B0358:
	cmp r2, #0x7f
	bgt _080B037C
	cmp r0, #0
	bge _080B0362
	rsbs r0, r0, #0
_080B0362:
	cmp r0, #0x7f
	bgt _080B037C
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080af374
	ldr r0, _080B0378 @ =0x0000068E
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	b _080B038E
	.align 2, 0
_080B0378: .4byte 0x0000068E
_080B037C:
	ldr r1, _080B0394 @ =0x0000068E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080B038E
	adds r0, r4, #0
	movs r1, #7
	bl FUN_080af374
_080B038E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B0394: .4byte 0x0000068E

	thumb_func_start FUN_080b0398
FUN_080b0398: @ 0x080B0398
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	str r1, [sp]
	movs r0, #0
	mov r8, r0
	movs r7, #0xff
	ldr r1, _080B03F0 @ =0x085B0A08
	mov sl, r1
	movs r2, #1
	mov sb, r2
_080B03B6:
	movs r0, #0x68
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	adds r0, #0x68
	adds r0, r0, r6
	mov ip, r0
	mov r4, ip
	ldr r2, _080B03F0 @ =0x085B0A08
	adds r0, #0x64
	ldrh r1, [r0]
	adds r0, r7, #0
	ands r0, r1
	adds r0, #0x40
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	cmp r1, #0
	bge _080B03E2
	rsbs r1, r1, #0
_080B03E2:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080B03F4
	asrs r0, r0, #0xc
	b _080B03FA
	.align 2, 0
_080B03F0: .4byte 0x085B0A08
_080B03F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080B03FA:
	adds r3, r0, #0
	adds r3, #0x3c
	mov r0, ip
	adds r0, #0x66
	ldrh r1, [r0]
	adds r1, #0x40
	ands r1, r7
	lsls r1, r1, #1
	add r1, sl
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r1, r3, r1
	adds r2, r0, #0
	cmp r1, #0
	blt _080B041C
	asrs r1, r1, #0xc
	b _080B0422
_080B041C:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080B0422:
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r0, r6, r5
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	ldr r1, _080B0450 @ =0x0000061A
	adds r0, r6, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x1e]
	ldrh r1, [r2]
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r3, r0
	cmp r0, #0
	blt _080B0454
	asrs r1, r0, #0xc
	b _080B045A
	.align 2, 0
_080B0450: .4byte 0x0000061A
_080B0454:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080B045A:
	ldr r3, _080B047C @ =0x0000061C
	adds r0, r6, r3
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	movs r5, #0xcf
	lsls r5, r5, #3
	adds r0, r6, r5
	ldrh r0, [r0]
	cmp r0, #2
	bne _080B0480
	mov r1, ip
	adds r1, #0x64
	ldrh r0, [r1]
	adds r0, #4
	b _080B0488
	.align 2, 0
_080B047C: .4byte 0x0000061C
_080B0480:
	mov r1, ip
	adds r1, #0x64
	ldrh r0, [r1]
	adds r0, #2
_080B0488:
	strh r0, [r1]
	mov r0, r8
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _080B049A
	ldrh r0, [r2]
	adds r0, #1
	b _080B049E
_080B049A:
	ldrh r0, [r2]
	adds r0, #0xff
_080B049E:
	ands r0, r7
	strh r0, [r2]
	mov r4, ip
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, ip
	ldr r1, [r2, #0x48]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r2, #0x10]
	ldrb r0, [r4, #4]
	mov r2, sb
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r3, sb
	ands r0, r3
	cmp r2, r0
	beq _080B04DA
	mov r1, ip
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _080B04E6
_080B04DA:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080B04E6:
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
	beq _080B050C
	mov r5, ip
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	str r0, [r5]
	b _080B051A
_080B050C:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
_080B051A:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _080B0550 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r4, #7]
	cmp r0, r5
	blo _080B0588
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B0554
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B0548
	ldrb r0, [r4, #5]
_080B0548:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B0564
	.align 2, 0
_080B0550: .4byte 0x0000FFFF
_080B0554:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B0564
	strh r1, [r4, #8]
_080B0564:
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
	ands r0, r7
	cmp r0, #0
	bne _080B0588
	mov r3, sb
	strb r3, [r4, #7]
_080B0588:
	mov r0, ip
	adds r0, #0x2c
	ldr r1, [sp]
	bl FUN_0822b20c
	movs r5, #1
	add r8, r5
	mov r0, r8
	cmp r0, #7
	bgt _080B059E
	b _080B03B6
_080B059E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b05b0
FUN_080b05b0: @ 0x080B05B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	str r1, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r1, #0xff
	mov sl, r1
	movs r2, #0x18
	str r2, [sp, #8]
_080B05CC:
	movs r0, #0x68
	ldr r3, [sp, #4]
	muls r0, r3, r0
	movs r4, #0xea
	lsls r4, r4, #2
	adds r0, r0, r4
	add r0, r8
	mov ip, r0
	mov sb, ip
	adds r2, r3, #0
	adds r2, #2
	movs r0, #8
	subs r3, r0, r2
	ldr r0, _080B0608 @ =0x0000061A
	add r0, r8
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r0, _080B060C @ =0x00000672
	add r0, r8
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r1, r1, r0
	muls r1, r3, r1
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _080B0610
	asrs r0, r0, #5
	b _080B0616
	.align 2, 0
_080B0608: .4byte 0x0000061A
_080B060C: .4byte 0x00000672
_080B0610:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_080B0616:
	adds r4, r0, #0
	movs r0, #0xc3
	lsls r0, r0, #3
	add r0, r8
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r1, r0, #0
	muls r1, r2, r1
	movs r0, #0xce
	lsls r0, r0, #3
	add r0, r8
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080B063C
	asrs r0, r0, #3
	b _080B0642
_080B063C:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080B0642:
	adds r1, r0, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080B0670 @ =0xFFFF0000
	ands r0, r6
	adds r6, r0, #0
	orrs r6, r1
	ldr r0, _080B0674 @ =0x0000061A
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r2, r1
	ldr r0, _080B0678 @ =0x00000672
	add r0, r8
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080B067C
	asrs r0, r0, #3
	b _080B0682
	.align 2, 0
_080B0670: .4byte 0xFFFF0000
_080B0674: .4byte 0x0000061A
_080B0678: .4byte 0x00000672
_080B067C:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080B0682:
	lsls r1, r0, #0x10
	ldr r0, _080B06AC @ =0x0000FFFF
	ands r0, r6
	adds r6, r0, #0
	orrs r6, r1
	ldr r0, _080B06B0 @ =0x0000061C
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r2, r1
	ldr r0, _080B06B4 @ =0x00000674
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080B06B8
	asrs r0, r0, #3
	b _080B06BE
	.align 2, 0
_080B06AC: .4byte 0x0000FFFF
_080B06B0: .4byte 0x0000061C
_080B06B4: .4byte 0x00000674
_080B06B8:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080B06BE:
	adds r1, r0, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080B06F4 @ =0xFFFF0000
	ands r0, r7
	adds r7, r0, #0
	orrs r7, r1
	ldr r2, _080B06F8 @ =0x085B0A08
	mov r3, ip
	adds r3, #0x64
	ldrh r1, [r3]
	mov r0, sl
	ands r0, r1
	adds r0, #0x40
	mov r4, sl
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r0, [r0, r5]
	ldr r1, [sp, #8]
	muls r0, r1, r0
	cmp r0, #0
	blt _080B06FC
	asrs r0, r0, #0xc
	b _080B0702
	.align 2, 0
_080B06F4: .4byte 0xFFFF0000
_080B06F8: .4byte 0x085B0A08
_080B06FC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080B0702:
	adds r5, r0, #0
	mov r0, ip
	adds r0, #0x66
	ldrh r1, [r0]
	adds r1, #0x40
	mov r4, sl
	ands r1, r4
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r4, #0
	ldrsh r1, [r1, r4]
	muls r1, r5, r1
	adds r4, r0, #0
	cmp r1, #0
	blt _080B0724
	asrs r0, r1, #0xc
	b _080B072A
_080B0724:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080B072A:
	adds r0, r6, r0
	mov r1, sb
	strh r0, [r1, #0x1c]
	asrs r0, r6, #0x10
	strh r0, [r1, #0x1e]
	ldrh r1, [r4]
	mov r0, sl
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _080B074C
	asrs r0, r0, #0xc
	b _080B0752
_080B074C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080B0752:
	adds r0, r7, r0
	mov r5, sb
	strh r0, [r5, #0x20]
	ldrh r0, [r4]
	adds r0, #3
	mov r1, sl
	ands r0, r1
	strh r0, [r4]
	ldrh r0, [r3]
	adds r0, #5
	strh r0, [r3]
	mov r4, ip
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, ip
	ldr r1, [r2, #0x48]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r2, #0x10]
	ldrb r0, [r4, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _080B07A0
	mov r1, ip
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _080B07AC
_080B07A0:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080B07AC:
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
	beq _080B07D2
	mov r5, ip
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	str r0, [r5]
	b _080B07E0
_080B07D2:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
_080B07E0:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _080B0814 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r4, #7]
	cmp r0, r5
	blo _080B084E
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B0818
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B080E
	ldrb r0, [r4, #5]
_080B080E:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B0828
	.align 2, 0
_080B0814: .4byte 0x0000FFFF
_080B0818:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B0828
	strh r1, [r4, #8]
_080B0828:
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
	mov r3, sl
	ands r0, r3
	cmp r0, #0
	bne _080B084E
	movs r5, #1
	strb r5, [r4, #7]
_080B084E:
	mov r0, ip
	adds r0, #0x2c
	ldr r1, [sp]
	bl FUN_0822b20c
	ldr r0, [sp, #8]
	adds r0, #4
	str r0, [sp, #8]
	ldr r1, [sp, #4]
	adds r1, #1
	str r1, [sp, #4]
	cmp r1, #5
	bgt _080B086A
	b _080B05CC
_080B086A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b087c
FUN_080b087c: @ 0x080B087C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldrh r0, [r5, #0x1c]
	adds r4, r0, #0
	adds r4, #0x2c
	strh r4, [r5, #0x1c]
	ldrh r0, [r5, #0x1e]
	adds r0, #0x40
	strh r0, [r5, #0x1e]
	ldrh r0, [r5, #0x20]
	adds r3, r0, #0
	adds r3, #0x2c
	strh r3, [r5, #0x20]
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #8
	bne _080B08D4
	ldr r2, _080B0904 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080B0908 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080B090C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	subs r0, #8
	adds r1, r4, r0
	strh r1, [r5, #0x1c]
	subs r0, r3, r0
	strh r0, [r5, #0x20]
_080B08D4:
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
	beq _080B0910
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080B0918
	.align 2, 0
_080B0904: .4byte 0x030046B8
_080B0908: .4byte 0x000003FF
_080B090C: .4byte 0x0203B400
_080B0910:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B0918:
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
	beq _080B093C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080B0944
_080B093C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B0944:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B097C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B09B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B0980
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B0974
	ldrb r0, [r4, #5]
_080B0974:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B0990
	.align 2, 0
_080B097C: .4byte 0x0000FFFF
_080B0980:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B0990
	strh r1, [r4, #8]
_080B0990:
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
	bne _080B09B4
	movs r0, #1
	strb r0, [r4, #7]
_080B09B4:
	adds r0, r5, #0
	adds r0, #0x2c
	adds r1, r7, #0
	bl FUN_0822b20c
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_080b0398
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_080b05b0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b09d4
FUN_080b09d4: @ 0x080B09D4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080B0A14 @ =0x00000C6C
	adds r5, r4, r0
	adds r0, r5, #0
	bl FUN_080b02e0
	ldr r1, _080B0A18 @ =0x085AD054
	ldr r2, _080B0A1C @ =0x000012E4
	adds r0, r4, r2
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldr r0, _080B0A20 @ =0x000012F6
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _080B0A28
	ldr r1, _080B0A24 @ =0x00001292
	adds r2, r4, r1
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	b _080B0A42
	.align 2, 0
_080B0A14: .4byte 0x00000C6C
_080B0A18: .4byte 0x085AD054
_080B0A1C: .4byte 0x000012E4
_080B0A20: .4byte 0x000012F6
_080B0A24: .4byte 0x00001292
_080B0A28:
	ldr r3, _080B0A94 @ =0x00001292
	adds r2, r4, r3
	ldrh r1, [r2]
	ldr r0, _080B0A98 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080B0A9C @ =0x0000128C
	adds r0, r4, r1
	ldr r2, _080B0AA0 @ =0x00001284
	adds r1, r4, r2
	movs r2, #0
	bl FUN_082364c4
_080B0A42:
	ldr r3, _080B0AA4 @ =0x00000C0F
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B0A52
	adds r0, r5, #0
	bl FUN_080af6c4
_080B0A52:
	movs r6, #0x3e
	ldr r1, _080B0AA8 @ =0x0000135C
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080B0A84
	ldr r3, _080B0AAC @ =0x00001348
	adds r2, r4, r3
	ldr r0, _080B0AB0 @ =0x0000134A
	adds r1, r4, r0
	ldrh r0, [r2]
	ldrh r3, [r1]
	cmp r0, r3
	bhs _080B0A82
	ldrh r3, [r2]
	ldrh r0, [r1]
	subs r0, #0x5a
	cmp r3, r0
	blt _080B0A84
	lsrs r0, r3, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B0A84
_080B0A82:
	movs r6, #0x3f
_080B0A84:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_080b087c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B0A94: .4byte 0x00001292
_080B0A98: .4byte 0x0000FFFB
_080B0A9C: .4byte 0x0000128C
_080B0AA0: .4byte 0x00001284
_080B0AA4: .4byte 0x00000C0F
_080B0AA8: .4byte 0x0000135C
_080B0AAC: .4byte 0x00001348
_080B0AB0: .4byte 0x0000134A

	thumb_func_start FUN_080b0ab4
FUN_080b0ab4: @ 0x080B0AB4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl FUN_0822a4e0
	adds r4, r6, #0
	adds r4, #0x68
	movs r5, #7
_080B0AC2:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x68
	subs r5, #1
	cmp r5, #0
	bge _080B0AC2
	movs r0, #0xea
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r5, #5
_080B0AD8:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x68
	subs r5, #1
	cmp r5, #0
	bge _080B0AD8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b0aec
FUN_080b0aec: @ 0x080B0AEC
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r4, r5, r0
	ldr r2, _080B0B6C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _080B0B70 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _080B0B74 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	movs r0, #0xc3
	lsls r0, r0, #3
	adds r1, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _080B0B78 @ =FUN_080af200
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B0B6C: .4byte 0xFFFF0000
_080B0B70: .4byte 0x0000FFFF
_080B0B74: .4byte 0x00004001
_080B0B78: .4byte FUN_080af200

	thumb_func_start FUN_080b0b7c
FUN_080b0b7c: @ 0x080B0B7C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x2c
	ldr r0, _080B0BE8 @ =0x08251DD0
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl FUN_0822b16c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	movs r6, #0
	strh r6, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #7]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldr r5, _080B0BEC @ =0x0000922E
	ldr r0, _080B0BF0 @ =0x08251DD4
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl GetFile
	adds r1, r0, #0
	str r1, [r4, #0x58]
	adds r4, #0x48
	str r6, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B0BE8: .4byte 0x08251DD0
_080B0BEC: .4byte 0x0000922E
_080B0BF0: .4byte 0x08251DD4

	thumb_func_start FUN_080b0bf4
FUN_080b0bf4: @ 0x080B0BF4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	movs r0, #0
	mov r8, r0
	ldr r7, _080B0C4C @ =0x030046B8
	ldr r1, _080B0C50 @ =0x000003FF
	mov sl, r1
_080B0C0C:
	movs r0, #0x68
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	adds r0, #0x68
	mov r1, sb
	adds r5, r1, r0
	adds r6, r5, #0
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r0, _080B0C54 @ =0x08251DD0
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0822b16c
	mov r0, r8
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	beq _080B0C58
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x80
	lsls r2, r2, #2
	bl FUN_0822a470
	b _080B0C64
	.align 2, 0
_080B0C4C: .4byte 0x030046B8
_080B0C50: .4byte 0x000003FF
_080B0C54: .4byte 0x08251DD0
_080B0C58:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x80
	lsls r2, r2, #3
	bl FUN_0822a470
_080B0C64:
	movs r0, #0
	strh r0, [r5, #0x10]
	movs r1, #1
	strb r1, [r5, #7]
	movs r0, #0xc3
	lsls r0, r0, #3
	add r0, sb
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	mov r3, r8
	lsls r0, r3, #5
	adds r1, r6, #0
	adds r1, #0x66
	strh r0, [r1]
	ldr r0, [r7]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080B0D1C @ =0x0203B400
	adds r0, r0, r3
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	ldr r0, _080B0D20 @ =0x08251DD4
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080B0D24 @ =0x0000922E
	bl GetFile
	str r0, [r6, #0x58]
	ldr r0, [r7]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080B0D1C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r2, r0, #0
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r0, #0x48
	ldr r1, [r6, #0x58]
	movs r3, #0
	str r3, [sp]
	bl FUN_08236fac
	ldr r0, [r7]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080B0D1C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B0D00
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080B0D00:
	movs r3, #1
	add r8, r3
	mov r0, r8
	cmp r0, #7
	bgt _080B0D0C
	b _080B0C0C
_080B0D0C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B0D1C: .4byte 0x0203B400
_080B0D20: .4byte 0x08251DD4
_080B0D24: .4byte 0x0000922E

	thumb_func_start FUN_080b0d28
FUN_080b0d28: @ 0x080B0D28
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	movs r7, #0
	movs r0, #1
	mov sb, r0
	movs r1, #0
	mov sl, r1
_080B0D40:
	movs r0, #0x68
	muls r0, r7, r0
	movs r3, #0xea
	lsls r3, r3, #2
	adds r0, r0, r3
	mov r1, r8
	adds r5, r1, r0
	adds r6, r5, #0
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r0, _080B0D80 @ =0x08251DD0
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r7, #0
	mov r3, sb
	ands r0, r3
	cmp r0, #0
	beq _080B0D84
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x80
	lsls r2, r2, #2
	bl FUN_0822a470
	b _080B0D90
	.align 2, 0
_080B0D80: .4byte 0x08251DD0
_080B0D84:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x80
	lsls r2, r2, #3
	bl FUN_0822a470
_080B0D90:
	mov r0, sl
	strh r0, [r5, #0x10]
	cmp r7, #0
	bne _080B0D9E
	movs r0, #2
	strb r0, [r5, #7]
	b _080B0DA2
_080B0D9E:
	mov r1, sb
	strb r1, [r5, #7]
_080B0DA2:
	movs r0, #0xc3
	lsls r0, r0, #3
	add r0, r8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	lsls r0, r7, #5
	adds r1, r6, #0
	adds r1, #0x66
	strh r0, [r1]
	ldr r2, _080B0E28 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080B0E2C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080B0E30 @ =0x0203B400
	adds r0, r0, r3
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	ldr r0, _080B0E34 @ =0x08251DD4
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080B0E38 @ =0x0000922E
	bl GetFile
	adds r1, r0, #0
	str r1, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0x48
	adds r4, r7, #1
	asrs r3, r4, #1
	movs r2, #5
	subs r2, r2, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r3, sl
	str r3, [sp]
	movs r3, #0
	bl FUN_08236fac
	mov r0, sb
	ands r7, r0
	cmp r7, #0
	beq _080B0E12
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080B0E12:
	adds r7, r4, #0
	cmp r7, #5
	ble _080B0D40
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B0E28: .4byte 0x030046B8
_080B0E2C: .4byte 0x000003FF
_080B0E30: .4byte 0x0203B400
_080B0E34: .4byte 0x08251DD4
_080B0E38: .4byte 0x0000922E

	thumb_func_start FUN_080b0e3c
FUN_080b0e3c: @ 0x080B0E3C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080b0b7c
	adds r0, r4, #0
	bl FUN_080b0bf4
	adds r0, r4, #0
	bl FUN_080b0d28
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b0e58
FUN_080b0e58: @ 0x080B0E58
	ldr r2, _080B0E88 @ =0x0000069C
	adds r1, r0, r2
	movs r2, #0xa0
	strh r2, [r1]
	ldr r3, _080B0E8C @ =0x0000069E
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	ldr r2, _080B0E90 @ =0x000006A4
	adds r1, r0, r2
	movs r3, #0x40
	strh r3, [r1]
	ldr r1, _080B0E94 @ =0x000006A6
	adds r2, r0, r1
	movs r1, #0x20
	strh r1, [r2]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r0, r2
	strh r3, [r0]
	bx lr
	.align 2, 0
_080B0E88: .4byte 0x0000069C
_080B0E8C: .4byte 0x0000069E
_080B0E90: .4byte 0x000006A4
_080B0E94: .4byte 0x000006A6

	thumb_func_start FUN_080b0e98
FUN_080b0e98: @ 0x080B0E98
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r0, _080B0F1C @ =0x00000C6C
	adds r6, r7, r0
	ldr r1, _080B0F20 @ =0x000012DC
	adds r3, r7, r1
	movs r2, #0xa2
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldrh r0, [r3]
	subs r0, #0x20
	strh r0, [r3]
	movs r0, #0x97
	lsls r0, r0, #5
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0x20
	strh r0, [r1]
	ldr r1, _080B0F24 @ =0x00001284
	adds r2, r7, r1
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080B0F28 @ =0x00001286
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	ldr r4, _080B0F2C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080B0F30 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _080B0F34 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x96
	lsls r1, r1, #2
	bl Mod
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	adds r0, r6, #0
	bl FUN_080b0e3c
	movs r0, #0x4c
	bl prepare_08231510
	cmp r0, #0
	beq _080B0F38
	bl Script_GetValue
	adds r1, r0, #0
	b _080B0F3A
	.align 2, 0
_080B0F1C: .4byte 0x00000C6C
_080B0F20: .4byte 0x000012DC
_080B0F24: .4byte 0x00001284
_080B0F28: .4byte 0x00001286
_080B0F2C: .4byte 0x030046B8
_080B0F30: .4byte 0x000003FF
_080B0F34: .4byte 0x0203B400
_080B0F38:
	movs r1, #5
_080B0F3A:
	adds r0, r6, #0
	bl FUN_080b0aec
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080af374
	ldr r2, _080B1010 @ =0x0000067C
	adds r1, r6, r2
	movs r0, #0
	mov r8, r0
	movs r0, #0xa0
	strh r0, [r1]
	ldr r1, _080B1014 @ =0x0000067E
	adds r0, r6, r1
	mov r2, r8
	strh r2, [r0]
	ldr r5, _080B1018 @ =0x0203B400
	ldr r0, _080B101C @ =0x030046B8
	mov ip, r0
	ldr r1, [r0]
	adds r1, #1
	ldr r4, _080B1020 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0xf
	ands r0, r2
	adds r3, r0, #0
	adds r3, #8
	movs r0, #0xd0
	lsls r0, r0, #3
	adds r2, r6, r0
	strh r3, [r2]
	adds r1, #1
	ands r1, r4
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B0F9A
	rsbs r0, r3, #0
	strh r0, [r2]
_080B0F9A:
	mov r2, ip
	ldr r1, [r2]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r3, #0x3f
	ands r0, r3
	adds r0, #0xc0
	ldr r2, _080B1024 @ =0x00000682
	strh r0, [r2, r6]
	ldr r0, _080B1028 @ =0x0000068C
	adds r2, r6, r0
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080B102C @ =0x00000684
	adds r0, r6, r2
	mov r2, r8
	strh r2, [r0]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r0, #0xc0
	ldr r2, _080B1030 @ =0x00000686
	strh r0, [r2, r6]
	adds r1, #1
	ands r1, r4
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	ands r0, r3
	adds r0, #0x40
	adds r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0xd3
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_080b0e58
	ldr r1, _080B1034 @ =0x000006AC
	adds r0, r6, r1
	str r7, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1010: .4byte 0x0000067C
_080B1014: .4byte 0x0000067E
_080B1018: .4byte 0x0203B400
_080B101C: .4byte 0x030046B8
_080B1020: .4byte 0x000003FF
_080B1024: .4byte 0x00000682
_080B1028: .4byte 0x0000068C
_080B102C: .4byte 0x00000684
_080B1030: .4byte 0x00000686
_080B1034: .4byte 0x000006AC

	thumb_func_start FUN_080b1038
FUN_080b1038: @ 0x080B1038
	push {r4, r5, lr}
	adds r4, r2, #0
	movs r2, #0
	ldrsh r3, [r0, r2]
	movs r5, #0
	ldrsh r2, [r1, r5]
	subs r3, r3, r2
	movs r5, #4
	ldrsh r2, [r0, r5]
	movs r5, #4
	ldrsh r0, [r1, r5]
	subs r1, r2, r0
	cmp r3, r4
	bgt _080B106C
	cmp r1, r4
	bgt _080B106C
	adds r0, r3, #0
	muls r0, r3, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	adds r1, r4, #0
	muls r1, r4, r1
	cmp r0, r1
	ble _080B1070
_080B106C:
	movs r0, #0
	b _080B1072
_080B1070:
	movs r0, #1
_080B1072:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b1078
FUN_080b1078: @ 0x080B1078
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _080B10B4 @ =0x03002C00
	ldr r3, [r0]
	cmp r3, #0
	beq _080B10BC
	ldr r0, _080B10B8 @ =0x03002BE0
	ldr r2, [r0]
	ldr r0, [r2, #0x1c]
	cmp r0, #1
	bne _080B10BC
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #6
	bne _080B10BC
	adds r0, r3, #0
	adds r0, #0x48
	movs r2, #0xa2
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r2, #0x46
	bl FUN_080b1038
	cmp r0, #0
	beq _080B10BC
	movs r0, #1
	b _080B10BE
	.align 2, 0
_080B10B4: .4byte 0x03002C00
_080B10B8: .4byte 0x03002BE0
_080B10BC:
	movs r0, #0
_080B10BE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b10c4
FUN_080b10c4: @ 0x080B10C4
	push {r4, lr}
	movs r2, #0
	ldrb r1, [r0, #0x1e]
	cmp r2, r1
	bge _080B10F0
	adds r3, r1, #0
	ldr r4, _080B10E4 @ =0x00000BE8
	adds r1, r0, r4
_080B10D4:
	ldr r0, [r1]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #2
	beq _080B10E8
	movs r0, #0
	b _080B10F2
	.align 2, 0
_080B10E4: .4byte 0x00000BE8
_080B10E8:
	adds r1, #4
	adds r2, #1
	cmp r2, r3
	blt _080B10D4
_080B10F0:
	movs r0, #1
_080B10F2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b10f8
FUN_080b10f8: @ 0x080B10F8
	push {lr}
	adds r1, r0, #0
	ldr r0, _080B113C @ =0x03002BE0
	ldr r2, [r0]
	ldr r0, [r2, #0x1c]
	cmp r0, #1
	bne _080B1140
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _080B1140
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #7
	bne _080B1140
	adds r0, r2, #0
	adds r0, #0x2c
	movs r2, #0xa1
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r2, #0x64
	bl FUN_080b1038
	cmp r0, #0
	beq _080B1140
	movs r0, #1
	b _080B1142
	.align 2, 0
_080B113C: .4byte 0x03002BE0
_080B1140:
	movs r0, #0
_080B1142:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080b1148
FUN_080b1148: @ 0x080B1148
	push {lr}
	adds r1, r0, #0
	ldr r0, _080B1168 @ =0x03002C00
	ldr r0, [r0]
	adds r0, #0x48
	movs r2, #0xa2
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r2, #0xc8
	lsls r2, r2, #2
	bl FUN_080b1038
	cmp r0, #0
	bne _080B116C
	movs r0, #1
	b _080B116E
	.align 2, 0
_080B1168: .4byte 0x03002C00
_080B116C:
	movs r0, #0
_080B116E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080b1174
FUN_080b1174: @ 0x080B1174
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	bl FUN_080b1078
	cmp r0, #0
	beq _080B11A4
	ldr r0, _080B11AC @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #1
	rsbs r2, r2, #0
	movs r4, #0
	str r4, [sp]
	movs r1, #0
	movs r3, #0
	bl FUN_0807bb3c
	ldr r1, _080B11B0 @ =0x00000C16
	adds r0, r5, r1
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ad1ec
_080B11A4:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B11AC: .4byte 0x03002BE0
_080B11B0: .4byte 0x00000C16

	thumb_func_start FUN_080b11b4
FUN_080b11b4: @ 0x080B11B4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _080B125C @ =0x000004FE
	adds r0, r0, r7
	mov sb, r0
	ldrh r0, [r0]
	adds r0, #1
	mov r1, sb
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #5
	bhi _080B127C
	mov r2, sb
	ldrh r0, [r2]
	movs r4, #6
	subs r4, r4, r0
	ldr r5, _080B1260 @ =0x03002C00
	ldr r0, [r5]
	adds r0, #0x48
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r6, r4, #1
	muls r0, r6, r0
	movs r2, #0xa2
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080B1264 @ =0xFFFF0000
	mov r8, r1
	ldr r1, [sp]
	mov r2, r8
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldr r0, [r5]
	adds r0, #0x4c
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	ldr r2, _080B1268 @ =0x00000514
	adds r1, r7, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	mov r2, r8
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	ldr r0, [r5]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r2, [r0]
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B1272
	adds r0, r2, #0
	cmp r0, #0
	beq _080B1272
	cmp r0, #4
	bls _080B126C
	adds r2, #1
	b _080B126E
	.align 2, 0
_080B125C: .4byte 0x000004FE
_080B1260: .4byte 0x03002C00
_080B1264: .4byte 0xFFFF0000
_080B1268: .4byte 0x00000514
_080B126C:
	subs r2, #1
_080B126E:
	movs r0, #7
	ands r2, r0
_080B1272:
	mov r0, sp
	adds r1, r2, #0
	bl FUN_08086590
	b _080B13E6
_080B127C:
	cmp r1, #6
	bne _080B12C4
	ldr r1, _080B12BC @ =0x03002C00
	ldr r0, [r1]
	ldr r3, _080B12C0 @ =0x000001F5
	adds r2, r0, r3
	movs r0, #0xb
	strb r0, [r2]
	ldr r2, [r1]
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #0x48]
	str r1, [r2, #0x4c]
	adds r3, #0xb
	adds r2, r2, r3
	movs r0, #0
	strb r0, [r2]
	movs r0, #0x95
	lsls r0, r0, #2
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xf9
	bl PlaySound_082406e0
	b _080B13E6
	.align 2, 0
_080B12BC: .4byte 0x03002C00
_080B12C0: .4byte 0x000001F5
_080B12C4:
	cmp r1, #0x45
	bhi _080B1304
	ldr r2, _080B12F8 @ =0x00000C16
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #2
	beq _080B12E6
	cmp r1, #0x14
	bne _080B12E6
	ldr r1, _080B12FC @ =FUN_080adb5c
	adds r0, r7, #0
	bl FUN_080ad9f4
	movs r0, #0x93
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080B12E6:
	ldr r3, _080B1300 @ =0x000004FE
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r0, #0x46
	subs r0, r0, r1
	asrs r0, r0, #1
	bl FUN_0823b9cc
	b _080B13E6
	.align 2, 0
_080B12F8: .4byte 0x00000C16
_080B12FC: .4byte FUN_080adb5c
_080B1300: .4byte 0x000004FE
_080B1304:
	ldr r1, _080B1348 @ =0x00000C16
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B1354
	movs r4, #0
	ldrb r2, [r7, #0x1e]
	cmp r0, r2
	bge _080B132A
	ldr r3, _080B134C @ =0x00000BE8
	adds r5, r7, r3
_080B131A:
	ldm r5!, {r0}
	movs r1, #1
	bl FUN_080b283c
	adds r4, #1
	ldrb r0, [r7, #0x1e]
	cmp r4, r0
	blt _080B131A
_080B132A:
	ldr r0, _080B1350 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	bl FUN_0807b910
	movs r0, #0xfa
	bl PlaySound_082406e0
	adds r0, r7, #0
	movs r1, #2
	bl FUN_080ad1ec
	b _080B13E6
	.align 2, 0
_080B1348: .4byte 0x00000C16
_080B134C: .4byte 0x00000BE8
_080B1350: .4byte 0x03002BE0
_080B1354:
	cmp r0, #1
	bne _080B13AE
	ldr r4, _080B139C @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #1
	rsbs r1, r1, #0
	bl FUN_0807b910
	ldr r0, [r4]
	bl FUN_0807d118
	movs r3, #0
	ldrb r0, [r7, #0x1e]
	cmp r3, r0
	bge _080B138C
	ldr r1, _080B13A0 @ =0x00000BE8
	adds r2, r7, r1
	adds r1, r0, #0
_080B1378:
	ldr r0, [r2]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B1384
	movs r3, #1
_080B1384:
	adds r2, #4
	subs r1, #1
	cmp r1, #0
	bne _080B1378
_080B138C:
	cmp r3, #0
	beq _080B13A4
	adds r0, r7, #0
	movs r1, #4
	bl FUN_080ad1ec
	b _080B13E6
	.align 2, 0
_080B139C: .4byte 0x03002BE0
_080B13A0: .4byte 0x00000BE8
_080B13A4:
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ad1ec
	b _080B13E6
_080B13AE:
	ldr r4, _080B13F4 @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #1
	rsbs r1, r1, #0
	bl FUN_0807b910
	ldr r0, [r4]
	bl FUN_0807d118
	movs r0, #0xf5
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, _080B13F8 @ =0x03002C00
	ldr r0, [r0]
	ldr r2, _080B13FC @ =0x000001F5
	adds r1, r0, r2
	movs r0, #0xd
	strb r0, [r1]
	ldr r3, _080B1400 @ =0x00000C6C
	adds r0, r7, r3
	movs r1, #1
	bl FUN_080af374
	adds r0, r7, #0
	movs r1, #0xa
	bl FUN_080ad1ec
_080B13E6:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B13F4: .4byte 0x03002BE0
_080B13F8: .4byte 0x03002C00
_080B13FC: .4byte 0x000001F5
_080B1400: .4byte 0x00000C6C

	thumb_func_start FUN_080b1404
FUN_080b1404: @ 0x080B1404
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080b10c4
	cmp r0, #0
	beq _080B1428
	ldr r0, _080B1430 @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807d118
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080ad1ec
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ad204
_080B1428:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B1430: .4byte 0x03002BE0

	thumb_func_start FUN_080b1434
FUN_080b1434: @ 0x080B1434
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _080B147C @ =0x03002C00
	ldr r0, [r0]
	ldr r1, _080B1480 @ =0x000001F5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xb
	beq _080B1474
	adds r0, r4, #0
	bl FUN_080b1078
	cmp r0, #0
	beq _080B1474
	ldr r0, _080B1484 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	str r1, [sp]
	movs r3, #0
	bl FUN_0807bb3c
	ldr r5, _080B1488 @ =0x00000C16
	adds r1, r4, r5
	movs r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ad1ec
_080B1474:
	movs r2, #0
	ldrb r3, [r4, #0x1e]
	b _080B148E
	.align 2, 0
_080B147C: .4byte 0x03002C00
_080B1480: .4byte 0x000001F5
_080B1484: .4byte 0x03002BE0
_080B1488: .4byte 0x00000C16
_080B148C:
	adds r2, #1
_080B148E:
	cmp r2, r3
	bge _080B14AC
	lsls r1, r2, #2
	ldr r5, _080B14B4 @ =0x00000BE8
	adds r0, r4, r5
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B148C
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080ad1ec
_080B14AC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B14B4: .4byte 0x00000BE8

	thumb_func_start FUN_080b14b8
FUN_080b14b8: @ 0x080B14B8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r7, #0
	movs r6, #0
	ldrb r0, [r4, #0x1e]
	cmp r7, r0
	bge _080B1506
_080B14C6:
	lsls r0, r6, #2
	ldr r2, _080B1560 @ =0x00000BE8
	adds r1, r4, r2
	adds r5, r1, r0
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B14FE
	adds r7, #1
	adds r0, r1, #0
	adds r0, #0xec
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B14FE
	movs r0, #0x93
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	ldr r1, _080B1564 @ =FUN_080adb5c
	bl FUN_080ad9f4
	ldr r0, [r5]
	adds r0, #0xec
	movs r1, #0
	strb r1, [r0]
_080B14FE:
	adds r6, #1
	ldrb r0, [r4, #0x1e]
	cmp r6, r0
	blt _080B14C6
_080B1506:
	ldr r2, _080B1568 @ =0x00001332
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _080B1522
	ldrb r0, [r4, #0x1e]
	cmp r7, r0
	blt _080B1522
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ad204
_080B1522:
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080B1536
	ldr r1, _080B156C @ =FUN_080adce4
	adds r0, r4, #0
	bl FUN_080ad9f4
_080B1536:
	adds r0, r4, #0
	bl FUN_080b10f8
	cmp r0, #0
	beq _080B155A
	ldr r0, _080B1570 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0xa1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080ad1ec
_080B155A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1560: .4byte 0x00000BE8
_080B1564: .4byte FUN_080adb5c
_080B1568: .4byte 0x00001332
_080B156C: .4byte FUN_080adce4
_080B1570: .4byte 0x03002BE0

	thumb_func_start FUN_080b1574
FUN_080b1574: @ 0x080B1574
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r6, _080B1620 @ =0x03002BE0
	ldr r5, [r6]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B1650
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r2, #0x2c
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x10
	ldr r3, _080B1624 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	ldr r7, _080B1628 @ =0x00000502
	adds r0, r4, r7
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r7, #0x2e
	ldrsh r1, [r5, r7]
	adds r0, r0, r1
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x10
	lsls r0, r0, #0x10
	ldr r1, _080B162C @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldr r1, _080B1630 @ =0x00000504
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r1, r0, #1
	adds r1, r1, r0
	movs r7, #0x30
	ldrsh r0, [r5, r7]
	adds r1, r1, r0
	lsls r1, r1, #0xe
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	movs r0, #0x10
	mov r1, sp
	bl FUN_0823bb7c
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B1638
	ldr r0, [r6]
	movs r1, #1
	movs r2, #0
	bl FUN_0807bbb0
	movs r0, #5
	bl PlaySound_082406e0
	ldr r1, _080B1634 @ =FUN_080ada44
	adds r0, r4, #0
	bl FUN_080ad9f4
	adds r0, r4, #0
	movs r1, #7
	bl FUN_080ad1ec
	b _080B1650
	.align 2, 0
_080B1620: .4byte 0x03002BE0
_080B1624: .4byte 0xFFFF0000
_080B1628: .4byte 0x00000502
_080B162C: .4byte 0x0000FFFF
_080B1630: .4byte 0x00000504
_080B1634: .4byte FUN_080ada44
_080B1638:
	ldr r0, [r6]
	movs r1, #0
	movs r2, #0
	bl FUN_0807bbb0
	ldr r0, _080B1658 @ =0x00000197
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #6
	bl FUN_080ad1ec
_080B1650:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1658: .4byte 0x00000197

	thumb_func_start FUN_080b165c
FUN_080b165c: @ 0x080B165C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080B16B0 @ =0x000004FE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	bne _080B16BC
	movs r4, #0
	ldrb r2, [r5, #0x1e]
	cmp r4, r2
	bge _080B169E
_080B167A:
	lsls r0, r4, #2
	ldr r2, _080B16B4 @ =0x00000BE8
	adds r1, r5, r2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r1, #0
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B1696
	adds r0, r1, #0
	movs r1, #5
	bl FUN_080b283c
_080B1696:
	adds r4, #1
	ldrb r0, [r5, #0x1e]
	cmp r4, r0
	blt _080B167A
_080B169E:
	ldr r1, _080B16B8 @ =FUN_080adb5c
	adds r0, r5, #0
	bl FUN_080ad9f4
	movs r0, #4
	bl sound_fadeout_08240440
	b _080B170A
	.align 2, 0
_080B16B0: .4byte 0x000004FE
_080B16B4: .4byte 0x00000BE8
_080B16B8: .4byte FUN_080adb5c
_080B16BC:
	cmp r0, #0x5a
	bne _080B16D8
	movs r0, #0x10
	bl FUN_0823bca8
	ldr r0, _080B16D4 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0
	bl FUN_0807bc64
	b _080B170A
	.align 2, 0
_080B16D4: .4byte 0x03002BE0
_080B16D8:
	cmp r0, #0x69
	bls _080B170A
	ldr r0, _080B1710 @ =0x03002BE0
	ldr r1, [r0]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B170A
	adds r0, r1, #0
	bl FUN_0807d118
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080ad1ec
	ldr r0, _080B1714 @ =0x00001332
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080ad204
_080B170A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B1710: .4byte 0x03002BE0
_080B1714: .4byte 0x00001332

	thumb_func_start FUN_080b1718
FUN_080b1718: @ 0x080B1718
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B1760 @ =0x000004FE
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x45
	bhi _080B173A
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x46
	bne _080B173A
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080ad204
_080B173A:
	ldr r1, _080B1764 @ =0x00001333
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B175A
	ldr r0, _080B1768 @ =0x00001334
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _080B1752
	adds r0, #1
	strh r0, [r1]
_080B1752:
	ldrh r0, [r1]
	lsrs r0, r0, #1
	bl FUN_0823b9cc
_080B175A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B1760: .4byte 0x000004FE
_080B1764: .4byte 0x00001333
_080B1768: .4byte 0x00001334

	thumb_func_start FUN_080b176c
FUN_080b176c: @ 0x080B176C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B1780 @ =0x000004FE
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _080B1784
	adds r0, #1
	strh r0, [r1]
	b _080B17AA
	.align 2, 0
_080B1780: .4byte 0x000004FE
_080B1784:
	ldr r1, _080B17B0 @ =0x00000C12
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B17AA
	movs r0, #0xf5
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, _080B17B4 @ =0x03002C00
	ldr r0, [r0]
	ldr r2, _080B17B8 @ =0x000001F5
	adds r1, r0, r2
	movs r0, #0xd
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #9
	bl FUN_080ad1ec
_080B17AA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B17B0: .4byte 0x00000C12
_080B17B4: .4byte 0x03002C00
_080B17B8: .4byte 0x000001F5

	thumb_func_start FUN_080b17bc
FUN_080b17bc: @ 0x080B17BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B17E8 @ =0x03002C00
	ldr r0, [r0]
	ldr r1, _080B17EC @ =0x000001F5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xc
	bne _080B17E0
	ldr r1, _080B17F0 @ =0x00000C6C
	adds r0, r4, r1
	movs r1, #1
	bl FUN_080af374
	adds r0, r4, #0
	movs r1, #0xa
	bl FUN_080ad1ec
_080B17E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B17E8: .4byte 0x03002C00
_080B17EC: .4byte 0x000001F5
_080B17F0: .4byte 0x00000C6C

	thumb_func_start FUN_080b17f4
FUN_080b17f4: @ 0x080B17F4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r3, _080B184C @ =0x030046A0
	cmp r0, #0
	beq _080B1828
	ldrb r0, [r4, #0x1e]
	cmp r5, r0
	bge _080B1828
	subs r1, #0x28
	adds r2, r4, r1
	adds r1, r0, #0
_080B1814:
	ldr r0, [r2]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B1820
	movs r5, #1
_080B1820:
	adds r2, #4
	subs r1, #1
	cmp r1, #0
	bne _080B1814
_080B1828:
	ldr r0, [r3]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	ble _080B183C
	adds r0, r4, #0
	bl FUN_080af0ac
_080B183C:
	cmp r5, #0
	beq _080B1854
	ldr r0, _080B1850 @ =0x000004FE
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	b _080B1878
	.align 2, 0
_080B184C: .4byte 0x030046A0
_080B1850: .4byte 0x000004FE
_080B1854:
	ldr r0, _080B1880 @ =0x000004FE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _080B1878
	ldr r1, _080B1884 @ =0x00000C6C
	adds r0, r4, r1
	movs r1, #6
	bl FUN_080af374
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_080ad1ec
_080B1878:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B1880: .4byte 0x000004FE
_080B1884: .4byte 0x00000C6C

	thumb_func_start FUN_080b1888
FUN_080b1888: @ 0x080B1888
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B18BC @ =0x000012E4
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B18B6
	ldr r0, _080B18C0 @ =0x000001EB
	bl PlaySound_082406e0
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_08086b18
	adds r0, r4, #0
	movs r1, #0xc
	bl FUN_080ad1ec
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080ad204
_080B18B6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B18BC: .4byte 0x000012E4
_080B18C0: .4byte 0x000001EB

	thumb_func_start FUN_080b18c4
FUN_080b18c4: @ 0x080B18C4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	bl FUN_080b1078
	cmp r0, #0
	beq _080B1900
	ldr r0, _080B18F8 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	str r1, [sp]
	movs r3, #0
	bl FUN_0807bb3c
	ldr r0, _080B18FC @ =0x00000C16
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ad1ec
	b _080B19B2
	.align 2, 0
_080B18F8: .4byte 0x03002BE0
_080B18FC: .4byte 0x00000C16
_080B1900:
	adds r0, r5, #0
	bl FUN_080b1148
	cmp r0, #0
	beq _080B19B2
	ldr r0, _080B1960 @ =0x03002C00
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x48
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r6, _080B1964 @ =0x03002BE0
	ldr r4, [r6]
	movs r3, #0x2c
	ldrsh r0, [r4, r3]
	subs r2, r2, r0
	adds r1, #0x4c
	movs r0, #0
	ldrsh r1, [r1, r0]
	movs r3, #0x30
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #1
	bls _080B193C
	cmp r0, #5
	bne _080B1968
_080B193C:
	adds r0, r2, #0
	bl FUN_0823785c
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #5
	adds r1, #3
	movs r0, #7
	ands r1, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0807b9dc
	b _080B1990
	.align 2, 0
_080B1960: .4byte 0x03002C00
_080B1964: .4byte 0x03002BE0
_080B1968:
	adds r0, r2, #0
	bl FUN_0823785c
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #5
	adds r1, #3
	movs r0, #7
	ands r1, r0
	adds r0, r4, #0
	bl FUN_0807b910
	ldr r0, [r6]
	movs r1, #0
	bl FUN_0807cc84
_080B1990:
	ldr r4, _080B19BC @ =0x03002C00
	ldr r0, [r4]
	bl FUN_0808613c
	ldr r1, [r4]
	adds r1, #0x48
	movs r0, #0x10
	bl FUN_0823bb7c
	adds r0, r5, #0
	movs r1, #0xd
	bl FUN_080ad1ec
	adds r0, r5, #0
	movs r1, #6
	bl FUN_080ad204
_080B19B2:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B19BC: .4byte 0x03002C00

	thumb_func_start FUN_080b19c0
FUN_080b19c0: @ 0x080B19C0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _080B1A70 @ =0x000004FE
	adds r5, r6, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x21
	bne _080B1A16
	ldr r0, _080B1A74 @ =0x03002C00
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, _080B1A78 @ =0x03002BE0
	ldr r4, [r1]
	movs r3, #0x2c
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	adds r2, #0x4c
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r3, #0x30
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #5
	adds r1, #3
	movs r0, #7
	ands r1, r0
	adds r0, r4, #0
	bl FUN_0807b910
_080B1A16:
	ldrh r0, [r5]
	cmp r0, #0x40
	bne _080B1A22
	ldr r0, _080B1A7C @ =0x000001C5
	bl PlaySound_082406e0
_080B1A22:
	ldrh r0, [r5]
	cmp r0, #0xf0
	bne _080B1A34
	ldr r0, _080B1A78 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	movs r0, #0x10
	bl FUN_0823bb7c
_080B1A34:
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne _080B1A56
	ldr r1, _080B1A80 @ =0x00001346
	adds r0, r6, r1
	ldrh r0, [r0]
	bl PlaySound_082406e0
	ldr r0, _080B1A78 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	movs r2, #0
	bl FUN_0807bcb0
_080B1A56:
	ldrh r1, [r5]
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	bne _080B1A68
	adds r0, r6, #0
	movs r1, #7
	bl FUN_080ad204
_080B1A68:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B1A70: .4byte 0x000004FE
_080B1A74: .4byte 0x03002C00
_080B1A78: .4byte 0x03002BE0
_080B1A7C: .4byte 0x000001C5
_080B1A80: .4byte 0x00001346

	thumb_func_start FUN_080b1a84
FUN_080b1a84: @ 0x080B1A84
	bx lr
	.align 2, 0

	thumb_func_start FUN_080b1a88
FUN_080b1a88: @ 0x080B1A88
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r1, _080B1B14 @ =0x00000C0F
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B1B0A
	movs r2, #0x95
	lsls r2, r2, #2
	adds r4, r6, r2
	mov r8, r4
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r5, r6, r0
	ldr r1, _080B1B18 @ =0x0000C039
	adds r0, r5, #0
	bl FUN_0822b16c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #3
	strb r0, [r4, #7]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0822b234
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r7, r6, r1
	ldr r2, [r5, #0xc]
	adds r1, r7, #0
	movs r3, #0xf
_080B1AD2:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _080B1AD2
	str r7, [r5, #0xc]
	adds r0, r4, #0
	adds r0, #0x6a
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r2, r8
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #1
	strh r0, [r1]
_080B1B0A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1B14: .4byte 0x00000C0F
_080B1B18: .4byte 0x0000C039

	thumb_func_start FUN_080b1b1c
FUN_080b1b1c: @ 0x080B1B1C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa3
	lsls r0, r0, #3
	adds r4, r5, r0
	adds r0, #0x2c
	adds r6, r5, r0
	ldr r1, _080B1B70 @ =0x00003641
	adds r0, r6, #0
	bl FUN_0822b16c
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_0822a470
	movs r0, #0
	strh r0, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #2
	orrs r0, r1
	str r0, [r4]
	movs r0, #0x60
	strb r0, [r4, #9]
	strb r0, [r4, #8]
	movs r0, #1
	strb r0, [r4, #7]
	movs r0, #0xa2
	lsls r0, r0, #3
	adds r5, r5, r0
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldrh r0, [r4, #0x1e]
	adds r0, #0x48
	strh r0, [r4, #0x1e]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B1B70: .4byte 0x00003641

	thumb_func_start FUN_080b1b74
FUN_080b1b74: @ 0x080B1B74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	mov r8, r0
	ldrh r0, [r0, #0x1a]
	movs r1, #0
	str r1, [sp, #0x30]
	cmp r0, #1
	bne _080B1B90
	movs r2, #1
	str r2, [sp, #0x30]
_080B1B90:
	movs r0, #0x67
	bl prepare_08231510
	cmp r0, #0
	bne _080B1BA4
	movs r3, #0x64
	str r3, [sp, #0x28]
	movs r4, #0
	str r4, [sp, #0x2c]
	b _080B1BB0
_080B1BA4:
	bl Script_GetValue
	str r0, [sp, #0x28]
	bl Script_GetValue
	str r0, [sp, #0x2c]
_080B1BB0:
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	bne _080B1BE0
	movs r7, #0
	mov r0, r8
	ldrb r0, [r0, #0x1e]
	cmp r7, r0
	bge _080B1C04
	movs r0, #0
	add r2, sp, #0x10
	ldr r1, _080B1BDC @ =0x00000BE8
	add r1, r8
_080B1BCC:
	stm r1!, {r0}
	stm r2!, {r0}
	adds r7, #1
	mov r3, r8
	ldrb r3, [r3, #0x1e]
	cmp r7, r3
	blt _080B1BCC
	b _080B1C04
	.align 2, 0
_080B1BDC: .4byte 0x00000BE8
_080B1BE0:
	movs r7, #0
	mov r4, r8
	ldrb r4, [r4, #0x1e]
	cmp r7, r4
	bge _080B1C04
	add r5, sp, #0x10
	ldr r4, _080B1C38 @ =0x00000BE8
	add r4, r8
_080B1BF0:
	movs r0, #0
	stm r4!, {r0}
	bl Script_GetValue
	stm r5!, {r0}
	adds r7, #1
	mov r0, r8
	ldrb r0, [r0, #0x1e]
	cmp r7, r0
	blt _080B1BF0
_080B1C04:
	movs r7, #0
	mov r1, r8
	ldrb r1, [r1, #0x1e]
	cmp r7, r1
	blt _080B1C10
	b _080B1D48
_080B1C10:
	ldr r2, _080B1C3C @ =0xFFFFFDFE
	mov sl, r2
	add r5, sp, #0x20
	ldr r3, _080B1C40 @ =0xFFFF0000
	mov sb, r3
_080B1C1A:
	movs r0, #0xa0
	lsls r0, r0, #3
	add r0, r8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	cmp r7, #1
	beq _080B1CD4
	cmp r7, #1
	bgt _080B1C44
	cmp r7, #0
	beq _080B1C4E
	b _080B1D08
	.align 2, 0
_080B1C38: .4byte 0x00000BE8
_080B1C3C: .4byte 0xFFFFFDFE
_080B1C40: .4byte 0xFFFF0000
_080B1C44:
	cmp r7, #2
	beq _080B1C7A
	cmp r7, #3
	beq _080B1CA6
	b _080B1D08
_080B1C4E:
	ldrh r1, [r5]
	add r1, sl
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x20]
	mov r4, sb
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r5, #4]
	adds r1, #0x4c
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #1
	mov ip, r0
	movs r6, #0
	movs r2, #6
	b _080B1D10
_080B1C7A:
	ldrh r1, [r5]
	adds r1, #0x4c
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x20]
	mov r2, sb
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r5, #4]
	add r1, sl
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	movs r3, #1
	mov ip, r3
	movs r6, #1
	movs r2, #3
	b _080B1D10
_080B1CA6:
	ldrh r1, [r5]
	subs r1, #0x4c
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x20]
	mov r4, sb
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r5, #4]
	ldr r0, _080B1CD0 @ =0x00000202
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r5, #4]
	movs r1, #0
	mov ip, r1
	b _080B1D0C
	.align 2, 0
_080B1CD0: .4byte 0x00000202
_080B1CD4:
	ldrh r1, [r5]
	ldr r2, _080B1D04 @ =0x00000202
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x20]
	mov r3, sb
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r5, #4]
	subs r1, #0x4c
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r5, #4]
	movs r4, #0
	mov ip, r4
	movs r6, #1
	movs r2, #9
	b _080B1D10
	.align 2, 0
_080B1D04: .4byte 0x00000202
_080B1D08:
	movs r0, #0
	mov ip, r0
_080B1D0C:
	movs r6, #0
	movs r2, #0
_080B1D10:
	add r1, sp, #0x20
	lsls r4, r7, #2
	mov r0, sp
	adds r0, r0, r4
	adds r0, #0x10
	ldr r3, [r0]
	ldr r0, [sp, #0x30]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	str r0, [sp, #4]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	adds r0, r1, #0
	mov r1, ip
	adds r2, r6, #0
	bl FUN_080b3898
	ldr r1, _080B1D58 @ =0x00000BE8
	add r1, r8
	adds r1, r1, r4
	str r0, [r1]
	adds r7, #1
	mov r1, r8
	ldrb r1, [r1, #0x1e]
	cmp r7, r1
	bge _080B1D48
	b _080B1C1A
_080B1D48:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1D58: .4byte 0x00000BE8

	thumb_func_start FUN_080b1d5c
FUN_080b1d5c: @ 0x080B1D5C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _080B1D8A
	bl Script_GetValue
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r1, r4, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r5, _080B1DD8 @ =0x00000502
	adds r1, r4, r5
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080B1DDC @ =0x00000504
	adds r1, r4, r2
	strh r0, [r1]
_080B1D8A:
	movs r5, #0xa1
	lsls r5, r5, #3
	adds r2, r4, r5
	movs r0, #0xa0
	lsls r0, r0, #3
	adds r3, r4, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r5, [r2]
	adds r1, r0, r5
	strh r1, [r2]
	ldr r2, _080B1DE0 @ =0x0000050C
	adds r1, r4, r2
	ldrh r5, [r1]
	adds r0, r0, r5
	strh r0, [r1]
	movs r0, #0xa2
	lsls r0, r0, #3
	adds r2, r4, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r2, _080B1DE4 @ =0x00000514
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #0x14
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B1DD8: .4byte 0x00000502
_080B1DDC: .4byte 0x00000504
_080B1DE0: .4byte 0x0000050C
_080B1DE4: .4byte 0x00000514

	thumb_func_start FUN_080b1de8
FUN_080b1de8: @ 0x080B1DE8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080B1E08
	bl Script_GetValue
	ldr r2, _080B1E04 @ =0x000017A4
	adds r1, r4, r2
	str r0, [r1]
	b _080B1E0E
	.align 2, 0
_080B1E04: .4byte 0x000017A4
_080B1E08:
	ldr r2, _080B1E14 @ =0x000017A4
	adds r0, r4, r2
	str r1, [r0]
_080B1E0E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B1E14: .4byte 0x000017A4

	thumb_func_start FUN_080b1e18
FUN_080b1e18: @ 0x080B1E18
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x62
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080B1E5C
	bl Script_GetValue
	ldr r2, _080B1E54 @ =0x00001336
	adds r1, r5, r2
	strb r0, [r1]
	bl Script_GetValue
	ldr r4, _080B1E58 @ =0x030046A0
	ldr r1, [r4]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r1, r2
	str r0, [r1]
	bl Script_GetValue
	ldr r1, [r4]
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r1, r2
	str r0, [r1]
	b _080B1E7A
	.align 2, 0
_080B1E54: .4byte 0x00001336
_080B1E58: .4byte 0x030046A0
_080B1E5C:
	ldr r2, _080B1E9C @ =0x00001336
	adds r0, r5, r2
	strb r1, [r0]
	ldr r2, _080B1EA0 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, _080B1EA4 @ =0x00001770
	str r1, [r0]
	ldr r0, [r2]
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r0, r0, r2
	str r1, [r0]
_080B1E7A:
	ldr r0, _080B1EA0 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r0, r2
	adds r2, #4
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #2
	ldr r1, [r1]
	cmp r1, r0
	ble _080B1EAC
	ldr r0, _080B1EA8 @ =0x0000133F
	adds r1, r5, r0
	movs r0, #0
	b _080B1EB2
	.align 2, 0
_080B1E9C: .4byte 0x00001336
_080B1EA0: .4byte 0x030046A0
_080B1EA4: .4byte 0x00001770
_080B1EA8: .4byte 0x0000133F
_080B1EAC:
	ldr r2, _080B1ECC @ =0x0000133F
	adds r1, r5, r2
	movs r0, #1
_080B1EB2:
	strb r0, [r1]
	ldr r1, _080B1ED0 @ =0x00001336
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _080B1EC0
	b _080B2022
_080B1EC0:
	lsls r0, r0, #2
	ldr r1, _080B1ED4 @ =_080B1ED8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B1ECC: .4byte 0x0000133F
_080B1ED0: .4byte 0x00001336
_080B1ED4: .4byte _080B1ED8
_080B1ED8: @ jump table
	.4byte _080B1EF0 @ case 0
	.4byte _080B1F28 @ case 1
	.4byte _080B1F5C @ case 2
	.4byte _080B1F94 @ case 3
	.4byte _080B1FC8 @ case 4
	.4byte _080B2000 @ case 5
_080B1EF0:
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r5, r2
	ldr r0, _080B1F14 @ =0x0000023F
	strh r0, [r1]
	ldr r0, _080B1F18 @ =0x00001342
	adds r1, r5, r0
	ldr r0, _080B1F1C @ =0x00000245
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	adds r0, #0xd
	strh r0, [r1]
	ldr r0, _080B1F20 @ =0x00001346
	adds r1, r5, r0
	ldr r0, _080B1F24 @ =0x0000024B
	b _080B2020
	.align 2, 0
_080B1F14: .4byte 0x0000023F
_080B1F18: .4byte 0x00001342
_080B1F1C: .4byte 0x00000245
_080B1F20: .4byte 0x00001346
_080B1F24: .4byte 0x0000024B
_080B1F28:
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r5, r2
	movs r0, #0x90
	lsls r0, r0, #2
	strh r0, [r1]
	ldr r0, _080B1F50 @ =0x00001342
	adds r1, r5, r0
	ldr r0, _080B1F54 @ =0x00000246
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	adds r0, #0xd
	strh r0, [r1]
	ldr r0, _080B1F58 @ =0x00001346
	adds r1, r5, r0
	movs r0, #0x93
	lsls r0, r0, #2
	b _080B2020
	.align 2, 0
_080B1F50: .4byte 0x00001342
_080B1F54: .4byte 0x00000246
_080B1F58: .4byte 0x00001346
_080B1F5C:
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r5, r2
	ldr r0, _080B1F80 @ =0x00000241
	strh r0, [r1]
	ldr r0, _080B1F84 @ =0x00001342
	adds r1, r5, r0
	ldr r0, _080B1F88 @ =0x00000247
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	adds r0, #0xd
	strh r0, [r1]
	ldr r0, _080B1F8C @ =0x00001346
	adds r1, r5, r0
	ldr r0, _080B1F90 @ =0x0000024D
	b _080B2020
	.align 2, 0
_080B1F80: .4byte 0x00000241
_080B1F84: .4byte 0x00001342
_080B1F88: .4byte 0x00000247
_080B1F8C: .4byte 0x00001346
_080B1F90: .4byte 0x0000024D
_080B1F94:
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r5, r2
	ldr r0, _080B1FB8 @ =0x00000242
	strh r0, [r1]
	ldr r0, _080B1FBC @ =0x00001342
	adds r1, r5, r0
	movs r0, #0x92
	lsls r0, r0, #2
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	adds r0, #0xd
	strh r0, [r1]
	ldr r0, _080B1FC0 @ =0x00001346
	adds r1, r5, r0
	ldr r0, _080B1FC4 @ =0x0000024E
	b _080B2020
	.align 2, 0
_080B1FB8: .4byte 0x00000242
_080B1FBC: .4byte 0x00001342
_080B1FC0: .4byte 0x00001346
_080B1FC4: .4byte 0x0000024E
_080B1FC8:
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r5, r2
	ldr r0, _080B1FEC @ =0x00000243
	strh r0, [r1]
	ldr r0, _080B1FF0 @ =0x00001342
	adds r1, r5, r0
	ldr r0, _080B1FF4 @ =0x00000249
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	adds r0, #0xd
	strh r0, [r1]
	ldr r0, _080B1FF8 @ =0x00001346
	adds r1, r5, r0
	ldr r0, _080B1FFC @ =0x0000024F
	b _080B2020
	.align 2, 0
_080B1FEC: .4byte 0x00000243
_080B1FF0: .4byte 0x00001342
_080B1FF4: .4byte 0x00000249
_080B1FF8: .4byte 0x00001346
_080B1FFC: .4byte 0x0000024F
_080B2000:
	movs r1, #0x9a
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r1, #0x91
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r2, _080B2038 @ =0x00001342
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _080B203C @ =0x00001344
	adds r1, r5, r0
	ldr r0, _080B2040 @ =0x00000257
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	subs r0, #7
_080B2020:
	strh r0, [r1]
_080B2022:
	movs r0, #0x54
	bl prepare_08231510
	cmp r0, #0
	beq _080B2048
	bl Script_GetValue
	ldr r2, _080B2044 @ =0x0000134E
	adds r1, r5, r2
	b _080B204E
	.align 2, 0
_080B2038: .4byte 0x00001342
_080B203C: .4byte 0x00001344
_080B2040: .4byte 0x00000257
_080B2044: .4byte 0x0000134E
_080B2048:
	ldr r0, _080B205C @ =0x0000134E
	adds r1, r5, r0
	movs r0, #0xa
_080B204E:
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080af0f8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B205C: .4byte 0x0000134E

	thumb_func_start FUN_080b2060
FUN_080b2060: @ 0x080B2060
	push {r4, lr}
	movs r2, #0
	ldrb r1, [r0, #0x1e]
	cmp r2, r1
	bge _080B208C
	adds r3, r1, #0
	ldr r4, _080B2080 @ =0x00000BE8
	adds r1, r0, r4
_080B2070:
	ldr r0, [r1]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B2084
	movs r0, #0
	b _080B208E
	.align 2, 0
_080B2080: .4byte 0x00000BE8
_080B2084:
	adds r1, #4
	adds r2, #1
	cmp r2, r3
	blt _080B2070
_080B208C:
	movs r0, #1
_080B208E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b2094
FUN_080b2094: @ 0x080B2094
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrh r6, [r5, #0x1a]
	cmp r6, #0
	beq _080B20A4
	cmp r6, #1
	beq _080B2148
	b _080B21CE
_080B20A4:
	adds r0, r5, #0
	bl FUN_080b2060
	cmp r0, #0
	beq _080B20BE
	adds r0, r5, #0
	bl FUN_080b1a88
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ad1ec
	b _080B21CE
_080B20BE:
	movs r0, #0x4f
	bl prepare_08231510
	cmp r0, #0
	beq _080B20CE
	bl Script_GetValue
	b _080B20D0
_080B20CE:
	movs r0, #0
_080B20D0:
	cmp r0, #0
	beq _080B2138
	ldr r2, _080B212C @ =0x03002C00
	ldr r0, [r2]
	cmp r0, #0
	beq _080B2138
	ldr r3, _080B2130 @ =0x000001F5
	adds r1, r0, r3
	movs r3, #0
	movs r0, #0xb
	strb r0, [r1]
	ldr r2, [r2]
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #0x48]
	str r1, [r2, #0x4c]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r2, r0
	strb r3, [r2]
	ldrb r0, [r5, #0x1e]
	cmp r3, r0
	bge _080B211E
	ldr r1, _080B2134 @ =0x00000BE8
	adds r2, r5, r1
	adds r1, r0, #0
_080B210A:
	ldr r0, [r2]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B2116
	movs r3, #1
_080B2116:
	adds r2, #4
	subs r1, #1
	cmp r1, #0
	bne _080B210A
_080B211E:
	cmp r3, #0
	beq _080B213E
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080ad1ec
	b _080B21CE
	.align 2, 0
_080B212C: .4byte 0x03002C00
_080B2130: .4byte 0x000001F5
_080B2134: .4byte 0x00000BE8
_080B2138:
	adds r0, r5, #0
	bl FUN_080b1a88
_080B213E:
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080ad1ec
	b _080B21CE
_080B2148:
	adds r0, r5, #0
	bl FUN_080b0e98
	adds r0, r5, #0
	bl FUN_080b1e18
	ldr r3, _080B2190 @ =0x03002C00
	ldr r0, [r3]
	ldr r2, _080B2194 @ =0x000001F5
	adds r1, r0, r2
	movs r4, #0
	movs r0, #0xb
	strb r0, [r1]
	ldr r2, [r3]
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #0x48]
	str r1, [r2, #0x4c]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r2, r0
	strb r4, [r2]
	ldr r0, [r3]
	strb r6, [r0, #0x1b]
	ldr r0, [r3]
	ldrb r0, [r0, #0x1a]
	cmp r0, #6
	bne _080B219C
	ldr r2, _080B2198 @ =0x00000BF8
	adds r1, r5, r2
	movs r0, #0x50
	b _080B21B2
	.align 2, 0
_080B2190: .4byte 0x03002C00
_080B2194: .4byte 0x000001F5
_080B2198: .4byte 0x00000BF8
_080B219C:
	cmp r0, #7
	bne _080B21AC
	ldr r3, _080B21A8 @ =0x00000BF8
	adds r1, r5, r3
	movs r0, #0x78
	b _080B21B2
	.align 2, 0
_080B21A8: .4byte 0x00000BF8
_080B21AC:
	ldr r0, _080B21D4 @ =0x00000BF8
	adds r1, r5, r0
	movs r0, #0x64
_080B21B2:
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080ade88
	adds r0, r5, #0
	bl FUN_080ae394
	adds r0, r5, #0
	bl FUN_080b1b1c
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080ad1ec
_080B21CE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B21D4: .4byte 0x00000BF8

	thumb_func_start FUN_080b21d8
FUN_080b21d8: @ 0x080B21D8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080B21EA
	bl Script_GetValue
_080B21EA:
	strh r0, [r4, #0x1a]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b21f4
FUN_080b21f4: @ 0x080B21F4
	push {lr}
	ldr r2, _080B221C @ =0x03002C58
	ldr r1, [r2]
	cmp r1, #0
	beq _080B2216
	ldr r0, _080B2220 @ =0x00000C0F
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r2]
	movs r2, #0xc1
	lsls r2, r2, #4
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r2, #1
	adds r0, r0, r2
	strb r1, [r0]
_080B2216:
	pop {r0}
	bx r0
	.align 2, 0
_080B221C: .4byte 0x03002C58
_080B2220: .4byte 0x00000C0F

	thumb_func_start FUN_080b2224
FUN_080b2224: @ 0x080B2224
	push {r4, lr}
	sub sp, #8
	ldr r4, _080B2268 @ =0x03002C58
	ldr r0, [r4]
	cmp r0, #0
	beq _080B22E0
	mov r0, sp
	bl FUN_0823167c
	ldr r0, [r4]
	ldrh r2, [r0, #0x1a]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldr r0, _080B226C @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _080B2280
	ldr r1, _080B2270 @ =0x000001F5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xb
	bne _080B2274
	mov r0, sp
	movs r1, #0
	movs r2, #1
	bl FUN_0823206c
	b _080B228A
	.align 2, 0
_080B2268: .4byte 0x03002C58
_080B226C: .4byte 0x03002C00
_080B2270: .4byte 0x000001F5
_080B2274:
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
	b _080B228A
_080B2280:
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
_080B228A:
	movs r4, #0
_080B228C:
	mov r0, sp
	bl FUN_0823167c
	ldr r0, _080B22B8 @ =0x03002C58
	ldr r0, [r0]
	lsls r1, r4, #2
	ldr r2, _080B22BC @ =0x00000BE8
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080B22AC
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #1
	bhi _080B22C0
_080B22AC:
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
	b _080B22DA
	.align 2, 0
_080B22B8: .4byte 0x03002C58
_080B22BC: .4byte 0x00000BE8
_080B22C0:
	cmp r0, #4
	bne _080B22D0
	mov r0, sp
	movs r1, #0
	movs r2, #4
	bl FUN_0823206c
	b _080B22DA
_080B22D0:
	mov r0, sp
	movs r1, #0
	movs r2, #2
	bl FUN_0823206c
_080B22DA:
	adds r4, #1
	cmp r4, #3
	ble _080B228C
_080B22E0:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b22e8
FUN_080b22e8: @ 0x080B22E8
	push {lr}
	ldr r3, _080B2308 @ =0x03002C58
	ldr r1, [r3]
	cmp r1, #0
	beq _080B2304
	ldr r0, _080B230C @ =0x00001333
	adds r1, r1, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r3]
	ldr r1, _080B2310 @ =0x00001334
	adds r0, r0, r1
	strh r2, [r0]
_080B2304:
	pop {r0}
	bx r0
	.align 2, 0
_080B2308: .4byte 0x03002C58
_080B230C: .4byte 0x00001333
_080B2310: .4byte 0x00001334

	thumb_func_start FUN_080b2314
FUN_080b2314: @ 0x080B2314
	push {lr}
	ldr r0, _080B232C @ =0x03002C58
	ldr r0, [r0]
	cmp r0, #0
	beq _080B2326
	ldr r2, _080B2330 @ =0x00000C12
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
_080B2326:
	pop {r0}
	bx r0
	.align 2, 0
_080B232C: .4byte 0x03002C58
_080B2330: .4byte 0x00000C12

	thumb_func_start FUN_080b2334
FUN_080b2334: @ 0x080B2334
	push {lr}
	ldr r0, _080B234C @ =0x03002C58
	ldr r0, [r0]
	cmp r0, #0
	beq _080B2346
	ldr r2, _080B2350 @ =0x00000C12
	adds r1, r0, r2
	movs r0, #0
	strb r0, [r1]
_080B2346:
	pop {r0}
	bx r0
	.align 2, 0
_080B234C: .4byte 0x03002C58
_080B2350: .4byte 0x00000C12

	thumb_func_start FUN_080b2354
FUN_080b2354: @ 0x080B2354
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _080B23A4 @ =0x000017A8
	adds r5, r7, r0
	movs r6, #0
	ldr r2, _080B23A8 @ =0x03002B4C
	ldr r1, [r2]
	adds r1, #0x24
	ldr r3, _080B23AC @ =0x000017AE
	adds r0, r7, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _080B23EC
	mov r8, r2
_080B2378:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r6, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #0
	beq _080B23B0
	cmp r0, #1
	beq _080B23C8
	b _080B23D8
	.align 2, 0
_080B23A4: .4byte 0x000017A8
_080B23A8: .4byte 0x03002B4C
_080B23AC: .4byte 0x000017AE
_080B23B0:
	ldrh r1, [r4, #8]
	ldr r2, _080B23C4 @ =0x00000C11
	adds r0, r7, r2
	strb r1, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08022488
	b _080B23D8
	.align 2, 0
_080B23C4: .4byte 0x00000C11
_080B23C8:
	adds r0, r7, #0
	ldr r1, _080B23F8 @ =FUN_080ada44
	bl FUN_080ad9f4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08022488
_080B23D8:
	adds r6, #1
	mov r3, r8
	ldr r1, [r3]
	adds r1, #0x24
	adds r0, r5, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	blt _080B2378
_080B23EC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B23F8: .4byte FUN_080ada44

	thumb_func_start FUN_080b23fc
FUN_080b23fc: @ 0x080B23FC
	push {lr}
	ldr r1, _080B240C @ =0x000017A8
	adds r0, r0, r1
	bl FUN_08022428
	pop {r0}
	bx r0
	.align 2, 0
_080B240C: .4byte 0x000017A8

	thumb_func_start FUN_080b2410
FUN_080b2410: @ 0x080B2410
	push {lr}
	ldr r1, _080B2424 @ =0x000017A8
	adds r2, r0, r1
	ldrh r1, [r0, #0x18]
	adds r0, r2, #0
	movs r2, #9
	bl FUN_080223f4
	pop {r0}
	bx r0
	.align 2, 0
_080B2424: .4byte 0x000017A8

	thumb_func_start FUN_080b2428
FUN_080b2428: @ 0x080B2428
	ldr r1, _080B2430 @ =0x03002C58
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080B2430: .4byte 0x03002C58

	thumb_func_start FUN_080b2434
FUN_080b2434: @ 0x080B2434
	push {lr}
	adds r2, r0, #0
	ldr r1, _080B2450 @ =0x00000C0F
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B245C
	ldr r0, _080B2454 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _080B2458 @ =0x00000942
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	b _080B2462
	.align 2, 0
_080B2450: .4byte 0x00000C0F
_080B2454: .4byte 0x030046A0
_080B2458: .4byte 0x00000942
_080B245C:
	ldr r1, _080B2470 @ =0x00000C11
	adds r0, r2, r1
	ldrb r1, [r0]
_080B2462:
	movs r3, #0xc1
	lsls r3, r3, #4
	adds r0, r2, r3
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_080B2470: .4byte 0x00000C11

	thumb_func_start FUN_080b2474
FUN_080b2474: @ 0x080B2474
	push {r4, lr}
	movs r3, #0
	ldrb r1, [r0, #0x1e]
	cmp r3, r1
	bge _080B2496
	ldr r4, _080B24A0 @ =0x00000BE8
	adds r2, r0, r4
_080B2482:
	ldr r0, [r2]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B248E
	adds r3, #1
_080B248E:
	adds r2, #4
	subs r1, #1
	cmp r1, #0
	bne _080B2482
_080B2496:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B24A0: .4byte 0x00000BE8

	thumb_func_start FUN_080b24a4
FUN_080b24a4: @ 0x080B24A4
	push {lr}
	adds r3, r0, #0
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B2518
	ldrb r0, [r3, #0x1f]
	cmp r0, #0
	beq _080B2518
	ldr r2, _080B2504 @ =0x000004FC
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r0, #0xa
	beq _080B24C8
	cmp r0, #0xe
	bne _080B2518
_080B24C8:
	movs r0, #0xa3
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #1
	strh r0, [r2, #0x10]
	ldr r2, _080B2508 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080B250C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080B2510 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x48
	ldr r2, _080B2514 @ =0x00000521
	adds r1, r3, r2
	strb r0, [r1]
	subs r2, #1
	adds r1, r3, r2
	strb r0, [r1]
	b _080B2526
	.align 2, 0
_080B2504: .4byte 0x000004FC
_080B2508: .4byte 0x030046B8
_080B250C: .4byte 0x000003FF
_080B2510: .4byte 0x0203B400
_080B2514: .4byte 0x00000521
_080B2518:
	movs r1, #0xa3
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_080B2526:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b252c
FUN_080b252c: @ 0x080B252C
	push {r4, r5, lr}
	sub sp, #8
	ldr r1, _080B2588 @ =0x03002BE0
	ldr r4, [r1]
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r2, r0, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r1, r1, r2
	lsls r1, r1, #0xf
	lsrs r1, r1, #0x10
	ldr r5, _080B258C @ =0xFFFF0000
	ldr r3, [sp]
	ands r3, r5
	orrs r3, r1
	str r3, [sp]
	ldrh r2, [r4, #0x2e]
	adds r2, #0x96
	lsls r2, r2, #0x10
	ldr r1, _080B2590 @ =0x0000FFFF
	ands r1, r3
	orrs r1, r2
	str r1, [sp]
	movs r2, #0x30
	ldrsh r1, [r4, r2]
	ldr r3, _080B2594 @ =0x00000504
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	lsls r1, r1, #0xf
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	bl FUN_0823b8ac
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B2588: .4byte 0x03002BE0
_080B258C: .4byte 0xFFFF0000
_080B2590: .4byte 0x0000FFFF
_080B2594: .4byte 0x00000504

	thumb_func_start FUN_080b2598
FUN_080b2598: @ 0x080B2598
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080b2354
	adds r0, r4, #0
	bl FUN_080b2434
	adds r0, r4, #0
	bl FUN_080b2474
	strb r0, [r4, #0x1f]
	ldr r0, _080B25BC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x1c]
	cmp r1, #4
	bne _080B25C0
	movs r0, #0
	b _080B26C2
	.align 2, 0
_080B25BC: .4byte 0x03002BE0
_080B25C0:
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	bne _080B2604
	ldr r2, _080B2628 @ =0x000004FC
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0xe
	beq _080B2604
	cmp r1, #1
	bne _080B2604
	ldr r0, _080B262C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080B2604
	adds r0, r4, #0
	movs r1, #0xe
	bl FUN_080ad1ec
	ldr r2, _080B2630 @ =0x00000C6C
	adds r0, r4, r2
	movs r1, #9
	bl FUN_080af374
	adds r0, r4, #0
	bl FUN_080af0c8
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080ad204
_080B2604:
	ldr r1, _080B2634 @ =0x085AD07C
	ldr r2, _080B2628 @ =0x000004FC
	adds r0, r4, r2
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrh r0, [r4, #0x1a]
	cmp r0, #0
	bne _080B2638
	adds r0, r4, #0
	bl FUN_080ad96c
	b _080B26BC
	.align 2, 0
_080B2628: .4byte 0x000004FC
_080B262C: .4byte 0x030046A0
_080B2630: .4byte 0x00000C6C
_080B2634: .4byte 0x085AD07C
_080B2638:
	adds r0, r4, #0
	bl FUN_080b09d4
	adds r0, r4, #0
	bl FUN_080b252c
	adds r0, r4, #0
	bl FUN_080ae8a4
	adds r0, r4, #0
	bl FUN_080ade4c
	adds r0, r4, #0
	bl FUN_080b24a4
	ldr r1, _080B2688 @ =0x0000133E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B26BC
	ldr r2, _080B268C @ =0x00000C0F
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B26B4
	ldr r0, _080B2690 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080B2698
	ldr r2, _080B2694 @ =0x00001344
	adds r0, r4, r2
	ldrh r0, [r0]
	bl PlaySound_082406e0
	b _080B26AE
	.align 2, 0
_080B2688: .4byte 0x0000133E
_080B268C: .4byte 0x00000C0F
_080B2690: .4byte 0x030046A0
_080B2694: .4byte 0x00001344
_080B2698:
	ldr r1, _080B26C8 @ =0x0000133F
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r1, r1, #1
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r0, r4, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	bl PlaySound_082406e0
_080B26AE:
	ldr r0, _080B26CC @ =0x0000029B
	bl PlaySound_082406e0
_080B26B4:
	ldr r0, _080B26D0 @ =0x0000133E
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_080B26BC:
	adds r0, r4, #0
	bl FUN_080ad23c
_080B26C2:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B26C8: .4byte 0x0000133F
_080B26CC: .4byte 0x0000029B
_080B26D0: .4byte 0x0000133E

	thumb_func_start FUN_080b26d4
FUN_080b26d4: @ 0x080B26D4
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x1a]
	cmp r0, #0
	bne _080B26F4
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080B270E
	subs r1, #0x68
	adds r0, r4, r1
	bl FUN_0822a4e0
	b _080B270E
_080B26F4:
	ldr r1, _080B2728 @ =0x00000C6C
	adds r0, r4, r1
	bl FUN_080b0ab4
	movs r1, #0xa3
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_0822a4e0
	movs r0, #1
	movs r1, #1
	bl SetBGPrioDirect
_080B270E:
	adds r0, r4, #0
	bl FUN_080ad368
	adds r0, r4, #0
	bl FUN_080b23fc
	ldr r1, _080B272C @ =0x03002C58
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B2728: .4byte 0x00000C6C
_080B272C: .4byte 0x03002C58

	thumb_func_start FUN_080b2730
FUN_080b2730: @ 0x080B2730
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x64
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080B2750
	bl Script_GetValue
	ldr r2, _080B274C @ =0x00000C0F
	adds r1, r4, r2
	strb r0, [r1]
	b _080B2756
	.align 2, 0
_080B274C: .4byte 0x00000C0F
_080B2750:
	ldr r2, _080B2788 @ =0x00000C0F
	adds r0, r4, r2
	strb r1, [r0]
_080B2756:
	ldr r0, _080B278C @ =0x03002BE0
	ldr r1, [r0]
	ldr r2, _080B2790 @ =0x000004F4
	adds r0, r4, r2
	str r1, [r0]
	movs r0, #0x9f
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _080B2794 @ =0x03002C00
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080b1d5c
	adds r0, r4, #0
	bl FUN_080b21d8
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _080B2798
	bl Script_GetValue
	b _080B279A
	.align 2, 0
_080B2788: .4byte 0x00000C0F
_080B278C: .4byte 0x03002BE0
_080B2790: .4byte 0x000004F4
_080B2794: .4byte 0x03002C00
_080B2798:
	movs r0, #4
_080B279A:
	strb r0, [r4, #0x1e]
	adds r0, r4, #0
	bl FUN_080b1b74
	adds r0, r4, #0
	bl FUN_080b2094
	adds r0, r4, #0
	bl FUN_080ad388
	adds r0, r4, #0
	bl FUN_080ad544
	adds r0, r4, #0
	bl FUN_080b1de8
	adds r0, r4, #0
	bl FUN_080b2410
	ldr r0, _080B27E0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080B27E4 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0xc1
	lsls r2, r2, #4
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _080B27E8 @ =0x03002C58
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B27E0: .4byte 0x030046A0
_080B27E4: .4byte 0x00000942
_080B27E8: .4byte 0x03002C58

	thumb_func_start FUN_080b27ec
FUN_080b27ec: @ 0x080B27EC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080B2824 @ =0x03002C58
	ldr r0, [r0]
	cmp r0, #0
	bne _080B2836
	ldr r1, _080B2828 @ =0x000017DC
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080B2834
	ldr r1, _080B282C @ =FUN_080b2598
	ldr r2, _080B2830 @ =FUN_080b26d4
	bl SetEntityRoutine
	strh r5, [r4, #0x18]
	adds r0, r4, #0
	bl FUN_080b2730
	cmp r0, #0
	bge _080B2834
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080B2836
	.align 2, 0
_080B2824: .4byte 0x03002C58
_080B2828: .4byte 0x000017DC
_080B282C: .4byte FUN_080b2598
_080B2830: .4byte FUN_080b26d4
_080B2834:
	adds r0, r4, #0
_080B2836:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b283c
FUN_080b283c: @ 0x080B283C
	push {lr}
	adds r3, r0, #0
	movs r0, #0xcf
	adds r0, r0, r3
	mov ip, r0
	movs r2, #0
	strb r1, [r0]
	adds r0, r3, #0
	adds r0, #0xd0
	strh r2, [r0]
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r2, r3, r1
	ldr r1, _080B2874 @ =0x085AD0B8
	mov r3, ip
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldrb r0, [r3]
	cmp r0, #3
	bne _080B2878
	movs r0, #0xfb
	bl PlaySound_082406e0
	b _080B2882
	.align 2, 0
_080B2874: .4byte 0x085AD0B8
_080B2878:
	cmp r0, #5
	bne _080B2882
	movs r0, #0xfc
	bl PlaySound_082406e0
_080B2882:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b2888
FUN_080b2888: @ 0x080B2888
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	ldr r0, [r4, #0x60]
	ldr r1, [r4, #0x64]
	str r0, [r4, #0x34]
	str r1, [r4, #0x38]
	adds r1, r4, #0
	adds r1, #0xed
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080B28EC @ =0x0203B400
	mov r8, r0
	ldr r5, _080B28F0 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r6, _080B28F4 @ =0x000003FF
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	ldrh r1, [r4, #0x34]
	subs r1, #5
	adds r1, r1, r0
	strh r1, [r4, #0x34]
	ldr r0, [r5]
	adds r0, #1
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	ldrh r1, [r4, #0x38]
	subs r1, #5
	adds r1, r1, r0
	strh r1, [r4, #0x38]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B28EC: .4byte 0x0203B400
_080B28F0: .4byte 0x030046B8
_080B28F4: .4byte 0x000003FF

	thumb_func_start FUN_080b28f8
FUN_080b28f8: @ 0x080B28F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r6, _080B2998 @ =0x03002BE0
	ldr r3, [r6]
	movs r1, #0x2c
	ldrsh r2, [r3, r1]
	adds r7, r0, #0
	adds r7, #0x60
	movs r4, #0
	ldrsh r1, [r7, r4]
	subs r2, r2, r1
	movs r5, #0x30
	ldrsh r1, [r3, r5]
	adds r0, #0x64
	mov r8, r0
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r3, r1, r0
	adds r0, r2, #0
	cmp r2, #0
	bge _080B2926
	rsbs r0, r2, #0
_080B2926:
	cmp r0, #0x7f
	bgt _080B298C
	adds r0, r3, #0
	cmp r3, #0
	bge _080B2932
	rsbs r0, r3, #0
_080B2932:
	cmp r0, #0x7f
	bgt _080B298C
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r3, #0
	muls r1, r3, r1
	adds r0, r0, r1
	ldr r1, _080B299C @ =0x00003FFF
	cmp r0, r1
	bgt _080B298C
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_0823785c
	ldr r4, [r6]
	mov ip, r4
	ldr r4, _080B29A0 @ =0x085B0A08
	adds r1, r0, #0
	adds r1, #0x40
	movs r3, #0xff
	ands r1, r3
	lsls r1, r1, #1
	adds r1, r1, r4
	movs r5, #0
	ldrsh r2, [r1, r5]
	lsls r1, r2, #6
	adds r1, r1, r2
	asrs r1, r1, #0xb
	ldrh r7, [r7]
	adds r1, r1, r7
	mov r2, ip
	strh r1, [r2, #0x2c]
	ldr r2, [r6]
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #6
	adds r0, r0, r1
	asrs r0, r0, #0xb
	mov r4, r8
	ldrh r4, [r4]
	adds r0, r0, r4
	strh r0, [r2, #0x30]
_080B298C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B2998: .4byte 0x03002BE0
_080B299C: .4byte 0x00003FFF
_080B29A0: .4byte 0x085B0A08

	thumb_func_start FUN_080b29a4
FUN_080b29a4: @ 0x080B29A4
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r1, #0x7f
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080B2A0A
	adds r1, r2, #0
	adds r5, r1, #0
	adds r5, #0xe0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080B2A0A
	adds r0, r1, #0
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #2
	bne _080B2A0A
	ldrh r1, [r3, #0x3c]
	ldrh r0, [r4, #0x3c]
	subs r1, r1, r0
	cmp r1, #0
	bge _080B29D6
	movs r1, #1
_080B29D6:
	adds r3, r2, #0
	adds r3, #0xeb
	movs r0, #4
	strb r0, [r3]
	subs r3, #0x19
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xd4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	blo _080B2A00
	strh r1, [r3]
	adds r0, r2, #0
	movs r1, #3
	bl FUN_080b283c
	b _080B2A0A
_080B2A00:
	movs r0, #0xc
	strh r0, [r5]
	ldr r0, _080B2A10 @ =0x00000127
	bl PlaySound_082406e0
_080B2A0A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B2A10: .4byte 0x00000127

	thumb_func_start FUN_080b2a14
FUN_080b2a14: @ 0x080B2A14
	bx lr
	.align 2, 0

	thumb_func_start FUN_080b2a18
FUN_080b2a18: @ 0x080B2A18
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0xdc
	ldrh r0, [r1]
	cmp r0, #0
	beq _080B2A2E
	subs r0, #1
	strh r0, [r1]
	b _080B2B60
_080B2A2E:
	ldr r0, [r5, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x18]
	adds r2, r5, #0
	adds r2, #0x6e
	ldrh r1, [r2]
	ldr r0, _080B2A94 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r0, #2
	strb r0, [r5, #0x1f]
	adds r4, r5, #0
	adds r4, #0xb8
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r7, r5, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _080B2A98
	ldr r0, [r5, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B2AA0
	.align 2, 0
_080B2A94: .4byte 0x0000FFFB
_080B2A98:
	ldr r0, [r5, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B2AA0:
	str r0, [r5, #0x18]
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
	beq _080B2AC4
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B2ACC
_080B2AC4:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B2ACC:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B2B04 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B2B4A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B2B0E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B2B08
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080B2B24
	.align 2, 0
_080B2B04: .4byte 0x0000FFFF
_080B2B08:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B2B22
_080B2B0E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B2B22
	strh r1, [r4, #8]
	movs r2, #1
	b _080B2B24
_080B2B22:
	movs r2, #0
_080B2B24:
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
	bne _080B2B4C
	movs r0, #1
	strb r0, [r4, #7]
	b _080B2B4C
_080B2B4A:
	movs r2, #0
_080B2B4C:
	cmp r2, #0
	beq _080B2B60
	adds r0, r5, #0
	adds r0, #0x68
	bl FUN_08236400
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080b283c
_080B2B60:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b2b68
FUN_080b2b68: @ 0x080B2B68
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0xb8
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	adds r7, r6, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	cmp r1, r0
	beq _080B2BB8
	ldr r0, [r6, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B2BC0
_080B2BB8:
	ldr r0, [r6, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B2BC0:
	str r0, [r6, #0x18]
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
	beq _080B2BE4
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B2BEC
_080B2BE4:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B2BEC:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B2C24 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B2C5C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B2C28
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B2C1C
	ldrb r0, [r4, #5]
_080B2C1C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B2C38
	.align 2, 0
_080B2C24: .4byte 0x0000FFFF
_080B2C28:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B2C38
	strh r1, [r4, #8]
_080B2C38:
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
	bne _080B2C5C
	movs r0, #1
	strb r0, [r4, #7]
_080B2C5C:
	adds r1, r6, #0
	adds r1, #0xee
	ldr r0, _080B2C6C @ =0x000001C3
	strh r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B2C6C: .4byte 0x000001C3

	thumb_func_start FUN_080b2c70
FUN_080b2c70: @ 0x080B2C70
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r0, #0xce
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B2CB0
	adds r0, r5, #0
	adds r0, #0xc0
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #5
	bne _080B2C92
	adds r0, #6
	ldrh r0, [r0]
	cmp r0, #0
	beq _080B2CC4
_080B2C92:
	ldrh r0, [r2]
	cmp r0, #5
	bls _080B2CCE
	adds r0, r5, #0
	adds r0, #0xea
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B2CC4
	adds r1, r5, #0
	adds r1, #0xee
	ldr r0, _080B2CAC @ =0x000001C5
	b _080B2CCC
	.align 2, 0
_080B2CAC: .4byte 0x000001C5
_080B2CB0:
	adds r0, r5, #0
	adds r0, #0xc0
	ldrh r0, [r0]
	cmp r0, #5
	bne _080B2CCE
	adds r0, r5, #0
	adds r0, #0xc6
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B2CCE
_080B2CC4:
	adds r1, r5, #0
	adds r1, #0xee
	movs r0, #0xe2
	lsls r0, r0, #1
_080B2CCC:
	strh r0, [r1]
_080B2CCE:
	adds r4, r5, #0
	adds r4, #0xb8
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r7, r5, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _080B2D1A
	ldr r0, [r5, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B2D22
_080B2D1A:
	ldr r0, [r5, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B2D22:
	str r0, [r5, #0x18]
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
	beq _080B2D46
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B2D4E
_080B2D46:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B2D4E:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B2D88 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B2DCE
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B2D92
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B2D8C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080B2DA8
	.align 2, 0
_080B2D88: .4byte 0x0000FFFF
_080B2D8C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B2DA6
_080B2D92:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B2DA6
	strh r1, [r4, #8]
	movs r2, #1
	b _080B2DA8
_080B2DA6:
	movs r2, #0
_080B2DA8:
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
	bne _080B2DD0
	movs r0, #1
	strb r0, [r4, #7]
	b _080B2DD0
_080B2DCE:
	movs r2, #0
_080B2DD0:
	cmp r2, #0
	beq _080B2DE4
	adds r1, r5, #0
	adds r1, #0xec
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080b283c
_080B2DE4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b2dec
FUN_080b2dec: @ 0x080B2DEC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0xb8
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08236fac
	adds r7, r6, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	cmp r1, r0
	beq _080B2E3C
	ldr r0, [r6, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B2E44
_080B2E3C:
	ldr r0, [r6, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B2E44:
	str r0, [r6, #0x18]
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
	beq _080B2E68
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B2E70
_080B2E68:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B2E70:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B2EA8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B2EE0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B2EAC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B2EA0
	ldrb r0, [r4, #5]
_080B2EA0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B2EBC
	.align 2, 0
_080B2EA8: .4byte 0x0000FFFF
_080B2EAC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B2EBC
	strh r1, [r4, #8]
_080B2EBC:
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
	bne _080B2EE0
	movs r0, #1
	strb r0, [r4, #7]
_080B2EE0:
	adds r0, r6, #0
	adds r0, #0xea
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B2EF8
	adds r1, r6, #0
	adds r1, #0xee
	ldr r0, _080B2EF4 @ =0x000001C5
	b _080B2F00
	.align 2, 0
_080B2EF4: .4byte 0x000001C5
_080B2EF8:
	adds r1, r6, #0
	adds r1, #0xee
	movs r0, #0xe2
	lsls r0, r0, #1
_080B2F00:
	strh r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b2f0c
FUN_080b2f0c: @ 0x080B2F0C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r0, #0xce
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B2F1C
	b _080B3076
_080B2F1C:
	adds r0, r5, #0
	adds r0, #0xc0
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #5
	bne _080B2F3A
	adds r0, #6
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B2F3A
	adds r1, r5, #0
	adds r1, #0xee
	movs r0, #0xe2
	lsls r0, r0, #1
	b _080B2F50
_080B2F3A:
	ldrh r0, [r2]
	cmp r0, #6
	bne _080B2F52
	adds r0, r5, #0
	adds r0, #0xc6
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B2F52
	adds r1, r5, #0
	adds r1, #0xee
	ldr r0, _080B2FA0 @ =0x000001C3
_080B2F50:
	strh r0, [r1]
_080B2F52:
	adds r4, r5, #0
	adds r4, #0xb8
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #4
	bl FUN_08236fac
	adds r7, r5, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _080B2FA4
	ldr r0, [r5, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B2FAC
	.align 2, 0
_080B2FA0: .4byte 0x000001C3
_080B2FA4:
	ldr r0, [r5, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B2FAC:
	str r0, [r5, #0x18]
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
	beq _080B2FD0
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B2FD8
_080B2FD0:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B2FD8:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B3010 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B3056
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B301A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B3014
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080B3030
	.align 2, 0
_080B3010: .4byte 0x0000FFFF
_080B3014:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B302E
_080B301A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B302E
	strh r1, [r4, #8]
	movs r2, #1
	b _080B3030
_080B302E:
	movs r2, #0
_080B3030:
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
	bne _080B3058
	movs r0, #1
	strb r0, [r4, #7]
	b _080B3058
_080B3056:
	movs r2, #0
_080B3058:
	cmp r2, #0
	bne _080B305E
	b _080B31AC
_080B305E:
	adds r1, r5, #0
	adds r1, #0xd2
	movs r0, #0
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x5a
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #6
	bl FUN_080b283c
	b _080B31AC
_080B3076:
	adds r0, r5, #0
	adds r0, #0xc0
	ldrh r0, [r0]
	cmp r0, #5
	bne _080B3092
	adds r0, r5, #0
	adds r0, #0xc6
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B3092
	adds r1, r5, #0
	adds r1, #0xee
	ldr r0, _080B30E0 @ =0x000001C3
	strh r0, [r1]
_080B3092:
	adds r4, r5, #0
	adds r4, #0xb8
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #4
	bl FUN_08236fac
	adds r7, r5, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _080B30E4
	ldr r0, [r5, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B30EC
	.align 2, 0
_080B30E0: .4byte 0x000001C3
_080B30E4:
	ldr r0, [r5, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B30EC:
	str r0, [r5, #0x18]
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
	beq _080B3110
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B3118
_080B3110:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B3118:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B3150 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B3196
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B315A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B3154
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080B3170
	.align 2, 0
_080B3150: .4byte 0x0000FFFF
_080B3154:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B316E
_080B315A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B316E
	strh r1, [r4, #8]
	movs r2, #1
	b _080B3170
_080B316E:
	movs r2, #0
_080B3170:
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
	bne _080B3198
	movs r0, #1
	strb r0, [r4, #7]
	b _080B3198
_080B3196:
	movs r2, #0
_080B3198:
	cmp r2, #0
	beq _080B31AC
	adds r1, r5, #0
	adds r1, #0xd2
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080b283c
_080B31AC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b31b4
FUN_080b31b4: @ 0x080B31B4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xb8
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	adds r7, r5, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _080B3204
	ldr r0, [r5, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B320C
_080B3204:
	ldr r0, [r5, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B320C:
	str r0, [r5, #0x18]
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
	beq _080B3230
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B3238
_080B3230:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B3238:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B3270 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B32A8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B3274
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B3268
	ldrb r0, [r4, #5]
_080B3268:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B3284
	.align 2, 0
_080B3270: .4byte 0x0000FFFF
_080B3274:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B3284
	strh r1, [r4, #8]
_080B3284:
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
	bne _080B32A8
	movs r0, #1
	strb r0, [r4, #7]
_080B32A8:
	adds r1, r5, #0
	adds r1, #0xde
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080B32D0
	adds r1, #0xf
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r5, #0x60]
	ldr r1, [r5, #0x64]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080b283c
	b _080B32D6
_080B32D0:
	adds r0, r5, #0
	bl FUN_080b2888
_080B32D6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b32e0
FUN_080b32e0: @ 0x080B32E0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xf9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080B32F2
	subs r0, #1
	strb r0, [r1]
_080B32F2:
	adds r2, r4, #0
	adds r2, #0xf2
	ldrh r6, [r2]
	cmp r6, #0
	bne _080B3354
	adds r5, r4, #0
	adds r5, #0xd0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080B3310
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08246790
_080B3310:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080B3344
	ldr r0, [r4, #0x60]
	ldr r1, [r4, #0x64]
	str r0, [r4, #0x34]
	str r1, [r4, #0x38]
	adds r1, r4, #0
	adds r1, #0xee
	ldr r0, _080B3340 @ =0x000001C5
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b283c
	adds r0, r4, #0
	adds r0, #0xa6
	strh r6, [r0]
	strh r6, [r5]
	b _080B3384
	.align 2, 0
_080B3340: .4byte 0x000001C5
_080B3344:
	adds r0, r4, #0
	adds r0, #0xf0
	ldrh r0, [r0]
	subs r0, #1
	adds r1, r4, #0
	adds r1, #0xee
	strh r0, [r1]
	b _080B3384
_080B3354:
	adds r0, r4, #0
	adds r0, #0xf0
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0xee
	strh r0, [r1]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
	adds r5, r4, #0
	adds r5, #0xf4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r5]
	cmp r0, r1
	bhs _080B3384
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_082466ec
	ldrh r0, [r5]
	subs r0, #0xfa
	strh r0, [r5]
_080B3384:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b338c
FUN_080b338c: @ 0x080B338C
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r2, #0
	adds r4, #0xe2
	ldrh r0, [r4]
	cmp r0, #0
	beq _080B33B0
	adds r0, r2, #0
	adds r0, #0xe4
	ldrh r3, [r0]
	adds r1, r0, #0
	cmp r3, #0xb
	bhi _080B33AA
	adds r0, r3, #1
	strh r0, [r1]
_080B33AA:
	movs r0, #0
	strh r0, [r4]
	b _080B33C0
_080B33B0:
	adds r0, r2, #0
	adds r0, #0xe4
	ldrh r3, [r0]
	adds r1, r0, #0
	cmp r3, #0
	beq _080B33C0
	subs r0, r3, #1
	strh r0, [r1]
_080B33C0:
	ldrh r0, [r1]
	cmp r0, #0xc
	bne _080B33D8
	adds r0, r2, #0
	adds r0, #0x44
	ldr r1, _080B33D4 @ =0x000001C7
	bl FUN_0822b20c
	b _080B3416
	.align 2, 0
_080B33D4: .4byte 0x000001C7
_080B33D8:
	cmp r0, #0
	beq _080B33EA
	adds r0, r2, #0
	adds r0, #0x44
	movs r1, #0xe3
	lsls r1, r1, #1
	bl FUN_0822b20c
	b _080B3416
_080B33EA:
	adds r4, r2, #0
	adds r4, #0xeb
	ldrb r0, [r4]
	cmp r0, #0
	beq _080B3408
	adds r0, r2, #0
	adds r0, #0x44
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _080B3416
_080B3408:
	adds r0, r2, #0
	adds r0, #0x44
	adds r1, r2, #0
	adds r1, #0xee
	ldrh r1, [r1]
	bl FUN_0822b20c
_080B3416:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b341c
FUN_080b341c: @ 0x080B341C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xcf
	ldrb r0, [r5]
	cmp r0, #0
	beq _080B3430
	adds r0, r4, #0
	bl FUN_080b28f8
_080B3430:
	adds r1, r4, #0
	adds r1, #0xda
	ldrh r0, [r1]
	cmp r0, #0
	beq _080B343E
	subs r0, #1
	strh r0, [r1]
_080B343E:
	adds r1, r4, #0
	adds r1, #0xe0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080B344C
	subs r0, #1
	strh r0, [r1]
_080B344C:
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080b338c
	adds r2, r4, #0
	adds r2, #0xe8
	ldrh r0, [r2]
	cmp r0, #0
	beq _080B3496
	ldr r0, _080B3484 @ =0x03002C58
	ldr r0, [r0]
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B3494
	ldrb r0, [r5]
	cmp r0, #4
	beq _080B3488
	movs r0, #0
	b _080B3494
	.align 2, 0
_080B3484: .4byte 0x03002C58
_080B3488:
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r2]
	subs r0, #1
_080B3494:
	strh r0, [r2]
_080B3496:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080b34a0
FUN_080b34a0: @ 0x080B34A0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0x68
	bl FUN_08236424
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b34c4
FUN_080b34c4: @ 0x080B34C4
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r5, #0
	adds r4, #0x68
	ldr r2, _080B3538 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x64
	orrs r0, r3
	ldr r1, _080B353C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0x10
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
	ldr r2, _080B3540 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	adds r1, r5, #0
	adds r1, #0x60
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _080B3544 @ =FUN_080b29a4
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B3538: .4byte 0xFFFF0000
_080B353C: .4byte 0x0000FFFF
_080B3540: .4byte 0x00004001
_080B3544: .4byte FUN_080b29a4

	thumb_func_start FUN_080b3548
FUN_080b3548: @ 0x080B3548
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r4, [sp, #0x2c]
	ldr r6, [sp, #0x30]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r7, #0x60]
	str r1, [r7, #0x64]
	adds r0, r7, #0
	adds r0, #0xce
	strb r4, [r0]
	movs r0, #0xcc
	adds r0, r0, r7
	mov sl, r0
	strb r2, [r0]
	adds r1, r7, #0
	adds r1, #0xcd
	str r1, [sp, #4]
	strb r3, [r1]
	adds r0, r7, #0
	adds r0, #0xdc
	mov r2, sp
	ldrh r2, [r2, #0x38]
	strh r2, [r0]
	movs r0, #0xd4
	adds r0, r0, r7
	mov r8, r0
	strh r6, [r0]
	ldrh r0, [r0]
	movs r1, #6
	bl Div
	adds r1, r7, #0
	adds r1, #0xd8
	strh r0, [r1]
	movs r1, #0x18
	adds r1, r1, r7
	mov sb, r1
	adds r4, r7, #0
	adds r4, #0x44
	ldr r1, _080B35F8 @ =0x0000C038
	adds r0, r4, #0
	bl FUN_0822b16c
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r0, [r7, #0x60]
	ldr r1, [r7, #0x64]
	mov r2, sb
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, _080B35FC @ =0x0000922E
	ldr r1, _080B3600 @ =0x00003449
	bl GetFile
	adds r6, r7, #0
	adds r6, #0xc8
	str r0, [r6]
	adds r0, r7, #0
	ldr r1, [sp, #0x34]
	bl FUN_080b34c4
	adds r0, r7, #0
	ldr r1, [sp, #0x28]
	bl FUN_080b283c
	adds r0, r7, #0
	adds r0, #0xcf
	ldrb r5, [r0]
	cmp r5, #2
	beq _080B3634
	cmp r5, #2
	bgt _080B3604
	cmp r5, #0
	beq _080B3612
	movs r0, #0xee
	adds r0, r0, r7
	mov r8, r0
	b _080B3854
	.align 2, 0
_080B35F8: .4byte 0x0000C038
_080B35FC: .4byte 0x0000922E
_080B3600: .4byte 0x00003449
_080B3604:
	cmp r5, #4
	bne _080B360A
	b _080B3746
_080B360A:
	movs r1, #0xee
	adds r1, r1, r7
	mov r8, r1
	b _080B3854
_080B3612:
	adds r0, r7, #0
	adds r0, #0xd2
	strh r5, [r0]
	adds r2, r7, #0
	adds r2, #0xee
	ldr r0, _080B3630 @ =0x000001C3
	strh r0, [r2]
	movs r0, #3
	strb r0, [r7, #0x1f]
	ldr r0, [r7, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x18]
	mov r8, r2
	b _080B3854
	.align 2, 0
_080B3630: .4byte 0x000001C3
_080B3634:
	adds r1, r7, #0
	adds r1, #0xd2
	movs r0, #0
	strh r0, [r1]
	movs r2, #0xee
	adds r2, r2, r7
	mov r8, r2
	ldr r0, _080B3690 @ =0x000001C3
	strh r0, [r2]
	adds r4, r7, #0
	adds r4, #0xb8
	ldr r1, [r6]
	mov r0, sl
	ldrb r3, [r0]
	ldr r2, [sp, #4]
	ldrb r0, [r2]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	mov ip, sb
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
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
	beq _080B3694
	ldr r0, [r7, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B369C
	.align 2, 0
_080B3690: .4byte 0x000001C3
_080B3694:
	ldr r0, [r7, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B369C:
	str r0, [r7, #0x18]
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
	beq _080B36C2
	mov r2, ip
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	b _080B36CE
_080B36C2:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_080B36CE:
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B3704 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B373C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B3708
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B36FE
	ldrb r0, [r4, #5]
_080B36FE:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B3718
	.align 2, 0
_080B3704: .4byte 0x0000FFFF
_080B3708:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B3718
	strh r1, [r4, #8]
_080B3718:
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
	bne _080B373C
	movs r0, #1
	strb r0, [r4, #7]
_080B373C:
	adds r0, r7, #0
	adds r0, #0x68
	bl FUN_08236400
	b _080B3854
_080B3746:
	mov r1, r8
	ldrh r0, [r1]
	adds r1, r7, #0
	adds r1, #0xd2
	strh r0, [r1]
	movs r2, #0xee
	adds r2, r2, r7
	mov r8, r2
	movs r0, #0xe2
	lsls r0, r0, #1
	strh r0, [r2]
	adds r4, r7, #0
	adds r4, #0xb8
	ldr r1, [r6]
	mov r0, sl
	ldrb r3, [r0]
	ldr r2, [sp, #4]
	ldrb r0, [r2]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08236fac
	mov ip, sb
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
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
	beq _080B37A2
	ldr r0, [r7, #0x18]
	orrs r0, r5
	b _080B37AA
_080B37A2:
	ldr r0, [r7, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B37AA:
	str r0, [r7, #0x18]
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
	beq _080B37D0
	mov r2, ip
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	b _080B37DC
_080B37D0:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_080B37DC:
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B3814 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B384C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B3818
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B380C
	ldrb r0, [r4, #5]
_080B380C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B3828
	.align 2, 0
_080B3814: .4byte 0x0000FFFF
_080B3818:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B3828
	strh r1, [r4, #8]
_080B3828:
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
	bne _080B384C
	movs r0, #1
	strb r0, [r4, #7]
_080B384C:
	adds r0, r7, #0
	adds r0, #0x68
	bl FUN_08236400
_080B3854:
	adds r0, r7, #0
	adds r0, #0x44
	mov r2, r8
	ldrh r1, [r2]
	bl FUN_0822b20c
	adds r0, r7, #0
	adds r0, #0xda
	movs r4, #0
	movs r2, #0
	strh r2, [r0]
	adds r0, #0x12
	strb r4, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r1, r7, #0
	adds r1, #0x34
	str r2, [sp]
	movs r3, #0
	bl FUN_0824742c
	adds r0, r7, #0
	adds r0, #0xea
	strb r4, [r0]
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b3898
FUN_080b3898: @ 0x080B3898
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0x8f
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080B38F4
	ldr r1, _080B38EC @ =FUN_080b341c
	ldr r2, _080B38F0 @ =FUN_080b34a0
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x30]
	str r0, [sp, #8]
	ldr r0, [sp, #0x34]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x10]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_080b3548
	cmp r0, #0
	bge _080B38F4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080B38F6
	.align 2, 0
_080B38EC: .4byte FUN_080b341c
_080B38F0: .4byte FUN_080b34a0
_080B38F4:
	adds r0, r4, #0
_080B38F6:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080b3904
FUN_080b3904: @ 0x080B3904
	push {r4, r5, r6, lr}
	ldr r0, _080B392C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080B39B0
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _080B3930
	bl Script_GetValue
	adds r4, r0, #0
	cmp r4, #0xa
	ble _080B3932
	movs r4, #0xa
	b _080B3936
	.align 2, 0
_080B392C: .4byte 0x030047A4
_080B3930:
	movs r4, #0
_080B3932:
	cmp r4, #0
	ble _080B39B0
_080B3936:
	ldr r2, _080B3958 @ =0x030046A0
	ldr r5, [r2]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r5, r1
	movs r6, #0
	ldrsh r3, [r0, r6]
	subs r1, r3, #1
	ldr r0, _080B395C @ =0x0000270D
	cmp r1, r0
	bhi _080B398C
	movs r1, #0
	cmp r1, r4
	bge _080B3982
	ldr r6, _080B3960 @ =0x0000023A
	adds r0, r5, r6
	b _080B3970
	.align 2, 0
_080B3958: .4byte 0x030046A0
_080B395C: .4byte 0x0000270D
_080B3960: .4byte 0x0000023A
_080B3964:
	adds r1, #1
	cmp r1, r4
	bge _080B3982
	ldr r0, [r2]
	ldr r6, _080B39B8 @ =0x0000023A
	adds r0, r0, r6
_080B3970:
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r3, r0
	asrs r0, r0, #6
	adds r3, r0, #1
	ldr r0, _080B39BC @ =0x0000270E
	cmp r3, r0
	ble _080B3964
	ldr r3, _080B39C0 @ =0x0000270F
_080B3982:
	ldr r0, [r2]
	movs r6, #0x91
	lsls r6, r6, #4
	adds r0, r0, r6
	strh r3, [r0]
_080B398C:
	bl GetSecond
	adds r1, r0, #0
	ldr r4, _080B39C4 @ =0x030046A0
	ldr r0, [r4]
	movs r2, #0xad
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	eors r0, r1
	movs r1, #0xd
	bl Mod
	ldr r1, [r4]
	ldr r5, _080B39B8 @ =0x0000023A
	adds r1, r1, r5
	adds r0, #0x41
	strh r0, [r1]
_080B39B0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B39B8: .4byte 0x0000023A
_080B39BC: .4byte 0x0000270E
_080B39C0: .4byte 0x0000270F
_080B39C4: .4byte 0x030046A0

	thumb_func_start FUN_080b39c8
FUN_080b39c8: @ 0x080B39C8
	ldr r0, _080B39D8 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080B39D8: .4byte 0x030046A0
_080B39DC:
	.byte 0x00, 0xB5, 0x61, 0x20
	.byte 0x7D, 0xF1, 0x96, 0xFD, 0x00, 0x28, 0x0C, 0xD0, 0x7D, 0xF1, 0x7C, 0xFE, 0x01, 0x1C, 0x06, 0x48
	.byte 0x81, 0x42, 0x00, 0xDD, 0x01, 0x1C, 0x05, 0x48, 0x00, 0x68, 0x91, 0x22, 0x12, 0x01, 0x80, 0x18
	.byte 0x01, 0x80, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x0F, 0x27, 0x00, 0x00, 0xA0, 0x46, 0x00, 0x03

	thumb_func_start solar_bank_080b3a10
solar_bank_080b3a10: @ 0x080B3A10
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	ldr r0, _080B3A38 @ =0x000005D4
	add r0, r8
	ldr r4, [r0]
	cmp r4, #0
	bne _080B3A3C
	mov r7, r8
	adds r7, #0x38
	movs r1, #0
	add r0, sp, #0xc
_080B3A2C:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _080B3A2C
	b _080B3A7C
	.align 2, 0
_080B3A38: .4byte 0x000005D4
_080B3A3C:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
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
	subs r1, r4, r1
	str r1, [sp, #0xc]
	mov r7, r8
	adds r7, #0x38
_080B3A7C:
	mov r6, sp
	movs r4, #0xee
	lsls r4, r4, #2
	add r4, r8
	movs r5, #3
_080B3A86:
	ldm r6!, {r2}
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r7, #0
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B3A86
	movs r0, #0xbb
	lsls r0, r0, #3
	add r0, r8
	ldr r4, [r0]
	cmp r4, #0
	bne _080B3AB8
	movs r1, #0
	add r0, sp, #0xc
_080B3AAE:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _080B3AAE
	b _080B3AF4
_080B3AB8:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
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
	subs r1, r4, r1
	str r1, [sp, #0xc]
_080B3AF4:
	mov r6, sp
	movs r4, #0x8e
	lsls r4, r4, #2
	add r4, r8
	movs r5, #3
_080B3AFE:
	ldm r6!, {r2}
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r7, #0
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B3AFE
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b3b24
FUN_080b3b24: @ 0x080B3B24
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #1
	adds r1, r3, #0
	adds r1, #0x60
	movs r2, #0xc
_080B3B30:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080B3B30
	movs r4, #1
	movs r0, #0xa7
	lsls r0, r0, #3
	adds r1, r3, r0
	movs r2, #1
_080B3B48:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _080B3B48
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b3b5c
FUN_080b3b5c: @ 0x080B3B5C
	movs r3, #0xbe
	lsls r3, r3, #3
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080B3B70 @ =0x000005EC
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080B3B70: .4byte 0x000005EC

	thumb_func_start FUN_080b3b74
FUN_080b3b74: @ 0x080B3B74
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #0
	bl FUN_0822c398
	movs r6, #0
	str r6, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r4, #0
	bl FUN_080b3b24
	ldr r0, [r4, #0x60]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	str r6, [sp]
	movs r2, #0
	movs r3, #2
	bl FUN_082370cc
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r0, #0
	bl FUN_08047a28
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B3C00 @ =0x0000FFFF
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080B3C04 @ =FUN_080b3e3c
	adds r0, r4, #0
	bl FUN_080b3b5c
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B3C00: .4byte 0x0000FFFF
_080B3C04: .4byte FUN_080b3e3c

	thumb_func_start FUN_080b3c08
FUN_080b3c08: @ 0x080B3C08
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #0
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r4, #0
	bl FUN_080b3b24
	ldr r0, [r4, #0x60]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r4, #0x60]
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, _080B3C90 @ =0x000005EA
	adds r1, r4, r0
	movs r0, #1
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0xc0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0xb8
	subs r1, #0x88
	str r5, [sp]
	movs r2, #4
	movs r3, #1
	bl FUN_082370cc
	movs r0, #1
	bl FUN_08047a28
	ldr r1, _080B3C94 @ =FUN_080b3e80
	adds r0, r4, #0
	bl FUN_080b3b5c
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B3C90: .4byte 0x000005EA
_080B3C94: .4byte FUN_080b3e80

	thumb_func_start FUN_080b3c98
FUN_080b3c98: @ 0x080B3C98
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #1
	bl FUN_0822c398
	movs r6, #0
	str r6, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r7, #0
	bl FUN_080b3b24
	ldr r0, [r7, #0x60]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r7, #0x60]
	adds r0, r7, #0
	adds r0, #0x58
	adds r5, r7, #0
	adds r5, #0x18
	str r6, [sp]
	adds r1, r5, #0
	movs r2, #1
	movs r3, #1
	bl FUN_082370cc
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r1, r5, #0
	movs r2, #0x12
	movs r3, #1
	bl Sprite_SetSprite
	movs r3, #0xbb
	lsls r3, r3, #3
	adds r2, r7, r3
	ldr r0, _080B3DB4 @ =0x030046A0
	ldr r1, [r0]
	movs r3, #0xef
	lsls r3, r3, #2
	adds r0, r1, r3
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, _080B3DB8 @ =0x000005D4
	adds r2, r7, r0
	movs r3, #0x91
	lsls r3, r3, #4
	adds r1, r1, r3
	movs r3, #0
	ldrsh r0, [r1, r3]
	str r0, [r2]
	movs r0, #0xf0
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r3, #0x90
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r3, #3
_080B3D30:
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	ldr r0, [r2]
	ands r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _080B3D30
	adds r0, r7, #0
	bl solar_bank_080b3a10
	movs r2, #2
	rsbs r2, r2, #0
	movs r0, #0xa7
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r3, #1
_080B3D58:
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r1, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080B3D58
	movs r4, #0
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, _080B3DBC @ =0x0000013D
	bl FUN_0822b20c
	ldr r3, _080B3DC0 @ =0x000005AC
	adds r0, r7, r3
	movs r1, #0xa0
	lsls r1, r1, #1
	bl FUN_0822b20c
	movs r0, #2
	bl FUN_08047a28
	ldr r1, _080B3DC4 @ =0x000005E2
	adds r0, r7, r1
	strh r4, [r0]
	ldr r3, _080B3DC8 @ =0x000005E4
	adds r0, r7, r3
	strh r4, [r0]
	adds r1, #4
	adds r0, r7, r1
	strh r4, [r0]
	adds r3, #4
	adds r0, r7, r3
	strh r4, [r0]
	subs r1, #6
	adds r0, r7, r1
	strh r4, [r0]
	ldr r1, _080B3DCC @ =solar_bank_080b3f38
	adds r0, r7, #0
	bl FUN_080b3b5c
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B3DB4: .4byte 0x030046A0
_080B3DB8: .4byte 0x000005D4
_080B3DBC: .4byte 0x0000013D
_080B3DC0: .4byte 0x000005AC
_080B3DC4: .4byte 0x000005E2
_080B3DC8: .4byte 0x000005E4
_080B3DCC: .4byte solar_bank_080b3f38

	thumb_func_start FUN_080b3dd0
FUN_080b3dd0: @ 0x080B3DD0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #2
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r4, #0
	bl FUN_080b3b24
	ldr r0, _080B3E34 @ =0x000002BF
	bl PlaySound_082406e0
	ldr r0, [r4, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	str r5, [sp]
	movs r2, #2
	movs r3, #2
	bl FUN_082370cc
	movs r0, #3
	bl FUN_08047a28
	ldr r1, _080B3E38 @ =FUN_080b4334
	adds r0, r4, #0
	bl FUN_080b3b5c
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B3E34: .4byte 0x000002BF
_080B3E38: .4byte FUN_080b4334

	thumb_func_start FUN_080b3e3c
FUN_080b3e3c: @ 0x080B3E3C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080B3E78 @ =0x000005EC
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x20
	bne _080B3E50
	ldr r0, _080B3E7C @ =0x000002BE
	bl PlaySound_082406e0
_080B3E50:
	adds r0, r5, #0
	adds r0, #0x58
	adds r1, r5, #0
	adds r1, #0x18
	bl FUN_082372cc
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x68
	bls _080B3E70
	adds r0, r5, #0
	bl FUN_080b3c08
_080B3E70:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B3E78: .4byte 0x000005EC
_080B3E7C: .4byte 0x000002BE

	thumb_func_start FUN_080b3e80
FUN_080b3e80: @ 0x080B3E80
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _080B3EAC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B3EB4
	ldr r1, _080B3EB0 @ =0x000005EA
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080B3EC0
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b3c98
	b _080B3F24
	.align 2, 0
_080B3EAC: .4byte 0x030044E0
_080B3EB0: .4byte 0x000005EA
_080B3EB4:
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _080B3ECE
_080B3EC0:
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b3dd0
	b _080B3F24
_080B3ECE:
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _080B3F18
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _080B3F00 @ =0x000005EA
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080B3F04
	adds r0, r4, #0
	adds r0, #0xb8
	adds r1, r4, #0
	adds r1, #0x38
	str r5, [sp]
	movs r2, #4
	b _080B3F10
	.align 2, 0
_080B3F00: .4byte 0x000005EA
_080B3F04:
	adds r0, r4, #0
	adds r0, #0xb8
	adds r1, r4, #0
	adds r1, #0x38
	str r2, [sp]
	movs r2, #5
_080B3F10:
	movs r3, #1
	bl FUN_082370cc
	b _080B3F24
_080B3F18:
	adds r0, r4, #0
	adds r0, #0xb8
	adds r1, r4, #0
	adds r1, #0x38
	bl FUN_082372cc
_080B3F24:
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	bl FUN_082372cc
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start solar_bank_080b3f38
solar_bank_080b3f38: @ 0x080B3F38
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r3, _080B3F84 @ =0x030044E0
	ldrh r1, [r3, #2]
	movs r0, #1
	mov sb, r0
	ands r0, r1
	cmp r0, #0
	beq _080B3F90
	ldr r2, _080B3F88 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r3, #0xbb
	lsls r3, r3, #3
	adds r1, r5, r3
	ldr r1, [r1]
	str r1, [r0]
	ldr r0, [r2]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r2, _080B3F8C @ =0x000005D4
	adds r1, r5, r2
	ldr r1, [r1]
	strh r1, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080b3dd0
	b _080B3FA8
	.align 2, 0
_080B3F84: .4byte 0x030044E0
_080B3F88: .4byte 0x030046A0
_080B3F8C: .4byte 0x000005D4
_080B3F90:
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080B3FAE
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080b3c08
_080B3FA8:
	adds r1, r5, #0
	adds r1, #0x18
	b _080B4318
_080B3FAE:
	ldrh r1, [r3]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _080B3FBA
	b _080B40BC
_080B3FBA:
	movs r3, #0xbb
	lsls r3, r3, #3
	adds r6, r5, r3
	ldr r1, [r6]
	ldr r0, _080B4030 @ =0x0000270E
	cmp r1, r0
	bls _080B3FCA
	b _080B41F4
_080B3FCA:
	ldr r0, _080B4034 @ =0x000005D4
	adds r4, r5, r0
	ldr r0, [r4]
	cmp r0, #0
	bne _080B3FD6
	b _080B41F4
_080B3FD6:
	ldr r1, _080B4038 @ =0x000005E2
	adds r7, r5, r1
	ldrh r0, [r7]
	cmp r0, #0
	bne _080B3FE6
	adds r3, #0xc
	adds r0, r5, r3
	strh r2, [r0]
_080B3FE6:
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r0, r5, r1
	strh r2, [r0]
	ldr r2, _080B403C @ =0x000005E6
	adds r2, r2, r5
	mov r8, r2
	movs r0, #0x10
	strh r0, [r2]
	ldrh r1, [r7]
	adds r0, r1, #0
	cmp r0, #0x7f
	bls _080B4070
	ldr r0, _080B4040 @ =0x0000037D
	bl PlaySound_082406e0
	movs r7, #0xa
	ldr r0, [r4]
	cmp r0, #0xa
	bhs _080B4010
	adds r7, r0, #0
_080B4010:
	movs r2, #0xa
	ldr r1, [r6]
	adds r0, r1, #0
	adds r0, #0xa
	ldr r3, _080B4044 @ =0x0000270F
	cmp r0, r3
	bls _080B4020
	subs r2, r3, r1
_080B4020:
	cmp r7, r2
	bge _080B4048
	adds r0, r1, r7
	str r0, [r6]
	ldr r0, [r4]
	subs r0, r0, r7
	b _080B4050
	.align 2, 0
_080B4030: .4byte 0x0000270E
_080B4034: .4byte 0x000005D4
_080B4038: .4byte 0x000005E2
_080B403C: .4byte 0x000005E6
_080B4040: .4byte 0x0000037D
_080B4044: .4byte 0x0000270F
_080B4048:
	adds r0, r1, r2
	str r0, [r6]
	ldr r0, [r4]
	subs r0, r0, r2
_080B4050:
	str r0, [r4]
	adds r0, r5, #0
	bl solar_bank_080b3a10
	ldr r3, _080B4068 @ =0x000005E4
	adds r1, r5, r3
	movs r0, #2
	strh r0, [r1]
	ldr r0, _080B406C @ =0x000005E6
	adds r1, r5, r0
	b _080B4174
	.align 2, 0
_080B4068: .4byte 0x000005E4
_080B406C: .4byte 0x000005E6
_080B4070:
	cmp r0, #0x3f
	bls _080B4094
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080B4082
	ldr r0, _080B4090 @ =0x0000037D
	bl PlaySound_082406e0
_080B4082:
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
	b _080B41A2
	.align 2, 0
_080B4090: .4byte 0x0000037D
_080B4094:
	adds r0, r1, #1
	strh r0, [r7]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	beq _080B40A2
	b _080B420A
_080B40A2:
	ldr r0, _080B40B8 @ =0x0000037D
	bl PlaySound_082406e0
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
	b _080B41E6
	.align 2, 0
_080B40B8: .4byte 0x0000037D
_080B40BC:
	movs r2, #0x10
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _080B40CC
	b _080B4204
_080B40CC:
	movs r1, #0xbb
	lsls r1, r1, #3
	adds r6, r5, r1
	ldr r0, [r6]
	cmp r0, #0
	bne _080B40DA
	b _080B41F4
_080B40DA:
	ldr r3, _080B4140 @ =0x000005D4
	adds r4, r5, r3
	ldr r1, [r4]
	ldr r0, _080B4144 @ =0x0000270E
	cmp r1, r0
	bls _080B40E8
	b _080B41F4
_080B40E8:
	ldr r0, _080B4148 @ =0x000005E2
	adds r7, r5, r0
	ldrh r1, [r7]
	cmp r1, #0
	bne _080B40F8
	adds r3, #0x10
	adds r0, r5, r3
	strh r1, [r0]
_080B40F8:
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r0, r5, r1
	mov r3, sb
	strh r3, [r0]
	ldr r0, _080B414C @ =0x000005E6
	adds r0, r0, r5
	mov r8, r0
	strh r2, [r0]
	ldrh r1, [r7]
	adds r0, r1, #0
	cmp r0, #0x7f
	bls _080B4184
	ldr r0, _080B4150 @ =0x0000037D
	bl PlaySound_082406e0
	movs r7, #0xa
	ldr r0, [r6]
	cmp r0, #0xa
	bhs _080B4122
	adds r7, r0, #0
_080B4122:
	movs r2, #0xa
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0xa
	ldr r3, _080B4154 @ =0x0000270F
	cmp r0, r3
	bls _080B4132
	subs r2, r3, r1
_080B4132:
	cmp r7, r2
	bge _080B4158
	adds r0, r1, r7
	str r0, [r4]
	ldr r0, [r6]
	subs r0, r0, r7
	b _080B4160
	.align 2, 0
_080B4140: .4byte 0x000005D4
_080B4144: .4byte 0x0000270E
_080B4148: .4byte 0x000005E2
_080B414C: .4byte 0x000005E6
_080B4150: .4byte 0x0000037D
_080B4154: .4byte 0x0000270F
_080B4158:
	adds r0, r1, r2
	str r0, [r4]
	ldr r0, [r6]
	subs r0, r0, r2
_080B4160:
	str r0, [r6]
	adds r0, r5, #0
	bl solar_bank_080b3a10
	ldr r2, _080B417C @ =0x000005E4
	adds r1, r5, r2
	movs r0, #2
	strh r0, [r1]
	ldr r3, _080B4180 @ =0x000005E6
	adds r1, r5, r3
_080B4174:
	movs r0, #4
	strh r0, [r1]
	b _080B420A
	.align 2, 0
_080B417C: .4byte 0x000005E4
_080B4180: .4byte 0x000005E6
_080B4184:
	cmp r0, #0x3f
	bls _080B41C8
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080B4196
	ldr r0, _080B41C0 @ =0x0000037D
	bl PlaySound_082406e0
_080B4196:
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	ldr r0, [r6]
	subs r0, #1
	str r0, [r6]
_080B41A2:
	adds r0, r5, #0
	bl solar_bank_080b3a10
	ldr r1, _080B41C4 @ =0x000005E4
	adds r0, r5, r1
	mov r2, sb
	strh r2, [r0]
	movs r0, #4
	mov r3, r8
	strh r0, [r3]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	b _080B420A
	.align 2, 0
_080B41C0: .4byte 0x0000037D
_080B41C4: .4byte 0x000005E4
_080B41C8:
	adds r0, r1, #1
	strh r0, [r7]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080B420A
	ldr r0, _080B41F0 @ =0x0000037D
	bl PlaySound_082406e0
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	ldr r0, [r6]
	subs r0, #1
	str r0, [r6]
_080B41E6:
	adds r0, r5, #0
	bl solar_bank_080b3a10
	b _080B420A
	.align 2, 0
_080B41F0: .4byte 0x0000037D
_080B41F4:
	ldr r0, _080B4200 @ =0x000005E2
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	b _080B420A
	.align 2, 0
_080B4200: .4byte 0x000005E2
_080B4204:
	ldr r2, _080B422C @ =0x000005E2
	adds r0, r5, r2
	strh r1, [r0]
_080B420A:
	ldr r3, _080B4230 @ =0x000005E6
	adds r0, r5, r3
	ldrh r1, [r0]
	cmp r1, #0
	beq _080B4264
	ldr r1, _080B4234 @ =0x000005E4
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne _080B4238
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #4
	b _080B4252
	.align 2, 0
_080B422C: .4byte 0x000005E2
_080B4230: .4byte 0x000005E6
_080B4234: .4byte 0x000005E4
_080B4238:
	cmp r0, #1
	bne _080B4248
	movs r3, #0xbc
	lsls r3, r3, #3
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #2
	b _080B4252
_080B4248:
	movs r0, #0xbc
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
_080B4252:
	strh r0, [r1]
	ldr r2, _080B4260 @ =0x000005E6
	adds r1, r5, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _080B426C
	.align 2, 0
_080B4260: .4byte 0x000005E6
_080B4264:
	movs r3, #0xbc
	lsls r3, r3, #3
	adds r0, r5, r3
	strh r1, [r0]
_080B426C:
	movs r1, #0xbc
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne _080B42B0
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, _080B42A8 @ =0x0000013D
	bl FUN_0822b20c
	ldr r3, _080B42AC @ =0x000005AC
	adds r0, r5, r3
	movs r1, #0xa0
	lsls r1, r1, #1
	bl FUN_0822b20c
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, r4, #0
	movs r2, #0x12
	movs r3, #1
	bl Sprite_SetSprite
	b _080B4316
	.align 2, 0
_080B42A8: .4byte 0x0000013D
_080B42AC: .4byte 0x000005AC
_080B42B0:
	movs r0, #0x1f
	ands r0, r1
	lsrs r0, r0, #3
	cmp r0, #1
	beq _080B42CA
	cmp r0, #1
	bgt _080B42C4
	cmp r0, #0
	beq _080B42CE
	b _080B42D2
_080B42C4:
	cmp r0, #2
	beq _080B42CE
	b _080B42D2
_080B42CA:
	movs r6, #2
	b _080B42D4
_080B42CE:
	movs r6, #1
	b _080B42D4
_080B42D2:
	movs r6, #0
_080B42D4:
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, _080B432C @ =0x0000013D
	adds r1, r6, r3
	bl FUN_0822b20c
	ldr r1, _080B4330 @ =0x000005AC
	adds r0, r5, r1
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r1, r6, r1
	bl FUN_0822b20c
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r4, r5, #0
	adds r4, #0x18
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r1, r5, r3
	ldrh r1, [r1]
	lsls r2, r1, #1
	adds r2, r2, r1
	adds r2, #0x13
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
_080B4316:
	adds r1, r4, #0
_080B4318:
	adds r0, r5, #0
	adds r0, #0x58
	bl FUN_082372cc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B432C: .4byte 0x0000013D
_080B4330: .4byte 0x000005AC

	thumb_func_start FUN_080b4334
FUN_080b4334: @ 0x080B4334
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	bl FUN_082372cc
	ldr r0, _080B4380 @ =0x000005EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _080B4376
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B4384 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080B4388 @ =FUN_080b438c
	adds r0, r4, #0
	bl FUN_080b3b5c
_080B4376:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B4380: .4byte 0x000005EC
_080B4384: .4byte 0x0000FFFF
_080B4388: .4byte FUN_080b438c

	thumb_func_start FUN_080b438c
FUN_080b438c: @ 0x080B438C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B43C0 @ =0x000005EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080B43B8
	ldr r1, _080B43C4 @ =0x000005DC
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080B43B8
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
_080B43B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B43C0: .4byte 0x000005EC
_080B43C4: .4byte 0x000005DC

	thumb_func_start FUN_080b43c8
FUN_080b43c8: @ 0x080B43C8
	push {lr}
	movs r2, #0xbe
	lsls r2, r2, #3
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_080b43dc
FUN_080b43dc: @ 0x080B43DC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x58
	movs r5, #0xc
_080B43E6:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B43E6
	movs r0, #0xa7
	lsls r0, r0, #3
	adds r4, r6, r0
	movs r5, #1
_080B43FC:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _080B43FC
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080b4414
FUN_080b4414: @ 0x080B4414
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080B444C @ =0x0000C091
	ldr r1, _080B4450 @ =0x000083C0
	bl GetFile
	adds r2, r0, #0
	movs r0, #0xb9
	lsls r0, r0, #3
	adds r4, r4, r0
	str r2, [r4]
	movs r0, #0
	str r0, [sp, #0xc]
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B444C: .4byte 0x0000C091
_080B4450: .4byte 0x000083C0

	thumb_func_start FUN_080b4454
FUN_080b4454: @ 0x080B4454
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B447C @ =0x000092B3
	ldr r1, _080B4480 @ =0x0000EAA8
	bl GetFile
	ldr r1, _080B4484 @ =0x000005CC
	adds r4, r4, r1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, _080B4488 @ =0x030043F0
	ldr r2, _080B448C @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B447C: .4byte 0x000092B3
_080B4480: .4byte 0x0000EAA8
_080B4484: .4byte 0x000005CC
_080B4488: .4byte 0x030043F0
_080B448C: .4byte 0x04000018

	thumb_func_start FUN_080b4490
FUN_080b4490: @ 0x080B4490
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	ldr r4, _080B4710 @ =0x0000CB05
	ldr r1, _080B4714 @ =0x000092F0
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	mov r1, r8
	adds r1, #0x18
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	mov r6, r8
	adds r6, #0x18
	adds r0, r6, #0
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080B4718 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	mov r1, r8
	adds r1, #0x38
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	mov r7, r8
	adds r7, #0x38
	adds r0, r7, #0
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080B471C @ =0xFFFF0000
	movs r5, #0
	str r5, [sp, #0x10]
	mov r0, sp
	adds r0, #0x10
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	mov r0, r8
	adds r0, #0x58
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	mov sl, r1
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r4, _080B4720 @ =0x030046A0
	ldr r0, [r4]
	ldr r3, _080B4724 @ =0x0000023A
	mov sb, r3
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080B4550
	bl GetSecond
	adds r1, r0, #0
	ldr r0, [r4]
	movs r2, #0xad
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	eors r0, r1
	movs r1, #0xd
	bl Mod
	ldr r1, [r4]
	ldr r3, _080B4724 @ =0x0000023A
	adds r1, r1, r3
	adds r0, #0x41
	strh r0, [r1]
_080B4550:
	ldr r0, [r4]
	add r0, sb
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x64
	adds r4, r1, #0
	muls r4, r0, r4
	asrs r4, r4, #6
	subs r4, #0x64
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	adds r2, r0, #0
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	subs r4, r4, r0
	movs r0, #0x8c
	lsls r0, r0, #1
	add r0, r8
	adds r2, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r5, [sp]
	str r5, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r1, r6, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	ldrh r0, [r0]
	adds r0, #8
	add r1, sp, #0x10
	strh r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	add r0, r8
	adds r4, #8
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r5, [sp]
	str r5, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	adds r2, r4, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r5, [r0]
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, r8
	str r5, [sp]
	str r5, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x12
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, _080B4728 @ =0x0000FFF8
	ldr r6, [sp, #0x18]
	strh r0, [r6, #2]
	mov r0, r8
	adds r0, #0xb8
	str r5, [sp]
	str r5, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r7, #0
	movs r2, #0x94
	movs r3, #0x10
	bl FUN_0822f3fc
	movs r1, #0x28
	add r0, sp, #0x10
	strh r1, [r0]
	strh r1, [r6, #2]
	mov sb, r7
	adds r5, r0, #0
	movs r4, #0x8e
	lsls r4, r4, #2
	add r4, r8
	movs r6, #0
	movs r7, #3
_080B4616:
	str r6, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r5]
	adds r0, #8
	strh r0, [r5]
	adds r4, #0x60
	subs r7, #1
	cmp r7, #0
	bge _080B4616
	movs r1, #0x88
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x28
	strh r0, [r1, #2]
	adds r5, r1, #0
	movs r4, #0xee
	lsls r4, r4, #2
	add r4, r8
	movs r6, #0
	movs r7, #3
_080B4652:
	str r6, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r5]
	adds r0, #8
	strh r0, [r5]
	adds r4, #0x60
	subs r7, #1
	cmp r7, #0
	bge _080B4652
	movs r7, #0
	movs r3, #0xa7
	lsls r3, r3, #3
	add r3, r8
	mov sb, r3
	movs r4, #0x38
	mov sl, r4
	movs r6, #0xb2
	lsls r6, r6, #3
	add r6, r8
_080B468A:
	adds r0, r6, #0
	ldr r1, _080B472C @ =0x0000A47C
	bl FUN_0822b16c
	movs r0, #0x2c
	adds r4, r7, #0
	muls r4, r0, r4
	movs r5, #0xa7
	lsls r5, r5, #3
	adds r0, r4, r5
	add r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822a470
	mov r0, r8
	adds r5, r0, r4
	ldr r1, _080B4730 @ =0x0000053F
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	add r4, sb
	movs r0, #0x30
	str r0, [r4]
	cmp r7, #0
	bne _080B46C8
	mov r3, sb
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
_080B46C8:
	cmp r7, #1
	bne _080B46D8
	ldr r0, _080B4734 @ =0x000005AC
	add r0, r8
	movs r1, #0xa0
	lsls r1, r1, #1
	bl FUN_0822b20c
_080B46D8:
	ldr r4, _080B4738 @ =0x00000554
	adds r0, r5, r4
	mov r1, sl
	strh r1, [r0]
	ldr r2, _080B473C @ =0x00000556
	adds r1, r5, r2
	movs r0, #0x58
	strh r0, [r1]
	movs r3, #0xab
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r4, #0
	strh r4, [r0]
	movs r5, #0x60
	add sl, r5
	adds r6, #0x1c
	adds r7, #1
	cmp r7, #1
	ble _080B468A
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B4710: .4byte 0x0000CB05
_080B4714: .4byte 0x000092F0
_080B4718: .4byte 0x0000B343
_080B471C: .4byte 0xFFFF0000
_080B4720: .4byte 0x030046A0
_080B4724: .4byte 0x0000023A
_080B4728: .4byte 0x0000FFF8
_080B472C: .4byte 0x0000A47C
_080B4730: .4byte 0x0000053F
_080B4734: .4byte 0x000005AC
_080B4738: .4byte 0x00000554
_080B473C: .4byte 0x00000556

	thumb_func_start FUN_080b4740
FUN_080b4740: @ 0x080B4740
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080B475A
	bl FUN_0823d340
	movs r2, #0xba
	lsls r2, r2, #3
	adds r1, r4, r2
	str r0, [r1]
_080B475A:
	ldr r0, _080B4784 @ =0x0000EAA8
	bl FUN_08047dc0
	movs r1, #0xba
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_080478f0
	movs r0, #1
	movs r1, #0xf
	movs r2, #0x1c
	movs r3, #4
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B4784: .4byte 0x0000EAA8

	thumb_func_start FUN_080b4788
FUN_080b4788: @ 0x080B4788
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080b4414
	adds r0, r4, #0
	bl FUN_080b4454
	adds r0, r4, #0
	bl FUN_080b4490
	adds r0, r4, #0
	bl FUN_080b4740
	movs r0, #0x65
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080B47C0
	bl Script_GetValue
	ldr r2, _080B47BC @ =0x000005DC
	adds r1, r4, r2
	str r0, [r1]
	b _080B47C6
	.align 2, 0
_080B47BC: .4byte 0x000005DC
_080B47C0:
	ldr r2, _080B47D4 @ =0x000005DC
	adds r0, r4, r2
	str r1, [r0]
_080B47C6:
	adds r0, r4, #0
	bl FUN_080b3b74
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B47D4: .4byte 0x000005DC

	thumb_func_start FUN_080b47d8
FUN_080b47d8: @ 0x080B47D8
	push {r4, lr}
	ldr r1, _080B4804 @ =0x000005F4
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080B4810
	ldr r1, _080B4808 @ =FUN_080b43c8
	ldr r2, _080B480C @ =FUN_080b43dc
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080b4788
	cmp r0, #0
	bge _080B4810
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080B4812
	.align 2, 0
_080B4804: .4byte 0x000005F4
_080B4808: .4byte FUN_080b43c8
_080B480C: .4byte FUN_080b43dc
_080B4810:
	adds r0, r4, #0
_080B4812:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b4818
FUN_080b4818: @ 0x080B4818
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _080B4850 @ =0x030046A0
	ldr r1, [r0]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r2, _080B4854 @ =0x0000082E
	adds r0, r5, r2
	ldrh r2, [r0]
	ldr r3, _080B4858 @ =0x0000082C
	adds r0, r5, r3
	ldrh r0, [r0]
	muls r2, r0, r2
	ldr r0, [r1]
	adds r4, r0, r2
	cmp r4, #0
	bne _080B485C
	adds r6, r5, #0
	adds r6, #0x38
	movs r1, #0
	add r0, sp, #0xc
_080B4846:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _080B4846
	b _080B489C
	.align 2, 0
_080B4850: .4byte 0x030046A0
_080B4854: .4byte 0x0000082E
_080B4858: .4byte 0x0000082C
_080B485C:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
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
	subs r1, r4, r1
	str r1, [sp, #0xc]
	adds r6, r5, #0
	adds r6, #0x38
_080B489C:
	mov r7, sp
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r5, #3
_080B48A6:
	ldm r7!, {r2}
	adds r2, #0x14
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B48A6
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start dark_loans_080b48c8
dark_loans_080b48c8: @ 0x080B48C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	ldr r1, _080B48FC @ =0x0000082E
	adds r0, r7, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _080B4900
	adds r2, r7, #0
	adds r2, #0x60
	str r2, [sp, #0x10]
	movs r0, #0x18
	adds r0, r0, r7
	mov sl, r0
	movs r1, #0
	add r0, sp, #0xc
_080B48F0:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _080B48F0
	b _080B4948
	.align 2, 0
_080B48FC: .4byte 0x0000082E
_080B4900:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
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
	subs r1, r4, r1
	str r1, [sp, #0xc]
	adds r1, r7, #0
	adds r1, #0x60
	str r1, [sp, #0x10]
	movs r2, #0x18
	adds r2, r2, r7
	mov sl, r2
_080B4948:
	mov sb, sp
	movs r0, #0x83
	lsls r0, r0, #3
	adds r5, r7, r0
	ldr r1, [sp, #0x10]
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r4, r1, r2
	movs r6, #3
_080B495A:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	mov r8, r1
	ands r0, r1
	str r0, [r4]
	mov r0, sb
	adds r0, #4
	mov sb, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r2, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	mov r1, sl
	movs r3, #1
	bl Sprite_SetSprite
	adds r5, #0x60
	adds r4, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080B495A
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, [r1]
	mov r2, r8
	ands r0, r2
	str r0, [r1]
	ldr r1, _080B49BC @ =0x0000082E
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _080B49C0 @ =0x0000082C
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r4, r1, #0
	muls r4, r0, r4
	cmp r4, #0
	bne _080B49C4
	movs r1, #0
	add r0, sp, #0xc
_080B49B0:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _080B49B0
	b _080B4A00
	.align 2, 0
_080B49BC: .4byte 0x0000082E
_080B49C0: .4byte 0x0000082C
_080B49C4:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
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
	subs r1, r4, r1
	str r1, [sp, #0xc]
_080B4A00:
	mov r8, sp
	movs r0, #0xbf
	lsls r0, r0, #3
	adds r5, r7, r0
	ldr r1, [sp, #0x10]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r4, r1, r2
	movs r6, #3
_080B4A12:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r0, r8
	adds r0, #4
	mov r8, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r2, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	mov r1, sl
	movs r3, #1
	bl Sprite_SetSprite
	adds r5, #0x60
	adds r4, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080B4A12
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b4a50
FUN_080b4a50: @ 0x080B4A50
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B4A70 @ =0x030046A0
	ldr r2, [r0]
	ldr r0, _080B4A74 @ =0x0000082E
	adds r1, r4, r0
	movs r3, #0x2c
	ldrsh r0, [r2, r3]
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0x2e
	ldrsh r2, [r2, r1]
	cmp r0, #0
	bne _080B4A78
	movs r3, #0
	b _080B4A8A
	.align 2, 0
_080B4A70: .4byte 0x030046A0
_080B4A74: .4byte 0x0000082E
_080B4A78:
	subs r1, r0, #1
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	subs r1, r2, #1
	bl Div
	adds r3, r0, #1
_080B4A8A:
	movs r0, #0xf0
	lsls r0, r0, #3
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r3, #0
	subs r1, #0x98
	movs r2, #0xf3
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	ldr r3, _080B4AB4 @ =0x0000079A
	adds r1, r4, r3
	ldr r0, _080B4AB8 @ =0x0000FFD8
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B4AB4: .4byte 0x0000079A
_080B4AB8: .4byte 0x0000FFD8

	thumb_func_start FUN_080b4abc
FUN_080b4abc: @ 0x080B4ABC
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #1
	adds r1, r3, #0
	adds r1, #0x60
	movs r2, #0x13
_080B4AC8:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080B4AC8
	movs r1, #0xfb
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b4aec
FUN_080b4aec: @ 0x080B4AEC
	ldr r3, _080B4AFC @ =0x0000084C
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080B4B00 @ =0x00000844
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080B4AFC: .4byte 0x0000084C
_080B4B00: .4byte 0x00000844

	thumb_func_start FUN_080b4b04
FUN_080b4b04: @ 0x080B4B04
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r6, #0
	bl FUN_080b4abc
	ldr r0, [r6, #0x60]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0x58
	adds r1, r6, #0
	adds r1, #0x18
	str r5, [sp]
	movs r2, #4
	movs r3, #2
	bl FUN_082370cc
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0
	bl FUN_08047a28
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B4B9C @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080B4BA0 @ =FUN_080b4f08
	adds r0, r6, #0
	bl FUN_080b4aec
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B4B9C: .4byte 0x0000FFFF
_080B4BA0: .4byte FUN_080b4f08

	thumb_func_start FUN_080b4ba4
FUN_080b4ba4: @ 0x080B4BA4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r6, #0
	bl FUN_080b4abc
	ldr r0, [r6, #0x60]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0x58
	adds r1, r6, #0
	adds r1, #0x18
	str r5, [sp]
	movs r2, #7
	movs r3, #2
	bl FUN_082370cc
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	ldr r0, _080B4C50 @ =0x00000842
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	adds r1, r6, #0
	adds r1, #0xc0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	subs r1, #0x88
	str r5, [sp]
	movs r2, #4
	movs r3, #1
	bl FUN_082370cc
	movs r0, #1
	bl FUN_08047a28
	ldr r1, _080B4C54 @ =0x0000082E
	adds r0, r6, r1
	strh r5, [r0]
	ldr r1, _080B4C58 @ =FUN_080b4f48
	adds r0, r6, #0
	bl FUN_080b4aec
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B4C50: .4byte 0x00000842
_080B4C54: .4byte 0x0000082E
_080B4C58: .4byte FUN_080b4f48

	thumb_func_start FUN_080b4c5c
FUN_080b4c5c: @ 0x080B4C5C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #4
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r7, #0
	bl FUN_080b4abc
	ldr r0, [r7, #0x60]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r7, #0x60]
	adds r0, r7, #0
	adds r0, #0x58
	adds r6, r7, #0
	adds r6, #0x18
	str r5, [sp]
	adds r1, r6, #0
	movs r2, #5
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0x90
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r7, r1
	adds r1, r6, #0
	movs r2, #0x12
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _080B4D80 @ =0x0000082E
	adds r0, r7, r1
	strh r5, [r0]
	adds r6, #0x48
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #3
_080B4CD2:
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B4CD2
	adds r0, r7, #0
	bl FUN_080b4818
	adds r0, r7, #0
	bl FUN_080b4a50
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r2, r7, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r3, r6, r3
	movs r0, #0xf0
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r5, #3
_080B4D06:
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	adds r3, #0x60
	adds r2, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B4D06
	movs r4, #0
	adds r0, r7, #0
	bl dark_loans_080b48c8
	ldr r1, _080B4D84 @ =0x00000848
	adds r0, r7, r1
	strh r4, [r0]
	adds r1, #2
	adds r0, r7, r1
	strh r4, [r0]
	movs r0, #0xfb
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080B4D88 @ =0x00000804
	adds r0, r7, r1
	ldr r1, _080B4D8C @ =0x00000143
	bl FUN_0822b20c
	movs r0, #4
	bl FUN_08047a28
	ldr r1, _080B4D90 @ =0x0000083A
	adds r0, r7, r1
	strh r4, [r0]
	adds r1, #2
	adds r0, r7, r1
	strh r4, [r0]
	adds r1, #2
	adds r0, r7, r1
	strh r4, [r0]
	adds r1, #2
	adds r0, r7, r1
	strh r4, [r0]
	subs r1, #8
	adds r0, r7, r1
	strh r4, [r0]
	ldr r1, _080B4D94 @ =dark_loans_080b5020
	adds r0, r7, #0
	bl FUN_080b4aec
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B4D80: .4byte 0x0000082E
_080B4D84: .4byte 0x00000848
_080B4D88: .4byte 0x00000804
_080B4D8C: .4byte 0x00000143
_080B4D90: .4byte 0x0000083A
_080B4D94: .4byte dark_loans_080b5020

	thumb_func_start FUN_080b4d98
FUN_080b4d98: @ 0x080B4D98
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #5
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r4, #0
	bl FUN_080b4abc
	ldr r0, _080B4DFC @ =0x000002C1
	bl PlaySound_082406e0
	ldr r0, [r4, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	str r5, [sp]
	movs r2, #6
	movs r3, #2
	bl FUN_082370cc
	movs r0, #3
	bl FUN_08047a28
	ldr r1, _080B4E00 @ =FUN_080b539c
	adds r0, r4, #0
	bl FUN_080b4aec
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B4DFC: .4byte 0x000002C1
_080B4E00: .4byte FUN_080b539c

	thumb_func_start FUN_080b4e04
FUN_080b4e04: @ 0x080B4E04
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #5
	bl FUN_0822c398
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r4, #0
	bl FUN_080b4abc
	ldr r0, [r4, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x60]
	ldr r0, _080B4E54 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #3
	bgt _080B4E58
	movs r0, #9
	bl FUN_08047a28
	b _080B4E76
	.align 2, 0
_080B4E54: .4byte 0x030046A0
_080B4E58:
	cmp r0, #5
	bgt _080B4E64
	movs r0, #0xa
	bl FUN_08047a28
	b _080B4E76
_080B4E64:
	cmp r0, #7
	bgt _080B4E70
	movs r0, #0xb
	bl FUN_08047a28
	b _080B4E76
_080B4E70:
	movs r0, #0xc
	bl FUN_08047a28
_080B4E76:
	ldr r1, _080B4E88 @ =0x080B54A1
	adds r0, r4, #0
	bl FUN_080b4aec
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B4E88: .4byte 0x080B54A1

	thumb_func_start FUN_080b4e8c
FUN_080b4e8c: @ 0x080B4E8C
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #5
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r4, #0
	bl FUN_080b4abc
	ldr r0, [r4, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	str r5, [sp]
	movs r2, #6
	movs r3, #2
	bl FUN_082370cc
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B4F00 @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #0xd
	bl FUN_08047a28
	ldr r1, _080B4F04 @ =FUN_080b5528
	adds r0, r4, #0
	bl FUN_080b4aec
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B4F00: .4byte 0x0000FFFF
_080B4F04: .4byte FUN_080b5528

	thumb_func_start FUN_080b4f08
FUN_080b4f08: @ 0x080B4F08
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x58
	adds r1, r5, #0
	adds r1, #0x18
	bl FUN_082372cc
	ldr r0, _080B4F44 @ =0x00000844
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x20
	bne _080B4F28
	movs r0, #0xb0
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080B4F28:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x68
	bls _080B4F3C
	adds r0, r5, #0
	bl FUN_080b4ba4
_080B4F3C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B4F44: .4byte 0x00000844

	thumb_func_start FUN_080b4f48
FUN_080b4f48: @ 0x080B4F48
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	bl FUN_082372cc
	ldr r0, _080B4F7C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B4F84
	ldr r1, _080B4F80 @ =0x00000842
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080B4F90
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b4c5c
	b _080B4FF4
	.align 2, 0
_080B4F7C: .4byte 0x030044E0
_080B4F80: .4byte 0x00000842
_080B4F84:
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _080B4F9E
_080B4F90:
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b4d98
	b _080B4FF4
_080B4F9E:
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _080B4FE8
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _080B4FD0 @ =0x00000842
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _080B4FD4
	adds r0, r4, #0
	adds r0, #0xb8
	adds r1, r4, #0
	adds r1, #0x38
	str r5, [sp]
	movs r2, #4
	b _080B4FE0
	.align 2, 0
_080B4FD0: .4byte 0x00000842
_080B4FD4:
	adds r0, r4, #0
	adds r0, #0xb8
	adds r1, r4, #0
	adds r1, #0x38
	str r3, [sp]
	movs r2, #5
_080B4FE0:
	movs r3, #1
	bl FUN_082370cc
	b _080B4FF4
_080B4FE8:
	adds r0, r4, #0
	adds r0, #0xb8
	adds r1, r4, #0
	adds r1, #0x38
	bl FUN_082372cc
_080B4FF4:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b4ffc
FUN_080b4ffc: @ 0x080B4FFC
	push {lr}
	asrs r0, r0, #2
	cmp r0, #1
	beq _080B5016
	cmp r0, #1
	ble _080B501A
	cmp r0, #2
	beq _080B5012
	cmp r0, #3
	beq _080B5016
	b _080B501A
_080B5012:
	movs r0, #2
	b _080B501C
_080B5016:
	movs r0, #1
	b _080B501C
_080B501A:
	movs r0, #0
_080B501C:
	pop {r1}
	bx r1

	thumb_func_start dark_loans_080b5020
dark_loans_080b5020: @ 0x080B5020
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r0, #0x58
	movs r1, #0x18
	adds r1, r1, r5
	mov r8, r1
	bl FUN_082372cc
	ldr r1, _080B5054 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080B50B4
	ldr r2, _080B5058 @ =0x0000082E
	adds r6, r5, r2
	ldrh r0, [r6]
	cmp r0, #0
	bne _080B505C
	movs r0, #0xde
	bl PlaySound_082406e0
	b _080B509E
	.align 2, 0
_080B5054: .4byte 0x030044E0
_080B5058: .4byte 0x0000082E
_080B505C:
	ldr r3, _080B50A8 @ =0x030046A0
	ldr r1, [r3]
	ldrh r7, [r1, #0x2c]
	adds r0, r0, r7
	strh r0, [r1, #0x2c]
	ldr r1, [r3]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrh r2, [r6]
	ldr r7, _080B50AC @ =0x0000082C
	adds r4, r5, r7
	ldrh r0, [r4]
	muls r2, r0, r2
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, [r3]
	movs r1, #0xea
	lsls r1, r1, #1
	adds r2, r0, r1
	ldrh r1, [r6]
	ldrh r0, [r4]
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	cmp r0, #0
	bge _080B5096
	ldr r0, _080B50B0 @ =0x7FFFFFFF
_080B5096:
	str r0, [r2]
	movs r0, #0xdd
	bl PlaySound_082406e0
_080B509E:
	adds r0, r5, #0
	bl FUN_080b4d98
	b _080B538C
	.align 2, 0
_080B50A8: .4byte 0x030046A0
_080B50AC: .4byte 0x0000082C
_080B50B0: .4byte 0x7FFFFFFF
_080B50B4:
	movs r0, #2
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _080B50D0
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080b4ba4
	b _080B538C
_080B50D0:
	ldrh r1, [r1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080B5198
	ldr r0, _080B5178 @ =0x030046A0
	ldr r3, [r0]
	movs r7, #0xe2
	lsls r7, r7, #1
	adds r2, r3, r7
	ldr r0, _080B517C @ =0x0000082E
	adds r4, r5, r0
	ldrh r6, [r4]
	adds r1, r6, #1
	ldr r7, _080B5180 @ =0x0000082C
	adds r0, r5, r7
	ldrh r0, [r0]
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	ldr r1, _080B5184 @ =0x0000270F
	cmp r0, r1
	bgt _080B5198
	movs r1, #0x2c
	ldrsh r0, [r3, r1]
	adds r0, r0, r6
	movs r2, #0x2e
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bge _080B5198
	ldr r0, _080B5188 @ =0x0000037D
	bl PlaySound_082406e0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	adds r0, r5, #0
	bl FUN_080b4818
	adds r0, r5, #0
	bl FUN_080b4a50
	adds r0, r5, #0
	bl dark_loans_080b48c8
	movs r3, #0x84
	lsls r3, r3, #4
	adds r4, r5, r3
	movs r0, #0x13
	strh r0, [r4]
	ldr r0, _080B518C @ =0x0000083E
	adds r7, r5, r0
	ldrh r0, [r7]
	bl FUN_080b4ffc
	adds r6, r0, #0
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r2, [r4]
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r1, r8
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _080B5190 @ =0x00000804
	adds r0, r5, r2
	ldr r3, _080B5194 @ =0x00000143
	adds r1, r6, r3
	bl FUN_0822b20c
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080B5172
	b _080B52BC
_080B5172:
	mov r0, sb
	strh r0, [r7]
	b _080B52BC
	.align 2, 0
_080B5178: .4byte 0x030046A0
_080B517C: .4byte 0x0000082E
_080B5180: .4byte 0x0000082C
_080B5184: .4byte 0x0000270F
_080B5188: .4byte 0x0000037D
_080B518C: .4byte 0x0000083E
_080B5190: .4byte 0x00000804
_080B5194: .4byte 0x00000143
_080B5198:
	ldr r0, _080B5228 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080B5244
	ldr r1, _080B522C @ =0x0000082E
	adds r4, r5, r1
	ldrh r0, [r4]
	cmp r0, #0
	beq _080B5244
	ldr r0, _080B5230 @ =0x0000037D
	bl PlaySound_082406e0
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	adds r0, r5, #0
	bl FUN_080b4818
	adds r0, r5, #0
	bl FUN_080b4a50
	adds r0, r5, #0
	bl dark_loans_080b48c8
	movs r2, #0x84
	lsls r2, r2, #4
	adds r4, r5, r2
	movs r0, #0x16
	strh r0, [r4]
	ldr r3, _080B5234 @ =0x0000083E
	adds r7, r5, r3
	ldrh r0, [r7]
	bl FUN_080b4ffc
	adds r6, r0, #0
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	ldrh r2, [r4]
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _080B5238 @ =0x00000804
	adds r0, r5, r2
	ldr r3, _080B523C @ =0x00000143
	adds r1, r6, r3
	bl FUN_0822b20c
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080B5218
	movs r0, #0
	strh r0, [r7]
_080B5218:
	ldr r7, _080B5240 @ =0x00000848
	adds r1, r5, r7
	ldrh r0, [r1]
	cmp r0, #0
	beq _080B52BC
	movs r0, #1
	strh r0, [r1]
	b _080B52BC
	.align 2, 0
_080B5228: .4byte 0x030044E0
_080B522C: .4byte 0x0000082E
_080B5230: .4byte 0x0000037D
_080B5234: .4byte 0x0000083E
_080B5238: .4byte 0x00000804
_080B523C: .4byte 0x00000143
_080B5240: .4byte 0x00000848
_080B5244:
	ldr r0, _080B5294 @ =0x0000083E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _080B52A0
	bl FUN_080b4ffc
	adds r6, r0, #0
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r3, #0x84
	lsls r3, r3, #4
	adds r2, r5, r3
	ldrh r2, [r2]
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
	ldr r7, _080B5298 @ =0x00000804
	adds r0, r5, r7
	ldr r2, _080B529C @ =0x00000143
	adds r1, r6, r2
	bl FUN_0822b20c
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080B52BC
	movs r0, #0
	strh r0, [r4]
	b _080B52BC
	.align 2, 0
_080B5294: .4byte 0x0000083E
_080B5298: .4byte 0x00000804
_080B529C: .4byte 0x00000143
_080B52A0:
	ldr r3, _080B5320 @ =0x00000804
	adds r0, r5, r3
	ldr r1, _080B5324 @ =0x00000143
	bl FUN_0822b20c
	movs r7, #0x8e
	lsls r7, r7, #2
	adds r0, r5, r7
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x12
	movs r3, #1
	bl Sprite_SetSprite
_080B52BC:
	ldr r0, _080B5328 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080B52F4
	ldr r0, _080B532C @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r2, r2, r0
	ldr r1, _080B5330 @ =0x0000082E
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r0, #1
	ldr r3, _080B5334 @ =0x0000082C
	adds r1, r5, r3
	ldrh r1, [r1]
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	ldr r1, _080B5338 @ =0x0000270F
	cmp r0, r1
	ble _080B52F4
	ldr r7, _080B533C @ =0x00000848
	adds r1, r5, r7
	movs r0, #0x3c
	strh r0, [r1]
_080B52F4:
	ldr r0, _080B533C @ =0x00000848
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080B538C
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _080B5344
	adds r0, r5, #0
	bl dark_loans_080b48c8
	movs r0, #4
	bl FUN_08047a28
	ldr r1, _080B5340 @ =0x0000084A
	adds r0, r5, r1
	strh r4, [r0]
	b _080B538C
	.align 2, 0
_080B5320: .4byte 0x00000804
_080B5324: .4byte 0x00000143
_080B5328: .4byte 0x030044E0
_080B532C: .4byte 0x030046A0
_080B5330: .4byte 0x0000082E
_080B5334: .4byte 0x0000082C
_080B5338: .4byte 0x0000270F
_080B533C: .4byte 0x00000848
_080B5340: .4byte 0x0000084A
_080B5344:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	movs r4, #1
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r2, r5, r3
	movs r7, #0x84
	lsls r7, r7, #3
	adds r1, r5, r7
	movs r3, #3
_080B5362:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _080B5362
	ldr r0, _080B5398 @ =0x0000084A
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080B538C
	movs r0, #6
	bl FUN_08047a28
	movs r0, #1
	strh r0, [r4]
_080B538C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B5398: .4byte 0x0000084A

	thumb_func_start FUN_080b539c
FUN_080b539c: @ 0x080B539C
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	bl FUN_082372cc
	ldr r0, _080B53E4 @ =0x00000844
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _080B5422
	ldr r1, _080B53E8 @ =0x0000082E
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0
	beq _080B5404
	movs r0, #5
	bl FUN_08047a28
	movs r1, #0x83
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080B53EC
	movs r1, #0
	bl Script_ExecById
	b _080B53F4
	.align 2, 0
_080B53E4: .4byte 0x00000844
_080B53E8: .4byte 0x0000082E
_080B53EC:
	movs r0, #0
	movs r1, #3
	bl FUN_08047c40
_080B53F4:
	ldr r1, _080B5400 @ =FUN_080b5434
	adds r0, r4, #0
	bl FUN_080b4aec
	b _080B5422
	.align 2, 0
_080B5400: .4byte FUN_080b5434
_080B5404:
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B542C @ =0x0000FFFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080B5430 @ =FUN_080b54ec
	adds r0, r4, #0
	bl FUN_080b4aec
_080B5422:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B542C: .4byte 0x0000FFFF
_080B5430: .4byte FUN_080b54ec

	thumb_func_start FUN_080b5434
FUN_080b5434: @ 0x080B5434
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, _080B5480 @ =0x00000844
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _080B5496
	ldr r0, _080B5484 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	bne _080B5490
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B5488 @ =0x0000FFFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080B548C @ =FUN_080b54ec
	adds r0, r4, #0
	bl FUN_080b4aec
	b _080B5496
	.align 2, 0
_080B5480: .4byte 0x00000844
_080B5484: .4byte 0x030046A0
_080B5488: .4byte 0x0000FFFF
_080B548C: .4byte FUN_080b54ec
_080B5490:
	adds r0, r4, #0
	bl FUN_080b4e04
_080B5496:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B54A0:
	.byte 0x10, 0xB5, 0x83, 0xB0, 0x04, 0x1C, 0x0E, 0x48, 0x21, 0x18, 0x08, 0x88, 0x01, 0x30, 0x08, 0x80
	.byte 0x00, 0x04, 0x00, 0x0C, 0x95, 0x28, 0x0F, 0xD9, 0x04, 0x20, 0x00, 0x90, 0x09, 0x48, 0x01, 0x90
	.byte 0x00, 0x20, 0x02, 0x90, 0x03, 0x20, 0x05, 0x21, 0x04, 0x22, 0x04, 0x23, 0x87, 0xF1, 0xCC, 0xFC
	.byte 0x05, 0x49, 0x20, 0x1C, 0xFF, 0xF7, 0x0A, 0xFB, 0x03, 0xB0, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.byte 0x44, 0x08, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xED, 0x54, 0x0B, 0x08

	thumb_func_start FUN_080b54ec
FUN_080b54ec: @ 0x080B54EC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B5520 @ =0x00000844
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080B5518
	ldr r1, _080B5524 @ =0x00000834
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080B5518
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
_080B5518:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B5520: .4byte 0x00000844
_080B5524: .4byte 0x00000834

	thumb_func_start FUN_080b5528
FUN_080b5528: @ 0x080B5528
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r0, #0x58
	adds r1, r5, #0
	adds r1, #0x18
	bl FUN_082372cc
	ldr r0, _080B5584 @ =0x00000844
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x96
	bne _080B555A
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B5588 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_080B555A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb5
	bls _080B557A
	ldr r1, _080B558C @ =0x00000834
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0
	bl Script_ExecById
	adds r0, r5, #0
	bl KillEntity
_080B557A:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B5584: .4byte 0x00000844
_080B5588: .4byte 0x0000FFFF
_080B558C: .4byte 0x00000834

	thumb_func_start FUN_080b5590
FUN_080b5590: @ 0x080B5590
	push {lr}
	ldr r2, _080B55A4 @ =0x0000084C
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080B55A4: .4byte 0x0000084C

	thumb_func_start FUN_080b55a8
FUN_080b55a8: @ 0x080B55A8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x58
	movs r5, #0x13
_080B55B2:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B55B2
	movs r1, #0xfb
	lsls r1, r1, #3
	adds r0, r6, r1
	bl FUN_0822a4e0
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080b55d4
FUN_080b55d4: @ 0x080B55D4
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080B560C @ =0x0000C091
	ldr r1, _080B5610 @ =0x000083C0
	bl GetFile
	adds r2, r0, #0
	movs r0, #0x82
	lsls r0, r0, #4
	adds r4, r4, r0
	str r2, [r4]
	movs r0, #0
	str r0, [sp, #0xc]
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B560C: .4byte 0x0000C091
_080B5610: .4byte 0x000083C0

	thumb_func_start FUN_080b5614
FUN_080b5614: @ 0x080B5614
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B563C @ =0x000092B3
	ldr r1, _080B5640 @ =0x0000EAA8
	bl GetFile
	ldr r1, _080B5644 @ =0x00000824
	adds r4, r4, r1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, _080B5648 @ =0x030043F0
	ldr r2, _080B564C @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B563C: .4byte 0x000092B3
_080B5640: .4byte 0x0000EAA8
_080B5644: .4byte 0x00000824
_080B5648: .4byte 0x030043F0
_080B564C: .4byte 0x04000018

	thumb_func_start FUN_080b5650
FUN_080b5650: @ 0x080B5650
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r4, _080B5900 @ =0x0000CB05
	ldr r1, _080B5904 @ =0x000092F0
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x18
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r6, r7, #0
	adds r6, #0x18
	adds r0, r6, #0
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080B5908 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x38
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	movs r5, #0x38
	adds r5, r5, r7
	mov sb, r5
	mov r0, sb
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080B590C @ =0xFFFF0000
	movs r4, #0
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	mov r8, r0
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x58
	str r1, [sp]
	str r1, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #4
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r3, _080B5910 @ =0x0000082C
	adds r1, r7, r3
	ldrh r2, [r1]
	adds r2, #7
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	ldrh r0, [r0]
	adds r0, #8
	add r1, sp, #0x10
	strh r0, [r1]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #8
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	ldrh r0, [r0]
	adds r0, #8
	add r1, sp, #0x10
	strh r0, [r1]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #8
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r1, _080B5914 @ =0x0000FFF8
	add r0, sp, #0x10
	strh r1, [r0]
	mov r0, r8
	strh r1, [r0, #2]
	adds r0, r7, #0
	adds r0, #0xb8
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	mov r1, sb
	movs r2, #0x94
	movs r3, #0x10
	bl FUN_0822f3fc
	movs r1, #0x10
	add r0, sp, #0x10
	strh r1, [r0]
	ldr r0, _080B5918 @ =0x0000FFFC
	mov r2, r8
	strh r0, [r2, #2]
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x12
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x28
	mov r5, r8
	strh r0, [r5, #2]
	add r6, sp, #0x10
	mov sl, sb
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r1, #0
	mov r8, r1
	movs r4, #3
_080B57A6:
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r3, #0x3c
	mov sb, r3
	str r3, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r2, #0x14
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080B57A6
	movs r4, #0xef
	lsls r4, r4, #3
	adds r0, r7, r4
	movs r1, #1
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	mov r5, sb
	str r5, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	mov r1, sl
	movs r2, #0x47
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r1, _080B591C @ =0x0000FFC8
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x38
	strh r0, [r4, #2]
	movs r6, #0x18
	adds r6, r6, r7
	mov sb, r6
	add r6, sp, #0x10
	movs r0, #0x83
	lsls r0, r0, #3
	adds r5, r7, r0
	movs r1, #0
	mov r8, r1
	movs r4, #3
_080B580E:
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r3, #0x3c
	mov sl, r3
	str r3, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sb
	movs r2, #8
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080B580E
	movs r3, #0
	movs r1, #0x58
	add r0, sp, #0x10
	strh r1, [r0]
	adds r4, r0, #0
	movs r0, #0x38
	strh r0, [r4, #2]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r6, _080B5910 @ =0x0000082C
	adds r1, r7, r6
	ldrh r2, [r1]
	adds r2, #7
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	str r3, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	mov r1, sb
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r1, _080B5920 @ =0x0000FFD0
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x48
	strh r0, [r4, #2]
	add r6, sp, #0x10
	movs r2, #0xbf
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r3, #0
	mov r8, r3
	movs r4, #3
_080B5880:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sb
	movs r2, #8
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080B5880
	movs r6, #0
	ldr r1, _080B5924 @ =0x00000804
	adds r4, r7, r1
	ldr r1, _080B5928 @ =0x0000A47C
	adds r0, r4, #0
	bl FUN_0822b16c
	movs r2, #0xfb
	lsls r2, r2, #3
	adds r5, r7, r2
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r3, _080B592C @ =0x000007DF
	adds r0, r7, r3
	strb r6, [r0]
	movs r0, #0x30
	str r0, [r5]
	ldr r1, _080B5930 @ =0x00000143
	adds r0, r4, #0
	bl FUN_0822b20c
	ldr r4, _080B5934 @ =0x000007F4
	adds r1, r7, r4
	movs r0, #0xa0
	strh r0, [r1]
	ldr r5, _080B5938 @ =0x000007F6
	adds r1, r7, r5
	movs r0, #0x58
	strh r0, [r1]
	movs r1, #0xff
	lsls r1, r1, #3
	adds r0, r7, r1
	strh r6, [r0]
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B5900: .4byte 0x0000CB05
_080B5904: .4byte 0x000092F0
_080B5908: .4byte 0x0000B343
_080B590C: .4byte 0xFFFF0000
_080B5910: .4byte 0x0000082C
_080B5914: .4byte 0x0000FFF8
_080B5918: .4byte 0x0000FFFC
_080B591C: .4byte 0x0000FFC8
_080B5920: .4byte 0x0000FFD0
_080B5924: .4byte 0x00000804
_080B5928: .4byte 0x0000A47C
_080B592C: .4byte 0x000007DF
_080B5930: .4byte 0x00000143
_080B5934: .4byte 0x000007F4
_080B5938: .4byte 0x000007F6

	thumb_func_start FUN_080b593c
FUN_080b593c: @ 0x080B593C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080B5954
	bl FUN_0823d340
	ldr r2, _080B597C @ =0x00000828
	adds r1, r4, r2
	str r0, [r1]
_080B5954:
	ldr r0, _080B5980 @ =0x0000EAA8
	bl FUN_08047dc0
	ldr r1, _080B597C @ =0x00000828
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_080478f0
	movs r0, #1
	movs r1, #0xf
	movs r2, #0x1c
	movs r3, #4
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B597C: .4byte 0x00000828
_080B5980: .4byte 0x0000EAA8

	thumb_func_start FUN_080b5984
FUN_080b5984: @ 0x080B5984
	push {lr}
	ldr r0, _080B599C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080B59A0 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #1
	bgt _080B59A4
	movs r0, #9
	b _080B59B0
	.align 2, 0
_080B599C: .4byte 0x030046A0
_080B59A0: .4byte 0x00000942
_080B59A4:
	cmp r1, #9
	bgt _080B59AE
	movs r0, #0xb
	subs r0, r0, r1
	b _080B59B0
_080B59AE:
	movs r0, #2
_080B59B0:
	pop {r1}
	bx r1

	thumb_func_start FUN_080b59b4
FUN_080b59b4: @ 0x080B59B4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080b5984
	ldr r2, _080B59F4 @ =0x0000082C
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080b55d4
	adds r0, r4, #0
	bl FUN_080b5614
	adds r0, r4, #0
	bl FUN_080b5650
	adds r0, r4, #0
	bl FUN_080b593c
	movs r0, #0x64
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080B59F8
	bl Script_GetValue
	movs r2, #0x83
	lsls r2, r2, #4
	adds r1, r4, r2
	str r0, [r1]
	b _080B5A00
	.align 2, 0
_080B59F4: .4byte 0x0000082C
_080B59F8:
	movs r2, #0x83
	lsls r2, r2, #4
	adds r0, r4, r2
	str r1, [r0]
_080B5A00:
	movs r0, #0x65
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080B5A1C
	bl Script_GetValue
	ldr r2, _080B5A18 @ =0x00000834
	adds r1, r4, r2
	str r0, [r1]
	b _080B5A22
	.align 2, 0
_080B5A18: .4byte 0x00000834
_080B5A1C:
	ldr r2, _080B5A3C @ =0x00000834
	adds r0, r4, r2
	str r1, [r0]
_080B5A22:
	movs r0, #0x6f
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080B5A44
	bl Script_GetValue
	ldr r2, _080B5A40 @ =0x00000846
	adds r1, r4, r2
	strh r0, [r1]
	b _080B5A4A
	.align 2, 0
_080B5A3C: .4byte 0x00000834
_080B5A40: .4byte 0x00000846
_080B5A44:
	ldr r2, _080B5A5C @ =0x00000846
	adds r0, r4, r2
	strh r1, [r0]
_080B5A4A:
	ldr r1, _080B5A5C @ =0x00000846
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080B5A60
	adds r0, r4, #0
	bl FUN_080b4e8c
	b _080B5A66
	.align 2, 0
_080B5A5C: .4byte 0x00000846
_080B5A60:
	adds r0, r4, #0
	bl FUN_080b4b04
_080B5A66:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080b5a70
FUN_080b5a70: @ 0x080B5A70
	push {r4, lr}
	movs r1, #0x85
	lsls r1, r1, #4
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080B5AA8
	ldr r1, _080B5AA0 @ =FUN_080b5590
	ldr r2, _080B5AA4 @ =FUN_080b55a8
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080b59b4
	cmp r0, #0
	bge _080B5AA8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080B5AAA
	.align 2, 0
_080B5AA0: .4byte FUN_080b5590
_080B5AA4: .4byte FUN_080b55a8
_080B5AA8:
	adds r0, r4, #0
_080B5AAA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b5ab0
FUN_080b5ab0: @ 0x080B5AB0
	ldr r3, _080B5AC0 @ =0x00001494
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080B5AC4 @ =0x0000140E
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080B5AC0: .4byte 0x00001494
_080B5AC4: .4byte 0x0000140E

	thumb_func_start FUN_080b5ac8
FUN_080b5ac8: @ 0x080B5AC8
	ldr r2, _080B5AD0 @ =0x0000140C
	adds r0, r0, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
_080B5AD0: .4byte 0x0000140C

	thumb_func_start FUN_080b5ad4
FUN_080b5ad4: @ 0x080B5AD4
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _080B5AF4 @ =0x00001498
	adds r0, r4, r3
	str r1, [r0]
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080b5ac8
	ldr r0, _080B5AF8 @ =0x0000140E
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B5AF4: .4byte 0x00001498
_080B5AF8: .4byte 0x0000140E

	thumb_func_start FUN_080b5afc
FUN_080b5afc: @ 0x080B5AFC
	push {r4, lr}
	adds r4, r1, #0
	movs r2, #0xf
	ldr r3, _080B5B28 @ =0x00001467
	adds r1, r0, r3
_080B5B06:
	strb r2, [r1]
	subs r1, #1
	subs r2, #1
	cmp r2, #0
	bge _080B5B06
	movs r2, #0x10
	ldr r1, _080B5B2C @ =0x00001458
	adds r3, r0, r1
_080B5B16:
	adds r1, r3, r2
	adds r0, r2, r4
	strb r0, [r1]
	adds r2, #1
	cmp r2, #0x1f
	ble _080B5B16
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B5B28: .4byte 0x00001467
_080B5B2C: .4byte 0x00001458

	thumb_func_start FUN_080b5b30
FUN_080b5b30: @ 0x080B5B30
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _080B5B4C @ =0x03003ED0
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
_080B5B4C: .4byte 0x03003ED0

	thumb_func_start FUN_080b5b50
FUN_080b5b50: @ 0x080B5B50
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_08049e5c
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xa0
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r5, #0
	bl FUN_08047a28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b5b94
FUN_080b5b94: @ 0x080B5B94
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, _080B5BC4 @ =0x00001429
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #7
	bhi _080B5BCC
	ldr r2, _080B5BC8 @ =0x0000142B
	adds r5, r6, r2
	ldrb r0, [r5]
	adds r1, #0x2f
	adds r4, r6, r1
	adds r0, r4, r0
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r7, r0, #0
	ldrb r0, [r5]
	adds r4, r4, r0
	ldrb r0, [r4]
	bl item_08092034
	adds r3, r0, #0
	b _080B5BD2
	.align 2, 0
_080B5BC4: .4byte 0x00001429
_080B5BC8: .4byte 0x0000142B
_080B5BCC:
	movs r7, #1
	rsbs r7, r7, #0
	movs r3, #0xcf
_080B5BD2:
	cmp r7, #0
	bge _080B5BEE
	movs r2, #0xf2
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _080B5CA4
_080B5BEE:
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080B5C5C @ =0x00000F18
	adds r0, r6, r1
	adds r1, r6, #0
	adds r1, #0x38
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _080B5C60 @ =0x000013F4
	adds r4, r6, r2
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r7, #0
	bl FUN_08047a28
	ldr r0, [r4]
	bl VM_ParseStringRef
	ldr r0, [r4]
	bl VM_ParseStringRef
	adds r1, r0, #0
	ldr r0, _080B5C64 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #5
	bne _080B5C7A
	cmp r7, #1
	bne _080B5C68
	adds r0, r1, #0
	adds r0, #0xea
	b _080B5C70
	.align 2, 0
_080B5C5C: .4byte 0x00000F18
_080B5C60: .4byte 0x000013F4
_080B5C64: .4byte 0x030046A0
_080B5C68:
	cmp r7, #0xd
	bne _080B5C7A
	adds r0, r1, #0
	adds r0, #0xa9
_080B5C70:
	bl Textbox_LookupString
	bl FUN_08049e30
	b _080B5CA4
_080B5C7A:
	ldr r0, _080B5C94 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _080B5C90
	cmp r0, #5
	bne _080B5C98
_080B5C90:
	adds r1, #0x4e
	b _080B5C9A
	.align 2, 0
_080B5C94: .4byte 0x030046A0
_080B5C98:
	adds r1, #0x9c
_080B5C9A:
	adds r0, r1, r7
	bl Textbox_LookupString
	bl FUN_08049e30
_080B5CA4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b5cac
FUN_080b5cac: @ 0x080B5CAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _080B5D30 @ =0x00001412
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r2, _080B5D34 @ =0x00001413
	adds r1, r7, r2
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r3, #0
	mov sb, r3
	adds r0, r7, #0
	adds r0, #0x80
	str r0, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
_080B5CDA:
	movs r2, #0
	mov sl, r2
	mov r3, sb
	lsls r3, r3, #2
	mov r8, r3
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r2, [sp, #8]
	adds r6, r2, r0
	mov r1, r8
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r3, [sp, #4]
	adds r4, r0, r3
_080B5CFC:
	mov r5, r8
	add r5, sl
	ldr r1, _080B5D38 @ =0x00001458
	adds r0, r7, r1
	adds r0, r0, r5
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r2, r0, #0
	cmp r2, #0
	blt _080B5D3C
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080B5D52
	.align 2, 0
_080B5D30: .4byte 0x00001412
_080B5D34: .4byte 0x00001413
_080B5D38: .4byte 0x00001458
_080B5D3C:
	ldr r2, _080B5DE0 @ =0x00001412
	adds r1, r7, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B5D4A
	strb r5, [r1]
_080B5D4A:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B5D52:
	adds r0, r6, #0
	ldr r1, _080B5DE4 @ =0x000002DF
	bl FUN_080b95bc
	adds r6, #0x60
	adds r4, #0x60
	movs r3, #1
	add sl, r3
	mov r0, sl
	cmp r0, #3
	ble _080B5CFC
	ldr r1, [sp, #8]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r1, r2
	str r1, [sp, #8]
	add sb, r3
	mov r3, sb
	cmp r3, #3
	ble _080B5CDA
	movs r0, #0
	mov sb, r0
_080B5D7E:
	movs r1, #0
	mov sl, r1
	mov r2, sb
	lsls r2, r2, #2
	mov r8, r2
	mov r3, sb
	adds r3, #1
	str r3, [sp]
	adds r2, #0x13
	mov r1, sb
	lsls r0, r1, #3
	add r0, r8
	lsls r0, r0, #5
	movs r3, #0xf3
	lsls r3, r3, #3
	adds r1, r7, r3
	adds r6, r0, r1
	mov r5, r8
	adds r5, #0x10
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r1, [sp, #4]
	adds r4, r0, r1
_080B5DAE:
	ldr r2, _080B5DE8 @ =0x00001458
	adds r0, r7, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r2, r0, #0
	cmp r2, #0
	blt _080B5DEC
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080B5E02
	.align 2, 0
_080B5DE0: .4byte 0x00001412
_080B5DE4: .4byte 0x000002DF
_080B5DE8: .4byte 0x00001458
_080B5DEC:
	ldr r3, _080B5E44 @ =0x00001413
	adds r1, r7, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B5DFA
	strb r5, [r1]
_080B5DFA:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B5E02:
	adds r4, #0x60
	adds r6, #0x60
	adds r5, #1
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	ble _080B5DAE
	ldr r2, [sp]
	mov sb, r2
	cmp r2, #3
	ble _080B5D7E
	movs r3, #1
	ldr r0, [sp, #4]
	movs r2, #0xf0
	lsls r2, r2, #4
	adds r1, r0, r2
	movs r2, #3
_080B5E26:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080B5E26
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B5E44: .4byte 0x00001413

	thumb_func_start FUN_080b5e48
FUN_080b5e48: @ 0x080B5E48
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _080B5E84
	ldr r1, _080B5E68 @ =0x00001429
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080B5E70
	ldr r1, _080B5E6C @ =0x0000130C
	adds r0, r4, r1
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080B5F0E
	.align 2, 0
_080B5E68: .4byte 0x00001429
_080B5E6C: .4byte 0x0000130C
_080B5E70:
	ldr r1, _080B5E80 @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080B5F0E
	.align 2, 0
_080B5E80: .4byte 0x0000130C
_080B5E84:
	ldr r0, _080B5EAC @ =0x0000142E
	adds r6, r4, r0
	ldrb r0, [r6]
	ldr r1, _080B5EB0 @ =0x00001458
	adds r5, r4, r1
	adds r0, r5, r0
	ldrb r0, [r0]
	bl GetNormalItemID
	cmp r0, #0
	bge _080B5EB8
	ldr r1, _080B5EB4 @ =0x0000142B
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldrb r0, [r0]
	bl GetNormalItemID
	b _080B5EDA
	.align 2, 0
_080B5EAC: .4byte 0x0000142E
_080B5EB0: .4byte 0x00001458
_080B5EB4: .4byte 0x0000142B
_080B5EB8:
	ldr r1, _080B5ECC @ =0x0000142B
	adds r0, r4, r1
	ldrb r0, [r0]
	ldrb r6, [r6]
	cmp r0, r6
	bne _080B5EE4
	cmp r0, #0xf
	bhi _080B5ED0
	subs r1, #0x18
	b _080B5ED2
	.align 2, 0
_080B5ECC: .4byte 0x0000142B
_080B5ED0:
	ldr r1, _080B5EE0 @ =0x00001412
_080B5ED2:
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
_080B5EDA:
	mvns r0, r0
	lsrs r0, r0, #0x1f
	b _080B5EE6
	.align 2, 0
_080B5EE0: .4byte 0x00001412
_080B5EE4:
	movs r0, #1
_080B5EE6:
	cmp r0, #1
	bne _080B5F00
	ldr r1, _080B5EFC @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080B5F0E
	.align 2, 0
_080B5EFC: .4byte 0x0000130C
_080B5F00:
	ldr r1, _080B5F14 @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080B5F0E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B5F14: .4byte 0x0000130C

	thumb_func_start FUN_080b5f18
FUN_080b5f18: @ 0x080B5F18
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080B5F48 @ =0x0000142E
	adds r6, r4, r0
	ldrb r0, [r6]
	ldr r1, _080B5F4C @ =0x00001458
	adds r5, r4, r1
	adds r0, r5, r0
	ldrb r0, [r0]
	bl GetNormalItemID
	cmp r0, #0
	bge _080B5F54
	ldr r1, _080B5F50 @ =0x0000142B
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldrb r0, [r0]
	bl GetNormalItemID
	cmp r0, #0
	blt _080B5F8E
	b _080B5FBA
	.align 2, 0
_080B5F48: .4byte 0x0000142E
_080B5F4C: .4byte 0x00001458
_080B5F50: .4byte 0x0000142B
_080B5F54:
	ldr r5, _080B5F78 @ =0x0000142B
	adds r3, r4, r5
	ldrb r0, [r3]
	ldrb r6, [r6]
	cmp r0, r6
	bne _080B5FC4
	cmp r0, #0xf
	bhi _080B5F80
	ldr r0, _080B5F7C @ =0x00001413
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080B5F8E
	movs r0, #3
	ands r0, r1
	b _080B5FA2
	.align 2, 0
_080B5F78: .4byte 0x0000142B
_080B5F7C: .4byte 0x00001413
_080B5F80:
	ldr r0, _080B5F94 @ =0x00001412
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bge _080B5F98
_080B5F8E:
	movs r0, #0
	b _080B5FCA
	.align 2, 0
_080B5F94: .4byte 0x00001412
_080B5F98:
	adds r0, r1, #0
	subs r0, #0x10
	movs r1, #3
	ands r0, r1
	adds r0, #4
_080B5FA2:
	ldr r5, _080B5FC0 @ =0x00001429
	adds r1, r4, r5
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r2, r0]
	subs r0, #0x10
	asrs r0, r0, #2
	adds r5, #1
	adds r1, r4, r5
	strb r0, [r1]
	ldrb r0, [r2]
	strb r0, [r3]
_080B5FBA:
	movs r0, #1
	b _080B5FCA
	.align 2, 0
_080B5FC0: .4byte 0x00001429
_080B5FC4:
	cmp r0, #0x20
	bne _080B5FBA
	movs r0, #2
_080B5FCA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b5fd0
FUN_080b5fd0: @ 0x080B5FD0
	push {lr}
	ldr r2, _080B5FF4 @ =0x0000142B
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _080B5FF8 @ =0x00001458
	adds r2, r0, r3
	adds r1, r2, r1
	ldrb r3, [r1]
	ldr r1, _080B5FFC @ =0x0000142E
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r2, r2, r0
	ldrb r1, [r2]
	adds r0, r3, #0
	bl SwapNormalItem
	pop {r0}
	bx r0
	.align 2, 0
_080B5FF4: .4byte 0x0000142B
_080B5FF8: .4byte 0x00001458
_080B5FFC: .4byte 0x0000142E

	thumb_func_start FUN_080b6000
FUN_080b6000: @ 0x080B6000
	push {lr}
	ldr r2, _080B6018 @ =0x0000142E
	adds r1, r0, r2
	adds r2, #0x2a
	adds r0, r0, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl RemoveItem
	pop {r0}
	bx r0
	.align 2, 0
_080B6018: .4byte 0x0000142E

	thumb_func_start FUN_080b601c
FUN_080b601c: @ 0x080B601C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	adds r7, r0, #0
	movs r5, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x44]
	add r1, sp, #0x34
	mov r8, r1
	add r0, sp, #0x3c
	mov sb, r0
	add r1, sp, #0x1c
	mov sl, r1
	str r0, [sp, #0x48]
	mov r1, r8
	str r1, [sp, #0x4c]
	ldr r2, [sp, #0x44]
_080B6046:
	cmp r5, #0
	bne _080B6054
	ldr r1, _080B6050 @ =0x0000142E
	b _080B6056
	.align 2, 0
_080B6050: .4byte 0x0000142E
_080B6054:
	ldr r1, _080B608C @ =0x0000142B
_080B6056:
	adds r0, r7, r1
	ldrb r4, [r0]
	adds r1, r4, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r1, r7, #0
	adds r1, #0x80
	adds r1, r1, r0
	ldr r0, [r1]
	movs r6, #1
	orrs r0, r6
	str r0, [r1]
	ldr r1, _080B6090 @ =0x00001458
	adds r0, r7, r1
	adds r0, r0, r4
	ldrb r0, [r0]
	str r2, [sp, #0x50]
	bl GetNormalItemID
	adds r1, r0, #0
	ldr r2, [sp, #0x50]
	cmp r1, #0
	blt _080B6094
	str r6, [r2]
	b _080B6098
	.align 2, 0
_080B608C: .4byte 0x0000142B
_080B6090: .4byte 0x00001458
_080B6094:
	movs r0, #0
	str r0, [r2]
_080B6098:
	adds r0, r1, #0
	adds r0, #0x68
	ldr r1, [sp, #0x4c]
	stm r1!, {r0}
	str r1, [sp, #0x4c]
	ldr r0, _080B6108 @ =0x000002DF
	ldr r1, [sp, #0x48]
	stm r1!, {r0}
	str r1, [sp, #0x48]
	lsls r0, r5, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r4, #0
	str r2, [sp, #0x50]
	bl FUN_080b9938
	ldr r2, [sp, #0x50]
	adds r2, #4
	adds r5, #1
	cmp r5, #1
	ble _080B6046
	add r2, sp, #0x14
	mov r3, sl
	movs r5, #1
_080B60C8:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r5, #1
	cmp r5, #0
	bge _080B60C8
	ldr r1, _080B610C @ =0x00001218
	adds r0, r7, r1
	mov r1, r8
	str r1, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x44]
	add r2, sp, #0xc
	mov r3, sl
	bl FUN_080b9a28
	ldr r0, _080B6110 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B6108: .4byte 0x000002DF
_080B610C: .4byte 0x00001218
_080B6110: .4byte 0x0000038A

	thumb_func_start FUN_080b6114
FUN_080b6114: @ 0x080B6114
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r3, #1
	str r3, [sp, #0x2c]
	ldr r0, _080B61B0 @ =0x0000142E
	adds r4, r5, r0
	ldrb r0, [r4]
	adds r0, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r5, #0
	adds r2, #0x80
	adds r2, r2, r1
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldr r1, _080B61B4 @ =0x00001458
	adds r0, r5, r1
	ldrb r1, [r4]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r0, #0x68
	str r0, [sp, #0x34]
	ldr r0, _080B61B8 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r4]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	movs r0, #0x68
	add r6, sp, #0x34
	str r0, [r6, #4]
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
	ldr r0, _080B61BC @ =0x00001218
	adds r5, r5, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080B61C0 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B61B0: .4byte 0x0000142E
_080B61B4: .4byte 0x00001458
_080B61B8: .4byte 0x000002DF
_080B61BC: .4byte 0x00001218
_080B61C0: .4byte 0x0000038A

	thumb_func_start FUN_080b61c4
FUN_080b61c4: @ 0x080B61C4
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x8b
	lsls r0, r0, #5
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x88
	lsls r0, r0, #5
	adds r2, r5, r0
	ldr r0, [r2]
	subs r1, #3
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_080b5cac
	ldr r0, _080B6224 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r0, _080B6228 @ =0x000010F8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FUN_080b5b94
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b5e48
	ldr r1, _080B622C @ =FUN_080b6230
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080b5ad4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B6224: .4byte 0x00001428
_080B6228: .4byte 0x000010F8
_080B622C: .4byte FUN_080b6230

	thumb_func_start FUN_080b6230
FUN_080b6230: @ 0x080B6230
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080B6264 @ =0x00001428
	adds r4, r5, r0
	ldr r2, _080B6268 @ =0x00000D98
	adds r1, r5, r2
	ldr r0, _080B626C @ =0x00000E58
	adds r2, r5, r0
	adds r0, #0x60
	adds r3, r5, r0
	adds r0, r4, #0
	bl FUN_080b95d0
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B6270
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080B627E
	.align 2, 0
_080B6264: .4byte 0x00001428
_080B6268: .4byte 0x00000D98
_080B626C: .4byte 0x00000E58
_080B6270:
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080B627E:
	str r1, [r0]
	ldr r4, _080B62E0 @ =0x030044E0
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080B62F0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b5ac8
	ldr r1, _080B62E4 @ =0x000010F8
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _080B62E8 @ =0x0000130C
	adds r0, r5, r2
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B62BE
	b _080B6490
_080B62BE:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _080B62EC @ =0x00001478
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080B62D8
	b _080B6490
_080B62D8:
	movs r0, #0
	strb r0, [r1]
	b _080B6490
	.align 2, 0
_080B62E0: .4byte 0x030044E0
_080B62E4: .4byte 0x000010F8
_080B62E8: .4byte 0x0000130C
_080B62EC: .4byte 0x00001478
_080B62F0:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b5ac8
	ldr r1, _080B6360 @ =0x000010F8
	adds r6, r5, r1
	adds r7, r5, #0
	adds r7, #0x18
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082372cc
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B6314
	b _080B646C
_080B6314:
	ldr r2, _080B6364 @ =0x0000142B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0x21
	bne _080B6380
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B6368 @ =0x00001428
	adds r0, r5, r1
	bl FUN_080b9fd8
	ldr r2, _080B636C @ =0x000013F4
	adds r0, r5, r2
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl FUN_080b5b50
	ldr r1, _080B6370 @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B6374 @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r2, _080B6378 @ =0x0000130C
	adds r0, r5, r2
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B637C @ =FUN_080b6754
	b _080B63C4
	.align 2, 0
_080B6360: .4byte 0x000010F8
_080B6364: .4byte 0x0000142B
_080B6368: .4byte 0x00001428
_080B636C: .4byte 0x000013F4
_080B6370: .4byte 0x000011B8
_080B6374: .4byte 0x0000140D
_080B6378: .4byte 0x0000130C
_080B637C: .4byte FUN_080b6754
_080B6380:
	cmp r0, #0x22
	bne _080B63E8
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B63D0 @ =0x00001428
	adds r0, r5, r1
	bl FUN_080b9fd8
	ldr r2, _080B63D4 @ =0x000013F4
	adds r0, r5, r2
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #4
	adds r3, r4, #0
	bl FUN_080b5b50
	ldr r1, _080B63D8 @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B63DC @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r2, _080B63E0 @ =0x0000130C
	adds r0, r5, r2
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B63E4 @ =FUN_080b67c0
_080B63C4:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B6490
	.align 2, 0
_080B63D0: .4byte 0x00001428
_080B63D4: .4byte 0x000013F4
_080B63D8: .4byte 0x000011B8
_080B63DC: .4byte 0x0000140D
_080B63E0: .4byte 0x0000130C
_080B63E4: .4byte FUN_080b67c0
_080B63E8:
	ldr r0, _080B6434 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fd8
	movs r1, #0x8b
	lsls r1, r1, #5
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080B6438 @ =0x00001178
	adds r2, r5, r0
	ldr r1, _080B643C @ =0x00001118
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080B6440 @ =0x0000142E
	adds r1, r5, r2
	adds r2, #0x2a
	adds r0, r5, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl GetNormalItemID
	cmp r0, #0
	blt _080B6444
	adds r0, r4, #0
	movs r1, #0x18
	bl FUN_080b9d94
	b _080B644C
	.align 2, 0
_080B6434: .4byte 0x00001428
_080B6438: .4byte 0x00001178
_080B643C: .4byte 0x00001118
_080B6440: .4byte 0x0000142E
_080B6444:
	adds r0, r4, #0
	movs r1, #0x1c
	bl FUN_080b9d94
_080B644C:
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B6468 @ =FUN_080b649c
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080b5ad4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b5e48
	b _080B6490
	.align 2, 0
_080B6468: .4byte FUN_080b649c
_080B646C:
	ldr r0, _080B6498 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080B6490
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080b5b94
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b5e48
_080B6490:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B6498: .4byte 0x00001428

	thumb_func_start FUN_080b649c
FUN_080b649c: @ 0x080B649C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080B64D4 @ =0x00001428
	adds r4, r5, r0
	ldr r0, _080B64D8 @ =0x00000D98
	adds r1, r5, r0
	adds r0, #0xc0
	adds r2, r5, r0
	adds r0, #0x60
	adds r3, r5, r0
	adds r0, r4, #0
	bl FUN_080b95d0
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B64DC
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080B6520
	.align 2, 0
_080B64D4: .4byte 0x00001428
_080B64D8: .4byte 0x00000D98
_080B64DC:
	ldr r1, _080B64F8 @ =0x0000140E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _080B64FC
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _080B6508
	.align 2, 0
_080B64F8: .4byte 0x0000140E
_080B64FC:
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_080B6508:
	str r1, [r0]
	ldr r0, _080B658C @ =0x0000140E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080B6520
	movs r0, #0
	strh r0, [r1]
_080B6520:
	ldr r1, _080B6590 @ =0x000010F8
	adds r6, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_082372cc
	ldr r0, _080B6594 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #4
	ands r0, r1
	adds r7, r4, #0
	cmp r0, #0
	beq _080B65A8
	ldr r1, _080B6598 @ =0x00001428
	adds r0, r5, r1
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B65A8
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080B659C @ =0x00001118
	adds r0, r5, r1
	movs r1, #0x20
	bl FUN_080b9938
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _080B65A0 @ =0x0000130C
	adds r0, r5, r1
	movs r4, #1
	rsbs r4, r4, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r0, _080B65A4 @ =0x00000107
	bl PlaySound_082406e0
	b _080B65F8
	.align 2, 0
_080B658C: .4byte 0x0000140E
_080B6590: .4byte 0x000010F8
_080B6594: .4byte 0x030044E0
_080B6598: .4byte 0x00001428
_080B659C: .4byte 0x00001118
_080B65A0: .4byte 0x0000130C
_080B65A4: .4byte 0x00000107
_080B65A8:
	ldr r0, _080B65E0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B6638
	adds r0, r5, #0
	bl FUN_080b5f18
	adds r4, r0, #0
	ldr r1, _080B65E4 @ =0x0000130C
	adds r0, r5, r1
	movs r6, #1
	rsbs r6, r6, #0
	adds r1, r6, #0
	adds r2, r6, #0
	bl FUN_080b98c0
	cmp r4, #1
	beq _080B65E8
	cmp r4, #2
	beq _080B65F8
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080B6674
	.align 2, 0
_080B65E0: .4byte 0x030044E0
_080B65E4: .4byte 0x0000130C
_080B65E8:
	adds r0, r5, #0
	bl FUN_080b601c
	ldr r1, _080B65F4 @ =0x080B6835
	b _080B661C
	.align 2, 0
_080B65F4: .4byte 0x080B6835
_080B65F8:
	ldr r1, _080B6628 @ =0x000013F4
	adds r0, r5, r1
	ldr r2, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r3, #1
	rsbs r3, r3, #0
	bl FUN_080b5b50
	ldr r1, _080B662C @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B6630 @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080B6634 @ =FUN_080b685c
_080B661C:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B6674
	.align 2, 0
_080B6628: .4byte 0x000013F4
_080B662C: .4byte 0x000011B8
_080B6630: .4byte 0x0000140D
_080B6634: .4byte FUN_080b685c
_080B6638:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B664E
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080b61c4
	b _080B6674
_080B664E:
	ldr r0, _080B667C @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080B6674
	ldr r0, _080B6680 @ =0x000010F8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080b5b94
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b5e48
_080B6674:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B667C: .4byte 0x00001428
_080B6680: .4byte 0x000010F8

	thumb_func_start FUN_080b6684
FUN_080b6684: @ 0x080B6684
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080B66D8 @ =0x000010F8
	adds r5, r4, r0
	adds r6, r4, #0
	adds r6, #0x18
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_082372cc
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080B66DC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B66E8
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080B66E0 @ =0x00001428
	adds r0, r4, r1
	adds r1, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080b5b94
	ldr r1, _080B66E4 @ =FUN_080b649c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B673A
	.align 2, 0
_080B66D8: .4byte 0x000010F8
_080B66DC: .4byte 0x030044E0
_080B66E0: .4byte 0x00001428
_080B66E4: .4byte FUN_080b649c
_080B66E8:
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080B673A
	movs r0, #0x88
	lsls r0, r0, #5
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080B6740 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080B6744 @ =0x000013F4
	adds r0, r4, r1
	ldr r2, [r0]
	movs r3, #1
	rsbs r3, r3, #0
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080b5b50
	ldr r1, _080B6748 @ =0x000011B8
	adds r0, r4, r1
	ldr r1, _080B674C @ =0x0000140D
	adds r2, r4, r1
	adds r1, r6, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080B6750 @ =FUN_080b685c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
_080B673A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B6740: .4byte 0x00000107
_080B6744: .4byte 0x000013F4
_080B6748: .4byte 0x000011B8
_080B674C: .4byte 0x0000140D
_080B6750: .4byte FUN_080b685c

	thumb_func_start FUN_080b6754
FUN_080b6754: @ 0x080B6754
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B6794 @ =0x000011B8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080B6798 @ =0x0000140D
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080B67A8
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortInventory
	ldr r1, _080B679C @ =0x0000142C
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080B67A0 @ =0x0000142D
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080B67A4 @ =0x0000142E
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b61c4
	b _080B67B8
	.align 2, 0
_080B6794: .4byte 0x000011B8
_080B6798: .4byte 0x0000140D
_080B679C: .4byte 0x0000142C
_080B67A0: .4byte 0x0000142D
_080B67A4: .4byte 0x0000142E
_080B67A8:
	cmp r0, #0
	bne _080B67B8
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b61c4
_080B67B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b67c0
FUN_080b67c0: @ 0x080B67C0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B6808 @ =0x000011B8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080B680C @ =0x0000140D
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080B681C
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B6810 @ =0x00001468
	adds r0, r4, r1
	ldrb r0, [r0]
	bl SortInventory
	ldr r3, _080B6814 @ =0x0000142C
	adds r1, r4, r3
	movs r2, #0
	movs r0, #4
	strb r0, [r1]
	ldr r1, _080B6818 @ =0x0000142D
	adds r0, r4, r1
	strb r2, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080b61c4
	b _080B682C
	.align 2, 0
_080B6808: .4byte 0x000011B8
_080B680C: .4byte 0x0000140D
_080B6810: .4byte 0x00001468
_080B6814: .4byte 0x0000142C
_080B6818: .4byte 0x0000142D
_080B681C:
	cmp r0, #0
	bne _080B682C
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b61c4
_080B682C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B6834:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x07, 0x49, 0x60, 0x18, 0x03, 0xF0, 0x4E, 0xF9
	.byte 0x00, 0x28, 0x05, 0xD0, 0x20, 0x1C, 0xFF, 0xF7, 0xC3, 0xFB, 0x20, 0x1C, 0xFF, 0xF7, 0xBA, 0xFC
	.byte 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x18, 0x12, 0x00, 0x00

	thumb_func_start FUN_080b685c
FUN_080b685c: @ 0x080B685C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B6898 @ =0x000011B8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080B689C @ =0x0000140D
	adds r2, r4, r3
	bl FUN_080b977c
	adds r2, r0, #0
	cmp r2, #1
	bne _080B68A4
	movs r1, #0x88
	lsls r1, r1, #5
	adds r0, r4, r1
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080b6114
	ldr r1, _080B68A0 @ =FUN_080b68bc
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B68B4
	.align 2, 0
_080B6898: .4byte 0x000011B8
_080B689C: .4byte 0x0000140D
_080B68A0: .4byte FUN_080b68bc
_080B68A4:
	cmp r2, #0
	bne _080B68B4
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b61c4
_080B68B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b68bc
FUN_080b68bc: @ 0x080B68BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B68EC @ =0x00001218
	adds r0, r4, r1
	bl FUN_080b9adc
	cmp r0, #0
	beq _080B68E4
	adds r0, r4, #0
	bl FUN_080b6000
	movs r0, #0x87
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080B68F0 @ =FUN_080b68f4
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
_080B68E4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B68EC: .4byte 0x00001218
_080B68F0: .4byte FUN_080b68f4

	thumb_func_start FUN_080b68f4
FUN_080b68f4: @ 0x080B68F4
	push {lr}
	adds r3, r0, #0
	ldr r0, _080B691C @ =0x0000140E
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	bhi _080B693C
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B6924
	ldr r2, _080B6920 @ =0x00000DBA
	adds r1, r3, r2
	b _080B6944
	.align 2, 0
_080B691C: .4byte 0x0000140E
_080B6920: .4byte 0x00000DBA
_080B6924:
	ldrh r1, [r2]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x40
	subs r1, r1, r0
	ldr r2, _080B6938 @ =0x00000DBA
	adds r0, r3, r2
	strh r1, [r0]
	b _080B6956
	.align 2, 0
_080B6938: .4byte 0x00000DBA
_080B693C:
	cmp r1, #0xf
	bhi _080B6950
	ldr r0, _080B694C @ =0x00000DBA
	adds r1, r3, r0
_080B6944:
	movs r0, #0x40
	strh r0, [r1]
	b _080B6956
	.align 2, 0
_080B694C: .4byte 0x00000DBA
_080B6950:
	adds r0, r3, #0
	bl FUN_080b61c4
_080B6956:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b695c
FUN_080b695c: @ 0x080B695C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_080b5afc
	adds r0, r4, #0
	bl FUN_080b5cac
	ldr r0, _080B69AC @ =0x00001428
	adds r5, r4, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080b9ff8
	ldr r0, _080B69B0 @ =0x000010F8
	adds r1, r4, r0
	adds r0, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080b5b94
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b5e48
	ldr r1, _080B69B4 @ =FUN_080b6230
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080b5ad4
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B69AC: .4byte 0x00001428
_080B69B0: .4byte 0x000010F8
_080B69B4: .4byte FUN_080b6230

	thumb_func_start FUN_080b69b8
FUN_080b69b8: @ 0x080B69B8
	push {r4, r5, lr}
	sub sp, #0x24
	adds r5, r0, #0
	ldr r1, _080B69E0 @ =0x00001429
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	bhi _080B69E8
	ldr r2, _080B69E4 @ =0x0000142B
	adds r0, r5, r2
	adds r2, #0x2d
	adds r1, r5, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	mov r1, sp
	bl FUN_08242b14
	b _080B69EE
	.align 2, 0
_080B69E0: .4byte 0x00001429
_080B69E4: .4byte 0x0000142B
_080B69E8:
	mov r1, sp
	movs r0, #0
	strb r0, [r1]
_080B69EE:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B6A0E
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _080B6A60
_080B6A0E:
	mov r0, sp
	bl FUN_08094e70
	adds r2, r0, #0
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r3, r5, r0
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
	ldr r1, _080B6A68 @ =0x00000F18
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x38
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _080B6A6C @ =0x000013F8
	adds r4, r5, r2
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r0, _080B6A70 @ =0x00001404
	adds r1, r5, r0
	mov r0, sp
	bl FUN_08094d1c
	ldr r1, [r4]
	mov r0, sp
	bl FUN_08094d48
_080B6A60:
	add sp, #0x24
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B6A68: .4byte 0x00000F18
_080B6A6C: .4byte 0x000013F8
_080B6A70: .4byte 0x00001404

	thumb_func_start FUN_080b6a74
FUN_080b6a74: @ 0x080B6A74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _080B6AF8 @ =0x00001412
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r3, _080B6AFC @ =0x00001413
	adds r1, r7, r3
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r0, #0
	mov sb, r0
	adds r1, r7, #0
	adds r1, #0x80
	str r1, [sp, #4]
	movs r3, #0
	str r3, [sp, #8]
_080B6AA2:
	movs r0, #0
	mov sl, r0
	mov r1, sb
	lsls r1, r1, #2
	mov r8, r1
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [sp, #8]
	adds r5, r1, r0
	mov r1, r8
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r3, [sp, #4]
	adds r4, r0, r3
_080B6AC4:
	mov r6, r8
	add r6, sl
	ldr r1, _080B6B00 @ =0x00001458
	adds r0, r7, r1
	adds r0, r0, r6
	ldrb r0, [r0]
	bl GetWeaponID
	adds r2, r0, #0
	cmp r2, #0
	ble _080B6B04
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080B6B1A
	.align 2, 0
_080B6AF8: .4byte 0x00001412
_080B6AFC: .4byte 0x00001413
_080B6B00: .4byte 0x00001458
_080B6B04:
	ldr r3, _080B6B30 @ =0x00001412
	adds r1, r7, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B6B12
	strb r6, [r1]
_080B6B12:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B6B1A:
	adds r0, r6, #0
	bl FUN_082430d4
	cmp r0, #0
	beq _080B6B34
	adds r0, r5, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080B6B3C
	.align 2, 0
_080B6B30: .4byte 0x00001412
_080B6B34:
	adds r0, r5, #0
	ldr r1, _080B6BC4 @ =0x000002DF
	bl FUN_080b95bc
_080B6B3C:
	adds r5, #0x60
	adds r4, #0x60
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	ble _080B6AC4
	ldr r3, [sp, #8]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r3, r3, r0
	str r3, [sp, #8]
	movs r1, #1
	add sb, r1
	mov r3, sb
	cmp r3, #3
	ble _080B6AA2
	movs r0, #0
	mov sb, r0
_080B6B62:
	movs r1, #0
	mov sl, r1
	mov r3, sb
	lsls r3, r3, #2
	mov r8, r3
	mov r0, sb
	adds r0, #1
	str r0, [sp]
	mov r2, r8
	adds r2, #0x13
	mov r1, sb
	lsls r0, r1, #3
	add r0, r8
	lsls r0, r0, #5
	movs r3, #0xf3
	lsls r3, r3, #3
	adds r1, r7, r3
	adds r6, r0, r1
	mov r5, r8
	adds r5, #0x10
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r1, [sp, #4]
	adds r4, r0, r1
_080B6B94:
	ldr r3, _080B6BC8 @ =0x00001458
	adds r0, r7, r3
	adds r0, r0, r5
	ldrb r0, [r0]
	bl GetWeaponID
	adds r2, r0, #0
	cmp r2, #0
	ble _080B6BCC
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080B6BE2
	.align 2, 0
_080B6BC4: .4byte 0x000002DF
_080B6BC8: .4byte 0x00001458
_080B6BCC:
	ldr r0, _080B6C44 @ =0x00001413
	adds r1, r7, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B6BDA
	strb r5, [r1]
_080B6BDA:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B6BE2:
	adds r4, #0x60
	adds r6, #0x60
	adds r5, #1
	movs r1, #1
	add sl, r1
	mov r3, sl
	cmp r3, #3
	ble _080B6B94
	ldr r0, [sp]
	mov sb, r0
	cmp r0, #3
	ble _080B6B62
	ldr r0, _080B6C48 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, [sp, #4]
	movs r3, #0xf0
	lsls r3, r3, #4
	adds r2, r1, r3
	adds r3, r0, #0
	adds r3, #0x60
	ldr r0, _080B6C4C @ =0x00000F98
	adds r5, r7, r0
	movs r6, #3
_080B6C10:
	ldrh r4, [r3]
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _080B6C50
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r5]
	ldrh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x12
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r5, #2]
	b _080B6C58
	.align 2, 0
_080B6C44: .4byte 0x00001413
_080B6C48: .4byte 0x030046A0
_080B6C4C: .4byte 0x00000F98
_080B6C50:
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_080B6C58:
	adds r2, #0x60
	adds r3, #2
	adds r5, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080B6C10
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b6c74
FUN_080b6c74: @ 0x080B6C74
	push {r4, lr}
	cmp r1, #0xf
	ble _080B6C80
	b _080B6C9A
_080B6C7C:
	adds r0, r3, #0
	b _080B6C9E
_080B6C80:
	movs r3, #0
	ldr r0, _080B6CA4 @ =0x030046A0
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x60
_080B6C8A:
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, r1
	beq _080B6C7C
	adds r2, #2
	adds r3, #1
	cmp r3, #3
	ble _080B6C8A
_080B6C9A:
	movs r0, #1
	rsbs r0, r0, #0
_080B6C9E:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B6CA4: .4byte 0x030046A0

	thumb_func_start FUN_080b6ca8
FUN_080b6ca8: @ 0x080B6CA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	adds r7, r0, #0
	movs r6, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x48]
	mov r1, sp
	adds r1, #0x34
	str r1, [sp, #0x4c]
	add r2, sp, #0x3c
	mov sl, r2
	subs r0, #0x10
	str r0, [sp, #0x44]
	mov r1, sl
	str r1, [sp, #0x50]
	ldr r2, [sp, #0x4c]
	str r2, [sp, #0x54]
	ldr r0, [sp, #0x48]
	mov sb, r0
_080B6CD8:
	cmp r6, #0
	bne _080B6CE8
	ldr r1, _080B6CE4 @ =0x0000142E
	adds r0, r7, r1
	b _080B6CEC
	.align 2, 0
_080B6CE4: .4byte 0x0000142E
_080B6CE8:
	ldr r2, _080B6D40 @ =0x0000142B
	adds r0, r7, r2
_080B6CEC:
	ldrb r4, [r0]
	adds r0, r4, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r5, r7, #0
	adds r5, #0x80
	adds r1, r5, r1
	ldr r0, [r1]
	movs r2, #1
	mov r8, r2
	orrs r0, r2
	str r0, [r1]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_080b6c74
	cmp r0, #0
	blt _080B6D24
	adds r0, #0x28
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r1, r5, r1
	ldr r0, [r1]
	mov r2, r8
	orrs r0, r2
	str r0, [r1]
_080B6D24:
	ldr r1, _080B6D44 @ =0x00001458
	adds r0, r7, r1
	adds r0, r0, r4
	ldrb r0, [r0]
	bl GetWeaponID
	adds r1, r0, #0
	cmp r1, #0
	ble _080B6D48
	mov r2, r8
	mov r0, sb
	str r2, [r0]
	b _080B6D4E
	.align 2, 0
_080B6D40: .4byte 0x0000142B
_080B6D44: .4byte 0x00001458
_080B6D48:
	movs r0, #0
	mov r2, sb
	str r0, [r2]
_080B6D4E:
	ldr r0, [sp, #0x54]
	stm r0!, {r1}
	str r0, [sp, #0x54]
	ldr r0, _080B6DB8 @ =0x000002DF
	ldr r1, [sp, #0x50]
	stm r1!, {r0}
	str r1, [sp, #0x50]
	lsls r0, r6, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r4, #0
	bl FUN_080b9938
	movs r2, #4
	add sb, r2
	adds r6, #1
	cmp r6, #1
	ble _080B6CD8
	add r2, sp, #0x14
	ldr r3, [sp, #0x44]
	movs r6, #1
_080B6D78:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r6, #1
	cmp r6, #0
	bge _080B6D78
	ldr r1, _080B6DBC @ =0x00001218
	adds r0, r7, r1
	ldr r2, [sp, #0x4c]
	str r2, [sp]
	mov r1, sl
	str r1, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x48]
	add r2, sp, #0xc
	ldr r3, [sp, #0x44]
	bl FUN_080b9a28
	ldr r0, _080B6DC0 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B6DB8: .4byte 0x000002DF
_080B6DBC: .4byte 0x00001218
_080B6DC0: .4byte 0x0000038A

	thumb_func_start FUN_080b6dc4
FUN_080b6dc4: @ 0x080B6DC4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r3, #1
	str r3, [sp, #0x2c]
	ldr r0, _080B6E5C @ =0x0000142E
	adds r4, r5, r0
	ldrb r0, [r4]
	adds r0, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r5, #0
	adds r2, #0x80
	adds r2, r2, r1
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldr r1, _080B6E60 @ =0x00001458
	adds r0, r5, r1
	ldrb r1, [r4]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl GetWeaponID
	str r0, [sp, #0x34]
	ldr r0, _080B6E64 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r4]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_080b9938
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
	ldr r0, _080B6E68 @ =0x00001218
	adds r5, r5, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080B6E6C @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B6E5C: .4byte 0x0000142E
_080B6E60: .4byte 0x00001458
_080B6E64: .4byte 0x000002DF
_080B6E68: .4byte 0x00001218
_080B6E6C: .4byte 0x0000038A

	thumb_func_start FUN_080b6e70
FUN_080b6e70: @ 0x080B6E70
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _080B6EAC
	ldr r1, _080B6E90 @ =0x00001429
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080B6E98
	ldr r1, _080B6E94 @ =0x0000130C
	adds r0, r4, r1
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080B6F9A
	.align 2, 0
_080B6E90: .4byte 0x00001429
_080B6E94: .4byte 0x0000130C
_080B6E98:
	ldr r1, _080B6EA8 @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080B6F9A
	.align 2, 0
_080B6EA8: .4byte 0x0000130C
_080B6EAC:
	ldr r0, _080B6EE8 @ =0x0000142E
	adds r6, r4, r0
	ldrb r0, [r6]
	ldr r1, _080B6EEC @ =0x00001458
	adds r7, r4, r1
	adds r0, r7, r0
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	bne _080B6EF8
	ldr r0, _080B6EF0 @ =0x0000142B
	adds r5, r4, r0
	ldrb r0, [r5]
	adds r0, r7, r0
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	beq _080B6F9A
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_080b6c74
	cmp r0, #0
	blt _080B6F9A
	ldr r1, _080B6EF4 @ =0x0000142C
	adds r0, r4, r1
	ldrb r0, [r0]
	b _080B6F9A
	.align 2, 0
_080B6EE8: .4byte 0x0000142E
_080B6EEC: .4byte 0x00001458
_080B6EF0: .4byte 0x0000142B
_080B6EF4: .4byte 0x0000142C
_080B6EF8:
	ldr r0, _080B6F1C @ =0x0000142B
	adds r5, r4, r0
	ldrb r0, [r5]
	ldrb r1, [r6]
	cmp r0, r1
	bne _080B6F3C
	ldr r1, _080B6F20 @ =0x00001428
	adds r0, r4, r1
	movs r1, #2
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B6F68
	ldrb r0, [r5]
	cmp r0, #0xf
	bhi _080B6F28
	ldr r1, _080B6F24 @ =0x00001413
	b _080B6F2A
	.align 2, 0
_080B6F1C: .4byte 0x0000142B
_080B6F20: .4byte 0x00001428
_080B6F24: .4byte 0x00001413
_080B6F28:
	ldr r1, _080B6F38 @ =0x00001412
_080B6F2A:
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mvns r0, r0
	lsrs r1, r0, #0x1f
	b _080B6F72
	.align 2, 0
_080B6F38: .4byte 0x00001412
_080B6F3C:
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_080b6c74
	cmp r0, #0
	blt _080B6F50
	ldr r1, _080B6F4C @ =0x0000142C
	b _080B6F5E
	.align 2, 0
_080B6F4C: .4byte 0x0000142C
_080B6F50:
	ldrb r1, [r6]
	adds r0, r4, #0
	bl FUN_080b6c74
	cmp r0, #0
	blt _080B6F70
	ldr r1, _080B6F6C @ =0x00001429
_080B6F5E:
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	cmp r0, #3
	bls _080B6F72
_080B6F68:
	movs r1, #0
	b _080B6F72
	.align 2, 0
_080B6F6C: .4byte 0x00001429
_080B6F70:
	movs r1, #1
_080B6F72:
	cmp r1, #1
	bne _080B6F8C
	ldr r1, _080B6F88 @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080B6F9A
	.align 2, 0
_080B6F88: .4byte 0x0000130C
_080B6F8C:
	ldr r1, _080B6FA0 @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080B6F9A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B6FA0: .4byte 0x0000130C

	thumb_func_start FUN_080b6fa4
FUN_080b6fa4: @ 0x080B6FA4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080B6FE8 @ =0x0000142E
	adds r5, r4, r0
	ldrb r0, [r5]
	ldr r1, _080B6FEC @ =0x00001458
	adds r6, r4, r1
	adds r0, r6, r0
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	bne _080B6FF8
	ldr r3, _080B6FF0 @ =0x0000142B
	adds r5, r4, r3
	ldrb r0, [r5]
	adds r0, r6, r0
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	beq _080B709A
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_080b6c74
	cmp r0, #0
	blt _080B70A4
_080B6FDC:
	ldr r1, _080B6FF4 @ =0x0000142C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080B709A
	b _080B70A4
	.align 2, 0
_080B6FE8: .4byte 0x0000142E
_080B6FEC: .4byte 0x00001458
_080B6FF0: .4byte 0x0000142B
_080B6FF4: .4byte 0x0000142C
_080B6FF8:
	ldr r3, _080B7044 @ =0x0000142B
	adds r6, r4, r3
	ldrb r0, [r6]
	ldrb r1, [r5]
	cmp r0, r1
	bne _080B7070
	subs r3, #3
	adds r0, r4, r3
	movs r1, #2
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B709A
	ldrb r0, [r6]
	cmp r0, #0xf
	bhi _080B7050
	ldr r0, _080B7048 @ =0x00001413
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080B709A
	movs r0, #3
	ands r0, r1
_080B702A:
	ldr r3, _080B704C @ =0x00001429
	adds r1, r4, r3
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r2, r0]
	subs r0, #0x10
	asrs r0, r0, #2
	adds r3, #1
	adds r1, r4, r3
	strb r0, [r1]
	ldrb r0, [r2]
	strb r0, [r6]
	b _080B70A4
	.align 2, 0
_080B7044: .4byte 0x0000142B
_080B7048: .4byte 0x00001413
_080B704C: .4byte 0x00001429
_080B7050:
	ldr r0, _080B706C @ =0x00001412
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080B709A
	adds r0, r1, #0
	subs r0, #0x10
	movs r1, #3
	ands r0, r1
	adds r0, #4
	b _080B702A
	.align 2, 0
_080B706C: .4byte 0x00001412
_080B7070:
	cmp r0, #0x20
	bne _080B7078
	movs r0, #2
	b _080B70A6
_080B7078:
	ldrb r1, [r6]
	adds r0, r4, #0
	bl FUN_080b6c74
	cmp r0, #0
	bge _080B6FDC
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_080b6c74
	cmp r0, #0
	blt _080B70A4
	ldr r3, _080B70A0 @ =0x00001429
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #3
	bls _080B70A4
_080B709A:
	movs r0, #0
	b _080B70A6
	.align 2, 0
_080B70A0: .4byte 0x00001429
_080B70A4:
	movs r0, #1
_080B70A6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b70ac
FUN_080b70ac: @ 0x080B70AC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x8b
	lsls r0, r0, #5
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x88
	lsls r0, r0, #5
	adds r2, r5, r0
	ldr r0, [r2]
	subs r1, #3
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_080b6a74
	ldr r0, _080B710C @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r0, _080B7110 @ =0x000010F8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FUN_080b69b8
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b6e70
	ldr r1, _080B7114 @ =FUN_080b7118
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080b5ad4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B710C: .4byte 0x00001428
_080B7110: .4byte 0x000010F8
_080B7114: .4byte FUN_080b7118

	thumb_func_start FUN_080b7118
FUN_080b7118: @ 0x080B7118
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080B714C @ =0x00001428
	adds r4, r5, r0
	ldr r0, _080B7150 @ =0x00000D98
	adds r1, r5, r0
	adds r0, #0xc0
	adds r2, r5, r0
	adds r0, #0x60
	adds r3, r5, r0
	adds r0, r4, #0
	bl FUN_080b95d0
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B7154
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080B7162
	.align 2, 0
_080B714C: .4byte 0x00001428
_080B7150: .4byte 0x00000D98
_080B7154:
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080B7162:
	str r1, [r0]
	ldr r0, _080B71D0 @ =0x000010F8
	adds r6, r5, r0
	adds r7, r5, #0
	adds r7, #0x18
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082372cc
	ldr r4, _080B71D4 @ =0x030044E0
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080B71E0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b5ac8
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _080B71D8 @ =0x0000130C
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B71AE
	b _080B73AC
_080B71AE:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _080B71DC @ =0x00001478
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080B71C8
	b _080B73AC
_080B71C8:
	movs r0, #0
	strb r0, [r1]
	b _080B73AC
	.align 2, 0
_080B71D0: .4byte 0x000010F8
_080B71D4: .4byte 0x030044E0
_080B71D8: .4byte 0x0000130C
_080B71DC: .4byte 0x00001478
_080B71E0:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b5ac8
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082372cc
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B71FC
	b _080B7388
_080B71FC:
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B7250 @ =0x0000142B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x21
	bne _080B726C
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B7254 @ =0x00001428
	adds r0, r5, r1
	bl FUN_080b9fd8
	ldr r1, _080B7258 @ =0x000013F4
	adds r0, r5, r1
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl FUN_080b5b50
	ldr r1, _080B725C @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B7260 @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080B7264 @ =0x0000130C
	adds r0, r5, r1
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B7268 @ =FUN_080b7670
	b _080B7378
	.align 2, 0
_080B7250: .4byte 0x0000142B
_080B7254: .4byte 0x00001428
_080B7258: .4byte 0x000013F4
_080B725C: .4byte 0x000011B8
_080B7260: .4byte 0x0000140D
_080B7264: .4byte 0x0000130C
_080B7268: .4byte FUN_080b7670
_080B726C:
	cmp r0, #0x22
	bne _080B72CC
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B72B4 @ =0x00001428
	adds r0, r5, r1
	bl FUN_080b9fd8
	ldr r1, _080B72B8 @ =0x000013F4
	adds r0, r5, r1
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #4
	adds r3, r4, #0
	bl FUN_080b5b50
	ldr r1, _080B72BC @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B72C0 @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080B72C4 @ =0x0000130C
	adds r0, r5, r1
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B72C8 @ =0x080B76DD
	b _080B7378
	.align 2, 0
_080B72B4: .4byte 0x00001428
_080B72B8: .4byte 0x000013F4
_080B72BC: .4byte 0x000011B8
_080B72C0: .4byte 0x0000140D
_080B72C4: .4byte 0x0000130C
_080B72C8: .4byte 0x080B76DD
_080B72CC:
	ldr r0, _080B7324 @ =0x00001428
	adds r7, r5, r0
	adds r0, r7, #0
	bl FUN_080b9fd8
	movs r1, #0x8b
	lsls r1, r1, #5
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080B7328 @ =0x00001178
	adds r2, r5, r0
	ldr r1, _080B732C @ =0x00001118
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _080B7330 @ =0x0000142E
	adds r6, r5, r0
	ldr r1, _080B7334 @ =0x00001458
	adds r0, r5, r1
	ldrb r1, [r6]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl GetWeaponID
	adds r4, r0, #0
	cmp r4, #0
	ble _080B7366
	ldrb r1, [r6]
	adds r0, r5, #0
	bl FUN_080b6c74
	cmp r0, #0
	blt _080B7338
	adds r0, r7, #0
	movs r1, #0x1e
	bl FUN_080b9d94
	b _080B736E
	.align 2, 0
_080B7324: .4byte 0x00001428
_080B7328: .4byte 0x00001178
_080B732C: .4byte 0x00001118
_080B7330: .4byte 0x0000142E
_080B7334: .4byte 0x00001458
_080B7338:
	adds r0, r4, #0
	subs r0, #0x3a
	cmp r0, #3
	bls _080B734C
	cmp r4, #0x3f
	beq _080B734C
	cmp r4, #0x40
	beq _080B734C
	cmp r4, #0x41
	bne _080B735C
_080B734C:
	ldr r1, _080B7358 @ =0x00001428
	adds r0, r5, r1
	movs r1, #0x1c
	bl FUN_080b9d94
	b _080B736E
	.align 2, 0
_080B7358: .4byte 0x00001428
_080B735C:
	adds r0, r7, #0
	movs r1, #0x18
	bl FUN_080b9d94
	b _080B736E
_080B7366:
	adds r0, r7, #0
	movs r1, #0x1c
	bl FUN_080b9d94
_080B736E:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b6e70
	ldr r1, _080B7384 @ =FUN_080b73b8
_080B7378:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B73AC
	.align 2, 0
_080B7384: .4byte FUN_080b73b8
_080B7388:
	ldr r0, _080B73B4 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080B73AC
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080b69b8
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b6e70
_080B73AC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B73B4: .4byte 0x00001428

	thumb_func_start FUN_080b73b8
FUN_080b73b8: @ 0x080B73B8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080B73F0 @ =0x00001428
	adds r4, r5, r0
	ldr r0, _080B73F4 @ =0x00000D98
	adds r1, r5, r0
	adds r0, #0xc0
	adds r2, r5, r0
	adds r0, #0x60
	adds r3, r5, r0
	adds r0, r4, #0
	bl FUN_080b95d0
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B73F8
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080B743C
	.align 2, 0
_080B73F0: .4byte 0x00001428
_080B73F4: .4byte 0x00000D98
_080B73F8:
	ldr r1, _080B7414 @ =0x0000140E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _080B7418
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _080B7424
	.align 2, 0
_080B7414: .4byte 0x0000140E
_080B7418:
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_080B7424:
	str r1, [r0]
	ldr r0, _080B74A8 @ =0x0000140E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080B743C
	movs r0, #0
	strh r0, [r1]
_080B743C:
	ldr r1, _080B74AC @ =0x000010F8
	adds r6, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_082372cc
	ldr r0, _080B74B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #4
	ands r0, r1
	adds r7, r4, #0
	cmp r0, #0
	beq _080B74C4
	ldr r1, _080B74B4 @ =0x00001428
	adds r0, r5, r1
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B74C4
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080B74B8 @ =0x00001118
	adds r0, r5, r1
	movs r1, #0x20
	bl FUN_080b9938
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _080B74BC @ =0x0000130C
	adds r0, r5, r1
	movs r4, #1
	rsbs r4, r4, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r0, _080B74C0 @ =0x00000107
	bl PlaySound_082406e0
	b _080B7514
	.align 2, 0
_080B74A8: .4byte 0x0000140E
_080B74AC: .4byte 0x000010F8
_080B74B0: .4byte 0x030044E0
_080B74B4: .4byte 0x00001428
_080B74B8: .4byte 0x00001118
_080B74BC: .4byte 0x0000130C
_080B74C0: .4byte 0x00000107
_080B74C4:
	ldr r0, _080B74FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B7554
	adds r0, r5, #0
	bl FUN_080b6fa4
	adds r4, r0, #0
	ldr r1, _080B7500 @ =0x0000130C
	adds r0, r5, r1
	movs r6, #1
	rsbs r6, r6, #0
	adds r1, r6, #0
	adds r2, r6, #0
	bl FUN_080b98c0
	cmp r4, #1
	beq _080B7504
	cmp r4, #2
	beq _080B7514
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080B7590
	.align 2, 0
_080B74FC: .4byte 0x030044E0
_080B7500: .4byte 0x0000130C
_080B7504:
	adds r0, r5, #0
	bl FUN_080b6ca8
	ldr r1, _080B7510 @ =0x080B7751
	b _080B7538
	.align 2, 0
_080B7510: .4byte 0x080B7751
_080B7514:
	ldr r1, _080B7544 @ =0x000013F4
	adds r0, r5, r1
	ldr r2, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r3, #1
	rsbs r3, r3, #0
	bl FUN_080b5b50
	ldr r1, _080B7548 @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B754C @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080B7550 @ =FUN_080b7794
_080B7538:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B7590
	.align 2, 0
_080B7544: .4byte 0x000013F4
_080B7548: .4byte 0x000011B8
_080B754C: .4byte 0x0000140D
_080B7550: .4byte FUN_080b7794
_080B7554:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B756A
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080b70ac
	b _080B7590
_080B756A:
	ldr r0, _080B7598 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080B7590
	ldr r0, _080B759C @ =0x000010F8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080b69b8
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b6e70
_080B7590:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B7598: .4byte 0x00001428
_080B759C: .4byte 0x000010F8

	thumb_func_start FUN_080b75a0
FUN_080b75a0: @ 0x080B75A0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080B75F4 @ =0x000010F8
	adds r5, r4, r0
	adds r6, r4, #0
	adds r6, #0x18
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_082372cc
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080B75F8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B7604
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080B75FC @ =0x00001428
	adds r0, r4, r1
	adds r1, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080b69b8
	ldr r1, _080B7600 @ =FUN_080b73b8
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B7656
	.align 2, 0
_080B75F4: .4byte 0x000010F8
_080B75F8: .4byte 0x030044E0
_080B75FC: .4byte 0x00001428
_080B7600: .4byte FUN_080b73b8
_080B7604:
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080B7656
	movs r0, #0x88
	lsls r0, r0, #5
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080B765C @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080B7660 @ =0x000013F4
	adds r0, r4, r1
	ldr r2, [r0]
	movs r3, #1
	rsbs r3, r3, #0
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080b5b50
	ldr r1, _080B7664 @ =0x000011B8
	adds r0, r4, r1
	ldr r1, _080B7668 @ =0x0000140D
	adds r2, r4, r1
	adds r1, r6, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080B766C @ =FUN_080b7794
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
_080B7656:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B765C: .4byte 0x00000107
_080B7660: .4byte 0x000013F4
_080B7664: .4byte 0x000011B8
_080B7668: .4byte 0x0000140D
_080B766C: .4byte FUN_080b7794

	thumb_func_start FUN_080b7670
FUN_080b7670: @ 0x080B7670
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B76B0 @ =0x000011B8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080B76B4 @ =0x0000140D
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080B76C4
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortWeapons
	ldr r1, _080B76B8 @ =0x0000142C
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080B76BC @ =0x0000142D
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080B76C0 @ =0x0000142E
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b70ac
	b _080B76D4
	.align 2, 0
_080B76B0: .4byte 0x000011B8
_080B76B4: .4byte 0x0000140D
_080B76B8: .4byte 0x0000142C
_080B76BC: .4byte 0x0000142D
_080B76C0: .4byte 0x0000142E
_080B76C4:
	cmp r0, #0
	bne _080B76D4
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b70ac
_080B76D4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B76DC:
	.byte 0x10, 0xB5, 0x04, 0x1C
	.byte 0x10, 0x49, 0x60, 0x18, 0x21, 0x1C, 0x18, 0x31, 0x0F, 0x4B, 0xE2, 0x18, 0x02, 0xF0, 0x46, 0xF8
	.byte 0x01, 0x28, 0x21, 0xD1, 0xDD, 0x20, 0x88, 0xF1, 0xF3, 0xFF, 0x0C, 0x49, 0x60, 0x18, 0x00, 0x78
	.byte 0x8B, 0xF1, 0xF0, 0xFA, 0x0A, 0x4B, 0xE1, 0x18, 0x00, 0x22, 0x04, 0x20, 0x08, 0x70, 0x09, 0x49
	.byte 0x60, 0x18, 0x02, 0x70, 0x02, 0x33, 0xE1, 0x18, 0x10, 0x20, 0x08, 0x70, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0xC5, 0xFC, 0x11, 0xE0, 0xB8, 0x11, 0x00, 0x00, 0x0D, 0x14, 0x00, 0x00, 0x68, 0x14, 0x00, 0x00
	.byte 0x2C, 0x14, 0x00, 0x00, 0x2D, 0x14, 0x00, 0x00, 0x00, 0x28, 0x05, 0xD1, 0xDE, 0x20, 0x88, 0xF1
	.byte 0xCF, 0xFF, 0x20, 0x1C, 0xFF, 0xF7, 0xB2, 0xFC, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x0C, 0x49, 0x60, 0x18, 0x02, 0xF0, 0xC0, 0xF9, 0x00, 0x28, 0x10, 0xD0
	.byte 0x0A, 0x4B, 0xE0, 0x18, 0x00, 0x78, 0x0A, 0x49, 0x62, 0x18, 0x10, 0x18, 0x00, 0x78, 0x03, 0x33
	.byte 0xE1, 0x18, 0x09, 0x78, 0x52, 0x18, 0x11, 0x78, 0x8B, 0xF1, 0x64, 0xFA, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0x95, 0xFC, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x18, 0x12, 0x00, 0x00, 0x2B, 0x14, 0x00, 0x00
	.byte 0x58, 0x14, 0x00, 0x00

	thumb_func_start FUN_080b7794
FUN_080b7794: @ 0x080B7794
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B77D0 @ =0x000011B8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080B77D4 @ =0x0000140D
	adds r2, r4, r3
	bl FUN_080b977c
	adds r2, r0, #0
	cmp r2, #1
	bne _080B77DC
	movs r1, #0x88
	lsls r1, r1, #5
	adds r0, r4, r1
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080b6dc4
	ldr r1, _080B77D8 @ =0x080B77F5
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B77EC
	.align 2, 0
_080B77D0: .4byte 0x000011B8
_080B77D4: .4byte 0x0000140D
_080B77D8: .4byte 0x080B77F5
_080B77DC:
	cmp r2, #0
	bne _080B77EC
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b70ac
_080B77EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B77F4:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x0D, 0x49, 0x60, 0x18, 0x02, 0xF0, 0x6E, 0xF9
	.byte 0x00, 0x28, 0x11, 0xD0, 0x0B, 0x4A, 0xA1, 0x18, 0x2A, 0x32, 0xA0, 0x18, 0x09, 0x78, 0x40, 0x18
	.byte 0x00, 0x78, 0x8B, 0xF1, 0xF9, 0xF9, 0x87, 0x20, 0x40, 0x00, 0x88, 0xF1, 0x61, 0xFF, 0x06, 0x49
	.byte 0x20, 0x1C, 0x00, 0x22, 0xFE, 0xF7, 0x56, 0xF9, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x18, 0x12, 0x00, 0x00, 0x2E, 0x14, 0x00, 0x00, 0x3D, 0x78, 0x0B, 0x08

	thumb_func_start FUN_080b783c
FUN_080b783c: @ 0x080B783C
	push {lr}
	adds r3, r0, #0
	ldr r0, _080B7864 @ =0x0000140E
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	bhi _080B7884
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B786C
	ldr r2, _080B7868 @ =0x00000DBA
	adds r1, r3, r2
	b _080B788C
	.align 2, 0
_080B7864: .4byte 0x0000140E
_080B7868: .4byte 0x00000DBA
_080B786C:
	ldrh r1, [r2]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x40
	subs r1, r1, r0
	ldr r2, _080B7880 @ =0x00000DBA
	adds r0, r3, r2
	strh r1, [r0]
	b _080B789E
	.align 2, 0
_080B7880: .4byte 0x00000DBA
_080B7884:
	cmp r1, #0xf
	bhi _080B7898
	ldr r0, _080B7894 @ =0x00000DBA
	adds r1, r3, r0
_080B788C:
	movs r0, #0x40
	strh r0, [r1]
	b _080B789E
	.align 2, 0
_080B7894: .4byte 0x00000DBA
_080B7898:
	adds r0, r3, #0
	bl FUN_080b70ac
_080B789E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b78a4
FUN_080b78a4: @ 0x080B78A4
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_080b5afc
	adds r0, r4, #0
	bl FUN_080b6a74
	ldr r0, _080B78F4 @ =0x00001428
	adds r5, r4, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080b9ff8
	ldr r0, _080B78F8 @ =0x000010F8
	adds r1, r4, r0
	adds r0, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080b69b8
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b6e70
	ldr r1, _080B78FC @ =FUN_080b7118
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080b5ad4
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B78F4: .4byte 0x00001428
_080B78F8: .4byte 0x000010F8
_080B78FC: .4byte FUN_080b7118

	thumb_func_start FUN_080b7900
FUN_080b7900: @ 0x080B7900
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _080B7930 @ =0x00001429
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	bhi _080B793C
	ldr r2, _080B7934 @ =0x0000142B
	adds r1, r5, r2
	adds r2, #0x2d
	adds r0, r5, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _080B7938 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r6, [r0, r2]
	b _080B7940
	.align 2, 0
_080B7930: .4byte 0x00001429
_080B7934: .4byte 0x0000142B
_080B7938: .4byte 0x030046A0
_080B793C:
	movs r6, #1
	rsbs r6, r6, #0
_080B7940:
	cmp r6, #0
	bge _080B795C
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _080B79C6
_080B795C:
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080B79CC @ =0x00000F18
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x38
	movs r2, #0xcf
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _080B79D0 @ =0x000013FC
	adds r5, r5, r2
	ldr r0, [r5]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r0, _080B79D4 @ =0x08DAA7B0
	lsls r4, r6, #3
	adds r4, r4, r0
	ldrb r1, [r4, #1]
	movs r0, #0
	bl FUN_08049e6c
	ldrb r1, [r4, #2]
	movs r0, #1
	bl FUN_08049e6c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r6, #0
	bl FUN_08047a28
	ldr r0, [r5]
	bl VM_ParseStringRef
	adds r0, #0x25
	adds r0, r0, r6
	bl Textbox_LookupString
	bl FUN_08049e30
_080B79C6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B79CC: .4byte 0x00000F18
_080B79D0: .4byte 0x000013FC
_080B79D4: .4byte 0x08DAA7B0

	thumb_func_start FUN_080b79d8
FUN_080b79d8: @ 0x080B79D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _080B7A68 @ =0x00001412
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r2, _080B7A6C @ =0x00001413
	adds r1, r7, r2
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r3, #0
	mov sb, r3
	adds r0, r7, #0
	adds r0, #0x80
	str r0, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
_080B7A06:
	movs r2, #0
	mov sl, r2
	mov r3, sb
	lsls r3, r3, #2
	mov r8, r3
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r2, [sp, #8]
	adds r5, r2, r0
	mov r1, r8
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r3, [sp, #4]
	adds r4, r0, r3
_080B7A28:
	mov r6, r8
	add r6, sl
	ldr r1, _080B7A70 @ =0x00001458
	adds r0, r7, r1
	adds r0, r0, r6
	ldrb r0, [r0]
	ldr r1, _080B7A74 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	cmp r2, #0
	blt _080B7A78
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080B7A8E
	.align 2, 0
_080B7A68: .4byte 0x00001412
_080B7A6C: .4byte 0x00001413
_080B7A70: .4byte 0x00001458
_080B7A74: .4byte 0x030046A0
_080B7A78:
	ldr r0, _080B7AA8 @ =0x00001412
	adds r1, r7, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B7A86
	strb r6, [r1]
_080B7A86:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B7A8E:
	ldr r0, _080B7AAC @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bne _080B7AB0
	adds r0, r5, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080B7AB8
	.align 2, 0
_080B7AA8: .4byte 0x00001412
_080B7AAC: .4byte 0x030046A0
_080B7AB0:
	adds r0, r5, #0
	ldr r1, _080B7B4C @ =0x000002DF
	bl FUN_080b95bc
_080B7AB8:
	adds r5, #0x60
	adds r4, #0x60
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #3
	ble _080B7A28
	ldr r0, [sp, #8]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #8]
	add sb, r2
	mov r2, sb
	cmp r2, #3
	ble _080B7A06
	movs r3, #0
	mov sb, r3
_080B7ADC:
	movs r0, #0
	mov sl, r0
	mov r1, sb
	lsls r1, r1, #2
	mov r8, r1
	mov r2, sb
	adds r2, #1
	str r2, [sp]
	mov r2, r8
	adds r2, #0x13
	mov r3, sb
	lsls r0, r3, #3
	add r0, r8
	lsls r0, r0, #5
	movs r3, #0xf3
	lsls r3, r3, #3
	adds r1, r7, r3
	adds r6, r0, r1
	mov r5, r8
	adds r5, #0x10
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r1, [sp, #4]
	adds r4, r0, r1
_080B7B0E:
	ldr r2, _080B7B50 @ =0x00001458
	adds r0, r7, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	ldr r1, _080B7B54 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r2, [r0, r1]
	cmp r2, #0
	blt _080B7B58
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080B7B6E
	.align 2, 0
_080B7B4C: .4byte 0x000002DF
_080B7B50: .4byte 0x00001458
_080B7B54: .4byte 0x030046A0
_080B7B58:
	ldr r2, _080B7BD0 @ =0x00001413
	adds r1, r7, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B7B66
	strb r5, [r1]
_080B7B66:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B7B6E:
	adds r4, #0x60
	adds r6, #0x60
	adds r5, #1
	movs r3, #1
	add sl, r3
	mov r0, sl
	cmp r0, #3
	ble _080B7B0E
	ldr r1, [sp]
	mov sb, r1
	cmp r1, #3
	ble _080B7ADC
	ldr r0, _080B7BD4 @ =0x030046A0
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x5c
	ldrh r4, [r3]
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	blt _080B7BE0
	movs r0, #0xf8
	lsls r0, r0, #4
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	ldr r2, _080B7BD8 @ =0x00000F98
	adds r1, r7, r2
	strh r0, [r1]
	ldrh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x12
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	ldr r3, _080B7BDC @ =0x00000F9A
	adds r1, r7, r3
	strh r0, [r1]
	b _080B7BEE
	.align 2, 0
_080B7BD0: .4byte 0x00001413
_080B7BD4: .4byte 0x030046A0
_080B7BD8: .4byte 0x00000F98
_080B7BDC: .4byte 0x00000F9A
_080B7BE0:
	movs r1, #0xf8
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_080B7BEE:
	movs r3, #1
	ldr r2, [sp, #4]
	movs r0, #0xf6
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r2, #2
_080B7BFA:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080B7BFA
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b7c18
FUN_080b7c18: @ 0x080B7C18
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _080B7C54
	ldr r1, _080B7C38 @ =0x00001429
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080B7C40
	ldr r2, _080B7C3C @ =0x0000130C
	adds r0, r4, r2
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080B7D5E
	.align 2, 0
_080B7C38: .4byte 0x00001429
_080B7C3C: .4byte 0x0000130C
_080B7C40:
	ldr r3, _080B7C50 @ =0x0000130C
	adds r0, r4, r3
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080B7D5E
	.align 2, 0
_080B7C50: .4byte 0x0000130C
_080B7C54:
	ldr r5, _080B7CA8 @ =0x0000142E
	adds r0, r4, r5
	ldrb r3, [r0]
	ldr r0, _080B7CAC @ =0x00001458
	adds r1, r4, r0
	adds r0, r1, r3
	ldrb r6, [r0]
	ldr r0, _080B7CB0 @ =0x030046A0
	ldr r2, [r0]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	bge _080B7CBC
	ldr r3, _080B7CB4 @ =0x0000142B
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, r1, r0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r2
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _080B7D5E
	adds r0, r2, #0
	adds r0, #0x5c
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	bne _080B7D5E
	ldr r1, _080B7CB8 @ =0x0000142C
	adds r0, r4, r1
	ldrb r0, [r0]
	b _080B7D5E
	.align 2, 0
_080B7CA8: .4byte 0x0000142E
_080B7CAC: .4byte 0x00001458
_080B7CB0: .4byte 0x030046A0
_080B7CB4: .4byte 0x0000142B
_080B7CB8: .4byte 0x0000142C
_080B7CBC:
	ldr r0, _080B7CE0 @ =0x0000142B
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, r3
	bne _080B7D00
	ldr r1, _080B7CE4 @ =0x00001428
	adds r0, r4, r1
	movs r1, #2
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B7D2C
	ldrb r0, [r5]
	cmp r0, #0xf
	bhi _080B7CEC
	ldr r2, _080B7CE8 @ =0x00001413
	adds r0, r4, r2
	b _080B7CF0
	.align 2, 0
_080B7CE0: .4byte 0x0000142B
_080B7CE4: .4byte 0x00001428
_080B7CE8: .4byte 0x00001413
_080B7CEC:
	ldr r3, _080B7CFC @ =0x00001412
	adds r0, r4, r3
_080B7CF0:
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mvns r0, r0
	lsrs r1, r0, #0x1f
	b _080B7D36
	.align 2, 0
_080B7CFC: .4byte 0x00001412
_080B7D00:
	ldrb r0, [r5]
	adds r0, r1, r0
	ldrb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x5c
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	bne _080B7D1C
	ldr r1, _080B7D18 @ =0x0000142C
	adds r0, r4, r1
	b _080B7D24
	.align 2, 0
_080B7D18: .4byte 0x0000142C
_080B7D1C:
	cmp r6, r0
	bne _080B7D34
	ldr r2, _080B7D30 @ =0x00001429
	adds r0, r4, r2
_080B7D24:
	ldrb r0, [r0]
	movs r1, #1
	cmp r0, #3
	bls _080B7D36
_080B7D2C:
	movs r1, #0
	b _080B7D36
	.align 2, 0
_080B7D30: .4byte 0x00001429
_080B7D34:
	movs r1, #1
_080B7D36:
	cmp r1, #1
	bne _080B7D50
	ldr r3, _080B7D4C @ =0x0000130C
	adds r0, r4, r3
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080B7D5E
	.align 2, 0
_080B7D4C: .4byte 0x0000130C
_080B7D50:
	ldr r5, _080B7D64 @ =0x0000130C
	adds r0, r4, r5
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080B7D5E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B7D64: .4byte 0x0000130C

	thumb_func_start FUN_080b7d68
FUN_080b7d68: @ 0x080B7D68
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080B7DC4 @ =0x0000142E
	adds r0, r4, r1
	ldrb r3, [r0]
	ldr r2, _080B7DC8 @ =0x00001458
	adds r1, r4, r2
	adds r0, r1, r3
	ldrb r6, [r0]
	ldr r0, _080B7DCC @ =0x030046A0
	ldr r2, [r0]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	bge _080B7DD8
	ldr r3, _080B7DD0 @ =0x0000142B
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, r1, r0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r2
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _080B7E7C
	adds r0, r2, #0
	adds r0, #0x5c
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	bne _080B7E84
_080B7DB8:
	ldr r1, _080B7DD4 @ =0x0000142C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080B7E7C
	b _080B7E84
	.align 2, 0
_080B7DC4: .4byte 0x0000142E
_080B7DC8: .4byte 0x00001458
_080B7DCC: .4byte 0x030046A0
_080B7DD0: .4byte 0x0000142B
_080B7DD4: .4byte 0x0000142C
_080B7DD8:
	ldr r0, _080B7E24 @ =0x0000142B
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, r3
	bne _080B7E54
	ldr r1, _080B7E28 @ =0x00001428
	adds r0, r4, r1
	movs r1, #2
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B7E7C
	ldrb r0, [r5]
	cmp r0, #0xf
	bhi _080B7E34
	ldr r3, _080B7E2C @ =0x00001413
	adds r2, r4, r3
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080B7E7C
	movs r0, #3
	ands r0, r1
_080B7E08:
	ldr r3, _080B7E30 @ =0x00001429
	adds r1, r4, r3
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r2, r0]
	subs r0, #0x10
	asrs r0, r0, #2
	adds r3, #1
	adds r1, r4, r3
	strb r0, [r1]
	ldrb r0, [r2]
	strb r0, [r5]
	b _080B7E84
	.align 2, 0
_080B7E24: .4byte 0x0000142B
_080B7E28: .4byte 0x00001428
_080B7E2C: .4byte 0x00001413
_080B7E30: .4byte 0x00001429
_080B7E34:
	ldr r0, _080B7E50 @ =0x00001412
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080B7E7C
	adds r0, r1, #0
	subs r0, #0x10
	movs r1, #3
	ands r0, r1
	adds r0, #4
	b _080B7E08
	.align 2, 0
_080B7E50: .4byte 0x00001412
_080B7E54:
	cmp r0, #0x20
	bne _080B7E5C
	movs r0, #2
	b _080B7E86
_080B7E5C:
	ldrb r0, [r5]
	adds r0, r1, r0
	ldrb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x5c
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	beq _080B7DB8
	cmp r6, r0
	bne _080B7E84
	ldr r2, _080B7E80 @ =0x00001429
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #3
	bls _080B7E84
_080B7E7C:
	movs r0, #0
	b _080B7E86
	.align 2, 0
_080B7E80: .4byte 0x00001429
_080B7E84:
	movs r0, #1
_080B7E86:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b7e8c
FUN_080b7e8c: @ 0x080B7E8C
	push {r4, r5, r6, lr}
	ldr r2, _080B7ED4 @ =0x0000142B
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _080B7ED8 @ =0x00001458
	adds r2, r0, r3
	adds r1, r2, r1
	ldrb r6, [r1]
	ldr r1, _080B7EDC @ =0x0000142E
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r2, r2, r0
	ldrb r5, [r2]
	ldr r0, _080B7EE0 @ =0x030046A0
	ldr r3, [r0]
	lsls r2, r6, #1
	adds r2, r2, r3
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r2, r2, r1
	movs r0, #0
	ldrsh r4, [r2, r0]
	lsls r0, r5, #1
	adds r0, r0, r3
	adds r0, r0, r1
	ldrh r1, [r0]
	strh r1, [r2]
	strh r4, [r0]
	adds r3, #0x5c
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, r6
	bne _080B7EE4
	strh r5, [r3]
	b _080B7EEA
	.align 2, 0
_080B7ED4: .4byte 0x0000142B
_080B7ED8: .4byte 0x00001458
_080B7EDC: .4byte 0x0000142E
_080B7EE0: .4byte 0x030046A0
_080B7EE4:
	cmp r0, r5
	bne _080B7EEA
	strh r6, [r3]
_080B7EEA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b7ef0
FUN_080b7ef0: @ 0x080B7EF0
	ldr r2, _080B7F18 @ =0x0000142E
	adds r1, r0, r2
	adds r2, #0x2a
	adds r0, r0, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _080B7F1C @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080B7F18: .4byte 0x0000142E
_080B7F1C: .4byte 0x030046A0

	thumb_func_start FUN_080b7f20
FUN_080b7f20: @ 0x080B7F20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	adds r6, r0, #0
	movs r4, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x48]
	add r1, sp, #0x34
	mov sl, r1
	add r2, sp, #0x3c
	mov sb, r2
	subs r0, #0x10
	str r0, [sp, #0x44]
	mov r1, sb
	str r1, [sp, #0x4c]
	mov r2, sl
	str r2, [sp, #0x50]
	ldr r0, [sp, #0x48]
	mov r8, r0
_080B7F4E:
	cmp r4, #0
	bne _080B7F5C
	ldr r1, _080B7F58 @ =0x0000142E
	adds r0, r6, r1
	b _080B7F60
	.align 2, 0
_080B7F58: .4byte 0x0000142E
_080B7F5C:
	ldr r2, _080B7FB8 @ =0x0000142B
	adds r0, r6, r2
_080B7F60:
	ldrb r3, [r0]
	adds r1, r3, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r1, r6, #0
	adds r1, #0x80
	adds r1, r1, r0
	ldr r0, [r1]
	movs r5, #1
	orrs r0, r5
	str r0, [r1]
	ldr r7, _080B7FBC @ =0x030046A0
	ldr r0, [r7]
	adds r0, #0x5c
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _080B7FC0 @ =0x00001458
	adds r0, r6, r2
	adds r2, r0, r3
	ldrb r0, [r2]
	cmp r1, r0
	bne _080B7F9A
	movs r0, #0xf8
	lsls r0, r0, #4
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
_080B7F9A:
	ldrb r0, [r2]
	ldr r1, [r7]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	blt _080B7FC4
	mov r0, r8
	str r5, [r0]
	b _080B7FCA
	.align 2, 0
_080B7FB8: .4byte 0x0000142B
_080B7FBC: .4byte 0x030046A0
_080B7FC0: .4byte 0x00001458
_080B7FC4:
	movs r0, #0
	mov r2, r8
	str r0, [r2]
_080B7FCA:
	adds r0, r1, #0
	adds r0, #0x43
	ldr r1, [sp, #0x50]
	stm r1!, {r0}
	str r1, [sp, #0x50]
	ldr r0, _080B8038 @ =0x000002DF
	ldr r2, [sp, #0x4c]
	stm r2!, {r0}
	str r2, [sp, #0x4c]
	lsls r0, r4, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r3, #0
	bl FUN_080b9938
	movs r0, #4
	add r8, r0
	adds r4, #1
	cmp r4, #1
	ble _080B7F4E
	add r2, sp, #0x14
	ldr r3, [sp, #0x44]
	movs r4, #1
_080B7FF8:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r4, #1
	cmp r4, #0
	bge _080B7FF8
	ldr r1, _080B803C @ =0x00001218
	adds r0, r6, r1
	mov r2, sl
	str r2, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x48]
	add r2, sp, #0xc
	ldr r3, [sp, #0x44]
	bl FUN_080b9a28
	ldr r0, _080B8040 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B8038: .4byte 0x000002DF
_080B803C: .4byte 0x00001218
_080B8040: .4byte 0x0000038A

	thumb_func_start FUN_080b8044
FUN_080b8044: @ 0x080B8044
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r4, #1
	str r4, [sp, #0x2c]
	ldr r0, _080B80EC @ =0x0000142E
	adds r3, r5, r0
	ldrb r0, [r3]
	adds r0, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r5, #0
	adds r2, #0x80
	adds r2, r2, r1
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	ldr r1, _080B80F0 @ =0x00001458
	adds r0, r5, r1
	ldrb r1, [r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _080B80F4 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r0, #0x43
	str r0, [sp, #0x34]
	ldr r0, _080B80F8 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r3]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	movs r0, #0x43
	add r6, sp, #0x34
	str r0, [r6, #4]
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
	ldr r0, _080B80FC @ =0x00001218
	adds r5, r5, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080B8100 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B80EC: .4byte 0x0000142E
_080B80F0: .4byte 0x00001458
_080B80F4: .4byte 0x030046A0
_080B80F8: .4byte 0x000002DF
_080B80FC: .4byte 0x00001218
_080B8100: .4byte 0x0000038A

	thumb_func_start FUN_080b8104
FUN_080b8104: @ 0x080B8104
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x8b
	lsls r0, r0, #5
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x88
	lsls r0, r0, #5
	adds r2, r5, r0
	ldr r0, [r2]
	subs r1, #3
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_080b79d8
	ldr r0, _080B8164 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r0, _080B8168 @ =0x000010F8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FUN_080b7900
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b7c18
	ldr r1, _080B816C @ =FUN_080b8170
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080b5ad4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B8164: .4byte 0x00001428
_080B8168: .4byte 0x000010F8
_080B816C: .4byte FUN_080b8170

	thumb_func_start FUN_080b8170
FUN_080b8170: @ 0x080B8170
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080B81A4 @ =0x00001428
	adds r4, r5, r0
	ldr r2, _080B81A8 @ =0x00000D98
	adds r1, r5, r2
	ldr r3, _080B81AC @ =0x00000E58
	adds r2, r5, r3
	ldr r0, _080B81B0 @ =0x00000EB8
	adds r3, r5, r0
	adds r0, r4, #0
	bl FUN_080b95d0
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B81B4
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080B81C2
	.align 2, 0
_080B81A4: .4byte 0x00001428
_080B81A8: .4byte 0x00000D98
_080B81AC: .4byte 0x00000E58
_080B81B0: .4byte 0x00000EB8
_080B81B4:
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080B81C2:
	str r1, [r0]
	ldr r4, _080B8224 @ =0x030044E0
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080B8234
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b5ac8
	ldr r3, _080B8228 @ =0x000010F8
	adds r0, r5, r3
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _080B822C @ =0x0000130C
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B8202
	b _080B83F8
_080B8202:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r2, _080B8230 @ =0x00001478
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080B821C
	b _080B83F8
_080B821C:
	movs r0, #0
	strb r0, [r1]
	b _080B83F8
	.align 2, 0
_080B8224: .4byte 0x030044E0
_080B8228: .4byte 0x000010F8
_080B822C: .4byte 0x0000130C
_080B8230: .4byte 0x00001478
_080B8234:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b5ac8
	ldr r3, _080B82A4 @ =0x000010F8
	adds r6, r5, r3
	adds r7, r5, #0
	adds r7, #0x18
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082372cc
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B8258
	b _080B83D4
_080B8258:
	ldr r1, _080B82A8 @ =0x0000142B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x21
	bne _080B82C4
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r2, _080B82AC @ =0x00001428
	adds r0, r5, r2
	bl FUN_080b9fd8
	ldr r3, _080B82B0 @ =0x000013F4
	adds r0, r5, r3
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl FUN_080b5b50
	ldr r1, _080B82B4 @ =0x000011B8
	adds r0, r5, r1
	ldr r3, _080B82B8 @ =0x0000140D
	adds r2, r5, r3
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080B82BC @ =0x0000130C
	adds r0, r5, r1
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B82C0 @ =FUN_080b86bc
	b _080B83C4
	.align 2, 0
_080B82A4: .4byte 0x000010F8
_080B82A8: .4byte 0x0000142B
_080B82AC: .4byte 0x00001428
_080B82B0: .4byte 0x000013F4
_080B82B4: .4byte 0x000011B8
_080B82B8: .4byte 0x0000140D
_080B82BC: .4byte 0x0000130C
_080B82C0: .4byte FUN_080b86bc
_080B82C4:
	cmp r0, #0x22
	bne _080B8324
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r2, _080B830C @ =0x00001428
	adds r0, r5, r2
	bl FUN_080b9fd8
	ldr r3, _080B8310 @ =0x000013F4
	adds r0, r5, r3
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #4
	adds r3, r4, #0
	bl FUN_080b5b50
	ldr r1, _080B8314 @ =0x000011B8
	adds r0, r5, r1
	ldr r3, _080B8318 @ =0x0000140D
	adds r2, r5, r3
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080B831C @ =0x0000130C
	adds r0, r5, r1
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B8320 @ =0x080B8729
	b _080B83C4
	.align 2, 0
_080B830C: .4byte 0x00001428
_080B8310: .4byte 0x000013F4
_080B8314: .4byte 0x000011B8
_080B8318: .4byte 0x0000140D
_080B831C: .4byte 0x0000130C
_080B8320: .4byte 0x080B8729
_080B8324:
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r2, _080B8390 @ =0x00001428
	adds r4, r5, r2
	adds r0, r4, #0
	bl FUN_080b9fd8
	movs r3, #0x8b
	lsls r3, r3, #5
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080B8394 @ =0x00001178
	adds r2, r5, r0
	ldr r1, _080B8398 @ =0x00001118
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080B839C @ =0x0000142E
	adds r1, r5, r2
	ldr r3, _080B83A0 @ =0x00001458
	adds r0, r5, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r2, [r0]
	ldr r0, _080B83A4 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _080B83B2
	adds r0, r1, #0
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bne _080B83A8
	adds r0, r4, #0
	movs r1, #0x1e
	bl FUN_080b9d94
	b _080B83BA
	.align 2, 0
_080B8390: .4byte 0x00001428
_080B8394: .4byte 0x00001178
_080B8398: .4byte 0x00001118
_080B839C: .4byte 0x0000142E
_080B83A0: .4byte 0x00001458
_080B83A4: .4byte 0x030046A0
_080B83A8:
	adds r0, r4, #0
	movs r1, #0x18
	bl FUN_080b9d94
	b _080B83BA
_080B83B2:
	adds r0, r4, #0
	movs r1, #0x1c
	bl FUN_080b9d94
_080B83BA:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b7c18
	ldr r1, _080B83D0 @ =FUN_080b8404
_080B83C4:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B83F8
	.align 2, 0
_080B83D0: .4byte FUN_080b8404
_080B83D4:
	ldr r2, _080B8400 @ =0x00001428
	adds r4, r5, r2
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080B83F8
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080b7900
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b7c18
_080B83F8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B8400: .4byte 0x00001428

	thumb_func_start FUN_080b8404
FUN_080b8404: @ 0x080B8404
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080B843C @ =0x00001428
	adds r4, r5, r0
	ldr r0, _080B8440 @ =0x00000D98
	adds r1, r5, r0
	adds r0, #0xc0
	adds r2, r5, r0
	adds r0, #0x60
	adds r3, r5, r0
	adds r0, r4, #0
	bl FUN_080b95d0
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B8444
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080B8488
	.align 2, 0
_080B843C: .4byte 0x00001428
_080B8440: .4byte 0x00000D98
_080B8444:
	ldr r1, _080B8460 @ =0x0000140E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _080B8464
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _080B8470
	.align 2, 0
_080B8460: .4byte 0x0000140E
_080B8464:
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_080B8470:
	str r1, [r0]
	ldr r0, _080B84F4 @ =0x0000140E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080B8488
	movs r0, #0
	strh r0, [r1]
_080B8488:
	ldr r1, _080B84F8 @ =0x000010F8
	adds r6, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_082372cc
	ldr r0, _080B84FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #4
	ands r0, r1
	adds r7, r4, #0
	cmp r0, #0
	beq _080B8510
	ldr r1, _080B8500 @ =0x00001428
	adds r0, r5, r1
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B8510
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080B8504 @ =0x00001118
	adds r0, r5, r1
	movs r1, #0x20
	bl FUN_080b9938
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _080B8508 @ =0x0000130C
	adds r0, r5, r1
	movs r4, #1
	rsbs r4, r4, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r0, _080B850C @ =0x00000107
	bl PlaySound_082406e0
	b _080B8560
	.align 2, 0
_080B84F4: .4byte 0x0000140E
_080B84F8: .4byte 0x000010F8
_080B84FC: .4byte 0x030044E0
_080B8500: .4byte 0x00001428
_080B8504: .4byte 0x00001118
_080B8508: .4byte 0x0000130C
_080B850C: .4byte 0x00000107
_080B8510:
	ldr r0, _080B8548 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B85A0
	adds r0, r5, #0
	bl FUN_080b7d68
	adds r4, r0, #0
	ldr r1, _080B854C @ =0x0000130C
	adds r0, r5, r1
	movs r6, #1
	rsbs r6, r6, #0
	adds r1, r6, #0
	adds r2, r6, #0
	bl FUN_080b98c0
	cmp r4, #1
	beq _080B8550
	cmp r4, #2
	beq _080B8560
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080B85DC
	.align 2, 0
_080B8548: .4byte 0x030044E0
_080B854C: .4byte 0x0000130C
_080B8550:
	adds r0, r5, #0
	bl FUN_080b7f20
	ldr r1, _080B855C @ =0x080B879D
	b _080B8584
	.align 2, 0
_080B855C: .4byte 0x080B879D
_080B8560:
	ldr r1, _080B8590 @ =0x000013F4
	adds r0, r5, r1
	ldr r2, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r3, #1
	rsbs r3, r3, #0
	bl FUN_080b5b50
	ldr r1, _080B8594 @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B8598 @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080B859C @ =FUN_080b87c4
_080B8584:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B85DC
	.align 2, 0
_080B8590: .4byte 0x000013F4
_080B8594: .4byte 0x000011B8
_080B8598: .4byte 0x0000140D
_080B859C: .4byte FUN_080b87c4
_080B85A0:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B85B6
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080b8104
	b _080B85DC
_080B85B6:
	ldr r0, _080B85E4 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080B85DC
	ldr r0, _080B85E8 @ =0x000010F8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080b7900
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b7c18
_080B85DC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B85E4: .4byte 0x00001428
_080B85E8: .4byte 0x000010F8

	thumb_func_start FUN_080b85ec
FUN_080b85ec: @ 0x080B85EC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080B8640 @ =0x000010F8
	adds r5, r4, r0
	adds r6, r4, #0
	adds r6, #0x18
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_082372cc
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080B8644 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B8650
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080B8648 @ =0x00001428
	adds r0, r4, r1
	adds r1, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080b7900
	ldr r1, _080B864C @ =FUN_080b8404
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B86A2
	.align 2, 0
_080B8640: .4byte 0x000010F8
_080B8644: .4byte 0x030044E0
_080B8648: .4byte 0x00001428
_080B864C: .4byte FUN_080b8404
_080B8650:
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080B86A2
	movs r0, #0x88
	lsls r0, r0, #5
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080B86A8 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080B86AC @ =0x000013F4
	adds r0, r4, r1
	ldr r2, [r0]
	movs r3, #1
	rsbs r3, r3, #0
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080b5b50
	ldr r1, _080B86B0 @ =0x000011B8
	adds r0, r4, r1
	ldr r1, _080B86B4 @ =0x0000140D
	adds r2, r4, r1
	adds r1, r6, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080B86B8 @ =FUN_080b87c4
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
_080B86A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B86A8: .4byte 0x00000107
_080B86AC: .4byte 0x000013F4
_080B86B0: .4byte 0x000011B8
_080B86B4: .4byte 0x0000140D
_080B86B8: .4byte FUN_080b87c4

	thumb_func_start FUN_080b86bc
FUN_080b86bc: @ 0x080B86BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B86FC @ =0x000011B8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080B8700 @ =0x0000140D
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080B8710
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortArmors
	ldr r1, _080B8704 @ =0x0000142C
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080B8708 @ =0x0000142D
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080B870C @ =0x0000142E
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b8104
	b _080B8720
	.align 2, 0
_080B86FC: .4byte 0x000011B8
_080B8700: .4byte 0x0000140D
_080B8704: .4byte 0x0000142C
_080B8708: .4byte 0x0000142D
_080B870C: .4byte 0x0000142E
_080B8710:
	cmp r0, #0
	bne _080B8720
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b8104
_080B8720:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B8728:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x10, 0x49, 0x60, 0x18
	.byte 0x21, 0x1C, 0x18, 0x31, 0x0F, 0x4B, 0xE2, 0x18, 0x01, 0xF0, 0x20, 0xF8, 0x01, 0x28, 0x21, 0xD1
	.byte 0xDD, 0x20, 0x87, 0xF1, 0xCD, 0xFF, 0x0C, 0x49, 0x60, 0x18, 0x00, 0x78, 0x8A, 0xF1, 0xBC, 0xFD
	.byte 0x0A, 0x4B, 0xE1, 0x18, 0x00, 0x22, 0x04, 0x20, 0x08, 0x70, 0x09, 0x49, 0x60, 0x18, 0x02, 0x70
	.byte 0x02, 0x33, 0xE1, 0x18, 0x10, 0x20, 0x08, 0x70, 0x20, 0x1C, 0xFF, 0xF7, 0xCB, 0xFC, 0x11, 0xE0
	.byte 0xB8, 0x11, 0x00, 0x00, 0x0D, 0x14, 0x00, 0x00, 0x68, 0x14, 0x00, 0x00, 0x2C, 0x14, 0x00, 0x00
	.byte 0x2D, 0x14, 0x00, 0x00, 0x00, 0x28, 0x05, 0xD1, 0xDE, 0x20, 0x87, 0xF1, 0xA9, 0xFF, 0x20, 0x1C
	.byte 0xFF, 0xF7, 0xB8, 0xFC, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x10, 0xB5, 0x04, 0x1C
	.byte 0x07, 0x49, 0x60, 0x18, 0x01, 0xF0, 0x9A, 0xF9, 0x00, 0x28, 0x05, 0xD0, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0x6D, 0xFB, 0x20, 0x1C, 0xFF, 0xF7, 0xA6, 0xFC, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x18, 0x12, 0x00, 0x00

	thumb_func_start FUN_080b87c4
FUN_080b87c4: @ 0x080B87C4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B8800 @ =0x000011B8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080B8804 @ =0x0000140D
	adds r2, r4, r3
	bl FUN_080b977c
	adds r2, r0, #0
	cmp r2, #1
	bne _080B880C
	movs r1, #0x88
	lsls r1, r1, #5
	adds r0, r4, r1
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080b8044
	ldr r1, _080B8808 @ =0x080B8825
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B881C
	.align 2, 0
_080B8800: .4byte 0x000011B8
_080B8804: .4byte 0x0000140D
_080B8808: .4byte 0x080B8825
_080B880C:
	cmp r2, #0
	bne _080B881C
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b8104
_080B881C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B8824:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x0A, 0x49, 0x60, 0x18, 0x01, 0xF0, 0x56, 0xF9
	.byte 0x00, 0x28, 0x0B, 0xD0, 0x20, 0x1C, 0xFF, 0xF7, 0x5B, 0xFB, 0x87, 0x20, 0x40, 0x00, 0x87, 0xF1
	.byte 0x4F, 0xFF, 0x05, 0x49, 0x20, 0x1C, 0x00, 0x22, 0xFD, 0xF7, 0x44, 0xF9, 0x10, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00, 0x18, 0x12, 0x00, 0x00, 0x5D, 0x88, 0x0B, 0x08

	thumb_func_start FUN_080b885c
FUN_080b885c: @ 0x080B885C
	push {lr}
	adds r3, r0, #0
	ldr r0, _080B8884 @ =0x0000140E
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	bhi _080B88A4
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B888C
	ldr r2, _080B8888 @ =0x00000DBA
	adds r1, r3, r2
	b _080B88AC
	.align 2, 0
_080B8884: .4byte 0x0000140E
_080B8888: .4byte 0x00000DBA
_080B888C:
	ldrh r1, [r2]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x40
	subs r1, r1, r0
	ldr r2, _080B88A0 @ =0x00000DBA
	adds r0, r3, r2
	strh r1, [r0]
	b _080B88BE
	.align 2, 0
_080B88A0: .4byte 0x00000DBA
_080B88A4:
	cmp r1, #0xf
	bhi _080B88B8
	ldr r0, _080B88B4 @ =0x00000DBA
	adds r1, r3, r0
_080B88AC:
	movs r0, #0x40
	strh r0, [r1]
	b _080B88BE
	.align 2, 0
_080B88B4: .4byte 0x00000DBA
_080B88B8:
	adds r0, r3, #0
	bl FUN_080b8104
_080B88BE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b88c4
FUN_080b88c4: @ 0x080B88C4
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_080b5afc
	adds r0, r4, #0
	bl FUN_080b79d8
	ldr r0, _080B8914 @ =0x00001428
	adds r5, r4, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080b9ff8
	ldr r0, _080B8918 @ =0x000010F8
	adds r1, r4, r0
	adds r0, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080b7900
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b7c18
	ldr r1, _080B891C @ =FUN_080b8170
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080b5ad4
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B8914: .4byte 0x00001428
_080B8918: .4byte 0x000010F8
_080B891C: .4byte FUN_080b8170

	thumb_func_start FUN_080b8920
FUN_080b8920: @ 0x080B8920
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, _080B8978 @ =0x00001410
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	bne _080B8938
	b _080B8ABE
_080B8938:
	bl Script_GetValue
	ldr r2, _080B897C @ =0x00001411
	adds r6, r4, r2
	strb r0, [r6]
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	bne _080B894E
	b _080B8ABE
_080B894E:
	movs r5, #0
	ldrb r6, [r6]
	cmp r5, r6
	bge _080B896E
	ldr r0, _080B8980 @ =0x00001414
	adds r7, r4, r0
	ldr r1, _080B897C @ =0x00001411
	adds r6, r4, r1
_080B895E:
	bl Script_GetValue
	adds r1, r7, r5
	strb r0, [r1]
	adds r5, #1
	ldrb r2, [r6]
	cmp r5, r2
	blt _080B895E
_080B896E:
	movs r5, #0
	ldr r1, _080B897C @ =0x00001411
	adds r0, r4, r1
	b _080B8A84
	.align 2, 0
_080B8978: .4byte 0x00001410
_080B897C: .4byte 0x00001411
_080B8980: .4byte 0x00001414
_080B8984:
	ldr r2, _080B899C @ =0x00001414
	adds r0, r4, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #4
	bls _080B8992
	b _080B8ABE
_080B8992:
	lsls r0, r0, #2
	ldr r1, _080B89A0 @ =_080B89A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B899C: .4byte 0x00001414
_080B89A0: .4byte _080B89A4
_080B89A4: @ jump table
	.4byte _080B89B8 @ case 0
	.4byte _080B89E4 @ case 1
	.4byte _080B8A0C @ case 2
	.4byte _080B8A38 @ case 3
	.4byte _080B8A60 @ case 4
_080B89B8:
	ldr r1, _080B89D8 @ =0x00001419
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x50
	strb r1, [r0]
	ldr r2, _080B89DC @ =0x0000141E
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #3
	strb r1, [r0]
	ldr r1, _080B89E0 @ =0x00001423
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x2c
	b _080B8A7C
	.align 2, 0
_080B89D8: .4byte 0x00001419
_080B89DC: .4byte 0x0000141E
_080B89E0: .4byte 0x00001423
_080B89E4:
	ldr r2, _080B8A04 @ =0x00001419
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #0x50
	strb r1, [r0]
	ldr r1, _080B8A08 @ =0x0000141E
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #3
	strb r1, [r0]
	adds r2, #0xa
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #0x2d
	b _080B8A7C
	.align 2, 0
_080B8A04: .4byte 0x00001419
_080B8A08: .4byte 0x0000141E
_080B8A0C:
	ldr r1, _080B8A2C @ =0x00001419
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x5a
	strb r1, [r0]
	ldr r2, _080B8A30 @ =0x0000141E
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #5
	strb r1, [r0]
	ldr r1, _080B8A34 @ =0x00001423
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x2c
	b _080B8A7C
	.align 2, 0
_080B8A2C: .4byte 0x00001419
_080B8A30: .4byte 0x0000141E
_080B8A34: .4byte 0x00001423
_080B8A38:
	ldr r2, _080B8A58 @ =0x00001419
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #0x5a
	strb r1, [r0]
	ldr r1, _080B8A5C @ =0x0000141E
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #5
	strb r1, [r0]
	adds r2, #0xa
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #0x2d
	b _080B8A7C
	.align 2, 0
_080B8A58: .4byte 0x00001419
_080B8A5C: .4byte 0x0000141E
_080B8A60:
	ldr r1, _080B8AA4 @ =0x00001419
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x53
	strb r1, [r0]
	ldr r2, _080B8AA8 @ =0x0000141E
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #7
	strb r1, [r0]
	ldr r1, _080B8AAC @ =0x00001423
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x10
_080B8A7C:
	strb r1, [r0]
	adds r5, #1
	ldr r2, _080B8AB0 @ =0x00001411
	adds r0, r4, r2
_080B8A84:
	ldrb r0, [r0]
	cmp r5, r0
	bge _080B8A8C
	b _080B8984
_080B8A8C:
	movs r0, #0x65
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080B8AB8
	bl Script_GetValue
	ldr r2, _080B8AB4 @ =0x00001490
	adds r1, r4, r2
	str r0, [r1]
	b _080B8ABE
	.align 2, 0
_080B8AA4: .4byte 0x00001419
_080B8AA8: .4byte 0x0000141E
_080B8AAC: .4byte 0x00001423
_080B8AB0: .4byte 0x00001411
_080B8AB4: .4byte 0x00001490
_080B8AB8:
	ldr r2, _080B8AC4 @ =0x00001490
	adds r0, r4, r2
	str r1, [r0]
_080B8ABE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B8AC4: .4byte 0x00001490

	thumb_func_start FUN_080b8ac8
FUN_080b8ac8: @ 0x080B8AC8
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080B8B18 @ =0x0000C091
	ldr r1, _080B8B1C @ =0x00009F57
	bl GetFile
	adds r2, r0, #0
	ldr r0, _080B8B20 @ =0x000013EC
	adds r4, r4, r0
	str r2, [r4]
	movs r5, #0
	str r5, [sp, #0xc]
	str r5, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	ldr r1, [r4]
	movs r0, #0
	movs r2, #5
	bl FUN_0822c398
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B8B18: .4byte 0x0000C091
_080B8B1C: .4byte 0x00009F57
_080B8B20: .4byte 0x000013EC

	thumb_func_start FUN_080b8b24
FUN_080b8b24: @ 0x080B8B24
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B8B4C @ =0x000092B3
	ldr r1, _080B8B50 @ =0x0000A41A
	bl GetFile
	ldr r1, _080B8B54 @ =0x000013F0
	adds r4, r4, r1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, _080B8B58 @ =0x030043F0
	ldr r2, _080B8B5C @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B8B4C: .4byte 0x000092B3
_080B8B50: .4byte 0x0000A41A
_080B8B54: .4byte 0x000013F0
_080B8B58: .4byte 0x030043F0
_080B8B5C: .4byte 0x04000018

	thumb_func_start FUN_080b8b60
FUN_080b8b60: @ 0x080B8B60
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sb, r0
	ldr r4, _080B8E40 @ =0x0000CB05
	ldr r1, _080B8E44 @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	mov r1, sb
	adds r1, #0x38
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	movs r6, #0x38
	add r6, sb
	mov r8, r6
	mov r0, r8
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080B8E48 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	mov r1, sb
	adds r1, #0x18
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	mov r0, sb
	adds r0, #0x18
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080B8E4C @ =0x0000414C
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	mov r1, sb
	adds r1, #0x58
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r4, r5}
	stm r1!, {r4, r5}
	mov r6, sb
	adds r6, #0x58
	adds r0, r6, #0
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080B8E50 @ =0xFFFF0000
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	mov r0, sb
	adds r0, #0x78
	str r1, [sp]
	str r1, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x28
	movs r3, #0x30
	bl FUN_0822f3fc
	mov r0, sb
	adds r0, #0xd8
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x23
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x24
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r6, #0
	add r5, sp, #0x10
	mov sl, r6
	mov r4, r8
	str r4, [sp, #0x18]
	movs r0, #0xf3
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
	movs r7, #0xcc
	lsls r7, r7, #1
	add r7, sb
	str r4, [sp, #0x1c]
_080B8C56:
	asrs r1, r6, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r5, #2]
	movs r0, #3
	ands r0, r6
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #3
	adds r0, r4, #0
	adds r0, #0x90
	strh r0, [r5]
	mov r1, sl
	str r1, [sp]
	str r1, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x68
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r4, #8
	strh r4, [r5]
	mov r3, sl
	str r3, [sp]
	str r3, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	str r5, [sp, #0xc]
	mov r0, r8
	ldr r1, [sp, #0x18]
	movs r2, #0x68
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r0, #0x60
	add r8, r0
	adds r7, #0x60
	adds r6, #1
	cmp r6, #0xf
	ble _080B8C56
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	add r1, sp, #0x10
	mov r8, r1
	movs r0, #0x80
	strh r0, [r1, #2]
	ldr r0, _080B8E54 @ =0x00000F18
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	movs r6, #0x3c
	str r6, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0xcf
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0x70
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x40
	mov r3, r8
	strh r0, [r3, #2]
	ldr r5, _080B8E58 @ =0x00000D98
	add r5, sb
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0xca
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r5, #0
	bl FUN_080b95bc
	add r0, sp, #0x10
	strh r4, [r0]
	mov r1, r8
	strh r4, [r1, #2]
	ldr r0, _080B8E5C @ =0x00000DF8
	add r0, sb
	mov r1, sb
	adds r1, #0x58
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	movs r2, #0x2a
	movs r3, #0x31
	bl FUN_0822f3fc
	movs r1, #0x78
	add r0, sp, #0x10
	strh r1, [r0]
	movs r5, #0x68
	mov r3, r8
	strh r5, [r3, #2]
	ldr r0, _080B8E60 @ =0x00000E58
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0xcb
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r5, [r0]
	movs r0, #0x20
	mov r2, r8
	strh r0, [r2, #2]
	ldr r0, _080B8E64 @ =0x00000EB8
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0xcb
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	mov r5, r8
	strh r4, [r5, #2]
	movs r6, #0x18
	add r6, sb
	mov sl, r6
	adds r5, r0, #0
	mov r8, r4
	ldr r4, _080B8E68 @ =0x00000F78
	add r4, sb
	movs r7, #0x20
	movs r6, #3
_080B8D8E:
	strh r7, [r5, #2]
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0x41
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r4, #0x60
	adds r7, #0x18
	subs r6, #1
	cmp r6, #0
	bge _080B8D8E
	movs r4, #0
	ldr r0, _080B8E6C @ =0x00001158
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r6, sp, #0x10
	str r6, [sp, #0xc]
	mov r1, sl
	movs r3, #0x31
	bl FUN_0822f3fc
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x20
	strh r0, [r6, #2]
	ldr r5, _080B8E70 @ =0x000010F8
	add r5, sb
	str r4, [sp]
	str r4, [sp, #4]
	movs r3, #0x3c
	str r3, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x39
	movs r3, #0x30
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r6, #2]
	ldr r0, _080B8E74 @ =0x000011B8
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sl
	movs r2, #0x94
	movs r3, #0x11
	bl FUN_0822f3fc
	ldr r0, _080B8E78 @ =0x00001218
	add r0, sb
	bl FUN_080b99a0
	ldr r0, _080B8E7C @ =0x0000130C
	add r0, sb
	bl FUN_080b9814
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B8E40: .4byte 0x0000CB05
_080B8E44: .4byte 0x00005D04
_080B8E48: .4byte 0x0000B343
_080B8E4C: .4byte 0x0000414C
_080B8E50: .4byte 0xFFFF0000
_080B8E54: .4byte 0x00000F18
_080B8E58: .4byte 0x00000D98
_080B8E5C: .4byte 0x00000DF8
_080B8E60: .4byte 0x00000E58
_080B8E64: .4byte 0x00000EB8
_080B8E68: .4byte 0x00000F78
_080B8E6C: .4byte 0x00001158
_080B8E70: .4byte 0x000010F8
_080B8E74: .4byte 0x000011B8
_080B8E78: .4byte 0x00001218
_080B8E7C: .4byte 0x0000130C

	thumb_func_start FUN_080b8e80
FUN_080b8e80: @ 0x080B8E80
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _080B8E98
	bl FUN_0823d340
	ldr r2, _080B8EF8 @ =0x000013F4
	adds r1, r4, r2
	str r0, [r1]
_080B8E98:
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _080B8EAC
	bl FUN_0823d340
	ldr r2, _080B8EFC @ =0x000013F8
	adds r1, r4, r2
	str r0, [r1]
_080B8EAC:
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _080B8EC0
	bl FUN_0823d340
	ldr r2, _080B8F00 @ =0x000013FC
	adds r1, r4, r2
	str r0, [r1]
_080B8EC0:
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080B8ED6
	bl FUN_0823d340
	movs r2, #0xa0
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
_080B8ED6:
	bl FUN_08049f5c
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	ldr r0, _080B8F04 @ =0x0000A41A
	bl FUN_08047dc0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B8EF8: .4byte 0x000013F4
_080B8EFC: .4byte 0x000013F8
_080B8F00: .4byte 0x000013FC
_080B8F04: .4byte 0x0000A41A

	thumb_func_start FUN_080b8f08
FUN_080b8f08: @ 0x080B8F08
	push {lr}
	adds r2, r0, #0
	ldr r0, _080B8F2C @ =0x0000140E
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080B8F26
	ldr r1, _080B8F30 @ =FUN_080b90dc
	adds r0, r2, #0
	bl FUN_080b5ab0
_080B8F26:
	pop {r0}
	bx r0
	.align 2, 0
_080B8F2C: .4byte 0x0000140E
_080B8F30: .4byte FUN_080b90dc

	thumb_func_start FUN_080b8f34
FUN_080b8f34: @ 0x080B8F34
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _080B8F64 @ =0x030044E0
	ldrh r2, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _080B8F70
	ldr r0, _080B8F68 @ =0x00001410
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _080B8F5A
	ldr r3, _080B8F6C @ =0x00001411
	adds r0, r1, r3
	ldrb r0, [r0]
_080B8F5A:
	subs r0, #1
	strb r0, [r2]
_080B8F5E:
	movs r0, #1
	b _080B8F9E
	.align 2, 0
_080B8F64: .4byte 0x030044E0
_080B8F68: .4byte 0x00001410
_080B8F6C: .4byte 0x00001411
_080B8F70:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080B8F9C
	ldr r4, _080B8F98 @ =0x00001410
	adds r2, r1, r4
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	adds r4, #1
	adds r1, r1, r4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _080B8F5E
	strb r3, [r2]
	b _080B8F5E
	.align 2, 0
_080B8F98: .4byte 0x00001410
_080B8F9C:
	movs r0, #0
_080B8F9E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b8fa4
FUN_080b8fa4: @ 0x080B8FA4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x12
	movs r2, #3
	bl FUN_080b5b30
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _080B901C @ =0x00001410
	adds r2, r4, r0
	ldrb r0, [r2]
	ldr r6, _080B9020 @ =0x0000141E
	adds r5, r4, r6
	adds r0, r5, r0
	ldrb r0, [r0]
	cmp r3, r0
	bge _080B8FEC
	ldr r0, _080B9024 @ =0x00001419
	adds r6, r4, r0
	ldr r0, _080B9028 @ =0xFFFFF000
	adds r7, r0, #0
	adds r4, r5, #0
_080B8FD2:
	ldrb r0, [r2]
	adds r0, r6, r0
	ldrb r0, [r0]
	adds r0, r0, r3
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	ldrb r0, [r2]
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r3, r0
	blt _080B8FD2
_080B8FEC:
	movs r2, #0
	ldr r6, _080B9028 @ =0xFFFFF000
	adds r4, r6, #0
_080B8FF2:
	adds r0, r2, #0
	adds r0, #0x60
	orrs r0, r4
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	adds r2, #1
	cmp r2, #2
	ble _080B8FF2
	cmp r3, #9
	bgt _080B9016
	ldr r2, _080B902C @ =0x0000F010
	adds r0, r2, #0
_080B900C:
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	cmp r3, #9
	ble _080B900C
_080B9016:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B901C: .4byte 0x00001410
_080B9020: .4byte 0x0000141E
_080B9024: .4byte 0x00001419
_080B9028: .4byte 0xFFFFF000
_080B902C: .4byte 0x0000F010

	thumb_func_start FUN_080b9030
FUN_080b9030: @ 0x080B9030
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0
	movs r1, #1
	movs r2, #3
	bl FUN_080b5b30
	adds r2, r0, #0
	movs r3, #0
	ldr r0, _080B90C4 @ =0x00001410
	adds r1, r5, r0
	ldrb r0, [r1]
	ldr r6, _080B90C8 @ =0x0000141E
	adds r4, r5, r6
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r3, r0
	bge _080B9076
	ldr r0, _080B90CC @ =0x00001419
	adds r6, r5, r0
	ldr r0, _080B90D0 @ =0xFFFFF000
	adds r7, r0, #0
_080B905C:
	ldrb r0, [r1]
	adds r0, r6, r0
	ldrb r0, [r0]
	adds r0, r0, r3
	orrs r0, r7
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	ldrb r0, [r1]
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r3, r0
	blt _080B905C
_080B9076:
	movs r1, #0
	ldr r6, _080B90D0 @ =0xFFFFF000
	adds r4, r6, #0
_080B907C:
	adds r0, r1, #0
	adds r0, #0x1d
	orrs r0, r4
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	adds r1, #1
	cmp r1, #2
	ble _080B907C
	ldr r0, _080B90C4 @ =0x00001410
	adds r1, r5, r0
	ldr r4, _080B90D4 @ =0x00001423
	adds r0, r5, r4
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0xf0
	lsls r6, r6, #8
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	cmp r3, #0xa
	bgt _080B90BC
	ldr r1, _080B90D8 @ =0x0000F010
	adds r0, r1, #0
_080B90B2:
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	cmp r3, #0xa
	ble _080B90B2
_080B90BC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B90C4: .4byte 0x00001410
_080B90C8: .4byte 0x0000141E
_080B90CC: .4byte 0x00001419
_080B90D0: .4byte 0xFFFFF000
_080B90D4: .4byte 0x00001423
_080B90D8: .4byte 0x0000F010

	thumb_func_start FUN_080b90dc
FUN_080b90dc: @ 0x080B90DC
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080B911C @ =0x0000140C
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _080B90EE
	b _080B920C
_080B90EE:
	ldr r2, _080B9120 @ =0x00001479
	adds r0, r4, r2
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1d
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080B9124
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	b _080B913C
	.align 2, 0
_080B911C: .4byte 0x0000140C
_080B9120: .4byte 0x00001479
_080B9124:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
_080B913C:
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080b8f34
	adds r5, r0, #0
	cmp r5, #0
	beq _080B91CA
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r2, _080B9170 @ =0x00001410
	adds r1, r4, r2
	adds r2, #4
	adds r0, r4, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #4
	bhi _080B91BC
	lsls r0, r0, #2
	ldr r1, _080B9174 @ =_080B9178
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B9170: .4byte 0x00001410
_080B9174: .4byte _080B9178
_080B9178: @ jump table
	.4byte _080B918C @ case 0
	.4byte _080B9196 @ case 1
	.4byte _080B91A0 @ case 2
	.4byte _080B91AA @ case 3
	.4byte _080B91B4 @ case 4
_080B918C:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b695c
	b _080B91BC
_080B9196:
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080b695c
	b _080B91BC
_080B91A0:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b78a4
	b _080B91BC
_080B91AA:
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080b78a4
	b _080B91BC
_080B91B4:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b88c4
_080B91BC:
	adds r0, r4, #0
	bl FUN_080b8fa4
	adds r0, r4, #0
	bl FUN_080b9030
	b _080B922A
_080B91CA:
	ldr r0, _080B91FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B922A
	ldr r0, _080B9200 @ =0x00000119
	bl PlaySound_082406e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B9204 @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080B9208 @ =FUN_080b9248
	adds r0, r4, #0
	bl FUN_080b5ab0
	b _080B9236
	.align 2, 0
_080B91FC: .4byte 0x030044E0
_080B9200: .4byte 0x00000119
_080B9204: .4byte 0x0000FFFF
_080B9208: .4byte FUN_080b9248
_080B920C:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080B9240 @ =0x00001479
	adds r0, r4, r1
	strb r3, [r0]
_080B922A:
	ldr r2, _080B9244 @ =0x00001498
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080B9236:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B9240: .4byte 0x00001479
_080B9244: .4byte 0x00001498

	thumb_func_start FUN_080b9248
FUN_080b9248: @ 0x080B9248
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B927C @ =0x0000140E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080B9274
	ldr r1, _080B9280 @ =0x00001490
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080B926E
	movs r1, #0
	bl Script_ExecById
_080B926E:
	adds r0, r4, #0
	bl KillEntity
_080B9274:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B927C: .4byte 0x0000140E
_080B9280: .4byte 0x00001490

	thumb_func_start FUN_080b9284
FUN_080b9284: @ 0x080B9284
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080B92AC @ =0x00001478
	adds r5, r4, r0
	ldrb r0, [r5]
	bl FUN_080b94cc
	ldrb r0, [r5]
	bl FUN_080b9400
	ldr r1, _080B92B0 @ =0x00001494
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080B92AC: .4byte 0x00001478
_080B92B0: .4byte 0x00001494

	thumb_func_start FUN_080b92b4
FUN_080b92b4: @ 0x080B92B4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x78
	movs r5, #0x2e
_080B92BE:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B92BE
	ldr r1, _080B92E4 @ =0x00001218
	adds r0, r6, r1
	bl FUN_080b9a0c
	ldr r1, _080B92E8 @ =0x0000130C
	adds r0, r6, r1
	bl FUN_080b9894
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080B92E4: .4byte 0x00001218
_080B92E8: .4byte 0x0000130C

	thumb_func_start FUN_080b92ec
FUN_080b92ec: @ 0x080B92EC
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_080b8920
	adds r0, r4, #0
	bl FUN_080b8ac8
	adds r0, r4, #0
	bl FUN_080b8b24
	adds r0, r4, #0
	bl FUN_080b8b60
	adds r0, r4, #0
	bl FUN_080b8e80
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B9348 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b695c
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080B934C @ =FUN_080b8f08
	adds r0, r4, #0
	bl FUN_080b5ab0
	movs r0, #0
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B9348: .4byte 0x0000FFFF
_080B934C: .4byte FUN_080b8f08

	thumb_func_start FUN_080b9350
FUN_080b9350: @ 0x080B9350
	push {r4, lr}
	ldr r1, _080B937C @ =0x0000149C
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080B9388
	ldr r1, _080B9380 @ =FUN_080b9284
	ldr r2, _080B9384 @ =FUN_080b92b4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080b92ec
	cmp r0, #0
	bge _080B9388
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080B938A
	.align 2, 0
_080B937C: .4byte 0x0000149C
_080B9380: .4byte FUN_080b9284
_080B9384: .4byte FUN_080b92b4
_080B9388:
	adds r0, r4, #0
_080B938A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b9390
FUN_080b9390: @ 0x080B9390
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _080B93AC @ =0x03003ED0
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
_080B93AC: .4byte 0x03003ED0

	thumb_func_start FUN_080b93b0
FUN_080b93b0: @ 0x080B93B0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r4, [sp, #0x14]
	movs r0, #0
	bl FUN_080b9390
	adds r7, r0, #0
	lsls r4, r4, #4
	adds r4, #0x21
	cmp r6, #0
	ble _080B93F8
_080B93CC:
	adds r0, r5, #0
	adds r1, r6, #0
	bl Div
	adds r1, r0, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r3, #0xf0
	lsls r3, r3, #8
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r7]
	adds r7, #2
	muls r0, r6, r0
	subs r5, r5, r0
	adds r0, r6, #0
	movs r1, #0xa
	bl Div
	adds r6, r0, #0
	cmp r6, #0
	bgt _080B93CC
_080B93F8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b9400
FUN_080b9400: @ 0x080B9400
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x12
	movs r2, #0
	bl FUN_080b9390
	adds r1, r0, #0
	cmp r4, #0
	bne _080B9444
	ldr r2, _080B9440 @ =0x0000F03B
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1, #2]
	bl GetHour
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_080b93b0
	bl GetMinute
	b _080B9470
	.align 2, 0
_080B9440: .4byte 0x0000F03B
_080B9444:
	cmp r4, #1
	bne _080B9488
	ldr r2, _080B9480 @ =0x0000F045
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _080B9484 @ =0x030047E0
	ldrb r0, [r5, #0xa]
	movs r4, #0
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_080b93b0
	ldrb r0, [r5, #0xb]
_080B9470:
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x19
	movs r3, #0
	bl FUN_080b93b0
	b _080B94BC
	.align 2, 0
_080B9480: .4byte 0x0000F045
_080B9484: .4byte 0x030047E0
_080B9488:
	ldr r2, _080B94C4 @ =0x0000F045
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _080B94C8 @ =0x030047E0
	ldrb r0, [r5, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_080b93b0
	ldrb r0, [r5, #0xd]
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x19
	movs r3, #0
	bl FUN_080b93b0
_080B94BC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B94C4: .4byte 0x0000F045
_080B94C8: .4byte 0x030047E0

	thumb_func_start FUN_080b94cc
FUN_080b94cc: @ 0x080B94CC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x12
	movs r2, #1
	bl FUN_080b9390
	adds r1, r0, #0
	cmp r4, #0
	bne _080B9520
	ldr r2, _080B9518 @ =0x0000F03E
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x2a
	adds r0, r2, #0
	strh r0, [r1]
	subs r2, #0x68
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r0, _080B951C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	b _080B9554
	.align 2, 0
_080B9518: .4byte 0x0000F03E
_080B951C: .4byte 0x030046A0
_080B9520:
	cmp r4, #1
	bne _080B956C
	ldr r2, _080B9564 @ =0x0000F040
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #4
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x2c
	adds r0, r2, #0
	strh r0, [r1]
	subs r2, #0x39
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r0, _080B9568 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
_080B9554:
	movs r1, #0xfa
	lsls r1, r1, #2
	str r4, [sp]
	movs r2, #0x17
	movs r3, #1
	bl FUN_080b93b0
	b _080B95AA
	.align 2, 0
_080B9564: .4byte 0x0000F040
_080B9568: .4byte 0x030046A0
_080B956C:
	ldr r2, _080B95B4 @ =0x0000F042
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #6
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #7
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #0x25
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r0, _080B95B8 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, #0x2c
	movs r2, #0
	str r2, [sp]
	movs r2, #0x17
	movs r3, #1
	bl FUN_080b93b0
_080B95AA:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B95B4: .4byte 0x0000F042
_080B95B8: .4byte 0x030046A0

	thumb_func_start FUN_080b95bc
FUN_080b95bc: @ 0x080B95BC
	strh r1, [r0, #0x3a]
	ldr r1, _080B95CC @ =0x03003584
	ldrh r2, [r0, #0x3a]
	lsls r2, r2, #5
	ldr r1, [r1]
	adds r1, r1, r2
	str r1, [r0, #0x48]
	bx lr
	.align 2, 0
_080B95CC: .4byte 0x03003584

	thumb_func_start FUN_080b95d0
FUN_080b95d0: @ 0x080B95D0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r3, #0
	cmp r4, #0
	beq _080B95FC
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B95F4
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r4, #0
	bl FUN_080b95bc
	b _080B95FC
_080B95F4:
	ldr r1, _080B9618 @ =0x000002DF
	adds r0, r4, #0
	bl FUN_080b95bc
_080B95FC:
	cmp r5, #0
	beq _080B9624
	adds r0, r6, #0
	movs r1, #8
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B961C
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r5, #0
	bl FUN_080b95bc
	b _080B9624
	.align 2, 0
_080B9618: .4byte 0x000002DF
_080B961C:
	ldr r1, _080B9640 @ =0x000002DF
	adds r0, r5, #0
	bl FUN_080b95bc
_080B9624:
	cmp r7, #0
	beq _080B964C
	adds r0, r6, #0
	movs r1, #0x10
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9644
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r7, #0
	bl FUN_080b95bc
	b _080B964C
	.align 2, 0
_080B9640: .4byte 0x000002DF
_080B9644:
	ldr r1, _080B9654 @ =0x000002DF
	adds r0, r7, #0
	bl FUN_080b95bc
_080B964C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B9654: .4byte 0x000002DF

	thumb_func_start FUN_080b9658
FUN_080b9658: @ 0x080B9658
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov sb, r0
	adds r6, r1, #0
	mov r8, r2
	adds r4, r3, #0
	ldr r5, [sp, #0x2c]
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x20]
	str r1, [r6, #0x24]
	adds r2, r5, #0
	adds r2, #0x17
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	adds r6, #0x60
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
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
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, #0
	bne _080B96D8
	movs r0, #0
_080B96D8:
	adds r4, r0, #0
	mov r7, sp
	movs r5, #3
_080B96DE:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldm r7!, {r2}
	adds r2, #0x19
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x20]
	str r1, [r6, #0x24]
	ldrh r0, [r6, #0x20]
	adds r0, r0, r4
	strh r0, [r6, #0x20]
	adds r6, #0x60
	adds r4, #6
	subs r5, #1
	cmp r5, #0
	bge _080B96DE
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b9724
FUN_080b9724: @ 0x080B9724
	push {lr}
	adds r1, r0, #0
	movs r3, #1
	movs r2, #4
_080B972C:
	ldr r0, [r1, #8]
	orrs r0, r3
	str r0, [r1, #8]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080B972C
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b9740
FUN_080b9740: @ 0x080B9740
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	strb r3, [r2]
	lsls r3, r3, #0x18
	movs r2, #5
	cmp r3, #0
	beq _080B975E
	movs r2, #4
_080B975E:
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_082370cc
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_082372cc
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b977c
FUN_080b977c: @ 0x080B977C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	ldr r0, _080B97A0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080B97A4
	ldr r0, [r5, #8]
	orrs r0, r2
	str r0, [r5, #8]
	ldrb r0, [r4]
	b _080B980C
	.align 2, 0
_080B97A0: .4byte 0x030044E0
_080B97A4:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B97B6
	ldr r0, [r5, #8]
	orrs r0, r2
	str r0, [r5, #8]
	movs r0, #0
	b _080B980C
_080B97B6:
	movs r2, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _080B97CC
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r2, r0, #0x1f
	b _080B97D6
_080B97CC:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080B97D6
	movs r2, #1
_080B97D6:
	cmp r2, #0
	beq _080B9800
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldrb r1, [r4]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r4]
	ldrb r0, [r4]
	movs r2, #5
	subs r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r3, #1
	bl FUN_082370cc
_080B9800:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_082372cc
	movs r0, #1
	rsbs r0, r0, #0
_080B980C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b9814
FUN_080b9814: @ 0x080B9814
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r0, _080B9888 @ =0x0000CB05
	ldr r1, _080B988C @ =0x0000B343
	bl GetFile
	adds r1, r0, #0
	adds r2, r7, #0
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r0, r7, #0
	bl FUN_0822f284
	ldr r1, _080B9890 @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r5, #0
	mov r8, r5
	add r4, sp, #0x10
	adds r5, r7, #0
	adds r5, #0x20
	movs r6, #1
_080B9854:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #0x93
	movs r3, #0x31
	bl FUN_0822f3fc
	ldrh r0, [r4, #2]
	adds r0, #8
	strh r0, [r4, #2]
	adds r5, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080B9854
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B9888: .4byte 0x0000CB05
_080B988C: .4byte 0x0000B343
_080B9890: .4byte 0xFFFF0000

	thumb_func_start FUN_080b9894
FUN_080b9894: @ 0x080B9894
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x20
	movs r5, #1
_080B989C:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B989C
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b98b0
FUN_080b98b0: @ 0x080B98B0
	push {lr}
	cmp r0, #0
	beq _080B98BA
	adds r0, #0xa0
	b _080B98BC
_080B98BA:
	movs r0, #0x93
_080B98BC:
	pop {r1}
	bx r1

	thumb_func_start FUN_080b98c0
FUN_080b98c0: @ 0x080B98C0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	cmp r3, #0
	blt _080B98F0
	ldr r0, [r4, #0x28]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x28]
	adds r0, r3, #0
	bl FUN_080b98b0
	adds r2, r0, #0
	adds r0, r4, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
	b _080B98F8
_080B98F0:
	ldr r0, [r4, #0x28]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x28]
_080B98F8:
	cmp r5, #0
	blt _080B9924
	adds r2, r4, #0
	adds r2, #0x88
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_080b98b0
	adds r2, r0, #0
	adds r0, r4, #0
	adds r0, #0x80
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
	b _080B9930
_080B9924:
	adds r0, r4, #0
	adds r0, #0x88
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_080B9930:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b9938
FUN_080b9938: @ 0x080B9938
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	cmp r2, #0xf
	bgt _080B995C
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
	b _080B999A
_080B995C:
	cmp r2, #0x1f
	bgt _080B997C
	subs r2, #0x10
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r3]
	asrs r2, r2, #2
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, #0x20
	b _080B999A
_080B997C:
	cmp r2, #0x20
	bne _080B9988
	movs r0, #0x70
	strh r0, [r3]
	movs r0, #0x40
	b _080B999A
_080B9988:
	cmp r2, #0x21
	bne _080B9994
	movs r0, #0x78
	strh r0, [r3]
	movs r0, #0x68
	b _080B999A
_080B9994:
	movs r0, #0x68
	strh r0, [r3]
	movs r0, #0x20
_080B999A:
	strh r0, [r3, #2]
	pop {r0}
	bx r0

	thumb_func_start FUN_080b99a0
FUN_080b99a0: @ 0x080B99A0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, _080B9A00 @ =0x0000CB05
	ldr r1, _080B9A04 @ =0x00005D04
	bl GetFile
	adds r1, r0, #0
	adds r2, r6, #0
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r0, r6, #0
	bl FUN_0822f284
	ldr r1, _080B9A08 @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r7, #0
	adds r4, r6, #0
	adds r4, #0x20
	movs r5, #1
_080B99D8:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x31
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B99D8
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B9A00: .4byte 0x0000CB05
_080B9A04: .4byte 0x00005D04
_080B9A08: .4byte 0xFFFF0000

	thumb_func_start FUN_080b9a0c
FUN_080b9a0c: @ 0x080B9A0C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x20
	movs r5, #1
_080B9A14:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B9A14
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b9a28
FUN_080b9a28: @ 0x080B9A28
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0
	mov sl, r0
	mov sb, r3
	mov r8, r2
	ldr r3, [sp, #0x28]
	str r3, [sp, #4]
	adds r4, r5, #0
	adds r4, #0x20
	movs r7, #0
	str r7, [sp]
	adds r6, r1, #0
_080B9A4C:
	ldr r0, [r6]
	cmp r0, #0
	bne _080B9A5C
	ldr r0, [r4, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #8]
	b _080B9A9A
_080B9A5C:
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	ldr r0, [sp, #4]
	ldrh r2, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl Sprite_SetSprite
	adds r2, r5, #0
	adds r2, #0x40
	ldr r3, [sp]
	adds r2, r2, r3
	mov r7, sl
	lsls r3, r7, #3
	mov r7, r8
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r2, r5, #0
	adds r2, #0xe0
	adds r2, r2, r3
	mov r3, sb
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
_080B9A9A:
	movs r7, #8
	add sb, r7
	movs r0, #8
	add r8, r0
	ldr r3, [sp, #4]
	adds r3, #4
	str r3, [sp, #4]
	adds r4, #0x60
	ldr r7, [sp]
	adds r7, #0x60
	str r7, [sp]
	adds r6, #4
	movs r0, #1
	add sl, r0
	mov r3, sl
	cmp r3, #1
	ble _080B9A4C
	movs r1, #0
	adds r0, r5, #0
	adds r0, #0xf0
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0xf2
	ldr r0, [sp, #0x30]
	strh r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b9adc
FUN_080b9adc: @ 0x080B9ADC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	adds r2, r3, #0
	adds r2, #0xf0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	adds r1, r3, #0
	adds r1, #0xf2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r4, [r1]
	cmp r0, r4
	blo _080B9B10
	ldr r0, [r3, #0x28]
	movs r2, #1
	orrs r0, r2
	str r0, [r3, #0x28]
	subs r1, #0x6a
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #1
	b _080B9B68
_080B9B10:
	ldrh r1, [r1]
	ldrh r0, [r2]
	subs r6, r1, r0
	adds r7, r6, #1
	adds r5, r3, #0
	adds r5, #0xe0
	adds r4, r3, #0
	adds r4, #0x28
	movs r0, #1
	mov r8, r0
_080B9B24:
	ldr r0, [r4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080B9B56
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	muls r0, r6, r0
	movs r2, #0
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	adds r1, r7, #0
	bl Div
	strh r0, [r4, #0x18]
	movs r1, #0x1a
	ldrsh r0, [r4, r1]
	muls r0, r6, r0
	movs r2, #2
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	adds r1, r7, #0
	bl Div
	strh r0, [r4, #0x1a]
_080B9B56:
	adds r5, #8
	adds r4, #0x60
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _080B9B24
	movs r0, #0
_080B9B68:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080b9b74
FUN_080b9b74: @ 0x080B9B74
	ldrb r1, [r0, #1]
	lsls r1, r1, #2
	ldrb r2, [r0, #2]
	adds r1, r1, r2
	adds r0, #0xc
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bx lr

	thumb_func_start FUN_080b9b88
FUN_080b9b88: @ 0x080B9B88
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #1
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9BC4
	movs r3, #0
	adds r4, r5, #0
	adds r4, #0xc
	movs r0, #0x2c
	adds r0, r0, r5
	mov r8, r0
	adds r7, r4, #0
	movs r6, #0xff
_080B9BAA:
	adds r1, r3, r7
	movs r2, #3
_080B9BAE:
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9BAE
	adds r3, #1
	cmp r3, #3
	ble _080B9BAA
	b _080B9BEE
_080B9BC4:
	movs r3, #0
	adds r4, r5, #0
	adds r4, #0xc
	movs r1, #0x2c
	adds r1, r1, r5
	mov r8, r1
	adds r6, r4, #0
_080B9BD2:
	lsls r0, r3, #2
	movs r2, #3
	adds r1, r0, #3
	adds r0, r3, r6
	adds r0, #0xc
_080B9BDC:
	strb r1, [r0]
	subs r1, #1
	subs r0, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9BDC
	adds r3, #1
	cmp r3, #3
	ble _080B9BD2
_080B9BEE:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9C1E
	movs r3, #0
	movs r6, #0xff
	adds r7, r4, #0
	adds r7, #0x10
_080B9C02:
	adds r4, r3, #1
	adds r1, r3, r7
	movs r2, #3
_080B9C08:
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9C08
	adds r3, r4, #0
	cmp r3, #3
	ble _080B9C02
	b _080B9CDC
_080B9C1E:
	ldrb r1, [r5]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B9C9E
	adds r0, r5, #0
	movs r1, #0x20
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9C54
	movs r3, #0
	adds r6, r4, #0
	adds r6, #0x10
_080B9C3A:
	adds r4, r3, #1
	adds r1, r3, r6
	movs r2, #3
_080B9C40:
	ldrb r0, [r5, #6]
	strb r0, [r1]
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9C40
	adds r3, r4, #0
	cmp r3, #3
	ble _080B9C3A
	b _080B9CDC
_080B9C54:
	movs r3, #0
	adds r6, r5, #0
	adds r6, #0xf
	movs r0, #0xe
	adds r0, r0, r5
	mov ip, r0
	adds r7, r4, #0
	adds r7, #0x10
_080B9C64:
	adds r4, r3, #1
	lsls r0, r3, #2
	movs r2, #3
	adds r1, r0, #0
	adds r1, #0x13
	adds r0, r3, r7
	adds r0, #0xc
_080B9C72:
	strb r1, [r0]
	subs r1, #1
	subs r0, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9C72
	adds r3, r4, #0
	cmp r3, #2
	ble _080B9C64
	mov r3, ip
	adds r3, #0x10
	adds r1, r6, #0
	adds r1, #0x10
	movs r2, #3
_080B9C8E:
	ldrb r0, [r3]
	strb r0, [r1]
	adds r3, #4
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9C8E
	b _080B9CDC
_080B9C9E:
	movs r3, #0
	adds r6, r5, #0
	adds r6, #0xf
	adds r7, r4, #0
	adds r7, #0x10
_080B9CA8:
	adds r4, r3, #1
	lsls r0, r3, #2
	movs r2, #3
	adds r1, r0, #0
	adds r1, #0x13
	adds r0, r3, r7
	adds r0, #0xc
_080B9CB6:
	strb r1, [r0]
	subs r1, #1
	subs r0, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9CB6
	adds r3, r4, #0
	cmp r3, #2
	ble _080B9CA8
	movs r2, #3
	movs r1, #0x1f
	adds r0, r6, #0
	adds r0, #0x1c
_080B9CD0:
	strb r1, [r0]
	subs r1, #1
	subs r0, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9CD0
_080B9CDC:
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9D24
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9D0A
	movs r3, #0
	mov r2, r8
	movs r4, #0xff
_080B9CFA:
	adds r1, r2, r3
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	adds r3, #1
	cmp r3, #3
	ble _080B9CFA
	b _080B9D8A
_080B9D0A:
	movs r3, #0
	adds r4, r5, #0
	adds r4, #0x2f
	mov r2, r8
	movs r5, #0xff
_080B9D14:
	adds r1, r2, r3
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r3, #1
	cmp r3, #2
	ble _080B9D14
	b _080B9D4E
_080B9D24:
	ldrb r0, [r5]
	cmp r0, #1
	bne _080B9D54
	adds r4, r5, #0
	adds r4, #0x2f
	mov r1, r8
	movs r2, #0x22
	adds r0, r1, #2
_080B9D34:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _080B9D34
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9D4E
	movs r0, #0x22
	strb r0, [r4]
	b _080B9D8A
_080B9D4E:
	movs r0, #0x21
	strb r0, [r4]
	b _080B9D8A
_080B9D54:
	movs r0, #0x22
	mov r1, r8
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	adds r4, r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9D82
	adds r1, r5, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	orrs r0, r4
	b _080B9D88
_080B9D82:
	adds r1, r5, #0
	adds r1, #0x2f
	movs r0, #0x21
_080B9D88:
	strb r0, [r1]
_080B9D8A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b9d94
FUN_080b9d94: @ 0x080B9D94
	push {lr}
	strb r1, [r0, #7]
	bl FUN_080b9b88
	pop {r0}
	bx r0

	thumb_func_start FUN_080b9da0
FUN_080b9da0: @ 0x080B9DA0
	ldrb r0, [r0, #7]
	ands r0, r1
	bx lr
	.align 2, 0

	thumb_func_start FUN_080b9da8
FUN_080b9da8: @ 0x080B9DA8
	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _080B9DC4 @ =0x030044E0
	ldrh r0, [r4, #2]
	movs r1, #0xf0
	adds r2, r1, #0
	ands r2, r0
	cmp r2, #0
	beq _080B9DC8
	movs r0, #0
	strb r0, [r3, #8]
	ldrh r0, [r4, #2]
	b _080B9DE8
	.align 2, 0
_080B9DC4: .4byte 0x030044E0
_080B9DC8:
	ldrh r0, [r4]
	ands r1, r0
	cmp r1, #0
	beq _080B9DE4
	ldrb r0, [r3, #8]
	adds r0, #1
	strb r0, [r3, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _080B9DE6
	strb r2, [r3, #8]
	ldrh r0, [r4]
	b _080B9DE8
_080B9DE4:
	strb r1, [r3, #8]
_080B9DE6:
	movs r0, #0
_080B9DE8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080b9df0
FUN_080b9df0: @ 0x080B9DF0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #2]
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	adds r1, r2, r1
	adds r0, #0xc
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r3, r2, #3
	movs r0, #3
	ands r3, r0
	cmp r3, r2
	beq _080B9E48
_080B9E0E:
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	adds r1, r3, r1
	adds r0, r4, #0
	adds r0, #0xc
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080B9E3C
	cmp r0, r5
	beq _080B9E3C
	strb r3, [r4, #2]
	adds r0, r4, #0
	bl FUN_080b9b74
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _080B9E4A
_080B9E3C:
	adds r3, #3
	movs r0, #3
	ands r3, r0
	ldrb r0, [r4, #2]
	cmp r3, r0
	bne _080B9E0E
_080B9E48:
	movs r0, #0
_080B9E4A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b9e50
FUN_080b9e50: @ 0x080B9E50
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #2]
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	adds r1, r2, r1
	adds r0, #0xc
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r3, r2, #1
	movs r0, #3
	ands r3, r0
	cmp r3, r2
	beq _080B9EA8
_080B9E6E:
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	adds r1, r3, r1
	adds r0, r4, #0
	adds r0, #0xc
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080B9E9C
	cmp r0, r5
	beq _080B9E9C
	strb r3, [r4, #2]
	adds r0, r4, #0
	bl FUN_080b9b74
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _080B9EAA
_080B9E9C:
	adds r3, #1
	movs r0, #3
	ands r3, r0
	ldrb r0, [r4, #2]
	cmp r3, r0
	bne _080B9E6E
_080B9EA8:
	movs r0, #0
_080B9EAA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b9eb0
FUN_080b9eb0: @ 0x080B9EB0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r3, [r4, #1]
	lsls r1, r3, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xc
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	subs r2, r3, #1
	cmp r3, #0
	bne _080B9F04
_080B9ECC:
	movs r2, #8
	b _080B9F04
_080B9ED0:
	lsls r1, r2, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xc
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080B9EFE
	cmp r0, r5
	beq _080B9EFE
	strb r2, [r4, #1]
	adds r0, r4, #0
	bl FUN_080b9b74
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _080B9F0A
_080B9EFE:
	cmp r2, #0
	beq _080B9ECC
	subs r2, #1
_080B9F04:
	cmp r2, r3
	bne _080B9ED0
	movs r0, #0
_080B9F0A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b9f10
FUN_080b9f10: @ 0x080B9F10
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r3, [r4, #1]
	lsls r1, r3, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xc
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r2, r3, #1
	cmp r3, #8
	bne _080B9F64
_080B9F2C:
	movs r2, #0
	b _080B9F64
_080B9F30:
	lsls r1, r2, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xc
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080B9F5E
	cmp r0, r5
	beq _080B9F5E
	strb r2, [r4, #1]
	adds r0, r4, #0
	bl FUN_080b9b74
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _080B9F6A
_080B9F5E:
	cmp r2, #8
	beq _080B9F2C
	adds r2, #1
_080B9F64:
	cmp r2, r3
	bne _080B9F30
	movs r0, #0
_080B9F6A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b9f70
FUN_080b9f70: @ 0x080B9F70
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080b9da8
	adds r1, r0, #0
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080B9F8A
	adds r0, r4, #0
	bl FUN_080b9df0
	b _080B9FBC
_080B9F8A:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080B9F9A
	adds r0, r4, #0
	bl FUN_080b9e50
	b _080B9FBC
_080B9F9A:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080B9FAA
	adds r0, r4, #0
	bl FUN_080b9eb0
	b _080B9FBC
_080B9FAA:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080B9FB6
	movs r0, #0
	b _080B9FBC
_080B9FB6:
	adds r0, r4, #0
	bl FUN_080b9f10
_080B9FBC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080b9fc4
FUN_080b9fc4: @ 0x080B9FC4
	push {lr}
	adds r1, #0x20
	ldrb r2, [r0, #3]
	adds r0, r1, #0
	adds r1, r2, #0
	bl FUN_080b9938
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b9fd8
FUN_080b9fd8: @ 0x080B9FD8
	ldrb r1, [r0, #1]
	strb r1, [r0, #4]
	ldrb r1, [r0, #2]
	strb r1, [r0, #5]
	ldrb r1, [r0, #3]
	strb r1, [r0, #6]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080b9fe8
FUN_080b9fe8: @ 0x080B9FE8
	ldrb r1, [r0, #4]
	strb r1, [r0, #1]
	ldrb r1, [r0, #5]
	strb r1, [r0, #2]
	ldrb r1, [r0, #6]
	strb r1, [r0, #3]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080b9ff8
FUN_080b9ff8: @ 0x080B9FF8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	adds r0, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r1, [sp, #0x14]
	movs r2, #0
	mov r8, r2
	strb r0, [r4]
	adds r0, r4, #0
	bl FUN_080b9d94
	strb r5, [r4, #1]
	strb r6, [r4, #2]
	adds r0, r4, #0
	bl FUN_080b9b74
	strb r0, [r4, #3]
	mov r0, r8
	strb r0, [r4, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ba030
FUN_080ba030: @ 0x080BA030
	ldr r3, _080BA040 @ =0x00001538
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080BA044 @ =0x000012F0
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080BA040: .4byte 0x00001538
_080BA044: .4byte 0x000012F0

	thumb_func_start FUN_080ba048
FUN_080ba048: @ 0x080BA048
	ldr r2, _080BA050 @ =0x000012EE
	adds r0, r0, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
_080BA050: .4byte 0x000012EE

	thumb_func_start FUN_080ba054
FUN_080ba054: @ 0x080BA054
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _080BA074 @ =0x0000153C
	adds r0, r4, r3
	str r1, [r0]
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080ba048
	ldr r0, _080BA078 @ =0x000012F0
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BA074: .4byte 0x0000153C
_080BA078: .4byte 0x000012F0

	thumb_func_start FUN_080ba07c
FUN_080ba07c: @ 0x080BA07C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_08049e5c
	movs r0, #0xce
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x97
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r5, #0
	bl FUN_08047a28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ba0c0
FUN_080ba0c0: @ 0x080BA0C0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0x64
	bl Div
	str r0, [r5]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [r5, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [r5, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ba0f0
FUN_080ba0f0: @ 0x080BA0F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	mov sl, r0
	adds r7, r1, #0
	ldr r0, _080BA114 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x5c
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _080BA118
	movs r0, #0
	b _080BA126
	.align 2, 0
_080BA114: .4byte 0x030046A0
_080BA118:
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl GetInventoryArmor
	lsls r0, r0, #3
	ldr r1, _080BA138 @ =0x08DAA7B0
	adds r0, r0, r1
_080BA126:
	bl FUN_0807a70c
	adds r4, r0, #0
	cmp r7, #0
	bge _080BA13C
	adds r0, r4, #0
	movs r6, #0
	b _080BA154
	.align 2, 0
_080BA138: .4byte 0x08DAA7B0
_080BA13C:
	lsls r0, r7, #3
	ldr r1, _080BA1B4 @ =0x08DAA7B0
	adds r0, r0, r1
	bl FUN_0807a70c
	movs r6, #0
	cmp r0, r4
	beq _080BA154
	movs r6, #2
	cmp r0, r4
	ble _080BA154
	movs r6, #1
_080BA154:
	add r4, sp, #0x24
	adds r1, r4, #0
	bl FUN_080ba0c0
	movs r0, #0x18
	add r0, sl
	mov r8, r0
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r6, r0, #1
	add r1, sp, #0x24
	mov sb, r1
	ldr r4, _080BA1B8 @ =0x00001158
	add r4, sl
	movs r5, #2
_080BA172:
	mov r0, sb
	adds r0, #4
	mov sb, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BA172
	ldr r0, _080BA1BC @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x58
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	bl FUN_08242b28
	mov r0, sp
	bl FUN_0807a6cc
	adds r5, r0, #0
	cmp r7, #0
	bge _080BA1C0
	movs r6, #0
	b _080BA1DA
	.align 2, 0
_080BA1B4: .4byte 0x08DAA7B0
_080BA1B8: .4byte 0x00001158
_080BA1BC: .4byte 0x030046A0
_080BA1C0:
	lsls r1, r7, #3
	ldr r0, _080BA218 @ =0x08DAA7B0
	adds r1, r1, r0
	mov r0, sp
	bl FUN_0807a5d8
	movs r6, #0
	cmp r0, r5
	beq _080BA1DA
	movs r6, #2
	cmp r0, r5
	ble _080BA1DA
	movs r6, #1
_080BA1DA:
	add r1, sp, #0x24
	bl FUN_080ba0c0
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r6, r0, #1
	add r7, sp, #0x24
	ldr r4, _080BA21C @ =0x00001038
	add r4, sl
	movs r5, #2
_080BA1EE:
	ldm r7!, {r2}
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BA1EE
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BA218: .4byte 0x08DAA7B0
_080BA21C: .4byte 0x00001038

	thumb_func_start FUN_080ba220
FUN_080ba220: @ 0x080BA220
	push {lr}
	adds r1, r0, #0
	cmp r1, #4
	bls _080BA238
	cmp r1, #6
	beq _080BA238
	cmp r1, #7
	beq _080BA238
	cmp r1, #9
	beq _080BA238
	cmp r1, #0xa
	bne _080BA274
_080BA238:
	ldr r0, _080BA268 @ =0x08DAA8D8
	lsls r1, r1, #4
	adds r0, #0xc
	adds r1, r1, r0
	ldr r0, _080BA26C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xef
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r0, [r1]
	muls r0, r2, r0
	movs r1, #0x64
	bl Div
	cmp r0, #0
	bgt _080BA25E
	movs r0, #1
_080BA25E:
	ldr r1, _080BA270 @ =0x0000270F
	cmp r0, r1
	ble _080BA27E
	adds r0, r1, #0
	b _080BA27E
	.align 2, 0
_080BA268: .4byte 0x08DAA8D8
_080BA26C: .4byte 0x030046A0
_080BA270: .4byte 0x0000270F
_080BA274:
	ldr r0, _080BA284 @ =0x08DAA8D8
	lsls r1, r1, #4
	adds r0, #0xc
	adds r1, r1, r0
	ldr r0, [r1]
_080BA27E:
	pop {r1}
	bx r1
	.align 2, 0
_080BA284: .4byte 0x08DAA8D8

	thumb_func_start FUN_080ba288
FUN_080ba288: @ 0x080BA288
	push {r4, r5, lr}
	adds r5, r0, #0
	bl item_08092034
	movs r4, #0x32
	cmp r0, #0xcf
	beq _080BA2AE
	adds r1, r0, #0
	subs r1, #0xd0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	subs r4, r4, r0
	cmp r4, #0x32
	ble _080BA2A8
	movs r4, #0x32
_080BA2A8:
	cmp r4, #0x13
	bgt _080BA2AE
	movs r4, #0x14
_080BA2AE:
	adds r0, r5, #0
	bl GetNormalItemID
	bl FUN_080ba220
	muls r0, r4, r0
	movs r1, #0x64
	bl Div
	cmp r0, #0
	bgt _080BA2C6
	movs r0, #1
_080BA2C6:
	ldr r1, _080BA2D4 @ =0x0000270F
	cmp r0, r1
	ble _080BA2CE
	adds r0, r1, #0
_080BA2CE:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080BA2D4: .4byte 0x0000270F

	thumb_func_start FUN_080ba2d8
FUN_080ba2d8: @ 0x080BA2D8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _080BA2FC @ =0x00001409
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BA304
	ldr r2, _080BA300 @ =0x0000140B
	adds r4, r5, r2
	ldrb r0, [r4]
	bl GetNormalItemID
	adds r6, r0, #0
	ldrb r0, [r4]
	bl item_08092034
	adds r3, r0, #0
	b _080BA33A
	.align 2, 0
_080BA2FC: .4byte 0x00001409
_080BA300: .4byte 0x0000140B
_080BA304:
	cmp r0, #7
	bhi _080BA334
	ldr r1, _080BA328 @ =0x0000140B
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r2, _080BA32C @ =0x000012E4
	adds r0, r0, r2
	movs r6, #0
	ldrsb r6, [r0, r6]
	ldr r1, _080BA330 @ =0x08DAA8D8
	lsls r0, r6, #4
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	movs r3, #0xd0
	cmp r0, #0
	bne _080BA33A
	b _080BA338
	.align 2, 0
_080BA328: .4byte 0x0000140B
_080BA32C: .4byte 0x000012E4
_080BA330: .4byte 0x08DAA8D8
_080BA334:
	movs r6, #1
	rsbs r6, r6, #0
_080BA338:
	movs r3, #0xcf
_080BA33A:
	cmp r6, #0
	bge _080BA356
	movs r1, #0xce
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _080BA408
_080BA356:
	movs r0, #0xce
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BA3C0 @ =0x00000CD8
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x38
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _080BA3C4 @ =0x000012E4
	adds r4, r5, r2
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r6, #0
	bl FUN_08047a28
	ldr r0, [r4]
	bl VM_ParseStringRef
	adds r1, r0, #0
	ldr r0, _080BA3C8 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #5
	bne _080BA3DE
	cmp r6, #1
	bne _080BA3CC
	adds r0, r1, #0
	adds r0, #0xea
	b _080BA3D4
	.align 2, 0
_080BA3C0: .4byte 0x00000CD8
_080BA3C4: .4byte 0x000012E4
_080BA3C8: .4byte 0x030046A0
_080BA3CC:
	cmp r6, #0xd
	bne _080BA3DE
	adds r0, r1, #0
	adds r0, #0xa9
_080BA3D4:
	bl Textbox_LookupString
	bl FUN_08049e30
	b _080BA408
_080BA3DE:
	ldr r0, _080BA3F8 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _080BA3F4
	cmp r0, #5
	bne _080BA3FC
_080BA3F4:
	adds r1, #0x4e
	b _080BA3FE
	.align 2, 0
_080BA3F8: .4byte 0x030046A0
_080BA3FC:
	adds r1, #0x9c
_080BA3FE:
	adds r0, r1, r6
	bl Textbox_LookupString
	bl FUN_08049e30
_080BA408:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ba410
FUN_080ba410: @ 0x080BA410
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	movs r7, #0
	adds r0, #0x80
	str r0, [sp]
	movs r1, #0
	str r1, [sp, #8]
_080BA428:
	movs r0, #0
	mov sl, r0
	lsls r1, r7, #2
	mov r8, r1
	movs r0, #0xcc
	lsls r0, r0, #1
	add r0, sb
	ldr r1, [sp, #8]
	adds r6, r1, r0
	mov r1, r8
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, [sp]
	adds r4, r0, r1
_080BA448:
	mov r1, r8
	add r1, sl
	adds r0, r1, #0
	bl GetNormalItemID
	adds r5, r0, #0
	cmp r5, #0
	blt _080BA478
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, r5, #0
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080BA480
_080BA478:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080BA480:
	adds r0, r6, #0
	ldr r1, _080BA524 @ =0x000002DF
	bl FUN_080b95bc
	adds r6, #0x60
	adds r4, #0x60
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	ble _080BA448
	ldr r0, [sp, #8]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #8]
	adds r7, #1
	cmp r7, #3
	ble _080BA428
	movs r7, #0
_080BA4A8:
	movs r0, #0
	mov sl, r0
	lsls r1, r7, #2
	mov r8, r1
	adds r0, r7, #1
	str r0, [sp, #4]
	mov r2, r8
	adds r2, #0x13
	lsls r0, r7, #3
	add r0, r8
	lsls r0, r0, #5
	movs r1, #0xf3
	lsls r1, r1, #3
	add r1, sb
	adds r7, r0, r1
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r1, [sp]
	adds r6, r0, r1
_080BA4D0:
	mov r1, r8
	add r1, sl
	ldr r0, _080BA528 @ =0x000012F4
	add r0, sb
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	cmp r5, #0
	blt _080BA540
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r2, r5, #0
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r7, #0
	mov r1, sb
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _080BA52C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0
	ldrsh r4, [r0, r1]
	adds r0, r5, #0
	bl FUN_080ba220
	cmp r4, r0
	bge _080BA530
	adds r0, r7, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BA548
	.align 2, 0
_080BA524: .4byte 0x000002DF
_080BA528: .4byte 0x000012F4
_080BA52C: .4byte 0x030046A0
_080BA530:
	adds r0, r7, #0
	ldr r1, _080BA53C @ =0x000002DF
	bl FUN_080b95bc
	b _080BA548
	.align 2, 0
_080BA53C: .4byte 0x000002DF
_080BA540:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
_080BA548:
	adds r6, #0x60
	adds r7, #0x60
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	ble _080BA4D0
	ldr r7, [sp, #4]
	cmp r7, #2
	ble _080BA4A8
	movs r0, #0xd4
	lsls r0, r0, #4
	add r0, sb
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ba57c
FUN_080ba57c: @ 0x080BA57C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r1, _080BA5A8 @ =0x00001409
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BA5B0
	ldr r2, _080BA5AC @ =0x0000140B
	adds r6, r5, r2
	ldrb r0, [r6]
	bl GetNormalItemID
	adds r4, r0, #0
	cmp r4, #0
	blt _080BA610
	ldrb r0, [r6]
	bl FUN_080ba288
	adds r6, r0, #0
	movs r7, #1
	b _080BA5E4
	.align 2, 0
_080BA5A8: .4byte 0x00001409
_080BA5AC: .4byte 0x0000140B
_080BA5B0:
	cmp r0, #7
	bhi _080BA5DC
	ldr r1, _080BA5D4 @ =0x0000140B
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r2, _080BA5D8 @ =0x000012E4
	adds r0, r0, r2
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #0
	blt _080BA610
	adds r0, r4, #0
	bl FUN_080ba220
	adds r6, r0, #0
	b _080BA5E2
	.align 2, 0
_080BA5D4: .4byte 0x0000140B
_080BA5D8: .4byte 0x000012E4
_080BA5DC:
	movs r4, #1
	rsbs r4, r4, #0
	movs r6, #0
_080BA5E2:
	movs r7, #0
_080BA5E4:
	cmp r4, #0
	blt _080BA610
	ldr r1, _080BA608 @ =0x0000140B
	adds r0, r5, r1
	ldrb r1, [r0]
	add r0, sp, #4
	bl FUN_080b9938
	adds r0, r5, #0
	adds r0, #0x58
	ldr r2, _080BA60C @ =0x00000E58
	adds r1, r5, r2
	str r7, [sp]
	add r2, sp, #4
	adds r3, r6, #0
	bl FUN_080b9658
	b _080BA618
	.align 2, 0
_080BA608: .4byte 0x0000140B
_080BA60C: .4byte 0x00000E58
_080BA610:
	ldr r1, _080BA620 @ =0x00000E58
	adds r0, r5, r1
	bl FUN_080b9724
_080BA618:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BA620: .4byte 0x00000E58

	thumb_func_start FUN_080ba624
FUN_080ba624: @ 0x080BA624
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	adds r7, r0, #0
	movs r6, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x44]
	add r1, sp, #0x34
	mov r8, r1
	add r0, sp, #0x3c
	mov sb, r0
	add r1, sp, #0x1c
	mov sl, r1
	str r0, [sp, #0x48]
	mov r1, r8
	str r1, [sp, #0x4c]
	ldr r2, [sp, #0x44]
_080BA64E:
	cmp r6, #0
	bne _080BA65C
	ldr r1, _080BA658 @ =0x0000140E
	b _080BA65E
	.align 2, 0
_080BA658: .4byte 0x0000140E
_080BA65C:
	ldr r1, _080BA68C @ =0x0000140B
_080BA65E:
	adds r0, r7, r1
	ldrb r4, [r0]
	adds r1, r4, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r1, r7, #0
	adds r1, #0x80
	adds r1, r1, r0
	ldr r0, [r1]
	movs r5, #1
	orrs r0, r5
	str r0, [r1]
	adds r0, r4, #0
	str r2, [sp, #0x50]
	bl GetNormalItemID
	adds r1, r0, #0
	ldr r2, [sp, #0x50]
	cmp r1, #0
	blt _080BA690
	str r5, [r2]
	b _080BA694
	.align 2, 0
_080BA68C: .4byte 0x0000140B
_080BA690:
	movs r0, #0
	str r0, [r2]
_080BA694:
	adds r0, r1, #0
	adds r0, #0x68
	ldr r1, [sp, #0x4c]
	stm r1!, {r0}
	str r1, [sp, #0x4c]
	ldr r0, _080BA704 @ =0x000002DF
	ldr r1, [sp, #0x48]
	stm r1!, {r0}
	str r1, [sp, #0x48]
	lsls r0, r6, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r4, #0
	str r2, [sp, #0x50]
	bl FUN_080b9938
	ldr r2, [sp, #0x50]
	adds r2, #4
	adds r6, #1
	cmp r6, #1
	ble _080BA64E
	add r2, sp, #0x14
	mov r3, sl
	movs r6, #1
_080BA6C4:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r6, #1
	cmp r6, #0
	bge _080BA6C4
	ldr r1, _080BA708 @ =0x00001314
	adds r0, r7, r1
	mov r1, r8
	str r1, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x44]
	add r2, sp, #0xc
	mov r3, sl
	bl FUN_080b9a28
	ldr r0, _080BA70C @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BA704: .4byte 0x000002DF
_080BA708: .4byte 0x00001314
_080BA70C: .4byte 0x0000038A

	thumb_func_start FUN_080ba710
FUN_080ba710: @ 0x080BA710
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r3, #1
	str r3, [sp, #0x2c]
	ldr r0, _080BA7A8 @ =0x0000140E
	adds r4, r5, r0
	ldrb r0, [r4]
	adds r0, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r5, #0
	adds r2, #0x80
	adds r2, r2, r1
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldrb r0, [r4]
	bl GetNormalItemID
	adds r0, #0x68
	str r0, [sp, #0x34]
	ldr r1, _080BA7AC @ =0x000002DF
	mov r8, r1
	str r1, [sp, #0x3c]
	ldrb r1, [r4]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	ldr r1, _080BA7B0 @ =0x0000140B
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	movs r0, #0x68
	add r6, sp, #0x34
	str r0, [r6, #4]
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
	ldr r0, _080BA7B4 @ =0x00001314
	adds r5, r5, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080BA7B8 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BA7A8: .4byte 0x0000140E
_080BA7AC: .4byte 0x000002DF
_080BA7B0: .4byte 0x0000140B
_080BA7B4: .4byte 0x00001314
_080BA7B8: .4byte 0x0000038A

	thumb_func_start FUN_080ba7bc
FUN_080ba7bc: @ 0x080BA7BC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r0, #1
	str r0, [sp, #0x2c]
	ldr r0, _080BA844 @ =0x0000140E
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, r5, r0
	ldr r2, _080BA848 @ =0x000012E4
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #0x68
	str r0, [sp, #0x34]
	ldr r0, _080BA84C @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r1]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	ldr r1, _080BA850 @ =0x0000140B
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	movs r0, #0x68
	add r6, sp, #0x34
	str r0, [r6, #4]
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
	ldr r2, _080BA854 @ =0x00001314
	adds r5, r5, r2
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080BA858 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BA844: .4byte 0x0000140E
_080BA848: .4byte 0x000012E4
_080BA84C: .4byte 0x000002DF
_080BA850: .4byte 0x0000140B
_080BA854: .4byte 0x00001314
_080BA858: .4byte 0x0000038A

	thumb_func_start FUN_080ba85c
FUN_080ba85c: @ 0x080BA85C
	push {r4, r5, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _080BA894
	ldr r1, _080BA87C @ =0x00001409
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BA880
	adds r1, #0x2f
	adds r0, r4, r1
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080BA976
	.align 2, 0
_080BA87C: .4byte 0x00001409
_080BA880:
	ldr r1, _080BA890 @ =0x00001438
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080BA976
	.align 2, 0
_080BA890: .4byte 0x00001438
_080BA894:
	movs r2, #0
	ldr r1, _080BA8C4 @ =0x0000140C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BA8E4
	ldr r0, _080BA8C8 @ =0x0000140E
	adds r5, r4, r0
	ldrb r0, [r5]
	bl GetNormalItemID
	cmp r0, #0
	blt _080BA8D0
	ldr r1, _080BA8CC @ =0x0000140B
	adds r0, r4, r1
	ldrb r0, [r0]
	ldrb r5, [r5]
	cmp r0, r5
	beq _080BA8C0
	movs r2, #1
	cmp r0, #0x22
	bne _080BA912
_080BA8C0:
	movs r2, #5
	b _080BA912
	.align 2, 0
_080BA8C4: .4byte 0x0000140C
_080BA8C8: .4byte 0x0000140E
_080BA8CC: .4byte 0x0000140B
_080BA8D0:
	ldr r1, _080BA8E0 @ =0x0000140B
	adds r0, r4, r1
	ldrb r0, [r0]
	bl GetNormalItemID
	mvns r0, r0
	lsrs r2, r0, #0x1f
	b _080BA912
	.align 2, 0
_080BA8E0: .4byte 0x0000140B
_080BA8E4:
	ldr r0, _080BA8F8 @ =0x0000140B
	adds r3, r4, r0
	adds r0, #3
	adds r1, r4, r0
	ldrb r0, [r3]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BA8FC
	movs r2, #4
	b _080BA912
	.align 2, 0
_080BA8F8: .4byte 0x0000140B
_080BA8FC:
	ldr r1, _080BA920 @ =0x00001409
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BA912
	ldrb r0, [r3]
	bl GetNormalItemID
	asrs r2, r0, #0x1f
	movs r0, #4
	ands r2, r0
_080BA912:
	cmp r2, #4
	beq _080BA92A
	cmp r2, #4
	bgt _080BA924
	cmp r2, #1
	beq _080BA954
	b _080BA968
	.align 2, 0
_080BA920: .4byte 0x00001409
_080BA924:
	cmp r2, #5
	beq _080BA940
	b _080BA968
_080BA92A:
	ldr r1, _080BA93C @ =0x00001438
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #7
	bl FUN_080b98c0
	b _080BA976
	.align 2, 0
_080BA93C: .4byte 0x00001438
_080BA940:
	ldr r1, _080BA950 @ =0x00001438
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #6
	bl FUN_080b98c0
	b _080BA976
	.align 2, 0
_080BA950: .4byte 0x00001438
_080BA954:
	ldr r1, _080BA964 @ =0x00001438
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080BA976
	.align 2, 0
_080BA964: .4byte 0x00001438
_080BA968:
	ldr r1, _080BA97C @ =0x00001438
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080BA976:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BA97C: .4byte 0x00001438

	thumb_func_start FUN_080ba980
FUN_080ba980: @ 0x080BA980
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080BA9B0 @ =0x0000140C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BA9DC
	ldr r2, _080BA9B4 @ =0x0000140E
	adds r5, r4, r2
	ldrb r0, [r5]
	bl GetNormalItemID
	cmp r0, #0
	blt _080BA9C4
	ldr r3, _080BA9B8 @ =0x0000140B
	adds r1, r4, r3
	ldrb r0, [r1]
	ldrb r5, [r5]
	cmp r0, r5
	bne _080BA9BC
	movs r0, #0x22
	strb r0, [r1]
	movs r0, #5
	b _080BAA3A
	.align 2, 0
_080BA9B0: .4byte 0x0000140C
_080BA9B4: .4byte 0x0000140E
_080BA9B8: .4byte 0x0000140B
_080BA9BC:
	cmp r0, #0x22
	bne _080BA9D2
	movs r0, #5
	b _080BAA3A
_080BA9C4:
	ldr r1, _080BA9D8 @ =0x0000140B
	adds r0, r4, r1
	ldrb r0, [r0]
	bl GetNormalItemID
	cmp r0, #0
	blt _080BAA38
_080BA9D2:
	movs r0, #1
	b _080BAA3A
	.align 2, 0
_080BA9D8: .4byte 0x0000140B
_080BA9DC:
	ldr r3, _080BAA0C @ =0x0000140B
	adds r2, r4, r3
	ldr r0, _080BAA10 @ =0x0000140E
	adds r1, r4, r0
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BAA1C
	ldr r1, _080BAA14 @ =0x000012F2
	adds r0, r4, r1
	ldrh r1, [r0]
	strb r1, [r2]
	movs r0, #3
	ands r0, r1
	subs r3, #2
	adds r1, r4, r3
	strb r0, [r1]
	ldrb r0, [r2]
	lsrs r0, r0, #2
	ldr r2, _080BAA18 @ =0x0000140A
	adds r1, r4, r2
	strb r0, [r1]
	movs r0, #4
	b _080BAA3A
	.align 2, 0
_080BAA0C: .4byte 0x0000140B
_080BAA10: .4byte 0x0000140E
_080BAA14: .4byte 0x000012F2
_080BAA18: .4byte 0x0000140A
_080BAA1C:
	ldr r3, _080BAA34 @ =0x00001409
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BAA38
	ldrb r0, [r2]
	bl GetNormalItemID
	cmp r0, #0
	bge _080BAA38
	movs r0, #4
	b _080BAA3A
	.align 2, 0
_080BAA34: .4byte 0x00001409
_080BAA38:
	movs r0, #0
_080BAA3A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080baa40
FUN_080baa40: @ 0x080BAA40
	push {r4, lr}
	movs r4, #0
_080BAA44:
	adds r0, r4, #0
	bl GetNormalItemID
	cmp r0, #0
	bge _080BAA52
	adds r0, r4, #0
	b _080BAA5C
_080BAA52:
	adds r4, #1
	cmp r4, #0xf
	ble _080BAA44
	movs r0, #1
	rsbs r0, r0, #0
_080BAA5C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080baa64
FUN_080baa64: @ 0x080BAA64
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xda
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	subs r1, #3
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_080baa40
	ldr r2, _080BAAD8 @ =0x000012F2
	adds r1, r5, r2
	strh r0, [r1]
	ldr r0, _080BAADC @ =0x00001408
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r2, _080BAAE0 @ =0x00000D98
	adds r1, r5, r2
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #0x14
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FUN_080ba410
	adds r0, r5, #0
	bl FUN_080ba57c
	adds r0, r5, #0
	bl FUN_080ba2d8
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba85c
	ldr r1, _080BAAE4 @ =FUN_080baae8
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080ba054
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BAAD8: .4byte 0x000012F2
_080BAADC: .4byte 0x00001408
_080BAAE0: .4byte 0x00000D98
_080BAAE4: .4byte FUN_080baae8

	thumb_func_start FUN_080baae8
FUN_080baae8: @ 0x080BAAE8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _080BAB54 @ =0x00001408
	adds r6, r5, r0
	ldr r1, _080BAB58 @ =0x00000C78
	adds r2, r5, r1
	ldr r0, _080BAB5C @ =0x00000C18
	adds r3, r5, r0
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080b95d0
	ldr r7, _080BAB60 @ =0x030044E0
	ldrh r1, [r7]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080BAB6C
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba048
	ldr r1, _080BAB64 @ =0x00000D98
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldrh r1, [r7, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BAB34
	b _080BAD26
_080BAB34:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r2, _080BAB68 @ =0x0000151A
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080BAB4E
	b _080BAD26
_080BAB4E:
	movs r0, #0
	strb r0, [r1]
	b _080BAD26
	.align 2, 0
_080BAB54: .4byte 0x00001408
_080BAB58: .4byte 0x00000C78
_080BAB5C: .4byte 0x00000C18
_080BAB60: .4byte 0x030044E0
_080BAB64: .4byte 0x00000D98
_080BAB68: .4byte 0x0000151A
_080BAB6C:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ba048
	ldr r0, _080BABD4 @ =0x00000D98
	adds r4, r5, r0
	movs r1, #0x18
	adds r1, r1, r5
	mov r8, r1
	adds r0, r4, #0
	bl FUN_082372cc
	ldrh r1, [r7, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BAB90
	b _080BAD00
_080BAB90:
	ldr r2, _080BABD8 @ =0x0000140B
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0x21
	bne _080BABF4
	ldr r0, _080BABDC @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BABE0 @ =0x000012E4
	adds r0, r5, r1
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl FUN_080ba07c
	ldr r2, _080BABE4 @ =0x00001278
	adds r0, r5, r2
	ldr r1, _080BABE8 @ =0x000012EF
	adds r2, r5, r1
	mov r1, r8
	movs r3, #1
	bl FUN_080b9740
	ldr r2, _080BABEC @ =0x00001438
	adds r0, r5, r2
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080BABF0 @ =FUN_080baeb0
	b _080BACF2
	.align 2, 0
_080BABD4: .4byte 0x00000D98
_080BABD8: .4byte 0x0000140B
_080BABDC: .4byte 0x00000107
_080BABE0: .4byte 0x000012E4
_080BABE4: .4byte 0x00001278
_080BABE8: .4byte 0x000012EF
_080BABEC: .4byte 0x00001438
_080BABF0: .4byte FUN_080baeb0
_080BABF4:
	ldr r2, _080BAC44 @ =0x00001409
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #3
	bls _080BAC90
	movs r7, #1
	ldrb r0, [r1]
	adds r0, r5, r0
	ldr r1, _080BAC48 @ =0x000012E4
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	blt _080BAC3A
	ldr r0, _080BAC4C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r2, #0
	ldrsh r4, [r0, r2]
	adds r0, r1, #0
	bl FUN_080ba220
	cmp r4, r0
	blt _080BAC3A
	ldr r1, _080BAC50 @ =0x000012F2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bge _080BAC36
	movs r7, #0
_080BAC36:
	cmp r7, #0
	bne _080BAC54
_080BAC3A:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BAD26
	.align 2, 0
_080BAC44: .4byte 0x00001409
_080BAC48: .4byte 0x000012E4
_080BAC4C: .4byte 0x030046A0
_080BAC50: .4byte 0x000012F2
_080BAC54:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_080b9fd8
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BAC8C @ =0x00000E18
	adds r2, r5, r1
	subs r1, #0x60
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r6, #0
	movs r1, #0x3c
	bl FUN_080b9d94
	b _080BACE8
	.align 2, 0
_080BAC8C: .4byte 0x00000E18
_080BAC90:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_080b9fd8
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BACD8 @ =0x00000E18
	adds r2, r5, r1
	subs r1, #0x60
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080BACDC @ =0x0000140E
	adds r0, r5, r2
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r1, r0, #0
	cmp r1, #0
	bge _080BACE0
	adds r0, r6, #0
	movs r1, #0x1e
	bl FUN_080b9d94
	b _080BACE8
	.align 2, 0
_080BACD8: .4byte 0x00000E18
_080BACDC: .4byte 0x0000140E
_080BACE0:
	adds r0, r6, #0
	movs r1, #0xe
	bl FUN_080b9d94
_080BACE8:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ba85c
	ldr r1, _080BACFC @ =FUN_080bad30
_080BACF2:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BAD26
	.align 2, 0
_080BACFC: .4byte FUN_080bad30
_080BAD00:
	adds r0, r6, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080BAD26
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080ba2d8
	adds r0, r5, #0
	bl FUN_080ba57c
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba85c
_080BAD26:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bad30
FUN_080bad30: @ 0x080BAD30
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080BAD68 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BAD42
	b _080BAE3E
_080BAD42:
	adds r0, r5, #0
	bl FUN_080ba980
	adds r4, r0, #0
	ldr r1, _080BAD6C @ =0x00001438
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	cmp r4, #4
	beq _080BAD8C
	cmp r4, #4
	bgt _080BAD70
	cmp r4, #1
	beq _080BAD76
	b _080BAE34
	.align 2, 0
_080BAD68: .4byte 0x030044E0
_080BAD6C: .4byte 0x00001438
_080BAD70:
	cmp r4, #5
	beq _080BADDC
	b _080BAE34
_080BAD76:
	adds r0, r5, #0
	bl FUN_080ba624
	ldr r1, _080BAD88 @ =0x080BAF1D
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BAE52
	.align 2, 0
_080BAD88: .4byte 0x080BAF1D
_080BAD8C:
	ldr r0, _080BADC8 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BADCC @ =0x000012E4
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r1, _080BADD0 @ =0x0000140E
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r1, _080BADCC @ =0x000012E4
	adds r0, r0, r1
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba07c
	ldr r1, _080BADD4 @ =0x00001278
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x77
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080BADD8 @ =FUN_080baf50
	b _080BAE14
	.align 2, 0
_080BADC8: .4byte 0x00000107
_080BADCC: .4byte 0x000012E4
_080BADD0: .4byte 0x0000140E
_080BADD4: .4byte 0x00001278
_080BADD8: .4byte FUN_080baf50
_080BADDC:
	ldr r0, _080BAE20 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BAE24 @ =0x000012E4
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r1, _080BAE28 @ =0x0000140E
	adds r0, r5, r1
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r3, r0, #0
	adds r0, r5, #0
	movs r1, #1
	adds r2, r4, #0
	bl FUN_080ba07c
	ldr r1, _080BAE2C @ =0x00001278
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x77
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080BAE30 @ =FUN_080bb01c
_080BAE14:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BAE82
	.align 2, 0
_080BAE20: .4byte 0x00000107
_080BAE24: .4byte 0x000012E4
_080BAE28: .4byte 0x0000140E
_080BAE2C: .4byte 0x00001278
_080BAE30: .4byte FUN_080bb01c
_080BAE34:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BAE52
_080BAE3E:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BAE58
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080baa64
_080BAE52:
	adds r4, r5, #0
	adds r4, #0x18
	b _080BAE82
_080BAE58:
	ldr r0, _080BAEA4 @ =0x00001408
	adds r6, r5, r0
	adds r0, r6, #0
	bl FUN_080b9f70
	adds r4, r5, #0
	adds r4, #0x18
	cmp r0, #0
	beq _080BAE82
	ldr r0, _080BAEA8 @ =0x00000D98
	adds r1, r5, r0
	adds r0, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080ba2d8
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ba85c
_080BAE82:
	ldr r1, _080BAEA4 @ =0x00001408
	adds r0, r5, r1
	ldr r1, _080BAEAC @ =0x00000C78
	adds r2, r5, r1
	subs r1, #0x60
	adds r3, r5, r1
	movs r1, #0
	bl FUN_080b95d0
	ldr r1, _080BAEA8 @ =0x00000D98
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_082372cc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BAEA4: .4byte 0x00001408
_080BAEA8: .4byte 0x00000D98
_080BAEAC: .4byte 0x00000C78

	thumb_func_start FUN_080baeb0
FUN_080baeb0: @ 0x080BAEB0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BAEF0 @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BAEF4 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BAF04
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortInventory
	ldr r1, _080BAEF8 @ =0x0000140C
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080BAEFC @ =0x0000140D
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080BAF00 @ =0x0000140E
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080baa64
	b _080BAF14
	.align 2, 0
_080BAEF0: .4byte 0x00001278
_080BAEF4: .4byte 0x000012EF
_080BAEF8: .4byte 0x0000140C
_080BAEFC: .4byte 0x0000140D
_080BAF00: .4byte 0x0000140E
_080BAF04:
	cmp r0, #0
	bne _080BAF14
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080baa64
_080BAF14:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BAF1C:
	.byte 0x10, 0xB5, 0x04, 0x1C
	.byte 0x09, 0x49, 0x60, 0x18, 0xFE, 0xF7, 0xDA, 0xFD, 0x00, 0x28, 0x0A, 0xD0, 0x07, 0x4A, 0xA0, 0x18
	.byte 0x00, 0x78, 0x03, 0x3A, 0xA1, 0x18, 0x09, 0x78, 0x87, 0xF1, 0xDA, 0xFA, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0x91, 0xFD, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x14, 0x13, 0x00, 0x00, 0x0E, 0x14, 0x00, 0x00

	thumb_func_start FUN_080baf50
FUN_080baf50: @ 0x080BAF50
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BAF80 @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BAF84 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BAF8C
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080ba7bc
	ldr r1, _080BAF88 @ =0x080BAFA5
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BAF9C
	.align 2, 0
_080BAF80: .4byte 0x00001278
_080BAF84: .4byte 0x000012EF
_080BAF88: .4byte 0x080BAFA5
_080BAF8C:
	cmp r0, #0
	bne _080BAF9C
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080baa64
_080BAF9C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BAFA4:
	.byte 0x70, 0xB5, 0x06, 0x1C, 0x16, 0x49, 0x70, 0x18, 0xFE, 0xF7, 0x96, 0xFD
	.byte 0x00, 0x28, 0x23, 0xD0, 0x14, 0x49, 0x70, 0x18, 0x05, 0x78, 0x03, 0x31, 0x70, 0x18, 0x04, 0x78
	.byte 0x34, 0x19, 0x12, 0x48, 0x24, 0x18, 0x00, 0x20, 0x20, 0x56, 0xFF, 0xF7, 0x29, 0xF9, 0x10, 0x49
	.byte 0x0A, 0x68, 0x91, 0x21, 0x09, 0x01, 0x52, 0x18, 0x11, 0x88, 0x09, 0x1A, 0x11, 0x80, 0x00, 0x21
	.byte 0x61, 0x56, 0x28, 0x1C, 0x87, 0xF1, 0x50, 0xF9, 0x0A, 0x48, 0x31, 0x18, 0x01, 0x20, 0x08, 0x70
	.byte 0x09, 0x48, 0x85, 0xF1, 0x75, 0xFB, 0x30, 0x1C, 0xFF, 0xF7, 0x34, 0xFD, 0x70, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00, 0x14, 0x13, 0x00, 0x00, 0x0B, 0x14, 0x00, 0x00, 0xE4, 0x12, 0x00, 0x00
	.byte 0xA0, 0x46, 0x00, 0x03, 0x1B, 0x15, 0x00, 0x00, 0x11, 0x01, 0x00, 0x00

	thumb_func_start FUN_080bb01c
FUN_080bb01c: @ 0x080BB01C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BB04C @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BB050 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BB058
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080ba710
	ldr r1, _080BB054 @ =0x080BB071
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BB068
	.align 2, 0
_080BB04C: .4byte 0x00001278
_080BB050: .4byte 0x000012EF
_080BB054: .4byte 0x080BB071
_080BB058:
	cmp r0, #0
	bne _080BB068
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080baa64
_080BB068:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BB070:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0x16, 0x49, 0x60, 0x18, 0xFE, 0xF7, 0x30, 0xFD, 0x00, 0x28, 0x23, 0xD0
	.byte 0x14, 0x49, 0x60, 0x18, 0x05, 0x78, 0x28, 0x1C, 0xFF, 0xF7, 0xFE, 0xF8, 0x12, 0x4B, 0x1A, 0x68
	.byte 0x91, 0x21, 0x09, 0x01, 0x52, 0x18, 0x11, 0x88, 0x09, 0x18, 0x11, 0x80, 0x09, 0x04, 0x09, 0x14
	.byte 0x0E, 0x4A, 0x91, 0x42, 0x04, 0xDD, 0x18, 0x68, 0x91, 0x21, 0x09, 0x01, 0x40, 0x18, 0x02, 0x80
	.byte 0x28, 0x1C, 0x87, 0xF1, 0xFF, 0xF8, 0x0A, 0x49, 0x60, 0x18, 0x01, 0x21, 0x01, 0x70, 0x09, 0x49
	.byte 0x20, 0x1C, 0x00, 0x22, 0xFE, 0xF7, 0xC6, 0xFF, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x14, 0x13, 0x00, 0x00, 0x0E, 0x14, 0x00, 0x00, 0xA0, 0x46, 0x00, 0x03, 0x0F, 0x27, 0x00, 0x00
	.byte 0x1C, 0x15, 0x00, 0x00, 0xE9, 0xB0, 0x0B, 0x08

	thumb_func_start FUN_080bb0e8
FUN_080bb0e8: @ 0x080BB0E8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080BB11C @ =0x000012F0
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080BB0FC
	ldr r0, _080BB120 @ =0x00000276
	bl PlaySound_082406e0
_080BB0FC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	bhi _080BB140
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BB128
	ldr r2, _080BB124 @ =0x00000C3A
	adds r1, r5, r2
	b _080BB148
	.align 2, 0
_080BB11C: .4byte 0x000012F0
_080BB120: .4byte 0x00000276
_080BB124: .4byte 0x00000C3A
_080BB128:
	ldrh r1, [r4]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x20
	subs r1, r1, r0
	ldr r2, _080BB13C @ =0x00000C3A
	adds r0, r5, r2
	strh r1, [r0]
	b _080BB15A
	.align 2, 0
_080BB13C: .4byte 0x00000C3A
_080BB140:
	cmp r1, #0xf
	bhi _080BB154
	ldr r0, _080BB150 @ =0x00000C3A
	adds r1, r5, r0
_080BB148:
	movs r0, #0x20
	strh r0, [r1]
	b _080BB15A
	.align 2, 0
_080BB150: .4byte 0x00000C3A
_080BB154:
	adds r0, r5, #0
	bl FUN_080baa64
_080BB15A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bb160
FUN_080bb160: @ 0x080BB160
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, _080BB23C @ =0x000012ED
	adds r0, r6, r1
	movs r5, #0
	strb r5, [r0]
	adds r0, r6, #0
	bl FUN_080baa40
	ldr r2, _080BB240 @ =0x000012F2
	adds r1, r6, r2
	strh r0, [r1]
	ldr r0, _080BB244 @ =0x03003ED0
	ldr r4, [r0, #0x2c]
	ldr r1, _080BB248 @ =0x000012D8
	adds r0, r6, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #2
	bl FUN_0822c398
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r4, #0xe4
	ldr r2, _080BB24C @ =0x0000F050
	adds r0, r2, #0
	strh r0, [r4]
	adds r4, #2
	ldr r1, _080BB250 @ =0x0000F051
	adds r0, r1, #0
	strh r0, [r4]
	adds r4, #2
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r4]
	adds r4, #2
	adds r1, #0xf
	adds r0, r1, #0
	strh r0, [r4]
	adds r4, #2
	adds r2, #0xf
	adds r0, r2, #0
	strh r0, [r4]
	adds r4, #2
	adds r1, #2
	adds r0, r1, #0
	strh r0, [r4]
	adds r4, #2
	subs r2, #0x51
	adds r0, r2, #0
	strh r0, [r4]
	adds r4, #2
	strh r0, [r4]
	adds r4, #2
	strh r0, [r4]
	adds r4, #2
	strh r0, [r4]
	strh r0, [r4, #2]
	ldr r0, _080BB254 @ =0x0000151A
	adds r4, r6, r0
	ldrb r0, [r4]
	bl FUN_080b94cc
	ldrb r0, [r4]
	bl FUN_080b9400
	ldr r1, _080BB258 @ =0x00001408
	adds r4, r6, r1
	movs r0, #0x14
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #4
	movs r3, #0
	bl FUN_080b9ff8
	ldr r2, _080BB25C @ =0x00000D98
	adds r1, r6, r2
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r6, #0
	bl FUN_080ba410
	adds r0, r6, #0
	bl FUN_080ba57c
	adds r0, r6, #0
	bl FUN_080ba2d8
	ldr r0, _080BB260 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x5c
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _080BB264
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r6, #0
	bl FUN_080ba0f0
	b _080BB274
	.align 2, 0
_080BB23C: .4byte 0x000012ED
_080BB240: .4byte 0x000012F2
_080BB244: .4byte 0x03003ED0
_080BB248: .4byte 0x000012D8
_080BB24C: .4byte 0x0000F050
_080BB250: .4byte 0x0000F051
_080BB254: .4byte 0x0000151A
_080BB258: .4byte 0x00001408
_080BB25C: .4byte 0x00000D98
_080BB260: .4byte 0x030046A0
_080BB264:
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl GetInventoryArmor
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_080ba0f0
_080BB274:
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ba85c
	ldr r1, _080BB290 @ =FUN_080baae8
	adds r0, r6, #0
	movs r2, #1
	bl FUN_080ba054
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BB290: .4byte FUN_080baae8

	thumb_func_start FUN_080bb294
FUN_080bb294: @ 0x080BB294
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, _080BB2BC @ =0x00001409
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BB2C4
	adds r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	ldr r1, _080BB2C0 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r7, [r0, r1]
	b _080BB2E8
	.align 2, 0
_080BB2BC: .4byte 0x00001409
_080BB2C0: .4byte 0x030046A0
_080BB2C4:
	cmp r0, #7
	bhi _080BB2E4
	ldr r1, _080BB2DC @ =0x0000140B
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r0, r6, r0
	ldr r1, _080BB2E0 @ =0x000012F4
	adds r0, r0, r1
	movs r7, #0
	ldrsb r7, [r0, r7]
	b _080BB2E8
	.align 2, 0
_080BB2DC: .4byte 0x0000140B
_080BB2E0: .4byte 0x000012F4
_080BB2E4:
	movs r7, #1
	rsbs r7, r7, #0
_080BB2E8:
	cmp r7, #0
	bge _080BB304
	movs r1, #0xce
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _080BB36E
_080BB304:
	movs r0, #0xce
	lsls r0, r0, #4
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BB37C @ =0x00000CD8
	adds r0, r6, r1
	adds r1, r6, #0
	adds r1, #0x38
	movs r2, #0xcf
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _080BB380 @ =0x000012E8
	adds r5, r6, r0
	ldr r0, [r5]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r0, _080BB384 @ =0x08DAA7B0
	lsls r4, r7, #3
	adds r4, r4, r0
	ldrb r1, [r4, #1]
	movs r0, #0
	bl FUN_08049e6c
	ldrb r1, [r4, #2]
	movs r0, #1
	bl FUN_08049e6c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r7, #0
	bl FUN_08047a28
	ldr r0, [r5]
	bl VM_ParseStringRef
	adds r0, #0x25
	adds r0, r0, r7
	bl Textbox_LookupString
	bl FUN_08049e30
_080BB36E:
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_080ba0f0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BB37C: .4byte 0x00000CD8
_080BB380: .4byte 0x000012E8
_080BB384: .4byte 0x08DAA7B0

	thumb_func_start FUN_080bb388
FUN_080bb388: @ 0x080BB388
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov sl, r0
	movs r0, #0
	str r0, [sp]
	mov r1, sl
	adds r1, #0x80
	str r1, [sp, #8]
	movs r2, #0
	str r2, [sp, #0xc]
	str r0, [sp, #0x10]
	movs r1, #0
	str r1, [sp, #0x14]
_080BB3AA:
	movs r2, #0
	mov sb, r2
	movs r0, #0xcc
	lsls r0, r0, #1
	add r0, sl
	ldr r1, [sp, #0x14]
	adds r6, r1, r0
	ldr r2, [sp, #0xc]
	mov r8, r2
	ldr r1, [sp, #0x10]
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #8]
	adds r5, r0, r1
_080BB3CA:
	ldr r7, [sp, #0x10]
	add r7, sb
	ldr r0, _080BB404 @ =0x030046A0
	ldr r0, [r0]
	add r0, r8
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r4, [r0, r1]
	cmp r4, #0
	blt _080BB408
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r2, r4, #0
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080BB410
	.align 2, 0
_080BB404: .4byte 0x030046A0
_080BB408:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
_080BB410:
	ldr r0, _080BB438 @ =0x08DAA7B0
	lsls r1, r4, #3
	adds r1, r1, r0
	movs r2, #6
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _080BB42C
	ldr r0, _080BB43C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r7, r0
	bne _080BB440
_080BB42C:
	adds r0, r6, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BB448
	.align 2, 0
_080BB438: .4byte 0x08DAA7B0
_080BB43C: .4byte 0x030046A0
_080BB440:
	adds r0, r6, #0
	ldr r1, _080BB504 @ =0x000002DF
	bl FUN_080b95bc
_080BB448:
	adds r6, #0x60
	movs r2, #2
	add r8, r2
	adds r5, #0x60
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #3
	ble _080BB3CA
	ldr r2, [sp, #0xc]
	adds r2, #8
	str r2, [sp, #0xc]
	ldr r0, [sp, #0x10]
	adds r0, #4
	str r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r1, r2
	str r1, [sp, #0x14]
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	cmp r0, #3
	ble _080BB3AA
	movs r1, #0
	str r1, [sp]
_080BB47E:
	movs r2, #0
	mov sb, r2
	ldr r0, [sp]
	lsls r0, r0, #2
	mov r8, r0
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp, #4]
	mov r2, r8
	adds r2, #0x13
	ldr r1, [sp]
	lsls r0, r1, #3
	add r0, r8
	lsls r0, r0, #5
	movs r1, #0xf3
	lsls r1, r1, #3
	add r1, sl
	adds r6, r0, r1
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r2, [sp, #8]
	adds r5, r0, r2
_080BB4AC:
	mov r7, r8
	add r7, sb
	ldr r0, _080BB508 @ =0x00001304
	add r0, sl
	adds r0, r0, r7
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #0
	blt _080BB524
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r2, r4, #0
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _080BB50C @ =0x030046A0
	ldr r1, [r0]
	movs r0, #0x91
	lsls r0, r0, #4
	adds r1, r1, r0
	ldr r2, _080BB510 @ =0x08DAA7B0
	lsls r0, r4, #3
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #6
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _080BB514
	adds r0, r6, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BB52C
	.align 2, 0
_080BB504: .4byte 0x000002DF
_080BB508: .4byte 0x00001304
_080BB50C: .4byte 0x030046A0
_080BB510: .4byte 0x08DAA7B0
_080BB514:
	adds r0, r6, #0
	ldr r1, _080BB520 @ =0x000002DF
	bl FUN_080b95bc
	b _080BB52C
	.align 2, 0
_080BB520: .4byte 0x000002DF
_080BB524:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
_080BB52C:
	adds r5, #0x60
	adds r6, #0x60
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #3
	ble _080BB4AC
	movs r5, #3
	ldr r2, [sp, #4]
	str r2, [sp]
	cmp r2, #2
	ble _080BB47E
	ldr r0, _080BB568 @ =0x030046A0
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x5c
	ldrh r4, [r3]
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bge _080BB56C
	movs r0, #0xd4
	lsls r0, r0, #4
	add r0, sl
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080BB5A2
	.align 2, 0
_080BB568: .4byte 0x030046A0
_080BB56C:
	movs r2, #0xd4
	lsls r2, r2, #4
	add r2, sl
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r5, #0
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	ldr r1, _080BB5B4 @ =0x00000D58
	add r1, sl
	strh r0, [r1]
	ldrh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x12
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	ldr r1, _080BB5B8 @ =0x00000D5A
	add r1, sl
	strh r0, [r1]
_080BB5A2:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BB5B4: .4byte 0x00000D58
_080BB5B8: .4byte 0x00000D5A

	thumb_func_start FUN_080bb5bc
FUN_080bb5bc: @ 0x080BB5BC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r1, _080BB600 @ =0x00001409
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BB610
	ldr r2, _080BB604 @ =0x0000140B
	adds r0, r5, r2
	ldrb r0, [r0]
	ldr r1, _080BB608 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r4, [r0, r2]
	ldr r1, _080BB60C @ =0x08DAA7B0
	lsls r0, r4, #3
	adds r0, r0, r1
	movs r2, #6
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	adds r6, r0, #0
	movs r7, #1
	b _080BB644
	.align 2, 0
_080BB600: .4byte 0x00001409
_080BB604: .4byte 0x0000140B
_080BB608: .4byte 0x030046A0
_080BB60C: .4byte 0x08DAA7B0
_080BB610:
	cmp r0, #7
	bhi _080BB63C
	ldr r1, _080BB630 @ =0x0000140B
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r2, _080BB634 @ =0x000012F4
	adds r0, r0, r2
	movs r4, #0
	ldrsb r4, [r0, r4]
	ldr r1, _080BB638 @ =0x08DAA7B0
	lsls r0, r4, #3
	adds r0, r0, r1
	movs r1, #6
	ldrsh r6, [r0, r1]
	b _080BB642
	.align 2, 0
_080BB630: .4byte 0x0000140B
_080BB634: .4byte 0x000012F4
_080BB638: .4byte 0x08DAA7B0
_080BB63C:
	movs r4, #1
	rsbs r4, r4, #0
	movs r6, #0
_080BB642:
	movs r7, #0
_080BB644:
	cmp r4, #0
	blt _080BB674
	cmp r6, #0
	ble _080BB674
	ldr r2, _080BB66C @ =0x0000140B
	adds r0, r5, r2
	ldrb r1, [r0]
	add r0, sp, #4
	bl FUN_080b9938
	adds r0, r5, #0
	adds r0, #0x58
	ldr r2, _080BB670 @ =0x00000E58
	adds r1, r5, r2
	str r7, [sp]
	add r2, sp, #4
	adds r3, r6, #0
	bl FUN_080b9658
	b _080BB67C
	.align 2, 0
_080BB66C: .4byte 0x0000140B
_080BB670: .4byte 0x00000E58
_080BB674:
	ldr r1, _080BB684 @ =0x00000E58
	adds r0, r5, r1
	bl FUN_080b9724
_080BB67C:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BB684: .4byte 0x00000E58

	thumb_func_start FUN_080bb688
FUN_080bb688: @ 0x080BB688
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	adds r6, r0, #0
	movs r5, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x44]
	add r1, sp, #0x34
	mov r8, r1
	add r4, sp, #0x3c
	mov sb, r4
	add r0, sp, #0x1c
	mov sl, r0
	mov r1, sb
	str r1, [sp, #0x48]
	mov r4, r8
	str r4, [sp, #0x4c]
	ldr r7, [sp, #0x44]
_080BB6B4:
	cmp r5, #0
	bne _080BB6C4
	ldr r1, _080BB6C0 @ =0x0000140E
	adds r0, r6, r1
	b _080BB6C8
	.align 2, 0
_080BB6C0: .4byte 0x0000140E
_080BB6C4:
	ldr r4, _080BB714 @ =0x0000140B
	adds r0, r6, r4
_080BB6C8:
	ldrb r2, [r0]
	adds r1, r2, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r1, r6, #0
	adds r1, #0x80
	adds r1, r1, r0
	ldr r0, [r1]
	movs r3, #1
	orrs r0, r3
	str r0, [r1]
	ldr r4, _080BB718 @ =0x030046A0
	ldr r0, [r4]
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bne _080BB6FA
	movs r0, #0xd4
	lsls r0, r0, #4
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
_080BB6FA:
	ldr r1, [r4]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	cmp r1, #0
	blt _080BB71C
	str r3, [r7]
	b _080BB720
	.align 2, 0
_080BB714: .4byte 0x0000140B
_080BB718: .4byte 0x030046A0
_080BB71C:
	movs r0, #0
	str r0, [r7]
_080BB720:
	adds r0, r1, #0
	adds r0, #0x43
	ldr r1, [sp, #0x4c]
	stm r1!, {r0}
	str r1, [sp, #0x4c]
	ldr r0, _080BB78C @ =0x000002DF
	ldr r4, [sp, #0x48]
	stm r4!, {r0}
	str r4, [sp, #0x48]
	lsls r0, r5, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r2, #0
	bl FUN_080b9938
	adds r7, #4
	adds r5, #1
	cmp r5, #1
	ble _080BB6B4
	add r2, sp, #0x14
	mov r3, sl
	movs r5, #1
_080BB74C:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r5, #1
	cmp r5, #0
	bge _080BB74C
	ldr r1, _080BB790 @ =0x00001314
	adds r0, r6, r1
	mov r4, r8
	str r4, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x44]
	add r2, sp, #0xc
	mov r3, sl
	bl FUN_080b9a28
	ldr r0, _080BB794 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BB78C: .4byte 0x000002DF
_080BB790: .4byte 0x00001314
_080BB794: .4byte 0x0000038A

	thumb_func_start FUN_080bb798
FUN_080bb798: @ 0x080BB798
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r4, #1
	str r4, [sp, #0x2c]
	ldr r0, _080BB83C @ =0x0000140E
	adds r3, r5, r0
	ldrb r0, [r3]
	adds r0, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r5, #0
	adds r2, #0x80
	adds r2, r2, r1
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	ldrb r0, [r3]
	ldr r1, _080BB840 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r0, #0x43
	str r0, [sp, #0x34]
	ldr r0, _080BB844 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r3]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	ldr r1, _080BB848 @ =0x0000140B
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	movs r0, #0x43
	add r6, sp, #0x34
	str r0, [r6, #4]
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
	ldr r0, _080BB84C @ =0x00001314
	adds r5, r5, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080BB850 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BB83C: .4byte 0x0000140E
_080BB840: .4byte 0x030046A0
_080BB844: .4byte 0x000002DF
_080BB848: .4byte 0x0000140B
_080BB84C: .4byte 0x00001314
_080BB850: .4byte 0x0000038A

	thumb_func_start FUN_080bb854
FUN_080bb854: @ 0x080BB854
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r0, #1
	str r0, [sp, #0x2c]
	ldr r0, _080BB8DC @ =0x0000140E
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, r5, r0
	ldr r2, _080BB8E0 @ =0x000012F4
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #0x43
	str r0, [sp, #0x34]
	ldr r0, _080BB8E4 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r1]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	ldr r1, _080BB8E8 @ =0x0000140B
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	movs r0, #0x68
	add r6, sp, #0x34
	str r0, [r6, #4]
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
	ldr r2, _080BB8EC @ =0x00001314
	adds r5, r5, r2
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080BB8F0 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BB8DC: .4byte 0x0000140E
_080BB8E0: .4byte 0x000012F4
_080BB8E4: .4byte 0x000002DF
_080BB8E8: .4byte 0x0000140B
_080BB8EC: .4byte 0x00001314
_080BB8F0: .4byte 0x0000038A

	thumb_func_start FUN_080bb8f4
FUN_080bb8f4: @ 0x080BB8F4
	push {r4, r5, lr}
	adds r3, r0, #0
	cmp r1, #0
	bne _080BB930
	ldr r1, _080BB914 @ =0x00001409
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BB91C
	ldr r2, _080BB918 @ =0x00001438
	adds r0, r3, r2
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080BBA7E
	.align 2, 0
_080BB914: .4byte 0x00001409
_080BB918: .4byte 0x00001438
_080BB91C:
	ldr r4, _080BB92C @ =0x00001438
	adds r0, r3, r4
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080BBA7E
	.align 2, 0
_080BB92C: .4byte 0x00001438
_080BB930:
	movs r4, #0
	ldr r5, _080BB97C @ =0x0000140C
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BB9D4
	ldr r1, _080BB980 @ =0x0000140E
	adds r0, r3, r1
	ldrb r2, [r0]
	ldr r0, _080BB984 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	blt _080BB9B4
	ldr r5, _080BB988 @ =0x00001409
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BB990
	adds r0, r1, #0
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, r2
	beq _080BBA14
	ldr r2, _080BB98C @ =0x0000140B
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080BBA14
	movs r4, #5
	b _080BBA14
	.align 2, 0
_080BB97C: .4byte 0x0000140C
_080BB980: .4byte 0x0000140E
_080BB984: .4byte 0x030046A0
_080BB988: .4byte 0x00001409
_080BB98C: .4byte 0x0000140B
_080BB990:
	ldr r4, _080BB9AC @ =0x0000140B
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, r2
	bne _080BB9B0
	adds r0, r1, #0
	adds r0, #0x5c
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r4, #5
	cmp r0, r2
	bne _080BBA14
	movs r4, #0
	b _080BBA14
	.align 2, 0
_080BB9AC: .4byte 0x0000140B
_080BB9B0:
	movs r4, #1
	b _080BBA14
_080BB9B4:
	ldr r2, _080BB9D0 @ =0x0000140B
	adds r0, r3, r2
	ldrb r2, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r4, #0xa8
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	mvns r0, r0
	lsrs r4, r0, #0x1f
	b _080BBA14
	.align 2, 0
_080BB9D0: .4byte 0x0000140B
_080BB9D4:
	ldr r0, _080BB9E8 @ =0x0000140B
	adds r2, r3, r0
	ldr r5, _080BB9EC @ =0x0000140E
	adds r1, r3, r5
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BB9F0
	movs r4, #4
	b _080BBA14
	.align 2, 0
_080BB9E8: .4byte 0x0000140B
_080BB9EC: .4byte 0x0000140E
_080BB9F0:
	ldr r1, _080BBA24 @ =0x00001409
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BBA14
	ldrb r2, [r2]
	ldr r0, _080BBA28 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	asrs r4, r0, #0x1f
	movs r0, #4
	ands r4, r0
_080BBA14:
	cmp r4, #4
	beq _080BBA32
	cmp r4, #4
	bgt _080BBA2C
	cmp r4, #1
	beq _080BBA5C
	b _080BBA70
	.align 2, 0
_080BBA24: .4byte 0x00001409
_080BBA28: .4byte 0x030046A0
_080BBA2C:
	cmp r4, #5
	beq _080BBA48
	b _080BBA70
_080BBA32:
	ldr r5, _080BBA44 @ =0x00001438
	adds r0, r3, r5
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #7
	bl FUN_080b98c0
	b _080BBA7E
	.align 2, 0
_080BBA44: .4byte 0x00001438
_080BBA48:
	ldr r1, _080BBA58 @ =0x00001438
	adds r0, r3, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #6
	bl FUN_080b98c0
	b _080BBA7E
	.align 2, 0
_080BBA58: .4byte 0x00001438
_080BBA5C:
	ldr r2, _080BBA6C @ =0x00001438
	adds r0, r3, r2
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080BBA7E
	.align 2, 0
_080BBA6C: .4byte 0x00001438
_080BBA70:
	ldr r4, _080BBA84 @ =0x00001438
	adds r0, r3, r4
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080BBA7E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BBA84: .4byte 0x00001438

	thumb_func_start FUN_080bba88
FUN_080bba88: @ 0x080BBA88
	push {r4, lr}
	adds r2, r0, #0
	ldr r1, _080BBAD8 @ =0x0000140C
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BBB34
	ldr r3, _080BBADC @ =0x0000140E
	adds r0, r2, r3
	ldrb r3, [r0]
	ldr r0, _080BBAE0 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r4, #0xa8
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	blt _080BBB14
	ldr r4, _080BBAE4 @ =0x00001409
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BBAEC
	adds r0, r1, #0
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, r3
	beq _080BBBA4
	ldr r3, _080BBAE8 @ =0x0000140B
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080BBBA4
	movs r0, #5
	b _080BBBA6
	.align 2, 0
_080BBAD8: .4byte 0x0000140C
_080BBADC: .4byte 0x0000140E
_080BBAE0: .4byte 0x030046A0
_080BBAE4: .4byte 0x00001409
_080BBAE8: .4byte 0x0000140B
_080BBAEC:
	ldr r0, _080BBB0C @ =0x0000140B
	adds r4, r2, r0
	ldrb r0, [r4]
	cmp r0, r3
	bne _080BBB2C
	ldr r1, _080BBB10 @ =0x0000140F
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080BBBA4
	movs r0, #0x22
	strb r0, [r4]
	movs r0, #5
	b _080BBBA6
	.align 2, 0
_080BBB0C: .4byte 0x0000140B
_080BBB10: .4byte 0x0000140F
_080BBB14:
	ldr r3, _080BBB30 @ =0x0000140B
	adds r0, r2, r3
	ldrb r2, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r4, #0xa8
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080BBBA4
_080BBB2C:
	movs r0, #1
	b _080BBBA6
	.align 2, 0
_080BBB30: .4byte 0x0000140B
_080BBB34:
	ldr r4, _080BBB64 @ =0x0000140B
	adds r3, r2, r4
	ldr r0, _080BBB68 @ =0x0000140E
	adds r1, r2, r0
	ldrb r0, [r3]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BBB74
	ldr r1, _080BBB6C @ =0x000012F2
	adds r0, r2, r1
	ldrh r1, [r0]
	strb r1, [r3]
	movs r0, #3
	ands r0, r1
	subs r4, #2
	adds r1, r2, r4
	strb r0, [r1]
	ldrb r0, [r3]
	lsrs r0, r0, #2
	ldr r3, _080BBB70 @ =0x0000140A
	adds r1, r2, r3
	strb r0, [r1]
	movs r0, #4
	b _080BBBA6
	.align 2, 0
_080BBB64: .4byte 0x0000140B
_080BBB68: .4byte 0x0000140E
_080BBB6C: .4byte 0x000012F2
_080BBB70: .4byte 0x0000140A
_080BBB74:
	ldr r4, _080BBB9C @ =0x00001409
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BBBA4
	ldrb r2, [r3]
	ldr r0, _080BBBA0 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bge _080BBBA4
	movs r0, #4
	b _080BBBA6
	.align 2, 0
_080BBB9C: .4byte 0x00001409
_080BBBA0: .4byte 0x030046A0
_080BBBA4:
	movs r0, #0
_080BBBA6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080bbbac
FUN_080bbbac: @ 0x080BBBAC
	push {lr}
	movs r2, #0
	ldr r0, _080BBBC8 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r1, r0, r3
_080BBBBA:
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bge _080BBBCC
	adds r0, r2, #0
	b _080BBBD8
	.align 2, 0
_080BBBC8: .4byte 0x030046A0
_080BBBCC:
	adds r1, #2
	adds r2, #1
	cmp r2, #0xf
	ble _080BBBBA
	movs r0, #1
	rsbs r0, r0, #0
_080BBBD8:
	pop {r1}
	bx r1

	thumb_func_start FUN_080bbbdc
FUN_080bbbdc: @ 0x080BBBDC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xda
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	subs r1, #3
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_080bbbac
	ldr r2, _080BBC50 @ =0x000012F2
	adds r1, r5, r2
	strh r0, [r1]
	ldr r0, _080BBC54 @ =0x00001408
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r2, _080BBC58 @ =0x00000D98
	adds r1, r5, r2
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #0x14
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FUN_080bb294
	adds r0, r5, #0
	bl FUN_080bb388
	adds r0, r5, #0
	bl FUN_080bb5bc
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bb8f4
	ldr r1, _080BBC5C @ =FUN_080bbc60
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080ba054
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BBC50: .4byte 0x000012F2
_080BBC54: .4byte 0x00001408
_080BBC58: .4byte 0x00000D98
_080BBC5C: .4byte FUN_080bbc60

	thumb_func_start FUN_080bbc60
FUN_080bbc60: @ 0x080BBC60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _080BBCCC @ =0x00001408
	adds r6, r5, r0
	ldr r1, _080BBCD0 @ =0x00000C78
	adds r2, r5, r1
	ldr r0, _080BBCD4 @ =0x00000C18
	adds r3, r5, r0
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080b95d0
	ldr r7, _080BBCD8 @ =0x030044E0
	ldrh r1, [r7]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080BBCE4
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba048
	ldr r1, _080BBCDC @ =0x00000D98
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldrh r1, [r7, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BBCAC
	b _080BBEE2
_080BBCAC:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r2, _080BBCE0 @ =0x0000151A
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080BBCC6
	b _080BBEE2
_080BBCC6:
	movs r0, #0
	strb r0, [r1]
	b _080BBEE2
	.align 2, 0
_080BBCCC: .4byte 0x00001408
_080BBCD0: .4byte 0x00000C78
_080BBCD4: .4byte 0x00000C18
_080BBCD8: .4byte 0x030044E0
_080BBCDC: .4byte 0x00000D98
_080BBCE0: .4byte 0x0000151A
_080BBCE4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ba048
	ldr r3, _080BBD50 @ =0x00000D98
	adds r4, r5, r3
	movs r0, #0x18
	adds r0, r0, r5
	mov r8, r0
	adds r0, r4, #0
	mov r1, r8
	bl FUN_082372cc
	ldrh r1, [r7, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BBD0A
	b _080BBEBC
_080BBD0A:
	ldr r1, _080BBD54 @ =0x0000140B
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #0x21
	bne _080BBD70
	ldr r0, _080BBD58 @ =0x00000107
	bl PlaySound_082406e0
	ldr r2, _080BBD5C @ =0x000012E4
	adds r0, r5, r2
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl FUN_080ba07c
	ldr r3, _080BBD60 @ =0x00001278
	adds r0, r5, r3
	ldr r1, _080BBD64 @ =0x000012EF
	adds r2, r5, r1
	mov r1, r8
	movs r3, #1
	bl FUN_080b9740
	ldr r2, _080BBD68 @ =0x00001438
	adds r0, r5, r2
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080BBD6C @ =FUN_080bc07c
	b _080BBEAE
	.align 2, 0
_080BBD50: .4byte 0x00000D98
_080BBD54: .4byte 0x0000140B
_080BBD58: .4byte 0x00000107
_080BBD5C: .4byte 0x000012E4
_080BBD60: .4byte 0x00001278
_080BBD64: .4byte 0x000012EF
_080BBD68: .4byte 0x00001438
_080BBD6C: .4byte FUN_080bc07c
_080BBD70:
	ldr r3, _080BBDC4 @ =0x00001409
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #3
	bls _080BBE18
	movs r7, #1
	ldrb r0, [r4]
	adds r0, r5, r0
	ldr r1, _080BBDC8 @ =0x000012F4
	adds r0, r0, r1
	movs r3, #0
	ldrsb r3, [r0, r3]
	cmp r3, #0
	blt _080BBDBA
	ldr r0, _080BBDCC @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r1, r1, r2
	ldr r2, _080BBDD0 @ =0x08DAA7B0
	lsls r0, r3, #3
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r2, #6
	ldrsh r0, [r0, r2]
	cmp r1, r0
	blt _080BBDBA
	ldr r3, _080BBDD4 @ =0x000012F2
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _080BBDB6
	movs r7, #0
_080BBDB6:
	cmp r7, #0
	bne _080BBDD8
_080BBDBA:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BBEE2
	.align 2, 0
_080BBDC4: .4byte 0x00001409
_080BBDC8: .4byte 0x000012F4
_080BBDCC: .4byte 0x030046A0
_080BBDD0: .4byte 0x08DAA7B0
_080BBDD4: .4byte 0x000012F2
_080BBDD8:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_080b9fd8
	movs r3, #0xe0
	lsls r3, r3, #4
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080BBE10 @ =0x00000E18
	adds r2, r5, r0
	ldr r1, _080BBE14 @ =0x00000DB8
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r6, #0
	movs r1, #0x3c
	bl FUN_080b9d94
	b _080BBEA4
	.align 2, 0
_080BBE10: .4byte 0x00000E18
_080BBE14: .4byte 0x00000DB8
_080BBE18:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_080b9fd8
	movs r3, #0xe0
	lsls r3, r3, #4
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080BBE88 @ =0x00000E18
	adds r2, r5, r0
	ldr r1, _080BBE8C @ =0x00000DB8
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldrb r2, [r4]
	ldr r0, _080BBE90 @ =0x030046A0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x5c
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r2, r0
	beq _080BBE7A
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	blt _080BBE7A
	ldr r0, _080BBE94 @ =0x08DAA7B0
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r3, #6
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne _080BBE9C
_080BBE7A:
	ldr r1, _080BBE98 @ =0x00001408
	adds r0, r5, r1
	movs r1, #0x1e
	bl FUN_080b9d94
	b _080BBEA4
	.align 2, 0
_080BBE88: .4byte 0x00000E18
_080BBE8C: .4byte 0x00000DB8
_080BBE90: .4byte 0x030046A0
_080BBE94: .4byte 0x08DAA7B0
_080BBE98: .4byte 0x00001408
_080BBE9C:
	adds r0, r6, #0
	movs r1, #0xe
	bl FUN_080b9d94
_080BBEA4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bb8f4
	ldr r1, _080BBEB8 @ =FUN_080bbeec
_080BBEAE:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BBEE2
	.align 2, 0
_080BBEB8: .4byte FUN_080bbeec
_080BBEBC:
	adds r0, r6, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080BBEE2
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080bb294
	adds r0, r5, #0
	bl FUN_080bb5bc
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bb8f4
_080BBEE2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bbeec
FUN_080bbeec: @ 0x080BBEEC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080BBF24 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BBEFE
	b _080BC00A
_080BBEFE:
	adds r0, r5, #0
	bl FUN_080bba88
	adds r4, r0, #0
	ldr r1, _080BBF28 @ =0x00001438
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	cmp r4, #4
	beq _080BBF48
	cmp r4, #4
	bgt _080BBF2C
	cmp r4, #1
	beq _080BBF32
	b _080BC000
	.align 2, 0
_080BBF24: .4byte 0x030044E0
_080BBF28: .4byte 0x00001438
_080BBF2C:
	cmp r4, #5
	beq _080BBF9C
	b _080BC000
_080BBF32:
	adds r0, r5, #0
	bl FUN_080bb688
	ldr r1, _080BBF44 @ =0x080BC0E9
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BC01E
	.align 2, 0
_080BBF44: .4byte 0x080BC0E9
_080BBF48:
	ldr r0, _080BBF84 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BBF88 @ =0x000012E8
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r1, _080BBF8C @ =0x0000140E
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r1, _080BBF90 @ =0x000012F4
	adds r0, r0, r1
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba07c
	ldr r1, _080BBF94 @ =0x00001278
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x77
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080BBF98 @ =FUN_080bc11c
	b _080BBFDE
	.align 2, 0
_080BBF84: .4byte 0x00000107
_080BBF88: .4byte 0x000012E8
_080BBF8C: .4byte 0x0000140E
_080BBF90: .4byte 0x000012F4
_080BBF94: .4byte 0x00001278
_080BBF98: .4byte FUN_080bc11c
_080BBF9C:
	ldr r0, _080BBFE8 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BBFEC @ =0x000012E8
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r1, _080BBFF0 @ =0x0000140E
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r1, _080BBFF4 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r3, [r0, r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ba07c
	ldr r1, _080BBFF8 @ =0x00001278
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x77
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080BBFFC @ =FUN_080bc1ec
_080BBFDE:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BC04E
	.align 2, 0
_080BBFE8: .4byte 0x00000107
_080BBFEC: .4byte 0x000012E8
_080BBFF0: .4byte 0x0000140E
_080BBFF4: .4byte 0x030046A0
_080BBFF8: .4byte 0x00001278
_080BBFFC: .4byte FUN_080bc1ec
_080BC000:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BC01E
_080BC00A:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BC024
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080bbbdc
_080BC01E:
	adds r4, r5, #0
	adds r4, #0x18
	b _080BC04E
_080BC024:
	ldr r0, _080BC070 @ =0x00001408
	adds r6, r5, r0
	adds r0, r6, #0
	bl FUN_080b9f70
	adds r4, r5, #0
	adds r4, #0x18
	cmp r0, #0
	beq _080BC04E
	ldr r0, _080BC074 @ =0x00000D98
	adds r1, r5, r0
	adds r0, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080bb294
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bb8f4
_080BC04E:
	ldr r1, _080BC070 @ =0x00001408
	adds r0, r5, r1
	ldr r1, _080BC078 @ =0x00000C78
	adds r2, r5, r1
	subs r1, #0x60
	adds r3, r5, r1
	movs r1, #0
	bl FUN_080b95d0
	ldr r1, _080BC074 @ =0x00000D98
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_082372cc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BC070: .4byte 0x00001408
_080BC074: .4byte 0x00000D98
_080BC078: .4byte 0x00000C78

	thumb_func_start FUN_080bc07c
FUN_080bc07c: @ 0x080BC07C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BC0BC @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BC0C0 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BC0D0
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortArmors
	ldr r1, _080BC0C4 @ =0x0000140C
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080BC0C8 @ =0x0000140D
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080BC0CC @ =0x0000140E
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080bbbdc
	b _080BC0E0
	.align 2, 0
_080BC0BC: .4byte 0x00001278
_080BC0C0: .4byte 0x000012EF
_080BC0C4: .4byte 0x0000140C
_080BC0C8: .4byte 0x0000140D
_080BC0CC: .4byte 0x0000140E
_080BC0D0:
	cmp r0, #0
	bne _080BC0E0
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bbbdc
_080BC0E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BC0E8:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x09, 0x49, 0x60, 0x18
	.byte 0xFD, 0xF7, 0xF4, 0xFC, 0x00, 0x28, 0x0A, 0xD0, 0x07, 0x4A, 0xA0, 0x18, 0x00, 0x78, 0x03, 0x3A
	.byte 0xA1, 0x18, 0x09, 0x78, 0x87, 0xF1, 0xBE, 0xF8, 0x20, 0x1C, 0xFF, 0xF7, 0x67, 0xFD, 0x10, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47, 0x14, 0x13, 0x00, 0x00, 0x0E, 0x14, 0x00, 0x00

	thumb_func_start FUN_080bc11c
FUN_080bc11c: @ 0x080BC11C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BC14C @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BC150 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BC158
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080bb854
	ldr r1, _080BC154 @ =0x080BC171
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BC168
	.align 2, 0
_080BC14C: .4byte 0x00001278
_080BC150: .4byte 0x000012EF
_080BC154: .4byte 0x080BC171
_080BC158:
	cmp r0, #0
	bne _080BC168
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bbbdc
_080BC168:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BC170:
	.byte 0x30, 0xB5, 0x05, 0x1C, 0x16, 0x49, 0x68, 0x18, 0xFD, 0xF7, 0xB0, 0xFC, 0x00, 0x28, 0x24, 0xD0
	.byte 0x14, 0x4A, 0xA8, 0x18, 0x00, 0x78, 0x03, 0x32, 0xA9, 0x18, 0x0C, 0x78, 0x2C, 0x19, 0x12, 0x49
	.byte 0x64, 0x18, 0x00, 0x21, 0x61, 0x56, 0x87, 0xF1, 0x47, 0xF8, 0x10, 0x48, 0x02, 0x68, 0x91, 0x20
	.byte 0x00, 0x01, 0x12, 0x18, 0x0E, 0x49, 0x00, 0x20, 0x20, 0x56, 0xC0, 0x00, 0x40, 0x18, 0x11, 0x88
	.byte 0xC0, 0x88, 0x09, 0x1A, 0x11, 0x80, 0x0B, 0x4A, 0xA9, 0x18, 0x01, 0x20, 0x08, 0x70, 0x0A, 0x48
	.byte 0x84, 0xF1, 0x8E, 0xFA, 0x28, 0x1C, 0xFF, 0xF7, 0x09, 0xFD, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.byte 0x14, 0x13, 0x00, 0x00, 0x0B, 0x14, 0x00, 0x00, 0xF4, 0x12, 0x00, 0x00, 0xA0, 0x46, 0x00, 0x03
	.byte 0xB0, 0xA7, 0xDA, 0x08, 0x1B, 0x15, 0x00, 0x00, 0x11, 0x01, 0x00, 0x00

	thumb_func_start FUN_080bc1ec
FUN_080bc1ec: @ 0x080BC1EC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BC21C @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BC220 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BC228
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080bb798
	ldr r1, _080BC224 @ =0x080BC241
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BC238
	.align 2, 0
_080BC21C: .4byte 0x00001278
_080BC220: .4byte 0x000012EF
_080BC224: .4byte 0x080BC241
_080BC228:
	cmp r0, #0
	bne _080BC238
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bbbdc
_080BC238:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BC240:
	.byte 0x70, 0xB5, 0x04, 0x1C, 0x1D, 0x49, 0x60, 0x18, 0xFD, 0xF7, 0x48, 0xFC, 0x00, 0x28, 0x32, 0xD0
	.byte 0x1B, 0x4A, 0xA0, 0x18, 0x06, 0x78, 0x1B, 0x4A, 0x1B, 0x4D, 0x29, 0x68, 0x70, 0x00, 0x40, 0x18
	.byte 0xA8, 0x21, 0x49, 0x00, 0x40, 0x18, 0x00, 0x21, 0x40, 0x5E, 0xC0, 0x00, 0x80, 0x18, 0x06, 0x22
	.byte 0x81, 0x5E, 0x32, 0x20, 0x48, 0x43, 0x64, 0x21, 0x8F, 0xF1, 0xA0, 0xFF, 0x2A, 0x68, 0x91, 0x21
	.byte 0x09, 0x01, 0x52, 0x18, 0x11, 0x88, 0x09, 0x18, 0x11, 0x80, 0x09, 0x04, 0x09, 0x14, 0x0F, 0x4A
	.byte 0x91, 0x42, 0x04, 0xDD, 0x28, 0x68, 0x91, 0x21, 0x09, 0x01, 0x40, 0x18, 0x02, 0x80, 0x30, 0x1C
	.byte 0x86, 0xF1, 0xE2, 0xFF, 0x0A, 0x4A, 0xA0, 0x18, 0x01, 0x21, 0x01, 0x70, 0x09, 0x49, 0x20, 0x1C
	.byte 0x00, 0x22, 0xFD, 0xF7, 0xCF, 0xFE, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x14, 0x13, 0x00, 0x00
	.byte 0x0E, 0x14, 0x00, 0x00, 0xB0, 0xA7, 0xDA, 0x08, 0xA0, 0x46, 0x00, 0x03, 0x0F, 0x27, 0x00, 0x00
	.byte 0x1C, 0x15, 0x00, 0x00, 0xD9, 0xC2, 0x0B, 0x08

	thumb_func_start FUN_080bc2d8
FUN_080bc2d8: @ 0x080BC2D8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080BC30C @ =0x000012F0
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080BC2EC
	ldr r0, _080BC310 @ =0x00000276
	bl PlaySound_082406e0
_080BC2EC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	bhi _080BC330
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BC318
	ldr r2, _080BC314 @ =0x00000C3A
	adds r1, r5, r2
	b _080BC338
	.align 2, 0
_080BC30C: .4byte 0x000012F0
_080BC310: .4byte 0x00000276
_080BC314: .4byte 0x00000C3A
_080BC318:
	ldrh r1, [r4]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x20
	subs r1, r1, r0
	ldr r2, _080BC32C @ =0x00000C3A
	adds r0, r5, r2
	strh r1, [r0]
	b _080BC34A
	.align 2, 0
_080BC32C: .4byte 0x00000C3A
_080BC330:
	cmp r1, #0xf
	bhi _080BC344
	ldr r0, _080BC340 @ =0x00000C3A
	adds r1, r5, r0
_080BC338:
	movs r0, #0x20
	strh r0, [r1]
	b _080BC34A
	.align 2, 0
_080BC340: .4byte 0x00000C3A
_080BC344:
	adds r0, r5, #0
	bl FUN_080bbbdc
_080BC34A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bc350
FUN_080bc350: @ 0x080BC350
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _080BC3E4 @ =0x000012ED
	adds r1, r4, r0
	movs r5, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080bbbac
	ldr r2, _080BC3E8 @ =0x000012F2
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _080BC3EC @ =0x000012D8
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #2
	bl FUN_0822c398
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r2, _080BC3F0 @ =0x0000151A
	adds r5, r4, r2
	ldrb r0, [r5]
	bl FUN_080b94cc
	ldrb r0, [r5]
	bl FUN_080b9400
	ldr r0, _080BC3F4 @ =0x00001408
	adds r5, r4, r0
	movs r0, #0x14
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #4
	movs r3, #0
	bl FUN_080b9ff8
	ldr r2, _080BC3F8 @ =0x00000D98
	adds r1, r4, r2
	adds r0, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080bb388
	adds r0, r4, #0
	bl FUN_080bb5bc
	adds r0, r4, #0
	bl FUN_080bb294
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080bb8f4
	ldr r1, _080BC3FC @ =FUN_080bbc60
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080ba054
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BC3E4: .4byte 0x000012ED
_080BC3E8: .4byte 0x000012F2
_080BC3EC: .4byte 0x000012D8
_080BC3F0: .4byte 0x0000151A
_080BC3F4: .4byte 0x00001408
_080BC3F8: .4byte 0x00000D98
_080BC3FC: .4byte FUN_080bbc60

	thumb_func_start FUN_080bc400
FUN_080bc400: @ 0x080BC400
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080BC450 @ =0x0000C091
	ldr r1, _080BC454 @ =0x00009F57
	bl GetFile
	adds r2, r0, #0
	ldr r0, _080BC458 @ =0x000012D8
	adds r4, r4, r0
	str r2, [r4]
	movs r5, #0
	str r5, [sp, #0xc]
	str r5, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	ldr r1, [r4]
	movs r0, #0
	movs r2, #2
	bl FUN_0822c398
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BC450: .4byte 0x0000C091
_080BC454: .4byte 0x00009F57
_080BC458: .4byte 0x000012D8

	thumb_func_start FUN_080bc45c
FUN_080bc45c: @ 0x080BC45C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080BC484 @ =0x000092B3
	ldr r1, _080BC488 @ =0x0000A41A
	bl GetFile
	ldr r1, _080BC48C @ =0x000012DC
	adds r4, r4, r1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, _080BC490 @ =0x030043F0
	ldr r2, _080BC494 @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BC484: .4byte 0x000092B3
_080BC488: .4byte 0x0000A41A
_080BC48C: .4byte 0x000012DC
_080BC490: .4byte 0x030043F0
_080BC494: .4byte 0x04000018

	thumb_func_start FUN_080bc498
FUN_080bc498: @ 0x080BC498
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r4, _080BC598 @ =0x0000CB05
	ldr r1, _080BC59C @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x38
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080BC5A0 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x18
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	adds r0, r7, #0
	adds r0, #0x18
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080BC5A4 @ =0x0000414C
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x58
	ldm r0!, {r4, r5, r6}
	stm r1!, {r4, r5, r6}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	adds r5, r7, #0
	adds r5, #0x58
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080BC5A8 @ =0xFFFF0000
	movs r6, #0
	str r6, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	ldr r4, _080BC5AC @ =0x000012EC
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #1
	bne _080BC5B4
	ldr r0, _080BC5B0 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r4, #0x31
	mov r8, r4
	cmp r0, #5
	beq _080BC548
	movs r0, #0x30
	mov r8, r0
_080BC548:
	adds r0, r7, #0
	adds r0, #0x78
	str r1, [sp]
	str r1, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x25
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r0, r7, #0
	adds r0, #0xd8
	str r6, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x23
	mov r3, r8
	bl FUN_0822f3fc
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r0, r7, r3
	str r6, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x24
	mov r3, r8
	bl FUN_0822f3fc
	b _080BC600
	.align 2, 0
_080BC598: .4byte 0x0000CB05
_080BC59C: .4byte 0x00005D04
_080BC5A0: .4byte 0x0000B343
_080BC5A4: .4byte 0x0000414C
_080BC5A8: .4byte 0xFFFF0000
_080BC5AC: .4byte 0x000012EC
_080BC5B0: .4byte 0x030046A0
_080BC5B4:
	adds r0, r7, #0
	adds r0, #0x78
	str r1, [sp]
	str r1, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x26
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r0, r7, #0
	adds r0, #0xd8
	str r6, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x23
	movs r3, #0x31
	bl FUN_0822f3fc
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r0, r7, r3
	str r6, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x24
	movs r3, #0x31
	bl FUN_0822f3fc
_080BC600:
	movs r4, #0
	movs r5, #0x38
	adds r5, r5, r7
	mov sb, r5
	adds r6, r7, #0
	adds r6, #0x18
	str r6, [sp, #0x18]
	adds r0, r7, #0
	adds r0, #0x58
	str r0, [sp, #0x1c]
	add r6, sp, #0x10
	mov r8, r4
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r5, r7, r1
_080BC61E:
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r6, #2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r6]
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sb
	movs r2, #0x68
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xf
	ble _080BC61E
	movs r4, #0
	add r6, sp, #0x10
	mov r8, r4
	movs r3, #0xf3
	lsls r3, r3, #3
	adds r5, r7, r3
_080BC664:
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r6, #2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r6]
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0x3c
	mov sl, r1
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sb
	movs r2, #0x68
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xb
	ble _080BC664
	ldr r2, _080BC894 @ =0x00000D38
	adds r0, r7, r2
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	add r6, sp, #0x10
	str r6, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x41
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	movs r0, #0x80
	strh r0, [r6, #2]
	ldr r5, _080BC898 @ =0x00000CD8
	adds r0, r7, r5
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sb
	movs r2, #0xd0
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0x78
	add r0, sp, #0x10
	strh r1, [r0]
	movs r5, #0x68
	strh r5, [r6, #2]
	ldr r3, _080BC89C @ =0x00000C78
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sb
	movs r2, #0xcb
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r5, [r0]
	movs r3, #0x20
	mov r8, r3
	mov r5, r8
	strh r5, [r6, #2]
	ldr r0, _080BC8A0 @ =0x00000C18
	adds r5, r7, r0
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sb
	movs r2, #0xcc
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r5, #0
	bl FUN_080b95bc
	ldr r3, _080BC8A4 @ =0x00000DF8
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r5, sl
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x3c
	movs r3, #0x31
	bl FUN_0822f3fc
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	mov r2, r8
	strh r2, [r6, #2]
	ldr r3, _080BC8A8 @ =0x00000D98
	adds r5, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r6, sl
	str r6, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x39
	movs r3, #0x30
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _080BC8AC @ =0x00000E58
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0x18
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0xb
	add r1, sp, #0x10
	strh r0, [r1]
	adds r6, r1, #0
	ldr r3, _080BC8B0 @ =0x00000EB8
	adds r5, r7, r3
	mov r8, r4
	movs r4, #3
_080BC7AC:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0x19
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #6
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BC7AC
	movs r1, #0x30
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x68
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r1, _080BC8B4 @ =0x00001038
	adds r5, r7, r1
	movs r2, #0
	mov r8, r2
	movs r4, #2
_080BC7EA:
	mov r3, r8
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BC7EA
	movs r1, #0x30
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x70
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r4, _080BC8B8 @ =0x00001158
	adds r5, r7, r4
	movs r0, #0
	mov r8, r0
	movs r4, #2
_080BC828:
	mov r1, r8
	str r1, [sp]
	str r1, [sp, #4]
	movs r2, #0x3c
	mov sb, r2
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BC828
	movs r1, #0
	add r0, sp, #0x10
	strh r1, [r0]
	strh r1, [r0, #2]
	ldr r3, _080BC8BC @ =0x00001278
	adds r0, r7, r3
	str r1, [sp]
	str r1, [sp, #4]
	mov r4, sb
	str r4, [sp, #8]
	add r5, sp, #0x10
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x94
	movs r3, #0x11
	bl FUN_0822f3fc
	ldr r6, _080BC8C0 @ =0x00001314
	adds r0, r7, r6
	bl FUN_080b99a0
	ldr r1, _080BC8C4 @ =0x00001438
	adds r0, r7, r1
	bl FUN_080b9814
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BC894: .4byte 0x00000D38
_080BC898: .4byte 0x00000CD8
_080BC89C: .4byte 0x00000C78
_080BC8A0: .4byte 0x00000C18
_080BC8A4: .4byte 0x00000DF8
_080BC8A8: .4byte 0x00000D98
_080BC8AC: .4byte 0x00000E58
_080BC8B0: .4byte 0x00000EB8
_080BC8B4: .4byte 0x00001038
_080BC8B8: .4byte 0x00001158
_080BC8BC: .4byte 0x00001278
_080BC8C0: .4byte 0x00001314
_080BC8C4: .4byte 0x00001438

	thumb_func_start FUN_080bc8c8
FUN_080bc8c8: @ 0x080BC8C8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080BC8E2
	bl FUN_0823d340
	movs r2, #0x97
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
_080BC8E2:
	bl FUN_08049f5c
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	ldr r0, _080BC904 @ =0x0000A41A
	bl FUN_08047dc0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BC904: .4byte 0x0000A41A

	thumb_func_start FUN_080bc908
FUN_080bc908: @ 0x080BC908
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x49
	bl prepare_08231510
	cmp r0, #0
	beq _080BC91E
	bl Script_GetValue
	adds r5, r0, #0
	b _080BC920
_080BC91E:
	movs r5, #0
_080BC920:
	movs r0, #0x54
	bl prepare_08231510
	cmp r0, #0
	beq _080BC96C
	movs r4, #0
	cmp r4, r5
	bge _080BC942
	ldr r0, _080BC988 @ =0x000012F4
	adds r6, r7, r0
_080BC934:
	bl Script_GetValue
	adds r1, r6, r4
	strb r0, [r1]
	adds r4, #1
	cmp r4, r5
	blt _080BC934
_080BC942:
	cmp r4, #0xb
	bgt _080BC95A
	ldr r0, _080BC988 @ =0x000012F4
	adds r2, r7, r0
	movs r3, #0xff
_080BC94C:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #0xb
	ble _080BC94C
_080BC95A:
	ldr r2, _080BC98C @ =0x000012FC
	adds r1, r7, r2
	movs r4, #3
_080BC960:
	ldrb r0, [r1]
	strb r0, [r1, #4]
	adds r1, #1
	subs r4, #1
	cmp r4, #0
	bge _080BC960
_080BC96C:
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _080BC980
	bl FUN_0823d340
	ldr r2, _080BC990 @ =0x000012E4
	adds r1, r7, r2
	str r0, [r1]
_080BC980:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BC988: .4byte 0x000012F4
_080BC98C: .4byte 0x000012FC
_080BC990: .4byte 0x000012E4

	thumb_func_start FUN_080bc994
FUN_080bc994: @ 0x080BC994
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _080BC9AA
	bl Script_GetValue
	adds r5, r0, #0
	b _080BC9AC
_080BC9AA:
	movs r5, #0
_080BC9AC:
	movs r0, #0x52
	bl prepare_08231510
	cmp r0, #0
	beq _080BC9F8
	movs r4, #0
	cmp r4, r5
	bge _080BC9CE
	ldr r0, _080BCA14 @ =0x00001304
	adds r6, r7, r0
_080BC9C0:
	bl Script_GetValue
	adds r1, r6, r4
	strb r0, [r1]
	adds r4, #1
	cmp r4, r5
	blt _080BC9C0
_080BC9CE:
	cmp r4, #0xb
	bgt _080BC9E6
	ldr r0, _080BCA14 @ =0x00001304
	adds r2, r7, r0
	movs r3, #0xff
_080BC9D8:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #0xb
	ble _080BC9D8
_080BC9E6:
	ldr r2, _080BCA18 @ =0x0000130C
	adds r1, r7, r2
	movs r4, #3
_080BC9EC:
	ldrb r0, [r1]
	strb r0, [r1, #4]
	adds r1, #1
	subs r4, #1
	cmp r4, #0
	bge _080BC9EC
_080BC9F8:
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _080BCA0C
	bl FUN_0823d340
	ldr r2, _080BCA1C @ =0x000012E8
	adds r1, r7, r2
	str r0, [r1]
_080BCA0C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BCA14: .4byte 0x00001304
_080BCA18: .4byte 0x0000130C
_080BCA1C: .4byte 0x000012E8

	thumb_func_start FUN_080bca20
FUN_080bca20: @ 0x080BCA20
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x65
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080BCA40
	bl Script_GetValue
	ldr r2, _080BCA3C @ =0x00001534
	adds r1, r4, r2
	str r0, [r1]
	b _080BCA46
	.align 2, 0
_080BCA3C: .4byte 0x00001534
_080BCA40:
	ldr r2, _080BCA4C @ =0x00001534
	adds r0, r4, r2
	str r1, [r0]
_080BCA46:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BCA4C: .4byte 0x00001534

	thumb_func_start FUN_080bca50
FUN_080bca50: @ 0x080BCA50
	push {lr}
	adds r2, r0, #0
	ldr r0, _080BCA74 @ =0x000012F0
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BCA6E
	ldr r1, _080BCA78 @ =FUN_080bca7c
	adds r0, r2, #0
	bl FUN_080ba030
_080BCA6E:
	pop {r0}
	bx r0
	.align 2, 0
_080BCA74: .4byte 0x000012F0
_080BCA78: .4byte FUN_080bca7c

	thumb_func_start FUN_080bca7c
FUN_080bca7c: @ 0x080BCA7C
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080BCAD8 @ =0x000012EE
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _080BCA8E
	b _080BCBB8
_080BCA8E:
	subs r1, #2
	adds r0, r4, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _080BCB5C
	ldr r0, _080BCADC @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #5
	beq _080BCB5C
	ldr r1, _080BCAE0 @ =0x0000151D
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1d
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080BCAE4
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	b _080BCAFC
	.align 2, 0
_080BCAD8: .4byte 0x000012EE
_080BCADC: .4byte 0x030046A0
_080BCAE0: .4byte 0x0000151D
_080BCAE4:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
_080BCAFC:
	str r0, [r1]
	ldr r0, _080BCB28 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r5, #0xc0
	lsls r5, r5, #2
	ands r5, r1
	cmp r5, #0
	beq _080BCB38
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080BCB2C @ =0x000012ED
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080BCB30
	adds r0, r4, #0
	bl FUN_080bc350
	b _080BCBD6
	.align 2, 0
_080BCB28: .4byte 0x030044E0
_080BCB2C: .4byte 0x000012ED
_080BCB30:
	adds r0, r4, #0
	bl FUN_080bb160
	b _080BCBD6
_080BCB38:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BCBD6
	ldr r0, _080BCB54 @ =0x00000119
	bl PlaySound_082406e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BCB58 @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	b _080BCB92
	.align 2, 0
_080BCB54: .4byte 0x00000119
_080BCB58: .4byte 0x0000FFFF
_080BCB5C:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080BCBA8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BCBD6
	ldr r0, _080BCBAC @ =0x00000119
	bl PlaySound_082406e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BCBB0 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
_080BCB92:
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080BCBB4 @ =FUN_080bcbf4
	adds r0, r4, #0
	bl FUN_080ba030
	b _080BCBE2
	.align 2, 0
_080BCBA8: .4byte 0x030044E0
_080BCBAC: .4byte 0x00000119
_080BCBB0: .4byte 0x0000FFFF
_080BCBB4: .4byte FUN_080bcbf4
_080BCBB8:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080BCBEC @ =0x0000151D
	adds r0, r4, r1
	strb r3, [r0]
_080BCBD6:
	ldr r1, _080BCBF0 @ =0x0000153C
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080BCBE2:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BCBEC: .4byte 0x0000151D
_080BCBF0: .4byte 0x0000153C

	thumb_func_start FUN_080bcbf4
FUN_080bcbf4: @ 0x080BCBF4
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080BCC4C @ =0x000012F0
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BCC44
	ldr r1, _080BCC50 @ =0x00001534
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080BCC3E
	ldr r1, _080BCC54 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	ldr r1, _080BCC58 @ =0x0000151B
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp, #4]
	add r1, sp, #8
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_080BCC3E:
	adds r0, r4, #0
	bl KillEntity
_080BCC44:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BCC4C: .4byte 0x000012F0
_080BCC50: .4byte 0x00001534
_080BCC54: .4byte 0xFFFF0000
_080BCC58: .4byte 0x0000151B

	thumb_func_start FUN_080bcc5c
FUN_080bcc5c: @ 0x080BCC5C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080BCC84 @ =0x0000151A
	adds r5, r4, r0
	ldrb r0, [r5]
	bl FUN_080b94cc
	ldrb r0, [r5]
	bl FUN_080b9400
	ldr r1, _080BCC88 @ =0x00001538
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080BCC84: .4byte 0x0000151A
_080BCC88: .4byte 0x00001538

	thumb_func_start FUN_080bcc8c
FUN_080bcc8c: @ 0x080BCC8C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x78
	movs r5, #0x30
_080BCC96:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BCC96
	ldr r1, _080BCCBC @ =0x00001314
	adds r0, r6, r1
	bl FUN_080b9a0c
	ldr r1, _080BCCC0 @ =0x00001438
	adds r0, r6, r1
	bl FUN_080b9894
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BCCBC: .4byte 0x00001314
_080BCCC0: .4byte 0x00001438

	thumb_func_start FUN_080bccc4
FUN_080bccc4: @ 0x080BCCC4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _080BCD44 @ =0x000012EC
	adds r4, r5, r0
	movs r6, #0
	strb r1, [r4]
	adds r0, r5, #0
	bl FUN_080bc908
	ldrb r0, [r4]
	cmp r0, #1
	bne _080BCCE4
	adds r0, r5, #0
	bl FUN_080bc994
_080BCCE4:
	adds r0, r5, #0
	bl FUN_080bc400
	adds r0, r5, #0
	bl FUN_080bc45c
	adds r0, r5, #0
	bl FUN_080bc498
	adds r0, r5, #0
	bl FUN_080bc8c8
	adds r0, r5, #0
	bl FUN_080bca20
	ldr r1, _080BCD48 @ =0x0000151B
	adds r0, r5, r1
	strb r6, [r0]
	adds r1, #1
	adds r0, r5, r1
	strb r6, [r0]
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BCD4C @ =0x0000FFFF
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r5, #0
	bl FUN_080bb160
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080BCD50 @ =FUN_080bca50
	adds r0, r5, #0
	bl FUN_080ba030
	movs r0, #0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BCD44: .4byte 0x000012EC
_080BCD48: .4byte 0x0000151B
_080BCD4C: .4byte 0x0000FFFF
_080BCD50: .4byte FUN_080bca50
_080BCD54:
	.byte 0x10, 0xB5, 0xAA, 0x21, 0x49, 0x01, 0x0B, 0x20, 0x73, 0xF1, 0x28, 0xFF
	.byte 0x04, 0x1C, 0x00, 0x2C, 0x12, 0xD0, 0x07, 0x49, 0x07, 0x4A, 0x73, 0xF1, 0x45, 0xFF, 0x20, 0x1C
	.byte 0x00, 0x21, 0xFF, 0xF7, 0xA7, 0xFF, 0x00, 0x28, 0x08, 0xDA, 0x20, 0x1C, 0x73, 0xF1, 0x76, 0xFF
	.byte 0x00, 0x20, 0x04, 0xE0, 0x5D, 0xCC, 0x0B, 0x08, 0x8D, 0xCC, 0x0B, 0x08, 0x20, 0x1C, 0x10, 0xBC
	.byte 0x02, 0xBC, 0x08, 0x47, 0x10, 0xB5, 0xAA, 0x21, 0x49, 0x01, 0x0B, 0x20, 0x73, 0xF1, 0x08, 0xFF
	.byte 0x04, 0x1C, 0x00, 0x2C, 0x12, 0xD0, 0x07, 0x49, 0x07, 0x4A, 0x73, 0xF1, 0x25, 0xFF, 0x20, 0x1C
	.byte 0x01, 0x21, 0xFF, 0xF7, 0x87, 0xFF, 0x00, 0x28, 0x08, 0xDA, 0x20, 0x1C, 0x73, 0xF1, 0x56, 0xFF
	.byte 0x00, 0x20, 0x04, 0xE0, 0x5D, 0xCC, 0x0B, 0x08, 0x8D, 0xCC, 0x0B, 0x08, 0x20, 0x1C, 0x10, 0xBC
	.byte 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080bcdd4
FUN_080bcdd4: @ 0x080BCDD4
	ldr r3, _080BCDE4 @ =0x00001898
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080BCDE8 @ =0x0000168E
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080BCDE4: .4byte 0x00001898
_080BCDE8: .4byte 0x0000168E

	thumb_func_start FUN_080bcdec
FUN_080bcdec: @ 0x080BCDEC
	ldr r2, _080BCDF4 @ =0x00001655
	adds r0, r0, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
_080BCDF4: .4byte 0x00001655

	thumb_func_start FUN_080bcdf8
FUN_080bcdf8: @ 0x080BCDF8
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _080BCE18 @ =0x0000189C
	adds r0, r4, r3
	str r1, [r0]
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080bcdec
	ldr r0, _080BCE1C @ =0x0000168E
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BCE18: .4byte 0x0000189C
_080BCE1C: .4byte 0x0000168E

	thumb_func_start FUN_080bce20
FUN_080bce20: @ 0x080BCE20
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_08049e5c
	movs r0, #0xce
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xb2
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r5, #0
	bl FUN_08047a28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bce64
FUN_080bce64: @ 0x080BCE64
	push {r4, r5, lr}
	bl GetWeapon
	adds r5, r0, #0
	ldr r2, _080BCE84 @ =0x08DA9E68
	ldrb r1, [r5]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r2, [r0, #0xa]
	cmp r2, #0
	bne _080BCE88
	movs r0, #0
	b _080BCECE
	.align 2, 0
_080BCE84: .4byte 0x08DA9E68
_080BCE88:
	movs r3, #0
	adds r1, r5, #0
	movs r4, #2
_080BCE8E:
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	beq _080BCE96
	adds r3, #1
_080BCE96:
	adds r1, #4
	subs r4, #1
	cmp r4, #0
	bge _080BCE8E
	cmp r3, #0
	bne _080BCEB2
	movs r0, #1
	ldrsb r0, [r5, r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	adds r1, #0x32
	adds r0, r2, #0
	muls r0, r1, r0
	b _080BCEBC
_080BCEB2:
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, #0x64
	muls r0, r2, r0
_080BCEBC:
	movs r1, #0x64
	bl Div
	adds r2, r0, #0
	cmp r2, #0
	ble _080BCECC
	adds r0, r2, #0
	b _080BCECE
_080BCECC:
	movs r0, #1
_080BCECE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080bced4
FUN_080bced4: @ 0x080BCED4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0x64
	bl Div
	str r0, [r5]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [r5, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [r5, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bcf04
FUN_080bcf04: @ 0x080BCF04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	mov sl, r0
	str r1, [sp, #0x30]
	ldrb r0, [r1, #1]
	cmp r0, #1
	beq _080BCF34
	cmp r0, #1
	bgt _080BCF24
	cmp r0, #0
	beq _080BCF2E
	b _080BCF44
_080BCF24:
	cmp r0, #2
	beq _080BCF38
	cmp r0, #4
	beq _080BCF3E
	b _080BCF44
_080BCF2E:
	movs r0, #0
	str r0, [sp, #0x34]
	b _080BCF4A
_080BCF34:
	movs r1, #1
	b _080BCF48
_080BCF38:
	movs r2, #2
	str r2, [sp, #0x34]
	b _080BCF4A
_080BCF3E:
	movs r0, #3
	str r0, [sp, #0x34]
	b _080BCF4A
_080BCF44:
	movs r1, #1
	rsbs r1, r1, #0
_080BCF48:
	str r1, [sp, #0x34]
_080BCF4A:
	movs r6, #0
	mov r2, sp
	adds r2, #0xc
	str r2, [sp, #0x3c]
	mov r0, sl
	adds r0, #0x18
	str r0, [sp, #0x38]
_080BCF58:
	adds r0, r6, #0
	ldr r1, [sp, #0x3c]
	bl FUN_08242b28
	ldr r0, [sp, #0x3c]
	bl FUN_0807a6cc
	adds r4, r0, #0
	ldr r1, [sp, #0x34]
	cmp r6, r1
	beq _080BCFAC
	mov r1, sp
	bl FUN_080bced4
	movs r7, #0
	lsls r1, r6, #1
	adds r2, r6, #1
	mov sb, r2
	movs r0, #0
	mov r8, r0
	mov r5, sp
	adds r0, r6, #0
	adds r0, #0x28
	adds r4, r1, r0
_080BCF88:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #5
	adds r0, #0x78
	add r0, sl
	ldm r5!, {r2}
	add r2, r8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, [sp, #0x38]
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #1
	adds r7, #1
	cmp r7, #2
	ble _080BCF88
	b _080BD006
_080BCFAC:
	ldr r0, [sp, #0x30]
	bl FUN_0807a6cc
	movs r5, #0
	cmp r0, r4
	beq _080BCFC0
	movs r5, #2
	cmp r0, r4
	ble _080BCFC0
	movs r5, #1
_080BCFC0:
	mov r1, sp
	bl FUN_080bced4
	movs r7, #0
	lsls r1, r6, #1
	lsls r0, r5, #2
	adds r2, r6, #1
	mov sb, r2
	adds r0, r0, r5
	lsls r5, r0, #1
	mov r8, sp
	adds r0, r6, #0
	adds r0, #0x28
	adds r4, r1, r0
_080BCFDC:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #5
	adds r0, #0x78
	add r0, sl
	mov r1, r8
	adds r1, #4
	mov r8, r1
	subs r1, #4
	ldm r1!, {r2}
	adds r2, r2, r5
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, [sp, #0x38]
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #1
	adds r7, #1
	cmp r7, #2
	ble _080BCFDC
_080BD006:
	mov r6, sb
	cmp r6, #3
	ble _080BCF58
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bd01c
FUN_080bd01c: @ 0x080BD01C
	push {r4, r5, lr}
	adds r5, r1, #0
	movs r1, #0
	ldr r2, _080BD054 @ =0x00001648
	adds r0, r0, r2
	ldr r3, [r0]
	ldrb r2, [r3]
	cmp r2, #0
	beq _080BD044
	adds r4, r5, #0
	adds r4, #0xc
_080BD032:
	adds r0, r4, r1
	strb r2, [r0]
	adds r3, #1
	adds r1, #1
	ldrb r2, [r3]
	cmp r2, #0
	beq _080BD044
	cmp r1, #0xa
	ble _080BD032
_080BD044:
	adds r0, r5, #0
	adds r0, #0xc
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BD054: .4byte 0x00001648

	thumb_func_start FUN_080bd058
FUN_080bd058: @ 0x080BD058
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	ldr r1, _080BD078 @ =0x00001785
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD080
	ldr r2, _080BD07C @ =0x00001787
	adds r0, r6, r2
	ldrb r0, [r0]
	mov r1, sp
	bl FUN_08242b14
	b _080BD0E8
	.align 2, 0
_080BD078: .4byte 0x00001785
_080BD07C: .4byte 0x00001787
_080BD080:
	cmp r0, #7
	bhi _080BD0D8
	ldr r2, _080BD0C8 @ =0x08DA9E68
	ldr r3, _080BD0CC @ =0x00001787
	adds r1, r6, r3
	ldr r4, _080BD0D0 @ =0x00001654
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #4
	subs r0, #0x10
	ldrb r1, [r1]
	adds r0, r0, r1
	ldr r3, _080BD0D4 @ =0x0000165C
	adds r1, r6, r3
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, sp
	adds r1, r1, r2
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	mov r1, sp
	movs r0, #0
	strb r0, [r1, #0x18]
	adds r0, r6, #0
	bl FUN_080bd01c
	b _080BD0E8
	.align 2, 0
_080BD0C8: .4byte 0x08DA9E68
_080BD0CC: .4byte 0x00001787
_080BD0D0: .4byte 0x00001654
_080BD0D4: .4byte 0x0000165C
_080BD0D8:
	mov r1, sp
	ldr r0, _080BD108 @ =0x08DA9E68
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
_080BD0E8:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _080BD10C
	movs r4, #0xce
	lsls r4, r4, #4
	adds r0, r6, r4
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _080BD162
	.align 2, 0
_080BD108: .4byte 0x08DA9E68
_080BD10C:
	movs r0, #0xce
	lsls r0, r0, #4
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BD174 @ =0x00000CD8
	adds r4, r6, r1
	adds r5, r6, #0
	adds r5, #0x38
	mov r0, sp
	bl FUN_08094e70
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _080BD178 @ =0x00001644
	adds r4, r6, r2
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r3, _080BD17C @ =0x0000164C
	adds r1, r6, r3
	mov r0, sp
	bl FUN_08094d1c
	ldr r1, [r4]
	mov r0, sp
	bl FUN_08094d48
_080BD162:
	adds r0, r6, #0
	mov r1, sp
	bl FUN_080bcf04
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BD174: .4byte 0x00000CD8
_080BD178: .4byte 0x00001644
_080BD17C: .4byte 0x0000164C

	thumb_func_start FUN_080bd180
FUN_080bd180: @ 0x080BD180
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	movs r0, #0
	mov sl, r0
	mov r1, r8
	adds r1, #0x80
	str r1, [sp, #8]
	movs r2, #0
	str r2, [sp, #0xc]
_080BD19C:
	movs r0, #0
	str r0, [sp]
	mov r1, sl
	lsls r1, r1, #2
	mov sb, r1
	movs r0, #0xcc
	lsls r0, r0, #1
	add r0, r8
	ldr r2, [sp, #0xc]
	adds r7, r2, r0
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #8]
	adds r6, r0, r1
_080BD1BC:
	ldr r5, [sp]
	add r5, sb
	adds r0, r5, #0
	bl GetWeaponID
	adds r4, r0, #0
	cmp r4, #0
	ble _080BD1E8
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	adds r0, r7, #0
	mov r1, r8
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080BD1F0
_080BD1E8:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
_080BD1F0:
	adds r0, r5, #0
	bl FUN_082430d4
	cmp r0, #0
	bne _080BD204
	adds r0, r5, #0
	bl FUN_080bce64
	cmp r0, #0
	bne _080BD210
_080BD204:
	adds r0, r7, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BD218
_080BD210:
	adds r0, r7, #0
	ldr r1, _080BD2D8 @ =0x000002DF
	bl FUN_080b95bc
_080BD218:
	adds r7, #0x60
	adds r6, #0x60
	ldr r2, [sp]
	adds r2, #1
	str r2, [sp]
	cmp r2, #3
	ble _080BD1BC
	ldr r0, [sp, #0xc]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #0xc]
	movs r2, #1
	add sl, r2
	mov r0, sl
	cmp r0, #3
	ble _080BD19C
	movs r1, #0
	mov sl, r1
_080BD23E:
	movs r2, #0
	str r2, [sp]
	mov r0, sl
	lsls r0, r0, #2
	mov sb, r0
	mov r1, sl
	adds r1, #1
	str r1, [sp, #4]
	mov r2, sb
	adds r2, #0x13
	mov r1, sl
	lsls r0, r1, #3
	add r0, sb
	lsls r0, r0, #5
	movs r1, #0xf3
	lsls r1, r1, #3
	add r1, r8
	adds r7, r0, r1
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r2, [sp, #8]
	adds r6, r0, r2
_080BD26C:
	ldr r5, [sp]
	add r5, sb
	ldr r0, _080BD2DC @ =0x00001654
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r5, r0
	ldr r1, _080BD2E0 @ =0x0000165C
	add r1, r8
	adds r1, r1, r0
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080BD2E4 @ =0x08DA9E68
	adds r0, r0, r1
	ldrb r4, [r0]
	cmp r4, #0
	ble _080BD2FC
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r0, r7, #0
	mov r1, r8
	adds r1, #0x38
	adds r2, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _080BD2E8 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #2
	ldr r2, _080BD2E4 @ =0x08DA9E68
	adds r0, r0, r2
	ldrh r0, [r0, #0xa]
	cmp r1, r0
	bge _080BD2EC
	adds r0, r7, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BD304
	.align 2, 0
_080BD2D8: .4byte 0x000002DF
_080BD2DC: .4byte 0x00001654
_080BD2E0: .4byte 0x0000165C
_080BD2E4: .4byte 0x08DA9E68
_080BD2E8: .4byte 0x030046A0
_080BD2EC:
	adds r0, r7, #0
	ldr r1, _080BD2F8 @ =0x000002DF
	bl FUN_080b95bc
	b _080BD304
	.align 2, 0
_080BD2F8: .4byte 0x000002DF
_080BD2FC:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
_080BD304:
	adds r6, #0x60
	adds r7, #0x60
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	cmp r0, #3
	ble _080BD26C
	ldr r1, [sp, #4]
	mov sl, r1
	cmp r1, #2
	ble _080BD23E
	ldr r0, _080BD344 @ =0x030046A0
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #0x60
	ldr r5, _080BD348 @ =0x00000D58
	add r5, r8
	ldr r0, [sp, #8]
	movs r1, #0xcc
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r6, #3
_080BD330:
	ldrh r3, [r4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _080BD34C
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _080BD374
	.align 2, 0
_080BD344: .4byte 0x030046A0
_080BD348: .4byte 0x00000D58
_080BD34C:
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #3
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r5]
	ldrh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x12
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r5, #2]
_080BD374:
	adds r4, #2
	adds r5, #0x60
	adds r2, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080BD330
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bd390
FUN_080bd390: @ 0x080BD390
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r1, _080BD3B8 @ =0x00001785
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD3C0
	ldr r2, _080BD3BC @ =0x00001787
	adds r4, r6, r2
	ldrb r0, [r4]
	bl GetWeaponID
	adds r5, r0, #0
	ldrb r0, [r4]
	bl FUN_080bce64
	adds r4, r0, #0
	movs r7, #1
	b _080BD402
	.align 2, 0
_080BD3B8: .4byte 0x00001785
_080BD3BC: .4byte 0x00001787
_080BD3C0:
	cmp r0, #7
	bhi _080BD3FC
	ldr r0, _080BD3F0 @ =0x00001787
	adds r1, r6, r0
	ldr r2, _080BD3F4 @ =0x00001654
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #4
	subs r0, #0x10
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r2, #8
	adds r1, r6, r2
	adds r1, r1, r0
	movs r5, #0
	ldrsb r5, [r1, r5]
	ldr r1, _080BD3F8 @ =0x08DA9E68
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r4, [r0, #0xa]
	b _080BD400
	.align 2, 0
_080BD3F0: .4byte 0x00001787
_080BD3F4: .4byte 0x00001654
_080BD3F8: .4byte 0x08DA9E68
_080BD3FC:
	movs r5, #0
	movs r4, #0
_080BD400:
	movs r7, #0
_080BD402:
	cmp r5, #0
	ble _080BD434
	cmp r4, #0
	ble _080BD434
	ldr r1, _080BD42C @ =0x00001787
	adds r0, r6, r1
	ldrb r1, [r0]
	add r0, sp, #4
	bl FUN_080b9938
	adds r0, r6, #0
	adds r0, #0x58
	ldr r2, _080BD430 @ =0x000013F8
	adds r1, r6, r2
	str r7, [sp]
	add r2, sp, #4
	adds r3, r4, #0
	bl FUN_080b9658
	b _080BD43C
	.align 2, 0
_080BD42C: .4byte 0x00001787
_080BD430: .4byte 0x000013F8
_080BD434:
	ldr r1, _080BD444 @ =0x000013F8
	adds r0, r6, r1
	bl FUN_080b9724
_080BD43C:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BD444: .4byte 0x000013F8

	thumb_func_start FUN_080bd448
FUN_080bd448: @ 0x080BD448
	push {r4, lr}
	adds r3, r0, #0
	movs r2, #0
	ldr r0, _080BD464 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x60
_080BD456:
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, r3
	bne _080BD468
	adds r0, r2, #0
	b _080BD474
	.align 2, 0
_080BD464: .4byte 0x030046A0
_080BD468:
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _080BD456
	movs r0, #1
	rsbs r0, r0, #0
_080BD474:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080bd47c
FUN_080bd47c: @ 0x080BD47C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	mov r8, r0
	movs r7, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x4c]
	add r1, sp, #0x34
	mov sl, r1
	mov r2, sp
	adds r2, #0x3c
	str r2, [sp, #0x44]
	subs r0, #0x10
	str r0, [sp, #0x48]
	str r2, [sp, #0x50]
	str r1, [sp, #0x54]
	ldr r2, [sp, #0x4c]
	mov sb, r2
_080BD4A8:
	cmp r7, #0
	bne _080BD4B4
	ldr r0, _080BD4B0 @ =0x0000178A
	b _080BD4B6
	.align 2, 0
_080BD4B0: .4byte 0x0000178A
_080BD4B4:
	ldr r0, _080BD4FC @ =0x00001787
_080BD4B6:
	add r0, r8
	ldrb r4, [r0]
	adds r0, r4, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	mov r5, r8
	adds r5, #0x80
	adds r1, r5, r1
	ldr r0, [r1]
	movs r6, #1
	orrs r0, r6
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080bd448
	cmp r0, #0
	blt _080BD4EA
	adds r0, #0x22
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r1, r5, r1
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
_080BD4EA:
	adds r0, r4, #0
	bl GetWeaponID
	adds r1, r0, #0
	cmp r1, #0
	ble _080BD500
	mov r0, sb
	str r6, [r0]
	b _080BD506
	.align 2, 0
_080BD4FC: .4byte 0x00001787
_080BD500:
	movs r0, #0
	mov r2, sb
	str r0, [r2]
_080BD506:
	ldr r0, [sp, #0x54]
	stm r0!, {r1}
	str r0, [sp, #0x54]
	ldr r0, _080BD570 @ =0x000002DF
	ldr r1, [sp, #0x50]
	stm r1!, {r0}
	str r1, [sp, #0x50]
	lsls r0, r7, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r4, #0
	bl FUN_080b9938
	movs r2, #4
	add sb, r2
	adds r7, #1
	cmp r7, #1
	ble _080BD4A8
	add r2, sp, #0x14
	ldr r3, [sp, #0x48]
	movs r7, #1
_080BD530:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r7, #1
	cmp r7, #0
	bge _080BD530
	ldr r0, _080BD574 @ =0x00001690
	add r0, r8
	mov r1, sl
	str r1, [sp]
	ldr r2, [sp, #0x44]
	str r2, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x4c]
	add r2, sp, #0xc
	ldr r3, [sp, #0x48]
	bl FUN_080b9a28
	ldr r0, _080BD578 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BD570: .4byte 0x000002DF
_080BD574: .4byte 0x00001690
_080BD578: .4byte 0x0000038A

	thumb_func_start FUN_080bd57c
FUN_080bd57c: @ 0x080BD57C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r3, #1
	str r3, [sp, #0x2c]
	ldr r0, _080BD610 @ =0x0000178A
	adds r4, r5, r0
	ldrb r0, [r4]
	adds r0, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r5, #0
	adds r2, #0x80
	adds r2, r2, r1
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldrb r0, [r4]
	bl GetWeaponID
	str r0, [sp, #0x34]
	ldr r1, _080BD614 @ =0x000002DF
	mov r8, r1
	str r1, [sp, #0x3c]
	ldrb r1, [r4]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	ldr r1, _080BD618 @ =0x00001787
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b9938
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
	ldr r0, _080BD61C @ =0x00001690
	adds r5, r5, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080BD620 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BD610: .4byte 0x0000178A
_080BD614: .4byte 0x000002DF
_080BD618: .4byte 0x00001787
_080BD61C: .4byte 0x00001690
_080BD620: .4byte 0x0000038A

	thumb_func_start FUN_080bd624
FUN_080bd624: @ 0x080BD624
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r4, r0, #0
	movs r0, #1
	str r0, [sp, #0x2c]
	ldr r0, _080BD6B4 @ =0x0000178A
	adds r2, r4, r0
	ldr r1, _080BD6B8 @ =0x00001654
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #4
	subs r0, #0x10
	ldrb r3, [r2]
	adds r0, r0, r3
	ldr r3, _080BD6BC @ =0x0000165C
	adds r1, r4, r3
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	str r0, [sp, #0x34]
	ldr r0, _080BD6C0 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r2]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r5, sp, #0x1c
	ldr r1, _080BD6C4 @ =0x00001787
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_080b9938
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
	strh r2, [r5, #8]
	strh r2, [r5, #0xa]
	strh r2, [r5, #0xc]
	ldr r0, _080BD6C8 @ =0x00001690
	adds r4, r4, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r4, #0
	add r2, sp, #0xc
	adds r3, r5, #0
	bl FUN_080b9a28
	ldr r0, _080BD6CC @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BD6B4: .4byte 0x0000178A
_080BD6B8: .4byte 0x00001654
_080BD6BC: .4byte 0x0000165C
_080BD6C0: .4byte 0x000002DF
_080BD6C4: .4byte 0x00001787
_080BD6C8: .4byte 0x00001690
_080BD6CC: .4byte 0x0000038A

	thumb_func_start FUN_080bd6d0
FUN_080bd6d0: @ 0x080BD6D0
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _080BD708
	ldr r1, _080BD6F0 @ =0x00001785
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BD6F4
	adds r1, #0x2f
	adds r0, r4, r1
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080BD832
	.align 2, 0
_080BD6F0: .4byte 0x00001785
_080BD6F4:
	ldr r1, _080BD704 @ =0x000017B4
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080BD832
	.align 2, 0
_080BD704: .4byte 0x000017B4
_080BD708:
	movs r6, #0
	ldr r1, _080BD750 @ =0x00001788
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD7A4
	ldr r0, _080BD754 @ =0x0000178A
	adds r7, r4, r0
	ldrb r5, [r7]
	adds r0, r5, #0
	bl GetWeaponID
	cmp r0, #0
	ble _080BD78C
	ldr r1, _080BD758 @ =0x00001785
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BD760
	adds r0, r5, #0
	bl FUN_080bd448
	cmp r0, #0
	bge _080BD7CA
	adds r0, r5, #0
	bl FUN_080bce64
	cmp r0, #0
	beq _080BD7CA
	ldr r1, _080BD75C @ =0x00001787
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080BD7CA
	movs r6, #5
	b _080BD7CA
	.align 2, 0
_080BD750: .4byte 0x00001788
_080BD754: .4byte 0x0000178A
_080BD758: .4byte 0x00001785
_080BD75C: .4byte 0x00001787
_080BD760:
	ldr r1, _080BD788 @ =0x00001787
	adds r0, r4, r1
	ldrb r0, [r0]
	ldrb r7, [r7]
	cmp r0, r7
	bne _080BD79A
	adds r0, r5, #0
	bl FUN_080bd448
	cmp r0, #0
	bge _080BD7CA
	adds r0, r5, #0
	bl FUN_080bce64
	movs r6, #5
	cmp r0, #0
	bne _080BD7CA
	movs r6, #0
	b _080BD7CA
	.align 2, 0
_080BD788: .4byte 0x00001787
_080BD78C:
	ldr r1, _080BD7A0 @ =0x00001787
	adds r0, r4, r1
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	ble _080BD7CA
_080BD79A:
	movs r6, #1
	b _080BD7CA
	.align 2, 0
_080BD7A0: .4byte 0x00001787
_080BD7A4:
	ldr r0, _080BD7D8 @ =0x00001787
	adds r2, r4, r0
	adds r0, #3
	adds r1, r4, r0
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080BD7C8
	ldr r1, _080BD7DC @ =0x00001785
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD7CA
	ldrb r0, [r2]
	bl GetWeaponID
	cmp r0, #0
	bne _080BD7CA
_080BD7C8:
	movs r6, #4
_080BD7CA:
	cmp r6, #4
	beq _080BD7E6
	cmp r6, #4
	bgt _080BD7E0
	cmp r6, #1
	beq _080BD810
	b _080BD824
	.align 2, 0
_080BD7D8: .4byte 0x00001787
_080BD7DC: .4byte 0x00001785
_080BD7E0:
	cmp r6, #5
	beq _080BD7FC
	b _080BD824
_080BD7E6:
	ldr r1, _080BD7F8 @ =0x000017B4
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #7
	bl FUN_080b98c0
	b _080BD832
	.align 2, 0
_080BD7F8: .4byte 0x000017B4
_080BD7FC:
	ldr r1, _080BD80C @ =0x000017B4
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #6
	bl FUN_080b98c0
	b _080BD832
	.align 2, 0
_080BD80C: .4byte 0x000017B4
_080BD810:
	ldr r1, _080BD820 @ =0x000017B4
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080BD832
	.align 2, 0
_080BD820: .4byte 0x000017B4
_080BD824:
	ldr r1, _080BD838 @ =0x000017B4
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080BD832:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BD838: .4byte 0x000017B4

	thumb_func_start FUN_080bd83c
FUN_080bd83c: @ 0x080BD83C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080BD888 @ =0x00001788
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD8DC
	ldr r2, _080BD88C @ =0x0000178A
	adds r6, r4, r2
	ldrb r5, [r6]
	adds r0, r5, #0
	bl GetWeaponID
	cmp r0, #0
	ble _080BD8C4
	ldr r3, _080BD890 @ =0x00001785
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BD898
	adds r0, r5, #0
	bl FUN_080bd448
	cmp r0, #0
	bge _080BD938
	adds r0, r5, #0
	bl FUN_080bce64
	cmp r0, #0
	beq _080BD938
	ldr r1, _080BD894 @ =0x00001787
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080BD938
	movs r0, #5
	b _080BD93A
	.align 2, 0
_080BD888: .4byte 0x00001788
_080BD88C: .4byte 0x0000178A
_080BD890: .4byte 0x00001785
_080BD894: .4byte 0x00001787
_080BD898:
	ldr r2, _080BD8C0 @ =0x00001787
	adds r4, r4, r2
	ldrb r0, [r4]
	ldrb r6, [r6]
	cmp r0, r6
	bne _080BD8D2
	adds r0, r5, #0
	bl FUN_080bd448
	cmp r0, #0
	bge _080BD938
	adds r0, r5, #0
	bl FUN_080bce64
	cmp r0, #0
	beq _080BD938
	movs r0, #0x22
	strb r0, [r4]
	movs r0, #5
	b _080BD93A
	.align 2, 0
_080BD8C0: .4byte 0x00001787
_080BD8C4:
	ldr r3, _080BD8D8 @ =0x00001787
	adds r0, r4, r3
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	ble _080BD938
_080BD8D2:
	movs r0, #1
	b _080BD93A
	.align 2, 0
_080BD8D8: .4byte 0x00001787
_080BD8DC:
	ldr r0, _080BD90C @ =0x00001787
	adds r2, r4, r0
	ldr r3, _080BD910 @ =0x0000178A
	adds r1, r4, r3
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BD91C
	ldr r1, _080BD914 @ =0x0000168C
	adds r0, r4, r1
	ldrh r1, [r0]
	strb r1, [r2]
	movs r0, #3
	ands r0, r1
	subs r3, #5
	adds r1, r4, r3
	strb r0, [r1]
	ldrb r0, [r2]
	lsrs r0, r0, #2
	ldr r2, _080BD918 @ =0x00001786
	adds r1, r4, r2
	strb r0, [r1]
	movs r0, #4
	b _080BD93A
	.align 2, 0
_080BD90C: .4byte 0x00001787
_080BD910: .4byte 0x0000178A
_080BD914: .4byte 0x0000168C
_080BD918: .4byte 0x00001786
_080BD91C:
	ldr r3, _080BD934 @ =0x00001785
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD938
	ldrb r0, [r2]
	bl GetWeaponID
	cmp r0, #0
	bne _080BD938
	movs r0, #4
	b _080BD93A
	.align 2, 0
_080BD934: .4byte 0x00001785
_080BD938:
	movs r0, #0
_080BD93A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080bd940
FUN_080bd940: @ 0x080BD940
	push {r4, lr}
	movs r4, #0
_080BD944:
	adds r0, r4, #0
	bl GetWeaponID
	cmp r0, #0
	bne _080BD952
	adds r0, r4, #0
	b _080BD95C
_080BD952:
	adds r4, #1
	cmp r4, #0xf
	ble _080BD944
	movs r0, #1
	rsbs r0, r0, #0
_080BD95C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080bd964
FUN_080bd964: @ 0x080BD964
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xec
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	subs r1, #3
	ands r0, r1
	str r0, [r2]
	ldr r2, _080BD9D8 @ =0x00001784
	adds r4, r5, r2
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r0, _080BD9DC @ =0x00000EB8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #0x14
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FUN_080bd940
	ldr r2, _080BD9E0 @ =0x0000168C
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080bd058
	adds r0, r5, #0
	bl FUN_080bd180
	adds r0, r5, #0
	bl FUN_080bd390
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bd6d0
	ldr r1, _080BD9E4 @ =FUN_080bd9e8
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080bcdf8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BD9D8: .4byte 0x00001784
_080BD9DC: .4byte 0x00000EB8
_080BD9E0: .4byte 0x0000168C
_080BD9E4: .4byte FUN_080bd9e8

	thumb_func_start FUN_080bd9e8
FUN_080bd9e8: @ 0x080BD9E8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _080BDA54 @ =0x00001784
	adds r7, r5, r0
	ldr r1, _080BDA58 @ =0x00000C78
	adds r2, r5, r1
	ldr r0, _080BDA5C @ =0x00000C18
	adds r3, r5, r0
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080b95d0
	ldr r6, _080BDA60 @ =0x030044E0
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080BDA6C
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bcdec
	ldr r1, _080BDA64 @ =0x00000EB8
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldrh r1, [r6, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BDA34
	b _080BDC5A
_080BDA34:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r2, _080BDA68 @ =0x00001657
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080BDA4E
	b _080BDC5A
_080BDA4E:
	movs r0, #0
	strb r0, [r1]
	b _080BDC5A
	.align 2, 0
_080BDA54: .4byte 0x00001784
_080BDA58: .4byte 0x00000C78
_080BDA5C: .4byte 0x00000C18
_080BDA60: .4byte 0x030044E0
_080BDA64: .4byte 0x00000EB8
_080BDA68: .4byte 0x00001657
_080BDA6C:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bcdec
	ldr r0, _080BDAD4 @ =0x00000EB8
	adds r4, r5, r0
	movs r1, #0x18
	adds r1, r1, r5
	mov r8, r1
	adds r0, r4, #0
	bl FUN_082372cc
	ldrh r1, [r6, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BDA90
	b _080BDC34
_080BDA90:
	ldr r2, _080BDAD8 @ =0x00001787
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0x21
	bne _080BDAF0
	ldr r0, _080BDADC @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BDAE0 @ =0x00001644
	adds r0, r5, r1
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl FUN_080bce20
	ldr r2, _080BDAE4 @ =0x000017B4
	adds r0, r5, r2
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080BDAE8 @ =0x000015D8
	adds r0, r5, r1
	adds r1, #0x7e
	adds r2, r5, r1
	mov r1, r8
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080BDAEC @ =FUN_080bddc0
	b _080BDC26
	.align 2, 0
_080BDAD4: .4byte 0x00000EB8
_080BDAD8: .4byte 0x00001787
_080BDADC: .4byte 0x00000107
_080BDAE0: .4byte 0x00001644
_080BDAE4: .4byte 0x000017B4
_080BDAE8: .4byte 0x000015D8
_080BDAEC: .4byte FUN_080bddc0
_080BDAF0:
	ldr r2, _080BDB54 @ =0x00001785
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #3
	bls _080BDBA8
	movs r6, #1
	ldr r1, _080BDB58 @ =0x00001654
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #4
	subs r0, #0x10
	ldrb r4, [r4]
	adds r0, r0, r4
	ldr r2, _080BDB5C @ =0x0000165C
	adds r1, r5, r2
	adds r1, r1, r0
	movs r3, #0
	ldrsb r3, [r1, r3]
	cmp r3, #0
	ble _080BDB48
	ldr r0, _080BDB60 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldr r1, _080BDB64 @ =0x08DA9E68
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0, #0xa]
	cmp r2, r0
	blt _080BDB48
	ldr r2, _080BDB68 @ =0x0000168C
	adds r0, r5, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _080BDB44
	movs r6, #0
_080BDB44:
	cmp r6, #0
	bne _080BDB6C
_080BDB48:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BDC5A
	.align 2, 0
_080BDB54: .4byte 0x00001785
_080BDB58: .4byte 0x00001654
_080BDB5C: .4byte 0x0000165C
_080BDB60: .4byte 0x030046A0
_080BDB64: .4byte 0x08DA9E68
_080BDB68: .4byte 0x0000168C
_080BDB6C:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r7, #0
	bl FUN_080b9fd8
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BDBA4 @ =0x00000F38
	adds r2, r5, r1
	subs r1, #0x60
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	movs r1, #0x3c
	bl FUN_080b9d94
	b _080BDC1C
	.align 2, 0
_080BDBA4: .4byte 0x00000F38
_080BDBA8:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r7, #0
	bl FUN_080b9fd8
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BDC08 @ =0x00000F38
	adds r2, r5, r1
	subs r1, #0x60
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldrb r4, [r4]
	adds r0, r4, #0
	bl GetWeaponID
	adds r6, r0, #0
	adds r0, r4, #0
	bl FUN_080bd448
	cmp r0, #0
	bge _080BDBFC
	cmp r6, #0
	ble _080BDBFC
	ldr r0, _080BDC0C @ =0x08DA9E68
	lsls r1, r6, #3
	adds r1, r1, r6
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r0, [r1, #0xa]
	cmp r0, #0
	bne _080BDC14
_080BDBFC:
	ldr r2, _080BDC10 @ =0x00001784
	adds r0, r5, r2
	movs r1, #0x1e
	bl FUN_080b9d94
	b _080BDC1C
	.align 2, 0
_080BDC08: .4byte 0x00000F38
_080BDC0C: .4byte 0x08DA9E68
_080BDC10: .4byte 0x00001784
_080BDC14:
	adds r0, r7, #0
	movs r1, #0xe
	bl FUN_080b9d94
_080BDC1C:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bd6d0
	ldr r1, _080BDC30 @ =FUN_080bdc64
_080BDC26:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080bcdf8
	b _080BDC5A
	.align 2, 0
_080BDC30: .4byte FUN_080bdc64
_080BDC34:
	adds r0, r7, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080BDC5A
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080bd058
	adds r0, r5, #0
	bl FUN_080bd390
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bd6d0
_080BDC5A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bdc64
FUN_080bdc64: @ 0x080BDC64
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080BDC98 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080BDD4E
	adds r0, r5, #0
	bl FUN_080bd83c
	adds r4, r0, #0
	ldr r1, _080BDC9C @ =0x000017B4
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	cmp r4, #4
	beq _080BDCBC
	cmp r4, #4
	bgt _080BDCA0
	cmp r4, #1
	beq _080BDCA6
	b _080BDD44
	.align 2, 0
_080BDC98: .4byte 0x030044E0
_080BDC9C: .4byte 0x000017B4
_080BDCA0:
	cmp r4, #5
	beq _080BDCFC
	b _080BDD44
_080BDCA6:
	adds r0, r5, #0
	bl FUN_080bd47c
	ldr r1, _080BDCB8 @ =0x080BDE2D
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080bcdf8
	b _080BDD62
	.align 2, 0
_080BDCB8: .4byte 0x080BDE2D
_080BDCBC:
	ldr r0, _080BDCEC @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BDCF0 @ =0x00001644
	adds r0, r5, r1
	ldr r2, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_080bce20
	ldr r1, _080BDCF4 @ =0x000015D8
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x7e
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080BDCF8 @ =FUN_080bde60
	b _080BDD28
	.align 2, 0
_080BDCEC: .4byte 0x00000107
_080BDCF0: .4byte 0x00001644
_080BDCF4: .4byte 0x000015D8
_080BDCF8: .4byte FUN_080bde60
_080BDCFC:
	ldr r0, _080BDD34 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BDD38 @ =0x00001644
	adds r0, r5, r1
	ldr r2, [r0]
	adds r0, r5, #0
	movs r1, #1
	movs r3, #0
	bl FUN_080bce20
	ldr r1, _080BDD3C @ =0x000015D8
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x7e
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080BDD40 @ =FUN_080bdf94
_080BDD28:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080bcdf8
	b _080BDD92
	.align 2, 0
_080BDD34: .4byte 0x00000107
_080BDD38: .4byte 0x00001644
_080BDD3C: .4byte 0x000015D8
_080BDD40: .4byte FUN_080bdf94
_080BDD44:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BDD62
_080BDD4E:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BDD68
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080bd964
_080BDD62:
	adds r4, r5, #0
	adds r4, #0x18
	b _080BDD92
_080BDD68:
	ldr r0, _080BDDB4 @ =0x00001784
	adds r6, r5, r0
	adds r0, r6, #0
	bl FUN_080b9f70
	adds r4, r5, #0
	adds r4, #0x18
	cmp r0, #0
	beq _080BDD92
	ldr r0, _080BDDB8 @ =0x00000EB8
	adds r1, r5, r0
	adds r0, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080bd058
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bd6d0
_080BDD92:
	ldr r1, _080BDDB4 @ =0x00001784
	adds r0, r5, r1
	ldr r1, _080BDDBC @ =0x00000C78
	adds r2, r5, r1
	subs r1, #0x60
	adds r3, r5, r1
	movs r1, #0
	bl FUN_080b95d0
	ldr r1, _080BDDB8 @ =0x00000EB8
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_082372cc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BDDB4: .4byte 0x00001784
_080BDDB8: .4byte 0x00000EB8
_080BDDBC: .4byte 0x00000C78

	thumb_func_start FUN_080bddc0
FUN_080bddc0: @ 0x080BDDC0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BDE00 @ =0x000015D8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BDE04 @ =0x00001656
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BDE14
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortWeapons
	ldr r1, _080BDE08 @ =0x00001788
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080BDE0C @ =0x00001789
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080BDE10 @ =0x0000178A
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080bd964
	b _080BDE24
	.align 2, 0
_080BDE00: .4byte 0x000015D8
_080BDE04: .4byte 0x00001656
_080BDE08: .4byte 0x00001788
_080BDE0C: .4byte 0x00001789
_080BDE10: .4byte 0x0000178A
_080BDE14:
	cmp r0, #0
	bne _080BDE24
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bd964
_080BDE24:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BDE2C:
	.byte 0x10, 0xB5, 0x04, 0x1C
	.byte 0x09, 0x49, 0x60, 0x18, 0xFB, 0xF7, 0x52, 0xFE, 0x00, 0x28, 0x0A, 0xD0, 0x07, 0x4A, 0xA0, 0x18
	.byte 0x00, 0x78, 0x03, 0x3A, 0xA1, 0x18, 0x09, 0x78, 0x84, 0xF1, 0xFC, 0xFE, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0x89, 0xFD, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x90, 0x16, 0x00, 0x00, 0x8A, 0x17, 0x00, 0x00

	thumb_func_start FUN_080bde60
FUN_080bde60: @ 0x080BDE60
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BDE90 @ =0x000015D8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BDE94 @ =0x00001656
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BDE9C
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080bd624
	ldr r1, _080BDE98 @ =0x080BDEB5
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080bcdf8
	b _080BDEAC
	.align 2, 0
_080BDE90: .4byte 0x000015D8
_080BDE94: .4byte 0x00001656
_080BDE98: .4byte 0x080BDEB5
_080BDE9C:
	cmp r0, #0
	bne _080BDEAC
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bd964
_080BDEAC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BDEB4:
	.byte 0xF0, 0xB5, 0x57, 0x46, 0x4E, 0x46, 0x45, 0x46, 0xE0, 0xB4, 0x89, 0xB0
	.byte 0x07, 0x1C, 0x2B, 0x49, 0x78, 0x18, 0xFB, 0xF7, 0x09, 0xFE, 0x00, 0x28, 0x48, 0xD0, 0x29, 0x4A
	.byte 0xB8, 0x18, 0x00, 0x78, 0x81, 0x46, 0x28, 0x4B, 0xF8, 0x18, 0x04, 0x78, 0x10, 0x3C, 0x27, 0x4E
	.byte 0xB0, 0x46, 0x27, 0x48, 0xC0, 0x19, 0x82, 0x46, 0x00, 0x78, 0x00, 0x01, 0x20, 0x18, 0x25, 0x49
	.byte 0x7D, 0x18, 0x28, 0x18, 0x00, 0x78, 0x00, 0x06, 0x00, 0x16, 0xC1, 0x00, 0x09, 0x18, 0x89, 0x00
	.byte 0x68, 0x46, 0x41, 0x44, 0x4C, 0xC9, 0x4C, 0xC0, 0x4C, 0xC9, 0x4C, 0xC0, 0x4C, 0xC9, 0x4C, 0xC0
	.byte 0x69, 0x46, 0x00, 0x20, 0x08, 0x76, 0x38, 0x1C, 0xFF, 0xF7, 0x80, 0xF8, 0x48, 0x46, 0x69, 0x46
	.byte 0x84, 0xF1, 0x24, 0xFE, 0x18, 0x48, 0x02, 0x68, 0x91, 0x20, 0x00, 0x01, 0x12, 0x18, 0x51, 0x46
	.byte 0x08, 0x78, 0x00, 0x01, 0x24, 0x18, 0x2D, 0x19, 0x00, 0x21, 0x69, 0x56, 0xC8, 0x00, 0x40, 0x18
	.byte 0x80, 0x00, 0x40, 0x44, 0x11, 0x88, 0x40, 0x89, 0x09, 0x1A, 0x11, 0x80, 0x0F, 0x4A, 0xB9, 0x18
	.byte 0x01, 0x20, 0x08, 0x70, 0x0E, 0x48, 0x82, 0xF1, 0xC3, 0xFB, 0x38, 0x1C, 0xFF, 0xF7, 0x02, 0xFD
	.byte 0x09, 0xB0, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.byte 0x90, 0x16, 0x00, 0x00, 0x87, 0x17, 0x00, 0x00, 0x8A, 0x17, 0x00, 0x00, 0x68, 0x9E, 0xDA, 0x08
	.byte 0x54, 0x16, 0x00, 0x00, 0x5C, 0x16, 0x00, 0x00, 0xA0, 0x46, 0x00, 0x03, 0x58, 0x16, 0x00, 0x00
	.byte 0x11, 0x01, 0x00, 0x00

	thumb_func_start FUN_080bdf94
FUN_080bdf94: @ 0x080BDF94
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BDFC4 @ =0x000015D8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BDFC8 @ =0x00001656
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BDFD0
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080bd57c
	ldr r1, _080BDFCC @ =0x080BDFE9
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080bcdf8
	b _080BDFE0
	.align 2, 0
_080BDFC4: .4byte 0x000015D8
_080BDFC8: .4byte 0x00001656
_080BDFCC: .4byte 0x080BDFE9
_080BDFD0:
	cmp r0, #0
	bne _080BDFE0
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bd964
_080BDFE0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BDFE8:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0x16, 0x49, 0x60, 0x18
	.byte 0xFB, 0xF7, 0x74, 0xFD, 0x00, 0x28, 0x23, 0xD0, 0x14, 0x49, 0x60, 0x18, 0x05, 0x78, 0x28, 0x1C
	.byte 0xFE, 0xF7, 0x30, 0xFF, 0x12, 0x4B, 0x1A, 0x68, 0x91, 0x21, 0x09, 0x01, 0x52, 0x18, 0x11, 0x88
	.byte 0x09, 0x18, 0x11, 0x80, 0x09, 0x04, 0x09, 0x14, 0x0E, 0x4A, 0x91, 0x42, 0x04, 0xDD, 0x18, 0x68
	.byte 0x91, 0x21, 0x09, 0x01, 0x40, 0x18, 0x02, 0x80, 0x28, 0x1C, 0x84, 0xF1, 0xED, 0xFD, 0x0A, 0x49
	.byte 0x60, 0x18, 0x01, 0x21, 0x01, 0x70, 0x09, 0x49, 0x20, 0x1C, 0x00, 0x22, 0xFE, 0xF7, 0xDC, 0xFE
	.byte 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x90, 0x16, 0x00, 0x00, 0x8A, 0x17, 0x00, 0x00
	.byte 0xA0, 0x46, 0x00, 0x03, 0x0F, 0x27, 0x00, 0x00, 0x59, 0x16, 0x00, 0x00, 0x61, 0xE0, 0x0B, 0x08

	thumb_func_start FUN_080be060
FUN_080be060: @ 0x080BE060
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080BE094 @ =0x0000168E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080BE074
	ldr r0, _080BE098 @ =0x00000276
	bl PlaySound_082406e0
_080BE074:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	bhi _080BE0B8
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BE0A0
	ldr r2, _080BE09C @ =0x00000C3A
	adds r1, r5, r2
	b _080BE0C0
	.align 2, 0
_080BE094: .4byte 0x0000168E
_080BE098: .4byte 0x00000276
_080BE09C: .4byte 0x00000C3A
_080BE0A0:
	ldrh r1, [r4]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x20
	subs r1, r1, r0
	ldr r2, _080BE0B4 @ =0x00000C3A
	adds r0, r5, r2
	strh r1, [r0]
	b _080BE0D2
	.align 2, 0
_080BE0B4: .4byte 0x00000C3A
_080BE0B8:
	cmp r1, #0xf
	bhi _080BE0CC
	ldr r0, _080BE0C8 @ =0x00000C3A
	adds r1, r5, r0
_080BE0C0:
	movs r0, #0x20
	strh r0, [r1]
	b _080BE0D2
	.align 2, 0
_080BE0C8: .4byte 0x00000C3A
_080BE0CC:
	adds r0, r5, #0
	bl FUN_080bd964
_080BE0D2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080be0d8
FUN_080be0d8: @ 0x080BE0D8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _080BE134 @ =0x00001784
	adds r5, r4, r0
	movs r0, #0x14
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #4
	movs r3, #0
	bl FUN_080b9ff8
	ldr r2, _080BE138 @ =0x00000EB8
	adds r1, r4, r2
	adds r0, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080bd940
	ldr r2, _080BE13C @ =0x0000168C
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080bd180
	adds r0, r4, #0
	bl FUN_080bd390
	adds r0, r4, #0
	bl FUN_080bd058
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080bd6d0
	ldr r1, _080BE140 @ =FUN_080bd9e8
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080bcdf8
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BE134: .4byte 0x00001784
_080BE138: .4byte 0x00000EB8
_080BE13C: .4byte 0x0000168C
_080BE140: .4byte FUN_080bd9e8

	thumb_func_start FUN_080be144
FUN_080be144: @ 0x080BE144
	push {r4, r5, lr}
	sub sp, #0x34
	adds r4, r0, #0
	ldr r0, _080BE1B0 @ =0x0000C091
	ldr r1, _080BE1B4 @ =0x00009F57
	bl GetFile
	adds r2, r0, #0
	ldr r0, _080BE1B8 @ =0x00001638
	adds r4, r4, r0
	str r2, [r4]
	movs r5, #0
	str r5, [sp, #0x30]
	str r5, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0x30
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	ldr r1, [r4]
	movs r0, #0
	movs r2, #4
	bl FUN_0822c398
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #3
	add r1, sp, #0xc
	bl FUN_08242b28
	add r0, sp, #0xc
	ldrb r0, [r0, #1]
	cmp r0, #4
	bne _080BE1A8
	ldr r0, _080BE1BC @ =0x03003ED0
	ldr r0, [r0, #0x2c]
	ldr r1, _080BE1C0 @ =0x00000392
	adds r0, r0, r1
	ldr r2, _080BE1C4 @ =0x0000F06E
	adds r1, r2, #0
	strh r1, [r0]
_080BE1A8:
	add sp, #0x34
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BE1B0: .4byte 0x0000C091
_080BE1B4: .4byte 0x00009F57
_080BE1B8: .4byte 0x00001638
_080BE1BC: .4byte 0x03003ED0
_080BE1C0: .4byte 0x00000392
_080BE1C4: .4byte 0x0000F06E

	thumb_func_start FUN_080be1c8
FUN_080be1c8: @ 0x080BE1C8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080BE1F0 @ =0x000092B3
	ldr r1, _080BE1F4 @ =0x0000A41A
	bl GetFile
	ldr r1, _080BE1F8 @ =0x0000163C
	adds r4, r4, r1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, _080BE1FC @ =0x030043F0
	ldr r2, _080BE200 @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE1F0: .4byte 0x000092B3
_080BE1F4: .4byte 0x0000A41A
_080BE1F8: .4byte 0x0000163C
_080BE1FC: .4byte 0x030043F0
_080BE200: .4byte 0x04000018

	thumb_func_start FUN_080be204
FUN_080be204: @ 0x080BE204
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r4, _080BE5E0 @ =0x0000CB05
	ldr r1, _080BE5E4 @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x38
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	movs r6, #0x38
	adds r6, r6, r7
	mov r8, r6
	mov r0, r8
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080BE5E8 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x18
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r7, #0
	adds r0, #0x18
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080BE5EC @ =0x0000414C
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x58
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r4, r5}
	stm r1!, {r4, r5}
	adds r6, r7, #0
	adds r6, #0x58
	adds r0, r6, #0
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080BE5F0 @ =0xFFFF0000
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x78
	str r1, [sp]
	str r1, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x27
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r0, r7, #0
	adds r0, #0xd8
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x23
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x24
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r4, #0
	add r6, sp, #0x10
	mov sb, r4
	mov r5, r8
	str r5, [sp, #0x18]
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r5, r7, r0
_080BE2F0:
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r6, #2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r6]
	mov r1, sb
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r2, #0x68
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xf
	ble _080BE2F0
	movs r4, #0
	movs r2, #0x18
	adds r2, r2, r7
	mov sl, r2
	adds r3, r7, #0
	adds r3, #0x58
	str r3, [sp, #0x1c]
	add r6, sp, #0x10
	mov r8, r4
	movs r0, #0xf3
	lsls r0, r0, #3
	adds r5, r7, r0
_080BE344:
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r6, #2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r6]
	mov r1, r8
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x68
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xb
	ble _080BE344
	movs r6, #0
	ldr r2, _080BE5F4 @ =0x00000D38
	adds r5, r7, r2
	movs r4, #3
_080BE386:
	str r6, [sp]
	str r6, [sp, #4]
	movs r3, #0x3c
	mov sb, r3
	str r3, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x41
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE386
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	adds r6, r0, #0
	movs r0, #0x80
	strh r0, [r6, #2]
	ldr r1, _080BE5F8 @ =0x00000CD8
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0xd0
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0x78
	add r0, sp, #0x10
	strh r1, [r0]
	movs r5, #0x68
	strh r5, [r6, #2]
	ldr r3, _080BE5FC @ =0x00000C78
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0xcb
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r5, [r0]
	movs r3, #0x20
	mov r8, r3
	mov r5, r8
	strh r5, [r6, #2]
	ldr r0, _080BE600 @ =0x00000C18
	adds r5, r7, r0
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0xcc
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r5, #0
	bl FUN_080b95bc
	ldr r3, _080BE604 @ =0x00000F18
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r5, sb
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	mov r1, sl
	movs r2, #0x3c
	movs r3, #0x31
	bl FUN_0822f3fc
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	mov r2, r8
	strh r2, [r6, #2]
	ldr r3, _080BE608 @ =0x00000EB8
	adds r5, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r6, sb
	str r6, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x39
	movs r3, #0x30
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _080BE60C @ =0x000013F8
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0x18
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0xb
	add r1, sp, #0x10
	strh r0, [r1]
	adds r6, r1, #0
	ldr r3, _080BE610 @ =0x00001458
	adds r5, r7, r3
	mov r8, r4
	movs r4, #3
_080BE49A:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0x19
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #6
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE49A
	movs r1, #0x28
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x68
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r1, _080BE614 @ =0x00000F78
	adds r5, r7, r1
	movs r2, #0
	mov r8, r2
	movs r4, #2
_080BE4D8:
	mov r3, r8
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE4D8
	movs r1, #0x58
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x68
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r4, _080BE618 @ =0x00001098
	adds r5, r7, r4
	movs r0, #0
	mov r8, r0
	movs r4, #2
_080BE516:
	mov r1, r8
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE516
	movs r1, #0x28
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x70
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r2, _080BE61C @ =0x000011B8
	adds r5, r7, r2
	movs r3, #0
	mov r8, r3
	movs r4, #2
_080BE554:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE554
	movs r1, #0x58
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x70
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r1, _080BE620 @ =0x000012D8
	adds r5, r7, r1
	movs r2, #0
	mov r8, r2
	movs r4, #2
_080BE592:
	mov r3, r8
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #0x3c
	mov sb, r0
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE592
	movs r1, #0
	add r0, sp, #0x10
	strh r1, [r0]
	strh r1, [r0, #2]
	ldr r2, _080BE624 @ =0x000015D8
	adds r0, r7, r2
	str r1, [sp]
	str r1, [sp, #4]
	mov r3, sb
	str r3, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	mov r1, sl
	movs r2, #0x94
	movs r3, #0x11
	bl FUN_0822f3fc
	b _080BE628
	.align 2, 0
_080BE5E0: .4byte 0x0000CB05
_080BE5E4: .4byte 0x00005D04
_080BE5E8: .4byte 0x0000B343
_080BE5EC: .4byte 0x0000414C
_080BE5F0: .4byte 0xFFFF0000
_080BE5F4: .4byte 0x00000D38
_080BE5F8: .4byte 0x00000CD8
_080BE5FC: .4byte 0x00000C78
_080BE600: .4byte 0x00000C18
_080BE604: .4byte 0x00000F18
_080BE608: .4byte 0x00000EB8
_080BE60C: .4byte 0x000013F8
_080BE610: .4byte 0x00001458
_080BE614: .4byte 0x00000F78
_080BE618: .4byte 0x00001098
_080BE61C: .4byte 0x000011B8
_080BE620: .4byte 0x000012D8
_080BE624: .4byte 0x000015D8
_080BE628:
	ldr r5, _080BE648 @ =0x00001690
	adds r0, r7, r5
	bl FUN_080b99a0
	ldr r6, _080BE64C @ =0x000017B4
	adds r0, r7, r6
	bl FUN_080b9814
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BE648: .4byte 0x00001690
_080BE64C: .4byte 0x000017B4

	thumb_func_start FUN_080be650
FUN_080be650: @ 0x080BE650
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080BE66A
	bl FUN_0823d340
	movs r2, #0xb2
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
_080BE66A:
	bl FUN_08049f5c
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	ldr r0, _080BE68C @ =0x0000A41A
	bl FUN_08047dc0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE68C: .4byte 0x0000A41A

	thumb_func_start FUN_080be690
FUN_080be690: @ 0x080BE690
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r0, #0x57
	bl prepare_08231510
	cmp r0, #0
	beq _080BE6AC
	bl Script_GetValue
	adds r5, r0, #0
	b _080BE6AE
_080BE6AC:
	movs r5, #0
_080BE6AE:
	movs r0, #0x50
	bl prepare_08231510
	cmp r0, #0
	beq _080BE75C
	movs r4, #0
	movs r6, #0
	movs r7, #0
	cmp r7, r5
	bge _080BE720
	ldr r0, _080BE6E4 @ =0x08DA9E68
	mov sb, r0
_080BE6C6:
	bl Script_GetValue
	adds r1, r0, #0
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, sb
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _080BE700
	cmp r0, #1
	bgt _080BE6E8
	cmp r0, #0
	beq _080BE6EE
	b _080BE71A
	.align 2, 0
_080BE6E4: .4byte 0x08DA9E68
_080BE6E8:
	cmp r0, #2
	beq _080BE710
	b _080BE71A
_080BE6EE:
	ldr r0, _080BE6FC @ =0x0000165C
	add r0, r8
	adds r0, r0, r4
	strb r1, [r0]
	adds r4, #1
	b _080BE71A
	.align 2, 0
_080BE6FC: .4byte 0x0000165C
_080BE700:
	ldr r0, _080BE70C @ =0x0000166C
	add r0, r8
	adds r0, r0, r6
	strb r1, [r0]
	adds r6, #1
	b _080BE71A
	.align 2, 0
_080BE70C: .4byte 0x0000166C
_080BE710:
	ldr r0, _080BE7A0 @ =0x0000167C
	add r0, r8
	adds r0, r0, r7
	strb r1, [r0]
	adds r7, #1
_080BE71A:
	subs r5, #1
	cmp r5, #0
	bne _080BE6C6
_080BE720:
	cmp r4, #0xb
	bgt _080BE734
	ldr r1, _080BE7A4 @ =0x0000165C
	add r1, r8
	movs r2, #0
_080BE72A:
	adds r0, r1, r4
	strb r2, [r0]
	adds r4, #1
	cmp r4, #0xb
	ble _080BE72A
_080BE734:
	cmp r6, #0xb
	bgt _080BE748
	ldr r1, _080BE7A8 @ =0x0000166C
	add r1, r8
	movs r2, #0
_080BE73E:
	adds r0, r1, r6
	strb r2, [r0]
	adds r6, #1
	cmp r6, #0xb
	ble _080BE73E
_080BE748:
	cmp r7, #0xb
	bgt _080BE75C
	ldr r1, _080BE7A0 @ =0x0000167C
	add r1, r8
	movs r2, #0
_080BE752:
	adds r0, r1, r7
	strb r2, [r0]
	adds r7, #1
	cmp r7, #0xb
	ble _080BE752
_080BE75C:
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _080BE770
	bl FUN_0823d340
	ldr r1, _080BE7AC @ =0x00001644
	add r1, r8
	str r0, [r1]
_080BE770:
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _080BE794
	bl FUN_0823d340
	ldr r4, _080BE7B0 @ =0x00001648
	add r4, r8
	str r0, [r4]
	cmp r0, #0
	beq _080BE794
	bl VM_ParseStringRef
	adds r0, #1
	bl Textbox_LookupString
	str r0, [r4]
_080BE794:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BE7A0: .4byte 0x0000167C
_080BE7A4: .4byte 0x0000165C
_080BE7A8: .4byte 0x0000166C
_080BE7AC: .4byte 0x00001644
_080BE7B0: .4byte 0x00001648

	thumb_func_start FUN_080be7b4
FUN_080be7b4: @ 0x080BE7B4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x65
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080BE7D4
	bl Script_GetValue
	ldr r2, _080BE7D0 @ =0x00001894
	adds r1, r4, r2
	str r0, [r1]
	b _080BE7DA
	.align 2, 0
_080BE7D0: .4byte 0x00001894
_080BE7D4:
	ldr r2, _080BE7E0 @ =0x00001894
	adds r0, r4, r2
	str r1, [r0]
_080BE7DA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE7E0: .4byte 0x00001894

	thumb_func_start FUN_080be7e4
FUN_080be7e4: @ 0x080BE7E4
	push {lr}
	adds r2, r0, #0
	ldr r0, _080BE808 @ =0x0000168E
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BE802
	ldr r1, _080BE80C @ =FUN_080be810
	adds r0, r2, #0
	bl FUN_080bcdd4
_080BE802:
	pop {r0}
	bx r0
	.align 2, 0
_080BE808: .4byte 0x0000168E
_080BE80C: .4byte FUN_080be810

	thumb_func_start FUN_080be810
FUN_080be810: @ 0x080BE810
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080BE850 @ =0x00001655
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	beq _080BE90C
	adds r1, #5
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1d
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080BE854
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	b _080BE86C
	.align 2, 0
_080BE850: .4byte 0x00001655
_080BE854:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
_080BE86C:
	str r0, [r1]
	ldr r0, _080BE890 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080BE89C
	ldr r0, _080BE894 @ =0x00001654
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _080BE898
	movs r0, #2
	b _080BE8BE
	.align 2, 0
_080BE890: .4byte 0x030044E0
_080BE894: .4byte 0x00001654
_080BE898:
	subs r0, #1
	b _080BE8BE
_080BE89C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _080BE8D0
	ldr r0, _080BE8B8 @ =0x00001654
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #2
	bne _080BE8BC
	strb r2, [r1]
	b _080BE8C0
	.align 2, 0
_080BE8B8: .4byte 0x00001654
_080BE8BC:
	adds r0, #1
_080BE8BE:
	strb r0, [r1]
_080BE8C0:
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080be0d8
	b _080BE92A
_080BE8D0:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BE92A
	ldr r0, _080BE900 @ =0x00000119
	bl PlaySound_082406e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BE904 @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080BE908 @ =FUN_080be948
	adds r0, r4, #0
	bl FUN_080bcdd4
	b _080BE936
	.align 2, 0
_080BE900: .4byte 0x00000119
_080BE904: .4byte 0x0000FFFF
_080BE908: .4byte FUN_080be948
_080BE90C:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080BE940 @ =0x0000165A
	adds r0, r4, r1
	strb r3, [r0]
_080BE92A:
	ldr r1, _080BE944 @ =0x0000189C
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080BE936:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BE940: .4byte 0x0000165A
_080BE944: .4byte 0x0000189C

	thumb_func_start FUN_080be948
FUN_080be948: @ 0x080BE948
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080BE9A0 @ =0x0000168E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BE998
	ldr r1, _080BE9A4 @ =0x00001894
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080BE992
	ldr r1, _080BE9A8 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	ldr r1, _080BE9AC @ =0x00001658
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp, #4]
	add r1, sp, #8
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_080BE992:
	adds r0, r4, #0
	bl KillEntity
_080BE998:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE9A0: .4byte 0x0000168E
_080BE9A4: .4byte 0x00001894
_080BE9A8: .4byte 0xFFFF0000
_080BE9AC: .4byte 0x00001658

	thumb_func_start FUN_080be9b0
FUN_080be9b0: @ 0x080BE9B0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080BE9D8 @ =0x00001657
	adds r5, r4, r0
	ldrb r0, [r5]
	bl FUN_080b94cc
	ldrb r0, [r5]
	bl FUN_080b9400
	ldr r1, _080BE9DC @ =0x00001898
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080BE9D8: .4byte 0x00001657
_080BE9DC: .4byte 0x00001898

	thumb_func_start FUN_080be9e0
FUN_080be9e0: @ 0x080BE9E0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x78
	movs r5, #0x39
_080BE9EA:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BE9EA
	ldr r1, _080BEA10 @ =0x00001690
	adds r0, r6, r1
	bl FUN_080b9a0c
	ldr r1, _080BEA14 @ =0x000017B4
	adds r0, r6, r1
	bl FUN_080b9894
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BEA10: .4byte 0x00001690
_080BEA14: .4byte 0x000017B4

	thumb_func_start FUN_080bea18
FUN_080bea18: @ 0x080BEA18
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_080be690
	adds r0, r4, #0
	bl FUN_080be144
	adds r0, r4, #0
	bl FUN_080be1c8
	adds r0, r4, #0
	bl FUN_080be204
	adds r0, r4, #0
	bl FUN_080be650
	adds r0, r4, #0
	bl FUN_080be7b4
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BEA8C @ =0x0000FFFF
	str r0, [sp, #4]
	movs r5, #0
	str r5, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080BEA90 @ =0x00001654
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_080be0d8
	ldr r1, _080BEA94 @ =0x00001658
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r5, [r0]
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080BEA98 @ =FUN_080be7e4
	adds r0, r4, #0
	bl FUN_080bcdd4
	movs r0, #0
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080BEA8C: .4byte 0x0000FFFF
_080BEA90: .4byte 0x00001654
_080BEA94: .4byte 0x00001658
_080BEA98: .4byte FUN_080be7e4
_080BEA9C:
	.byte 0x10, 0xB5, 0xC5, 0x21
	.byte 0x49, 0x01, 0x0B, 0x20, 0x72, 0xF1, 0x84, 0xF8, 0x04, 0x1C, 0x00, 0x2C, 0x12, 0xD0, 0x07, 0x49
	.byte 0x07, 0x4A, 0x72, 0xF1, 0xA1, 0xF8, 0x20, 0x1C, 0xFF, 0xF7, 0xAE, 0xFF, 0x00, 0x28, 0x09, 0xDA
	.byte 0x20, 0x1C, 0x72, 0xF1, 0xD3, 0xF8, 0x00, 0x20, 0x05, 0xE0, 0x00, 0x00, 0xB1, 0xE9, 0x0B, 0x08
	.byte 0xE1, 0xE9, 0x0B, 0x08, 0x20, 0x1C, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080beadc
FUN_080beadc: @ 0x080BEADC
	ldr r3, _080BEAEC @ =0x000010E8
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080BEAF0 @ =0x00000ECA
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080BEAEC: .4byte 0x000010E8
_080BEAF0: .4byte 0x00000ECA

	thumb_func_start FUN_080beaf4
FUN_080beaf4: @ 0x080BEAF4
	ldr r2, _080BEAFC @ =0x00000EC8
	adds r0, r0, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
_080BEAFC: .4byte 0x00000EC8

	thumb_func_start FUN_080beb00
FUN_080beb00: @ 0x080BEB00
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _080BEB20 @ =0x000010EC
	adds r0, r4, r3
	str r1, [r0]
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080beaf4
	ldr r0, _080BEB24 @ =0x00000ECA
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BEB20: .4byte 0x000010EC
_080BEB24: .4byte 0x00000ECA

	thumb_func_start FUN_080beb28
FUN_080beb28: @ 0x080BEB28
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_08049e5c
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xec
	lsls r0, r0, #4
	adds r4, r4, r0
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r5, #0
	bl FUN_08047a28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080beb6c
FUN_080beb6c: @ 0x080BEB6C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080BEB88 @ =0x00000FD1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BEB8C
	adds r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	bl GetValuableItemID
	adds r5, r0, #0
	b _080BEBB0
	.align 2, 0
_080BEB88: .4byte 0x00000FD1
_080BEB8C:
	cmp r0, #7
	bhi _080BEBAC
	ldr r1, _080BEBA4 @ =0x00000FD3
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, r4, r0
	ldr r1, _080BEBA8 @ =0x00000EBC
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	b _080BEBB0
	.align 2, 0
_080BEBA4: .4byte 0x00000FD3
_080BEBA8: .4byte 0x00000EBC
_080BEBAC:
	movs r5, #1
	rsbs r5, r5, #0
_080BEBB0:
	cmp r5, #0
	bge _080BEBCC
	movs r1, #0xb6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _080BEC10
_080BEBCC:
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BEC18 @ =0x00000EC4
	adds r4, r4, r1
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r5, #0
	bl FUN_08047a28
	ldr r0, [r4]
	bl VM_ParseStringRef
	adds r0, #0x4e
	adds r0, r0, r5
	bl Textbox_LookupString
	bl FUN_08049e30
_080BEC10:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BEC18: .4byte 0x00000EC4

	thumb_func_start FUN_080bec1c
FUN_080bec1c: @ 0x080BEC1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	movs r7, #0
	adds r0, #0x80
	str r0, [sp]
	movs r1, #0
	str r1, [sp, #8]
	mov sb, r1
_080BEC36:
	movs r2, #0
	mov r8, r2
	mov r1, sb
	adds r1, #1
	mov r0, sl
	adds r0, #0xd8
	ldr r2, [sp, #8]
	adds r6, r2, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, [sp]
	adds r5, r0, r1
_080BEC50:
	mov r1, sb
	add r1, r8
	adds r0, r1, #0
	bl GetValuableItemID
	adds r4, r0, #0
	cmp r4, #0
	blt _080BECA0
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r2, r4, #0
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r4, #0
	subs r0, #0x38
	cmp r0, #7
	bhi _080BEC94
	adds r0, r6, #0
	ldr r1, _080BEC90 @ =0x000002DF
	bl FUN_080b95bc
	b _080BECA8
	.align 2, 0
_080BEC90: .4byte 0x000002DF
_080BEC94:
	adds r0, r6, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BECA8
_080BECA0:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
_080BECA8:
	adds r5, #0x60
	adds r6, #0x60
	movs r2, #1
	add r8, r2
	mov r0, r8
	cmp r0, #3
	ble _080BEC50
	ldr r1, [sp, #8]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r1, r2
	str r1, [sp, #8]
	movs r0, #4
	add sb, r0
	adds r7, #1
	cmp r7, #3
	ble _080BEC36
	movs r7, #0
_080BECCC:
	movs r1, #0
	mov r8, r1
	lsls r2, r7, #2
	mov sb, r2
	adds r0, r7, #1
	str r0, [sp, #4]
	adds r2, #0x11
	lsls r0, r7, #3
	add r0, sb
	lsls r0, r0, #5
	movs r1, #0xdb
	lsls r1, r1, #3
	add r1, sl
	adds r6, r0, r1
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r1, [sp]
	adds r5, r0, r1
_080BECF2:
	mov r1, sb
	add r1, r8
	ldr r0, _080BED48 @ =0x00000ECC
	add r0, sl
	adds r0, r0, r1
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #0
	blt _080BED64
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r2, r4, #0
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _080BED4C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r4, #4
	ldr r2, _080BED50 @ =0x08DAA8E4
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r1, r0
	bhs _080BED54
	adds r0, r6, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BED6C
	.align 2, 0
_080BED48: .4byte 0x00000ECC
_080BED4C: .4byte 0x030046A0
_080BED50: .4byte 0x08DAA8E4
_080BED54:
	adds r0, r6, #0
	ldr r1, _080BED60 @ =0x000002DF
	bl FUN_080b95bc
	b _080BED6C
	.align 2, 0
_080BED60: .4byte 0x000002DF
_080BED64:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
_080BED6C:
	adds r5, #0x60
	adds r6, #0x60
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #3
	ble _080BECF2
	ldr r7, [sp, #4]
	cmp r7, #2
	ble _080BECCC
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bed90
FUN_080bed90: @ 0x080BED90
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r1, _080BEDD4 @ =0x00000FD3
	adds r0, r5, r1
	ldrb r2, [r0]
	adds r0, r5, r2
	ldr r1, _080BEDD8 @ =0x00000EBC
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	blt _080BEDE4
	ldr r0, _080BEDDC @ =0x08DAA8D8
	lsls r1, r1, #4
	adds r0, #0xc
	adds r1, r1, r0
	ldr r4, [r1]
	add r0, sp, #4
	adds r1, r2, #0
	bl FUN_080b9938
	adds r0, r5, #0
	adds r0, #0x58
	ldr r2, _080BEDE0 @ =0x00000C78
	adds r1, r5, r2
	movs r2, #0
	str r2, [sp]
	add r2, sp, #4
	adds r3, r4, #0
	bl FUN_080b9658
	b _080BEDEC
	.align 2, 0
_080BEDD4: .4byte 0x00000FD3
_080BEDD8: .4byte 0x00000EBC
_080BEDDC: .4byte 0x08DAA8D8
_080BEDE0: .4byte 0x00000C78
_080BEDE4:
	ldr r1, _080BEDF4 @ =0x00000C78
	adds r0, r5, r1
	bl FUN_080b9724
_080BEDEC:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BEDF4: .4byte 0x00000C78

	thumb_func_start FUN_080bedf8
FUN_080bedf8: @ 0x080BEDF8
	push {r4, lr}
	movs r4, #0
_080BEDFC:
	adds r0, r4, #0
	bl GetValuableItemID
	subs r0, #0x38
	cmp r0, #7
	bhi _080BEE0C
	adds r0, r4, #0
	b _080BEE14
_080BEE0C:
	adds r4, #1
	cmp r4, #0xf
	ble _080BEDFC
	movs r0, #0x38
_080BEE14:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080bee1c
FUN_080bee1c: @ 0x080BEE1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	mov sb, r0
	bl FUN_080bedf8
	adds r6, r0, #0
	bl GetValuableItemID
	adds r4, r0, #0
	adds r1, r6, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	mov r5, sb
	adds r5, #0x80
	adds r0, r5, r0
	ldr r1, [r0]
	movs r2, #1
	mov r8, r2
	orrs r1, r2
	str r1, [r0]
	str r2, [sp, #0x2c]
	adds r0, r4, #0
	adds r0, #0x68
	str r0, [sp, #0x34]
	ldr r0, _080BEEE8 @ =0x000002DF
	mov sl, r0
	str r0, [sp, #0x3c]
	add r0, sp, #0xc
	adds r1, r6, #0
	bl FUN_080b9938
	add r7, sp, #0x1c
	subs r4, #0x28
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_080b9938
	ldr r2, _080BEEEC @ =0x00000FD6
	add r2, sb
	ldrb r1, [r2]
	adds r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r5, r5, r0
	ldr r0, [r5]
	mov r1, r8
	orrs r0, r1
	str r0, [r5]
	add r6, sp, #0x2c
	str r1, [r6, #4]
	ldrb r0, [r2]
	add r0, sb
	ldr r1, _080BEEF0 @ =0x00000EBC
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #0x68
	add r5, sp, #0x34
	str r0, [r5, #4]
	add r4, sp, #0x3c
	mov r0, sl
	str r0, [r4, #4]
	add r0, sp, #0x14
	ldrb r1, [r2]
	bl FUN_080b9938
	add r0, sp, #0x24
	ldr r1, _080BEEF4 @ =0x00000FD3
	add r1, sb
	ldrb r1, [r1]
	bl FUN_080b9938
	ldr r1, _080BEEF8 @ =0x00000EDC
	add sb, r1
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	mov r0, sb
	adds r1, r6, #0
	add r2, sp, #0xc
	adds r3, r7, #0
	bl FUN_080b9a28
	ldr r0, _080BEEFC @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BEEE8: .4byte 0x000002DF
_080BEEEC: .4byte 0x00000FD6
_080BEEF0: .4byte 0x00000EBC
_080BEEF4: .4byte 0x00000FD3
_080BEEF8: .4byte 0x00000EDC
_080BEEFC: .4byte 0x0000038A

	thumb_func_start FUN_080bef00
FUN_080bef00: @ 0x080BEF00
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	cmp r1, #0
	bne _080BEF1A
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080BEF80
_080BEF1A:
	movs r2, #0
	ldr r0, _080BEF30 @ =0x00000FD3
	adds r4, r5, r0
	adds r0, #3
	adds r1, r5, r0
	ldrb r0, [r4]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BEF34
	movs r2, #4
	b _080BEF56
	.align 2, 0
_080BEF30: .4byte 0x00000FD3
_080BEF34:
	ldr r1, _080BEF6C @ =0x00000FD1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BEF56
	ldrb r0, [r4]
	bl GetValuableItemID
	adds r6, r0, #0
	ldrb r4, [r4]
	bl FUN_080bedf8
	movs r2, #4
	cmp r4, r0
	beq _080BEF56
	asrs r0, r6, #0x1f
	ands r2, r0
_080BEF56:
	cmp r2, #4
	bne _080BEF70
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #7
	bl FUN_080b98c0
	b _080BEF80
	.align 2, 0
_080BEF6C: .4byte 0x00000FD1
_080BEF70:
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080BEF80:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bef88
FUN_080bef88: @ 0x080BEF88
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080BEFBC @ =0x00000FD3
	adds r5, r4, r0
	ldr r2, _080BEFC0 @ =0x00000FD6
	adds r1, r4, r2
	ldrb r0, [r5]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BEFC8
	bl FUN_080bedf8
	strb r0, [r5]
	movs r1, #3
	ands r1, r0
	ldr r2, _080BEFC4 @ =0x00000FD1
	adds r0, r4, r2
	strb r1, [r0]
	ldrb r0, [r5]
	lsrs r0, r0, #2
	adds r2, #1
	adds r1, r4, r2
	strb r0, [r1]
_080BEFB6:
	movs r0, #4
	b _080BEFEA
	.align 2, 0
_080BEFBC: .4byte 0x00000FD3
_080BEFC0: .4byte 0x00000FD6
_080BEFC4: .4byte 0x00000FD1
_080BEFC8:
	ldr r1, _080BEFF0 @ =0x00000FD1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BEFE8
	ldrb r0, [r5]
	bl GetValuableItemID
	adds r6, r0, #0
	ldrb r4, [r5]
	bl FUN_080bedf8
	cmp r4, r0
	beq _080BEFB6
	cmp r6, #0
	blt _080BEFB6
_080BEFE8:
	movs r0, #0
_080BEFEA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BEFF0: .4byte 0x00000FD1

	thumb_func_start FUN_080beff4
FUN_080beff4: @ 0x080BEFF4
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xc2
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xfd
	lsls r0, r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r0, _080BF050 @ =0x00000BB8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #0x1d
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FUN_080beb6c
	adds r0, r5, #0
	bl FUN_080bec1c
	adds r0, r5, #0
	bl FUN_080bed90
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bef00
	ldr r1, _080BF054 @ =FUN_080bf058
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080beb00
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BF050: .4byte 0x00000BB8
_080BF054: .4byte FUN_080bf058

	thumb_func_start FUN_080bf058
FUN_080bf058: @ 0x080BF058
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, _080BF0B0 @ =0x030044E0
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080BF0B8
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080beaf4
	ldr r1, _080BF0B4 @ =0x00000BB8
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BF08C
	b _080BF1B8
_080BF08C:
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r2, #0x87
	lsls r2, r2, #5
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080BF0A8
	b _080BF1B8
_080BF0A8:
	movs r0, #0
	strb r0, [r1]
	b _080BF1B8
	.align 2, 0
_080BF0B0: .4byte 0x030044E0
_080BF0B4: .4byte 0x00000BB8
_080BF0B8:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080beaf4
	ldr r0, _080BF11C @ =0x00000BB8
	adds r6, r5, r0
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r6, #0
	bl FUN_082372cc
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080BF18C
	ldr r1, _080BF120 @ =0x00000FD3
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r2, _080BF124 @ =0x00000EBC
	adds r0, r0, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r3, #1
	cmp r1, #0
	blt _080BF110
	ldr r0, _080BF128 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x91
	lsls r4, r4, #4
	adds r0, r0, r4
	movs r4, #0
	ldrsh r2, [r0, r4]
	ldr r0, _080BF12C @ =0x08DAA8D8
	lsls r1, r1, #4
	adds r0, #0xc
	adds r1, r1, r0
	ldr r0, [r1]
	cmp r2, r0
	bhs _080BF10C
	movs r3, #0
_080BF10C:
	cmp r3, #0
	bne _080BF130
_080BF110:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BF1B8
	.align 2, 0
_080BF11C: .4byte 0x00000BB8
_080BF120: .4byte 0x00000FD3
_080BF124: .4byte 0x00000EBC
_080BF128: .4byte 0x030046A0
_080BF12C: .4byte 0x08DAA8D8
_080BF130:
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0xfd
	lsls r0, r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fd8
	movs r1, #0xc2
	lsls r1, r1, #4
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080BF180 @ =0x00000C38
	adds r2, r5, r0
	ldr r1, _080BF184 @ =0x00000BD8
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r4, #0
	movs r1, #0x3c
	bl FUN_080b9d94
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bef00
	ldr r1, _080BF188 @ =0x080BF1C1
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080beb00
	b _080BF1B8
	.align 2, 0
_080BF180: .4byte 0x00000C38
_080BF184: .4byte 0x00000BD8
_080BF188: .4byte 0x080BF1C1
_080BF18C:
	movs r2, #0xfd
	lsls r2, r2, #4
	adds r4, r5, r2
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080BF1B8
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080beb6c
	adds r0, r5, #0
	bl FUN_080bed90
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bef00
_080BF1B8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BF1C0:
	.byte 0x70, 0xB5, 0x05, 0x1C, 0x17, 0x48, 0x41, 0x88, 0x01, 0x20, 0x08, 0x40, 0x00, 0x28, 0x38, 0xD0
	.byte 0x28, 0x1C, 0xFF, 0xF7, 0xD9, 0xFE, 0x04, 0x1C, 0x80, 0x21, 0x49, 0x01, 0x68, 0x18, 0x01, 0x22
	.byte 0x52, 0x42, 0x11, 0x1C, 0xFA, 0xF7, 0x6C, 0xFB, 0x04, 0x2C, 0x25, 0xD1, 0x0E, 0x48, 0x81, 0xF1
	.byte 0x77, 0xFA, 0x0E, 0x49, 0x68, 0x18, 0x02, 0x68, 0x28, 0x1C, 0x00, 0x21, 0x00, 0x23, 0xFF, 0xF7
	.byte 0x93, 0xFC, 0x0B, 0x49, 0x68, 0x18, 0x2C, 0x1C, 0x18, 0x34, 0x71, 0x31, 0x6A, 0x18, 0x21, 0x1C
	.byte 0x01, 0x23, 0xFA, 0xF7, 0x95, 0xFA, 0x07, 0x49, 0x28, 0x1C, 0x00, 0x22, 0xFF, 0xF7, 0x70, 0xFC
	.byte 0x32, 0xE0, 0x00, 0x00, 0xE0, 0x44, 0x00, 0x03, 0x07, 0x01, 0x00, 0x00, 0xC4, 0x0E, 0x00, 0x00
	.byte 0x58, 0x0E, 0x00, 0x00, 0x9D, 0xF2, 0x0B, 0x08, 0xC9, 0x20, 0x40, 0x00, 0x81, 0xF1, 0x50, 0xFA
	.byte 0x09, 0xE0, 0x02, 0x20, 0x08, 0x40, 0x00, 0x28, 0x08, 0xD0, 0xDE, 0x20, 0x81, 0xF1, 0x48, 0xFA
	.byte 0x28, 0x1C, 0xFF, 0xF7, 0xCF, 0xFE, 0x2C, 0x1C, 0x18, 0x34, 0x15, 0xE0, 0xFD, 0x20, 0x00, 0x01
	.byte 0x2E, 0x18, 0x30, 0x1C, 0xFA, 0xF7, 0x84, 0xFE, 0x2C, 0x1C, 0x18, 0x34, 0x00, 0x28, 0x0B, 0xD0
	.byte 0x09, 0x48, 0x29, 0x18, 0x30, 0x1C, 0xFA, 0xF7, 0xA5, 0xFE, 0x28, 0x1C, 0xFF, 0xF7, 0x76, 0xFC
	.byte 0x28, 0x1C, 0x01, 0x21, 0xFF, 0xF7, 0x3C, 0xFE, 0x03, 0x49, 0x68, 0x18, 0x21, 0x1C, 0x78, 0xF1
	.byte 0x1D, 0xF8, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0xB8, 0x0B, 0x00, 0x00

	thumb_func_start FUN_080bf29c
FUN_080bf29c: @ 0x080BF29C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BF2CC @ =0x00000E58
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BF2D0 @ =0x00000EC9
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BF2D8
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080bee1c
	ldr r1, _080BF2D4 @ =0x080BF2F1
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080beb00
	b _080BF2E8
	.align 2, 0
_080BF2CC: .4byte 0x00000E58
_080BF2D0: .4byte 0x00000EC9
_080BF2D4: .4byte 0x080BF2F1
_080BF2D8:
	cmp r0, #0
	bne _080BF2E8
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080beff4
_080BF2E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF2F0:
	.byte 0xF0, 0xB5, 0x47, 0x46, 0x80, 0xB4, 0x07, 0x1C, 0x21, 0x49, 0x78, 0x18, 0xFA, 0xF7, 0xEE, 0xFB
	.byte 0x00, 0x28, 0x37, 0xD0, 0xFF, 0xF7, 0x78, 0xFD, 0x06, 0x1C, 0x82, 0xF1, 0xB1, 0xFF, 0x80, 0x46
	.byte 0x1C, 0x49, 0x78, 0x18, 0x00, 0x78, 0x10, 0x38, 0x1B, 0x49, 0x7D, 0x18, 0x28, 0x18, 0x00, 0x24
	.byte 0x04, 0x57, 0x30, 0x1C, 0x82, 0xF1, 0xD4, 0xFF, 0x18, 0x49, 0x78, 0x18, 0x00, 0x78, 0x21, 0x1C
	.byte 0x82, 0xF1, 0xB4, 0xFF, 0x16, 0x48, 0x02, 0x68, 0x91, 0x20, 0x00, 0x01, 0x12, 0x18, 0x15, 0x48
	.byte 0x21, 0x01, 0x0C, 0x30, 0x09, 0x18, 0x09, 0x68, 0x10, 0x88, 0x40, 0x1A, 0x10, 0x80, 0x40, 0x46
	.byte 0x38, 0x38, 0x28, 0x18, 0x41, 0x46, 0x01, 0x70, 0x38, 0x3C, 0x2D, 0x19, 0xFF, 0x20, 0x28, 0x70
	.byte 0x0D, 0x48, 0x39, 0x18, 0x01, 0x20, 0x08, 0x70, 0x0C, 0x48, 0x81, 0xF1, 0xB9, 0xF9, 0x38, 0x1C
	.byte 0xFF, 0xF7, 0x40, 0xFE, 0x08, 0xBC, 0x98, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0xDC, 0x0E, 0x00, 0x00, 0xD6, 0x0F, 0x00, 0x00, 0xCC, 0x0E, 0x00, 0x00, 0xD3, 0x0F, 0x00, 0x00
	.byte 0xA0, 0x46, 0x00, 0x03, 0xD8, 0xA8, 0xDA, 0x08, 0xE1, 0x10, 0x00, 0x00, 0x11, 0x01, 0x00, 0x00

	thumb_func_start FUN_080bf3a0
FUN_080bf3a0: @ 0x080BF3A0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0xfd
	lsls r0, r0, #4
	adds r5, r4, r0
	movs r0, #0x1d
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #4
	movs r3, #0
	bl FUN_080b9ff8
	ldr r0, _080BF3F4 @ =0x00000BB8
	adds r1, r4, r0
	adds r0, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080bec1c
	adds r0, r4, #0
	bl FUN_080bed90
	adds r0, r4, #0
	bl FUN_080beb6c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080bef00
	ldr r1, _080BF3F8 @ =FUN_080bf058
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080beb00
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BF3F4: .4byte 0x00000BB8
_080BF3F8: .4byte FUN_080bf058

	thumb_func_start FUN_080bf3fc
FUN_080bf3fc: @ 0x080BF3FC
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080BF44C @ =0x0000C091
	ldr r1, _080BF450 @ =0x00009F57
	bl GetFile
	adds r2, r0, #0
	ldr r0, _080BF454 @ =0x00000EB8
	adds r4, r4, r0
	str r2, [r4]
	movs r5, #0
	str r5, [sp, #0xc]
	str r5, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	ldr r1, [r4]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BF44C: .4byte 0x0000C091
_080BF450: .4byte 0x00009F57
_080BF454: .4byte 0x00000EB8

	thumb_func_start FUN_080bf458
FUN_080bf458: @ 0x080BF458
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080BF480 @ =0x000092B3
	ldr r1, _080BF484 @ =0x0000A41A
	bl GetFile
	ldr r1, _080BF488 @ =0x00000EBC
	adds r4, r4, r1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, _080BF48C @ =0x030043F0
	ldr r2, _080BF490 @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF480: .4byte 0x000092B3
_080BF484: .4byte 0x0000A41A
_080BF488: .4byte 0x00000EBC
_080BF48C: .4byte 0x030043F0
_080BF490: .4byte 0x04000018

	thumb_func_start FUN_080bf494
FUN_080bf494: @ 0x080BF494
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r4, _080BF6E4 @ =0x0000CB05
	ldr r1, _080BF6E8 @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x38
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	movs r6, #0x38
	adds r6, r6, r7
	mov sb, r6
	mov r0, sb
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080BF6EC @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x18
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r7, #0
	adds r0, #0x18
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080BF6F0 @ =0x0000414C
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x58
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r4, r5}
	stm r1!, {r4, r5}
	adds r4, r7, #0
	adds r4, #0x58
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080BF6F4 @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x78
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r6, sp, #0x10
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0x29
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r4, #0
	add r6, sp, #0x10
	mov r8, r4
	mov sl, sb
	adds r5, r7, #0
	adds r5, #0xd8
_080BF54A:
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r6, #2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r6]
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r2, #0x68
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xf
	ble _080BF54A
	movs r4, #0
	adds r1, r7, #0
	adds r1, #0x18
	str r1, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x58
	str r2, [sp, #0x18]
	add r6, sp, #0x10
	mov sb, r4
	movs r3, #0xdb
	lsls r3, r3, #3
	adds r5, r7, r3
_080BF59E:
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r6, #2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r6]
	mov r0, sb
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0x3c
	mov r8, r1
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x68
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xb
	ble _080BF59E
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	adds r5, r0, #0
	movs r0, #0x80
	strh r0, [r5, #2]
	ldr r2, _080BF6F8 @ =0x00000B58
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, sl
	movs r2, #0xcf
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r6, _080BF6FC @ =0x00000C18
	adds r0, r7, r6
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0x3c
	movs r3, #0x31
	bl FUN_0822f3fc
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x20
	strh r0, [r5, #2]
	ldr r3, _080BF700 @ =0x00000BB8
	adds r5, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r6, r8
	str r6, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0x39
	movs r3, #0x30
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _080BF704 @ =0x00000C78
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x18
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0xb
	add r1, sp, #0x10
	strh r0, [r1]
	adds r6, r1, #0
	ldr r3, _080BF708 @ =0x00000CD8
	adds r5, r7, r3
	mov r8, r4
	movs r4, #3
_080BF678:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0x3c
	mov sb, r1
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x19
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #6
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BF678
	movs r1, #0
	add r0, sp, #0x10
	strh r1, [r0]
	strh r1, [r0, #2]
	ldr r2, _080BF70C @ =0x00000E58
	adds r0, r7, r2
	str r1, [sp]
	str r1, [sp, #4]
	mov r3, sb
	str r3, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0x94
	movs r3, #0x11
	bl FUN_0822f3fc
	ldr r5, _080BF710 @ =0x00000EDC
	adds r0, r7, r5
	bl FUN_080b99a0
	movs r6, #0x80
	lsls r6, r6, #5
	adds r0, r7, r6
	bl FUN_080b9814
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BF6E4: .4byte 0x0000CB05
_080BF6E8: .4byte 0x00005D04
_080BF6EC: .4byte 0x0000B343
_080BF6F0: .4byte 0x0000414C
_080BF6F4: .4byte 0xFFFF0000
_080BF6F8: .4byte 0x00000B58
_080BF6FC: .4byte 0x00000C18
_080BF700: .4byte 0x00000BB8
_080BF704: .4byte 0x00000C78
_080BF708: .4byte 0x00000CD8
_080BF70C: .4byte 0x00000E58
_080BF710: .4byte 0x00000EDC

	thumb_func_start FUN_080bf714
FUN_080bf714: @ 0x080BF714
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080BF72E
	bl FUN_0823d340
	movs r2, #0xec
	lsls r2, r2, #4
	adds r1, r4, r2
	str r0, [r1]
_080BF72E:
	bl FUN_08049f5c
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	ldr r0, _080BF750 @ =0x0000A41A
	bl FUN_08047dc0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF750: .4byte 0x0000A41A

	thumb_func_start FUN_080bf754
FUN_080bf754: @ 0x080BF754
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r0, #0x43
	bl prepare_08231510
	cmp r0, #0
	beq _080BF76A
	bl Script_GetValue
	adds r5, r0, #0
	b _080BF76C
_080BF76A:
	movs r5, #0
_080BF76C:
	bl FUN_080bedf8
	bl GetValuableItemID
	adds r7, r0, #0
	movs r0, #0x4f
	bl prepare_08231510
	cmp r0, #0
	beq _080BF7D2
	movs r4, #0
	cmp r4, r5
	bge _080BF7A8
_080BF786:
	bl Script_GetValue
	adds r1, r0, #0
	ldr r2, _080BF7EC @ =0x00000ECC
	adds r0, r6, r2
	adds r2, r0, r4
	strb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r7, r0
	bne _080BF7A2
	movs r0, #0xff
	orrs r1, r0
	strb r1, [r2]
_080BF7A2:
	adds r4, #1
	cmp r4, r5
	blt _080BF786
_080BF7A8:
	cmp r4, #0xb
	bgt _080BF7C0
	ldr r0, _080BF7EC @ =0x00000ECC
	adds r2, r6, r0
	movs r3, #0xff
_080BF7B2:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #0xb
	ble _080BF7B2
_080BF7C0:
	ldr r2, _080BF7F0 @ =0x00000ED4
	adds r1, r6, r2
	movs r4, #3
_080BF7C6:
	ldrb r0, [r1]
	strb r0, [r1, #4]
	adds r1, #1
	subs r4, #1
	cmp r4, #0
	bge _080BF7C6
_080BF7D2:
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _080BF7E6
	bl FUN_0823d340
	ldr r2, _080BF7F4 @ =0x00000EC4
	adds r1, r6, r2
	str r0, [r1]
_080BF7E6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BF7EC: .4byte 0x00000ECC
_080BF7F0: .4byte 0x00000ED4
_080BF7F4: .4byte 0x00000EC4

	thumb_func_start FUN_080bf7f8
FUN_080bf7f8: @ 0x080BF7F8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x65
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080BF818
	bl Script_GetValue
	ldr r2, _080BF814 @ =0x000010E4
	adds r1, r4, r2
	str r0, [r1]
	b _080BF81E
	.align 2, 0
_080BF814: .4byte 0x000010E4
_080BF818:
	ldr r2, _080BF824 @ =0x000010E4
	adds r0, r4, r2
	str r1, [r0]
_080BF81E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF824: .4byte 0x000010E4

	thumb_func_start FUN_080bf828
FUN_080bf828: @ 0x080BF828
	push {lr}
	adds r2, r0, #0
	ldr r0, _080BF84C @ =0x00000ECA
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BF846
	ldr r1, _080BF850 @ =FUN_080bf854
	adds r0, r2, #0
	bl FUN_080beadc
_080BF846:
	pop {r0}
	bx r0
	.align 2, 0
_080BF84C: .4byte 0x00000ECA
_080BF850: .4byte FUN_080bf854

	thumb_func_start FUN_080bf854
FUN_080bf854: @ 0x080BF854
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080BF898 @ =0x00000EC8
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080BF8AC
	ldr r0, _080BF89C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BF8AC
	ldr r0, _080BF8A0 @ =0x00000119
	bl PlaySound_082406e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BF8A4 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080BF8A8 @ =FUN_080bf8c4
	adds r0, r4, #0
	bl FUN_080beadc
	b _080BF8B8
	.align 2, 0
_080BF898: .4byte 0x00000EC8
_080BF89C: .4byte 0x030044E0
_080BF8A0: .4byte 0x00000119
_080BF8A4: .4byte 0x0000FFFF
_080BF8A8: .4byte FUN_080bf8c4
_080BF8AC:
	ldr r1, _080BF8C0 @ =0x000010EC
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080BF8B8:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF8C0: .4byte 0x000010EC

	thumb_func_start FUN_080bf8c4
FUN_080bf8c4: @ 0x080BF8C4
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080BF91C @ =0x00000ECA
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BF914
	ldr r1, _080BF920 @ =0x000010E4
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080BF90E
	ldr r1, _080BF924 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	ldr r1, _080BF928 @ =0x000010E1
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp, #4]
	add r1, sp, #8
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_080BF90E:
	adds r0, r4, #0
	bl KillEntity
_080BF914:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF91C: .4byte 0x00000ECA
_080BF920: .4byte 0x000010E4
_080BF924: .4byte 0xFFFF0000
_080BF928: .4byte 0x000010E1

	thumb_func_start FUN_080bf92c
FUN_080bf92c: @ 0x080BF92C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x87
	lsls r0, r0, #5
	adds r5, r4, r0
	ldrb r0, [r5]
	bl FUN_080b94cc
	ldrb r0, [r5]
	bl FUN_080b9400
	ldr r1, _080BF958 @ =0x000010E8
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080BF958: .4byte 0x000010E8

	thumb_func_start FUN_080bf95c
FUN_080bf95c: @ 0x080BF95C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x78
	movs r5, #0x25
_080BF966:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BF966
	ldr r1, _080BF990 @ =0x00000EDC
	adds r0, r6, r1
	bl FUN_080b9a0c
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r6, r1
	bl FUN_080b9894
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BF990: .4byte 0x00000EDC

	thumb_func_start FUN_080bf994
FUN_080bf994: @ 0x080BF994
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_080bf754
	adds r0, r4, #0
	bl FUN_080bf3fc
	adds r0, r4, #0
	bl FUN_080bf458
	adds r0, r4, #0
	bl FUN_080bf494
	adds r0, r4, #0
	bl FUN_080bf714
	adds r0, r4, #0
	bl FUN_080bf7f8
	ldr r1, _080BFA00 @ =0x000010E1
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080BFA04 @ =0x000010E2
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BFA08 @ =0x0000FFFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r4, #0
	bl FUN_080bf3a0
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080BFA0C @ =FUN_080bf828
	adds r0, r4, #0
	bl FUN_080beadc
	movs r0, #0
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080BFA00: .4byte 0x000010E1
_080BFA04: .4byte 0x000010E2
_080BFA08: .4byte 0x0000FFFF
_080BFA0C: .4byte FUN_080bf828

	thumb_func_start FUN_080bfa10
FUN_080bfa10: @ 0x080BFA10
	push {r4, lr}
	ldr r1, _080BFA3C @ =0x000010F0
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080BFA48
	ldr r1, _080BFA40 @ =FUN_080bf92c
	ldr r2, _080BFA44 @ =FUN_080bf95c
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080bf994
	cmp r0, #0
	bge _080BFA48
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080BFA4A
	.align 2, 0
_080BFA3C: .4byte 0x000010F0
_080BFA40: .4byte FUN_080bf92c
_080BFA44: .4byte FUN_080bf95c
_080BFA48:
	adds r0, r4, #0
_080BFA4A:
	pop {r4}
	pop {r1}
	bx r1
_080BFA50:
	.byte 0x01, 0x49, 0x00, 0x20, 0x08, 0x60, 0x70, 0x47, 0x58, 0x01, 0x00, 0x03

	thumb_func_start FUN_080bfa5c
FUN_080bfa5c: @ 0x080BFA5C
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080BFA70 @ =0x000005B6
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080BFA70: .4byte 0x000005B6

	thumb_func_start FUN_080bfa74
FUN_080bfa74: @ 0x080BFA74
	push {r4, r5, lr}
	movs r1, #0
	ldr r5, _080BFAA0 @ =0x03002BE0
	adds r4, r5, #0
	ldr r3, _080BFAA4 @ =0x0000040C
	movs r2, #0
_080BFA80:
	ldr r0, [r4]
	adds r0, r0, r3
	adds r0, r0, r1
	strb r2, [r0]
	adds r1, #1
	cmp r1, #0x1f
	ble _080BFA80
	ldr r0, [r5]
	ldr r1, _080BFAA8 @ =0x0000042E
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BFAA0: .4byte 0x03002BE0
_080BFAA4: .4byte 0x0000040C
_080BFAA8: .4byte 0x0000042E

	thumb_func_start FUN_080bfaac
FUN_080bfaac: @ 0x080BFAAC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r6, _080BFB24 @ =0x03002BE0
	ldr r1, [r6]
	movs r4, #1
	str r4, [r1, #0x1c]
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r2, #0
	movs r0, #0x20
	strb r0, [r1]
	ldr r0, [r6]
	ldr r1, _080BFB28 @ =0x0000037D
	adds r0, r0, r1
	strb r2, [r0]
	ldr r1, [r6]
	movs r7, #0
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r1, #0x2c]
	ldr r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #0x2e]
	ldr r1, [r6]
	movs r0, #0xb0
	lsls r0, r0, #3
	strh r0, [r1, #0x30]
	ldr r0, [r6]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #7
	strb r1, [r0]
	ldr r0, [r6]
	ldr r1, _080BFB2C @ =0x000002E6
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r6]
	adds r1, #1
	adds r0, r0, r1
	strb r4, [r0]
	bl FUN_080bfa74
	ldr r0, [r6]
	ldr r1, _080BFB30 @ =0x0000042C
	adds r0, r0, r1
	strh r4, [r0]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r5, r5, r0
	ldrh r0, [r5]
	cmp r0, #1
	beq _080BFB48
	cmp r0, #1
	bgt _080BFB34
	cmp r0, #0
	beq _080BFB3E
	b _080BFB6E
	.align 2, 0
_080BFB24: .4byte 0x03002BE0
_080BFB28: .4byte 0x0000037D
_080BFB2C: .4byte 0x000002E6
_080BFB30: .4byte 0x0000042C
_080BFB34:
	cmp r0, #2
	beq _080BFB58
	cmp r0, #3
	beq _080BFB62
	b _080BFB6E
_080BFB3E:
	ldr r0, [r6]
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x20
	b _080BFB6A
_080BFB48:
	ldr r0, [r6]
	ldr r1, _080BFB54 @ =0x0000042C
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x40
	b _080BFB6A
	.align 2, 0
_080BFB54: .4byte 0x0000042C
_080BFB58:
	ldr r0, [r6]
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x10
	b _080BFB6A
_080BFB62:
	ldr r0, [r6]
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x80
_080BFB6A:
	orrs r1, r2
	strh r1, [r0]
_080BFB6E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bfb74
FUN_080bfb74: @ 0x080BFB74
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0xb4
	ldrh r0, [r3]
	lsrs r0, r0, #3
	adds r1, r2, #0
	adds r1, #0x6c
	strh r0, [r1, #0x10]
	adds r0, r2, #0
	adds r0, #0xb6
	ldrh r0, [r0]
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080BFB9E
	movs r0, #0
	strh r0, [r3]
_080BFB9E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bfba4
FUN_080bfba4: @ 0x080BFBA4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080BFC08 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x86
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080BFBC6
	adds r1, r0, #0
	movs r0, #0x80
	bl Div
	adds r1, r0, #0
	cmp r1, #0
	bgt _080BFBC8
_080BFBC6:
	movs r1, #1
_080BFBC8:
	adds r2, r4, #0
	adds r2, #0x68
	ldrh r0, [r2]
	adds r1, r0, r1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _080BFBE0
	adds r0, r1, #0
	subs r0, #0xc
	strh r0, [r2]
_080BFBE0:
	ldrh r0, [r2]
	lsrs r0, r0, #2
	strh r0, [r4, #0x30]
	ldr r1, _080BFC0C @ =0x0000057C
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080BFC3C
	ldr r0, _080BFC08 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _080BFC10 @ =0x0000042E
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #1
	bhi _080BFC18
	ldr r0, _080BFC14 @ =0x0000023A
	bl PlaySound_082406e0
	b _080BFC3C
	.align 2, 0
_080BFC08: .4byte 0x03002BE0
_080BFC0C: .4byte 0x0000057C
_080BFC10: .4byte 0x0000042E
_080BFC14: .4byte 0x0000023A
_080BFC18:
	cmp r0, #3
	bhi _080BFC28
	ldr r0, _080BFC24 @ =0x0000023B
	bl PlaySound_082406e0
	b _080BFC3C
	.align 2, 0
_080BFC24: .4byte 0x0000023B
_080BFC28:
	cmp r0, #5
	bhi _080BFC36
	movs r0, #0x8f
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080BFC3C
_080BFC36:
	ldr r0, _080BFC58 @ =0x0000023D
	bl PlaySound_082406e0
_080BFC3C:
	ldr r0, _080BFC5C @ =0x0000057C
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _080BFC52
	movs r0, #0
	strh r0, [r1]
_080BFC52:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BFC58: .4byte 0x0000023D
_080BFC5C: .4byte 0x0000057C

	thumb_func_start FUN_080bfc60
FUN_080bfc60: @ 0x080BFC60
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _080BFCE0 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
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
	mov r6, sp
	movs r3, #0xfe
	lsls r3, r3, #2
	adds r4, r7, r3
	movs r5, #3
_080BFCB8:
	ldm r6!, {r2}
	adds r2, #0x1e
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r3, #0xde
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BFCB8
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BFCE0: .4byte 0x030046A0

	thumb_func_start FUN_080bfce4
FUN_080bfce4: @ 0x080BFCE4
	push {lr}
	movs r3, #2
	rsbs r3, r3, #0
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #4
_080BFCF2:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080BFCF2
	pop {r0}
	bx r0

	thumb_func_start FUN_080bfd04
FUN_080bfd04: @ 0x080BFD04
	push {lr}
	movs r3, #1
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #4
_080BFD10:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080BFD10
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bfd24
FUN_080bfd24: @ 0x080BFD24
	push {lr}
	adds r1, r0, #0
	ldr r0, _080BFD44 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _080BFD48 @ =0x0000042E
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #3
	bls _080BFD4C
	movs r0, #0xb1
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	b _080BFD54
	.align 2, 0
_080BFD44: .4byte 0x03002BE0
_080BFD48: .4byte 0x0000042E
_080BFD4C:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r0, #0
_080BFD54:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bfd5c
FUN_080bfd5c: @ 0x080BFD5C
	push {lr}
	adds r2, r0, #0
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r3, _080BFD78 @ =0x0000058E
	adds r1, r2, r3
	ldrh r3, [r0]
	ldrh r1, [r1]
	cmp r3, r1
	bls _080BFD7C
	movs r0, #0xa
	b _080BFDA6
	.align 2, 0
_080BFD78: .4byte 0x0000058E
_080BFD7C:
	ldr r1, _080BFD8C @ =0x0000058C
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r3, r0
	bls _080BFD90
	movs r0, #5
	b _080BFDA6
	.align 2, 0
_080BFD8C: .4byte 0x0000058C
_080BFD90:
	ldr r1, _080BFDA0 @ =0x0000058A
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r3, r0
	bhi _080BFDA4
	movs r0, #1
	b _080BFDA6
	.align 2, 0
_080BFDA0: .4byte 0x0000058A
_080BFDA4:
	movs r0, #2
_080BFDA6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080bfdac
FUN_080bfdac: @ 0x080BFDAC
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrh r1, [r0]
	cmp r1, #1
	bne _080BFDE0
	movs r2, #0x30
	movs r1, #5
	ldr r4, _080BFDDC @ =0x0000034A
	adds r0, r3, r4
_080BFDC4:
	strh r2, [r0]
	subs r0, #0x2c
	subs r1, #1
	cmp r1, #0
	bge _080BFDC4
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #4
	strh r0, [r1]
	b _080BFE40
	.align 2, 0
_080BFDDC: .4byte 0x0000034A
_080BFDE0:
	cmp r1, #2
	bne _080BFDEE
	movs r2, #0x9f
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r0, #4
	b _080BFE08
_080BFDEE:
	cmp r1, #5
	bne _080BFDFC
	movs r4, #0x9f
	lsls r4, r4, #2
	adds r0, r3, r4
	strh r1, [r0, #0x10]
	b _080BFE0A
_080BFDFC:
	cmp r1, #0xa
	bne _080BFE0A
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #6
_080BFE08:
	strh r0, [r1, #0x10]
_080BFE0A:
	movs r7, #2
	rsbs r7, r7, #0
	adds r2, r3, #0
	movs r4, #0x94
	lsls r4, r4, #2
	adds r1, r3, r4
	adds r4, r3, #0
	adds r4, #0xdc
	ldr r6, _080BFE48 @ =0x0000026E
	movs r5, #0x38
_080BFE1E:
	ldr r0, [r1]
	ands r0, r7
	str r0, [r1]
	adds r0, r2, r6
	strh r5, [r0]
	adds r2, #0x2c
	adds r1, #0x2c
	cmp r2, r4
	ble _080BFE1E
	movs r1, #0xdd
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r1, #0xa
	strh r1, [r0]
	ldr r0, _080BFE4C @ =0x0000028B
	bl PlaySound_082406e0
_080BFE40:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BFE48: .4byte 0x0000026E
_080BFE4C: .4byte 0x0000028B

	thumb_func_start FUN_080bfe50
FUN_080bfe50: @ 0x080BFE50
	push {r4, r5, lr}
	adds r1, r0, #0
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r4, r1, r0
	ldrh r3, [r4]
	adds r2, r3, #0
	cmp r2, #0
	beq _080BFEEC
	movs r5, #0xb2
	lsls r5, r5, #3
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #1
	bne _080BFEAC
	subs r0, r3, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080BFE92
	movs r2, #1
	movs r0, #0x94
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r3, #5
_080BFE82:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080BFE82
	b _080BFEEC
_080BFE92:
	ldr r5, _080BFEA8 @ =0x0000026E
	adds r1, r1, r5
	movs r3, #5
_080BFE98:
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	adds r1, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080BFE98
	b _080BFEEC
	.align 2, 0
_080BFEA8: .4byte 0x0000026E
_080BFEAC:
	cmp r2, #3
	bls _080BFECC
	ldr r0, _080BFEC8 @ =0x0000026E
	adds r2, r1, r0
	movs r3, #5
_080BFEB6:
	ldrh r0, [r2]
	subs r0, #2
	strh r0, [r2]
	adds r2, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080BFEB6
	b _080BFEE0
	.align 2, 0
_080BFEC8: .4byte 0x0000026E
_080BFECC:
	ldr r5, _080BFEF4 @ =0x0000026E
	adds r2, r1, r5
	movs r3, #5
_080BFED2:
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
	adds r2, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080BFED2
_080BFEE0:
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_080BFEEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BFEF4: .4byte 0x0000026E

	thumb_func_start FUN_080bfef8
FUN_080bfef8: @ 0x080BFEF8
	push {lr}
	movs r3, #1
	movs r2, #0x94
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #5
_080BFF04:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _080BFF04
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bff18
FUN_080bff18: @ 0x080BFF18
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080BFF44 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080BFF48 @ =0x0000042E
	adds r0, r0, r1
	ldrh r2, [r0]
	cmp r2, #7
	ble _080BFF2C
	movs r2, #7
_080BFF2C:
	movs r1, #0
	cmp r1, r2
	bge _080BFF56
	movs r4, #1
	movs r3, #2
	movs r6, #0x80
	lsls r6, r6, #1
	adds r0, r5, r6
_080BFF3C:
	cmp r1, #3
	bgt _080BFF4C
	strh r4, [r0, #0x10]
	b _080BFF4E
	.align 2, 0
_080BFF44: .4byte 0x03002BE0
_080BFF48: .4byte 0x0000042E
_080BFF4C:
	strh r3, [r0, #0x10]
_080BFF4E:
	adds r0, #0x2c
	adds r1, #1
	cmp r1, r2
	blt _080BFF3C
_080BFF56:
	cmp r1, #6
	bgt _080BFF72
	movs r2, #0
	movs r0, #0x2c
	muls r0, r1, r0
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r0, r0, r5
_080BFF68:
	strh r2, [r0, #0x10]
	adds r0, #0x2c
	adds r1, #1
	cmp r1, #6
	ble _080BFF68
_080BFF72:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bff78
FUN_080bff78: @ 0x080BFF78
	push {lr}
	movs r3, #2
	rsbs r3, r3, #0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r2, #6
_080BFF86:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _080BFF86
	pop {r0}
	bx r0

	thumb_func_start FUN_080bff98
FUN_080bff98: @ 0x080BFF98
	push {lr}
	movs r3, #1
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r2, #6
_080BFFA4:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _080BFFA4
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bffb8
FUN_080bffb8: @ 0x080BFFB8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080bfce4
	adds r0, r4, #0
	bl FUN_080bff78
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bffcc
FUN_080bffcc: @ 0x080BFFCC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080bfd04
	adds r0, r4, #0
	bl FUN_080bfef8
	adds r0, r4, #0
	bl FUN_080bff98
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BFFE8:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0xFF, 0xF7, 0x5E, 0xFD
	.byte 0x20, 0x1C, 0xFF, 0xF7, 0xE1, 0xFF, 0x05, 0x48, 0x21, 0x18, 0x20, 0x20, 0x08, 0x80, 0x04, 0x49
	.byte 0x20, 0x1C, 0xFF, 0xF7, 0x2B, 0xFD, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x7A, 0x05, 0x00, 0x00
	.byte 0x49, 0x02, 0x0C, 0x08

	thumb_func_start FUN_080c0014
FUN_080c0014: @ 0x080C0014
	push {r4, lr}
	sub sp, #0xc
	adds r2, r0, #0
	ldr r1, _080C004C @ =0x000005AC
	adds r0, r2, r1
	ldr r3, [r0]
	cmp r3, #0
	beq _080C0044
	ldr r1, _080C0050 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r4, sp
	str r4, [r1, #4]
	ldr r4, _080C0054 @ =0x0000057E
	adds r0, r2, r4
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r3, #0
	bl Script_ExecById
_080C0044:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C004C: .4byte 0x000005AC
_080C0050: .4byte 0xFFFF0000
_080C0054: .4byte 0x0000057E

	thumb_func_start FUN_080c0058
FUN_080c0058: @ 0x080C0058
	push {lr}
	sub sp, #0xc
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080C0080
	ldr r1, _080C0088 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_080C0080:
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_080C0088: .4byte 0xFFFF0000

	thumb_func_start FUN_080c008c
FUN_080c008c: @ 0x080C008C
	push {r4, lr}
	ldr r0, _080C00C8 @ =0x03000158
	ldr r3, [r0]
	cmp r3, #0
	beq _080C00C2
	ldr r2, _080C00CC @ =0x080BFFE9
	movs r0, #0
	movs r1, #0
	bl FUN_080a6180
	ldr r4, _080C00D0 @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #7
	bl FUN_0807b910
	ldr r1, [r4]
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r1, #0x2c]
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #0x2e]
	ldr r1, [r4]
	movs r0, #0xb0
	lsls r0, r0, #3
	strh r0, [r1, #0x30]
_080C00C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C00C8: .4byte 0x03000158
_080C00CC: .4byte 0x080BFFE9
_080C00D0: .4byte 0x03002BE0

	thumb_func_start FUN_080c00d4
FUN_080c00d4: @ 0x080C00D4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, _080C00EC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080C00F0 @ =0x0000042E
	adds r0, r0, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne _080C00F4
	movs r7, #0
	b _080C0106
	.align 2, 0
_080C00EC: .4byte 0x03002BE0
_080C00F0: .4byte 0x0000042E
_080C00F4:
	cmp r1, #3
	bhi _080C00FC
	movs r7, #1
	b _080C0106
_080C00FC:
	ldrh r0, [r0]
	subs r7, r0, #2
	subs r0, #3
	muls r0, r7, r0
	asrs r7, r0, #1
_080C0106:
	adds r0, r4, #0
	bl FUN_080bfd5c
	adds r5, r0, #0
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r6, r4, r2
	ldrh r0, [r6]
	cmp r0, r5
	beq _080C0146
	ldr r3, _080C0190 @ =0x000005A4
	adds r0, r4, r3
	ldr r2, [r0]
	cmp r2, #0
	beq _080C013E
	ldr r1, _080C0194 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	str r5, [sp]
	adds r0, r2, #0
	bl Script_ExecById
_080C013E:
	strh r5, [r6]
	adds r0, r4, #0
	bl FUN_080bfdac
_080C0146:
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r2, #0xb6
	lsls r2, r2, #3
	adds r1, r4, r2
	muls r0, r7, r0
	ldrh r3, [r1]
	adds r2, r0, r3
	strh r2, [r1]
	ldr r0, _080C0198 @ =0x000005B2
	adds r5, r4, r0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	ldrh r3, [r5]
	cmp r0, r3
	blo _080C019C
	movs r4, #0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r3
	blo _080C018C
	adds r3, r1, #0
	adds r2, r5, #0
_080C0178:
	adds r4, #1
	ldrh r0, [r3]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r2]
	cmp r0, r1
	bhs _080C0178
_080C018C:
	adds r0, r4, #0
	b _080C019E
	.align 2, 0
_080C0190: .4byte 0x000005A4
_080C0194: .4byte 0xFFFF0000
_080C0198: .4byte 0x000005B2
_080C019C:
	movs r0, #0
_080C019E:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C01A8:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080c01ac
FUN_080c01ac: @ 0x080C01AC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, _080C0218 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0
	str r4, [r0]
	bl FUN_080bfa74
	movs r0, #0xb2
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r5, #0
	movs r0, #1
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r7, r1
	strh r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	bl FUN_08240630
	movs r0, #8
	bl FUN_0823bca8
	adds r0, r7, #0
	bl FUN_080bffcc
	ldr r2, _080C021C @ =0x03002BE0
	ldr r0, [r2]
	movs r1, #2
	str r1, [r0, #0x1c]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	strb r5, [r0]
	ldr r0, [r2]
	adds r1, #1
	adds r0, r0, r1
	strb r5, [r0]
	cmp r6, #0
	bne _080C0224
	ldr r2, _080C0220 @ =FUN_080c0014
	movs r0, #1
	movs r1, #0
	adds r3, r7, #0
	bl FUN_080a6180
	b _080C0230
	.align 2, 0
_080C0218: .4byte 0x030046A0
_080C021C: .4byte 0x03002BE0
_080C0220: .4byte FUN_080c0014
_080C0224:
	ldr r2, _080C0240 @ =FUN_080c0058
	movs r0, #1
	movs r1, #0
	adds r3, r7, #0
	bl FUN_080a6180
_080C0230:
	ldr r1, _080C0244 @ =0x080C01A9
	adds r0, r7, #0
	bl FUN_080bfa5c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C0240: .4byte FUN_080c0058
_080C0244: .4byte 0x080C01A9

	thumb_func_start FUN_080c0248
FUN_080c0248: @ 0x080C0248
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r4, _080C0294 @ =0x03002BE0
	ldr r3, [r4]
	ldr r0, _080C0298 @ =0x0000037D
	adds r5, r3, r0
	ldrb r2, [r5]
	cmp r2, #0
	beq _080C025E
	b _080C03F0
_080C025E:
	ldr r2, _080C029C @ =0x00000594
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080bfba4
	movs r5, #0
	ldr r2, [r4]
	ldr r1, _080C02A0 @ =0x0000042E
	adds r0, r2, r1
	ldrh r1, [r0]
	subs r1, #3
	ldrh r0, [r2, #0x2c]
	subs r0, r0, r1
	strh r0, [r2, #0x2c]
	ldr r1, [r4]
	movs r4, #0x2c
	ldrsh r2, [r1, r4]
	ldr r0, _080C02A4 @ =0x0000037F
	cmp r2, r0
	bgt _080C02A8
	adds r0, #1
	strh r0, [r1, #0x2c]
	b _080C02B2
	.align 2, 0
_080C0294: .4byte 0x03002BE0
_080C0298: .4byte 0x0000037D
_080C029C: .4byte 0x00000594
_080C02A0: .4byte 0x0000042E
_080C02A4: .4byte 0x0000037F
_080C02A8:
	ldr r0, _080C030C @ =0x000003FF
	cmp r2, r0
	ble _080C02B2
	strh r0, [r1, #0x2c]
	movs r5, #1
_080C02B2:
	cmp r5, #0
	beq _080C032C
	ldr r0, _080C0310 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080C0314 @ =0x0000037D
	adds r0, r0, r1
	movs r5, #0
	movs r4, #1
	strb r4, [r0]
	ldr r2, _080C0318 @ =0x0000057E
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _080C031C @ =0x0000023A
	bl sound_08240740
	ldr r0, _080C0320 @ =0x0000023B
	bl sound_08240740
	movs r0, #0x8f
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _080C0324 @ =0x0000023D
	bl sound_08240740
	ldr r1, _080C0328 @ =0x0000057C
	adds r0, r6, r1
	strh r5, [r0]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r4, [r0]
	movs r4, #0xb1
	lsls r4, r4, #3
	adds r0, r6, r4
	strh r5, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	bl FUN_08240630
	bl FUN_080bfa74
	b _080C03C8
	.align 2, 0
_080C030C: .4byte 0x000003FF
_080C0310: .4byte 0x03002BE0
_080C0314: .4byte 0x0000037D
_080C0318: .4byte 0x0000057E
_080C031C: .4byte 0x0000023A
_080C0320: .4byte 0x0000023B
_080C0324: .4byte 0x0000023D
_080C0328: .4byte 0x0000057C
_080C032C:
	adds r0, r6, #0
	bl FUN_080bfd24
	adds r0, r6, #0
	bl FUN_080c00d4
	adds r4, r0, #0
	ldr r0, _080C036C @ =0x0000059C
	adds r1, r6, r0
	ldr r0, [r1]
	adds r3, r0, r4
	str r3, [r1]
	ldr r0, _080C0370 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, r4
	bge _080C0378
	str r5, [r1]
	ldr r4, _080C0374 @ =0x0000057A
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _080C03C8
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080c01ac
	b _080C03C8
	.align 2, 0
_080C036C: .4byte 0x0000059C
_080C0370: .4byte 0x030046A0
_080C0374: .4byte 0x0000057A
_080C0378:
	ldr r1, _080C03A0 @ =0x00000594
	adds r0, r6, r1
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blt _080C03A4
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r3, r0
	blt _080C03A4
	adds r0, r6, #0
	movs r1, #1
	bl FUN_080c01ac
	b _080C03C8
	.align 2, 0
_080C03A0: .4byte 0x00000594
_080C03A4:
	ldr r0, _080C03E4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _080C03E8 @ =0x0000042E
	adds r0, r0, r2
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	bl FUN_08240630
	ldr r0, _080C03EC @ =0x030046A0
	ldr r1, [r0]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	subs r0, r0, r4
	str r0, [r1]
_080C03C8:
	adds r0, r6, #0
	bl FUN_080bfc60
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #1
	bls _080C04AE
	lsls r0, r0, #2
	bl FUN_0823b9cc
	b _080C04AE
	.align 2, 0
_080C03E4: .4byte 0x03002BE0
_080C03E8: .4byte 0x0000042E
_080C03EC: .4byte 0x030046A0
_080C03F0:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r0, [r0]
	ldr r1, _080C0418 @ =0xFFFFFF00
	ands r0, r1
	movs r1, #0x81
	lsls r1, r1, #9
	cmp r0, r1
	bne _080C0420
	movs r0, #4
	str r0, [sp]
	ldr r0, _080C041C @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #5
	movs r2, #4
	b _080C0472
	.align 2, 0
_080C0418: .4byte 0xFFFFFF00
_080C041C: .4byte 0x00001FFF
_080C0420:
	cmp r2, #3
	bne _080C048C
	ldr r2, _080C047C @ =0x0000037E
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r0, #0x1f
	bls _080C04AE
	movs r3, #0
	movs r2, #4
	strb r2, [r5]
	ldr r0, [r4]
	ldr r1, _080C047C @ =0x0000037E
	adds r0, r0, r1
	strh r3, [r0]
	ldr r1, [r4]
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r1, #0x2c]
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #0x2e]
	ldr r1, [r4]
	movs r0, #0xb0
	lsls r0, r0, #3
	strh r0, [r1, #0x30]
	ldr r0, [r4]
	ldr r1, _080C0480 @ =0x000002E6
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r4, _080C0484 @ =0x000002E7
	adds r0, r0, r4
	strb r1, [r0]
	str r2, [sp]
	ldr r0, _080C0488 @ =0x00001FFF
	str r0, [sp, #4]
	str r3, [sp, #8]
	movs r0, #0
	movs r1, #5
_080C0472:
	movs r3, #4
	bl FUN_0823ce68
	b _080C04AE
	.align 2, 0
_080C047C: .4byte 0x0000037E
_080C0480: .4byte 0x000002E6
_080C0484: .4byte 0x000002E7
_080C0488: .4byte 0x00001FFF
_080C048C:
	cmp r2, #4
	bne _080C04AE
	ldr r1, _080C04D0 @ =0x0000037E
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #0x1f
	bls _080C04AE
	movs r0, #0
	strb r0, [r5]
	ldr r1, [r4]
	ldr r2, _080C04D0 @ =0x0000037E
	adds r1, r1, r2
	strh r0, [r1]
	movs r4, #0xb1
	lsls r4, r4, #3
	adds r1, r6, r4
	strh r0, [r1]
_080C04AE:
	adds r0, r6, #0
	bl FUN_080bff18
	adds r0, r6, #0
	bl FUN_080bfe50
	ldr r0, _080C04D4 @ =0x0000057A
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080C04C8
	subs r0, #1
	strh r0, [r1]
_080C04C8:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C04D0: .4byte 0x0000037E
_080C04D4: .4byte 0x0000057A

	thumb_func_start FUN_080c04d8
FUN_080c04d8: @ 0x080C04D8
	push {lr}
	ldr r0, _080C04FC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080C0500 @ =0x0000042E
	adds r3, r0, r1
	ldrh r0, [r3]
	cmp r0, #3
	bhi _080C050C
	ldr r1, _080C0504 @ =0x04000050
	movs r0, #0xee
	strh r0, [r1]
	ldr r2, _080C0508 @ =0x04000054
	ldrh r1, [r3]
	movs r0, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	strh r0, [r2]
	b _080C051A
	.align 2, 0
_080C04FC: .4byte 0x03002BE0
_080C0500: .4byte 0x0000042E
_080C0504: .4byte 0x04000050
_080C0508: .4byte 0x04000054
_080C050C:
	ldr r1, _080C0524 @ =0x04000050
	movs r0, #0xae
	strh r0, [r1]
	adds r1, #4
	ldrh r0, [r3]
	subs r0, #4
	strh r0, [r1]
_080C051A:
	ldr r1, _080C0528 @ =0x04000052
	movs r0, #0
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080C0524: .4byte 0x04000050
_080C0528: .4byte 0x04000052

	thumb_func_start FUN_080c052c
FUN_080c052c: @ 0x080C052C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080bfb74
	adds r0, r4, #0
	bl FUN_080c04d8
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080C0554:
	.byte 0x70, 0xB5, 0x06, 0x1C, 0x20, 0x30, 0x69, 0xF1, 0xC1, 0xFF, 0x30, 0x1C
	.byte 0x6C, 0x30, 0x69, 0xF1, 0xBD, 0xFF, 0x30, 0x1C, 0xB8, 0x30, 0x69, 0xF1, 0xB9, 0xFF, 0xE6, 0x20
	.byte 0x80, 0x00, 0x35, 0x18, 0x04, 0x24, 0x28, 0x1C, 0x6E, 0xF1, 0x22, 0xFE, 0x60, 0x35, 0x01, 0x3C
	.byte 0x00, 0x2C, 0xF8, 0xDA, 0x80, 0x20, 0x40, 0x00, 0x35, 0x18, 0x06, 0x24, 0x28, 0x1C, 0x69, 0xF1
	.byte 0xA7, 0xFF, 0x2C, 0x35, 0x01, 0x3C, 0x00, 0x2C, 0xF8, 0xDA, 0x94, 0x20, 0x80, 0x00, 0x35, 0x18
	.byte 0x05, 0x24, 0x28, 0x1C, 0x69, 0xF1, 0x9C, 0xFF, 0x2C, 0x35, 0x01, 0x3C, 0x00, 0x2C, 0xF8, 0xDA
	.byte 0x00, 0x20, 0x04, 0x49, 0x08, 0x60, 0x04, 0x48, 0x80, 0xF1, 0xC2, 0xF8, 0x00, 0x20, 0x70, 0xBC
	.byte 0x02, 0xBC, 0x08, 0x47, 0x58, 0x01, 0x00, 0x03, 0x3E, 0x02, 0x00, 0x00

	thumb_func_start FUN_080c05cc
FUN_080c05cc: @ 0x080C05CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r0, _080C06C8 @ =0x0000CB05
	ldr r1, _080C06CC @ =0x0000B343
	bl GetFile
	adds r1, r0, #0
	movs r0, #0xde
	lsls r0, r0, #2
	adds r4, r7, r0
	adds r2, r4, #0
	adds r0, r1, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl FUN_0822f284
	ldr r2, _080C06D0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x90
	orrs r0, r1
	ldr r1, _080C06D4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	movs r2, #0
	movs r6, #0xe6
	lsls r6, r6, #2
	adds r0, r7, r6
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0x28
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r2, _080C06D8 @ =0x000003D2
	adds r0, r7, r2
	ldr r2, _080C06DC @ =0x000002A7
	strh r2, [r0]
	movs r5, #0xf8
	lsls r5, r5, #2
	adds r3, r7, r5
	ldr r0, _080C06E0 @ =0x03003584
	lsls r1, r2, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r3]
	add r0, sp, #0x10
	ldrh r0, [r0]
	adds r0, #8
	add r1, sp, #0x10
	strh r0, [r1]
	movs r6, #0
	mov sl, r6
	adds r5, r1, #0
	movs r0, #0x60
	mov r8, r0
	movs r1, #0xfe
	lsls r1, r1, #2
	adds r4, r7, r1
	mov sb, r2
_080C0670:
	movs r0, #1
	str r0, [sp]
	mov r2, sl
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r3, #0xde
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r2, #0x1e
	movs r3, #0x30
	bl FUN_0822f3fc
	mov r0, sb
	strh r0, [r4, #0x3a]
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r2, r7, r1
	add r2, r8
	ldr r0, _080C06E0 @ =0x03003584
	ldrh r1, [r4, #0x3a]
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	ldrh r0, [r5]
	adds r0, #8
	strh r0, [r5]
	movs r2, #0x60
	add r8, r2
	adds r4, #0x60
	adds r6, #1
	cmp r6, #3
	ble _080C0670
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C06C8: .4byte 0x0000CB05
_080C06CC: .4byte 0x0000B343
_080C06D0: .4byte 0xFFFF0000
_080C06D4: .4byte 0x0000FFFF
_080C06D8: .4byte 0x000003D2
_080C06DC: .4byte 0x000002A7
_080C06E0: .4byte 0x03003584

	thumb_func_start FUN_080c06e4
FUN_080c06e4: @ 0x080C06E4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r2, _080C0730 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r4
	movs r1, #0x84
	orrs r0, r1
	ldr r1, _080C0734 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #0xe
	adds r4, r0, #0
	orrs r4, r1
	ands r5, r2
	movs r0, #0xd6
	lsls r0, r0, #2
	add r0, r8
	ldr r1, _080C0738 @ =0x0000A8E7
	bl FUN_0822b16c
	movs r7, #0
	movs r6, #0x94
	lsls r6, r6, #2
	add r6, r8
_080C0718:
	adds r0, r6, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x11
	bl FUN_0822a470
	cmp r7, #1
	bgt _080C073C
	adds r0, r7, #3
	b _080C073E
	.align 2, 0
_080C0730: .4byte 0xFFFF0000
_080C0734: .4byte 0x0000FFFF
_080C0738: .4byte 0x0000A8E7
_080C073C:
	adds r0, r7, #5
_080C073E:
	strh r0, [r6, #0x10]
	str r4, [r6, #0x1c]
	str r5, [r6, #0x20]
	movs r0, #1
	strb r0, [r6, #7]
	adds r1, r4, #0
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080C076C @ =0xFFFF0000
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	adds r6, #0x2c
	adds r7, #1
	cmp r7, #5
	ble _080C0718
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C076C: .4byte 0xFFFF0000

	thumb_func_start FUN_080c0770
FUN_080c0770: @ 0x080C0770
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r2, _080C0800 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r5
	movs r1, #0x80
	orrs r0, r1
	ldr r1, _080C0804 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xe0
	lsls r1, r1, #0xe
	adds r5, r0, #0
	orrs r5, r1
	ands r6, r2
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, _080C0808 @ =0x0000A8E7
	bl FUN_0822b16c
	movs r3, #0
	movs r2, #0x80
	lsls r2, r2, #1
	mov r8, r2
_080C07A6:
	movs r0, #0x2c
	adds r4, r3, #0
	muls r4, r0, r4
	mov r1, r8
	adds r0, r4, r1
	adds r0, r7, r0
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r2, #0x10
	str r3, [sp]
	bl FUN_0822a470
	adds r0, r4, r7
	add r0, r8
	movs r1, #0
	strh r1, [r0, #0x10]
	adds r1, r7, r4
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r1, r2
	str r5, [r0]
	str r6, [r0, #4]
	ldr r0, _080C080C @ =0x00000107
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080C0800 @ =0xFFFF0000
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	ldr r3, [sp]
	adds r3, #1
	cmp r3, #6
	ble _080C07A6
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C0800: .4byte 0xFFFF0000
_080C0804: .4byte 0x0000FFFF
_080C0808: .4byte 0x0000A8E7
_080C080C: .4byte 0x00000107

	thumb_func_start FUN_080c0810
FUN_080c0810: @ 0x080C0810
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080C0832
	bl Script_GetValue
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r1, r7, r2
	strh r0, [r1]
	b _080C083A
_080C0832:
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	strh r1, [r0]
_080C083A:
	adds r5, r7, #0
	adds r5, #0x4c
	ldr r0, _080C08C0 @ =0x0000C046
	mov r8, r0
	adds r0, r5, #0
	mov r1, r8
	bl FUN_0822b16c
	adds r4, r7, #0
	adds r4, #0x20
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	movs r6, #0
	strh r6, [r4, #0x10]
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r7, #0x3c]
	strh r6, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x40
	ldr r0, _080C08C4 @ =0x0000052C
	strh r0, [r1]
	adds r5, #0x4c
	adds r0, r5, #0
	mov r1, r8
	bl FUN_0822b16c
	adds r4, #0x4c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	strh r6, [r4, #0x10]
	adds r2, r7, #0
	adds r2, #0x88
	ldr r0, [r7, #0x3c]
	ldr r1, [r7, #0x40]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r7, #0
	adds r1, #0x8c
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0x4e
	bl prepare_08231510
	cmp r0, #0
	beq _080C08E0
	bl Script_GetValue
	cmp r0, #3
	beq _080C08D0
	cmp r0, #3
	ble _080C08E0
	cmp r0, #4
	beq _080C08C8
	cmp r0, #0xa
	beq _080C08D8
	b _080C08E0
	.align 2, 0
_080C08C0: .4byte 0x0000C046
_080C08C4: .4byte 0x0000052C
_080C08C8:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #1
	b _080C08E6
_080C08D0:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #4
	b _080C08E6
_080C08D8:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #3
	b _080C08E6
_080C08E0:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #2
_080C08E6:
	strh r0, [r1]
	adds r5, r7, #0
	adds r5, #0xe4
	ldr r1, _080C095C @ =0x0000C046
	adds r0, r5, #0
	bl FUN_0822b16c
	adds r4, r7, #0
	adds r4, #0xb8
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0
	strh r0, [r4, #0x10]
	adds r2, r7, #0
	adds r2, #0xd4
	ldr r0, [r7, #0x3c]
	ldr r1, [r7, #0x40]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r7, #0
	adds r1, #0xd8
	ldr r2, _080C0960 @ =0xFFFFFD00
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_080c05cc
	adds r0, r7, #0
	bl FUN_080bfc60
	ldr r1, _080C0964 @ =0x080C01A9
	adds r0, r7, #0
	bl FUN_080bfa5c
	adds r0, r7, #0
	bl FUN_080c0770
	adds r0, r7, #0
	bl FUN_080c06e4
	adds r0, r7, #0
	bl FUN_080bffcc
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080C096C
	bl Script_GetValue
	ldr r2, _080C0968 @ =0x000005B2
	adds r1, r7, r2
	b _080C0974
	.align 2, 0
_080C095C: .4byte 0x0000C046
_080C0960: .4byte 0xFFFFFD00
_080C0964: .4byte 0x080C01A9
_080C0968: .4byte 0x000005B2
_080C096C:
	ldr r0, _080C09A0 @ =0x000005B2
	adds r1, r7, r0
	movs r0, #0x96
	lsls r0, r0, #1
_080C0974:
	strh r0, [r1]
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080C09B0
	bl Script_GetValue
	ldr r2, _080C09A4 @ =0x0000058A
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080C09A8 @ =0x0000058C
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080C09AC @ =0x0000058E
	adds r1, r7, r2
	b _080C09C8
	.align 2, 0
_080C09A0: .4byte 0x000005B2
_080C09A4: .4byte 0x0000058A
_080C09A8: .4byte 0x0000058C
_080C09AC: .4byte 0x0000058E
_080C09B0:
	ldr r0, _080C09E4 @ =0x0000058A
	adds r1, r7, r0
	movs r0, #0xb4
	strh r0, [r1]
	ldr r2, _080C09E8 @ =0x0000058C
	adds r1, r7, r2
	adds r0, #0x78
	strh r0, [r1]
	ldr r0, _080C09EC @ =0x0000058E
	adds r1, r7, r0
	movs r0, #0x96
	lsls r0, r0, #2
_080C09C8:
	strh r0, [r1]
	movs r0, #0x62
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080C09F4
	bl Script_GetValue
	ldr r2, _080C09F0 @ =0x000005A4
	adds r1, r7, r2
	str r0, [r1]
	b _080C09FA
	.align 2, 0
_080C09E4: .4byte 0x0000058A
_080C09E8: .4byte 0x0000058C
_080C09EC: .4byte 0x0000058E
_080C09F0: .4byte 0x000005A4
_080C09F4:
	ldr r2, _080C0A7C @ =0x000005A4
	adds r0, r7, r2
	str r1, [r0]
_080C09FA:
	movs r0, #0xb2
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r5, #0
	movs r0, #1
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r7, r1
	strh r5, [r0]
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _080C0A22
	bl Script_GetValue
	ldr r2, _080C0A80 @ =0x000005AC
	adds r1, r7, r2
	str r0, [r1]
_080C0A22:
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _080C0A50
	bl Script_GetValue
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r1, r7, r2
	str r0, [r1]
	bl Script_GetValue
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r1, r7, r2
	str r0, [r1]
	bl Script_GetValue
	movs r2, #0xb5
	lsls r2, r2, #3
	adds r1, r7, r2
	str r0, [r1]
_080C0A50:
	ldr r0, _080C0A84 @ =0x00000594
	adds r4, r7, r0
	str r5, [r4]
	ldr r1, _080C0A88 @ =0x0000059C
	adds r0, r7, r1
	str r5, [r0]
	ldr r0, _080C0A8C @ =0x0000023E
	bl PlaySound_082406e0
	ldr r2, _080C0A90 @ =0x0000057E
	adds r0, r7, r2
	strh r5, [r0]
	str r5, [r4]
	ldr r0, _080C0A94 @ =0x03000158
	str r7, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C0A7C: .4byte 0x000005A4
_080C0A80: .4byte 0x000005AC
_080C0A84: .4byte 0x00000594
_080C0A88: .4byte 0x0000059C
_080C0A8C: .4byte 0x0000023E
_080C0A90: .4byte 0x0000057E
_080C0A94: .4byte 0x03000158

	thumb_func_start FUN_080c0a98
FUN_080c0a98: @ 0x080C0A98
	push {r4, lr}
	ldr r0, _080C0ACC @ =0x03000158
	ldr r0, [r0]
	cmp r0, #0
	bne _080C0ADE
	ldr r1, _080C0AD0 @ =0x000005BC
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C0ADC
	ldr r1, _080C0AD4 @ =FUN_080c052c
	ldr r2, _080C0AD8 @ =0x080C0555
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080c0810
	cmp r0, #0
	bge _080C0ADC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C0ADE
	.align 2, 0
_080C0ACC: .4byte 0x03000158
_080C0AD0: .4byte 0x000005BC
_080C0AD4: .4byte FUN_080c052c
_080C0AD8: .4byte 0x080C0555
_080C0ADC:
	adds r0, r4, #0
_080C0ADE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080c0ae4
FUN_080c0ae4: @ 0x080C0AE4
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b00
FUN_080c0b00: @ 0x080C0B00
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl PlaySound_08240718
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b1c
FUN_080c0b1c: @ 0x080C0B1C
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl sound_08240264
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b38
FUN_080c0b38: @ 0x080C0B38
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_08240360
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b54
FUN_080c0b54: @ 0x080C0B54
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_082403d0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b70
FUN_080c0b70: @ 0x080C0B70
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl sound_fadeout_08240440
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b8c
FUN_080c0b8c: @ 0x080C0B8C
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_082404b0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0ba8
FUN_080c0ba8: @ 0x080C0BA8
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_082404fc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0bc4
FUN_080c0bc4: @ 0x080C0BC4
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_08240568
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0be0
FUN_080c0be0: @ 0x080C0BE0
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_082405c0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0bfc
FUN_080c0bfc: @ 0x080C0BFC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x1c
	movs r7, #0
	ldr r1, _080C0C14 @ =0x03002B4C
	ldr r2, [r1]
	adds r2, #0x24
	adds r1, r6, #0
	adds r1, #0x22
	b _080C0CF8
	.align 2, 0
_080C0C14: .4byte 0x03002B4C
_080C0C18:
	ldr r0, _080C0C48 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r1, [r4, #6]
	cmp r1, #9
	bhi _080C0CEE
	lsls r0, r1, #2
	ldr r1, _080C0C4C @ =_080C0C50
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080C0C48: .4byte 0x03002B4C
_080C0C4C: .4byte _080C0C50
_080C0C50: @ jump table
	.4byte _080C0C78 @ case 0
	.4byte _080C0C84 @ case 1
	.4byte _080C0C90 @ case 2
	.4byte _080C0C9C @ case 3
	.4byte _080C0CA8 @ case 4
	.4byte _080C0CB4 @ case 5
	.4byte _080C0CC0 @ case 6
	.4byte _080C0CCC @ case 7
	.4byte _080C0CD8 @ case 8
	.4byte _080C0CE4 @ case 9
_080C0C78:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0ae4
	b _080C0CEE
_080C0C84:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0b00
	b _080C0CEE
_080C0C90:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0b1c
	b _080C0CEE
_080C0C9C:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0b38
	b _080C0CEE
_080C0CA8:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0b54
	b _080C0CEE
_080C0CB4:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0b70
	b _080C0CEE
_080C0CC0:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0b8c
	b _080C0CEE
_080C0CCC:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0ba8
	b _080C0CEE
_080C0CD8:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0bc4
	b _080C0CEE
_080C0CE4:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0be0
_080C0CEE:
	adds r7, #1
	ldr r1, _080C0D08 @ =0x03002B4C
	ldr r2, [r1]
	adds r2, #0x24
	adds r1, r5, #6
_080C0CF8:
	ldrb r2, [r2]
	adds r1, r1, r2
	ldrb r1, [r1]
	cmp r7, r1
	blt _080C0C18
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C0D08: .4byte 0x03002B4C
_080C0D0C:
	.byte 0x00, 0xB5, 0xFF, 0xF7
	.byte 0x75, 0xFF, 0x00, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x20, 0x70, 0x47

	thumb_func_start FUN_080c0d1c
FUN_080c0d1c: @ 0x080C0D1C
	push {lr}
	adds r0, #0x1c
	movs r2, #8
	bl FUN_080223f4
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_080c0d2c
FUN_080c0d2c: @ 0x080C0D2C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xb
	movs r1, #0x50
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C0D64
	ldr r1, _080C0D5C @ =0x080C0D0D
	ldr r2, _080C0D60 @ =0x080C0D19
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080c0d1c
	cmp r0, #0
	bge _080C0D64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C0D66
	.align 2, 0
_080C0D5C: .4byte 0x080C0D0D
_080C0D60: .4byte 0x080C0D19
_080C0D64:
	adds r0, r4, #0
_080C0D66:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080c0d6c
FUN_080c0d6c: @ 0x080C0D6C
	str r1, [r0, #0x78]
	adds r0, #0x76
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080c0d78
FUN_080c0d78: @ 0x080C0D78
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r0, #0x76
	ldrh r0, [r0]
	cmp r0, #2
	bhi _080C0D90
	adds r0, r2, #0
	adds r0, #0x6a
	ldrh r0, [r0]
	lsrs r0, r0, #1
	adds r0, #4
	b _080C0DD2
_080C0D90:
	adds r1, r2, #0
	adds r1, #0x6c
	ldrh r3, [r1]
	movs r0, #1
	ands r0, r3
	adds r5, r1, #0
	cmp r0, #0
	beq _080C0DA4
	movs r4, #1
	b _080C0DB4
_080C0DA4:
	lsrs r1, r3, #1
	movs r0, #1
	ands r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r4, r0, #0x1f
	movs r0, #2
	ands r4, r0
_080C0DB4:
	ldrh r1, [r5]
	movs r3, #0
	cmp r1, #2
	bls _080C0DCA
	movs r3, #8
	cmp r1, #4
	bls _080C0DCA
	movs r3, #4
	cmp r1, #5
	bhi _080C0DCA
	movs r3, #0xc
_080C0DCA:
	ldr r0, [r2, #0x18]
	orrs r0, r3
	str r0, [r2, #0x18]
	adds r0, r4, #6
_080C0DD2:
	strh r0, [r2, #0x28]
	adds r1, r2, #0
	adds r1, #0x76
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080C0DEC
	adds r0, r2, #0
	bl KillEntity
_080C0DEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C0DF4:
	.byte 0x00, 0xB5, 0x02, 0x1C, 0x11, 0x1C, 0x60, 0x31, 0x6E, 0x30, 0x00, 0x88
	.byte 0x0B, 0x88, 0xC0, 0x18, 0x08, 0x80, 0x04, 0x31, 0x10, 0x1C, 0x70, 0x30, 0x00, 0x88, 0x0B, 0x88
	.byte 0xC0, 0x18, 0x08, 0x80, 0x10, 0x6E, 0x51, 0x6E, 0x50, 0x63, 0x91, 0x63, 0x11, 0x1C, 0x76, 0x31
	.byte 0x08, 0x88, 0x01, 0x30, 0x08, 0x80, 0x02, 0x39, 0x00, 0x04, 0x00, 0x0C, 0x09, 0x88, 0x88, 0x42
	.byte 0x03, 0xD3, 0x03, 0x49, 0x10, 0x1C, 0xFF, 0xF7, 0x99, 0xFF, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x79, 0x0D, 0x0C, 0x08

	thumb_func_start FUN_080c0e44
FUN_080c0e44: @ 0x080C0E44
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x76
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	subs r1, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080C0E70
	ldr r0, [r2, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x18]
	ldr r1, _080C0E74 @ =0x080C0DF5
	adds r0, r2, #0
	bl FUN_080c0d6c
_080C0E70:
	pop {r0}
	bx r0
	.align 2, 0
_080C0E74: .4byte 0x080C0DF5

	thumb_func_start FUN_080c0e78
FUN_080c0e78: @ 0x080C0E78
	push {lr}
	ldr r1, [r0, #0x78]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080C0E88:
	.byte 0x00, 0xB5, 0x18, 0x30, 0x69, 0xF1, 0x28, 0xFB
	.byte 0x00, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00

	thumb_func_start FUN_080c0e98
FUN_080c0e98: @ 0x080C0E98
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r5, r1, #0
	mov sb, r2
	mov r8, r3
	adds r6, r7, #0
	adds r6, #0x18
	adds r4, r7, #0
	adds r4, #0x44
	ldr r1, _080C0F18 @ =0x0000210E
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r7, #0x60]
	str r1, [r7, #0x64]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	movs r0, #1
	strb r0, [r6, #7]
	adds r0, r4, #0
	mov r1, sb
	bl FUN_0822b20c
	adds r0, r7, #0
	adds r0, #0x6a
	mov r1, r8
	strh r1, [r0]
	ldrh r0, [r0]
	strh r0, [r6, #0x10]
	adds r0, r7, #0
	adds r0, #0x6c
	mov r2, sp
	ldrh r2, [r2, #0x1c]
	strh r2, [r0]
	ldrh r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080C0F1C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x20]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C0F20
	asrs r0, r0, #0xc
	b _080C0F26
	.align 2, 0
_080C0F18: .4byte 0x0000210E
_080C0F1C: .4byte 0x085B0A08
_080C0F20:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C0F26:
	rsbs r0, r0, #0
	adds r1, r7, #0
	adds r1, #0x6e
	strh r0, [r1]
	ldr r1, _080C0F44 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x20]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C0F48
	asrs r0, r0, #0xc
	b _080C0F4E
	.align 2, 0
_080C0F44: .4byte 0x085B0A08
_080C0F48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C0F4E:
	rsbs r1, r0, #0
	adds r0, r7, #0
	adds r0, #0x70
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x72
	ldr r0, [sp, #0x24]
	strh r0, [r2]
	adds r1, r7, #0
	adds r1, #0x74
	ldr r0, [sp, #0x28]
	strh r0, [r1]
	ldrh r0, [r2]
	cmp r0, #0
	beq _080C0F84
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	ldr r1, _080C0F80 @ =FUN_080c0e44
	adds r0, r7, #0
	bl FUN_080c0d6c
	b _080C0F8C
	.align 2, 0
_080C0F80: .4byte FUN_080c0e44
_080C0F84:
	ldr r1, _080C0F9C @ =0x080C0DF5
	adds r0, r7, #0
	bl FUN_080c0d6c
_080C0F8C:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C0F9C: .4byte 0x080C0DF5

	thumb_func_start FUN_080c0fa0
FUN_080c0fa0: @ 0x080C0FA0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r0, #0xa
	movs r1, #0x7c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C0FF8
	ldr r1, _080C0FF0 @ =FUN_080c0e78
	ldr r2, _080C0FF4 @ =0x080C0E89
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x28]
	str r0, [sp, #4]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #8]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_080c0e98
	cmp r0, #0
	bge _080C0FF8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C0FFA
	.align 2, 0
_080C0FF0: .4byte FUN_080c0e78
_080C0FF4: .4byte 0x080C0E89
_080C0FF8:
	adds r0, r4, #0
_080C0FFA:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080c1008
FUN_080c1008: @ 0x080C1008
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	mov sb, r0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080C105C
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080C1054 @ =0xFFFF0000
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080C1058 @ =0x0000FFFF
	ldr r1, [sp, #0x10]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x10]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x14]
	b _080C1066
	.align 2, 0
_080C1054: .4byte 0xFFFF0000
_080C1058: .4byte 0x0000FFFF
_080C105C:
	ldr r1, _080C1078 @ =0xFFFF0000
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
_080C1066:
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _080C107C
	bl Script_GetValue
	adds r0, #0x2c
	b _080C107E
	.align 2, 0
_080C1078: .4byte 0xFFFF0000
_080C107C:
	movs r0, #0x2c
_080C107E:
	mov r8, r0
	movs r0, #0x45
	bl prepare_08231510
	cmp r0, #0
	beq _080C1092
	bl Script_GetValue
	adds r7, r0, #0
	b _080C1094
_080C1092:
	movs r7, #0
_080C1094:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _080C10A6
	bl Script_GetValue
	adds r6, r0, #0
	b _080C10A8
_080C10A6:
	movs r6, #0
_080C10A8:
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080C10BA
	bl Script_GetValue
	adds r5, r0, #0
	b _080C10BC
_080C10BA:
	movs r5, #0x20
_080C10BC:
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _080C10CE
	bl Script_GetValue
	adds r4, r0, #0
	b _080C10D0
_080C10CE:
	movs r4, #0
_080C10D0:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _080C10E0
	bl Script_GetValue
	b _080C10E2
_080C10E0:
	movs r0, #0x5a
_080C10E2:
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	str r0, [sp, #0xc]
	mov r0, sb
	add r1, sp, #0x10
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080c0e98
	movs r0, #0
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C1108:
	.byte 0x70, 0xB5, 0x05, 0x1C, 0x0E, 0x1C, 0x09, 0x20
	.byte 0x7C, 0x21, 0x6F, 0xF1, 0x4D, 0xFD, 0x04, 0x1C, 0x00, 0x2C, 0x13, 0xD0, 0x07, 0x49, 0x08, 0x4A
	.byte 0x6F, 0xF1, 0x6A, 0xFD, 0x20, 0x1C, 0x29, 0x1C, 0x32, 0x1C, 0xFF, 0xF7, 0x6D, 0xFF, 0x00, 0x28
	.byte 0x08, 0xDA, 0x20, 0x1C, 0x6F, 0xF1, 0x9A, 0xFD, 0x00, 0x20, 0x04, 0xE0, 0x79, 0x0E, 0x0C, 0x08
	.byte 0x89, 0x0E, 0x0C, 0x08, 0x20, 0x1C, 0x70, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080c1150
FUN_080c1150: @ 0x080C1150
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x96
	adds r0, #0x98
	ldrh r1, [r3]
	ldrh r0, [r0]
	cmp r1, r0
	bhi _080C116E
	movs r1, #1
	strh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x9e
	strh r1, [r0]
	b _080C1172
_080C116E:
	subs r0, r1, r0
	strh r0, [r3]
_080C1172:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c1178
FUN_080c1178: @ 0x080C1178
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0x18
	movs r5, #0
	ldr r2, _080C11EC @ =0x03002B4C
	ldr r1, [r2]
	adds r1, #0x24
	adds r0, #0x1e
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	bge _080C11E0
	mov r8, r2
_080C119A:
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
	cmp r0, #6
	bne _080C11CC
	adds r1, r7, #0
	adds r1, #0xac
	ldr r0, _080C11F0 @ =FUN_080c1150
	str r0, [r1]
	ldr r0, _080C11F4 @ =0x0000025D
	bl PlaySound_082406e0
_080C11CC:
	adds r5, #1
	mov r0, r8
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r6, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	blt _080C119A
_080C11E0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C11EC: .4byte 0x03002B4C
_080C11F0: .4byte FUN_080c1150
_080C11F4: .4byte 0x0000025D

	thumb_func_start FUN_080c11f8
FUN_080c11f8: @ 0x080C11F8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080c1178
	adds r0, r4, #0
	adds r0, #0xac
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #1
	bhi _080C121E
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	b _080C1224
_080C121E:
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
_080C1224:
	strh r0, [r1, #0x10]
	adds r0, r4, #0
	adds r0, #0x96
	ldrh r1, [r0]
	subs r0, #0x41
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x9c
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _080C124A
	movs r0, #0
	strh r0, [r1]
_080C124A:
	adds r0, r4, #0
	adds r0, #0x9e
	ldrh r0, [r0]
	cmp r0, #0
	beq _080C1264
	adds r0, r4, #0
	adds r0, #0x18
	movs r1, #1
	bl FUN_08022488
	adds r0, r4, #0
	bl KillEntity
_080C1264:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080c126c
FUN_080c126c: @ 0x080C126C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl FUN_08022428
	adds r4, #0x4c
	adds r0, r4, #0
	bl FUN_0822a4e0
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080c1288
FUN_080c1288: @ 0x080C1288
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	adds r2, r7, #0
	adds r2, #0x94
	strh r1, [r2]
	adds r0, #0x18
	ldrh r1, [r2]
	movs r2, #0xa
	bl FUN_080223f4
	movs r0, #0x70
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080C12D2
	bl Script_GetValue
	adds r4, r7, #0
	adds r4, #0xa4
	strh r0, [r4]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0xa6
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0xa8
	strh r0, [r1]
	mov sl, r4
	b _080C12E4
_080C12D2:
	adds r1, r7, #0
	adds r1, #0xa4
	strh r2, [r1]
	adds r0, r7, #0
	adds r0, #0xa6
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	mov sl, r1
_080C12E4:
	movs r0, #0x52
	bl prepare_08231510
	cmp r0, #0
	beq _080C12F4
	bl Script_GetValue
	b _080C12F6
_080C12F4:
	movs r0, #2
_080C12F6:
	mov sb, r0
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080C131A
	bl Script_GetValue
	adds r4, r7, #0
	adds r4, #0x9a
	strh r0, [r4]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r2, r4, #0
	b _080C132A
_080C131A:
	adds r2, r7, #0
	adds r2, #0x9a
	movs r0, #0x40
	strh r0, [r2]
	adds r1, r7, #0
	adds r1, #0x98
	movs r0, #2
	strh r0, [r1]
_080C132A:
	ldrh r0, [r2]
	movs r1, #0x96
	adds r1, r1, r7
	mov r8, r1
	movs r6, #0
	strh r0, [r1]
	adds r5, r7, #0
	adds r5, #0x4c
	adds r4, r7, #0
	adds r4, #0x78
	ldr r1, _080C139C @ =0x00003641
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #2
	bl FUN_0822a470
	adds r0, r4, #0
	movs r1, #0x32
	bl FUN_0822b20c
	strh r6, [r5, #0x10]
	mov r2, r8
	ldrh r0, [r2]
	strb r0, [r5, #8]
	strb r0, [r5, #9]
	ldr r0, [r7, #0x4c]
	movs r1, #2
	orrs r0, r1
	str r0, [r7, #0x4c]
	mov r0, sb
	strb r0, [r5, #7]
	mov r2, sl
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	adds r0, r7, #0
	adds r0, #0x9c
	strh r6, [r0]
	adds r0, #2
	strh r6, [r0]
	adds r1, r7, #0
	adds r1, #0xac
	ldr r0, _080C13A0 @ =0x080C114D
	str r0, [r1]
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C139C: .4byte 0x00003641
_080C13A0: .4byte 0x080C114D

	thumb_func_start FUN_080c13a4
FUN_080c13a4: @ 0x080C13A4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #0xa
	movs r1, #0xb0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C13E0
	ldr r1, _080C13D8 @ =FUN_080c11f8
	ldr r2, _080C13DC @ =FUN_080c126c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080c1288
	cmp r0, #0
	bge _080C13E0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C13E2
	.align 2, 0
_080C13D8: .4byte FUN_080c11f8
_080C13DC: .4byte FUN_080c126c
_080C13E0:
	adds r0, r4, #0
_080C13E2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080c13e8
FUN_080c13e8: @ 0x080C13E8
	movs r3, #0x9e
	lsls r3, r3, #1
	adds r2, r0, r3
	str r1, [r2]
	adds r0, #0x70
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start FUN_080c13f8
FUN_080c13f8: @ 0x080C13F8
	push {r4, r5, r6, lr}
	mov ip, r0
	ldr r3, [r0, #0x18]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	mov r2, ip
	str r0, [r2, #0x38]
	str r1, [r2, #0x3c]
	ldrh r0, [r2, #0x3a]
	adds r0, #0xc8
	strh r0, [r2, #0x3a]
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r3, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r1, _080C1454 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r4, [r0, r6]
	adds r0, r5, #0
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r2, [r0, r6]
	ldr r0, _080C1458 @ =0x000002E7
	adds r3, r3, r0
	ldrb r0, [r3]
	adds r6, r1, #0
	cmp r0, #0
	beq _080C14B2
	movs r0, #0xaa
	muls r0, r4, r0
	cmp r0, #0
	blt _080C145C
	asrs r0, r0, #0xc
	b _080C1462
	.align 2, 0
_080C1454: .4byte 0x085B0A08
_080C1458: .4byte 0x000002E7
_080C145C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C1462:
	adds r1, r0, #0
	lsls r0, r2, #3
	cmp r0, #0
	blt _080C146E
	asrs r0, r0, #0xc
	b _080C1474
_080C146E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C1474:
	adds r0, r1, r0
	mov r1, ip
	ldrh r1, [r1, #0x38]
	adds r0, r0, r1
	mov r3, ip
	strh r0, [r3, #0x38]
	movs r0, #0xaa
	muls r0, r2, r0
	cmp r0, #0
	blt _080C148C
	asrs r0, r0, #0xc
	b _080C1492
_080C148C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C1492:
	adds r1, r0, #0
	lsls r0, r4, #3
	cmp r0, #0
	blt _080C149E
	asrs r0, r0, #0xc
	b _080C14A4
_080C149E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C14A4:
	subs r0, r1, r0
	mov r1, ip
	ldrh r1, [r1, #0x3c]
	adds r0, r0, r1
	mov r2, ip
	strh r0, [r2, #0x3c]
	b _080C1512
_080C14B2:
	movs r0, #0xaa
	muls r0, r4, r0
	cmp r0, #0
	blt _080C14BE
	asrs r0, r0, #0xc
	b _080C14C4
_080C14BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C14C4:
	adds r1, r0, #0
	lsls r0, r2, #3
	cmp r0, #0
	blt _080C14D0
	asrs r0, r0, #0xc
	b _080C14D6
_080C14D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C14D6:
	subs r0, r1, r0
	mov r3, ip
	ldrh r3, [r3, #0x38]
	adds r0, r0, r3
	mov r1, ip
	strh r0, [r1, #0x38]
	movs r0, #0xaa
	muls r0, r2, r0
	cmp r0, #0
	blt _080C14EE
	asrs r0, r0, #0xc
	b _080C14F4
_080C14EE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C14F4:
	adds r1, r0, #0
	lsls r0, r4, #3
	cmp r0, #0
	blt _080C1500
	asrs r0, r0, #0xc
	b _080C1506
_080C1500:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C1506:
	adds r0, r1, r0
	mov r2, ip
	ldrh r2, [r2, #0x3c]
	adds r0, r0, r2
	mov r3, ip
	strh r0, [r3, #0x3c]
_080C1512:
	movs r2, #0xff
	lsrs r0, r5, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	mov r0, ip
	adds r0, #0x6e
	strb r1, [r0]
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r1, ip
	adds r1, #0x6c
	ldrh r0, [r1]
	muls r0, r2, r0
	adds r3, r1, #0
	cmp r0, #0
	blt _080C1542
	asrs r2, r0, #0xc
	b _080C1548
_080C1542:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C1548:
	mov r0, ip
	adds r0, #0x64
	strh r2, [r0]
	lsls r0, r5, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C1562
	asrs r1, r0, #0xc
	b _080C1568
_080C1562:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C1568:
	mov r0, ip
	adds r0, #0x68
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c1574
FUN_080c1574: @ 0x080C1574
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov ip, r0
	adds r0, #0x6e
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	mov sl, r0
	movs r0, #0xff
	mov r8, r0
	ldr r1, _080C15D0 @ =0x085B0A08
	mov sb, r1
	movs r7, #0
	str r7, [sp]
	mov r3, ip
	adds r3, #0x94
	mov r5, ip
	adds r5, #0xa8
	movs r6, #3
_080C15A6:
	ldrb r0, [r3, #0x10]
	cmp r0, #0
	beq _080C1644
	ldrh r0, [r3, #0x14]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0x14]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080C15D4
	strb r1, [r3, #0x10]
	mov r0, ip
	adds r0, #0x7c
	ldr r1, [sp]
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080C1644
	.align 2, 0
_080C15D0: .4byte 0x085B0A08
_080C15D4:
	ldrh r2, [r3, #0x12]
	ldrh r1, [r5]
	movs r0, #0x10
	subs r0, r0, r1
	muls r0, r2, r0
	asrs r4, r0, #3
	movs r0, #0x11
	ldrsb r0, [r3, r0]
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r0, r7
	mov r1, sl
	adds r2, r1, r0
	mov r7, r8
	ands r2, r7
	mov r7, ip
	ldr r0, [r7, #0x38]
	ldr r1, [r7, #0x3c]
	str r0, [r3]
	str r1, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x40
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r4, r0
	cmp r0, #0
	blt _080C1616
	asrs r1, r0, #0xc
	b _080C161C
_080C1616:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C161C:
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	mov r0, r8
	ands r2, r0
	lsls r0, r2, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080C1638
	asrs r1, r0, #0xc
	b _080C163E
_080C1638:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C163E:
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
_080C1644:
	ldr r7, [sp]
	adds r7, #0x30
	str r7, [sp]
	adds r3, #0x30
	adds r5, #0x30
	subs r6, #1
	cmp r6, #0
	bge _080C15A6
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c1664
FUN_080c1664: @ 0x080C1664
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0x77
	adds r0, r0, r7
	mov r8, r0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xa4
	movs r3, #0
	movs r1, #1
	strb r1, [r0]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r1, r7, #0
	adds r1, #0x7c
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xa8
	strh r3, [r0]
	ldr r6, _080C1760 @ =0x0203B400
	ldr r5, _080C1764 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r4, _080C1768 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	mov r0, r8
	ldrb r3, [r0]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #4
	adds r0, r7, r0
	asrs r2, r2, #3
	movs r3, #0x7f
	ands r2, r3
	adds r2, #0x40
	adds r0, #0xa6
	strh r2, [r0]
	adds r1, #1
	ands r1, r4
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	movs r1, #0x60
	bl Mod
	mov r1, r8
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	adds r1, r7, r1
	subs r0, #0x30
	adds r1, #0xa5
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x6e
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	mov r1, r8
	ldrb r0, [r1]
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #4
	adds r2, r7, r2
	adds r0, r2, #0
	adds r0, #0xa5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r4, r4, r0
	movs r3, #0xff
	ands r4, r3
	adds r2, #0x94
	ldr r0, [r7, #0x38]
	ldr r1, [r7, #0x3c]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xa6
	ldrh r2, [r0]
	ldr r1, _080C176C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C1770
	asrs r2, r0, #0xc
	b _080C1776
	.align 2, 0
_080C1760: .4byte 0x0203B400
_080C1764: .4byte 0x030046B8
_080C1768: .4byte 0x000003FF
_080C176C: .4byte 0x085B0A08
_080C1770:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C1776:
	adds r3, r7, #0
	adds r3, #0x77
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0x94
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xa6
	ldrh r2, [r0]
	ldr r1, _080C17B0 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C17B4
	asrs r2, r0, #0xc
	b _080C17BA
	.align 2, 0
_080C17B0: .4byte 0x085B0A08
_080C17B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C17BA:
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0x98
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080C17DE
	movs r0, #0
	strb r0, [r3]
_080C17DE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c17e8
FUN_080c17e8: @ 0x080C17E8
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #1
	adds r2, r0, #0
	adds r2, #0xa4
	adds r1, r0, #0
	movs r3, #3
_080C17F6:
	strb r5, [r2]
	ldr r0, [r1, #0x7c]
	orrs r0, r4
	str r0, [r1, #0x7c]
	adds r2, #0x30
	adds r1, #0x30
	subs r3, #1
	cmp r3, #0
	bge _080C17F6
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C1810:
	.byte 0x70, 0xB5, 0x04, 0x1C, 0xA0, 0x69, 0xDF, 0x21, 0x89, 0x00, 0x40, 0x18, 0x05, 0x78, 0x03, 0x2D
	.byte 0x03, 0xD0, 0x20, 0x1C, 0x6F, 0xF1, 0x22, 0xFA, 0x54, 0xE0, 0x20, 0x1C, 0xFF, 0xF7, 0xE4, 0xFD
	.byte 0xA0, 0x69, 0x0B, 0x49, 0x40, 0x18, 0x00, 0x78, 0x05, 0x28, 0x15, 0xD1, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0xD3, 0xFF, 0xE0, 0x69, 0x02, 0x21, 0x49, 0x42, 0x08, 0x40, 0xE0, 0x61, 0x20, 0x1C, 0x6F, 0x30
	.byte 0x00, 0x78, 0xA0, 0x85, 0x03, 0x49, 0x20, 0x1C, 0xFF, 0xF7, 0xC6, 0xFD, 0x3A, 0xE0, 0x00, 0x00
	.byte 0x7D, 0x03, 0x00, 0x00, 0xDD, 0x18, 0x0C, 0x08, 0x20, 0x1C, 0xFF, 0xF7, 0x83, 0xFE, 0xA0, 0x69
	.byte 0x0A, 0x49, 0x40, 0x18, 0x00, 0x78, 0x02, 0x28, 0x12, 0xD1, 0x21, 0x1C, 0x70, 0x31, 0x08, 0x88
	.byte 0x05, 0x40, 0x0E, 0x1C, 0x03, 0x2D, 0x02, 0xD1, 0x20, 0x1C, 0xFF, 0xF7, 0xEB, 0xFE, 0x21, 0x1C
	.byte 0x6F, 0x31, 0x00, 0x20, 0x08, 0x70, 0x0A, 0x1C, 0x0E, 0xE0, 0x00, 0x00, 0x7D, 0x03, 0x00, 0x00
	.byte 0xE0, 0x69, 0x02, 0x21, 0x49, 0x42, 0x08, 0x40, 0xE0, 0x61, 0x21, 0x1C, 0x6F, 0x31, 0x01, 0x20
	.byte 0x08, 0x70, 0x0A, 0x1C, 0x26, 0x1C, 0x70, 0x36, 0x30, 0x88, 0x80, 0x08, 0x01, 0x21, 0x08, 0x40
	.byte 0x00, 0x28, 0x02, 0xD0, 0x10, 0x78, 0x01, 0x30, 0x00, 0xE0, 0x10, 0x78, 0xA0, 0x85, 0x30, 0x88
	.byte 0x01, 0x30, 0x30, 0x80, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x00, 0xB5, 0x02, 0x1C
	.byte 0x64, 0x30, 0x00, 0x88, 0x11, 0x8F, 0x40, 0x18, 0x10, 0x87, 0x10, 0x1C, 0x68, 0x30, 0x00, 0x88
	.byte 0x91, 0x8F, 0x40, 0x18, 0x90, 0x87, 0x11, 0x1C, 0x70, 0x31, 0x08, 0x88, 0x01, 0x30, 0x08, 0x80
	.byte 0x02, 0x31, 0x00, 0x04, 0x00, 0x0C, 0x09, 0x88, 0x88, 0x42, 0x03, 0xD3, 0x02, 0x49, 0x10, 0x1C
	.byte 0xFF, 0xF7, 0x6A, 0xFD, 0x01, 0xBC, 0x00, 0x47, 0x1D, 0x19, 0x0C, 0x08

	thumb_func_start FUN_080c191c
FUN_080c191c: @ 0x080C191C
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x70
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _080C1938
	movs r0, #4
	strh r0, [r2, #0x2c]
	b _080C19A4
_080C1938:
	cmp r0, #4
	bne _080C199A
	adds r0, r2, #0
	adds r0, #0x6e
	adds r2, #0x1c
	ldrb r1, [r0]
	movs r3, #1
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _080C1952
	movs r0, #7
	b _080C1960
_080C1952:
	asrs r0, r1, #1
	ands r0, r3
	cmp r0, #0
	beq _080C195E
	movs r0, #8
	b _080C1960
_080C195E:
	movs r0, #6
_080C1960:
	strh r0, [r2, #0x10]
	cmp r1, #2
	bgt _080C196E
	ldr r0, [r2]
	movs r1, #0xd
	rsbs r1, r1, #0
	b _080C1994
_080C196E:
	cmp r1, #4
	bgt _080C197E
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #8
	b _080C1986
_080C197E:
	cmp r1, #5
	bgt _080C198C
	ldr r0, [r2]
	movs r1, #0xc
_080C1986:
	orrs r0, r1
	str r0, [r2]
	b _080C19A4
_080C198C:
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	subs r1, #0xd
_080C1994:
	ands r0, r1
	str r0, [r2]
	b _080C19A4
_080C199A:
	cmp r0, #6
	bls _080C19A4
	adds r0, r2, #0
	bl KillEntity
_080C19A4:
	pop {r0}
	bx r0
_080C19A8:
	.byte 0x00, 0xB5, 0x9E, 0x22, 0x52, 0x00, 0x81, 0x18
	.byte 0x09, 0x68, 0x8B, 0xF1, 0x57, 0xFA, 0x00, 0x20, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080c19bc
FUN_080c19bc: @ 0x080C19BC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	bl FUN_0822a4e0
	adds r4, #0x7c
	movs r5, #3
_080C19CA:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _080C19CA
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080c19e0
FUN_080c19e0: @ 0x080C19E0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x48
	ldr r1, _080C1A10 @ =0x0000210E
	adds r0, r5, #0
	bl FUN_0822b16c
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0822a470
	movs r0, #0
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	movs r1, #0x2e
	bl FUN_0822b20c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C1A10: .4byte 0x0000210E

	thumb_func_start FUN_080c1a14
FUN_080c1a14: @ 0x080C1A14
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x77
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080C1A7C @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r5, #0x78]
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
	adds r6, r5, #0
	adds r6, #0xa4
	adds r4, r5, #0
	adds r4, #0x7c
	movs r7, #3
_080C1A3C:
	ldr r1, [r5, #0x78]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, r8
	mov r2, r8
	bl FUN_0822dad4
	ldr r1, [r5, #0x78]
	adds r0, r4, #0
	movs r2, #0x11
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #0
	strb r0, [r6]
	adds r6, #0x30
	adds r4, #0x30
	subs r7, #1
	cmp r7, #0
	bge _080C1A3C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C1A7C: .4byte 0x00001C1E

	thumb_func_start FUN_080c1a80
FUN_080c1a80: @ 0x080C1A80
	push {r4, lr}
	adds r4, r0, #0
	str r1, [r4, #0x18]
	adds r0, #0x6c
	movs r1, #0
	strh r2, [r0]
	adds r0, #6
	strh r3, [r0]
	subs r0, #3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080c19e0
	adds r0, r4, #0
	bl FUN_080c13f8
	adds r0, r4, #0
	bl FUN_080c1a14
	ldr r1, _080C1AB8 @ =0x080C1811
	adds r0, r4, #0
	bl FUN_080c13e8
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080C1AB8: .4byte 0x080C1811

	thumb_func_start FUN_080c1abc
FUN_080c1abc: @ 0x080C1ABC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	movs r1, #0xa0
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C1B00
	ldr r1, _080C1AF8 @ =0x080C19A9
	ldr r2, _080C1AFC @ =FUN_080c19bc
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_080c1a80
	cmp r0, #0
	bge _080C1B00
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C1B02
	.align 2, 0
_080C1AF8: .4byte 0x080C19A9
_080C1AFC: .4byte FUN_080c19bc
_080C1B00:
	adds r0, r4, #0
_080C1B02:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080c1b08
FUN_080c1b08: @ 0x080C1B08
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x98
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, r4, #0
	bl FUN_082372cc
	adds r0, r5, #0
	adds r0, #0xf8
	adds r1, r4, #0
	bl FUN_082372cc
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_082372cc
	ldr r0, _080C1B40 @ =0x0000021E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C1B40: .4byte 0x0000021E

	thumb_func_start FUN_080c1b44
FUN_080c1b44: @ 0x080C1B44
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _080C1B74 @ =0x0000021E
	adds r6, r7, r0
	ldrh r0, [r6]
	cmp r0, #0x1d
	bhi _080C1B7C
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r7, #0
	adds r1, #0xb8
	movs r0, #0x3c
	strh r0, [r1]
	adds r1, #2
	ldr r0, _080C1B78 @ =0x0000FFE2
	b _080C1CDE
	.align 2, 0
_080C1B74: .4byte 0x0000021E
_080C1B78: .4byte 0x0000FFE2
_080C1B7C:
	cmp r0, #0x2c
	bhi _080C1BA4
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r7, #0
	adds r1, #0xb8
	movs r0, #0x3c
	strh r0, [r1]
	ldrh r0, [r6]
	lsls r0, r0, #1
	subs r0, #0x5a
	adds r3, r7, #0
	adds r3, #0xba
	strh r0, [r3]
	b _080C1CE0
_080C1BA4:
	cmp r0, #0x31
	bhi _080C1BF4
	ldr r0, _080C1BE8 @ =0x0203B400
	mov r8, r0
	ldr r4, _080C1BEC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C1BF0 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	adds r0, #0x3a
	adds r1, r7, #0
	adds r1, #0xb8
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	ldrh r2, [r6]
	movs r1, #0x2d
	subs r1, r1, r2
	b _080C1C34
	.align 2, 0
_080C1BE8: .4byte 0x0203B400
_080C1BEC: .4byte 0x030046B8
_080C1BF0: .4byte 0x000003FF
_080C1BF4:
	cmp r0, #0x36
	bhi _080C1C50
	ldr r0, _080C1C44 @ =0x0203B400
	mov r8, r0
	ldr r4, _080C1C48 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C1C4C @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	adds r0, #0x3a
	adds r1, r7, #0
	adds r1, #0xb8
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	ldrh r1, [r6]
	subs r1, #0x37
_080C1C34:
	lsls r1, r1, #1
	adds r1, r1, r0
	subs r1, #2
	adds r3, r7, #0
	adds r3, #0xba
	strh r1, [r3]
	b _080C1D56
	.align 2, 0
_080C1C44: .4byte 0x0203B400
_080C1C48: .4byte 0x030046B8
_080C1C4C: .4byte 0x000003FF
_080C1C50:
	cmp r0, #0x3b
	bhi _080C1C9C
	ldr r0, _080C1C90 @ =0x0203B400
	mov r8, r0
	ldr r4, _080C1C94 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C1C98 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	adds r0, #0x3a
	adds r1, r7, #0
	adds r1, #0xb8
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	subs r0, #2
	b _080C1CDA
	.align 2, 0
_080C1C90: .4byte 0x0203B400
_080C1C94: .4byte 0x030046B8
_080C1C98: .4byte 0x000003FF
_080C1C9C:
	cmp r0, #0x4f
	bhi _080C1CFC
	ldr r0, _080C1CF0 @ =0x0203B400
	mov r8, r0
	ldr r4, _080C1CF4 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C1CF8 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r0, #0x3b
	adds r1, r7, #0
	adds r1, #0xb8
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	subs r0, #1
_080C1CDA:
	adds r1, r7, #0
	adds r1, #0xba
_080C1CDE:
	strh r0, [r1]
_080C1CE0:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _080C1D56
	.align 2, 0
_080C1CF0: .4byte 0x0203B400
_080C1CF4: .4byte 0x030046B8
_080C1CF8: .4byte 0x000003FF
_080C1CFC:
	cmp r0, #0x59
	bhi _080C1D10
	adds r0, r7, #0
	adds r0, #0xb8
	movs r2, #0
	movs r1, #0x3c
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	b _080C1D56
_080C1D10:
	ldrh r0, [r6]
	movs r1, #0x2d
	bl Div
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	beq _080C1D3C
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _080C1D56
_080C1D3C:
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
_080C1D56:
	ldr r0, _080C1D6C @ =0x0000021E
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C1D6C: .4byte 0x0000021E

	thumb_func_start FUN_080c1d70
FUN_080c1d70: @ 0x080C1D70
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r5, r0, #0
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	cmp r1, #0
	beq _080C1D86
	bl _call_via_r1
_080C1D86:
	ldr r3, _080C1DD8 @ =0x0000022E
	adds r6, r5, r3
	ldrh r1, [r6]
	adds r4, r1, #0
	cmp r4, #0
	beq _080C1DE0
	adds r1, #1
	strh r1, [r6]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x10
	bhi _080C1DA0
	b _080C1F2C
_080C1DA0:
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080C1DCE
	ldr r1, _080C1DDC @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x10]
	add r1, sp, #0x10
	add r3, sp, #0xc
	str r3, [r1, #4]
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	adds r0, r2, #0
	bl Script_ExecById
_080C1DCE:
	adds r0, r5, #0
	bl KillEntity
	b _080C1F2C
	.align 2, 0
_080C1DD8: .4byte 0x0000022E
_080C1DDC: .4byte 0xFFFF0000
_080C1DE0:
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r3, _080C1E2C @ =0x00000226
	adds r2, r5, r3
	ldrh r1, [r1]
	ldrh r2, [r2]
	cmp r1, r2
	bne _080C1E34
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r2, [r1]
	adds r3, #4
	adds r1, r5, r3
	ldrh r1, [r1]
	subs r1, #0x10
	cmp r2, r1
	bne _080C1E34
	movs r0, #4
	str r0, [sp]
	ldr r0, _080C1E30 @ =0x0000FFFF
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #1
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r4, [r1]
	movs r1, #1
	strh r1, [r6]
	b _080C1F14
	.align 2, 0
_080C1E2C: .4byte 0x00000226
_080C1E30: .4byte 0x0000FFFF
_080C1E34:
	movs r3, #0x88
	lsls r3, r3, #2
	adds r1, r5, r3
	ldrh r1, [r1]
	cmp r1, #0x10
	bls _080C1E84
	ldr r1, _080C1E78 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r1, #9
	ands r1, r2
	cmp r1, #0
	beq _080C1E84
	movs r0, #4
	str r0, [sp]
	ldr r0, _080C1E7C @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #1
	strh r2, [r1]
	ldr r3, _080C1E80 @ =0x0000022E
	adds r1, r5, r3
	strh r2, [r1]
	b _080C1F14
	.align 2, 0
_080C1E78: .4byte 0x030044E0
_080C1E7C: .4byte 0x0000FFFF
_080C1E80: .4byte 0x0000022E
_080C1E84:
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r3, _080C1EE0 @ =0x0000022A
	adds r2, r5, r3
	ldrh r1, [r1]
	ldrh r2, [r2]
	cmp r1, r2
	blo _080C1F14
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	movs r2, #0
	strh r1, [r0]
	subs r3, #0xe
	adds r0, r5, r3
	ldrh r6, [r0]
	cmp r6, #1
	bne _080C1EE4
	adds r0, r5, #0
	adds r0, #0xf8
	adds r4, r5, #0
	adds r4, #0x18
	str r2, [sp]
	adds r1, r4, #0
	movs r2, #4
	movs r3, #1
	bl FUN_082370cc
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #1
	movs r3, #1
	bl Sprite_SetSprite
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	b _080C1EF8
	.align 2, 0
_080C1EE0: .4byte 0x0000022A
_080C1EE4:
	cmp r6, #3
	bne _080C1EF8
	movs r3, #0x8d
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r1, _080C1F34 @ =FUN_080c1b44
	str r1, [r0]
	ldr r1, _080C1F38 @ =0x0000021E
	adds r0, r5, r1
	strh r2, [r0]
_080C1EF8:
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	bl FUN_080477e4
	movs r3, #0x89
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	bl FUN_08047a28
_080C1F14:
	movs r1, #0x88
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	movs r3, #0x8a
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
_080C1F2C:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080C1F34: .4byte FUN_080c1b44
_080C1F38: .4byte 0x0000021E

	thumb_func_start FUN_080c1f3c
FUN_080c1f3c: @ 0x080C1F3C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x38
	movs r5, #4
_080C1F44:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080C1F44
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080c1f5c
FUN_080c1f5c: @ 0x080C1F5C
	push {lr}
	ldr r0, _080C1F80 @ =0x03003ED0
	ldr r1, [r0, #0x2c]
	movs r0, #0
	ldr r2, _080C1F84 @ =0x0000F001
	adds r3, r2, #0
_080C1F68:
	adds r2, r0, #1
	movs r0, #0x1f
_080C1F6C:
	strh r3, [r1]
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bge _080C1F6C
	adds r0, r2, #0
	cmp r0, #0x1f
	ble _080C1F68
	pop {r0}
	bx r0
	.align 2, 0
_080C1F80: .4byte 0x03003ED0
_080C1F84: .4byte 0x0000F001

	thumb_func_start FUN_080c1f88
FUN_080c1f88: @ 0x080C1F88
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080C1FA8
	ldr r1, _080C1FA0 @ =0x0000CFE1
	ldr r7, _080C1FA4 @ =0x0000ACBD
	movs r6, #0
	b _080C1FAE
	.align 2, 0
_080C1FA0: .4byte 0x0000CFE1
_080C1FA4: .4byte 0x0000ACBD
_080C1FA8:
	ldr r1, _080C2020 @ =0x0000A413
	ldr r7, _080C2024 @ =0x0000EFDA
	movs r6, #0xc
_080C1FAE:
	ldr r0, _080C2028 @ =0x0000C091
	bl GetFile
	adds r5, r0, #0
	movs r4, #0
	str r4, [sp, #0xc]
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	adds r2, r5, #0
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0822c398
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _080C202C @ =0x000092B3
	adds r1, r7, #0
	bl GetFile
	movs r1, #0xda
	lsls r1, r1, #1
	adds r3, r0, r1
	movs r1, #0xd
	ldr r5, _080C2030 @ =0x03004250
_080C1FFA:
	lsls r0, r1, #5
	adds r4, r1, #1
	adds r1, r0, r5
	movs r2, #0xf
_080C2002:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _080C2002
	adds r1, r4, #0
	cmp r1, #0xf
	ble _080C1FFA
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C2020: .4byte 0x0000A413
_080C2024: .4byte 0x0000EFDA
_080C2028: .4byte 0x0000C091
_080C202C: .4byte 0x000092B3
_080C2030: .4byte 0x03004250

	thumb_func_start FUN_080c2034
FUN_080c2034: @ 0x080C2034
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r0, _080C20F0 @ =0x0000CB05
	ldr r1, _080C20F4 @ =0x0000DF11
	bl GetFile
	adds r1, r0, #0
	adds r2, r7, #0
	adds r2, #0x18
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r6, r7, #0
	adds r6, #0x18
	adds r0, r6, #0
	bl FUN_0822f284
	ldr r1, _080C20F8 @ =0xFFFF0000
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0x38
	str r4, [sp]
	str r4, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0xf
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r0, r7, #0
	adds r0, #0x98
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0xb
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r3, #0xdc
	lsls r3, r3, #1
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #5
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r3, #0xac
	lsls r3, r3, #1
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C20F0: .4byte 0x0000CB05
_080C20F4: .4byte 0x0000DF11
_080C20F8: .4byte 0xFFFF0000

	thumb_func_start FUN_080c20fc
FUN_080c20fc: @ 0x080C20FC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, [r7, #0x40]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x40]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0xd
	bhi _080C21DC
	lsls r0, r0, #2
	ldr r1, _080C2124 @ =_080C2128
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080C2124: .4byte _080C2128
_080C2128: @ jump table
	.4byte _080C2160 @ case 0
	.4byte _080C216A @ case 1
	.4byte _080C2176 @ case 2
	.4byte _080C2182 @ case 3
	.4byte _080C2182 @ case 4
	.4byte _080C218E @ case 5
	.4byte _080C219A @ case 6
	.4byte _080C21A6 @ case 7
	.4byte _080C21A6 @ case 8
	.4byte _080C21B2 @ case 9
	.4byte _080C21B2 @ case 10
	.4byte _080C21B2 @ case 11
	.4byte _080C21BE @ case 12
	.4byte _080C21CA @ case 13
_080C2160:
	ldr r0, [r7, #0x40]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x40]
	b _080C21E2
_080C216A:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0xf
	b _080C21D4
_080C2176:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x10
	b _080C21D4
_080C2182:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x11
	b _080C21D4
_080C218E:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x12
	b _080C21D4
_080C219A:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x13
	b _080C21D4
_080C21A6:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x14
	b _080C21D4
_080C21B2:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x15
	b _080C21D4
_080C21BE:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x16
	b _080C21D4
_080C21CA:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x17
_080C21D4:
	movs r3, #1
	bl Sprite_SetSprite
	b _080C21E2
_080C21DC:
	movs r0, #1
	orrs r1, r0
	str r1, [r7, #0x40]
_080C21E2:
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0xc
	bls _080C21F0
	b _080C24BC
_080C21F0:
	lsls r0, r0, #2
	ldr r1, _080C21FC @ =_080C2200
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080C21FC: .4byte _080C2200
_080C2200: @ jump table
	.4byte _080C2234 @ case 0
	.4byte _080C22B0 @ case 1
	.4byte _080C23B4 @ case 2
	.4byte _080C2430 @ case 3
	.4byte _080C2338 @ case 4
	.4byte _080C24BC @ case 5
	.4byte _080C24BC @ case 6
	.4byte _080C24BC @ case 7
	.4byte _080C24BC @ case 8
	.4byte _080C23B4 @ case 9
	.4byte _080C24BC @ case 10
	.4byte _080C24BC @ case 11
	.4byte _080C2338 @ case 12
_080C2234:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080C22AC @ =FUN_080c1b08
	b _080C24F8
	.align 2, 0
_080C22AC: .4byte FUN_080c1b08
_080C22B0:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl FUN_082370cc
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl FUN_082370cc
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_SetSprite
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080C2334 @ =FUN_080c1b08
	b _080C24F8
	.align 2, 0
_080C2334: .4byte FUN_080c1b08
_080C2338:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #1
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl FUN_082370cc
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080C23B0 @ =FUN_080c1b08
	b _080C24F8
	.align 2, 0
_080C23B0: .4byte FUN_080c1b08
_080C23B4:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl FUN_082370cc
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080C242C @ =FUN_080c1b08
	b _080C24F8
	.align 2, 0
_080C242C: .4byte FUN_080c1b08
_080C2430:
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	adds r0, #0x98
	adds r5, r7, #0
	adds r5, #0x18
	movs r6, #0
	str r6, [sp]
	adds r1, r5, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	adds r1, r7, #0
	adds r1, #0xb8
	movs r0, #0x3c
	strh r0, [r1]
	adds r1, #2
	ldr r0, _080C24B4 @ =0x0000FFE2
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r1, r5, #0
	movs r2, #1
	movs r3, #1
	bl Sprite_SetSprite
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, _080C24B8 @ =0x0000FFBF
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x28
	strh r0, [r1]
	subs r2, #0x18
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r7, r1
	str r6, [r0]
	b _080C24FA
	.align 2, 0
_080C24B4: .4byte 0x0000FFE2
_080C24B8: .4byte 0x0000FFBF
_080C24BC:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	bl FUN_080c1f5c
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0
_080C24F8:
	str r0, [r1]
_080C24FA:
	movs r0, #0x88
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c250c
FUN_080c250c: @ 0x080C250C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne _080C252C
	movs r2, #0x89
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	b _080C2580
_080C252C:
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080C25B2
	bl FUN_0823d340
	movs r1, #0x86
	lsls r1, r1, #2
	adds r6, r5, r1
	str r0, [r6]
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080C25B2
	bl Script_GetValue
	movs r2, #0x89
	lsls r2, r2, #2
	adds r4, r5, r2
	strh r0, [r4]
	bl Script_GetValue
	ldrh r1, [r4]
	adds r1, r1, r0
	subs r1, #1
	ldr r2, _080C2594 @ =0x00000226
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _080C2598 @ =0x0000EFDA
	bl FUN_08047dc0
	ldr r0, [r6]
	bl FUN_080478f0
	movs r0, #1
	bl FUN_080477e4
	ldrh r0, [r4]
	bl FUN_08047a28
_080C2580:
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _080C25A0
	bl Script_GetValue
	ldr r2, _080C259C @ =0x0000022A
	adds r1, r5, r2
	b _080C25A6
	.align 2, 0
_080C2594: .4byte 0x00000226
_080C2598: .4byte 0x0000EFDA
_080C259C: .4byte 0x0000022A
_080C25A0:
	ldr r0, _080C25B8 @ =0x0000022A
	adds r1, r5, r0
	movs r0, #0x3c
_080C25A6:
	strh r0, [r1]
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
_080C25B2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C25B8: .4byte 0x0000022A

	thumb_func_start FUN_080c25bc
FUN_080c25bc: @ 0x080C25BC
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r0, #0x69
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080C25DC
	bl Script_GetValue
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	b _080C25E4
_080C25DC:
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
_080C25E4:
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080C25FE
	bl Script_GetValue
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	b _080C2606
_080C25FE:
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
_080C2606:
	adds r0, r4, #0
	bl FUN_080c1f88
	adds r0, r4, #0
	bl FUN_080c2034
	adds r0, r4, #0
	bl FUN_080c20fc
	adds r0, r4, #0
	bl FUN_080c250c
	movs r0, #4
	str r0, [sp]
	ldr r0, _080C263C @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080C263C: .4byte 0x0000FFFF

	thumb_func_start FUN_080c2640
FUN_080c2640: @ 0x080C2640
	push {r4, lr}
	movs r1, #0x8e
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C2678
	ldr r1, _080C2670 @ =FUN_080c1d70
	ldr r2, _080C2674 @ =FUN_080c1f3c
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080c25bc
	cmp r0, #0
	bge _080C2678
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C267A
	.align 2, 0
_080C2670: .4byte FUN_080c1d70
_080C2674: .4byte FUN_080c1f3c
_080C2678:
	adds r0, r4, #0
_080C267A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080c2680
FUN_080c2680: @ 0x080C2680
	movs r3, #0xa9
	lsls r3, r3, #2
	adds r2, r0, r3
	str r1, [r2]
	movs r1, #0
	strh r1, [r0, #4]
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080c2694
FUN_080c2694: @ 0x080C2694
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r6, r1, #0
	ldr r0, _080C26A4 @ =0x00000165
	cmp r6, r0
	bne _080C26A8
	movs r0, #0
	b _080C26AA
	.align 2, 0
_080C26A4: .4byte 0x00000165
_080C26A8:
	movs r0, #1
_080C26AA:
	strb r0, [r2, #2]
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r4, r2, r0
	movs r5, #7
_080C26B4:
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_0822b20c
	adds r4, #0x1c
	subs r5, #1
	cmp r5, #0
	bge _080C26B4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C26CC:
	.byte 0xF0, 0xB5, 0x47, 0x46
	.byte 0x80, 0xB4, 0x06, 0x1C, 0xB0, 0x88, 0x00, 0x28, 0x1F, 0xD1, 0x70, 0x78, 0x31, 0x1C, 0x24, 0x31
	.byte 0x0D, 0x30, 0x08, 0x82, 0x02, 0x23, 0x5B, 0x42, 0xAC, 0x20, 0x40, 0x00, 0x32, 0x18, 0x08, 0x68
	.byte 0x18, 0x40, 0x08, 0x60, 0x2C, 0x31, 0x91, 0x42, 0xF9, 0xDD, 0xB0, 0x78, 0x01, 0x28, 0x05, 0xD1
	.byte 0x25, 0x49, 0x30, 0x1C, 0xFF, 0xF7, 0xC6, 0xFF, 0x06, 0x20, 0xF0, 0x70, 0x00, 0x20, 0xB0, 0x83
	.byte 0xF0, 0x83, 0x30, 0x84, 0xB0, 0x88, 0x01, 0x30, 0xB0, 0x80, 0xB2, 0x69, 0x11, 0x68, 0xF0, 0x69
	.byte 0x81, 0x42, 0x05, 0xD1, 0x04, 0x23, 0xD1, 0x5E, 0x20, 0x24, 0x30, 0x5F, 0x81, 0x42, 0x73, 0xD0
	.byte 0x53, 0x68, 0x12, 0x68, 0x10, 0x1C, 0x31, 0x89, 0x40, 0x18, 0x00, 0x04, 0x00, 0x0C, 0x17, 0x4D
	.byte 0x29, 0x1C, 0x11, 0x40, 0x01, 0x43, 0x08, 0x14, 0x74, 0x89, 0x00, 0x19, 0x00, 0x04, 0x14, 0x4C
	.byte 0x0C, 0x40, 0x04, 0x43, 0x22, 0x1C, 0x18, 0x1C, 0xB1, 0x89, 0x40, 0x18, 0x00, 0x04, 0x00, 0x0C
	.byte 0x1D, 0x40, 0x2B, 0x1C, 0x03, 0x43, 0x00, 0x20, 0x84, 0x46, 0x10, 0x04, 0x00, 0x14, 0x80, 0x46
	.byte 0x37, 0x1C, 0x40, 0x37, 0x24, 0x14, 0x18, 0x04, 0x02, 0x14, 0x08, 0x20, 0x61, 0x46, 0x45, 0x1A
	.byte 0x10, 0x23, 0xF0, 0x5E, 0x61, 0x46, 0x41, 0x43, 0x40, 0x46, 0x68, 0x43, 0x08, 0x18, 0x00, 0x28
	.byte 0x08, 0xDB, 0xC0, 0x10, 0x09, 0xE0, 0x00, 0x00, 0x67, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF
	.byte 0xFF, 0xFF, 0x00, 0x00, 0x40, 0x42, 0xC0, 0x10, 0x40, 0x42, 0x38, 0x80, 0x12, 0x21, 0x70, 0x5E
	.byte 0x61, 0x46, 0x41, 0x43, 0x20, 0x1C, 0x68, 0x43, 0x08, 0x18, 0x00, 0x28, 0x01, 0xDB, 0xC0, 0x10
	.byte 0x02, 0xE0, 0x40, 0x42, 0xC0, 0x10, 0x40, 0x42, 0x78, 0x80, 0x14, 0x23, 0xF0, 0x5E, 0x61, 0x46
	.byte 0x41, 0x43, 0x10, 0x1C, 0x68, 0x43, 0x08, 0x18, 0x00, 0x28, 0x01, 0xDB, 0xC0, 0x10, 0x02, 0xE0
	.byte 0x40, 0x42, 0xC0, 0x10, 0x40, 0x42, 0xB8, 0x80, 0x2C, 0x37, 0x01, 0x20, 0x84, 0x44, 0x61, 0x46
	.byte 0x07, 0x29, 0xC2, 0xDD, 0xF0, 0x78, 0x00, 0x28, 0x09, 0xD0, 0x01, 0x38, 0xF0, 0x70, 0x00, 0x06
	.byte 0x00, 0x28, 0x04, 0xD1, 0xB3, 0x21, 0x49, 0x00, 0x30, 0x1C, 0xFF, 0xF7, 0x43, 0xFF, 0xB0, 0x69
	.byte 0x41, 0x68, 0x00, 0x68, 0xF0, 0x61, 0x31, 0x62, 0x08, 0xBC, 0x98, 0x46, 0xF0, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00, 0xF0, 0xB5, 0x4F, 0x46, 0x46, 0x46, 0xC0, 0xB4, 0x84, 0x46, 0x80, 0x88
	.byte 0x00, 0x28, 0x32, 0xD1, 0x61, 0x46, 0x48, 0x78, 0x88, 0x86, 0x23, 0x4A, 0x91, 0x46, 0x23, 0x4F
	.byte 0xB8, 0x46, 0x23, 0x4E, 0x1F, 0x25, 0x63, 0x46, 0x07, 0x24, 0x40, 0x46, 0x01, 0x68, 0x01, 0x31
	.byte 0x31, 0x40, 0x48, 0x00, 0x48, 0x44, 0x00, 0x88, 0x28, 0x40, 0x10, 0x38, 0x99, 0x27, 0xBF, 0x00
	.byte 0xDA, 0x19, 0x10, 0x80, 0x01, 0x31, 0x31, 0x40, 0x48, 0x00, 0x48, 0x44, 0x00, 0x88, 0x28, 0x40
	.byte 0x18, 0x38, 0x02, 0x37, 0xDA, 0x19, 0x10, 0x80, 0x01, 0x31, 0x31, 0x40, 0x40, 0x46, 0x01, 0x60
	.byte 0x49, 0x00, 0x49, 0x44, 0x08, 0x88, 0x28, 0x40, 0x10, 0x38, 0x9A, 0x22, 0x92, 0x00, 0x99, 0x18
	.byte 0x08, 0x80, 0x08, 0x33, 0x01, 0x3C, 0x00, 0x2C, 0xD7, 0xDA, 0x67, 0x46, 0xB8, 0x88, 0x41, 0x1C
	.byte 0xB9, 0x80, 0x08, 0x04, 0x00, 0x0C, 0x59, 0x28, 0x14, 0xD9, 0x00, 0x20, 0x38, 0x70, 0x01, 0x23
	.byte 0x61, 0x46, 0x24, 0x31, 0xAC, 0x22, 0x52, 0x00, 0x62, 0x44, 0x08, 0x68, 0x18, 0x43, 0x08, 0x60
	.byte 0x2C, 0x31, 0x91, 0x42, 0xF9, 0xDD, 0x51, 0xE0, 0x00, 0xB4, 0x03, 0x02, 0xB8, 0x46, 0x00, 0x03
	.byte 0xFF, 0x03, 0x00, 0x00, 0x00, 0x25, 0x09, 0x04, 0x08, 0x0C, 0x3C, 0x28, 0x02, 0xD9, 0x8D, 0x0C
	.byte 0x01, 0x20, 0x05, 0x40, 0x07, 0x4C, 0x64, 0x44, 0x62, 0x46, 0x40, 0x32, 0x63, 0x46, 0x24, 0x33
	.byte 0xAC, 0x26, 0x76, 0x00, 0x66, 0x44, 0x00, 0x2D, 0x06, 0xD0, 0x18, 0x68, 0x01, 0x21, 0x08, 0x43
	.byte 0x06, 0xE0, 0x00, 0x00, 0x66, 0x02, 0x00, 0x00, 0x18, 0x68, 0x02, 0x21, 0x49, 0x42, 0x08, 0x40
	.byte 0x18, 0x60, 0x99, 0x20, 0x80, 0x00, 0x60, 0x44, 0x00, 0x88, 0x11, 0x88, 0x40, 0x18, 0x10, 0x80
	.byte 0x20, 0x88, 0x57, 0x88, 0xC0, 0x19, 0x50, 0x80, 0x9A, 0x20, 0x80, 0x00, 0x60, 0x44, 0x00, 0x88
	.byte 0x91, 0x88, 0x40, 0x18, 0x90, 0x80, 0x20, 0x88, 0x01, 0x38, 0x20, 0x80, 0x02, 0x27, 0xD0, 0x5F
	.byte 0xFF, 0x28, 0x0C, 0xDC, 0x80, 0x20, 0x40, 0x00, 0x50, 0x80, 0x00, 0x20, 0x21, 0x5E, 0x48, 0x42
	.byte 0x00, 0x28, 0x01, 0xDB, 0x40, 0x10, 0x01, 0xE0, 0x48, 0x10, 0x40, 0x42, 0x20, 0x80, 0x08, 0x34
	.byte 0x08, 0x21, 0x8C, 0x44, 0x2C, 0x32, 0x2C, 0x33, 0xB3, 0x42, 0xC4, 0xDD, 0x18, 0xBC, 0x98, 0x46
	.byte 0xA1, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_080c2978
FUN_080c2978: @ 0x080C2978
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrh r0, [r6, #4]
	cmp r0, #0
	bne _080C29AA
	ldrb r0, [r6, #1]
	adds r1, r6, #0
	adds r1, #0x24
	strh r0, [r1, #0x10]
	movs r3, #2
	rsbs r3, r3, #0
	movs r0, #0xac
	lsls r0, r0, #1
	adds r2, r6, r0
_080C2994:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _080C2994
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r6, #0
	bl FUN_080c2694
_080C29AA:
	ldr r0, [r6, #0x18]
	ldr r4, [r0]
	ldr r5, [r0, #4]
	adds r0, r4, #0
	ldrh r1, [r6, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _080C2A00 @ =0xFFFF0000
	adds r1, r3, #0
	ands r1, r4
	orrs r1, r0
	asrs r0, r1, #0x10
	ldrh r2, [r6, #0xa]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	ldr r2, _080C2A04 @ =0x0000FFFF
	ands r1, r2
	adds r4, r1, #0
	orrs r4, r0
	adds r0, r5, #0
	ldrh r1, [r6, #0xc]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r3, r5
	adds r5, r3, #0
	orrs r5, r0
	movs r0, #0x10
	ldrsh r2, [r6, r0]
	ldrh r1, [r6, #4]
	movs r0, #4
	subs r0, r0, r1
	muls r2, r0, r2
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r0, r2, r0
	adds r3, r1, #0
	cmp r0, #0
	blt _080C2A08
	asrs r0, r0, #2
	b _080C2A0E
	.align 2, 0
_080C2A00: .4byte 0xFFFF0000
_080C2A04: .4byte 0x0000FFFF
_080C2A08:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C2A0E:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080C2A34 @ =0xFFFF0000
	ands r1, r4
	orrs r1, r0
	adds r4, r1, #0
	movs r0, #0x12
	ldrsh r2, [r6, r0]
	movs r0, #4
	subs r0, r0, r3
	muls r2, r0, r2
	asrs r1, r1, #0x10
	adds r0, r1, #0
	muls r0, r3, r0
	adds r0, r2, r0
	cmp r0, #0
	blt _080C2A38
	asrs r0, r0, #2
	b _080C2A3E
	.align 2, 0
_080C2A34: .4byte 0xFFFF0000
_080C2A38:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C2A3E:
	lsls r1, r0, #0x10
	ldr r0, _080C2A64 @ =0x0000FFFF
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	movs r2, #0x14
	ldrsh r1, [r6, r2]
	movs r0, #4
	subs r0, r0, r3
	muls r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C2A68
	asrs r0, r0, #2
	b _080C2A6E
	.align 2, 0
_080C2A64: .4byte 0x0000FFFF
_080C2A68:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C2A6E:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080C2AA8 @ =0xFFFF0000
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	movs r3, #0
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	mov ip, r0
	adds r2, r6, #0
	adds r2, #0x40
	asrs r7, r4, #0x10
	lsls r0, r5, #0x10
	asrs r5, r0, #0x10
_080C2A8C:
	movs r0, #8
	subs r4, r0, r3
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	adds r1, r0, #0
	muls r1, r3, r1
	mov r0, ip
	muls r0, r4, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C2AAC
	asrs r0, r0, #3
	b _080C2AB2
	.align 2, 0
_080C2AA8: .4byte 0xFFFF0000
_080C2AAC:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080C2AB2:
	strh r0, [r2]
	movs r1, #0x12
	ldrsh r0, [r6, r1]
	adds r1, r0, #0
	muls r1, r3, r1
	adds r0, r7, #0
	muls r0, r4, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C2ACA
	asrs r0, r0, #3
	b _080C2AD0
_080C2ACA:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080C2AD0:
	strh r0, [r2, #2]
	movs r1, #0x14
	ldrsh r0, [r6, r1]
	adds r1, r0, #0
	muls r1, r3, r1
	adds r0, r5, #0
	muls r0, r4, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C2AE8
	asrs r0, r0, #3
	b _080C2AEE
_080C2AE8:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080C2AEE:
	strh r0, [r2, #4]
	adds r2, #0x2c
	adds r3, #1
	cmp r3, #7
	ble _080C2A8C
	ldrh r0, [r6, #4]
	adds r0, #1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _080C2B14
	ldr r0, _080C2B1C @ =0x00000233
	bl PlaySound_082406e0
	ldr r1, _080C2B20 @ =0x080C26CD
	adds r0, r6, #0
	bl FUN_080c2680
_080C2B14:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C2B1C: .4byte 0x00000233
_080C2B20: .4byte 0x080C26CD

	thumb_func_start FUN_080c2b24
FUN_080c2b24: @ 0x080C2B24
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _080C2B58 @ =0x00001934
	adds r4, r6, r0
	movs r7, #0
	movs r5, #3
_080C2B30:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080C2B44
	ldr r1, _080C2B5C @ =0x00001BD8
	adds r0, r6, r1
	adds r0, r0, r7
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080C2B44:
	movs r0, #0xaa
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r7, r7, r0
	subs r5, #1
	cmp r5, #0
	bge _080C2B30
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C2B58: .4byte 0x00001934
_080C2B5C: .4byte 0x00001BD8

	thumb_func_start FUN_080c2b60
FUN_080c2b60: @ 0x080C2B60
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r1, _080C2BA0 @ =0x00001930
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C2B98
	movs r1, #0
_080C2B70:
	movs r5, #0
	lsls r0, r1, #2
	adds r6, r1, #1
	adds r0, r0, r1
	lsls r1, r0, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r7
	ldr r1, _080C2BA4 @ =0x00001958
	adds r4, r0, r1
_080C2B84:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x2c
	adds r5, #1
	cmp r5, #7
	ble _080C2B84
	adds r1, r6, #0
	cmp r1, #3
	ble _080C2B70
_080C2B98:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C2BA0: .4byte 0x00001930
_080C2BA4: .4byte 0x00001958

	thumb_func_start FUN_080c2ba8
FUN_080c2ba8: @ 0x080C2BA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	ldr r1, _080C2C08 @ =0x00001930
	adds r1, r0, r1
	str r1, [sp, #4]
	movs r0, #1
	strb r0, [r1]
	movs r2, #0
	mov r8, r2
	movs r3, #0xc0
	mov sl, r3
_080C2BC8:
	mov r1, r8
	lsls r0, r1, #2
	add r0, r8
	lsls r1, r0, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #4
	ldr r2, [sp, #4]
	adds r4, r2, r0
	movs r3, #0
	strb r3, [r4]
	mov r0, r8
	strb r0, [r4, #1]
	strb r3, [r4, #2]
	movs r0, #0xa0
	lsls r0, r0, #3
	strh r0, [r4, #0x10]
	movs r0, #0xe0
	lsls r0, r0, #3
	strh r0, [r4, #0x12]
	movs r0, #0xd1
	lsls r0, r0, #2
	strh r0, [r4, #0x14]
	mov r1, r8
	cmp r1, #1
	beq _080C2C28
	cmp r1, #1
	bgt _080C2C0C
	cmp r1, #0
	beq _080C2C18
	b _080C2C54
	.align 2, 0
_080C2C08: .4byte 0x00001930
_080C2C0C:
	mov r2, r8
	cmp r2, #2
	beq _080C2C38
	cmp r2, #3
	beq _080C2C48
	b _080C2C54
_080C2C18:
	ldr r0, _080C2C24 @ =0x0000FFC8
	strh r0, [r4, #8]
	mov r3, sl
	strh r3, [r4, #0xa]
	subs r0, #0x10
	b _080C2C52
	.align 2, 0
_080C2C24: .4byte 0x0000FFC8
_080C2C28:
	ldr r0, _080C2C34 @ =0x0000FF98
	strh r0, [r4, #8]
	mov r0, sl
	strh r0, [r4, #0xa]
	movs r0, #0x58
	b _080C2C52
	.align 2, 0
_080C2C34: .4byte 0x0000FF98
_080C2C38:
	movs r0, #0x68
	strh r0, [r4, #8]
	mov r1, sl
	strh r1, [r4, #0xa]
	ldr r0, _080C2C44 @ =0x0000FFA0
	b _080C2C52
	.align 2, 0
_080C2C44: .4byte 0x0000FFA0
_080C2C48:
	movs r0, #0x38
	strh r0, [r4, #8]
	mov r2, sl
	strh r2, [r4, #0xa]
	movs r0, #0x48
_080C2C52:
	strh r0, [r4, #0xc]
_080C2C54:
	movs r3, #8
	ldrsh r0, [r4, r3]
	ldrh r1, [r4, #8]
	cmp r0, #0
	ble _080C2C78
	ldrh r2, [r4, #0xc]
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	cmp r0, #0
	ble _080C2C78
	ldrh r0, [r4, #0x10]
	adds r0, #0x60
	adds r0, r1, r0
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0x14]
	subs r0, #0x60
	adds r0, r2, r0
	b _080C2CAE
_080C2C78:
	lsls r0, r1, #0x10
	cmp r0, #0
	bge _080C2C98
	ldrh r2, [r4, #0xc]
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	cmp r0, #0
	bge _080C2C98
	ldrh r0, [r4, #0x10]
	subs r0, #0x30
	adds r0, r1, r0
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0x14]
	adds r0, #0x30
	adds r0, r2, r0
	b _080C2CAE
_080C2C98:
	movs r1, #8
	ldrsh r0, [r4, r1]
	lsls r0, r0, #2
	ldrh r2, [r4, #0x10]
	adds r0, r0, r2
	strh r0, [r4, #0x10]
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	ldrh r1, [r4, #0x14]
	adds r0, r0, r1
_080C2CAE:
	strh r0, [r4, #0x14]
	movs r3, #0
	movs r2, #1
	add r2, r8
	mov sb, r2
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r7, r4, r0
_080C2CBE:
	movs r0, #0x2c
	muls r0, r3, r0
	adds r0, #0x24
	adds r6, r4, r0
	cmp r3, #0
	bne _080C2CD8
	ldr r1, _080C2CD4 @ =0x00008205
	mov r5, r8
	adds r5, #0xd
	b _080C2CDC
	.align 2, 0
_080C2CD4: .4byte 0x00008205
_080C2CD8:
	ldr r1, _080C2D2C @ =0x00008207
	movs r5, #6
_080C2CDC:
	adds r0, r7, #0
	str r3, [sp, #8]
	bl FUN_0822b16c
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0822a470
	strh r5, [r6, #0x10]
	movs r0, #1
	strb r0, [r6, #7]
	adds r7, #0x1c
	ldr r3, [sp, #8]
	adds r3, #1
	cmp r3, #7
	ble _080C2CBE
	adds r0, r4, #0
	ldr r1, _080C2D30 @ =0x00000165
	bl FUN_080c2694
	ldr r1, [sp]
	ldr r2, _080C2D34 @ =0x00000424
	adds r0, r1, r2
	ldr r0, [r0]
	str r0, [r4, #0x18]
	mov r8, sb
	mov r3, r8
	cmp r3, #3
	bgt _080C2D1A
	b _080C2BC8
_080C2D1A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C2D2C: .4byte 0x00008207
_080C2D30: .4byte 0x00000165
_080C2D34: .4byte 0x00000424

	thumb_func_start FUN_080c2d38
FUN_080c2d38: @ 0x080C2D38
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov r8, r0
	ldr r0, _080C2DA8 @ =0x00000DB9
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C2D50
	b _080C2E72
_080C2D50:
	movs r7, #0
	ldr r0, _080C2DAC @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r6, r0, #0x1f
	movs r5, #0
_080C2D66:
	movs r0, #0x54
	adds r1, r5, #0
	muls r1, r0, r1
	mov r2, r8
	adds r0, r2, r1
	ldr r3, _080C2DB0 @ =0x00000E14
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C2E64
	ldr r4, _080C2DB4 @ =0x00000DC4
	adds r0, r1, r4
	adds r4, r2, r0
	adds r1, r4, #0
	adds r1, #0x51
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	adds r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _080C2DB8
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r0, r4, #0
	adds r0, #0x50
	strb r2, [r0]
	b _080C2E64
	.align 2, 0
_080C2DA8: .4byte 0x00000DB9
_080C2DAC: .4byte 0x03002BE0
_080C2DB0: .4byte 0x00000E14
_080C2DB4: .4byte 0x00000DC4
_080C2DB8:
	movs r7, #1
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r0, [r0]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	ldrh r2, [r4, #0x1e]
	adds r0, r0, r2
	strh r0, [r4, #0x1e]
	adds r0, r4, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	ldrh r3, [r4, #0x20]
	adds r0, r0, r3
	strh r0, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x53
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C2E32
	cmp r6, #0
	bne _080C2E32
	ldr r0, _080C2E44 @ =0x03002BE0
	ldr r2, [r0]
	movs r0, #0x2c
	ldrsh r1, [r2, r0]
	movs r3, #0x1c
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _080C2E00
	rsbs r1, r1, #0
_080C2E00:
	cmp r1, #0x3f
	bgt _080C2E32
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	movs r3, #0x20
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _080C2E14
	rsbs r1, r1, #0
_080C2E14:
	cmp r1, #0x3f
	bgt _080C2E32
	ldr r0, _080C2E48 @ =0x00000DBE
	add r0, r8
	ldrh r1, [r0]
	movs r0, #4
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	adds r0, r2, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0807e7fc
	movs r6, #1
_080C2E32:
	adds r1, r4, #0
	adds r1, #0x51
	ldrb r0, [r1]
	cmp r0, #0x2c
	bhi _080C2E4C
	movs r1, #4
	bl Div
	b _080C2E62
	.align 2, 0
_080C2E44: .4byte 0x03002BE0
_080C2E48: .4byte 0x00000DBE
_080C2E4C:
	cmp r0, #0x47
	bne _080C2E54
	movs r0, #0xe
	b _080C2E62
_080C2E54:
	cmp r0, #0x4a
	bne _080C2E5C
	movs r0, #5
	b _080C2E62
_080C2E5C:
	cmp r0, #0x4d
	bne _080C2E64
	movs r0, #2
_080C2E62:
	strh r0, [r4, #0x10]
_080C2E64:
	adds r5, #1
	cmp r5, #0x1f
	bgt _080C2E6C
	b _080C2D66
_080C2E6C:
	ldr r0, _080C2F1C @ =0x00000DB9
	add r0, r8
	strb r7, [r0]
_080C2E72:
	ldr r2, _080C2F20 @ =0x00000DBC
	add r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne _080C2E7E
	b _080C30FE
_080C2E7E:
	ldr r1, _080C2F24 @ =0x00000DBB
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080C2E92
	b _080C30F6
_080C2E92:
	ldr r0, _080C2F28 @ =0x00000DBA
	add r0, r8
	ldrb r1, [r0]
	movs r0, #0x54
	muls r0, r1, r0
	ldr r4, _080C2F2C @ =0x00000DC4
	adds r0, r0, r4
	mov r1, r8
	adds r7, r1, r0
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	movs r0, #0
	strh r0, [r7, #0x10]
	ldrb r0, [r2]
	cmp r0, #1
	bne _080C2F90
	ldr r2, _080C2F30 @ =0x0203B400
	mov sb, r2
	ldr r4, _080C2F34 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C2F38 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x30
	bl Mod
	adds r6, r0, #0
	adds r6, #0x28
	ldr r1, [r4]
	adds r1, #1
	ands r1, r5
	lsls r2, r1, #1
	add r2, sb
	ldrh r2, [r2]
	movs r3, #0x7f
	ands r2, r3
	adds r3, #0xc1
	adds r3, r3, r2
	mov ip, r3
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sb
	ldrh r1, [r1]
	movs r2, #3
	ands r1, r2
	adds r5, r1, #3
	ldr r2, _080C2F3C @ =0x085B0A08
	adds r0, #0x68
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r5, r0
	cmp r0, #0
	blt _080C2F40
	asrs r0, r0, #0xc
	b _080C2F46
	.align 2, 0
_080C2F1C: .4byte 0x00000DB9
_080C2F20: .4byte 0x00000DBC
_080C2F24: .4byte 0x00000DBB
_080C2F28: .4byte 0x00000DBA
_080C2F2C: .4byte 0x00000DC4
_080C2F30: .4byte 0x0203B400
_080C2F34: .4byte 0x030046B8
_080C2F38: .4byte 0x000003FF
_080C2F3C: .4byte 0x085B0A08
_080C2F40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C2F46:
	adds r2, r7, #0
	adds r2, #0x48
	strh r0, [r2]
	adds r1, r7, #0
	adds r1, #0x4a
	movs r0, #3
	strh r0, [r1]
	ldr r1, _080C2F70 @ =0x085B0A08
	movs r0, #0xff
	ands r6, r0
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _080C2F74
	asrs r2, r0, #0xc
	b _080C2F7A
	.align 2, 0
_080C2F70: .4byte 0x085B0A08
_080C2F74:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C2F7A:
	adds r1, r7, #0
	adds r1, #0x4c
	movs r0, #0
	strh r2, [r1]
	adds r3, r7, #0
	adds r3, #0x53
	strb r0, [r3]
	ldr r3, _080C2F8C @ =0x030046B8
	b _080C3030
	.align 2, 0
_080C2F8C: .4byte 0x030046B8
_080C2F90:
	ldr r5, _080C2FE0 @ =0x0203B400
	ldr r3, _080C2FE4 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r4, _080C2FE8 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	asrs r2, r2, #3
	movs r0, #0x1f
	ands r2, r0
	adds r6, r2, #0
	adds r6, #0x30
	movs r0, #0xc0
	lsls r0, r0, #1
	mov ip, r0
	adds r1, #1
	ands r1, r4
	str r1, [r3]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	movs r1, #7
	ands r0, r1
	adds r5, r0, #0
	adds r5, #0xa
	ldr r1, _080C2FEC @ =0x085B0A08
	adds r2, #0x70
	lsls r2, r2, #1
	adds r2, r2, r1
	movs r4, #0
	ldrsh r0, [r2, r4]
	muls r0, r5, r0
	adds r2, r1, #0
	cmp r0, #0
	blt _080C2FF0
	asrs r4, r0, #0xc
	b _080C2FF6
	.align 2, 0
_080C2FE0: .4byte 0x0203B400
_080C2FE4: .4byte 0x030046B8
_080C2FE8: .4byte 0x000003FF
_080C2FEC: .4byte 0x085B0A08
_080C2FF0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r4, r0, #0
_080C2FF6:
	adds r1, r7, #0
	adds r1, #0x48
	movs r0, #0
	strh r4, [r1]
	adds r4, r7, #0
	adds r4, #0x4a
	strh r0, [r4]
	movs r0, #0xff
	ands r6, r0
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	adds r5, r1, #0
	cmp r0, #0
	blt _080C301C
	asrs r0, r0, #0xc
	b _080C3022
_080C301C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C3022:
	adds r1, r7, #0
	adds r1, #0x4c
	strh r0, [r1]
	adds r4, r7, #0
	adds r4, #0x53
	movs r0, #1
	strb r0, [r4]
_080C3030:
	adds r4, r1, #0
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldrh r1, [r5]
	ldrh r0, [r7, #0x20]
	adds r1, r1, r0
	strh r1, [r7, #0x20]
	ldrh r0, [r4]
	add r0, ip
	adds r1, r1, r0
	strh r1, [r7, #0x20]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080C3074 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _080C3078 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C307C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080C3084
	.align 2, 0
_080C3074: .4byte 0x000003FF
_080C3078: .4byte 0x0203B400
_080C307C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080C3084:
	str r0, [r7]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080C30AC @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _080C30B0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C30B4
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080C30BC
	.align 2, 0
_080C30AC: .4byte 0x000003FF
_080C30B0: .4byte 0x0203B400
_080C30B4:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080C30BC:
	str r0, [r7]
	adds r0, r7, #0
	adds r0, #0x51
	movs r2, #0
	strb r2, [r0]
	adds r1, r7, #0
	adds r1, #0x52
	movs r0, #0x50
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x50
	movs r1, #1
	strb r1, [r0]
	ldr r0, _080C310C @ =0x00000DB9
	add r0, r8
	strb r1, [r0]
	ldr r1, _080C3110 @ =0x00000DBA
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _080C30F0
	strb r2, [r1]
_080C30F0:
	ldr r0, _080C3114 @ =0x00000DBB
	add r0, r8
	strb r2, [r0]
_080C30F6:
	ldr r1, _080C3118 @ =0x00000DBC
	add r1, r8
	movs r0, #0
	strb r0, [r1]
_080C30FE:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C310C: .4byte 0x00000DB9
_080C3110: .4byte 0x00000DBA
_080C3114: .4byte 0x00000DBB
_080C3118: .4byte 0x00000DBC

	thumb_func_start FUN_080c311c
FUN_080c311c: @ 0x080C311C
	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r2, _080C3144 @ =0x00000DB8
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C313E
	ldr r0, _080C3148 @ =0x00000DC4
	adds r4, r1, r0
	movs r5, #0x1f
_080C3130:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x54
	subs r5, #1
	cmp r5, #0
	bge _080C3130
_080C313E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3144: .4byte 0x00000DB8
_080C3148: .4byte 0x00000DC4

	thumb_func_start FUN_080c314c
FUN_080c314c: @ 0x080C314C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	ldr r2, _080C31B8 @ =0x00000DB8
	add r2, sb
	movs r3, #0
	movs r0, #1
	strb r0, [r2]
	ldr r0, _080C31BC @ =0x00000DBA
	add r0, sb
	strb r3, [r0]
	ldr r0, _080C31C0 @ =0x00000DBB
	add r0, sb
	strb r3, [r0]
	ldr r0, _080C31C4 @ =0x00000DBE
	add r0, sb
	strh r1, [r0]
	movs r7, #0
	movs r0, #1
	mov sl, r0
	movs r1, #0
	mov r8, r1
_080C317E:
	movs r0, #0x54
	muls r0, r7, r0
	ldr r1, _080C31C8 @ =0x00000DC4
	adds r0, r0, r1
	mov r1, sb
	adds r4, r1, r0
	adds r6, r4, #0
	adds r5, r4, #0
	adds r5, #0x2c
	ldr r0, _080C31CC @ =0x08251E04
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl FUN_0822b16c
	adds r0, r7, #0
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _080C31D4
	adds r0, r4, #0
	adds r1, r5, #0
	ldr r2, _080C31D0 @ =0x00000201
	bl FUN_0822a470
	b _080C31DE
	.align 2, 0
_080C31B8: .4byte 0x00000DB8
_080C31BC: .4byte 0x00000DBA
_080C31C0: .4byte 0x00000DBB
_080C31C4: .4byte 0x00000DBE
_080C31C8: .4byte 0x00000DC4
_080C31CC: .4byte 0x08251E04
_080C31D0: .4byte 0x00000201
_080C31D4:
	adds r0, r4, #0
	adds r1, r5, #0
	ldr r2, _080C3214 @ =0x00000401
	bl FUN_0822a470
_080C31DE:
	mov r0, r8
	strh r0, [r6, #0x10]
	adds r0, r5, #0
	movs r1, #0xb4
	lsls r1, r1, #1
	bl FUN_0822b20c
	mov r1, sl
	strb r1, [r6, #7]
	adds r0, r4, #0
	adds r0, #0x50
	mov r1, r8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r7, #1
	cmp r7, #0x1f
	ble _080C317E
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3214: .4byte 0x00000401

	thumb_func_start FUN_080c3218
FUN_080c3218: @ 0x080C3218
	adds r2, r0, #0
	adds r2, #0xb8
	str r1, [r2]
	movs r1, #0
	strh r1, [r0, #8]
	bx lr

	thumb_func_start FUN_080c3224
FUN_080c3224: @ 0x080C3224
	push {r4, lr}
	adds r2, r0, #0
	ldrh r0, [r2, #8]
	adds r0, #1
	strh r0, [r2, #8]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080C3244
	ldr r0, [r2, #0x10]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x10]
	movs r0, #0
	strb r0, [r2, #1]
	b _080C3272
_080C3244:
	adds r0, r2, #0
	adds r0, #0xa8
	ldrh r0, [r0]
	ldrh r1, [r2, #0x2c]
	adds r0, r0, r1
	strh r0, [r2, #0x2c]
	adds r0, r2, #0
	adds r0, #0xac
	ldrh r0, [r0]
	ldrh r1, [r2, #0x30]
	adds r0, r0, r1
	strh r0, [r2, #0x30]
	adds r4, r2, #0
	adds r4, #0x58
	adds r1, r2, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_080C3272:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c3278
FUN_080c3278: @ 0x080C3278
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #8]
	adds r1, r0, #1
	strh r1, [r5, #8]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _080C3298
	ldr r0, [r5, #0x10]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x10]
	movs r0, #0
	strb r0, [r5, #1]
	b _080C33D0
_080C3298:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x18
	bls _080C32AA
	ldrb r0, [r5, #4]
	cmp r0, #0x13
	bhi _080C32AA
	adds r0, #1
	strb r0, [r5, #4]
_080C32AA:
	ldrh r0, [r5, #8]
	cmp r0, #0x17
	bhi _080C32C0
	adds r2, r5, #0
	adds r2, #0xb0
	ldr r0, _080C3308 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
_080C32C0:
	ldrh r1, [r5, #8]
	adds r0, r1, #0
	subs r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2b
	bhi _080C3322
	adds r0, r5, #0
	adds r0, #0xb0
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x2c
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	adds r1, r5, #0
	adds r1, #0xb4
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r3, #0x30
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldrb r2, [r5, #3]
	subs r0, r0, r2
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r0, r3
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x80
	ble _080C330C
	adds r0, r2, #0
	adds r0, #0xfd
	b _080C330E
	.align 2, 0
_080C3308: .4byte 0x03002BE0
_080C330C:
	adds r0, r2, #3
_080C330E:
	strb r0, [r5, #3]
	adds r0, r1, #0
	subs r0, #0x18
	cmp r0, #0xd0
	bhi _080C332A
	ldrh r0, [r5, #6]
	cmp r0, #0xf
	bls _080C3334
	subs r0, #1
	b _080C3332
_080C3322:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080C3334
_080C332A:
	ldrh r0, [r5, #6]
	cmp r0, #0x18
	bhi _080C3334
	adds r0, #1
_080C3332:
	strh r0, [r5, #6]
_080C3334:
	ldrh r3, [r5, #6]
	ldr r2, _080C3354 @ =0x085B0A08
	ldrb r0, [r5, #3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r3, r2, #0
	cmp r0, #0
	blt _080C3358
	asrs r0, r0, #0xc
	b _080C335E
	.align 2, 0
_080C3354: .4byte 0x085B0A08
_080C3358:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C335E:
	adds r2, r5, #0
	adds r2, #0xa8
	strh r0, [r2]
	ldrh r1, [r5, #6]
	ldrb r0, [r5, #3]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	adds r7, r2, #0
	cmp r0, #0
	blt _080C337C
	asrs r0, r0, #0xc
	b _080C3382
_080C337C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C3382:
	adds r2, r5, #0
	adds r2, #0xac
	strh r0, [r2]
	ldrb r1, [r5, #0x16]
	ldrb r0, [r5, #4]
	subs r0, r1, r0
	movs r3, #0x80
	lsls r3, r3, #1
	adds r4, r0, r3
	movs r0, #0xff
	ands r4, r0
	adds r6, r2, #0
	cmp r1, #0x5f
	bls _080C33A8
	cmp r4, #0x5f
	bgt _080C33A8
	adds r0, #0x6a
	bl PlaySound_082406e0
_080C33A8:
	strb r4, [r5, #0x16]
	ldrh r0, [r7]
	ldrh r1, [r5, #0x2c]
	adds r0, r0, r1
	strh r0, [r5, #0x2c]
	ldrh r0, [r6]
	ldrh r2, [r5, #0x30]
	adds r0, r0, r2
	strh r0, [r5, #0x30]
	adds r4, r5, #0
	adds r4, #0x58
	adds r1, r5, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_080C33D0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c33d8
FUN_080c33d8: @ 0x080C33D8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0x58
	ldr r4, _080C3488 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r4
	movs r3, #0x30
	orrs r0, r3
	ldr r5, _080C348C @ =0x0000FFFF
	ands r0, r5
	movs r2, #0x80
	lsls r2, r2, #0xf
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r3
	str r0, [sp, #0x10]
	adds r0, r7, #0
	adds r0, #0xa8
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r2, r2, #0x12
	lsrs r2, r2, #0x10
	ldr r0, [sp, #0x14]
	ands r0, r4
	orrs r0, r2
	ands r0, r5
	str r0, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0xac
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r2, r2, #0x12
	lsrs r2, r2, #0x10
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r3, #4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080C3490 @ =0x00002101
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823646c
	ldrh r1, [r7, #0xa]
	ldrh r2, [r7, #0xc]
	movs r0, #0xc0
	lsls r0, r0, #0xb
	str r0, [sp]
	ldrh r0, [r7, #0xe]
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_082364f8
	ldrb r0, [r7, #3]
	adds r1, r7, #0
	adds r1, #0x9a
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	adds r2, r7, #0
	bl FUN_0823651c
	adds r1, r7, #0
	adds r1, #0x2c
	adds r0, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3488: .4byte 0xFFFF0000
_080C348C: .4byte 0x0000FFFF
_080C3490: .4byte 0x00002101

	thumb_func_start FUN_080c3494
FUN_080c3494: @ 0x080C3494
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x58
	ldr r5, _080C351C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r5
	movs r3, #0x80
	orrs r0, r3
	ldr r2, _080C3520 @ =0x0000FFFF
	ands r0, r2
	movs r2, #0x80
	lsls r2, r2, #0xf
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r5
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r5
	str r0, [r3, #4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080C3524 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823646c
	ldrh r1, [r4, #0xa]
	ldrh r2, [r4, #0xc]
	movs r0, #0xc0
	lsls r0, r0, #0xb
	str r0, [sp]
	ldrh r0, [r4, #0xe]
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_082364f8
	adds r0, r6, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r4, #0x2c
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C351C: .4byte 0xFFFF0000
_080C3520: .4byte 0x0000FFFF
_080C3524: .4byte 0x00002001

	thumb_func_start FUN_080c3528
FUN_080c3528: @ 0x080C3528
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x24
	adds r6, r0, #0
	movs r0, #0x58
	adds r0, r0, r6
	mov r8, r0
	ldr r5, _080C35DC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r5
	ldr r2, _080C35E0 @ =0x000005AA
	orrs r0, r2
	ldr r4, _080C35E4 @ =0x0000FFFF
	ands r0, r4
	movs r2, #0x80
	lsls r2, r2, #0x11
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r5
	ldr r2, _080C35E8 @ =0x000003A5
	orrs r0, r2
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r5
	movs r3, #0x80
	orrs r0, r3
	ands r0, r4
	movs r2, #0x80
	lsls r2, r2, #0xf
	orrs r0, r2
	str r0, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r5
	orrs r0, r3
	str r0, [r4, #4]
	movs r0, #0
	str r0, [sp, #0x1c]
	add r3, sp, #0x1c
	ldr r0, [r3, #4]
	ands r0, r5
	str r0, [r3, #4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080C35EC @ =0x00002101
	movs r0, #0x10
	str r0, [sp]
	str r4, [sp, #4]
	str r3, [sp, #8]
	mov r0, r8
	movs r3, #0
	bl FUN_0823646c
	ldrh r1, [r6, #0xa]
	ldrh r2, [r6, #0xc]
	movs r0, #0xc0
	lsls r0, r0, #0xb
	str r0, [sp]
	ldrh r0, [r6, #0xe]
	str r0, [sp, #4]
	mov r0, r8
	movs r3, #0
	bl FUN_082364f8
	movs r0, #0x40
	adds r1, r6, #0
	adds r1, #0x9a
	strb r0, [r1]
	mov r0, r8
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0823651c
	mov r0, r8
	add r1, sp, #0xc
	movs r2, #0
	bl FUN_082364c4
	mov r0, r8
	bl FUN_08236400
	add sp, #0x24
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C35DC: .4byte 0xFFFF0000
_080C35E0: .4byte 0x000005AA
_080C35E4: .4byte 0x0000FFFF
_080C35E8: .4byte 0x000003A5
_080C35EC: .4byte 0x00002101

	thumb_func_start FUN_080c35f0
FUN_080c35f0: @ 0x080C35F0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080C3650 @ =0x00001844
	adds r4, r5, r0
	strb r1, [r4, #2]
	movs r3, #1
	strb r3, [r4, #1]
	strb r2, [r4, #3]
	ldr r1, _080C3654 @ =0x00001854
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080C3658 @ =0x00000514
	strh r0, [r2, #0x1c]
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r2, #0x1e]
	movs r0, #0xc0
	lsls r0, r0, #2
	strh r0, [r2, #0x20]
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _080C36B4
	strh r0, [r2, #0x10]
	ldrb r0, [r4, #3]
	adds r0, #0x60
	mvns r0, r0
	strb r0, [r2, #6]
	ldr r2, _080C365C @ =0x085B0A08
	ldrb r0, [r4, #3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080C3660
	asrs r1, r0, #0xc
	b _080C3666
	.align 2, 0
_080C3650: .4byte 0x00001844
_080C3654: .4byte 0x00001854
_080C3658: .4byte 0x00000514
_080C365C: .4byte 0x085B0A08
_080C3660:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C3666:
	adds r0, r4, #0
	adds r0, #0xa8
	strh r1, [r0]
	ldrb r0, [r4, #3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080C3684
	asrs r2, r0, #0xc
	b _080C368A
_080C3684:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C368A:
	adds r0, r4, #0
	adds r0, #0xac
	strh r2, [r0]
	adds r0, r5, #0
	adds r0, #0x48
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_080c33d8
	ldr r0, _080C36AC @ =0x0000018F
	bl PlaySound_082406e0
	ldr r1, _080C36B0 @ =FUN_080c3224
	adds r0, r4, #0
	bl FUN_080c3218
	b _080C372C
	.align 2, 0
_080C36AC: .4byte 0x0000018F
_080C36B0: .4byte FUN_080c3224
_080C36B4:
	strh r3, [r2, #0x10]
	movs r0, #0x60
	strb r0, [r2, #6]
	movs r3, #0x19
	strh r3, [r4, #6]
	movs r0, #0xa
	strb r0, [r4, #4]
	ldr r2, _080C36E0 @ =0x085B0A08
	ldrb r0, [r4, #3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080C36E4
	asrs r1, r0, #0xc
	b _080C36EA
	.align 2, 0
_080C36E0: .4byte 0x085B0A08
_080C36E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C36EA:
	adds r0, r4, #0
	adds r0, #0xa8
	strh r1, [r0]
	ldrh r1, [r4, #6]
	ldrb r0, [r4, #3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C3706
	asrs r1, r0, #0xc
	b _080C370C
_080C3706:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C370C:
	adds r0, r4, #0
	adds r0, #0xac
	strh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x48
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_080c3494
	ldr r0, _080C3734 @ =0x00000169
	bl PlaySound_082406e0
	ldr r1, _080C3738 @ =FUN_080c3278
	adds r0, r4, #0
	bl FUN_080c3218
_080C372C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3734: .4byte 0x00000169
_080C3738: .4byte FUN_080c3278

	thumb_func_start FUN_080c373c
FUN_080c373c: @ 0x080C373C
	push {lr}
	adds r2, r0, #0
	ldr r1, _080C375C @ =0x00001845
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C3758
	ldr r3, _080C3760 @ =0x000018FC
	adds r1, r2, r3
	subs r3, #0xb8
	adds r0, r2, r3
	ldr r1, [r1]
	bl _call_via_r1
_080C3758:
	pop {r0}
	bx r0
	.align 2, 0
_080C375C: .4byte 0x00001845
_080C3760: .4byte 0x000018FC

	thumb_func_start FUN_080c3764
FUN_080c3764: @ 0x080C3764
	push {lr}
	adds r1, r0, #0
	ldr r2, _080C3780 @ =0x00001844
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C377A
	adds r2, #0x10
	adds r0, r1, r2
	bl FUN_0822a4e0
_080C377A:
	pop {r0}
	bx r0
	.align 2, 0
_080C3780: .4byte 0x00001844

	thumb_func_start FUN_080c3784
FUN_080c3784: @ 0x080C3784
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	mov sb, r1
	mov sl, r2
	adds r7, r3, #0
	ldr r0, _080C37EC @ =0x00001844
	adds r5, r4, r0
	movs r0, #0
	movs r1, #1
	mov r8, r1
	mov r1, r8
	strb r1, [r5]
	strb r0, [r5, #1]
	strh r0, [r5, #8]
	ldr r0, _080C37F0 @ =0x00001854
	adds r6, r4, r0
	movs r1, #0xc4
	lsls r1, r1, #5
	adds r4, r4, r1
	ldr r1, _080C37F4 @ =0x00005291
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #3
	bl FUN_0822a470
	mov r0, r8
	strh r0, [r6, #0x10]
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r4, #0
	bl FUN_0822b20c
	mov r1, sb
	strh r1, [r5, #0xa]
	mov r0, sl
	strh r0, [r5, #0xc]
	strh r7, [r5, #0xe]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C37EC: .4byte 0x00001844
_080C37F0: .4byte 0x00001854
_080C37F4: .4byte 0x00005291

	thumb_func_start FUN_080c37f8
FUN_080c37f8: @ 0x080C37F8
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	ldr r0, _080C3818 @ =0x03003584
	ldr r0, [r0]
	ldr r4, _080C381C @ =0x00002BA0
	adds r3, r0, r4
	cmp r1, #0x1f
	ble _080C3828
	ldr r0, _080C3820 @ =0x0000259C
	adds r1, r2, r0
	ldr r2, _080C3824 @ =0x04000008
	adds r0, r3, #0
	bl CpuSet
	b _080C3862
	.align 2, 0
_080C3818: .4byte 0x03003584
_080C381C: .4byte 0x00002BA0
_080C3820: .4byte 0x0000259C
_080C3824: .4byte 0x04000008
_080C3828:
	adds r5, r1, #0
	movs r7, #0x1f
	ldr r0, _080C3868 @ =0x0000259C
	adds r4, r2, r0
	movs r6, #0xf
_080C3832:
	ldrh r0, [r3]
	movs r2, #0x1f
	ands r2, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x15
	ands r1, r7
	lsrs r0, r0, #0x1a
	ands r0, r7
	muls r2, r5, r2
	asrs r2, r2, #5
	muls r1, r5, r1
	asrs r1, r1, #5
	muls r0, r5, r0
	asrs r0, r0, #5
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r2
	strh r0, [r4]
	adds r3, #2
	adds r4, #2
	subs r6, #1
	cmp r6, #0
	bge _080C3832
_080C3862:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3868: .4byte 0x0000259C

	thumb_func_start FUN_080c386c
FUN_080c386c: @ 0x080C386C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r2, r1, #0
	ldr r3, _080C3898 @ =0x00001904
	adds r1, r0, r3
	ldr r3, _080C389C @ =0x000025BE
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #6
	ldr r1, [r1]
	adds r5, r1, r0
	cmp r2, #0x1f
	ble _080C38A8
	ldr r1, _080C38A0 @ =0x03004250
	ldr r2, _080C38A4 @ =0x04000010
	adds r0, r5, #0
	bl CpuSet
	b _080C38FC
	.align 2, 0
_080C3898: .4byte 0x00001904
_080C389C: .4byte 0x000025BE
_080C38A0: .4byte 0x03004250
_080C38A4: .4byte 0x04000010
_080C38A8:
	adds r4, r2, #0
	movs r0, #0
	movs r1, #0x1f
	mov r8, r1
	ldr r3, _080C3908 @ =0x03004250
	mov sb, r3
_080C38B4:
	movs r6, #0
	lsls r7, r0, #5
	adds r0, #1
	mov ip, r0
_080C38BC:
	ldrh r0, [r5]
	movs r2, #0x1f
	ands r2, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x15
	mov r3, r8
	ands r1, r3
	lsrs r0, r0, #0x1a
	ands r0, r3
	adds r3, r2, #0
	muls r3, r4, r3
	asrs r3, r3, #5
	adds r2, r1, #0
	muls r2, r4, r2
	asrs r2, r2, #5
	muls r0, r4, r0
	asrs r0, r0, #5
	lsls r1, r6, #1
	adds r1, r1, r7
	add r1, sb
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r3
	strh r0, [r1]
	adds r5, #2
	adds r6, #1
	cmp r6, #0xf
	ble _080C38BC
	mov r0, ip
	cmp r0, #1
	ble _080C38B4
_080C38FC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3908: .4byte 0x03004250

	thumb_func_start FUN_080c390c
FUN_080c390c: @ 0x080C390C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r1, _080C3958 @ =0x03003584
	ldr r2, _080C395C @ =0x085AD0D8
	ldr r5, _080C3960 @ =0x000025BE
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r0, r1, r0
	str r0, [sp]
	adds r5, #1
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r7, r1, r0
	cmp r3, #0xf
	ble _080C396C
	ldr r0, _080C3964 @ =0x0000259C
	adds r1, r4, r0
	ldr r2, _080C3968 @ =0x04000008
	adds r0, r7, #0
	bl CpuSet
	b _080C39F2
	.align 2, 0
_080C3958: .4byte 0x03003584
_080C395C: .4byte 0x085AD0D8
_080C3960: .4byte 0x000025BE
_080C3964: .4byte 0x0000259C
_080C3968: .4byte 0x04000008
_080C396C:
	movs r0, #0x10
	subs r0, r0, r3
	mov sb, r0
	mov r8, r3
	movs r1, #0x1f
	mov sl, r1
	ldr r2, _080C3A04 @ =0x0000259C
	adds r2, r2, r4
	mov ip, r2
	movs r3, #0xf
	str r3, [sp, #4]
_080C3982:
	ldr r5, [sp]
	ldrh r3, [r5]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	mov r0, sl
	ands r6, r0
	lsrs r3, r3, #0x1a
	ands r3, r0
	ldrh r1, [r7]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x15
	mov r5, sl
	ands r4, r5
	lsrs r1, r1, #0x1a
	ands r1, r5
	mov r5, sb
	muls r5, r2, r5
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r5, r5, r0
	asrs r5, r5, #4
	mov r2, sb
	muls r2, r6, r2
	mov r0, r8
	muls r0, r4, r0
	adds r2, r2, r0
	asrs r2, r2, #4
	mov r0, sb
	muls r0, r3, r0
	mov r3, r8
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	asrs r0, r0, #4
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	mov r5, ip
	strh r0, [r5]
	ldr r0, [sp]
	adds r0, #2
	str r0, [sp]
	adds r7, #2
	movs r1, #2
	add ip, r1
	ldr r2, [sp, #4]
	subs r2, #1
	str r2, [sp, #4]
	cmp r2, #0
	bge _080C3982
_080C39F2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3A04: .4byte 0x0000259C

	thumb_func_start FUN_080c3a08
FUN_080c3a08: @ 0x080C3A08
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r3, r1, #0
	ldr r1, _080C3A44 @ =0x00001904
	adds r2, r0, r1
	ldr r4, _080C3A48 @ =0x000025BE
	adds r1, r0, r4
	ldrb r1, [r1]
	lsls r1, r1, #6
	ldr r2, [r2]
	adds r1, r1, r2
	mov sb, r1
	ldr r5, _080C3A4C @ =0x000025BF
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r2, r2, r0
	mov r8, r2
	cmp r3, #0xf
	ble _080C3A58
	ldr r1, _080C3A50 @ =0x03004250
	ldr r2, _080C3A54 @ =0x04000010
	mov r0, r8
	bl CpuSet
	b _080C3AE0
	.align 2, 0
_080C3A44: .4byte 0x00001904
_080C3A48: .4byte 0x000025BE
_080C3A4C: .4byte 0x000025BF
_080C3A50: .4byte 0x03004250
_080C3A54: .4byte 0x04000010
_080C3A58:
	movs r0, #0x10
	subs r0, r0, r3
	mov ip, r0
	adds r7, r3, #0
	movs r0, #0
_080C3A62:
	movs r1, #0
	mov sl, r1
	lsls r3, r0, #5
	str r3, [sp, #4]
	adds r0, #1
	str r0, [sp]
_080C3A6E:
	mov r4, sb
	ldrh r3, [r4]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	movs r5, #0x1f
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
	mov r5, ip
	muls r5, r2, r5
	muls r0, r7, r0
	adds r5, r5, r0
	asrs r5, r5, #4
	mov r2, ip
	muls r2, r6, r2
	adds r0, r4, #0
	muls r0, r7, r0
	adds r2, r2, r0
	asrs r2, r2, #4
	mov r0, ip
	muls r0, r3, r0
	muls r1, r7, r1
	adds r0, r0, r1
	asrs r0, r0, #4
	mov r3, sl
	lsls r1, r3, #1
	ldr r4, [sp, #4]
	adds r1, r1, r4
	ldr r3, _080C3AF0 @ =0x03004250
	adds r1, r1, r3
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	strh r0, [r1]
	movs r4, #2
	add sb, r4
	add r8, r4
	movs r5, #1
	add sl, r5
	mov r0, sl
	cmp r0, #0xf
	ble _080C3A6E
	ldr r0, [sp]
	cmp r0, #1
	ble _080C3A62
_080C3AE0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3AF0: .4byte 0x03004250

	thumb_func_start FUN_080c3af4
FUN_080c3af4: @ 0x080C3AF4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080C3B38 @ =0x000025C5
	adds r3, r5, r0
	ldrb r2, [r3]
	cmp r2, #0
	beq _080C3B44
	ldr r1, _080C3B3C @ =0x000025C6
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C3B22
	ldr r0, _080C3B40 @ =0x000025C7
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _080C3B22
	movs r0, #0
	strb r0, [r3]
_080C3B22:
	ldr r1, _080C3B40 @ =0x000025C7
	adds r4, r5, r1
	ldrb r1, [r4]
	adds r0, r5, #0
	bl FUN_080c37f8
	ldrb r1, [r4]
	adds r0, r5, #0
	bl FUN_080c386c
	b _080C3B74
	.align 2, 0
_080C3B38: .4byte 0x000025C5
_080C3B3C: .4byte 0x000025C6
_080C3B40: .4byte 0x000025C7
_080C3B44:
	movs r0, #0x97
	lsls r0, r0, #6
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C3B74
	ldr r0, _080C3B7C @ =0x000025C1
	adds r4, r5, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _080C3B64
	strb r2, [r1]
_080C3B64:
	ldrb r1, [r4]
	adds r0, r5, #0
	bl FUN_080c390c
	ldrb r1, [r4]
	adds r0, r5, #0
	bl FUN_080c3a08
_080C3B74:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3B7C: .4byte 0x000025C1

	thumb_func_start FUN_080c3b80
FUN_080c3b80: @ 0x080C3B80
	push {lr}
	adds r2, r0, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C3BA0
	ldr r1, _080C3B98 @ =0x000025BE
	adds r0, r2, r1
	movs r1, #2
	strb r1, [r0]
	ldr r3, _080C3B9C @ =0x000025BF
	b _080C3BBC
	.align 2, 0
_080C3B98: .4byte 0x000025BE
_080C3B9C: .4byte 0x000025BF
_080C3BA0:
	ldr r0, _080C3BE0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080C3BE4 @ =0x00000942
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0
	cmp r0, #0
	bne _080C3BB4
	movs r1, #1
_080C3BB4:
	ldr r3, _080C3BE8 @ =0x000025BE
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
_080C3BBC:
	adds r0, r2, r3
	strb r1, [r0]
	subs r3, #2
	adds r0, r2, r3
	strb r1, [r0]
	ldr r0, _080C3BEC @ =0x000025C1
	adds r1, r2, r0
	movs r0, #0x10
	strb r0, [r1]
	adds r3, #3
	adds r1, r2, r3
	movs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	bl FUN_080c3af4
	pop {r0}
	bx r0
	.align 2, 0
_080C3BE0: .4byte 0x030046A0
_080C3BE4: .4byte 0x00000942
_080C3BE8: .4byte 0x000025BE
_080C3BEC: .4byte 0x000025C1

	thumb_func_start FUN_080c3bf0
FUN_080c3bf0: @ 0x080C3BF0
	push {lr}
	adds r2, r0, #0
	ldr r0, _080C3C1C @ =0x000025C2
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C3C48
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C3C2C
	ldr r3, _080C3C20 @ =0x00000366
	adds r1, r2, r3
	ldr r0, _080C3C24 @ =0x00000155
	strh r0, [r1]
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r3, _080C3C28 @ =0x0000259C
	adds r0, r2, r3
	b _080C3C46
	.align 2, 0
_080C3C1C: .4byte 0x000025C2
_080C3C20: .4byte 0x00000366
_080C3C24: .4byte 0x00000155
_080C3C28: .4byte 0x0000259C
_080C3C2C:
	ldr r0, _080C3C70 @ =0x00000366
	adds r1, r2, r0
	movs r0, #0x99
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0xdd
	lsls r3, r3, #2
	adds r1, r2, r3
	ldr r0, _080C3C74 @ =0x03003584
	ldr r0, [r0]
	movs r3, #0x99
	lsls r3, r3, #6
	adds r0, r0, r3
_080C3C46:
	str r0, [r1]
_080C3C48:
	ldr r0, _080C3C78 @ =0x000025C3
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C3CA6
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C3C8C
	ldr r3, _080C3C7C @ =0x0000065E
	adds r1, r2, r3
	ldr r0, _080C3C80 @ =0x00000155
	strh r0, [r1]
	ldr r0, _080C3C84 @ =0x0000066C
	adds r1, r2, r0
	ldr r3, _080C3C88 @ =0x0000259C
	adds r0, r2, r3
	b _080C3CA4
	.align 2, 0
_080C3C70: .4byte 0x00000366
_080C3C74: .4byte 0x03003584
_080C3C78: .4byte 0x000025C3
_080C3C7C: .4byte 0x0000065E
_080C3C80: .4byte 0x00000155
_080C3C84: .4byte 0x0000066C
_080C3C88: .4byte 0x0000259C
_080C3C8C:
	ldr r0, _080C3CD0 @ =0x0000065E
	adds r1, r2, r0
	movs r0, #0x99
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r3, _080C3CD4 @ =0x0000066C
	adds r1, r2, r3
	ldr r0, _080C3CD8 @ =0x03003584
	ldr r0, [r0]
	movs r3, #0x99
	lsls r3, r3, #6
	adds r0, r0, r3
_080C3CA4:
	str r0, [r1]
_080C3CA6:
	ldr r0, _080C3CDC @ =0x000025C4
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C3D08
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C3CEC
	ldr r3, _080C3CE0 @ =0x00000572
	adds r1, r2, r3
	ldr r0, _080C3CE4 @ =0x00000155
	strh r0, [r1]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r1, r2, r0
	ldr r3, _080C3CE8 @ =0x0000259C
	adds r0, r2, r3
	b _080C3D06
	.align 2, 0
_080C3CD0: .4byte 0x0000065E
_080C3CD4: .4byte 0x0000066C
_080C3CD8: .4byte 0x03003584
_080C3CDC: .4byte 0x000025C4
_080C3CE0: .4byte 0x00000572
_080C3CE4: .4byte 0x00000155
_080C3CE8: .4byte 0x0000259C
_080C3CEC:
	ldr r0, _080C3D0C @ =0x00000572
	adds r1, r2, r0
	movs r0, #0x99
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r1, r2, r3
	ldr r0, _080C3D10 @ =0x03003584
	ldr r0, [r0]
	movs r2, #0x99
	lsls r2, r2, #6
	adds r0, r0, r2
_080C3D06:
	str r0, [r1]
_080C3D08:
	pop {r0}
	bx r0
	.align 2, 0
_080C3D0C: .4byte 0x00000572
_080C3D10: .4byte 0x03003584

	thumb_func_start FUN_080c3d14
FUN_080c3d14: @ 0x080C3D14
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r4, r0, #0
	ldr r7, _080C3DA0 @ =0x030046B8
	ldr r0, _080C3DA4 @ =0xFFFF0000
	mov r8, r0
	add r5, sp, #0x10
	movs r6, #4
_080C3D28:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080C3DA8 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080C3DAC @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	asrs r2, r2, #3
	movs r0, #0xff
	ands r2, r0
	movs r0, #0x9b
	lsls r0, r0, #2
	adds r3, r4, r0
	ldr r1, _080C3DB0 @ =0x0000026E
	adds r0, r4, r1
	ldrh r1, [r0]
	subs r2, #0x80
	adds r1, r2, r1
	lsls r1, r1, #0x10
	ldrh r0, [r3]
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	mov r2, r8
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #0
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FUN_080ddcc8
	subs r6, #1
	cmp r6, #0
	bge _080C3D28
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3DA0: .4byte 0x030046B8
_080C3DA4: .4byte 0xFFFF0000
_080C3DA8: .4byte 0x000003FF
_080C3DAC: .4byte 0x0203B400
_080C3DB0: .4byte 0x0000026E

	thumb_func_start FUN_080c3db4
FUN_080c3db4: @ 0x080C3DB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov r8, r3
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	add r0, sp, #0x1c
	ldrh r0, [r0]
	ldrh r1, [r2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080C3F18 @ =0xFFFF0000
	ldr r3, [sp, #0x1c]
	ands r3, r4
	orrs r3, r0
	asrs r1, r3, #0x10
	ldrh r0, [r2, #2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _080C3F1C @ =0x0000FFFF
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldrh r0, [r0, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x20]
	ldr r1, _080C3F20 @ =0x030046B8
	mov sl, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r4, _080C3F24 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	adds r0, #2
	adds r1, #1
	ands r1, r4
	mov r2, sl
	str r1, [r2]
	lsls r1, r1, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #3
	ands r1, r2
	adds r1, #8
	movs r7, #8
	str r7, [sp]
	str r1, [sp, #4]
	movs r6, #4
	str r6, [sp, #8]
	movs r1, #0xa
	str r1, [sp, #0xc]
	str r7, [sp, #0x10]
	movs r2, #5
	str r2, [sp, #0x14]
	str r1, [sp, #0x18]
	adds r1, #0xff
	add r2, sp, #0x1c
	mov r3, r8
	bl FUN_080149dc
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ands r0, r4
	lsls r1, r0, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r1, r1, r2
	ldrh r3, [r1]
	movs r1, #7
	mov sb, r1
	ands r3, r1
	add r3, r8
	movs r5, #0xff
	ands r3, r5
	adds r0, #1
	ands r0, r4
	mov r2, sl
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C3F28 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, sb
	ands r0, r2
	adds r0, #6
	str r7, [sp]
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0xe
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	movs r6, #6
	str r6, [sp, #0x14]
	movs r0, #0xa
	str r0, [sp, #0x18]
	movs r0, #3
	ldr r1, _080C3F2C @ =0x00000109
	add r2, sp, #0x1c
	bl FUN_080149dc
	mov r2, sl
	ldr r1, [r2]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0xf
	ands r0, r2
	add r8, r0
	mov r0, r8
	ands r0, r5
	mov r8, r0
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	adds r0, #1
	adds r1, #1
	ands r1, r4
	mov r2, sl
	str r1, [r2]
	lsls r1, r1, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	mov r2, sb
	ands r1, r2
	adds r1, #4
	str r7, [sp]
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	movs r1, #3
	str r1, [sp, #0x10]
	movs r2, #5
	str r2, [sp, #0x14]
	movs r1, #0xa
	str r1, [sp, #0x18]
	adds r1, #0xff
	add r2, sp, #0x1c
	mov r3, r8
	bl FUN_080149dc
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3F18: .4byte 0xFFFF0000
_080C3F1C: .4byte 0x0000FFFF
_080C3F20: .4byte 0x030046B8
_080C3F24: .4byte 0x000003FF
_080C3F28: .4byte 0x0203B400
_080C3F2C: .4byte 0x00000109

	thumb_func_start FUN_080c3f30
FUN_080c3f30: @ 0x080C3F30
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, _080C3F94 @ =0x000023D4
	adds r6, r4, r0
	movs r1, #0
	movs r0, #1
	strb r0, [r6]
	strb r1, [r6, #3]
	ldr r0, _080C3F98 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #4]
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
	ldr r0, _080C3F9C @ =0x000023EC
	adds r5, r4, r0
	subs r0, #0x10
	adds r4, r4, r0
	movs r7, #7
_080C3F5C:
	movs r0, #0
	strb r0, [r4]
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
	movs r0, #1
	strb r0, [r4, #0x1f]
	adds r5, #0x38
	adds r4, #0x38
	subs r7, #1
	cmp r7, #0
	bge _080C3F5C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3F94: .4byte 0x000023D4
_080C3F98: .4byte 0x00001C1E
_080C3F9C: .4byte 0x000023EC

	thumb_func_start FUN_080c3fa0
FUN_080c3fa0: @ 0x080C3FA0
	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r2, _080C3FC8 @ =0x000023D4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C3FC2
	ldr r0, _080C3FCC @ =0x000023EC
	adds r4, r1, r0
	movs r5, #7
_080C3FB4:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x38
	subs r5, #1
	cmp r5, #0
	bge _080C3FB4
_080C3FC2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3FC8: .4byte 0x000023D4
_080C3FCC: .4byte 0x000023EC

	thumb_func_start FUN_080c3fd0
FUN_080c3fd0: @ 0x080C3FD0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r7, _080C404C @ =0x000023D4
	add r7, r8
	adds r1, #2
	ldrb r0, [r7, #2]
	adds r1, r1, r0
	strb r1, [r7, #2]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x1d
	bhi _080C3FEE
	b _080C40FC
_080C3FEE:
	ldrb r1, [r7, #1]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	adds r6, r7, r0
	movs r0, #0
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	ldr r4, _080C4050 @ =0x0203B400
	ldr r1, _080C4054 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080C4058 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r3, [r1]
	adds r0, #1
	ands r0, r2
	ldr r2, _080C4054 @ =0x030046B8
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	movs r4, #0xa0
	lsls r4, r4, #1
	adds r2, r0, r4
	ldr r1, _080C405C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r2, r0
	ldr r4, _080C4054 @ =0x030046B8
	cmp r0, #0
	blt _080C4060
	asrs r0, r0, #0xc
	b _080C4066
	.align 2, 0
_080C404C: .4byte 0x000023D4
_080C4050: .4byte 0x0203B400
_080C4054: .4byte 0x030046B8
_080C4058: .4byte 0x000003FF
_080C405C: .4byte 0x085B0A08
_080C4060:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C4066:
	strh r0, [r6, #8]
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C407A
	asrs r0, r0, #0xc
	b _080C4080
_080C407A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C4080:
	strh r0, [r6, #0xc]
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080C4108 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _080C410C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #0x1c
	strh r0, [r6, #6]
	adds r4, r6, #0
	adds r4, #0x10
	ldr r0, [r6, #0x10]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x10]
	ldr r1, [r7, #4]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	movs r1, #0xba
	lsls r1, r1, #2
	add r1, r8
	ldrh r0, [r6, #8]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldr r0, _080C4110 @ =0x000002EA
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r4, #0x1a]
	movs r0, #0xbb
	lsls r0, r0, #2
	add r0, r8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r2, #0
	ldrh r6, [r6, #0xc]
	adds r1, r1, r6
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	ldrb r0, [r7, #1]
	adds r0, #1
	strb r0, [r7, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080C40F2
	movs r0, #0
	strb r0, [r7, #1]
_080C40F2:
	ldrb r0, [r7, #2]
	subs r0, #0x1e
	strb r0, [r7, #2]
	movs r0, #1
	strb r0, [r7, #3]
_080C40FC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C4108: .4byte 0x000003FF
_080C410C: .4byte 0x0203B400
_080C4110: .4byte 0x000002EA

	thumb_func_start FUN_080c4114
FUN_080c4114: @ 0x080C4114
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r2, r0, #0
	ldr r0, _080C418C @ =0x000023D4
	adds r0, r0, r2
	mov sb, r0
	ldrb r0, [r0, #3]
	cmp r0, #0
	bne _080C412E
	b _080C4246
_080C412E:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r5, [r0]
	ldr r6, [r0, #4]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r6, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080C4190 @ =0xFFFF0000
	ands r0, r6
	adds r6, r0, #0
	orrs r6, r1
	movs r3, #0
	ldr r0, _080C4194 @ =0x000023DC
	adds r4, r2, r0
	ldr r1, _080C4198 @ =0x000023EC
	adds r1, r1, r2
	mov r8, r1
	movs r2, #7
	mov sl, r2
_080C415A:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080C4230
	mov r7, r8
	movs r1, #8
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _080C416C
	rsbs r0, r0, #0
_080C416C:
	cmp r0, #0x3f
	bgt _080C419C
	movs r2, #0xc
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bge _080C417A
	rsbs r0, r0, #0
_080C417A:
	cmp r0, #0x3f
	bgt _080C419C
	ldr r0, [r4, #0x10]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x10]
	movs r0, #0
	strb r0, [r4]
	b _080C4230
	.align 2, 0
_080C418C: .4byte 0x000023D4
_080C4190: .4byte 0xFFFF0000
_080C4194: .4byte 0x000023DC
_080C4198: .4byte 0x000023EC
_080C419C:
	movs r3, #8
	ldrsh r0, [r4, r3]
	movs r2, #0xc
	ldrsh r1, [r4, r2]
	bl FUN_0823785c
	adds r2, r0, #0
	ldrh r1, [r4, #6]
	adds r0, #0x40
	movs r3, #0xff
	ands r0, r3
	lsls r0, r0, #1
	ldr r3, _080C41C8 @ =0x085B0A08
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C41CC
	asrs r1, r0, #0xc
	b _080C41D2
	.align 2, 0
_080C41C8: .4byte 0x085B0A08
_080C41CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C41D2:
	ldrh r0, [r4, #8]
	subs r0, r0, r1
	strh r0, [r4, #8]
	ldrh r1, [r4, #6]
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	ldr r2, _080C41F4 @ =0x085B0A08
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C41F8
	asrs r1, r0, #0xc
	b _080C41FE
	.align 2, 0
_080C41F4: .4byte 0x085B0A08
_080C41F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C41FE:
	ldrh r0, [r4, #0xc]
	subs r0, r0, r1
	strh r0, [r4, #0xc]
	adds r0, r5, #0
	ldrh r1, [r4, #8]
	adds r0, r0, r1
	strh r0, [r7, #0x18]
	adds r0, r6, #0
	ldrh r2, [r4, #0xc]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
	movs r3, #0xff
	ands r0, r3
	cmp r0, #4
	bne _080C422E
	mov r0, sb
	ldr r1, [r0, #4]
	adds r0, r7, #0
	movs r2, #3
	bl FUN_0822dafc
_080C422E:
	movs r3, #1
_080C4230:
	adds r4, #0x38
	movs r1, #0x38
	add r8, r1
	movs r2, #1
	rsbs r2, r2, #0
	add sl, r2
	mov r0, sl
	cmp r0, #0
	bge _080C415A
	mov r1, sb
	strb r3, [r1, #3]
_080C4246:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c4254
FUN_080c4254: @ 0x080C4254
	push {r4, r5, r6, lr}
	ldr r1, _080C4288 @ =0x000023D7
	adds r2, r0, r1
	movs r1, #0
	strb r1, [r2]
	movs r6, #1
	adds r2, r0, #0
	ldr r0, _080C428C @ =0x000023EC
	adds r1, r2, r0
	ldr r5, _080C4290 @ =0x000023DC
	movs r4, #0
	movs r3, #7
_080C426C:
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	adds r0, r2, r5
	strb r4, [r0]
	adds r2, #0x38
	adds r1, #0x38
	subs r3, #1
	cmp r3, #0
	bge _080C426C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C4288: .4byte 0x000023D7
_080C428C: .4byte 0x000023EC
_080C4290: .4byte 0x000023DC

	thumb_func_start FUN_080c4294
FUN_080c4294: @ 0x080C4294
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #0
	beq _080C42A6
	b _080C4512
_080C42A6:
	adds r4, r2, #0
	movs r1, #0x80
	lsls r1, r1, #0xb
	adds r0, r4, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080C42BA
	b _080C4512
_080C42BA:
	movs r0, #0xf
	ldr r1, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _080C42D8
	ldr r0, _080C42D4 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x24
	ldrsh r1, [r7, r2]
	movs r3, #0x2c
	ldrsh r0, [r0, r3]
	b _080C42EE
	.align 2, 0
_080C42D4: .4byte 0x03002BE0
_080C42D8:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080C42E6
	movs r0, #0x24
	ldrsh r1, [r7, r0]
	b _080C42EA
_080C42E6:
	movs r3, #0x24
	ldrsh r1, [r7, r3]
_080C42EA:
	movs r2, #0x24
	ldrsh r0, [r5, r2]
_080C42EE:
	movs r2, #2
	cmp r1, r0
	ble _080C42F6
	movs r2, #1
_080C42F6:
	cmp r2, #1
	bne _080C43EC
	ldr r3, _080C43C0 @ =0x0000191A
	adds r6, r4, r3
	ldrh r0, [r6]
	cmp r0, #0x77
	bls _080C4306
	b _080C4512
_080C4306:
	ldr r1, _080C43C4 @ =0x000025C8
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C43AA
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08236524
	ldr r2, _080C43C8 @ =0x00001910
	adds r1, r4, r2
	ldrh r0, [r7, #0x3e]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r7, #0x3e]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	ldr r3, _080C43CC @ =0x0000191C
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080C43D0 @ =0x000025C2
	adds r1, r4, r0
	movs r0, #6
	strb r0, [r1]
	ldr r1, _080C43D4 @ =0x000025D8
	adds r2, r4, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r4, r3
	str r1, [r2]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r1]
	subs r0, r0, r1
	ldr r3, _080C43D8 @ =0x000025DC
	adds r1, r4, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x64
	ble _080C4364
	movs r0, #0x64
	strh r0, [r1]
_080C4364:
	ldr r1, [r2]
	ldrh r0, [r5, #0xe]
	ldrh r1, [r1, #2]
	subs r0, r0, r1
	ldr r3, _080C43DC @ =0x000025DE
	adds r1, r4, r3
	strh r0, [r1]
	ldr r1, [r2]
	ldrh r0, [r5, #0x10]
	ldrh r1, [r1, #4]
	subs r0, r0, r1
	ldr r1, _080C43E0 @ =0x000025E0
	adds r2, r4, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xaf
	lsls r1, r1, #1
	cmp r0, r1
	ble _080C438E
	strh r1, [r2]
_080C438E:
	ldr r2, _080C43E4 @ =0x000025E4
	adds r1, r4, r2
	movs r0, #0x10
	strh r0, [r1]
	ldr r3, _080C43E8 @ =0x000025CC
	adds r1, r4, r3
	ldrh r0, [r5, #0x3e]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	ldr r1, [r5, #0x34]
	subs r2, #0x14
	adds r0, r4, r2
	str r1, [r0]
_080C43AA:
	adds r1, r7, #0
	adds r1, #0x44
	movs r0, #0x14
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _080C44B8
	b _080C44F8
	.align 2, 0
_080C43C0: .4byte 0x0000191A
_080C43C4: .4byte 0x000025C8
_080C43C8: .4byte 0x00001910
_080C43CC: .4byte 0x0000191C
_080C43D0: .4byte 0x000025C2
_080C43D4: .4byte 0x000025D8
_080C43D8: .4byte 0x000025DC
_080C43DC: .4byte 0x000025DE
_080C43E0: .4byte 0x000025E0
_080C43E4: .4byte 0x000025E4
_080C43E8: .4byte 0x000025CC
_080C43EC:
	cmp r2, #2
	beq _080C43F2
	b _080C4512
_080C43F2:
	ldr r0, _080C44C8 @ =0x00001918
	adds r6, r4, r0
	ldrh r0, [r6]
	cmp r0, #0x77
	bls _080C43FE
	b _080C4512
_080C43FE:
	ldr r1, _080C44CC @ =0x000025C8
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C44A4
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08236524
	ldr r2, _080C44D0 @ =0x0000190E
	adds r1, r4, r2
	ldrh r0, [r7, #0x3e]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r7, #0x3e]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	ldr r3, _080C44D4 @ =0x0000191C
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080C44D8 @ =0x000025C2
	adds r1, r4, r0
	movs r0, #6
	strb r0, [r1]
	ldr r1, _080C44DC @ =0x000025D8
	adds r2, r4, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r4, r3
	str r1, [r2]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r1]
	subs r0, r0, r1
	ldr r1, _080C44E0 @ =0x000025DC
	adds r3, r4, r1
	strh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x64
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080C445E
	strh r1, [r3]
_080C445E:
	ldr r1, [r2]
	ldrh r0, [r5, #0xe]
	ldrh r1, [r1, #2]
	subs r0, r0, r1
	ldr r3, _080C44E4 @ =0x000025DE
	adds r1, r4, r3
	strh r0, [r1]
	ldr r1, [r2]
	ldrh r0, [r5, #0x10]
	ldrh r1, [r1, #4]
	subs r0, r0, r1
	ldr r1, _080C44E8 @ =0x000025E0
	adds r2, r4, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xaf
	lsls r1, r1, #1
	cmp r0, r1
	ble _080C4488
	strh r1, [r2]
_080C4488:
	ldr r2, _080C44EC @ =0x000025E4
	adds r1, r4, r2
	movs r0, #0x10
	strh r0, [r1]
	ldr r3, _080C44F0 @ =0x000025CC
	adds r1, r4, r3
	ldrh r0, [r5, #0x3e]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	ldr r1, [r5, #0x34]
	subs r2, #0x14
	adds r0, r4, r2
	str r1, [r0]
_080C44A4:
	adds r1, r7, #0
	adds r1, #0x44
	movs r0, #0x14
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080C44F8
_080C44B8:
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r3, _080C44F4 @ =0x000025D6
	adds r0, r4, r3
	strh r1, [r0]
	b _080C4506
	.align 2, 0
_080C44C8: .4byte 0x00001918
_080C44CC: .4byte 0x000025C8
_080C44D0: .4byte 0x0000190E
_080C44D4: .4byte 0x0000191C
_080C44D8: .4byte 0x000025C2
_080C44DC: .4byte 0x000025D8
_080C44E0: .4byte 0x000025DC
_080C44E4: .4byte 0x000025DE
_080C44E8: .4byte 0x000025E0
_080C44EC: .4byte 0x000025E4
_080C44F0: .4byte 0x000025CC
_080C44F4: .4byte 0x000025D6
_080C44F8:
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r0, [r0]
	asrs r0, r0, #1
	ldr r2, _080C4518 @ =0x000025D6
	adds r1, r4, r2
	strh r0, [r1]
_080C4506:
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r1, [r0]
	ldr r3, _080C451C @ =0x000025D5
	adds r0, r4, r3
	strb r1, [r0]
_080C4512:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C4518: .4byte 0x000025D6
_080C451C: .4byte 0x000025D5

	thumb_func_start FUN_080c4520
FUN_080c4520: @ 0x080C4520
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	movs r0, #0xd4
	lsls r0, r0, #1
	adds r4, r6, r0
	ldr r2, _080C45AC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r1, #0x80
	orrs r0, r1
	ldr r1, _080C45B0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x96
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	adds r1, #0x6a
	orrs r0, r1
	str r0, [r3, #4]
	adds r0, r6, #0
	adds r0, #0x48
	ldrh r1, [r0]
	ldr r2, _080C45B4 @ =0x00005001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0
	bl FUN_08236514
	ldr r1, _080C45B8 @ =FUN_080c4294
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C45AC: .4byte 0xFFFF0000
_080C45B0: .4byte 0x0000FFFF
_080C45B4: .4byte 0x00005001
_080C45B8: .4byte FUN_080c4294

	thumb_func_start FUN_080c45bc
FUN_080c45bc: @ 0x080C45BC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	adds r7, r6, #0
	adds r7, #0x44
	ldrh r0, [r7]
	cmp r0, #0
	bne _080C466E
	movs r1, #0x80
	lsls r1, r1, #0xc
	adds r0, r4, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080C466E
	ldr r1, _080C4674 @ =0x000025C8
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C466A
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08236524
	ldr r2, _080C4678 @ =0x00001914
	adds r1, r4, r2
	ldrh r0, [r6, #0x3e]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r0, _080C467C @ =0x0000191C
	adds r1, r4, r0
	ldrh r0, [r1]
	movs r2, #8
	orrs r0, r2
	strh r0, [r1]
	ldr r1, _080C4680 @ =0x000025C4
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _080C4684 @ =0x000025D8
	adds r2, r4, r3
	movs r0, #0xbe
	lsls r0, r0, #2
	adds r1, r4, r0
	str r1, [r2]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r1]
	subs r0, r0, r1
	adds r3, #4
	adds r1, r4, r3
	strh r0, [r1]
	ldr r1, [r2]
	ldrh r0, [r5, #0xe]
	ldrh r1, [r1, #2]
	subs r0, r0, r1
	adds r3, #2
	adds r1, r4, r3
	strh r0, [r1]
	ldr r1, [r2]
	ldrh r0, [r5, #0x10]
	ldrh r1, [r1, #4]
	subs r0, r0, r1
	ldr r2, _080C4688 @ =0x000025E0
	adds r1, r4, r2
	strh r0, [r1]
	adds r3, #6
	adds r1, r4, r3
	movs r0, #0x10
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r1, [r0]
	subs r2, #0xb
	adds r0, r4, r2
	strb r1, [r0]
	subs r3, #0x18
	adds r1, r4, r3
	ldrh r0, [r5, #0x3e]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	ldr r1, [r5, #0x34]
	subs r2, #5
	adds r0, r4, r2
	str r1, [r0]
_080C466A:
	movs r0, #0xf
	strh r0, [r7]
_080C466E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C4674: .4byte 0x000025C8
_080C4678: .4byte 0x00001914
_080C467C: .4byte 0x0000191C
_080C4680: .4byte 0x000025C4
_080C4684: .4byte 0x000025D8
_080C4688: .4byte 0x000025E0

	thumb_func_start FUN_080c468c
FUN_080c468c: @ 0x080C468C
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r4, r6, r0
	ldr r2, _080C4714 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _080C4718 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
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
	adds r0, r6, #0
	adds r0, #0x48
	ldrh r1, [r0]
	ldr r2, _080C471C @ =0x00005001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0
	bl FUN_08236514
	ldr r1, _080C4720 @ =FUN_080c45bc
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	movs r0, #0xbe
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C4714: .4byte 0xFFFF0000
_080C4718: .4byte 0x0000FFFF
_080C471C: .4byte 0x00005001
_080C4720: .4byte FUN_080c45bc

	thumb_func_start FUN_080c4724
FUN_080c4724: @ 0x080C4724
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r4, #0
	adds r7, #0x44
	ldrh r0, [r7]
	cmp r0, #0
	bne _080C4784
	adds r0, r6, #0
	bl FUN_08236524
	ldr r0, _080C478C @ =0x00001912
	adds r1, r5, r0
	ldrh r0, [r4, #0x3e]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _080C4790 @ =0x0000191C
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xf
	strh r0, [r7]
	ldr r2, _080C4794 @ =0x000025C3
	adds r1, r5, r2
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080C4798 @ =0x000025F9
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080c3d14
	ldr r2, _080C479C @ =0x000025CC
	adds r1, r5, r2
	ldrh r0, [r6, #0x3e]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r6, #0x3e]
	ldr r1, [r6, #0x34]
	adds r2, #4
	adds r0, r5, r2
	str r1, [r0]
_080C4784:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C478C: .4byte 0x00001912
_080C4790: .4byte 0x0000191C
_080C4794: .4byte 0x000025C3
_080C4798: .4byte 0x000025F9
_080C479C: .4byte 0x000025CC

	thumb_func_start FUN_080c47a0
FUN_080c47a0: @ 0x080C47A0
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	movs r0, #0x92
	lsls r0, r0, #2
	adds r4, r6, r0
	ldr r2, _080C4830 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r1, #0x40
	orrs r0, r1
	ldr r1, _080C4834 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x80
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	movs r1, #0x90
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r3, #4]
	adds r0, r6, #0
	adds r0, #0x48
	ldrh r1, [r0]
	ldr r2, _080C4838 @ =0x00005005
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0
	bl FUN_08236514
	ldr r1, _080C483C @ =FUN_080c4724
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C4830: .4byte 0xFFFF0000
_080C4834: .4byte 0x0000FFFF
_080C4838: .4byte 0x00005005
_080C483C: .4byte FUN_080c4724

	thumb_func_start FUN_080c4840
FUN_080c4840: @ 0x080C4840
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r0, #0xac
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r2, _080C48DC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _080C48E0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, _080C48E4 @ =0xFFE00000
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	str r0, [r3, #4]
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r0]
	ldr r2, _080C48E8 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, r8
	movs r3, #0
	bl FUN_082364f8
	adds r0, r4, #0
	movs r1, #0
	adds r2, r7, #0
	bl FUN_0823651c
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C48DC: .4byte 0xFFFF0000
_080C48E0: .4byte 0x0000FFFF
_080C48E4: .4byte 0xFFE00000
_080C48E8: .4byte 0x00002001

	thumb_func_start FUN_080c48ec
FUN_080c48ec: @ 0x080C48EC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r2, _080C4984 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _080C4988 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r5, #0
	str r5, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r0]
	ldr r2, _080C498C @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	str r5, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl FUN_082364f8
	adds r0, r4, #0
	movs r1, #0
	adds r2, r7, #0
	bl FUN_0823651c
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C4984: .4byte 0xFFFF0000
_080C4988: .4byte 0x0000FFFF
_080C498C: .4byte 0x00002001

	thumb_func_start FUN_080c4990
FUN_080c4990: @ 0x080C4990
	push {r4, lr}
	adds r3, r0, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0xbc
	lsls r4, r4, #2
	adds r0, r3, r4
	movs r4, #0
	ldrsh r2, [r0, r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	blt _080C49B6
	asrs r1, r0, #3
	b _080C49BC
_080C49B6:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080C49BC:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r3, r2
	strh r1, [r0]
	ldr r4, _080C49E4 @ =0x000002EA
	adds r0, r3, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r4, #8
	adds r0, r3, r4
	movs r4, #0
	ldrsh r2, [r0, r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	blt _080C49E8
	asrs r1, r0, #3
	b _080C49EE
	.align 2, 0
_080C49E4: .4byte 0x000002EA
_080C49E8:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080C49EE:
	ldr r2, _080C4A14 @ =0x000002EA
	adds r0, r3, r2
	strh r1, [r0]
	movs r4, #0xbb
	lsls r4, r4, #2
	adds r0, r3, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r4, #8
	adds r0, r3, r4
	movs r4, #0
	ldrsh r2, [r0, r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	blt _080C4A18
	asrs r1, r0, #3
	b _080C4A1E
	.align 2, 0
_080C4A14: .4byte 0x000002EA
_080C4A18:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080C4A1E:
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r3, r2
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c4a2c
FUN_080c4a2c: @ 0x080C4A2C
	movs r1, #0xba
	lsls r1, r1, #2
	adds r2, r0, r1
	adds r1, #8
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	bx lr

	thumb_func_start FUN_080c4a40
FUN_080c4a40: @ 0x080C4A40
	movs r3, #0x98
	muls r1, r3, r1
	adds r0, r0, r1
	ldr r1, _080C4A50 @ =0x00000397
	adds r0, r0, r1
	strb r2, [r0]
	bx lr
	.align 2, 0
_080C4A50: .4byte 0x00000397

	thumb_func_start FUN_080c4a54
FUN_080c4a54: @ 0x080C4A54
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	movs r4, #0
_080C4A5C:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_080c4a40
	adds r4, #1
	cmp r4, #4
	ble _080C4A5C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c4a74
FUN_080c4a74: @ 0x080C4A74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r5, r0, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xbe
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r6, r1, r0
	subs r3, #0xe
	adds r0, r5, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, #0x10
	adds r0, r5, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	mov r8, r1
	subs r3, #0xe
	adds r0, r5, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, #0x10
	adds r0, r5, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r4, r1, r0
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r7, r0, #0
	cmp r6, #0
	bne _080C4AD0
	cmp r4, #0
	beq _080C4B1C
_080C4AD0:
	adds r1, r6, #0
	cmp r6, #0
	bge _080C4AD8
	rsbs r1, r6, #0
_080C4AD8:
	adds r0, r4, #0
	cmp r4, #0
	bge _080C4AE0
	rsbs r0, r4, #0
_080C4AE0:
	cmp r1, r0
	ble _080C4B00
	lsls r0, r6, #0xc
	ldr r3, _080C4AFC @ =0x085B0A08
	adds r1, r7, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	b _080C4B10
	.align 2, 0
_080C4AFC: .4byte 0x085B0A08
_080C4B00:
	lsls r0, r4, #0xc
	ldr r2, _080C4B18 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r7
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
_080C4B10:
	bl Div
	adds r2, r0, #0
	b _080C4B20
	.align 2, 0
_080C4B18: .4byte 0x085B0A08
_080C4B1C:
	movs r2, #0xc0
	lsls r2, r2, #2
_080C4B20:
	movs r0, #0xa0
	lsls r0, r0, #2
	cmp r8, r0
	ble _080C4B3A
	ldr r0, _080C4B48 @ =0xFFFFFD80
	add r0, r8
	lsls r0, r0, #1
	adds r2, r2, r0
	movs r0, #0xc0
	lsls r0, r0, #2
	cmp r2, r0
	ble _080C4B3A
	adds r2, r0, #0
_080C4B3A:
	ldr r0, _080C4B4C @ =0x000002FF
	cmp r2, r0
	ble _080C4B50
	movs r3, #0
	str r3, [sp, #0x1c]
	b _080C4B5E
	.align 2, 0
_080C4B48: .4byte 0xFFFFFD80
_080C4B4C: .4byte 0x000002FF
_080C4B50:
	movs r1, #0xc0
	lsls r1, r1, #2
	subs r0, r1, r2
	lsls r0, r0, #8
	bl Div
	str r0, [sp, #0x1c]
_080C4B5E:
	ldr r1, _080C4B90 @ =0x000008F4
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	beq _080C4B9C
	ldr r3, _080C4B94 @ =0x000008F5
	adds r2, r5, r3
	ldrb r0, [r2]
	cmp r0, #7
	bhi _080C4BC0
	ldr r0, _080C4B98 @ =0x000008F6
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080C4BC0
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	movs r0, #0
	strb r0, [r1]
	b _080C4BC0
	.align 2, 0
_080C4B90: .4byte 0x000008F4
_080C4B94: .4byte 0x000008F5
_080C4B98: .4byte 0x000008F6
_080C4B9C:
	ldr r1, _080C4BEC @ =0x000008F5
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080C4BC0
	ldr r0, _080C4BF0 @ =0x000008F6
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080C4BC0
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	strb r3, [r1]
_080C4BC0:
	movs r7, #0
	adds r1, r5, #0
	adds r1, #0x98
	str r1, [sp, #0x20]
	add r2, sp, #0x14
	mov r8, r2
	ldr r3, _080C4BF4 @ =0xFFFF0000
	mov sl, r3
	add r0, sp, #0xc
	mov sb, r0
_080C4BD4:
	movs r0, #0x98
	muls r0, r7, r0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r6, r5, r0
	cmp r7, #0
	bne _080C4BF8
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	b _080C4C02
	.align 2, 0
_080C4BEC: .4byte 0x000008F5
_080C4BF0: .4byte 0x000008F6
_080C4BF4: .4byte 0xFFFF0000
_080C4BF8:
	cmp r7, #4
	bne _080C4C0C
	movs r3, #0xbe
	lsls r3, r3, #2
	adds r0, r5, r3
_080C4C02:
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	b _080C4CF0
_080C4C0C:
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r2, r0, #0
	muls r2, r7, r2
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #4
	subs r0, r3, r7
	muls r0, r1, r0
	adds r0, r2, r0
	cmp r0, #0
	blt _080C4C34
	asrs r0, r0, #2
	b _080C4C3A
_080C4C34:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C4C3A:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0xc]
	mov r2, sl
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r3, _080C4C6C @ =0x000002FA
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r0, #0
	muls r2, r7, r2
	subs r3, #0x10
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #4
	subs r0, r3, r7
	muls r0, r1, r0
	adds r0, r2, r0
	cmp r0, #0
	blt _080C4C70
	asrs r0, r0, #2
	b _080C4C76
	.align 2, 0
_080C4C6C: .4byte 0x000002FA
_080C4C70:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C4C76:
	lsls r2, r0, #0x10
	ldr r1, _080C4CAC @ =0x0000FFFF
	ldr r0, [sp, #0xc]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0xc]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r2, r0, #0
	muls r2, r7, r2
	movs r3, #0xbb
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #4
	subs r0, r3, r7
	muls r0, r1, r0
	adds r0, r2, r0
	cmp r0, #0
	blt _080C4CB0
	asrs r0, r0, #2
	b _080C4CB6
	.align 2, 0
_080C4CAC: .4byte 0x0000FFFF
_080C4CB0:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C4CB6:
	adds r3, r0, #0
	ldr r2, _080C4CD4 @ =0x085B0A08
	lsls r0, r7, #5
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x1c]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C4CD8
	asrs r0, r0, #0xc
	b _080C4CDE
	.align 2, 0
_080C4CD4: .4byte 0x085B0A08
_080C4CD8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C4CDE:
	subs r1, r3, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r3, sb
	ldr r0, [r3, #4]
	mov r2, sl
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
_080C4CF0:
	adds r4, r6, #0
	adds r4, #0x97
	ldrb r0, [r4]
	cmp r0, #0
	beq _080C4D42
	ldr r2, _080C4D70 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C4D74 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080C4D78 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	subs r0, #0xa
	mov r1, sb
	ldrh r2, [r1]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, [sp, #0xc]
	mov r3, sl
	ands r1, r3
	orrs r1, r2
	str r1, [sp, #0xc]
	mov r2, sb
	ldrh r1, [r2, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
_080C4D42:
	movs r3, #0x8f
	lsls r3, r3, #4
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #2
	lsls r1, r7, #6
	adds r0, r0, r1
	movs r2, #0xff
	adds r3, #5
	adds r1, r5, r3
	ldrb r3, [r1]
	ldr r1, _080C4D7C @ =0x085B0A08
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080C4D80
	asrs r0, r0, #0xc
	b _080C4D86
	.align 2, 0
_080C4D70: .4byte 0x030046B8
_080C4D74: .4byte 0x000003FF
_080C4D78: .4byte 0x0203B400
_080C4D7C: .4byte 0x085B0A08
_080C4D80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C4D86:
	mov r2, sb
	ldrh r1, [r2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0xc]
	mov r3, sl
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r2, [r0]
	add r4, sp, #0xc
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r2]
	str r1, [r2, #4]
	cmp r7, #1
	ble _080C4E30
	subs r1, r7, #1
	movs r0, #0x98
	muls r1, r0, r1
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r3, #2
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	cmp r3, #0
	bne _080C4DDA
	movs r0, #0x40
	b _080C4DE2
_080C4DDA:
	lsls r0, r0, #6
	adds r1, r3, #0
	bl Div
_080C4DE2:
	cmp r0, #0x17
	ble _080C4E0C
	adds r1, r6, #0
	adds r1, #0x95
	ldrb r2, [r1]
	cmp r2, #1
	bne _080C4E30
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	ldrb r1, [r1]
	str r2, [sp]
	str r0, [sp, #4]
	movs r3, #4
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	b _080C4E30
_080C4E0C:
	adds r1, r6, #0
	adds r1, #0x95
	ldrb r2, [r1]
	cmp r2, #0
	bne _080C4E30
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	ldrb r1, [r1]
	str r0, [sp]
	str r2, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08055b5c
_080C4E30:
	adds r0, r6, #0
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C4E40
	adds r0, r6, #0
	bl FUN_08055c04
_080C4E40:
	adds r7, #1
	cmp r7, #4
	bgt _080C4E48
	b _080C4BD4
_080C4E48:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r2, [sp, #0x20]
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080C4E70
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r1, #2
	bl FUN_08055f5c
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	bl FUN_08055f5c
	b _080C4E88
_080C4E70:
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #1
	bl FUN_08055f5c
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r1, #1
	bl FUN_08055f5c
_080C4E88:
	movs r7, #0
	movs r6, #0
_080C4E8C:
	movs r0, #0x98
	muls r0, r7, r0
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r4, r5, r0
	ldr r2, _080C4EC4 @ =0x000004BC
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	cmp r7, #2
	bne _080C4EC8
	mov r3, r8
	ldrh r0, [r3]
	adds r0, #8
	add r1, sp, #0x14
	strh r0, [r1]
	ldrh r0, [r3, #2]
	adds r0, #0x10
	strh r0, [r3, #2]
	ldrh r0, [r3, #4]
	adds r0, #8
	strh r0, [r3, #4]
	b _080C4EE0
	.align 2, 0
_080C4EC4: .4byte 0x000004BC
_080C4EC8:
	mov r1, r8
	ldrh r0, [r1]
	subs r0, #8
	add r1, sp, #0x14
	strh r0, [r1]
	mov r2, r8
	ldrh r0, [r2, #2]
	subs r0, #0x10
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	subs r0, #8
	strh r0, [r2, #4]
_080C4EE0:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r2, [r0]
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r3, _080C4F20 @ =0x000004C5
	adds r0, r5, r3
	ldrb r2, [r0]
	cmp r2, #1
	bne _080C4F24
	adds r1, r4, #0
	adds r1, #0x95
	ldrb r0, [r1]
	cmp r0, #1
	beq _080C4F4E
	strb r2, [r1]
	adds r0, r4, #0
	adds r0, #0x96
	ldrb r1, [r0]
	adds r1, #1
	str r2, [sp]
	str r6, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	b _080C4F4E
	.align 2, 0
_080C4F20: .4byte 0x000004C5
_080C4F24:
	adds r2, r4, #0
	adds r2, #0x95
	ldrb r0, [r2]
	cmp r0, #0
	beq _080C4F4E
	strb r6, [r2]
	adds r0, r4, #0
	adds r0, #0x96
	ldrb r1, [r0]
	ldrb r0, [r2]
	adds r1, r1, r0
	movs r0, #1
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C4F4E:
	ldr r1, _080C4FB4 @ =0x000008F4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C4F5E
	adds r0, r4, #0
	bl FUN_08055c04
_080C4F5E:
	adds r7, #1
	cmp r7, #2
	ble _080C4E8C
	ldr r2, [sp, #0x20]
	ldr r0, [r2]
	cmp r0, #0
	bge _080C4FC0
	movs r3, #0xd2
	lsls r3, r3, #3
	adds r4, r5, r3
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08055f1c
	ldr r0, _080C4FB8 @ =0x0000071C
	adds r2, r5, r0
	ldr r3, [r2]
	ldr r1, _080C4FBC @ =0x00000554
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r1, [r2]
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	ldr r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldr r1, [r2]
	ldrh r0, [r1, #4]
	adds r0, #0x80
	strh r0, [r1, #4]
	adds r0, r4, #0
	bl FUN_08055c04
	b _080C4FCC
	.align 2, 0
_080C4FB4: .4byte 0x000008F4
_080C4FB8: .4byte 0x0000071C
_080C4FBC: .4byte 0x00000554
_080C4FC0:
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #1
	bl FUN_08055ef8
_080C4FCC:
	movs r1, #0x80
	lsls r1, r1, #0xe
	ldr r2, [sp, #0x20]
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080C5024
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r4, r5, r3
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08055f1c
	ldr r0, _080C5020 @ =0x00000684
	adds r2, r5, r0
	ldr r3, [r2]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r1, [r2]
	ldrh r0, [r1]
	adds r0, #0x10
	strh r0, [r1]
	ldr r1, [r2]
	ldrh r0, [r1, #2]
	adds r0, #0x20
	strh r0, [r1, #2]
	ldr r1, [r2]
	ldrh r0, [r1, #4]
	adds r0, #0x10
	strh r0, [r1, #4]
	adds r0, r4, #0
	bl FUN_08055c04
	b _080C5030
	.align 2, 0
_080C5020: .4byte 0x00000684
_080C5024:
	movs r2, #0xbf
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r1, #1
	bl FUN_08055ef8
_080C5030:
	movs r3, #0x8f
	lsls r3, r3, #4
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _080C5048
	movs r0, #0
	strh r0, [r1]
_080C5048:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
